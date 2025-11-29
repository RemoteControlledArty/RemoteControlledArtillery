class CfgPatches
{
	class RC_Crocus
	{
		name="improved Crocus FPV";
		author="Ascent";

		units[]=
		{
			"B_Crocus_MP",
			"O_Crocus_MP",
			"I_Crocus_MP",

			"B_Crocus_MP_Bag",
			"O_Crocus_MP_Bag",
			"I_Crocus_MP_Bag",

			"B_Crocus_MP_Sens",
			"O_Crocus_MP_Sens",
			"I_Crocus_MP_Sens",

			"B_Crocus_MP_Sens_Bag",
			"O_Crocus_MP_Sens_Bag",
			"I_Crocus_MP_Sens_Bag",

			"B_Crocus_MP_NV",
			"O_Crocus_MP_NV",
			"I_Crocus_MP_NV",

			"B_Crocus_MP_NV_Bag",
			"O_Crocus_MP_NV_Bag",
			"I_Crocus_MP_NV_Bag",

			"B_Crocus_MP_NV_Sens",
			"O_Crocus_MP_NV_Sens",
			"I_Crocus_MP_NV_Sens",

			"B_Crocus_MP_NV_Sens_Bag",
			"O_Crocus_MP_NV_Sens_Bag",
			"I_Crocus_MP_NV_Sens_Bag",

			"B_Crocus_SignalBooster_Bag",
			//"O_Crocus_SignalBooster_Bag",
			//"I_Crocus_SignalBooster_Bag",

			"RC_SignalBoosterLRR_blk",
			"RC_SignalBoosterLRR_mtp",
			"RC_SignalBoosterLRR_wdl",
			"RC_SignalBoosterLRR_tropic"
		};
		
		ammo[]=
		{
			"FPV_RPG42_AT_Penetrator_MP",
			"FPV_RPG42_MP",
			"RC_target_confirmer_AB_ammo",
			"RC_shapedcharge_reticle_AB_ammo",
			"RC_Crocus_Deployer_Ammo"
		};
		magazines[]=
		{
			"RC_target_confirmer_AB_mag",
			"RC_shapedcharge_reticle_AB_mag",
			"RC_6xCrocus_Deployer_Mag",
			"RC_8xCrocus_Deployer_Mag",
			"RC_6xCrocus_Deployer_UGV_Mag",
			"RC_8xCrocus_Deployer_UGV_Mag"
		};
		weapons[]=
		{
			"RC_target_confirmer_AB_weapon",
			"RC_shapedcharge_reticle_AB_weapon",
			"RC_Crocus_Deployer"
		};

		requiredAddons[]=
		{
			"cba_main",
			"ArmaFPV_Data",
			"RC_Artillery"
		};

		skipWhenMissingDependencies=1;
	};
};

class CfgFunctions
{
	class RC
	{
		class RC_Crocus
		{
            file="\RC_Crocus\functions";
			class fpv_handleConnect_MP {postInit=1;};
			class fpv_handleSignal_MP {};
			class fpv_getSignal_MP {};
			class fpv_createDialog_MP {};
			class fpv_droneInit_MP {};
			class fpv_onDestroy_MP {};
			class fpv_onSignalLost_MP {};

			class fpv_CarrierDeploy {};
			class fpv_CarrierDeployPvP {};
			class fpv_MothershipDeploy {};
		};
		class RC_Crocus_getSignalSub
		{
            file="\RC_Crocus\functions\getSignalSub";
			class fpv_evaluateTerrainImpact_MP {};
			class fpv_countInterferingObjects_MP {};
			class fpv_findRetranslatorsUAV_MP {};
			class fpv_findRetranslatorsUGV_MP {};
			class fpv_findRetranslatorsAntenna_MP {};
			class fpv_findRetranslatorsBackpack_MP {};
			class fpv_findJammers_MP {};
		};
	};
};

//later required sensors
class SensorTemplateIR;
class SensorTemplateNV;
class SensorTemplateVisual;
class SensorTemplateMan;
class SensorTemplateLaser;
class SensorTemplateDataLink;
class DefaultVehicleSystemsDisplayManagerLeft
{
	class components;
};
class DefaultVehicleSystemsDisplayManagerRight
{
	class components;
};

#include "\RC_Crocus\UI\ArmaFPV_interface.hpp"
#include "\RC_Crocus\cfgAmmoMagazinesWeapons\cfgAmmoMagazinesWeapons.hpp"

class CfgVehicles
{
	#include "\RC_Crocus\cfgVehicles\CrocusMP.hpp"
	#include "\RC_Crocus\cfgVehicles\CrocusMP_NV.hpp"
	#include "\RC_Crocus\cfgVehicles\SignalBooster.hpp"
	#include "\RC_Crocus\cfgVehicles\SignalBoosterBackpack.hpp"
};