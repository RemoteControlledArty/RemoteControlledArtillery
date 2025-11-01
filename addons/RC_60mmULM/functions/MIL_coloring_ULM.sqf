//needs to be adjusted so that there is a large color difference for the last +-0.3 MIL

// Set color for elevation ctrl
private _differenceHighAngle = abs (_highAngleSol - _realElevation);
private _differenceMediumAngle = abs (_mediumAngleSol - _realElevation);
private _colorEL = [[0.725,1,0.5,1], COLOR_CLOSE_TARGET, 0.12, (_differenceHighAngle min _differenceMediumAngle) min 10] call BIS_fnc_interpolateVector;
_ctrlElevation ctrlSetTextColor ([[1, 1, 1, 1], _colorEL] select ((_differenceHighAngle min _differenceMediumAngle) <= 10.0));

if ((_realElevation < (_mediumAngleSol + 0.5)) and (_realElevation > (_mediumAngleSol - 0.5))) then {_ctrlElevation ctrlSetTextColor [0,1,0,1];};
if ((_realElevation < (_highAngleSol + 0.5)) and (_realElevation > (_highAngleSol - 0.5))) then {_ctrlElevation ctrlSetTextColor [0,1,0,1];};

if (_usingMediumAngle) then {
	if (_adjustedVelocityMedium == 0) then {_ctrlElevation ctrlSetTextColor [1, 1, 1, 1]};
} else {
	if (_adjustedVelocityHigh == 0) then {_ctrlElevation ctrlSetTextColor [1, 1, 1, 1]};
};

// Set color for azimuth ctrl
private _difference = abs (_targetAzimuth - _realAzimuth);
private _colorAZ = [[0.725,1,0.5,1], COLOR_CLOSE_TARGET, 0.057, _difference min 20] call BIS_fnc_interpolateVector;
_ctrlAzimuth ctrlSetTextColor ([[1, 1, 1, 1], _colorAZ] select (_difference <= 20.0));


if ((_realAzimuth < (_targetAzimuth + 0.5)) and (_realAzimuth > (_targetAzimuth - 0.5))) then {_ctrlAzimuth ctrlSetTextColor [0,1,0,1];};