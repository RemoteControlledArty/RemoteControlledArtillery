#define RC_SENSIVITY 12  //7

//params ["_position", "_direction", "_magazine"];
params ["_position", "_direction", "_velocity", "_dirVec"];

call RC_fnc_Interceptor_createUI;

cutrsc ["SB_RscDisplayUAV", "plain"];
"SB_RscCompass" cutrsc ["RscCompass","plain"];

private _display = localNameSpace getVariable ["RC_Interceptor_display", displayNull];

private _ammo = "Interceptor_MP";
/*
private _ammo = "";

if (_magazine == "Interceptor_Shell_AT") then {
    _ammo = "Interceptor_MP";
} else {
    _ammo = "RC_ammo_Interceptor_HE";
};
*/

//private _uav = _ammo createVehicle _position;
//private _uav = [_position, _direction, "B_Crocus_MP_TI_Sens", east] call BIS_fnc_spawnVehicle;
private _uav = createVehicle ["O_Crocus_MP_TI_Sens", _position, [], 0, "FLY"];
//private _uavSpawn = [_spawnPos, direction _uav, _version, _side] call BIS_fnc_spawnVehicle;
createVehicleCrew _uav;
//_uav setPosASL _position;
_uav setDir _direction;
_uav setVelocity _velocity;
_uav flyInHeight 20;

player connectTerminalToUAV _uav;
//[_uav] call RC_fnc_RC_uavChangeLocality;
//player action ["UAVTerminalOpen", player];
driver _uav switchCamera "Internal";
player remoteControl driver _uav;

/*
private _uav = [_position, _direction, _ammo, sideEmpty] call BIS_fnc_spawnVehicle;
_uav = _uav select 0;
_uav setVelocity _velocity;
*/

//test
private _target = [[0,0,500], _direction, "RC_Projectile_Target_O", east] call BIS_fnc_spawnVehicle;
_target = _target select 0;
_target disableCollisionWith _uav;
_target attachTo [_uav, [0,1,1]];


//_uav hideObject true;
/*
private _camera = "camera" camCreate getPosASL _uav;
_camera cameraEffect ["External", "BACK"];
showCinemaBorder false;
cameraEffectEnableHUD true;
_camera camSetTarget _uav;
_camera camSetDir _dirVec;  //
_camera camSetRelPos [0,0,0];
_camera camCommit 0.1;
_camera attachTo [_uav, [0, 2, 0]];
*/
setMousePosition [0.5, 0.5];
RC_X = 0.5;
RC_Y = 0.5;
_lastpos = getPosASL _uav;
_dir = getDir _uav;


//[_uav, _position, _magazine] spawn RC_fnc_Interceptor_waitUAVdestroy;

//localNameSpace setVariable ["RC_Interceptor_speed", speed _uav];
//localNameSpace setVariable ["RC_Interceptor_camera", _camera];
localNameSpace setVariable ["RC_Interceptor_maxSpeed", 1];    //300
localNameSpace setVariable ["RC_Interceptor_vehicle", _uav];
localNameSpace setVariable ["RC_Interceptor_cameraZoom", 0.9]; //0.75


[_uav, _position] spawn {
    params ["_uav", "_position"];

	while {
        !(isNull _uav)
    } do {
        if (isNull (localNameSpace getVariable ["RC_Interceptor_display", displayNull])) exitWith {};
        setMousePosition [0.5, 0.5];
		sleep 0.01;
		_A = getMousePosition;
        _xx = (_A # 0);
        _yy = (_A # 1);
        _dt = diag_deltaTime;

        if (_xx != 0.5) then {
            //RC_X = RC_X - (0.5 - _xx) * (_dt / 0.0167);
            RC_X = RC_X - (0.5 - _xx);
        };
        if (!(_yy >= 0.499 and _yy <= 0.5)) then {
			//RC_Y = RC_Y + (0.5 - _yy) * (_dt / 0.0167);
            RC_Y = RC_Y + (0.5 - _yy);
        };

        STING_SIGNAL = 1 - ((_uav distance player) / 10000);
	};
};


_currentX = 0.5;    // smoothed yaw for momentum
_currentY = 0.5;    // smoothed pitch for momentum
_previousX = _currentX;
_previousY = _currentY;
_alpha = 8;         // momentum / smoothing factor

private _EventHead = addMissionEventHandler ["EachFrame", {
    _thisArgs params ["_uav"];

    private _dt = diag_deltaTime;
    private _frameAlpha = (_alpha * _dt) min 1;  // smoothing factor scaled by deltaTime

    _currentX = _currentX + (RC_X - _currentX) * _frameAlpha;
    _currentY = _currentY + (RC_Y - _currentY) * _frameAlpha;

    //_y = RC_X * RC_SENSIVITY * (_dt / 0.0167);
    //_p = RC_Y * RC_SENSIVITY * (_dt / 0.0167);
    _y = RC_X * RC_SENSIVITY;
    _p = RC_Y * RC_SENSIVITY;
    _r = 0;

    _dir = [
        sin _y * cos _p,
        cos _y * cos _p,
        sin _p
    ];
    
    _uav setVectorDirAndUp [
        _dir,
        [[0, -sin _p, cos _p], -_y] call BIS_fnc_rotateVector2D
    ];

    //physics
    /*
    _velDir = [
        sin _currentX * cos _currentY,
        cos _currentX * cos _currentY,
        sin _currentY
    ];
    */

    //visual
    //_visDir = vectorNormalized [sin _currentX, cos _currentX, 0]; // horizontal

    _speed = speed _uav;
    _maxSpeed = localNameSpace getVariable ["RC_Interceptor_maxSpeed", 1];
    if (_speed > _maxSpeed) then {_speed = _maxSpeed;};
    
    //_vel = _velDir vectorMultiply (_speed / 3.6);
    _vel = _dir vectorMultiply (_speed / 3.6);
    //gravity cancel
    _vel set [2, (_vel # 2) + (9.81 * _dt)];
    //apply
    _uav setVelocity _vel;

    //_previousX = _currentX;

    //hint format ["_dir: %1\n_up: %2", _dir, _up];

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
	_thisArgs params ["_vehicle"];

    getPosATLVisual _vehicle params ["_xPos", "_yPos", "_zPos"];

    (localNameSpace getVariable ["RC_Interceptor_controls", []]) params ["_controlCoord", "_controlDate", "_controlSpeed"];

    //private _camera = localNameSpace getVariable ["RC_Interceptor_camera", objNull];
    //private _speed  = localNameSpace getVariable ["RC_Interceptor_speed", speed _vehicle];

    private _curDate = date;
    private _ddMMyyyy = parseText format ["<t font='EtelkaMonospacePro'>%3/%2/%1 - %4</t>",
    	_curDate select 0,
    	(if (_curDate select 1 < 10) then { "0" } else { "" }) + str (_curDate select 1),
    	(if (_curDate select 2 < 10) then { "0" } else { "" }) + str (_curDate select 2),
        [daytime] call BIS_fnc_timeToString
    ];
    
    _controlCoord ctrlSetStructuredText parseText format ["<t align='right' font='EtelkaMonospacePro'>%1, %2, %3</t>", round _xPos, round _yPos, round _zPos];
    _controlDate  ctrlSetStructuredText _ddMMyyyy;
    _controlSpeed ctrlSetStructuredText parseText format ["<t font='EtelkaMonospacePro'>%1 Km/h</t>", round (speed _vehicle)];
}, [_uav]];


private _idSlowDown = _display displayAddEventHandler ["KeyDown",  { 
    params ["", "_key"];

    if (_key != 44) exitWith {};

    private _speed = localNameSpace getVariable ["RC_Interceptor_maxSpeed", 1]; ///350

    private _norm = linearConversion [1, 350, _speed, 0, 1, true];

    private _maxAcc = 5;
    private _minAcc = 1;
    private _acc = (_maxAcc * (_maxAcc * _norm * (1 - _norm))) max _minAcc;

    _speed = (_speed - _acc) max 1;

    localNameSpace setVariable ["RC_Interceptor_maxSpeed", _speed];
}];

private _idUpSpeed = _display displayAddEventHandler ["KeyDown",  { 
    params ["", "", "_shift"];

    if !(_shift) exitWith {};

    private _speed = localNameSpace getVariable ["RC_Interceptor_maxSpeed", 1];   //101

    private _norm = linearConversion [1, 350, _speed, 0, 1, true];

    private _maxAcc = 5;
    private _minAcc = 1;
    private _acc = (_maxAcc * (_maxAcc * _norm * (1 - _norm))) max _minAcc;

    _speed = (_speed + _acc) min 350;

    localNameSpace setVariable ["RC_Interceptor_maxSpeed", _speed];
}];

/*
private _idZoom = _display displayAddEventHandler ["MouseZChanged", {
    params ["", "_scroll"];

    private _camera = localNameSpace getVariable ["RC_Interceptor_camera", objNull];
    private _cameraZoom = localNameSpace getVariable ["RC_Interceptor_cameraZoom", 0.9];

    if (_scroll > 0) then {
        _cameraZoom = (_cameraZoom - 0.1) max 0.1; //0.35
    } else {
        if (_scroll < 0) then {
            _cameraZoom = (_cameraZoom + 0.1) min 0.9; //0.75
        };
    };    

    _camera camSetFov _cameraZoom;
    _camera camCommit 0.1;

    localNameSpace setVariable ["RC_Interceptor_cameraZoom", _cameraZoom];
}];

localNameSpace setVariable ["RC_Interceptor_idEachFrame", _idEachFrame];
localNameSpace setVariable ["RC_Interceptor_idNvg", _idNvg];
localNameSpace setVariable ["RC_Interceptor_EventHead", _EventHead];

/*
[_uav, _position] spawn {
    params ["_vehicle", "_position"];

	while {
        !(isNull _vehicle)
    } do {
        if (isNull (localNameSpace getVariable ["RC_Interceptor_display", displayNull])) exitWith {};
        setMousePosition [0.5, 0.5];
		sleep 0.01;
		_A = getMousePosition;
        _xx = (_A # 0);
        _yy = (_A # 1);
        if (_xx != 0.5) then {
            RC_X =  RC_X - (0.5 - (_A # 0));
        };
        if (!(_yy >=0.499 and _yy<=0.5)) then {
			RC_Y = RC_Y + (0.5 - (_A # 1));
        };
	};
};
*/


while {
    !(isNull _uav)
} do {
    if (isNull (localNameSpace getVariable ["RC_Interceptor_display", displayNull])) exitWith {};
    if !(_lastpos isEqualTo [0,0,0]) then {
        _lastpos = getPosASL _uav;
    };
    
    _lastTime = time;
    _distancePOS = getPosASL _uav;
    _S = getMousePosition;

    _dir = getDir _uav;
};


/*
while {
    !(isNull _uav)
} do {
    if (isNull (localNameSpace getVariable ["RC_Interceptor_display", displayNull])) exitWith {};
    if !(_lastpos isEqualTo [0,0,0]) then {
        _lastpos = getPosASL _uav;
    };
    
    _lastTime = time;
    _distancePOS = getPosASL _uav;
    _S = getMousePosition;

	_camera camSetTarget _uav;
    _dir = getDir _uav;
	_camera camSetRelPos [0,0,0];
	_camera camcommit 5 * (time - _lastTime);
};
*/


waitUntil {
    !(canMove _uav) ||
    ((_uav distance _position) > 12000) ||
    (isNull (localNameSpace getVariable ["RC_Interceptor_display", displayNull]))
};

removeMissionEventHandler ["EachFrame",_EventHead];

private _controls = localNameSpace getVariable ["RC_Interceptor_controls", []];

_display closeDisplay 1;
  
private _effect_1 = localNameSpace getVariable ["RC_Interceptor_effect_1",  -1];
private _effect_2 = localNameSpace getVariable ["RC_Interceptor_effect_2",  -1];

ppEffectDestroy _effect_1;
ppEffectDestroy _effect_2;

removeMissionEventHandler ["EachFrame", _idEachFrame];
removeMissionEventHandler ["EachFrame", _EventHead];

_display displayRemoveEventHandler ["KeyDown", _idNvg];

_controls apply { ctrlDelete _x };
    
// deleteVehicle _uav;

camUseNVG false;
false setCamUseTI 1;

cutText ["", "PLAIN"];
"SB_RscCompass" cutText ["", "PLAIN"];