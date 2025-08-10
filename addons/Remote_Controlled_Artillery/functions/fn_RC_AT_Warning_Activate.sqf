/*
	Author: Ascent

	Description:
	If line of sight: Warning sound for any hostile AT, marks source of fire briefly in datalink.
*/

params ['_target','_unit'];

if ((_target distance _unit) > 4000) exitwith {};
if (!RC_AT_SourceIndicationStatic && !RC_AT_SourceIndicationInf && !RC_AT_SourceIndicationVic) exitwith {};
if (([_unit, 'GEOM', _target] checkVisibility [eyePos _unit, eyePos _target]) == 0) exitwith {};

private _crew = (crew _target) select {isPlayer _x};
[['\A3\Sounds_F\vehicles\air\noises\alarm_locked_by_missile_1.wss', 0.3]] remoteExec ['playSoundUI', _crew];

private _controllers = (UAVControl _target);
private _controller1 = _controllers select 0;
if (_controller1 isNotEqualTo objNull) then {
	[['\A3\Sounds_F\vehicles\air\noises\alarm_locked_by_missile_1.wss', 0.3]] remoteExec ['playSoundUI', _controller1];

	if (count _controllers > 2) then {
		private _controller2 = _controllers select 3;
		[['\A3\Sounds_F\vehicles\air\noises\alarm_locked_by_missile_1.wss', 0.3]] remoteExec ['playSoundUI', _controller2];
	};
};

private _side = side _target;
if (_unit isKindOf 'StaticWeapon' && RC_AT_SourceIndicationStatic) then {
	[_side,[_unit, 300]] remoteExec ['reportRemoteTarget', _side];
	[_unit, [_side, true]] remoteExec ['confirmSensorTarget', _side];
} else {
	if (_unit isKindOf 'Man' && RC_AT_SourceIndicationInf) then {
		[_side,[_unit, 10]] remoteExec ['reportRemoteTarget', _side];
		[_unit, [_side, true]] remoteExec ['confirmSensorTarget', _side];
	} else {
		if (RC_AT_SourceIndicationVic) then {
			[_side,[_unit, 20]] remoteExec ['reportRemoteTarget', _side];
			[_unit, [_side, true]] remoteExec ['confirmSensorTarget', _side];
		};
	};
};


//turns turret to AT source
private _ATrespondingTurret = getNumber (configFile >> "CfgVehicles" >> typeOf _target >> "RC_ATrespondingTurret");

[_target, _unit, _ATrespondingTurret] spawn {

	params ['_target','_unit','_ATrespondingTurret'];

	if (_ATrespondingTurret == 1) then {

		private _gunTurretID = _target turretOwner [0];
		[_target, [_unit, [0], true]] remoteExec ['lockCameraTo', _gunTurretID];
		//_target lockCameraTo [_unit, [0], true];
		sleep 3.5;
		[_target, [objNull, [0], true]] remoteExec ['lockCameraTo', _gunTurretID];
		//_target lockCameraTo [objNull, [0], true];
	};
	if (_ATrespondingTurret == 2) then {

		private _comTurretID = _target turretOwner [0,0];
		[_target, [_unit, [0,0], true]] remoteExec ['lockCameraTo', _comTurretID];
		//_target lockCameraTo [_unit, [0,0], true];
		sleep 3.5;
		[_target, [objNull, [0,0], true]] remoteExec ['lockCameraTo', _comTurretID];
		//_target lockCameraTo [objNull, [0,0], true];
	};
};