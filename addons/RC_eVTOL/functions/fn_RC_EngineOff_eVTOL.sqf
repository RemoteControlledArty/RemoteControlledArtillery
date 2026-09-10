/*
	Author: Ascent
*/

params ["_veh"];

//_veh engineOn false;

//private _rpm = (rotorRpmRTD _veh)#0;
_veh setWantedRPMRTD [0, 2, -1];

sleep 2;

[_veh] call fncfoldarms;
//_veh animate ["foldArms", 1, true];
