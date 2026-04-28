// --- Helper: connect player terminal to a UV (and attempt to open UAV terminal UI) ---
params ["_uav", "_seat"];

// connect UV
player connectTerminalToUAV _uav;

// check if seat exists, prevents major bugs
if (_seat isNotEqualTo objNull) then {
	// direct control of driver or gunner
	driver _uav switchCamera "Internal";
	player remoteControl _seat;
} else {
	// fallback: open terminal
	if (isNull (findDisplay 160)) then {
		player action ["UAVTerminalOpen", player];
	};
};


/*
// check if seat exists
if (_seat isEqualTo objNull) then {
	if (gunner _uav isNotEqualTo objNull) then {
		_seat = gunner _uav;
	} else {
		if (driver _uav isNotEqualTo objNull) then {
			_seat = driver _uav;
		};
	};
};

// savety
if (_seat isNotEqualTo objNull) then {
	// direct control of driver or gunner
	driver _uav switchCamera "Internal";
	player remoteControl _seat;
} else {
	// fallback: open terminal
	if (isNull (findDisplay 160)) then {
		player action ["UAVTerminalOpen", player];
	};
};
*/