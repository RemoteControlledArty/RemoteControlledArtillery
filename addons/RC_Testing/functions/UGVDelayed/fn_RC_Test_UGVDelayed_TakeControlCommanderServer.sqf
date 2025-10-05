params ["_vic"];

private _com = commander _vic;

[_vic, _com] spawn {		
	params ["_vic","_com"];

	if (isNull (driver _vic)) then {

		private _side = side _com;
		private _driverType = typeOf _com;
		private _grp = grpNull;
		//private _grp = createGroup sideLogic;

		switch (true) do {
			case((_side == west)): {_driverType = "B_UAV_AI"; _grp = createGroup west;};
			case((_side == east)): {_driverType = "O_UAV_AI"; _grp = createGroup east;};
			case((_side == resistance)): {_driverType = "I_UAV_AI"; _grp = createGroup resistance;};
			case((_side == civilian)): {_driverType = "C_UAV_AI_F"; _grp = createGroup civilian;};
		};

		/*
		switch (true) do {
			case((_side == west)): {_driverType = "B_UAV_AI";};
			case((_side == east)): {_driverType = "O_UAV_AI";};
			case((_side == resistance)): {_driverType = "I_UAV_AI";};
			case((_side == civilian)): {_driverType = "C_UAV_AI_F";};
		};
		*/

		private _driver = _grp createUnit [_driverType, [0,0,0], [], 0, "NONE"];
		_driver moveInDriver _vic;
	};

	sleep 1;

	(group (driver _vic)) setGroupOwner (owner _com);
	//_vic setEffectiveCommander _gun;
	[_vic, _com] remoteExec ['setEffectiveCommander', 0];

	private _crew = (crew _vic) select {isPlayer _x};
	['commander took drive controls'] remoteExec ['systemChat', _crew];
};