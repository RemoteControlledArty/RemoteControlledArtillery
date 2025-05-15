/*
	Author: Ascent

	Description:
	Fixes multiplayer locality of this mods UAV's/UGV's.
*/

// Need to exit early if we aren't a client
if (!hasInterface) exitWith {};

RC_UAVLocalHash = createHashMap;

RC_Local = [] spawn {
    private _prevCtrl = false;

    while { true } do {
        sleep 0.5;

        private _isCtrl = isRemoteControlling player;

        if (_isCtrl && !_prevCtrl) then {

			[player, 'check passed'] remoteExec ['globalChat', player];
			
            private _uav = getConnectedUAV player;
            private _uavClass = typeOf _uav;
            private _UAVLocal = RC_UAVLocalHash get _uavClass;
            if (isNil "_UAVLocal") then {
                _UAVLocal = getNumber (configFile >> "CfgVehicles" >> _uavClass >> "RC_Local");
                RC_UAVLocalHash set [_uavClass, _UAVLocal];
            };
            if (_UAVLocal != 0) then {
                private _driverGroup = group (driver _uav);
                private _playerID = clientOwner;
                [_driverGroup, _playerID] remoteExec ['setGroupOwner', 2];
                [_uav, player] remoteExec ['setEffectiveCommander', 0];
            };
        };

        _prevCtrl = _isCtrl;
    };
};