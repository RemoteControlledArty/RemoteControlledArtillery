//throwable
class GrenadeHand;
class Interceptor_MP2_ThrowAmmo_Base: GrenadeHand
{
	class Eventhandlers
	{
		fired="if (!local (_this select 6)) exitWith {}; [_this select 6, _this select 7] spawn RC_fnc_fpv_Throw;";		//spawn to allow sleep
	};
	model="\frtz_p1sun\p1sun.p3d";

	hit=0;	//8
	indirectHit=0;	//8
	indirectHitRange=0;	//6
	dangerRadiusHit=0;	//60
	suppressionRadiusHit=0;	//24
	typicalspeed=18;
	fuseDistance=20;	//0
};
class Interceptor_MP2_ThrowAmmo:		Interceptor_MP2_ThrowAmmo_Base	{asset="Interceptor_MP2";};