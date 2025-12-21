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
	private _targetVersion = 'RC_Projectile_Target_B';
	if (_sidePlayer == east) then {_targetVersion = 'RC_Projectile_Target_O';};
	if (_sidePlayer == resistance) then {_targetVersion = 'RC_Projectile_Target_I';};

	private _target = [[0, 0, 500], _dir, _targetVersion, east] call BIS_fnc_spawnVehicle;
	_target = _target select 0;
	_target disableCollisionWith _uav;
	_target attachTo [_uav, [0, 1, 1]];

	//output
	_target
};


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


fnc_Interceptor_setVel = {
	params ["_uav"];
	
	// 1. basics
	private _dt = diag_deltaTime;
	private _maxMS = 350 / 3.6;


	// 2. keypress = instant 350 , release = instant 0
	private _curFwd  = (if (RC_FORWARD) then { 1 } else { 0 }) + (if (RC_BACKWARD)	then { -1 } else { 0 });
	private _curSide = (if (RC_RIGHT) 	then { 1 } else { 0 }) + (if (RC_LEFT) 		then { -1 } else { 0 });
	private _curVert = (if (RC_LIFT) 	then { 1 } else { 0 }) + (if (RC_DROP) 		then { -1 } else { 0 });


	// 3. orientation (aamera aim)
	private _y = RC_X * RC_SENSIVITY;
	private _p = RC_Y * RC_SENSIVITY;
	private _vDir = [sin _y * cos _p, cos _y * cos _p, sin _p];


	// 4. vector blending (hover logic)
	private _weight = (linearConversion [0, 0.5, abs _curVert, 0, 1, true]);
	
	private _vFlat = [_vDir # 0, _vDir # 1, 0];
	private _magF = vectorMagnitude _vFlat;
	if (_magF > 0) then { _vFlat = _vFlat vectorMultiply (1/_magF) };

	private _blendedDir = [
		(_vDir # 0) + _weight * ((_vFlat # 0) - (_vDir # 0)),
		(_vDir # 1) + _weight * ((_vFlat # 1) - (_vDir # 1)),
		(_vDir # 2) + _weight * ((_vFlat # 2) - (_vDir # 2))
	];
	
	private _sideVec = [-(_blendedDir # 1), (_blendedDir # 0), 0];
	private _magS = vectorMagnitude _sideVec;
	if (_magS > 0) then { _sideVec = _sideVec vectorMultiply (1/_magS) };


	// 5. sum vel & gravity compensation
	private _vF = _blendedDir vectorMultiply _curFwd;
	private _vS = _sideVec vectorMultiply _curSide;
	private _vV = [0, 0, _curVert];
	
	private _finalVel = ((_vF vectorAdd _vS) vectorAdd _vV) vectorMultiply _maxMS;

	private _antiGravity = 0.18;
	_finalVel = _finalVel vectorAdd [0, 0, _antiGravity];


	// 6. speed cap
	if (vectorMagnitude _finalVel > _maxMS) then {
		_finalVel = (vectorNormalized _finalVel) vectorMultiply _maxMS;
	};


	// 7. apply vel and orientation
	_uav setVelocity _finalVel;
	_uav setVectorDirAndUp [_vDir, [[0, -sin _p, cos _p], -_y] call BIS_fnc_rotateVector2D];
};


//is this actually needed? isnt the camera attached to the projectile? or would it not self align?
fnc_Interceptor_updateCam = {
	params ["_uav", "_lastpos"];

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
};


fnc_Interceptor_destroy = {
	params ["_uav", "_pos"];
	
	removeMissionEventHandler ["EachFrame", _EventHead];

	private _controls = localNameSpace getVariable ["RC_Interceptor_controls", []];
	_display closeDisplay 1;
	private _PP_colorC = localNameSpace getVariable ["RC_Interceptor_PP_colorC",  -1];
	private _PP_dynamic = localNameSpace getVariable ["RC_Interceptor_PP_dynamic",  -1];
	private _PP_film = localNameSpace getVariable ["RC_Interceptor_PP_film",  -1];

	ppEffectDestroy _PP_colorC;
	ppEffectDestroy _PP_dynamic;
	ppEffectDestroy _PP_film;

	removeMissionEventHandler ["EachFrame", _idEachFrame];
	removeMissionEventHandler ["EachFrame", _EventHead];
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
	private _idEventHead    = localNameSpace getVariable ["RC_Interceptor_EventHead", -1];
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