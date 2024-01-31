/*
	Author: Ascent

	Description:
	Limits the viewrange from the operator of specific UAV's, to make them less OP in Zeus Missions, and easier to inplement for Zeus.
*/

// Need to exit early if we aren't a client
if !hasInterface exitWith {};
RC_UAVBlur = [] spawn
{
	KK_fnc_trueZoom = {(([0.5,0.5] distance2D worldToScreen positionCameraToWorld [0,3,4]) * (getResolution select 5) / 2)};

	while {true} do
	{
		sleep 0.1;
		_uav = (getConnectedUAV player); // UAV
		// If the Player is currently controlling the UAV
		//_inDrone = ((UAVControl _uav) select 1) in ["DRIVER", "GUNNER", "COMMANDER"];
		_inDrone = isRemoteControlling player;
		_uavClass = typeOf _uav; // UAV ClassName
		_blur = ppEffectCreate ["dynamicBlur", 401];

		if (_inDrone && (_uav isNotEqualto objNull)) then {
			// If seats have been disabled in the Config we handle that here
			_UAVBlur = getNumber (configFile >> "CfgVehicles" >> _uavClass >> "RC_UAVBlur");

			if (_UAVBlur != 0) then {

				//APPROACH ISNT OPTIMAL, due to glance clarity, range from uav to operator, and reduced camera zoom, might be better *edit 2.5x can see 2000m clearly, 0.5 would fit, but by disallowing zoom by range
				//test less clear general view/accept 2500m range

				_uavPos = getpos (getConnectedUAV player);
				_playerPos = getpos player;
				_viewPos = screenToWorld [0.5, 0.5];
				
				//_playerDistance = _uavPos distance _playerPos;
				//_viewDistance = _uavPos distance _viewPos;
				_viewDistance = _playerPos distance _viewPos;  
				
				_zoom = (round (call KK_fnc_trueZoom * 10) / 10);

				//_connection = 1+(_distance * 0.0008)^5;
				//_connectionBlur = 1;
				_viewBlur = 1;
				//if (_playerDistance >= 1000) then {_connectionBlur = 1+((_playerDistance-1000) * 0.005)^4};
				if (_viewDistance >= 1000) then {_viewBlur = 1+((_viewDistance-1000) * 0.003)^4};
				//_finalBlur = 1;
				//_finalBlur = 0.1 * _viewBlur * (10/_zoom)^0.2;
				_finalBlur = 0.1 * _viewBlur * (_zoom/100)^0.1;
				//_finalBlur = 0.1 * _viewBlur;
				//hintSilent format ["distance: %1", _distance];
				hintSilent format ["blur: %1", _finalBlur];
			
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