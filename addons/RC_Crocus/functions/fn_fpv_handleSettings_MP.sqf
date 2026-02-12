private _player = missionNamespace getVariable ["bis_fnc_moduleRemoteControl_unit", player];
private _mainText = uiNameSpace getVariable ["ArmaFPV_MainText", controlNull]; 
private _defaultText = missionNamespace getVariable ["FPV_DefaultText", "CROCUS"]; 
private _isCaptive = missionNamespace getVariable ["FPV_isUavCaptive", true];
private _textArray = toArray _defaultText; 
private _allowedChars = toArray "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz.,;\/ "; 

private _isValid = true; 
{ 
    if !(_x in _allowedChars) exitWith { _isValid = false; }; 
} forEach _textArray; 

if (_isValid) then { 
    _mainText ctrlSetText _defaultText; 
} else { 
    _mainText ctrlSetText ""; 
}; 

(getConnectedUAV _player) setCaptive _isCaptive;

missionNamespace setVariable ["RC_FPV_Layer_ID", _layer];
