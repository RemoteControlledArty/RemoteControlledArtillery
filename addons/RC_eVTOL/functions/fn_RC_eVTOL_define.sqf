/*
private _veh = getConnectedUav player;

private _attObj = (attachedObjects _veh);
if (count _attObj > 0) then {
    {deleteVehicle _x} forEach _attObj;
};
*/
    
fnc_RC_eVTOL_attachToMothership = {

    params ["_veh"];

    private _type = typeOf _veh;
    private _side = _type select (count _type - 1);
    private _eVTOL_Str = "RC_eVTOL_TI_" + _side;

    _posArrL = [
        [[0, 0, 1010], [3.8, 1.3, -0.6]],
        [[0, 0, 1020], [2.8, 0.7375, -0.595]],
        [[0, 0, 1030], [1.8, 0.175, -0.585]],
        [[0, 0, 1040], [0.8, -0.3875, -0.575]],
        [[0, 0, 1050], [-0.2, -0.95, -0.565]]
    ];
    {
        private _eVTOL = _eVTOL_Str createVehicle _x#0;
        _eVTOL attachTo [_veh, _x#1, 'wing_fold_l', true];
    } foreach _posArrL;


    _posArrR = [
        [[0, 0, 1060], [-3.8, 1.3, -0.6]],
        [[0, 0, 1070], [-2.8, 0.7375, -0.595]],
        [[0, 0, 1080], [-1.8, 0.175, -0.585]],
        [[0, 0, 1090], [-0.8, -0.3875, -0.575]],
        [[0, 0, 1100], [0.2, -0.95, -0.565]]
    ];
    {
        private _eVTOL = _eVTOL_Str createVehicle _x#0;
        _eVTOL attachTo [_veh, _x#1, 'wing_fold_r', true];
    } foreach _posArrR;
};


fnc_RC_eVTOL_attachToMothership_Minigun = {

    params ["_veh"];

    private _type = typeOf _veh;
    private _side = _type select (count _type - 1);
    private _eVTOL_Str = "RC_eVTOL_Minigun_TI_" + _side;

    _posArrL = [
        [[0, 0, 1010], [3.8, 1.3, -0.6]],
        [[0, 0, 1020], [2.8, 0.7375, -0.595]],
        [[0, 0, 1030], [1.8, 0.175, -0.585]],
        [[0, 0, 1040], [0.8, -0.3875, -0.575]],
        [[0, 0, 1050], [-0.2, -0.95, -0.565]]
    ];
    {
        private _eVTOL = _eVTOL_Str createVehicle _x#0;
        _eVTOL attachTo [_veh, _x#1, 'wing_fold_l', true];
    } foreach _posArrL;


    _posArrR = [
        [[0, 0, 1060], [-3.8, 1.3, -0.6]],
        [[0, 0, 1070], [-2.8, 0.7375, -0.595]],
        [[0, 0, 1080], [-1.8, 0.175, -0.585]],
        [[0, 0, 1090], [-0.8, -0.3875, -0.575]],
        [[0, 0, 1100], [0.2, -0.95, -0.565]]
    ];
    {
        private _eVTOL = _eVTOL_Str createVehicle _x#0;
        _eVTOL attachTo [_veh, _x#1, 'wing_fold_r', true];
    } foreach _posArrR;
};

//[_veh] call fnc_attachToMothership;


fnc_RC_eVTOL_detach = {

    params ["_veh"];

    _veh allowDamage false;
    private _host = attachedTo _veh;
    _host allowDamage false;     //remoteExec where local!
    player allowDamage false;   //to prevent impulse damage

    detach _veh;
    sleep 1;

    _veh allowDamage true;
    _host allowDamage true;     //remoteExec where local!
    player allowDamage true;   //to prevent impulse damage

    private _type = typeOf _veh;
	private _config = configFile >> "CfgVehicles" >> _type;
	private _sizeVis = getNumber (_config >> "visualTargetSize");
    private _sizeIR = getNumber (_config >> "irTargetSize");
    private _sizeRad = getNumber (_config >> "radarTargetSize");

    _veh setTargetSize [_sizeVis, _sizeIR, _sizeRad];
    //systemchat str (_veh setTargetSize []);
};


fnc_RC_eVTOL_attach = {

    params ["_veh", "_host"];

    _veh engineOn false;
    [_veh, 1, player] call GYGJetson_fnc_setFold;

    _veh allowDamage false;
    _host allowDamage false;     //remoteExec where local!
    player allowDamage false;
    sleep 0.2;
    [_veh, cursorObject] call BIS_fnc_attachToRelative;
    sleep 0.5;
    _veh allowDamage true; 
    _host allowDamage true;     //remoteExec where local!
    player allowDamage true;
};


fnc_RC_eVTOL_EH_attached = {

    params ["_veh"];

    systemchat "attached";

    //[_veh, true] call fnc_RC_eVTOL_EH_engine;
    _veh setTargetSize [0.1,0.1,0.1];
    //systemchat str (_veh setTargetSize []);
};


fnc_RC_eVTOL_EH_getOut = {

    params ["_veh"];

    //systemchat "getOut";

    _veh allowDamage false;
    _veh engineOn false;
    [_veh, 1, player] call GYGJetson_fnc_setFold;

    sleep 3;
    _veh allowDamage true;
};


fnc_RC_eVTOL_EH_engine = {

    params ["_veh", "_engOn"];

    if (_engOn) then {

        //systemchat "engineOn";

        if ((attachedTo _veh) isNotEqualTo objNull) then {

            _veh engineOn false;
            _veh animateSource ["FoldArms", 1];
            //sleep 2.1;
            [_veh, 1, player] call GYGJetson_fnc_setFold;

            //systemchat "currAttached";
        };
    } else {

        [_veh, 1, player] call GYGJetson_fnc_setFold;

        //systemchat "engineOff";
    };
};


fnc_RC_eVTOL_minigun = {

    params ["_veh"];

    //disable collision so AI doesnt try to dodge obj by infinitely ascending

    _w = createSimpleObject ["\rhsusf\addons\rhsusf_airweapons\MELB\rhsusf_g_m134", _veh modelToWorldVisualWorld [0,0.87,-0.55], false];
    _w allowdamage false;
    [_w, _veh, true] call BIS_fnc_attachToRelative;
    _yaw = 180;
    _pitch = 0;
    _roll = 0;

    _w setVectorDirAndUp [           
        [sin _yaw * cos _pitch, cos _yaw * cos _pitch, sin _pitch],           
        [[sin _roll, -sin _pitch, cos _roll * cos _pitch], - _yaw] call BIS_fnc_rotateVector2D          
    ];
};


/*
    private _veh = vehicle player;

    private _attObj = (attachedObjects _veh);
    if (count _attObj > 0) then {
        {deleteVehicle _x} forEach _attObj;
    };

    _w = createSimpleObject ["\rhsusf\addons\rhsusf_airweapons\MELB\rhsusf_g_m134", _veh modelToWorldVisualWorld [0,0.87,-0.55], false];
    _w allowdamage false;
    [_w, _veh, true] call BIS_fnc_attachToRelative;
    _yaw = 180;
    _pitch = 0;
    _roll = 0;

    _w setVectorDirAndUp [           
        [sin _yaw * cos _pitch, cos _yaw * cos _pitch, sin _pitch],           
        [[sin _roll, -sin _pitch, cos _roll * cos _pitch], - _yaw] call BIS_fnc_rotateVector2D          
    ]; 


    (vehicle player) addMagazineTurret ["RC_60Rnd_20mm_HEAB_cUAS_T_G", [-1]];
    (vehicle player) addMagazineTurret ["RC_60Rnd_20mm_cUAS", [-1]];
    (vehicle player) addWeaponTurret ["RC_autocannon_20mm_cUAS", [-1]];

    (vehicle player) addMagazineTurret ["RC_PylonM_1000Rnd_127mm_SLAP_T_G_left", [-1]];
    (vehicle player) addWeaponTurret ["RC_PylonW_127mm_Minigun", [-1]];

    (vehicle player) addMagazineTurret ["RC_2000Rnd_338_SLAP_T_G", [-1]];
    (vehicle player) addWeaponTurret ["RC_RHS_338_DoorMinigun_1", [-1]];
    
    (vehicle player) addMagazineTurret ["RC_PylonM_175Rnd_20mm_Proxy_Lead", [-1]];
    (vehicle player) addWeaponTurret ["RC_PylonW_TwinCannon_Lead_Base", [-1]];
*/


//[_veh] call fncfoldarms;
//_veh animate ["foldArms", 1, true];
//_veh animateSource ["RotorPark",1];
//(vehicle player) setWantedRPMRTD [0, 2, -1];


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


_veh spawn {
    params ["_veh"];
    private _gearDown = false;

    while {alive _veh} do {
        private _alt = getPosATL _veh select 2;
        private _spd = speed _veh; // km/h

        if (!_gearDown && _alt < 50 && _spd < 80) then {
            _veh landGear "DOWN";
            _gearDown = true;
        };
        if (_gearDown && (_alt > 70 || _spd > 120)) then {
            _veh landGear "UP";
            _gearDown = false;
        };

        sleep 0.3;
    };
};
*/

//private _rpm = (rotorRpmRTD _veh)#0;
//_veh setWantedRPMRTD [0, 2, -1];

//[_veh] call fncfoldarms;
//_veh animate ["foldArms", 1, true];




/*
private _veh = getConnectedUav player;
private _vehP = vehicle player;

_veh setPhysicsCollisionFlag false;
_vehP setPhysicsCollisionFlag false;    //bugs into ground and explodes
_veh disableCollisionWith _vehP;
*/


/*
	selectionNames (getConnectedUAV player);

	private _offset = (getConnectedUAV player) worldToModel (ASLToAGL (getPosASL (vehicle player)));
	copyToClipboard str _offset;
	hint str _offset;
	[-5.14209,-2.40117,-1.09293]

	private _obj1 = (vehicle player);
	private _obj2 = (getConnectedUAV player);
	private _offset = (_obj2 worldToModel (ASLToAGL (getPosASL _obj1))) vectorDiff (_obj2 selectionPosition "wing_fold_l");
	copyToClipboard str _offset;
	hint str _offset;

	private _obj1 = (vehicle player);
	private _obj2 = (getConnectedUAV player);
	private _offset = (_obj2 worldToModel (getPos _obj1)) vectorDiff (_obj2 selectionPosition "wing_fold_l");
	copyToClipboard str _offset;
	hint str _offset;

	[3.77412,1.27356,-1.48752]
	(vehicle player) attachTo [(getConnectedUAV player), [-3.77412,1.27356,-0.6], 'wing_fold_r', true];

	(getConnectedUAV player) animate ["wing_fold_l", 1];
*/
