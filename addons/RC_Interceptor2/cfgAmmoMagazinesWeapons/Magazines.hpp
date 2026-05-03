//throwable
class HandGrenade;
class Interceptor_MP2_Throw_Base: HandGrenade
{
	scope=0;
	//scopeArsenal = 0;
	model="\frtz_p1sun\p1sun.p3d";
	picture="\frtz_p1sun\ui\p1sun_ico_ca.paa";
	descriptionShort="throwable Interceptor";
	mass=50;
};
class Interceptor_MP2_Throw: Interceptor_MP2_Throw_Base
{
	scope=2;	//1
	scopeArsenal=2;

	ammo="Interceptor_MP2_ThrowAmmo";
	displayName="MP Interceptor";
	displayNameShort="MP Interceptor";
};