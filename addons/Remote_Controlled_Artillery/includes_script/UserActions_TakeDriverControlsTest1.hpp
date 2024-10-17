class UserActions: UserActions
{
	class DriveControlsCommander
	{
		displayName="Drive Controls Commander";
		position="pos commander";
		radius=15;
		showwindow=0;
		condition="player isEqualTo (commander this);";

		statement="_vicOwner = owner this; \
		_vicCommander = commander this; \
		_vicCommanderID = owner _vicCommander; \
		_driverGroup = group (driver this); \
		[this, 'commander took drive controls'] remoteExec ['vehicleChat', _vicOwner]; \
		[this, 'commander took drive controls'] remoteExec ['vehicleChat', _vicCommander]; \
		[_driverGroup, _vicCommanderID] remoteExec ['setGroupOwner', _vicOwner]; \
		[this, _vicCommander] remoteExec ['setEffectiveCommander', _vicOwner];";

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
		
		statement="_vicOwner = owner this; \
		_vicGunner = gunner this; \
		_vicGunnerID = owner _vicGunner; \
		_driverGroup = group (driver this); \
		[this, 'gunner took drive controls'] remoteExec ['vehicleChat', _vicOwner]; \
		[this, 'gunner took drive controls'] remoteExec ['vehicleChat', _vicGunner]; \
		[_driverGroup, _vicGunnerID] remoteExec ['setGroupOwner', _vicOwner]; \
		[this, _vicGunner] remoteExec ['setEffectiveCommander', _vicOwner];";
		
		onlyforplayer=1;
		shortcut="";
	};
	/*
	class DriveControlsCommander
	{
		displayName="Drive Controls Commander";
		position="pos commander";
		radius=15;
		showwindow=0;
		condition="player isEqualTo (commander this);";

		statement="_vicOwner = owner this; \
		_vicCommander = commander this; \
		_vicCommanderID = owner _vicCommander;
		_driverGroup = group (driver this); \
		[this, 'commander took drive controls'] remoteExec ['vehicleChat', _vicOwner]; \
		[this, 'commander took drive controls'] remoteExec ['vehicleChat', _vicCommander]; \
		[_driverGroup, _vicCommanderID] remoteExec ['setGroupOwner', _vicOwner]; \
		[this, _vicCommander] remoteExec ['setEffectiveCommander', _vicOwner];";

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
		
		statement="_vicOwner = owner this; \
		_vicGunner = gunner this; \
		_vicGunnerID = owner _vicGunner;
		_driverGroup = group (driver this); \
		[this, 'gunner took drive controls'] remoteExec ['vehicleChat', _vicOwner]; \
		[this, 'gunner took drive controls'] remoteExec ['vehicleChat', _vicGunner]; \
		[_driverGroup, _vicGunnerID] remoteExec ['setGroupOwner', _vicOwner]; \
		[this, _vicGunner] remoteExec ['setEffectiveCommander', _vicOwner];";
		
		onlyforplayer=1;
		shortcut="";
	};
	*/
};