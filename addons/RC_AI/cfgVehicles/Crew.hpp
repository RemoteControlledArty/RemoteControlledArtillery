class B_crew_F;
/*
class RC_AI_B_Crew_Base: B_crew_F
{
};
*/
class RC_AI_B_Crew: B_crew_F
{
	displayName="Crewman [West]";
	#include "\RC_AI\includes_cfg\crewChanges.hpp"
};
class O_crew_F;
class RC_AI_O_Crew: O_crew_F
{
	displayName="Crewman [East]";
	#include "\RC_AI\includes_cfg\crewChanges.hpp"
};
class I_crew_F;
class RC_AI_I_Crew: I_crew_F
{
	displayName="Crewman [Ind]";
	#include "\RC_AI\includes_cfg\crewChanges.hpp"
};