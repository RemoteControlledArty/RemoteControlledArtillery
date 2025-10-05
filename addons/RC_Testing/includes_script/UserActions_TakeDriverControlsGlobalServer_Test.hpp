class UserActions: UserActions
{
	class DriveControlsCommander
	{
		displayName="Take Drive Controls";
		position="pos commander";
		radius=15;
		showwindow=0;
		onlyforplayer=1;
		shortcut="";

		condition="player isEqualTo (commander this);";
		statement="[this, RC_fnc_RC_TakeControlCommanderServer_Test] remoteExec ['call', 2]";
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
		statement="[this, RC_fnc_RC_TakeControlGunnerServer_Test] remoteExec ['call', 2]";
	};
};