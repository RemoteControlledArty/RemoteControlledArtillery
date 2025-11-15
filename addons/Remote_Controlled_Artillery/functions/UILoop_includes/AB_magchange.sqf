//script to disable airburst when turret is too low for it, and reenable it when high enough
private _currentMag = currentMagazine _uav;
private _currentWeapon = currentWeapon _uav;

if (_realElevation <= 50) then
{
	if (_currentMag regexMatch ".*_HEAB.*") then
	{
		private _currentAmmoCount = parseNumber (((((currentMagazineDetail _uav) splitString "(") select 1) splitString "/") select 0);
		private _replacementMag = _currentMag regexReplace ["_HEAB", "_backupHEAB"];
		_uav addMagazineTurret [_replacementMag, [0]];
		_uav loadMagazine [[0], _currentWeapon, _replacementMag];
		_uav removeMagazineTurret [_currentMag, [0]];
		_uav setAmmo [_currentWeapon, _currentAmmoCount];
	};
	if (_currentMag regexMatch ".*_lowHEAB.*") then
	{
		private _currentAmmoCount = parseNumber (((((currentMagazineDetail _uav) splitString "(") select 1) splitString "/") select 0);
		private _replacementMag = _currentMag regexReplace ["_lowHEAB", "_backuplowHEAB"];
		_uav addMagazineTurret [_replacementMag, [0]];
		_uav loadMagazine [[0], _currentWeapon, _replacementMag];
		_uav removeMagazineTurret [_currentMag, [0]];
		_uav setAmmo [_currentWeapon, _currentAmmoCount];
	};
}
else
{
	if (_currentMag regexMatch ".*_backupHEAB.*") then
	{
		private _currentAmmoCount = parseNumber (((((currentMagazineDetail _uav) splitString "(") select 1) splitString "/") select 0);
		private _replacementMag = _currentMag regexReplace ["_backupHEAB", "_HEAB"];
		_uav addMagazineTurret [_replacementMag, [0]];
		_uav loadMagazine [[0], _currentWeapon, _replacementMag];
		_uav removeMagazineTurret [_currentMag, [0]];
		_uav setAmmo [_currentWeapon, _currentAmmoCount];
	};
	if (_currentMag regexMatch ".*_backuplowHEAB.*") then
	{
		private _currentAmmoCount = parseNumber (((((currentMagazineDetail _uav) splitString "(") select 1) splitString "/") select 0);
		private _replacementMag = _currentMag regexReplace ["_backuplowHEAB", "_lowHEAB"];
		_uav addMagazineTurret [_replacementMag, [0]];
		_uav loadMagazine [[0], _currentWeapon, _replacementMag];
		_uav removeMagazineTurret [_currentMag, [0]];
		_uav setAmmo [_currentWeapon, _currentAmmoCount];
	};
};