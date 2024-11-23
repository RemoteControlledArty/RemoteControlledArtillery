_ETA = _vehicle getArtilleryETA [_targetPosition, currentMagazine _vehicle];

[_vehicle, _targetPosition, _timeSinceLast, _timeInterval, _ETA] spawn {
    params ["_vehicle", "_targetPosition", "_timeSinceLast", "_timeInterval", "_ETA"];
    private _artySourcePos = getPosASL _vehicle;
    _firstUnit = (units west) select 0;

    private _angle = random 360;
    private _distance = 15 * (sqrt random 1);   //first value is radius

    _artySourceGrid = mapGridPosition _artySourcePos;
    _artySourceGridX = _artySourceGrid select [0, 3];
    _artySourceGridY = _artySourceGrid select [3, 3];
    _targetGrid = mapGridPosition _targetPosition;
    _targetGridX = _targetGrid select [0, 3];
    _targetGridY = _targetGrid select [3, 3];

    _shownETA = round (_ETA - RC_DetectionTime_F1);

    sleep (RC_DetectionTime_F1);


    //for testing
    /*
    _pos = getpos _this;
    _firstUnit = (units east) select 0; 
    private _marker = createMarkerLocal ["_USER_DEFINED" + str _pos, _pos, 1, _firstUnit]; 
    _marker setMarkerTypeLocal "o_art";
    _marker setMarkerAlpha 1;

    _pos = getpos _this;
    private _marker = createMarkerLocal ["_USER_DEFINED" + str _pos, _pos]; 
    _marker setMarkerTypeLocal "o_art";
    _marker setMarkerAlpha 1;
    */


    //if (_ETA > RC_DetectionTime_F1) then {
        private _markerPosition = _targetPosition getPos [_distance, _angle];

        //red impact area
        private _targetMarkerName = ("_USER_DEFINED AproxArtyMarker" + str _markerPosition);
        //deleteMarker _targetMarkerName;
        //private _artyTargetMarker = createMarkerLocal [_targetMarkerName, _markerPosition];
        private _artyTargetMarker = createMarker [_targetMarkerName, _markerPosition, 1, _firstUnit];
        _artyTargetMarker setMarkerShapeLocal "ELLIPSE"; 
        _artyTargetMarker setMarkerSizeLocal [15, 15];  //radius
        _artyTargetMarker setMarkerColorLocal "colorRed";
        _artyTargetMarker setMarkerBrushLocal "SolidBorder";

        _artyTargetMarker setMarkerAlpha 0.5;
        //[_targetMarkerName] remoteExec ["deleteMarkerLocal", east];
        //[_targetMarkerName] remoteExec ["deleteMarkerLocal", resistance];
        //[_targetMarkerName] remoteExec ["deleteMarkerLocal", civilian];

        //orange frag area
        private _targetMarkerName2 = ("_USER_DEFINED AproxArtyMarker2" + str _markerPosition);
        //deleteMarker _targetMarkerName2;
        //private _artyTargetMarker2 = createMarkerLocal [_targetMarkerName2, _markerPosition];
        private _artyTargetMarker2 = createMarker [_targetMarkerName2, _markerPosition, 1, _firstUnit];
        _artyTargetMarker2 setMarkerShapeLocal "ELLIPSE"; 
        _artyTargetMarker2 setMarkerSizeLocal [100, 100];  //radius
        _artyTargetMarker2 setMarkerColorLocal "colorOrange";
        _artyTargetMarker2 setMarkerBrushLocal "SolidBorder";

        _artyTargetMarker2 setMarkerAlpha 0.3;
        //[_targetMarkerName2] remoteExec ["deleteMarkerLocal", east];
        //[_targetMarkerName2] remoteExec ["deleteMarkerLocal", resistance];
        //[_targetMarkerName2] remoteExec ["deleteMarkerLocal", civilian];

        if ((_targetPosition select 0) == 0) then {
            _message = "INCOMING" + "\n" + "ETA: <" + str _shownETA + " sec" + "\n" + "target: ???-???" + "\n" + "source: " + _artySourceGridX + "-" + _artySourceGridY;
            [["\A3\Sounds_F\vehicles\air\noises\alarm_locked_by_missile_4.wss", 0.1]] remoteExec ["playSoundUI", west];
            [_message] remoteExec ["hintSilent", west];
            sleep 5;
            [""] remoteExec ["hintSilent", west];
        } else {
            _message = "INCOMING" + "\n" + "ETA: <" + str _shownETA + " sec" + "\n" + "target: " + _targetGridX + "-" + _targetGridY + "\n" + "source: " + _artySourceGridX + "-" + _artySourceGridY;
            //playSound3D ["\A3\Sounds_F\vehicles\air\noises\alarm_locked_by_missile_4.wss", objNull, false, _targetPosition, 2, 1, 1000];    //sadly not side specific
            _nearPlayers = allPlayers select {_x distance2D _targetPosition < 200};
            _nearPlayers_B = _nearPlayers select {side _x == west};

            if ((count _nearPlayers_B) > 0) then {
                [["\A3\Sounds_F\vehicles\air\noises\alarm_locked_by_missile_4.wss", 0.2]] remoteExec ["playSoundUI", _nearPlayers_B];
            };

            [_message] remoteExec ["hintSilent", west];
            sleep 5;
            [""] remoteExec ["hintSilent", west];
        };
    //};


    if (_timeSinceLast > _timeInterval) then {
        _vehicle setVariable ["ArtySourceTime", time, true];

        _roundedArtySourcePosX = round (_artySourcePos select 0);
        _roundedArtySourcePosY = round (_artySourcePos select 1);
        _markerName = ("_USER_DEFINED_" + str _roundedArtySourcePosX + str _roundedArtySourcePosY);
        //_markerName = ("_USER_DEFINED_" + str _markerPosition2);
        deleteMarker _markerName;   //preventing doubles and outdated timestamp
        
        //private _artySourceMarker = createMarkerLocal [_markerName, _artySourcePos];
        private _artySourceMarker = createMarkerLocal [_markerName, _artySourcePos, 1, _firstUnit];
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
        //[_markerName] remoteExec ["deleteMarkerLocal", east, true];
        //[_markerName] remoteExec ["deleteMarkerLocal", resistance, true];
        //[_markerName] remoteExec ["deleteMarkerLocal", civilian, true];
    };


    //if (_ETA > RC_DetectionTime_F1) then {
        if ((_shownETA - 5) > 0) then {
            sleep _shownETA - 5;
            deleteMarker _targetMarkerName;
            deleteMarker _targetMarkerName2;
        } else {
            deleteMarker _targetMarkerName;
            deleteMarker _targetMarkerName2;
        };
    //};
};