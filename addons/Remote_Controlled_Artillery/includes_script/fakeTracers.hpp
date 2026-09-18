class RC_FakeTracers
{
	fired="params ['_unit','_weapon','_muzzle','_mode','_ammo','_magazine','_projectile','_gunner'];	\
	if (!local _gunner) exitWith {};	\
	if ((_ammo find 'HEAB' == -1) && (_ammo find 'MPAB' == -1)) exitWith {};	\
	[_ammo, _projectile, _gunner] call RC_fnc_RC_fakeTracers;";
};