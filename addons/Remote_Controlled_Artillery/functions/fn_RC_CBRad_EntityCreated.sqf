/*
 * Author: Eric & Ascent
 * Checks spawned vehicles if they have the value "artilleryscanner=1;", adds them to array for counter battery use.
 * Needs to be preinit to work on 3den spawned vehicles.
*/


addMissionEventHandler ["EntityCreated", {
	params ["_entity"];
    if (!isServer) exitwith {};

    private _isArtillery = getNumber (configFile >> "CfgVehicles" >> (typeOf _entity) >> "artilleryScanner") == 1;

    if (_isArtillery) then {

        _entity setVariable ["ArtySourceTime", 0, true];
        RC_ArtilleryArray pushback _entity;

        /*
        _entity addMPEventHandler ["MPKilled", {
            if (!isServer) exitwith {};
            params ["_unit"];

            RC_ArtilleryArray deleteAt (RC_ArtilleryArray find _unit);
        }];
        */
        /*
        _entity addEventHandler ["Killed", {
            params ["_unit"];

            [_unit] call RC_fnc_RC_CBRad_Killed_RE;
        }];
        */
    };
}];


/*
//checks if spawned vehicles are artillery, to add them in counter battery array
addMissionEventHandler ["EntityCreated", {
	params ["_entity"];
    if (!local _entity) exitwith {};

    [_entity] call RC_fnc_RC_CBRad_EntityCreated_RE;
}];
*/