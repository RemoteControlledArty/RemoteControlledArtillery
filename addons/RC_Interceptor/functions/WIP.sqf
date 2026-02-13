//FILE NOT LOADED, just a notepad for scripts


//for SP testing
player addItem "Interceptor_MP_Throw";
player addItem "Interceptor_MP_Throw";
player addItem "Interceptor_MP_Throw";
player addItem "Interceptor_MP_Throw";
player addItem "Interceptor_MP_Throw";
player addItem "Interceptor_MP_Throw";


//global modifiers
RC_ACC = 50.0;
RC_MAXMS = 350.0 / 3.6;

RC_PREV_VEL = [0, 0, 0];
RC_PREV_POS = [0, 0, 0];
RC_DT = 0.01;
RC_G = 9.81;



//version 5
//functional velocity merging version with momentum and acceleration, 0.5m sea skimming, 1.5m terrain skimming, 50% drift reduction, 3 axis differing acceleration
RC_ACC_FWD  = 50;
RC_ACC_SIDE = 25;
RC_ACC_VERT = 25;

RC_MAXMS = 400 / 3.6;
RC_DRIFT_DAMPENING = 1;

RC_PREV_VEL = [0, 0, 0];
RC_PREV_POS = [0, 0, 0];
RC_DT = 0.01;
RC_G = 9.81;

RC_MIN_HEIGHT_ASL = 1;   // sea level protection (meters)
RC_MIN_HEIGHT_AGL = 1.5; // terrain protection (meters)
RC_SKIMMING_PUSH = 30;	 // proportional force
RC_SKIMMING_DAMP = 5;	 // damping force

//ADD SKIM logic above inputs, to reduce exess downward thrust when close to ground


fnc_Interceptor_SetVel = {
	params ["_uav"];

	private _dt = diag_deltaTime * 0.25 + 0.75 * RC_DT;
	RC_DT = _dt;

	// 1. CAPTURE INPUTS
	private _curFwd  = (if (RC_FORWARD) then { 1 } else { 0 }) + (if (RC_BACKWARD) then { -1 } else { 0 });
	private _curSide = (if (RC_LEFT)	then { 1 } else { 0 }) + (if (RC_RIGHT)	then { -1 } else { 0 });
	private _curVert = (if (RC_LIFT)	then { 1 } else { 0 }) + (if (RC_DROP)	 then { -0.5 } else { 0 });

	// 2. ORIENTATION
	private _y = RC_X * RC_SENSIVITY;
	private _p = RC_Y * RC_SENSIVITY;
	private _vDir = [sin _y * cos _p, cos _y * cos _p, sin _p];

	private _currentVel = velocity _uav;
	private _currentPos = getPosASL _uav;
	private _speed = vectorMagnitude _currentVel;

	// 3. AXIS VECTORS
	private _forward = _vDir;
	private _vFlat = [_vDir # 0, _vDir # 1, 0];
	private _magF = vectorMagnitude _vFlat;
	if (_magF > 0) then { _vFlat = _vFlat vectorMultiply (1/_magF) };
	private _sideVec = [-(_vFlat # 1), (_vFlat # 0), 0];
	private _magS = vectorMagnitude _sideVec;
	if (_magS > 0) then { _sideVec = _sideVec vectorMultiply (1/_magS) };

	// 4. USER INTENT
	private _fwdAcc  = _forward vectorMultiply (_curFwd * RC_ACC_FWD);
	private _sideAcc = _sideVec vectorMultiply (_curSide * RC_ACC_SIDE);
	private _vertAcc = [0,0,1] vectorMultiply (_curVert * RC_ACC_VERT);
	private _pureInput = _fwdAcc vectorAdd _sideAcc vectorAdd _vertAcc;

	// MAGNITUDE CLAMPING
	private _inputMag = vectorMagnitude _pureInput;
	if (_inputMag > RC_ACC_FWD) then {
		_pureInput = (vectorNormalized _pureInput) vectorMultiply RC_ACC_FWD;
	};

	// 5. SMART ANTI-DRIFT
	private _antiDriftAcc = [0,0,0];
	if (_curFwd != 0 || _curSide != 0 || _curVert != 0) then {
		private _intendedDir = vectorNormalized _pureInput;
		private _velAlongIntention = _intendedDir vectorMultiply (_currentVel vectorDotProduct _intendedDir);
		private _driftVel = _currentVel vectorDiff _velAlongIntention;
		_antiDriftAcc = _driftVel vectorMultiply (-RC_DRIFT_DAMPENING);
	} else {
		_antiDriftAcc = _currentVel vectorMultiply (-RC_DRIFT_DAMPENING);
	};

	// === 6. DUAL SKIMMING (ASL + AGL) ===
	private _altASL = _currentPos # 2;
	private _altAGL = (getPosATL _uav) # 2;
	
	private _safetyPushASL = 0;
	private _safetyPushAGL = 0;
	
	// ASL Check
	if (_altASL < RC_MIN_HEIGHT_ASL) then {
		private _depth = RC_MIN_HEIGHT_ASL - _altASL;
		private _fallingSpeed = 0 max (-(_currentVel # 2));
		_safetyPushASL = (_depth * RC_SKIMMING_PUSH) + (_fallingSpeed * RC_SKIMMING_DAMP);
	};
	
	// AGL Check
	if (_altAGL < RC_MIN_HEIGHT_AGL) then {
		private _depth = RC_MIN_HEIGHT_AGL - _altAGL;
		private _fallingSpeed = 0 max (-(_currentVel # 2));
		_safetyPushAGL = (_depth * RC_SKIMMING_PUSH) + (_fallingSpeed * RC_SKIMMING_DAMP);
	};
	
	private _safetyPush = _safetyPushASL max _safetyPushAGL;

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


//version 4
//functional velocity merging version with momentum and acceleration, 0.5m sea skimming, 50% drift reduction
fnc_Interceptor_SetVel = {
	params ["_uav"];

	private _dt = diag_deltaTime * 0.25 + 0.75 * RC_DT;
	RC_DT = _dt;

	// 1. DIRECT TARGET LOGIC (Your Coefficients)
	private _curFwd  = (if (RC_FORWARD) then { 1 } else { 0 }) + (if (RC_BACKWARD) then { -1 } else { 0 });
	private _curSide = (if (RC_LEFT)	then { 0.5 } else { 0 }) + (if (RC_RIGHT)	then { -0.5 } else { 0 });
	private _curVert = (if (RC_LIFT)	then { 0.5 } else { 0 }) + (if (RC_DROP)	 then { -0.25 } else { 0 });

	// 2. ORIENTATION
	private _y = RC_X * RC_SENSIVITY;
	private _p = RC_Y * RC_SENSIVITY;
	private _vDir = [sin _y * cos _p, cos _y * cos _p, sin _p];

	private _currentVel = velocity _uav;
	private _currentPos = getPosASL _uav;
	private _speed = vectorMagnitude _currentVel;

	// 3. AXIS VECTORS
	private _forward = _vDir;
	private _vFlat = [_vDir # 0, _vDir # 1, 0];
	private _magF = vectorMagnitude _vFlat;
	if (_magF > 0) then { _vFlat = _vFlat vectorMultiply (1/_magF) };
	private _sideVec = [-(_vFlat # 1), (_vFlat # 0), 0];
	private _magS = vectorMagnitude _sideVec;
	if (_magS > 0) then { _sideVec = _sideVec vectorMultiply (1/_magS) };

	// 4. USER INTENT
	private _pureInput = (_forward vectorMultiply (_curFwd * RC_ACC)) 
	vectorAdd (_sideVec vectorMultiply (_curSide * RC_ACC)) 
	vectorAdd ([0,0,1] vectorMultiply (_curVert * RC_ACC));

	// 5. SMART ANTI-DRIFT
	private _antiDriftAcc = [0,0,0];
	if (_curFwd != 0 || _curSide != 0 || _curVert != 0) then {
		private _intendedDir = vectorNormalized _pureInput;
		private _velAlongIntention = _intendedDir vectorMultiply (_currentVel vectorDotProduct _intendedDir);
		private _driftVel = _currentVel vectorDiff _velAlongIntention;
		_antiDriftAcc = _driftVel vectorMultiply (-RC_DRIFT_DAMPENING);
	} else {
		_antiDriftAcc = _currentVel vectorMultiply (-RC_DRIFT_DAMPENING);
	};

	// --- 6. ASL SAFETY FLOOR ---
	private _minHeight = 0.5;
	private _alt = _currentPos # 2;
	private _safetyPush = 0;
	if (_alt < _minHeight) then {
		// 1. Calculate how much we are 'under' the floor
		private _depth = _minHeight - _alt;
		
		// 2. Isolate downward velocity (if Z is -10, _fallingSpeed becomes 10)
		private _fallingSpeed = 0 max (-(_currentVel # 2));
	
		// 3. Apply the force
		_safetyPush = (_depth * 150) + (_fallingSpeed * 20);
	};

	// 7. DRAG & FINAL ACCEL
	private _dragAcc = _currentVel vectorMultiply (-_speed * RC_ACC / (RC_MAXMS * RC_MAXMS));
	
	private _accel = _pureInput 
	vectorAdd _antiDriftAcc 
	vectorAdd _dragAcc 
	vectorAdd [0, 0, RC_G + _safetyPush]; // Added to gravity cancel

	// 8. APPLY
	private _newVel = _currentVel vectorAdd (_accel vectorMultiply _dt);
	_uav setVelocity _newVel;
	_uav setVectorDirAndUp [_vDir, [[0, -sin _p, cos _p], -_y] call BIS_fnc_rotateVector2D];

	RC_PREV_VEL = (_currentPos vectorDiff RC_PREV_POS) vectorMultiply (1/_dt);
	RC_PREV_POS = _currentPos;
};


//version 3
//functional velocity merging version with momentum and acceleration, 50% drift reduction, 3 axis differing acceleration
RC_MAXMS = 400 / 3.6;
RC_DRIFT_DAMPENING = 1;  //0 = disabled, 1 = moderate, 2 = strong

RC_ACC_FWD  = 50;   // forward/backward
RC_ACC_SIDE = 25;   // left/right
RC_ACC_VERT = 25;   // up/down

fnc_Interceptor_SetVel = {
	params ["_uav"];

	private _dt = diag_deltaTime * 0.25 + 0.75 * RC_DT;
	RC_DT = _dt;

	// 1. CAPTURE INPUTS (-1 to 1)
	private _curFwd  = (if (RC_FORWARD) then { 1 } else { 0 }) + (if (RC_BACKWARD) then { -1 } else { 0 });
	private _curSide = (if (RC_LEFT)	then { 1 } else { 0 }) + (if (RC_RIGHT)	then { -1 } else { 0 });
	private _curVert = (if (RC_LIFT)	then { 1 } else { 0 }) + (if (RC_DROP)	 then { -0.5 } else { 0 });

	// 2. ORIENTATION
	private _y = RC_X * RC_SENSIVITY;
	private _p = RC_Y * RC_SENSIVITY;
	private _vDir = [sin _y * cos _p, cos _y * cos _p, sin _p];

	private _currentVel = velocity _uav;
	private _currentPos = getPosASL _uav;
	private _speed = vectorMagnitude _currentVel;

	// 3. AXIS VECTORS
	private _forward = _vDir;
	private _vFlat = [_vDir # 0, _vDir # 1, 0];
	private _magF = vectorMagnitude _vFlat;
	if (_magF > 0) then { _vFlat = _vFlat vectorMultiply (1/_magF) };
	private _sideVec = [-(_vFlat # 1), (_vFlat # 0), 0];
	private _magS = vectorMagnitude _sideVec;
	if (_magS > 0) then { _sideVec = _sideVec vectorMultiply (1/_magS) };

	// 4. USER INTENT (Weighted by your specific RC_ACC values)
	private _fwdAcc  = _forward vectorMultiply (_curFwd * RC_ACC_FWD);
	private _sideAcc = _sideVec vectorMultiply (_curSide * RC_ACC_SIDE);
	private _vertAcc = [0,0,1] vectorMultiply (_curVert * RC_ACC_VERT);
	private _pureInput = _fwdAcc vectorAdd _sideAcc vectorAdd _vertAcc;

	// --- FIX: MAGNITUDE CLAMPING ---
	// Ensures diagonal movement doesn't exceed the main engine's power
	private _inputMag = vectorMagnitude _pureInput;
	if (_inputMag > RC_ACC_FWD) then {
		_pureInput = (vectorNormalized _pureInput) vectorMultiply RC_ACC_FWD;
	};

	// 5. SMART ANTI-DRIFT
	private _antiDriftAcc = [0,0,0];
	if (_curFwd != 0 || _curSide != 0 || _curVert != 0) then {
		private _intendedDir = vectorNormalized _pureInput;
		private _velAlongIntention = _intendedDir vectorMultiply (_currentVel vectorDotProduct _intendedDir);
		private _driftVel = _currentVel vectorDiff _velAlongIntention;
		_antiDriftAcc = _driftVel vectorMultiply (-RC_DRIFT_DAMPENING);
	} else {
		_antiDriftAcc = _currentVel vectorMultiply (-RC_DRIFT_DAMPENING);
	};

	// 6. DRAG & PHYSICS
	private _dragAcc = _currentVel vectorMultiply (-_speed * RC_ACC_FWD / (RC_MAXMS * RC_MAXMS));
	private _accel = _pureInput vectorAdd _antiDriftAcc vectorAdd _dragAcc vectorAdd [0, 0, RC_G];

	// 7. APPLY
	private _newVel = _currentVel vectorAdd (_accel vectorMultiply _dt);
	_uav setVelocity _newVel;
	_uav setVectorDirAndUp [_vDir, [[0, -sin _p, cos _p], -_y] call BIS_fnc_rotateVector2D];

	RC_PREV_VEL = (_currentPos vectorDiff RC_PREV_POS) vectorMultiply (1/_dt);
	RC_PREV_POS = _currentPos;
};


//version 2
//functional velocity merging version with momentum and acceleration, 50% drift reduction
RC_ACC = 50;
RC_MAXMS = 400 / 3.6;
RC_DRIFT_DAMPENING = 1;  //0 = disabled, 1 = moderate, 2 = strong


fnc_Interceptor_SetVel = {
	params ["_uav"];

	private _dt = diag_deltaTime * 0.25 + 0.75 * RC_DT;
	RC_DT = _dt;
	

	// 1. DIRECT TARGET LOGIC
	private _curFwd  = (if (RC_FORWARD) then { 1 } else { 0 }) + (if (RC_BACKWARD)	then { -1 } else { 0 });
	private _curSide = (if (RC_LEFT)	 then { 0.5 } else { 0 }) + (if (RC_RIGHT)	 then { -0.5 } else { 0 });
	//private _curVert = (if (RC_LIFT)	 then { 1 } else { 0 }) + (if (RC_DROP)		then { -1 } else { 0 });
	//decreases drop, which is already gravity adjusted, to reduce chance of accitental crashes
	private _curVert = (if (RC_LIFT)	 then { 0.5 } else { 0 }) + (if (RC_DROP)		then { -0.25 } else { 0 });

	// 2. ORIENTATION (Camera Aim)
	private _y = RC_X * RC_SENSIVITY;
	private _p = RC_Y * RC_SENSIVITY;
	
	private _vDir = [sin _y * cos _p, cos _y * cos _p, sin _p];

	private _currentVel = velocity _uav;
	private _currentPos = getPosASL _uav;
	private _vel = vectorMagnitude _currentVel;

		
	// _steer is the direction we want to go
	private _steer = [0,0,0];
	private _pureInput = [0,0,0]; // <-- NEW: Stores intended movement direction
	
	if (_curFwd == 0 and _curSide == 0 and _curVert == 0) then 
	{
		// hover/stop
		_steer = _currentVel vectorMultiply -1;
	}
	else
	{
		// Forward: full 3D-direction (including Z for diagonal)
		private _forward = _vDir;
		// Side: stays horizontal (level)
		private _vFlat = [_vDir # 0, _vDir # 1, 0];
		private _magF = vectorMagnitude _vFlat;
		if (_magF > 0) then { _vFlat = _vFlat vectorMultiply (1/_magF) };
		
		private _sideVec = [-(_vFlat # 1), (_vFlat # 0), 0];
		private _magS = vectorMagnitude _sideVec;
		if (_magS > 0) then { _sideVec = _sideVec vectorMultiply (1/_magS) };
		
		// <-- NEW: Save the pure input before gravity applies
		_pureInput = (_forward vectorMultiply _curFwd) vectorAdd (_sideVec vectorMultiply _curSide) vectorAdd ([0,0,1] vectorMultiply _curVert); 
		_steer = _pureInput;
	};
	
	
	// gravity compensation
	private _steerDir = (vectorNormalized _steer);
	private _steerZ = _steerDir#2;
	private _steerRad = sqrt (1 - _steerZ * _steerZ);
	private _accelMag = sqrt (RC_G * RC_G *_steerZ * _steerZ + RC_ACC * RC_ACC) - RC_G * _steerZ;
	private _steerFlat = vectorNormalized [_steer#0, _steer#1, 0];
	_steer = (_steerFlat vectorMultiply _steerRad * _accelMag) vectorAdd [0, 0, RC_G + _steerZ * _accelMag];
	

	// drag
	private _vel4Drag = _currentVel;
	private _dragAcc = _vel4Drag vectorMultiply (-_vel * RC_ACC / RC_MAXMS / RC_MAXMS);
	private _drag = vectorMagnitude _dragAcc;
	
	// --- REWORKED: SMART ANTI-DRIFT LOGIC ---
	private _antiDriftAcc = [0,0,0];
	
	if (_curFwd == 0 and _curSide == 0 and _curVert == 0) then {
		// No input: Dampen ALL movement to help brake/hover faster
		_antiDriftAcc = _currentVel vectorMultiply (-RC_DRIFT_DAMPENING);
	} else {
		// Input active: Dampen only the velocity that doesn't align with user input
		private _intendedDir = vectorNormalized _pureInput;
		
		// Find how much of our current velocity is moving in the intended direction
		private _intendedVelMag = _currentVel vectorDotProduct _intendedDir;
		private _intendedVel = _intendedDir vectorMultiply _intendedVelMag;
		
		// Subtract intended velocity from total velocity to find the unwanted drift
		private _driftVelocity = _currentVel vectorDiff _intendedVel;
		
		// Apply dampening ONLY against the unwanted drift
		_antiDriftAcc = _driftVelocity vectorMultiply (-RC_DRIFT_DAMPENING);
	};

	// acceleration (Combine drag, user steering, and anti-drift)
	private _accel = _dragAcc vectorAdd _steer vectorAdd _antiDriftAcc;
	private _newVel = _currentVel vectorAdd (_accel vectorMultiply _dt);
			
	
	// --- DEBUG HUD ---
	private _activeKeys = [];
	if (RC_FORWARD)  then { _activeKeys pushBack "Forward" };
	if (RC_BACKWARD) then { _activeKeys pushBack "Backward" };
	if (RC_LEFT)	 then { _activeKeys pushBack "Left" };
	if (RC_RIGHT)	then { _activeKeys pushBack "Right" };
	if (RC_LIFT)	 then { _activeKeys pushBack "Up" };
	if (RC_DROP)	 then { _activeKeys pushBack "Down" };
	
	private _keyString = if (count _activeKeys == 0) then {"None"} else {_activeKeys joinString " & "};
	
	private _deltaVel = (_currentPos vectorDiff RC_PREV_POS) vectorMultiply (1/_dt);
	private _deltaAcc = (_deltaVel vectorDiff RC_PREV_VEL) vectorMultiply (1/_dt);
	
	private _zVel = _newVel # 2;
	systemChat format ["Z-Velocity: %1 m/s | Z-Drift: %2 km/h", round (_zVel * 100) / 100, round (_zVel * 3.6)];
	
	hintSilent format [
		"--- INTERCEPTOR DEBUG ---\nKeys: %1\nPos: %2 m\nActualS: %3 km/h\nActualVel: %4\nComputedS: %5 km/h\nComputedVel: %6\nAccel (RC_ACC): %7 m/s2\nComputedAcc: %8 m/s2\nComputedAccel: %9\nDrag: %10 m/s^2\nDragVec: %11\nFPS: %12",
		_keyString,
		[round (_currentPos#0), round (_currentPos#1), round (_currentPos#2)],
		
		round (vectorMagnitude _currentVel * 3.6),
		[round (_currentVel#0), round (_currentVel#1), round (_currentVel#2)],
		
		round (vectorMagnitude _deltaVel * 3.6),
		[round (_deltaVel#0), round (_deltaVel#1), round (_deltaVel#2)],
		
		RC_ACC,
		round (vectorMagnitude _deltaAcc),
		[round (_deltaAcc#0), round (_deltaAcc#1), round (_deltaAcc#2)],
		_drag,
		[round (_dragAcc#0), round (_dragAcc#1), round (_dragAcc#2)],
		
		round diag_fps
	];
	
	systemchat str _dt; 

	// APPLY
	_uav setVelocity _newVel;
	_uav setVectorDirAndUp [_vDir, [[0, -sin _p, cos _p], -_y] call BIS_fnc_rotateVector2D];
	RC_PREV_VEL = _deltaVel;
	RC_PREV_POS = _currentPos;
};


//version 1
//functional velocity merging version with momentum and acceleration
fnc_Interceptor_SetVel = {
	params ["_uav"];

	private _dt = diag_deltaTime * 0.25 + 0.75 * RC_DT;
	RC_DT = _dt;
	

	// 1. DIRECT TARGET LOGIC
	private _curFwd  = (if (RC_FORWARD) then { 1 } else { 0 }) + (if (RC_BACKWARD)	then { -1 } else { 0 });
	private _curSide = (if (RC_LEFT)	 then { 1 } else { 0 }) + (if (RC_RIGHT)	 then { -1 } else { 0 });
	private _curVert = (if (RC_LIFT)	 then { 1 } else { 0 }) + (if (RC_DROP)		then { -1 } else { 0 });

	// 2. ORIENTATION (Camera Aim)
	private _y = RC_X * RC_SENSIVITY;
	private _p = RC_Y * RC_SENSIVITY;
	
	private _vDir = [sin _y * cos _p, cos _y * cos _p, sin _p];

	private _currentVel = velocity _uav;
	private _currentPos = getPosASL _uav;
	private _vel = vectorMagnitude _currentVel;
	

	// _steer is the direction we want to go
	private _steer = [0,0,0];
	if (_curFwd == 0 and _curSide == 0 and _curVert == 0) then 
	{
		// hover/stop
		_steer = _currentVel vectorMultiply -1;
	}
	else
	{
		// Forward: full 3D-direction (including Z for diagonal)
		private _forward = _vDir;
		
		// Side: stays horizontal (level)
		private _vFlat = [_vDir # 0, _vDir # 1, 0];
		private _magF = vectorMagnitude _vFlat;
		if (_magF > 0) then { _vFlat = _vFlat vectorMultiply (1/_magF) };
		
		private _sideVec = [-(_vFlat # 1), (_vFlat # 0), 0];
		private _magS = vectorMagnitude _sideVec;
		if (_magS > 0) then { _sideVec = _sideVec vectorMultiply (1/_magS) };
		
		_steer = (_forward vectorMultiply _curFwd) vectorAdd (_sideVec vectorMultiply _curSide) vectorAdd ([0,0,1] vectorMultiply _curVert);
	};
	

	// gravity compensation
	private _steerDir = (vectorNormalized _steer);
	private _steerZ = _steerDir#2;
	private _steerRad = sqrt (1 - _steerZ * _steerZ);
	private _accelMag = sqrt (RC_G * RC_G *_steerZ * _steerZ + RC_ACC * RC_ACC) - RC_G * _steerZ;
	private _steerFlat = vectorNormalized [_steer#0, _steer#1, 0];
	_steer = (_steerFlat vectorMultiply _steerRad * _accelMag) vectorAdd [0, 0, RC_G + _steerZ * _accelMag];
	
	// drag
	private _vel4Drag = _currentVel;
	private _dragAcc = _vel4Drag vectorMultiply (-_vel * RC_ACC / RC_MAXMS / RC_MAXMS);
	private _drag = vectorMagnitude _dragAcc;
	
	// acceleration
	private _accel = _dragAcc vectorAdd _steer;
	private _newVel = _currentVel vectorAdd (_accel vectorMultiply _dt);
	
	
	// --- DEBUG HUD ---
	private _activeKeys = [];
	if (RC_FORWARD)  then { _activeKeys pushBack "Forward" };
	if (RC_BACKWARD) then { _activeKeys pushBack "Backward" };
	if (RC_LEFT)	 then { _activeKeys pushBack "Left" };
	if (RC_RIGHT)	then { _activeKeys pushBack "Right" };
	if (RC_LIFT)	 then { _activeKeys pushBack "Up" };
	if (RC_DROP)	 then { _activeKeys pushBack "Down" };
	
	private _keyString = if (count _activeKeys == 0) then {"None"} else {_activeKeys joinString " & "};
	
	private _deltaVel = (_currentPos vectorDiff RC_PREV_POS) vectorMultiply (1/_dt);
	private _deltaAcc = (_deltaVel vectorDiff RC_PREV_VEL) vectorMultiply (1/_dt);
	
	private _zVel = _newVel # 2;
	systemChat format ["Z-Velocity: %1 m/s | Z-Drift: %2 km/h", round (_zVel * 100) / 100, round (_zVel * 3.6)];
	
	hintSilent format [
		"--- INTERCEPTOR DEBUG ---\nKeys: %1\nPos: %2 m\nActualS: %3 km/h\nActualVel: %4\nComputedS: %5 km/h\nComputedVel: %6\nAccel (RC_ACC): %7 m/s2\nComputedAcc: %8 m/s2\nComputedAccel: %9\nDrag: %10 m/s^2\nDragVec: %11\nFPS: %12",
		_keyString,
		[round (_currentPos#0), round (_currentPos#1), round (_currentPos#2)],
		
		round (vectorMagnitude _currentVel * 3.6),
		[round (_currentVel#0), round (_currentVel#1), round (_currentVel#2)],
		
		round (vectorMagnitude _deltaVel * 3.6),
		[round (_deltaVel#0), round (_deltaVel#1), round (_deltaVel#2)],
		
		RC_ACC,
		round (vectorMagnitude _deltaAcc),
		[round (_deltaAcc#0), round (_deltaAcc#1), round (_deltaAcc#2)],
		_drag,
		[round (_dragAcc#0), round (_dragAcc#1), round (_dragAcc#2)],
		
		round diag_fps
	];
	
	systemchat str _dt; 

	// APPLY
	_uav setVelocity _newVel;
	_uav setVectorDirAndUp [_vDir, [[0, -sin _p, cos _p], -_y] call BIS_fnc_rotateVector2D];
	RC_PREV_VEL = _deltaVel;
	RC_PREV_POS = _currentPos;
};


//old velocity merging version
fnc_Interceptor_SetVel = {
	params ["_uav"];

	private _dt = diag_deltaTime * 0.25 + 0.75 * RC_DT;
	RC_DT = _dt;
	

	// 1. DIRECT TARGET LOGIC (Instant 0 or 350)
	// Removed smoothing: _cur values now equal _tar values immediately
	private _curFwd  = (if (RC_FORWARD) then { 1 } else { 0 }) + (if (RC_BACKWARD) then { -1 } else { 0 });
	private _curSide = (if (RC_RIGHT) then { -1 } else { 0 }) + (if (RC_LEFT) then { 1 } else { 0 });
	private _curVert = (if (RC_LIFT) then { -1 } else { 0 }) + (if (RC_DROP) then { 1 } else { 0 });

	// 2. ORIENTATION (Camera Aim)
	private _y = RC_X * RC_SENSIVITY;
	private _p = RC_Y * RC_SENSIVITY;
	
	private _vDir = [sin _y * cos _p, cos _y * cos _p, sin _p];

	private _currentVel = velocity _uav;
	private _currentPos = position _uav;
	private _vel = vectorMagnitude _currentVel;
	
	//-----------------------------------------------------------------------------------------------
	// _steer is the direction we want to go
	private _steer = [0,0,0];
	if (_curFwd == 0 and _curSide == 0 and _curVert == 0) then 
	{
		// hover/stop
		_steer = _currentVel vectorMultiply -1;
	}
	else
	{
		//has inputs
		private _p0 = positionCameraToWorld [0,0,0];
		private _pFront = positionCameraToWorld [0,0,1];
		private _pRight = positionCameraToWorld [-1,0,0];
		
		private _front = vectorNormalized (_pFront vectorDiff _p0);
		private _right = vectorNormalized (_pRight vectorDiff _p0);

		_steer = (_front vectorMultiply _curFwd) vectorAdd (_right vectorMultiply _curSide) vectorAdd ([0,0,1] vectorMultiply _curVert);
	};
	// gravity is applied by the engine outside of the loop, so we may want to have gravity compensation "builtin"
	// compensate gravity, use just enough accel to counter gravity
	// the direction we want to fly to
	private _steerDir = (vectorNormalized _steer);
	private _steerZ = _steerDir#2;
	private _steerRad = sqrt (1 - _steerZ * _steerZ);
	// the acceleration we have to apply to overcome gravity, but still fly in the direction we want to head
	private _accelMag = sqrt (RC_G * RC_G *_steerZ * _steerZ + RC_ACC * RC_ACC) - RC_G * _steerZ;
	// steering direction on ground
	private _steerFlat = vectorNormalized [_steer#0, _steer#1, 0];
	// steering direction and magnitude, here RC_G is antigravity acceleration, _steerZ is the intended 
	_steer = (_steerFlat vectorMultiply _steerRad * _accelMag) vectorAdd [0, 0, RC_G + _steerZ * _accelMag];
	
	// compute Drag deccel, to include wind, we would need to add the wind velocity here, the wind direction and magnitude
	private _vel4Drag = _currentVel;
	private _dragAcc = _vel4Drag vectorMultiply (-_vel * RC_ACC / RC_MAXMS / RC_MAXMS);
	private _drag = vectorMagnitude _dragAcc;
	// add drag and steering
	private _accel = _dragAcc vectorAdd _steer;
	// compute new velocity, integrate over time
	private _newVel = _currentVel vectorAdd (_accel vectorMultiply _dt);
		
	// --- 7. DEBUG HUD (The "Clean List") ---
	private _activeKeys = [];
	if (RC_FORWARD)  then { _activeKeys pushBack "Forward" };
	if (RC_BACKWARD) then { _activeKeys pushBack "Backward" };
	if (RC_LEFT)	 then { _activeKeys pushBack "Left" };
	if (RC_RIGHT)	then { _activeKeys pushBack "Right" };
	if (RC_LIFT)	 then { _activeKeys pushBack "Up" };
	if (RC_DROP)	 then { _activeKeys pushBack "Down" };
	
	private _keyString = if (count _activeKeys == 0) then {"None"} else {_activeKeys joinString " & "};
	
	private _deltaVel = (_currentPos vectorDiff RC_PREV_POS) vectorMultiply (1/_dt);
	private _deltaAcc = (_deltaVel vectorDiff RC_PREV_VEL) vectorMultiply (1/_dt);
	
	hintSilent format [
		"--- INTERCEPTOR DEBUG ---\nKeys: %1\nPos: %2 m\nActualS: %3 km/h\nActualVel: %4\nComputedS: %5 km/h\nComputedVel: %6\nAccel (RC_ACC): %7 m/s2\nComputedAcc: %8 m/s2\nComputedAccel: %9\nDrag: %10 m/s^2\nDragVec: %11\nFPS: %12",
		_keyString,
		[round (_currentPos#0), round (_currentPos#1), round (_currentPos#2)],
		
		round (vectorMagnitude _currentVel * 3.6),
		[round (_currentVel#0), round (_currentVel#1), round (_currentVel#2)],
		
		round (vectorMagnitude _deltaVel * 3.6),
		[round (_deltaVel#0), round (_deltaVel#1), round (_deltaVel#2)],
		
		RC_ACC,
		round (vectorMagnitude _deltaAcc),
		[round (_deltaAcc#0), round (_deltaAcc#1), round (_deltaAcc#2)],
		_drag,
		[round (_dragAcc#0), round (_dragAcc#1), round (_dragAcc#2)],
		
		round diag_fps
	];
	
	// DEBUG systemChat for _dt
	systemchat str _dt; 

	// 6. APPLY
	_uav setVelocity _newVel;	//_newVel
	_uav setVectorDirAndUp [_vDir, [[0, -sin _p, cos _p], -_y] call BIS_fnc_rotateVector2D];
	RC_PREV_VEL = _deltaVel;
	RC_PREV_POS = _currentPos;
};


//functional middleground, fake momentum, decent acceleration
fnc_Interceptor_setVel = {
	params ["_uav"];

	private _dt = diag_deltaTime;
	private _maxSpeedMS = 400 / 3.6;	   

	// --- 1. TUNING PARAMETERS ---
	private _accRate   = 40 * _dt;	// How fast W accelerates you
	private _brakeRate = 40 * _dt;	// How fast Idle/S slows you down
	private _fric	  = 0.995;		// High friction (keeps momentum during flight)
	private _stopLimit = 0.3;		// ~1 km/h (Threshold to stop completely)

	// --- 2. INPUTS (Using your KeyDown variables) ---
	private _fwdInput   = (if (RC_FORWARD) then {1} else {0}) - (if (RC_BACKWARD) then {1} else {0});
	private _sideInput = (if (RC_RIGHT) then {1} else {0}) - (if (RC_LEFT) then {1} else {0});
	private _vertInput  = (if (RC_LIFT) then {1} else {0}) - (if (RC_DROP) then {1} else {0});

	// --- 3. ORIENTATION ---
	private _y = RC_X * RC_SENSIVITY; 
	private _p = RC_Y * RC_SENSIVITY;
	private _vDir = [sin _y * cos _p, cos _y * cos _p, sin _p];
	private _vUp  = [[0, -sin _p, cos _p], -_y] call BIS_fnc_rotateVector2D;

	// --- 4. LOCAL VELOCITY MATH ---
	private _localVel = _uav vectorWorldToModel (velocity _uav);
	private _vx = _localVel # 0; 
	private _vy = _localVel # 1; 
	private _vz = _localVel # 2; 

	// --- 5. THE ACTIVE BRAKING LOGIC ---
	// Forward/Back Logic
	if (_fwdInput == 1) then {
		_vy = _vy + _accRate; // Accelerating Forward
	} else {
		if (_fwdInput == -1) then {
			_vy = _vy - _brakeRate; // Manual Braking / Reverse
		} else {
			// IDLE BRAKING: If no key, move _vy toward 0 using _brakeRate
			if (_vy > _stopLimit) then { _vy = (_vy - _brakeRate) max 0; };
			if (_vy < -_stopLimit) then { _vy = (_vy + _brakeRate) min 0; };
		};
	};

	// Strafe/Vertical (Keeping these responsive)
	_vx = _vx + (_sideInput * _accRate);
	_vz = _vz + (_vertInput * _accRate);

	// If no strafe input, snap to center (prevents sliding when aiming)
	if (_sideInput == 0) then { _vx = _vx * 0.9; };
	if (_vertInput == 0) then { _vz = _vz * 0.9; };

	// Apply General Momentum Friction
	_vy = _vy * _fric;
	_vx = _vx * _fric;
	_vz = _vz * _fric;

	// --- 6. APPLY ---
	private _newLocal = [_vx, _vy, _vz];
	
	// Clamp to 400 km/h
	if (vectorMagnitude _newLocal > _maxSpeedMS) then {
		_newLocal = vectorNormalized _newLocal vectorMultiply _maxSpeedMS;
	};

	private _finalVel = (_uav vectorModelToWorldVisual _newLocal) vectorAdd [0, 0, 0.18];

	_uav setVelocity _finalVel;
	_uav setVectorDirAndUp [_vDir, _vUp];
};


//no momentum, instant acceleration
fnc_Interceptor_setVel = {
	params ["_uav"];
	
	// 1. basics
	private _dt = diag_deltaTime;
	private _maxMS = 350 / 3.6;


	// 2. keypress = instant 350 , release = instant 0
	private _curFwd  = (if (RC_FORWARD) then { 1 } else { 0 }) + (if (RC_BACKWARD)	then { -1 } else { 0 });
	private _curSide = (if (RC_LEFT) 	then { 1 } else { 0 }) + (if (RC_RIGHT) 		then { -1 } else { 0 });
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


// ---------------------------- OLD ------------------------------
//global modifiers
RC_ACC = 20.0;
RC_MAXMS = 350.0 / 3.6;
RC_DRAGCOEFF = RC_ACC / RC_MAXMS / RC_MAXMS;

//velocity merging version
fnc_Interceptor_SetVel = {
	params ["_uav"];
	  
	private _dt = diag_deltaTime;
	private _maxMS = 350 / 3.6;

	// 1. DIRECT TARGET LOGIC (Instant 0 or 350)
	// Removed smoothing: _cur values now equal _tar values immediately
	private _curFwd  = (if (RC_FORWARD) then { 1 } else { 0 }) + (if (RC_BACKWARD) then { -1 } else { 0 });
	private _curSide = (if (RC_RIGHT) then { 1 } else { 0 }) + (if (RC_LEFT) then { -1 } else { 0 });
	private _curVert = (if (RC_LIFT) then { 1 } else { 0 }) + (if (RC_DROP) then { -1 } else { 0 });

	// 2. ORIENTATION (Camera Aim)
	private _y = RC_X * RC_SENSIVITY;
	private _p = RC_Y * RC_SENSIVITY;
	
	//-----------------------------------------------------------------------------------------------
	
	/*		
	private _p0 = positionCameraToWorld [0,0,0];
	private _pFront = positionCameraToWorld [0,0,1];
	private _pRight = positionCameraToWorld [1,0,0];
	private _pDown = positionCameraToWorld [0,1,0];
	
	private _front = _pFront vectorDiff _p0;
	private _right = _pRight vectorDiff _p0;
	//private _down = _pDown vectorDiff _p0;
	*/
	
	/*	
	private _dirTurret = (_fwd #0) atan2 (_fwd #1);
	if (_dirTurret < 0) then {_dirTurret = _dirTurret + 360};
	private _pitchTurret = (_fwd #2) atan2 sqrt((_fwd #0)^2 + (_fwd #1)^2);
	*/
	  
	/* 
	//_string = str ?;
	//systemchat _string;
	
	private _vDir = _front;
	*/
	
	//-----------------------------------------------------------------------------------------------  
	
	private _vDir = [sin _y * cos _p, cos _y * cos _p, sin _p];

	// 3. VECTOR BLENDING (Hover Logic)
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
	//private _sideVec = _right;
	private _magS = vectorMagnitude _sideVec;
	if (_magS > 0) then { _sideVec = _sideVec vectorMultiply (1/_magS) };

	// 4. SUM VELOCITY & GRAVITY COMPENSATION
	private _vF = _blendedDir vectorMultiply _curFwd;
	private _vS = _sideVec vectorMultiply _curSide;
	private _vV = [0, 0, _curVert];
	private _targetVel = ((_vF vectorAdd _vS) vectorAdd _vV) vectorMultiply _maxMS;
	
	//----------------------------------------------------------------------------------------------- 
	
	private _currentVel = velocity _uav;
	
	/*
	if (RC_BACKWARD) then {
	   _currentVel = [0,0,0]; 
	};
	*/	

	private _velocityGap = _targetVel vectorDiff _currentVel;
	// get the direction of the target direction
	private _velocityGapNorm = vectorNormalized _velocityGap;
	// calculate the acceleration to apply (integrated over time step)
	// delta v = 1/2 * a * delta t
	//private _acc = RC_ACC / 2 * _dt;
	private _acc = RC_ACC * _dt;
	// get the velocity magnitude
	private _vel = vectorMagnitude _currentVel;
	// if speed less then 20, interpolate the acceleration beteen 30% at start and 100% at 20 km/h
	//if (_vel < 20) then { _acc = _acc * linearConversion [0, 20, _vel, 0.3, 1.0, true ]; };
	// calculate drag: (1/2 * A * c_a) * velocity ^ 2 ==> DRAGCOEFF * velocity ^ 2
	// also make sure it is in opposite direction of current direction
	
	private _dragVel = _currentVel vectorMultiply (-_vel * RC_DRAGCOEFF * _dt);
	//private _dragVel = _currentVel vectorMultiply (-_vel * RC_DRAGCOEFF / 2 * _dt);
	systemchat ((str ((vectorMagnitude _dragVel) - _acc)) + " " + (str _velocityGapNorm));
	// apply acceleration to direction, apply that and the drag to current velocity
	
		
	//systemchat str (_currentVel vectorCos _velocityGapNorm);
	private _vecProd = ((vectorNormalized _currentVel) vectorMultiply _velocityGapNorm);
	private _vecSum = _vecProd#0 + _vecProd#1 + _vecProd#2;
	private _string = str _vecSum;
	//systemchat _string;
	
	private _newVel = _currentVel vectorAdd _dragVel vectorAdd (_velocityGapNorm vectorMultiply _acc);
	//private _newVel = _currentVel vectorAdd (_velocityGapNorm vectorMultiply _acc);
	private _antiGravity = 0;	//0.18
	_newVel = _newVel vectorAdd [0, 0, _antiGravity];
	
		
	// --- 7. DEBUG HUD (The "Clean List") ---
	private _activeKeys = [];
	if (RC_FORWARD)  then { _activeKeys pushBack "Forward" };
	if (RC_BACKWARD) then { _activeKeys pushBack "Backward" };
	if (RC_LEFT)	 then { _activeKeys pushBack "Left" };
	if (RC_RIGHT)	then { _activeKeys pushBack "Right" };
	if (RC_LIFT)	 then { _activeKeys pushBack "Up" };
	if (RC_DROP)	 then { _activeKeys pushBack "Down" };
	
	private _keyString = if (count _activeKeys == 0) then {"None"} else {_activeKeys joinString " & "};

	hintSilent format [
		"--- INTERCEPTOR DEBUG ---\nKeys: %1\nTargetS: %2 km/h\nTargetVel: %3\nActualS: %4 km/h\nActualVel: %5\nNewS: %6 km/h\nNewVel: %7\nAccel (RC_ACC): %8\nRC_X (RC_X): %9\nRC_Y (RC_Y): %10\nFPS: %11",
		_keyString,
		
		round (vectorMagnitude _targetVel * 3.6),
		[round (_targetVel#0), round (_targetVel#1), round (_targetVel#2)],
		
		round (vectorMagnitude _currentVel * 3.6),
		[round (_currentVel#0), round (_currentVel#1), round (_currentVel#2)],
		
		round (vectorMagnitude _newVel * 3.6),
		[round (_newVel#0), round (_newVel#1), round (_newVel#2)],
		
		RC_ACC,
		RC_X,
		RC_Y,
		
		round diag_fps
	];

	
	//private _string = str [round (_currentVel#0), round (_currentVel#1), round (_currentVel#2)] + " " + str [round (_newVel#0), round (_newVel#1), round (_newVel#2)];
	
	//_string = str (_currentVel vectorDiff _newVel);
	//systemchat _string; 
	
	
	//-----------------------------------------------------------------------------------------------

	/*
	// 5. SPEED CAP, optional
	if (vectorMagnitude _newVel > _maxMS) then {
		_newVel = (vectorNormalized _newVel) vectorMultiply _maxMS;
	};
	*/

	// 6. APPLY
	_uav setVelocity _newVel;	//_newVel
	_uav setVectorDirAndUp [_vDir, [[0, -sin _p, cos _p], -_y] call BIS_fnc_rotateVector2D];
	
	/* 
	private _p0 = positionCameraToWorld [0,0,0];
	private _p1 = positionCameraToWorld [0,0,1];
	private _fwd = _p1 vectorDiff _p0;
	private _dirTurret = (_fwd #0) atan2 (_fwd #1);
	if (_dirTurret < 0) then {_dirTurret = _dirTurret + 360};
	private _pitchTurret = (_fwd #2) atan2 sqrt((_fwd #0)^2 + (_fwd #1)^2);
	
	_string = str _dirTurret;
	systemchat _string;
	*/  
};


//working 0->350 version, no velocity merging
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