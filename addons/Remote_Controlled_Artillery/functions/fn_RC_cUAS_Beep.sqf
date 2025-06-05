/*
	Author: Ascent

	Description:
	Beep for newly detected UAV in Datalink.
*/

// Need to exit early if we aren't a client
//if (!isServer) exitWith {};

params ["_vic"];
RC_cUAS_Beep = ["_vic"] spawn
{
	params ["_vic"];
	//_vic = vehicle player;
	private _cycle = 0;

	while {true} do
	{
		sleep 1;

		if (!alive _vic) exitwith {};
		private _crewPlayers = (crew _vic) select {isPlayer _x};
		if ((count _crewPlayers) == 0) then {
			continue;  
		};

		private _targetsDL = listRemoteTargets side _vic;

		private _targetsInDistance = (_targetsDL) select {((_x select 0) distance _vic <= 400)};
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
				private _dNorm = (_distance / 400) min 1;
				private _vol   = (1 - _dNorm) * 0.25 + 0.05;
				_vol = _vol max 0.05 min 0.3;

				private _sound = ["a3\sounds_f\air\heli_light_01\warning.wss", _vol, 0.8];
				[_sound] remoteExec ["playSoundUI", crew _vic];

				//private _vicPos = getPosASL _vic;
				//private _dir = vectorNormalized (_vicPos vectorDiff _vicPos);
				//private _soundPos = _vicPos vectorAdd (_dir vectorMultiply 25);
				//playSound3D ["a3\sounds_f\air\heli_light_01\warning.wss", objNull, false, _soundPos, 10, 1, 75];
				//playSound3D ["a3\sounds_f\air\heli_light_01\warning.wss", objNull, false, getPosASL _vic, 20, 0.8, 60];
				//playSound3D ["a3\sounds_f\air\heli_light_01\warning.wss", vehicle player, false, [], 10, 0.8, 30];

				_cycle = 0;
			};
		};
	};
};


/*
RC_TestScript = [] spawn
{
	_vic = vehicle player;
	private _cycle = 0;

	while {true} do
	{
		sleep 1;

		if (!alive _vic) exitwith {};
		private _crewPlayers = (crew _vic) select {isPlayer _x};
		if ((count _crewPlayers) == 0) then {
			continue;  
		};

		private _targetsDL = listRemoteTargets side _vic;

		private _targetsInDistance = (_targetsDL) select {((_x select 0) distance _vic <= 400)};
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
				private _dNorm = (_distance / 400) min 1;
				private _vol   = (1 - _dNorm) * 0.25 + 0.05;
				_vol = _vol max 0.05 min 0.3;

				private _sound = ["a3\sounds_f\air\heli_light_01\warning.wss", _vol, 0.8];
				[_sound] remoteExec ["playSoundUI", crew _vic];

				//private _vicPos = getPosASL _vic;
				//private _dir = vectorNormalized (_vicPos vectorDiff _vicPos);
				//private _soundPos = _vicPos vectorAdd (_dir vectorMultiply 25);
				//playSound3D ["a3\sounds_f\air\heli_light_01\warning.wss", objNull, false, _soundPos, 10, 1, 75];
				//playSound3D ["a3\sounds_f\air\heli_light_01\warning.wss", objNull, false, getPosASL _vic, 20, 0.8, 60];
				//playSound3D ["a3\sounds_f\air\heli_light_01\warning.wss", vehicle player, false, [], 10, 0.8, 30];

				_cycle = 0;
			};
		};
	};
};
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