addMissionEventHandler ["EntityCreated", {
	params ["_entity"];
	
	if (!local _entity) exitwith {};

	if ((getNumber (configFile >> "CfgVehicles" >> (typeOf _entity) >> "isUav") == 1)) then {
	//if (unitIsUAV _entity) then {		//somehow triggers multiple times
	
		[[_entity], RC_fnc_RC_addAction_nameUV] remoteExec ["call", 0, true];

		[[_entity], RC_fnc_RC_addAction_addFavUV] remoteExec ["call", 0, true];
		[[_entity], RC_fnc_RC_addAction_removeFavUV] remoteExec ["call", 0, true];
	};
}];


/*
addMissionEventHandler ["EntityCreated", {
	params ["_entity"];
    if (!local _entity) exitwith {};
	if ((getNumber (configFile >> "CfgVehicles" >> (typeOf _entity) >> "isUav") != 1)) exitwith {};

	_entity addEventHandler ["Local", {
		params ["_entity", "_isLocal"];
		if (!_isLocal) exitwith {};

		private _grp = group _entity
		private _grpName = groupId _grp;
		private _localName = name player;
		private _name = [_grpName,_localName] call RC_fnc_RC_addLocalName;
		_grp setGroupIdGlobal [_name];
	}];
}];
*/


/*
call{
	this spawn { 

		_this setBehaviour "CARELESS";  
		_this flyInHeight 30;
		_this setSkill 1;    
		_this setSpeedMode "FULL";   

		while {
			isNull(_this findNearestEnemy _this)
		} do {
			sleep 1;
		};

		private _target = _this findNearestEnemy _this;

		for "_i" from count waypoints (group _this) - 1 to 0 step -1 do {  
			deleteWaypoint [(group _this), _i];  
		};

		private _cutDistance = 0;    
		while {
			(_this distance2D _target > _cutDistance) && (_this distance2D _target > 30)
		} do {
			_this DoMove (position _target);    
			sleep 0.2;     
			_temp = (2*9.81*(((getPosASL _this)select 2)-((getPosASL _target)select 2)));  
			_temp = sqrt _temp; 
			_cutDistance = (((speed _this)*0.278)*_temp*0.102);    
		};

		_this deleteVehicleCrew driver _this;      
	};
}
*/