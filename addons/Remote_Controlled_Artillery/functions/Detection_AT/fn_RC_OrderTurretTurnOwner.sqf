/*
	Author: Ascent

	Order turret turn to your target.
*/

params ['_vic','_responder','_targetPos'];
private _responderID = owner _responder;
[_vic, _responder, _targetPos] remoteExec ['RC_fnc_RC_OrderTurretTurn', _responderID];