class CopilotTurret: CopilotTurret
{
	class Components
	{
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_panels.hpp"
	};

	dontCreateAI=1;
	gunnerCompartments="Compartment1";	//3
	showAllTargets="2 + 4";
	canUseScanners=1;
	canEject=1;	//0
	allowTabLock=1;

	isCopilot=1;
	gunnerName="Copilot";
	usePiP=1;
	inGunnerMayFire=1;

	weapons[]=
	{
		"Laserdesignator_pilotCamera"
	};
	magazines[]=
	{
		"Laserbatteries"
	};

	/*
	gunnerCanFire=1;
	enableManualFire=1;
	vehicleWeaponAccess=1;
	*/

	memoryPointGunnerOptics="pos pilot";
	gunBeg="pos pilot";
	gunEnd="laserstart";
	memoryPointGun="laserstart";
	body="obsTurret";
	gun="obsGun";
	animationSourceBody="obsTurret";
	animationSourceGun="obsGun";

	gunnerAction="copilot_Heli_Light_03";
	gunnerInAction="copilot_Heli_Light_03";
	precisegetinout=1;
	gunnerGetInAction="copilot_Heli_Light_03_Enter";
	gunnerGetOutAction="copilot_Heli_Light_03_Exit";
	gunnerOpticsEffect[]={};
	gunnerOpticsModel="";
	gunnerLeftHandAnimName="lever_copilot";
	gunnerRightHandAnimName="stick_copilot";
	gunnerLeftLegAnimName="pedalL";
	gunnerRightLegAnimName="pedalR";

	turretInfoType="RscOptics_Heli_Attack_01_gunner";
	stabilizedInAxes=3;
	primaryGunner=0;
	minElev=-60;
	maxElev=20;
	initElev=0;
	minTurn=-120;
	maxTurn=120;
	initTurn=0;
	soundServo[]=
	{
		"",
		0.0099999998,
		1,
		30
	};

	class OpticsIn: OpticsIn
	{
		class Wide: Wide
		{
			initAngleX=0;
			minAngleX=-30;
			maxAngleX=30;
			initAngleY=0;
			minAngleY=-100;
			maxAngleY=100;

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
			gunnerOpticsModel="A3\drones_f\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_wide_F.p3d";
		};
	};

	/*
	class OpticsOut
	{
		class Monocular
		{
			initAngleX=0;
			minAngleX=-30;
			maxAngleX=30;
			initAngleY=0;
			minAngleY=-100;
			maxAngleY=100;
			minFov=0.25;
			maxFov=1.25;
			initFov=0.75;
			visionMode[]=
			{
				"Normal",
				"NVG"
			};
			gunnerOpticsModel="";
			gunnerOpticsEffect[]={};
		};
	};
	class ViewGunner: ViewPilot
	{
		initAngleX=-15;
	};
	startEngine=0;
	gunnerHasFlares=0;
	*/

	/*
	class HitPoints
	{
		class HitTurret
		{
			armor=1;
			material=-1;
			name="main_turret_hit";
			visual="gun";
			passThrough=0.2;
			radius=0.25;
		};
		class HitGun
		{
			armor=1;
			material=-1;
			name="main_gun_hit";
			visual="gun";
			passThrough=0.2;
			radius=0.25;
		};
	};
	*/
};


/*
class CopilotTurret: CopilotTurret
{
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
		};
	};
};
*/