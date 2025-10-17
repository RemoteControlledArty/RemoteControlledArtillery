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
	"isRemoteControlling player"
];

//(isRemoteControlling player) && ((groupId group this) find (name player) != -1)
//(isRemoteControlling player) && ((groupId group _target) find (name player) != -1)