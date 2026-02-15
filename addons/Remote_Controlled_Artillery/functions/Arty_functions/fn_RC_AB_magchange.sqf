//script to disable airburst when turret is too low for it, and reenable it when high enough
private _currentMag = currentMagazine _uav;

if (_realElevation <= HEAB_MIN_ELEVATION) then
{
	if (_currentMag regexMatch ".*_HEAB.*") then
	{
		private _magChangeArray = ["_HEAB", "_backupHEAB"];

		[_currentMag, _magChangeArray] call RC_fnc_changeMag;
	};
	if (_currentMag regexMatch ".*_lowHEAB.*") then
	{
		private _magChangeArray = ["_lowHEAB", "_backuplowHEAB"];
	
		[_currentMag, _magChangeArray] call RC_fnc_changeMag;
	};
}
else
{
	if (_currentMag regexMatch ".*_backupHEAB.*") then
	{
		private _magChangeArray = ["_backupHEAB", "_HEAB"];

		[_currentMag, _magChangeArray] call RC_fnc_changeMag;
	};
	if (_currentMag regexMatch ".*_backuplowHEAB.*") then
	{
		private _magChangeArray = ["_backuplowHEAB", "_lowHEAB"];

		[_currentMag, _magChangeArray] call RC_fnc_changeMag;
	};
};