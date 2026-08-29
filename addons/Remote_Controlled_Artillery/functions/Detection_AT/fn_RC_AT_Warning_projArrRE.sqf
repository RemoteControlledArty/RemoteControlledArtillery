params ["_proj", "_isRocket", "_projFirstPos", "_sourceVisible"];

//missile / rocket
private _m = "M ";
if (_isRocket) then {
	_m = "R ";
};
//only set for first detection to keep origin pos
if (isNil {_proj getVariable "RC_AR_Prj"}) then {

	private _posAGL = (ASLToAGL _projFirstPos);
	private _time = (round diag_tickTime);

	_proj setVariable ["RC_AR_Prj", [_m, _posAGL, _time]];

	if (!_sourceVisible) then {
		//if source not visible store first detected pos
		private _posAGL = ASLToAGL _projFirstPos;
		RC_AR_undetectedLauncher_arr pushback [_posAGL, _time];
	};
};

//add spawn with sleep for redetection possibility
//_proj setVariable ["Prj", nil];

//add to array
RC_AR_projectile_arr pushbackUnique _proj;