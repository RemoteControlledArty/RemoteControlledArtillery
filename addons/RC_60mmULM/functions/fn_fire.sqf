params ["_unit", "_weapon", "_muzzle", "_mode", "_ammo", "_magazine", "_projectile", "_gunner"];

if (!local _unit) exitwith {};
if (hasInterface) then {_gunner removeMagazine _magazine};


//velocity adjustment per venthole
/*
private _vel = velocity _projectile;
if (RC_ULM_Velocity <= 0) exitWith {systemchat "vel <= 0"};
_projectile setVelocity (_vel vectorMultiply (RC_ULM_Velocity / vectorMagnitude _vel));
*/

[_projectile] spawn {
	params ["_projectile"];
	sleep 1;
	
	private _vel = velocity _projectile;
	systemchat str _vel;
	if (RC_ULM_Velocity <= 0) exitWith {systemchat "vel <= 0"};
	_projectile setVelocity (_vel vectorMultiply (RC_ULM_Velocity / vectorMagnitude _vel));
};

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