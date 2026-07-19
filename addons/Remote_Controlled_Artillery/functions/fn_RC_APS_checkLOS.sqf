params ["_vic", "_proj", "_projPos", "_vicCenter", "_fwd", "_halfWidth", "_halfLength"];

// vehicle pivot: mass center, raised to height of sensors
private _sensorsHeight = 1.4;
private _centerPos = _vicCenter vectorAdd [0,0,_sensorsHeight];

// horizontal approach direction and its perpendicular
private _dirHoriz = [(_projPos#0)-(_centerPos#0), (_projPos#1)-(_centerPos#1), 0];
_dirHoriz = vectorNormalized _dirHoriz;
private _perp = [-(_dirHoriz#1), (_dirHoriz#0), 0];

private _offsetDist = (_halfWidth  * abs(_right vectorDotProduct _perp))
					+ (_halfLength * abs(_fwd   vectorDotProduct _perp));

// side sensors if center sensor obstructed
private _leftPos  = _centerPos vectorAdd (_perp vectorMultiply _offsetDist);
private _rightPos = _centerPos vectorAdd (_perp vectorMultiply (-_offsetDist));

// building/rock obstruction check from center, left, right sensors
private _fnc_objClear = {
	params ["_from"];
	private _hits = lineIntersectsObjs [_from, _projPos, _vic, _proj, false];
	({_x isKindOf "Building" || {_x isKindOf "Rock"}} count _hits) == 0
};

private _objClear = ([_centerPos] call _fnc_objClear)
				|| ([_leftPos]   call _fnc_objClear)
				|| ([_rightPos]  call _fnc_objClear);

// output
_objClear