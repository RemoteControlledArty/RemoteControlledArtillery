/*
	The Order is
	Weapon -> Bag
*/

// Blufor
// Arid
class RC_Static_ATGM_Arid: RC_Static_AT_Arid
{
	displayname="RC Static ATGM 3km";

	class assembleInfo: assembleInfo
	{
		displayName="RC Static ATGM 3km";
		dissasembleTo[]=
		{
			"RC_Static_ATGM_Arid_Bag"
		};
	};

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			weapons[]=
			{
				"RC_ATGM"
			};
			magazines[]=
			{
				"RC_1Rnd_ATGM_MT",
				"RC_1Rnd_ATGM_MT",
				"RC_1Rnd_ATGM_MT",
				"RC_1Rnd_ATGM_MT"
			};
		};
	};
};
class RC_Static_ATGM_Arid_Bag: RC_Static_AA_Arid_Bag
{
	displayName="RC Static ATGM 3km";
	class assembleInfo: assembleInfo
	{
		displayName="RC Static ATGM 3km";
		assembleTo="RC_Static_ATGM_Arid";
	};
};

// Woodland
class RC_Static_ATGM_Woodland: RC_Static_ATGM_Arid
{
	DLC="Expansion";

	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"RC_Static_ATGM_Woodland_Bag"
		};
	};

	editorPreview="\A3\EditorPreviews_F\Data\CfgVehicles\I_static_AT_F.jpg";
	hiddenSelectionsTextures[]=
	{
		"\a3\weapons_f_beta\launchers\titan\data\launcher_INDP_co.paa",
		"\a3\weapons_f_beta\launchers\titan\data\tubem_INDP_co.paa"
	};
};
class RC_Static_ATGM_Woodland_Bag: RC_Static_AA_Woodland_Bag
{
	displayName="RC Static ATGM 3km";
	class assembleInfo: assembleInfo
	{
		displayName="RC Static ATGM 3km";
		assembleTo="RC_Static_ATGM_Woodland";
	};
};

// Opfor
// Arid
class RC_Static_ATGM_Arid_O: RC_Static_ATGM_Arid
{
	faction="RemoteControlled_O";
	side=0;
	crew="O_UAV_AI";

	class assembleInfo: assembleInfo
	{
		displayName="RC Static ATGM 3km [Opf]";
		dissasembleTo[]=
		{
			"RC_Static_ATGM_Arid_Bag_O"
		};
	};
};
class RC_Static_ATGM_Arid_Bag_O: RC_Static_ATGM_Arid_Bag
{
	displayName="RC Static ATGM 3km [Opf]";
	class assembleInfo: assembleInfo
	{
		displayName="RC Static ATGM 3km [Opf]";
		assembleTo="RC_Static_AT_Arid_O";
	};
};

// Woodland
class RC_Static_ATGM_Woodland_O: RC_Static_ATGM_Woodland
{
	faction="RemoteControlled_O";
	side=0;
	crew="O_UAV_AI";

	class assembleInfo: assembleInfo
	{
		displayName="RC Static ATGM 3km [Opf]";
		dissasembleTo[]=
		{
			"RC_Static_ATGM_Woodland_Bag_O"
		};
	};
};
class RC_Static_ATGM_Woodland_Bag_O: RC_Static_ATGM_Woodland_Bag
{
	displayName="RC Static ATGM 3km [Opf]";
	class assembleInfo: assembleInfo
	{
		displayName="RC Static ATGM 3km [Opf]";
		assembleTo="RC_Static_ATGM_Woodland_O";
	};
};

// Independent / Indi
// Arid
class RC_Static_ATGM_Arid_I: RC_Static_ATGM_Arid
{
	faction="RemoteControlled_I";
	side=2;
	crew="I_UAV_AI";

	class assembleInfo: assembleInfo
	{
		displayName="RC Static ATGM 3km [Ind]";
		dissasembleTo[]=
		{
			"RC_Static_ATGM_Arid_Bag_I"
		};
	};
};
class RC_Static_ATGM_Arid_Bag_I: RC_Static_ATGM_Arid_Bag
{
	displayName="RC Static ATGM 3km [Ind]";
	class assembleInfo: assembleInfo
	{
		displayName="RC Static ATGM 3km [Ind]";
		assembleTo="RC_Static_ATGM_Arid_I";
	};
};

// Woodland
class RC_Static_ATGM_Woodland_I: RC_Static_ATGM_Woodland
{
	faction="RemoteControlled_I";
	side=2;
	crew="I_UAV_AI";

	class assembleInfo: assembleInfo
	{
		displayName="RC Static ATGM 3km [Ind]";
		dissasembleTo[]=
		{
			"RC_Static_ATGM_Woodland_Bag_I"
		};
	};
};
class RC_Static_ATGM_Woodland_Bag_I: RC_Static_ATGM_Woodland_Bag
{
	displayName="RC Static ATGM 3km [Ind]";
	class assembleInfo: assembleInfo
	{
		displayName="RC Static ATGM 3km [Ind]";
		assembleTo="RC_Static_ATGM_Woodland_I";
	};
};
