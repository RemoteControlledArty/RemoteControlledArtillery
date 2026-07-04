//required to define side of storage container, so neutral throwable FPV can be requested from container last opened from specific side

player addEventHandler ["InventoryClosed", {
	params ["_unit", "_container"];

	_container setVariable ["RC_FPV_ContainerSide", side player, true];
}];


//temporary overwritable define of check above function
fnc_checkAbove = {
	params ["_veh"];

	private _pos = getPosASL _veh;
	private _height = 50;
	private _i = 0;
	private _hasAbove = false;

	/*
	//reduced size version
	private _endPos = [(_pos #0), (_pos #1), (_pos #2) + _height];
	_hasAbove = lineIntersects [_pos, _endPos, _veh, objNull];
	*/

	private _coords = [[0, 0], [1, 1], [-1, 1], [1, -1], [-1,-1]];
	
	while {!_hasAbove && _i < count _coords} do {

		private _x = _coords #_i;
		private _startPos = [(_pos #0) + (_x #0), (_pos #1) + (_x #1), (_pos #2)];
		private _endPos = [(_startPos #0), (_startPos #1), (_pos #2) + _height];
		_hasAbove = lineIntersects [_startPos, _endPos, _veh, objNull];
		_i = _i + 1;
	};

	if (_hasAbove) then {

		private _posATL = getPosATL _veh;
		private _str = "FPV request failed at y" + str (round (_posATL #0)) + " x" + str (round (_posATL #1)) + ", obstructed above, cannot start.";

		systemchat _str;
		_continue = false;

		//output
		_continue
	};
};


