class RC_FPV_Mothership;
class RC_Crocus_Mothership_Base: RC_FPV_Mothership
{
	class Turrets;
	class MainTurret;
	class EventHandlers;
	scope=0;
	scopeCurator=0;
	//RC_UAVBlurRange=2000;
	RC_Local=1; //1 = requires transfer of locality/ownership for full functionality
};
class RC_Crocus_Mothership: RC_Crocus_Mothership_Base
{
	class EventHandlers: EventHandlers
	{
		class RC_Crocus
		{
			fired="params ['_uav', '_weapon'];  if (!Local _uav) exitWith {};  [_uav, _weapon] call RC_fnc_fpv_MothershipDeploy";
		};
	};

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			weapons[]=
			{
				"Laserdesignator_mounted",
				"RC_Crocus_Deployer"
			};
			magazines[]=
			{
				"Laserbatteries",
				"RC_8xCrocus_Deployer_Mag"
			};
		};
	};

	displayName="RC Crocus Mothership";
	scope=2;
	scopeCurator=2;
};
class RC_Crocus_Mothership_O: RC_Crocus_Mothership
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
};
class RC_Crocus_Mothership_I: RC_Crocus_Mothership
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
};


class RC_FPV_Mothership_NoCam;
class RC_Crocus_Mothership_NoCam_Base: RC_FPV_Mothership_NoCam
{
	class Turrets;
	class MainTurret;
	class EventHandlers;
	scope=0;
	scopeCurator=0;
	//RC_UAVBlurRange=2000;
	RC_Local=1; //1 = requires transfer of locality/ownership for full functionality
};
class RC_Crocus_Mothership_NoCam: RC_Crocus_Mothership_NoCam_Base
{
	class EventHandlers: EventHandlers
	{
		class RC_Crocus
		{
			fired="params ['_uav', '_weapon'];  if (!Local _uav) exitWith {};  [_uav, _weapon] call RC_fnc_fpv_MothershipDeploy";
		};
	};

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			weapons[]=
			{
				"RC_Crocus_Deployer"
			};
			magazines[]=
			{
				"RC_8xCrocus_Deployer_Mag"
			};
		};
	};

	displayName="RC Crocus Mothership [no camera]";
	scope=2;
	scopeCurator=2;
};
class RC_Crocus_Mothership_NoCam_O: RC_Crocus_Mothership_NoCam
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
};
class RC_Crocus_Mothership_NoCam_I: RC_Crocus_Mothership_NoCam
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
};


class RC_FPV_MothershipMQ;
class RC_Crocus_MothershipMQ_Base: RC_FPV_MothershipMQ
{
	class Turrets;
	class MainTurret;
	class EventHandlers;
	scope=0;
	scopeCurator=0;
	//RC_UAVBlurRange=2000;
	RC_Local=1; //1 = requires transfer of locality/ownership for full functionality
};
class RC_Crocus_MothershipMQ: RC_Crocus_MothershipMQ_Base
{
	class EventHandlers: EventHandlers
	{
		class RC_Crocus
		{
			fired="params ['_uav', '_weapon'];  if (!Local _uav) exitWith {};  [_uav, _weapon] call RC_fnc_fpv_MothershipDeploy";
		};
	};

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			weapons[]=
			{
				"Laserdesignator_mounted",
				"RC_Crocus_Deployer"
			};
			magazines[]=
			{
				"Laserbatteries",
				"RC_8xCrocus_Deployer_Mag"
			};
		};
	};

	displayName="RC Crocus Mothership";
	scope=2;
	scopeCurator=2;
};
class RC_Crocus_MothershipMQ_O: RC_Crocus_MothershipMQ
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
};
class RC_Crocus_MothershipMQ_I: RC_Crocus_MothershipMQ
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
};


class RC_FPV_MothershipMQ_NoCam;
class RC_Crocus_MothershipMQ_NoCam_Base: RC_FPV_MothershipMQ_NoCam
{
	class Turrets;
	class MainTurret;
	class EventHandlers;
	scope=0;
	scopeCurator=0;
	//RC_UAVBlurRange=2000;
	RC_Local=1; //1 = requires transfer of locality/ownership for full functionality
};
class RC_Crocus_MothershipMQ_NoCam: RC_Crocus_MothershipMQ_NoCam_Base
{
	class EventHandlers: EventHandlers
	{
		class RC_Crocus
		{
			fired="params ['_uav', '_weapon'];  if (!Local _uav) exitWith {};  [_uav, _weapon] call RC_fnc_fpv_MothershipDeploy";
		};
	};

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			weapons[]=
			{
				"RC_Crocus_Deployer"
			};
			magazines[]=
			{
				"RC_8xCrocus_Deployer_Mag"
			};
		};
	};

	displayName="RC Crocus Mothership [no camera]";
	scope=2;
	scopeCurator=2;
};
class RC_Crocus_MothershipMQ_NoCam_O: RC_Crocus_MothershipMQ_NoCam
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
};
class RC_Crocus_MothershipMQ_NoCam_I: RC_Crocus_MothershipMQ_NoCam
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
};