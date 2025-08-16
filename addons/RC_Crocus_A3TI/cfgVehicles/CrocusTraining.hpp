class B_Crocus_Training: B_Crocus_MP_TI_Sens
{
	displayName="Crocus Training";

	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"B_Crocus_Training_Bag"
		};
	};
};
class O_Crocus_Training: B_Crocus_Training
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;

	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"O_Crocus_Training_Bag"
		};
	};
};
class I_Crocus_Training: B_Crocus_Training
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;

	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"I_Crocus_Training_Bag"
		};
	};
};

class B_Crocus_Training_Bag: B_Crocus_MP_TI_Bag
{
	displayName="Crocus Training Bag";

	class assembleInfo: assembleInfo
	{
		assembleTo="B_Crocus_Training";
		displayName="Crocus Training";
	};
};
class O_Crocus_Training_Bag: B_Crocus_Training_Bag
{
	displayName="Crocus Training Bag [Opf]";

	class assembleInfo: assembleInfo
	{
		assembleTo="O_Crocus_Training";
		displayName="Crocus Training [Opf]";
	};
};
class I_Crocus_Training_Bag: B_Crocus_Training_Bag
{
	displayName="Crocus Training Bag [Ind]";

	class assembleInfo: assembleInfo
	{
		assembleTo="I_Crocus_Training";
		displayName="Crocus Training [Ind]";
	};
};