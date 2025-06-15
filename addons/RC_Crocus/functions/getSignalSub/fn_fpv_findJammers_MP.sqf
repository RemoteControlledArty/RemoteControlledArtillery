params ["_position", "_radius"];

private _jammers = _position nearEntities [["Sania", "Sania_with_tripod"], _radius];
_jammers = _jammers select { _x getVariable ["DB_jammer_isActive", false] };

_jammers