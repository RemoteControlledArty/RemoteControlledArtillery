params ["_unit", "_weapon", "_muzzle", "_mode", "_ammo", "_magazine", "_projectile", "_gunner"];

if (!local _unit) exitwith {};
if (hasInterface) then {_gunner removeMagazine _magazine};


//velocity adjustment per venthole
private _vel = velocity _projectile;
if (RC_ULM_Velocity <= 0) exitWith {systemchat "vel <= 0"};
_projectile setVelocity (_vel vectorMultiply (RC_ULM_Velocity / vectorMagnitude _vel));


[RC_ULM_ETA] spawn {
	params ["_ETA"];

	if (_ETA > 5) then {
		sleep (_ETA - 5);
		systemchat "splash in 5sec";
		sleep 5;
	} else {
		sleep _ETA;
	};

	systemchat "splash";
};