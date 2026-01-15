class UserActions: UserActions
{
	class ResetCameraDir
	{
		displayName="Reset Camera Dir";
		position="pos commander";	//pos driver
		radius=1.5;
		showwindow=0;
		onlyforplayer=1;
		shortcut="";

		condition="(this isEqualTo vehicle player) && (currentPilot this isNotEqualTo player) && (commander this isEqualTo player) && (!isRemoteControlling player)";
		statement="this lockCameraTo [this modelToWorld [0, 100, 70], [0], true]";
	};
};