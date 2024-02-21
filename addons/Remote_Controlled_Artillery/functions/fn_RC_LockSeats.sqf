/*
	Author: Ascent

	Description:
	Locks Seats for specific Vehicles.
*/

// Need to exit early if we aren't a client
if !hasInterface exitWith {};
RC_LockSeats = [] spawn
{
	while {true} do
	{
		sleep 0.1;
		_uav = (getConnectedUAV player);
		_uavClass = typeOf _uav; // UAV ClassName
		
		// If seats have been disabled in the Config we handle that here
		_disableSeats = getNumber (configFile >> "CfgVehicles" >> _uavClass >> "RCDisableSeats");
		_reenableSeats = getNumber (configFile >> "CfgVehicles" >> _uavClass >> "RCReenableSeats");

		if (_disableSeats != 0) then {
			if (_reenableSeats != 0) then {
				if (isRemoteControlling player) then {
					switch (_disableSeats) do {
						// Locks Driver Seat
						case 1: {_uav lockDriver true;};
						// Locks Gunner Seat, or if the Commander seat is at [0] instead of [0,0]
						case 2: {_uav lockTurret [[0], true];};
						// Locks Commander Seat
						case 3: {_uav lockTurret [[0,0], true];};
						// Locks Driver and Gunner Seat, or if the Commander seat is at [0] instead of [0,0]
						case 4: {_uav lockDriver true; _uav lockTurret [[0], true];};
						// Locks Driver and Commander Seat
						case 5: {_uav lockDriver true; _uav lockTurret [[0,0], true];};
						// Locks Gunner and Commander Seat
						case 6: {_uav lockTurret [[0], true]; _uav lockTurret [[0,0], true];};
						// Locks Driver, Gunner and Commander Seat
						case 7: {_uav lockDriver true; _uav lockTurret [[0], true]; _uav lockTurret [[0,0], true];};
						//default {hint "Something Went Wrong!"};
					}
				}
				else {
					switch (_reenableSeats) do {
						// reenables Driver Seat
						case 1: {_uav lockDriver false;};
						// reenables Gunner Seat
						case 2: {_uav lockTurret [[0], false];};
						// reenables Commander Seat
						case 3: {_uav lockTurret [[0,0], false];};
						// reenables Driver and Gunner Seat
						case 4: {_uav lockDriver false; _uav lockTurret [[0], false];};
						// reenables Driver and Commander Seat
						case 5: {_uav lockDriver false; _uav lockTurret [[0,0], false];};
						// reenables Gunner and Commander Seat
						case 6: {_uav lockTurret [[0], false]; _uav lockTurret [[0,0], false];};
						// reenables Driver, Gunner and Commander Seat
						case 7: {_uav lockDriver false; _uav lockTurret [[0], false]; _uav lockTurret [[0,0], false];};
						//default {hint "Something Went Wrong!"};
					};
				};
			}
			else {
				switch (_disableSeats) do {
					// Locks Driver Seat
					case 1: {_uav lockDriver true;};
					// Locks Gunner Seat, or if the Commander seat is at [0] instead of [0,0]
					case 2: {_uav lockTurret [[0], true];};
					// Locks Commander Seat
					case 3: {_uav lockTurret [[0,0], true];};
					// Locks Driver and Gunner Seat, or if the Commander seat is at [0] instead of [0,0]
					case 4: {_uav lockDriver true; _uav lockTurret [[0], true];};
					// Locks Driver and Commander Seat
					case 5: {_uav lockDriver true; _uav lockTurret [[0,0], true];};
					// Locks Gunner and Commander Seat
					case 6: {_uav lockTurret [[0], true]; _uav lockTurret [[0,0], true];};
					// Locks Driver, Gunner and Commander Seat
					case 7: {_uav lockDriver true; _uav lockTurret [[0], true]; _uav lockTurret [[0,0], true];};
					//default {hint "Something Went Wrong!"};
				};
			};
		};
	};
};