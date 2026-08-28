/*
	Author: Ascent & Nightware

	Description:
	Allows requesting of FPV, if systems operator glasses are equipped.
*/


fnc_RC_FPV_Request_findDeployers = {

	params ['_flyToPos','_sidePlayer'];

	scopeName "RC_FPV_Request_SearchScope";


	//request from dedicated deployer vehicle
	private _validDeployerMags = ["RC_1Rnd_Crocus_Deployer_Mag", "RC_1Rnd_Crocus_Deployer_UGV_Mag"];
	//array cleanup
	RC_FPV_Deployers = RC_FPV_Deployers select {!isNull _x && alive _x};
	//array sort by distance2D
	RC_FPV_Deployers = RC_FPV_Deployers apply {[round (_x distance2D _flyToPos), _x]};
	RC_FPV_Deployers sort true;
	RC_FPV_Deployers = RC_FPV_Deployers apply {_x#1};


	if (count RC_FPV_Deployers > 0) then {
		{
			private _veh = _x;
			
			//if ((_veh distance2D player) <= 15000) then {
				if ((count (crew _veh)) > 0) then {
					if (side _veh isEqualTo _sidePlayer) then {
						
						{
							_x params ["_magClass", "_turretPath", "_ammo"];

							if ((_magClass in _validDeployerMags) && (_ammo > 0)) then {
								{
									if (_magClass in (getArray (configFile >> "CfgWeapons" >> _x >> "magazines"))) exitWith {

										//output, vehicle & weapon
										[_veh, _x]

										breakOut "RC_FPV_Request_SearchScope";
									};
								} forEach (_veh weaponsTurret _turretPath);
							};
						} forEach (magazinesAllTurrets _veh);
					};
				};
			//};
		} forEach RC_FPV_Deployers;
	};

	//backup output for the variable become any empty array instead of nothing, breaks without
	[]
};



fnc_RC_FPV_Request_validifyVehicles = {

	params ['_flyToPos', '_sidePlayer'];


	private _allVeh = vehicles;
	private _validVeh = [];
	{
		private _veh = _x;

		if (!isNull _veh) then {
			//if ((_veh distance2D player <= 15000)) then {
				if ((count (crew _veh)) > 0) then {
					if (!([side _veh, _sidePlayer] call BIS_fnc_sideIsEnemy)) then {
						if (side _veh != civilian) then {
							_validVeh pushBack _veh;
						};
					};
				} else {
					//checks which side last opened the container to reprogram the fpv's, defaults to _sidePlayer if none is set, CONCIDER MAKING UNOPENED CRATES NON ACCESSABLE
					if (_veh getVariable ["RC_FPV_ContainerSide", _sidePlayer] == _sidePlayer) then {
						_validVeh pushBack _veh;
					};
				};
			//};
		};
	} forEach _allVeh;

	/*
	//sort by distance
	_validVeh = _validVeh apply {[_x distance2D _flyToPos, _x]};
	_validVeh sort true;
	//select only the vehicles
	_validVeh = _validVeh apply {_x #1};
	*/

	//sort by distance
	_validVeh = [_validVeh, [], {_x distance2D _flyToPos}, "ASCEND"] call BIS_fnc_sortBy;

	//output
	_validVeh
};


fnc_RC_checkAbove = {
	
	params ['_veh'];

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

	//output
	_hasAbove
};


fnc_RC_FPV_Request_checkCargo = {

	params ['_validVeh'];

	//neutral side bags & throwables, CONCIDER MAKING UNOPENED CRATES NON ACCESSABLE for MP
	private _validBags = ["Crocus_MP_Bag", "Crocus_MP_Sens_Bag", "Crocus_MP_NV_Bag", "Crocus_MP_NV_Sens_Bag", "Crocus_MP_TI_Bag", "Crocus_MP_TI_Sens_Bag", "Crocus_PvP_Bag", "Crocus_Training_Bag"];
	private _validMags = ["Crocus_MP_Throw", "Crocus_MP_Sens_Throw", "Crocus_MP_NV_Throw", "Crocus_MP_NV_Sens_Throw", "Crocus_MP_TI_Throw", "Crocus_MP_TI_Sens_Throw", "Crocus_PvP_Throw", "Crocus_Training_Throw"];
	
	
	//forEach _validVeh;
	{
		private _veh = _x;

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
			private _hasAbove = [_veh] call fnc_RC_checkAbove;

			if (_hasAbove) then {

				private _dir = str (round (player getDir _veh));
				private _dist = str (round (player distance _veh));
				//private _posY = str (round(_pos #0));
				//private _posX = str (round(_pos #1));
				private _grid = mapGridPosition _veh;
				private _gridX = _grid select [0, 3];
				private _gridY = _grid select [3, 3];

				systemchat "FPV request failed, obstructed above, cannot start.";
				//systemchat (_dir + "°  " + _dist + "m  y" + _posY + "  x" + _posX);
				systemchat (_dir + "°  " + _dist + "m  x" + _gridX + "  x" + _gridY);

				_continue = false;
			};
		};


		if (_idx > -1 && _continue) exitWith {

			private _classBag = (_classes #_idx);
			private _stringSplit = _classBag splitString "_";
			private _stringCountNew = (count _stringSplit) - 1;

			_stringSplit deleteAt _stringCountNew;
			private _uavClass = _stringSplit joinString "_";

			//output
			[_veh, 1, _uavClass, _cargo, _idx]
		};


		if (_idx2 > -1 && _continue) exitWith {

			private _classThrowable = (_classes2 #_idx2);
			private _stringSplit = _classThrowable splitString "_";
			private _stringCountNew = (count _stringSplit) - 1;

			_stringSplit deleteAt _stringCountNew;
			private _uavClass = _stringSplit joinString "_";

			//output
			[_veh, 2, _uavClass, _cargo2, _idx2]
		};

		//backup output for the variable become any empty array instead of nothing, breaks without
		[]	
	} forEach _validVeh;
};


/*
fnc_RC_FPV_Request_deployShot = {

	params ["_veh", "_weapon"];
	if (isNull _veh) exitWith {};
	if (_weapon isNotEqualTo "RC_Crocus_Deployer") exitWith {};


	private _flyToPos = getPosASL player;
	private _pos = getPos _veh;
	private _spawnPos = +_pos;
	private _posZ = _pos #2;
	private _isAir = _veh isKindOf "Air";
	if (_isAir) then 
	{
		//currently aimed at pos
		_flyToPos = screenToWorld [0.5, 0.5];
		//to prevent accidental trigger when trying to use laser designator, how is its locality? what about camless?
		//_veh selectWeaponTurret ["Laserdesignator_mounted", [0]];
		//if ((_pos select 2) > 1000) then {_posZ = 1000;
		if (_posZ > 15) then {
			_posZ = _posZ - 3;
		} else {
			_posZ = _posZ + 3;
		};
	} else {
		_posZ = _posZ + 5;
	};
	_spawnPos set [2, _posZ];


	_uavClass = "Crocus_MP_TI_Sens";
	if ((typeOf _veh) find "PvP" > -1) then {
		_uavClass = "Crocus_PvP";
	};
	private _uavArray = [[0,0,200], direction _veh, _uavClass, side _veh];


	[_veh, _uavArray, _spawnPos, _flyToPos, _weapon] spawn {
		params ["_veh", "_uavArray", "_spawnPos", "_flyToPos", "_weapon"];

		sleep 0.2;
		_uavSpawn = _uavArray call BIS_fnc_spawnVehicle;
		private _uav = _uavSpawn #0;
		//needs to be manually set, otherwise 50m minimum
		_uav setPos _spawnPos;
		sleep 1;


		player connectTerminalToUAV _uav;
		[_uav] call RC_fnc_RC_uavChangeLocality;
		//SOP height if no C-UAS in the area, after changeLocality due to it being local command global effect
		_uav flyInHeight 200;
		_flyToPos set [2, 200];
    	(group _uav) addWaypoint [_flyToPos, 3, -1, ""];


		sleep 0.3;
		player action ["UAVTerminalOpen", player];
	};
};
*/


/*
private _array = [getPos _this, direction _this, "RC_Crocus_Carrier_A", west];
[_array, BIS_fnc_spawnVehicle] remoteExec ["call", 2];
[_array] remoteExec ["BIS_fnc_spawnVehicle", 2];

[_this, RC_fnc_RC_uavChangeLocality] remoteExec ["call", 2];
[_this] remoteExec ["RC_fnc_RC_uavChangeLocality", 2];
*/


fnc_RC_FPV_Request_deployFromDeployer = {

	params ["_veh", "_flyToPos", "_weapon"];
	if (isNull _veh) exitWith {};

	//how to insert flyToPos WP to fired fpv?
	//per setvariable on fired would work, veh getvariable returning last deployed uv
	
	[_veh, _weapon] spawn {
		params ["_veh", "_weapon"];

		//fire only works where local and crocus deployer fired eventhandler is gated for local only
		if (local _veh) then {
			_veh fire _weapon;
		} else {
			[_veh] call RC_fnc_RC_uavChangeLocality;
			sleep 1;
			_veh fire _weapon;
		};
		
		hint format [
			"sending FPV from:\n%1\n%2° %3m\ny%4 x%5",
			(getText (configFile >> "CfgVehicles" >> typeOf _veh >> "displayName")),
			round (player getDir _veh),
			round (player distance _veh), 
			round ((getPos _veh) #0), 
			round ((getPos _veh) #1)
		];
		sleep 3;
		hint "";
	};
};



fnc_RC_FPV_Request_deployFromCargo = {

	params ["_veh", "_sidePlayer", "_flyToPos", "_kind", "_uavClass", "_cargo", "_idx"];
	if (isNull _veh) exitWith {};


	//find backpack / mag index
	private _classes = _cargo #0;
	private _counts  = _cargo #1;
	private _newCount = (_counts #_idx) - 1;
	private _classToRemove = _classes #_idx;	//isnt that doubled by _class = _classes #_idx2?
	//1 = backpack, 2 = mag (throwable)
	if (_kind == 1) then {
		
		//clear & re-add all backpacks except the one removed
		clearBackpackCargoGlobal _veh;
		for "_idx" from 0 to ((count _classes) - 1) do {
			private _class = _classes #_idx;
			private _count = _counts #_idx;

			if (_class == _classToRemove) then {
				//avoiding negative numbers
				_count = _newCount max 0;
			};

			if (_count > 0) then {
				_veh addBackpackCargoGlobal [_class, _count];
			};
		};
	} else {
		//clear & re-add all mags except the one removed
		clearMagazineCargoGlobal _veh;
		for "_idx" from 0 to ((count _classes) - 1) do {
			private _class = _classes #_idx;
			private _count = _counts #_idx;

			if (_class == _classToRemove) then {
				//avoiding negative numbers
				_count = _newCount max 0;
			};

			if (_count > 0) then {
				_veh addMagazineCargoGlobal [_class, _count];
			};
		};
	};


	private _pos = getPos _veh;
	hint format [
		"sending FPV from:\n%1\n%2° %3m\ny%4 x%5",
		(getText (configFile >> "CfgVehicles" >> typeOf _veh >> "displayName")),
		round (player getDir _veh),
		round (player distance _veh), 
		round (_pos #0), 
		round (_pos #1)
	];
	sleep 4.1;


	_pos = getPos _veh;
	private _spawnPos = +_pos;
	_posZ = (_pos #2) + 5;
	_spawnPos set [2, _posZ];
	private _uavArray = [[0,0,200], direction _veh, _uavClass, _sidePlayer];
	_uavSpawn = _uavArray call BIS_fnc_spawnVehicle;
	private _uav = _uavSpawn #0;
	//needs to be manually set, otherwise 50m minimum
	_uav setPos _spawnPos;
	sleep 0.2;


	player connectTerminalToUAV _uav;
	[_uav] call RC_fnc_RC_uavChangeLocality;
	//SOP height if no C-UAS in the area, after changeLocality due to it being local command global effect
	_uav flyInHeight 200;
	_flyToPos set [2, 200];
	(group _uav) addWaypoint [_flyToPos, 3, -1, ""];
	sleep 0.2;


	player action ["UAVTerminalOpen", player];
	hint "";
};



fnc_RC_FPV_Request_Search = {

	params ['_flyToPos', '_sidePlayer'];

	//search for nearest fpv deployers with ammo, output [_veh, _weapon]
	private _deployerArr = [_flyToPos, _sidePlayer] call fnc_RC_FPV_Request_findDeployers;
	
	//search for valid vehicles sorted by distance, output [_veh1, _veh2, ...]
	private _validVehicles = [_flyToPos, _sidePlayer] call fnc_RC_FPV_Request_validifyVehicles;

	private _cargoArr = [];
	if (count _validVehicles > 0) then {
		//search for nearest fpv in cargo, output [_veh, _kind, _uavClass, _cargo, _idx];
		_cargoArr = [_validVehicles] call fnc_RC_FPV_Request_checkCargo;
	};

	//checks output
	private _vehDeployer = if (count _deployerArr > 0) then { _deployerArr #0 } else { objNull };
	private _vehCargo = if (count _cargoArr > 0) then { _cargoArr #0 } else { objNull };


	//chooses closest existing one
	if (isNull _vehDeployer && isNull _vehCargo) then {

		hint "no FPV's found";
		0 spawn {
			sleep 3;
			hint "";
		};

	} else {

		private _fromDeployer = false;
		if (!isNull _vehDeployer && !isNull _vehCargo) then {
			//checks which is closer
			_fromDeployer = _vehDeployer distance2D _flyToPos <= _vehCargo distance2D _flyToPos;
		} else {
			_fromDeployer = !isNull _vehDeployer;
		};


		if (_fromDeployer) then {
			
			_deployerArr params ["_veh", "_weapon"];
			[_veh, _flyToPos, _weapon] spawn fnc_RC_FPV_Request_deployFromDeployer;

			if (visibleMap) then {
				private _map = findDisplay 12 displayCtrl 51;
				_map ctrlMapAnimAdd [0.2, 0.1, getPosASL _veh];
				ctrlMapAnimCommit _map;
			};
		} else {
			_cargoArr params ["_veh", "_kind", "_uavClass", "_cargo", "_idx"];
			[_veh, _sidePlayer, _flyToPos, _kind, _uavClass, _cargo, _idx] spawn fnc_RC_FPV_Request_deployFromCargo;

			if (visibleMap) then {
				private _map = findDisplay 12 displayCtrl 51;
				_map ctrlMapAnimAdd [0.2, 0.1, getPosASL _veh];
				ctrlMapAnimCommit _map;
			};
		};
	};
};


/*
fnc_RC_FPV_Request_Action = {

	params ['_player'];

	private _sidePlayer = side player;

	if (visibleMap) then {
		//[_player, _sidePlayer] call fnc_RC_FPV_Request_SelectMapPos;
		[_flyToPos, _sidePlayer] call fnc_RC_FPV_Request_Search;
	} else {
		[getPosATL player, _sidePlayer] call fnc_RC_FPV_Request_Search;
	};
};
*/


fnc_RC_FPV_Request_Action = {

	params ['_player'];

	if (visibleMap) then {
		
		private _mapDisplay = findDisplay 12;
		if (isNull _mapDisplay) exitWith {};
		private _mapCtrl = _mapDisplay displayCtrl 51;


		hint "LMB on map position to request FPV.\nClose map to cancel.";
		createMarkerLocal ["fpv_preview", [0,0,0], 1];
		"fpv_preview" setMarkerShapeLocal "ICON";
		"fpv_preview" setMarkerTypeLocal "mil_destroy";
		"fpv_preview" setMarkerColorLocal "ColorRed";
		"fpv_preview" setMarkerTextLocal "request FPV";


		uiNamespace setVariable ["RC_FPV_cleanup", {
			private _mEH = uiNamespace getVariable ["RC_FPV_moveEH", -1];
			private _cEH = uiNamespace getVariable ["RC_FPV_clickEH", -1];
			private _ctrl = uiNamespace getVariable ["RC_FPV_ctrl", controlNull];

			if (!isNull _ctrl) then {
				if (_mEH != -1) then { _ctrl ctrlRemoveEventHandler ["MouseMoving", _mEH] };
				if (_cEH != -1) then { _ctrl ctrlRemoveEventHandler ["MouseButtonDown", _cEH] };
			};
			deleteMarkerLocal "fpv_preview";
			hint "";

			uiNamespace setVariable ["RC_FPV_moveEH", -1];
			uiNamespace setVariable ["RC_FPV_clickEH", -1];
		}];
		uiNamespace setVariable ["RC_FPV_ctrl", _mapCtrl];


		private _moveEH = _mapCtrl ctrlAddEventHandler ["MouseMoving", {
			params ["_control", "_xPos", "_yPos"];
			"fpv_preview" setMarkerPosLocal (_control ctrlMapScreenToWorld [_xPos, _yPos]);
		}];
		uiNamespace setVariable ["RC_FPV_moveEH", _moveEH];


		private _clickEH = _mapCtrl ctrlAddEventHandler ["MouseButtonDown", {
			params ["_control", "_button", "_xPos", "_yPos"];
			if (_button != 0) exitWith {};

			private _flyToPos = _control ctrlMapScreenToWorld [_xPos, _yPos];
			call (uiNamespace getVariable "RC_FPV_cleanup");

			RC_FPV_FlyToPos = _flyToPos;
			[_flyToPos, side player] call fnc_RC_FPV_Request_Search;
		}];
		uiNamespace setVariable ["RC_FPV_clickEH", _clickEH];


		/*_mapDisplay displayAddEventHandler ["Unload", {
			systemChat "UNLOAD FIRED";
			call (uiNamespace getVariable "RC_FPV_cleanup");
		}];*/
		[] spawn {
			waitUntil { sleep 0.1; !visibleMap };
			call (uiNamespace getVariable "RC_FPV_cleanup");
		};
		
	} else {

		private _flyToPos = getPosATL player;
		RC_FPV_FlyToPos = _flyToPos;
		[_flyToPos, side player] call fnc_RC_FPV_Request_Search;
	};
};