[] spawn {
	private _dronesArray = ["B_Crocus_MP", "B_Crocus_MP_Sens", "B_Crocus_MP_NV", "B_Crocus_MP_NV_Sens", "B_Crocus_MP_TI", "B_Crocus_MP_TI_Sens", "O_Crocus_MP", "O_Crocus_MP_Sens", "O_Crocus_MP_NV", "O_Crocus_MP_NV_Sens", "O_Crocus_MP_TI", "O_Crocus_MP_TI_Sens", "I_Crocus_MP", "I_Crocus_MP_Sens", "I_Crocus_MP_NV", "I_Crocus_MP_NV_Sens", "I_Crocus_MP_TI", "I_Crocus_MP_TI_Sens"];
	private _terminalsArray = ["B_UavTerminal", "O_UavTerminal", "I_UavTerminal"];

	while { True } do {
		private _player = missionNamespace getVariable ["bis_fnc_moduleRemoteControl_unit", player];
		private _assignedItems = assignedItems _player;

		if ({ _x in _assignedItems } count _terminalsArray > 0) then {
			private _drones = vehicles select { (typeOf _x) in _dronesArray };
			private _dronesNear = _player nearEntities [_dronesArray, 4000];

			{
				_player disableUAVConnectability [_x, true];
			} forEach (_drones - _dronesNear);

			{
				if (_x getVariable ["DB_fpv_isUAVsignalLost", false]) then { continue };

				_player enableUAVConnectability [_x, true];
			} forEach _dronesNear;
		};


		if (((typeOf (getConnectedUAV _player)) in _dronesArray) and (cameraView == "GUNNER") and ((typeOf cameraOn) in _dronesArray)) then {

			missionNamespace setVariable ["ArmaFPV_isControl", true];

			(getConnectedUAV _player) setVariable ["DB_fpv_isUAVsignalLost", false];

			call RC_fnc_fpv_createDialog_MP;

			waitUntil {!((typeOf (getConnectedUAV _player)) in _dronesArray) or (cameraView != "GUNNER") or !((typeOf cameraOn) in _dronesArray)};

			missionNamespace setVariable ["ArmaFPV_isControl", false];

			call DB_fnc_fpv_destroyUI;
		};

		sleep 0.1;
	};
};

[] spawn {
	waitUntil {!isNull findDisplay 46};

	findDisplay 46 displayAddEventHandler ["KeyDown", {
    	private _handled = false;

    	if (missionNamespace getVariable ["ArmaFPV_isControl", false]) then {
        	if (inputAction "showMap" > 0) then {
            	_handled = true;
       		};
    	};

    	_handled;
	}];
};

[] spawn {
	private _dronesArray = ["B_Crocus_MP", "B_Crocus_MP_Sens", "B_Crocus_MP_NV", "B_Crocus_MP_NV_Sens", "B_Crocus_MP_TI", "B_Crocus_MP_TI_Sens", "O_Crocus_MP", "O_Crocus_MP_Sens", "O_Crocus_MP_NV", "O_Crocus_MP_NV_Sens", "O_Crocus_MP_TI", "O_Crocus_MP_TI_Sens", "I_Crocus_MP", "I_Crocus_MP_Sens", "I_Crocus_MP_NV", "I_Crocus_MP_NV_Sens", "I_Crocus_MP_TI", "I_Crocus_MP_TI_Sens"];
	private _signalDropTime = -1;

	while {true} do {
		private _player = missionNamespace getVariable ["bis_fnc_moduleRemoteControl_unit", player];
		private _uav = getConnectedUAV _player;
		private _connectedUAVType = typeOf _uav;

		if (_connectedUAVType in _dronesArray) then {
			private _uavSignal = [_player, _uav] call DB_fnc_fpv_getSignal;

            if (_uavSignal < 0.05) then {
                if (_signalDropTime == -1) then {
                    _signalDropTime = time;
                } else {
					private _currentTime = (time - _signalDropTime);

					if (_currentTime >= 5) then {
						[_player, _uav] call RC_fnc_fpv_onSignalLost_MP;
						_signalDropTime = -1;
					};
                };
            } else {
                _signalDropTime = -1;
            };
		};

		sleep 0.1;
	};
};