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


params ["_veh"];

[_veh] spawn {
    params ["_veh"];

    sleep 2;
    if (_veh isEqualTo objNull) exitwith {};
    if !(alive _veh) exitwith {};
    
    _veh allowCrewInImmobile true;

    while {true} do {

        sleep 2;
        if (_veh isEqualTo objNull) exitwith {};
        if !(alive _veh) exitwith {};

        if !(canMove _veh) then {
            if ((count (crew _veh)) > 0) then {
                if !(_veh getVariable ["RC_immobileTimerRunning", false]) then {
                    _veh setVariable ["RC_immobileTimerRunning", true];

                    private _vehOwner = owner _veh;
                    private _crew = crew _veh;
                    private _dri = driver _veh;
                    private _gun = gunner _veh;
                    private _com = commander _veh;

                    private _cargoArr = [];
                    {
                        private _unit = _x;
                        if !(isPlayer _x) then {
                            if ((_unit isNotEqualTo _dri) && (_unit isNotEqualTo _gun) && (_unit isNotEqualTo _com)) then {
                                
                                [_unit] joinSilent grpNull;
                                _cargoArr pushBackUnique _unit;
                            };
                        };
                    } forEach _crew;


                    if (count _cargoArr > 0) then {

                        private _newLead = _cargoArr #0;
                        [_newLead] joinSilent grpNull;
                        sleep 0.1;
                        _cargoArr deleteAt 0;
                        private _newGroup = group _newLead;

                        if (count _cargoArr > 0) then {
                            _cargoArr joinSilent _newGroup;
                        };
                        [_newGroup, _veh] remoteExec ["leaveVehicle", _vehOwner];
                    };

                    
                    sleep random [10, 11, 12];
                    _vehOwner = owner _veh;
                    _veh allowCrewInImmobile false;
                    _veh setVariable ["RC_immobileTimerRunning", false];

                    private _driverGroup = group (driver _veh);
                    [_driverGroup, _veh] remoteExec ["leaveVehicle", _vehOwner];
                };
            } else {
                sleep 20;
            };
        };
    };
};


//current
RC_fnc_ImmobilizeTest = {

    params ["_veh"];

    [_veh] spawn {
        params ["_veh"];

        sleep 2;
        if (_veh isEqualTo objNull) exitwith {};
        if !(alive _veh) exitwith {};
        
        _veh allowCrewInImmobile true;
        "passed" remoteExec ["systemchat", 0];

        while {true} do {

            sleep 2;
            if (_veh isEqualTo objNull) exitwith {};
            if !(alive _veh) exitwith {};

            if !(canMove _veh) then {
                if ((count (crew _veh)) > 0) then {
                    if !(_veh getVariable ["RC_immobileTimerRunning", false]) then {
                        _veh setVariable ["RC_immobileTimerRunning", true];

                        "immobilized" remoteExec ["systemchat", -2];
                        private _dri = driver _veh;
                        private _gun = gunner _veh;
                        private _com = commander _veh;

                        private _cargoArr = [];
                        {
                            private _unit = _x;
                            if !(isPlayer _unit) then {
                                if (alive _unit) then {
                                    if ((_unit isNotEqualTo _dri) && (_unit isNotEqualTo _gun) && (_unit isNotEqualTo _com)) then {
                                        
                                        [_unit] joinSilent grpNull;
                                        _cargoArr pushBackUnique _unit;
                                    };
                                };
                            };
                        } forEach (crew _veh);


                        private _driverGrp = group (driver _veh);
                        if (count _cargoArr > 0) then {

                            private _newLead = _cargoArr #0;
                            [_newLead] joinSilent grpNull;
                            sleep 0.1;
                            _cargoArr deleteAt 0;
                            private _newGrp = group _newLead;

                            if (count _cargoArr > 0) then {
                                _cargoArr joinSilent _newGrp;
                            };
                            private _grpOwner = groupOwner _newGrp;
                            [_newGrp, _veh] remoteExec ["leaveVehicle", _grpOwner];
                            
                            _newGrp copyWaypoints _driverGrp
                        };

                        
                        sleep random [20, 30, 40];
                        _veh allowCrewInImmobile false;

                        "timer over" remoteExec ["systemchat", -2];
                        _veh setVariable ["RC_immobileTimerRunning", false];

                        if !(canMove _veh) then {
                            if ((count (crew _veh)) > 0) then {
                                private _grpOwner = groupOwner _driverGrp;
                                [_driverGrp, _veh] remoteExec ["leaveVehicle", _grpOwner];
                                "crew dismounting" remoteExec ["systemchat", -2];
                            };
                        };
                    };
                } else {
                    sleep 20;
                };
            };
        };
    };
};
private _veh = _this;
[_veh] remoteExecCall ["RC_fnc_ImmobilizeTest", 2];

//REACTIVATE AFTER REPAIR!? maybe in else statement of canMove?




RC_fnc_SpawnTest = {
    params ["_pos"];
    [_pos, 180, "O_APC_Tracked_02_cannon_F", east] call BIS_fnc_spawnVehicle;
};
private _pos = getPos _this;
[_pos] remoteExecCall ["RC_fnc_SpawnTest", 2];