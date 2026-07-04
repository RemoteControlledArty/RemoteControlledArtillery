/*
	Author: Ascent

	Description:
	Allows requesting of FPV, if systems operator glasses are equipped.
*/

params ['_player'];

private _sidePlayer = side player;
private _validFPVs = [];
private _valid_FPV_Containers = [];

switch (true) do {
	case(_sidePlayer == west): {
		_validFPVs = ["B_Crocus_MP_Bag", "B_Crocus_MP_Sens_Bag", "B_Crocus_MP_NV_Bag", "B_Crocus_MP_NV_Sens_Bag", "B_Crocus_MP_TI_Bag", "B_Crocus_MP_TI_Sens_Bag", "B_Crocus_PvP_Bag", "B_Crocus_Training_Bag"];
		_FPV_Containers = RC_FPV_Containers_B;
	};
	case(_sidePlayer == east): {
		_validFPVs = ["O_Crocus_MP_Bag", "O_Crocus_MP_Sens_Bag", "O_Crocus_MP_NV_Bag", "O_Crocus_MP_NV_Sens_Bag", "O_Crocus_MP_TI_Bag", "O_Crocus_MP_TI_Sens_Bag", "O_Crocus_PvP_Bag", "O_Crocus_Training_Bag"];
		_FPV_Containers = RC_FPV_Containers_O;
	};
	case(_sidePlayer == resistance): {
		_validFPVs = ["I_Crocus_MP_Bag", "I_Crocus_MP_Sens_Bag", "I_Crocus_MP_NV_Bag", "I_Crocus_MP_NV_Sens_Bag", "I_Crocus_MP_TI_Bag", "I_Crocus_MP_TI_Sens_Bag", "I_Crocus_PvP_Bag", "I_Crocus_Training_Bag"];
		_FPV_Containers = RC_FPV_Containers_I;
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
				//checks which side last opened the container to reprogram the fpv's, defaults to _sidePlayer if none is set
				if (_x getVariable ["RC_FPV_ContainerSide", _sidePlayer] == _sidePlayer) then {
                    _validVeh pushBack _x;
                };
			};
		};
	};
} forEach _allVeh;


_validVeh = _validVeh apply {[round (_x distance player), _x]};
_validVeh sort true;


private _foundFPV = false;
{
    private _veh = _x select 1;


    //backpacks
    private _cargo = getBackpackCargo _veh;
    private _classes = _cargo select 0;        //0 is classes, 1 is amount
    private _idx = _classes findIf {(_x in _validFPVs)};

    //throwable
    private _cargo2 = getMagazineCargo _veh;
    private _classes2 = _cargo2 select 0;        //0 is classes, 1 is amount
    private _idx2 = _classes2 findIf {(_x in ["Crocus_MP_Throw", "Crocus_MP_Sens_Throw", "Crocus_MP_NV_Throw", "Crocus_MP_NV_Sens_Throw", "Crocus_MP_TI_Throw", "Crocus_MP_TI_Sens_Throw", "Crocus_PvP_Throw", "Crocus_Training_Throw"])};


    private _continue = true;
    if (_idx > -1 || _idx2 > -1) then
    {
        private _position = getPosASL _veh;
        private _height = 50;
        private _i = 0;
        private _hasAbove = false;
        private _coords = [[0, 0], [1, 1], [-1, 1], [1, -1], [-1,-1]];
		
        while { ! _hasAbove  && _i < count _coords} do
        {
			private _x = _coords select _i;
            private _startPos = [(_position select 0) + (_x select 0), (_position select 1) + (_x select 1), (_position select 2)];
            private _endPos = [(_startPos select 0), (_startPos select 1), (_position select 2) + _height];
            _hasAbove = lineIntersects [_startPos, _endPos, _this select 0, objNull];
            _i = _i + 1;
        };
        if (_hasAbove) then
        {
			private _posATL = getPosATL _veh;
			private _str = "FPV request failed at y" + str (round (_posATL #0)) + " x" + str (round (_posATL #1)) + ", obstructed above, cannot start.";

			systemchat _str;
			_continue = false;
        }
    };


	if (_idx > -1 && _continue) exitWith {

        private _classBag = (_classes select _idx);
        private _stringSplit = _classBag splitString "_";
        private _stringCountNew = (count _stringSplit) - 1;

        _stringSplit deleteAt _stringCountNew;
        private _classFPV = _stringSplit joinString "_";

        //systemchat _classFPV;
        systemchat "Sending FPV, wait!";

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
                _count = _newCount max 0;    //avoiding negative numbers
            };

            if (_count > 0) then {
                _veh addBackpackCargoGlobal [_class, _count];
            };
        };

        [_veh, _classFPV, _sidePlayer] call RC_fnc_RC_FPV_Request_Deploy;
        _foundFPV = true;
    };


	if (_idx2 > -1 && _continue) exitWith {

        private _classThrowable = (_classes2 select _idx2);
        private _stringSplit = _classThrowable splitString "_";
        private _stringCountNew = (count _stringSplit) - 1;

        _stringSplit deleteAt _stringCountNew;
        private _classFPV = _stringSplit joinString "_";

        switch (true) do {
            case(_sidePlayer == west): {
                _classFPV = "B_" + _classFPV;
            };
            case(_sidePlayer == east): {
                _classFPV = "O_" + _classFPV;
            };
            case(_sidePlayer == resistance): {
                _classFPV = "I_" + _classFPV;
            };
        };

        //systemchat _classFPV;
        systemchat "Sending FPV, wait!";

        //find backpack index
        private _counts  = _cargo2 select 1;
        private _newCount = (_counts select _idx2) - 1;
        private _classToRemove = _classes2 select _idx2;

        //clear all backpacks
        clearMagazineCargoGlobal _veh;

        //re-add backpacks except the one removed
        for "_idx2" from 0 to ((count _classes2) - 1) do {
            private _class = _classes2 select _idx2;
            private _count = _counts select _idx2;

            if (_class == _classToRemove) then {
                _count = _newCount max 0;    //avoiding negative numbers
            };

            if (_count > 0) then {
                _veh addMagazineCargoGlobal [_class, _count];
            };
        };

        [_veh, _classFPV, _sidePlayer] call RC_fnc_RC_FPV_Request_Deploy;
        _foundFPV = true;
    };
} forEach _validVeh;

/*
private _foundFPV = false;
{
	private _veh = _x select 1;


	//backpacks
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
		systemchat "sending FPV, wait";

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


	//throwable
	private _cargo = getMagazineCargo _veh;
	private _classes = _cargo select 0;		//0 is classes, 1 is amount
	private _idx = _classes findIf {(_x in ["Crocus_MP_Throw", "Crocus_MP_Sens_Throw", "Crocus_MP_NV_Throw", "Crocus_MP_NV_Sens_Throw", "Crocus_MP_TI_Throw", "Crocus_MP_TI_Sens_Throw", "Crocus_PvP_Throw", "Crocus_Training_Throw"])};

	if (_idx > -1) exitWith {

		private _classThrowable = (_classes select _idx);
		private _stringSplit = _classThrowable splitString "_";
		private _stringCountNew = (count _stringSplit) - 1;

		_stringSplit deleteAt _stringCountNew;
		private _classFPV = _stringSplit joinString "_";

		switch (true) do {
			case(_sidePlayer == west): {
				_classFPV = "B_" + _classFPV;
			};
			case(_sidePlayer == east): {
				_classFPV = "O_" + _classFPV;
			};
			case(_sidePlayer == resistance): {
				_classFPV = "I_" + _classFPV;
			};
		};

		//systemchat _classFPV;
		systemchat "sending FPV, wait";

		//find backpack index
		private _counts  = _cargo select 1;
		private _newCount = (_counts select _idx) - 1;
		private _classToRemove = _classes select _idx;

		//clear all backpacks
		clearMagazineCargoGlobal _veh;

		//re-add backpacks except the one removed
		for "_idx" from 0 to ((count _classes) - 1) do {
			private _class = _classes select _idx;
			private _count = _counts select _idx;

			if (_class == _classToRemove) then {
				_count = _newCount max 0;	//avoiding negative numbers
			};

			if (_count > 0) then {
				_veh addMagazineCargoGlobal [_class, _count];
			};
		};

		[_veh, _classFPV, _sidePlayer] call RC_fnc_RC_FPV_Request_Deploy;
		_foundFPV = true;
	};
} forEach _validVeh;


if (!_foundFPV) then {
	systemchat "no FPV's available";
};
*/