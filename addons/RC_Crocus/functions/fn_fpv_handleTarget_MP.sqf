addMissionEventHandler ["EachFrame", {

	private _type = typeOf (playerTargetLock#0);
	private _FPV_Target = RC_FPV_Target_Hash get _type;

	if (isNil "_FPV_Target") then {
		_FPV_Target = getText (configFile >> "CfgVehicles" >> _type >> "displayName");
		RC_FPV_Target_Hash set [_type, _FPV_Target];
	};
	
	private _controlText = uiNameSpace getVariable ["ArmaFPV_Target", controlNull];
	
	_controlText ctrlSetText _FPV_Target;

	if !(missionNamespace getVariable ["ArmaFPV_isControl", false]) exitWith {
    	removeMissionEventHandler ["EachFrame", _thisEventHandler];
	};
}];