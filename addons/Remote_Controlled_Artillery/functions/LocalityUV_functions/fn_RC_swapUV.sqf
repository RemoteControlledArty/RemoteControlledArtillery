// --- Main logic ---
private _primaryUV = player getVariable ["RC_primary_UV",  objNull];
private _primaryUV_seat = player getVariable ["RC_primary_UV_seat",  objNull];
private _previousUV = player getVariable ["RC_previous_UV", objNull];
private _previousUV_seat = player getVariable ["RC_previous_UV_seat", objNull];
private _currentUV = getConnectedUAV player;
private _connected = !isNull _currentUV;
private _currentIsNotPrimaryUV = _currentUV isNotEqualTo _primaryUV;


if (!([_primaryUV] call RC_fnc_RC_isValidUV)) exitWith {
	// Primary UV not set or destroyed
	if (isNull _primaryUV) then {
		hint "Set a primary UV to enable swapping. (Mousewheel action on any UV while remote controlling.)";
	} else {
		hint "Primary UV is destroyed. Set a new primary UV.";
	};
};



/*
//RC_SpawCount = 3;  defined in preInit
private _swapCount = RC_SpawCount;

switch (true) do {
	case (_swapCount == 3): {
		
		RC_SpawCount = 2;
		systemchat "3->2";

		if (_connected && _currentIsNotPrimaryUV) then {
			player setVariable ["RC_previous_UV", _currentUV];
			player setVariable ["RC_previous_UV_seat", getConnectedUAVUnit player];
		};

		if ([_primaryUV] call RC_fnc_RC_isValidUV) then {
				[_primaryUV, _primaryUV_seat] call RC_fnc_RC_connectToUV;
		} else {
			hint "No primary UV available to swap to. Set a primary UV first.";
		};
	};
	case (_swapCount == 2): {

		RC_SpawCount = 1;
		systemchat "2->1";
		
		if ([_previousUV] call RC_fnc_RC_isValidUV) then {
			[_previousUV, _previousUV_seat] call RC_fnc_RC_connectToUV;
		} else {
			hint "No previous UV available to swap to. Swap away per hokey from a UV first.";
		};
	};
	case (_swapCount == 1): {

		RC_SpawCount = 3;
		systemchat "1->3";

		//player switchCamera "INTERNAL";
		player remoteControl objNull;
		closeDialog 0;
	};
};
*/


//If (_connected && primary is set && primary is valid && connected is primary)
if (isRemoteControlling player) then {

	//player switchCamera "INTERNAL";
	player remoteControl objNull;
	closeDialog 0;

} else {

	if ((_currentUV isNotEqualTo _primaryUV) && ([_primaryUV] call RC_fnc_RC_isValidUV)) then {

		player setVariable ["RC_previous_UV", _currentUV];
		player setVariable ["RC_previous_UV_seat", getConnectedUAVUnit player];	//cannot be set if not RC!

		[_primaryUV, _primaryUV_seat] call RC_fnc_RC_connectToUV;

	} else {

		//somewhere here set previous

		if ([_previousUV] call RC_fnc_RC_isValidUV) then {

			[_previousUV, _previousUV_seat] call RC_fnc_RC_connectToUV;

		} else {

			if ([_primaryUV] call RC_fnc_RC_isValidUV) then {

				[_primaryUV, _primaryUV_seat] call RC_fnc_RC_connectToUV;

			} else {

				hint "No primary/previous UV available to swap to. First set a primary UV or swap away per hokey from a UV.";
			};
		};
	};
};


//logic breakdown
if (isRCing) then {
	back to player
} else {
	if ((currentUV != primaryUV) && (primaryUV is valid)) then {
		setVariable previous_UV is _currentUV
		control primaryUV
	} else {

		//somewhere here set previous

		if (previousUV is valid) then {

			[_previousUV, _previousUV_seat] call RC_fnc_RC_connectToUV;

		} else {

			if ([_primaryUV] call RC_fnc_RC_isValidUV) then {

				[_primaryUV, _primaryUV_seat] call RC_fnc_RC_connectToUV;

			} else {

				hint "No primary/previous UV available to swap to. First set a primary UV or swap away per hokey from a UV.";
			};
		};
	};
};


/*
//If (_connected && primary is set && primary is valid && connected is primary)
If (_connected && (_currentUV isEqualTo _primaryUV) && ([_primaryUV] call RC_fnc_RC_isValidUV))

//--> try connecting to previous, fallback disconnect
if ([_previousUV] call RC_fnc_RC_isValidUV) then {
	[_previousUV, _previousUV_seat] call RC_fnc_RC_connectToUV;
} else {
	if !(isRemoteControlling player) then {
		if ([_primaryUV] call RC_fnc_RC_isValidUV) then {
			[_primaryUV, _primaryUV_seat] call RC_fnc_RC_connectToUV;
		} else {
			hint "No previous/primary UV available to swap to. First swap away per hokey from a UV or set a primary UV.";
		};
	} else {
		hint "No previously selected UV available to swap to. Swap away per hokey from a UV first.";
	};
};

//Else if (_connected [implicitly not primary])
//--> set this as previous, then Always disconnect
//Else # not connected
//--> try connecting to primary, if not valid try connecting to previous, else probably send a hint so the player understands why nothing is happening (no primary, no previous, how to set)
if (!_connected) then {

	if ([_primaryUV] call RC_fnc_RC_isValidUV) then {
		// Case 2 & 3: Connect to primary UV (not connected, or connected to non-primary)
		[_primaryUV, _primaryUV_seat] call RC_fnc_RC_connectToUV;
	} else {
		if ([_previousUV] call RC_fnc_RC_isValidUV) then {
			[_previousUV, _previousUV_seat] call RC_fnc_RC_connectToUV;
		} else {
			hint "No primary/previous UV available to swap to. First set a primary UV or swap away per hokey from a UV.";
		};
	};
};
*/


/*
if (_connected && {_currentUV isEqualTo _primaryUV}) then {
	// Case 1: Connected to primary UV -> swap to previous UV
	if ([_previousUV] call RC_fnc_RC_isValidUV) then {
		[_previousUV, _previousUV_seat] call RC_fnc_RC_connectToUV;
	} else {
		if !(isRemoteControlling player) then {
			if ([_primaryUV] call RC_fnc_RC_isValidUV) then {
				[_primaryUV, _primaryUV_seat] call RC_fnc_RC_connectToUV;
			} else {
				hint "No previous/primary UV available to swap to. First swap away per hokey from a UV or set a primary UV.";
			};
		} else {
			hint "No previously selected UV available to swap to. Swap away per hokey from a UV first.";
		};
	};
} else {
	if (_connected) then {
		// Case 2: Connected to a different UV -> remember it and swap to primary UV
		player setVariable ["RC_previous_UV", _currentUV];

		if (isRemoteControlling player) then {
			player setVariable ["RC_previous_UV_seat", getConnectedUAVUnit player];
		};
	};

	if ([_primaryUV] call RC_fnc_RC_isValidUV) then {
		// Case 2 & 3: Connect to primary UV (not connected, or connected to non-primary)
		[_primaryUV, _primaryUV_seat] call RC_fnc_RC_connectToUV;
	} else {
		if !(isRemoteControlling player) then {
			if ([_previousUV] call RC_fnc_RC_isValidUV) then {
				[_previousUV, _previousUV_seat] call RC_fnc_RC_connectToUV;
			} else {
				hint "No primary/previous UV available to swap to. First set a primary UV or swap away per hokey from a UV.";
			};
		} else {
			hint "No primary UV available to swap to. Set a primary UV first.";
		};
	};
};
*/


/*
if (isRemoteControlling player) then {
	if (_connected && {_currentUV isEqualTo _primaryUV}) then {
		// Case 1: Connected to primary UV -> swap to previous UV
		if ([_previousUV] call RC_fnc_RC_isValidUV) then {
			[_previousUV, _previousUV_seat] call RC_fnc_RC_connectToUV;
		} else {
			hint "No previously selected UV available. Swap away per hokey from a UV first.";
		};
	} else {
		if (_connected) then {
			// Case 2: Connected to a different UV -> remember it and swap to primary UV
			player setVariable ["RC_previous_UV", _currentUV];
			player setVariable ["RC_previous_UV_seat", getConnectedUAVUnit player];
		};
		if ([_primaryUV] call RC_fnc_RC_isValidUV) then {
			// Case 2 & 3: Connect to primary UV (not connected, or connected to non-primary)
			[_primaryUV, _primaryUV_seat] call RC_fnc_RC_connectToUV;
		} else {
			hint "No primary UV available. Define a primary UV first.";
		};
	};
} else {
	if (_connected) then {
		// Case 2: Connected to a different UV -> remember it and swap to primary UV
		player setVariable ["RC_previous_UV", _currentUV];
		player setVariable ["RC_previous_UV_seat", getConnectedUAVUnit player];
	};
	if ([_primaryUV] call RC_fnc_RC_isValidUV) then {
		// Case 2 & 3: Connect to primary UV (not connected, or connected to non-primary)
		[_primaryUV, _primaryUV_seat] call RC_fnc_RC_connectToUV;
	} else {
		hint "No primary UV available. Define a primary UV first.";
	};
};
*/