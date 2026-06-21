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
	faction="RemoteControlled_B";
	#include "\Remote_Controlled_Artillery\includes_cfg\crewChanges.hpp"
};
class RC_B_CrewAgent: RC_B_Crew {scope=1;};

class O_crew_F;
class RC_O_Crew: O_crew_F
{
	displayName="Crewman";
	faction="RemoteControlled_O";
	#include "\Remote_Controlled_Artillery\includes_cfg\crewChanges.hpp"
};
class RC_O_CrewAgent: RC_O_Crew {scope=1;};

class I_crew_F;
class RC_I_Crew: I_crew_F
{
	displayName="Crewman";
	faction="RemoteControlled_I";
	#include "\Remote_Controlled_Artillery\includes_cfg\crewChanges.hpp"
};
class RC_I_CrewAgent: RC_I_Crew {scope=1;};


class B_Helipilot_F;
class RC_B_HeliPilot: B_Helipilot_F
{
	displayName="Heli Pilot";
	faction="RemoteControlled_B";
	#include "\Remote_Controlled_Artillery\includes_cfg\heliPilotChanges.hpp"
};
class O_Helipilot_F;
class RC_O_HeliPilot: O_Helipilot_F
{
	displayName="Heli Pilot";
	faction="RemoteControlled_O";
	#include "\Remote_Controlled_Artillery\includes_cfg\heliPilotChanges.hpp"
};
class I_Helipilot_F;
class RC_I_HeliPilot: I_Helipilot_F
{
	displayName="Heli Pilot";
	faction="RemoteControlled_I";
	#include "\Remote_Controlled_Artillery\includes_cfg\heliPilotChanges.hpp"
};


class RC_B_DoorGunner: RC_B_HeliPilot
{
	displayName="Door Gunner";
	#include "\Remote_Controlled_Artillery\includes_cfg\doorGunnerChanges.hpp"
};
class RC_O_DoorGunner: RC_O_HeliPilot
{
	displayName="Door Gunner";
	#include "\Remote_Controlled_Artillery\includes_cfg\doorGunnerChanges.hpp"
};
class RC_I_DoorGunner: RC_I_HeliPilot
{
	displayName="Door Gunner";
	#include "\Remote_Controlled_Artillery\includes_cfg\doorGunnerChanges.hpp"
};