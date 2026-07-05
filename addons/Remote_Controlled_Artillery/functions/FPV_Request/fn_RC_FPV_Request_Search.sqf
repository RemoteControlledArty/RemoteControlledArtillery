/*
	Author: Ascent

	Description:
	Allows requesting of FPV, if systems operator glasses are equipped.
*/

params ['_player'];

private _sidePlayer = side player;

/*
//made side neutral bags
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
*/


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
				//checks which side last opened the container to reprogram the fpv's, defaults to _sidePlayer if none is set, CONCIDER MAKING UNOPENED CRATES NON ACCESSABLE
				if (_x getVariable ["RC_FPV_ContainerSide", _sidePlayer] == _sidePlayer) then {
                    _validVeh pushBack _x;
                };
			};
		};
	};
} forEach _allVeh;


_validVeh = _validVeh apply {[round (_x distance player), _x]};
_validVeh sort true;



//neutral side bags & throwables, CONCIDER MAKING UNOPENED CRATES NON ACCESSABLE for MP
private _validBags = ["Crocus_MP_Bag", "Crocus_MP_Sens_Bag", "Crocus_MP_NV_Bag", "Crocus_MP_NV_Sens_Bag", "Crocus_MP_TI_Bag", "Crocus_MP_TI_Sens_Bag", "Crocus_PvP_Bag", "Crocus_Training_Bag"];
private _validMags = ["Crocus_MP_Throw", "Crocus_MP_Sens_Throw", "Crocus_MP_NV_Throw", "Crocus_MP_NV_Sens_Throw", "Crocus_MP_TI_Throw", "Crocus_MP_TI_Sens_Throw", "Crocus_PvP_Throw", "Crocus_Training_Throw"];


private _foundFPV = false;
{
    private _veh = _x #1;


    //backpacks
    private _cargo = getBackpackCargo _veh;
    private _classes = _cargo #0;        //0 is classes, 1 is amount
    private _idx = _classes findIf {(_x in _validBags)};

    //throwable
    private _cargo2 = getMagazineCargo _veh;
    private _classes2 = _cargo2 #0;        //0 is classes, 1 is amount
    private _idx2 = _classes2 findIf {(_x in _validMags)};

	private _pos = [0,0,0];
    private _continue = true;
    if (_idx > -1 || _idx2 > -1) then
    {
		//[_veh] call fnc_checkAbove;

		_pos = getPosASL _veh;
		private _height = 50;
		private _i = 0;
		private _hasAbove = false;

		/*
		//reduced size version
		private _endPos = [(_pos #0), (_pos #1), (_pos #2) + _height];
		_hasAbove = lineIntersects [_pos, _endPos, _veh, objNull];
		*/

		private _coords = [[0, 0], [1, 1], [-1, 1], [1, -1], [-1,-1]];
		while {!_hasAbove && _i < count _coords} do {

			private _x = _coords #_i;
			private _startPos = [(_pos #0) + (_x #0), (_pos #1) + (_x #1), (_pos #2)];
			private _endPos = [(_startPos #0), (_startPos #1), (_pos #2) + _height];
			_hasAbove = lineIntersects [_startPos, _endPos, _veh, objNull];
			_i = _i + 1;
		};

		if (_hasAbove) then {

			private _str = "FPV request failed at y" + str (round(_pos #0)) + " x" + str (round(_pos #1)) + ", obstructed above, cannot start.";

			/*
			//would be overwritten by next deploy, so systemchat is better atm
			hint format [
			"FPV request failed at:\ny%1 x%2\n%3m", 
				round (_pos #0), 
				round (_pos #1), 
				round (player distance _veh)
			];
			0 spawn
			{
				sleep 2.5;
				hint "";
			};
			*/

			systemchat _str;
			_continue = false;
		};
    };


	if (_idx > -1 && _continue) exitWith {

		private _classBag = (_classes #_idx);
        private _stringSplit = _classBag splitString "_";
        private _stringCountNew = (count _stringSplit) - 1;

        _stringSplit deleteAt _stringCountNew;
        private _classFPV = _stringSplit joinString "_";

        //systemchat "Sending FPV, wait!";
		hint format [
			"sending FPV from:\ny%1 x%2\n%3m", 
			round (_pos #0), 
			round (_pos #1), 
			round (player distance _veh)
		];
		0 spawn
		{
			sleep 4;
			hint "";
		};

        //find backpack index
        private _counts  = _cargo #1;
        private _newCount = (_counts #_idx) - 1;
        private _classToRemove = _classes #_idx;

        //clear all backpacks
        clearBackpackCargoGlobal _veh;

        //re-add backpacks except the one removed
        for "_idx" from 0 to ((count _classes) - 1) do {
            private _class = _classes #_idx;
            private _count = _counts #_idx;

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

        private _classThrowable = (_classes2 #_idx2);
        private _stringSplit = _classThrowable splitString "_";
        private _stringCountNew = (count _stringSplit) - 1;

        _stringSplit deleteAt _stringCountNew;
        private _classFPV = _stringSplit joinString "_";

		/*
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
		*/

        //systemchat "Sending FPV, wait!";
		hint format [
			"sending FPV from:\ny%1 x%2\n%3m", 
			round (_pos #0), 
			round (_pos #1), 
			round (player distance _veh)
		];
		0 spawn
		{
			sleep 4;
			hint "";
		};

        //find backpack index
        private _counts  = _cargo2 #1;
        private _newCount = (_counts #_idx2) - 1;
        private _classToRemove = _classes2 #_idx2;

        //clear all backpacks
        clearMagazineCargoGlobal _veh;

        //re-add backpacks except the one removed
        for "_idx2" from 0 to ((count _classes2) - 1) do {
            private _class = _classes2 #_idx2;
            private _count = _counts #_idx2;

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
	private _classes = _cargo #0;		//0 is classes, 1 is amount
	private _idx = _classes findIf {(_x in _validFPVs)};

	if (_idx > -1) exitWith {

		private _classBag = (_classes #_idx);
		private _stringSplit = _classBag splitString "_";
		private _stringCountNew = (count _stringSplit) - 1;

		_stringSplit deleteAt _stringCountNew;
		private _classFPV = _stringSplit joinString "_";

		//systemchat _classFPV;
		systemchat "sending FPV, wait";

		//find backpack index
		private _counts  = _cargo #1;
		private _newCount = (_counts #_idx) - 1;
		private _classToRemove = _classes #_idx;

		//clear all backpacks
		clearBackpackCargoGlobal _veh;

		//re-add backpacks except the one removed
		for "_idx" from 0 to ((count _classes) - 1) do {
			private _class = _classes #_idx;
			private _count = _counts #_idx;

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
	private _classes = _cargo #0;		//0 is classes, 1 is amount
	private _idx = _classes findIf {(_x in ["Crocus_MP_Throw", "Crocus_MP_Sens_Throw", "Crocus_MP_NV_Throw", "Crocus_MP_NV_Sens_Throw", "Crocus_MP_TI_Throw", "Crocus_MP_TI_Sens_Throw", "Crocus_PvP_Throw", "Crocus_Training_Throw"])};

	if (_idx > -1) exitWith {

		private _classThrowable = (_classes #_idx);
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
		private _counts  = _cargo #1;
		private _newCount = (_counts #_idx) - 1;
		private _classToRemove = _classes #_idx;

		//clear all backpacks
		clearMagazineCargoGlobal _veh;

		//re-add backpacks except the one removed
		for "_idx" from 0 to ((count _classes) - 1) do {
			private _class = _classes #_idx;
			private _count = _counts #_idx;

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