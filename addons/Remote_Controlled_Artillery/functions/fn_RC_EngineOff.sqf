/*
	Author: Fluffy & Ascent

	Description:
	Turns of engines of UGV's when speed is 0 .
*/

// Need to exit early if we aren't a client
if !hasInterface exitWith {};
RC_EngineOff = [] spawn
{
	//private _position = getPosASL (getConnectedUAV player);
	while {true} do
	{
		sleep 0.1;

		_uav = (getConnectedUAV player);

		// If we don't have a UAV connected, Start at the top
		if (_uav isEqualTo objNull) then {continue;};

		// If the Player is currently controlling the UAV
		_inDrone = ((UAVControl _uav) select 1) isEqualTo "GUNNER"; 

		_uavClass = typeOf _uav; // UAV ClassName
		
		// See if the vehicle has the isRCArty property
		_isRCArty = (getNumber (configFile >> "CfgVehicles" >> _uavClass >> "isRCArty") == 1);

		// Turns off Engine when staying still
		/*
		_speedCheck1 = false;
		_speedCheck2 = false;
		if ((speed _uav == 0)) then {_speedCheck1 = true};
		sleep 0.9;
		if ((speed _uav == 0)) then {_speedCheck2 = true};
		if (_speedCheck1 and _speedCheck2 and (_uavClass isKindof "Tank" || _uavClass isKindof "Car")) then {_uav engineOn false};
		*/

		_speedCheck1 = false;
		_speedCheck2 = false;
		if ((speed _uav <= 0.1) and (speed _uav >= -0.1)) then {_speedCheck1 == true};

		sleep 0.1;
		if (getNumber (configFile >> "CfgVehicles" >> _uavClass >> "RCEngineOffDelay") == 1) then {sleep 2};

		if ((speed _uav <= 0.1) and (speed _uav >= -0.1)) then {_speedCheck2 == true};
		if (((_speedCheck1) and (_speedCheck2)) and (_uavClass isKindof "Tank" || _uavClass isKindof "Car")) then {_uav engineOn false};

		/*
  		if (((_position distance getPosASL _uav) > 0) and (_uavClass isKindof "Tank" || _uavClass isKindof "Car")) then 
		{
    		_uav engineOn false;
   			_position = getPosASL _uav;
 		};
		sleep 0.4;
		*/
	};
};