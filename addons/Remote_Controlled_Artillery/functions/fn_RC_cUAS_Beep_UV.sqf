/*
	Author: Ascent

	Description:
	Beep for newly detected UAV in Datalink.
	Version adapted for unmanned vehicles.
*/

[_vic, _beepDist] spawn
{
	params ["_vic","_beepDist"];
	private _cycle = 0;

	while {true} do
	{
		sleep 1;

		if (!alive _vic) exitwith {};
		
		private _controllers = (UAVControl _vic);
		if ((_controllers select 0) isEqualTo objNull) then {
			continue;  
		};

		private _targetsDL = listRemoteTargets side _vic;

		private _targetsInDistance = (_targetsDL) select {((_x select 0) distance _vic <= _beepDist)};
		private _targetsAir = (_targetsInDistance) select {((_x select 0) isKindOf "Air")};
		private _targetsHostile = (_targetsAir) select {([side (_x select 0), side _vic] call BIS_fnc_sideIsEnemy)};
		private _targetsNotCiv = (_targetsHostile) select {(side (_x select 0) != civilian)};

		_oldTargetsCount = count _targetsNotCiv;
		_targetsCount = count _targetsNotCiv;
		if (_targetsCount > 0) then {
			
			_cycle = _cycle + 1;
			if ((_cycle >= 4) or (_targetsCount > _oldTargetsCount)) then {
				private _targetsDistances = [];
				{
					_targetsDistances pushBack ((_x select 0) distance _vic);
				} forEach _targetsNotCiv;

				private _distance = selectMin _targetsDistances;
				private _dNorm = (_distance / _beepDist) min 1;
				private _vol   = (1 - _dNorm) * 0.25 + 0.05;
				_vol = _vol max 0.05 min 0.3;

				private _sound = ["a3\sounds_f\air\heli_light_01\warning.wss", _vol, 0.8];

				private _controller1 = _controllers select 0;
				[_sound] remoteExec ["playSoundUI", crew _vic];
				
				if (count controllers > 2) then {
					private _controller2 = _controllers select 3;
					[_sound] remoteExec ["playSoundUI", crew _vic];
				};

				_cycle = 0;
			};
		};
	};
};