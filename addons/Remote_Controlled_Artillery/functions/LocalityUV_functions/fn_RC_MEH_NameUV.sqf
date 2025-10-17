addMissionEventHandler ["EntityCreated", {
	params ["_entity"];
	
	if (!local _entity) exitwith {};

	if ((getNumber (configFile >> "CfgVehicles" >> (typeOf _entity) >> "isUav") == 1)) then {
	
		[[_entity], RC_fnc_RC_addAction_NameUV] remoteExec ["call", 0, true];
	};
}];