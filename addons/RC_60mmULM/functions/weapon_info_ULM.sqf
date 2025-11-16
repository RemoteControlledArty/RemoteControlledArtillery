// current turret of UAV gunner
private _turret = _uav unitTurret gunner _uav;
// current fire mode of the UAV gunner
private _currentFireMode = currentWeaponMode (gunner _uav);
// weapon
private _weapon = (_uav weaponsTurret _turret) param [0, ""];

// weapon config
private _weaponConfig = RC_weaponConfigHash get _weapon;
if (isNil "_weaponConfig") then {
	_weaponConfig = configFile >> "CfgWeapons" >> _weapon;
	RC_weaponConfigHash set [_weapon, _weaponConfig];
};