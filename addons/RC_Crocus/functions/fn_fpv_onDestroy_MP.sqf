params ["_uav"];

if (isNull _uav) exitWith {};
private _uavType = typeOf _uav;		//private _uavType = toLower (typeOf _uav);
if !(_uavType in ["B_Crocus_MP", "B_Crocus_MP_Sens", "B_Crocus_MP_NV", "B_Crocus_MP_NV_Sens", "B_Crocus_MP_TI", "B_Crocus_MP_TI_Sens", "O_Crocus_MP", "O_Crocus_MP_Sens", "O_Crocus_MP_NV", "O_Crocus_MP_NV_Sens", "O_Crocus_MP_TI", "O_Crocus_MP_TI_Sens", "I_Crocus_MP", "I_Crocus_MP_Sens", "I_Crocus_MP_NV", "I_Crocus_MP_NV_Sens", "I_Crocus_MP_TI", "I_Crocus_MP_TI_Sens", "B_Crocus_PvP", "O_Crocus_PvP", "I_Crocus_PvP", "B_Crocus_Training", "O_Crocus_Training", "I_Crocus_Training"]) exitWIth {};

cutText ["", "PLAIN"];

private _killer = driver _uav;
private _instigator = (UAVControl _uav) # 0;
private _missileType = "";

_missileType = "FPV_RPG42_MP";
if (_uavType in ["B_Crocus_PvP", "O_Crocus_PvP", "I_Crocus_PvP"]) then {_missileType = "FPV_RPG42_PvP";};
if (_uavType in ["B_Crocus_Training", "O_Crocus_Training", "I_Crocus_Training"]) then {_missileType = "FPV_RPG42_Training";};

if (local _killer) then {
	_killer setCaptive false;
} else {
	[_killer, false] remoteExec ["setCaptive", 2];
};

private _missile = createVehicle [_missileType, _uav modelToWorld [0, 0, 0]];

_missile setVectorDirAndUp [vectorDir _uav, vectorUp _uav];

[_missile, [_killer, _instigator]] remoteExec ["setShotParents", 2];
[_missile, true] remoteExec ["hideObjectGlobal", 2];

deleteVehicle _uav;

[
	{
		_this params ["_missile", "_shotParents"];

		(getShotParents _missile) isEqualTo _shotParents;
	}, 
	{
		_this params ["_missile"];

		triggerAmmo _missile;
	}, 
	[_missile, [_killer, _instigator]]
] call CBA_fnc_waitUntilAndExecute;
