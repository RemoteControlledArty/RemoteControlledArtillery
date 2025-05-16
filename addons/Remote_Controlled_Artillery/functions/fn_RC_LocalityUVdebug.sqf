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