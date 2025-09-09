/*
	Author: Ascent

	Description:
	Allows crew to stay in armored vehicles if immobilized (tracks/wheels), but after a 60-90sec timer they dismount.
	Making armored vehicles more threatening, in a balanced way, without extra effort for the zeus.
*/

if !(RC_allowCrewInImmobile) exitwith {};

params ["_veh"];

[_veh] spawn {
    params ["_veh"];

    sleep 2;
    if (isNull _veh) exitwith {};
    if !(alive _veh) exitwith {};
    
    _veh allowCrewInImmobile true;

    private _while = true;
    while {_while} do {

        sleep 2;
        if (isNull _veh) exitwith {_while = false;};
        if !(alive _veh) exitwith {_while = false;};

        if !(canMove _veh) then {
            if ((count (crew _veh)) > 0) then {
                if !(_veh getVariable ["RC_immobileTimerRunning", false]) then {
                    _veh setVariable ["RC_immobileTimerRunning", true];

                    private _dri = driver _veh;
                    private _gun = gunner _veh;
                    private _com = commander _veh;

                    private _cargoArr = [];
                    {
                        private _unit = _x;
                        if !(isPlayer _unit) then {
                            if (alive _unit) then {
                                if ((_unit isNotEqualTo _dri) && (_unit isNotEqualTo _gun) && (_unit isNotEqualTo _com)) then {
                                    
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
                        
                        _newGrp copyWaypoints _driverGrp;
                    };

                    
                    sleep random [60, 75, 90];
                    if (isNull _veh) exitwith {_while = false;};
                    if !(alive _veh) exitwith {_while = false;};

                    if !(canMove _veh) then {

                        _veh allowCrewInImmobile false;
                        _veh setVariable ["RC_immobileTimerRunning", false];
                        _while = false;

                        if (((count (crew _veh)) > 0) && (!isNull _driverGrp)) then {  
                            private _grpOwner = groupOwner _driverGrp;
                            [_driverGrp, _veh] remoteExec ["leaveVehicle", _grpOwner];
                        };
                    };
                };
            } else {
                sleep 20;
            };
        };
    };
};


/*
//testing
RC_fnc_ImmobilizeTest = {

    params ["_veh"];

    [_veh] spawn {
        params ["_veh"];

        sleep 2;
        if (isNull _veh) exitwith {};
        if !(alive _veh) exitwith {};
        
        _veh allowCrewInImmobile true;
        "passed" remoteExec ["systemchat", 0];

        private _while = true;
        while {_while} do {
            "while" remoteExec ["systemchat", 0];

            sleep 2;
            if (isNull _veh) exitwith {_while = false;};
            if !(alive _veh) exitwith {_while = false;};

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
                            
                            _newGrp copyWaypoints _driverGrp;
                        };

                        
                        sleep random [60, 75, 90];
                        if (isNull _veh) exitwith {_while = false;};
                        if !(alive _veh) exitwith {_while = false;};

                        if !(canMove _veh) then {

                            _veh allowCrewInImmobile false;
                            _veh setVariable ["RC_immobileTimerRunning", false];
                            "timer over" remoteExec ["systemchat", -2];
                            _while = false;
                            
                            if (((count (crew _veh)) > 0) && (!isNull _driverGrp)) then {  
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
private _owner = owner _this;
"local" remoteExec ["systemchat", _owner];



RC_fnc_SpawnTest = {
    params ["_pos"];
    [_pos, 180, "O_APC_Tracked_02_cannon_F", east] call BIS_fnc_spawnVehicle;
};
private _pos = getPos _this;
[_pos] remoteExecCall ["RC_fnc_SpawnTest", 2];
*/