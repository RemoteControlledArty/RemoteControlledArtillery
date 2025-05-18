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

            [_uav] call RC_fnc_RC_uavContinue;

            private _uavClass = typeOf _uav;
            private _RCLocal = RC_RCLocalHash get _uavClass;

            [_uav] call RC_fnc_RC_uavHash;

			if ((_RCLocal != 0) or RC_FixLocalityOfAllUVs) then {

				if (!isNull (findDisplay 160)) then {
					[_uav] call RC_fnc_uavWp;
				};

				if (isRemoteControlling player) then {
					[_uav] call RC_fnc_RC_uavChangeLocality;
				};
			};
		};
	};
};