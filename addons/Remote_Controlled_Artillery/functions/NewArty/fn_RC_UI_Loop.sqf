/*
    RC UI Loop (DEBUG)
*/

diag_log "[RC][UI] Loop started";

while {uiNamespace getVariable ["RC_UI_Active", false]} do {

    private _ui = uiNamespace getVariable "RC_ui";
    if (isNil "_ui") exitWith {
        diag_log "[RC][UI] ERROR: UI hashmap missing";
    };

    // visual heartbeat
    (_ui get "az") ctrlSetText "RC UI ACTIVE";

    uiSleep 0.5;
};

diag_log "[RC][UI] Loop exited";


/*
    RC UI Loop
    Render-only loop, runs every frame while UI is active
*/

/*
while {uiNamespace getVariable ["RC_UI_Active", false]} do {

    private _ui = uiNamespace getVariable "RC_ui";
    private _state = uiNamespace getVariable "RC_state";
    private _veh = uiNamespace getVariable "RC_vehicle";

    if (isNil "_ui" || isNil "_state" || isNil "_veh") exitWith {};

    // ---- read live inputs ----
    private _target = laserTarget _veh;
    if (isNull _target) then {
        {
            (_x) ctrlSetText "---";
        } forEach (values _ui);
        uiSleep 0.02;
        continue;
    };

    private _distance = _veh distance _target;
    private _elevation = (getPosASL _target select 2) - (getPosASL _veh select 2);

    // ---- speed from cached weapon/firemode ----
    private _weapon = currentWeapon _veh;
    private _speed = getNumber (configFile >> "CfgWeapons" >> _weapon >> "initSpeed");

    // ---- update state only if changed ----
    if (
        _distance != (_state get "distance")
        || _elevation != (_state get "barrelElevation")
        || _speed != (_state get "muzzleSpeed")
    ) then {
        [_distance, _elevation, _speed] call RC_fnc_State_Update;
    };

    // ---- render ----
    if (_state get "valid") then {
        (_ui get "highSol") ctrlSetText format ["%1°", (_state get "highAngle")];
        (_ui get "lowSol") ctrlSetText format ["%1°", (_state get "lowAngle")];
        (_ui get "etaHigh") ctrlSetText format ["%1 s", (_state get "highETA")];
        (_ui get "etaLow") ctrlSetText format ["%1 s", (_state get "lowETA")];
    } else {
        {
            (_x) ctrlSetText "NO SOL";
        } forEach (values _ui);
    };

    uiSleep 0.02;
};
*/