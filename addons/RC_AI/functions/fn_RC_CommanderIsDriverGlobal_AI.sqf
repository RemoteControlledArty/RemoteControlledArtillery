params ['_vic'];

if ((crew _vic) findIf {isPlayer _x} > -1) then {

	private _com = commander _vic;

	if (isPlayer _com) then {
		
		if ((driver _vic) isEqualTo objNull) then {
			private _driver = createAgent [(typeOf _com), [0,0,0], [], 0, "NONE"];
			_driver allowDamage false;
			_driver moveInDriver _vic;
		};
		_vic setEffectiveCommander _com;
	};
} else {
    _vic deleteVehicleCrew (driver _vic);
};