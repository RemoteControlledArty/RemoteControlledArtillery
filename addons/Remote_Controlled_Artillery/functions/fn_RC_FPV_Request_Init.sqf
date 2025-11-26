/*
	Author: Ascent
*/

if (!hasInterface) exitWith {};

RC_AllowedEquipment = ["G_Tactical_Clear", "G_Tactical_Black", "G_Tactical_Camo", "RC_SO_Goggles_tan", "RC_SO_Goggles_grn", "RC_SO_Goggles_blk", "RC_SO_Goggles_NV_tan", "RC_SO_Goggles_NV_grn", "RC_SO_Goggles_NV_blk", "RC_SO_Goggles_TI_tan", "RC_SO_Goggles_TI_grn", "RC_SO_Goggles_TI_blk"];
RC_AllowedEquipment = ["B_Crocus_MP", "B_Crocus_MP_Sens", "B_Crocus_MP_NV", "B_Crocus_MP_NV_Sens", "B_Crocus_MP_TI", "B_Crocus_MP_TI_Sens", "O_Crocus_MP", "O_Crocus_MP_Sens", "O_Crocus_MP_NV", "O_Crocus_MP_NV_Sens", "O_Crocus_MP_TI", "O_Crocus_MP_TI_Sens", "I_Crocus_MP", "I_Crocus_MP_Sens", "I_Crocus_MP_NV", "I_Crocus_MP_NV_Sens", "I_Crocus_MP_TI", "I_Crocus_MP_TI_Sens", "B_Crocus_PvP", "O_Crocus_PvP", "I_Crocus_PvP", "B_Crocus_Training", "O_Crocus_Training", "I_Crocus_Training"];
_playerEquipment = [goggles player, headgear player];
_playerEquipment = [goggles player, headgear player];
_playerEquipment append (assignedItems player);

RC_wearing = false;
{
	if (_x in _playerEquipment) exitWith {RC_wearing = true};
} forEach RC_AllowedEquipment;


player addEventHandler ["SlotItemChanged", {
	//params ["_unit", "_name", "_slot", "_assigned", "_weapon"];
	//params ["_unit"];

	//_AllowedEquipment = RC_AllowedEquipment splitString ",";
	_playerEquipment = [goggles player, headgear player];
	_playerEquipment append (assignedItems player);
	//_playerEquipment = [goggles _unit, headgear _unit];
	//_playerEquipment append (assignedItems _unit);


	RC_wearing = false;
	{
		if (_x in _playerEquipment) exitWith {RC_wearing = true};
	} forEach RC_AllowedEquipment;

	if (RC_wearing) then {
		
		_backpacksArray = backpackCargo _veh;

		_test = cursorTarget;
		//[_test, "O_Crocus_MP_TI_Bag"] call BIS_fnc_hasItem;

		//hint str backpackCargo _test;
		//hint str itemCargo _test;
		_array = backpackCargo _test;
		//_array = everyBackpack _test;
		//_bool = _array findIf {_x isEqualTo "O_Crocus_MP_TI_Bag"};
		_bool1 = _array findIf {_x find "O_Crocus_MP_TI_Bag" != -1};
		_bool2 = _bool1 > -1;
		systemchat str _bool2;

		if (_bool2) then {
			//[_test] call RC_fnc_fpv_CarrierDeploy;
		};

		_test removeAllWeapons; //removeItems "O_Crocus_MP_TI_Bag";
	};
}];



//
private _veh = _this select 0;        // your vehicle object
private _bag = "MyBag";               // backpack class to remove

// Get current cargo
private _cargo = getBackpackCargo _veh;
private _classes = _cargo select 0;
private _counts  = _cargo select 1;

// Find the index of the backpack
private _i = _classes find _bag;

if (_i > -1) then {
    private _newCount = (_counts select _i) - 1;

    // First: clear all backpacks
    clearBackpackCargoGlobal _veh;

    // Re-add backpacks except the one removed
    for "_idx" from 0 to ((count _classes) - 1) do {
        private _class = _classes select _idx;
        private _count = _counts select _idx;

        if (_class == _bag) then {
            _count = _newCount max 0;   // avoid negative numbers
        };

        if (_count > 0) then {
            _veh addBackpackCargoGlobal [_class, _count];
        };
    };
};
