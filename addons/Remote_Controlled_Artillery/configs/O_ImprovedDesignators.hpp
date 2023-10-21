/*
	The Order is
	Normal -> Thermal -> Normal Bag -> Thermal Bag
*/

// Arid
class RC_Improved_FOV_Laser_Designator_Arid_O: RC_Improved_FOV_Laser_Designator_Arid
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;

	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"RC_Improved_FOV_Laser_Designator_Bag_Arid_O"
		};
	};
};
class RC_Improved_FOV_Laser_Designator_Ti_Arid_O: RC_Improved_FOV_Laser_Designator_Ti_Arid
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;

	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"RC_Improved_FOV_Laser_Designator_Ti_Bag_Arid_O"
		};
	};
};
class RC_Improved_FOV_Laser_Designator_Bag_Arid_O: RC_Improved_FOV_Laser_Designator_Bag_Arid
{
	class assembleInfo: assembleInfo
	{
		assembleTo="RC_Improved_FOV_Laser_Designator_Arid_O";
	};
};
class RC_Improved_FOV_Laser_Designator_Ti_Bag_Arid_O: RC_Improved_FOV_Laser_Designator_Ti_Bag_Arid
{
	class assembleInfo: assembleInfo
	{
		assembleTo="RC_Improved_FOV_Laser_Designator_Ti_Arid_O";
	};
};

// Woodland
class RC_Improved_FOV_Laser_Designator_Woodland_O: RC_Improved_FOV_Laser_Designator_Woodland
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;

	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"RC_Improved_FOV_Laser_Designator_Bag_Woodland_O"
		};
	};
};
class RC_Improved_FOV_Laser_Designator_Ti_Woodland_O: RC_Improved_FOV_Laser_Designator_Ti_Woodland
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;

	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"RC_Improved_FOV_Laser_Designator_Ti_Bag_Woodlan_O"
		};
	};
};
class RC_Improved_FOV_Laser_Designator_Bag_Woodland_O: RC_Improved_FOV_Laser_Designator_Bag_Woodland
{
	class assembleInfo: assembleInfo
	{
		assembleTo="RC_Improved_FOV_Laser_Designator_Woodland_O";
	};
};
class RC_Improved_FOV_Laser_Designator_Ti_Bag_Woodland_O: RC_Improved_FOV_Laser_Designator_Ti_Bag_Woodland
{
	class assembleInfo: assembleInfo
	{
		assembleTo="RC_Improved_FOV_Laser_Designator_Woodland_O";
	};
};