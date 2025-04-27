IncomingMissile="params ['_target','_ammo','_vehicle','_instigator','_missile'];	\
if (!(vehicle player == _target)) exitWith {}; \
if ((_target distance _vehicle) > 4000) exitwith {}; \
['\A3\Sounds_F\vehicles\air\noises\alarm_locked_by_missile_1.wss', 0.2];	\
if (!RC_AT_SourceIndication) exitwith {}; \
if (([_vehicle, 'GEOM', _target] checkVisibility [eyePos _vehicle, eyePos _target]) == 0) exitwith {}; \
private _side = side _target;	\
if (_vehicle isKindOf 'StaticWeapon') then {	\
	_side reportRemoteTarget [_vehicle, 180];	\
	_vehicle confirmSensorTarget [_side, true];	\
} else {	\
	if (_vehicle isKindOf 'Man') then {	\
		_side reportRemoteTarget [_vehicle, 6];	\
		_vehicle confirmSensorTarget [_side, true];	\
	} else {	\
		_side reportRemoteTarget [_vehicle, 12];	\
		_vehicle confirmSensorTarget [_side, true];	\
	};	\
};";