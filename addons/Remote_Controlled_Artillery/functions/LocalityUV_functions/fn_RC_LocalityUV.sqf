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

				if (isRemoteControlling player) then {
					[_uav] call RC_fnc_RC_uavChangeLocality;
				};
			};
		};
	};
};


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
			
			private _uavClass = typeOf _uav;
            private _RCLocal = RC_RCLocalHash get _uavClass;

            [_uav] call RC_fnc_RC_uavHash;

			if ((_RCLocal != 0) or RC_FixLocalityOfAllUVs) then {
				
				//waypoint setvariable
				if (!isNull (findDisplay 160)) then {
					[_uav] call RC_fnc_debugWaypointsTestServer;
				};

				if (local _uav) then {continue;};

				//getvariable & locality change
				if (!isNull (findDisplay 160)) then {
					[_uav] call RC_fnc_debugWaypointsTestServer;
				};

				if (isRemoteControlling player) then {
					[_uav] call RC_fnc_RC_uavChangeLocality;
				};
			};
		};
	};
};



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

            [_uav] call RC_fnc_RC_uavHash;

			if ((_RCLocal != 0) or RC_FixLocalityOfAllUVs) then {

				if (!isNull (findDisplay 160)) then {
					[_uav] call RC_fnc_debugWaypointsTestServer;
				};

				if (isRemoteControlling player) then {
					[_uav] call RC_fnc_RC_uavChangeLocality;
				};
			};
		};
	};
};

//server and RE works, public doesnt, but redefine waypoints even if not unlocal


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

private _prevWpPos1 = (_uav getVariable ["RC_prevWpPos1", 0]);
private _prevWpPos2 = (_uav getVariable ["RC_prevWpPos2", 0]);
private _prevWpPos3 = (_uav getVariable ["RC_prevWpPos3", 0]);
private _curWpPos1 = (waypointPosition [_uav, 1]) select 1;
private _curWpPos2 = (waypointPosition [_uav, 2]) select 1;
private _curWpPos3 = (waypointPosition [_uav, 3]) select 1;
[player, "Wp1: " + str _curWpPos1] remoteExec ['globalChat', 0, true];
[player, "Wp2: " + str _curWpPos2] remoteExec ['globalChat', 0, true];
[player, "Wp3: " + str _curWpPos3] remoteExec ['globalChat', 0, true];

[_uav, ["RC_prevWpPos1", _curWpPos1]] remoteExec ["setVariable", 0, true];
[_uav, ["RC_prevWpPos2", _curWpPos2]] remoteExec ["setVariable", 0, true];
[_uav, ["RC_prevWpPos3", _curWpPos3]] remoteExec ["setVariable", 0, true];

private _ServercurWpCount = count (waypoints _uav);
[_uav, ["RC_prevWpCount", _ServercurWpCount]] remoteExec ["setVariable", 0, true];
[player, "SERVER WpCount: " + str _ServercurWpCount] remoteExec ['globalChat', 0];


//[_uav] call RC_fnc_uavWaypoints;
/*
RC_fnc_LocalityUV =
{
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

						[_uav] call RC_fnc_uavWaypointsTest;
					};

					if (isRemoteControlling player) then {
						[_uav] call RC_fnc_RC_uavChangeLocality;
					};
				};
			};
		};
	};
};
*/


/*
//overwriting didnt work
//RC_LocalityUV =
RC_fnc_LocalityUV =
{
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

						[_uav] call RC_fnc_uavWaypointsTest;
					};

					if (isRemoteControlling player) then {
						[_uav] call RC_fnc_RC_uavChangeLocality;
					};
				};
			};
		};
	};
};
*/

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
					[_uav] call RC_fnc_uavWaypointsTest;
				};

				if (isRemoteControlling player) then {
					[_uav] call RC_fnc_RC_uavChangeLocality;
				};
			};
		};
	};
};
*/