params ["_pos", "_dir", "_vel", "_dirVec"];


//UI
call RC_fnc_Interceptor_UI;
cutrsc ["Interceptor_RscDisplayUAV", "plain"];
"SB_RscCompass" cutrsc ["RscCompass","plain"];
private _display = localNameSpace getVariable ["RC_Interceptor_display", displayNull];


//spawn _uav
private _versionOutput = [_pos, _dir, _vel] call fnc_Interceptor_version;
_versionOutput params ["_uav", "_ammo"];


//interceptability
[_uav, _dir] call fnc_Interceptor_interceptability;


//camera
private _cameraOutput = [_uav, _pos, _dir, _vel, _dirVec] call fnc_Interceptor_camera;
_cameraOutput params ["_camera", "_lastpos", "_dir"];


//moved to end of this file
//[_uav, _pos, _magazine] spawn RC_fnc_Interceptor_destroy;    //?


//steering
[_uav, _pos] spawn fnc_Interceptor_mouseSteer;  //spawn to allow sleep


//localNameSpace setVariable ["RC_Interceptor_speed", speed _uav];    //?
localNameSpace setVariable ["RC_Interceptor_camera", _camera];
localNameSpace setVariable ["RC_Interceptor_uav", _uav];
localNameSpace setVariable ["RC_Interceptor_AB", false];
localNameSpace setVariable ["RC_Interceptor_maxSpeed", 1];
localNameSpace setVariable ["RC_Interceptor_cameraZoom", 0.9];


//hotkeys
// e = 18
private _idAB = _display displayAddEventHandler ["KeyDown",  { 
    params ["", "_key"];
    if (_key != 18) exitWith {};

    localNameSpace setVariable ["RC_Interceptor_AB", true];
}];

// w = 17
RC_FORWARD = false;
_display displayAddEventHandler ["KeyDown", { 
    params ["", "_key"]; 
    if (_key == 17) then { RC_FORWARD = true; true }; 
}];
_display displayAddEventHandler ["KeyUp", { 
    params ["", "_key"]; 
    if (_key == 17) then { RC_FORWARD = false; true }; 
}];

// s = 31
RC_BACKWARD = false;
_display displayAddEventHandler ["KeyDown", { 
    params ["", "_key"]; 
    if (_key == 31) then { RC_BACKWARD = true; true }; 
}];
_display displayAddEventHandler ["KeyUp", { 
    params ["", "_key"]; 
    if (_key == 31) then { RC_BACKWARD = false; true }; 
}];

// a = 30
RC_RIGHT = false;
_display displayAddEventHandler ["KeyDown", { 
    params ["", "_key"]; 
    if (_key == 30) then { RC_RIGHT = true; true }; 
}];
_display displayAddEventHandler ["KeyUp", { 
    params ["", "_key"]; 
    if (_key == 30) then { RC_RIGHT = false; true }; 
}];

// d = 32
RC_LEFT = false;
_display displayAddEventHandler ["KeyDown", { 
    params ["", "_key"]; 
    if (_key == 32) then { RC_LEFT = true; true }; 
}];
_display displayAddEventHandler ["KeyUp", { 
    params ["", "_key"]; 
    if (_key == 32) then { RC_LEFT = false; true }; 
}];

// shift = 42
RC_LIFT = false;
_display displayAddEventHandler ["KeyDown", { 
    params ["", "_key"];
    if (_key == 42) then { RC_LIFT = true; };
}];
_display displayAddEventHandler ["KeyUp", { 
    params ["", "_key"];
    if (_key == 42) then { RC_LIFT = false; };
}];

// c = 46
RC_DROP = false;
_display displayAddEventHandler ["KeyDown", { 
    params ["", "_key"];
    if (_key == 46) then { RC_DROP = true; };
}];
_display displayAddEventHandler ["KeyUp", { 
    params ["", "_key"];
    if (_key == 46) then { RC_DROP = false; };
}];


//main setVel logic
private _EventHead = addMissionEventHandler ["EachFrame", {
    _thisArgs params ["_uav"];
    //params ["_uav"];

    private _AB = localNameSpace getVariable ["RC_Interceptor_AB", false];
    if (_AB) then {
        triggerAmmo _uav;   //check if that makes it double trigger
    };

    [_uav] call fnc_Interceptor_setVel;

}, [_uav]];


private _idNvg = _display displayAddEventHandler ["KeyDown",  { 

    if (inputAction "nightVision" <= 0) exitWith {};

    private _currentOn = localNameSpace getVariable ["RC_Interceptor_currentOn", 0];
    
    switch (_currentOn) do {
        case 0: {
            _currentOn = 1;
            camUseNVG true;
        };
        case 1: {
            _currentOn = 2;
            camUseNVG false;
            true setCamUseTI 0;
        };
        case 2: {
            _currentOn = 0;
            camUseNVG false;
            false setCamUseTI 0;
        };
        default { };
    };

    localNameSpace setVariable ["RC_Interceptor_currentOn", _currentOn];
}];


private _idEachFrame = addMissionEventHandler ["EachFrame", {
	_thisArgs params ["_uav"];

    getPosATLVisual _uav params ["_xPos", "_yPos", "_zPos"];

    (localNameSpace getVariable ["RC_Interceptor_controls", []]) params ["_controlCoord", "_controlDate", "_controlSpeed"];

    private _camera = localNameSpace getVariable ["RC_Interceptor_camera", objNull];
    //private _speed  = localNameSpace getVariable ["RC_Interceptor_speed", speed _uav];    //?

    private _curDate = date;
    private _ddMMyyyy = parseText format ["<t font='EtelkaMonospacePro'>%3/%2/%1 - %4</t>",
    	_curDate select 0,
    	(if (_curDate select 1 < 10) then { "0" } else { "" }) + str (_curDate select 1),
    	(if (_curDate select 2 < 10) then { "0" } else { "" }) + str (_curDate select 2),
        [daytime] call BIS_fnc_timeToString
    ];
    
    _controlCoord ctrlSetStructuredText parseText format ["<t align='right' font='EtelkaMonospacePro'>%1, %2, %3</t>", round _xPos, round _yPos, round _zPos];
    _controlDate  ctrlSetStructuredText _ddMMyyyy;

    // get the 3D velocity vector [x, y, z] in meters per second
    private _velVector = velocity _uav;
    // calculate the absolute length of that vector (m/s)
    private _speedMS = vectorMagnitude _velVector;
    // convert to km/h
    private _absoluteSpeedKMH = round (_speedMS * 3.6);
    _controlSpeed ctrlSetStructuredText parseText format ["<t font='EtelkaMonospacePro'>%1 Km/h</t>", _absoluteSpeedKMH];
}, [_uav]];


private _idZoom = _display displayAddEventHandler ["MouseZChanged", {
    params ["", "_scroll"];

    private _camera = localNameSpace getVariable ["RC_Interceptor_camera", objNull];
    private _cameraZoom = localNameSpace getVariable ["RC_Interceptor_cameraZoom", 0.9];

    if (_scroll > 0) then {
        _cameraZoom = (_cameraZoom - 0.1) max 0.1;
    } else {
        if (_scroll < 0) then {
            _cameraZoom = (_cameraZoom + 0.1) min 0.9;
        };
    };    

    _camera camSetFov _cameraZoom;
    _camera camCommit 0.1;

    localNameSpace setVariable ["RC_Interceptor_cameraZoom", _cameraZoom];
}];


localNameSpace setVariable ["RC_Interceptor_idEachFrame", _idEachFrame];
localNameSpace setVariable ["RC_Interceptor_idNvg", _idNvg];
localNameSpace setVariable ["RC_Interceptor_EventHead", _EventHead];


//updateCam
while {
    !(isNull _uav)
} do {
    [_uav, _lastpos] call fnc_Interceptor_UpdateCam;
};


//waitUntil
waitUntil {
    !(canMove _uav) ||
    ((_uav distance _pos) > 10000) ||
    (isNull (localNameSpace getVariable ["RC_Interceptor_display", displayNull]))
};


//destroy
[_uav, _pos] call fnc_Interceptor_destroy;
//outputs needed or not?