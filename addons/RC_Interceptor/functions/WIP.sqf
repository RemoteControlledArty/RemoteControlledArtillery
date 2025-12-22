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

//velocity merging version
fnc_Interceptor_SetVel = {
	params ["_uav"];

	private _dt = diag_deltaTime * 0.25 + 0.75 * RC_DT;
	RC_DT = _dt;
	

	// 1. DIRECT TARGET LOGIC (Instant 0 or 350)
	// Removed smoothing: _cur values now equal _tar values immediately
	private _curFwd  = (if (RC_FORWARD) then { 1 } else { 0 }) + (if (RC_BACKWARD) then { -1 } else { 0 });
	private _curSide = (if (RC_RIGHT) then { 1 } else { 0 }) + (if (RC_LEFT) then { -1 } else { 0 });
	private _curVert = (if (RC_LIFT) then { 1 } else { 0 }) + (if (RC_DROP) then { -1 } else { 0 });

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