/*
	Author: Ascent

	Description:
	Checks on Server for turretOwner.
*/

params ['_vic','_source','_turretPath'];

private _turretOwnerID = _vic turretOwner _turretPath;
[_vic, _source, _turretPath] remoteExec ['RC_fnc_RC_AT_Turn', _turretOwnerID];