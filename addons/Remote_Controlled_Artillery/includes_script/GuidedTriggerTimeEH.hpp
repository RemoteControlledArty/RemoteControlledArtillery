//backup trigger time if height/distance trigger fails, effects all ammo inherited from RC_Sh_AMOS_MP_LaserGuided_Base
fired="params ['_unit', '_weapon', '_muzzle', '_mode', '_ammo', '_magazine', '_projectile', '_gunner'];	\
if (!(_unit turretLocal [0])) exitwith {}; \
if (!(_ammo isKindOf 'RC_Sh_AMOS_MP_LaserGuided_Base')) exitWith {};	\
if (!((RC_GuidedTriggerTime isEqualType 0) && (RC_GuidedTriggerTime > 0))) exitWith {};	\
[_projectile] spawn {	\
	params ['_projectile'];	\
	sleep RC_GuidedTriggerTime;	\
	triggerAmmo _projectile;	\
};";

//if (!(_unit turretLocal [0])) exitwith {};	//only works if mainturret is [0]
//if (!local _unit) exitwith {};