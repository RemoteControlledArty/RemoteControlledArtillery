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

    private _timeInterval = 10;
    private _lastTime = _vehicle getVariable "ArtySourceTime";
    private _timeSinceLast = time - _lastTime;

    if (_timeSinceLast > _timeInterval) then {
        _vehicle setVariable ["ArtySourceTime", time, true];
    
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
                sleep RC_DetectionTime_F1;

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
                    sleep (RC_PrepTime_F1);

                    //selects first opposing artillery in range to return fire
                    _isInRange_B = (RC_isInRangeArray_B select 0);
                    //changes locality of asset to server, as somehow only there doArtilleryFire works
                    _isInRange_B_Owner = owner _isInRange_B;
                    [_isInRange_B, [_vehiclePos, (currentMagazine _isInRange_B), 1]] remoteExec ["doArtilleryFire", _isInRange_B_Owner];
                    
                    //if it doesnt shoot in time, firemission will be passed to next in isInRangeArray
                    RC_fireMissionArray_B pushback _isInRange_B;
                    publicVariable "RC_fireMissionArray_B";
                    sleep RC_ReassignTime_F1;
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
                            sleep RC_ReassignTime_F1;
                            _fireMissionNotCompleted = (({_x == _isInRange_B} count RC_fireMissionArray_B) > 0);

                            if (_fireMissionNotCompleted) then
                            {
                                if ((count RC_isInRangeArray_B) > 2) then
                                {
                                    //selects second opposing artillery in range to return fire
                                    _isInRange_B = (RC_isInRangeArray_B select 2);
                                    //changes locality of asset to server, as somehow only there doArtilleryFire works
                                    _isInRange_B_Owner = owner _isInRange_B;
                                    [_isInRange_B, [_vehiclePos, (currentMagazine _isInRange_B), 1]] remoteExec ["doArtilleryFire", _isInRange_B_Owner];
                                    
                                    //if it doesnt shoot in time, firemission will be passed to next in isInRangeArray
                                    RC_fireMissionArray_B pushback _isInRange_B;
                                    publicVariable "RC_fireMissionArray_B";
                                    sleep RC_ReassignTime_F1;
                                    _fireMissionNotCompleted = (({_x == _isInRange_B} count RC_fireMissionArray_B) > 0);

                                    if (_fireMissionNotCompleted) then
                                    {
                                        if ((count RC_isInRangeArray_B) > 3) then
                                        {
                                            //selects third opposing artillery in range to return fire
                                            _isInRange_B = (RC_isInRangeArray_B select 3);
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
                sleep RC_DetectionTime_F1;

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
                    sleep (RC_PrepTime_F1);

                    //selects first opposing artillery in range to return fire
                    _isInRange_O = (RC_isInRangeArray_O select 0);
                    //changes locality of asset to server, as somehow only there doArtilleryFire works
                    _isInRange_O_Owner = owner _isInRange_O;
                    [_isInRange_O, [_vehiclePos, (currentMagazine _isInRange_O), 1]] remoteExec ["doArtilleryFire", _isInRange_O_Owner];
                    
                    //if it doesnt shoot in time, firemission will be passed to next in isInRangeArray
                    RC_fireMissionArray_O pushback _isInRange_O;
                    publicVariable "RC_fireMissionArray_O";
                    sleep RC_ReassignTime_F1;
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
                            sleep RC_ReassignTime_F1;
                            _fireMissionNotCompleted = (({_x == _isInRange_O} count RC_fireMissionArray_O) > 0);

                            if (_fireMissionNotCompleted) then
                            {
                                if ((count RC_isInRangeArray_O) > 2) then
                                {
                                    //selects second opposing artillery in range to return fire
                                    _isInRange_O = (RC_isInRangeArray_O select 2);
                                    //changes locality of asset to server, as somehow only there doArtilleryFire works
                                    _isInRange_O_Owner = owner _isInRange_O;
                                    [_isInRange_O, [_vehiclePos, (currentMagazine _isInRange_O), 1]] remoteExec ["doArtilleryFire", _isInRange_O_Owner];
                                    
                                    //if it doesnt shoot in time, firemission will be passed to next in isInRangeArray
                                    RC_fireMissionArray_O pushback _isInRange_O;
                                    publicVariable "RC_fireMissionArray_O";
                                    sleep RC_ReassignTime_F1;
                                    _fireMissionNotCompleted = (({_x == _isInRange_O} count RC_fireMissionArray_O) > 0);

                                    if (_fireMissionNotCompleted) then
                                    {
                                        if ((count RC_isInRangeArray_O) > 3) then
                                        {
                                            //selects third opposing artillery in range to return fire
                                            _isInRange_O = (RC_isInRangeArray_O select 3);
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
            };
        };


        //Infor AI
        if (_opposedTo_I and (_CBRad_AI_AliveAmount_I>0)) then {
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
                sleep RC_DetectionTime_F1;

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

                //true if atleast 1 opposing artillery is in range
                if ((count RC_isInRangeArray_I) > 0) then
                {
                    //simulating AI preperation time before shot (AI only)
                    sleep (RC_PrepTime_F1);

                    //selects first opposing artillery in range to return fire
                    _isInRange_I = (RC_isInRangeArray_I select 0);
                    //changes locality of asset to server, as somehow only there doArtilleryFire works
                    _isInRange_I_Owner = owner _isInRange_I;
                    [_isInRange_I, [_vehiclePos, (currentMagazine _isInRange_I), 1]] remoteExec ["doArtilleryFire", _isInRange_I_Owner];
                    
                    //if it doesnt shoot in time, firemission will be passed to next in isInRangeArray
                    RC_fireMissionArray_I pushback _isInRange_I;
                    publicVariable "RC_fireMissionArray_I";
                    sleep RC_ReassignTime_F1;
                    _fireMissionNotCompleted = (({_x == _isInRange_I} count RC_fireMissionArray_I) > 0);

                    if (_fireMissionNotCompleted) then
                    {
                        if ((count RC_isInRangeArray_I) > 1) then
                        {
                            //selects second opposing artillery in range to return fire
                            _isInRange_I = (RC_isInRangeArray_I select 1);
                            //changes locality of asset to server, as somehow only there doArtilleryFire works
                            _isInRange_I_Owner = owner _isInRange_I;
                            [_isInRange_I, [_vehiclePos, (currentMagazine _isInRange_I), 1]] remoteExec ["doArtilleryFire", _isInRange_I_Owner];
                            
                            //if it doesnt shoot in time, firemission will be passed to next in isInRangeArray
                            RC_fireMissionArray_I pushback _isInRange_I;
                            publicVariable "RC_fireMissionArray_I";
                            sleep RC_ReassignTime_F1;
                            _fireMissionNotCompleted = (({_x == _isInRange_I} count RC_fireMissionArray_I) > 0);

                            if (_fireMissionNotCompleted) then
                            {
                                if ((count RC_isInRangeArray_I) > 2) then
                                {
                                    //selects second opposing artillery in range to return fire
                                    _isInRange_I = (RC_isInRangeArray_I select 2);
                                    //changes locality of asset to server, as somehow only there doArtilleryFire works
                                    _isInRange_I_Owner = owner _isInRange_I;
                                    [_isInRange_I, [_vehiclePos, (currentMagazine _isInRange_I), 1]] remoteExec ["doArtilleryFire", _isInRange_I_Owner];
                                    
                                    //if it doesnt shoot in time, firemission will be passed to next in isInRangeArray
                                    RC_fireMissionArray_I pushback _isInRange_I;
                                    publicVariable "RC_fireMissionArray_I";
                                    sleep RC_ReassignTime_F1;
                                    _fireMissionNotCompleted = (({_x == _isInRange_I} count RC_fireMissionArray_I) > 0);

                                    if (_fireMissionNotCompleted) then
                                    {
                                        if ((count RC_isInRangeArray_I) > 3) then
                                        {
                                            //selects third opposing artillery in range to return fire
                                            _isInRange_I = (RC_isInRangeArray_I select 3);
                                            //changes locality of asset to server, as somehow only there doArtilleryFire works
                                            _isInRange_I_Owner = owner _isInRange_I;
                                            [_isInRange_I, [_vehiclePos, (currentMagazine _isInRange_I), 1]] remoteExec ["doArtilleryFire", _isInRange_I_Owner];
                                        };
                                    };
                                };
                            };
                        };
                    };
                };
            };
        };
    };


    //Blufor Player
    if (_opposedTo_B and (_CBRad_Player_AliveAmount_B>0)) then {

        _ETA = _vehicle getArtilleryETA [_targetPosition, currentMagazine _vehicle];

        [_vehicle, _targetPosition, _timeSinceLast, _timeInterval, _ETA] spawn {
            params ["_vehicle", "_targetPosition", "_timeSinceLast", "_timeInterval", "_ETA"];
            private _artySourcePos = getPosASL _vehicle;

            _artySourceGrid = mapGridPosition _artySourcePos;
            _artySourceGridX = _artySourceGrid select [0, 3];
            _artySourceGridY = _artySourceGrid select [3, 3];
            _targetGrid = mapGridPosition _targetPosition;
            _targetGridX = _targetGrid select [0, 3];
            _targetGridY = _targetGrid select [3, 3];

            _shownETA = round (_ETA - RC_DetectionTime_F1);

            sleep (RC_DetectionTime_F1);

            
            private _radius = 15;
            private _angle = random 360;
            private _randomSquareRoot = sqrt random 1;
            private _distance = _radius * _randomSquareRoot;
            private _markerPosition = _targetPosition getPos [_distance, _angle];
            private _targetMarkerName = ("_USER_DEFINED AproxArtyMarker" + str _markerPosition);
            deleteMarker _targetMarkerName;
            
            private _artyTargetMarker = createMarkerLocal [_targetMarkerName, _markerPosition];
            _artyTargetMarker setMarkerShapeLocal "ELLIPSE"; 
            _artyTargetMarker setMarkerSizeLocal [_radius, _radius];
            _artyTargetMarker setMarkerColorLocal "colorRed";
            _artyTargetMarker setMarkerBrushLocal "SolidBorder";

            _artyTargetMarker setMarkerAlpha 0.5;
            [_targetMarkerName] remoteExec ["deleteMarkerLocal", east];
            [_targetMarkerName] remoteExec ["deleteMarkerLocal", resistance];
            [_targetMarkerName] remoteExec ["deleteMarkerLocal", civilian];

            private _targetMarkerName2 = ("_USER_DEFINED AproxArtyMarker2" + str _markerPosition);
            deleteMarker _targetMarkerName2;
            
            private _artyTargetMarker2 = createMarkerLocal [_targetMarkerName2, _markerPosition];
            _artyTargetMarker2 setMarkerShapeLocal "ELLIPSE"; 
            _artyTargetMarker2 setMarkerSizeLocal [100, 100];
            _artyTargetMarker2 setMarkerColorLocal "colorOrange";
            _artyTargetMarker2 setMarkerBrushLocal "SolidBorder";

            _artyTargetMarker2 setMarkerAlpha 0.3;
            [_targetMarkerName2] remoteExec ["deleteMarkerLocal", east];
            [_targetMarkerName2] remoteExec ["deleteMarkerLocal", resistance];
            [_targetMarkerName2] remoteExec ["deleteMarkerLocal", civilian];
            

            /*
            _roundedArtyTargetPosX = round (_targetPosition select 0);
            _roundedArtyTargetPosY = round (_targetPosition select 1);
            _targetMarkerName = ("_USER_DEFINED_" + str _roundedArtyTargetPosX + str _roundedArtyTargetPosY);
            deleteMarker _targetMarkerName;   //preventing doubles and outdated timestamp

            private _artyTargetMarker = createMarkerLocal [_targetMarkerName, _targetPosition];
            _artyTargetMarker setMarkerTypeLocal "mil_dot";
            _artyTargetMarker setMarkerAlphaLocal 1;

            _artyTargetMarkerText = "ETA: <" + str _shownETA + " sec";
            _artyTargetMarker setMarkerTextLocal format ["%1", _artyTargetMarkerText];

            _artyTargetMarker setMarkerColor "ColorOrange";
            [_targetMarkerName] remoteExec ["deleteMarkerLocal", east];
            [_targetMarkerName] remoteExec ["deleteMarkerLocal", resistance];
            */

            //playSound3D ["\A3\Sounds_F\vehicles\air\noises\alarm_locked_by_missile_4.wss", _targetPosition, 0.15, 1, 100];
            //playSound3D [filename, soundSource, isInside, soundPosition, volume, soundPitch, distance, offset, local]

            if ((_targetPosition select 0) == 0) then {
                _message = "INCOMING" + "\n" + "ETA: <" + str _shownETA + " sec" + "\n" + "target: ???-???" + "\n" + "source: " + _artySourceGridX + "-" + _artySourceGridY;
                [["\A3\Sounds_F\vehicles\air\noises\alarm_locked_by_missile_4.wss", 0.1]] remoteExec ["playSoundUI", west];
                [_message] remoteExec ["hintSilent", west];
                sleep 5;
                [""] remoteExec ["hintSilent", west];
            } else {
                _message = "INCOMING" + "\n" + "ETA: <" + str _shownETA + " sec" + "\n" + "target: " + _targetGridX + "-" + _targetGridY + "\n" + "source: " + _artySourceGridX + "-" + _artySourceGridY;
                playSound3D ["\A3\Sounds_F\vehicles\air\noises\alarm_locked_by_missile_4.wss", objNull, false, _targetPosition, 5, 1, 1000];
                //try if its louder at mid distance with 300m setting
                [_message] remoteExec ["hintSilent", west];
                sleep 5;
                [""] remoteExec ["hintSilent", west];
            };

            if (_timeSinceLast > _timeInterval) then {
                _vehicle setVariable ["ArtySourceTime", time, true];

                _roundedArtySourcePosX = round (_artySourcePos select 0);
                _roundedArtySourcePosY = round (_artySourcePos select 1);
                _markerName = ("_USER_DEFINED_" + str _roundedArtySourcePosX + str _roundedArtySourcePosY);
                deleteMarker _markerName;   //preventing doubles and outdated timestamp

                private _artySourceMarker = createMarkerLocal [_markerName, _artySourcePos];
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
                [_markerName] remoteExec ["deleteMarkerLocal", civilian];
            };

            if ((_shownETA - 5) > 0) then {
                sleep _shownETA - 5;
                [_targetMarkerName] remoteExec ["deleteMarker", west];
                [_targetMarkerName2] remoteExec ["deleteMarker", west];
            } else {
                [_targetMarkerName] remoteExec ["deleteMarker", west];
                [_targetMarkerName2] remoteExec ["deleteMarker", west];
            };
        };
    };

    //Opfor Player
    if (_opposedTo_O and (_CBRad_Player_AliveAmount_O>0)) then {

        _ETA = _vehicle getArtilleryETA [_targetPosition, currentMagazine _vehicle];

        [_vehicle, _targetPosition, _timeSinceLast, _timeInterval, _ETA] spawn {
            params ["_vehicle", "_targetPosition", "_timeSinceLast", "_timeInterval", "_ETA"];
            _vehicle setVariable ["ArtySourceTime", time, true];
            private _artySourcePos = getPosASL _vehicle;

            _artySourceGrid = mapGridPosition _artySourcePos;
            _artySourceGridX = _artySourceGrid select [0, 3];
            _artySourceGridY = _artySourceGrid select [3, 3];
            _targetGrid = mapGridPosition _targetPosition;
            _targetGridX = _targetGrid select [0, 3];
            _targetGridY = _targetGrid select [3, 3];

            _shownETA = round (_ETA - RC_DetectionTime_F1);

            sleep (RC_DetectionTime_F1);

            if ((_targetPosition select 0) == 0) then {
                _message = "INCOMING" + "\n" + "ETA: <" + str _shownETA + " sec" + "\n" + "target: ???-???" + "\n" + "source: " + _artySourceGridX + "-" + _artySourceGridY;
                [["\A3\Sounds_F\vehicles\air\noises\alarm_locked_by_missile_4.wss", 0.1]] remoteExec ["playSoundUI", east];
                [_message] remoteExec ["hintSilent", east];
                sleep 5;
                [""] remoteExec ["hintSilent", east];
            } else {
                _message = "INCOMING" + "\n" + "ETA: <" + str _shownETA + " sec" + "\n" + "target: " + _targetGridX + "-" + _targetGridY + "\n" + "source: " + _artySourceGridX + "-" + _artySourceGridY;
                [["\A3\Sounds_F\vehicles\air\noises\alarm_locked_by_missile_4.wss", 0.1]] remoteExec ["playSoundUI", east];
                [_message] remoteExec ["hintSilent", east];
                sleep 5;
                [""] remoteExec ["hintSilent", east];
            };

            if (_timeSinceLast > _timeInterval) then {
                _vehicle setVariable ["ArtySourceTime", time, true];

                _roundedArtySourcePosX = round (_artySourcePos select 0);
                _roundedArtySourcePosY = round (_artySourcePos select 1);
                _markerName = ("_USER_DEFINED_" + str _roundedArtySourcePosX + str _roundedArtySourcePosY);
                deleteMarker _markerName;   //preventing doubles and outdated timestamp

                private _artySourceMarker = createMarkerLocal [_markerName, _artySourcePos];
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

                //-----------------------------------------------------

                _roundedArtyTargetPosX = round (_targetPosition select 0);
                _roundedArtyTargetPosY = round (_targetPosition select 1);
                _targetMarkerName = ("_USER_DEFINED_" + str _roundedArtyTargetPosX + str _roundedArtyTargetPosY);
                deleteMarker _targetMarkerName;   //preventing doubles and outdated timestamp

                private _artyTargetMarker = createMarkerLocal [_targetMarkerName, _targetPosition];
                _artyTargetMarker setMarkerTypeLocal "mil_dot";
                _artyTargetMarker setMarkerAlphaLocal 1;

                _artyTargetMarkerText = "ETA: <" + str _shownETA + " sec";
                _artyTargetMarker setMarkerTextLocal format ["%1", _artyTargetMarkerText];

                _artyTargetMarker setMarkerColor "ColorOrange";
                [_targetMarkerName] remoteExec ["deleteMarkerLocal", west];
                [_targetMarkerName] remoteExec ["deleteMarkerLocal", resistance];

                sleep _shownETA + 1;
                deleteMarker _targetMarkerName;
            };
        };
    };

    //Infor Player
    if (_opposedTo_I and (_CBRad_Player_AliveAmount_I>0)) then {
        
        _ETA = _vehicle getArtilleryETA [_targetPosition, currentMagazine _vehicle];

        [_vehicle, _targetPosition, _timeSinceLast, _timeInterval, _ETA] spawn {
            params ["_vehicle", "_targetPosition", "_timeSinceLast", "_timeInterval", "_ETA"];
            _vehicle setVariable ["ArtySourceTime", time, true];
            private _artySourcePos = getPosASL _vehicle;

            _artySourceGrid = mapGridPosition _artySourcePos;
            _artySourceGridX = _artySourceGrid select [0, 3];
            _artySourceGridY = _artySourceGrid select [3, 3];
            _targetGrid = mapGridPosition _targetPosition;
            _targetGridX = _targetGrid select [0, 3];
            _targetGridY = _targetGrid select [3, 3];

            _shownETA = round (_ETA - RC_DetectionTime_F1);

            sleep (RC_DetectionTime_F1);

            if ((_targetPosition select 0) == 0) then {
                _message = "INCOMING" + "\n" + "ETA: <" + str _shownETA + " sec" + "\n" + "target: ???-???" + "\n" + "source: " + _artySourceGridX + "-" + _artySourceGridY;
                [["\A3\Sounds_F\vehicles\air\noises\alarm_locked_by_missile_4.wss", 0.1]] remoteExec ["playSoundUI", resistance];
                [_message] remoteExec ["hintSilent", resistance];
                sleep 5;
                [""] remoteExec ["hintSilent", resistance];
            } else {
                _message = "INCOMING" + "\n" + "ETA: <" + str _shownETA + " sec" + "\n" + "target: " + _targetGridX + "-" + _targetGridY + "\n" + "source: " + _artySourceGridX + "-" + _artySourceGridY;
                [["\A3\Sounds_F\vehicles\air\noises\alarm_locked_by_missile_4.wss", 0.1]] remoteExec ["playSoundUI", resistance];
                [_message] remoteExec ["hintSilent", resistance];
                sleep 5;
                [""] remoteExec ["hintSilent", resistance];
            };

            if (_timeSinceLast > _timeInterval) then {
                _vehicle setVariable ["ArtySourceTime", time, true];

                _roundedArtySourcePosX = round (_artySourcePos select 0);
                _roundedArtySourcePosY = round (_artySourcePos select 1);
                _markerName = ("_USER_DEFINED_" + str _roundedArtySourcePosX + str _roundedArtySourcePosY);
                deleteMarker _markerName;   //preventing doubles and outdated timestamp

                private _artySourceMarker = createMarkerLocal [_markerName, _artySourcePos];
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
                [_markerName] remoteExec ["deleteMarkerLocal", east];

                //-----------------------------------------------------

                _roundedArtyTargetPosX = round (_targetPosition select 0);
                _roundedArtyTargetPosY = round (_targetPosition select 1);
                _targetMarkerName = ("_USER_DEFINED_" + str _roundedArtyTargetPosX + str _roundedArtyTargetPosY);
                deleteMarker _targetMarkerName;   //preventing doubles and outdated timestamp

                private _artyTargetMarker = createMarkerLocal [_targetMarkerName, _targetPosition];
                _artyTargetMarker setMarkerTypeLocal "mil_dot";
                _artyTargetMarker setMarkerAlphaLocal 1;

                _artyTargetMarkerText = "ETA: <" + str _shownETA + " sec";
                _artyTargetMarker setMarkerTextLocal format ["%1", _artyTargetMarkerText];

                _artyTargetMarker setMarkerColor "ColorOrange";
                [_targetMarkerName] remoteExec ["deleteMarkerLocal", west];
                [_targetMarkerName] remoteExec ["deleteMarkerLocal", resistance];

                sleep _shownETA + 1;
                deleteMarker _targetMarkerName;
            };
        };
    };
}];