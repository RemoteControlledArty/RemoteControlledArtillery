params ["_name"];

private _existingNames = allGroups apply {groupId _x};
private _number = 1;

while {format ["%1 %2", _name, _number] in _existingNames} do {
    _number = _number + 1;
};

format ["%1 %2", _name, _number];