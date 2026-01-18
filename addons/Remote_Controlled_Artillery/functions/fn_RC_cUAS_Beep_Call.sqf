params ["_CUAS_VehArray","_side"];


private _targetsDL = listRemoteTargets _side;
private _validTargets = [];
{
	private _target = _x select 0;

	if (!isNull _target && {_target isKindOf "Air"}) then {
		if ([side _target, _side] call BIS_fnc_sideIsEnemy) then {
			if (side _target != civilian) then {
				_validTargets pushBack _target;
			};
		};
	};
} forEach _targetsDL;


private _validTargetsCount = count _validTargets;
if (_validTargetsCount > 0) then {
	{
		private _veh = _x;

		//create a list of distances for this vehicle
		private _distArr = _validTargets apply {_x distance _veh};
		private _closestDist = selectMin _distArr;
		private _beepDist = _veh getVariable ["cUAS_BeepDist", 400];


		if (_closestDist < _beepDist) then {
			
			//_cycle = _cycle + 1;
			//if ((_cycle >= 4) or (_validTargetsCount > (_veh getVariable ["cUAS_oldTargetsCount", 400]) )) then {

			private _dNorm = (_closestDist / _beepDist) min 1;
			private _vol   = (1 - _dNorm) * 0.11 + 0.04;
			_vol = _vol max 0.04 min 0.15;
			private _sound = ["a3\sounds_f\air\heli_light_01\warning.wss", _vol, 0.8];


			private _crewPlayerCount = count ((crew _veh) select {isPlayer _x});

			if (_crewPlayerCount > 0) then {
				
				[_sound] remoteExec ["playSoundUI", crew _veh];
			};


			private _controllers = (UAVControl _veh);
			private _controller1 = _controllers select 0;
	
			if (_controller1 isNotEqualTo objNull) then {

				[_sound] remoteExec ["playSoundUI", _controller1];

				if (count _controllers > 2) then {

					private _controller2 = _controllers select 2;
					[_sound] remoteExec ["playSoundUI", _controller2];
				};
			};

			//_cycle = 0;
			//_veh setVariable ['cUAS_oldTargetsCount', _validTargetsCount]
		};

	} forEach _CUAS_VehArray;
};