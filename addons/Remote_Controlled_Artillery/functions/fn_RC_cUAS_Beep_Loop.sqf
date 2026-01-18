/*
	Author: Ascent

	Description:
	Beep for newly detected UAV in Datalink.
*/

if (!isServer) exitWith {};

private _cycle = 0;

while {true} do {

	sleep 0.2;

	RC_CUAS_VehArray pushBack _veh;
	RC_CUAS_VehArray = RC_CUAS_VehArray select {!isNull _x && alive _x};

	if (count RC_CUAS_VehArray < 1) then {
		continue;
	};

	//seperates the alive vehicles by side, then counts each
	private _CUAS_VehArray_B = [];
	private _CUAS_VehArray_O = [];
	private _CUAS_VehArray_I = [];
	{
		private _side = side _x;
		
		switch (true) do {
			case(_side == west): {
				_CUAS_VehArray_B pushback _x;
			};
			case(_side == east): {
				_CUAS_VehArray_O pushback _x;
			};
			case(_side == resistance): {
				_CUAS_VehArray_I pushback _x;
			};
		};
	} forEach RC_CUAS_VehArray;


	sleep 0.2;

	if (count _CUAS_VehArray_B > 0) then {
		
		[_CUAS_VehArray_B, west] call RC_fnc_RC_cUAS_Beep_Call;
	};

	sleep 0.2;

	if (count _CUAS_VehArray_O > 0) then {
		
		[_CUAS_VehArray_O, east] call RC_fnc_RC_cUAS_Beep_Call;
	};

	sleep 0.2;

	if (count _CUAS_VehArray_I > 0) then {
		
		[_CUAS_VehArray_I, resistance] call RC_fnc_RC_cUAS_Beep_Call;
	};
};


/*
//didnt work, localizing vic per take control did
[_this, 400] spawn
{
	params ["_vic","_beepDist"];

	while {true} do
	{
		sleep 1;
		if (!alive _vic) exitwith {};

		private _targetsDL = listRemoteTargets side _vic;
		private _validTargets = [];
		{
			private _target = _x select 0;

			if (!isNull _target && {_target isKindOf "Air"}) then {
				if ((_target distance _vic <= _beepDist)) then {
					if ([side _target, side _vic] call BIS_fnc_sideIsEnemy) then {
						if (side _target != civilian) then {

							[_side,[_target, 180]] remoteExec ["reportRemoteTarget", _side];
							[_target, [_side, true]] remoteExec ["confirmSensorTarget", _side];

							hint format ["target %1", _target];
						};
					};
				};
			};
		} forEach _targetsDL;
	};
};
*/


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