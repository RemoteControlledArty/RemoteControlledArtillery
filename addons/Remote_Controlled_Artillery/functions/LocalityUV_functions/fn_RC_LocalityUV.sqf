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
			
			private _uavClass = typeOf _uav;
            private _RCLocal = RC_RCLocalHash get _uavClass;

			if (isNil "_RCLocal") then {
				_RCLocal = getNumber (configFile >> "CfgVehicles" >> _uavClass >> "RC_Local");
				RC_RCLocalHash set [_uavClass, _RCLocal];
			};

			if ((_RCLocal != 0) or RC_FixLocalityOfAllUVs) then {
				
				if (!isNull (findDisplay 160)) then {
					[_uav] call RC_fnc_RC_uavWaypoints;
				};

				if (isRemoteControlling player) then {
					if (!local _uav) then {
						[_uav] call RC_fnc_RC_uavChangeLocality;
					};
				};
			};
		};
	};
};