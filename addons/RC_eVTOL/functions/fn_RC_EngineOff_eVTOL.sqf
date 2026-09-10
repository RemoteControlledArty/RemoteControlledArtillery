/*
	Author: Ascent
*/

params ["_veh"];

//_veh engineOn false;

/*
_engineDmg = _veh getHitPointDamage "hitEngine";
_rotorDmg  = _veh getHitPointDamage "hitHRotor"; // main rotor hitpoint
_noFuel    = (fuel _veh) <= 0;

if (_engineDmg >= 0.9 || _rotorDmg >= 0.9 || _noFuel) then {
    //
} else {
    //
};


_veh spawn {
    params ["_veh"];
    private _gearDown = false;

    while {alive _veh} do {
        private _alt = getPosATL _veh select 2;
        private _spd = speed _veh; // km/h

        if (!_gearDown && _alt < 50 && _spd < 80) then {
            _veh landGear "DOWN";
            _gearDown = true;
        };
        if (_gearDown && (_alt > 70 || _spd > 120)) then {
            _veh landGear "UP";
            _gearDown = false;
        };

        sleep 0.3;
    };
};
*/

//private _rpm = (rotorRpmRTD _veh)#0;
_veh setWantedRPMRTD [0, 2, -1];

sleep 2;

[_veh] call fncfoldarms;
//_veh animate ["foldArms", 1, true];
