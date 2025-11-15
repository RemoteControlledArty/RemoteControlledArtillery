// All the Different Controls
_ctrlCharge = _display displayCtrl IDC_CHARGE;
_ctrlAzimuth = _display displayCtrl IDC_AZIMUTH;
_ctrlElevation = _display displayCtrl IDC_ELEVATION;
_ctrlDistance = _display displayCtrl IDC_DISTANCE;
_ctrlTarget = _display displayCtrl IDC_TARGET;
_ctrlTargetAzimuth = _display displayCtrl IDC_TARGET_AZIMUTH;
_ctrlDifference = _display displayCtrl IDC_DIFFERENCE;
_ctrlHighSol = _display displayCtrl IDC_HIGHSOL;
_ctrlLowSol = _display displayCtrl IDC_LOWSOL;
_ctrlHighETA = _display displayCtrl IDC_HIGHETA;
_ctrlLowETA = _display displayCtrl IDC_LOWETA;
_ctrlMessage = _display displayCtrl IDC_MESSAGE;

//Keybind Display
_ctrlKeySelect = _display displayCtrl IDC_KEY_SELECT;
_ctrlKeyUnselect = _display displayCtrl IDC_KEY_UNSELECT;
_ctrlKeyMarkersF = _display displayCtrl IDC_KEY_MARKERSF;
_ctrlKeyMarkersB = _display displayCtrl IDC_KEY_MARKERSB;
_ctrlKeyCharges = _display displayCtrl IDC_KEY_CHARGES;
_ctrlKeyElUp = _display displayCtrl IDC_KEY_ELUP;
_ctrlKeyElDown = _display displayCtrl IDC_KEY_ELDOWN;
_ctrlKeyElSlow = _display displayCtrl IDC_KEY_ELSLOW;
_ctrlAzSlow = _display displayCtrl IDC_KEY_AZSLOW;

_ctrlKeySelect ctrlSetText format ["select DL target: %1%2", ((actionKeysNamesArray "vehLockTargets") select 0), " / aim at"];
_ctrlKeyUnselect ctrlSetText format ["unselect DL target: %1%2", ((actionKeysNamesArray "lockTarget") select 0)];

private _arrayMarkersF = ["Remote Controlled Artillery", "RC_Scroll_Targets_Forwards"] call CBA_fnc_getKeybind;
private _keyMarkersF = (((_arrayMarkersF select 8) select 0) select 0) call BIS_fnc_keyCode;
if (!isNil "_keyMarkersF") then {_ctrlKeyMarkersF ctrlSetText format ["cycle markers ->: %1%2", _keyMarkersF];};

private _arrayMarkersB = ["Remote Controlled Artillery", "RC_Scroll_Targets_Backwards"] call CBA_fnc_getKeybind;
private _keyMarkersB = (((_arrayMarkersB select 8) select 0) select 0) call BIS_fnc_keyCode;
if (!isNil "_keyMarkersB") then {_ctrlKeyMarkersB ctrlSetText format ["cycle markers <-: %1%2", _keyMarkersB];};

_ctrlKeyCharges ctrlSetText format ["cycle charges: %1%2", ((actionKeysNamesArray "nextWeapon") select 0)];
_ctrlKeyElUp ctrlSetText format ["elevation up: %1%2", ((actionKeysNamesArray "gunElevUp") select 0)];
_ctrlKeyElDown ctrlSetText format ["elevation down: %1%2", ((actionKeysNamesArray "gunElevDown") select 0)];
_ctrlKeyElSlow ctrlSetText format ["slow elevation: %1%2", ((actionKeysNamesArray "gunElevSlow") select 0)];
_ctrlAzSlow ctrlSetText format ["slow azimuth: zoom in %1%2"];

//if ace installed, warning that ace adjustable scopes prevent gun elevation when hotkeys overlap
if ((isClass(configFile >> "CfgPatches" >> "ace_main"))) then
{
	if (RC_ace_hotkey_warning) then {
		{(_display displayCtrl _x) ctrlShow true} forEach [1026,1027,1028];
	} else {
		{(_display displayCtrl _x) ctrlShow false} forEach [1026,1027,1028];
	};
};