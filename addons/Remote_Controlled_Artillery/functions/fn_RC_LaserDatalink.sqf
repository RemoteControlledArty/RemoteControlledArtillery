/*
	Author: Fluffy & Ascent

	Description:
	Turns off engines of UGV's when halting.
*/

// Need to exit early if we aren't a client
if !hasInterface exitWith {};
RC_EngineOff = [] spawn
{
	while {true} do
	{
		sleep 0.1;

		_uav = (getConnectedUAV player);

		// If we don't have a UAV connected, Start at the top
		if (_uav isEqualTo objNull) then {continue;};

		// UAV ClassName
		_uavClass = typeOf _uav;
		
		// Turns off Engine when staying still
		_speedCheck1 = false;
		_speedCheck2 = false;
		if ((speed _uav <= 0.1) and (speed _uav >= -0.1)) then {_speedCheck1 = true} else {_speedCheck1 = false};
		sleep 0.1;
		if ((getNumber (configFile >> "CfgVehicles" >> _uavClass >> "RCEngineOffDelay")) == 1) then {sleep 2};
		if ((speed _uav <= 0.1) and (speed _uav >= -0.1)) then {_speedCheck2 = true} else {_speedCheck2 = false};
		if ((_speedCheck1) and (_speedCheck2) and (_uavClass isKindof "Tank" || _uavClass isKindof "Car")) then {_uav engineOn false};
	};
};