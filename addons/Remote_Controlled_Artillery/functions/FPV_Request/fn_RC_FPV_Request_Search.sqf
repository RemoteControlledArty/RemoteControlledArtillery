/*
	Author: Ascent

	Description:
	Allows requesting of FPV, if systems operator glasses are equipped.
*/

params ['_player'];

private _sidePlayer = side player;
private _validFPVs = [];
switch (true) do {
	case(_sidePlayer == west): {
		_validFPVs = ["B_Crocus_MP_Bag", "B_Crocus_MP_Sens_Bag", "B_Crocus_MP_NV_Bag", "B_Crocus_MP_NV_Sens_Bag", "B_Crocus_MP_TI_Bag", "B_Crocus_MP_TI_Sens_Bag", "B_Crocus_PvP_Bag", "B_Crocus_Training_Bag"];
	};
	case(_sidePlayer == east): {
		_validFPVs = ["O_Crocus_MP_Bag", "O_Crocus_MP_Sens_Bag", "O_Crocus_MP_NV_Bag", "O_Crocus_MP_NV_Sens_Bag", "O_Crocus_MP_TI_Bag", "O_Crocus_MP_TI_Sens_Bag", "O_Crocus_PvP_Bag", "O_Crocus_Training_Bag"];
	};
	case(_sidePlayer == resistance): {
		_validFPVs = ["I_Crocus_MP_Bag", "I_Crocus_MP_Sens_Bag", "I_Crocus_MP_NV_Bag", "I_Crocus_MP_NV_Sens_Bag", "I_Crocus_MP_TI_Bag", "I_Crocus_MP_TI_Sens_Bag", "I_Crocus_PvP_Bag", "I_Crocus_Training_Bag"];
	};
};


private _allVeh = vehicles;
private _validVeh = [];
{
	if (!isNull _x) then {
		if ((_x distance player <= 15000)) then {
			if ((count (crew _x)) > 0) then {
				if (!([side _x, _sidePlayer] call BIS_fnc_sideIsEnemy)) then {
					if (side _x != civilian) then {
						_validVeh pushBack _x;
					};
				};
			} else {
				_validVeh pushBack _x;
			};
		};
	};
} forEach _allVeh;


_validVeh = _validVeh apply {[round (_x distance player), _x]};
_validVeh sort true;


private _foundFPV = false;
{
	private _veh = _x select 1;
	private _cargo = getBackpackCargo _veh;
	private _classes = _cargo select 0;		//0 is classes, 1 is amount
	private _idx = _classes findIf {(_x in _validFPVs)};

	if (_idx > -1) exitWith {

		private _classBag = (_classes select _idx);
		private _stringSplit = _classBag splitString "_";
		private _stringCountNew = (count _stringSplit) - 1;

		_stringSplit deleteAt _stringCountNew;
		private _classFPV = _stringSplit joinString "_";

		//systemchat _classFPV;
		systemchat "sending FPV";

		//find backpack index
		private _counts  = _cargo select 1;
		private _newCount = (_counts select _idx) - 1;
		private _classToRemove = _classes select _idx;

		//clear all backpacks
		clearBackpackCargoGlobal _veh;

		//re-add backpacks except the one removed
		for "_idx" from 0 to ((count _classes) - 1) do {
			private _class = _classes select _idx;
			private _count = _counts select _idx;

			if (_class == _classToRemove) then {
				_count = _newCount max 0;	//avoiding negative numbers
			};

			if (_count > 0) then {
				_veh addBackpackCargoGlobal [_class, _count];
			};
		};

		[_veh, _classFPV, _sidePlayer] call RC_fnc_RC_FPV_Request_Deploy;
		_foundFPV = true;
	};
} forEach _validVeh;


if (!_foundFPV) then {
	systemchat "no FPV's available";
};