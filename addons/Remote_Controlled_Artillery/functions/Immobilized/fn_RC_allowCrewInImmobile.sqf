/*
	Author: Ascent

	Description:
	Allows crew to stay in armored vehicles if immobilized (tracks/wheels), but after a timer they dismount.
	Making armored vehicles more threatening, in a balanced way, without extra effort for the zeus.
*/

if !(RC_allowCrewInImmobile) exitwith {};

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

        //G
        if !(canMove _veh) then {
            if ((count (crew _veh)) > 0) then {
                if !(_veh getVariable ["RC_immobileTimerRunning", false]) then {
                    _veh setVariable ["RC_immobileTimerRunning", true];


                    private _crew = crew _veh;
                    private _cargoArr = [];
                    {
                        if !(isPlayer _x) then {
                            private _role = (assignedVehicleRole _x) #0;    //G         //(assignedVehicleRole _x) #0;

                            if (_role isEqualTo "cargo") then {
                                _cargoArr pushBackUnique _x;
                            };
                        };
                    } forEach _crew;


                    if (count _cargoArr > 0) then {

                        private _newLead = _cargoArr #0; 
                        [_newLead] joinSilent grpNull;      //G G
                        _cargoArr deleteAt 0;
                        private _newGroup = group _newLead; //G  "In MP the command is not initialised in functions called by initline or init eventhandlers."

                        if (count _cargoArr > 0) then {
                            _cargoArr joinSilent _newGroup; //G G
                        };
                        _newGroup leaveVehicle _veh;        //L L
                    };

                    
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


/*
private _veh = _this;
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


                    private _crew = crew _veh;
                    private _cargoArr = [];	
                    {
                        if !(isPlayer _x) then {
                            private _role = (assignedVehicleRole _x) #0;
	  
                            if (_role isEqualTo "cargo") then {
                                _cargoArr pushBackUnique _x;
                            };		
                        };
                    } forEach _crew;


                    if (count _cargoArr > 0) then {

                        private _newLead = _cargoArr #0; 
                        [_newLead] joinSilent grpNull;
                        _cargoArr deleteAt 0;
                        private _newGroup = group _newLead;

                        if (count _cargoArr > 0) then {
                            _cargoArr joinSilent _newGroup;
                        };
                        _newGroup leaveVehicle _veh;
                    };

                    
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
*/