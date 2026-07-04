class B_Crocus_PvP: B_Crocus_MP_TI_Sens
{
	/*
	class EventHandlers: EventHandlers
	{
		class RC_Crocus
		{
			init="(_this # 0) spawn RC_fnc_fpv_droneInit_MP;";
			//fired="params ['_unit'];  if (local _unit) then { _unit spawn RC_fnc_fpv_detonate_MP };";
			handleDamage="params ['_unit', '_selection', '_damage'];  if (local _unit) then { if (_damage > 0.1) then {_unit spawn RC_fnc_fpv_detonate_MP }; };";
		};
	};
	
	weapons[]=
	{
		"RC_target_confirmer_impact_weapon"
	};
	magazines[]=
	{
		"RC_target_confirmer_impact_mag"
	};
	*/

	displayName="Crocus PvP";

	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"Crocus_PvP_Bag"
			//"B_Crocus_PvP_Bag"
		};
	};
};
class O_Crocus_PvP: B_Crocus_PvP
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;

	/*
	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"O_Crocus_PvP_Bag"
		};
	};
	*/
};
class I_Crocus_PvP: B_Crocus_PvP
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;

	/*
	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"I_Crocus_PvP_Bag"
		};
	};
	*/
};


class Crocus_PvP_Assemble: B_Crocus_PvP
{
	scope=1;
	scopeCurator=1;
	side=3;
	crew="C_UAV_AI_F";
	//faction="RemoteControlled_C";
};
class Crocus_PvP_Bag: Crocus_MP_TI_Bag
{
	displayName="Crocus PvP Bag";

	class assembleInfo: assembleInfo
	{
		displayName="Crocus PvP";
		assembleTo="Crocus_PvP_Assemble";
	};
};


/*
class B_Crocus_PvP_Bag: B_Crocus_MP_TI_Bag
{
	displayName="Crocus PvP Bag";

	class assembleInfo: assembleInfo
	{
		assembleTo="B_Crocus_PvP";
		displayName="Crocus PvP";
	};
};
class O_Crocus_PvP_Bag: B_Crocus_PvP_Bag
{
	displayName="Crocus PvP Bag [Opf]";

	class assembleInfo: assembleInfo
	{
		assembleTo="O_Crocus_PvP";
		displayName="Crocus PvP [Opf]";
	};
};
class I_Crocus_PvP_Bag: B_Crocus_PvP_Bag
{
	displayName="Crocus PvP Bag [Ind]";

	class assembleInfo: assembleInfo
	{
		assembleTo="I_Crocus_PvP";
		displayName="Crocus PvP [Ind]";
	};
};
*/