params ["_entity"];

_entity addAction [
	"Remove as primary UV",
	{
		params ["_target"];
		player setVariable ["RC_primary_UV", objNull];
		player setVariable ["RC_primary_UV_seat", objNull];
	},
	nil,	// arguments
	1.5,	// priority
	false,	// showWindow
	true,	// hideOnUse
	"",		// shortcut
	"((isRemoteControlling player) && (_target isEqualTo (getConnectedUAV player)) && ((getConnectedUAVUnit player) isEqualTo (player getVariable ['RC_primary_UV_seat', objNull])))",	// condition
	5		// radius, >4m requied for larger vehicles
];