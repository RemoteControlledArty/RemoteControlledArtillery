fired="params ['_unit', '_weapon', '_muzzle', '_mode', '_ammo', '_magazine', '_projectile', '_gunner'];	\
if (_magazine regexMatch '^.*HEAB(\d{1,2}).*$') then {	\
    private _number = parseNumber (_magazine regexFind ['^.*HEAB(\d{1,2}).*$', 0] select 0);	\
	[_projectile, _gunner, _number] spawn {	\
		private _projectile = (_this select 0);	\
		private _gunner = (_this select 1);	\
		private _gunnerSide = side _gunner;	\
		waitUntil {	\
			(count ((nearestObjects [_projectile, ['Man','Car','Air','Truck','Tank','laserTarget','Motorcycle'], (_this select 2)]) select {alive _x && side _x != _gunnerSide && _gunner knowsAbout _x > 0})) > 0;	\
		};	\
		triggerAmmo _projectile;	\
		hint format ['%1', 'BOOM'];	\
		sleep 2;	\
		hint format ['%1',''];	\
	};	\
};";