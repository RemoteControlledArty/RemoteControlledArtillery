params ["_position", "_radius", "_side"];

private _retranslators = _position nearObjects ["FPV_Retranslator", _radius];

/*
_retranslators = [];
if (_side isEqualTo west) then {
	_retranslators = _position nearEntities ["FPV_Retranslator", _radius];
};
if (_side isEqualTo east) then {
	_retranslators = _position nearEntities ["FPV_Retranslator_I", _radius];
};
if (_side isEqualTo resistance) then {
	_retranslators = _position nearEntities ["FPV_Retranslator_O", _radius];
};
*/

_retranslators