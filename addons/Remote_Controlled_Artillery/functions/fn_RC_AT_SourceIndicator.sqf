/*
	Author: Ascent

	Description:
	Warning sound fired at by any AT (except player fired unguided), if line of sight marks source of fire briefly in datalink.
*/

params ['_target','_ammo','_vehicle','_instigator','_missile'];

if ((_target distance _vehicle) > 4000) exitwith {};

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

if (!RC_AT_SourceIndicationStatic && !RC_AT_SourceIndicationInf && !RC_AT_SourceIndicationVic) exitwith {};
if (([_vehicle, 'GEOM', _target] checkVisibility [eyePos _vehicle, eyePos _target]) == 0) exitwith {};

private _side = side _target;
if (_vehicle isKindOf 'StaticWeapon' && RC_AT_SourceIndicationStatic) then {
	[_side,[_vehicle, 300]] remoteExec ['reportRemoteTarget', _side];
	[_vehicle, [_side, true]] remoteExec ['confirmSensorTarget', _side];
} else {
	if (_vehicle isKindOf 'Man'	&& RC_AT_SourceIndicationInf) then {
		[_side,[_vehicle, 10]] remoteExec ['reportRemoteTarget', _side];
		[_vehicle, [_side, true]] remoteExec ['confirmSensorTarget', _side];
	} else {
		if (RC_AT_SourceIndicationVic) then {
			[_side,[_vehicle, 20]] remoteExec ['reportRemoteTarget', _side];
			[_vehicle, [_side, true]] remoteExec ['confirmSensorTarget', _side];
		};
	};
};