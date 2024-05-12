class QIN_Titus_base;
class QIN_Titus_DES;
class RC_Titus_unarmed_D_base: QIN_Titus_DES
{
	class Turrets;
	class ViewOptics;
	//class ViewGunner;
	class CommanderTurret;
	class CargoTurret_01;
	class CargoTurret_02;
	class CargoTurret_03;
	class AnimationSources;
	class Components;
	class Door_LF;
	class Door_RF;
	class Door_rear;
	class comp_camonet;
	class comp_klec;
	class HitPoints;
	class HitLFWheel;
	class HitLF2Wheel;
	class HitLMWheel;
	class HitLBWheel;
	class HitRFWheel;
	class HitRF2Wheel;
	class HitRMWheel;
	class HitRBWheel;
	class EventHandlers;
	scope=0;
	scopeCurator=0;
	RC_Local=1; //1 = requires transfer of locality/ownership for full functionality
};

class RC_Titus_unarmed_D: RC_Titus_unarmed_D_base
{
	#include "\RC_Titus\Titus_include.hpp"

	class EventHandlers: EventHandlers
	{
		#include "\Remote_Controlled_Artillery\includes\DriverControlsEH_ICV.hpp"
	};

	displayName="RC Titus";
	editorSubcategory="RC_Titus_subcat";
	scope=2;
	scopeCurator=2;
	forceInGarage=1;
	uavCameraGunnerPos="PiP1_pos";
	uavCameraGunnerDir="PiP1_dir";
	threat[]={0.30000001,0.30000001,0.30000001};

	class Turrets: Turrets
	{
		class CommanderTurret : CommanderTurret
		{
			#include "\Remote_Controlled_Artillery\includes\cfgTakeControls.hpp"
			showAllTargets="2 + 4";
			gunnerCompartments="Compartment4";
			primaryGunner=1;
			primaryObserver=0;
			gunnerForceOptics=1;
			forceHideGunner=1;
			commanding=4;

			//gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_02_n_F.p3d";
			//personTurretAction="";	//no effect
			//forceHideCommander=1;	//makes view bug
			//gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_02_n_F.p3d";
			//turretInfoType="RscWeaponRangeFinder";
			//turretInfoType="";

			gunnerAction="";
			//canHideGunner=1;
			//viewGunnerInExternal=1;
			isPersonTurret=0;
			//animationSourceHatch="hatch_3";
			personTurretAction="";

			class ViewOptics: ViewOptics
			{
				initFov=1;
				minFov=0.05;
				maxFov=1;
				visionMode[]=
				{
					"Normal",
					"NVG",
					"Ti"
				};
				thermalMode[]={0};
			};

			weapons[]=
			{
				"RC_Laserdesignator_vehicle",
				"SmokeLauncher"
			};
			magazines[]=
			{
				"Laserbatteries",
				"SmokeLauncherMag",
				"SmokeLauncherMag"
			};
			
			class Components: Components
			{
				class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight
				{
					defaultDisplay="SensorsDisplayComponent";

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
						class UAVFeedDisplay
						{
							componentType="UAVFeedDisplayComponent";
						};
						class SensorDisplay
						{
							componentType="SensorsDisplayComponent";
							range[]={4000,2000,1000,500};
							resource="RscCustomInfoSensors";
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
				class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft
				{
					defaultDisplay="EmptyDisplayComponent";

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
						class UAVFeedDisplay
						{
							componentType="UAVFeedDisplayComponent";
						};
						class SensorDisplay
						{
							componentType="SensorsDisplayComponent";
							range[]={4000,2000,1000,500};
							resource="RscCustomInfoSensors";
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

		class CargoTurret_01: CargoTurret_01 {};
		class CargoTurret_02: CargoTurret_02 {};
		class CargoTurret_03: CargoTurret_03
		{
			commanding=3;
			primaryGunner=0;
			primaryObserver=1;

			weapons[]=
			{
				"TruckHorn2",
				"SmokeLauncher"
			};
			magazines[]=
			{
				"SmokeLauncherMag",
				"SmokeLauncherMag"
			};
			
			class Components: Components
			{
				class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight
				{
					defaultDisplay="SensorsDisplayComponent";

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
						class UAVFeedDisplay
						{
							componentType="UAVFeedDisplayComponent";
						};
						class SensorDisplay
						{
							componentType="SensorsDisplayComponent";
							range[]={4000,2000,1000,500};
							resource="RscCustomInfoSensors";
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
				class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft
				{
					defaultDisplay="EmptyDisplayComponent";

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
						class UAVFeedDisplay
						{
							componentType="UAVFeedDisplayComponent";
						};
						class SensorDisplay
						{
							componentType="SensorsDisplayComponent";
							range[]={4000,2000,1000,500};
							resource="RscCustomInfoSensors";
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
		
		/*
		//seem to be blocked?
		class CargoTurret_03: CargoTurret_01
		{
			gunnerAction="vehicle_turnout_2";
			memoryPointsGetInGunner="pos codriver";
			memoryPointsGetInGunnerDir="pos codriver dir";
			gunnerName="Co-Driver";
			proxyIndex=11;
			gunnerInAction="passenger_low01";
			animationSourceHatch="hatch_4";
			gunnerDoor="door_rf";
		};
		*/
	};
};

class RC_Titus_unarmed_WD: RC_Titus_unarmed_D
{
	editorPreview="qin_titus\data\preview\titus_unarmed_wdl.jpg";
	hiddenSelectionsTextures[]=
	{
		"qin_titus\data\skins\wdl\karoserie1_wdl.paa",
		"qin_titus\data\skins\wdl\karoserie2_wdl.paa",
		"qin_titus\data\skins\wdl\karoserie3_wdl.paa",
		"qin_titus\data\skins\wdl\arx20_wdl.paa",
		"qin_titus\data\skins\wdl\interier1_wdl.paa",
		"qin_titus\data\skins\wdl\interier2_wdl.paa",
		"qin_titus\data\camonet_wdl_co.paa"
	};
};

class RC_Titus_unarmed_A: RC_Titus_unarmed_D
{
	hiddenSelectionsTextures[]=
	{
		"qin_titus\data\skins\wdl2\karoserie1_wdl2.paa",
		"qin_titus\data\skins\wdl2\karoserie2_wdl2.paa",
		"qin_titus\data\skins\wdl2\karoserie3_wdl2.paa",
		"qin_titus\data\skins\wdl2\arx20_wdl2.paa",
		"qin_titus\data\skins\wdl2\interier1_wdl2.paa",
		"qin_titus\data\skins\wdl2\interier2_wdl2.paa",
		"qin_titus\data\camonet_wdl2_co.paa"
	};
};

/*
class QIN_Titus_arx20_DES;
class RC_Titus_armed_base: QIN_Titus_arx20_DES
{
	class ARX20Turret;
};
class RC_Titus_armed_D: RC_Titus_armed_base
{
	displayName="RC Titus 20mm";

	class Turrets: Turrets
	{
		class CommanderTurret : CommanderTurret
		{
			primaryGunner=1;
			primaryObserver=0;

		};
		class ARX20Turret: ARX20Turret
		{
			primaryGunner=0;
			primaryObserver=1;
		};
	};
};
*/