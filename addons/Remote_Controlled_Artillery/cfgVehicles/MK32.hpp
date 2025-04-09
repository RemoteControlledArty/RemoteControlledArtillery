class B_GMG_01_high_F;
class RC_AntiDroneTurret_base: B_GMG_01_high_F
{
	class Turrets;
	class MainTurret;
	class assembleInfo;
	class OpticsIn;
	class ViewOptics;
	class Components;
	class AnimationSources;
	scope=0;
	scopeCurator=0;
};
class RC_AntiDroneTurret: RC_AntiDroneTurret_base
{
	displayName="RC Anti Drone 20mm";
	faction="RemoteControlled_B";
	editorSubcategory="RC_AntiDrone_subcat";
	author="Ascent";
	scope=2;
	scopeCurator=2;
	side=1;
	forceInGarage=1;

	visionMode[]=
	{
		"Normal"
	};

	#include "\Remote_Controlled_Artillery\includes_cfg\isUGV.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\Systems.hpp"

	uavCameraGunnerPos="eye";
	uavCameraGunnerDir="look";
	crew="B_UAV_AI";
	showAllTargets="2 + 4";
	enableGPS=1;

	//armor=30;	//30

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{	
			showAllTargets="2 + 4";
			gunnerForceOptics=1;
			maxElev=70;
			thermalMode[]={0};

			weapons[]=
			{
				"RC_autocannon_20mm_AntiDrone"
			};
			magazines[]=
			{
				"RC_60Rnd_20mm_AntiDroneShot",
				"RC_60Rnd_20mm_AntiDroneShot",
				"RC_60Rnd_20mm_AntiDroneShot",
				"RC_60Rnd_20mm_AntiDroneShot"
			};

			class OpticsIn: OpticsIn
			{
				class ViewOptics: ViewOptics
				{
					gunnerOpticsModel="\A3\weapons_f\reticle\Optics_Gunner_02_F";
					initFov=0.89999998;
					minFov=0.02;
					maxFov=0.89999998;
					//memoryPointGunnerOptics="gunnerview";
					thermalMode[]={0};
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
							range[]={600};
							resource="RscCustomInfoSensors";
						};
					};
				};
				class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft
				{
					defaultDisplay="EmptyDisplay";

					class Components
					{
						class MinimapDisplay
						{
							componentType="MinimapDisplayComponent";
							resource="RscCustomInfoMiniMap";
						};
						class EmptyDisplay
						{
							componentType="EmptyDisplayComponent";
						};
					};
				};
			};
		};
	};

	class Components: Components
	{
		class SensorsManagerComponent
		{
			class Components
			{
				class DataLinkSensorComponent: SensorTemplateDataLink
				{
					typeRecognitionDistance=4000;

					class AirTarget
					{
						minRange=4000;
						maxRange=4000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=4000;
						maxRange=4000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
				};
				class IRSensorComponent: SensorTemplateIR
				{
					typeRecognitionDistance=400;

					class AirTarget
					{
						minRange=400;
						maxRange=400;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=0;
						maxRange=0;
						objectDistanceLimitCoef=1;
						viewDistanceLimitCoef=1;
					};
					maxTrackableSpeed=600;
					angleRangeHorizontal=360;
					angleRangeVertical=360;
					animDirection="mainGun";
				};
				class VisualSensorComponent: SensorTemplateVisual
				{
					typeRecognitionDistance=400;

					class AirTarget
					{
						minRange=400;
						maxRange=400;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=0;
						maxRange=0;
						objectDistanceLimitCoef=1;
						viewDistanceLimitCoef=1;
					};
					maxTrackableSpeed=600;
					nightRangeCoef=0.80000001;
					angleRangeHorizontal=360;
					angleRangeVertical=360;
					animDirection="mainGun";
				};
			};
		};
	};

	class AnimationSources: AnimationSources
	{
		class muzzle_source
		{
			source="reload";
			weapon="GMG_20mm";
		};
		class muzzle_source_rot
		{
			source="ammorandom";
			weapon="GMG_20mm";
		};
		class ReloadAnim
		{
			source="reload";
			weapon="GMG_20mm";
		};
		class ReloadMagazine
		{
			source="reloadmagazine";
			weapon="GMG_20mm";
		};
		class Revolving
		{
			source="revolving";
			weapon="GMG_20mm";
		};
	};

	/*
	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"RC_Mortar_Bag"
		};
	};
	*/
};
class RC_AntiDroneTurret_O: RC_AntiDroneTurret
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
};
class RC_AntiDroneTurret_I: RC_AntiDroneTurret
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
};


/*
class B_Mortar_01_weapon_F;
class RC_Mortar_Bag_base: B_Mortar_01_weapon_F
{
	class assembleInfo;
	scope=0;
	scopeCurator=0;
};
class RC_Mortar_Bag: RC_Mortar_Bag_base
{
	displayName="RC Mortar";
	scope=2;
	scopeCurator=2;

	mass=540;

	model="\A3\Weapons_F\Ammoboxes\Bags\Backpack_Tortila.p3d";
	picture="\A3\Weapons_F\Ammoboxes\Bags\data\UI\icon_B_C_Tortila_cbr.paa";
	hiddenSelectionsTextures[]=
	{
		"\A3\Weapons_F\Ammoboxes\Bags\Data\backpack_Tortila_cbr_co.paa"
	};

	class assembleInfo: assembleInfo
	{
		displayName="RC Mortar";
		assembleTo="RC_Mortar";
		base="";
	};
};
class RC_Mortar_Bag_O: RC_Mortar_Bag
{
	displayName="RC Mortar [Opf]";

	class assembleInfo: assembleInfo
	{
		displayName="RC Mortar [Opf]";
		assembleTo="RC_Mortar_O";
	};
};
class RC_Mortar_Bag_HEX_O: RC_Mortar_Bag_base
{
	picture="\A3\Weapons_F\Ammoboxes\Bags\data\UI\icon_B_C_Tortila_hex.paa";
	hiddenSelectionsTextures[]=
	{
		"\A3\Weapons_F\Ammoboxes\Bags\Data\backpack_Tortila_hex_co.paa"
	};

	class assembleInfo: assembleInfo
	{
		assembleTo="RC_Mortar_HEX_O";
	};
};	
class RC_Mortar_Bag_I: RC_Mortar_Bag
{
	displayName="RC Mortar [Ind]";

	class assembleInfo: assembleInfo
	{
		displayName="RC Mortar [Ind]";
		assembleTo="RC_Mortar_I";
	};
};
*/