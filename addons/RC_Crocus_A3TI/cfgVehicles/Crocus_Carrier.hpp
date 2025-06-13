class RC_FPV_Carrier;
class RC_Crocus_Carrier_Base: RC_FPV_Carrier
{
	class Turrets;
	class MainTurret;
	class EventHandlers;
	scope=0;
	scopeCurator=0;
	//RC_UAVBlurRange=2000;
	RC_Local=1; //1 = requires transfer of locality/ownership for full functionality
};
class RC_Crocus_Carrier: RC_Crocus_Carrier_Base
{
	class EventHandlers: EventHandlers
	{
		class RC_Crocus
		{
			fired="params ['_uav', '_weapon'];  if (!Local _uav) exitWith {};  [_uav, _weapon] call RC_fnc_fpv_MothershipDeploy";
		};
	};

	weapons[]=
	{
		"RC_target_confirmer_datalink",
		"RC_Crocus_Deployer"
	};
	magazines[]=
	{
		"RC_target_confirmer_mag",
		"RC_6xCrocus_Deployer_Mag"
	};

	displayName="6xCrocus Carrier";
	scope=2;
	scopeCurator=2;
};
class RC_Crocus_Carrier_O: RC_Crocus_Carrier
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
};
class RC_Crocus_Carrier_I: RC_Crocus_Carrier
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
};