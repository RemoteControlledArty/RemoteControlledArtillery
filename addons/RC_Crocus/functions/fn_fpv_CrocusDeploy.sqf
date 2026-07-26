params ["_veh", "_weapon"];
if (isNull _veh) exitWith {};
if (_weapon isNotEqualTo "RC_Crocus_Deployer") exitWith {};


private _flyToPos = getPosASL player;
private _pos = getPos _veh;
private _spawnPos = +_pos;
private _posZ = _pos #2;
private _isAir = _veh isKindOf "Air";
if (_isAir) then 
{
	//currently aimed at pos
	_flyToPos = screenToWorld [0.5, 0.5];
	//to prevent accidental trigger when trying to use laser designator, how is its locality? what about camless?
	//_veh selectWeaponTurret ["Laserdesignator_mounted", [0]];
	//if ((_pos select 2) > 1000) then {_posZ = 1000;
	if (_posZ > 15) then {

		if (_posZ > 1003) then {
			_posZ = 1000;
		} else {
			_posZ = _posZ - 3;
		};
	} else {
		_posZ = _posZ + 3;
	};
} else {
	_posZ = _posZ + 5;
};
_spawnPos set [2, _posZ];


_uavClass = "Crocus_MP_TI_Sens";
if ((typeOf _veh) find "PvP" > -1) then {
	_uavClass = "Crocus_PvP";
};
private _uavArray = [[0,0,200], direction _veh, _uavClass, side _veh];


[_veh, _uavArray, _spawnPos, _flyToPos, _weapon] spawn {
	params ["_veh", "_uavArray", "_spawnPos", "_flyToPos", "_weapon"];

	sleep 0.2;
	_uavSpawn = _uavArray call BIS_fnc_spawnVehicle;
	private _uav = _uavSpawn #0;
	//needs to be manually set, otherwise 50m minimum
	_uav setPos _spawnPos;
	sleep 1;


	player connectTerminalToUAV _uav;
	[_uav] call RC_fnc_RC_uavChangeLocality;
	//SOP height if no C-UAS in the area, after changeLocality due to it being local command global effect
	_uav flyInHeight 200;
	_flyToPos set [2, 200];
	(group _uav) addWaypoint [_flyToPos, 3, -1, ""];


	sleep 0.3;
	player action ["UAVTerminalOpen", player];
};