class UserActions: UserActions
{
	class DriveControlsCommander
	{
		displayName="Drive controls commander";
		position="pos commander";
		radius=15;
		showwindow=0;
		condition="player isEqualTo (commander this);";
		//statement="this vehicleChat 'commander took drive controls'; (group (driver this)) setGroupOwner (owner (commander this)); this setOwner (owner (commander this)); this setEffectiveCommander (commander this);";

		statement="this vehicleChat 'commander took drive controls'; \
		[ (group (driver this)) setGroupOwner (owner (commander this)) ] remoteExec ['spawn', 2]; \
		[ this setOwner (owner (commander this)) ] remoteExec ['spawn', 2]; \
		[ this setEffectiveCommander (commander this) ] remoteExec ['spawn', 2];";
		
		onlyforplayer=1;
		shortcut="";
	};
	class DriveControlsGunner
	{
		displayName="Drive controls gunner";
		position="pos gunner";
		radius=15;
		showwindow=0;
		condition="player isEqualTo (gunner this);";
		//statement="this vehicleChat 'gunner took drive controls'; (group (driver this)) setGroupOwner (owner (gunner this)); this setOwner (owner (gunner this)); this setEffectiveCommander (gunner this);";
		
		statement="this vehicleChat 'gunner took drive controls'; \
		[ (group (driver this)) setGroupOwner (owner (gunner this)) ] remoteExec ['spawn', 2]; \
		[ this setOwner (owner (gunner this)) ] remoteExec ['spawn', 2]; \
		[ this setEffectiveCommander (gunner this) ] remoteExec ['spawn', 2];";
		
		onlyforplayer=1;
		shortcut="";
	};
};