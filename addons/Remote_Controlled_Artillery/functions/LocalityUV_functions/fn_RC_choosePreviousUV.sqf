if (_previousUV isEqualTo (vehicle _previousUV_seat)) then {

	[_previousUV, _previousUV_seat] call RC_fnc_RC_connectToUV;
} else {

	[_previousUV, objNull] call RC_fnc_RC_connectToUV;	//if just defined previousUV is not equal to vehicle of stored seat
};