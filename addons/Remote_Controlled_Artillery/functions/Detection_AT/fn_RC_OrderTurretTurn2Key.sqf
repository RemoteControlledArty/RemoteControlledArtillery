/*
	Author: Ascent

	Order commander turret turn to your target, made for UAV Operator seat to differentiate keys between gunner and commander.
*/

//params ["_args"];

private _vic = vehicle player;
if (_vic isEqualTo player) exitwith {};


private _responder = commander _vic;
if (_responder isEqualTo objNull) exitwith {};


private _cursorTarget = cursorTarget;
private _target = _cursorTarget;
private _targetPos = eyePos _cursorTarget;
if (_target isEqualTo objNull) then {
	_targetPos = AGLToASL (screenToWorld [0.5, 0.5]);
} else {
    _responder doTarget _target;
};


[_vic, _responder, _targetPos] remoteExec ['RC_fnc_RC_OrderTurretTurnOwner', 2];