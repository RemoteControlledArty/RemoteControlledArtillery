// --- Helper: connect player terminal to a UV (and attempt to open UAV terminal UI) ---
params ["_uav", "_seat"];

player connectTerminalToUAV _uav;

// check if seat exists, prevents major bugs
if (_seat isNotEqualTo objNull) then {
	// direct control of driver or gunner
	player remoteControl _seat;
	_seat switchCamera "GUNNER";
} else {
	// fallback: open terminal
	if (isNull (findDisplay 160)) then {
		player action ["UAVTerminalOpen", player];
	};
};