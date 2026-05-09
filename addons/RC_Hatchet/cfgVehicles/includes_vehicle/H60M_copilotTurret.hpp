class CopilotTurret: CopilotTurret
{
	class Components
	{
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_panels.hpp"
	};
	
	dontCreateAI=1;
	CanEject=1;

	primaryGunner=0;
	primaryObserver=1;	//test 0, but center cam uses if commander condition
	gunnerCompartments="Compartment1";
	showAllTargets="2 + 4";
	canUseScanners=1;
	stabilizedInAxes=3;


	//test values
	//showHMD=0;
	gunnerCanFire=1;
	enableManualFire=1;
	vehicleWeaponAccess=1;
	inGunnerMayFire=1;
	allowTabLock=1;	//0
	isCopilot=1;
	//gunnerUsesPilotView=0;	//??? in Mi48


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

			gunnerOpticsModel="rhsusf\addons\rhsusf_melb\data\optics\melb_flir_m.p3d";

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
	};
};


/*
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