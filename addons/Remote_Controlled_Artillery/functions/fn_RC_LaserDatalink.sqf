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
		private _laserSpot = laserTarget player;
		private _side = side player;
		if (!isNull _laserSpot) then {[_side,[_laserSpot, 5]] remoteExec ["reportRemoteTarget", _side];};
		sleep 2;
	};
};

//prior ["reportRemoteTarget", 0, true] but removed true (JIP) to prevent backlogging, will add again if it made it stop working


/*
//old versions

private _oldPos = getPosASLVisual laserTarget player;
while {true} do
{
	waitUntil {sleep 1; !isNull (laserTarget player) && getPosASLVisual (laserTarget player) isNotEqualTo _oldPos};
	_laserSpot = laserTarget player;
	_playerSide = side player;
	[_playerSide,[_laserSpot, 5]] remoteExec ["reportRemoteTarget", 0, true];
	_oldPos = getPosASLVisual _laserSpot;
	sleep 1;
};

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