/*
	Author: Ascent

	Description:
	Allows requesting of FPV, if systems operator glasses are equipped.
*/

params ['_player'];

systemchat "1";

private _sidePlayer = side player;
private _validFPVs = [];
if (_sidePlayer == west) then {
	_validFPVs = ["B_Crocus_MP_Bag", "B_Crocus_MP_Sens_Bag", "B_Crocus_MP_NV_Bag", "B_Crocus_MP_NV_Sens_Bag", "B_Crocus_MP_TI_Bag", "B_Crocus_MP_TI_Sens_Bag", "B_Crocus_PvP_Bag", "B_Crocus_Training_Bag"];
};
if (_sidePlayer == east) then {
	_validFPVs = ["O_Crocus_MP_Bag", "O_Crocus_MP_Sens_Bag", "O_Crocus_MP_NV_Bag", "O_Crocus_MP_NV_Sens_Bag", "O_Crocus_MP_TI_Bag", "O_Crocus_MP_TI_Sens_Bag", "O_Crocus_PvP_Bag", "O_Crocus_Training_Bag"];
};
if (_sidePlayer == resistance) then {
	_validFPVs = ["I_Crocus_MP_Bag", "I_Crocus_MP_Sens_Bag", "I_Crocus_MP_NV_Bag", "I_Crocus_MP_NV_Sens_Bag", "I_Crocus_MP_TI_Bag", "I_Crocus_MP_TI_Sens_Bag", "I_Crocus_PvP_Bag", "I_Crocus_Training_Bag"];
};
/*
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
*/

systemchat "2";

private _allVeh = vehicles;
private _validVeh = [];
{
	if (!isNull _x) then {
		if ((_x distance player <= 15000)) then {
			if (!([side _x, _sidePlayer] call BIS_fnc_sideIsEnemy)) then {
				if (side _x != civilian) then {
					_validVeh pushBack _x;
				};
			};
		};
	};
} forEach _allVeh;

systemchat "3";

_validVeh = _validVeh apply {[round (_x distance player), _x]};
_validVeh sort true;
/*
hint format [
	"Most distant is at %1, distance %2 m",
	_validVeh	
];
*/

systemchat "4";

{
	private _veh = _x select 1;
	private _cargo = getBackpackCargo _veh;
	private _classes = _cargo select 0;
	private _idx = _classes findIf {(_x in _validFPVs)};

	if (_idx > -1) exitWith {

		private _classBag = (_classes select _idx);
		private _stringSplit = _classBag splitString "_";
		private _stringCountNew = (count _stringSplit) - 1;

		_stringSplit deleteAt _stringCountNew;
		private _classFPV = _stringSplit joinString "_";

		systemchat _classFPV;
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
				//avoiding negative numbers
				_count = _newCount max 0;
			};

			if (_count > 0) then {
				_veh addBackpackCargoGlobal [_class, _count];
			};
		};

		[_veh, _classFPV, _sidePlayer] call RC_fnc_fpv_CarrierDeployLow;
		private _foundFPV = true;
	};
} forEach _validVeh;

systemchat "5";

if (!_foundFPV) then {
	systemchat "no FPV's available";
};