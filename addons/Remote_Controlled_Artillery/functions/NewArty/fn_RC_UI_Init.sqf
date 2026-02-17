/*
    RC UI Init (DEBUG)
*/

params ["_display", "_vehicle"];

diag_log "[RC][INIT] UI Init called";

if (isNull _display) exitWith {
    diag_log "[RC][INIT] ERROR: display is null";
};

if (isNull _vehicle) exitWith {
    diag_log "[RC][INIT] ERROR: vehicle is null";
};

systemChat "[RC] UI Init OK";

// cache controls (example)
private _ui = createHashMapFromArray [
    ["az", _display displayCtrl IDC_AZIMUTH],
    ["el", _display displayCtrl IDC_ELEVATION],
    ["dist", _display displayCtrl IDC_DISTANCE],
    ["highSol", _display displayCtrl IDC_HIGHSOL],
    ["lowSol", _display displayCtrl IDC_LOWSOL]
];

uiNamespace setVariable ["RC_ui", _ui];
uiNamespace setVariable ["RC_UI_Active", true];

// start UI loop
[] spawn RC_fnc_RC_UI_Loop;



/*
	RC UI Init
	Called ONCE when the RC artillery UI is opened
*/

/*
params ["_display", "_vehicle"];

if (isNull _display || isNull _vehicle) exitWith {false};

// ---- asset check (once) ----
if !(_vehicle getVariable ["isRCArty", false]) exitWith {
    closeDialog 0;
    false
};

// ---- cache UI controls ----
private _ui = createHashMapFromArray [
    ["az", _display displayCtrl 1001],
    ["el", _display displayCtrl 1002],
    ["highSol", _display displayCtrl 1003],
    ["lowSol", _display displayCtrl 1004],
    ["etaHigh", _display displayCtrl 1005],
    ["etaLow", _display displayCtrl 1006]
];

// ---- init state ----
private _state = call RC_fnc_State_Init;

// ---- store namespaces ----
uiNamespace setVariable ["RC_ui", _ui];
uiNamespace setVariable ["RC_state", _state];
uiNamespace setVariable ["RC_vehicle", _vehicle];

// ---- start render loop ----
uiNamespace setVariable ["RC_UI_Active", true];
[] spawn RC_fnc_RC_UI_Loop;

true
*/