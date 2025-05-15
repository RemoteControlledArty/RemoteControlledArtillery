/*
	Author: Ascent

	Description:
	Fixes multiplayer locality of this mods UAV's/UGV's, needs to be run server side for "owner" to work.
*/

/*
params ["_uav, _player"];
if (!isServer) exitwith {};

_driverGroup = group (driver _uav);
_playerID = owner _player;
[_driverGroup, _playerID] remoteExec ['setGroupOwner', 2];
[_uav, _player] remoteExec ['setEffectiveCommander', 0];
*/