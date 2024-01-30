/*
	Author: Ascent

	Description:
	Limits the usable range of specific UAV's, to make them less OP in Zeus Missions, and easier to inlpement for Zeus.
*/

// Need to exit early if we aren't a client
if !hasInterface exitWith {};
RC_UAVBlur = [] spawn
{
	KK_fnc_trueZoom = {(([0.5,0.5] distance2D  worldToScreen positionCameraToWorld [0,3,4]) * (getResolution select 5) / 2)};

	while {true} do
	{
		sleep 0.1;

		_uav = (getConnectedUAV player); // UAV

		// If the Player is currently controlling the UAV
		_inDrone = ((UAVControl _uav) select 1) in ["DRIVER", "GUNNER", "COMMANDER"];
		//_inDrone = isRemoteControlling player;
		//_inDrone = ((UAVControl _uav) select 1) isEqualTo "GUNNER";
		
		_uavClass = typeOf _uav; // UAV ClassName

		if (_inDrone && (_uav isNotEqualto objNull)) then {
			// If seats have been disabled in the Config we handle that here
			_disableSeats = getNumber (configFile >> "CfgVehicles" >> _uavClass >> "RCDisableSeats");
			
		_uavPos = getpos (getConnectedUAV player);
		_playerPos = getpos player;
		_viewPos = screenToWorld [0.5, 0.5];
		
		//_playerDistance = _uavPos distance _playerPos;
		//_viewDistance = _uavPos distance _viewPos;
		_viewDistance = _playerPos distance _viewPos;  
		
		_zoomBlur = (round (call KK_fnc_trueZoom * 10) / 10)*0.04;
		//_connection = 1+(_distance * 0.0008)^5;
		//_connectionBlur = 1;
		_viewBlur = 1;
		//if (_playerDistance >= 1000) then {_connectionBlur = 1+((_playerDistance-1000) * 0.005)^4};
		if (_viewDistance >= 1000) then {_viewBlur = 1+((_viewDistance-1000) * 0.0035)^4};
		//_finalBlur = 1;
		_finalBlur = 0.1 * _viewBlur * _zoomBlur;
		//hintSilent format ["distance: %1", _distance];
		hintSilent format ["blur: %1", _finalBlur];
		
		
		_blur = ppEffectCreate ["dynamicBlur", 401];
		_blur ppEffectEnable true;
		_blur ppEffectAdjust [_finalBlur];
		_blur ppEffectCommit 0;
	};
};