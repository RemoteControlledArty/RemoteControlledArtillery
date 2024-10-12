/*
 * Author: Eric & Ascent
 * Checks spawned vehicles if they have the value "artilleryscanner=1;", adds them to array for counter battery use.
 * Needs to be preinit to work on 3den spawned vehicles.
*/

//checks if spawned vehicles are artillery, to add them in counter battery array
addMissionEventHandler ["EntityCreated", {
	params ["_entity"];
    //if (!local _vehicle) exitwith {};

	_isArtillery = getNumber (configFile >> "CfgVehicles" >> (typeOf _entity) >> "artilleryScanner") == 1;

	if (_isArtillery) then {

        _entitySide_B = (side _entity == west);
        _entitySide_O = (side _entity == east);
        _entitySide_I = (side _entity == resistance);

        switch (true) do {
            case(_entitySide_B): {
                RC_ArtilleryArray_B pushback _entity;
                publicVariable "RC_ArtilleryArray_B";
                //hint for testing
                [str RC_ArtilleryArray_B] remoteExec ["hint", west];

                _entity addEventHandler ["Killed", {
                    params ["_unit"];

                    RC_ArtilleryArray_B deleteAt (RC_ArtilleryArray_B find _unit);
                    publicVariable "RC_ArtilleryArray_B";
                    //hint for testing
                    [str RC_ArtilleryArray_B] remoteExec ["hint", west];
                }];
            };
            case(_entitySide_O): {
                RC_ArtilleryArray_O pushback _entity;
                publicVariable "RC_ArtilleryArray_O";
                //hint for testing
                [str RC_ArtilleryArray_O] remoteExec ["hint", west];

                _entity addEventHandler ["Killed", {
                    params ["_unit"];

                    RC_ArtilleryArray_O deleteAt (RC_ArtilleryArray_O find _unit);
                    publicVariable "RC_ArtilleryArray_O";
                    //hint for testing
                    [str RC_ArtilleryArray_O] remoteExec ["hint", west];
                }];
            };
            case(_entitySide_I): {
                RC_ArtilleryArray_I pushback _entity;
                publicVariable "RC_ArtilleryArray_I";
                //hint for testing
                [str RC_ArtilleryArray_I] remoteExec ["hint", west];

                _entity addEventHandler ["Killed", {
                    params ["_unit"];

                    RC_ArtilleryArray_I deleteAt (RC_ArtilleryArray_I find _unit);
                    publicVariable "RC_ArtilleryArray_I";
                    //hint for testing
                    [str RC_ArtilleryArray_I] remoteExec ["hint", west];
                }];
            };
        };
    };
}];