/*
 * Author: Eric & Ascent
 * If artillery fired and opposing counter battery radar is active:
 * -for players marks opposing indirect fire sources and impact areas on the map
 * -for AI returns fire on opposing indirect fire sources
*/


//if artillery fires checks if opposing CBRad is alive, for opposing AI assigns CB firemission, for opposing players creates map markers
addMissionEventHandler ["ArtilleryShellFired", {
    params ["_veh", "_weapon", "_ammo", "_gunner", "_instigator", "_artilleryTarget", "_targetPos", "_proj"];
    if (!isServer) exitwith {};


    //checks side of the vehicle that fired the shell
    private _vehSide = side _veh;

    //conciders potential prior CB firemission completed
    switch (true) do {
        case(_vehSide == west): {
            RC_fireMissionArray_B deleteAt (RC_fireMissionArray_B find _veh);
        };
        case(_vehSide == east): {
            RC_fireMissionArray_O deleteAt (RC_fireMissionArray_O find _veh);
        };
        case(_vehSide == resistance): {
            RC_fireMissionArray_I deleteAt (RC_fireMissionArray_I find _veh);
        };
    };


    //cleans up CBRad arrays
    RC_CBRad_AI_Array = RC_CBRad_AI_Array select { !isNull _x && alive _x };
    RC_CBRad_Player_Array = RC_CBRad_Player_Array select { !isNull _x && alive _x };
    //checks if any CBRad's are alive, exits if not
    if ((count (RC_CBRad_AI_Array + RC_CBRad_Player_Array)) < 1) exitwith {};


    //seperates the alive player CBRad's by side, then counts each
    private _CBRad_Player_Arr_B = [];
    private _CBRad_Player_Arr_O = [];
    private _CBRad_Player_Arr_I = [];
    {
        private _side = side _x;
        
        switch (true) do {
            case(_side == west): {
                _CBRad_Player_Arr_B pushback _x;
            };
            case(_side == east): {
                _CBRad_Player_Arr_O pushback _x;
            };
            case(_side == resistance): {
                _CBRad_Player_Arr_I pushback _x;
            };
        };
    } forEach RC_CBRad_Player_Array;
    private _CBRad_Player_AliveAmount_B = count _CBRad_Player_Arr_B;
    private _CBRad_Player_AliveAmount_O = count _CBRad_Player_Arr_O;
    private _CBRad_Player_AliveAmount_I = count _CBRad_Player_Arr_I;


    //checks opposing sides
    private _opposedTo_B = [_vehSide, west] call BIS_fnc_sideIsEnemy;
    private _opposedTo_O = [_vehSide, east] call BIS_fnc_sideIsEnemy;
    private _opposedTo_I = [_vehSide, resistance] call BIS_fnc_sideIsEnemy;


    //private _lastTime = _veh getVariable "ArtySourceTime";
    private _lastTime = _veh getVariable ["ArtySourceTime", 0];
    private _timeSinceLast = time - _lastTime;


    //Blufor Player
    if (_opposedTo_B and (_CBRad_Player_AliveAmount_B > 0)) then {
        [_veh, _targetPos, _timeSinceLast, west, _proj] call RC_fnc_RC_CBRad_Player;
    };
    //Opfor Player
    if (_opposedTo_O and (_CBRad_Player_AliveAmount_O > 0)) then {
        [_veh, _targetPos, _timeSinceLast, east, _proj] call RC_fnc_RC_CBRad_Player;
    };
    //Indfor Player
    if (_opposedTo_I and (_CBRad_Player_AliveAmount_I > 0)) then {
        [_veh, _targetPos, _timeSinceLast, resistance, _proj] call RC_fnc_RC_CBRad_Player;
    };


    //seperates the alive AI CBRad's by side, then counts each
    private _CBRad_AI_Arr_B = [];
    private _CBRad_AI_Arr_O = [];
    private _CBRad_AI_Arr_I = [];
    {
        private _side = side _x;
        
        switch (true) do {
            case(_side == west): {
                _CBRad_AI_Arr_B pushback _x;
            };
            case(_side == east): {
                _CBRad_AI_Arr_O pushback _x;
            };
            case(_side == resistance): {
                _CBRad_AI_Arr_I pushback _x;
            };
        };
    } forEach RC_CBRad_AI_Array;
    private _CBRad_AI_AliveAmount_B = count _CBRad_AI_Arr_B;
    private _CBRad_AI_AliveAmount_O = count _CBRad_AI_Arr_O;
    private _CBRad_AI_AliveAmount_I = count _CBRad_AI_Arr_I;


    //cleans up array of available indirect fire assets
    RC_ArtilleryArray = RC_ArtilleryArray select { !isNull _x && alive _x };
    //exits if not indirect fire assets are available to return fire
    if ((count RC_ArtilleryArray) < 1) exitwith {};


    private _artyArray_B = [];
    private _artyArray_O = [];
    private _artyArray_I = [];
    {
        private _side = side _x;
        
        switch (true) do {
            case(_side == west): {
                _artyArray_B pushback _x;
            };
            case(_side == east): {
                _artyArray_O pushback _x;
            };
            case(_side == resistance): {
                _artyArray_I pushback _x;
            };
        };
    } forEach RC_ArtilleryArray;
    private _artyAliveAmount_B = count _artyArray_B;
    private _artyAliveAmount_O = count _artyArray_O;
    private _artyAliveAmount_I = count _artyArray_I;


    //timesincelast doesnt seem to work, and maybe doesnt have to eighter
    if (_timeSinceLast > RC_CBRad_IgnoreTime_AI) then {
        _veh setVariable ["ArtySourceTime", time, true];    //likely doesnt need true (public), as its server only?

        //Blufor AI
        if (_opposedTo_B && (_CBRad_AI_AliveAmount_B > 0) && (_artyAliveAmount_B > 0)) then {
            [_veh, _artyArray_B, west] call RC_fnc_RC_CBRad_AI;
        };
        //Opfor AI
        if (_opposedTo_O && (_CBRad_AI_AliveAmount_O > 0) && (_artyAliveAmount_O > 0)) then {
            [_veh, _artyArray_O, east] call RC_fnc_RC_CBRad_AI;
        };
        //Indfor AI
        if (_opposedTo_I && (_CBRad_AI_AliveAmount_I > 0) && (_artyAliveAmount_I > 0)) then {
            [_veh, _artyArray_I, resistance] call RC_fnc_RC_CBRad_AI;
        };
    };
}];