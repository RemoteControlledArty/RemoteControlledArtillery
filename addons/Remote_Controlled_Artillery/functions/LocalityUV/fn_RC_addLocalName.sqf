params ["_grpName", "_localName"];

private _localNameTr = trim ((_localName splitString ". ") select ((count (_localName splitString ". ")) - 1));

private _grpNameTr = _grpName;
if (_grpName find "," > -1) then {
    _grpNameTr = trim (_grpName select [0, _grpName find ","]);
};

if ((_grpNameTr find _localNameTr) == -1) then {
    format ["%1, %2", _grpNameTr, _localNameTr]
} else {
    _grpNameTr
};