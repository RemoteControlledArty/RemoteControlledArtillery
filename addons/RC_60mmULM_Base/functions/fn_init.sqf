["vehicle", twc_2inch_fnc_ui, true] call CBA_fnc_addPlayerEventHandler;

["RC_60mmULM", "RC_60mmULM_deploykey", ["Deploy 2 Inch", "This deploys the static with you on it."], {
	//[player] call twc_2inch_fnc_deploy
	[player] call RC_ULM_fnc_deploy
}, {}, [0x04, [false, false, false]]] call CBA_fnc_addKeybind;