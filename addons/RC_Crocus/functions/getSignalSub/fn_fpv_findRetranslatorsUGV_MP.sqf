params ["_position", "_radius", "_side"];

private _retranslators1 = [];
private _retranslators2 = [];
if (_side isEqualTo west) then {
	_retranslators1 = _position nearEntities ["RC_Crocus_Carrier_A", _radius];
	_retranslators2 = _position nearEntities ["RC_Crocus_Carrier_WD", _radius];
};
if (_side isEqualTo east) then {
	_retranslators1 = _position nearEntities ["RC_Crocus_Carrier_A_O", _radius];
	_retranslators2 = _position nearEntities ["RC_Crocus_Carrier_WD_O", _radius];
};
if (_side isEqualTo resistance) then {
	_retranslators1 = _position nearEntities ["RC_Crocus_Carrier_A_I", _radius];
	_retranslators2 = _position nearEntities ["RC_Crocus_Carrier_WD_I", _radius];
};
private _retranslators = _retranslators1 + _retranslators2;

_retranslators