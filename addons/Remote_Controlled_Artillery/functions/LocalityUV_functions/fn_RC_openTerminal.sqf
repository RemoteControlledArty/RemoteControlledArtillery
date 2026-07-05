if (isRemoteControlling player) then {

	player remoteControl objNull;
	player switchCamera "INTERNAL";
	player action ["UAVTerminalOpen", player];
} else {
	player action ["UAVTerminalOpen", player];
};


/*
//hotkey sadly doesnt work in terminal
if (isRemoteControlling player) then {

	player remoteControl objNull;
	player switchCamera "INTERNAL";
	player action ["UAVTerminalOpen", player];
} else {
	if (isNull (findDisplay 160)) then {
		//if terminal closed open terminal
		player action ["UAVTerminalOpen", player];
	} else {
		//if terminal open close terminal
		(findDisplay 160) closeDisplay 1;
	};
};
*/