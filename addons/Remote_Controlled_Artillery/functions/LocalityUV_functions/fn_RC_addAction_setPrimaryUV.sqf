params ["_entity"];

_entity addAction [
	"Set as primary UV",
	{
		params ["_target"];
		player setVariable ["RC_primary_UV", _target];
		player setVariable ["RC_primary_UV_seat", (getConnectedUAVUnit player)];
	},
	nil,	// arguments
	1.5,	// priority
	false,	// showWindow
	true,	// hideOnUse
	"",		// shortcut
	//"(isRemoteControlling player)",	// condition
	"((isRemoteControlling player) && ((getConnectedUAVUnit player) isNotEqualTo (player getVariable ['RC_primary_UV_seat', objNull])))",	// condition
	//"(isRemoteControlling player) && ((getConnectedUAV player) isNotEqualTo (player getVariable ['RC_primary_UV', objNull])) && ((getConnectedUAVUnit player) isNotEqualTo (player getVariable ['RC_primary_UV_seat', objNull]))",	// condition
	1		// radius
];

/*
_entity addAction [
	"Set as secondary UV",
	{
		params ["_target"];
		player setVariable ["RC_secondary_UV", _target];
		player setVariable ["RC_secondary_UV_seat", (getConnectedUAVUnit player)];
	},
	nil,	// arguments
	1.5,	// priority
	false,	// showWindow
	true,	// hideOnUse
	"",		// shortcut
	//"(isRemoteControlling player)",	// condition
	"((isRemoteControlling player) && ((getConnectedUAVUnit player) isNotEqualTo (player getVariable ['RC_secondary_UV_seat', objNull])))",	// condition
	1		// radius
];
*/