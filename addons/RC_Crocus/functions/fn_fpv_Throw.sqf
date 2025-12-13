params ["_proj"];

sleep 1;

private _vel = velocity _proj;
private _pos = getPosASL _proj;
_proj setPosASL [0,0,0];
deleteVehicle _proj;

private _uavType = getText (configFile >> "CfgAmmo" >> typeOf _proj >> "asset");
private _uavSide = objNull;

switch (side player) do {
	case west:			{_uavSide = "B_"};
	case east:			{_uavSide = "O_"};
	case independent:	{_uavSide = "I_"};
	//case civilian:		{_uavSide = "C_"};
};

_uav = createVehicle [[_uavSide, _uavType] joinString "", [0,0,0], [], 0, "FLY"];
//private _uavSpawn = [_spawnPos, direction _uav, _version, _side] call BIS_fnc_spawnVehicle;
createVehicleCrew _uav;
_uav setPosASL _pos;
_uav setDir getDir player;
_uav setVelocity _vel;
_uav flyInHeight 20;

sleep 1;

player connectTerminalToUAV _uav;
//[_uav] call RC_fnc_RC_uavChangeLocality;
player action ["UAVTerminalOpen", player];
//driver _uav switchCamera "Internal";
//player remoteControl driver _uav;