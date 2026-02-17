/*
    RC State Update
    Recomputes ballistic solution when inputs change
*/

params ["_distance", "_elevation", "_speed"];

private _state = uiNamespace getVariable "RC_state";
if (isNil "_state") exitWith {};

// ---- early outs ----
if (_distance <= 0 || _speed <= 0) exitWith {
    _state set ["valid", false];
};

// ---- physics ----
private _g = 9.81;
private _v2 = _speed ^ 2;

private _disc = (_v2 ^ 2) - _g * (_g * (_distance ^ 2) + 2 * _elevation * _v2);

// clamp discriminant ONLY
if (_disc < 0) exitWith {
    _state set ["valid", false];
};

private _sqrt = sqrt _disc;

private _low = atan ((_v2 - _sqrt) / (_g * _distance));
private _high = atan ((_v2 + _sqrt) / (_g * _distance));

// ---- ETA (simple, consistent with your existing logic) ----
private _etaLow = _distance / (_speed * cos _low);
private _etaHigh = _distance / (_speed * cos _high);

// ---- store ----
_state set ["distance", _distance];
_state set ["barrelElevation", _elevation];
_state set ["muzzleSpeed", _speed];

_state set ["lowAngle", _low];
_state set ["highAngle", _high];
_state set ["lowETA", _etaLow];
_state set ["highETA", _etaHigh];

_state set ["valid", true];