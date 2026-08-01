params ["_entity"];

_entity setVariable ["ArtySourceTime", 0, true];

private _isArtillery = getNumber (configFile >> "CfgVehicles" >> (typeOf _entity) >> "artilleryScanner") == 1;

if (_isArtillery) then {

    RC_ArtilleryArray pushback _entity;

    _entity addEventHandler ["Killed", {
        params ["_unit"];

        [_unit] call RC_fnc_RC_CBRad_Killed_RE;
    }];
};