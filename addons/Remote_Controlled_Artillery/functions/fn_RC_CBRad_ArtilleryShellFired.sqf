/*
 * Author: Eric & Ascent
 * If artillery fired and opposing counter battery radar is active:
 * -for players marks opposing indirect fire sources on the map
 * -for AI returns fire on opposing indirect fire sources
*/

//if artillery fires checks if opposing CBRad is alive, for opposing AI assigns CB firemission, for opposing players creates map markers
addMissionEventHandler ["ArtilleryShellFired", {
    params ["_vehicle", "_weapon", "_ammo", "_gunner", "_instigator", "_artilleryTarget", "_targetPosition", "_shell"];
    if (!isServer) exitwith {};

    //checks for opposing CBRad's
    _CBRad_Player_AliveAmount_B = ({alive _x} count RC_CBRad_Player_Array_B);
    _CBRad_Player_AliveAmount_O = ({alive _x} count RC_CBRad_Player_Array_O);
    _CBRad_AI_AliveAmount_B = ({alive _x} count RC_CBRad_AI_Array_B);
    _CBRad_AI_AliveAmount_O = ({alive _x} count RC_CBRad_AI_Array_O);

    _CBRad_AliveAmount = _CBRad_Player_AliveAmount_B + _CBRad_Player_AliveAmount_O+ _CBRad_AI_AliveAmount_B + _CBRad_AI_AliveAmount_O;
    if (!(_CBRad_AliveAmount>0)) exitwith {};

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


    //Blufor AI
    if (_opposedTo_B and (_CBRad_AI_AliveAmount_B>0)) then {

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
            sleep RC_DetectionTime_Test1;

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

            //true if atleast 1 opposing artillery is in range
            if ((count RC_isInRangeArray_B) > 0) then
            {
                //simulating AI preperation time before shot (AI only)
                sleep RC_PrepTime_Test1;

                //selects first opposing artillery in range to return fire
                _isInRange_B = (RC_isInRangeArray_B select 0);
                //changes locality of asset to server, as somehow only there doArtilleryFire works
                _isInRange_B_Owner = owner _isInRange_B;
                [_isInRange_B, [_vehiclePos, (currentMagazine _isInRange_B), 1]] remoteExec ["doArtilleryFire", _isInRange_B_Owner];
                
                //if it doesnt shoot in time, firemission will be passed to next in isInRangeArray
                RC_fireMissionArray_B pushback _isInRange_B;
                publicVariable "RC_fireMissionArray_B";
                sleep RC_ReassignTime_Test1;
                _fireMissionNotCompleted = (({_x == _isInRange_B} count RC_fireMissionArray_B) > 0);

                if (_fireMissionNotCompleted) then
                {
                    if ((count RC_isInRangeArray_B) > 1) then
                    {
                        //selects second opposing artillery in range to return fire
                        _isInRange_B = (RC_isInRangeArray_B select 1);
                        //changes locality of asset to server, as somehow only there doArtilleryFire works
                        _isInRange_B_Owner = owner _isInRange_B;
                        [_isInRange_B, [_vehiclePos, (currentMagazine _isInRange_B), 1]] remoteExec ["doArtilleryFire", _isInRange_B_Owner];
                        
                        //if it doesnt shoot in time, firemission will be passed to next in isInRangeArray
                        RC_fireMissionArray_B pushback _isInRange_B;
                        publicVariable "RC_fireMissionArray_B";
                        sleep RC_ReassignTime_Test1;
                        _fireMissionNotCompleted = (({_x == _isInRange_B} count RC_fireMissionArray_B) > 0);

                        if (_fireMissionNotCompleted) then
                        {
                            if ((count RC_isInRangeArray_B) > 2) then
                            {
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
            sleep RC_DetectionTime_Test1;

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

            //true if atleast 1 opposing artillery is in range
            if ((count RC_isInRangeArray_O) > 0) then
            {
                //simulating AI preperation time before shot (AI only)
                sleep RC_PrepTime_Test1;

                //selects first opposing artillery in range to return fire
                _isInRange_O = (RC_isInRangeArray_O select 0);
                //changes locality of asset to server, as somehow only there doArtilleryFire works
                _isInRange_O_Owner = owner _isInRange_O;
                [_isInRange_O, [_vehiclePos, (currentMagazine _isInRange_O), 1]] remoteExec ["doArtilleryFire", _isInRange_O_Owner];
                
                //if it doesnt shoot in time, firemission will be passed to next in isInRangeArray
                RC_fireMissionArray_O pushback _isInRange_O;
                publicVariable "RC_fireMissionArray_O";
                sleep RC_ReassignTime_Test1;
                _fireMissionNotCompleted = (({_x == _isInRange_O} count RC_fireMissionArray_O) > 0);

                if (_fireMissionNotCompleted) then
                {
                    if ((count RC_isInRangeArray_O) > 1) then
                    {
                        //selects second opposing artillery in range to return fire
                        _isInRange_O = (RC_isInRangeArray_O select 1);
                        //changes locality of asset to server, as somehow only there doArtilleryFire works
                        _isInRange_O_Owner = owner _isInRange_O;
                        [_isInRange_O, [_vehiclePos, (currentMagazine _isInRange_O), 1]] remoteExec ["doArtilleryFire", _isInRange_O_Owner];
                        
                        //if it doesnt shoot in time, firemission will be passed to next in isInRangeArray
                        RC_fireMissionArray_O pushback _isInRange_O;
                        publicVariable "RC_fireMissionArray_O";
                        sleep RC_ReassignTime_Test1;
                        _fireMissionNotCompleted = (({_x == _isInRange_O} count RC_fireMissionArray_O) > 0);

                        if (_fireMissionNotCompleted) then
                        {
                            if ((count RC_isInRangeArray_O) > 2) then
                            {
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

                sleep (RC_DetectionTime_Test1);

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

                sleep (RC_DetectionTime_Test1);

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