params ["_unit", "_selection", "_damage", "_source", "_projectile", "_hitPartIndex", "_instigator", "_hitPoint", "_directHit", "_context"];

if (true) exitWith {

	private _uavType = toLower (typeOf _unit);
    private _vectorDir = vectorDir _unit;
   	private _vectorUp = vectorUp _unit;
    private _impactPos = _unit modelToWorld [0,0,0];
    private _killer = (UAVControl _unit)#0;

	deleteVehicle _unit;

	private _uavType = typeOf _uav;		//private _uavType = toLower (typeOf _uav);
	if !(_uavType in ["B_Crocus_MP", "B_Crocus_MP_Sens", "B_Crocus_MP_NV", "B_Crocus_MP_NV_Sens", "B_Crocus_MP_TI", "B_Crocus_MP_TI_Sens", "O_Crocus_MP", "O_Crocus_MP_Sens", "O_Crocus_MP_NV", "O_Crocus_MP_NV_Sens", "O_Crocus_MP_TI", "O_Crocus_MP_TI_Sens", "I_Crocus_MP", "I_Crocus_MP_Sens", "I_Crocus_MP_NV", "I_Crocus_MP_NV_Sens", "I_Crocus_MP_TI", "I_Crocus_MP_TI_Sens", "B_Crocus_PvP", "O_Crocus_PvP", "I_Crocus_PvP", "B_Crocus_Training", "O_Crocus_Training", "I_Crocus_Training"]) exitWIth {};

	private _missileType = "FPV_RPG42_MP";
	if (_uavType in ["B_Crocus_PvP", "O_Crocus_PvP", "I_Crocus_PvP"]) then {_missileType = "FPV_RPG42_PvP";};
	if (_uavType in ["B_Crocus_Training", "O_Crocus_Training", "I_Crocus_Training"]) then {_missileType = "FPV_RPG42_Training";};

	private _missile = createVehicle [_missileType, [0,0,100]];
    _missile setVectorDirAndUp [_vectorDir, _vectorUp];
    [_missile, [_killer, _killer]] remoteExec ["setShotParents", 2];

	waitUntil {
		(getShotParents _missile) isEqualTo [_killer, _killer];
    };

	_missile setPosATL _impactPos;
    triggerAmmo _missile;
    0
};