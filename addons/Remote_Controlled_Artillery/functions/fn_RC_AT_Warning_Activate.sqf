/*
	Author: Ascent

	Description:
	If line of sight: Warning sound for any hostile AT, marks source of fire briefly in datalink.
*/

params ['_target','_unit'];

private _vic = _target;
private _source = _unit;

if ((_vic distance _source) > 4000) exitwith {};
if (!RC_AT_SourceIndicationStatic && !RC_AT_SourceIndicationInf && !RC_AT_SourceIndicationVic) exitwith {};
if (([_source, 'GEOM', _vic] checkVisibility [eyePos _source, eyePos _vic]) == 0) exitwith {};

private _crew = (crew _vic) select {isPlayer _x};
[['\A3\Sounds_F\vehicles\air\noises\alarm_locked_by_missile_1.wss', 0.3]] remoteExec ['playSoundUI', _crew];

private _controllers = (UAVControl _vic);
private _controller1 = _controllers select 0;
if (_controller1 isNotEqualTo objNull) then {
	[['\A3\Sounds_F\vehicles\air\noises\alarm_locked_by_missile_1.wss', 0.3]] remoteExec ['playSoundUI', _controller1];

	if (count _controllers > 2) then {
		private _controller2 = _controllers select 2;
		[['\A3\Sounds_F\vehicles\air\noises\alarm_locked_by_missile_1.wss', 0.3]] remoteExec ['playSoundUI', _controller2];
	};
};


private _side = side _vic;
if (_source isKindOf 'StaticWeapon' && RC_AT_SourceIndicationStatic) then {
	[_side, [_source, 300]] remoteExec ['reportRemoteTarget', _side];
	[_source, [_side, true]] remoteExec ['confirmSensorTarget', _side];
} else {
	if (_source isKindOf 'Man' && RC_AT_SourceIndicationInf) then {
		[_side, [_source, 10]] remoteExec ['reportRemoteTarget', _side];
		[_source, [_side, true]] remoteExec ['confirmSensorTarget', _side];
	} else {
		if (RC_AT_SourceIndicationVic) then {
			[_side, [_source, 20]] remoteExec ['reportRemoteTarget', _side];
			[_source, [_side, true]] remoteExec ['confirmSensorTarget', _side];
		};
	};
};


//turns turret to AT source
private _turretPath = getArray (configFile >> "CfgVehicles" >> typeOf _vic >> "RC_ATrespondingTurret");

if (_turretPath isNotEqualTo []) then {
	private _turretOwnerID = _vic turretOwner _turretPath;
	[_vic, _source, _turretPath] remoteExec ['RC_fnc_RC_AT_Turn', _turretOwnerID];
};