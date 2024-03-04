/*
	Author: Ascent

	Description:
	Shares even handheld Laser in Datalink.
*/

// Need to exit early if we aren't a client
if !hasInterface exitWith {};
RC_LaserDatalink = [] spawn
{
	private _oldPos = getPosASLVisual laserTarget player;
	while {true} do
	{
		waitUntil {sleep 1; (laserTarget player) != isNull && getPosASLVisual (laserTarget player) isNotEqualTo _oldPos};
		_laserSpot = laserTarget player;
		_playerSide = side player;
		[[_playerSide],[_laserSpot, 5]] remoteExec ["reportRemoteTarget", 0, true];
		_oldPos = getPosASLVisual _laserSpot;
		sleep 1;
	};
};

/*
//old versions

while {true} do
{
	_LaserSpot = laserTarget player;
	side player reportRemoteTarget [_LaserSpot, 5];
	sleep 1;
};

while {true} do
{
	_laserSpot = laserTarget player;
	_playerSide = side player;
	[[_playerSide],[_laserSpot, 6]] remoteExec ["reportRemoteTarget", 0, true];
	sleep 3;
};
*/