// Counter Battery Radar - Player & AI Versions
class B_Radar_System_01_F;
class RC_CounterBatteryRadar_base: B_Radar_System_01_F
{
	class Components;
	class Turrets;
	class MainTurret;
	scope=0;
	scopeCurator=0;

	RC_CounterBatteryRadar=1;
};
class RC_CounterBatteryRadar_A: RC_CounterBatteryRadar_base
{
	displayName="Counter Battery Radar";
	faction="RemoteControlled_B";
	editorSubcategory="RC_Radar_subcat";
	author="Ascent";
	scope=2;
	scopeCurator=2;
	side=1;
	forceInGarage=1;

	threat[]={0.2,0.2,0.2};
	//radarTargetSize=1;
	lockDetectionSystem="2+4+8";
	incomingMissileDetectionSystem=16;

	class EventHandlers: EventHandlers
	{	
		class RC_Artillery
		{
			#include "\Remote_Controlled_Artillery\CounterBatteryRadar_scripts\CounterBatteryRadar_Player.hpp"
		};
	};

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			showAllTargets="2 + 4";

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
							range[]={50000,30000,15000,7500};
							resource="RscCustomInfoSensors";
						};
					};
				};
			};
		};
	};
};
class RC_CounterBatteryRadar_WD: RC_CounterBatteryRadar_A
{
	//DLC="Expansion";
	editorPreview="";
	textureList[]=
	{
		"Desert",
		0,
		"Olive",
		1
	};
	/*
	hiddenSelectionsTextures[]=
	{
		"A3\Static_F_Sams\Radar_System_01\Data\Radar_system_01_mat_01_olive_CO.paa",
		"A3\Static_F_Sams\Radar_System_01\Data\Radar_system_01_mat_02_olive_CO.paa"
	};
	*/
};
class RC_CounterBatteryRadar_A_O: RC_CounterBatteryRadar_A
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
};
class RC_CounterBatteryRadar_WD_O: RC_CounterBatteryRadar_WD
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
};
class RC_CounterBatteryRadar_A_I: RC_CounterBatteryRadar_A_A
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
};
class RC_CounterBatteryRadar_WD_I: RC_CounterBatteryRadar_WD
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
};