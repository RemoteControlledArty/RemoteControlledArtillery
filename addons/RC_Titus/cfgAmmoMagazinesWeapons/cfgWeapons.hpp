class RC_autocannon_20mm_CTWS;
class RC_Titus_autocannon_20mm: RC_autocannon_20mm_CTWS
{
	muzzlePos="usti hlavne";
	muzzleEnd="konec hlavne";
	selectionFireAnim="zasleh";
};


class QIN_M240C;
class RC_QIN_MG_Base: QIN_M240C
{
	class manual;
	canLock=2;
	autoReload=1;
	#include "\Remote_Controlled_Artillery\includes_cfg\BallisticsCalculatorMG.hpp"
};
class RC_QIN_HMG: RC_QIN_MG_Base
{
	displayName="12.7mm HMG";
	magazineReloadTime=15;
	maxZeroing=3000;

	magazines[]=
	{
		"RC_200Rnd_127x99_T_R",
		"RC_200Rnd_127x99_T_G",
		"RC_200Rnd_127x99_T_Y",
		"RC_200Rnd_127x99_SLAP_T_R",
		"RC_200Rnd_127x99_SLAP_T_G",
		"RC_200Rnd_127x99_SLAP_T_Y",

		"RC_150Rnd_127x99_T_R",
		"RC_150Rnd_127x99_T_G",
		"RC_150Rnd_127x99_T_Y",
		"RC_150Rnd_127x99_SLAP_T_R",
		"RC_150Rnd_127x99_SLAP_T_G",
		"RC_150Rnd_127x99_SLAP_T_Y"
	};
	class manual: manual
	{
		dispersion=0.001;
		reloadTime=0.11;
	};

	muzzlePos="usti hlavne";
	muzzleEnd="konec hlavne";
	selectionFireAnim="zasleh";

	class GunParticles
	{
		class Effect
		{
			effectName="MachineGun1";
			positionName="Usti hlavne";
			directionName="Konec hlavne";
		};
	};
};

class RC_QIN_338_MMG1: RC_QIN_MG_Base
{
	displayName=".338 NM MMG";
	magazineReloadTime=10;
	maxZeroing=2000;
	magazines[]=
	{
		"RC_150Rnd_338_T_R",
		"RC_150Rnd_338_T_G",
		"RC_150Rnd_338_T_Y"
	};
	class manual: manual
	{
		reloadTime=0.0857;
	};

	muzzlePos="usti hlavne";
	muzzleEnd="konec hlavne";
	selectionFireAnim="zasleh";

	class GunParticles
	{
		class Effect
		{
			effectName="MachineGun1";
			positionName="Usti hlavne";
			directionName="Konec hlavne";
		};
	};
};


class RC_QIN_338_MMG2: RC_QIN_MG_Base
{
	displayName=".338 NM MMG";
	maxZeroing=2000;
	magazines[]=
	{
		"RC_200Rnd_338_T_R",
		"RC_200Rnd_338_T_G",
		"RC_200Rnd_338_T_Y",

		"RC_150Rnd_338_T_R",
		"RC_150Rnd_338_T_G",
		"RC_150Rnd_338_T_Y"
	};
};


class RC_QIN_762_MMG: RC_QIN_MG_Base
{
	displayName="7.62mm MMG";
	magazineReloadTime=10;

	magazines[]=
	{
		"RC_200Rnd_762x51_T_R",
		"RC_200Rnd_762x51_T_G",
		"RC_200Rnd_762x51_T_Y",

		"RC_150Rnd_762x51_T_R",
		"RC_150Rnd_762x51_T_G",
		"RC_150Rnd_762x51_T_Y"
	};
};