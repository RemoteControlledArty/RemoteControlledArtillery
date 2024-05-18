//Autocannon
class RC_Titus_AC_WD: RC_Titus_AC_D
{
	#include "\RC_Titus\tex_wd_armed.hpp"
};
class RC_Titus_AC_A: RC_Titus_AC_D
{
	#include "\RC_Titus\tex_a_unarmed.hpp"
};


class RC_Titus_AC_D_O: RC_Titus_AC_D
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;

	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsO.hpp"

	class Turrets: Turrets
	{
		class ARX20Turret: ARX20Turret
		{
			magazines[]=
			{
				"RC_QIN_100Rnd_20mm_T_G",
				"RC_QIN_100Rnd_20mm_T_G",
				"RC_QIN_100Rnd_20mm_T_G",
				"RC_QIN_100Rnd_20mm_T_G",
				"RC_QIN_150Rnd_338_T_G",
				"RC_QIN_150Rnd_338_T_G",
				"RC_QIN_150Rnd_338_T_G",
				"RC_QIN_150Rnd_338_T_G",
				"RC_QIN_150Rnd_338_T_G",
				"RC_QIN_150Rnd_338_T_G",
				"SmokeLauncherMag",
				"SmokeLauncherMag"
			};
		};

		class CommanderTurret: CommanderTurret {};
		class CargoTurret_01: CargoTurret_01 {};
		class CargoTurret_02: CargoTurret_02 {};
	};
};
class RC_Titus_AC_WD_O: RC_Titus_AC_D_O
{
	#include "\RC_Titus\tex_wd_armed.hpp"
};
class RC_Titus_AC_A_O: RC_Titus_AC_D_O
{
	#include "\RC_Titus\tex_a_armed.hpp"
};


class RC_Titus_AC_D_I: RC_Titus_AC_D
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;

	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"

	class Turrets: Turrets
	{
		class ARX20Turret: ARX20Turret
		{
			magazines[]=
			{
				"RC_QIN_100Rnd_20mm_T_Y",
				"RC_QIN_100Rnd_20mm_T_Y",
				"RC_QIN_100Rnd_20mm_T_Y",
				"RC_QIN_100Rnd_20mm_T_Y",
				"RC_QIN_150Rnd_338_T_Y",
				"RC_QIN_150Rnd_338_T_Y",
				"RC_QIN_150Rnd_338_T_Y",
				"RC_QIN_150Rnd_338_T_Y",
				"RC_QIN_150Rnd_338_T_Y",
				"RC_QIN_150Rnd_338_T_Y",
				"SmokeLauncherMag",
				"SmokeLauncherMag"
			};
		};

		class CommanderTurret: CommanderTurret {};
		class CargoTurret_01: CargoTurret_01 {};
		class CargoTurret_02: CargoTurret_02 {};
	};
};
class RC_Titus_AC_WD_I: RC_Titus_AC_D_I
{
	#include "\RC_Titus\tex_wd_armed.hpp"
};
class RC_Titus_AC_A_I: RC_Titus_AC_D_I
{
	#include "\RC_Titus\tex_a_armed.hpp"
};


//MMG
class RC_Titus_MMG_WD: RC_Titus_MMG_D
{
	#include "\RC_Titus\tex_wd_armed.hpp"
};
class RC_Titus_MMG_A: RC_Titus_MMG_D
{
	#include "\RC_Titus\tex_a_armed.hpp"
};


class RC_Titus_MMG_D_O: RC_Titus_MMG_WD
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;

	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsO.hpp"

	class Turrets: Turrets
	{
		class ARX20Turret: ARX20Turret
		{
			magazines[]=
			{
				"RC_QIN_150Rnd_338_T_G",
				"RC_QIN_150Rnd_338_T_G",
				"RC_QIN_150Rnd_338_T_G",
				"RC_QIN_150Rnd_338_T_G",
				"SmokeLauncherMag",
				"SmokeLauncherMag"
			};
		};

		class CommanderTurret: CommanderTurret {};
		class CargoTurret_01: CargoTurret_01 {};
		class CargoTurret_02: CargoTurret_02 {};
	};
};
class RC_Titus_MMG_WD_O: RC_Titus_MMG_D_O
{
	#include "\RC_Titus\tex_wd_armed.hpp"
};
class RC_Titus_MMG_A_O: RC_Titus_MMG_D_O
{
	#include "\RC_Titus\tex_a_armed.hpp"
};


class RC_Titus_MMG_D_I: RC_Titus_MMG_D
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;

	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"

	class Turrets: Turrets
	{
		class ARX20Turret: ARX20Turret
		{
			magazines[]=
			{
				"RC_QIN_150Rnd_338_T_Y",
				"RC_QIN_150Rnd_338_T_Y",
				"RC_QIN_150Rnd_338_T_Y",
				"RC_QIN_150Rnd_338_T_Y",
				"SmokeLauncherMag",
				"SmokeLauncherMag"
			};
		};

		class CommanderTurret: CommanderTurret {};
		class CargoTurret_01: CargoTurret_01 {};
		class CargoTurret_02: CargoTurret_02 {};
	};
};
class RC_Titus_MMG_WD_I: RC_Titus_MMG_D_I
{
	#include "\RC_Titus\tex_wd_armed.hpp"
};
class RC_Titus_MMG_A_I: RC_Titus_MMG_D_I
{
	#include "\RC_Titus\tex_a_armed.hpp"
};