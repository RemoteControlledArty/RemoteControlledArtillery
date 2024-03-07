/*
	Author: Ascent, Eric, Fluffy
*/

if (!isServer) exitWith { };

addMissionEventHandler ["ControlsShifted", {
	params ["_newController", "_oldController", "_vehicle"];

	_RCNeedsLocality = (getNumber (configFile >> "CfgVehicles" >> (typeOf _vehicle) >> "RC_NeedsLocality") == 1);
	if (_RCNeedsLocality == 1) then {
		_vehicle setOwner (clientOwner _newController);
		(group (crew _vehicle)) setGroupOwner (clientOwner _newController);
	};
}];