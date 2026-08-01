/*
	Author: Ascent

	Description:
	Shares laser spot (even of handheld Laser-Designators) in Datalink.
*/


// exit early if not a client
if (!hasInterface) exitWith {};
RC_LaserDatalink = [] spawn
{
	while {true} do
	{
		private _l = laserTarget player;
		if (!isNull _l) then {
			private _s = side player;
			[_s,[_l, 2]] remoteExec ["reportRemoteTarget", _s];
		};
		sleep 1;
	};
};