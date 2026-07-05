params ['_unit'];

private _uavType = typeOf _unit;
private _vectorDir = vectorDir _unit;
private _vectorUp = vectorUp _unit;
private _impactPos = _unit modelToWorld [0,0,0];
private _killer = (UAVControl _unit)#0;

deleteVehicle _unit;

if !(_uavType in RC_FPV_validDronesDetonateArr) exitWIth {};

private _missileType = "FPV_RPG42_MP";
if (_uavType in RC_FPV_validDronesPvPArr) then {_missileType = "FPV_RPG42_PvP";};
if (_uavType in RC_FPV_validDronesTrainingArr) then {_missileType = "FPV_RPG42_Training";};

private _missile = createVehicle [_missileType, [0,0,100]];
_missile setVectorDirAndUp [_vectorDir, _vectorUp];
[_missile, [_killer, _killer]] remoteExec ["setShotParents", 2];

waitUntil { (getShotParents _missile) isEqualTo [_killer, _killer]; };

_missile setPosATL _impactPos;
triggerAmmo _missile;
0