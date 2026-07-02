if (isRemoteControlling player) then {

	call RC_fnc_RC_stopRC;

} else {

	//filter for valid favorites
	RC_UV_favs = RC_UV_favs select {!isNull _x && alive _x};

	if ((count RC_UV_favs) > 0) then {

		private _UV_index = ((RC_UV_favs find (getConnectedUAV player)) + 1) % (count RC_UV_favs);
		private _UV = RC_UV_favs select _UV_index;

		private _UV_seat = _UV getVariable ["RC_UV_seat", objNull];
		[_UV, _UV_seat] call RC_fnc_RC_connectToUV;
	} else {
		
		hint "No favorite UV's available to swap to.\nFirst add UV's to favorites.";
		player action ["UAVTerminalOpen", player];
		0 spawn {sleep 3.5; hint "";};
	};
};