params ["_veh", "_targetPos", "_timeSinceLast", "_side", "_proj"];

private _ETA = _veh getArtilleryETA [_targetPos, currentMagazine _veh];

[_veh, _targetPos, _timeSinceLast, _ETA, _side, _proj] spawn {
    params ["_veh", "_targetPos", "_timeSinceLast", "_ETA", "_side", "_proj"];


    private _shownETA = round (_ETA - RC_CBRad_DetectionTime_P);
    private _artySourcePos = getPosASL _veh;
    private _firstUnit = (units _side) #0;

    private _angle = random 360;
    private _radius = 15;
    private _distance = _radius * (sqrt random 1);

    private _artySourceGrid = mapGridPosition _artySourcePos;
    private _artySourceGridX = _artySourceGrid select [0, 3];
    private _artySourceGridY = _artySourceGrid select [3, 3];
    private _targetGrid = mapGridPosition _targetPos;
    private _targetGridX = _targetGrid select [0, 3];
    private _targetGridY = _targetGrid select [3, 3]; 


    sleep RC_CBRad_DetectionTime_P;
    //add to array client side
    [_proj, _shownETA] remoteExec ['RC_fnc_RC_CBRad_projArrRE', _side];


    //for testing
    /*
    _pos = getpos _this;
    _firstUnit = (units east) #0; 
    private _marker = createMarkerLocal ["_USER_DEFINED" + str _pos, _pos, 1, _firstUnit]; 
    _marker setMarkerTypeLocal "o_art";
    _marker setMarkerAlpha 1;

    _pos = getpos _this;
    private _marker = createMarkerLocal ["_USER_DEFINED" + str _pos, _pos]; 
    _marker setMarkerTypeLocal "o_art";
    _marker setMarkerAlpha 1;
    */


    //if (_ETA > RC_CBRad_DetectionTime_P) then {
        private _markerPosition = _targetPos getPos [_distance, _angle];

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

        if ((_targetPos #0) == 0) then {
            private _message = "INCOMING" + "\n" + "ETA: <" + str _shownETA + " sec" + "\n" + "target: ???-???" + "\n" + "source: " + _artySourceGridX + "-" + _artySourceGridY;
            [["\A3\Sounds_F\vehicles\air\noises\alarm_locked_by_missile_4.wss", 0.1]] remoteExec ["playSoundUI", _side];
            [_message] remoteExec ["hintSilent", _side];
            sleep 4;
            [""] remoteExec ["hintSilent", _side];
        } else {
            private _message = "INCOMING" + "\n" + "ETA: <" + str _shownETA + " sec" + "\n" + "target: " + _targetGridX + "-" + _targetGridY + "\n" + "source: " + _artySourceGridX + "-" + _artySourceGridY;
            //playSound3D ["\A3\Sounds_F\vehicles\air\noises\alarm_locked_by_missile_4.wss", objNull, false, _targetPos, 2, 1, 1000];    //sadly not side specific
            private _nearPlayers = (allPlayers select {_x distance2D _targetPos < 200}) select {side _x == _side};

            if ((count _nearPlayers) > 0) then {
                [["\A3\Sounds_F\vehicles\air\noises\alarm_locked_by_missile_4.wss", 0.2]] remoteExec ["playSoundUI", _nearPlayers];
            };

            [_message] remoteExec ["hintSilent", _side];
            sleep 4;
            [""] remoteExec ["hintSilent", _side];
        };
    //};


    //timesincelast usefull? doesnt seem to work ingame
    if (_timeSinceLast > RC_CBRad_IgnoreTime_P) then {
        _veh setVariable ["ArtySourceTime", time, true];


        //private _markerPosition2 = _artySourcePos getPos [_distance, _angle];

        /*
        private _SourceMarkerName2 = ("_USER_DEFINED AproxArtyMarker2" + str _markerPosition2);
        //deleteMarker _targetMarkerName;
        private _artySourceMarker2 = createMarkerLocal [_SourceMarkerName2, _markerPosition2];
        _artySourceMarker2 setMarkerShapeLocal "ELLIPSE"; 
        _artySourceMarker2 setMarkerSizeLocal [_radius2, _radius2];
        _artySourceMarker2 setMarkerColorLocal "colorOrange";
        _artySourceMarker2 setMarkerBrushLocal "SolidBorder";

        _artySourceMarker2 setMarkerAlpha 0.2;
        [_sourceMarkerName2] remoteExec ["deleteMarkerLocal", east];
        [_sourceMarkerName2] remoteExec ["deleteMarkerLocal", resistance];
        [_sourceMarkerName2] remoteExec ["deleteMarkerLocal", civilian];
        */
        

        private _roundedArtySourcePosX = round (_artySourcePos #0);
        private _roundedArtySourcePosY = round (_artySourcePos #1);
        private _markerName = ("_USER_DEFINED_" + str _roundedArtySourcePosX + str _roundedArtySourcePosY);
        //_markerName = ("_USER_DEFINED_" + str _markerPosition2);
        deleteMarker _markerName;   //preventing doubles and outdated timestamp
        
        //private _artySourceMarker = createMarkerLocal [_markerName, _artySourcePos];
        private _artySourceMarker = createMarkerLocal [_markerName, _artySourcePos, 1, _firstUnit];
        _artySourceMarker setMarkerTypeLocal "o_art";
        _artySourceMarker setMarkerAlphaLocal 1;
        _artySourceMarker setMarkerSizeLocal [0.6,0.6];
        
        private _artySourceMarkerHour = date #3;
        private _artySourceMarkerMinute = date #4;
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


    //if (_ETA > RC_CBRad_DetectionTime_P) then {
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