params ["_proj", "_shownETA", "_delay"];

[_proj, _shownETA, _delay] spawn {
    params ["_proj", "_shownETA", "_delay"];

    sleep _delay;

    if (isNil {_proj getVariable "RC_AR_Prj"}) then {
        _proj setVariable ["RC_AR_Prj", [_shownETA, diag_tickTime]];
    };
    RC_AR_CBRad_arr pushbackUnique _proj;
};


/*
params ["_proj", "_shownETA", "_delay"];

systemchat "0";

[_proj, _shownETA, _delay] spawn {
    params ["_proj", "_shownETA", "_delay"];

    systemchat "1";

    sleep _delay;

    systemchat "2";

    if (isNil {_proj getVariable "RC_AR_Prj"}) then {
        systemchat "3";
        _proj setVariable ["RC_AR_Prj", [_shownETA, diag_tickTime]];
        systemchat "4";
    };
    RC_AR_CBRad_arr pushbackUnique _proj;
    systemchat "5";
};
*/


/*
    _proj addEventHandler ["SubmunitionCreated", {
        params ["_projectile", "_submunitionProjectile", "_position", "_velocity"];

        private _isMissile = (getText (configFile >> "CfgAmmo" >> typeOf _submunitionProjectile >> "simulation")) isEqualTo "shotRocket";

        if (_isMissile) then {

            if (isNil {_proj getVariable "RC_AR_Prj"}) then {
                _proj setVariable ["RC_AR_Prj", [_shownETA, diag_tickTime, "M "]];
            };
            RC_AR_CBRad_arr pushbackUnique _proj;
        };
    }];
*/
