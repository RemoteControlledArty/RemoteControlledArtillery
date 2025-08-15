/*
	Author: Ascent

	Description:
	APS
*/

params ["_target", "_projectile"];

private _APSChargesCfg = getNumber (configFile >> "CfgVehicles" >> typeOf _target >> "RC_APSCharges");

private _mags = _target magazinesTurret [-1];
private _chargesAPS = {_x isEqualTo "RC_1Rnd_APS_M"} count _mags;

private _ingoreRockets = getNumber (configFile >> "CfgVehicles" >> typeOf _target >> "RC_ignoreRockets");
private _ammoType = getText (configFile >> "CfgAmmo" >> typeOf _projectile >> "simulation");
if ((_ingoreRockets != 0) && _ammoType isEqualTo "shotRocket") exitwith {};


/*
if (_ammoType isEqualTo "shotRocket") then {

	private _posProj = getPosASL _projectile;
	private _velProj = velocity _projectile;

	private _posVeh = getPosASL _vehicle;
	private _velVeh = velocity _vehicle;

	// Relative position & velocity
	private _relPos = _posProj vectorDiff _posVeh;
	private _relVel = _velProj vectorDiff _velVeh;

	// Time to closest approach
	private _tClosest = -((_relPos vectorDotProduct _relVel) / (_relVel vectorDotProduct _relVel));
	if (_tClosest <= 0) exitWith { false }; // Already passed or moving away

	// Predicted positions at closest point
	private _futureProj = _posProj vectorAdd (_velProj vectorMultiply _tClosest);
	private _futureVeh  = _posVeh vectorAdd (_velVeh vectorMultiply _tClosest);

	// Distance at closest point
	private _distClosest = _futureProj distance _futureVeh;

	// Vehicle size / hit radius
	private _hitRadius = 5; // adjust for vehicle model
	if (_distClosest > _hitRadius) exitWith { false }; // Will miss
};
*/


if (_chargesAPS > 0) then {
	
	[_target, _projectile] spawn
	{
		params ["_target", "_projectile"];

		while {(alive _target) and (alive _projectile)} do
		{
			if ((_projectile distance _target) <= 100) exitwith {

				private _mags = _target magazinesTurret [-1];
				private _chargesAPS = {_x isEqualTo "RC_1Rnd_APS_M"} count _mags;

				if (_chargesAPS > 0) then {

					private _projPos = (position _projectile);
					[_projectile] remoteExec ["deleteVehicle", 0];
					playSound3D ["a3\sounds_f_mod\arsenal\weapons\smg\adr_97\adr_97_closeshot_01.wss", _target, false, getPosASL _target, 10, 0.8, 600];
					_explosion = "ClaymoreDirectionalMine_Remote_Ammo_Scripted" createVehicle _projPos;
					_explosion setDamage 1;

					private _nextChargesAPS = 0 max (_chargesAPS - 1);
					_target removeMagazineTurret ["RC_1Rnd_APS_M", [-1]];

					private _string = "activated APS, " + str _nextChargesAPS + " remaining";
					[_target, _string] remoteExec ["vehicleChat", 0];
				};
			};
		};
	};
};