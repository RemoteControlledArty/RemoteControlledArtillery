//script to disable airburst when turret is too low for it, and reenable it when high enough
private _currentMag = currentMagazine _uav;

if (_realElevation <= HEAB_MIN_ELEVATION) then
{
	if (_currentMag regexMatch ".*_HEAB.*") then
	{
		private _magChangeArray = ["_HEAB", "_backupHEAB"];

		#include "\Remote_Controlled_Artillery\functions\UILoop_includes\changeMag.sqf"
	};
	if (_currentMag regexMatch ".*_lowHEAB.*") then
	{
		private _magChangeArray = ["_lowHEAB", "_backuplowHEAB"];

		#include "\Remote_Controlled_Artillery\functions\UILoop_includes\changeMag.sqf"
	};
}
else
{
	if (_currentMag regexMatch ".*_backupHEAB.*") then
	{
		private _magChangeArray = ["_backupHEAB", "_HEAB"];

		#include "\Remote_Controlled_Artillery\functions\UILoop_includes\changeMag.sqf"
	};
	if (_currentMag regexMatch ".*_backuplowHEAB.*") then
	{
		private _magChangeArray = ["_backuplowHEAB", "_lowHEAB"];

		#include "\Remote_Controlled_Artillery\functions\UILoop_includes\changeMag.sqf"
	};
};