///*
class LandVehicle;
class StaticWeapon: LandVehicle
{
	class Turrets
	{
		class MainTurret;
	};
};
class StaticMortar: StaticWeapon
{
	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			class ViewOptics;
		};
	};
};
class Mortar_01_base_F: StaticMortar
{
	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			class ViewOptics: ViewOptics
			{
			};
		};
	};
};
class twc_2inch_vehicle: Mortar_01_base_F
{
	displayname="60mm COMMANDO Mortar";
	author="LeoVetta";
	model="twc_2inch\twc_2inch.p3d";
	artilleryScanner=0;
	scope=1;
	scopeCurator=1;
	scopeArsenal=1;
	side=1;
	faction="BLU_F";
	crew="B_Soldier_F";
	availableForSupportTypes[]=
	{
		"Artillery"
	};
	editorPreview="\A3\EditorPreviews_F\Data\CfgVehicles\B_Mortar_01_F.jpg";
	class assembleInfo
	{
		assembleTo="";
		base="";
		displayName="";
		dissasembleTo[]={};
		primary=0;
	};
	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			initElev=-30;
			maxelev=0;
			minelev=-88;
			weapons[]=
			{
				"twc_2inch_weapon"
			};
			magazines[]={};
			gunnerAction="twc_2inch_Gunner";
			gunnerRightHandAnimName="OtocHlaven";
			gunnerOpticsModel="\A3\weapons_f\reticle\optics_empty";
			turretInfoType="twc_2inch_ui";
			elevationAnimSourceSpeed=10;
			maxHorizontalRotSpeed=4;
			maxVerticalRotSpeed=4;
			animationSourceElevation="elevBarrel";
			memoryPointGunnerOptics="AimPoint";
			class ViewOptics: ViewOptics
			{
				initAngleX=0;
				minAngleX=-30;
				maxAngleX=30;
				initAngleY=0;
				minAngleY=0;
				maxAngleY=45;
				initFov=0.69999999;
				minFov=0.69999999;
				maxFov=0.69999999;
				visionMode[]=
				{
					"Normal"
				};
			};
		};
	};
};
class RC_ULM_Core: StaticMortar
{
	features="Randomization: No						<br />Camo selections: 1 - the whole weapon with pod						<br />Script door sources: None						<br />Script animations: None						<br />Executed scripts: None						<br />Firing from vehicles: Just the weapon						<br />Slingload: No						<br />Cargo proxy indexes: None";
	author="$STR_A3_Bohemia_Interactive";
	_generalMacro="RC_M_Core";

	scope=0;
	scopeCurator=0;

	displayname="$STR_A3_CfgVehicles_Mortar_01_Base0";
	class Library
	{
		libTextDesc="$STR_A3_CfgVehicles_Mortar_01_Base_Library0";
	};
	transportSoldier=0;
	cargoAction[]=
	{
		"Mortar_Gunner"
	};
	getInAction="GetInMortar";
	getOutAction="GetOutLow";
	unitInfoType="RscUnitInfoMortar";
	//unitInfoType="";
	editorSubcategory="EdSubcat_Turrets";
	picture="\A3\Static_f\Mortar_01\data\UI\Mortar_01_ca.paa";
	icon="\A3\Static_f\Mortar_01\data\UI\map_Mortar_01_CA.paa";
	cost=200000;
	accuracy=0.25;
	EPEImpulseDamageCoef=5;
	class Damage
	{
		tex[]={};
		mat[]=
		{
			"A3\Static_f\Mortar_01\data\Mortar_01.rvmat",
			"A3\Static_f\Mortar_01\data\Mortar_01_damage.rvmat",
			"A3\Static_f\Mortar_01\data\Mortar_01_destruct.rvmat"
		};
	};
	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			gunnerAction="Mortar_Gunner";
			gunnergetInAction="";
			gunnergetOutAction="";
			weapons[]=
			{
				"mortar_82mm"
			};
			elevationMode=1;
			initCamElev=0;
			minCamElev=-35;
			maxCamElev=35;
			initElev=0;
			minTurn=-180;
			maxTurn=180;
			initTurn=0;
			cameraDir="look";
			discreteDistance[]={100,200,300,400,500,700,1000,1600,2000,2400,2800};
			discreteDistanceCameraPoint[]=
			{
				"eye"
			};
			discreteDistanceInitIndex=5;
			turretInfoType="RscWeaponRangeArtillery";
			//turretInfoType="";
			gunnerForceOptics=0;
			memoryPointGunnerOptics="eye";
			gunnerOpticsModel="\A3\Weapons_F\acc\reticle_Mortar_01_F.p3d";
			disableSoundAttenuation=1;
			class ViewOptics: ViewOptics
			{
				initAngleX=0;
				minAngleX=-30;
				maxAngleX=30;
				initAngleY=0;
				minAngleY=-100;
				maxAngleY=100;
				initFov=0.17399999;
				minFov=0.0077777999;
				maxFov=0.14;
				visionMode[]=
				{
					"Normal",
					"NVG"
				};
			};
			minelev=-30;
			maxelev=13;
			magazines[]=
			{
				"8Rnd_82mm_Mo_shells",
				"8Rnd_82mm_Mo_shells",
				"8Rnd_82mm_Mo_shells",
				"8Rnd_82mm_Mo_shells",
				"8Rnd_82mm_Mo_Flare_white",
				"8Rnd_82mm_Mo_Smoke_white"
			};
			ejectDeadGunner=1;
			usepip=2;
		};
	};
	class EventHandlers
	{
		fired="_this call (uinamespace getvariable 'BIS_fnc_effectFired');";
	};
	htMin=1;
	htMax=480;
	afMax=0;
	mfMax=0;
	mFact=1;
	tBody=100;
	class DestructionEffects
	{
		class Smoke
		{
			simulation="particles";
			type="WeaponWreckSmoke";
			position="destructionEffect";
			intensity=1;
			interval=1;
			lifeTime=5;
		};
	};
	model="\A3\static_f\Mortar_01\Mortar_01_F";
	artilleryScanner=1;
	class assembleInfo
	{
		primary=0;
		base="";
		assembleTo="";
		dissasembleTo[]=
		{
			"B_Mortar_01_weapon_F",
			"B_Mortar_01_support_F"
		};
		displayName="";
	};
	hiddenSelections[]=
	{
		"Camo"
	};
	hiddenSelectionsTextures[]=
	{
		"\A3\Static_f\Mortar_01\data\Mortar_01_CO.paa"
	};
};
class RC_ULM_Base: RC_ULM_Core
{
	author="$STR_A3_Bohemia_Interactive";
	class SimpleObject
	{
		eden=1;
		animate[]=
		{
			
			{
				"mainturret",
				0
			},
			
			{
				"maingun",
				0
			},
			
			{
				"optics",
				0
			},
			
			{
				"optics_stabilization",
				0
			},
			
			{
				"legs_zeroing",
				0
			},
			
			{
				"uplegs_zeroing",
				0
			}
		};
		hide[]=
		{
			"light_back",
			"brzdove svetlo",
			"clan",
			"podsvit pristroju",
			"poskozeni"
		};
		verticalOffset=0.75700003;
		verticalOffsetWorld=0.035;
		init="''";
	};
	editorPreview="\A3\EditorPreviews_F\Data\CfgVehicles\B_Mortar_01_F.jpg";
	_generalMacro="RC_M_Base";
	side=1;
	faction="BLU_F";
	crew="B_Soldier_F";
	availableForSupportTypes[]=
	{
		"Artillery"
	};
};
class RC_60mm_ULM_Core: RC_ULM_Base
{
	model="twc_2inch\twc_2inch.p3d";
	artilleryScanner=1;
	side=1;
	faction="BLU_F";
	crew="B_Soldier_F";
	availableForSupportTypes[]=
	{
		"Artillery"
	};
	editorPreview="\A3\EditorPreviews_F\Data\CfgVehicles\B_Mortar_01_F.jpg";
	class assembleInfo
	{
		assembleTo="";
		base="";
		displayName="";
		dissasembleTo[]={};
		primary=0;
	};

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			elevationAnimSourceSpeed=10;
			maxHorizontalRotSpeed=4;
			maxVerticalRotSpeed=4;
			magazines[]={};
			gunnerAction="twc_2inch_Gunner";
			gunnerRightHandAnimName="OtocHlaven";
		};
	};
};
//*/


/*
class B_Mortar_01_F;
class RC_60mm_ULM_Core: B_Mortar_01_F
{
	scope=0;
	scopeCurator=0;
	class Turrets;
	class MainTurret;
	//class Components;
	class ViewOptics;

	model="twc_2inch\twc_2inch.p3d";
	artilleryScanner=1;
	side=1;
	faction="BLU_F";
	crew="B_Soldier_F";
	availableForSupportTypes[]=
	{
		"Artillery"
	};
	editorPreview="\A3\EditorPreviews_F\Data\CfgVehicles\B_Mortar_01_F.jpg";
	class assembleInfo
	{
		assembleTo="";
		base="";
		displayName="";
		dissasembleTo[]={};
		primary=0;
	};
};
*/


/*
class twc_2inch_vehicle;
class RC_60mm_ULM_Core: twc_2inch_vehicle
{
	scope=0;
	scopeCurator=0;
	class Turrets;
	class MainTurret;
	class ViewOptics;
};
*/


class RC_60mm_ULM_Base: RC_60mm_ULM_Core
{
	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			elevationAnimSourceSpeed=10;
			maxHorizontalRotSpeed=4;
			maxVerticalRotSpeed=4;
			magazines[]={};
			gunnerAction="twc_2inch_Gunner";
			gunnerRightHandAnimName="OtocHlaven";

			maxelev=0;
			minelev=-55;	//<800MIL for use on uneven ground	//88 for low
			turretInfoType="Rsc_ULM";
			//turretInfoType="twc_2inch_ui";
			gunnerOpticsModel="\A3\weapons_f\reticle\optics_empty";
			animationSourceElevation="elevBarrel";
			memoryPointGunnerOptics="AimPoint";

			/*
			//gunnerAction="Mortar_Gunner";
			gunnergetInAction="";
			gunnergetOutAction="";
			elevationMode=1;
			initCamElev=0;
			minCamElev=-35;
			maxCamElev=35;
			minTurn=-180;
			maxTurn=180;
			initTurn=0;
			cameraDir="look";
			discreteDistance[]={100,200,300,400,500,700,1000,1600,2000,2400,2800};
			discreteDistanceCameraPoint[]=
			{
				"eye"
			};
			discreteDistanceInitIndex=5;
			//turretInfoType="RscWeaponRangeArtillery";
			gunnerForceOptics=0;
			//memoryPointGunnerOptics="eye";
			gunnerOpticsModel="\A3\Weapons_F\acc\reticle_Mortar_01_F.p3d";
			disableSoundAttenuation=1;
			*/

			class ViewOptics: ViewOptics
			{
				initAngleX=0;
				minAngleX=-30;
				maxAngleX=30;
				initAngleY=0;
				minAngleY=-100;
				maxAngleY=100;

				initFov=0.1;
				minFov=0.0125;
				maxFov=0.9;
				visionMode[]=
				{
					"Normal",
					"NVG"
				};
				
				minMoveX=0;
				maxMoveX=0;
				minMoveY=0;
				maxMoveY=0;
				minMoveZ=0;
				maxMoveZ=0;

				gunnerOpticsModel="\A3\Weapons_F\acc\reticle_mortar_01_f.p3d";
				gunnerOpticsEffect[]={};
			};
			class OpticsIn
			{
				class Wide
				{
					initAngleX=0;
					minAngleX=-30;
					maxAngleX=30;
					initAngleY=0;
					minAngleY=-100;
					maxAngleY=100;

					initFov=0.1;
					minFov=0.0125;
					maxFov=0.9;
					visionMode[]=
					{
						"Normal",
						"NVG"
					};
					
					minMoveX=0;
					maxMoveX=0;
					minMoveY=0;
					maxMoveY=0;
					minMoveZ=0;
					maxMoveZ=0;

					gunnerOpticsModel="\A3\Weapons_F\acc\reticle_mortar_01_f.p3d";
					gunnerOpticsEffect[]={};
				};
			};
		};
	};
};


class RC_60mm_ULM_Vic_Pre: RC_60mm_ULM_Base
{
	RC_BarrelAGL=0;			//AGL of barrel pivot point in meters, for estimating muzzle position, to increase accuracy
	RC_BarrelLenght=0.5;	//barrel lenght in meters, for estimating muzzle position, to increase accuracy
	RC_BarrelExtends=1;		//1 = true, if the barrel extends far past the vehicle, for estimating muzzle position, to increase accuracy;

	faction="RemoteControlled_B";
	editorSubcategory="RC_Mortar_subcat";
	author="Ascent";

	enableGPS=1;
	radartype=2;
	reportOwnPosition=1;
	receiveRemoteTargets=1;
	reportRemoteTargets=1;
	laserScanner=1;

	class Components
	{
		class SensorsManagerComponent
		{
			class Components
			{
				class LaserSensorComponent: SensorTemplateLaser
				{
					class AirTarget
					{
						minRange=3500;
						maxRange=3500;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=3500;
						maxRange=3500;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
				};
				class DataLinkSensorComponent: SensorTemplateDataLink
				{
					typeRecognitionDistance=6000;

					class AirTarget
					{
						minRange=6000;
						maxRange=6000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=6000;
						maxRange=6000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
				};
			};
		};
	};

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"

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
							range[]={3500,2000,1000};
							resource="RscCustomInfoSensors";
						};
					};
				};
				class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft
				{
					defaultDisplay="UAVFeedDisplay";

					class Components
					{
						class UAVFeedDisplay
						{
							componentType="UAVFeedDisplayComponent";
						};
						class VehicleMissileDisplay
						{
							componentType="TransportFeedDisplayComponent";
							source="Missile";
							resource="RscTransportCameraComponentMissile";
						};
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
};
class RC_60mm_ULM_Vic: RC_60mm_ULM_Vic_Pre
{
	class EventHandlers: EventHandlers
	{
		class RC_GuidedTriggerTime
		{
			#include "\Remote_Controlled_Artillery\includes_script\GuidedTriggerTimeEH.hpp"
		};
		class RM_ULM
		{
			getout="if (!local (_this select 0)) exitwith {}; _this call RC_ULM_fnc_getout";
			fired="if (!local (_this select 0)) exitwith {}; _this call RC_ULM_fnc_fire";
		};
	};

	scope=2;
	scopeCurator=2;
	
	displayName="60mm advanced Mortar";
	isULM=2; // 1 = display UI, 2 = display automatic gas vent UI, 45° always available
	RC_ArtyType=5; //1 = portable Mortar, 2 = vehicle Mortar, 3 = Howitzer, 4 = MLRS/MRL, 5 = NA for vanilla computer

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			weapons[]=
			{
				"RC_60mm_ULM_Weapon"
			};

			initElev=-44;	//804MIL on flat ground
		};
	};
};
class RC_60mm_ULM_Vic_attachable: RC_60mm_ULM_Vic
{
	class EventHandlers: EventHandlers
	{
		class RM_ULM
		{
			fired="if (!local (_this select 0)) exitwith {}; _this call RC_ULM_fnc_fire";
		};
	};

	displayName="RC 60mm advanced Mortar (attached)";
	scope=1;
	scopeCurator=1;

	crew="B_UAV_AI";
	textPlural="UGVs";
	textSingular="UGV";
	isUav=1;
	vehicleClass="Autonomous";
	uavCameraGunnerPos="eye";
	uavCameraGunnerDir="look";
	driverForceOptics=1;
};
class RC_60mm_ULM_Vic_old: RC_60mm_ULM_Vic_Pre
{
	class EventHandlers: EventHandlers
	{
		class RM_ULM
		{
			getout="if (!local (_this select 0)) exitwith {}; _this call RC_ULM_fnc_getout";
			fired="if (!local (_this select 0)) exitwith {}; _this call RC_ULM_fnc_fire_old";
		};
	};

	scope=1;
	scopeCurator=1;

	displayName="60mm advanced Mortar (old)";
	isULM=1; // 1 = display UI, 2 = display automatic gas vent UI, 45° always available
	RC_ArtyType=1; //1 = portable Mortar, 2 = vehicle Mortar, 3 = Howitzer, 4 = MLRS/MRL, 5 = NA for vanilla computer

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			weapons[]=
			{
				"RC_60mm_ULM_Weapon_old"
			};

			initElev=-30;
		};
	};
};