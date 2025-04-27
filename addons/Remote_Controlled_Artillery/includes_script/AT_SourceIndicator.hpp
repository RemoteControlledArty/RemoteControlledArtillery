IncomingMissile="params ['_target','_ammo','_vehicle','_instigator','_missile'];	\
if (!local (_this select 0)) exitwith {}; \
if ((_target distance _vehicle) > 4000) exitwith {}; \
private _crew = (crew _target) select {isPlayer _x};	\
[['\A3\Sounds_F\vehicles\air\noises\alarm_locked_by_missile_1.wss', 0.2]] remoteExec ['playSoundUI', _crew];	\
if (!RC_AT_SourceIndicationStatic && !RC_AT_SourceIndicationInf && !RC_AT_SourceIndicationVic) exitwith {}; \
if (([_vehicle, 'GEOM', _target] checkVisibility [eyePos _vehicle, eyePos _target]) == 0) exitwith {}; \
private _side = side _target;	\
if (_vehicle isKindOf 'StaticWeapon' && RC_AT_SourceIndicationStatic) then {	\
	[_side,[_vehicle, 180]] remoteExec ['reportRemoteTarget', _side];	\
	[_vehicle, [_side, true]] remoteExec ['confirmSensorTarget', _side];	\
} else {	\
	if (_vehicle isKindOf 'Man'	&& RC_AT_SourceIndicationInf) then {	\
		[_side,[_vehicle, 6]] remoteExec ['reportRemoteTarget', _side];	\
		[_vehicle, [_side, true]] remoteExec ['confirmSensorTarget', _side];	\
	} else {	\
		if (RC_AT_SourceIndicationVic) then {	\
			[_side,[_vehicle, 12]] remoteExec ['reportRemoteTarget', _side];	\
			[_vehicle, [_side, true]] remoteExec ['confirmSensorTarget', _side];	\
		};	\
	};	\
};";
