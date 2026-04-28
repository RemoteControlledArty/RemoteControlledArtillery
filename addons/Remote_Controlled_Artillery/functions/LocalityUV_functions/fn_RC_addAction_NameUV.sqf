params ["_entity"];

_entity addAction [
	"Name UV",
	{
		params ["_target"];
		[[_target, name player], RC_fnc_RC_NameUV_Server] remoteExec ["call", 2];
	},
	nil,	// arguments
	1.5,	// priority
	false,	// showWindow
	true,	// hideOnUse
	"",		// shortcut
	"(isRemoteControlling player) && ((groupId group (getconnectedUAV player)) find (trim (((name player) splitString '. ') select ((count ((name player) splitString '. ')) - 1))) == -1)",	// condition
	1		// radius
];
//"(isRemoteControlling player) && (((groupId group (getConnectedUAV player)) select [0, (groupId group (getConnectedUAV player)) find ',']) find (trim (((name player) splitString '. ') select ((count ((name player) splitString '. ')) - 1))) == -1)"
//"(isRemoteControlling player) && ((groupId group (getconnectedUAV player)) find (trim (((name player) splitString '. ') select ((count ((name player) splitString '. ')) - 1))) == -1)"