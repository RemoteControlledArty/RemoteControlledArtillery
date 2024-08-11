//ElDiff additions, like muzzle position, and rounds aim above value (airburst & topdown guided)

//for airburst and illum point of aim adjust
private _aimAboveHeight = RC_AimAboveHeightHash get _currentMag;
if (isNil "_aimAboveHeight") then {
	_aimAboveHeight = getNumber (configFile >> "CfgMagazines" >> _currentMag >> "RC_AimAboveHeight");
	RC_AimAboveHeightHash set [_currentMag, _aimAboveHeight];
};

private _BarrelAGL = RC_BarrelAGLHash get _uavClass;
if (isNil "_BarrelAGL") then {
	_BarrelAGL = getNumber (configFile >> "CfgVehicles" >> _uavClass >> "RC_BarrelAGL");
	RC_BarrelAGLHash set [_uavClass, _BarrelAGL];
};

private _BarrelLenght = RC_BarrelLenghtHash get _uavClass;
if (isNil "_BarrelLenght") then {
	_BarrelLenght = getNumber (configFile >> "CfgVehicles" >> _uavClass >> "RC_BarrelLenght");
	RC_BarrelLenghtHash set [_uavClass, _BarrelLenght];
};

_WeaponDirection = 0;
_muzzleHeight = 0;
_WeaponDirection = ((_uav weaponDirection currentWeapon _uav) select 2);
_muzzleHeightEstimate = _BarrelLenght * (sin (_WeaponDirection * 90)) + _BarrelAGL;