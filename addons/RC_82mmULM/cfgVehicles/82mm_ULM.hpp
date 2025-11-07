class RC_Mortar_Base;
class RC_82mm_ULM_Vic_Core: RC_Mortar_Base
{
	class Turrets;
	class MainTurret;
	class ViewOptics;
	//class Components;
	class EventHandlers;
};

//needs to be build from ground up not dependant on ace modified Mk6, and no backpack model is available
//UXO item models and pictures could be used for shells

class RC_82mm_ULM_Vic: RC_82mm_ULM_Vic_Core
{
	class EventHandlers: EventHandlers
	{
		class RM_ULM
		{
			getout="if (!local (_this select 0)) exitwith {}; _this call RC_82mmULM_fnc_getout_82mm";
			fired="if (!local (_this select 0)) exitwith {}; _this call RC_82mmULM_fnc_fire_82mm";
		};
	};

	side=0;

	scope=2;
	scopeCurator=2;
	
	displayName="82mm advanced Mortar";
	isULM=2; // 1 = display UI, 2 = display automatic gas vent UI, 45° always available
	RC_ArtyType=5; //1 = portable Mortar, 2 = vehicle Mortar, 3 = Howitzer, 4 = MLRS/MRL, 5 = NA for vanilla computer

	class assembleInfo
	{
		assembleTo="";
		base="";
		displayName="";
		dissasembleTo[]={};
		primary=0;
	};

	/*
	class Components: Components
	{
		class SensorsManagerComponent
		{
			class Components
			{
				class LaserSensorComponent: SensorTemplateLaser
				{
					class AirTarget
					{
						minRange=3000;
						maxRange=3000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=3000;
						maxRange=3000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
				};
				class DataLinkSensorComponent: SensorTemplateDataLink
				{
					typeRecognitionDistance=5000;

					class AirTarget
					{
						minRange=5000;
						maxRange=5000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=5000;
						maxRange=5000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
				};
			};
		};
	};
	*/

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			turretInfoType="Rsc_ULM";
			//maxCamElev=45;
			initCamElev=0;
			minCamElev=-5;
			initElev=-29.75;	//804MIL on flat ground
			//maxelev=89;
			minelev=-35;	//<800MIL for use on uneven ground

			weapons[]=
			{
				"RC_82mm_ULM_Weapon"
			};
			magazines[]={};

			class ViewOptics: ViewOptics
			{
				initFov=0.1;
				minFov=0.0125;
				maxFov=0.9;
			};

			/*
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
							range[]={4000,2000,1000};
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
			*/
		};
	};
};