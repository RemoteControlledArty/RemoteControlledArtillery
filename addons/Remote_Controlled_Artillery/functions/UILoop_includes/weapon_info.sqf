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

// 1. get all firemodes of the weapon 2. the player can use 3. have 'artilleryCharge' as a value
private _fireModes = RC_fireModesHash get _weapon;
if (isNil "_fireModes") then {

	_fireModes = getArray (configFile >> "CfgWeapons" >> _weapon >> "modes");
	_fireModes = (_fireModes apply { configFile >> "CfgWeapons" >> _weapon >> _x }) select { 1 == getNumber (_x >> "showToPlayer") };
	_fireModes = _fireModes apply { [getNumber (_x >> "artilleryCharge"), configName _x] };

	RC_fireModesHash set [_weapon, _fireModes];
};

// basic sort in ascending order
_fireModes sort true;
// grab only the names of the firemodes
_fireModes = _fireModes apply { _x select 1 };
// find the current charge
private _realCharge = _fireModes find _currentFireMode;