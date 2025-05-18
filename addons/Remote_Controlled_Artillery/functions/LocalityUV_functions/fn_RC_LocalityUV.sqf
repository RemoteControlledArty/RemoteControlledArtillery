/*
	Author: Ascent

	Description:
	Fixes multiplayer locality of UAV's/UGV's, to drive from UGV turret & set correct UAV altitude, without needing to first take driver control.
	Triggered by having terminal open and giving waypoint, or remote controlling turret.
*/

if (isServer) then {RC_RCLocalHash = createHashMap;};
if (!hasInterface) exitWith {};

[] spawn {
	
	while {true} do {

		sleep 0.5;

		if (RC_FixLocalityOfRCUVs or RC_FixLocalityOfAllUVs) then {

			private _uav = getConnectedUAV player;

			if (_uav isEqualto objNull) then {continue;};
			if (local _uav) then {continue;};

            private _uavClass = typeOf _uav;
            private _RCLocal = RC_RCLocalHash get _uavClass;

            [_uav] call RC_fnc_RC_uavHash;

			if ((_RCLocal != 0) or RC_FixLocalityOfAllUVs) then {

				if (!isNull (findDisplay 160)) then {
					[_uav] call RC_fnc_uavWaypoints;
				};

				if (isRemoteControlling player) then {
					[_uav] call RC_fnc_RC_uavChangeLocality;
				};
			};
		};
	};
};


/*
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

            [_uav] call RC_fnc_RC_uavContinue;

            private _uavClass = typeOf _uav;
            private _RCLocal = RC_RCLocalHash get _uavClass;

            [_uav] call RC_fnc_RC_uavHash;

			if ((_RCLocal != 0) or RC_FixLocalityOfAllUVs) then {

				if (!isNull (findDisplay 160)) then {
					[_uav] call RC_fnc_uavWaypoints;
				};

				if (isRemoteControlling player) then {
					[_uav] call RC_fnc_RC_uavChangeLocality;
				};
			};
		};
	};
};
*/