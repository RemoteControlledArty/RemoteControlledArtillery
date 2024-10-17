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
		this vehicleChat 'commander took drive controls'; \
		this vehicleChat 'commander took drive controls'; \
		_driverGroup setGroupOwner _vicCommanderID; \
		this setEffectiveCommander _vicCommander;";

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
		this vehicleChat 'gunner took drive controls'; \
		this vehicleChat 'gunner took drive controls'; \
		_driverGroup setGroupOwner _vicGunnerID; \
		this setEffectiveCommander _vicGunner;";
		
		onlyforplayer=1;
		shortcut="";
	};
};