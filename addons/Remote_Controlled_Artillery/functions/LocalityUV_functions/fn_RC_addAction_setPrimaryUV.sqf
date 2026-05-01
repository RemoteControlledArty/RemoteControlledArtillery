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
	"((isRemoteControlling player) && (_target isEqualTo (getConnectedUAV player)) && ((getConnectedUAVUnit player) isNotEqualTo (player getVariable ['RC_primary_UV_seat', objNull])))",	// condition
	5		// radius, >4m requied for larger vehicles
];


/*
{
	params ["_target"];
	
	private _previousPrimaryUV = player getVariable ["RC_primary_UV",  objNull];
	private _previousPrimaryUV_seat = player getVariable ["RC_primary_UV_seat",  objNull];
	
	if ([_previousPrimaryUV] call RC_fnc_RC_isValidUV) then {
		player setVariable ["RC_previous_UV", _previousPrimaryUV];
		player setVariable ["RC_previous_UV_seat", _previousPrimaryUV_seat];
	};

	player setVariable ["RC_primary_UV", _target];
	player setVariable ["RC_primary_UV_seat", (getConnectedUAVUnit player)];
},
*/


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