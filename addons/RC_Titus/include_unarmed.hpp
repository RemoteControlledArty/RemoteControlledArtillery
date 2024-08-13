class RC_Titus_unarmed_WD: RC_Titus_unarmed_D
{
	#include "\RC_Titus\tex_wd_unarmed.hpp"
};
class RC_Titus_unarmed_A: RC_Titus_unarmed_D
{
	#include "\RC_Titus\tex_a_unarmed.hpp"
};


class RC_Titus_unarmed_D_O: RC_Titus_unarmed_D
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;

	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsO.hpp"
};
class RC_Titus_unarmed_WD_O: RC_Titus_unarmed_D_O
{
	#include "\RC_Titus\tex_wd_unarmed.hpp"
};
class RC_Titus_unarmed_A_O: RC_Titus_unarmed_D_O
{
	#include "\RC_Titus\tex_a_unarmed.hpp"
};


class RC_Titus_unarmed_D_I: RC_Titus_unarmed_D
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;

	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"
};
class RC_Titus_unarmed_WD_I: RC_Titus_unarmed_D_I
{
	#include "\RC_Titus\tex_wd_unarmed.hpp"
};
class RC_Titus_unarmed_A_I: RC_Titus_unarmed_D_I
{
	#include "\RC_Titus\tex_a_unarmed.hpp"
};
