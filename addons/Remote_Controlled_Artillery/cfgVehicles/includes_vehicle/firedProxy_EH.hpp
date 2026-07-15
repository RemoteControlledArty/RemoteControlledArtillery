class RC_ProxyFuse
{
	fired="params ['_unit','_weapon','_muzzle','_mode','_ammo','_mag','_proj']; \
	if (!local _proj) exitwith {}; \
	if (_ammo find '_Proxy' > -1) exitwith { \
		[_proj] spawn fnc_RC_proxyFuse; \
	};"
};