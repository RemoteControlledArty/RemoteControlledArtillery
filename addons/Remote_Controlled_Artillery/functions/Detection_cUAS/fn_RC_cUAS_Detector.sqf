/*
	Author: Ascent

	Description:
	Temporary fix for anti drone sensors being destroyed by the arma update due to before unused cfgVehicles value "visualTargetSize = factor;" now having an effect.
	Problem is 400m C-UAS visual sensor * 0.05 FPV drone visual target size = 20m... 400m would take 8000m sensor which would be OP against helixopters and planes...

	_v = _vehicle;
	_vS = _vehicleSide;

	_sR = _sensorRange;
	_sR2 = _sensorRangeSquared;
	_sASL = _sensorPositionASL;

	_t = _target; (uav)

	_b = _beep;
	_pC = _playerCrew;
	_c = _controllers;
	_c1 = _controller1;
	_c2 = _controller2;
*/

//private _v = vehicle player;
//_v setVariable ["RC_cUAS_SensorRange", 400];


if (!isServer) exitWith {};

params ["_v"];


[_v] spawn {
	params ["_v"];

	
	while {(!isNull _v) && (alive _v)} do {

		sleep 2;

		//if crewed check, otherwise no side to report to
		if ((count (crew _v)) < 1) then {continue};


		//get sensor range of vehicle, backup default 400m
		private _sR = _v getVariable ["RC_cUAS_SensorRange", 400];
		//square to make distance calculation cheaper for multiple drones, 400^2 = 160000
		private _sR2 = _sR^2;
		//sensor position ASL, 1.4m above the vehicles center of mass
		private _sASL = (AGLToASL (_v modelToWorldVisual (getCenterOfMass _v))) vectorAdd [0, 0, 1.4];

		{
			//cheapest distance check
			if ((_x distanceSqr _v) > _sR2) then {continue};
			private _t = _x;
			//systemChat "in dist";
			

			//hostile check
			private _vS = side _v;
			if (!([side _t, _vS] call BIS_fnc_sideIsEnemy)) then {continue};
			//systemChat "hostile";


			//if in datalink check, including by other sensors
			if (_t in ((listRemoteTargets _vS) apply {_x #0})) then {


				//scale volume with distance
				private _b = ["a3\sounds_f\air\heli_light_01\warning.wss", ( ((1 - (((_x distanceSqr _v) / _sR2) min 1)) * 0.11 + 0.04) max 0.04 min 0.15 ), 0.8];
				/*
				private _dNorm = (_closestDist / _beepDist) min 1;
				private _vol   = (1 - _dNorm) * 0.11 + 0.04;
				_vol = _vol max 0.04 min 0.15;
				private _b = ["a3\sounds_f\air\heli_light_01\warning.wss", _vol, 0.8];
				*/


				private _pC = (crew _v) select {isPlayer _x};
				if ((count _pC) > 0) then {
					
					[_b] remoteExec ["playSoundUI", _pC];
				};


				private _c = (UAVControl _v);
				private _c1 = _c #0;
				if (_c1 isNotEqualTo objNull) then {

					[_b] remoteExec ["playSoundUI", _c1];

					if (count _c > 2) then {

						private _c2 = _c #2;
						[_b] remoteExec ["playSoundUI", _c2];
					};
				};
			};
			

			//visibility check
			if ([_v, "VIEW", _t] checkVisibility [_sASL, getPosASL _t] < 0.5) then {continue};
			/*
			private _vis = [_v, "VIEW", _t] checkVisibility [_sASL, getPosASL _t];
			if (_vis < 0.5) then {systemChat _visStr; continue};
			systemChat str _vis;
			*/


			//reporting
			[_vS, [_t, 10]] remoteExec ["reportRemoteTarget", _vS];
			//systemChat "datalinked";


			//add to array for orange mapmarker for inf, dot and "UAV"


		} forEach allUnitsUAV;
	};
};


//outdated LOS check
/*
	private _tASL = getPosASL _t;
	//terrain blocking sensor
	if (terrainIntersectASL [_sASL, _tASL]) then {continue};
	//buildings/rocks blocking sensor
	if ( ({_x isKindOf "Building" || {_x isKindOf "Rock"}} count (lineIntersectsObjs [_sASL, _tASL, _v, _t, false])) > 0) then {continue};
	systemChat "LOS";
*/