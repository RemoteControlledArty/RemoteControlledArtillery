/*
	Author: Fluffy & Ascent

	Description:
	Turns off engines of UGV's when halting.
*/

// Need to exit early if we aren't a client
if (!hasInterface) exitWith {};

RC_engineOffHash = createHashMap;

RC_EngineOff = [] spawn
{
	while {true} do
	{
		_uv = (getConnectedUAV player);

		// restart if no UV is connected
		if (_uv isEqualTo objNull) then {continue;};

		//engineOn only works where vehicle is local
		if (local _uv) then {

			// checks config value
			_uvClass = typeOf _uv;
			private _engineOff = RC_engineOffHash get _uvClass;
			if (isNil "_engineOff") then {
				_engineOff = getNumber (configFile >> "CfgVehicles" >> _uvClass >> "RCEngineOff");
				RC_engineOffHash set [_uvClass, _engineOff];
			};

			if (_engineOff > 0) then {
				// Turns off Engine when staying still
				_speedCheck1 = false;
				_speedCheck2 = false;
				if ((speed _uv <= 0.1) and (speed _uv >= -0.1)) then {_speedCheck1 = true} else {_speedCheck1 = false};
				sleep 1;
				if (_engineOff == 2) then {sleep 2};
				if ((speed _uv <= 0.1) and (speed _uv >= -0.1)) then {_speedCheck2 = true} else {_speedCheck2 = false};
				if ((_speedCheck1) and (_speedCheck2) and ((_engineOff == 1) or (_engineOff == 2))) then {_uv engineOn false};
			};
		};

		sleep 1;
	};
};