/*
	Author: Ascent

	Description:
	Fixes multiplayer locality of UAV's/UGV's, to drive from UGV turret & set correct UAV altitude, without needing to first take driver control.
*/

if (!hasInterface) exitWith {};
RC_RCLocalHash = createHashMap;

[] spawn {

	private _prevUAV = getConnectedUAV player;
	private _prevWpsCount = count (waypoints _prevUAV);
	private _prevWpPos1 = waypointPosition [_prevUAV, 1];

	while {true} do {

		sleep 1;

		if (RC_FixLocalityOfRCUVs or RC_FixLocalityOfAllUVs) then {

			private _uav = getConnectedUAV player;

            [_uav] call RC_fnc_RC_debugContinue;

            private _uavClass = typeOf _uav;
            private _RCLocal = RC_RCLocalHash get _uavClass;

            [_uav] call RC_fnc_RC_debugHash;

			if ((_RCLocal != 0) or RC_FixLocalityOfAllUVs) then {

				if (!isNull (findDisplay 160)) then {
					[_uav, _prevWpsCount, _prevWpPos1] call RC_fnc_RC_debugWps;
				};

				if (isRemoteControlling player) then {
					[_uav] call RC_fnc_RC_debugChangeLocality;
				};
			};
		};
	};
};



_pos = position _this;
private _array = [_pos, 180, "RC_cUAS_UGV_WD", west];
[_array, BIS_fnc_spawnVehicle] remoteExec ['call', 2];



//testing
if (!hasInterface) exitWith {};
RC_RCLocalHash = createHashMap;

[] spawn {

	private _prevUAV = getConnectedUAV player;
	private _prevWpsCount = count (waypoints _prevUAV);
	private _prevWpPos1 = waypointPosition [_prevUAV, 1];
	_repeats = 6;

	while {true} do {

		if (_repeats == 2) then {
        private _uav = getConnectedUAV player;
        private _driverGroupServer = group (driver _uav);
        [_driverGroupServer, 2] remoteExec ['setGroupOwner', 2];
        [player, "SERVER locality"] remoteExec ['globalChat', clientOwner];
        };
        if (_repeats == 4) then {
            private _uav = getConnectedUAV player;
            private _driverGroupServer = group (driver _uav);
            [_driverGroupServer, 2] remoteExec ['setGroupOwner', 2];
            [player, "SERVER locality"] remoteExec ['globalChat', clientOwner];
        };

		_repeats = _repeats - 1;
		sleep 4;

		if (_repeats <= 0) exitwith {[player, "ended test"] remoteExec ['globalChat', clientOwner];};

		if (RC_FixLocalityOfRCUVs or RC_FixLocalityOfAllUVs) then {

			private _uav = getConnectedUAV player;

            [_uav] call RC_fnc_RC_debugContinue;

            private _uavClass = typeOf _uav;
            private _RCLocal = RC_RCLocalHash get _uavClass;

            [_uav] call RC_fnc_RC_debugHash;

			if ((_RCLocal != 0) or RC_FixLocalityOfAllUVs) then {

				if (!isNull (findDisplay 160)) then {
					
					[player, "terminal open"] remoteExec ['globalChat', clientOwner];

					//prevwppos needs to be updated somewhere else!
					private _currentWpPos1 = waypointPosition [_uav, 1];
					if (((_currentWpPos1 select 1) != (_prevWpPos1 select 1))) then {

						private _driverGroup = group (driver _uav);
						private _playerID = clientOwner;
						[_driverGroup, _playerID] remoteExec ['setGroupOwner', 2];

						[player, "changed locality (wpPos)"] remoteExec ['globalChat', clientOwner];

						_prevWpPos1 = _currentWpPos1;
					};

					private _currentWpsCount = count (waypoints _uav);
					if (_currentWpsCount != _prevWpsCount) then {

						private _driverGroup = group (driver _uav);
						private _playerID = clientOwner;
						[_driverGroup, _playerID] remoteExec ['setGroupOwner', 2];

						[player, "changed locality (wpCount)"] remoteExec ['globalChat', clientOwner];
						
						_prevWpsCount = _currentWpsCount;
					};
				};

				if (isRemoteControlling player) then {
					[_uav] call RC_fnc_RC_debugChangeLocality;
				};
			};
		};
	};
};