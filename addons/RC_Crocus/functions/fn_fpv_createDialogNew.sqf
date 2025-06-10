private _layer = ("DB_FPV_Layer" call BIS_fnc_rscLayer);
_layer cutRsc ["ArmaFPV_DialogNew", "PLAIN"];

call DB_fnc_fpv_handleSettings;
call DB_fnc_fpv_handleBattery;
call DB_fnc_fpv_handleSignal;
call DB_fnc_fpv_handleTime;
