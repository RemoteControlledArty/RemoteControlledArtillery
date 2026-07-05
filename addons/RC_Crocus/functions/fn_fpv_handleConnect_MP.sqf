RC_FPV_Target_Hash = createHashMap;

[] spawn {
	while { True } do {
		private _player = missionNamespace getVariable ["bis_fnc_moduleRemoteControl_unit", player];
		
		/*
		private _assignedItems = assignedItems _player;

		if ({ _x in _assignedItems } count RC_FPV_validTerminalsArr > 0) then {
			private _drones = vehicles select { (typeOf _x) in RC_FPV_validDronesArr };
			private _dronesNear = _player nearEntities [RC_FPV_validDronesArr, 4000];

			{
				_player disableUAVConnectability [_x, true];
			} forEach (_drones - _dronesNear);

			{
				if (_x getVariable ["RC_fpv_isUAVsignalLost", false]) then { continue };

				_player enableUAVConnectability [_x, true];
			} forEach _dronesNear;
		};
		*/

		//change to remote controlled UAV not connected, or make not connectable at double range of controllable
		if (((typeOf (getConnectedUAV _player)) in RC_FPV_validDronesArr) and (cameraView == "GUNNER") and ((typeOf cameraOn) in RC_FPV_validDronesArr)) then {

			missionNamespace setVariable ["RC_ArmaFPV_isControl", true];

			(getConnectedUAV _player) setVariable ["RC_fpv_isUAVsignalLost", false];

			call RC_fnc_fpv_createDialog_MP;

			waitUntil {!((typeOf (getConnectedUAV _player)) in RC_FPV_validDronesArr) or (cameraView != "GUNNER") or !((typeOf cameraOn) in RC_FPV_validDronesArr)};

			missionNamespace setVariable ["RC_ArmaFPV_isControl", false];

			call RC_fnc_fpv_destroyUI_MP;
		};

		sleep 0.1;
	};
};


[] spawn {
	waitUntil {!isNull findDisplay 46};

	findDisplay 46 displayAddEventHandler ["KeyDown", {
    	private _handled = false;

    	if (missionNamespace getVariable ["RC_ArmaFPV_isControl", false]) then {
        	if (inputAction "showMap" > 0) then {
            	_handled = true;
       		};
    	};

    	_handled;
	}];
};


[] spawn {
	private _signalDropTime = -1;

	while {true} do {
		private _player = missionNamespace getVariable ["bis_fnc_moduleRemoteControl_unit", player];
		private _uav = getConnectedUAV _player;
		private _connectedUAVType = typeOf _uav;

		if (isRemoteControlling _player && _connectedUAVType in RC_FPV_validDronesArr) then {
			private _uavSignal = [_player, _uav] call RC_fnc_fpv_getSignal_MP;

            if (_uavSignal < 0.05) then {
                if (_signalDropTime == -1) then {
                    _signalDropTime = time;
                } else {
					private _currentTime = (time - _signalDropTime);

					if (_currentTime >= 3) then {
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