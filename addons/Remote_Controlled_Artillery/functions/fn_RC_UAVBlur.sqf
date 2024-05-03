/*
	Author: Ascent

	Description:
	Limits the usable range to about 2000m from the operator of specific UAV's, to make them less OP in Zeus Missions, and easier to implement for Zeus.
	RC_UAVBlur=800; means past 800m the connection becomes worse and blurry

	Currently unused alternative that is neat but unrealistic and plays wierd.
	if (_UAVBlurRange == 1) then {
		_Distance = _playerPos distance2d (screenToWorld [0.5, 0.5]);
		if (_Distance >= 1000) then {_viewBlur = 1+((_Distance-1000) * 0.003)^3};	//this seems perfect for limiting past 1500m unusable past 2000m
	};
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
		_UAVBlurRange = getNumber (configFile >> "CfgVehicles" >> _uavClass >> "RC_UAVBlurRange");

		// Checks config if its meant to be a shortrange UAV, no entry means no Effect
		if (_UAVBlurRange != 0) then {
			_playerPos = getpos player;
			_Distance = 1;
			_viewBlur = 1;
			_Distance = _playerPos distance2d (getpos (getConnectedUAV player));
			if (_Distance >= _UAVBlurRange) then {_viewBlur = 1+((_Distance-_UAVBlurRange) * 0.005)^2};	//this seems perfect for limiting past 1500m unusable past 2000m
			_finalBlur = 0.1 * _viewBlur;	//_finalBlur should not be worse than 0.45 blur to be usefull
			_blur ppEffectEnable true;
			_blur ppEffectAdjust [_finalBlur];
			_blur ppEffectCommit 0;
		}
		else {
			_blur ppEffectEnable false;
		};
	};
};