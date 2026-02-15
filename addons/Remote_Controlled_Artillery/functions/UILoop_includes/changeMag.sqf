private _currentWeapon = currentWeapon _uav;
private _currentAmmoCount = parseNumber (((((currentMagazineDetail _uav) splitString "(") select 1) splitString "/") select 0);
private _replacementMag = _currentMag regexReplace _magChangeArray;
_uav addMagazineTurret [_replacementMag, [0]];
_uav loadMagazine [[0], _currentWeapon, _replacementMag];
_uav removeMagazineTurret [_currentMag, [0]];
_uav setAmmo [_currentWeapon, _currentAmmoCount];