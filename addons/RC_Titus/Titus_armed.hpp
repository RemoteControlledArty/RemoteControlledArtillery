class QIN_Titus_arx20_DES;
class RC_Titus_AC_base: QIN_Titus_arx20_DES
{
	class ARX20Turret;

	class Turrets;
	class ViewOptics;
	class ViewGunner;
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
class RC_Titus_AC_D: RC_Titus_AC_base
{
	#include "\RC_Titus\Titus_include.hpp"

	class EventHandlers: EventHandlers
	{
		#include "\Remote_Controlled_Artillery\includes\initICV.hpp"
		#include "\Remote_Controlled_Artillery\includes\DriverControlsEH_ICV.hpp"
	};

	displayName="RC Titus 20mm";
	editorSubcategory="RC_Titus_subcat";
	scope=2;
	scopeCurator=2;
	forceInGarage=1;
	uavCameraGunnerPos="PiP1_pos";
	uavCameraGunnerDir="PiP1_dir";

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
		};
		class ARX20Turret: ARX20Turret
		{
			primaryGunner=0;
			primaryObserver=1;

			class ViewOptics: ViewOptics
			{
				minFov=0.025;
				maxFov=0.9;
				initFov=0.9;
				visionMode[]=
				{
					"Normal",
					"NVG",
					"TI"
				};
				thermalMode[]={0};
			};

			weapons[]=
			{
				"RC_QIN_20mm_AC",
				"RC_QIN_338_MMG2",
				"SmokeLauncher"
			};
			magazines[]=
			{
				"RC_QIN_100Rnd_20mm_T_R",
				"RC_QIN_100Rnd_20mm_T_R",
				"RC_QIN_100Rnd_20mm_T_R",
				"RC_QIN_150Rnd_338_T_R",
				"RC_QIN_150Rnd_338_T_R",
				"RC_QIN_150Rnd_338_T_R",
				"RC_QIN_150Rnd_338_T_R",
				"SmokeLauncherMag",
				"SmokeLauncherMag"
			};

			/*
			class ViewGunner: ViewGunner
			{
				minFov=0.25;
				maxFov=1.25;
				initFov=0.75;
				visionMode[]=
				{
					"Normal",
					"NVG",
					"TI"
				};
				thermalMode[]={0};
			};
			*/
		};

		class CargoTurret_01: CargoTurret_01 {};
		class CargoTurret_02: CargoTurret_02 {};
	};
};
class RC_Titus_AC_WD: RC_Titus_AC_D
{
	editorPreview="qin_titus\data\preview\titus_arx20_wdl.jpg";
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
class RC_Titus_AC_A: RC_Titus_AC_D
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


class RC_Titus_MMG_D: RC_Titus_AC_D
{
	displayName="RC Titus MMG";

	class Turrets: Turrets
	{
		class ARX20Turret: ARX20Turret
		{
			weapons[]=
			{
				"RC_QIN_338_MMG1",
				"SmokeLauncher"
			};
			magazines[]=
			{
				"RC_QIN_150Rnd_338_T_R",
				"RC_QIN_150Rnd_338_T_R",
				"RC_QIN_150Rnd_338_T_R",
				"RC_QIN_150Rnd_338_T_R",
				"RC_QIN_150Rnd_338_T_R",
				"SmokeLauncherMag",
				"SmokeLauncherMag"
			};
		};
	};
};
class RC_Titus_MMG_WD: RC_Titus_MMG_D
{
	editorPreview="qin_titus\data\preview\titus_arx20_wdl.jpg";
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
class RC_Titus_MMG_A: RC_Titus_MMG_D
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