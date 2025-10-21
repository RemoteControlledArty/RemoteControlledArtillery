params ["_entity"];

_entity addAction [
	"Name UV",
	{
		params ["_target"];
		[[_target, name player], RC_fnc_RC_NameUV_Server] remoteExec ["call", 2];
	},
	nil,
	1.5,
	true,
	true,
	"",
	"(isRemoteControlling player) && ((groupId group (getconnectedUAV player)) find (trim (((name player) splitString '. ') select ((count ((name player) splitString '. ')) - 1))) == -1)"
];
//"(isRemoteControlling player) && (((groupId group (getConnectedUAV player)) select [0, (groupId group (getConnectedUAV player)) find ',']) find (trim (((name player) splitString '. ') select ((count ((name player) splitString '. ')) - 1))) == -1)"
//"(isRemoteControlling player) && ((groupId group (getconnectedUAV player)) find (trim (((name player) splitString '. ') select ((count ((name player) splitString '. ')) - 1))) == -1)"