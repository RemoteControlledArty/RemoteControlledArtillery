params ["_uav", "_weapon"];

if (isNull _uav) exitWith {};
if (_weapon isNotEqualTo "RC_Crocus_Deployer") exitWith {};
//_uav selectWeaponTurret ["RC_target_confirmer_datalink", [0]];   //to prevent accidental trigger


private _pos = getPosASL _uav;
private _posZ = (_pos select 2) + 7;	//+500
private _spawnPos = +_pos;
_spawnPos set [2, _posZ];


//differentiate between asset
private _uavType = "Crocus_MP_TI_Sens";
if ((typeOf _uav) find "PvP" > -1) then {
	_uavType = "Crocus_PvP";
};


private _uavSide = objNull;
switch (side player) do {
	case west:			{_uavSide = "B_"};
	case east:			{_uavSide = "O_"};
	case independent:	{_uavSide = "I_"};
	//case civilian:	{_uavSide = "C_"};
};


_uavNew = createVehicle [[_uavSide, _uavType] joinString "", [0,0,0], [], 0, "FLY"];
createVehicleCrew _uavNew;
_uavNew setPosASL _spawnPos;
_uavNew setDir getDir _uav;
_uavNew flyInHeight 200;	//change to clear height if limited


/*
private _pos = getPos _uav;
private _posZ = (_pos select 2) + 7;	//+500
//private _spawnPos = _uav modelToWorld [0, -3, 0];
private _spawnPos = +_pos;
_spawnPos set [2, _posZ];

private _side = side _uav;
private _version = 'B_Crocus_MP_TI_Sens';
if (side _uav == east) then {_version = 'O_Crocus_MP_TI_Sens';};
if (side _uav == resistance) then {_version = 'I_Crocus_MP_TI_Sens';};

//[_spawnArray, BIS_fnc_spawnVehicle] remoteExec ['call', 2];
private _uavSpawn = [_spawnPos, direction _uav, _version, _side] call BIS_fnc_spawnVehicle;	//needs different script to spawn at +7m
private _uavNew = _uavSpawn select 0;
//SOP height if no C-UAS near
_uavNew flyInHeight 200;
*/


[_uavNew] spawn {
	params ["_uavNew"];

	sleep 0.2;
	player connectTerminalToUAV _uavNew;
	[_uavNew] call RC_fnc_RC_uavChangeLocality;
	player action ["UAVTerminalOpen", player];
	//driver _uavNew switchCamera "Internal";
	//player remoteControl driver _uavNew;
};