params ["_vic", "_proj", "_projPos", "_vicCenter"];

// vehicle pivot: mass center, raised to roughly turret height
private _vicCenterAGL = _vic modelToWorldVisual (getCenterOfMass _vic);
private _vicCenter = AGLToASL _vicCenterAGL;
private _sensorsHeight = 1.4;	//above centerMass
private _sensorCenterPos = _vicCenter vectorAdd [0,0,_sensorsHeight];

// horizontal approach direction and its perpendicular
private _dirHoriz = [(_projPos#0)-(_sensorCenterPos#0), (_projPos#1)-(_sensorCenterPos#1), 0];
_dirHoriz = vectorNormalized _dirHoriz;
private _perp = [-(_dirHoriz#1), (_dirHoriz#0), 0];

// vehicle's own forward/right axes, flattened horizontally
private _fwd = vectorDirVisual _vic;
_fwd = vectorNormalized [_fwd#0, _fwd#1, 0];
private _right = [(_fwd#1), -(_fwd#0), 0];

// fixed generic armored vehicle size
private _halfWidth  = 1.6;
private _halfLength = 3.6;

private _offsetDist = (_halfWidth  * abs(_right vectorDotProduct _perp))
					+ (_halfLength * abs(_fwd   vectorDotProduct _perp));

private _sensorLeftPos  = _sensorCenterPos vectorAdd (_perp vectorMultiply _offsetDist);
private _sensorRightPos = _sensorCenterPos vectorAdd (_perp vectorMultiply (-_offsetDist));

// building/rock obstruction check from center, left, right sensors
private _fnc_objClear = {
	params ["_from"];
	private _hits = lineIntersectsObjs [_from, _projPos, _vic, _proj, false];
	({_x isKindOf "Building" || {_x isKindOf "Rock"}} count _hits) == 0
};

private _objClear = ([_sensorCenterPos] call _fnc_objClear)
				|| ([_sensorLeftPos]   call _fnc_objClear)
				|| ([_sensorRightPos]  call _fnc_objClear);

//output
_objClear