/*
	Author: Ascent

	Description:
	APS
*/

params ["_target", "_projectile"];

private _APSCharges = getNumber (configFile >> "CfgVehicles" >> typeOf _target >> "RC_APSCharges");
if (_APSCharges != 0) then {

	_chargesAPS = _target getVariable ["RC_chargesAPS", 1];		//1 = default return value if undefined

	//systemchat str _chargesAPS;

	if (_chargesAPS > 0) then {
		//systemchat "_chargesAPS > 0";
		
		[_target, _projectile, _chargesAPS] spawn
		{
			//systemchat "spawn";
			params ["_target", "_projectile"];
			//systemchat "waiting for APS";

			while {(alive _target) and (alive _projectile)} do
			{
				//systemchat "while APS";

				//sleep 0.01;
				if ((_projectile distance _target) <= 50) exitwith {

					//systemchat "exitwith";

					private _chargesAPS = _target getVariable ["RC_chargesAPS", -1];	//-1 = default return value
					if (_chargesAPS == -1) then {_chargesAPS = 4;};
					//systemchat str _chargesAPS;

					if (_chargesAPS > 0) then {

						//systemchat "if";
						
						_projectile addEventHandler ["SubmunitionCreated", {
							params ["_projectile", "_submunitionProjectile"];

							deleteVehicle _submunitionProjectile;
						}];

						triggerAmmo _projectile;
						
						private _nextChargesAPS = _chargesAPS - 1;
						//systemchat str _nextChargesAPS;
						_target setVariable ["RC_chargesAPS", _nextChargesAPS, true];	//true is public without RE
						
						private _string = "activated APS, " + str _nextChargesAPS + " remaining";
						[_target, _string] remoteExec ["vehicleChat", 0];
					};
				};
			};
		};
	};
};