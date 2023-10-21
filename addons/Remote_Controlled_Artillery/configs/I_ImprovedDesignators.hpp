/*
	The Order is
	Normal -> Thermal -> Normal Bag -> Thermal Bag
*/

// Arid
class RC_Improved_FOV_Laser_Designator_Arid_I: RC_Improved_FOV_Laser_Designator_Arid
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;

	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"RC_Improved_FOV_Laser_Designator_Bag_Arid_I"
		};
	};
};
class RC_Improved_FOV_Laser_Designator_Ti_Arid_I: RC_Improved_FOV_Laser_Designator_Ti_Arid
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;

	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"RC_Improved_FOV_Laser_Designator_Ti_Bag_Arid_I"
		};
	};
};
class RC_Improved_FOV_Laser_Designator_Bag_Arid_I: RC_Improved_FOV_Laser_Designator_Bag_Arid
{
	class assembleInfo: assembleInfo
	{
		assembleTo="RC_Improved_FOV_Laser_Designator_Arid_I";
	};
};
class RC_Improved_FOV_Laser_Designator_Ti_Bag_Arid_I: RC_Improved_FOV_Laser_Designator_Ti_Bag_Arid
{
	class assembleInfo: assembleInfo
	{
		assembleTo="RC_Improved_FOV_Laser_Designator_Ti_Arid_I";
	};
};

// Woodland
class RC_Improved_FOV_Laser_Designator_Woodland_I: RC_Improved_FOV_Laser_Designator_Woodland
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;

	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"RC_Improved_FOV_Laser_Designator_Bag_Woodland_I"
		};
	};
};
class RC_Improved_FOV_Laser_Designator_Ti_Woodland_I: RC_Improved_FOV_Laser_Designator_Ti_Woodland
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;

	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"RC_Improved_FOV_Laser_Designator_Ti_Bag_Woodland_I"
		};
	};
};
class RC_Improved_FOV_Laser_Designator_Bag_Woodland_I: RC_Improved_FOV_Laser_Designator_Bag_Woodland
{
	class assembleInfo: assembleInfo
	{
		assembleTo="RC_Improved_FOV_Laser_Designator_Woodland_I";
	};
};
class RC_Improved_FOV_Laser_Designator_Ti_Bag_Woodland_I: RC_Improved_FOV_Laser_Designator_Ti_Bag_Woodland
{
	class assembleInfo: assembleInfo
	{
		assembleTo="RC_Improved_FOV_Laser_Designator_Woodland_I";
	};
};