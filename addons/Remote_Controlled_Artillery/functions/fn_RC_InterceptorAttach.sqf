params ["_gunner", "_projectile"];

//private _targetVersion = 'RC_InterceptorMissile_Target';
//private _target = [[0, 0, 500], getDir _projectile, _targetVersion, sideEmpty] call BIS_fnc_spawnVehicle;	//somehow sideEnemy still counts as friendly fire
//private _target = _targetVersion createVehicle [0, 0, 500];

private _sidePlayer = side _gunner;
private _targetVersion = 'RC_InterceptorMissile_Target_B';
if (_sidePlayer == east) then {_targetVersion = 'RC_InterceptorMissile_Target_O';};
if (_sidePlayer == resistance) then {_targetVersion = 'RC_InterceptorMissile_Target_I';};

//somehow not spotted by C-UAS in multiplayer
private _target = [[0, 0, 500], getDir _projectile, _targetVersion, _sidePlayer] call BIS_fnc_spawnVehicle;
_target = _target select 0;
_target disableCollisionWith _projectile;


_target addEventHandler ["Killed", {
    params ["_unit", "_killer", "_instigator", "_useEffects"];
    
	//to prevent FF due to projectile explosion destroying the attached target
    if (!isNull _instigator) then {
        _instigator addRating 5000; 
    } else {
        _killer addRating 5000;
    };

	triggerAmmo attachedTo _unit;
	deleteVehicle _unit;
}];
_projectile addEventHandler ["Deleted", {
	params ["_projectile"];

	deleteVehicle ((attachedObjects _projectile)#0);
}];
_projectile addEventHandler ["Explode", {
	params ["_projectile", "_position", "_velocity"];

	deleteVehicle ((attachedObjects _projectile)#0);
}];

//hide projectile to only show targetable attached vehicle
//hideObjectGlobal _projectile;
//hideObject unitName;
[_projectile, true] remoteExec ["hideObjectGlobal", 2];

//sleep to prevent collision in MP
sleep 0.1;
//-1 offset to not block the shaped charge
_target attachTo [_projectile, [0, -1, 0]];		//-1 to prevent ramming oneshot