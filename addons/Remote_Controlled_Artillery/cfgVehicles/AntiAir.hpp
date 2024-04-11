// AA
class B_APC_Tracked_01_AA_F;
class RC_AA_base: B_APC_Tracked_01_AA_F
{
	class AnimationSources;
	class Components;
	class showCamonetTurret;
	class showCamonetHull;
	class showCamonetPlates1;
	class showCamonetPlates2;
	class Turrets;
	class MainTurret;
	class CommanderOptics;
	scope=0;
	scopeCurator=0;
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
	uavCameraDriverPos="PiP0_pos";
	uavCameraDriverDir="PiP0_dir";
	uavCameraGunnerPos="PiP0_pos";
	uavCameraGunnerDir="PiP0_dir";
	crew="B_UAV_AI";
	driverForceOptics=1;
	driverCompartments="Compartment1";
	ejectDeadGunner=0;
	ejectDeadDriver=0;
	ejectDeadCommander=0;
	receiveRemoteTargets=1;
	reportRemoteTargets=1;
	lockDetectionSystem=4;
	incomingMissileDetectionSystem=16;

	hiddenSelectionsTextures[]=
	{
		"A3\Armor_F_Beta\APC_Tracked_01\Data\apc_tracked_01_aa_body_co.paa",
		"A3\Armor_F_Beta\APC_Tracked_01\Data\mbt_01_body_co.paa",
		"A3\Armor_F_Beta\APC_Tracked_01\Data\apc_tracked_01_aa_tower_co.paa",
		"Remote_Controlled_Artillery\textures\camonet_tan_CO.paa"
	};

	class AnimationSources: AnimationSources
	{
		class showCamonetPlates1: showCamonetPlates1
		{
			initPhase=1;
		};
		class showCamonetPlates2: showCamonetPlates2
		{
			initPhase=1;
		};
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
			gunnerCompartments="Compartment2";
			showAllTargets="2 + 4";
			commanding=2;
			gunnerForceOptics=1;
			forceHideGunner=1;
			
			class Turrets: Turrets
			{
				class CommanderOptics : CommanderOptics
				{
					gunnerCompartments="Compartment3";
					showAllTargets="2 + 4";
					commanding=1;
					hasGunner=-1;
					hasCommander=-1;
					forceHideGunner=1;
				};
			};

			class Components: Components
			{
				class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight
				{
					defaultDisplay="SensorDisplay";

					class Components
					{
						class SensorDisplay
						{
							componentType="SensorsDisplayComponent";
							range[]={16000,8000,4000,2000};
							resource="RscCustomInfoSensors";
						};
					};
				};
				class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft
				{
					defaultDisplay="EmptyDisplay";

					class Components
					{
						class EmptyDisplay
						{
							componentType="EmptyDisplayComponent";
						};
						class MinimapDisplay
						{
							componentType="MinimapDisplayComponent";
							resource="RscCustomInfoMiniMap";
						};
						/*
						class MineDetectorDisplay
						{
							componentType="MineDetectorDisplayComponent";
							range=50;
							resource="RscCustomInfoMineDetect";
						};
						*/
					};
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
		//"a3\Armor_F\Data\camonet_NATO_Green_CO.paa"
		"a3\armor_f\data\camonet_green_co.paa"
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
	RCEngineOff=1; //1 = turns off engine when stopping, 2 = same but with delay, required for slow accelerating vehicles
};
class RC_AA_HEX_A_O: RC_AA_base_HEX_O
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
	uavCameraDriverPos="PiP1_pos";
	uavCameraDriverDir="PiP1_dir";
	uavCameraGunnerPos="PiP1_pos";
	uavCameraGunnerDir="PiP1_dir";
	crew="O_UAV_AI";
	driverForceOptics=1;
	driverCompartments="Compartment1";
	ejectDeadGunner=0;
	ejectDeadDriver=0;
	ejectDeadCommander=0;
	receiveRemoteTargets=1;
	reportRemoteTargets=1;
	lockDetectionSystem=4;
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
			gunnerCompartments="Compartment2";
			showAllTargets="2 + 4";
			commanding=2;
			gunnerForceOptics=1;
			forceHideGunner=1;
			
			class Turrets: Turrets
			{
				class CommanderOptics : CommanderOptics
				{
					gunnerCompartments="Compartment3";
					showAllTargets="2 + 4";
					commanding=1;
					hasGunner=-1;
					hasCommander=-1;
					forceHideGunner=1;
				};
			};

			class Components: Components
			{
				class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight
				{
					defaultDisplay="SensorDisplay";

					class Components
					{
						class SensorDisplay
						{
							componentType="SensorsDisplayComponent";
							range[]={16000,8000,4000,2000};
							resource="RscCustomInfoSensors";
						};
					};
				};
				class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft
				{
					defaultDisplay="EmptyDisplay";

					class Components
					{
						class EmptyDisplay
						{
							componentType="EmptyDisplayComponent";
						};
						class MinimapDisplay
						{
							componentType="MinimapDisplayComponent";
							resource="RscCustomInfoMiniMap";
						};
						/*
						class MineDetectorDisplay
						{
							componentType="MineDetectorDisplayComponent";
							range=50;
							resource="RscCustomInfoMineDetect";
						};
						*/
					};
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
class RC_AA_HEX_WD_O: RC_AA_HEX_A_O
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


//optional Phantom Hawk Retextures (found in steam workshop)
class RC_AA_ReTex_WD: RC_AA_A
{
	faction="RemoteControlled_ReTex_B";
	editorSubcategory="RC_ReTex_Woodland_subcat";
	editorPreview="\A3\EditorPreviews_F_Exp\Data\CfgVehicles\B_T_APC_Tracked_01_AA_F.jpg";
	hiddenSelectionsTextures[]=
	{
		"namer\data\namer_01_aa_body_wd.paa",
		"namer\data\mbt_01_body_wd.paa",
		"namer\data\namer_01_aa_tower_wd.paa",
		"a3\armor_f\data\camonet_green_co.paa"
	};
};
class RC_AA_ReTex_WD_O: RC_AA_ReTex_WD
{
	faction="RemoteControlled_ReTex_O";
	crew="O_UAV_AI";
	side=0;
};
class RC_AA_ReTex_WD_I: RC_AA_ReTex_WD
{
	faction="RemoteControlled_ReTex_I";
	crew="I_UAV_AI";
	side=2;
};


class RC_AA_ReTex_D: RC_AA_A
{
	faction="RemoteControlled_ReTex_B";
	editorSubcategory="RC_ReTex_Desert_subcat";
	hiddenSelectionsTextures[]=
	{
		"namer\data\namer_01_aa_body_d.paa",
		"namer\data\mbt_01_body_d.paa",
		"namer\data\namer_01_aa_tower_d.paa",
		"namer\data\camonet_desert_co.paa"
	};
};
class RC_AA_ReTex_D_O: RC_AA_ReTex_D
{
	faction="RemoteControlled_ReTex_O";
	crew="O_UAV_AI";
	side=0;
};
class RC_AA_ReTex_D_I: RC_AA_ReTex_D
{
	faction="RemoteControlled_ReTex_I";
	crew="I_UAV_AI";
	side=2;
};