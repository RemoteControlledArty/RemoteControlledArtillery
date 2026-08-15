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
*/

//private _v = vehicle player;
//_v setVariable ["RC_cUAS_SensorRange", 400];


params ["_v"];

[_v] spawn {
	params ["_v"];
	
	//private _sensorRange = getNumber (configFile >> "CfgVehicles" >> (typeOf _veh) >> "RC_cUAS_Range");
	//if (_sensorRange < 10) then {_sensorRange = 400};  
	
	while {(!isNull _v) && (alive _v)} do {

		sleep 1;
		
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