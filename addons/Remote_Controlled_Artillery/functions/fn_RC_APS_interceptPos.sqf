params ["_vicCenter", "_projPos", "_projVel"];

//private _dist = _projPos distance (getPosASL _vic);
private _dist = _projPos distance _vicCenter;
private _timeOffset = ((_dist/2) min 15) / (vectorMagnitude _projVel);
private _interceptPos = [
	(_projPos #0) + (_projVel #0) * _timeOffset,
	(_projPos #1) + (_projVel #1) * _timeOffset,
	(_projPos #2) + (_projVel #2) * _timeOffset
];
_interceptPosATL = ASLToATL _interceptPos;

//output
_interceptPosATL