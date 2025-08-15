/*
	Author: Ascent

	Description:
	If line of sight: Warning sound for any hostile AT, marks source of fire briefly in datalink.
*/

params ['_target','_unit'];

private _vic = _target;
private _source = _unit;

if ((_vic distance _source) > 4000) exitwith {};
if (!RC_AT_SourceIndicationStatic && !RC_AT_SourceIndicationInf && !RC_AT_SourceIndicationVic) exitwith {};
if (([_source, 'GEOM', _vic] checkVisibility [eyePos _source, eyePos _vic]) == 0) exitwith {};

private _crew = (crew _vic) select {isPlayer _x};
[['\A3\Sounds_F\vehicles\air\noises\alarm_locked_by_missile_1.wss', 0.3]] remoteExec ['playSoundUI', _crew];

private _controllers = (UAVControl _vic);
private _controller1 = _controllers select 0;
if (_controller1 isNotEqualTo objNull) then {
	[['\A3\Sounds_F\vehicles\air\noises\alarm_locked_by_missile_1.wss', 0.3]] remoteExec ['playSoundUI', _controller1];

	if (count _controllers > 2) then {
		private _controller2 = _controllers select 3;
		[['\A3\Sounds_F\vehicles\air\noises\alarm_locked_by_missile_1.wss', 0.3]] remoteExec ['playSoundUI', _controller2];
	};
};


private _side = side _vic;
if (_source isKindOf 'StaticWeapon' && RC_AT_SourceIndicationStatic) then {
	[_side, [_source, 300]] remoteExec ['reportRemoteTarget', _side];
	[_source, [_side, true]] remoteExec ['confirmSensorTarget', _side];
} else {
	if (_source isKindOf 'Man' && RC_AT_SourceIndicationInf) then {
		[_side, [_source, 10]] remoteExec ['reportRemoteTarget', _side];
		[_source, [_side, true]] remoteExec ['confirmSensorTarget', _side];
	} else {
		if (RC_AT_SourceIndicationVic) then {
			[_side, [_source, 20]] remoteExec ['reportRemoteTarget', _side];
			[_source, [_side, true]] remoteExec ['confirmSensorTarget', _side];
		};
	};
};


//turns turret to AT source
//cfg values
private _turretPath = getArray (configFile >> "CfgVehicles" >> typeOf _vic >> "RC_ATrespondingTurret");
private _gunTurretID = _vic turretOwner _turretPath;

//run where turret is local to work for UAV's


//params ['_target','_unit', '_turretPath'];
private _turnTime = 3.5;

if (isPlayer _gunTurretID) then {
	private _turretCfg = [_vic, _turretPath] call BIS_fnc_turretConfig;
	private _rotSpeedH = getNumber (_turretCfg >> "maxHorizontalRotSpeed");
	private _rotSpeedV = getNumber (_turretCfg >> "maxVerticalRotSpeed");

	//turret angles
	private _p0 = positionCameraToWorld [0,0,0];
	private _p1 = positionCameraToWorld [0,0,1];
	private _fwd = _p1 vectorDiff _p0;				  	// camera forward vector in world
	private _dirTurret = (_fwd #0) atan2 (_fwd #1);		// 0° = North, 90° = East (Arma style)
	if (_dirTurret < 0) then {_dirTurret = _dirTurret + 360};

	private _pitchTurret = (_fwd #2) atan2 sqrt((_fwd #0)^2 + (_fwd #1)^2);

	//vic to source angles
	private _posVic = getPosASL _vic;
	private _posSource = eyePos _source;

	private _dx = (_posSource # 0) - (_posVic # 0);
	private _dy = (_posSource # 1) - (_posVic # 1);
	private _dz = (_posSource # 2) - (_posVic # 2);

	private _dirSource = _dx atan2 _dy;	 // atan2(X, Y) for compass-style
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

//turn RE
[_vic, _posSource, _turretPath, _turnTime] spawn {

	params ['_vic','_posSource','_turretPath', '_turnTime'];

	private _gunTurretID = _vic turretOwner _turretPath;
	[_vic, [_posSource, _turretPath, true]] remoteExec ['lockCameraTo', _gunTurretID];
	sleep _turnTime;
	[_vic, [objNull, _turretPath, true]] remoteExec ['lockCameraTo', _gunTurretID];
};


//hint format ["_dirRel %1 _dirAngle %2 _dirDiff %3 _pitchDiff %4 _turnTimeH %5 _turnTimeV %6 _turnTime %7", _dirSource, _dirTurret, _dirDiff, _pitchDiff, _turnTimeH, _turnTimeV, _turnTime];