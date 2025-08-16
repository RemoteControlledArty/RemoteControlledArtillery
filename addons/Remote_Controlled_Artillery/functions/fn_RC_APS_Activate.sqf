/*
	Author: Ascent

	Description:
	APS
*/

params ["_vic", "_proj"];

//systemchat "APS start";

private _chargesAPS = {_x isEqualTo "RC_1Rnd_APS_M"} count (_vic magazinesTurret [-1]);

//systemchat "charges" + str _chargesAPS;

if (_chargesAPS > 0) then {

	//systemchat "_chargesAPS > 0";

	private _ammoType = getText (configFile >> "CfgAmmo" >> typeOf _proj >> "simulation");
	/*
	private _ingoreRockets = getNumber (configFile >> "CfgVehicles" >> typeOf _vic >> "RC_ignoreRockets");
	private _isRocket = _ammoType isEqualTo "shotRocket";
	if ((_ingoreRockets != 0) && _isRocket) exitwith {};
	*/

	//systemchat "before spawn";

	if (_ammoType isEqualTo "shotRocket") then {
		[_vic, _proj, _chargesAPS] spawn
		{
			params ["_vic", "_proj", "_chargesAPS"];

			scopeName "APS";
			while {alive _vic && alive _proj} do {
				private _projPos = getPosASL _proj;
				private _vicPos  = getPosASL _vic;
				private _dist = _projPos distance _vicPos;

				if (_dist < 120) then {

					private _projVel = velocity _proj;
					private _vicVel  = velocity _vic;
					private _projSpeed = vectorMagnitude _projVel;
					if (_projSpeed < 1) exitWith {};

					private _time = _dist / _projSpeed;
					private _vicFuture = [
						(_vicPos #0) + (_vicVel #0) * _time,
						(_vicPos #1) + (_vicVel #1) * _time,
						(_vicPos #2) + (_vicVel #2) * _time
					];
					private _projFuture = [
						(_projPos #0) + (_projVel #0) * _time,
						(_projPos #1) + (_projVel #1) * _time,
						(_projPos #2) + (_projVel #2) * _time
					];

					if ((_vicFuture distance _projFuture) < 7) exitWith {

						private _chargesAPS = {_x isEqualTo "RC_1Rnd_APS_M"} count (_vic magazinesTurret [-1]);

						if (_chargesAPS > 0) then {
							private _projPos = (getPosATL _proj);
							private _projDir = (getDir _proj);
							deleteVehicle _proj;

							playSound3D ["a3\sounds_f_mod\arsenal\weapons\smg\adr_97\adr_97_closeshot_01.wss", _vic, false, getPosASL _vic, 5, 0.8, 600];

							_expl = "RC_APS_Expl_Scripted" createVehicle _projPos;
							private _explDir = -_projDir;
							[_expl, _explDir] remoteExec ["setDir", 0];
							_expl setDamage 1;
							
							private _nextChargesAPS = 0 max (_chargesAPS - 1);
							_vic removeMagazineTurret ["RC_1Rnd_APS_M", [-1]];
							
							private _string = "activated APS, " + str _nextChargesAPS + " remaining";
							private _crew = (crew _vic) select {isPlayer _x};
							[_string] remoteExec ["systemChat", _crew];

							breakOut "APS";
						};
					};
				};
			};
		};
	} else {
		[_vic, _proj, _chargesAPS] spawn
		{
			params ["_vic", "_proj", "_chargesAPS"];

			scopeName "main";
			while {(alive _vic) and (alive _proj)} do
			{
				if ((_proj distance _vic) < 120) exitwith {

					//systemchat "<150m";

					private _chargesAPS = {_x isEqualTo "RC_1Rnd_APS_M"} count (_vic magazinesTurret [-1]);

					if (_chargesAPS > 0) then {
						private _projPos = (getPosATL _proj);
						private _projDir = (getDir _proj);
						deleteVehicle _proj;
						//[_proj] remoteExec ["deleteVehicle", 0];

						//systemchat "activated APS";

						playSound3D ["a3\sounds_f_mod\arsenal\weapons\smg\adr_97\adr_97_closeshot_01.wss", _vic, false, getPosASL _vic, 5, 0.8, 600];

						/*
						private _vicPos = (getPosASL _vic);
						//private _factor = 1 max ((_vicPos distance _projPos) / 50);		//choose distance
						//systemchat str _factor;
						
						/*
						//if bypassing vehicle suddenly get dragged closer, despite model being seen shortly before
						private _explPosASL = [
							(_vicPos #0 + _projPos #0) / 2,
							(_vicPos #1 + _projPos #1) / 2,
							(_vicPos #2 + _projPos #2) / 2
						];
						_explPosATL = ASLToATL _explPosASL;
						*/
						_expl = "RC_APS_Expl_Scripted" createVehicle _projPos;
						private _explDir = -_projDir;
						[_expl, _explDir] remoteExec ["setDir", 0];
						_expl setDamage 1;
						
						private _nextChargesAPS = 0 max (_chargesAPS - 1);
						_vic removeMagazineTurret ["RC_1Rnd_APS_M", [-1]];
						
						private _string = "activated APS, " + str _nextChargesAPS + " remaining";
						private _crew = (crew _vic) select {isPlayer _x};
						[_string] remoteExec ["systemChat", _crew];

						breakOut "APS";
					};
				};
			};
		};
	};
};



/*
params ["_vic", "_proj"];

// Count APS charges up front
private _chargesAPS = { _x isEqualTo "RC_1Rnd_APS_M" } count (_vic magazinesTurret [-1]);

if (_chargesAPS > 0) then {

    private _ignoreRockets = getNumber (configFile >> "CfgVehicles" >> typeOf _vic >> "RC_ignoreRockets");
    private _ammoType      = getText   (configFile >> "CfgAmmo"     >> typeOf _proj >> "simulation");

    // Skip if rocket should be ignored
    if ((_ignoreRockets != 0) && {_ammoType isEqualTo "shotRocket"}) exitWith {};

    // Register EachFrame handler
    addMissionEventHandler [
        "EachFrame",
        {
            params ["_args"];
            _args params ["_vic", "_proj"];

            // Bail if one of them is gone
            if (!alive _vic || {!alive _proj}) exitWith {
                removeMissionEventHandler ["EachFrame", _thisEventHandler];
            };

            // Check distance threshold
            if ((_proj distance _vic) < 150) exitWith {

                private _chargesAPS = { _x isEqualTo "RC_1Rnd_APS_M" } count (_vic magazinesTurret [-1]);

                if (_chargesAPS > 0) then {
                    private _projPos = getPosATL _proj;
                    deleteVehicle _proj;

                    playSound3D [
                        "a3\sounds_f_mod\arsenal\weapons\smg\adr_97\adr_97_closeshot_01.wss",
                        _vic, false, getPosASL _vic, 10, 0.8, 600
                    ];

                    private _vicPos = getPosATL _vic;
                    private _explPos = [
                        (_vicPos # 0 + _projPos # 0) / 2,
                        (_vicPos # 1 + _projPos # 1) / 2,
                        (_vicPos # 2 + _projPos # 2) / 2
                    ];
                    private _explosion = "ClaymoreDirectionalMine_Remote_Ammo_Scripted" createVehicle _explPos;
                    _explosion setDamage 1;

                    private _nextChargesAPS = 0 max (_chargesAPS - 1);
                    _vic removeMagazineTurret ["RC_1Rnd_APS_M", [-1]];

                    [_vic, format ["activated APS, %1 remaining", _nextChargesAPS]]
                        remoteExec ["vehicleChat", 0];
                };

                // Remove handler once action is taken
                removeMissionEventHandler ["EachFrame", _thisEventHandler];
            };
        },
        [_vic, _proj] // _thisArgs passed into EH
    ];
};
*/



/*
if (_ammoType isEqualTo "shotRocket") then {

	private _posProj = getPosASL _proj;
	private _velProj = velocity _proj;

	private _posVeh = getPosASL _vehicle;
	private _velVeh = velocity _vehicle;

	// Relative position & velocity
	private _relPos = _posProj vectorDiff _posVeh;
	private _relVel = _velProj vectorDiff _velVeh;

	// Time to closest approach
	private _tClosest = -((_relPos vectorDotProduct _relVel) / (_relVel vectorDotProduct _relVel));
	if (_tClosest <= 0) exitWith { false }; // Already passed or moving away

	// Predicted positions at closest point
	private _futureProj = _posProj vectorAdd (_velProj vectorMultiply _tClosest);
	private _futureVeh  = _posVeh vectorAdd (_velVeh vectorMultiply _tClosest);

	// Distance at closest point
	private _distClosest = _futureProj distance _futureVeh;

	// Vehicle size / hit radius
	private _hitRadius = 5; // adjust for vehicle model
	if (_distClosest > _hitRadius) exitWith { false }; // Will miss
};
*/



/*
private _dist = (_proj distance _vic);

if ((_dist < 500) && (_dist > 400)) then {
	private _mags = _vic magazinesTurret [-1];
	private _chargesAPS = {_x isEqualTo "RC_1Rnd_APS_M"} count _mags;

	if (((speed _proj) / 3.6) > 600) exitwith {};		//decide on max interception speed

	systemchat "<500m >400m";

	if (((_proj distance _vic) < 100) && (_chargesAPS > 0)) exitwith {
};

if ((_dist < 400) && (_dist > 100)) then {

	systemchat "<400m >100m";
};
*/


/*
private _dist = _proj distance _vic;
private _frameTime = diag_deltaTime;

private _hitNextFrame = false;
private _projSpeed = (speed _proj) / 3.6;

if (_projSpeed != 0) then {
	private _hitNextFrame = (_frameTime * 2) >= ((_dist + 100) / _projSpeed);
};

if (((_dist <= 100) or _hitNextFrame) && (_chargesAPS > 0)) exitwith {
*/