params ["_entity"];

_entity addAction [
	"add UV to fav's",
	{
		params ["_target"];
		_target setVariable ["RC_UV_seat", (getConnectedUAVUnit player)];
		RC_UV_favs pushBackUnique _target;
	},
	nil,	// arguments
	1.5,	// priority
	false,	// showWindow
	true,	// hideOnUse
	"",		// shortcut
	"((isRemoteControlling player) && (_target isEqualTo (getConnectedUAV player)) && (RC_UV_favs find _target == -1))",	// condition
	5		// radius, >4m requied for larger vehicles
];