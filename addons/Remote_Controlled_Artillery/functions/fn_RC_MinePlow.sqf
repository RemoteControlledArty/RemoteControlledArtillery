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

	private _range1 = 3.9;
	private _range2 = 3.15;
	private _scanRadius = 2;
	private _interval = 0.05;
	private _lowSpeed = 20;
	private _resetSpeed = 200;
	private _anim = "MovePlow";
	
	while {alive _veh} do {

		if !(local _veh) then {
			sleep 1;
			continue;
		};
	
		if (_veh animationPhase _anim > 0.5) then {
			
			_veh setCruiseControl [_lowSpeed, false];
			_veh limitSpeed _lowSpeed;
			
			private _mines = nearestObjects [(_veh modelToWorld [0, _range1, -2]), ["MineBase"], _scanRadius];
    		_mines pushBackUnique (nearestObjects [(_veh modelToWorld [0, _range2, -2]), ["MineBase"], _scanRadius]);

			private _refPos = (_veh modelToWorld [0, 10, -2]);
			{
				//even with > 0.4 doesnt work?
				if ((_refPos distance2D (getPosAGL _x)) > 6.1) then {
					if (alive _x) then {

						triggerAmmo _x;
					};
				};
			} forEach _mines;
		} else {
			_veh setCruiseControl [_resetSpeed, false];
			_veh limitSpeed _resetSpeed;
		};

		sleep _interval;
	};
};