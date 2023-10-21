/*
	The Order is
	Weapon -> Bag
*/

// Blufor
// Arid
class RC_Static_AT_Arid: RC_Static_AT_Arid_base
{
	displayname="RC Static AT 2km";
	faction="RemoteControlled_B";
	editorSubcategory="RC_ATGM_subcat";
	scope=2;
	scopeCurator=2;
	side=1;

	vehicleClass="Autonomous";
	isUav=1;
	textPlural="UGVs";
	textSingular="UGV";
	uavCameraGunnerPos="eye";
	uavCameraGunnerDir="look";
	crew="B_UAV_AI";

	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"RC_Static_AT_Arid_Bag"
		};
	};

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			gunnerForceOptics=1;

			minTurn=-180;
			maxTurn=180;

			weapons[]=
			{
				"missiles_titan_static"
			};
			magazines[]=
			{
				"1Rnd_GAT_missiles",
				"1Rnd_GAT_missiles",
				"1Rnd_GAT_missiles",
				"1Rnd_GAT_missiles",
				"1Rnd_GAT_missiles",
				"1Rnd_GAT_missiles"
			};
			class ViewOptics: ViewOptics
			{
				initFov=0.25;
				minFov=0.02;
				maxFov=0.25;
				visionMode[]=
				{
					"Normal",
					"NVG",
					"Ti"
				};
				thermalMode[]={0};
			};
		};
	};
};
class RC_Static_AT_Arid_Bag: RC_Static_AA_Arid_Bag
{
	displayName="RC Static AT 2km Bag";

	class assembleInfo: assembleInfo
	{
		displayName="RC Static AT 2km Bag";
		assembleTo="RC_Static_AT_Arid";
	};
};

// Woodland
class RC_Static_AT_Woodland: RC_Static_AT_Arid
{
	DLC="Expansion";

	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"RC_Static_AT_Woodland_Bag"
		};
	};

	editorPreview="\A3\EditorPreviews_F\Data\CfgVehicles\I_static_AT_F.jpg";
	hiddenSelectionsTextures[]=
	{
		"\a3\weapons_f_beta\launchers\titan\data\launcher_INDP_co.paa",
		"\a3\weapons_f_beta\launchers\titan\data\tubem_INDP_co.paa"
	};
};
class RC_Static_AT_Woodland_Bag: RC_Static_AA_Woodland_Bag
{
	displayName="RC Static AT 2km Bag";

	class assembleInfo: assembleInfo
	{
		displayName="RC Static AT 2km Bag";
		assembleTo="RC_Static_AT_Woodland";
	};
};


// Opfor
// Arid
class RC_Static_AT_Arid_O: RC_Static_AT_Arid
{
	faction="RemoteControlled_O";
	side=0;
	crew="O_UAV_AI";

	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"RC_Static_AT_Arid_Bag_O"
		};
	};
};
class RC_Static_AT_Arid_Bag_O: RC_Static_AT_Arid_Bag
{
	class assembleInfo: assembleInfo
	{
		assembleTo="RC_Static_AT_Arid_O";
	};
};

// Woodland
class RC_Static_AT_Woodland_O: RC_Static_AT_Woodland
{
	faction="RemoteControlled_O";
	side=0;
	crew="O_UAV_AI";

	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"RC_Static_AT_Woodland_Bag_O"
		};
	};
};
class RC_Static_AT_Woodland_Bag_O: RC_Static_AT_Woodland_Bag
{
	class assembleInfo: assembleInfo
	{
		assembleTo="RC_Static_AT_Woodland_O";
	};
};


// Independent / Indi
// Arid
class RC_Static_AT_Arid_I: RC_Static_AT_Arid
{
	faction="RemoteControlled_I";
	side=2;
	crew="I_UAV_AI";

	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"RC_Static_AT_Arid_Bag_I"
		};
	};
};
class RC_Static_AT_Arid_Bag_I: RC_Static_AT_Arid_Bag
{
	class assembleInfo: assembleInfo
	{
		assembleTo="RC_Static_AT_Arid_I";
	};
};

// Woodland
class RC_Static_AT_Woodland_I: RC_Static_AT_Woodland
{
	faction="RemoteControlled_I";
	side=2;
	crew="I_UAV_AI";

	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"RC_Static_AT_Woodland_Bag_I"
		};
	};
};
class RC_Static_AT_Woodland_Bag_I: RC_Static_AT_Woodland_Bag
{
	class assembleInfo: assembleInfo
	{
		assembleTo="RC_Static_AT_Woodland_I";
	};
};