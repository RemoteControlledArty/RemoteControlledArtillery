params ["_proj"];

sleep 1;

private _vel = velocity _proj;
private _pos = getPosATL _proj;
private _dir = getDir player;
private _dirVec = (getPosATL player) vectorFromTo _pos;
_proj setPosASL [0,0,0];
deleteVehicle _proj;

[_pos, _dir, _vel, _dirVec] spawn RC_fnc_Interceptor_create;

