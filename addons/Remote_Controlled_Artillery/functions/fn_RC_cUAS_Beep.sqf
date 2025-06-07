/*
	Author: Ascent

	Description:
	Beep for newly detected UAV in Datalink.
*/


[_vic, _beepDist] spawn
{
	params ["_vic","_beepDist"];
	private _cycle = 0;

	while {true} do
	{
		sleep 1;
		if (!alive _vic) exitwith {};
		if (!local _vic) then {
			continue;
		};

		private _crewPlayers = (crew _vic) select {isPlayer _x};
		private _controllers = (UAVControl _vic);
		if (((count _crewPlayers) == 0) && ((_controllers select 0) isEqualTo objNull)) then {
			continue;  
		};

		private _targetsDL = listRemoteTargets side _vic;
		private _validTargets = [];
		{
			private _target = _x select 0;

			if (!isNull _target && {_target isKindOf "Air"}) then {
				if ((_target distance _vic <= _beepDist)) then {
					if ([side _target, side _vic] call BIS_fnc_sideIsEnemy) then {
						if (side _target != civilian) then {
							_validTargets pushBack _target;
						};
					};
				};
			};
		} forEach _targetsDL;

		_oldTargetsCount = count _validTargets;
		_targetsCount = count _validTargets;
		if (_targetsCount > 0) then {
			
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
	};
};


/*
this addEventHandler ["Local", {
	params ["_vic", "_isLocal"];

	if (!_isLocal) exitwith {};
	
	[_vic, _beepDist] spawn
	{
		params ["_vic","_beepDist"];
		private _cycle = 0;
		while {true} do
		{
			sleep 1;
			if (!local _vic) exitwith {};

			if (isRemoteControlling player) then {
				continue;
			};

			//code
		};
	};
}];
*/


/*
private _vicPos = getPosASL _vic;
private _dir = vectorNormalized (_vicPos vectorDiff _vicPos);
private _soundPos = _vicPos vectorAdd (_dir vectorMultiply 25);
playSound3D ["a3\sounds_f\air\heli_light_01\warning.wss", objNull, false, _soundPos, 10, 1, 75];
playSound3D ["a3\sounds_f\air\heli_light_01\warning.wss", objNull, false, getPosASL _vic, 20, 0.8, 60];
playSound3D ["a3\sounds_f\air\heli_light_01\warning.wss", vehicle player, false, [], 10, 0.8, 30];
*/


/*
private _targetsInDistance = (_targetsDL) select {((_x select 0) distance _vic <= _beepDist)};
private _targetsAir = (_targetsInDistance) select {((_x select 0) isKindOf "Air")};
private _targetsHostile = (_targetsAir) select {([side (_x select 0), side _vic] call BIS_fnc_sideIsEnemy)};
private _validTargets = (_targetsHostile) select {(side (_x select 0) != civilian)};
*/


/*
RC_TestScript = [] spawn
{
	_vic = vehicle player;
	private _cycle=0;

	while {true} do
	{
		sleep 1;
		systemchat (str time);

		if (!alive _vic) exitwith {};
		private _crewPlayers = (crew _vic) select {isPlayer _x};
		if ((count _crewPlayers) == 0) then {
			continue;  
		};

		private _targetsDL = listRemoteTargets side _vic;

		{
			private _target  = _x select 0;
			private _distance = _target distance _vic;
			if ((_target distance _vic <= 400) && (_target isKindOf "Air")) then {
				
				private _vicSide = side _vic;
				private _targetSide = side _target;
				if (([_targetSide, _vicSide] call BIS_fnc_sideIsEnemy) && (_targetSide != civilian)) then {

					_cycle = _cycle + 1;
					if (_cycle >= 4) then {
						private _dNorm = (_distance / 400) min 1;
						private _vol   = (1 - _dNorm) * 0.27 + 0.03;
						_vol = _vol max 0.03 min 0.3;
						private _sound = ["a3\sounds_f\air\heli_light_01\warning.wss", _vol, 0.8];
						[_sound] remoteExec ["playSoundUI", crew _vic];

						//private _vicPos = getPosASL _vic;
						//private _dir = vectorNormalized (_vicPos vectorDiff _vicPos);
						//private _soundPos = _vicPos vectorAdd (_dir vectorMultiply 25);
						//playSound3D ["a3\sounds_f\air\heli_light_01\warning.wss", objNull, false, _soundPos, 10, 1, 75];
					};

					_cycle = 0;  // Zähler zurücksetzen, um die nächsten 4 Sekunden zu zählen
				};
			};
		} forEach _targetsDL;
	};
};
*/