params ["_veh", "_weapon"];

if (isNull _veh) exitWith {};
if (_weapon isNotEqualTo "RC_Crocus_Deployer") exitWith {};
private _isAir = _veh isKindOf "Air";


private _pos = getPos _veh;
private _spawnPos = +_pos;
private _posZ = 200;
if (_isAir) then 
{
	//to prevent accidental trigger when trying to use laser designator, how is its locality?
	//_veh selectWeaponTurret ["Laserdesignator_mounted", [0]];

	if ((_pos select 2) > 1000) then {
		_posZ = 1000;
	} else {
		_posZ = (_pos select 2) - 15;	//somehow is min 50, doesnt bug into ground
	};
} else {
	_posZ = (_pos select 2) + 7;
};
_spawnPos set [2, _posZ];


private _uavClass = "Crocus_MP_TI_Sens";
if ((typeOf _veh) find "PvP" > -1) then {
	_uavClass = "Crocus_PvP";
};
private _uavSpawn = [_pos, direction _veh, _uavClass, side _veh] call BIS_fnc_spawnVehicle;
private _uavNew = _uavSpawn select 0;
//needs to be manually set, otherwise 50m minimum
_uavNew setPos _spawnPos;
//SOP height if no C-UAS in the area
_uavNew flyInHeight 200;


[_uavNew] spawn {
	params ["_uavNew"];
	sleep 1;
	player connectTerminalToUAV _uavNew;
	[_uavNew] call RC_fnc_RC_uavChangeLocality;
	player action ["UAVTerminalOpen", player];
	//driver _uavNew switchCamera "Internal";
	//player remoteControl driver _uavNew;
};