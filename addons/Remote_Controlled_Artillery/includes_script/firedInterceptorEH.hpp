fired="params ['_unit','_weapon','_muzzle','_mode','_ammo','_magazine','_projectile','_gunner'];	\
if (!local _gunner) exitWith {};	\
[_gunner, _projectile] spawn RC_fnc_RC_InterceptorAttach;";