params ['_vic'];

if ((crew _vic) findIf {isPlayer _x} > -1) then {

	private _gun = gunner _vic;

	if (isPlayer _gun) then {
		
		//[_vic, _gun] spawn {
		//params ["_vic","_gun"];

		if (isNull (driver _vic)) then {
			private _driver = createAgent [(typeOf _gun), [0,0,0], [], 0, "NONE"];
			_driver allowDamage false;
			//_driver hideObjectGlobal true;
			_driver moveInDriver _vic;
			//_driver setBehaviour "COMBAT";
		};

		//sleep 1;

		(driver _vic) setOwner (owner _gun);
		_vic setEffectiveCommander _gun;
		//};
	} else {

		private _com = commander _vic;

		if (isPlayer _com) then {

			//[_vic, _com] spawn {
			//params ["_vic","_com"];

			if (isNull (driver _vic)) then {
				private _driver = createAgent [(typeOf _gun), [0,0,0], [], 0, "NONE"];
				_driver allowDamage false;
				_driver moveInDriver _vic;
			};

			//sleep 1;

			(driver _vic) setOwner (owner _com);
			_vic setEffectiveCommander _com;
			//};
		};
	};
} else {

	_drv = (driver _vic);
	//private _crewArr = crew _vic;
	//_crewArr = _crewArr - [_drv];
	//if (_crewArr isEqualTo []) exitWith {};
	if ((!isNull _drv) && (isAgent _drv)) then {
        deleteVehicle _drv;
    };
    _vic deleteVehicleCrew _drv;
	_vic engineOn false;
};



/*
systemchat "EH";

if ((crew _vic) findIf {isPlayer _x} > -1) then {

	systemchat "player in crew";

	private _gun = gunner _vic;

	if (isPlayer _gun) then {

		systemchat "player is gunner";
		
		if ((driver _vic) isEqualTo objNull) then {

			systemchat "no driver, creating agent";
			
			private _driver = createAgent [(typeOf _gun), [0,0,0], [], 0, "NONE"];
			_driver allowDamage false;
			//_driver hideObjectGlobal true;
			_driver moveInDriver _vic;
		};
		_vic setEffectiveCommander _gun;
	} else {

		private _com = commander _vic;

		if (isPlayer _com) then {

			systemchat "player is commander";
			
			if ((driver _vic) isEqualTo objNull) then {

				systemchat "no driver, creating agent";

				private _driver = createAgent [(typeOf _com), [0,0,0], [], 0, "NONE"];
				_driver allowDamage false;
				_driver moveInDriver _vic;
			};
			_vic setEffectiveCommander _com;
		};
	};
} else {

	systemchat "no player in crew, deleting driver";

    _vic deleteVehicleCrew (driver _vic);
};
*/