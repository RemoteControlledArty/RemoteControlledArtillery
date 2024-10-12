/*
 * Author: Eric & Ascent
 * Checks spawned vehicles if they have the value "artilleryscanner=1;", adds them to array for counter battery fire when friendly counter battery radar is active:
 * -for players marks opposing indirect fire sources on the map
 * -for AI returns fire on opposing indirect fire sources
 * Needs to be preinit to work on 3den spawned vehicles.
*/

RC_CBRad_Player_Array_B = [];
RC_CBRad_Player_Array_O = [];

RC_CBRad_AI_Array_B = [];
RC_CBRad_AI_Array_O = [];

RC_ArtilleryArray_B = [];
RC_ArtilleryArray_O = [];

RC_isInRangeArray_B = [];
RC_isInRangeArray_O = [];

RC_fireMissionArray_B = [];
RC_fireMissionArray_O = [];


/* testing scripts section
[(str RC_ArtilleryArray_O)] remoteExec ["hintSilent", west];
[(str RC_CBRad_AI_Array_O)] remoteExec ["hintSilent", west];
[(str RC_isInRangeArray_O)] remoteExec ["hintSilent", west];
[(str RC_fireMissionArray_O)] remoteExec ["hintSilent", west];


_this doArtilleryFire [(getpos target), (currentMagazine _this), 1];
[(getpos target), (currentMagazine _this), 1] remoteExec ["doArtilleryFire", _this];

_entitySide_O = (side _this == east);
if (_entitySide_O) then { 
RC_ArtilleryArray_O pushback _entity;
*/

//server side only  //creates problem of assets not being added to array or EH triggering
//eden assets and script attached mortar been local to server and worked, all other assets been local to player and didnt work
//if (!isServer) exitwith {};


//checks if spawned vehicles are artillery, to add them in counter battery array
addMissionEventHandler ["EntityCreated", {
	params ["_entity"];
	_isArtillery = getNumber (configFile >> "CfgVehicles" >> (typeOf _entity) >> "artilleryScanner") == 1;

	if (_isArtillery) then {

        _entitySide_B = (side _entity == west);
        _entitySide_O = (side _entity == east);

        switch (true) do {
            case(_entitySide_B): {
                RC_ArtilleryArray_B pushback _entity;
                publicVariable "RC_ArtilleryArray_B";

                //hint for testing
                [str RC_ArtilleryArray_B] remoteExec ["hint", west];
            };
            case(_entitySide_O): {
                RC_ArtilleryArray_O pushback _entity;
                publicVariable "RC_ArtilleryArray_O";

                //hint for testing
                [str RC_ArtilleryArray_O] remoteExec ["hint", west];
            };
        };
    };
}];


//if artillery fires checks if opposing CBRad is alive, for opposing AI assigns CB firemission, for opposing players creates map markers
addMissionEventHandler ["ArtilleryShellFired", {
    params ["_vehicle", "_weapon", "_ammo", "_gunner", "_instigator", "_artilleryTarget", "_targetPosition", "_shell"];

    //checks side of the vehicle
    _vehicleSide_B = (side _vehicle == west);
    _vehicleSide_O = (side _vehicle == east);

    //conciders potential prior CB firemission completed
    switch (true) do {
        case(_vehicleSide_B): {
            RC_fireMissionArray_B deleteAt (RC_fireMissionArray_B find _vehicle);
            //hint for testing
            //[str RC_fireMissionArray_B] remoteExec ["hint", west];
        };
        case(_vehicleSide_O): {
            RC_fireMissionArray_O deleteAt (RC_fireMissionArray_O find _vehicle);
            //hint for testing
            //[str RC_fireMissionArray_O] remoteExec ["hint", west];
        };
    };

    //checks for opposing CBRad's
    _CBRad_Player_Alive_B = ({alive _x} count RC_CBRad_Player_Array_B) > 0;
    _CBRad_Player_Alive_O = ({alive _x} count RC_CBRad_Player_Array_O) > 0;
    _CBRad_AI_Alive_B = ({alive _x} count RC_CBRad_AI_Array_B) > 0;
    _CBRad_AI_Alive_O = ({alive _x} count RC_CBRad_AI_Array_O) > 0;

    //checks opposing sides
    _opposedTo_B = [side _vehicle, west] call BIS_fnc_sideIsEnemy;
    _opposedTo_O = [side _vehicle, east] call BIS_fnc_sideIsEnemy;


    //Blufor AI
    if (_opposedTo_B and _CBRad_AI_Alive_B) then {
        //hint for testing
        ["blufor rad(AI) detected shot"] remoteExec ["hint", west];

        //removes objNull from array
        RC_ArtilleryArray_B = RC_ArtilleryArray_B - [objNull];
        RC_isInRangeArray_B = RC_isInRangeArray_B - [objNull];

        //shot source position
        _vehiclePos = getPos _vehicle;
        [_vehiclePos] spawn
        {
            params ["_vehiclePos"];
            //CBRad detection time (same for players & AI)
            sleep RC_Timer1;

            //hint for testing
            _testHintB = "blufor artillery:"+ str RC_ArtilleryArray_B;
            [_testHintB] remoteExec ["hint", west];

            //simulating AI preperation time before shot (AI only), half to show hints better
            sleep (RC_Timer2 / 2);

            //checks if opposing artillery is in range
            //RC_isInRangeArray_B = []; //good or bad idea to empty the array?
            {
                RC_isInRangeArray_B deleteAt (RC_isInRangeArray_B find _x); //prevents doubles in array
                _isNull = isNull _x;
                if !(_isNull) then
                {
                    _isInRange = _vehiclePos inRangeOfArtillery [[_x], (currentMagazine _x)];
                    _isAlive = alive _x;
                    if (_isInRange && _isAlive) then {
                        RC_isInRangeArray_B pushback _x;
                    };
                };
                sleep 0.1;
            } forEach RC_ArtilleryArray_B;


            //hint for testing
            if ((count RC_isInRangeArray_B) < 1) then {["no blufor inRange"] remoteExec ["hint", west];};

            //true if atleast 1 opposing artillery is in range
            if ((count RC_isInRangeArray_B) > 0) then
            {
                //hint for testing
                _isInRangeHintB = "blufor in range:"+ str RC_isInRangeArray_B;
                [_isInRangeHintB] remoteExec ["hint", west];

                //simulating AI preperation time before shot (AI only), half to show hints better
                sleep (RC_Timer2 / 2);

                //selects first opposing artillery in range to return fire
                _isInRange_B = (RC_isInRangeArray_B select 0);
                _isInRange_B doArtilleryFire [_vehiclePos, (currentMagazine _isInRange_B), 1];
                
                //if it doesnt shoot in time, firemission will be passed to next in isInRangeArray
                RC_fireMissionArray_B pushback _isInRange_B;
                sleep RC_Timer3;
                _fireMissionNotCompleted = (({_x == _isInRange_B} count RC_fireMissionArray_B) > 0);

                if (_fireMissionNotCompleted) then
                {
                    if ((count RC_isInRangeArray_B) > 1) then
                    {
                        //hint for testing
                        ["first B firemission failed"] remoteExec ["hint", west];

                        //selects second opposing artillery in range to return fire
                        _isInRange_B = (RC_isInRangeArray_B select 1);
                        _isInRange_B doArtilleryFire [_vehiclePos, (currentMagazine _isInRange_B), 1];
                        
                        //if it doesnt shoot in time, firemission will be passed to next in isInRangeArray
                        RC_fireMissionArray_B pushback _isInRange_B;
                        sleep RC_Timer3;
                        _fireMissionNotCompleted = (({_x == _isInRange_B} count RC_fireMissionArray_B) > 0);

                        if (_fireMissionNotCompleted) then
                        {
                            if ((count RC_isInRangeArray_B) > 2) then
                            {
                                //hint for testing
                                ["second B firemission failed"] remoteExec ["hint", west];

                                //selects third opposing artillery in range to return fire
                                _isInRange_B = (RC_isInRangeArray_B select 2);
                                _isInRange_B doArtilleryFire [_vehiclePos, (currentMagazine _isInRange_B), 1];
                            };
                        };
                    };
                };
            };
        };
    };


    //Opfor AI
    if (_opposedTo_O and _CBRad_AI_Alive_O) then {
        //hint for testing
        ["opfor rad(AI) detected shot"] remoteExec ["hint", west];

        //removes objNull from array
        RC_ArtilleryArray_O = RC_ArtilleryArray_O - [objNull];
        RC_isInRangeArray_O = RC_isInRangeArray_O - [objNull];

        //shot source position
        _vehiclePos = getPos _vehicle;
        [_vehiclePos] spawn
        {
            params ["_vehiclePos"];
            //CBRad detection time (same for players & AI)
            sleep RC_Timer1;

            //hint for testing
            _testHintO = "opfor artillery:"+ str RC_ArtilleryArray_O;
            [_testHintO] remoteExec ["hint", west];

            //simulating AI preperation time before shot (AI only), half to show hints better
            sleep (RC_Timer2 / 2);


            //checks if opposing artillery is in range
            //RC_isInRangeArray_O = []; //good or bad idea to empty the array?
            {
                RC_isInRangeArray_O deleteAt (RC_isInRangeArray_O find _x); //prevents doubles in array
                _isNull = isNull _x;
                if !(_isNull) then
                {
                    _isInRange = _vehiclePos inRangeOfArtillery [[_x], (currentMagazine _x)];
                    _isAlive = alive _x;
                    if (_isInRange && _isAlive) then {
                        RC_isInRangeArray_O pushback _x;
                    };
                };
                sleep 0.1;
            } forEach RC_ArtilleryArray_O;


            //hint for testing
            if ((count RC_isInRangeArray_O) < 1) then {["no opfor inRange"] remoteExec ["hint", west];};

            //true if atleast 1 opposing artillery is in range
            if ((count RC_isInRangeArray_O) > 0) then
            {
                //hint for testing
                _isInRangeHintO = "opfor in range:"+ str RC_isInRangeArray_O;
                [_isInRangeHintO] remoteExec ["hint", west];

                //simulating AI preperation time before shot (AI only), half to show hints better
                sleep (RC_Timer2 / 2);

                //selects first opposing artillery in range to return fire
                _isInRange_O = (RC_isInRangeArray_O select 0);
                _isInRange_O doArtilleryFire [_vehiclePos, (currentMagazine _isInRange_O), 1];
                
                //if it doesnt shoot in time, firemission will be passed to next in isInRangeArray
                RC_fireMissionArray_O pushback _isInRange_O;
                sleep RC_Timer3;
                _fireMissionNotCompleted = (({_x == _isInRange_O} count RC_fireMissionArray_O) > 0);

                if (_fireMissionNotCompleted) then
                {
                    if ((count RC_isInRangeArray_O) > 1) then
                    {
                        //hint for testing
                        ["first O firemission failed"] remoteExec ["hint", west];

                        //selects second opposing artillery in range to return fire
                        _isInRange_O = (RC_isInRangeArray_O select 1);
                        _isInRange_O doArtilleryFire [_vehiclePos, (currentMagazine _isInRange_O), 1];
                        
                        //if it doesnt shoot in time, firemission will be passed to next in isInRangeArray
                        RC_fireMissionArray_O pushback _isInRange_O;
                        sleep RC_Timer3;
                        _fireMissionNotCompleted = (({_x == _isInRange_O} count RC_fireMissionArray_O) > 0);

                        if (_fireMissionNotCompleted) then
                        {
                            if ((count RC_isInRangeArray_O) > 2) then
                            {
                                //hint for testing
                                ["second O firemission failed"] remoteExec ["hint", west];

                                //selects third opposing artillery in range to return fire
                                _isInRange_O = (RC_isInRangeArray_O select 2);
                                _isInRange_O doArtilleryFire [_vehiclePos, (currentMagazine _isInRange_O), 1];
                            };
                        };
                    };
                };
            };
        };
    };
}];


/*
RC_ArtilleryArray_O deleteAt (RC_ArtilleryArray_O find [objNull]);     //prevents objNull in array
RC_isInRangeArray_O deleteAt (RC_isInRangeArray_O find [objNull]);     //prevents objNull in array
RC_ArtilleryArray_O = RC_ArtilleryArray_O arrayIntersect RC_ArtilleryArray_O;
RC_isInRangeArray_O = RC_isInRangeArray_O arrayIntersect RC_isInRangeArray_O;

You can remove duplicates (get unique items) with this command:
private _myArray = [1, 2, 2, 3, 4];
private _result = _myArray arrayIntersect _myArray; // _result is [1, 2, 3, 4]

if (ObjNull in RC_isInRangeArray_O) then {
    {RC_isInRangeArray_O = RC_isInRangeArray_O - [objNull]} forEach RC_isInRangeArray_O;
};
*/


/*
//Blufor Player
//_this setVariable ["ArtySourceMarkersTime", 0, true];

if (_opposedTo_B and _CBRad_Player_Alive_B) then {
    //hint for testing
    ["blufor rad(P) detected shot"] remoteExec ["hint", west];

    private _timeInterval = 10;
    private _lastMarkerTime = _vehicle getVariable "ArtySourceMarkersTime";
    private _timeSinceLastMarker = time - _lastMarkerTime;

    if (_timeSinceLastMarker > _timeInterval) then {
        [_vehicle] spawn
        {
            params ["_vehicle"];
            _vehicle setVariable ["ArtySourceMarkersTime", time, true];
            private _artySourcePos = getPosASL _vehicle;

            _markerName = ("_USER_DEFINED ArtySourceMarker" + str _artySourcePos);
            _markerArray = [_markerName, _artySourcePos, 1];

            sleep (RC_Timer1);
            private _artySourceMarker = createMarker [_markerName, _artySourcePos, 1];
            [_artySourceMarker, "o_art"] remoteExec ["setMarkerType", west];
            [_artySourceMarker, 0.7] remoteExec ["setMarkerAlpha", west];
            [_markerName] remoteExec ["deleteMarker", east];
            [_markerName] remoteExec ["deleteMarker", resistance];

            _artySourcePosX = round (_artySourcePos select 0);
            _artySourcePosY = round (_artySourcePos select 1);
            _artySourcePosZ = round (_artySourcePos select 2);

            _message = "incoming! source: x" + str _artySourcePosX + " y" + str _artySourcePosY + " z" + str _artySourcePosZ;
            [_message] remoteExec ["hint", west];
            sleep 3;
            [""] remoteExec ["hintSilent", west];
        };
    };
};
*/

/*
//Opfor Player
if (_opposedTo_O and _CBRad_Player_Alive_O) then {
    //hint for testing
    ["opfor rad(P) detected shot"] remoteExec ["hint", west];

    private _timeInterval = 10; 
    private _lastMarkerTime = _vehicle getVariable "ArtySourceMarkersTime";
    private _timeSinceLastMarker = time - _lastMarkerTime;

    if (_timeSinceLastMarker > _timeInterval) then {
        [_vehicle] spawn
        {
            params ["_vehicle"];
            _vehicle setVariable ["ArtySourceMarkersTime", time, true];
            private _artySourcePos = getPosASL _vehicle;
            
            _markerName = ("_USER_DEFINED ArtySourceMarker" + str _artySourcePos);
            _markerArray = [_markerName, _artySourcePos, 1];
            
            sleep (RC_Timer1);
            private _artySourceMarker = createMarker [_markerName, _artySourcePos, 1];
            [_artySourceMarker, "o_art"] remoteExec ["setMarkerType", east];
            [_artySourceMarker, 0.7] remoteExec ["setMarkerAlpha", east];
            [_markerName] remoteExec ["deleteMarker", west];
            [_markerName] remoteExec ["deleteMarker", resistance];

            _artySourcePosX = round (_artySourcePos select 0);
            _artySourcePosY = round (_artySourcePos select 1);
            _artySourcePosZ = round (_artySourcePos select 2);

            _message = "incoming! source: x" + str _artySourcePosX + " y" + str _artySourcePosY + " z" + str _artySourcePosZ;
            [_message] remoteExec ["hint", east];
            sleep 3;
            [""] remoteExec ["hintSilent", east];
        };
    };
};
*/