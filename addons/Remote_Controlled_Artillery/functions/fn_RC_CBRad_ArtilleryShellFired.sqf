/*
 * Author: Eric & Ascent
 * If artillery fired and opposing counter battery radar is active:
 * -for players marks opposing indirect fire sources on the map
 * -for AI returns fire on opposing indirect fire sources
*/

/* testing scripts section
[(str RC_ArtilleryArray_O)] remoteExec ["hintSilent", west];
[(str RC_CBRad_AI_Array_O)] remoteExec ["hintSilent", west];
[(str RC_isInRangeArray_O)] remoteExec ["hintSilent", west];
[(str RC_fireMissionArray_O)] remoteExec ["hintSilent", west];
*/

//if artillery fires checks if opposing CBRad is alive, for opposing AI assigns CB firemission, for opposing players creates map markers
addMissionEventHandler ["ArtilleryShellFired", {
    params ["_vehicle", "_weapon", "_ammo", "_gunner", "_instigator", "_artilleryTarget", "_targetPosition", "_shell"];
    //if (!local _vehicle) exitwith {};

    /* would be required for Sholef commander GMG/HMG to not trigger with every shot, hope for BI to fix the EH, or find how to check mag
    _isPrimaryAmmo = _magazine == (currentMagazine _vehicle);  //currentMagazine usually gives mainturret mag, so usually shouldnt trigger for commander turret?
    if (_isPrimaryAmmo) then {
    */

    //checks for opposing CBRad's
    _CBRad_Player_AliveAmount_B = ({alive _x} count RC_CBRad_Player_Array_B);
    _CBRad_Player_AliveAmount_O = ({alive _x} count RC_CBRad_Player_Array_O);
    _CBRad_Player_AliveAmount_I = ({alive _x} count RC_CBRad_Player_Array_I);
    _CBRad_AI_AliveAmount_B = ({alive _x} count RC_CBRad_AI_Array_B);
    _CBRad_AI_AliveAmount_O = ({alive _x} count RC_CBRad_AI_Array_O);
    _CBRad_AI_AliveAmount_I = ({alive _x} count RC_CBRad_AI_Array_I);

    _CBRad_AliveAmount = _CBRad_Player_AliveAmount_B + _CBRad_Player_AliveAmount_O + _CBRad_Player_AliveAmount_I + _CBRad_AI_AliveAmount_B + _CBRad_AI_AliveAmount_O + _CBRad_AI_AliveAmount_I;
    if (!(_CBRad_AliveAmount>0)) exitwith {};
    //if (_CBRad_AliveAmount<1) exitwith {};

    //cleans up CBRad arrays
    RC_CBRad_AI_Array_B = RC_CBRad_AI_Array_B - [objNull];
    RC_CBRad_AI_Array_O = RC_CBRad_AI_Array_O - [objNull];
    RC_CBRad_AI_Array_I = RC_CBRad_AI_Array_I - [objNull];
    publicVariable "RC_CBRad_AI_Array_B";
    publicVariable "RC_CBRad_AI_Array_O";
    publicVariable "RC_CBRad_AI_Array_I";
    RC_CBRad_Player_Array_B = RC_CBRad_Player_Array_B - [objNull];
    RC_CBRad_Player_Array_O = RC_CBRad_Player_Array_O - [objNull];
    RC_CBRad_Player_Array_I = RC_CBRad_Player_Array_I - [objNull];
    publicVariable "RC_CBRad_Player_Array_B";
    publicVariable "RC_CBRad_Player_Array_O";
    publicVariable "RC_CBRad_Player_Array_I";
    
    //checks side of the vehicle
    _vehicleSide_B = (side _vehicle == west);
    _vehicleSide_O = (side _vehicle == east);
    _vehicleSide_I = (side _vehicle == resistance);

    //checks opposing sides
    _opposedTo_B = [side _vehicle, west] call BIS_fnc_sideIsEnemy;
    _opposedTo_O = [side _vehicle, east] call BIS_fnc_sideIsEnemy;
    _opposedTo_I = [side _vehicle, resistance] call BIS_fnc_sideIsEnemy;

    //conciders potential prior CB firemission completed
    switch (true) do {
        case(_vehicleSide_B): {
            RC_fireMissionArray_B deleteAt (RC_fireMissionArray_B find _vehicle);
            publicVariable "RC_fireMissionArray_B";
            //hint for testing
            //[str RC_fireMissionArray_B] remoteExec ["hint", west];
        };
        case(_vehicleSide_O): {
            RC_fireMissionArray_O deleteAt (RC_fireMissionArray_O find _vehicle);
            publicVariable "RC_fireMissionArray_O";
            //hint for testing
            //[str RC_fireMissionArray_O] remoteExec ["hint", west];
        };
        case(_vehicleSide_I): {
            RC_fireMissionArray_I deleteAt (RC_fireMissionArray_I find _vehicle);
            publicVariable "RC_fireMissionArray_I";
            //hint for testing
            //[str RC_fireMissionArray_I] remoteExec ["hint", west];
        };
    };

    //------------------------------------------------------------------


    //Blufor AI
    if (_opposedTo_B and (_CBRad_AI_AliveAmount_B>0)) then {
        //hint for testing
        ["blufor rad(AI) detected shot"] remoteExec ["hint", west];

        //removes objNull from array
        RC_ArtilleryArray_B = RC_ArtilleryArray_B - [objNull];
        RC_isInRangeArray_B = RC_isInRangeArray_B - [objNull];
        publicVariable "RC_ArtilleryArray_B";
        publicVariable "RC_isInRangeArray_B";

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
            publicVariable "RC_isInRangeArray_B";


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
                //changes locality of asset to server, as somehow only there doArtilleryFire works
                //_isInRange_O setOwner 2;
                //[_isInRange_B, 2] remoteExec ["setOwner", 2];
                //_isInRange_B doArtilleryFire [_vehiclePos, (currentMagazine _isInRange_B), 1];
                _isInRange_B_Owner = owner _isInRange_B;
                [_isInRange_B, [_vehiclePos, (currentMagazine _isInRange_B), 1]] remoteExec ["doArtilleryFire", _isInRange_B_Owner];
                
                //if it doesnt shoot in time, firemission will be passed to next in isInRangeArray
                RC_fireMissionArray_B pushback _isInRange_B;
                publicVariable "RC_fireMissionArray_B";
                sleep RC_Timer3;
                _fireMissionNotCompleted = (({_x == _isInRange_B} count RC_fireMissionArray_B) > 0);

                if (_fireMissionNotCompleted) then
                {
                    if ((count RC_isInRangeArray_B) > 1) then
                    {
                        //hint for testing
                        ["first blufor firemission failed"] remoteExec ["hint", west];

                        //selects second opposing artillery in range to return fire
                        _isInRange_B = (RC_isInRangeArray_B select 1);
                        //changes locality of asset to server, as somehow only there doArtilleryFire works
                        //_isInRange_O setOwner 2;
                        //[_isInRange_B, 2] remoteExec ["setOwner", 2];
                        //_isInRange_B doArtilleryFire [_vehiclePos, (currentMagazine _isInRange_B), 1];
                        _isInRange_B_Owner = owner _isInRange_B;
                        [_isInRange_B, [_vehiclePos, (currentMagazine _isInRange_B), 1]] remoteExec ["doArtilleryFire", _isInRange_B_Owner];
                        
                        //if it doesnt shoot in time, firemission will be passed to next in isInRangeArray
                        RC_fireMissionArray_B pushback _isInRange_B;
                        publicVariable "RC_fireMissionArray_B";
                        sleep RC_Timer3;
                        _fireMissionNotCompleted = (({_x == _isInRange_B} count RC_fireMissionArray_B) > 0);

                        if (_fireMissionNotCompleted) then
                        {
                            if ((count RC_isInRangeArray_B) > 2) then
                            {
                                //hint for testing
                                ["second blufor firemission failed"] remoteExec ["hint", west];

                                //selects third opposing artillery in range to return fire
                                _isInRange_B = (RC_isInRangeArray_B select 2);
                                //changes locality of asset to server, as somehow only there doArtilleryFire works
                                //_isInRange_O setOwner 2;
                                //[_isInRange_B, 2] remoteExec ["setOwner", 2];
                                //_isInRange_B doArtilleryFire [_vehiclePos, (currentMagazine _isInRange_B), 1];
                                _isInRange_B_Owner = owner _isInRange_B;
                                [_isInRange_B, [_vehiclePos, (currentMagazine _isInRange_B), 1]] remoteExec ["doArtilleryFire", _isInRange_B_Owner];
                            };
                        };
                    };
                };
            };
        };
    };


    //Opfor AI
    if (_opposedTo_O and (_CBRad_AI_AliveAmount_O>0)) then {
        //hint for testing
        ["opfor rad(AI) detected shot"] remoteExec ["hint", west];

        //removes objNull from array
        RC_ArtilleryArray_O = RC_ArtilleryArray_O - [objNull];
        RC_isInRangeArray_O = RC_isInRangeArray_O - [objNull];
        publicVariable "RC_ArtilleryArray_O";
        publicVariable "RC_isInRangeArray_O";

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
            publicVariable "RC_isInRangeArray_O";


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
                //changes locality of asset to server, as somehow only there doArtilleryFire works
                //_isInRange_O setOwner 2;
                //[_isInRange_O, 2] remoteExec ["setOwner", 2];
                //_isInRange_O doArtilleryFire [_vehiclePos, (currentMagazine _isInRange_O), 1];
                _isInRange_O_Owner = owner _isInRange_O;
                [_isInRange_O, [_vehiclePos, (currentMagazine _isInRange_O), 1]] remoteExec ["doArtilleryFire", _isInRange_O_Owner];
                
                //if it doesnt shoot in time, firemission will be passed to next in isInRangeArray
                RC_fireMissionArray_O pushback _isInRange_O;
                publicVariable "RC_fireMissionArray_O";
                sleep RC_Timer3;
                _fireMissionNotCompleted = (({_x == _isInRange_O} count RC_fireMissionArray_O) > 0);

                if (_fireMissionNotCompleted) then
                {
                    if ((count RC_isInRangeArray_O) > 1) then
                    {
                        //hint for testing
                        ["first opfor firemission failed"] remoteExec ["hint", west];

                        //selects second opposing artillery in range to return fire
                        _isInRange_O = (RC_isInRangeArray_O select 1);
                        //changes locality of asset to server, as somehow only there doArtilleryFire works
                        //_isInRange_O setOwner 2;
                        //[_isInRange_O, 2] remoteExec ["setOwner", 2];
                        //_isInRange_O doArtilleryFire [_vehiclePos, (currentMagazine _isInRange_O), 1];
                        _isInRange_O_Owner = owner _isInRange_O;
                        [_isInRange_O, [_vehiclePos, (currentMagazine _isInRange_O), 1]] remoteExec ["doArtilleryFire", _isInRange_O_Owner];
                        
                        //if it doesnt shoot in time, firemission will be passed to next in isInRangeArray
                        RC_fireMissionArray_O pushback _isInRange_O;
                        publicVariable "RC_fireMissionArray_O";
                        sleep RC_Timer3;
                        _fireMissionNotCompleted = (({_x == _isInRange_O} count RC_fireMissionArray_O) > 0);

                        if (_fireMissionNotCompleted) then
                        {
                            if ((count RC_isInRangeArray_O) > 2) then
                            {
                                //hint for testing
                                ["second opfor firemission failed"] remoteExec ["hint", west];

                                //selects third opposing artillery in range to return fire
                                _isInRange_O = (RC_isInRangeArray_O select 2);
                                //changes locality of asset to server, as somehow only there doArtilleryFire works
                                //_isInRange_O setOwner 2;
                                //[_isInRange_O, 2] remoteExec ["setOwner", 2];
                                //_isInRange_O doArtilleryFire [_vehiclePos, (currentMagazine _isInRange_O), 1];
                                _isInRange_O_Owner = owner _isInRange_O;
                                [_isInRange_O, [_vehiclePos, (currentMagazine _isInRange_O), 1]] remoteExec ["doArtilleryFire", _isInRange_O_Owner];
                            };
                        };
                    };
                };
            };
        };
    };


    //Infor AI
    if (_opposedTo_I and (_CBRad_AI_AliveAmount_I>0)) then {
        //hint for testing
        ["infor rad(AI) detected shot"] remoteExec ["hint", west];

        //removes objNull from array
        RC_ArtilleryArray_I = RC_ArtilleryArray_I - [objNull];
        RC_isInRangeArray_I = RC_isInRangeArray_I - [objNull];
        publicVariable "RC_ArtilleryArray_I";
        publicVariable "RC_isInRangeArray_I";

        //shot source position
        _vehiclePos = getPos _vehicle;
        [_vehiclePos] spawn
        {
            params ["_vehiclePos"];
            //CBRad detection time (same for players & AI)
            sleep RC_Timer1;

            //hint for testing
            _testHintB = "infor artillery:"+ str RC_ArtilleryArray_I;
            [_testHintB] remoteExec ["hint", west];

            //simulating AI preperation time before shot (AI only), half to show hints better
            sleep (RC_Timer2 / 2);


            //checks if opposing artillery is in range
            //RC_isInRangeArray_I = []; //good or bad idea to empty the array?
            {
                RC_isInRangeArray_I deleteAt (RC_isInRangeArray_I find _x); //prevents doubles in array
                _isNull = isNull _x;
                if !(_isNull) then
                {
                    _isInRange = _vehiclePos inRangeOfArtillery [[_x], (currentMagazine _x)];
                    _isAlive = alive _x;
                    if (_isInRange && _isAlive) then {
                        RC_isInRangeArray_I pushback _x;
                    };
                };
                sleep 0.1;
            } forEach RC_ArtilleryArray_I;
            publicVariable "RC_isInRangeArray_I";


            //hint for testing
            if ((count RC_isInRangeArray_I) < 1) then {["no infor inRange"] remoteExec ["hint", west];};

            //true if atleast 1 opposing artillery is in range
            if ((count RC_isInRangeArray_I) > 0) then
            {
                //hint for testing
                _isInRangeHintB = "infor in range:"+ str RC_isInRangeArray_I;
                [_isInRangeHintB] remoteExec ["hint", west];

                //simulating AI preperation time before shot (AI only), half to show hints better
                sleep (RC_Timer2 / 2);

                //selects first opposing artillery in range to return fire
                _isInRange_I = (RC_isInRangeArray_I select 0);
                //changes locality of asset to server, as somehow only there doArtilleryFire works
                //_isInRange_O setOwner 2;
                //[_isInRange_I, 2] remoteExec ["setOwner", 2];
                //_isInRange_I doArtilleryFire [_vehiclePos, (currentMagazine _isInRange_I), 1];
                _isInRange_I_Owner = owner _isInRange_I;
                [_isInRange_I, [_vehiclePos, (currentMagazine _isInRange_I), 1]] remoteExec ["doArtilleryFire", _isInRange_I_Owner];
                
                //if it doesnt shoot in time, firemission will be passed to next in isInRangeArray
                RC_fireMissionArray_I pushback _isInRange_I;
                publicVariable "RC_fireMissionArray_I";
                sleep RC_Timer3;
                _fireMissionNotCompleted = (({_x == _isInRange_I} count RC_fireMissionArray_I) > 0);

                if (_fireMissionNotCompleted) then
                {
                    if ((count RC_isInRangeArray_I) > 1) then
                    {
                        //hint for testing
                        ["first infor firemission failed"] remoteExec ["hint", west];

                        //selects second opposing artillery in range to return fire
                        _isInRange_I = (RC_isInRangeArray_I select 1);
                        //changes locality of asset to server, as somehow only there doArtilleryFire works
                        //_isInRange_O setOwner 2;
                        //[_isInRange_I, 2] remoteExec ["setOwner", 2];
                        //_isInRange_I doArtilleryFire [_vehiclePos, (currentMagazine _isInRange_I), 1];
                        _isInRange_I_Owner = owner _isInRange_I;
                        [_isInRange_I, [_vehiclePos, (currentMagazine _isInRange_I), 1]] remoteExec ["doArtilleryFire", _isInRange_I_Owner];
                        
                        //if it doesnt shoot in time, firemission will be passed to next in isInRangeArray
                        RC_fireMissionArray_I pushback _isInRange_I;
                        publicVariable "RC_fireMissionArray_I";
                        sleep RC_Timer3;
                        _fireMissionNotCompleted = (({_x == _isInRange_I} count RC_fireMissionArray_I) > 0);

                        if (_fireMissionNotCompleted) then
                        {
                            if ((count RC_isInRangeArray_I) > 2) then
                            {
                                //hint for testing
                                ["second infor firemission failed"] remoteExec ["hint", west];

                                //selects third opposing artillery in range to return fire
                                _isInRange_I = (RC_isInRangeArray_I select 2);
                                //changes locality of asset to server, as somehow only there doArtilleryFire works
                                //_isInRange_O setOwner 2;
                                //[_isInRange_I, 2] remoteExec ["setOwner", 2];
                                //_isInRange_I doArtilleryFire [_vehiclePos, (currentMagazine _isInRange_I), 1];
                                _isInRange_I_Owner = owner _isInRange_I;
                                [_isInRange_I, [_vehiclePos, (currentMagazine _isInRange_I), 1]] remoteExec ["doArtilleryFire", _isInRange_I_Owner];
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

if (_opposedTo_B and _CBRad_Player_AliveAmount_B) then {
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
if (_opposedTo_O and _CBRad_Player_AliveAmount_O) then {
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