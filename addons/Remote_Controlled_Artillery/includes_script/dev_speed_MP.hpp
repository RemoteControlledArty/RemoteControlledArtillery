fired="params ['_unit', '_weapon', '_muzzle', '_mode', '_ammo', '_magazine', '_projectile', '_gunner'];	\
if (_ammo find 'MPAB' > -1) then {	\
	[_projectile, _gunner] spawn {	\
		private _projectile = (_this select 0);	\
		private _gunner = (_this select 1);	\
		private _gunnerSide = side _gunner;	\
		waitUntil {	\
			if (!alive _projectile) exitWith {false};	\
			sleep 0.005;
			(count ((nearestObjects [_projectile, ['AllVehicles','LaserTarget','RC_GPSDatalinkTarget'], (6/((1000^0.5)/(((speed _projectile)*0.277778)^0.5)))]) select {alive _x && side _x != _gunnerSide && _gunner knowsAbout _x > 0})) > 0;	\
		};	\
		hint format ['%1', (6/((1000^0.5)/(((speed _projectile)*0.277778)^0.5)))];	\
		triggerAmmo _projectile;	\
		playSoundUI ['a3\3den\data\sound\cfgsound\notificationdefault.wss', 0.5, 1.6];	\
	};	\
};";