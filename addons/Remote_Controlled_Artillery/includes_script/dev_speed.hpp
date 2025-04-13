fired="params ['_unit', '_weapon', '_muzzle', '_mode', '_ammo', '_magazine', '_projectile', '_gunner'];	\
if (_ammo find 'HEAB' > -1) then {	\
	[_projectile, _gunner] spawn {	\
		private _projectile = (_this select 0);	\
		private _gunner = (_this select 1);	\
		private _gunnerSide = side _gunner;	\
		waitUntil {	\
			if (!alive _projectile) exitWith {false};	\
			(count ((nearestObjects [_projectile, ['Man','Car','Air','Truck','Tank','laserTarget','Motorcycle'], (7/(1000/((speed _projectile) * 0.277778)))]) select {alive _x && side _x != _gunnerSide && _gunner knowsAbout _x > 0})) > 0;	\
		};	\
		triggerAmmo _projectile;	\
		hint format ['%1', 'BOOM'];	\
	};	\
};";