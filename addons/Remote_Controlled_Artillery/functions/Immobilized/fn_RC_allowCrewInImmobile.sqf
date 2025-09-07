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


//current
RC_fnc_ImmobilizeTest = {

    params ["_veh"];

    [_veh] spawn {
        params ["_veh"];

        sleep 2;
        if (_veh isEqualTo objNull) exitwith {};
        if !(alive _veh) exitwith {};
        
        private _ownerID = (owner _veh);
        _veh allowCrewInImmobile true;
        private _str1 = "passed";
        _str1 remoteExec ["systemchat", _ownerID];

        while {true} do {

            sleep 2;
            if (_veh isEqualTo objNull) exitwith {};
            if !(alive _veh) exitwith {};

            if !(canMove _veh) then {
                if ((count (crew _veh)) > 0) then {
                    if !(_veh getVariable ["RC_immobileTimerRunning", false]) then {
                        _veh setVariable ["RC_immobileTimerRunning", true];

                        private _ownerID = (owner _veh);
                        private _str2 = "immobilized";
                        _str2 remoteExec ["systemchat", _ownerID];


                        private _crew = crew _veh;
                        private _cargoArr = [];
                        {
                            private _unit = _x;
                            if !(isPlayer _x) then {
                                if ((_unit isNotEqualTo (driver _veh)) && (_unit isNotEqualTo (gunner _veh)) && (_unit isNotEqualTo (commander _veh))) then {
                                    
                                    [[_unit], grpNull] remoteExec ["joinSilent", _ownerID];
                                    _cargoArr pushBackUnique _unit;
                                };
                            };
                        } forEach _crew;


                        if (count _cargoArr > 0) then {

                            private _newLead = _cargoArr #0;
                            [[_newLead], grpNull] remoteExec ["joinSilent", _ownerID];
                            sleep 0.1;
                            _cargoArr deleteAt 0;
                            private _newGroup = group _newLead;

                            if (count _cargoArr > 0) then {
                                [_cargoArr, _newGroup] remoteExec ["joinSilent", _ownerID];
                            };
                            [_newGroup, _veh] remoteExec ["leaveVehicle", _ownerID];
                        };

                        
                        sleep random [6, 9, 12];
                        private _ownerID = (owner _veh);
                        _veh allowCrewInImmobile false;
                        private _str3 = "timer over";
                        _str3 remoteExec ["systemchat", _ownerID];
                        _veh setVariable ["RC_immobileTimerRunning", false];

                        private _driverGroup = group (driver _veh);
                        [_driverGroup, _veh] remoteExec ["leaveVehicle", _ownerID];
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


RC_fnc_SpawnTest = {
    params ["_pos"];
    [_pos, 180, "O_APC_Tracked_02_cannon_F", east] call BIS_fnc_spawnVehicle;
};
private _pos = getPos _this;
[_pos] remoteExecCall ["RC_fnc_SpawnTest", 2];