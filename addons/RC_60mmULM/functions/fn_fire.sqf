params ["_unit", "_weapon", "_muzzle", "_mode", "_ammo", "_magazine", "_projectile", "_gunner"];

if (!local _unit) exitwith {};
if (hasInterface) then {_gunner removeMagazine _magazine};

//velocity adjustment per venthole


/*
[_projectile] spawn {
	params ["_projectile"];
	sleep 0.01;
	
	private _vel = velocity _projectile;
	systemchat str _vel;
	if (RC_ULM_Velocity <= 0) exitWith {systemchat "vel <= 0"};
	_projectile setVelocity (_vel vectorMultiply (RC_ULM_Velocity / vectorMagnitude _vel));
};
*/



private _vel = velocity _projectile;
private _mag = vectorMagnitude _vel;
if (_mag <= 0) exitWith {systemchat "_mag <= 0"};

// how strong the random spread should be, in radians
private _spread = 0.6;

// random small yaw/pitch rotation
private _yaw   = random [-_spread, 0, _spread];
private _pitch = random [-_spread, 0, _spread];

// rotate vector by yaw then pitch
//private _dir = _vel vectorNormalize;
private _dir = vectorNormalized _vel;

_dir = [_dir, _yaw, _pitch] call {
    params ["_vec","_yaw","_pitch"];
    private _x0 = _vec select 0;
    private _y0 = _vec select 1;
    private _z0 = _vec select 2;

    // yaw (around Z)
    private _x1 = _x0 * cos _yaw - _y0 * sin _yaw;
    private _y1 = _x0 * sin _yaw + _y0 * cos _yaw;
    private _z1 = _z0;

    // pitch (around Y)
    private _x2 = _x1 * cos _pitch + _z1 * sin _pitch;
    private _y2 = _y1;
    private _z2 = -_x1 * sin _pitch + _z1 * cos _pitch;

    [_x2,_y2,_z2]
};

// scale to desired speed
private _speedSpread = 0.003;
_projectile setVelocity (_dir vectorMultiply (RC_ULM_Velocity * (1 + random [-_speedSpread, 0, _speedSpread])));


/*
private _targetSpeed = 200;
private _vel = velocity _projectile;
private _mag = vectorMagnitude _vel;
if (_mag <= 0) exitWith { systemChat "_mag <= 0"; };

// normalize velocity
private _dir = vectorNormalized _vel;

// spread strength in radians (e.g., 0.005 ≈ 0.29°)
private _spread = 0.5;

// pick a random small rotation axis perpendicular to direction
// generate a random vector, then make it orthogonal to _dir
private _randVec = [random 2 - 1, random 2 - 1, random 2 - 1];
private _axis = _randVec vectorCrossProduct _dir;
if ((vectorMagnitude _axis) < 0.0001) then { _axis = [0,0,1] vectorCrossProduct _dir; };
_axis = vectorNormalized _axis;

// random small rotation angle
private _angle = random [-_spread, 0, _spread];

// Rodrigues rotation formula
private _cosA = cos _angle;
private _sinA = sin _angle;
private _newDir =
    (_dir vectorMultiply _cosA)
    vectorAdd ((_axis vectorCrossProduct _dir) vectorMultiply _sinA)
    vectorAdd (_axis vectorMultiply ((1 - _cosA) * (_axis vectorDotProduct _dir)));

// apply new velocity
_projectile setVelocity (_newDir vectorMultiply _targetSpeed);
*/


/*
private _x0 = _dir select 0;
private _y0 = _dir select 1;
private _z0 = _dir select 2;

// yaw (around Z)
private _x1 = _x0 * cos _yaw - _y0 * sin _yaw;
private _y1 = _x0 * sin _yaw + _y0 * cos _yaw;
private _z1 = _z0;

// pitch (around Y)
private _x2 = _x1 * cos _pitch + _z1 * sin _pitch;
private _y2 = _y1;
private _z2 = -_x1 * sin _pitch + _z1 * cos _pitch;

_dir = [_x2,_y2,_z2];
*/


/*
private _vel = velocity _projectile;
if (RC_ULM_Velocity <= 0) exitWith {systemchat "vel <= 0"};
_projectile setVelocity (_vel vectorMultiply (RC_ULM_Velocity / vectorMagnitude _vel));
*/

/*
[_projectile] spawn {
	params ["_projectile"];
	sleep 0.01;
	
	private _vel = velocity _projectile;
	systemchat str _vel;
	if (RC_ULM_Velocity <= 0) exitWith {systemchat "vel <= 0"};
	_projectile setVelocity (_vel vectorMultiply (RC_ULM_Velocity / vectorMagnitude _vel));
};
*/


/*
private _targetSpeed = 200;
private _vel = velocity _projectile;
systemchat str _vel;
_projectile setVelocity (_vel vectorMultiply (_targetSpeed / vectorMagnitude _vel));
*/



/*
[_projectile] spawn {
	params ["_projectile"];
	sleep 1;
	
	private _targetSpeed = 200;
	private _vel = velocity _projectile;
	systemchat str _vel;
	if (_targetSpeed <= 0) exitWith {systemchat "vel <= 0"};
	_projectile setVelocity (_vel vectorMultiply (_targetSpeed / vectorMagnitude _vel));
};
*/

/*
private _targetSpeed = 200;
private _vel = velocity _projectile;
_projectile setVelocity (_vel vectorMultiply (_targetSpeed / vectorMagnitude _vel));

[_projectile] spawn {
	params ["_projectile"];
	sleep 0.01;
	_projectile setVelocity ((velocity _projectile vectorNormalize) vectorMultiply RC_ULM_Velocity);
};
*/


/*
diag_log format ["FiredEH start - proj: %1 | type: %2 | isLocal: %3 | owner: %4",
_projectile, typeOf _projectile, isLocal _projectile, owner _projectile];

private _vBefore = velocity _projectile;
diag_log format ["velocity before: %1 | speedBefore: %2 | dirBefore: %3",
_vBefore, _vBefore vectorMagnitude, (vectorNormalized _vBefore)];

private _targetSpeed = ULM_Velocity;
diag_log format ["ULM_Velocity: %1", _targetSpeed];
*/

/*
private _dir = vectorNormalized (velocity _projectile); // current fired direction (includes dispersion)
private _newVel = _dir vectorMultiply ULM_Velocity;
_projectile setVelocity _newVel;
*/


/*
private _targetSpeed = ULM_Velocity;
[_projectile, _targetSpeed] spawn {
    params ["_proj", "_speed"];
    sleep 0; // let engine initialize projectile
    private _dir = vectorNormalized (velocity _proj);
    if ((_dir vectorMagnitude) == 0) exitWith {}; // safety
    _proj setVelocity (_dir vectorMultiply _speed);
};
*/


[RC_ULM_ETA] spawn {
	params ["_ETA"];

	if (_ETA > 3) then {
		sleep (_ETA - 3);
		systemchat "splash in 3sec";
		sleep 3;
	} else {
		sleep _ETA;
	};

	systemchat "splash";
};