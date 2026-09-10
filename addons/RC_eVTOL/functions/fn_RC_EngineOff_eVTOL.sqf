/*
	Author: Ascent
*/

params ["_veh"];

//private _rpm = (rotorRpmRTD _veh)#0;
_veh setWantedRPMRTD [0, 2, -1];

sleep 2;

_veh animate ["foldArms", 1, true];
