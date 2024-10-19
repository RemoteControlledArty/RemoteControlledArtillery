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

_owner = str (owner _this);
[_owner] remoteExec ["hint", west];

addMissionEventHandler ["ArtilleryShellFired", {
    params ["_vehicle", "_weapon", "_ammo", "_gunner", "_instigator", "_artilleryTarget", "_targetPosition", "_shell"];
    if (!local _vehicle) exitwith {};

    [getPos me, 180, "RC_UAV_AR1", west] call BIS_fnc_spawnVehicle;
]};
*/


//if artillery fires checks if opposing CBRad is alive, for opposing AI assigns CB firemission, for opposing players creates map markers
addMissionEventHandler ["ArtilleryShellFired", {
    params ["_vehicle", "_weapon", "_ammo", "_gunner", "_instigator", "_artilleryTarget", "_targetPosition", "_shell"];
    //if (!local _vehicle) exitwith {};
    if (!isServer) exitwith {};

    /* would be required for Sholef commander GMG/HMG to not trigger with every shot, hope for BI to fix the EH, or find how to check mag
    _isPrimaryAmmo = _magazine == (currentMagazine _vehicle);  //currentMagazine usually gives mainturret mag, so usually shouldnt trigger for commander turret?
    if (_isPrimaryAmmo) then {
    */

    //checks for opposing CBRad's
    _CBRad_Player_AliveAmount_B = ({alive _x} count RC_CBRad_Player_Array_B);
    _CBRad_Player_AliveAmount_O = ({alive _x} count RC_CBRad_Player_Array_O);
    _CBRad_AI_AliveAmount_B = ({alive _x} count RC_CBRad_AI_Array_B);
    _CBRad_AI_AliveAmount_O = ({alive _x} count RC_CBRad_AI_Array_O);

    _CBRad_AliveAmount = _CBRad_Player_AliveAmount_B + _CBRad_Player_AliveAmount_O+ _CBRad_AI_AliveAmount_B + _CBRad_AI_AliveAmount_O;
    if (!(_CBRad_AliveAmount>0)) exitwith {};
    //if (_CBRad_AliveAmount<1) exitwith {};

    //cleans up CBRad arrays
    RC_CBRad_AI_Array_B = RC_CBRad_AI_Array_B - [objNull];
    RC_CBRad_AI_Array_O = RC_CBRad_AI_Array_O - [objNull];
    publicVariable "RC_CBRad_AI_Array_B";
    publicVariable "RC_CBRad_AI_Array_O";
    RC_CBRad_Player_Array_B = RC_CBRad_Player_Array_B - [objNull];
    RC_CBRad_Player_Array_O = RC_CBRad_Player_Array_O - [objNull];
    publicVariable "RC_CBRad_Player_Array_B";
    publicVariable "RC_CBRad_Player_Array_O";
    
    //checks side of the vehicle
    _vehicleSide_B = (side _vehicle == west);
    _vehicleSide_O = (side _vehicle == east);

    //checks opposing sides
    _opposedTo_B = [side _vehicle, west] call BIS_fnc_sideIsEnemy;
    _opposedTo_O = [side _vehicle, east] call BIS_fnc_sideIsEnemy;

    //conciders potential prior CB firemission completed
    switch (true) do {
        case(_vehicleSide_B): {
            RC_fireMissionArray_B deleteAt (RC_fireMissionArray_B find _vehicle);
            publicVariable "RC_fireMissionArray_B";
        };
        case(_vehicleSide_O): {
            RC_fireMissionArray_O deleteAt (RC_fireMissionArray_O find _vehicle);
            publicVariable "RC_fireMissionArray_O";
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
                                _isInRange_O_Owner = owner _isInRange_O;
                                [_isInRange_O, [_vehiclePos, (currentMagazine _isInRange_O), 1]] remoteExec ["doArtilleryFire", _isInRange_O_Owner];
                            };
                        };
                    };
                };
            };
        };
    };

    //Blufor Player
    if (_opposedTo_B and (_CBRad_Player_AliveAmount_B>0)) then {
        //for testing
        ["blufor rad(P) detected shot"] remoteExec ["hint", west];

        //private _timeInterval = 10;
        //private _lastMarkerTime = _vehiclePos getVariable "ArtySourceMarkersTime";
        //private _timeSinceLastMarker = time - _lastMarkerTime;

        //if (_timeSinceLastMarker > _timeInterval) then {
            [_vehicle, _targetPosition] spawn {
                params ["_vehicle", "_targetPosition"];
                //_vehicle setVariable ["ArtySourceMarkersTime", time, true];
                private _artySourcePos = getPosASL _vehicle;

                _roundedArtySourcePosX = round (_artySourcePos select 0);
                _roundedArtySourcePosY = round (_artySourcePos select 1);
                _markerName = ("_USER_DEFINED_" + str _roundedArtySourcePosX + str _roundedArtySourcePosY);
                deleteMarker _markerName;   //preventing doubles and outdated timestamp

                //_random = random [0, 10, 20];
                //_markerName = format ["%1%2", "_USER_DEFINED_", _random];

                sleep (RC_Timer1);

                private _artySourceMarker = createMarkerLocal [_markerName, _artySourcePos, 0];    //later sidechannel 1
                _artySourceMarker setMarkerTypeLocal "o_art";
                _artySourceMarker setMarkerAlphaLocal 1;
                _artySourceMarker setMarkerSizeLocal [0.6,0.6];
                
                _artySourceMarkerHour = date select 3;
                _artySourceMarkerMinute = date select 4;
                if (_artySourceMarkerMinute < 10) then {
                    _artySourceMarkerText = str _artySourceMarkerHour + ":0" + str _artySourceMarkerMinute;
                    _artySourceMarker setMarkerTextLocal format ["%1", _artySourceMarkerText];
                } else {
                    _artySourceMarkerText = str _artySourceMarkerHour + ":" + str _artySourceMarkerMinute;
                    _artySourceMarker setMarkerTextLocal format ["%1", _artySourceMarkerText];
                };

                _artySourceMarker setMarkerColor "ColorOrange";
                [_markerName] remoteExec ["deleteMarkerLocal", east];
                [_markerName] remoteExec ["deleteMarkerLocal", resistance];
                

                _artySourceGrid = mapGridPosition _artySourcePos;
                _artySourceGridX = _artySourceGrid select [0, 3];
                _artySourceGridY = _artySourceGrid select [3, 3];
                _targetGrid = mapGridPosition _targetPosition;
                _targetGridX = _targetGrid select [0, 3];
                _targetGridY = _targetGrid select [3, 3];

                if ((_targetPosition select 0) == 0) then {
                    _message = "INCOMING" + "\n" + "target: ???-???" + "\n" + "source: " + _artySourceGridX + "-" + _artySourceGridY;
                    [["\A3\Sounds_F\vehicles\air\noises\alarm_locked_by_missile_4.wss", 0.15]] remoteExec ["playSoundUI", west];
                    [_message] remoteExec ["hintSilent", west];
                    sleep 5;
                    [""] remoteExec ["hintSilent", west];
                } else {
                    _message = "INCOMING" + "\n" + "target: " + _targetGridX + "-" + _targetGridY + "\n" + "source: " + _artySourceGridX + "-" + _artySourceGridY;
                    [["\A3\Sounds_F\vehicles\air\noises\alarm_locked_by_missile_4.wss", 0.15]] remoteExec ["playSoundUI", west];
                    [_message] remoteExec ["hintSilent", west];
                    sleep 5;
                    [""] remoteExec ["hintSilent", west];
                };
            };
        //};
    };

    //Opfor Player
    if (_opposedTo_O and (_CBRad_Player_AliveAmount_O>0)) then {
        //for testing
        ["opfor rad(P) detected shot"] remoteExec ["hint", west];

        //private _timeInterval = 10;
        //private _lastMarkerTime = _vehiclePos getVariable "ArtySourceMarkersTime";
        //private _timeSinceLastMarker = time - _lastMarkerTime;

        //if (_timeSinceLastMarker > _timeInterval) then {
            [_vehicle, _targetPosition] spawn {
                params ["_vehicle", "_targetPosition"];
                //_vehicle setVariable ["ArtySourceMarkersTime", time, true];
                private _artySourcePos = getPosASL _vehicle;

                _roundedArtySourcePosX = round (_artySourcePos select 0);
                _roundedArtySourcePosY = round (_artySourcePos select 1);
                _markerName = ("_USER_DEFINED_" + str _roundedArtySourcePosX + str _roundedArtySourcePosY);
                deleteMarker _markerName;   //preventing doubles and outdated timestamp

                //_random = random [0, 10, 20];
                //_markerName = format ["%1%2", "_USER_DEFINED_", _random];

                sleep (RC_Timer1);

                private _artySourceMarker = createMarkerLocal [_markerName, _artySourcePos, 0];    //later sidechannel 1
                _artySourceMarker setMarkerTypeLocal "o_art";
                _artySourceMarker setMarkerAlphaLocal 1;
                _artySourceMarker setMarkerSizeLocal [0.6,0.6];
                
                _artySourceMarkerHour = date select 3;
                _artySourceMarkerMinute = date select 4;
                if (_artySourceMarkerMinute < 10) then {
                    _artySourceMarkerText = str _artySourceMarkerHour + ":0" + str _artySourceMarkerMinute;
                    _artySourceMarker setMarkerTextLocal format ["%1", _artySourceMarkerText];
                } else {
                    _artySourceMarkerText = str _artySourceMarkerHour + ":" + str _artySourceMarkerMinute;
                    _artySourceMarker setMarkerTextLocal format ["%1", _artySourceMarkerText];
                };

                _artySourceMarker setMarkerColor "ColorOrange";
                [_markerName] remoteExec ["deleteMarkerLocal", west];
                [_markerName] remoteExec ["deleteMarkerLocal", resistance];


                _artySourceGrid = mapGridPosition _artySourcePos;
                _artySourceGridX = _artySourceGrid select [0, 3];
                _artySourceGridY = _artySourceGrid select [3, 3];
                _targetGrid = mapGridPosition _targetPosition;
                _targetGridX = _targetGrid select [0, 3];
                _targetGridY = _targetGrid select [3, 3];

                if ((_targetPosition select 0) == 0) then {
                    _message = "INCOMING" + "\n" + "target: ???-???" + "\n" + "source: " + _artySourceGridX + "-" + _artySourceGridY;
                    [["\A3\Sounds_F\vehicles\air\noises\alarm_locked_by_missile_4.wss", 0.15]] remoteExec ["playSoundUI", east];
                    [_message] remoteExec ["hintSilent", east];
                    sleep 5;
                    [""] remoteExec ["hintSilent", east];
                } else {
                    _message = "INCOMING" + "\n" + "target: " + _targetGridX + "-" + _targetGridY + "\n" + "source: " + _artySourceGridX + "-" + _artySourceGridY;
                    [["\A3\Sounds_F\vehicles\air\noises\alarm_locked_by_missile_4.wss", 0.15]] remoteExec ["playSoundUI", east];
                    [_message] remoteExec ["hintSilent", east];
                    sleep 5;
                    [""] remoteExec ["hintSilent", east];
                };
            };
        //};
    };
}];

    /*
    [_vehicle, _targetPosition] spawn {
        params ["_vehicle", "_targetPosition"];
        _vehicle setVariable ["ArtySourceMarkersTime", time, true];
        private _artySourcePos = getPosASL _vehicle;

        //_markerName = ("_USER_DEFINED ArtySourceMarker" + str _artySourcePos);
        //_markerArray = [_markerName, _artySourcePos, 1];

        sleep (RC_Timer1);
        //_artySourceMarker = createMarkerLocal [_markerName, _artySourcePos, 1];
        _markerName = random [0, 10, 20];
	    _markerArray = format ["%1%2", "_USER_DEFINED_", _markerName];
        _artySourceMarker = createMarkerLocal [_markerArray, _artySourcePos, 1];
        _artySourceMarker setMarkerTypeLocal "o_art";
        _artySourceMarker setMarkerAlphaLocal 1;
        _artySourceMarker setMarkerSizeLocal [0.6,0.6];

        _artySourceMarkerHour = date select 3;
        _artySourceMarkerMinute = date select 4;
        if (_artySourceMarkerMinute < 10) then {
            _artySourceMarkerText = str _artySourceMarkerHour + ":0" + str _artySourceMarkerMinute;
            _artySourceMarker setMarkerTextLocal format ["%1", _artySourceMarkerText];
        } else {
            _artySourceMarkerText = str _artySourceMarkerHour + ":" + str _artySourceMarkerMinute;
            _artySourceMarker setMarkerTextLocal format ["%1", _artySourceMarkerText];
        };

        _artySourceMarker setMarkerColor "ColorOrange";

        [_markerName] remoteExec ["deleteMarkerLocal", west];
        [_markerName] remoteExec ["deleteMarkerLocal", resistance];

        _artySourceGrid = mapGridPosition _artySourcePos;
        _artySourceGridX = _artySourceGrid select [0, 3];
        _artySourceGridY = _artySourceGrid select [3, 3];
        _targetGrid = mapGridPosition _targetPosition;
        _targetGridX = _targetGrid select [0, 3];
        _targetGridY = _targetGrid select [3, 3];

        if ((_targetPosition select 0) == 0) then {
            _message = "INCOMING" + "\n" + "target: ???-???" + "\n" + "source: " + _artySourceGridX + "-" + _artySourceGridY;
            [["\A3\Sounds_F\vehicles\air\noises\alarm_locked_by_missile_4.wss", 0.15]] remoteExec ["playSoundUI", east];
            [_message] remoteExec ["hintSilent", east];
            sleep 5;
            [""] remoteExec ["hintSilent", east];
        } else {
            _message = "INCOMING" + "\n" + "target: " + _targetGridX + "-" + _targetGridY + "\n" + "source: " + _artySourceGridX + "-" + _artySourceGridY;
            [["\A3\Sounds_F\vehicles\air\noises\alarm_locked_by_missile_4.wss", 0.15]] remoteExec ["playSoundUI", east];
            [_message] remoteExec ["hintSilent", east];
            sleep 5;
            [""] remoteExec ["hintSilent", east];
        };
    };
    */


/*
_vehicle = vic;
_artySourcePos = getPosASL _vehicle;

_markerName = random [0, 10, 20];
_markerArray = format ["%1%2", "_USER_DEFINED_", _markerName];

_artySourceMarker = createMarkerLocal [_markerArray, _artySourcePos, 1];
_artySourceMarker setMarkerTypeLocal "o_art";
_artySourceMarker setMarkerAlphaLocal 1;
_artySourceMarker setMarkerSizeLocal [0.6,0.6];

_artySourceMarker setMarkerColor "ColorOrange";
*/


/*
_vehicle = vic;
_artySourcePos = getPosASL _vehicle;

_markerName = ("_USER_DEFINED ArtySourceMarker" + str _artySourcePos);
_markerArray = [_markerName, _artySourcePos, 1];

_artySourceMarker = createMarkerLocal [_markerName, _artySourcePos, 1];
_artySourceMarker setMarkerTypeLocal "o_art";
_artySourceMarker setMarkerAlphaLocal 1;
_artySourceMarker setMarkerSizeLocal [0.6,0.6];

[_artySourceMarker, "o_art"] remoteExec ["setMarkerTypeLocal", 0];
[_artySourceMarker, 1] remoteExec ["setMarkerAlphaLocal", 0];
[_artySourceMarker, [0.6,0.6]] remoteExec ["setMarkerSizeLocal", 0];
[_artySourceMarker, "ColorOrange"] remoteExec ["setMarkerColor", 0];
*/


/*
Putting that here for later, this works run local, not on server.
```sqf
_vehicle = _this;
_pos = getPosASL _vehicle;

_randomName = random [0, 10, 20];
_markerName = format ["%1%2", "_USER_DEFINED_", _randomName];
```

local to global
```sqf
_marker = createMarkerLocal [_markerName, _pos, 1];
_marker setMarkerTypeLocal "hd_destroy";
_marker setMarkerAlphaLocal 1;

_marker setMarkerColor "ColorBlue";  //non, 
```

global
```sqf
_marker = createMarker [_markerName, _pos, 1];
_marker setMarkerType "hd_destroy";
_marker setMarkerAlpha 1;

_marker setMarkerColor "ColorBlue";
```

RE
```sqf
_vehicle = _this;
_pos = getPosASL _vehicle;
_randomName = random [0, 10, 20];
_markerName = format ["%1%2", "_USER_DEFINED_", _randomName];
_marker = createMarker [_markerName, _pos, 1];
[_marker, "hd_destroy"] remoteExec ["setMarkerType", 4];
[_marker, 1] remoteExec ["setMarkerAlpha", 4];
[_marker, "ColorBlue"] remoteExec ["setMarkerColor", 4];
```
*/


/*
_vehicle = vic;
_artySourcePos = getPosASL _vehicle;

_markerName = ("_USER_DEFINED ArtySourceMarker" + str _artySourcePos);
_markerArray = [_markerName, _artySourcePos, 1];

_artySourceMarker = createMarker [_markerName, _artySourcePos, 1];
_artySourceMarker setMarkerType "o_art";
_artySourceMarker setMarkerAlpha 1;
_artySourceMarker setMarkerSize [0.6,0.6];
_artySourceMarker setMarkerColor "ColorOrange";
*/


//[_markerName] remoteExec ["deleteMarkerLocal", west];   //causes problems, not use for now
//[_markerName] remoteExec ["deleteMarkerLocal", resistance];   //causes problems, not use for now

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