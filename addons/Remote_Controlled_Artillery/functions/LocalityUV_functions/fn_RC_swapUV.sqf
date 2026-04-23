/*
 * Author: nw2372
 * Swap UV keybind handler.
 *
 * Swaps the player between their primary UV and the previously connected UV.
 * The primary UV is set via a "Set as primary UV" action on any UV.
 * RC_previous_UV is set contextually when the player swaps away from a non-primary UV.
 *
 * Usage: call RC_fnc_RC_swapUV
 */

// --- Helper: connect player terminal to a UV (and attempt to open UAV terminal UI) ---
private _connectTo = {
    params ["_uav"];

    // If actively remote controlling, stop before switching
    if (isRemoteControlling player) then {
        player action ["StopRemoteControl", vehicle player];
    };

    player connectTerminalToUAV objNull;
    player connectTerminalToUAV _uav;

    // Open UAV terminal display if not already open
    if (isNull (findDisplay 160)) then {
        player action ["UAVTerminal", player];
    };
};

// --- Helper: is _uav a valid, living UV? ---
private _isValidUV = {
    params ["_uav"];
    (!isNull _uav) && {alive _uav}
};

// --- Main logic ---

private _primaryUV   = player getVariable ["RC_primary_UV",  objNull];
private _previousUV  = player getVariable ["RC_previous_UV", objNull];
private _currentUV   = getConnectedUAV player;
private _connected   = !isNull _currentUV;

if (!([_primaryUV] call _isValidUV)) exitWith {
    // Primary UV not set or destroyed
    if (isNull _primaryUV) then {
        hint "Set a primary UV to enable swapping. (Mousewheel action on any UV while connected)";
    } else {
        hint "Primary UV is destroyed. Set a new primary UV.";
    };
};

if (_connected && {_currentUV isEqualTo _primaryUV}) then {
    // Case 1: Connected to primary UV -> swap to previous UV
    if ([_previousUV] call _isValidUV) then {
        [_previousUV] call _connectTo;
    } else {
        hint "No previously selected UV available or UV was destroyed. Swap away from another UV to your primary UV first.";
    };
} else {
    if (_connected) then {
        // Case 2: Connected to a different UV -> remember it and swap to primary UV
        player setVariable ["RC_previous_UV", _currentUV];
    };
    // Case 2 & 3: Connect to primary UV (not connected, or connected to non-primary)
    [_primaryUV] call _connectTo;
};

