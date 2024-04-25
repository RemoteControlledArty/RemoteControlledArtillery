/*
	Author: Ascent

	Description:
	Limits the usable range to max 1500m to 2000m from the operator of specific UAV's, to make them less OP in Zeus Missions, and easier to implement for Zeus.
	RC_UAVBlur=1; limits the distance between *point of view* to operator
	RC_UAVBlur=2; limits the distance between the *UAV* to the operator
*/

// Need to exit early if we aren't a client
if !hasInterface exitWith {};
RC_UAVBlur = [] spawn
{
	while {true} do
	{
		sleep 0.2;

		_blur = ppEffectCreate ["dynamicBlur", 401];

		if !(isRemoteControlling player) then {
			_blur ppEffectEnable false;
			continue;
		};

		_uav = (getConnectedUAV player);
		_uavClass = typeOf _uav; // UAV ClassName
		_UAVBlur = getNumber (configFile >> "CfgVehicles" >> _uavClass >> "RC_UAVBlur");

		// If the Player is currently controlling the UAV
		_inDrone = isRemoteControlling player;

		if (_inDrone && (_uav isNotEqualto objNull)) then {
			// Checks config if its meant to be a shortrange UAV, no entry means no Effect
			if (_UAVBlur != 0) then {
				_playerPos = getpos player;
				_viewPos = screenToWorld [0.5, 0.5];
				_uavPos = getpos (getConnectedUAV player);
				_Distance = 1;
				if (_UAVBlur == 1) then {_Distance = _playerPos distance2d _viewPos;};
				if (_UAVBlur == 2) then {_Distance = _playerPos distance2d _uavPos;};
				_viewBlur = 1;
				if (_Distance >= 1000) then {_viewBlur = 1+((_Distance-1000) * 0.003)^3};	//this seems perfect for limiting past 1500m unusable past 2000m
				_finalBlur = 0.1 * _viewBlur;	//1500m _finalBlur should not be worse than 0.45 blur to be usefull
				_blur ppEffectEnable true;
				_blur ppEffectAdjust [_finalBlur];
				_blur ppEffectCommit 0;
			}
			else {
				_blur ppEffectEnable false;
			};
		};
	};
};