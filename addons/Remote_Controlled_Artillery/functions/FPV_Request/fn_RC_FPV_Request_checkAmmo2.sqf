fnc_RC_FPV_Request_checkAmmo = {

	params ['_veh', '_flyToPos', '_sidePlayer', '_validDeployerMags'];

	{
		_x params ["_magClass", "_turretPath", "_ammo"];

		if ((_magClass in _validDeployerMags) && (_ammo > 0)) then {
			{
				if (_magClass in (getArray (configFile >> "CfgWeapons" >> _x >> "magazines"))) exitWith {
					
					//output
					[_veh, _weapon]

					private _weapon = _x;
					
					//_veh ammo _muzzle;	//getammo check, use for debug
					/*
						private _ammo = _veh ammo "RC_Crocus_Deployer";
						private _ammoStr = str _ammo;
						systemchat _ammoStr;
					*/
					
					//not suitable for mags with multiple rounds
					_veh setAmmo [_weapon, 0];
					//more suitable for mags with multiple rounds
					//_veh setAmmo [_weapon, ((_ammo - 1) max 0)];
					//doesnt work
					//_veh removeMagazine [_magClassname, _turretPath];
					[_veh, _weapon] call RC_fnc_RC_FPV_Request_VehDeploy;
					//RC_FPV_FinalArr = [_veh, round (_veh distance2D _flyToPos), _sidePlayer, _weapon, _sleep];


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


	/*
	//misses values
	{
		_x params ["_magClassname", "_ammoCount", "_weaponClassname", "_turretPath"];

		if (_weaponClassname isEqualTo _weapon) then {

			_veh removeMagazine [_magClassname, _turretPath];


			private _weapon = _x;
			//_veh setAmmo [_weapon, (_ammo - 1 max 0)];
			_veh setAmmo [_weapon, 0];
			[_veh, _weapon] call RC_fnc_RC_FPV_Request_VehDeploy;
			//RC_FPV_FinalArr = [_veh, round (_veh distance2D _flyToPos), _sidePlayer, _weapon, _sleep];


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
	} forEach (magazinesAllTurrets _veh);
	*/