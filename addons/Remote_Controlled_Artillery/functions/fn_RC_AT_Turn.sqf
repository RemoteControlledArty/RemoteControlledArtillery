/*
	Author: Ascent

	Description:
	Turns turret to detected AT source.
*/

params ['_vic','_source', '_turretPath'];

private _posSource = eyePos _source;
private _turnTime = 3.5;


private _controllers = (UAVControl _vic);
private _turretController = objNull;
if (_controllers #1 isEqualTo "GUNNER") then {_turretController = _controllers #0};
if (count _controllers > 2) then {
	if (_controllers #3 isEqualTo "GUNNER") then {_turretController = _controllers #2};
};

private _isPlayerCamera = (isPlayer (_vic turretUnit _turretPath)) or (isPlayer _turretController);


if (isPlayerCamera) then {
	private _turretCfg = [_vic, _turretPath] call BIS_fnc_turretConfig;
	private _rotSpeedH = getNumber (_turretCfg >> "maxHorizontalRotSpeed");
	private _rotSpeedV = getNumber (_turretCfg >> "maxVerticalRotSpeed");

	//turret angles
	private _p0 = positionCameraToWorld [0,0,0];
	private _p1 = positionCameraToWorld [0,0,1];
	private _fwd = _p1 vectorDiff _p0;				  	// camera forward vector in world
	private _dirTurret = (_fwd #0) atan2 (_fwd #1);
	if (_dirTurret < 0) then {_dirTurret = _dirTurret + 360};

	private _pitchTurret = (_fwd #2) atan2 sqrt((_fwd #0)^2 + (_fwd #1)^2);

	//vic to source angles
	private _posVic = getPosASL _vic;

	private _dx = (_posSource # 0) - (_posVic # 0);
	private _dy = (_posSource # 1) - (_posVic # 1);
	private _dz = (_posSource # 2) - (_posVic # 2);

	private _dirSource = _dx atan2 _dy;
	if (_dirSource < 0) then {_dirSource = _dirSource + 360};

	private _distHoriz = sqrt (_dx^2 + _dy^2);
	private _pitchSource = _dz atan2 _distHoriz;

	//angle differences
	private _dirDiff = abs((_dirSource - _dirTurret + 180) % 360 - 180);
	private _pitchDiff = abs(_pitchSource - _pitchTurret);

	//required time
	private _turnTimeH = (_dirDiff / (_rotSpeedH * 57.3));
	private _turnTimeV = (_pitchDiff / (_rotSpeedV * 57.3));
	private _turnTime = (_turnTimeH max _turnTimeV) + 1;	//+1 for acceleration & deaccelecation of turret
};


[_vic, _posSource, _turretPath, _turnTime] spawn {

	params ['_vic','_posSource','_turretPath', '_turnTime'];

	_vic lockCameraTo [_posSource, _turretPath, true];
	sleep _turnTime;
    _vic lockCameraTo [objNull, _turretPath, true];
};


//hint format ["_dirRel %1 _dirAngle %2 _dirDiff %3 _pitchDiff %4 _turnTimeH %5 _turnTimeV %6 _turnTime %7", _dirSource, _dirTurret, _dirDiff, _pitchDiff, _turnTimeH, _turnTimeV, _turnTime];