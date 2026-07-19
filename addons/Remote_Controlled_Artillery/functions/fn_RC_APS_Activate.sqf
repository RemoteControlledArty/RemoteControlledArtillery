/*
	Author: Ascent

	Description:
	APS
*/

//fnc_RC_APS_Activate = {

params ["_vic", "_proj"];

//systemchat "APS start";	//debug

private _chargesAPS = {_x isEqualTo "RC_1Rnd_APS_M"} count (_vic magazinesTurret [-1]);

if (_chargesAPS > 0) then {

	//systemchat "_chargesAPS > 0";	//debug

	private _ammoType = typeOf _proj;
	private _ammoConfig = configFile >> "CfgAmmo" >> _ammoType;
	private _ammoSim = getText (_ammoConfig >> "simulation");
	private _profiles = getArray (_ammoConfig >> "flightProfiles");
	//private _submunDir = getText (_ammoConfig >> "submunitionDirectionType");
	private _canOverfly = "Overfly" in _profiles;
	//private _submunTargetDir = "SubmunitionTargetDirection" in _submunDir;

	[_vic, _proj, _ammoSim, _canOverfly] spawn
	{
		params ["_vic", "_proj", "_ammoSim", "_canOverfly"];

		scopeName "APS";
		private _prevDist = 121;
		private _interceptDist = 120;

		while {alive _vic && alive _proj} do {

			//systemchat "while alive";	//debug

			private _curDist = _proj distance _vic;
			if (_curDist < _interceptDist) then {

				// exit if projectile already passed
				if (_curDist > _prevDist) exitWith {
					//systemchat "passed";	//debug
				};

				private _chargesAPS = {_x isEqualTo "RC_1Rnd_APS_M"} count (_vic magazinesTurret [-1]);
				if (_chargesAPS > 0) then {
				
					// only proceed if terrain doesnt block missile / countermeasure
					if (terrainIntersectASL [((getPosASL _vic) vectorAdd [0, 0, 2.5]), getPosASL _proj]) then {continue};
					

					// basic values
					private _projVel = velocity _proj;
					private _projPos = getPosASL _proj;
					private _projDir = getDir _proj;

					// average vehicle sizes
					private _halfWidth  = 1.75;
					private _halfLength = 3.75;
					private _halfHeight = 1.75;

					// vehicle forward/right/up axes, flattened horizontally
					private _fwd = vectorDirVisual _vic;
					_fwd = vectorNormalized [_fwd#0, _fwd#1, 0];
					private _right = [(_fwd#1), -(_fwd#0), 0];

					// vehicle center of mass
					private _vicCenter = AGLToASL (_vic modelToWorldVisual (getCenterOfMass _vic));


					// checks if buildings / rocks block the sensor and countermeasure
					private _sensorsHeight = 1.4;
					private _centerPos = _vicCenter vectorAdd [0,0,_sensorsHeight];

					// horizontal approach direction and its perpendicular
					private _dirHoriz = [(_projPos#0)-(_centerPos#0), (_projPos#1)-(_centerPos#1), 0];
					_dirHoriz = vectorNormalized _dirHoriz;
					private _perp = [-(_dirHoriz#1), (_dirHoriz#0), 0];

					private _offsetDist = (_halfWidth  * abs(_right vectorDotProduct _perp))
										+ (_halfLength * abs(_fwd   vectorDotProduct _perp));

					// side sensors if center sensor obstructed
					private _leftPos  = _centerPos vectorAdd (_perp vectorMultiply _offsetDist);
					private _rightPos = _centerPos vectorAdd (_perp vectorMultiply (-_offsetDist));

					// building/rock obstruction check from center, left, right sensors
					private _fnc_objClear = {
						params ["_from"];
						private _hits = lineIntersectsObjs [_from, _projPos, _vic, _proj, false];
						({_x isKindOf "Building" || {_x isKindOf "Rock"}} count _hits) == 0
					};

					private _objClear = ([_centerPos] call _fnc_objClear)
									|| ([_leftPos]   call _fnc_objClear)
									|| ([_rightPos]  call _fnc_objClear);

					// restart if buildings / rocks block the sensor and countermeasure
					if !(_objClear) then {continue};


					// relative position/velocity of projectile vs vehicle
					private _relPos = [
						(_projPos#0) - (_vicCenter#0),
						(_projPos#1) - (_vicCenter#1),
						(_projPos#2) - (_vicCenter#2)
					];
					private _vicVel  = velocity _vic;
					private _relVel = [
						(_projVel#0) - (_vicVel#0),
						(_projVel#1) - (_vicVel#1),
						(_projVel#2) - (_vicVel#2)
					];

					// transform into vehicle-local axes (right, forward, up)
					private _up = [0,0,1];
					private _localPos = [
						_relPos vectorDotProduct _right,
						_relPos vectorDotProduct _fwd,
						_relPos vectorDotProduct _up
					];
					private _localVel = [
						_relVel vectorDotProduct _right,
						_relVel vectorDotProduct _fwd,
						_relVel vectorDotProduct _up
					];

					// for hit/miss calculation
					private _tEnter = -1e6;
					private _tExit  = 1e6;
					private _possible = true;


					// --- if UNGUIDED ROCKET ---
					if (_ammoSim isEqualTo "shotRocket") then {
						
						private _bounds = [[-_halfWidth,_halfWidth], [-_halfLength,_halfLength], [-_halfHeight,_halfHeight]];

						for "_i" from 0 to 2 do {
							private _p = _localPos select _i;
							private _v = _localVel select _i;
							private _bound = _bounds select _i;
							private _lo = _bound select 0;
							private _hi = _bound select 1;

							if (abs(_v) < 0.001) then {
								if (_p < _lo || {_p > _hi}) then { _possible = false };
							} else {
								private _t1 = (_lo - _p) / _v;
								private _t2 = (_hi - _p) / _v;
								_tEnter = _tEnter max (_t1 min _t2);
								_tExit  = _tExit  min (_t1 max _t2);
							};
						};
						
						private _willHit = _possible && {_tEnter <= _tExit} && {_tExit >= 0};
						//systemchat str _willHit;	//debug

						if (_willHit) exitWith {
							// global argument, global effect
							deleteVehicle _proj;

							/*
							if (_submunTargetDir) then {
								deleteVehicle _proj;
							} else {
								private _dist = _projPos distance (getPosASL _vic);
								private _timeOffset = ((_dist/2) min 15) / (vectorMagnitude _projVel);
								private _interceptPosASL = [
									(_projPos #0) + (_projVel #0) * _timeOffset,
									(_projPos #1) + (_projVel #1) * _timeOffset,
									(_projPos #2) + (_projVel #2) * _timeOffset
								];
								
								_proj setVelocity [0,0,0];
								_proj setDir (_projDir + 90);
								_proj setPosASL _interceptPosASL;
								triggerAmmo _proj;
							};
							*/
							
							[_projPos, _projVel, _projDir, _vic, _vicCenter, _chargesAPS] call RC_fnc_RC_APS_intercept;
							// needed to not multitrigger
							breakOut "APS";
						};

					} else {
						
						// --- if GUIDED MISSILE ---
						// margin for potential missile guidance
						private _guidanceMargin = 1.5;
						private _hw = _halfWidth  + _guidanceMargin;
						private _hl = _halfLength + _guidanceMargin;
						private _hu = _halfHeight + _guidanceMargin;

						// taller margin NEEDED if missile is overfly capable
						private _highMargin = if (_canOverfly) then {15} else {_halfHeight + _guidanceMargin};
						private _bounds = [[-_hw,_hw], [-_hl,_hl], [-_hu,_highMargin]];

						for "_i" from 0 to 2 do {
							private _p = _localPos select _i;
							private _v = _localVel select _i;
							private _bound = _bounds select _i;
							private _lo = _bound select 0;
							private _hi = _bound select 1;

							if (abs(_v) < 0.001) then {
								if (_p < _lo || {_p > _hi}) then { _possible = false };
							} else {
								private _t1 = (_lo - _p) / _v;
								private _t2 = (_hi - _p) / _v;
								_tEnter = _tEnter max (_t1 min _t2);
								_tExit  = _tExit  min (_t1 max _t2);
							};
						};

						private _willHit = _possible && {_tEnter <= _tExit} && {_tExit >= 0};
						//systemchat str _willHit;	//debug

						if (_willHit) exitWith {
							// global argument, global effect
							deleteVehicle _proj;

							/*
							if (_submunTargetDir) then {
								deleteVehicle _proj;
							} else {
								private _dist = _projPos distance (getPosASL _vic);
								private _timeOffset = ((_dist/2) min 15) / (vectorMagnitude _projVel);
								private _interceptPosASL = [
									(_projPos #0) + (_projVel #0) * _timeOffset,
									(_projPos #1) + (_projVel #1) * _timeOffset,
									(_projPos #2) + (_projVel #2) * _timeOffset
								];
								
								_proj setVelocity [0,0,0];
								_proj setDir (_projDir + 90);
								_proj setPosASL _interceptPosASL;
								triggerAmmo _proj;
							};
							*/

							[_projPos, _projVel, _projDir, _vic, _vicCenter, _chargesAPS] call RC_fnc_RC_APS_intercept;
							// needed to not multitrigger
							breakOut "APS";
						};
					};
				};
			};

			_prevDist = _curDist;
		};
	};
};

//};