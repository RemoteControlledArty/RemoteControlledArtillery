class RHS_MELB_AH6M;
class RC_MELB_AH6M_Core: RHS_MELB_AH6M
{
	class Turrets;
	class CopilotTurret;
	class OpticsIn;
	class Wide;
	class Components;
	class AnimationSources;
	class UserActions;
	scope=0;
	scopeCurator=0;
};
class RC_MELB_AH6M_Base: RC_MELB_AH6M_Core
{
	displayName="OM AH-6M";
	editorSubcategory="RC_Heli_subcat";

	driverCompartments="Compartment1";

	bodyFrictionCoef=0.2;
	maxSpeed=250;
	liftForceCoef=1.7;
	cyclicAsideForceCoef=2;
	cyclicForwardForceCoef=0.43000001;
	startDuration=7.5;				//10
	slingLoadMemoryPoint="slingLoad0";
	slingLoadMaxCargoMass=4000;		//900
	maximumLoad=1500;				//1000

	#include "\Remote_Controlled_Artillery\includes_cfg\MissleApproachWarning.hpp"
	lockDetectionSystem="2+4+8";	//4+8
	showAllTargets="2 + 4";
	receiveRemoteTargets=1;
	reportRemoteTargets=1;
	reportOwnPosition=1;
	allowTabLock=1;
	canUseScanner=1;
	gunnerCanFire=1;
	enableManualFire=1;

	crewCrashProtection=0.1;		//0.2
	ejectDeadCargo=1;
	hullDamageCauseExplosion=1;		//1
	hullExplosionDelay[]={10,20};	//{10,20}

	class UserActions: UserActions
	{
		class ResetCameraDir
		{
			displayName="Reset Camera Dir";
			position="pos driver";
			radius=1.5;
			showwindow=0;
			onlyforplayer=1;
			shortcut="";

			condition="(this isEqualTo vehicle player) && (currentPilot this isNotEqualTo player) && (!isRemoteControlling player)";
			statement="this lockCameraTo [this modelToWorld [0, 100, 90], [0], true]";
		};
	};

	#include "\Remote_Controlled_Artillery\MFD\MFD_merged.hpp"

	class Components: Components
	{
		class TransportPylonsComponent
		{
			UIPicture = "\rhsusf\addons\rhsusf_melb\data\loadouts\RHS_AH6M_EDEN_CA.paa";
			class pylons
			{
				class pylon1
				{
					hardpoints[]={"20MM_TWIN_CANNON","RHS_HP_MELB","RHS_HP_MELB_L"};
					priority=2;
					attachment="RC_PylonWeapon_300Rnd_20mm_shells_slow";
					maxweight=1200;
					UIposition[]={0.625,0.2};
					bay=-1;
					turret[]={0};
					hitpoint="HitPylon1";
				};
				class pylon2 : pylon1
				{
					hardpoints[]		= {"RHS_HP_MELB_M134"};
					UIposition[]		= {0.562,0.30};
					priority			= 1;
					attachment			= "rhs_mag_m134_pylon_3000";
					hitpoint 			= HitPylon2;
				};
				class pylon3 : pylon2
				{
					UIposition[]		= {0.103,0.30};
					mirroredMissilePos	= 2;
					attachment			= "rhs_mag_m134_pylon_3000";
					hitpoint 			= HitPylon3;
				};
				class pylon4 : pylon1
				{
					hardpoints[]		= {"RHS_HP_MELB","RHS_HP_MELB_R"};
					UIposition[]		= {0.04,0.20};
					//attachment			= "rhs_mag_M151_7";
					mirroredMissilePos	= 1;
					turret[]={};
					hitpoint 			= HitPylon4;
				};
			};

			class Presets
			{
				class Light
				{
					attachment[] =
					{
						"rhs_mag_M151_7",
						"rhs_mag_m134_pylon_3000",
						"rhs_mag_m134_pylon_3000",
						"rhs_mag_M151_7"
					};
					displayname = "Light";
				};
				class Medium
				{
					attachment[] =
					{
						"rhsusf_mag_gau19_melb_left",
						"",
						"",
						"rhs_mag_M151_19"
					};
					displayname = "Medium";
				};
				class Heavy
				{
					attachment[] =
					{
						"rhsusf_mag_gau19_melb_left",
						"",
						"",
						"rhs_mag_AGM114K_2"
					};
					displayname = "Heavy";
				};
			};
		};
	};

	memoryPointTaskMarker="TaskMarker_1_pos";
	memoryPointDriverOptics="commanderview";
	//memoryPointDriverOptics="Copilot_view_dir";
	//memoryPointDriverOptics="Slingload_cam";
	unitInfoType="RscOptics_AV_pilot";
	unitInfoTypeRTD="RscOptics_AV_pilot";

	driverOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_02_n_F.p3d";

	class pilotCamera
	{
		//turretInfoType="RscOptics_MBT_03_gunner";
		unitInfoType="RscOptics_AV_pilot";
		unitInfoTypeRTD="RscOptics_AV_pilot";

		class OpticsIn
		{
			class Wide
			{
				opticsDisplayName="W";
				initAngleX=0;
				minAngleX=0;
				maxAngleX=0;
				initAngleY=0;
				minAngleY=0;
				maxAngleY=0;
				minFov=0.025;
				maxFov=1.5;
				initFov=1.5;
				directionStabilized=0;
				//directionStabilized=1;
				visionMode[]=
				{
					"Normal",
					"NVG",
					"Ti"
				};
				thermalMode[]={0};
				gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_02_n_F.p3d";
			};
			showMiniMapInOptics=0;
			showUAVViewpInOptics=0;
			showSlingLoadManagerInOptics=1;
		};
		minTurn=0;
		maxTurn=0;
		initTurn=0;
		minElev=80;
		maxElev=80;
		initElev=80;
		maxXRotSpeed=0.5;
		maxYRotSpeed=0.5;
		pilotOpticsShowCursor=1;
		controllable=0;	//test 1
	};

	class AnimationSources: AnimationSources
	{
		class Addcrosshair
		{
			source="user";
			animPeriod=1;
			initPhase=0;
		};
	};

	class Turrets: Turrets
	{
		class CopilotTurret: CopilotTurret
		{
			dontCreateAI=1;

			//showHMD=0;
			primaryGunner=0;
			primaryObserver=1;
			gunnerCompartments="Compartment1";
			showAllTargets="2 + 4";

			//test values
			gunnerCanFire=1;
			enableManualFire=1;
			vehicleWeaponAccess=1;
			inGunnerMayFire = 1;
			canUseScanners=1;
			allowTabLock=1;	//0
			isCopilot=1;
			//gunnerUsesPilotView = 0;	//??? in Mi48

			stabilizedInAxes=3;

			/*
			weapons[]=
			{
				"RC_Twin_Cannon_20mm_gunpod_slow",
				"rhs_weap_laserDesignator_AI",
				"rhs_weap_fcs_ah64"
			};
			magazines[]=
			{
				"RC_PylonWeapon_300Rnd_20mm_shells_slow",
				"rhs_laserfcsmag",
				"rhs_LaserMag_ai"
			};
			*/

			/*
			body="obsTurret";
			gun="obsGun";
			animationSourceBody="obsTurret";
			animationSourceGun="obsGun";
			turretInfoType="Rsc_MELB_Turret_UnitInfo";
			stabilizedInAxes=3;
			memoryPointGunnerOptics="commanderview";
			minElev=-180;
			maxElev=180;
			initElev=0;
			minTurn=-180;
			maxTurn=180;
			initTurn=0;
			minFov=0.25;
			maxFov=0.89999998;
			initFov=0.75;
			lodTurnedOut=1100;
			lodTurned=1100;
			memoryPointsGetInGunner="pos gunner";
			memoryPointsGetInGunnerDir="pos gunner dir";
			memoryPointsGetInGunnerPrecise="pos gunner";
			gunBeg="commanderview";
			gunEnd="laserstart";
			memoryPointGun="commanderview";
			discretedistance[]={100,200,300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500,1600,1700,1800,1900,2000,2100,2200,2300,2400,2500,2600,2700,2800,2900,3000};
			discretedistanceinitindex=3;
			weapons[]=
			{
				"rhs_weap_laserDesignator_AI",
				"rhs_weap_fcs_ah64"
			};
			magazines[]=
			{
				"rhs_laserfcsmag",
				"rhs_LaserMag_ai"
			};
			soundServo[]=
			{
				"",
				0.0099999998,
				1,
				30
			};
			inGunnerMayFire=1;
			outGunnerMayFire=1;
			gunnerAction="MELB_Copilot";
			gunnerInAction="MELB_Copilot";
			usePreciseGetInAction=1;
			precisegetinout=0;
			gunnerGetInAction="Chopperlight_R_In_H";
			gunnergetOutAction="GetOutLow";
			gunnerOpticsModel="";
			TurretCanSee="1+2+4+8";
			gunnerHasFlares=1;
			usepip=1;
			*/

			/*
			class ViewGunner
			{
				minAngleX=-65;
				maxAngleX=85;
				initAngleX=0;
				minAngleY=-150;
				maxAngleY=150;
				initAngleY=0;
				minFov=0.25;
				maxFov=0.89999998;
				initFov=0.75;
			};
			*/

			class OpticsIn: OpticsIn
			{
				class Wide: Wide
				{
					initFov=1;	//0.9
					minFov=0.02;
					maxFov=1;	//0.9
					visionMode[]=
					{
						"Normal",
						"NVG",
						"Ti"
					};
					thermalMode[]={0};
					directionStabilized=1;
					horizontallyStabilized=1;

					/*
					opticsDisplayName="TRK COR";
					initAngleX=0;
					minAngleX=-360;
					maxAngleX=360;
					initAngleY=0;
					minAngleY=-15;
					maxAngleY=85;

					gunnerOpticsModel="rhsusf\addons\rhsusf_melb\data\optics\melb_flir_wf.p3d";
					opticsPPEffects[]=
					{
						"OpticsCHAbera3",
						"OpticsBlur3"
					};
					gunnerOpticsEffect[]=
					{
						"TankCommanderOptics2"
					};
					*/
				};
				/*
				class WideT: Wide
				{
					initFov=0.2;
					minFov=0.2;
					maxFov=0.2;
					gunnerOpticsModel="rhsusf\addons\rhsusf_melb\data\optics\melb_flir_w2.p3d";
				};
				*/
			};
		};
	};

	/*
	class Components: Components
	{
		class SensorsManagerComponent
		{
			class Components
			{
				class DataLinkSensorComponent: SensorTemplateDataLink
				{
				};
				class PassiveRadarSensorComponent: SensorTemplatePassiveRadar
				{
				};
				class LaserSensorComponent: SensorTemplateLaser
				{
				};
			};
		};
		class VehicleSystemsDisplayManagerComponentLeft: VehicleSystemsTemplateLeftPilot
		{
		};
		class VehicleSystemsDisplayManagerComponentRight: VehicleSystemsTemplateRightPilot
		{
		};
	};
	*/

	/*
	mainBladeRadius=4.3200002;
	tailBladeRadius=0.76999998;
	startDuration=10;

	//default
	slingLoadMaxCargoMass=900;
	liftForceCoef=1;
	cyclicAsideForceCoef=1.65;
	cyclicForwardForceCoef=0.40000001;
	backrotorforcecoef=0.89999998;
	bodyFrictionCoef=0.30000001;
	sensitivity=2.5;
	maximumLoad=1000;

	class Turrets: Turrets
	{
		class CopilotTurret: CopilotTurret
		{
			gunnerCompartments="Compartment1";
			body="obsTurret";
			gun="obsGun";
			animationSourceBody="obsTurret";
			animationSourceGun="obsGun";
			turretInfoType="Rsc_MELB_Turret_UnitInfo";
			stabilizedInAxes=3;
			memoryPointGunnerOptics="commanderview";
			minElev=-180;
			maxElev=180;
			initElev=0;
			minTurn=-180;
			maxTurn=180;
			initTurn=0;
			minFov=0.25;
			maxFov=0.89999998;
			initFov=0.75;
			lodTurnedOut=1100;
			lodTurned=1100;
			memoryPointsGetInGunner="pos gunner";
			memoryPointsGetInGunnerDir="pos gunner dir";
			memoryPointsGetInGunnerPrecise="pos gunner";
			gunBeg="commanderview";
			gunEnd="laserstart";
			memoryPointGun="commanderview";
			discretedistance[]={100,200,300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500,1600,1700,1800,1900,2000,2100,2200,2300,2400,2500,2600,2700,2800,2900,3000};
			discretedistanceinitindex=3;
			weapons[]=
			{
				"rhs_weap_laserDesignator_AI",
				"rhs_weap_fcs_ah64"
			};
			magazines[]=
			{
				"rhs_laserfcsmag",
				"rhs_LaserMag_ai"
			};
			soundServo[]=
			{
				"",
				0.0099999998,
				1,
				30
			};
			inGunnerMayFire=1;
			outGunnerMayFire=1;
			primaryGunner=1;
			gunnerAction="MELB_Copilot";
			gunnerInAction="MELB_Copilot";
			usePreciseGetInAction=1;
			precisegetinout=0;
			gunnerGetInAction="Chopperlight_R_In_H";
			gunnergetOutAction="GetOutLow";
			gunnerOpticsModel="";
			TurretCanSee="1+2+4+8";
			showAllTargets=1;
			gunnerHasFlares=1;
			usepip=1;
			canUseScanners=1;
			allowTabLock=0;
			class ViewGunner
			{
				minAngleX=-65;
				maxAngleX=85;
				initAngleX=0;
				minAngleY=-150;
				maxAngleY=150;
				initAngleY=0;
				minFov=0.25;
				maxFov=0.89999998;
				initFov=0.75;
			};
			class OpticsIn
			{
				class Wide
				{
					opticsDisplayName="TRK COR";
					initAngleX=0;
					minAngleX=-360;
					maxAngleX=360;
					initAngleY=0;
					minAngleY=-15;
					maxAngleY=85;
					initFov=0.30000001;
					minFov=0.30000001;
					maxFov=0.30000001;
					visionMode[]=
					{
						"Normal",
						"NVG",
						"Ti"
					};
					thermalMode[]={0};
					directionStabilized=1;
					horizontallyStabilized=1;
					gunnerOpticsModel="rhsusf\addons\rhsusf_melb\data\optics\melb_flir_wf.p3d";
					opticsPPEffects[]=
					{
						"OpticsCHAbera3",
						"OpticsBlur3"
					};
					gunnerOpticsEffect[]=
					{
						"TankCommanderOptics2"
					};
				};
				class WideT: Wide
				{
					initFov=0.2;
					minFov=0.2;
					maxFov=0.2;
					gunnerOpticsModel="rhsusf\addons\rhsusf_melb\data\optics\melb_flir_w2.p3d";
				};
				class MediumT: WideT
				{
					initFov=0.1;
					minFov=0.1;
					maxFov=0.1;
					gunnerOpticsModel="rhsusf\addons\rhsusf_melb\data\optics\melb_flir_m.p3d";
				};
				class NarrowT: WideT
				{
					initFov=0.022;
					minFov=0.022;
					maxFov=0.022;
					gunnerOpticsModel="rhsusf\addons\rhsusf_melb\data\optics\melb_flir_n.p3d";
				};
				class NarrowT2: WideT
				{
					initFov=0.0092000002;
					minFov=0.0092000002;
					maxFov=0.0092000002;
					gunnerOpticsModel="rhsusf\addons\rhsusf_melb\data\optics\melb_flir_n2.p3d";
				};
			};
			class Components
			{
				class VehicleSystemsDisplayManagerComponentLeft: VehicleSystemsTemplateLeftPilot
				{
				};
				class VehicleSystemsDisplayManagerComponentRight: VehicleSystemsTemplateRightPilot
				{
				};
			};
			class Hitpoints
			{
			};
		};
	};

	class UserActions
	{
		class MFD_Toggle
		{
			displayName="Toggle Monitor";
			onlyforplayer=1;
			position="doplnovani";
			radius=2;
			shortcut="LandGearUp";
			condition="((call rhsusf_fnc_findPlayer)==driver this) or ((call rhsusf_fnc_findPlayer)==gunner this) ";
			statement="call RHS_MELB_fnc_MFD_toggle";
			showWindow=0;
		};
		class SAFEMODE
		{
			displayName="<t color='#00FF7F'>MASTERSAFE</t>";
			condition="(call rhsusf_fnc_findPlayer) in this";
			statement="(call rhsusf_fnc_findPlayer) action ['SwitchWeapon', this, (call rhsusf_fnc_findPlayer), 0];";
			position="";
			radius=10;
			priority=10.5;
			onlyforplayer=1;
			showWindow=0;
			shortcut="user13";
			hideOnUse=1;
		};
	};

	class pilotCamera
	{
	};

	armor=35;
	armorStructural=20;
	epeImpulseDamageCoef=20;
	damageResistance=0.01039;
	class HitPoints: HitPoints
	{
		class HitFuel: HitFuel
		{
			armor=-130;
			armorComponent="fuel_hit";
			name="fuel_hit";
			visual="-";
			radius=0.125;
			minimalhit=-0.039999999;
			explosionShielding=0.5;
			passThrough=0;
		};
		class HitHull: HitHull
		{
			depends="HitEngine";
			simulation="RHS_Hull_Helicopter";
			armor=-120;
			minimalHit=-0.15000001;
			radius=0.02;
			name="hull_hit";
			armorComponent="hull_hit";
			visual="zbytek";
			passThrough=1;
			class DestructionEffects: RHS_Effects_Helicopter_Hull_Destruction
			{
			};
		};
		class HitEngine: HitEngine
		{
			armorComponent="engine_hit";
			name="engine_hit";
			armor=-120;
			visual="-";
			radius=0.15000001;
			explosionShielding=0.85000002;
			minimalhit=-0.050000001;
			passThrough=0.30000001;
		};
		class HitAvionics: HitAvionics
		{
			name="avionics_hit";
			armor=2;
			visual="-";
			radius=0.050000001;
			explosionShielding=0.5;
		};
		class HitVRotor: HitVRotor
		{
			visual="tail rotor static";
			armor=1;
			radius=0.050000001;
			explosionShielding=0.80000001;
		};
		class HitHRotor: HitHRotor
		{
			visual="main rotor static";
			armor=3;
			radius=0.2;
			explosionShielding=0.5;
		};
		class HitGlass1: HitGlass1
		{
			armor=2;
			radius=0.15000001;
			explosionShielding=2;
		};
		class HitGlass2: HitGlass2
		{
			armor=2;
			radius=0.15000001;
			explosionShielding=2;
		};
		class HitGlass3: HitGlass3
		{
			armor=2;
			radius=0.15000001;
			explosionShielding=2;
		};
		class HitGlass4: HitGlass4
		{
			armor=2;
			radius=0.15000001;
			explosionShielding=2;
		};
		class HitPylon1
		{
			armor=-30;
			name="hit_pylon_1";
			passThrough=0;
			minimalHit=-0.1;
			explosionShielding=0.1;
			radius=0.69999999;
			visual="-";
			class DestructionEffects
			{
				ammoExplosionEffect="";
				effectRadius=1;
				ignoreFuel=1;
				class RHS_Pylon_Flash
				{
					simulation="particles";
					type="RHS_ERA_Flash";
					position="fx_pylon_1";
					intensity=0.5;
					interval=1;
					lifeTime=0.0060000001;
				};
				class RHS_Pylon_Sound
				{
					simulation="sound";
					type="RHS_ERA_Explosion_Sound";
					position="fx_pylon_1";
					intensity=1;
					interval=1;
					lifeTime=1;
				};
				class RHS_Pylon_Smoke
				{
					simulation="particles";
					type="RHS_ERA_Smoke";
					position="fx_pylon_1";
					intensity=0.1;
					interval=1;
					lifeTime=0.039999999;
				};
				class RHS_Pylon_Shard
				{
					simulation="particles";
					type="RHS_ERA_Shard";
					position="fx_pylon_1";
					intensity=1;
					interval=1;
					lifeTime=0.029999999;
				};
			};
		};
		class HitPylon2
		{
			armor=-30;
			name="hit_pylon_2";
			passThrough=0;
			minimalHit=-0.1;
			explosionShielding=0.1;
			radius=0.69999999;
			visual="-";
			class DestructionEffects
			{
				ammoExplosionEffect="";
				effectRadius=1;
				ignoreFuel=1;
				class RHS_Pylon_Flash
				{
					simulation="particles";
					type="RHS_ERA_Flash";
					position="fx_pylon_2";
					intensity=0.5;
					interval=1;
					lifeTime=0.0060000001;
				};
				class RHS_Pylon_Sound
				{
					simulation="sound";
					type="RHS_ERA_Explosion_Sound";
					position="fx_pylon_2";
					intensity=1;
					interval=1;
					lifeTime=1;
				};
				class RHS_Pylon_Smoke
				{
					simulation="particles";
					type="RHS_ERA_Smoke";
					position="fx_pylon_2";
					intensity=0.1;
					interval=1;
					lifeTime=0.039999999;
				};
				class RHS_Pylon_Shard
				{
					simulation="particles";
					type="RHS_ERA_Shard";
					position="fx_pylon_2";
					intensity=1;
					interval=1;
					lifeTime=0.029999999;
				};
			};
		};
		class HitPylon3
		{
			armor=-30;
			name="hit_pylon_3";
			passThrough=0;
			minimalHit=-0.1;
			explosionShielding=0.1;
			radius=0.69999999;
			visual="-";
			class DestructionEffects
			{
				ammoExplosionEffect="";
				effectRadius=1;
				ignoreFuel=1;
				class RHS_Pylon_Flash
				{
					simulation="particles";
					type="RHS_ERA_Flash";
					position="fx_pylon_3";
					intensity=0.5;
					interval=1;
					lifeTime=0.0060000001;
				};
				class RHS_Pylon_Sound
				{
					simulation="sound";
					type="RHS_ERA_Explosion_Sound";
					position="fx_pylon_3";
					intensity=1;
					interval=1;
					lifeTime=1;
				};
				class RHS_Pylon_Smoke
				{
					simulation="particles";
					type="RHS_ERA_Smoke";
					position="fx_pylon_3";
					intensity=0.1;
					interval=1;
					lifeTime=0.039999999;
				};
				class RHS_Pylon_Shard
				{
					simulation="particles";
					type="RHS_ERA_Shard";
					position="fx_pylon_3";
					intensity=1;
					interval=1;
					lifeTime=0.029999999;
				};
			};
		};
		class HitPylon4
		{
			armor=-30;
			name="hit_pylon_4";
			passThrough=0;
			minimalHit=-0.1;
			explosionShielding=0.1;
			radius=0.69999999;
			visual="-";
			class DestructionEffects
			{
				ammoExplosionEffect="";
				effectRadius=1;
				ignoreFuel=1;
				class RHS_Pylon_Flash
				{
					simulation="particles";
					type="RHS_ERA_Flash";
					position="fx_pylon_4";
					intensity=0.5;
					interval=1;
					lifeTime=0.0060000001;
				};
				class RHS_Pylon_Sound
				{
					simulation="sound";
					type="RHS_ERA_Explosion_Sound";
					position="fx_pylon_4";
					intensity=1;
					interval=1;
					lifeTime=1;
				};
				class RHS_Pylon_Smoke
				{
					simulation="particles";
					type="RHS_ERA_Smoke";
					position="fx_pylon_4";
					intensity=0.1;
					interval=1;
					lifeTime=0.039999999;
				};
				class RHS_Pylon_Shard
				{
					simulation="particles";
					type="RHS_ERA_Shard";
					position="fx_pylon_4";
					intensity=1;
					interval=1;
					lifeTime=0.029999999;
				};
			};
		};
	};
	*/
};
class RC_MELB_AH6M_UV: RC_MELB_AH6M_Base
{
	isUav=1;
	vehicleClass="Autonomous";

	uavCameraDriverPos="commanderview";
	uavCameraDriverDir="commanderview";

	//driverForceOptics=1;					//OFF FOR MFD TESTING
	driverCompartments="Compartment0";
};
class RC_MELB_AH6M: RC_MELB_AH6M_UV
{
	scope=2;
	scopeCurator=2;
	forceInGarage=1;

	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideB.hpp"
};
class RC_MELB_AH6M_O: RC_MELB_AH6M
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideO.hpp"
};
class RC_MELB_AH6M_I: RC_MELB_AH6M
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideI.hpp"
};