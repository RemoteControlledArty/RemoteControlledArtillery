//ElDiff additions, like muzzle position, and rounds aim above value (airburst & topdown guided)
_aimAboveHeight = 0;
_aimAboveHeight = getNumber (configFile >> "CfgMagazines" >> (currentMagazine _uav) >> "RC_AimAboveHeight");	//for airburst and illum point of aim adjust

_BarrelAGL = 0;
_BarrelLenght = 0;
_WeaponDirection = 0;
_muzzleHeight = 0;
_BarrelAGL = getNumber (configFile >> "CfgVehicles" >> _uavClass >> "RC_BarrelAGL");
_BarrelLenght = getNumber (configFile >> "CfgVehicles" >> _uavClass >> "RC_BarrelLenght");
_WeaponDirection = ((_uav weaponDirection currentWeapon _uav) select 2);
_muzzleHeightEstimate = _BarrelLenght * (sin (_WeaponDirection * 90)) + _BarrelAGL;