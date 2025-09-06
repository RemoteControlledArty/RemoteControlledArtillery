/*
	Author: Ascent

	Description:
	Allows crew to stay in armored vehicles if immobilized (tracks/wheels), but after a timer they dismount.
	Making armored vehicles more threatening, in a balanced way, without extra effort for the zeus.
*/

params ["_veh"];

[_veh] spawn {
    params ["_veh"];

    sleep 2;
    if (_veh isEqualTo objNull) exitwith {};
    if !(alive _veh) exitwith {};
    _veh allowCrewInImmobile true;

    while {true} do {

        sleep 10;
        if (_veh isEqualTo objNull) exitwith {};
        if !(alive _veh) exitwith {};

        if !(canMove _veh) then {
            if ((count (crew _veh)) > 0) then {
                if !(_veh getVariable ["RC_immobileTimerRunning", false]) then {

                    _veh setVariable ["RC_immobileTimerRunning", true];
                    sleep random [10, 15, 20];

                    _veh allowCrewInImmobile false;
                    _veh setVariable ["RC_immobileTimerRunning", false];
                };
            } else {
                sleep 20;
            };
        };
    };
};