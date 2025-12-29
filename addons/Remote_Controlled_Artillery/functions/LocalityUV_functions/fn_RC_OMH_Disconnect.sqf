/*
	Author: Ascent

	Description:
	Disconnects terminal from optionally manned helicopter when its destroyed, to prevent the unable to manually disconnect from destroyed UV bug.
*/

// exit if not player
if (!hasInterface) exitWith {};

params ["_unit"];

private _pSide = side player;
private _cfgSide = getNumber (configFile >> "CfgVehicles" >> (typeOf _unit) >> "side");

switch (true) do {
	case (_cfgSide == 1): {
		if (_pSide isEqualTo west) then {
			(_unit) spawn {
				sleep 3;
				player remoteControl objNull;
				systemChat 'lost connection to OM-H';
			};
		};
	};
	case (_cfgSide == 0): {
		if (_pSide isEqualTo east) then {
			(_unit) spawn {
				sleep 3;
				player remoteControl objNull;
				systemChat 'lost connection to OM-H';
			};
		};
	};
	case (_cfgSide == 2): {
		if (_pSide isEqualTo resistance) then {
			(_unit) spawn {
				sleep 3;
				player remoteControl objNull;
				systemChat 'lost connection to OM-H';
			};
		};
	};
	case (_cfgSide == 3): {
		if (_pSide isEqualTo civilian) then {
			(_unit) spawn {
				sleep 3;
				player remoteControl objNull;
				systemChat 'lost connection to OM-H';
			};
		};
	};
};
