//throwable
class HandGrenade;
class Interceptor_MP_Throw_Base: HandGrenade
{
	scope=0;
	//scopeArsenal = 0;
	model="\A3\Weapons_F_beta\Launchers\titan\titan_missile_ap";
	//model="\A3\Weapons_F_beta\Launchers\titan\titan_missile_ap_fly";
	//model="\A3\Weapons_F_Sams\Ammo\Bomb_05_F_fly.p3d";
	picture="\A3\Weapons_F_beta\Launchers\titan\Data\UI\gear_titan_missile_ap_CA.paa";
	descriptionShort="throwable Interceptor";
	mass=50;
};
class Interceptor_MP_Throw: Interceptor_MP_Throw_Base
{
	//scope=2;
	//scopeArsenal=2;
	scope=1;

	ammo="Interceptor_MP_ThrowAmmo";
	displayName="MP Interceptor";
	displayNameShort="MP Interceptor";
};