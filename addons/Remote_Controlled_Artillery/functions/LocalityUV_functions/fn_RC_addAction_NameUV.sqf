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

//"isRemoteControlling player"
//(isRemoteControlling player) && ((groupId group this) find (name player) != -1)
//(isRemoteControlling player) && ((groupId group _target) find (name player) != -1)

/*
_this addAction [
	"Test3",
	{
		params ["_target"];
		[[_target, name player], RC_fnc_RC_NameUV_Server] remoteExec ["call", 2];
	},
	nil,
	1.5,
	true,
	true,
	"",
	"((groupId group _target) find (name player) != -1)"
];
*/

/*
    params: [_uav]
    returns: true if the rename action should be shown for the local player
*/

_this addAction [
    "Test4",
    {
        params ["_target","_caller"];
        [[_target, name player], RC_fnc_RC_NameUV_Server] remoteExec ["call", 2];
    },
    nil, 1.5, true, true, "",
    "([this] call RC_fnc_canRenameUAV)"
];


_this addAction [
    "Test4",
    {
        params ["_target","_caller"];
        [[_target, name player], RC_fnc_RC_NameUV_Server] remoteExec ["call", 2];
    },
    nil, 1.5, true, true, "",
    "([this] call RC_fnc_Test4)"
];



private _fnc_Test4 = { 
	params ["_uav"];

	if (isNull _uav) exitWith { false };

	private _grp = group _uav;
	private _gid = "";
	if (!isNull _grp) then {
		_gid = groupId _grp;
	};

	private _gidL = toLower _gid;
	private _playerL = toLower name player;

	if (_gidL == "") exitWith { true };
	if (_gidL find _playerL != -1) exitWith { false };
	true;
};