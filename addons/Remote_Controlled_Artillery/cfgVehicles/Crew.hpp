class C_man_w_worker_F;
class RC_CoverallsBlk_Man: C_man_w_worker_F
{
	scope=1;
	displayName="Coveralls Black";
	uniformClass="RC_CoverallsBlk";
	model="\A3\characters_F\common\coveralls";
	modelSides[]={0,1,2,3};
	hiddenSelections[]={"Camo","insignia"};
	hiddenSelectionsTextures[]={"\A3\Characters_F\Common\Data\coveralls_black_co.paa"};
};


class B_crew_F;
class RC_B_Crew: B_crew_F
{
	displayName="Crewman";
	#include "\Remote_Controlled_Artillery\includes_cfg\crewChanges.hpp"
};
class O_crew_F;
class RC_O_Crew: O_crew_F
{
	displayName="Crewman";
	#include "\Remote_Controlled_Artillery\includes_cfg\crewChanges.hpp"
};
class I_crew_F;
class RC_I_Crew: I_crew_F
{
	displayName="Crewman";
	#include "\Remote_Controlled_Artillery\includes_cfg\crewChanges.hpp"
};


class B_Helipilot_F;
class RC_B_HeliPilot: B_Helipilot_F
{
	displayName="Heli Pilot";
	#include "\Remote_Controlled_Artillery\includes_cfg\heliPilotChanges.hpp"
};
class O_Helipilot_F;
class RC_O_HeliPilot: O_Helipilot_F
{
	displayName="Heli Pilot";
	#include "\Remote_Controlled_Artillery\includes_cfg\heliPilotChanges.hpp"
};
class I_Helipilot_F;
class RC_I_HeliPilot: I_Helipilot_F
{
	displayName="Heli Pilot";
	#include "\Remote_Controlled_Artillery\includes_cfg\heliPilotChanges.hpp"
};