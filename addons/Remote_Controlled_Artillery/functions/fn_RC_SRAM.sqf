params ["_veh", "_p"];

[_veh, _p] spawn {

	params ["_veh", "_p"];

    //sleep 1.5;

	while {(!(isNull _p)) && (!(isNull _veh)) && (alive _veh)} do {

		/*
        private _t = locked target or center of screen;
        private _vel = velocity _p;
        private _dir = dir bet
        _p setDir _dir; //run once or constant?
        */

        //inaccurate past 1000m, its for a hyper agile missile using most of its propellant for steering
		//past that eighter make inaccurate or detonate to prevent unintended casualties
		if ((_p distance _veh) > 1000) then {
			triggerAmmo _p;
		};
	};
};


/*
[_veh, _p] spawn {

	params ["_veh", "_p"];

	while {(!(isNull _p)) && (!(isNull _veh)) && (alive _veh)} do {

		private _dist = _p distance _veh;
		
		//inaccurate past 1000m, its for a hyper agile missile using most of its propellant for steering
		//past that eighter make inaccurate or detonate to prevent unintended casualties
		if (_dist > 1000) then {

			triggerAmmo _p;

			private _vel = velocity _p;
			*/

			/*
			private _minOffset = 0.1;
			private _maxOffset = 25;
			private _refDistance = 1000;

			private _factor = (((_dist - _refDistance) max 0) / _refDistance) min 1;
			_offset = _minOffset + (_maxOffset - _minOffset) * _factor;
			*/

			/*
			private _offset = 10;

			_vel set [0, (_vel select 0) + (_offset - random (_offset * 2))];
			_vel set [1, (_vel select 1) + (_offset - random (_offset * 2))];
			_vel set [2, (_vel select 2) + (_offset - random (_offset * 2))];

			_p setVelocity _vel;
		};
	};
};
*/


/*
(getConnectedUAV player) addEventHandler ["Fired", {
	params ["_unit", "_weapon", "_muzzle", "_mode", "_ammo", "_magazine", "_projectile", "_gunner"];

	if (isNil {_projectile getVariable "RC_AR_Prj"}) then {

		private _posAGL = (ASLToAGL (getPosASL _unit));
		private _time = (round diag_tickTime);

		_projectile setVariable ["RC_AR_Prj", ["M", [_posAGL], _time]];
	};

	RC_AR_projectile_arr pushbackUnique _projectile;
}];
*/
