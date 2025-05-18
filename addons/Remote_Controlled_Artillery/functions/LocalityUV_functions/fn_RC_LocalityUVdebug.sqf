/*
	Author: Ascent

	Description:
	Fixes multiplayer locality of UAV's/UGV's, to drive from UGV turret & set correct UAV altitude, without needing to first take driver control.
*/

if (isServer) then {RC_RCLocalHash = createHashMap;};
if (!hasInterface) exitWith {};

[] spawn {

	while {true} do {

		sleep 0.5;

		if (RC_FixLocalityOfRCUVs or RC_FixLocalityOfAllUVs) then {

			private _uav = getConnectedUAV player;

            [_uav] call RC_fnc_RC_debugContinue;

            private _uavClass = typeOf _uav;
            private _RCLocal = RC_RCLocalHash get _uavClass;

            [_uav] call RC_fnc_RC_debugHash;

			if ((_RCLocal != 0) or RC_FixLocalityOfAllUVs) then {

				if (!isNull (findDisplay 160)) then {
					[_uav] call RC_fnc_debugWaypoints;
				};

				if (isRemoteControlling player) then {
					[_uav] call RC_fnc_RC_debugChangeLocality;
				};
			};
		};
	};
};


//remote controlling maybe needs waypoint variables set on uav too?
//test: 2x player, !!!WPS used change to WP!!!

if (isServer) then {RC_RCLocalHash = createHashMap;};
if (!hasInterface) exitWith {};

[] spawn {
	
	_repeats = 80;

	while {true} do {

		_repeats = _repeats - 1;
		sleep 0.5;

		if (_repeats <= 0) exitwith {[player, "ended test"] remoteExec ['globalChat', 0];};

		if (RC_FixLocalityOfRCUVs or RC_FixLocalityOfAllUVs) then {

			private _uav = getConnectedUAV player;

			if (_uav isEqualto objNull) then {continue;};
			if (local _uav) then {continue;};

            private _uavClass = typeOf _uav;
            private _RCLocal = RC_RCLocalHash get _uavClass;

            [_uav] call RC_fnc_RC_debugHash;

			if ((_RCLocal != 0) or RC_FixLocalityOfAllUVs) then {

				if (!isNull (findDisplay 160)) then {
					[_uav] call RC_fnc_debugWaypointsTest;
				};

				if (isRemoteControlling player) then {
					[_uav] call RC_fnc_RC_debugChangeLocality;
				};
			};
		};
	};
};


//default values after spawned
private _uav = getConnectedUAV player;
private _curWpPos1 = (waypointPosition [_uav, 1]) select 1;
[player, "Wp1: " + str _curWpPos1] remoteExec ['globalChat', 0];
private _ServercurWpCount = count (waypoints _uav);
[player, "WpCount: " + str _ServercurWpCount] remoteExec ['globalChat', 0];



private _uav = getConnectedUAV player;
private _driverGroupServer = group (driver _uav);
[_driverGroupServer, 2] remoteExec ['setGroupOwner', 2];
[player, "SERVER locality"] remoteExec ['globalChat', 0];

private _uav = getConnectedUAV player;
private _prevWpPos1 = (_uav getVariable ["RC_prevWpPos1", 0]);
private _prevWpPos2 = (_uav getVariable ["RC_prevWpPos2", 0]);
private _prevWpPos3 = (_uav getVariable ["RC_prevWpPos3", 0]);
private _curWpPos1 = (waypointPosition [_uav, 1]) select 1;
private _curWpPos2 = (waypointPosition [_uav, 2]) select 1;
private _curWpPos3 = (waypointPosition [_uav, 3]) select 1;

[_uav, ["RC_prevWpPos1", _curWpPos1]] remoteExec ["setVariable", 0];
[_uav, ["RC_prevWpPos2", _curWpPos2]] remoteExec ["setVariable", 0];
[_uav, ["RC_prevWpPos3", _curWpPos3]] remoteExec ["setVariable", 0];

private _ServercurWpCount = count (waypoints _uav);
_uav setVariable ["RC_prevWpCount", _ServercurWpCount];
[player, "SERVER WpCount: " + str _ServercurWpCount] remoteExec ['globalChat', 0];



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


/*
//test: 1x player + server
if (isServer) then {RC_RCLocalHash = createHashMap;};
if (!hasInterface) exitWith {};

[] spawn {
	
	_repeats = 9;

	while {true} do {
		
		if (_repeats == 3) then {
			private _uav = getConnectedUAV player;
			private _driverGroupServer = group (driver _uav);
			[_driverGroupServer, 2] remoteExec ['setGroupOwner', 2];
			[player, "SERVER locality"] remoteExec ['globalChat', 0];


			private _ServercurWpPos1 = (waypointPosition [_uav, 1]) select 1;
			private _ServercurWpPos2 = (waypointPosition [_uav, 2]) select 1;
			private _ServercurWpPos3 = (waypointPosition [_uav, 3]) select 1;
			_uav setVariable ["RC_prevWpPos1", _ServercurWpPos1];
			_uav setVariable ["RC_prevWpPos2", _ServercurWpPos2];
			_uav setVariable ["RC_prevWpPos3", _ServercurWpPos3];
			[player, "SERVER WpPos1: " + str _ServercurWpPos1] remoteExec ['globalChat', 0];
			[player, "SERVER WpPos2: " + str _ServercurWpPos2] remoteExec ['globalChat', 0];
			[player, "SERVER WpPos3: " + str _ServercurWpPos3] remoteExec ['globalChat', 0];

			private _ServercurWpCount = count (waypoints _uav);
			_uav setVariable ["RC_prevWpCount", _ServercurWpCount];
			[player, "SERVER WpCount: " + str _ServercurWpCount] remoteExec ['globalChat', 0];
        };
        if (_repeats == 6) then {
            private _uav = getConnectedUAV player;
            private _driverGroupServer = group (driver _uav);
            [_driverGroupServer, 2] remoteExec ['setGroupOwner', 2];
            [player, "SERVER locality"] remoteExec ['globalChat', 0];


			private _ServercurWpPos1 = (waypointPosition [_uav, 1]) select 1;
			private _ServercurWpPos2 = (waypointPosition [_uav, 2]) select 1;
			private _ServercurWpPos3 = (waypointPosition [_uav, 3]) select 1;
			_uav setVariable ["RC_prevWpPos1", _ServercurWpPos1];
			_uav setVariable ["RC_prevWpPos2", _ServercurWpPos2];
			_uav setVariable ["RC_prevWpPos3", _ServercurWpPos3];
			[player, "SERVER WpPos1: " + str _ServercurWpPos1] remoteExec ['globalChat', 0];
			[player, "SERVER WpPos2: " + str _ServercurWpPos2] remoteExec ['globalChat', 0];
			[player, "SERVER WpPos3: " + str _ServercurWpPos3] remoteExec ['globalChat', 0];

			private _ServercurWpCount = count (waypoints _uav);
			_uav setVariable ["RC_prevWpCount", _ServercurWpCount];
			[player, "SERVER WpCount: " + str _ServercurWpCount] remoteExec ['globalChat', 0];
        };

		_repeats = _repeats - 1;
		sleep 4;

		if (_repeats <= 0) exitwith {[player, "ended test"] remoteExec ['globalChat', 0];};

		if (RC_FixLocalityOfRCUVs or RC_FixLocalityOfAllUVs) then {

			private _uav = getConnectedUAV player;

            [_uav] call RC_fnc_RC_debugContinue;

            private _uavClass = typeOf _uav;
            private _RCLocal = RC_RCLocalHash get _uavClass;

            [_uav] call RC_fnc_RC_debugHash;

			if ((_RCLocal != 0) or RC_FixLocalityOfAllUVs) then {

				if (!isNull (findDisplay 160)) then {
					[_uav] call RC_fnc_debugWpTest;
				};

				if (isRemoteControlling player) then {
					[_uav] call RC_fnc_RC_debugChangeLocality;
				};
			};
		};
	};
};
*/


/*
_pos = position _this;
private _array = [_pos, 180, "RC_cUAS_UGV_WD", west];
[_array, BIS_fnc_spawnVehicle] remoteExec ['call', 2];


_this setVariable ["RC_LastOwner", 2];
if ((_this getVariable ["RC_LastOwner", ""]) isNotEqualTo clientowner) then {
	[player, "passed"] remoteExec ['globalChat', clientOwner];
};
[player, "didnt crash"] remoteExec ['globalChat', clientOwner];

_uav setVariable ["RC_prevWpCount", 2];
((_uav getVariable ["RC_prevWpCount", 0]) isNotEqualTo clientowner)

if (isAutonomous _this) then {[_this, false] remoteExec ["setAutonomous", _this];};
*/