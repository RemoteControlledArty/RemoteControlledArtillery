params ["_unit", "_string", "_ctrl"];

sleep 3;
systemChat _string;

if (_ctrl) then {
	player remoteControl objNull;
	player connectTerminalToUAV objNull;
};