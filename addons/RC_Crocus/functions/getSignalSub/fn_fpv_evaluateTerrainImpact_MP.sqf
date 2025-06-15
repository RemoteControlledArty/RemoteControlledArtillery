params ["_startPoint", "_endPoint"];
private _terrainInterceptionValue = 0;
private _initialPos = eyePos _startPoint;
private _finalPos = getPosWorld _endPoint;
private _isIntersecting = terrainIntersectASL [_initialPos, _finalPos];
_terrainInterceptionValue = if (_isIntersecting) then {1} else {0};
_terrainInterceptionValue