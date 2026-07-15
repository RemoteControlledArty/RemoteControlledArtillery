/*
	Author: Ascent & Nightware

	Description:
	Allows requesting of FPV, if systems operator glasses are equipped.
*/
	

fnc_RC_FPV_Request_Search = {

	params ['_player'];


	/*
	private _flyToPos = [0,0,0];
	if (visibleMap) then {

		//???
	} else {
		_flyToPos = getPosATL player;
	};
	*/


	private _flyToPos = getPosATL player;
	private _sidePlayer = side player;


	//search for nearest fpv deployers with ammo
	scopeName "RC_FPV_Request_SearchScope";
	[_flyToPos, _sidePlayer] call fnc_RC_FPV_Request_findDeployers;


	//search for nearest fpv in cargo
	private _validVeh = [_flyToPos, _sidePlayer] call fnc_RC_FPV_Request_validifyVehicles;
	[_flyToPos, _sidePlayer, _validVeh] call fnc_RC_FPV_Request_checkCargo;
};




/*
fnc_RC_FPV_Request_Search2 = {

	params ['_player'];


	private _flyToPos = getPosATL player;	//change for mapInteraction action
	private _sidePlayer = side player;


	//search for nearest fpv deployers with ammo
	private _deployerArr = [_flyToPos, _sidePlayer] call RC_fnc_RC_FPV_Request_findDeployers;
	//search for nearest fpv in cargo
	private _validVehicles = [_flyToPos, _sidePlayer] call RC_fnc_RC_FPV_Request_validifyVehicles;
	private _cargoArr = [_flyToPos, _sidePlayer, _validVehicles] call RC_fnc_RC_FPV_Request_checkCargo;


	private _vehA = if (count _deployerArr > 0) then { _deployerArr select 0 } else { objNull };
	private _vehB = if (count _cargoArr > 0) then { _cargoArr select 0 } else { objNull };


	private _nearest = objNull;
	if (!isNull _vehA && !isNull _vehB) then {
		_nearest = [_vehB, _vehA] select (_vehA distance _flyToPos <= _vehB distance _flyToPos);
	} else {
		_nearest = [_vehA, _vehB] select (isNull _vehA);
	};


	if (isNull _nearest) then {
		
		hint "no FPV's found";
		0 spawn
		{
			sleep 3;
			hint "";
		};
	} else {
		[_flyToPos, _sidePlayer] call RC_fnc_RC_FPV_Request_deploy;
	};
};
*/




fnc_RC_FPV_Request_findDeployers = {

	params ['_flyToPos','_sidePlayer'];

	//scopeName "RC_FPV_Request_SearchScope";


	//request from dedicated deployer vehicle
	private _validDeployerMags = ["RC_1Rnd_Crocus_Deployer_Mag", "RC_1Rnd_Crocus_Deployer_UGV_Mag"];
	//array cleanup
	RC_FPV_Deployers = RC_FPV_Deployers select {!isNull _x && alive _x};
	//array sort by distance2D
	RC_FPV_Deployers = RC_FPV_Deployers apply {[round (_x distance2D _flyToPos), _x]};
	RC_FPV_Deployers sort true;
	RC_FPV_Deployers = RC_FPV_Deployers apply {_x#1};
	//RC_FPV_FinalArr = [];


	if (count RC_FPV_Deployers > 0) then {
		{
			private _veh = _x;
			
			if ((_veh distance2D player) <= 15000) then {
				if ((count (crew _veh)) > 0) then {
					if (side _veh isEqualTo _sidePlayer) then {
						
						//atm fnc insteaf of RC_fnc
						[_veh, _flyToPos, _sidePlayer, _validDeployerMags] call fnc_RC_FPV_Request_checkAmmo;	//RC_
					};
				};
			};
		} forEach RC_FPV_Deployers;
	};
};




fnc_RC_FPV_Request_checkAmmo = {

	params ['_veh', '_flyToPos', '_sidePlayer', '_validDeployerMags'];

	{
		_x params ["_magClass", "_turretPath", "_ammo"];

		if ((_magClass in _validDeployerMags) && (_ammo > 0)) then {
			{
				if (_magClass in (getArray (configFile >> "CfgWeapons" >> _x >> "magazines"))) exitWith {

					private _weapon = _x;
					
					//doesnt work for mags with >1 ammo
					_veh setAmmo [_weapon, 0];
					//better for mags with >1 ammo, but atm bugs not always removing a mag
					//_veh setAmmo [_weapon, ((_ammo - 1) max 0)];
					[_veh, _weapon, _sidePlayer] call fnc_RC_FPV_Request_vehDeploy;	//RC_


					private _pos = getPosASL _veh;
					private _name = getText (configFile >> "CfgVehicles" >> typeOf _veh >> "displayName");
					hint format [
						"sending FPV from:\ny%1 x%2\n%3m\n%4",
						round (_pos #0),
						round (_pos #1),
						round (player distance _veh),
						_name
					];
					0 spawn
					{
						sleep 3;
						hint "";
					};


					breakOut "RC_FPV_Request_SearchScope";
				};
			} forEach (_veh weaponsTurret _turretPath);
		};
	} forEach (magazinesAllTurrets _veh);
};




fnc_RC_FPV_Request_validifyVehicles = {

	params ['_flyToPos', '_sidePlayer'];


	private _allVeh = vehicles;
	private _validVeh = [];
	{
		private _veh = _x;

		if (!isNull _veh) then {
			if ((_veh distance2D player <= 15000)) then {
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
			};
		};
	} forEach _allVeh;


	_validVeh = _validVeh apply {[round (_x distance2D _flyToPos), _x]};
	_validVeh sort true;

	//output
	_validVeh
};




fnc_RC_FPV_Request_checkCargo = {

	params ['_flyToPos', '_sidePlayer', '_validVeh'];


	//neutral side bags & throwables, CONCIDER MAKING UNOPENED CRATES NON ACCESSABLE for MP
	private _validBags = ["Crocus_MP_Bag", "Crocus_MP_Sens_Bag", "Crocus_MP_NV_Bag", "Crocus_MP_NV_Sens_Bag", "Crocus_MP_TI_Bag", "Crocus_MP_TI_Sens_Bag", "Crocus_PvP_Bag", "Crocus_Training_Bag"];
	private _validMags = ["Crocus_MP_Throw", "Crocus_MP_Sens_Throw", "Crocus_MP_NV_Throw", "Crocus_MP_NV_Sens_Throw", "Crocus_MP_TI_Throw", "Crocus_MP_TI_Sens_Throw", "Crocus_PvP_Throw", "Crocus_Training_Throw"];
	
	
	//forEach _validVeh;
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
		} else {
			hint "no FPV's found";
			0 spawn
			{
				sleep 3;
				hint "";
			};
		};


		/*
		if (_idx > -1 && _continue) exitWith {

			[_veh, _cargo, _classes, _idx]
		};
		*/
		

		if (_idx > -1 && _continue) exitWith {

			private _classBag = (_classes #_idx);
			private _stringSplit = _classBag splitString "_";
			private _stringCountNew = (count _stringSplit) - 1;

			_stringSplit deleteAt _stringCountNew;
			private _uavClass = _stringSplit joinString "_";

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
					//avoiding negative numbers
					_count = _newCount max 0;
				};

				if (_count > 0) then {
					_veh addBackpackCargoGlobal [_class, _count];
				};
			};

			[_veh, _uavClass, _sidePlayer] call fnc_RC_FPV_Request_Deploy;	//RC_
		};


		if (_idx2 > -1 && _continue) exitWith {

			private _classThrowable = (_classes2 #_idx2);
			private _stringSplit = _classThrowable splitString "_";
			private _stringCountNew = (count _stringSplit) - 1;

			_stringSplit deleteAt _stringCountNew;
			private _uavClass = _stringSplit joinString "_";

			/*
			switch (true) do {
				case(_sidePlayer == west): {
					_uavClass = "B_" + _uavClass;
				};
				case(_sidePlayer == east): {
					_uavClass = "O_" + _uavClass;
				};
				case(_sidePlayer == resistance): {
					_uavClass = "I_" + _uavClass;
				};
			};
			*/

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
					//avoiding negative numbers
					_count = _newCount max 0;
				};

				if (_count > 0) then {
					_veh addMagazineCargoGlobal [_class, _count];
				};
			};

			[_veh, _uavClass, _sidePlayer] call fnc_RC_FPV_Request_deploy;	//RC_
		};
	} forEach _validVeh;
};




fnc_RC_FPV_Request_deploy = {

	params ["_veh", "_uavClass", "_sidePlayer"];

	if (isNull _veh) exitWith {};

	private _pos = getPos _veh;
	private _posZ = (_pos select 2) + 7;
	private _spawnPos = +_pos;
	_spawnPos set [2, _posZ];

	private _uavArray = [_pos, direction _veh, _uavClass, _sidePlayer];

	[_uavArray, _spawnPos] spawn {
		params ["_uavArray", "_spawnPos"];

		sleep 3.7;
		private _uavSpawn = _uavArray call BIS_fnc_spawnVehicle;
		private _uavNew = _uavSpawn select 0;
		//needs to be manually set, otherwise 50m minimum
		_uavNew setPos _spawnPos;
		//SOP height if no C-UAS in the area
		_uavNew flyInHeight 200;

		player connectTerminalToUAV _uavNew;
		[_uavNew] call RC_fnc_RC_uavChangeLocality;

		sleep 0.3;
		player action ["UAVTerminalOpen", player];
		//driver _uavNew switchCamera "Internal";
		//player remoteControl driver _uavNew;
	};
};




fnc_RC_FPV_Request_vehDeploy = {

	params ["_veh", "_weapon", "_sidePlayer"];

	if (isNull _veh) exitWith {};
	if (_weapon isNotEqualTo "RC_Crocus_Deployer") exitWith {};
	private _isAir = _veh isKindOf "Air";


	private _pos = getPos _veh;
	private _spawnPos = +_pos;
	private _posZ = 200;
	if (_isAir) then 
	{
		//to prevent accidental trigger when trying to use laser designator, how is its locality?
		//_veh selectWeaponTurret ["Laserdesignator_mounted", [0]];

		if ((_pos select 2) > 1000) then {
			_posZ = 1000;
		} else {
			_posZ = (_pos select 2) - 15;	//somehow is min 50, doesnt bug into ground
		};
	} else {
		_posZ = (_pos select 2) + 7;
	};
	_spawnPos set [2, _posZ];	//fix to not be < AGL


	private _uavClass = "Crocus_MP_TI_Sens";
	if ((typeOf _veh) find "PvP" > -1) then {
		_uavClass = "Crocus_PvP";
	};
	private _uavSpawn = [_pos, direction _veh, _uavClass, _sidePlayer] call BIS_fnc_spawnVehicle;
	private _uavNew = _uavSpawn select 0;
	//needs to be manually set, otherwise 50m minimum
	_uavNew setPos _spawnPos;
	//SOP height if no C-UAS in the area
	_uavNew flyInHeight 200;


	[_uavNew] spawn {
		params ["_uavNew"];
		sleep 1;
		player connectTerminalToUAV _uavNew;
		[_uavNew] call RC_fnc_RC_uavChangeLocality;
		player action ["UAVTerminalOpen", player];
		//driver _uavNew switchCamera "Internal";
		//player remoteControl driver _uavNew;
	};
};