if (!isServer) exitWith {};

params ["_vehicle"];

_vehicle addEventHandler ["GetIn", {
	params ["_vehicle"]; [
		if (isPlayer (commander _vehicle)) then {
			systemChat "GetIn Commander";
			(group (driver _vehicle)) setGroupOwner (owner (commander _vehicle));
			_vehicle setOwner (owner (commander _vehicle));
			_vehicle setEffectiveCommander (commander _vehicle);
		} else {
			if (isPlayer (gunner _vehicle)) then {
				systemChat "GetIn Gunner";
				(group (driver _vehicle)) setGroupOwner (owner (gunner _vehicle));
				_vehicle setOwner (owner (gunner _vehicle));
				_vehicle setEffectiveCommander (gunner _vehicle);
			}
		}
	] remoteExec ["spawn", 2];
}];

_vehicle addEventHandler ["GetOut", {
	params ["_vehicle"]; [
		if (isPlayer (commander _vehicle)) then {
			systemChat "GetOut Commander";
			(group (driver _vehicle)) setGroupOwner (owner (commander _vehicle));
			_vehicle setOwner (owner (commander _vehicle));
			_vehicle setEffectiveCommander (commander _vehicle);
		} else {
			if (isPlayer (gunner _vehicle)) then {
				systemChat "GetOut Gunner";
				(group (driver _vehicle)) setGroupOwner (owner (gunner _vehicle));
				_vehicle setOwner (owner (gunner _vehicle));
				_vehicle setEffectiveCommander (gunner _vehicle);
			}
		}
	] remoteExec ["spawn", 2];
}];

_vehicle addEventHandler ["SeatSwitched", {
	params ["_vehicle"]; [
		if (isPlayer (commander _vehicle)) then {
			systemChat "SeatSwitched Commander";
			(group (driver _vehicle)) setGroupOwner (owner (commander _vehicle));
			_vehicle setOwner (owner (commander _vehicle));
			_vehicle setEffectiveCommander (commander _vehicle);
		} else {
			if (isPlayer (gunner _vehicle)) then {
				systemChat "SeatSwitched Gunner";
				(group (driver _vehicle)) setGroupOwner (owner (gunner _vehicle));
				_vehicle setOwner (owner (gunner _vehicle));
				_vehicle setEffectiveCommander (gunner _vehicle);
			}
		}
	] remoteExec ["spawn", 2];
}];