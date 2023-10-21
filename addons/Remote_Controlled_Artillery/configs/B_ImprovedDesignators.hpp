/*
	The Order is
	Normal -> Thermal -> Normal Bag -> Thermal Bag
*/

// Arid
class RC_Improved_FOV_Laser_Designator_Arid: RC_Improved_FOV_Laser_Designator_Arid_base
{
	displayname="RC Improved Laser Designator";
	faction="RemoteControlled_B";
	editorSubcategory="RC_Spotting_subcat";

	scope=2;
	scopeCurator=2;

	threat[]={0.2,0.15,0.1};

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			class ViewOptics: viewOptics
			{
				minAngleX=-75;
				maxAngleX=75;

				initFov=0.25;
				minFov=0.0099999998;
				maxFov=0.25;

				visionMode[]=
				{
					"Normal",
					"NVG"
				};
			};
		};
	};

	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"RC_Improved_FOV_Laser_Designator_Bag_Arid"
		};
	};
};
class RC_Improved_FOV_Laser_Designator_Ti_Arid: RC_Improved_FOV_Laser_Designator_Arid
{
	displayname="RC Improved Laser Designator (whTi)";

	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"RC_Improved_FOV_Laser_Designator_Ti_Bag_Arid"
		};
	};

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			class ViewOptics: viewOptics
			{
				initFov=0.25;
				minFov=0.0099999998;
				maxFov=0.25;

				visionMode[]=
				{
					"Normal",
					"NVG",
					"TI"
				};
				thermalMode[]={0};
			};
		};
	};
};
class RC_Improved_FOV_Laser_Designator_Bag_Arid: RC_Improved_FOV_Laser_Designator_Bag_Arid_base
{
	displayname="RC Improved Laser Designator Bag";
	scope=2;
	scopeCurator=2;
	
	picture="\A3\Weapons_F\Ammoboxes\Bags\data\UI\icon_b_c_compact_rgr_ca.paa";
	hiddenSelectionsTextures[]=
	{
		"\A3\weapons_f\ammoboxes\bags\data\backpack_compact_rgr_co.paa"
	};
	
	class assembleInfo: assembleInfo
	{
		displayName="RC Improved Laser Designator Bag";
		assembleTo="RC_Improved_FOV_Laser_Designator_Arid";
	};
};
class RC_Improved_FOV_Laser_Designator_Ti_Bag_Arid: RC_Improved_FOV_Laser_Designator_Bag_Arid
{
	displayname="RC Improved Laser Designator (whTi) Bag";

	class assembleInfo: assembleInfo
	{
		displayName="RC Improved Laser Designator (whTi) Bag";
		assembleTo="RC_Improved_FOV_Laser_Designator_Ti_Arid";
	};
};

// Woodland
class RC_Improved_FOV_Laser_Designator_Woodland: RC_Improved_FOV_Laser_Designator_Woodland_base
{
	displayname="RC Improved Laser Designator";
	faction="RemoteControlled_B";
	editorSubcategory="RC_Spotting_subcat";

	scope=2;
	scopeCurator=2;
	
	threat[]={0.2,0.15,0.1};

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			class ViewOptics: viewOptics
			{
				initFov=0.25;
				minFov=0.0099999998;
				maxFov=0.25;

				visionMode[]=
				{
					"Normal",
					"NVG"
				};
			};
		};
	};

	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"RC_Improved_FOV_Laser_Designator_Bag_Woodland"
		};
	};
};
class RC_Improved_FOV_Laser_Designator_Ti_Woodland: RC_Improved_FOV_Laser_Designator_Woodland
{
	displayname="RC Improved Laser Designator (whTi)";

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			class ViewOptics: viewOptics
			{
				initFov=0.25;
				minFov=0.0099999998;
				maxFov=0.25;

				visionMode[]=
				{
					"Normal",
					"NVG",
					"TI"
				};
				thermalMode[]={0};
			};
		};
	};
};
class RC_Improved_FOV_Laser_Designator_Bag_Woodland: RC_Improved_FOV_Laser_Designator_Bag_Woodland_base
{
	displayname="RC Improved Laser Designator Bag";
	scope=2;
	scopeCurator=2;
	
	picture="\A3\Weapons_F\Ammoboxes\Bags\data\UI\icon_b_c_compact_sgg_ca.paa";
	hiddenSelectionsTextures[]=
	{
		"\A3\weapons_f\ammoboxes\bags\data\backpack_compact_sgg_co.paa"
	};
	
	class assembleInfo: assembleInfo
	{
		displayName="RC Improved Laser Designator Bag";
		assembleTo="RC_Improved_FOV_Laser_Designator_Woodland";
	};
};
class RC_Improved_FOV_Laser_Designator_Ti_Bag_Woodland: RC_Improved_FOV_Laser_Designator_Bag_Woodland
{
	displayname="RC Improved Laser Designator (whTi) Bag";

	class assembleInfo: assembleInfo
	{
		displayName="RC Improved Laser Designator (whTi) Bag";
		assembleTo="RC_Improved_FOV_Laser_Designator_Ti_Woodland";
	};
};



