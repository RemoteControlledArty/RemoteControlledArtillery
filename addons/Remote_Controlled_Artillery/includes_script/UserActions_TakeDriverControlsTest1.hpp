class UserActions: UserActions
{
	class DriveControlsCommander
	{
		displayName="Drive Controls Commander";
		position="pos commander";
		radius=15;
		showwindow=0;
		condition="player isEqualTo (commander this);";

		statement="[this, 'commander took drive controls'] remoteExec ['vehicleChat']; \
		[{ (group (driver this)) setGroupOwner (owner (commander this)); }] remoteExec ['call', 0]; \
		[{ this setOwner (owner (commander this)); }] remoteExec ['call', 0]; \
		[{ this setEffectiveCommander (commander this); }] remoteExec ['call', 0];";

		onlyforplayer=1;
		shortcut="";
	};
	class DriveControlsGunner
	{
		displayName="Drive Controls Gunner";
		position="pos gunner";
		radius=15;
		showwindow=0;
		condition="player isEqualTo (gunner this);";
		
		statement="[this, 'gunner took drive controls'] remoteExec ['vehicleChat']; \
		[{ (group (driver this)) setGroupOwner (owner (gunner this)); }] remoteExec ['call', 0]; \
		[{ this setOwner (owner (gunner this)); }] remoteExec ['call', 0]; \
		[{ this setEffectiveCommander (gunner this); }] remoteExec ['call', 0];";
		
		onlyforplayer=1;
		shortcut="";
	};
};