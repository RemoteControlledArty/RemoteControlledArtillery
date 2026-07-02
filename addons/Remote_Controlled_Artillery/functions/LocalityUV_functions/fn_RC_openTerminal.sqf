if (isRemoteControlling player) then {
	
	player remoteControl objNull;
	player switchCamera "INTERNAL";
	player action ["UAVTerminalOpen", player];
} else {
	player action ["UAVTerminalOpen", player];
};