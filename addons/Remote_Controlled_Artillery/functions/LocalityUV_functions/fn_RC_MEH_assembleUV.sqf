//systemchat "0";

player addEventHandler ["WeaponAssembled", {
	params ["_player", "_UV"];

	//systemchat "1";

	if (side _UV != side _player) then {

		if (getNumber (configFile >> "CfgVehicles" >> typeOf _UV >> "RC_assembleSideSwitch") == 1) then {
		//if (getNumber (configFile >> "CfgVehicles" >> typeOf _UV >> "isUav") == 1) then {

			//systemchat "2";
			createVehicleCrew _UV;
			_playerSide = side _player;
			_uavGroup = createGroup _playerSide;
			(crew _UV) joinSilent _uavGroup;
		};
	};

	if (getNumber (configFile >> "CfgVehicles" >> typeOf _UV >> "RC_assembleAutonomousOff") == 1) then {
		
		//systemchat "3";
		[_UV, false] remoteExec ["setAutonomous", _UV];
		/*
		if (isAutonomous _UV) then {
			[_UV, false] remoteExec ["setAutonomous", _UV];
		};
		*/
	};
}];