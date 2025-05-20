params ["_uav"];

private _prevWpPos1 = (_uav getVariable ["RC_prevWpPos1", 0]);
private _prevWpPos2 = (_uav getVariable ["RC_prevWpPos2", 0]);
private _prevWpPos3 = (_uav getVariable ["RC_prevWpPos3", 0]);
private _curWpPos1 = (waypointPosition [_uav, 1]) select 1;
private _curWpPos2 = (waypointPosition [_uav, 2]) select 1;
private _curWpPos3 = (waypointPosition [_uav, 3]) select 1;
if (((_curWpPos1 isNotEqualTo _prevWpPos1) or (_curWpPos2 isNotEqualTo _prevWpPos2) or (_curWpPos3 isNotEqualTo _prevWpPos3))) then {

    [_uav, ["RC_prevWpPos1", _curWpPos1]] remoteExec ["setVariable", 0];
    [_uav, ["RC_prevWpPos2", _curWpPos2]] remoteExec ["setVariable", 0];
    [_uav, ["RC_prevWpPos3", _curWpPos3]] remoteExec ["setVariable", 0];

    [_uav] call RC_fnc_RC_uavChangeLocality;
};

private _prevWpCount = (_uav getVariable ["RC_prevWpCount", 0]);
private _curWpCount = count (waypoints _uav);
if (_curWpCount != _prevWpCount) then {

    [_uav, ["RC_prevWpCount", _curWpCount]] remoteExec ["setVariable", 0];

    [_uav] call RC_fnc_RC_uavChangeLocality;
};

/*
RC_fnc_uavWaypoints =
{

};
*/

/*
RC_fnc_uavWaypointsTest =
{
    params ["_uav"];
  
    private _prevWpPos1 = (_uav getVariable ["RC_prevWpPos1", 0]);
    private _prevWpPos2 = (_uav getVariable ["RC_prevWpPos2", 0]);
    private _prevWpPos3 = (_uav getVariable ["RC_prevWpPos3", 0]);
    private _curWpPos1 = (waypointPosition [_uav, 1]) select 1;
    private _curWpPos2 = (waypointPosition [_uav, 2]) select 1;
    private _curWpPos3 = (waypointPosition [_uav, 3]) select 1;

    if (((_curWpPos1 isNotEqualTo _prevWpPos1))) then {

        private _driverGroup = group (driver _uav);
        private _playerID = clientOwner;
        [_driverGroup, _playerID] remoteExec ['setGroupOwner', 2];

        [_uav, ["RC_prevWpPos1", _curWpPos1]] remoteExec ["setVariable", 0];
    };
    if (((_curWpPos2 isNotEqualTo _prevWpPos2))) then {

        private _driverGroup = group (driver _uav);
        private _playerID = clientOwner;
        [_driverGroup, _playerID] remoteExec ['setGroupOwner', 2];

        [_uav, ["RC_prevWpPos2", _curWpPos2]] remoteExec ["setVariable", 0];
    };
    if (((_curWpPos3 isNotEqualTo _prevWpPos3))) then {

        private _driverGroup = group (driver _uav);
        private _playerID = clientOwner;
        [_driverGroup, _playerID] remoteExec ['setGroupOwner', 2];

        [_uav, ["RC_prevWpPos3", _curWpPos3]] remoteExec ["setVariable", 0];
    };

    private _prevWpCount = (_uav getVariable ["RC_prevWpCount", 0]);
    private _curWpCount = count (waypoints _uav);
    if (_curWpCount != _prevWpCount) then {

        private _driverGroup = group (driver _uav);
        private _playerID = clientOwner;
        [_driverGroup, _playerID] remoteExec ['setGroupOwner', 2];

        [_uav, ["RC_prevWpCount", _curWpCount]] remoteExec ["setVariable", 0];
    };
};
*/

/*
RC_fnc_uavWaypointsTest =
{
    params ["_uav"];
  
    private _prevWpPos1 = (_uav getVariable ["RC_prevWpPos1", 0]);
    private _prevWpPos2 = (_uav getVariable ["RC_prevWpPos2", 0]);
    private _prevWpPos3 = (_uav getVariable ["RC_prevWpPos3", 0]);
    private _curWpPos1 = (waypointPosition [_uav, 1]) select 1;
    private _curWpPos2 = (waypointPosition [_uav, 2]) select 1;
    private _curWpPos3 = (waypointPosition [_uav, 3]) select 1;

    if (((_curWpPos1 isNotEqualTo _prevWpPos1))) then {

        private _driverGroup = group (driver _uav);
        private _playerID = clientOwner;
        [_driverGroup, _playerID] remoteExec ['setGroupOwner', 2];

        [_uav, ["RC_prevWpPos1", _curWpPos1]] remoteExec ["setVariable", 0, true];
    };
    if (((_curWpPos2 isNotEqualTo _prevWpPos2))) then {

        private _driverGroup = group (driver _uav);
        private _playerID = clientOwner;
        [_driverGroup, _playerID] remoteExec ['setGroupOwner', 2];

        [_uav, ["RC_prevWpPos2", _curWpPos2]] remoteExec ["setVariable", 0, true];
    };
    if (((_curWpPos3 isNotEqualTo _prevWpPos3))) then {

        private _driverGroup = group (driver _uav);
        private _playerID = clientOwner;
        [_driverGroup, _playerID] remoteExec ['setGroupOwner', 2];

        [_uav, ["RC_prevWpPos3", _curWpPos3]] remoteExec ["setVariable", 0, true];
    };

    private _prevWpCount = (_uav getVariable ["RC_prevWpCount", 0]);
    private _curWpCount = count (waypoints _uav);
    if (_curWpCount != _prevWpCount) then {

        private _driverGroup = group (driver _uav);
        private _playerID = clientOwner;
        [_driverGroup, _playerID] remoteExec ['setGroupOwner', 2];

        [_uav, ["RC_prevWpCount", _curWpCount]] remoteExec ["setVariable", 0, true];
    };
};
*/