/*
    RC Watcher Loop (DEBUG)
*/


diag_log "[RC][WATCHER] Started";

[] spawn {
    private _wasActive = false;

    while {true} do {

        private _veh = getConnectedUAV player;
        private _isActive = !isNull _veh && {_veh getVariable ["isRCArty", false]};

        if (_isActive && !_wasActive) then {
            diag_log "[RC][WATCHER] RC arty CONNECTED";
            systemChat "[RC] RC arty connected";

            // IMPORTANT: this must match your UI type (see Part 2)
            "RC_Artillery" cutRsc ["RC_Artillery", "PLAIN"];
        };

        if (!_isActive && _wasActive) then {
            diag_log "[RC][WATCHER] RC arty DISCONNECTED";
            systemChat "[RC] RC arty disconnected";

            cutRsc ["RC_Artillery", "PLAIN", 0, false];
        };

        _wasActive = _isActive;
        uiSleep 0.15;
    };
};


/*
[] spawn {
    private _wasActive = false;

    while {true} do {

        private _veh = getConnectedUAV player;
        private _isActive = !isNull _veh && {_veh getVariable ["isRCArty", false]};

        if (_isActive && !_wasActive) then {
            if (isNull findDisplay 5000) then {
                createDialog "RC_Artillery_UI";
            };
        };

        if (!_isActive && _wasActive) then {
            if (!isNull findDisplay 5000) then {
                closeDialog 0;
            };
        };

        _wasActive = _isActive;
        uiSleep 0.15;
    };
};
*/


/*
private _wasActive = false;

while {true} do {

    private _veh = getConnectedUAV player;
    private _isActive = !isNull _veh && {_veh getVariable ["isRCArty", false]};

    // ---- transition: OFF → ON ----
    if (_isActive && !_wasActive) then {
        createDialog "RC_Artillery_UI";
    };

    // ---- transition: ON → OFF ----
    if (!_isActive && _wasActive) then {
        closeDialog 0;
    };

    _wasActive = _isActive;

    uiSleep 0.15;
};
*/