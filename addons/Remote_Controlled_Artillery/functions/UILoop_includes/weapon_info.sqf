// Current Turret of UAV Gunner
_turret = _uav unitTurret gunner _uav;
// Current Fire mode of the UAV Gunner
_currentFireMode = currentWeaponMode (gunner _uav);
// All of the Turrets Weapons
_weaponsTurret = _uav weaponsTurret _turret;
// Weapon
_weapon = _weaponsTurret param [0, ""];
// Weapon Config
_weaponConfig = configFile >> "CfgWeapons" >> _weapon;
// Get all Firemodes of the UAV Weapon
_fireModes = getArray (configFile >> "CfgWeapons" >> _weapon >> "modes");
// Get all the Firemodes the Players can use
_fireModes = (_fireModes apply { configFile >> "CfgWeapons" >> _weapon >> _x }) select { 1 == getNumber (_x >> "showToPlayer") };
// If the Firemodes have 'artilleryCharge' as a value
_fireModes = _fireModes apply { [getNumber (_x >> "artilleryCharge"), configName _x] };
// Basic Sort in ascending order
_fireModes sort true;
// Grab only the names of the Firemodes 
_fireModes = _fireModes apply { _x select 1 };
// Find the Current charge
_realCharge = _fireModes find _currentFireMode;