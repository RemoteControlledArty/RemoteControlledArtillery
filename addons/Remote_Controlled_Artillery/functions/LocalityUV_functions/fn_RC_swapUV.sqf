//systemchat "0";
private _primaryUV = player getVariable ["RC_primary_UV",  objNull];
private _primaryUV_seat = player getVariable ["RC_primary_UV_seat",  objNull];
private _previousUV = player getVariable ["RC_previous_UV", objNull];
private _previousUV_seat = player getVariable ["RC_previous_UV_seat", objNull];
private _currentUV = getConnectedUAV player;
private _connected = !isNull _currentUV;


//if RCing
if (isRemoteControlling player) then {	//systemchat "1 !RC";

	if (_currentUV isEqualTo _primaryUV) then {	//systemchat "2";

		//here to not close previous arty UI (closed when not RCing) when swapping to primary spotting UV
		call RC_fnc_RC_stopRC;
	} else {	//systemchat "3";

		//set currentUV as previousUV if its valid
		if ([_currentUV] call RC_fnc_RC_isValidUV) then {	//systemchat "5";

			player setVariable ["RC_previous_UV", _currentUV];
			player setVariable ["RC_previous_UV_seat", getConnectedUAVUnit player];	 //able to set seat for direct control
		};

		if ([_primaryUV] call RC_fnc_RC_isValidUV) then {	//systemchat "6";

			[_primaryUV, _primaryUV_seat] call RC_fnc_RC_connectToUV;
		} else {	//systemchat "7";
			
			//here to not close previous arty UI (closed when not RCing) when swapping to primary spotting UV
			call RC_fnc_RC_stopRC;
		};
	};
} else {	//systemchat "8 RC";

	//if not RCing
	if (_currentUV isEqualTo _primaryUV) then {	//systemchat "9";
		
		if ([_previousUV] call RC_fnc_RC_isValidUV) then {	//systemchat "10";

			//only direct control if seat valid, otherwise open terminal
			[_previousUV, _previousUV_seat] call RC_fnc_RC_choosePreviousUV;
		} else {	//systemchat "11";

			//fallback if previous invalid
			if ([_primaryUV] call RC_fnc_RC_isValidUV) then {	//systemchat "12";

				[_primaryUV, _primaryUV_seat] call RC_fnc_RC_connectToUV;
			} else {

				hint "No primary/previous UV available to swap to. First set a primary UV or swap away per hokey from a UV.";
			};
		};

	} else {	//systemchat "13";
		
		//set currentUV as previousUV if its valid
		if ([_currentUV] call RC_fnc_RC_isValidUV) then {	//systemchat "15";

			player setVariable ["RC_previous_UV", _currentUV];	//unable to set seat due to no RCing, but still saves UV to atleast open terminal
			_previousUV = _currentUV;							//overwrite required
		};

		if ([_primaryUV] call RC_fnc_RC_isValidUV) then {	//systemchat "16";

			[_primaryUV, _primaryUV_seat] call RC_fnc_RC_connectToUV;
		} else {	//systemchat "17";

			//fallback if primary invalid
			if ([_previousUV] call RC_fnc_RC_isValidUV) then {	//systemchat "18";
				
				//only direct control if seat valid, otherwise open terminal
				[_previousUV, _previousUV_seat] call RC_fnc_RC_choosePreviousUV;
			} else {

				hint "No primary/previous UV available to swap to. First set a primary UV or swap away per hokey from a UV.";
			};
		};
	};
};