/*
	Author: Ascent

	Description:
	If line of sight: Warning sound for any hostile interceptor drone is launched, marks interceptor drone in datalink.
*/

params ["_vic", "_source", "_proj", "_mag"];

systemchat "activate";

[_vic, _source, _proj, _mag] spawn
{
	params ["_vic", "_source", "_proj", "_mag"];

	//wait to attach
	sleep 1;

	scopeName "DetectInterceptor";
	while {alive _vic && alive _proj} do {
		
		//if (((_vic distance _proj) < 4000) && ((attachedObjects _proj) isNotEqual [])) then {
		if ((_vic distance _proj) < 4000) then {

			systemchat "<4000m";

			if ((([_proj, 'GEOM', _vic] checkVisibility [getPosASL _proj, eyePos _vic]) > 0)) exitwith {
				
				private _target = (attachedObjects _proj)#0;

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
				
				private _side = side _vic;
				if (_target isKindOf 'Air') then {

					private _duration = getNumber (configFile >> "CfgAmmo" >> typeOf _proj >> "timeToLive");
					[_side, [_target, _duration]] remoteExec ['reportRemoteTarget', _side];
					[_target, [_side, true]] remoteExec ['confirmSensorTarget', _side];
				};

				//only runs if player inside / connected per terminal
				if ((count _crew) > 0) then {
					
					private _string = "detected: " + getText (configFile >> "CfgMagazines" >> _mag >> "displayName");
					[_string] remoteExec ["systemChat", _crew];
				};

				breakOut "DetectInterceptor";
			};
		};

		sleep 1;
	};
};