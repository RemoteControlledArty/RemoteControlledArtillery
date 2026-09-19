class RC_AT_Warning_Backup
{
	IncomingMissile="params ['_target','_ammo','_vehicle','_instigator','_missile'];	\
	if (!local _target) exitwith {};	\
	[_target,_ammo,_vehicle,_instigator,_missile] call RC_fnc_RC_AT_SourceIndicator;";
};