private _layer = ("RC_FPV_Layer" call BIS_fnc_rscLayer);
_layer cutRsc ["ArmaFPV_DialogNew", "PLAIN"];

//missionNamespace setVariable ["RC_FPV_Layer_ID", _layer];
//call DB_fnc_fpv_handleSettings;

call RC_fnc_fpv_handleSettings_MP;
call RC_fnc_fpv_handleBattery_MP;
call RC_fnc_fpv_handleSignal_MP;
call RC_fnc_fpv_handleTarget_MP;
call RC_fnc_fpv_handleTime_MP;