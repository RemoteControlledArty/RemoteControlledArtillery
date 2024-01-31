/*
	Author: Ascent

	Description:
	Limits the usable viewrange to max 1500m to 2000m from the operator of specific UAV's, to make them less OP in Zeus Missions, and easier to implement for Zeus.
*/

// Need to exit early if we aren't a client
if !hasInterface exitWith {};
RC_UAVBlur = [] spawn
{
	while {true} do
	{
		sleep 0.1;
		_uav = (getConnectedUAV player);
		// If the Player is currently controlling the UAV
		_inDrone = isRemoteControlling player;
		_uavClass = typeOf _uav; // UAV ClassName
		_blur = ppEffectCreate ["dynamicBlur", 401];

		if (_inDrone && (_uav isNotEqualto objNull)) then {
			// Checks config if its meant to be a shortrange UAV, no entry means no Effect
			_UAVBlur = getNumber (configFile >> "CfgVehicles" >> _uavClass >> "RC_UAVBlur");
			if (_UAVBlur != 0) then {
				_uavPos = getpos (getConnectedUAV player);
				_playerPos = getpos player;
				_viewPos = screenToWorld [0.5, 0.5];
				_viewDistance = _playerPos distance2d _viewPos;
				_viewBlur = 1;
				if (_viewDistance >= 1000) then {_viewBlur = 1+((_viewDistance-1000) * 0.003)^3};	//this seems perfect for limiting past 1500m unusable past 2000m
				_finalBlur = 0.1 * _viewBlur;	//1500m _finalBlur should not be worse than 0.45 blur to be usefull
				_blur ppEffectEnable true;
				_blur ppEffectAdjust [_finalBlur];
				_blur ppEffectCommit 0;
			}
			else {
				_blur ppEffectEnable false;
			};
		}
		else {
			_blur ppEffectEnable false;
		};
	};
};