params ["_proj", "_isRocket", "_projFirstPos"];

//missile / rocket
private _m = "M ";
if (_isRocket) then {
	_m = "R ";
};
//only set for first detection to keep origin pos
if (isNil {_proj getVariable "RC_AR_Prj"}) then {
	_proj setVariable ["RC_AR_Prj", [_m, (ASLToAGL _projFirstPos), (round diag_tickTime)]];
};

//add spawn with sleep for redetection possibility
//_proj setVariable ["Prj", nil];

//add to array
RC_AR_projectile_arr pushbackUnique _proj;