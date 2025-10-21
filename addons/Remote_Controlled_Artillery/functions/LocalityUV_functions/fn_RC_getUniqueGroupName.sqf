params ["_name"];

private _name = trim ((_name splitString ". ") select ((count (_name splitString ". ")) - 1));

private _existingNames = allGroups apply {groupId _x};
private _number = 1;

while {format ["%1 %2", _name, _number] in _existingNames} do {
    _number = _number + 1;
};

format ["%1 %2", _name, _number];



//

/*
private _range = 4;			  // distance ahead of plow
private _scanRadius = 3;		 // width of scan area
private _interval = 0.5;		 // time between scans (seconds)
private _anim = "mineplow_hide"; // adjust to your animation source

while {alive _veh} do {
	// Wait until plow is down
	waitUntil {
		sleep 0.5;
		!alive _veh || (_veh animationPhase _anim < 0.5)
	};
	if (!alive _veh) exitWith {};
*/

/*
[] spawn {
	private _veh = getconnectedUAV player;
	private _range = 4;			// distance ahead of plow
	private _scanRadius = 3;	// width of scan area
	private _interval = 0.25;	// time between scans (seconds)
	private _lowSpeed = 20;	  // km/h limit when plow down
	private _anim = "MovePlow"; // animation source
	//get cfg maxspeed vehicle
	
	while {alive _veh && local _veh} do {
	
		if (_veh animationPhase _anim > 0.5) then {
			//_veh forceSpeed _lowSpeed;
			
			_veh setCruiseControl [_lowSpeed, false];
			
			private _frontPos = _veh modelToWorld [0, _range, -0.3];
			private _mines = nearestObjects [_frontPos, ["MineBase"], _scanRadius];
		
			{
				if (alive _x) then {
		
					triggerAmmo _x;	 //works
					//_x setDamage 1;   //works
		
					//deleteVehicle _x; //for effect
					//_expl = "RC_APS_Expl_Scripted" createVehicle (getPosATL _x);
					//_expl setDamage 1;
				};
			} forEach _mines;
		} else {
			_veh setCruiseControl [200, true];
		};
	
		sleep _interval;
	};
};

*/

