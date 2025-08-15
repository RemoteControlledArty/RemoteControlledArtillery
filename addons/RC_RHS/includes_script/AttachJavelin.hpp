init="if (!isserver) exitwith {}; \
(_this select 0) spawn { \
	private _javelin = 'item_rhs_fgm148_magazine_AT' createVehicle [0,0,0]; \
	_javelin attachTo [_this, [0.34, -0.05, -0.13], 'konec hlavne', true]; \
	private _yaw = 90; private _pitch = 0; private _roll = 20; \
	_javelin setVectorDirAndUp [ \
		[sin _yaw * cos _pitch, cos _yaw * cos _pitch, sin _pitch], \
		[[sin _roll, -sin _pitch, cos _roll * cos _pitch], -_yaw] call BIS_fnc_rotateVector2D \
	]; \
};";
//konec hlavne / usti hlavne


/*
_this addEventHandler ["CuratorObjectDeleted", {
	params ["_curator", "_entity"];
}];

_this addEventHandler ["Killed", {
	params ["_unit", "_killer", "_instigator", "_useEffects"];
}];
*/