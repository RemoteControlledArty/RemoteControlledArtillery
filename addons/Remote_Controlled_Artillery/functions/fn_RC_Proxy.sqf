/*
	Author: Ascent

	//_p = projectile
	//_fR = fuse radius
	//_t = targets
	//_e = exit
*/


fnc_RC_proxyFuse =
{
	params ["_p"];

	private _fR = 12;
	private _e = false;
	scopeName "RC_Proxy";

	while {(alive _p) && (!isNull _p)} do {
		
		private _t = _p nearEntities ["Air", 30];
		//private _t = nearestObjects [_p, ["Air"], 30];
		_t = _t select {!isNull _x && alive _x};
		_t = _t select {(side _x) != (side player)};
		
		{
			if ((_p distance _x) < _fR) then {

				if ((getNumber (configFile >> "CfgVehicles" >> typeOf _x >> "irTarget")) == 1) then {
					triggerAmmo _p;
					breakOut "RC_Proxy";
				};
			};
		} forEach _t;
	};
};


/*
//passed target trigger
	private _drone = cursorTarget;
	
	private _dist = _drone distance _proj;
	private _distLast = _proj getVariable ["RC_Hydra_Proxy", 10000];
	_proj setVariable ["RC_Hydra_Proxy", _dist];
	
	systemchat (str _dist + " > " + str _distLast);	   
	
	if ((_dist < _fuseRadius) or (_dist > _distLast)) exitWith {
		systemchat "boom";
		triggerAmmo _proj;
	};
*/