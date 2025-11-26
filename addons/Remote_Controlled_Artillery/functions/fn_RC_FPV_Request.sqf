/*
	Author: Ascent

	Description:
	Allows requesting of FPV, if systems operator glasses are equipped.
*/

params ['_vic'];

private _allVeh = vehicles;

private _validVeh = [];
{
	if (!isNull _x) then {
		if ((_x distance player <= 15000)) then {
			if (!([side _x, side player] call BIS_fnc_sideIsEnemy)) then {
				if (side _x != civilian) then {
					_validVeh pushBack _x;
				};
			};
		};
	};
} forEach _allVeh;


_validVeh = _validVeh apply {[round (_x distance player), _x]};
_validVeh sort true;
/*
hint format [
	"Most distant is at %1, distance %2 m",
	_validVeh	
];
*/


{
	_vehX = _x select 1;
	_array = backpackCargo _vehX;	
	_bool1 = _array findIf {_x find "O_Crocus_MP_TI_Bag" != -1};
	_bool2 = _bool1 > -1;

	if (_bool2) exitWith {
		[_vehX] call RC_fnc_fpv_CarrierDeploy;		 
	};
	
	systemchat "none available";
} forEach _validVeh;


///
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