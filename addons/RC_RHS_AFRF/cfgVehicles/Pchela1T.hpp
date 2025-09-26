/*
class Air;
class Plane: Air
{
	class HitPoints;
	class EventHandlers;
};
class UAV: Plane
{
	class NewTurret;
	class ViewPilot;
	class ViewOptics;
	class AnimationSources;
};
class UAV_02_base_F: UAV
{
	class EventHandlers;
};
*/
class UAV_02_base_F;
class rhs_pchela1t_core: UAV_02_base_F
{
	class HitPoints;
	class EventHandlers;
	class NewTurret;
	class ViewPilot;
	class ViewOptics;
	class AnimationSources;
	class Components;
};
class rhs_pchela1t_base: rhs_pchela1t_core
{
	RC_Local=1; //1 = requires transfer of locality/ownership for full functionality
	//camouflage=0.25;
	//radarTargetSize=0.05;
	//visualTargetSize=0.05;
	radartype=2;
	reportOwnPosition=1;
	receiveRemoteTargets=1;
	reportRemoteTargets=1;
	laserScanner=1;

	#include "\RC_RHS_AFRF\includes_cfg\Pchela1T_MainInclude.hpp"
	
	class Turrets
	{
		class MainTurret: NewTurret
		{
			//edits
			#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"
			enableManualFire=0;

			weapons[]=
			{
				"Laserdesignator_mounted"
			};
			magazines[]=
			{
				"Laserbatteries"
			};
			//gunnerInAction="Disabled";
			//gunnerAction="Disabled";

			class Components: Components
			{
				class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight
				{
					defaultDisplay="SensorDisplay";
					class components
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
					defaultDisplay="SensorDisplay";
					class components
					{
						class SensorDisplay
						{
							componentType="SensorsDisplayComponent";
							range[]={1000,2000,4000};
							resource="RscCustomInfoSensors";
						};
						class MinimapDisplay
						{
							componentType="MinimapDisplayComponent";
							resource="RscCustomInfoAirborneMiniMap";
						};
					};
				};
			};

			#include "\RC_RHS_AFRF\includes_cfg\Pchela1T_TurretInclude.hpp"
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
					typeRecognitionDistance=40000;

					class AirTarget
					{
						minRange=40000;
						maxRange=40000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=40000;
						maxRange=40000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};

					//animDirection="Optics_gun";
				};
				class IRSensorComponent: SensorTemplateIR
				{
					class AirTarget
					{
						minRange=500;
						maxRange=3000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=1;
					};
					class GroundTarget
					{
						minRange=500;
						maxRange=2500;
						objectDistanceLimitCoef=1;
						viewDistanceLimitCoef=1;
					};
					maxTrackableSpeed=50;
					angleRangeHorizontal=51;
					angleRangeVertical=37;
					animDirection="Optics_gun";
					aimDown=-0.5;
				};
				class VisualSensorComponent: SensorTemplateVisual
				{
					class AirTarget
					{
						minRange=500;
						maxRange=3000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=1;
					};
					class GroundTarget
					{
						minRange=500;
						maxRange=2500;
						objectDistanceLimitCoef=1;
						viewDistanceLimitCoef=1;
					};
					maxTrackableSpeed=50;
					angleRangeHorizontal=51;
					angleRangeVertical=37;
					animDirection="Optics_gun";
					aimDown=-0.5;
				};
				class PassiveRadarSensorComponent: SensorTemplatePassiveRadar
				{
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

					//animDirection="Optics_gun";
				};
				class LaserSensorComponent: SensorTemplateLaser
				{
					angleRangeHorizontal=360;
					angleRangeVertical=360;
					//animDirection="Optics_gun";
				};
				class NVSensorComponent: SensorTemplateNV
				{
					//animDirection="Optics_gun";
				};
			};
		};
	};
};
class rhs_pchela1t_vvs: rhs_pchela1t_base
{
	editorPreview="rhsafrf\addons\rhs_editorPreviews\data\rhs_pchela1t_vvs.paa";
	scope=2;
	author="$STR_RHS_AUTHOR_FULL";
	hiddenSelectionsTextures[]=
	{
		"\rhsafrf\addons\rhs_a2port_air\PCHELA1T\data\pchela1tblu_co.paa"
	};
};
class rhs_pchela1t_vvsc: rhs_pchela1t_base
{
	editorPreview="rhsafrf\addons\rhs_editorPreviews\data\rhs_pchela1t_vvsc.paa";
	scope=2;
	author="$STR_RHS_AUTHOR_FULL";
	faction="rhs_faction_vvs_c";
};