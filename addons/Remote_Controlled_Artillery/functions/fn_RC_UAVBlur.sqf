/*
	Author: Ascent

	Description:
	Limits the usable range from the operator of specific UAV's, to make them less OP in Zeus Missions, and easier to implement for Zeus.
	RC_UAVBlur=1500; means past 1500m the connection becomes worse and blurry

	Currently unused alternative that is neat but unrealistic and plays wierd.
	if (_UAVBlurRange == 1) then {
		_Distance = _playerPos distance2d (screenToWorld [0.5, 0.5]);
		if (_Distance >= 1000) then {_viewBlur = 1+((_Distance-1000) * 0.003)^3};	//this seems perfect for limiting past 1500m unusable past 2000m
	};
*/

// Need to exit early if we aren't a client
if (!hasInterface) exitWith {};

RC_UAVBlurRangeHash = createHashMap;
RC_UAVCtrlRangeHash = createHashMap;

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

		private _UAVBlurRange = RC_UAVBlurRangeHash get _uavClass;
		if (isNil "_UAVBlurRange") then {
			_UAVBlurRange = getNumber (configFile >> "CfgVehicles" >> _uavClass >> "RC_UAVBlurRange");
			RC_UAVBlurRangeHash set [_uavClass, _UAVBlurRange];
		};
		if (_UAVBlurRange != 0) then {
			_Distance = 1;
			_viewBlur = 1;
			_Distance = (getPosASL player) distance2d (getPosASL (getConnectedUAV player));
			if (_Distance >= _UAVBlurRange) then {_viewBlur = 1+((_Distance-_UAVBlurRange) * 0.005)^2};
			_finalBlur = 0.1 * _viewBlur;	//_finalBlur should not be worse than 0.45 blur to be usefull
			_blur ppEffectEnable true;
			_blur ppEffectAdjust [_finalBlur];
			_blur ppEffectCommit 0;
		}
		else {
			_blur ppEffectEnable false;
		};

		private _UAVCtrlRange = RC_UAVCtrlRangeHash get _uavClass;
		if (isNil "_UAVCtrlRange") then {
			_UAVCtrlRange = getNumber (configFile >> "CfgVehicles" >> _uavClass >> "RC_UAVCtrlRange");
			RC_UAVCtrlRangeHash set [_uavClass, _UAVCtrlRange];
		};
		if (_UAVCtrlRange != 0) then {
			_Distance = 1;
			_Distance = (getPosASL player) distance2d (getPosASL (getConnectedUAV player));
			if (_Distance >= _UAVCtrlRange) then {
				player remoteControl objNull;
				systemchat "out of range, lost UV connection";
			};
		};
	};
};