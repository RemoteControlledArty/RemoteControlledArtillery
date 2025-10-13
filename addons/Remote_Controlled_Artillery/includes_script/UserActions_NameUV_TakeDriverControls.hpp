class UserActions: UserActions
{
	class NameUV_Driver
	{
		displayName="Name UV";
		position="pos driver";
		radius=15;
		showwindow=0;
		onlyforplayer=1;
		shortcut="";

		condition="isRemoteControlling player;";
		statement="[[this,name player], RC_fnc_RC_NameUV_Server] remoteExec ['call', 2]";
	};
	/*
	class NameUV_Gunner
	{
		displayName="Name UV";
		position="pos gunner";
		radius=15;
		showwindow=0;
		onlyforplayer=1;
		shortcut="";

		condition="isRemoteControlling player;";
		statement="[[this,name player], RC_fnc_RC_NameUV_Server] remoteExec ['call', 2]";
	};
	*/
	class DriveControlsCommander
	{
		displayName="Take Drive Controls";
		position="pos commander";
		radius=15;
		showwindow=0;
		onlyforplayer=1;
		shortcut="";

		condition="player isEqualTo (commander this);";
		statement="[this, RC_fnc_RC_TakeControlCommanderServer] remoteExec ['call', 2]";
	};
	class DriveControlsGunner
	{
		displayName="Take Drive Controls";
		position="pos gunner";
		radius=15;
		showwindow=0;
		onlyforplayer=1;
		shortcut="";

		condition="player isEqualTo (gunner this);";
		statement="[this, RC_fnc_RC_TakeControlGunnerServer] remoteExec ['call', 2]";
	};
};