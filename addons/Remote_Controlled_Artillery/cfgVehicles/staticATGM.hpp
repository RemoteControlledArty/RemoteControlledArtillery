/*
	The Order is
	Weapon -> Bag
*/

// Blufor
// Arid
class RC_Static_ATGM_A: RC_Static_AT_A
{
	displayname="RC ATGM 3km manual";

	class assembleInfo: assembleInfo
	{
		displayName="RC ATGM 3km manual";
		dissasembleTo[]=
		{
			"RC_Static_ATGM_A_Bag"
		};
	};

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			weapons[]=
			{
				"RC_ATGM_SACLOS"
			};
			magazines[]=
			{
				"RC_1Rnd_ATGM_MP_SACLOS",
				"RC_1Rnd_ATGM_MP_SACLOS",
				"RC_1Rnd_ATGM_MP_SACLOS",
				"RC_1Rnd_ATGM_MP_SACLOS"
			};
		};
	};
};
class RC_Static_ATGM_A_Bag: RC_Static_AA_A_Bag
{
	displayName="RC ATGM 3km manual";
	class assembleInfo: assembleInfo
	{
		displayName="RC ATGM 3km manual";
		assembleTo="RC_Static_ATGM_A";
	};
};

// Woodland
class RC_Static_ATGM_WD: RC_Static_ATGM_A
{
	DLC="Expansion";

	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"RC_Static_ATGM_WD_Bag"
		};
	};

	editorPreview="\A3\EditorPreviews_F\Data\CfgVehicles\I_static_AT_F.jpg";
	hiddenSelectionsTextures[]=
	{
		"\a3\weapons_f_beta\launchers\titan\data\launcher_INDP_co.paa",
		"\a3\weapons_f_beta\launchers\titan\data\tubem_INDP_co.paa"
	};
};
class RC_Static_ATGM_WD_Bag: RC_Static_AA_WD_Bag
{
	displayName="RC ATGM 3km manual";
	class assembleInfo: assembleInfo
	{
		displayName="RC ATGM 3km manual";
		assembleTo="RC_Static_ATGM_WD";
	};
};

// Opfor
// Arid
class RC_Static_ATGM_A_O: RC_Static_ATGM_A
{
	faction="RemoteControlled_O";
	side=0;
	crew="O_UAV_AI";

	class assembleInfo: assembleInfo
	{
		displayName="RC ATGM 3km manual [Opf]";
		dissasembleTo[]=
		{
			"RC_Static_ATGM_A_Bag_O"
		};
	};
};
class RC_Static_ATGM_A_Bag_O: RC_Static_ATGM_A_Bag
{
	displayName="RC ATGM 3km manual [Opf]";
	class assembleInfo: assembleInfo
	{
		displayName="RC ATGM 3km manual [Opf]";
		assembleTo="RC_Static_AT_A_O";
	};
};

// Woodland
class RC_Static_ATGM_WD_O: RC_Static_ATGM_WD
{
	faction="RemoteControlled_O";
	side=0;
	crew="O_UAV_AI";

	class assembleInfo: assembleInfo
	{
		displayName="RC ATGM 3km manual [Opf]";
		dissasembleTo[]=
		{
			"RC_Static_ATGM_WD_Bag_O"
		};
	};
};
class RC_Static_ATGM_WD_Bag_O: RC_Static_ATGM_WD_Bag
{
	displayName="RC ATGM 3km manual [Opf]";
	class assembleInfo: assembleInfo
	{
		displayName="RC ATGM 3km manual [Opf]";
		assembleTo="RC_Static_ATGM_WD_O";
	};
};

// Independent / Indi
// Arid
class RC_Static_ATGM_A_I: RC_Static_ATGM_A
{
	faction="RemoteControlled_I";
	side=2;
	crew="I_UAV_AI";

	class assembleInfo: assembleInfo
	{
		displayName="RC ATGM 3km manual [Ind]";
		dissasembleTo[]=
		{
			"RC_Static_ATGM_A_Bag_I"
		};
	};
};
class RC_Static_ATGM_A_Bag_I: RC_Static_ATGM_A_Bag
{
	displayName="RC ATGM 3km manual [Ind]";
	class assembleInfo: assembleInfo
	{
		displayName="RC ATGM 3km manual [Ind]";
		assembleTo="RC_Static_ATGM_A_I";
	};
};

// Woodland
class RC_Static_ATGM_WD_I: RC_Static_ATGM_WD
{
	faction="RemoteControlled_I";
	side=2;
	crew="I_UAV_AI";

	class assembleInfo: assembleInfo
	{
		displayName="RC ATGM 3km manual [Ind]";
		dissasembleTo[]=
		{
			"RC_Static_ATGM_WD_Bag_I"
		};
	};
};
class RC_Static_ATGM_WD_Bag_I: RC_Static_ATGM_WD_Bag
{
	displayName="RC ATGM 3km manual [Ind]";
	class assembleInfo: assembleInfo
	{
		displayName="RC ATGM 3km manual [Ind]";
		assembleTo="RC_Static_ATGM_WD_I";
	};
};
