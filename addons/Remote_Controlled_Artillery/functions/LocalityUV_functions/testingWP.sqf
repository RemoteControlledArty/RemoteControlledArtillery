RC_fnc_debugWaypoints =
{
    params ["_uav"];

    [player, "terminal open"] remoteExec ['globalChat', clientowner];

    private _prevWpPos1 = [_uav, "RC_prevWpPos1", 0] call BIS_fnc_getServerVariable;
    private _prevWpPos2 = [_uav, "RC_prevWpPos2", 0] call BIS_fnc_getServerVariable;
    private _prevWpPos3 = [_uav, "RC_prevWpPos3", 0] call BIS_fnc_getServerVariable;
    private _curWpPos1 = (waypointPosition [_uav, 1]) select 1;
    private _curWpPos2 = (waypointPosition [_uav, 2]) select 1;
    private _curWpPos3 = (waypointPosition [_uav, 3]) select 1;

    if (((_curWpPos1 isNotEqualTo _prevWpPos1) or (_curWpPos2 isNotEqualTo _prevWpPos2) or (_curWpPos3 isNotEqualTo _prevWpPos3))) then {

        if (!(local _uav)) then {
            [_uav] call RC_fnc_RC_uavChangeLocality;

            [player, "localized"] remoteExec ['globalChat', 0];
        };

        [player, "wp1: " + str _prevWpPos1 + " -> " + str _curWpPos1] remoteExec ['globalChat', 0];
        [player, "wp2: " + str _prevWpPos2 + " -> " + str _curWpPos2] remoteExec ['globalChat', 0];
        [player, "wp3: " + str _prevWpPos3 + " -> " + str _curWpPos3] remoteExec ['globalChat', 0];

        [_uav, "RC_prevWpPos1", _curWpPos1] call BIS_fnc_setServerVariable;
        [_uav, "RC_prevWpPos2", _curWpPos2] call BIS_fnc_setServerVariable;
        [_uav, "RC_prevWpPos3", _curWpPos3] call BIS_fnc_setServerVariable;
    };

    private _prevWpCount = [_uav, "RC_prevWpCount", 0] call BIS_fnc_getServerVariable;
    private _curWpCount = count (waypoints _uav);
    if (_curWpCount != _prevWpCount) then {

        if (!(local _uav)) then {
            [_uav] call RC_fnc_RC_uavChangeLocality;

            [player, "localized"] remoteExec ['globalChat', 0];
        };

        [player, "wpCount: " + str _prevWpCount + " -> " + str _curWpCount] remoteExec ['globalChat', 0];

        [_uav, "RC_prevWpCount", _curWpCount] call BIS_fnc_setServerVariable;
    };
};




params ["_uav"];

[player, "terminal open"] remoteExec ['globalChat', clientowner];

private _prevWpPos1 = [_uav, "RC_prevWpPos1", 0] call BIS_fnc_getServerVariable;
private _prevWpPos2 = [_uav, "RC_prevWpPos2", 0] call BIS_fnc_getServerVariable;
private _prevWpPos3 = [_uav, "RC_prevWpPos3", 0] call BIS_fnc_getServerVariable;
private _curWpPos1 = (waypointPosition [_uav, 1]) select 1;
private _curWpPos2 = (waypointPosition [_uav, 2]) select 1;
private _curWpPos3 = (waypointPosition [_uav, 3]) select 1;

if (((_curWpPos1 isNotEqualTo _prevWpPos1) or (_curWpPos2 isNotEqualTo _prevWpPos2) or (_curWpPos3 isNotEqualTo _prevWpPos3))) then {

    if (!local _uav) then {
        private _driverGroup = group (driver _uav);
        private _playerID = clientOwner;
        [_driverGroup, _playerID] remoteExec ['setGroupOwner', 2];

        [player, "localized"] remoteExec ['globalChat', 0];
    };

    [player, "wp1: " + str _prevWpPos1 + " -> " + str _curWpPos1] remoteExec ['globalChat', 0];
    [player, "wp2: " + str _prevWpPos2 + " -> " + str _curWpPos2] remoteExec ['globalChat', 0];
    [player, "wp3: " + str _prevWpPos3 + " -> " + str _curWpPos3] remoteExec ['globalChat', 0];

    [_uav, "RC_prevWpPos1", _curWpPos1] call BIS_fnc_setServerVariable;
    [_uav, "RC_prevWpPos2", _curWpPos2] call BIS_fnc_setServerVariable;
    [_uav, "RC_prevWpPos3", _curWpPos3] call BIS_fnc_setServerVariable;
};

private _prevWpCount = [_uav, "RC_prevWpCount", 0] call BIS_fnc_getServerVariable;
private _curWpCount = count (waypoints _uav);
if (_curWpCount != _prevWpCount) then {

    if (!local _uav) then {
        private _driverGroup = group (driver _uav);
        private _playerID = clientOwner;
        [_driverGroup, _playerID] remoteExec ['setGroupOwner', 2];

        [player, "localized"] remoteExec ['globalChat', 0];
    };

    [player, "wpCount: " + str _prevWpCount + " -> " + str _curWpCount] remoteExec ['globalChat', 0];

    [_uav, "RC_prevWpCount", _curWpCount] call BIS_fnc_setServerVariable;
};



RC_fnc_uavWaypointsTest1 =
{
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
};


RC_fnc_debugWaypointsTestRE =
{
    params ["_uav"];

    [player, "terminal open"] remoteExec ['globalChat', clientowner];

    private _prevWpPos1 = (_uav getVariable ["RC_prevWpPos1", 0]);
    private _prevWpPos2 = (_uav getVariable ["RC_prevWpPos2", 0]);
    private _prevWpPos3 = (_uav getVariable ["RC_prevWpPos3", 0]);
    private _curWpPos1 = (waypointPosition [_uav, 1]) select 1;
    private _curWpPos2 = (waypointPosition [_uav, 2]) select 1;
    private _curWpPos3 = (waypointPosition [_uav, 3]) select 1;

    if (((_curWpPos1 isNotEqualTo _prevWpPos1) or (_curWpPos2 isNotEqualTo _prevWpPos2) or (_curWpPos3 isNotEqualTo _prevWpPos3))) then {

        private _driverGroup = group (driver _uav);
        private _playerID = clientOwner;
        [_driverGroup, _playerID] remoteExec ['setGroupOwner', 2];

        [player, "localized, wp1: " + str _prevWpPos1 + " -> " + str _curWpPos1] remoteExec ['globalChat', 0];
        [player, "localized, wp2: " + str _prevWpPos2 + " -> " + str _curWpPos2] remoteExec ['globalChat', 0];
        [player, "localized, wp3: " + str _prevWpPos3 + " -> " + str _curWpPos3] remoteExec ['globalChat', 0];

        [_uav, ["RC_prevWpPos1", _curWpPos1]] remoteExec ["setVariable", 0];
        [_uav, ["RC_prevWpPos2", _curWpPos2]] remoteExec ["setVariable", 0];
        [_uav, ["RC_prevWpPos3", _curWpPos3]] remoteExec ["setVariable", 0];
    };

    private _prevWpCount = (_uav getVariable ["RC_prevWpCount", 0]);
    private _curWpCount = count (waypoints _uav);
    if (_curWpCount != _prevWpCount) then {

        private _driverGroup = group (driver _uav);
        private _playerID = clientOwner;
        [_driverGroup, _playerID] remoteExec ['setGroupOwner', 2];

        [player, "localized, wpCount: " + str _prevWpCount + " -> " + str _curWpCount] remoteExec ['globalChat', 0];
        [_uav, ["RC_prevWpCount", _curWpCount]] remoteExec ["setVariable", 0];
    };
};


RC_fnc_debugWaypointsTestREJIP =
{
    params ["_uav"];

    [player, "terminal open"] remoteExec ['globalChat', clientowner];

    private _prevWpPos1 = (_uav getVariable ["RC_prevWpPos1", 0]);
    private _prevWpPos2 = (_uav getVariable ["RC_prevWpPos2", 0]);
    private _prevWpPos3 = (_uav getVariable ["RC_prevWpPos3", 0]);
    private _curWpPos1 = (waypointPosition [_uav, 1]) select 1;
    private _curWpPos2 = (waypointPosition [_uav, 2]) select 1;
    private _curWpPos3 = (waypointPosition [_uav, 3]) select 1;

    if (((_curWpPos1 isNotEqualTo _prevWpPos1) or (_curWpPos2 isNotEqualTo _prevWpPos2) or (_curWpPos3 isNotEqualTo _prevWpPos3))) then {

        private _driverGroup = group (driver _uav);
        private _playerID = clientOwner;
        [_driverGroup, _playerID] remoteExec ['setGroupOwner', 2];

        [player, "localized, wp1: " + str _prevWpPos1 + " -> " + str _curWpPos1] remoteExec ['globalChat', 0];
        [player, "localized, wp2: " + str _prevWpPos2 + " -> " + str _curWpPos2] remoteExec ['globalChat', 0];
        [player, "localized, wp3: " + str _prevWpPos3 + " -> " + str _curWpPos3] remoteExec ['globalChat', 0];

        [_uav, ["RC_prevWpPos1", _curWpPos1]] remoteExec ["setVariable", 0, true];
        [_uav, ["RC_prevWpPos2", _curWpPos2]] remoteExec ["setVariable", 0, true];
        [_uav, ["RC_prevWpPos3", _curWpPos3]] remoteExec ["setVariable", 0, true];
    };

    private _prevWpCount = (_uav getVariable ["RC_prevWpCount", 0]);
    private _curWpCount = count (waypoints _uav);
    if (_curWpCount != _prevWpCount) then {

        private _driverGroup = group (driver _uav);
        private _playerID = clientOwner;
        [_driverGroup, _playerID] remoteExec ['setGroupOwner', 2];

        [player, "localized, wpCount: " + str _prevWpCount + " -> " + str _curWpCount] remoteExec ['globalChat', 0];
        [_uav, ["RC_prevWpCount", _curWpCount]] remoteExec ["setVariable", 0, true];
    };
};


RC_fnc_debugWaypointsTestPublic =
{
    params ["_uav"];

    [player, "terminal open"] remoteExec ['globalChat', clientowner];

    private _prevWpPos1 = (_uav getVariable ["RC_prevWpPos1", 0]);
    private _prevWpPos2 = (_uav getVariable ["RC_prevWpPos2", 0]);
    private _prevWpPos3 = (_uav getVariable ["RC_prevWpPos3", 0]);
    private _curWpPos1 = (waypointPosition [_uav, 1]) select 1;
    private _curWpPos2 = (waypointPosition [_uav, 2]) select 1;
    private _curWpPos3 = (waypointPosition [_uav, 3]) select 1;

    if (((_curWpPos1 isNotEqualTo _prevWpPos1) or (_curWpPos2 isNotEqualTo _prevWpPos2) or (_curWpPos3 isNotEqualTo _prevWpPos3))) then {

        private _driverGroup = group (driver _uav);
        private _playerID = clientOwner;
        [_driverGroup, _playerID] remoteExec ['setGroupOwner', 2];

        [player, "localized, wp1: " + str _prevWpPos1 + " -> " + str _curWpPos1] remoteExec ['globalChat', 0];
        [player, "localized, wp2: " + str _prevWpPos2 + " -> " + str _curWpPos2] remoteExec ['globalChat', 0];
        [player, "localized, wp3: " + str _prevWpPos3 + " -> " + str _curWpPos3] remoteExec ['globalChat', 0];

        waituntil {local _uav; sleep 0.1};
        _uav setVariable ["RC_prevWpPos1", _curWpPos1, true];
        _uav setVariable ["RC_prevWpPos2", _curWpPos2, true];
        _uav setVariable ["RC_prevWpPos3", _curWpPos3, true];
    };

    private _prevWpCount = (_uav getVariable ["RC_prevWpCount", 0]);
    private _curWpCount = count (waypoints _uav);
    if (_curWpCount != _prevWpCount) then {

        private _driverGroup = group (driver _uav);
        private _playerID = clientOwner;
        [_driverGroup, _playerID] remoteExec ['setGroupOwner', 2];

        [player, "localized, wpCount: " + str _prevWpCount + " -> " + str _curWpCount] remoteExec ['globalChat', 0];

        waituntil {local _uav; sleep 0.1};
        _uav setVariable ["RC_prevWpCount", _curWpCount, true];
    };
};


RC_fnc_debugWaypointsTestServer =
{
    params ["_uav"];

    [player, "terminal open"] remoteExec ['globalChat', clientowner];

    private _prevWpPos1 = [_uav, "RC_prevWpPos1", 0] call BIS_fnc_getServerVariable;
    private _prevWpPos2 = [_uav, "RC_prevWpPos2", 0] call BIS_fnc_getServerVariable;
    private _prevWpPos3 = [_uav, "RC_prevWpPos3", 0] call BIS_fnc_getServerVariable;
    private _curWpPos1 = (waypointPosition [_uav, 1]) select 1;
    private _curWpPos2 = (waypointPosition [_uav, 2]) select 1;
    private _curWpPos3 = (waypointPosition [_uav, 3]) select 1;

    if (((_curWpPos1 isNotEqualTo _prevWpPos1) or (_curWpPos2 isNotEqualTo _prevWpPos2) or (_curWpPos3 isNotEqualTo _prevWpPos3))) then {

        private _driverGroup = group (driver _uav);
        private _playerID = clientOwner;
        [_driverGroup, _playerID] remoteExec ['setGroupOwner', 2];

        [player, "localized, wp1: " + str _prevWpPos1 + " -> " + str _curWpPos1] remoteExec ['globalChat', 0];
        [player, "localized, wp2: " + str _prevWpPos2 + " -> " + str _curWpPos2] remoteExec ['globalChat', 0];
        [player, "localized, wp3: " + str _prevWpPos3 + " -> " + str _curWpPos3] remoteExec ['globalChat', 0];

        [_uav, "RC_prevWpPos1", _curWpPos1] call BIS_fnc_setServerVariable;
        [_uav, "RC_prevWpPos2", _curWpPos2] call BIS_fnc_setServerVariable;
        [_uav, "RC_prevWpPos3", _curWpPos3] call BIS_fnc_setServerVariable;
    };

    private _prevWpCount = [_uav, "RC_prevWpCount", 0] call BIS_fnc_getServerVariable;
    private _curWpCount = count (waypoints _uav);
    if (_curWpCount != _prevWpCount) then {

        private _driverGroup = group (driver _uav);
        private _playerID = clientOwner;
        [_driverGroup, _playerID] remoteExec ['setGroupOwner', 2];

        [player, "localized, wpCount: " + str _prevWpCount + " -> " + str _curWpCount] remoteExec ['globalChat', 0];

        [_uav, "RC_prevWpCount", _curWpCount] call BIS_fnc_setServerVariable;
    };
};


//Current
RC_fnc_debugWaypointsCurrent =
{
    params ["_uav"];

    [player, "terminal open"] remoteExec ['globalChat', clientowner];

    private _curWpPos1 = (waypointPosition [_uav, 1]) select 1;
    private _curWpPos2 = (waypointPosition [_uav, 2]) select 1;
    private _curWpPos3 = (waypointPosition [_uav, 3]) select 1;

    private _curWpCount = count (waypoints _uav);
};


//Server setVariable
RC_fnc_debugWaypointsSetVar =
{
    params ["_uav"];

    [player, "terminal open"] remoteExec ['globalChat', clientowner];

    private _curWpPos1 = (waypointPosition [_uav, 1]) select 1;
    private _curWpPos2 = (waypointPosition [_uav, 2]) select 1;
    private _curWpPos3 = (waypointPosition [_uav, 3]) select 1;

    if (((_curWpPos1 isNotEqualTo _prevWpPos1) or (_curWpPos2 isNotEqualTo _prevWpPos2) or (_curWpPos3 isNotEqualTo _prevWpPos3))) then {

        private _driverGroup = group (driver _uav);
        private _playerID = clientOwner;
        [_driverGroup, _playerID] remoteExec ['setGroupOwner', 2];

        [player, "localized, wp1: " + str _prevWpPos1 + " -> " + str _curWpPos1] remoteExec ['globalChat', 0];
        [player, "localized, wp2: " + str _prevWpPos2 + " -> " + str _curWpPos2] remoteExec ['globalChat', 0];
        [player, "localized, wp3: " + str _prevWpPos3 + " -> " + str _curWpPos3] remoteExec ['globalChat', 0];

        [_uav, "RC_prevWpPos1", _curWpPos1] call BIS_fnc_setServerVariable;
        [_uav, "RC_prevWpPos2", _curWpPos2] call BIS_fnc_setServerVariable;
        [_uav, "RC_prevWpPos3", _curWpPos3] call BIS_fnc_setServerVariable;
    };

    private _prevWpCount = [_uav, "RC_prevWpCount", 0] call BIS_fnc_getServerVariable;
    private _curWpCount = count (waypoints _uav);
    if (_curWpCount != _prevWpCount) then {

        private _driverGroup = group (driver _uav);
        private _playerID = clientOwner;
        [_driverGroup, _playerID] remoteExec ['setGroupOwner', 2];

        [player, "localized, wpCount: " + str _prevWpCount + " -> " + str _curWpCount] remoteExec ['globalChat', 0];

        [_uav, "RC_prevWpCount", _curWpCount] call BIS_fnc_setServerVariable;
    };
};

//Server getVariable & locality change
RC_fnc_debugWaypointsGetVar =
{
    params ["_uav"];

    [player, "terminal open"] remoteExec ['globalChat', clientowner];

    private _prevWpPos1 = [_uav, "RC_prevWpPos1", 0] call BIS_fnc_getServerVariable;
    private _prevWpPos2 = [_uav, "RC_prevWpPos2", 0] call BIS_fnc_getServerVariable;
    private _prevWpPos3 = [_uav, "RC_prevWpPos3", 0] call BIS_fnc_getServerVariable;
    private _curWpPos1 = (waypointPosition [_uav, 1]) select 1;
    private _curWpPos2 = (waypointPosition [_uav, 2]) select 1;
    private _curWpPos3 = (waypointPosition [_uav, 3]) select 1;

    if (((_curWpPos1 isNotEqualTo _prevWpPos1) or (_curWpPos2 isNotEqualTo _prevWpPos2) or (_curWpPos3 isNotEqualTo _prevWpPos3))) then {

        private _driverGroup = group (driver _uav);
        private _playerID = clientOwner;
        [_driverGroup, _playerID] remoteExec ['setGroupOwner', 2];

        [player, "localized, wp1: " + str _prevWpPos1 + " -> " + str _curWpPos1] remoteExec ['globalChat', 0];
        [player, "localized, wp2: " + str _prevWpPos2 + " -> " + str _curWpPos2] remoteExec ['globalChat', 0];
        [player, "localized, wp3: " + str _prevWpPos3 + " -> " + str _curWpPos3] remoteExec ['globalChat', 0];

        [_uav, "RC_prevWpPos1", _curWpPos1] call BIS_fnc_setServerVariable;
        [_uav, "RC_prevWpPos2", _curWpPos2] call BIS_fnc_setServerVariable;
        [_uav, "RC_prevWpPos3", _curWpPos3] call BIS_fnc_setServerVariable;
    };

    private _prevWpCount = [_uav, "RC_prevWpCount", 0] call BIS_fnc_getServerVariable;
    private _curWpCount = count (waypoints _uav);
    if (_curWpCount != _prevWpCount) then {

        private _driverGroup = group (driver _uav);
        private _playerID = clientOwner;
        [_driverGroup, _playerID] remoteExec ['setGroupOwner', 2];

        [player, "localized, wpCount: " + str _prevWpCount + " -> " + str _curWpCount] remoteExec ['globalChat', 0];

        [_uav, "RC_prevWpCount", _curWpCount] call BIS_fnc_setServerVariable;
    };
};


//SHOULD WORK
//Server all in one, localize if not local
RC_fnc_debugWaypointsGetVar =
{
    params ["_uav"];

    [player, "terminal open"] remoteExec ['globalChat', clientowner];

    private _prevWpPos1 = [_uav, "RC_prevWpPos1", 0] call BIS_fnc_getServerVariable;
    private _prevWpPos2 = [_uav, "RC_prevWpPos2", 0] call BIS_fnc_getServerVariable;
    private _prevWpPos3 = [_uav, "RC_prevWpPos3", 0] call BIS_fnc_getServerVariable;
    private _curWpPos1 = (waypointPosition [_uav, 1]) select 1;
    private _curWpPos2 = (waypointPosition [_uav, 2]) select 1;
    private _curWpPos3 = (waypointPosition [_uav, 3]) select 1;

    if (((_curWpPos1 isNotEqualTo _prevWpPos1) or (_curWpPos2 isNotEqualTo _prevWpPos2) or (_curWpPos3 isNotEqualTo _prevWpPos3))) then {

        if (!local _uav) then {
            private _driverGroup = group (driver _uav);
            private _playerID = clientOwner;
            [_driverGroup, _playerID] remoteExec ['setGroupOwner', 2];

            [player, "localized"] remoteExec ['globalChat', 0];
        };

        [player, "wp1: " + str _prevWpPos1 + " -> " + str _curWpPos1] remoteExec ['globalChat', 0];
        [player, "wp2: " + str _prevWpPos2 + " -> " + str _curWpPos2] remoteExec ['globalChat', 0];
        [player, "wp3: " + str _prevWpPos3 + " -> " + str _curWpPos3] remoteExec ['globalChat', 0];

        [_uav, "RC_prevWpPos1", _curWpPos1] call BIS_fnc_setServerVariable;
        [_uav, "RC_prevWpPos2", _curWpPos2] call BIS_fnc_setServerVariable;
        [_uav, "RC_prevWpPos3", _curWpPos3] call BIS_fnc_setServerVariable;
    };

    private _prevWpCount = [_uav, "RC_prevWpCount", 0] call BIS_fnc_getServerVariable;
    private _curWpCount = count (waypoints _uav);
    if (_curWpCount != _prevWpCount) then {

        if (!local _uav) then {
            private _driverGroup = group (driver _uav);
            private _playerID = clientOwner;
            [_driverGroup, _playerID] remoteExec ['setGroupOwner', 2];

            [player, "localized"] remoteExec ['globalChat', 0];
        };

        [player, "wpCount: " + str _prevWpCount + " -> " + str _curWpCount] remoteExec ['globalChat', 0];

        [_uav, "RC_prevWpCount", _curWpCount] call BIS_fnc_setServerVariable;
    };
};



        //RE no JIP
        [_uav, ["RC_prevWpPos1", _curWpPos1]] remoteExec ["setVariable", 0, true];
        [_uav, ["RC_prevWpPos2", _curWpPos2]] remoteExec ["setVariable", 0, true];
        [_uav, ["RC_prevWpPos3", _curWpPos3]] remoteExec ["setVariable", 0, true];

        [_uav, ["RC_prevWpCount", _curWpCount]] remoteExec ["setVariable", 0, true];


        //RE no JIP
        [_uav, ["RC_prevWpPos1", _curWpPos1]] remoteExec ["setVariable", 0];
        [_uav, ["RC_prevWpPos2", _curWpPos2]] remoteExec ["setVariable", 0];
        [_uav, ["RC_prevWpPos3", _curWpPos3]] remoteExec ["setVariable", 0];

        [_uav, ["RC_prevWpCount", _curWpCount]] remoteExec ["setVariable", 0];


        //setvariable public, no RE
        //sleep!
        _uav setVariable ["RC_prevWpPos1", _curWpPos1, true];
        _uav setVariable ["RC_prevWpPos2", _curWpPos2, true];
        _uav setVariable ["RC_prevWpPos3", _curWpPos3, true];

        _uav setVariable ["RC_prevWpCount", _curWpCount, true];


        //setvariable public, no RE
        //sleep?
        private _prevWpPos1 = [_uav, "RC_prevWpPos1", 0] call BIS_fnc_getServerVariable;
        private _prevWpPos2 = [_uav, "RC_prevWpPos2", 0] call BIS_fnc_getServerVariable;
        private _prevWpPos3 = [_uav, "RC_prevWpPos3", 0] call BIS_fnc_getServerVariable;

        [_uav, "RC_prevWpPos1", _curWpPos1] call BIS_fnc_setServerVariable;
        [_uav, "RC_prevWpPos2", _curWpPos2] call BIS_fnc_setServerVariable;
        [_uav, "RC_prevWpPos3", _curWpPos3] call BIS_fnc_setServerVariable;

        private _prevWpCount = [_uav, "RC_prevWpCount", 0] call BIS_fnc_getServerVariable;

        [_uav, "RC_prevWpCount", _curWpCount] call BIS_fnc_setServerVariable;





























params ["_uav"];

[player, "terminal open"] remoteExec ['globalChat', 0];

private _prevWpPos1 = (_uav getVariable ["RC_prevWpPos1", 0]);
private _prevWpPos2 = (_uav getVariable ["RC_prevWpPos2", 0]);
private _prevWpPos3 = (_uav getVariable ["RC_prevWpPos3", 0]);
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




RC_fnc_debugWaypointsTest =
{
    params ["_uav"];

    [player, "terminal open"] remoteExec ['globalChat', 0];

    private _prevWpPos1 = (_uav getVariable ["RC_prevWpPos1", 0]);
    private _prevWpPos2 = (_uav getVariable ["RC_prevWpPos2", 0]);
    private _prevWpPos3 = (_uav getVariable ["RC_prevWpPos3", 0]);
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


RC_fnc_debugWaypointsTest =
{
    params ["_uav"];
    [player, "opend terminal"] remoteExec ['globalChat', 0];
    
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

        _prevWpPos1STR = str _prevWpPos1;
        _curWpPos1STR = str _curWpPos1;
        [player, "changed locality (wpPos1): " + _prevWpPos1STR + " -> " + _curWpPos1STR] remoteExec ['globalChat', 0];

        [_uav, ["RC_prevWpPos1", _curWpPos1]] remoteExec ["setVariable", 0, true];
    };
    if (((_curWpPos2 isNotEqualTo _prevWpPos2))) then {

        private _driverGroup = group (driver _uav);
        private _playerID = clientOwner;
        [_driverGroup, _playerID] remoteExec ['setGroupOwner', 2];

        _prevWpPos2STR = str _prevWpPos2;
        _curWpPos2STR = str _curWpPos2;
        [player, "changed locality (wpPos2): " + _prevWpPos2STR + " -> " + _curWpPos2STR] remoteExec ['globalChat', 0];

        [_uav, ["RC_prevWpPos2", _curWpPos2]] remoteExec ["setVariable", 0, true];
    };
    if (((_curWpPos3 isNotEqualTo _prevWpPos3))) then {

        private _driverGroup = group (driver _uav);
        private _playerID = clientOwner;
        [_driverGroup, _playerID] remoteExec ['setGroupOwner', 2];

        _prevWpPos3STR = str _prevWpPos3;
        _curWpPos3STR = str _curWpPos3;
        [player, "changed locality (wpPos3): " + _prevWpPos3STR + " -> " + _curWpPos3STR] remoteExec ['globalChat', 0];

        [_uav, ["RC_prevWpPos3", _curWpPos3]] remoteExec ["setVariable", 0, true];
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

        [_uav, ["RC_prevWpCount", _curWpCount]] remoteExec ["setVariable", 0, true];
    } else {
        [player, "same waypoints"] remoteExec ['globalChat', 0];
    };
};


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
    } else {
        [player, "same waypoints"] remoteExec ['globalChat', 0];
    };
};
*/