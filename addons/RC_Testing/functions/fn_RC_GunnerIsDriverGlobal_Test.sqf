params ['_vic'];

if ((crew _vic) findIf {isPlayer _x} > -1) then {

	private _gun = gunner _vic;

	if (isPlayer _gun) then {
		
		[_vic, _gun] spawn {
			params ["_vic","_gun"];

			//_vic deleteVehicleCrew (driver _vic);

			if (isNull (driver _vic)) then {

				private _side = side _gun;
				private _agentKind = typeOf _gun;
				switch (true) do {
					case((_side == west)): {_agentKind = "RC_AI_B_Crew_Agent";};
					case((_side == east)): {_agentKind = "RC_AI_O_Crew_Agent";};
					case((_side == resistance)): {_agentKind = "RC_AI_I_Crew_Agent";};
				};

				private _driver = createAgent [_agentKind, [0,0,0], [], 0, "NONE"];
				_driver allowDamage false;
				//_driver hideObjectGlobal true;
				_driver moveInDriver _vic;
				//_driver setBehaviour "COMBAT";
			};

			sleep 1;

			(driver _vic) setOwner (owner _gun);
			_vic setEffectiveCommander _gun;
		};
	};
} else {

	private _drv = (driver _vic);

	if (!isNull _drv) then {
		private _crewArr = crew _vic;
		_crewArr = _crewArr - [_drv];
		private _drvStr = typeOf _drv;

		if ((!isNull _drv) && (_drvStr find 'Crew_Agent' != -1) && (_crewArr isEqualTo [])) then {
			deleteVehicle _drv;
		};

		_vic engineOn false;
	};
};



/*
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
	};
} else {
    _vic deleteVehicleCrew (driver _vic);
};
*/