params ["_vic", "_vicCenter", "_projPos", "_projVel", "_curDist"];

private _vicVel  = velocity _vic;
private _projSpeed = vectorMagnitude _projVel;
//if (_projSpeed < 1) then { continue };	//needed and where to put?

private _time = _curDist / _projSpeed;

private _vicFuture = [
	(_vicCenter#0) + (_vicVel#0)*_time,
	(_vicCenter#1) + (_vicVel#1)*_time,
	(_vicCenter#2) + (_vicVel#2)*_time
];
private _projFuture = [
	(_projPos#0) + (_projVel#0)*_time,
	(_projPos#1) + (_projVel#1)*_time,
	(_projPos#2) + (_projVel#2)*_time
];

//output
[_vicFuture, _projFuture]