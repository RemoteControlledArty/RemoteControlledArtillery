params ["_driver"];

_driver addEventHandler ["SeatSwitchedMan", {
	params ["_unit1", "_unit2", "_vehicle"];

	if (isPlayer _unit1) exitWith {
		//systemchat "driver is player";
	};

	[_unit1, _vehicle] spawn {
		params ["_unit1", "_vehicle"];
		
		sleep 1;
		if (_unit1 isNotEqualTo (driver _vehicle)) then {
			_vehicle deleteVehicleCrew _unit1;
			//systemchat "deleted driver";
		};
	};
}];

/*
[] spawn {
	while {true} do {

		private _str = str (crew (vehicle player));
		systemchat _str;
		sleep 1;
	};
}; 
*/