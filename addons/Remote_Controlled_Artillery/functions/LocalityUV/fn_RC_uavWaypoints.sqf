params ["_uav"];

private _prevWpPos1 = [_uav, "RC_prevWpPos1", 0] call BIS_fnc_getServerVariable;
private _prevWpPos2 = [_uav, "RC_prevWpPos2", 0] call BIS_fnc_getServerVariable;
private _prevWpPos3 = [_uav, "RC_prevWpPos3", 0] call BIS_fnc_getServerVariable;
private _curWpPos1 = (waypointPosition [_uav, 1]) select 1;
private _curWpPos2 = (waypointPosition [_uav, 2]) select 1;
private _curWpPos3 = (waypointPosition [_uav, 3]) select 1;

if (((_curWpPos1 isNotEqualTo _prevWpPos1) or (_curWpPos2 isNotEqualTo _prevWpPos2) or (_curWpPos3 isNotEqualTo _prevWpPos3))) then {

    if (!(local _uav)) then {
        [_uav] call RC_fnc_RC_uavChangeLocality;
    };

    [_uav, "RC_prevWpPos1", _curWpPos1] call BIS_fnc_setServerVariable;
    [_uav, "RC_prevWpPos2", _curWpPos2] call BIS_fnc_setServerVariable;
    [_uav, "RC_prevWpPos3", _curWpPos3] call BIS_fnc_setServerVariable;
};

private _prevWpCount = [_uav, "RC_prevWpCount", 0] call BIS_fnc_getServerVariable;
private _curWpCount = count (waypoints _uav);
if (_curWpCount != _prevWpCount) then {

    if (!(local _uav)) then {
        [_uav] call RC_fnc_RC_uavChangeLocality;
    };

    [_uav, "RC_prevWpCount", _curWpCount] call BIS_fnc_setServerVariable;
};