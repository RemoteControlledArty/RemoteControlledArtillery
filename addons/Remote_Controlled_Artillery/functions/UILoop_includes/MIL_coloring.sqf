// set color for elevation ctrl
private _usedAngle = (abs (_highAngleSol - _realElevation)) min (abs (_lowAngleSol - _realElevation));
private _colorEL = [[0.725,1,0.5,1], COLOR_CLOSE_TARGET, 0.12, _usedAngle min 10] call BIS_fnc_interpolateVector;
_ctrlElevation ctrlSetTextColor ([[1, 1, 1, 1], _colorEL] select (_usedAngle <= 10.0));

if (_lockedGuided) then {
	if ((_realElevation < (_lowAngleSol + 6)) and (_realElevation > (_lowAngleSol - 6))) then {_ctrlElevation ctrlSetTextColor [0,1,0,1];};
	if ((_realElevation < (_highAngleSol + 6)) and (_realElevation > (_highAngleSol - 6))) then {_ctrlElevation ctrlSetTextColor [0,1,0,1];};
} else {
	if ((_realElevation < (_lowAngleSol + 0.3)) and (_realElevation > (_lowAngleSol - 0.3))) then {_ctrlElevation ctrlSetTextColor [0,1,0,1];};
	if ((_realElevation < (_highAngleSol + 0.3)) and (_realElevation > (_highAngleSol - 0.3))) then {_ctrlElevation ctrlSetTextColor [0,1,0,1];};
};

// set color for azimuth ctrl
private _difference = abs (_targetAzimuth - _realAzimuth);
private _colorAZ = [[0.725,1,0.5,1], COLOR_CLOSE_TARGET, 0.057, _difference min 20] call BIS_fnc_interpolateVector;
_ctrlAzimuth ctrlSetTextColor ([[1, 1, 1, 1], _colorAZ] select (_difference <= 20.0));

if (_lockedGuided) then {
	if ((_realAzimuth < (_targetAzimuth + 6)) and (_realAzimuth > (_targetAzimuth - 6))) then {_ctrlAzimuth ctrlSetTextColor [0,1,0,1];};
} else {
	if ((_realAzimuth < (_targetAzimuth + 0.3)) and (_realAzimuth > (_targetAzimuth - 0.3))) then {_ctrlAzimuth ctrlSetTextColor [0,1,0,1];};
};