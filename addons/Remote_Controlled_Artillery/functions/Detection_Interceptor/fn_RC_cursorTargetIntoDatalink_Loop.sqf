//to allow reliable pilotCamera point lock on helicopters (requires sensor/datalink target)
[] spawn {
	while {true} do {

		private _vehicle = vehicle player;

		if (_vehicle != player) then {

			private _vehicleType = typeOf _vehicle;

			if ((_vehicleType find 'RC_' != -1) && (_vehicleType find '_DAP' != -1)) then {

				private _target = cursorTarget;
				private _distance = _target distance _vehicle;

				if (!isNull _target && alive _target && (_distance <= 4000)) then {
					
					private _side = side player;

					if ((_target isKindOf "LandVehicle" or _target isKindOf "Air" or _target isKindOf "Ship") && RC_AB_VicConfirming) then {
						[_side,[_target, 2]] remoteExec ["reportRemoteTarget", _side];
					};
				};
			};
		};
		
		sleep 1;
	};
};