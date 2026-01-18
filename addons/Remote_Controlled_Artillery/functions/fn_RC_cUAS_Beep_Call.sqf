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


if (_validTargets < 1) then {
	{
		private _veh = _x;

		//create a list of distances for this vehicle
		private _distArr = _targets apply {_x distance _veh};
		//find the smallest number in that list
		private _closestDist = selectMin _distArr;


		if (_closestDist < _veh getVariable ["cUAS_BeepDist", 500];) then {
			
			_cycle = _cycle + 1;
			if ((_cycle >= 4) or (_targetsCount > _oldTargetsCount)) then {
				private _targetsDistances = [];
				{
					_targetsDistances pushBack (_x distance _vic);
				} forEach _validTargets;

				private _distance = selectMin _targetsDistances;
				private _dNorm = (_distance / _beepDist) min 1;
				private _vol   = (1 - _dNorm) * 0.11 + 0.04;
				_vol = _vol max 0.04 min 0.15;

				private _sound = ["a3\sounds_f\air\heli_light_01\warning.wss", _vol, 0.8];
				[_sound] remoteExec ["playSoundUI", crew _vic];

				private _controller1 = _controllers select 0;
				if (_controller1 isNotEqualTo objNull) then {
					[_sound] remoteExec ["playSoundUI", crew _controller1];

					if (count _controllers > 2) then {
						private _controller2 = _controllers select 3;
						[_sound] remoteExec ["playSoundUI", crew _controller2];
					};
				};

				_cycle = 0;
			};
		};

	} forEach _CUAS_VehArray;
};