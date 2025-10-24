/*
	Author: Ascent

	Description:
	Functional mineplow with early enough triggering to not ruin vehicle.
*/

params ['_veh'];

//widht=1.85x2, saver 1.9x2, 2m radius = -0.1 offset
//setCruiseControl does not work for AI
//scanradius/lowspeed=interval

//private _veh = getconnectedUAV player;

//center to mineplow = 3.7m
//hull until plow collider = 1.5m


[_veh] spawn {
	params ['_veh'];

	private _range = 4.2;
	private _scanRadius = 1.9;
	private _refRange = 10;
	private _height = -2.4;
	
	private _interval = 0.05;
	private _lowSpeed = 15;
	private _resetSpeed = 200;
	private _anim = "MovePlow";
	
	private _oldPos = getPosASL _veh;
	
	while {alive _veh} do {

		if !(local _veh) then {
			sleep 1;
			continue;
		};
	
		if (_veh animationPhase _anim > 0.5) then {
			
			if (_oldPos isNotEqualTo (getPosASL _veh)) then { 
				
				_veh setCruiseControl [_lowSpeed, false];
				_veh limitSpeed _lowSpeed;
	
				private _mines = nearestObjects [(_veh modelToWorld [0, _range, _height]), ["MineBase"], _scanRadius];
	
				private _refPos = (_veh modelToWorld [0, -_refRange, _height]);
				{
					if (((_refPos distance2D (ASLToAGL (getPosASL _x))) < (_refRange+_range)) && alive _x) then {
	
						triggerAmmo _x;
					};
				} forEach _mines;
			};
			_oldPos = getPosASL _veh;
		} else {
			_veh setCruiseControl [_resetSpeed, false];
			_veh limitSpeed _resetSpeed;
		};

		sleep _interval;
	};
};