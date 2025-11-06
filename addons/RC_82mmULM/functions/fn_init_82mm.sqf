//["vehicle", twc_2inch_fnc_ui, true] call CBA_fnc_addPlayerEventHandler;

["RC_82mmULM",
	"RC_82mmULM_deploykey",
	["Deploy 82mmULM", "This deploys the static with you on it."],
	{[player] call RC_82mmULM_fnc_deploy_82mm},
	{},
	[0x04, [false, false, false]]
] call CBA_fnc_addKeybind;