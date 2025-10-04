params ["_vic"];

private _gun = gunner _vic;

if (isNull (driver _vic)) then {

	private _side = side _gun;
	private _agentKind = typeOf _gun;
	switch (true) do {
		case((_side == west)): {
			_agentKind = "RC_AI_B_Crew_Agent";
		};
		case((_side == east)): {
			_agentKind = "RC_AI_O_Crew_Agent";
		};
		case((_side == resistance)): {
			_agentKind = "RC_AI_I_Crew_Agent";
		};
	};

	private _driver = createAgent [_agentKind, [0,0,0], [], 0, "NONE"];
	_driver allowDamage false;
	//_driver hideObjectGlobal true;
	_driver moveInDriver _vic;
	//_driver setBehaviour "COMBAT";
};

(driver _vic) setOwner (owner _gun);
//_vic setEffectiveCommander _gun;
[_vic, _gun] remoteExec ['setEffectiveCommander', 0];

private _crew = (crew _vic) select {isPlayer _x};
['gunner took drive controls'] remoteExec ['systemChat', _crew];