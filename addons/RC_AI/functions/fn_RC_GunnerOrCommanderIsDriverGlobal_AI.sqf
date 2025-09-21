params ['_vic'];

if ((crew _vic) findIf {isPlayer _x} > -1) then {

	private _gun = gunner _vic;

	if (isPlayer _gun) then {
		
		if ((driver _vic) isEqualTo objNull) then {
			private _driver = createAgent [(typeOf _gun), [0,0,0], [], 0, "NONE"];
			_driver allowDamage false;
			_driver moveInDriver _vic;
		};
		_vic setEffectiveCommander _gun;
	} else {

		private _com = commander _vic;

		if (isPlayer _com) then {
			
			if ((driver _vic) isEqualTo objNull) then {
				private _driver = createAgent [(typeOf _com), [0,0,0], [], 0, "NONE"];
				_driver allowDamage false;
				_driver moveInDriver _vic;
			};
			_vic setEffectiveCommander _com;
		};
	};
} else {
    _vic deleteVehicleCrew (driver _vic);
};


/*
params ['_vic'];

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