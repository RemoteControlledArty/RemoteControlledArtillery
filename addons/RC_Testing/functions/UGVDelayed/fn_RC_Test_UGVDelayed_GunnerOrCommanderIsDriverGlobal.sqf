params ['_vic'];

if ((crew _vic) findIf {isPlayer _x} > -1) then {

	private _gun = gunner _vic;

	if (isPlayer _gun) then {
		
		[_vic, _gun] spawn {
			params ["_vic","_gun"];

			if (isNull (driver _vic)) then {

				private _side = side _gun;
				private _driverType = typeOf _gun;
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
			
			(group (driver _vic)) setGroupOwner (owner _gun);
			_vic setEffectiveCommander _gun;
		};
	} else {

		private _com = commander _vic;

		if (isPlayer _com) then {

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
				_vic setEffectiveCommander _com;
			};
		};
	};
} else {

	private _drv = (driver _vic);

	if (!isNull _drv) then {
		private _crewArr = crew _vic;
		_crewArr = _crewArr - [_drv];

		if ((!isNull _drv) && ((typeOf _drv) find 'UAV_AI' != -1) && (_crewArr isEqualTo [])) then {
			deleteVehicle _drv;
		};

		_vic engineOn false;
	};
};