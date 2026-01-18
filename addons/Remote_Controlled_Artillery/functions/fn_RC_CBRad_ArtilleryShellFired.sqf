/*
 * Author: Eric & Ascent
 * If artillery fired and opposing counter battery radar is active:
 * -for players marks opposing indirect fire sources and impact areas on the map
 * -for AI returns fire on opposing indirect fire sources
*/


//if artillery fires checks if opposing CBRad is alive, for opposing AI assigns CB firemission, for opposing players creates map markers
addMissionEventHandler ["ArtilleryShellFired", {
    params ["_vehicle", "_weapon", "_ammo", "_gunner", "_instigator", "_artilleryTarget", "_targetPosition", "_shell"];
    if (!isServer) exitwith {};


    //checks side of the vehicle that fired the shell
    private _vehSide = side _vehicle;

    //conciders potential prior CB firemission completed
    switch (true) do {
        case(_vehSide == west): {
            RC_fireMissionArray_B deleteAt (RC_fireMissionArray_B find _vehicle);
        };
        case(_vehSide == east): {
            RC_fireMissionArray_O deleteAt (RC_fireMissionArray_O find _vehicle);
        };
        case(_vehSide == resistance): {
            RC_fireMissionArray_I deleteAt (RC_fireMissionArray_I find _vehicle);
        };
    };


    //cleans up CBRad arrays
    RC_CBRad_AI_Array = RC_CBRad_AI_Array select { !isNull _x && alive _x };
    RC_CBRad_Player_Array = RC_CBRad_Player_Array select { !isNull _x && alive _x };
    //checks if any CBRad's are alive, exits if not
    if ((count (RC_CBRad_AI_Array + RC_CBRad_Player_Array)) < 1) exitwith {};


    //seperates the alive player CBRad's by side, then counts each
    private _CBRad_Player_Array_B = [];
    private _CBRad_Player_Array_O = [];
    private _CBRad_Player_Array_I = [];
    {
        private _side = side _x;
        
        switch (true) do {
            case(_side == west): {
                _CBRad_Player_Array_B pushback _x;
            };
            case(_side == east): {
                _CBRad_Player_Array_O pushback _x;
            };
            case(_side == resistance): {
                _CBRad_Player_Array_I pushback _x;
            };
        };
    } forEach RC_CBRad_Player_Array;
    private _CBRad_Player_AliveAmount_B = count _CBRad_Player_Array_B;
    private _CBRad_Player_AliveAmount_O = count _CBRad_Player_Array_O;
    private _CBRad_Player_AliveAmount_I = count _CBRad_Player_Array_I;


    //checks opposing sides
    private _opposedTo_B = [_vehSide, west] call BIS_fnc_sideIsEnemy;
    private _opposedTo_O = [_vehSide, east] call BIS_fnc_sideIsEnemy;
    private _opposedTo_I = [_vehSide, resistance] call BIS_fnc_sideIsEnemy;


    //private _lastTime = _vehicle getVariable "ArtySourceTime";
    private _lastTime = _vehicle getVariable ["ArtySourceTime", 0];
    private _timeSinceLast = time - _lastTime;


    //Blufor Player
    if (_opposedTo_B and (_CBRad_Player_AliveAmount_B > 0)) then {
        [_vehicle, _targetPosition, _timeSinceLast] call RC_fnc_RC_Player_CBRad_Blufor;
    };
    //Opfor Player
    if (_opposedTo_O and (_CBRad_Player_AliveAmount_O > 0)) then {
        [_vehicle, _targetPosition, _timeSinceLast] call RC_fnc_RC_Player_CBRad_Opfor;
    };
    //Indfor Player
    if (_opposedTo_I and (_CBRad_Player_AliveAmount_I > 0)) then {
        [_vehicle, _targetPosition, _timeSinceLast] call RC_fnc_RC_Player_CBRad_Indfor;
    };


    //seperates the alive AI CBRad's by side, then counts each
    private _CBRad_AI_Array_B = [];
    private _CBRad_AI_Array_O = [];
    private _CBRad_AI_Array_I = [];
    {
        private _side = side _x;
        
        switch (true) do {
            case(_side == west): {
                _CBRad_AI_Array_B pushback _x;
            };
            case(_side == east): {
                _CBRad_AI_Array_O pushback _x;
            };
            case(_side == resistance): {
                _CBRad_AI_Array_I pushback _x;
            };
        };
    } forEach RC_CBRad_AI_Array;
    private _CBRad_AI_AliveAmount_B = count _CBRad_AI_Array_B;
    private _CBRad_AI_AliveAmount_O = count _CBRad_AI_Array_O;
    private _CBRad_AI_AliveAmount_I = count _CBRad_AI_Array_I;


    //cleans up array of available indirect fire assets
    RC_ArtilleryArray = RC_ArtilleryArray select { !isNull _x && alive _x };
    //exits if not indirect fire assets are available to return fire
    if ((count RC_ArtilleryArray) < 1) exitwith {};


    private _artilleryArray_B = [];
    private _artilleryArray_O = [];
    private _artilleryArray_I = [];
    {
        private _side = side _x;
        
        switch (true) do {
            case(_side == west): {
                _artilleryArray_B pushback _x;
            };
            case(_side == east): {
                _artilleryArray_O pushback _x;
            };
            case(_side == resistance): {
                _artilleryArray_I pushback _x;
            };
        };
    } forEach RC_ArtilleryArray;
    private _artilleryAliveAmount_B = count _artilleryArray_B;
    private _artilleryAliveAmount_O = count _artilleryArray_O;
    private _artilleryAliveAmount_I = count _artilleryArray_I;


    //timesincelast doesnt seem to work, and maybe doesnt have to eighter
    if (_timeSinceLast > RC_CBRad_IgnoreTime_AI) then {
        _vehicle setVariable ["ArtySourceTime", time, true];    //likely doesnt need true (public), as its server only?

        //Blufor AI
        if (_opposedTo_B && (_CBRad_AI_AliveAmount_B > 0) && (_artilleryAliveAmount_B > 0)) then {
            [_vehicle, _artilleryArray_B] call RC_fnc_RC_AI_CBRad_Blufor;
        };
        //Opfor AI
        if (_opposedTo_O && (_CBRad_AI_AliveAmount_O > 0) && (_artilleryAliveAmount_O > 0)) then {
            [_vehicle, _artilleryArray_O] call RC_fnc_RC_AI_CBRad_Opfor;
        };
        //Indfor AI
        if (_opposedTo_I && (_CBRad_AI_AliveAmount_I > 0) && (_artilleryAliveAmount_I > 0)) then {
            [_vehicle, _artilleryArray_I] call RC_fnc_RC_AI_CBRad_Indfor;
        };
    };
}];