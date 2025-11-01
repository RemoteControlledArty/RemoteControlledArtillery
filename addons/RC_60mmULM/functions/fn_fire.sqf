params ["_unit", "_weapon", "_muzzle", "_mode", "_ammo", "_magazine", "_projectile", "_gunner"];

if (!local _unit) exitwith {};
if (hasInterface) then {_gunner removeMagazine _magazine};


//velocity adjustment of mortar gas venthole, always allowing 800MIL (45°) trajectory, plus spread simulation
if (RC_ULM_Velocity > 0) then {

	private _spread = 0.0025;	//0.003 = max ~12m at 3500m, testing 0.0025 for now

	private _vel1 = velocity _projectile;
	private _dir = vectorNormalized _vel1;
	private _vel2 = _dir vectorMultiply RC_ULM_Velocity;

	private _vel3 = [
		(_vel2 select 0) * (1 + random [-_spread, 0, _spread]),
		(_vel2 select 1) * (1 + random [-_spread, 0, _spread]),
		(_vel2 select 2) * (1 + random [-_spread, 0, _spread])
	];

	_projectile setVelocity _vel3;


	//"splash in 3sec" notification
	[RC_ULM_ETA] spawn {
		params ["_ETA"];

		if (_ETA > 3) then {
			sleep (_ETA - 3);
			systemchat "splash in 3sec";
			sleep 3;
		} else {
			sleep _ETA;
		};

		systemchat "splash";
	};
} else {
	systemchat "could not calculate MV";
};