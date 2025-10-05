params ["_vic"];

private _com = commander _vic;

[_vic, _com] spawn {		
	params ["_vic","_com"];

	//_vic deleteVehicleCrew (driver _vic);
	
	if (isNull (driver _vic)) then {

		private _side = side _com;
		private _agentKind = typeOf _com;
		switch (true) do {
			case((_side == west)): {_agentKind = "RC_Test_B_Crew_Agent";};
			case((_side == east)): {_agentKind = "RC_Test_O_Crew_Agent";};
			case((_side == resistance)): {_agentKind = "RC_Test_I_Crew_Agent";};
		};

		private _driver = createAgent [_agentKind, [0,0,0], [], 0, "NONE"];
		_driver allowDamage false;
		//_driver hideObjectGlobal true;
		_driver moveInDriver _vic;
		//_driver setBehaviour "COMBAT";
	};

	sleep 1;

	(driver _vic) setOwner (owner _com);
	//_vic setEffectiveCommander _gun;
	[_vic, _com] remoteExec ['setEffectiveCommander', 0];

	private _crew = (crew _vic) select {isPlayer _x};
	['commander took drive controls'] remoteExec ['systemChat', _crew];
};