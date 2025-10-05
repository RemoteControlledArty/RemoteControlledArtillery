class B_crew_F;
/* class RC_AI_B_Crew_Base: B_crew_F {}; */
class RC_Test_B_Crew: B_crew_F
{
	displayName="Crewman [West]";
	#include "\RC_Testing\includes_cfg\crewChanges.hpp"
};
class RC_Test_B_Crew_Agent: RC_Test_B_Crew
{
	displayName="Crewman [West-A]";
};


class O_crew_F;
class RC_Test_O_Crew: O_crew_F
{
	displayName="Crewman [East]";
	#include "\RC_Testing\includes_cfg\crewChanges.hpp"
};
class RC_Test_O_Crew_Agent: RC_Test_O_Crew
{
	displayName="Crewman [East-A]";
};


class I_crew_F;
class RC_Test_I_Crew: I_crew_F
{
	displayName="Crewman [Ind]";
	#include "\RC_Testing\includes_cfg\crewChanges.hpp"
};
class RC_Test_I_Crew_Agent: RC_Test_I_Crew
{
	displayName="Crewman [Ind-A]";
};