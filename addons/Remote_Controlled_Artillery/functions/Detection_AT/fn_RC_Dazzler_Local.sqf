/*
	Author: Ascent

	Description:
	Dazzler
*/

params ["_vic", "_proj"];

//systemchat "Dazzler local"; 	//debug

[_vic, _proj] spawn {

	params ["_vic", "_proj"];

	while { (!(isNull _proj)) && (!(isNull _vic)) && (alive _vic)} do {

		private _dist = _proj distance _vic;
		if (_dist < 500) then {

			if (terrainIntersectASL [((getPosASL _vic) vectorAdd [0, 0, 2.5]), getPosASL _proj]) then {continue};
		
			//systemchat "<500m"; 	//debug

			private _vel = velocity _proj;

			private _minOffset = 0.1;
			private _maxOffset = 25;
			private _refDistance = 500;

			private _factor = 1 - ((_dist min _refDistance) / _refDistance);
			_offset = _minOffset + (_maxOffset - _minOffset) * _factor;
			
			_vel set [0, (_vel select 0) + (_offset - random (_offset * 2))];
			_vel set [1, (_vel select 1) + (_offset - random (_offset * 2))];
			_vel set [2, (_vel select 2) + (_offset - random (_offset * 2))];
			
			_proj setVelocity _vel;
		};

		sleep 0.1;
	};
};