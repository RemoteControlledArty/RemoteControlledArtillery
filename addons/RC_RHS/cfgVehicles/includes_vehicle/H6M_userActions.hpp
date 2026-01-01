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
	/*
	class MFD_Toggle
	{
	};
	class SAFEMODE
	{
	};
	*/
	//*
	class MFD_Toggle
	{
		displayName="removed";
		condition="false";
		statement="if (true) exitwith {};";
		onlyforplayer=1;
		position="doplnovani";
		radius=1;
		shortcut="LandGearUp";
		showWindow=0;
	};
	class SAFEMODE
	{
		displayName="removed";
		condition="false";
		statement="if (true) exitwith {};";
		position="";
		radius=1;
		priority=10.5;
		onlyforplayer=1;
		showWindow=0;
		shortcut="user13";
		hideOnUse=1;
	};
	//*/
};