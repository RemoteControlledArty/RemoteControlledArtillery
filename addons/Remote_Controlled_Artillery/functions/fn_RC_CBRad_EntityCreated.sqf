/*
 * Author: Eric & Ascent
 * Checks spawned vehicles if they have the value "artilleryscanner=1;", adds them to array for counter battery fire when friendly counter battery radar is active:
 * -for players marks opposing indirect fire sources on the map
 * -for AI returns fire on opposing indirect fire sources
 * Needs to be preinit to work on 3den spawned vehicles.
*/

RC_CBRad_Player_Array_B = [];
RC_CBRad_Player_Array_O = [];
publicVariable "RC_ArtilleryArray_B";
publicVariable "RC_ArtilleryArray_O";

RC_CBRad_AI_Array_B = [];
RC_CBRad_AI_Array_O = [];
publicVariable "RC_CBRad_AI_Array_B";
publicVariable "RC_CBRad_AI_Array_O";

RC_ArtilleryArray_B = [];
RC_ArtilleryArray_O = [];
publicVariable "RC_ArtilleryArray_B";
publicVariable "RC_ArtilleryArray_O";

RC_isInRangeArray_B = [];
RC_isInRangeArray_O = [];
publicVariable "RC_isInRangeArray_B";
publicVariable "RC_isInRangeArray_O";

RC_fireMissionArray_B = [];
RC_fireMissionArray_O = [];
publicVariable "RC_fireMissionArray_B";
publicVariable "RC_fireMissionArray_O";

//server side only  //creates problem of assets not being added to array or EH triggering
//eden assets and script attached mortar been local to server and worked, all other assets been local to player and didnt work
//if (!isServer) exitwith {};

//checks if spawned vehicles are artillery, to add them in counter battery array
addMissionEventHandler ["EntityCreated", {
	params ["_entity"];
    //if (!local _vehicle) exitwith {};

	_isArtillery = getNumber (configFile >> "CfgVehicles" >> (typeOf _entity) >> "artilleryScanner") == 1;

	if (_isArtillery) then {

        _entitySide_B = (side _entity == west);
        _entitySide_O = (side _entity == east);

        switch (true) do {
            case(_entitySide_B): {
                RC_ArtilleryArray_B pushback _entity;
                publicVariable "RC_ArtilleryArray_B";

                //hint for testing
                [str RC_ArtilleryArray_B] remoteExec ["hint", west];
            };
            case(_entitySide_O): {
                RC_ArtilleryArray_O pushback _entity;
                publicVariable "RC_ArtilleryArray_O";

                //hint for testing
                [str RC_ArtilleryArray_O] remoteExec ["hint", west];
            };
        };
    };
}];