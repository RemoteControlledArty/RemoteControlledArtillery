/*
//for SP development
player addItem "Interceptor_MP_Throw";
player addItem "Interceptor_MP_Throw";
player addItem "Interceptor_MP_Throw";
player addItem "Interceptor_MP_Throw";
player addItem "Interceptor_MP_Throw";
player addItem "Interceptor_MP_Throw";
*/


//fixed
RC_SENSIVITY = 12;

//adjustable, predefined to not be 0 initially
RC_INTERCEPTOR_SIGNAL=1;
RC_X = 0.5;
RC_Y = 0.5;

_uav = objNull;
_camera = objNull;
_lastpos = [0, 0, 0];
_dirVec = [0, 0, 0];
_dir = 0;


fnc_Interceptor_spawn = {
	params ["_pos", "_dir", "_ammo"];

	private _uav = [_pos, _dir, _ammo, sideEmpty] call BIS_fnc_spawnVehicle;
	_uav = _uav select 0;

	//share outside?
	_uav
};


//all below: ingame-overwritable functions, for easier development
fnc_Interceptor_version = {
	params ["_pos", "_dir", "_vel"];
	
	/*
	available _ammo:
	Interceptor_MP						//airFriction = 0; 		sideAirFriction = 0; 	thrust = 0; 	thrustTime = 0;
	Interceptor_MP_Friction,			//airFriction = 0.5; 	sideAirFriction = 0.5; 	thrust = 0; 	thrustTime = 0;
	Interceptor_MP_Thrust10				//airFriction = 0; 		sideAirFriction = 0; 	thrust = 10; 	thrustTime = 5;
	Interceptor_MP_Thrust35				//airFriction = 0; 		sideAirFriction = 0; 	thrust = 35; 	thrustTime = 5;
	Interceptor_MP_Friction_Thrust10	//airFriction = 0.5; 	sideAirFriction = 0.5; 	thrust = 10; 	thrustTime = 5;
	Interceptor_MP_Friction_Thrust35	//airFriction = 0.5; 	sideAirFriction = 0.5; 	thrust = 35; 	thrustTime = 5;
	*/

	private _ammo = "Interceptor_MP";
	private _uav = [_pos, _dir, _ammo, sideEmpty] call BIS_fnc_spawnVehicle;
	/*
	private _ammo = "RC_Interceptor_O";
	private _uav = [_pos, _dir, _ammo, east] call BIS_fnc_spawnVehicle;
	*/
	_uav = _uav select 0;

	/*
	//first have to delete attached target, otherwise count as teamkiller when explosion destroys target
	private _player = player;
	[_uav, [_player, _player]] remoteExec ["setShotParents", 2];
	waitUntil { (getShotParents _uav) isEqualTo [_player, _player]; };
	*/

	_uav setVelocity _vel;

	//output
	[_uav, _ammo]
};


fnc_Interceptor_interceptability = {
	params ["_uav", "_dir"];
	
	private _sidePlayer = side player;
	private _targetVersion = 'RC_Interceptor_Target_B';
	if (_sidePlayer == east) then {_targetVersion = 'RC_Interceptor_Target_O';};
	if (_sidePlayer == resistance) then {_targetVersion = 'RC_Interceptor_Target_I';};

	//somehow not spotted by C-UAS in multiplayer
	private _target = [[0, 0, 500], _dir, _targetVersion, _sidePlayer] call BIS_fnc_spawnVehicle;
	_target = _target select 0;
	_target disableCollisionWith _uav;

	_target addEventHandler ["Killed", {
		params ["_unit"];

		triggerAmmo attachedTo _unit;
		deleteVehicle _unit;
	}];

	//hide projectile to only show targetable attached vehicle
	//hideObjectGlobal _uav;
	//hideObject unitName;
	[_uav, true] remoteExec ["hideObjectGlobal", 2];

	//sleep to prevent collision in MP
	sleep 0.1;
	//-1 offset to not block the shaped charge
	_target attachTo [_uav, [0, -1, 0]];

	//output
	_target
};


/*
//old
fnc_Interceptor_camera = {
	params ["_uav", "_pos", "_dir", "_vel", "_dirVec"];
	
	//_uav hideObject true; //?
	private _camera = "camera" camCreate getPosASL _uav;
	_camera cameraEffect ["External", "BACK"];
	showCinemaBorder false;
	cameraEffectEnableHUD true;
	_camera camSetTarget _uav;
	_camera camSetDir _dirVec;  //overwitten?
	_camera camSetRelPos [0, 0, 0];
	_camera camCommit 0.1;
	_camera attachTo [_uav, [0, 2, 0]];
	setMousePosition [0.5, 0.5];
	_lastpos = getPosASL _uav;
	_dir = getDir _uav;

	//output
	[_camera, _lastpos, _dir]
};
*/


fnc_Interceptor_camera = {
	params ["_uav", "_pos", "_dir", "_vel", "_dirVec"];
	
	private _camera = "camera" camCreate getPosASL _uav;
	_camera cameraEffect ["External", "BACK"];
	showCinemaBorder false;
	cameraEffectEnableHUD true;
	
	//0.06 to prevent camera clipping before detonation
	_camera attachTo [_uav, [0, -0.06, 0]];
	
	setMousePosition [0.5, 0.5];
	_lastpos = getPosASL _uav;
	_dir = getDir _uav;

	[_camera, _lastpos, _dir]
};


/*
//old
fnc_Interceptor_updateCam = {
	params ["_uav", "_lastpos"];

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


fnc_Interceptor_updateCam = {
	params ["_uav"];

	if (isNull (localNameSpace getVariable ["RC_Interceptor_display", displayNull])) exitWith {};
	
	private _camera = localNameSpace getVariable ["RC_Interceptor_camera", objNull];
	
	// === DEBUG: Ist das UAV stabil? ===
	private _uavVel = velocity _uav;
	private _uavPitch = (vectorDir _uav) select 2;  // Z-component of direction
	systemChat format ["UAV Pitch: %1 | Z-Vel: %2", 
		round (_uavPitch * 1000) / 1000, 
		round ((_uavVel # 2) * 100) / 100
	];
	
	// Rotation
	private _y = RC_X * RC_SENSIVITY;
	private _p = RC_Y * RC_SENSIVITY;
	private _camDir = [sin _y * cos _p, cos _y * cos _p, sin _p];
	
	private _camPos = getPosASL _camera;
	private _targetPoint = _camPos vectorAdd (_camDir vectorMultiply 1000);
	
	_camera camSetTarget _targetPoint;
	_camera camCommit 0;
};


fnc_Interceptor_mousesteer = {
	params ["_uav", "_pos"];

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
            RC_X = RC_X - (0.5 - _xx);
        };
        if (!(_yy >= 0.499 and _yy <= 0.5)) then {
            RC_Y = RC_Y + (0.5 - _yy);
           	//RC_Y = ((RC_Y + (0.5 - _yy)) min 7.5) max -7.5;		//7.5 is 90° vertical limit, but doesnt yet work
        };

        RC_INTERCEPTOR_SIGNAL = 1 - ((_uav distance player) / 10000);
	};
};


//functional velocity merging version with momentum and acceleration, 1.5m sea & terrain skimming, 50% drift reduction, 3 axis differing acceleration

//fine tune flight performance
RC_ACC_FWD  = 50;	//40/40/40 seems best for 0.25 drift correction
RC_ACC_SIDE = 25;
RC_ACC_VERT = 25;

RC_MAXMS = 400 / 3.6;
RC_DRIFT_DAMPENING = 1;		//lower = much more skillbased, 0 makes it near unable to hit at speed

RC_PREV_VEL = [0, 0, 0];
RC_PREV_POS = [0, 0, 0];
RC_DT = 0.01;
RC_G = 9.81;

RC_MIN_HEIGHT = 1.5;   			// sea/terrain level skimming (meters)
RC_SKIMMING_DROP_EXPONENT = 6;  // factor for how much the drop input is reduced when flying close to the ground, higher factor = stronger reduction
RC_SKIMMING_PUSH = 30;			// proportional force
RC_SKIMMING_DAMP = 5;			// damping force

fnc_Interceptor_SetVel = {
	params ["_uav"];

	private _dt = diag_deltaTime * 0.25 + 0.75 * RC_DT;
	RC_DT = _dt;

	// 1. CAPTURE INPUTS
	private _curFwd  = (if (RC_FORWARD) then { 1 } else { 0 }) + (if (RC_BACKWARD) then { -1 } else { 0 });
	private _curSide = (if (RC_LEFT)	then { 1 } else { 0 }) + (if (RC_RIGHT)	then { -1 } else { 0 });
	private _curVert = (if (RC_LIFT)	then { 1 } else { 0 }) + (if (RC_DROP)	 then { -0.5 } else { 0 });

	private _currentPos = getPosASL _uav;
	private _currentVel = velocity _uav;
	
	// 2. DUAL SKIMMING (ASL + AGL)
	private _above = (_currentPos # 2) min ((getPosATL _uav) # 2);

	//ADD DIRECTIONAL ATL to prevent crashing while flying towards hill

	private _skimmingDrop = if (_above > 0) then {
		((((_above - RC_MIN_HEIGHT) / _above) max 0) min 1) ^ RC_SKIMMING_DROP_EXPONENT;
	} else {
		0
	};

	private _curVert = (if (RC_LIFT)	then { 1 } else { 0 }) + (if (RC_DROP)	 then { -_skimmingDrop } else { 0 });

	// height check
	private _safetyPush = 0;
	if (_above < RC_MIN_HEIGHT) then {
		private _depth = RC_MIN_HEIGHT - _above;
		private _fallingSpeed = 0 max (-(_currentVel # 2));
		_safetyPush = (_depth * RC_SKIMMING_PUSH) + (_fallingSpeed * RC_SKIMMING_DAMP);
	};

	// 3. ORIENTATION
	private _y = RC_X * RC_SENSIVITY;
	private _p = RC_Y * RC_SENSIVITY;
	private _vDir = [sin _y * cos _p, cos _y * cos _p, sin _p];
	private _speed = vectorMagnitude _currentVel;

	// 4. AXIS VECTORS
	private _forward = _vDir;
	private _vFlat = [_vDir # 0, _vDir # 1, 0];
	private _magF = vectorMagnitude _vFlat;
	if (_magF > 0) then { _vFlat = _vFlat vectorMultiply (1/_magF) };
	private _sideVec = [-(_vFlat # 1), (_vFlat # 0), 0];
	private _magS = vectorMagnitude _sideVec;
	if (_magS > 0) then { _sideVec = _sideVec vectorMultiply (1/_magS) };

	// 5. USER INTENT
	private _fwdAcc  = _forward vectorMultiply (_curFwd * RC_ACC_FWD);
	private _sideAcc = _sideVec vectorMultiply (_curSide * RC_ACC_SIDE);
	private _vertAcc = [0,0,1] vectorMultiply (_curVert * RC_ACC_VERT);
	private _pureInput = _fwdAcc vectorAdd _sideAcc vectorAdd _vertAcc;

	// MAGNITUDE CLAMPING
	private _inputMag = vectorMagnitude _pureInput;
	if (_inputMag > RC_ACC_FWD) then {
		_pureInput = (vectorNormalized _pureInput) vectorMultiply RC_ACC_FWD;
	};

	// 6. SMART ANTI-DRIFT
	private _antiDriftAcc = [0,0,0];
	if (_curFwd != 0 || _curSide != 0 || _curVert != 0) then {
		private _intendedDir = vectorNormalized _pureInput;
		private _velAlongIntention = _intendedDir vectorMultiply (_currentVel vectorDotProduct _intendedDir);
		private _driftVel = _currentVel vectorDiff _velAlongIntention;
		_antiDriftAcc = _driftVel vectorMultiply (-RC_DRIFT_DAMPENING);
	} else {
		_antiDriftAcc = _currentVel vectorMultiply (-RC_DRIFT_DAMPENING);
	};

	// 7. DRAG & PHYSICS
	private _dragAcc = _currentVel vectorMultiply (-_speed * RC_ACC_FWD / (RC_MAXMS * RC_MAXMS));
	private _accel = _pureInput vectorAdd _antiDriftAcc vectorAdd _dragAcc vectorAdd [0, 0, RC_G + _safetyPush];

	// 8. APPLY
	private _newVel = _currentVel vectorAdd (_accel vectorMultiply _dt);
	_uav setVelocity _newVel;
	_uav setVectorDirAndUp [_vDir, [[0, -sin _p, cos _p], -_y] call BIS_fnc_rotateVector2D];

	RC_PREV_VEL = (_currentPos vectorDiff RC_PREV_POS) vectorMultiply (1/_dt);
	RC_PREV_POS = _currentPos;
};


fnc_Interceptor_destroy = {
	params ["_uav", "_pos"];
	
	private _controls = localNameSpace getVariable ["RC_Interceptor_controls", []];
	_display closeDisplay 1;
	private _PP_colorC = localNameSpace getVariable ["RC_Interceptor_PP_colorC",  -1];
	private _PP_dynamic = localNameSpace getVariable ["RC_Interceptor_PP_dynamic",  -1];
	private _PP_film = localNameSpace getVariable ["RC_Interceptor_PP_film",  -1];

	ppEffectDestroy _PP_colorC;
	ppEffectDestroy _PP_dynamic;
	ppEffectDestroy _PP_film;

	removeMissionEventHandler ["EachFrame", _idEachFrame];
	removeMissionEventHandler ["EachFrame", _idEventHead];
	_display displayRemoveEventHandler ["KeyDown", _idNvg];
	_controls apply { ctrlDelete _x };

	// deleteVehicle _uav;      //was that right or wrong? *right for current version which doesnt spawn seperate ammo

	camUseNVG false;
	false setCamUseTI 1;

	//planned: add short static camera effect after detonation

	_camera cameraEffect ["terminate","back"];
	camDestroy _camera;

	cutText ["", "PLAIN"];
	"SB_RscCompass" cutText ["", "PLAIN"];
};


/*
//full destroy version, reimplement whats needed later

fnc_Interceptor_destroy = {
	//params ["_uav", "_pos", "_magazine"];
	params ["_uav", "_pos", "_magazine"];

	private _time           = time + 600;     //10min flight time
	private _camera         = localNameSpace getVariable ["RC_Interceptor_camera", objNull];
	private _PP_colorC      = localNameSpace getVariable ["RC_Interceptor_PP_colorC",  -1];
	private _PP_dynamic     = localNameSpace getVariable ["RC_Interceptor_PP_dynamic",  -1];
	private _PP_film        = localNameSpace getVariable ["RC_Interceptor_PP_film",  -1];
	private _idEachFrame    = localNameSpace getVariable ["RC_Interceptor_idEachFrame", -1];
	private _idEventHead    = localNameSpace getVariable ["RC_Interceptor_idEventHead", -1];
	private _idMouse        = localNameSpace getVariable ["RC_Interceptor_idMouse", -1];
	private _idNvg          = localNameSpace getVariable ["RC_Interceptor_idNvg", -1]; 
	private _idSlowDown     = localNameSpace getVariable ["RC_Interceptor_idSlowDown", -1]; 
	private _idUpSpeed      = localNameSpace getVariable ["RC_Interceptor_idUpSpeed", -1]; 
	private _controls       = localNameSpace getVariable ["RC_Interceptor_controls", []];

	//private _ammo           = getText (configFile >> "CfgMagazines" >> _magazine >> "ammo");
	private _ammo = "Interceptor_MP";


	waitUntil {
		!(canMove _uav) ||
		((_uav distance _pos) > 10000) ||
		(time > _time)
	};

	deleteVehicle ((attachedObjects _uav)#0);   //removes target
	_ammo = createVehicle [_ammo, (_uav modelToWorld [0, 0, 0]), [], 0, "CAN_COLLIDE"];
	_ammo setVectorDirAndUp [vectorDir _camera, vectorUp _camera];


	ppEffectDestroy _PP_colorC;
	ppEffectDestroy _PP_dynamic;
	ppEffectDestroy _PP_film;

	removeMissionEventHandler ["EachFrame", _idEachFrame];
	removeMissionEventHandler ["EachFrame", _idEventHead];
	findDisplay 46 displayRemoveEventHandler ["KeyDown", _idNvg];
	_controls apply { ctrlDelete _x };
		
	deleteVehicle _uav;

	camUseNVG false;
	false setCamUseTI 1;

	_camera cameraEffect ["terminate","back"];
	camDestroy _camera;

	cutText ["", "PLAIN"];
	"SB_RscCompass" cutText ["", "PLAIN"];
};
*/