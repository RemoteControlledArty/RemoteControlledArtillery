/*
	Author: Ascent

	Description:
	Allows crew to stay in armored vehicles if immobilized (tracks/wheels), but after a timer they dismount.
	Making armored vehicles more threatening, in a balanced way, without extra effort for the zeus.
*/

params ["_veh"];

_veh allowCrewInImmobile true;

_veh addEventHandler ["Dammaged", {
    params ["_veh"];

    if !(canMove _veh) then {
        if !(_veh getVariable ["RC_immobileTimerRunning", false]) then {
            _veh setVariable ["RC_immobileTimerRunning", true];
            _veh allowCrewInImmobile true;

            [_veh] spawn {
                sleep (random [6, 9, 12]);

                if !(canMove _veh) then {
                    _veh allowCrewInImmobile false;
                };
                _veh setVariable ["RC_immobileTimerRunning", false];
            };
        };
    };
}];
