// --- Main logic ---
private _primaryUV = player getVariable ["RC_primary_UV",  objNull];
private _primaryUV_seat = player getVariable ["RC_primary_UV_seat",  objNull];
private _previousUV = player getVariable ["RC_previous_UV", objNull];
private _previousUV_seat = player getVariable ["RC_previous_UV_seat", objNull];
private _currentUV = getConnectedUAV player;


if (!([_primaryUV] call _isValidUV)) exitWith {
	// Primary UV not set or destroyed
	if (isNull _primaryUV) then {
		hint "Set a primary UV to enable swapping. (Mousewheel action on any UV while connected)";
	} else {
		hint "Primary UV is destroyed. Set a new primary UV.";
	};
};


/*
if (_currentUV isEqualTo _primaryUV) then {
	// Case 1: Connected to primary UV -> swap to previous UV
	if ([_previousUV] call RC_fnc_RC_isValidUV) then {
		[_previousUV] call RC_fnc_RC_connectToUV;
	} else {
		hint "No previously selected UV available or UV was destroyed. Swap away from another UV to your primary UV first.";
	};
} else {
	if (_connected) then {
		// Case 2: Connected to a different UV -> remember it and swap to primary UV
		player setVariable ["RC_previous_UV", _currentUV];
		player setVariable ["RC_previous_UV_seat", getConnectedUAVUnit player];
	};
	// Case 2 & 3: Connect to primary UV (not connected, or connected to non-primary)
	[_primaryUV] call RC_fnc_RC_connectToUV;
};
*/


//*
private _connected = !isNull _currentUV;

if (isRemoteControlling player) then {
	if (_connected && {_currentUV isEqualTo _primaryUV}) then {
		// Case 1: Connected to primary UV -> swap to previous UV
		if ([_previousUV] call RC_fnc_RC_isValidUV) then {
			[_previousUV, _previousUV_seat] call RC_fnc_RC_connectToUV;
		} else {
			hint "No previously selected UV available or UV was destroyed. Swap away from another UV to your primary UV first.";
		};
	} else {
		if (_connected) then {
			// Case 2: Connected to a different UV -> remember it and swap to primary UV
			player setVariable ["RC_previous_UV", _currentUV];
			player setVariable ["RC_previous_UV_seat", getConnectedUAVUnit player];
		};
		// Case 2 & 3: Connect to primary UV (not connected, or connected to non-primary)
		[_primaryUV, _primaryUV_seat] call RC_fnc_RC_connectToUV;
	};
} else {
	if (_connected) then {
		// Case 2: Connected to a different UV -> remember it and swap to primary UV
		player setVariable ["RC_previous_UV", _currentUV];
		player setVariable ["RC_previous_UV_seat", getConnectedUAVUnit player];
	};
	// Case 2 & 3: Connect to primary UV (not connected, or connected to non-primary)
	[_primaryUV, _primaryUV_seat] call RC_fnc_RC_connectToUV;
};
//*/
