class CfgAmmo
{
	//throwable
	class Crocus_MP_ThrowAmmo_Base;
	class Crocus_MP_TI_ThrowAmmo:		Crocus_MP_ThrowAmmo_Base	{asset="Crocus_MP_TI";};
	class Crocus_MP_TI_Sens_ThrowAmmo:	Crocus_MP_ThrowAmmo_Base 	{asset="Crocus_MP_TI_Sens";};
	class Crocus_PvP_ThrowAmmo:			Crocus_MP_ThrowAmmo_Base	{asset="Crocus_PvP";};
	class Crocus_Training_ThrowAmmo:	Crocus_MP_ThrowAmmo_Base 	{asset="Crocus_Training";};
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
	class Crocus_MP_TI_Sens_Throw: Crocus_MP_TI_Throw
	{
		ammo="Crocus_MP_TI_Sens_ThrowAmmo";
		displayName="Crocus MP TI Sens";
		displayNameShort="Crocus MP TI Sens";
	};
	class Crocus_PvP_Throw: Crocus_MP_TI_Throw
	{
		ammo="Crocus_PvP_ThrowAmmo";
		displayName="Crocus PvP";
		displayNameShort="Crocus PvP";
	};
	class Crocus_Training_Throw: Crocus_MP_TI_Throw
	{
		ammo="Crocus_Training_ThrowAmmo";
		displayName="Crocus Training";
		displayNameShort="Crocus Training";
	};


	class Item_Crocus_MP;
	class Item_Crocus_MP_TI: Item_Crocus_MP
	{
		_generalMacro="Item_Crocus_MP_TI";
		displayName="Crocus MP TI";
		displayNameShort="Crocus MP TI";
		descriptionShort="Crocus MP TI";
	};
	class Item_Crocus_MP_TI_Sens: Item_Crocus_MP
	{
		_generalMacro="Item_Crocus_MP_TI_Sens";
		displayName="Crocus MP TI Sens";
		displayNameShort="Crocus MP TI Sens";
		descriptionShort="Crocus MP TI Sens";
	};
	class Item_Crocus_PvP: Item_Crocus_MP
	{
		_generalMacro="Item_Crocus_PvP";
		displayName="Crocus PvP";
		displayNameShort="Crocus PvP";
		descriptionShort="Crocus PvP";
	};
	class Item_Crocus_Training: Item_Crocus_MP
	{
		_generalMacro="Item_Crocus_Training";
		displayName="Crocus Training";
		displayNameShort="Crocus Training";
		descriptionShort="Crocus Training";
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
		class Crocus_PvP_ThrowMuzzle:			ThrowMuzzle {magazines[] = {"Crocus_PvP_Throw"};		};
		class Crocus_Training_ThrowMuzzle: 		ThrowMuzzle {magazines[] = {"Crocus_Training_Throw"};	};

		muzzles[]+=
		{
			"Crocus_MP_TI_ThrowMuzzle",
			"Crocus_MP_TI_Sens_ThrowMuzzle",
			"Crocus_PvP_ThrowMuzzle",
			"Crocus_Training_ThrowMuzzle"
		};
	};
};