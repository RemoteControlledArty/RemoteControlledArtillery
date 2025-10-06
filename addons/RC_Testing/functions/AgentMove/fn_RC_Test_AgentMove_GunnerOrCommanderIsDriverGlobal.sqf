params ['_vic'];

if !((crew _vic) findIf {isPlayer _x} > -1) then {

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