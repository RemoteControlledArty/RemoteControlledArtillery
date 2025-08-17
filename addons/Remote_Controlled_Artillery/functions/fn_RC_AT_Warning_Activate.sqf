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
				[['\A3\Sounds_F\vehicles\air\noises\alarm_locked_by_missile_1.wss', 0.3]] remoteExec ['playSoundUI', _crew];


				//checks if launcher visible
				private _sourceVisible = ([_source, 'GEOM', _vic] checkVisibility [eyePos _source, eyePos _vic]) > 0;
				if (_sourceVisible) then {

					//if visible datalinks launcher
					if (RC_AT_SourceIndicationStatic && RC_AT_SourceIndicationInf && RC_AT_SourceIndicationVic) then {
						if ((_vic distance _source) < 4000) then {
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


				//warning message with information
				private _ammoType = getText (configFile >> "CfgAmmo" >> typeOf _proj >> "simulation");
				private _magName = getText (configFile >> "CfgMagazines" >> _mag >> "displayName");


				// Projectile direction vector (normalized velocity)
				private _dirProj = vectorNormalized velocity _proj;
				// Reverse it (points back toward the shooter)
				private _dirSource = _dirProj vectorMultiply -1;
				// Construct a "fake shooter position" along that reverse vector (arbitrary distance, e.g. 1000m back)
				private _fakeSourcePos = (getPosASL _proj) vectorAdd (_dirSource vectorMultiply 4000);


				private _string = "missile detected: " + _magName;
				if (_ammoType isEqualTo "shotRocket") then {
					_string = "rocket detected: " + _magName;
					_fakeSourcePos = (getPosASL _proj) vectorAdd (_dirSource vectorMultiply 1000);
				};

				// Bearing from vehicle to that fake shooter position
				private _maxSourceBearing = round (_vic getRelDir _fakeSourcePos);
				private _bearing =  round (_vic getRelDir _projFirstPos);

				if (_sourceVisible) then {
					if (_source isKindOf 'Man') then {
						_string = _string + ",  launcher: infantry";
					} else {
						private _sourceType = getText (configFile >> "CfgVehicles" >> typeOf _source >> "displayName");
						_string = _string + ",  launcher: " + _sourceType;
					};
					_string = _string + ",  bearing: " + str _bearing;
				} else {
					_string = _string + ",  launcher: not detected";
					_string = _string + ",  bearing: " + str _bearing + " - " + str _maxSourceBearing;
				};

				[_string] remoteExec ["systemChat", _crew];

				breakOut "DetectProjectile";
			};
		};

		sleep 0.01;
	};
};