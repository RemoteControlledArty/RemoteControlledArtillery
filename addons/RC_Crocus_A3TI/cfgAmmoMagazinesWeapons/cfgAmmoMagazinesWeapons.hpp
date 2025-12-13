class CfgAmmo
{
	//throwable
	class Crocus_MP_ThrowAmmo_Base;
	class Crocus_MP_TI_ThrowAmmo:		Crocus_MP_ThrowAmmo_Base	{asset="Crocus_MP_TI";};
	class Crocus_MP_TI_Sens_ThrowAmmo:	Crocus_MP_ThrowAmmo_Base 	{asset="Crocus_MP_TI_Sens";};
};


class cfgMagazines
{
	//throwable
	class Crocus_MP_Throw_Base;
	class Crocus_MP_TI_Throw: Crocus_MP_Throw_Base
	{
		scope=2;
		ammo="Crocus_MP_TI_ThrowAmmo";
		displayName="Crocus MP TI";
		displayNameShort="Crocus MP TI";
	};
	class Crocus_MP_TI_Sens_Throw: Crocus_MP_Throw_Base
	{
		scope=2;
		ammo="Crocus_MP_TI_Sens_ThrowAmmo";
		displayName="Crocus MP TI Sens";
		displayNameShort="Crocus MP TI Sens";
	};
};


class cfgWeapons
{
	//throwable
	class GrenadeLauncher;
    class Throw: GrenadeLauncher {

		class ThrowMuzzle: GrenadeLauncher {};
		class Crocus_MP_TI_ThrowMuzzle:			ThrowMuzzle {magazines[] = {"Crocus_MP_TI_Throw"};		};
		class Crocus_MP_TI_Sens_ThrowMuzzle: 	ThrowMuzzle {magazines[] = {"Crocus_MP_TI_Sens_Throw"};	};

		muzzles[]+=
		{
			"Crocus_MP_TI_ThrowMuzzle",
			"Crocus_MP_TI_Sens_ThrowMuzzle"
		};
	};
};