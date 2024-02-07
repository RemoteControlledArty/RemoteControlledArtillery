// AA
class B_APC_Tracked_01_AA_F;
class RC_AA_base: B_APC_Tracked_01_AA_F
{
	class AnimationSources;
	class Components;
	class showCamonetTurret;
	class showCamonetHull;
	class Turrets;
	class MainTurret;
	class CommanderOptics;
	scope=0;
	scopeCurator=0;
	RCDisableSeats=5; // disables driver and commander seat
	RCEngineOff=1; //1 = turns off engine when stopping, 2 = same but with delay, required for slow accelerating vehicles
};
class RC_AA_A: RC_AA_base
{
	displayName="RC Anti-Air";
	faction="RemoteControlled_B";
	editorSubcategory="RC_AntiAir_subcat";
	author="Ascent";
	scope=2;
	scopeCurator=2;
	side=1;
	forceInGarage=1;

	textPlural="UGVs";
	textSingular="UGV";
	isUav=1;
	vehicleClass="Autonomous";
	uavCameraGunnerPos="PiP0_pos";
	uavCameraGunnerDir="PiP0_dir";
	crew="B_UAV_AI";
	driverForceOptics=1;

	ejectDeadGunner=0;
	ejectDeadDriver=0;
	ejectDeadCommander=0;

	receiveRemoteTargets=1;
	reportRemoteTargets=1;
	incomingMissileDetectionSystem=16;

	class AnimationSources: AnimationSources
	{
		class showCamonetTurret: showCamonetTurret
		{
			initPhase=1;
		};
		class showCamonetHull: showCamonetHull
		{
			initPhase=1;
		};
	};
	animationList[]=
	{
		"showCamonetTurret",
		0,
		"showCamonetHull",
		0
	};

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			commanding=2;
			gunnerForceOptics=1;
			forceHideGunner=1;
			
			class Turrets: Turrets
			{
				class CommanderOptics : CommanderOptics
				{
					commanding=1;
					hasGunner=-1;
					hasCommander=-1;
					forceHideGunner=1;
				};
			};
		};
	};

	class TransportMagazines
	{
	};
	class TransportItems
	{
		class _xx_Toolkit
		{
			name="Toolkit";
			count=2;
		};
		class _xx_Medikit
		{
			name="Medikit";
			count=5;
		};
		class _xx_FirstAidKit
		{
			name="FirstAidKit";
			count=5;
		};
	};
	class TransportWeapons
	{
	};
};
class RC_AA_WD: RC_AA_A
{
	DLC="Expansion";
	editorPreview="\A3\EditorPreviews_F_Exp\Data\CfgVehicles\B_T_APC_Tracked_01_AA_F.jpg";
	hiddenSelectionsTextures[]=
	{
		"A3\Armor_F_exp\APC_Tracked_01\Data\apc_tracked_01_aa_body_olive_co.paa",
		"A3\Armor_F_exp\APC_Tracked_01\Data\mbt_01_body_olive_co.paa",
		"A3\Armor_F_exp\APC_Tracked_01\Data\apc_tracked_01_aa_tower_olive_co.paa",
		"a3\Armor_F\Data\camonet_NATO_Green_CO.paa"
	};
};
class RC_AA_A_O: RC_AA_A
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
};
class RC_AA_WD_O: RC_AA_WD
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
};
class RC_AA_A_I: RC_AA_A
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
};
class RC_AA_WD_I: RC_AA_WD
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
};



class O_APC_Tracked_02_AA_F;
class RC_AA_base_HEX_O: O_APC_Tracked_02_AA_F
{
	class AnimationSources;
	class Components;
	class showCamonetTurret;
	class showCamonetHull;
	class showSLATHull;
	class Turrets;
	class MainTurret;
	class CommanderOptics;
	scope=0;
	scopeCurator=0;
	RCDisableSeats=5; // disables driver and commander seat
	RCEngineOff=1; //1 = turns off engine when stopping, 2 = same but with delay, required for slow accelerating vehicles
};
class RC_AA_HEX_A: RC_AA_base_HEX_O
{
	displayName="RC Anti-Air";
	faction="RemoteControlled_O";
	editorSubcategory="RC_AntiAir_subcat";
	author="Ascent";
	scope=2;
	scopeCurator=2;
	side=0;
	forceInGarage=1;


	textPlural="UGVs";
	textSingular="UGV";
	isUav=1;
	vehicleClass="Autonomous";
	uavCameraGunnerPos="PiP1_pos";
	uavCameraGunnerDir="PiP1_dir";
	crew="O_UAV_AI";
	driverForceOptics=1;

	ejectDeadGunner=0;
	ejectDeadDriver=0;
	ejectDeadCommander=0;

	incomingMissileDetectionSystem=16;

	class AnimationSources: AnimationSources
	{
		class showCamonetTurret: showCamonetTurret
		{
			initPhase=1;
		};
		class showCamonetHull: showCamonetHull
		{
			initPhase=1;
		};
		class showSLATHull: showSLATHull
		{
			initPhase=1;
		};
	};
	animationList[]=
	{
		"showCamonetTurret",
		1,
		"showCamonetHull",
		1,
		"showSLATHull",
		1
	};

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			commanding=2;
			gunnerForceOptics=1;
			forceHideGunner=1;
			
			class Turrets: Turrets
			{
				class CommanderOptics : CommanderOptics
				{
					commanding=1;
					hasGunner=-1;
					hasCommander=-1;
					forceHideGunner=1;
				};
			};
		};
	};
	class TransportMagazines
	{
	};
	class TransportItems
	{
		class _xx_Toolkit
		{
			name="Toolkit";
			count=2;
		};
		class _xx_Medikit
		{
			name="Medikit";
			count=5;
		};
		class _xx_FirstAidKit
		{
			name="FirstAidKit";
			count=5;
		};
	};
	class TransportWeapons
	{
	};
};
class RC_AA_HEX_WD: RC_AA_HEX_A
{
	DLC="Expansion";
	editorPreview="\A3\EditorPreviews_F_Exp\Data\CfgVehicles\O_T_APC_Tracked_02_AA_ghex_F.jpg";
	textureList[]=
	{
		"GreenHex",
		1
	};
	hiddenSelectionsTextures[]=
	{
		"A3\Armor_F_Exp\APC_Tracked_02\Data\APC_Tracked_02_ext_01_AA_ghex_CO.paa",
		"A3\Armor_F_Exp\APC_Tracked_02\Data\APC_Tracked_02_ext_02_ghex_CO.paa",
		"A3\Armor_F_Exp\APC_Tracked_02\Data\APC_Tracked_01_AA_Tower_ghex_CO.paa",
		"A3\Armor_F\Data\camonet_CSAT_HEX_Green_CO.paa",
		"A3\armor_f\data\cage_csat_green_CO.paa"
	};
};