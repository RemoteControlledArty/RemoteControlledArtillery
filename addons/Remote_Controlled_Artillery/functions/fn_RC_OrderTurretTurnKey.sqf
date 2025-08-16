/*
	Author: Ascent

	Order turret turn to your target.
*/

//params ["_args"];

private _vic = vehicle player;
if (_vic isEqualTo player) exitwith {};


private _com = commander _vic;
private _gun = gunner _vic;
private _responder = _gun;
if (player isEqualTo _gun) then {
	_responder = _com;
};
if (_responder isEqualTo objNull) exitwith {};


private _target = cursorTarget;
private _targetPos = eyePos cursorTarget;
if (_target isEqualTo objNull) then {
	_targetPos = AGLToASL (screenToWorld [0.5, 0.5]);
} else {
    _responder doTarget _target;
};


[_vic, _responder, _targetPos] remoteExec ['RC_fnc_RC_OrderTurretTurnOwner', 2];