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

    //maybe use single array but add radar side check, as that could prevent post spawn side change issues
    //checks for opposing CBRad's
    _CBRad_Player_AliveAmount_B = ({alive _x} count RC_CBRad_Player_Array_B);
    _CBRad_Player_AliveAmount_O = ({alive _x} count RC_CBRad_Player_Array_O);
    _CBRad_Player_AliveAmount_I = ({alive _x} count RC_CBRad_Player_Array_I);
    _CBRad_AI_AliveAmount_B = ({alive _x} count RC_CBRad_AI_Array_B);
    _CBRad_AI_AliveAmount_O = ({alive _x} count RC_CBRad_AI_Array_O);
    _CBRad_AI_AliveAmount_I = ({alive _x} count RC_CBRad_AI_Array_I);

    _CBRad_AliveAmount = _CBRad_Player_AliveAmount_B + _CBRad_Player_AliveAmount_O + _CBRad_Player_AliveAmount_I + _CBRad_AI_AliveAmount_B + _CBRad_AI_AliveAmount_O + _CBRad_AI_AliveAmount_I;
    if (!(_CBRad_AliveAmount>0)) exitwith {};


    //cleans up CBRad arrays
    RC_CBRad_AI_Array_B = RC_CBRad_AI_Array_B - [objNull];
    RC_CBRad_AI_Array_O = RC_CBRad_AI_Array_O - [objNull];
    RC_CBRad_AI_Array_I = RC_CBRad_AI_Array_I - [objNull];
    RC_CBRad_Player_Array_B = RC_CBRad_Player_Array_B - [objNull];
    RC_CBRad_Player_Array_O = RC_CBRad_Player_Array_O - [objNull];
    RC_CBRad_Player_Array_I = RC_CBRad_Player_Array_I - [objNull];
    
    //checks side of the vehicle
    _vehicleSide_B = (side _vehicle == west);
    _vehicleSide_O = (side _vehicle == east);
    _vehicleSide_I = (side _vehicle == resistance);

    //checks opposing sides
    _opposedTo_B = [side _vehicle, west] call BIS_fnc_sideIsEnemy;
    _opposedTo_O = [side _vehicle, east] call BIS_fnc_sideIsEnemy;
    _opposedTo_I = [side _vehicle, resistance] call BIS_fnc_sideIsEnemy;


    //conciders potential prior CB firemission completed
    switch (true) do {
        case(_vehicleSide_B): {
            RC_fireMissionArray_B deleteAt (RC_fireMissionArray_B find _vehicle);
        };
        case(_vehicleSide_O): {
            RC_fireMissionArray_O deleteAt (RC_fireMissionArray_O find _vehicle);
        };
        case(_vehicleSide_I): {
            RC_fireMissionArray_I deleteAt (RC_fireMissionArray_I find _vehicle);
        };
    };


    private _lastTime = _vehicle getVariable "ArtySourceTime";
    private _timeSinceLast = time - _lastTime;


    if (_timeSinceLast > RC_IgnoreTime_F1) then {
        _vehicle setVariable ["ArtySourceTime", time, true];

        //Blufor AI
        if (_opposedTo_B and (_CBRad_AI_AliveAmount_B > 0)) then {
            [_vehicle] call RC_fnc_RC_AI_CBRad_Blufor;
        };

        //Opfor AI
        if (_opposedTo_O and (_CBRad_AI_AliveAmount_O > 0)) then {
            [_vehicle] call RC_fnc_RC_AI_CBRad_Opfor;
        };

        //Indfor AI
        if (_opposedTo_I and (_CBRad_AI_AliveAmount_I > 0)) then {
            [_vehicle] call RC_fnc_RC_AI_CBRad_Indfor;
        };
    };

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
}];