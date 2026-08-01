/*
	Author: Ascent

	Description:
	Disconnects terminal from optionally manned helicopter when its destroyed, to prevent the unable to manually disconnect from destroyed UV bug.
*/

// exit if not player
if (!hasInterface) exitWith {};

params ["_unit"];

private _ctrl = _unit isEqualTo (getConnectedUAV player);
private _cfgSide = getNumber (configFile >> "CfgVehicles" >> (typeOf _unit) >> "side");
private _cfgName = getText (configFile >> "CfgVehicles" >> (typeOf _unit) >> "displayName");
private _string = "lost connection to " + _cfgName;
private _pSide = side player;

switch (true) do {
	case (_cfgSide == 1): {
		if (_pSide isEqualTo west) then {
			[_unit, _string, _ctrl] spawn RC_fnc_RC_OMH_Disconnect;
		};
	};
	case (_cfgSide == 0): {
		if (_pSide isEqualTo east) then {
			[_unit, _string, _ctrl] spawn RC_fnc_RC_OMH_Disconnect;
		};
	};
	case (_cfgSide == 2): {
		if (_pSide isEqualTo resistance) then {
			[_unit, _string, _ctrl] spawn RC_fnc_RC_OMH_Disconnect;
		};
	};
	case (_cfgSide == 3): {
		if (_pSide isEqualTo civilian) then {
			[_unit, _string, _ctrl] spawn RC_fnc_RC_OMH_Disconnect;
		};
	};
};
