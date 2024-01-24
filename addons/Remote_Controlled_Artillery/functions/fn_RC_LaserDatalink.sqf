/*
	Author: Ascent

	Description:
	Shares even handheld Laser in Datalink.
*/

// Need to exit early if we aren't a client
if !hasInterface exitWith {};
RC_LaserDatalink = [] spawn
{
	while {true} do
	{
		_LaserSpot = laserTarget player;
		side player reportRemoteTarget [_LaserSpot, 5];
		sleep 1;
	};
};

/*
hint format ["%1", _LaserSpot];
_uav = (getConnectedUAV player);
_LaserSpotUAV = laserTarget _uav;
hint format ["%1", _LaserSpotUAV];
side player reportRemoteTarget [_LaserSpotUAV, 15];
*/