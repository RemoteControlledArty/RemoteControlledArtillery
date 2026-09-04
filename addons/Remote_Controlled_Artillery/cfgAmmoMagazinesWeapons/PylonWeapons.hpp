//minigun
class M134_minigun;
class RC_PylonW_338_Minigun_Fetch: M134_minigun
{
	class HighROF;
};
class RC_PylonW_338_Minigun_Base: RC_PylonW_338_Minigun_Fetch
{
	displayName=".338NM Minigun";
	displayNameShort=".338NM Minigun";
	ballisticsComputer=8;
	allowTabLock=1;
	canLock=2;

	magazines[]=
	{
		"RC_PylonM_2500Rnd_338_SLAP_T_R_right",
		"RC_PylonM_2500Rnd_338_SLAP_T_G_right",
		"RC_PylonM_2500Rnd_338_SLAP_T_Y_right",

		"RC_PylonM_5000Rnd_338_SLAP_T_R_right",
		"RC_PylonM_5000Rnd_338_SLAP_T_G_right",
		"RC_PylonM_5000Rnd_338_SLAP_T_Y_right",

		"RC_AI_PylonM_2500Rnd_338_SLAP_T_R_right",
		"RC_AI_PylonM_2500Rnd_338_SLAP_T_G_right",
		"RC_AI_PylonM_2500Rnd_338_SLAP_T_Y_right",

		"RC_AI_PylonM_5000Rnd_338_SLAP_T_R_right",
		"RC_AI_PylonM_5000Rnd_338_SLAP_T_G_right",
		"RC_AI_PylonM_5000Rnd_338_SLAP_T_Y_right"
	};
	modes[]=
	{
		"HighROF","close","short","medium","far"
	};
	class HighROF: HighROF
	{
		displayName=".338NM";
		displayNameShort=".338NM";
		reloadTime=0.015;	//0.02 = 3000RPM, 0.015 = 4000RPM
		dispersion=0.005;	//0.0064
	};
};
class RC_PylonW_338_Minigun: RC_PylonW_338_Minigun_Base
{
};


class Gatling_127mm_HeliPylon_F;
class RC_PylonW_127mm_Minigun_Fetch: Gatling_127mm_HeliPylon_F
{
	class LowROF;
};
class RC_PylonW_127mm_Minigun_Base: RC_PylonW_127mm_Minigun_Fetch
{
	displayName="12.7mm Minigun";
	displayNameShort="12.7mm Minigun";
	ballisticsComputer=8;
	allowTabLock=1;
	canLock=2;

	magazines[]=
	{
		"RC_PylonM_1000Rnd_127mm_SLAP_T_R_left",
		"RC_PylonM_1000Rnd_127mm_SLAP_T_G_left",
		"RC_PylonM_1000Rnd_127mm_SLAP_T_Y_left",

		"RC_PylonM_1000Rnd_127mm_SLAP_T_R_right",
		"RC_PylonM_1000Rnd_127mm_SLAP_T_G_right",
		"RC_PylonM_1000Rnd_127mm_SLAP_T_Y_right",

        "RC_AI_PylonM_1000Rnd_127mm_SLAP_T_R_left",
		"RC_AI_PylonM_1000Rnd_127mm_SLAP_T_G_left",
		"RC_AI_PylonM_1000Rnd_127mm_SLAP_T_Y_left",

		"RC_AI_PylonM_1000Rnd_127mm_SLAP_T_R_right",
		"RC_AI_PylonM_1000Rnd_127mm_SLAP_T_G_right",
		"RC_AI_PylonM_1000Rnd_127mm_SLAP_T_Y_right"
	};
	modes[]=
	{
		"LowROF","close","short","medium","far"
	};
	class LowROF: LowROF
	{
		ballisticsComputer="8";
		displayName="12.7mm";
		displayNameShort="12.7mm";
		reloadTime=0.03;	//0.04 = 1500RPM, 0.03 = 2000RPM
		dispersion=0.005;	//0.003
		burst=4;			//5
	};
};
class RC_PylonW_127mm_Minigun: RC_PylonW_127mm_Minigun_Base
{
};


//HMG
class Twin_Cannon_20mm_gunpod;
class RC_PylonW_Twin_Fetch: Twin_Cannon_20mm_gunpod
{
	class manual;
	class close;
	class short;
	class medium;
	class far;
};
class RC_PylonW_Twin_Core: RC_PylonW_Twin_Fetch
{
	allowTabLock=1;
	canLock=2;
	weaponLockDelay=0;
	weaponLockSystem=0;
	lockAcquire=0;						//manual
	ballisticsComputer="8";				//4+8, test 1 more
	
	/*
	showAimCursorInternal=0;
	nameSound="cannon";
	cursor="EmptyCursor";
	cursorAim="mg";
	*/

	modes[]=
	{
		"manual","close","short","medium","far"
	};
	class manual: manual
	{
		ballisticsComputer="8";			//4+8, test 1 more

		allowTabLock=1;
		canLock=2;
		weaponLockDelay=0;
		burst=2;						//5
		autoFire=1;
		textureType="fullAuto";
	};
	class close: close
	{
		ballisticsComputer="8";
		allowTabLock=1;
	};
	class short: short
	{
		ballisticsComputer="8";
		allowTabLock=1;
	};
	class medium: medium
	{
		ballisticsComputer="8";
		allowTabLock=1;
	};
	class far: far
	{
		ballisticsComputer="8";
		allowTabLock=1;
	};
};
class RC_PylonW_TwinHMG_Base: RC_PylonW_Twin_Core
{
	displayName="Twin HMG";
	displayNameShort="Twin HMG";

	magazines[]=
	{
		"RC_PylonM_Twin_1000Rnd_127mm_SLAP_T_R",
		"RC_PylonM_Twin_1000Rnd_127mm_SLAP_T_G",
		"RC_PylonM_Twin_1000Rnd_127mm_SLAP_T_Y",

        "RC_AI_PylonM_Twin_1000Rnd_127mm_SLAP_T_R",
		"RC_AI_PylonM_Twin_1000Rnd_127mm_SLAP_T_G",
		"RC_AI_PylonM_Twin_1000Rnd_127mm_SLAP_T_Y"
	};
	class manual: manual
	{
		#include "\Remote_Controlled_Artillery\includes_cfg\PylonHMG.hpp"
		burst=4;
	};
	class close: close
	{
		#include "\Remote_Controlled_Artillery\includes_cfg\PylonHMG.hpp"
	};
	class short: short
	{
		#include "\Remote_Controlled_Artillery\includes_cfg\PylonHMG.hpp"
	};
	class medium: medium
	{
		#include "\Remote_Controlled_Artillery\includes_cfg\PylonHMG.hpp"
	};
	class far: far
	{
		#include "\Remote_Controlled_Artillery\includes_cfg\PylonHMG.hpp"
	};
};
class RC_PylonW_TwinHMG: RC_PylonW_TwinHMG_Base
{
};


//autocannon
class RC_PylonW_TwinCannon_Base: RC_PylonW_Twin_Core
{
	displayName="Autocannon";
	displayNameShort="Autocannon";

	magazines[]=
	{
		//"RC_PylonM_300Rnd_20mm_Aegis",
		"RC_PylonM_350Rnd_20mm",
		"RC_PylonM_350Rnd_20mm_Proxy",
		"RC_PylonM_300Rnd_25mm",
		"RC_PylonM_300Rnd_25mm_Proxy",
		"RC_PylonM_250Rnd_30mm",
		"RC_PylonM_250Rnd_30mm_Proxy",

		"RC_PylonM_175Rnd_20mm",
		"RC_PylonM_175Rnd_20mm_Proxy",
		"RC_PylonM_150Rnd_25mm",
		"RC_PylonM_150Rnd_25mm_Proxy",
		"RC_PylonM_125Rnd_30mm",
		"RC_PylonM_125Rnd_30mm_Proxy",

        "RC_AI_PylonM_250Rnd_30mm",
		"RC_AI_PylonM_250Rnd_30mm_Proxy",
		"RC_AI_PylonM_125Rnd_30mm",
		"RC_AI_PylonM_125Rnd_30mm_Proxy"
	};
	class manual: manual
	{
		#include "\Remote_Controlled_Artillery\includes_cfg\PylonAutocannon.hpp"
		burst=2;
	};
	class close: close
	{
		#include "\Remote_Controlled_Artillery\includes_cfg\PylonAutocannon.hpp"
	};
	class short: short
	{
		#include "\Remote_Controlled_Artillery\includes_cfg\PylonAutocannon.hpp"
	};
	class medium: medium
	{
		#include "\Remote_Controlled_Artillery\includes_cfg\PylonAutocannon.hpp"
	};
	class far: far
	{
		#include "\Remote_Controlled_Artillery\includes_cfg\PylonAutocannon.hpp"
	};
};
class RC_PylonW_TwinCannon: RC_PylonW_TwinCannon_Base
{
};
class RC_PylonW_TwinCannon_Lead_Base: RC_PylonW_TwinCannon_Base
{
	displayName="Lead Autocannon";
	displayNameShort="Lead Autocannon";
	ballisticsComputer="4+8";	//projected reticle on ground if not locked & lead indicator if locked
	magazines[]=
	{
		"RC_PylonM_350Rnd_20mm_Lead",
		"RC_PylonM_250Rnd_20mm_Proxy_Lead",
		"RC_PylonM_300Rnd_25mm_Lead",
		"RC_PylonM_250Rnd_25mm_Proxy_Lead",
		"RC_PylonM_250Rnd_30mm_Lead",
		"RC_PylonM_250Rnd_30mm_Proxy_Lead",

		"RC_PylonM_175Rnd_20mm_Lead",
		"RC_PylonM_175Rnd_20mm_Proxy_Lead",
		"RC_PylonM_150Rnd_25mm_Lead",
		"RC_PylonM_150Rnd_25mm_Proxy_Lead",
		"RC_PylonM_125Rnd_30mm_Lead",
		"RC_PylonM_125Rnd_30mm_Proxy_Lead",

        "RC_AI_PylonM_250Rnd_30mm_Lead",
		"RC_AI_PylonM_250Rnd_30mm_Proxy_Lead",
		"RC_AI_PylonM_125Rnd_30mm_Lead",
		"RC_AI_PylonM_125Rnd_30mm_Proxy_Lead"
	};
};
class RC_PylonW_TwinCannon_Lead: RC_PylonW_TwinCannon_Lead_Base
{
};


class RC_PylonW_Avtopushka_Base: RC_PylonW_TwinCannon_Base
{
	displayName="Avtopushka";
	displayNameShort="Avtopushka";

	magazines[]=
	{
		"RC_PylonM_350Rnd_20mm_O",
		"RC_PylonM_350Rnd_20mm_Proxy_O",
		"RC_PylonM_300Rnd_25mm_O",
		"RC_PylonM_300Rnd_25mm_Proxy_O",
		"RC_PylonM_250Rnd_30mm_O",
		"RC_PylonM_250Rnd_30mm_Proxy_O",

		"RC_PylonM_175Rnd_20mm_O",
		"RC_PylonM_175Rnd_20mm_Proxy_O",
		"RC_PylonM_150Rnd_25mm_O",
		"RC_PylonM_150Rnd_25mm_Proxy_O",
		"RC_PylonM_125Rnd_30mm_O",
		"RC_PylonM_125Rnd_30mm_Proxy_O",
		
		"RC_AI_PylonM_250Rnd_30mm_O",
		"RC_AI_PylonM_250Rnd_30mm_Proxy_O",
		"RC_AI_PylonM_125Rnd_30mm_O",
		"RC_AI_PylonM_125Rnd_30mm_Proxy_O"
	};
	class manual: manual
	{
		displayName="Avtopushka";
		displayNameShort="Avtopushka";
	};
};
class RC_PylonW_Avtopushka: RC_PylonW_Avtopushka_Base
{
};
class RC_PylonW_Avtopushka_Lead_Base: RC_PylonW_Avtopushka_Base
{
	displayName="Lead Avtopushka";
	displayNameShort="Lead Avtopushka";
	ballisticsComputer="4+8";	//projected reticle on ground if not locked & lead indicator if locked
	magazines[]=
	{
		"RC_PylonM_350Rnd_20mm_Lead_O",
		"RC_PylonM_350Rnd_20mm_Proxy_Lead_O",
		"RC_PylonM_300Rnd_25mm_Lead_O",
		"RC_PylonM_300Rnd_25mm_Proxy_Lead_O",
		"RC_PylonM_250Rnd_30mm_Lead_O",
		"RC_PylonM_250Rnd_30mm_Proxy_Lead_O",

		"RC_PylonM_175Rnd_20mm_Lead_O",
		"RC_PylonM_175Rnd_20mm_Proxy_Lead_O",
		"RC_PylonM_150Rnd_25mm_Lead_O",
		"RC_PylonM_150Rnd_25mm_Proxy_Lead_O",
		"RC_PylonM_125Rnd_30mm_Lead_O",
		"RC_PylonM_125Rnd_30mm_Proxy_Lead_O"
	};
};
class RC_PylonW_Avtopushka_Lead: RC_PylonW_Avtopushka_Lead_Base
{
};


//unguided rockets
class missiles_DAR;
class RC_PylonW_12Rnd_Hydra_Fetch: missiles_DAR
{
	class Burst;
	class Far_AI;
	class Medium_AI;
};
class RC_PylonW_12Rnd_Hydra_Base: RC_PylonW_12Rnd_Hydra_Fetch
{
	displayName="70mm Hydra Pod";
	displayNameShort="70mm Hydra Pod";
	ballisticsComputer=8;
	canLock=2;

	magazines[]=
	{
		"RC_PylonM_12Rnd_Hydra_MP",
		"RC_PylonM_12Rnd_Hydra_MP_Proxy",
		"RC_PylonM_12Rnd_Hydra_MP_Proxy_Green",

        "RC_AI_PylonM_12Rnd_Hydra_MP_Proxy",
        "RC_AI_PylonM_12Rnd_Hydra_MP_Proxy_Green"
	};
	modes[]=
	{
		"Burst",
		"Medium_AI",
		"Far_AI"
	};
	class Burst: Burst
	{
		displayName="Hydra";
		displayNameShort="Hydra";
		reloadTime=0.15;
		dispersion=0.004;	//0.015 default, 0.004 to make more viable alternative to guided against vics that need direct hit
	};
	class Medium_AI: Medium_AI
	{
		displayName="Hydra";
		displayNameShort="Hydra";
		reloadTime=0.15;
	};
	class Far_AI: Far_AI
	{
		displayName="Hydra";
		displayNameShort="Hydra";
		reloadTime=0.15;
	};
};
class RC_PylonW_12Rnd_Hydra: RC_PylonW_12Rnd_Hydra_Base
{
};
class RC_PylonW_12Rnd_S5_Base: RC_PylonW_12Rnd_Hydra_Base
{
	displayName="S-5 UB-12";
	displayNameShort="S-5 UB-12";
	magazines[]=
	{
		"RC_PylonM_12Rnd_S5_MP",
		"RC_PylonM_12Rnd_S5_MP_Proxy",

        "RC_AI_PylonM_12Rnd_S5_MP_Proxy"
	};
	class Burst: Burst
	{
		displayName="S-5";
		displayNameShort="S-5";
	};
	class Medium_AI: Medium_AI
	{
		displayName="S-5";
		displayNameShort="S-5";
	};
	class Far_AI: Far_AI
	{
		displayName="S-5";
		displayNameShort="S-5";
	};
};
class RC_PylonW_12Rnd_S5: RC_PylonW_12Rnd_S5_Base
{
};


//unify 70mm rocket pods?
class rockets_Skyfire;
class RC_PylonW_19Rnd_Hydra_Fetch: rockets_Skyfire
{
	class Burst;
	class Close_AI;
	class Medium_AI;
	class Far_AI;
};
class RC_PylonW_19Rnd_Hydra_Base: RC_PylonW_19Rnd_Hydra_Fetch
{
	displayName="70mm Hydra Pod";
	displayNameShort="70mm Hydra Pod";
	ballisticsComputer=8;

	magazines[]=
	{
		"RC_PylonM_19Rnd_Hydra_MP",
		"RC_PylonM_19Rnd_Hydra_MP_Proxy",

        "RC_AI_PylonM_19Rnd_Hydra_MP_Proxy"
	};
	modes[]=
	{
		"Burst",
		"Close_AI",
		"Medium_AI",
		"Far_AI"
	};
	class Burst: Burst
	{
		displayName="Hydra";
		displayNameShort="Hydra";
		reloadTime=0.15;
		dispersion=0.004;	//0.015 default, 0.004 to make more viable alternative to guided against vics that need direct hit
	};
	class Close_AI: Close_AI
	{
		displayName="Hydra";
		displayNameShort="Hydra";
		reloadTime=0.15;
	};
	class Medium_AI: Medium_AI
	{
		displayName="Hydra";
		displayNameShort="Hydra";
		reloadTime=0.15;
	};
	class Far_AI: Far_AI
	{
		displayName="Hydra";
		displayNameShort="Hydra";
		reloadTime=0.15;
	};
};
class RC_PylonW_19Rnd_Hydra: RC_PylonW_19Rnd_Hydra_Base
{
};


class RC_PylonW_19Rnd_S5_Base: RC_PylonW_19Rnd_Hydra_Base
{
	displayName="S-5 UB-19";
	displayNameShort="S-5 UB-19";
	magazines[]=
	{
		"RC_PylonM_19Rnd_S5_MP",
		"RC_PylonM_19Rnd_S5_MP_Proxy",

        "RC_AI_PylonM_19Rnd_S5_MP_Proxy"
	};
	class Burst: Burst
	{
		displayName="S-5";
		displayNameShort="S-5";
	};
	class Close_AI: Close_AI
	{
		displayName="S-5";
		displayNameShort="S-5";
	};
	class Medium_AI: Medium_AI
	{
		displayName="S-5";
		displayNameShort="S-5";
	};
	class Far_AI: Far_AI
	{
		displayName="S-5";
		displayNameShort="S-5";
	};
};
class RC_PylonW_19Rnd_S5: RC_PylonW_19Rnd_S5_Base
{
};


//light guided
class missiles_DAGRM;
class RC_PylonW_APKWS_Fetch: missiles_DAGRM
{
	class Burst;
};
class RC_PylonW_APKWS_Base: RC_PylonW_APKWS_Fetch
{
	displayName="APKWS LG Pod";
	displayNameShort="APKWS LG Pod";
	ballisticsComputer=8;

	magazines[]=
	{
		"RC_PylonM_12Rnd_APKWS",
        "RC_PylonM_12Rnd_APKWS_Proxy",

		"RC_PylonM_7Rnd_APKWS",
        "RC_PylonM_7Rnd_APKWS_Proxy",

		"RC_RHS_PylonM_7Rnd_APKWS",
        "RC_RHS_PylonM_7Rnd_APKWS_Proxy"
	};
	modes[]=
	{
		"Burst"
	};
	class Burst: Burst
	{
		displayName="APKWS";
		displayNameShort="APKWS";
		ballisticsComputer=8;
		reloadTime=0.15;
	};
};
class RC_PylonW_APKWS: RC_PylonW_APKWS_Base
{
};


class RC_PylonW_S8_LG_Base: RC_PylonW_APKWS_Base
{
	displayName="S-8 LG Ugroza";
	displayNameShort="S-8 LG Ugroza";
	magazines[]=
	{
		"RC_PylonM_12Rnd_S8_LG",
		"RC_PylonM_7Rnd_S8_LG",

		"RC_PylonM_12Rnd_S8_LG_Proxy",
        "RC_PylonM_7Rnd_S8_LG_Proxy"
	};
};
class RC_PylonW_S8_LG: RC_PylonW_S8_LG_Base
{
};


class missiles_DAGR;
class RC_PylonW_DAGR_Fetch: missiles_DAGR
{
	class Burst;
	class Medium_AI;
	class Far_AI;
	//class Direct;
	//class LoalDistance;
};
class RC_PylonW_DAGR_Base: RC_PylonW_DAGR_Fetch
{
	displayName="DAGR";
	displayNameShort="DAGR";
	ballisticsComputer=8;
	magazines[]=
	{
		"RC_PylonM_8Rnd_DAGR",
		"RC_PylonM_8Rnd_DAGR_Proxy",

        "RC_AI_PylonM_8Rnd_DAGR",
        "RC_AI_PylonM_8Rnd_DAGR_Proxy"
	};
	modes[]=
	{
		"Burst",
		"Medium_AI",
		"Far_AI"
	};
	class Burst: Burst
	{
		displayName="DAGR";
		displayNameShort="DAGR";
		ballisticsComputer=8;
		reloadTime=0.15;
	};
	class Medium_AI: Medium_AI
	{
		displayName="DAGR";
		displayNameShort="DAGR";
		ballisticsComputer=8;
		reloadTime=0.15;
	};
	class Far_AI: Far_AI
	{
		displayName="DAGR";
		displayNameShort="DAGR";
		ballisticsComputer=8;
		reloadTime=0.15;
	};
	/*
	modes[]=
	{
		"Direct",
		"LoalDistance"
	};
	class Direct: Direct
	{
		displayName="DAGR DIR";
		displayNameShort="DAGR DIR";
	};
	class LoalDistance: LoalDistance
	{
		displayName="DAGR LOAL";
		displayNameShort="DAGR LOAL";
	};
	*/
};
class RC_PylonW_DAGR: RC_PylonW_DAGR_Base
{
};
class RC_PylonW_S8_G_Base: RC_PylonW_DAGR_Base
{
	displayName="S-8 G";
	displayNameShort="S-8 G";
	magazines[]=
	{
		"RC_PylonM_8Rnd_S8_G",
		"RC_PylonM_8Rnd_S8_G_Proxy",

        "RC_AI_PylonM_8Rnd_S8_G",
        "RC_AI_PylonM_8Rnd_S8_G_Proxy"
	};
	class Burst: Burst
	{
		displayName="S8 G";
		displayNameShort="S8 G";
	};
	class Medium_AI: Medium_AI
	{
		displayName="S8 G";
		displayNameShort="S8 G";
	};
	class Far_AI: Far_AI
	{
		displayName="S8 G";
		displayNameShort="S8 G";
	};
	/*
	class Direct: Direct
	{
		displayName="S-8 G DIR";
		displayNameShort="S-8 G DIR";
	};
	class LoalDistance: LoalDistance
	{
		displayName="S-8 G LOAL";
		displayNameShort="S-8 G LOAL";
	};
	*/
};
class RC_PylonW_S8_G: RC_PylonW_S8_G_Base
{
};


class RC_PylonW_SRAM_Base: RC_PylonW_DAGR_Base
{
	displayName="SRAM";
	displayNameShort="SRAM";
	weaponLockDelay=0.25;

	magazines[]=
	{
		"RC_PylonM_8Rnd_SRAM",
		"RC_PylonM_8Rnd_SRAM_Proxy",

	    "RC_AI_PylonM_8Rnd_SRAM_Proxy",
        "RC_AI_PylonM_8Rnd_SRAM"
	};
	class Burst: Burst
	{
		displayName="SRAM";
		displayNameShort="SRAM";
	};
};
class RC_PylonW_SRAM: RC_PylonW_SRAM_Base
{
};


class RC_PylonW_SRAM_Green_Base: RC_PylonW_SRAM_Base
{
	magazines[]=
	{
		"RC_PylonM_12Rnd_SRAM",
		"RC_PylonM_12Rnd_SRAM_Proxy",
		"RC_PylonM_12Rnd_SRAM_Green",
		"RC_PylonM_12Rnd_SRAM_Green_Proxy",

		"RC_AI_PylonM_12Rnd_SRAM",
		"RC_AI_PylonM_12Rnd_SRAM_Proxy",
		"RC_AI_PylonM_12Rnd_SRAM_Green",
		"RC_AI_PylonM_12Rnd_SRAM_Green_Proxy"
	};
};
class RC_PylonW_SRAM_Green: RC_PylonW_SRAM_Green_Base
{
};


//heavy guided
class missiles_SCALPEL;
class RC_PylonW_Hellfire_Base: missiles_SCALPEL
{
	displayName="Hellfire";
	displayNameShort="Hellfire";
	magazines[]=
	{
		"RC_PylonM_4Rnd_AGM114K",
		"RC_PylonM_3Rnd_AGM114K",
		"RC_PylonM_2Rnd_AGM114K",
		"RC_PylonM_1Rnd_AGM114K",
		"RC_PylonM_4Rnd_AGM114K_Proxy",
		"RC_PylonM_3Rnd_AGM114K_Proxy",
		"RC_PylonM_2Rnd_AGM114K_Proxy",
		"RC_PylonM_1Rnd_AGM114K_Proxy"
	};
};
class RC_PylonW_Hellfire: RC_PylonW_Hellfire_Base
{
};


class RC_PylonW_Vikhr_Base: RC_PylonW_Hellfire
{
	displayName="9K121 Vikhr";
	displayNameShort="9K121 Vikhr";
	magazines[]=
	{
		"RC_PylonM_4Rnd_Vikhr",
		"RC_PylonM_3Rnd_Vikhr",
		"RC_PylonM_2Rnd_Vikhr",
		"RC_PylonM_1Rnd_Vikhr",
		"RC_PylonM_4Rnd_Vikhr_Proxy",
		"RC_PylonM_3Rnd_Vikhr_Proxy",
		"RC_PylonM_2Rnd_Vikhr_Proxy",
		"RC_PylonM_1Rnd_Vikhr_Proxy"
	};
};
class RC_PylonW_Vikhr: RC_PylonW_Vikhr_Base
{
};
