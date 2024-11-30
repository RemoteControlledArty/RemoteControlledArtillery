//needs to be adjusted so that there is a large color difference for the last +-0.3 MIL

// Set color for elevation ctrl
private _differenceHighAngle = abs (_highAngleSol - _realElevation);
private _differenceLowAngle = abs (_lowAngleSol - _realElevation);
private _colorEL = [COLOR_ON_TARGET, COLOR_CLOSE_TARGET, 0.12, (_differenceHighAngle min _differenceLowAngle) min 10] call BIS_fnc_interpolateVector;
_ctrlElevation ctrlSetTextColor ([[1, 1, 1, 1], _colorEL] select ((_differenceHighAngle min _differenceLowAngle) <= 10.0));

// Set color for azimuth ctrl
private _difference = abs (_targetAzimuth - _realAzimuth);
private _colorAZ = [COLOR_ON_TARGET, COLOR_CLOSE_TARGET, 0.057, _difference min 20] call BIS_fnc_interpolateVector;
_ctrlAzimuth ctrlSetTextColor ([[1, 1, 1, 1], _colorAZ] select (_difference <= 20.0));