addMissionEventHandler ["EntityCreated", {
	params ["_entity"];
	
	if (!local _entity) exitwith {};

	if ((getNumber (configFile >> "CfgVehicles" >> (typeOf _entity) >> "isUav") == 1)) then {
	
		[[_entity], RC_fnc_RC_addAction_NameUV] remoteExec ["call", 0, true];
	};
}];


/*
addMissionEventHandler ["EntityCreated", {
	params ["_entity"];
    if (!local _entity) exitwith {};
	if ((getNumber (configFile >> "CfgVehicles" >> (typeOf _entity) >> "isUav") != 1)) exitwith {};

	_entity addEventHandler ["Local", {
		params ["_entity", "_isLocal"];
		if (!_isLocal) exitwith {};

		private _grp = group _entity
		private _grpName = groupId _grp;
		private _localName = name player;
		private _name = [_grpName,_localName] call RC_fnc_RC_addLocalName;
		_grp setGroupIdGlobal [_name];
	}];
}];
*/