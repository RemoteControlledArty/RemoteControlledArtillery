params ["_unit", "_weapon", "_magazine"];

//if (!isServer) exitwith {};
//if (!local _unit) exitwith {};


//if ((RC_ETA_travelTimeLow <= 0) or (RC_ETA_travelTimeHigh <= 0) or (RC_ETA_Weapon isNotEqualTo _weapon)) exitwith {};
if (RC_ETA_Weapon isNotEqualTo _weapon) exitwith {};


if (isRemoteControlling player) then {
	if ((getConnectedUAV player) isNotEqualTo _unit) exitwith {};
} else {
	if ((vehicle player) isNotEqualTo _unit) exitwith {};
};


private _ETA = 0;
if ((abs (RC_ETA_realElevation - RC_ETA_lowAngleSol)) < (abs (RC_ETA_realElevation - RC_ETA_travelTimeLow))) then {
	_ETA = RC_ETA_travelTimeLow;
} else {
	_ETA = RC_ETA_travelTimeHigh;
};


private _magName = getText (configFile >> "CfgMagazines" >> _magazine >> "displayName");
if (isNil _magName) then {
	_magName = "?";
};

systemchat _magName;

/*
private _crew = (crew _unit) select {isPlayer _x};
private _controllers = (UAVControl _unit);
private _controller1 = _controllers select 0;

if (_controller1 isNotEqualTo objNull) then {
	_crew pushBack _controller1;

	if (count _controllers > 2) then {
		_crew pushBack (_controllers select 2);
	};
};
*/


private _crew = (crew (vehicle player)) select {isPlayer _x};
[RC_ETA_targetName, _magName, RC_ETA_distance, RC_ETA_charge, RC_ETA_realElevation, RC_ETA_aligned, _ETA] remoteExec ["RC_fnc_RC_ETA", _crew];