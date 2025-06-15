params ["_position", "_radius", "_side"];

private _retranslators = [];
if (_side isEqualTo west) then {
	_retranslators = _position nearEntities ["RC_Crocus_Mothership", _radius];
};
if (_side isEqualTo east) then {
	_retranslators = _position nearEntities ["RC_Crocus_Mothership_O", _radius];
};
if (_side isEqualTo resistance) then {
	_retranslators = _position nearEntities ["RC_Crocus_Mothership_I", _radius];
};

_retranslators