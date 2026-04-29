class GX_B_RQ11B_UAV;
class RC_FW_LM_MP_Fetch: GX_B_RQ11B_UAV
{
	class Components;
	class EventHandlers;

	scope=0;
	scopeCurator=0;
};
class RC_FW_LM_MP_Core: RC_FW_LM_MP_Fetch
{
	author="Ascent";	//all credits to the original maker, this is only an edit and soft-depends on the original mod
	faction="RemoteControlled_O";
	displayName="RC Loitering Munition";

	/*
	airFrictionCoefs0[] = {0.1,0.05,0.1};		//{0.1,0.1,0.1}
	airFrictionCoefs1[] = {0.112,0.019,0.0052};	//{0.112,0.038,0.0052}
	airFrictionCoefs2[] = {0.52,0.26,0.012};	//{0.52,0.51,0.012}
	*/
	airFrictionCoefs0[] = {0.1,0.1,0.1};		//{0.1,0.1,0.1}
	airFrictionCoefs1[] = {0.112,0.038,0.0052};	//{0.112,0.038,0.0052}
	airFrictionCoefs2[] = {0.52,0.51,0.012};	//{0.52,0.51,0.012}

	thrustCoef[] = {9.2,21.2,23.2,23.2,23.2,23.2,23.8,24.4,24.8,23.6,14.8,0.4,0.4,0.4,0.4,0.4};
	//thrustCoef[] = {4.6,10.6,11.6,11.6,11.6,11.6,11.9,12.2,12.4,11.8,7.4,0.2,0.2,0.2,0.2,0.2};
	//thrustCoef[] = {2.3,5.3,5.8,5.8,5.8,5.8,5.95,6.1,6.2,5.9,3.7,0.1,0.1,0.1,0.1,0.1};
	//rudderCoef[] = {0,0.6,1.5,1.6,1.7,1.7,1.7,1.7,1.7,1.7,1.7,0.9,0.9,0.9,0.7,0.5};

	//stallSpeed = ;		//
	//stallWarningTreshold = ;	//

	//bodyFrictionCoef=;	//NA
	maxSpeed=300;

	armor=2;	//needed for EH
	enableGPS=1;
	reportOwnPosition=1;
	receiveRemoteTargets=1;
	reportRemoteTargets=1;
	laserScanner=1;
	showAllTargets="2 + 4";

	weapons[]=
	{
		"RC_target_confirmer_AB_weapon",
		"RC_shapedcharge_reticle_AB_weapon"
	};
	magazines[]=
	{
		"RC_target_confirmer_AB_mag",
		"RC_shapedcharge_reticle_AB_mag"
	};

	class EventHandlers: EventHandlers
	{
		class RC_Warhead
		{
			init="(_this # 0) spawn RC_fnc_fpv_droneInit_MP;";
			fired="params ['_unit'];  if (local _unit) then { _unit spawn RC_fnc_fpv_detonate_MP };";
			handleDamage="params ['_unit', '_selection', '_damage'];  if (local _unit) then { if (_damage > 0.1) then {_unit spawn RC_fnc_fpv_detonate_MP }; };";
			//hit="_this call RC_fnc_fpv_onDestroy_MP";
		};
	};

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
					range[]={4000,2000,1000,500};
					resource="RscCustomInfoSensors";
				};
			};
		};
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
				class LaserSensorComponent: SensorTemplateLaser
				{
					angleRangeHorizontal=45;
					angleRangeVertical=45;
					animDirection="";	//aligned with body
					aimDown=0;	//-1

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
				class VisualSensorComponent: SensorTemplateVisual
				{
					typeRecognitionDistance=350;
					maxTrackableSpeed=600;
					nightRangeCoef=0.6;
					angleRangeHorizontal=45;
					angleRangeVertical=45;
					animDirection="";	//aligned with body
					aimDown=0;	//-1

					class AirTarget
					{
						minRange=500;
						maxRange=500;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=350;
						maxRange=350;
						objectDistanceLimitCoef=1;
						viewDistanceLimitCoef=1;
					};
				};
				class ManSensorComponent: SensorTemplateMan
				{
					typeRecognitionDistance=1;
					maxTrackableSpeed=15;
					nightRangeCoef=0.2;
					angleRangeHorizontal=45;
					angleRangeVertical=90;
					animDirection="";	//aligned with body
					aimDown=0;	//-1

					class AirTarget
					{
						minRange=60;
						maxRange=60;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=60;
						maxRange=60;
						objectDistanceLimitCoef=1;
						viewDistanceLimitCoef=1;
					};
				};
			};
		};
	};
};
class RC_FW_LM_MP_B: RC_FW_LM_MP_Core
{
	side=1;
	crew="B_UAV_AI";

	scope=2;
	scopeCurator=2;
};
class RC_FW_LM_MP_O: RC_FW_LM_MP_Core
{
	side=0;
	crew="O_UAV_AI";

	scope=2;
	scopeCurator=2;
};
class RC_FW_LM_MP_I: RC_FW_LM_MP_Core
{
	side=2;
	crew="I_UAV_AI";

	scope=2;
	scopeCurator=2;
};