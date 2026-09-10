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
*/

//private _rpm = (rotorRpmRTD _veh)#0;
_veh setWantedRPMRTD [0, 2, -1];

sleep 2;

[_veh] call fncfoldarms;
//_veh animate ["foldArms", 1, true];
