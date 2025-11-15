//ElDiff additions, like muzzle position, and rounds aim above value (airburst & topdown guided)

//for airburst and illum point of aim adjust
private _aimAboveHeight = RC_AimAboveHeightHash get _currentMag;
if (isNil "_aimAboveHeight") then {
	_aimAboveHeight = getNumber (configFile >> "CfgMagazines" >> _currentMag >> "RC_AimAboveHeight");
	RC_AimAboveHeightHash set [_currentMag, _aimAboveHeight];
};

private _barrelAGL = RC_barrelAGLHash get _uavClass;
if (isNil "_barrelAGL") then {
	_barrelAGL = getNumber (configFile >> "CfgVehicles" >> _uavClass >> "RC_BarrelAGL");
	RC_barrelAGLHash set [_uavClass, _barrelAGL];
};

private _barrelLenght = RC_BarrelLenghtHash get _uavClass;
if (isNil "_barrelLenght") then {
	_barrelLenght = getNumber (configFile >> "CfgVehicles" >> _uavClass >> "RC_BarrelLenght");
	RC_BarrelLenghtHash set [_uavClass, _barrelLenght];
};

private _weaponDirection = 0;
private _muzzleHeight = 0;
_weaponDirection = ((_uav weaponDirection currentWeapon _uav) select 2);
_muzzleHeightEstimate = _barrelLenght * (sin (_weaponDirection * 90)) + _barrelAGL;