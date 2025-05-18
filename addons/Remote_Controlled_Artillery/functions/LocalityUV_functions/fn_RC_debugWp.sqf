//REMOVE DEFINE
params ["_uav"];

[player, "terminal open"] remoteExec ['globalChat', 0];

private _prevWpPos1 = (_uav getVariable ["RC_prevWpPos1", [0,0,0]]);
private _prevWpPos2 = (_uav getVariable ["RC_prevWpPos2", [0,0,0]]);
private _prevWpPos3 = (_uav getVariable ["RC_prevWpPos3", [0,0,0]]);
private _curWpPos1 = (waypointPosition [_uav, 1]) select 1;
private _curWpPos2 = (waypointPosition [_uav, 2]) select 1;
private _curWpPos3 = (waypointPosition [_uav, 3]) select 1;

if (((_curWpPos1 isNotEqualTo _prevWpPos1) or (_curWpPos2 isNotEqualTo _prevWpPos2) or (_curWpPos3 isNotEqualTo _prevWpPos3))) then {

    private _driverGroup = group (driver _uav);
    private _playerID = clientOwner;
    [_driverGroup, _playerID] remoteExec ['setGroupOwner', 2];

    _prevWpPos1STR = str _prevWpPos1;
    _curWpPos1STR = str _curWpPos1;
    [player, "changed locality (wpPos): " + _prevWpPos1STR + " -> " + _curWpPos1STR] remoteExec ['globalChat', 0];
    _prevWpPos2STR = str _prevWpPos2;
    _curWpPos2STR = str _curWpPos2;
    [player, "changed locality (wpPos): " + _prevWpPos2STR + " -> " + _curWpPos2STR] remoteExec ['globalChat', 0];
    _prevWpPos3STR = str _prevWpPos3;
    _curWpPos3STR = str _curWpPos3;
    [player, "changed locality (wpPos): " + _prevWpPos3STR + " -> " + _curWpPos3STR] remoteExec ['globalChat', 0];

    _uav setVariable ["RC_prevWpPos1", _curWpPos1];
    _uav setVariable ["RC_prevWpPos2", _curWpPos2];
    _uav setVariable ["RC_prevWpPos3", _curWpPos3];
};

private _prevWpCount = (_uav getVariable ["RC_prevWpCount", 0]);
private _curWpCount = count (waypoints _uav);
if (_curWpCount != _prevWpCount) then {

    private _driverGroup = group (driver _uav);
    private _playerID = clientOwner;
    [_driverGroup, _playerID] remoteExec ['setGroupOwner', 2];

    _prevWpCountSTR = str _prevWpCount;
    _curWpCountSTR = str _curWpCount;
    [player, "changed locality (wpCount): " + _prevWpCountSTR + " -> " + _curWpCountSTR] remoteExec ['globalChat', 0];
    
    _uav setVariable ["RC_prevWpCount", _curWpCount];
};


/*
RC_fnc_debugWpTest =
{
    params ["_uav"];

    [player, "terminal open"] remoteExec ['globalChat', 0];

    private _prevWpPos1 = (_uav getVariable ["RC_prevWpPos1", [0,0,0]]);
    private _prevWpPos2 = (_uav getVariable ["RC_prevWpPos2", [0,0,0]]);
    private _prevWpPos3 = (_uav getVariable ["RC_prevWpPos3", [0,0,0]]);
    private _curWpPos1 = (waypointPosition [_uav, 1]) select 1;
    private _curWpPos2 = (waypointPosition [_uav, 2]) select 1;
    private _curWpPos3 = (waypointPosition [_uav, 3]) select 1;

    if (((_curWpPos1 isNotEqualTo _prevWpPos1) or (_curWpPos2 isNotEqualTo _prevWpPos2) or (_curWpPos3 isNotEqualTo _prevWpPos3))) then {

        private _driverGroup = group (driver _uav);
        private _playerID = clientOwner;
        [_driverGroup, _playerID] remoteExec ['setGroupOwner', 2];

        _prevWpPos1STR = str _prevWpPos1;
        _curWpPos1STR = str _curWpPos1;
        [player, "changed locality (wpPos): " + _prevWpPos1STR + " -> " + _curWpPos1STR] remoteExec ['globalChat', 0];
        _prevWpPos2STR = str _prevWpPos2;
        _curWpPos2STR = str _curWpPos2;
        [player, "changed locality (wpPos): " + _prevWpPos2STR + " -> " + _curWpPos2STR] remoteExec ['globalChat', 0];
        _prevWpPos3STR = str _prevWpPos3;
        _curWpPos3STR = str _curWpPos3;
        [player, "changed locality (wpPos): " + _prevWpPos3STR + " -> " + _curWpPos3STR] remoteExec ['globalChat', 0];

        _uav setVariable ["RC_prevWpPos1", _curWpPos1];
        _uav setVariable ["RC_prevWpPos2", _curWpPos2];
        _uav setVariable ["RC_prevWpPos3", _curWpPos3];
    };

    private _prevWpCount = (_uav getVariable ["RC_prevWpCount", 0]);
    private _curWpCount = count (waypoints _uav);
    if (_curWpCount != _prevWpCount) then {

        private _driverGroup = group (driver _uav);
        private _playerID = clientOwner;
        [_driverGroup, _playerID] remoteExec ['setGroupOwner', 2];

        _prevWpCountSTR = str _prevWpCount;
        _curWpCountSTR = str _curWpCount;
        [player, "changed locality (wpCount): " + _prevWpCountSTR + " -> " + _curWpCountSTR] remoteExec ['globalChat', 0];
        
        _uav setVariable ["RC_prevWpCount", _curWpCount];
    };
};
*/