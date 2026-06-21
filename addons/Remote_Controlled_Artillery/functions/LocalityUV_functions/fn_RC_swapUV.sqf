if (isRemoteControlling player) then {

	call RC_fnc_RC_stopRC;

} else {

	RC_UV_favs = RC_UV_favs select {!isNull _x && alive _x};

	if ((count RC_UV_favs) > 0) then {

		private _UV_index = ((RC_UV_favs find (getConnectedUAV player)) + 1) % (count RC_UV_favs);
		private _UV = RC_UV_favs select _UV_index;
		//systemchat str _UV_index;

		if ([_UV] call RC_fnc_RC_isValidUV) then {

			//systemchat str _UV;
			private _UV_seat = _UV getVariable ["RC_UV_seat", objNull];
			[_UV, _UV_seat] call RC_fnc_RC_connectToUV;
		} else {
			hint "Fav UV not valid. Remove UV from fav's";
		};
	} else {
		hint "No fav UV's available to swap to.\nFirst add UV's to fav's.";
	};
};