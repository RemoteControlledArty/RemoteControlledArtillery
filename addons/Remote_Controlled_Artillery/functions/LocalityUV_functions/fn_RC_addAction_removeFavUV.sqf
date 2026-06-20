params ["_entity"];

_entity addAction [
	"remove UV from fav's",
	{
		params ["_target"];
		RC_UV_favs = RC_UV_favs - [_target];
	},
	nil,	// arguments
	1.5,	// priority
	false,	// showWindow
	true,	// hideOnUse
	"",		// shortcut
	"((isRemoteControlling player) && (_target isEqualTo (getConnectedUAV player)) && (RC_UV_favs find _target != -1))",	// condition
	5		// radius, >4m requied for larger vehicles
];


//player setVariable ["RC_primary_UV", objNull];
//player setVariable ["RC_primary_UV_seat", objNull];