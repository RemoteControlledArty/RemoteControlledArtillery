class UserActions: UserActions
{
	class CommanderDrivingControls
	{
		displayName="Take driving controls";
		position="pos commander";
		radius=15;
		showwindow=0;
		condition="player isEqualTo (commander this);";
		statement="(group (driver this)) setGroupOwner (owner (commander this)); this setOwner (owner (commander this)); this setEffectiveCommander (commander this);";
		onlyforplayer=1;
		shortcut="";
	};
	class GunnerDrivingControls
	{
		displayName="Take driving controls";
		position="pos gunner";
		radius=15;
		showwindow=0;
		condition="player isEqualTo (gunner this);";
		statement="(group (driver this)) setGroupOwner (owner (gunner this)); this setOwner (owner (gunner this)); this setEffectiveCommander (gunner this);";
		onlyforplayer=1;
		shortcut="";
	};
};