/*
	Author: Ascent

	Description:
	If line of sight: Warning sound for any hostile AT, marks source of fire briefly in datalink.
*/

params ["_vic", "_source", "_proj", "_mag"];

[_vic, _source, _proj, _mag] spawn
{
	params ["_vic", "_source", "_proj", "_mag"];

	scopeName "DetectProjectile";
	while {alive _vic && alive _proj} do {
		
		if ((_vic distance _proj) < 4000) then {

			if ((([_proj, 'GEOM', _vic] checkVisibility [getPosASL _proj, eyePos _vic]) > 0)) exitwith {

				private _projFirstPos = getPosASL _proj;
				private _vicPos = getPosASL _vic;
				private _distNow = _projFirstPos distance _vicPos;
				private _distSource = _source distance _vicPos;

				//warning beeb as soon as projectile is detectable
				private _crew = (crew _vic) select {isPlayer _x};
				private _controllers = (UAVControl _vic);
				private _controller1 = _controllers select 0;

				if (_controller1 isNotEqualTo objNull) then {
					_crew pushBack _controller1;

					if (count _controllers > 2) then {
						_crew pushBack (_controllers select 2);
					};
				};

				private _tresh = 30;	//meters to side concidered rocket/missile is not aimed at vic, 30m as it includes lead moving >100kmh
    			private _projDir = getDir _proj;
				private _relDir = ([_proj, _vic] call BIS_fnc_dirTo);
				private _dist = _proj distance2D _vic;
				private _dirDif = abs (_projDir - _relDir);
				if (_dirDif > 180) then {_dirDif = 360 - _dirDif;};
				private _distPass = _dist * tan(_dirDif);

				if (_distPass < _tresh) then {
					[['\A3\Sounds_F\vehicles\air\noises\alarm_locked_by_missile_1.wss', 0.3]] remoteExec ['playSoundUI', _crew];
				} else {
					[['\A3\Sounds_F\vehicles\air\noises\alarm_locked_by_missile_2.wss', 0.2, 0.9]] remoteExec ['playSoundUI', _crew];
				};


				//checks if launcher visible
				private _sourceVisible = ([_source, 'GEOM', _vic] checkVisibility [eyePos _source, eyePos _vic]) > 0;
				if (_sourceVisible) then {

					//if visible datalinks launcher
					if (RC_AT_SourceIndicationStatic && RC_AT_SourceIndicationInf && RC_AT_SourceIndicationVic) then {
						if ((_distSource) < 4000) then {
							private _side = side _vic;
							if (_source isKindOf 'StaticWeapon' && RC_AT_SourceIndicationStatic) then {
								[_side, [_source, 300]] remoteExec ['reportRemoteTarget', _side];
								[_source, [_side, true]] remoteExec ['confirmSensorTarget', _side];
							} else {
								if (_source isKindOf 'Man' && RC_AT_SourceIndicationInf) then {
									[_side, [_source, 10]] remoteExec ['reportRemoteTarget', _side];
									[_source, [_side, true]] remoteExec ['confirmSensorTarget', _side];
								} else {
									if (RC_AT_SourceIndicationVic) then {
										[_side, [_source, 20]] remoteExec ['reportRemoteTarget', _side];
										[_source, [_side, true]] remoteExec ['confirmSensorTarget', _side];
									};
								};
							};
						};
					};
				};


				//turns turret to where the projectile was first detected
				private _turretPath = getArray (configFile >> "CfgVehicles" >> typeOf _vic >> "RC_ATrespondingTurret");

				if (_turretPath isNotEqualTo []) then {

					private _responder = _vic turretUnit _turretPath;

					if (_responder isNotEqualTo objNull) then {
						
						private _posSource = _projFirstPos;
						if (_sourceVisible) then {
							_posSource = eyePos _source;
							_responder doTarget _source;
						};

						[_vic, _posSource, _turretPath] remoteExec ['RC_fnc_RC_AT_TurretOwner', 2];
					};
				};


				//only runs if player inside / connected per terminal
				if ((count _crew) > 0) then {
					//warning message with information
					private _ammoType = getText (configFile >> "CfgAmmo" >> typeOf _proj >> "simulation");
					private _magName = getText (configFile >> "CfgMagazines" >> _mag >> "displayName");

					// missile direction vector (normalized velocity)
					private _dirProj = vectorNormalized velocity _proj;
					// Reverse it (points back toward the shooter)
					private _dirSource = _dirProj vectorMultiply -1;
					// Construct a "fake shooter position" along that reverse vector (arbitrary distance, e.g. 1000m back)
					private _fakeMissileSourcePos = _projFirstPos vectorAdd (_dirSource vectorMultiply 4000);
					private _maxSourceBearing = round ([_vic, _fakeMissileSourcePos] call BIS_fnc_dirTo);
					//_stringMissile = "missile: " + str _maxSourceBearing;
					//[_stringMissile] remoteExec ["systemChat", _crew];

					
					private _stringPrj = "missile: " + _magName;
					if (_ammoType isEqualTo "shotRocket") then {
						_stringPrj = "rocket: " + _magName;

						//Estimate launcher bearing & distance
						private _projVel = velocity _proj;
						private _projSpeed = vectorMagnitude _projVel;
						// assume initial speed ~30% higher than current
						private _estInitSpeed = _projSpeed * 1.3;

						// rough guess: how far back along trajectory it started
						// time since fired (guess) = currentDistance / avgSpeed
						private _avgSpeed = (_projSpeed + _estInitSpeed) / 2;
						private _timeGuess = _distNow / _avgSpeed;

						// project backwards along velocity vector
						private _estLaunchPos = _projFirstPos vectorDiff (_projVel vectorMultiply _timeGuess);
						// bearing from vic to guessed launch pos
						_maxSourceBearing = round ([_vic, _estLaunchPos] call BIS_fnc_dirTo);

						//_stringRocket = "rocket: " + str _maxSourceBearing;
						//[_stringRocket] remoteExec ["systemChat", _crew];
					};

					//bearing of first detected projectile pos
					private _bearing =  round ([_vic, _projFirstPos] call BIS_fnc_dirTo);

					private _stringSource = "launcher: ";
					if (_sourceVisible) then {
						if (_source isKindOf 'Man') then {
							_stringSource = _stringSource + "infantry";
						} else {
							private _sourceType = getText (configFile >> "CfgVehicles" >> typeOf _source >> "displayName");
							_stringSource = _stringSource + _sourceType;
						};
						_stringSource = _stringSource + ",  " + str (round _distSource) + "m,  " + str _bearing + "°";
					} else {
						_stringSource = _stringSource + "not detected";
						_stringSource = _stringSource + ",  " + str _bearing + "° - " + str _maxSourceBearing + "°";

						_stringPrj = _stringPrj + ",  " + str (round _distNow) + "m";
					};

					[_stringPrj] remoteExec ["systemChat", _crew];
					[_stringSource] remoteExec ["systemChat", _crew];
				};

				breakOut "DetectProjectile";
			};
		};

		sleep 0.01;
	};
};




/*
private _projFirstPos = getPosASL _proj;

//warning message with information
private _ammoType = getText (configFile >> "CfgAmmo" >> typeOf _proj >> "simulation");
private _magName = getText (configFile >> "CfgMagazines" >> _mag >> "displayName");

// missile direction vector (normalized velocity)
private _dirProj = vectorNormalized velocity _proj;
// Reverse it (points back toward the shooter)
private _dirSource = _dirProj vectorMultiply -1;
// Construct a "fake shooter position" along that reverse vector (arbitrary distance, e.g. 1000m back)
private _fakeSourcePos = (getPosASL _proj) vectorAdd (_dirSource vectorMultiply 4000);
private _maxSourceBearing = round ([_vic, _fakeSourcePos] call BIS_fnc_dirTo)


if (_ammoType isEqualTo "shotRocket") then {

	//_fakeSourcePos = (getPosASL _proj) vectorAdd (_dirSource vectorMultiply 1000);

	//Estimate launcher bearing & distance
	private _projVel = velocity _proj;
	private _projSpeed = vectorMagnitude _projVel;
	// assume initial speed ~30% higher than current
	private _estInitSpeed = _projSpeed * 1.3;

	// rough guess: how far back along trajectory it started
	// time since fired (guess) = currentDistance / avgSpeed
	private _distNow = _projFirstPos distance (getPosASL _vic);
	private _avgSpeed = (_projSpeed + _estInitSpeed) / 2;
	private _timeGuess = _distNow / _avgSpeed;

	// project backwards along velocity vector
	private _estLaunchPos = _projFirstPos vectorDiff (_projVel vectorMultiply _timeGuess);
	// bearing from vic to guessed launch pos
	private _maxSourceBearing = round ([_vic, _estLaunchPos] call BIS_fnc_dirTo);
};
*/