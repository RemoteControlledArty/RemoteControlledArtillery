fired="params ['_unit', '_weapon', '_muzzle', '_mode', '_ammo', '_magazine', '_projectile', '_gunner'];	\
if (_ammo find 'MPAB' > -1) then {	\
	[_projectile, _gunner] spawn {	\
		params ['_proj', '_gunner'];	\
		waitUntil { sleep 0.01; !isNull _proj && alive _proj };	\
		private _types = ['Car', 'Tank', 'Air', 'Man'];	\
		private _maxDistance = 4.5;	\
		private _step = 3;	\
		private _radius = 6;	\
		private _side = side _gunner;	\
		while { alive _proj } do {	\
			sleep 0.005;	\
			private _pos = getPosASL _proj;	\
			private _vel = velocity _proj;	\
			if (_vel isEqualTo [0,0,0]) exitWith {};	\
			private _dir = vectorNormalized _vel;	\
			private _posFront = _pos vectorAdd (_dir vectorMultiply _step);	\
			private _targets = 	\
				(nearestObjects [_pos, _types, _radius]) + 	\
				(nearestObjects [_posFront, _types, _radius]);	\
			private _validTargets = _targets select {	\
				alive _x &&	\
				side _x != _side &&	\
				(_gunner knowsAbout _x > 0)	\
			};	\
			if !(_validTargets isEqualTo []) then {	\
				private _closest = _validTargets apply { [_x distance _proj, _x] };	\
				_closest sort true;	\	\
				private _nearestDist = (_closest select 0) select 0;	\
				private _nearestObj  = (_closest select 0) select 1;	\
				if (_nearestDist <= _maxDistance) exitWith {	\
					triggerAmmo _proj;	\
				};	\
			};	\
		};	\
	};	\
};";