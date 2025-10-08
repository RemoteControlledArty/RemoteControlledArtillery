params ['_vic'];

if ((crew _vic) findIf {isPlayer _x} > -1) then {

	private _gun = gunner _vic;
	private _com = commander _vic;

	if (isPlayer _gun && (!(isplayer _com))) then {
		
		if (isNull (driver _vic)) then {

			private _side = side _gun;
			private _agentType = typeOf _gun;
			switch (true) do {
				case((_side == west)): {_agentType = "RC_AI_B_Crew_Agent";};
				case((_side == east)): {_agentType = "RC_AI_O_Crew_Agent";};
				case((_side == resistance)): {_agentType = "RC_AI_I_Crew_Agent";};
			};

			private _driver = createAgent [_agentType, [0,0,0], [], 0, "NONE"];
			_driver allowDamage false;
			//_driver hideObjectGlobal true;
			_driver moveInDriver _vic;
			//_driver setBehaviour "COMBAT";
		};

		(driver _vic) setOwner (owner _gun);
		_vic setEffectiveCommander _gun;
	} else {

		if (isPlayer _com && (!(isplayer _gun))) then {

			if (isNull (driver _vic)) then {
				private _side = side _com;
				private _agentType = typeOf _com;
				switch (true) do {
					case((_side == west)): {_agentType = "RC_AI_B_Crew_Agent";};
					case((_side == east)): {_agentType = "RC_AI_O_Crew_Agent";};
					case((_side == resistance)): {_agentType = "RC_AI_I_Crew_Agent";};
				};

				private _driver = createAgent [_agentType, [0,0,0], [], 0, "NONE"];
				_driver allowDamage false;
				//_driver hideObjectGlobal true;
				_driver moveInDriver _vic;
				//_driver setBehaviour "COMBAT";
			};

			(driver _vic) setOwner (owner _com);
			_vic setEffectiveCommander _com;
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