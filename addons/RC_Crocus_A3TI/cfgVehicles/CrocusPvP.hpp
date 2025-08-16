class B_Crocus_PvP: B_Crocus_MP_TI_Sens
{
	displayName="Crocus PvP";

	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"B_Crocus_PvP_Bag"
		};
	};
};
class O_Crocus_PvP: B_Crocus_PvP
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;

	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"O_Crocus_PvP_Bag"
		};
	};
};
class I_Crocus_PvP: B_Crocus_PvP
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;

	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"I_Crocus_PvP_Bag"
		};
	};
};

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