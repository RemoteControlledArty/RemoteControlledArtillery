/*
	Author: Fluffy, Ascent, Eric
*/

if (!isServer) exitWith { };

addMissionEventHandler ["MarkerCreated", {
	params ["_marker", "_channelNumber", "_owner", "_local"];

	/* Check if Marker starts with RC_Marker_Prefix or RC_GPS_Prefix */
	private _markerText = markerText _marker;
	private _isArtyMarker = (_markerText select [0, count RC_Marker_Prefix - 1]) isEqualTo RC_Marker_Prefix;
	private _isGPSMarker = { (_markerText select [0, count RC_GPS_Prefix - 1]) isEqualTo RC_GPS_Prefix };
	if (!_isArtyMarker && { !(call _isGPSMarker) }) exitWith { };

	if (_isArtyMarker) exitWith {
		_targetIndex = _markerText regexFind ["[0-9]{1,2}", 0]; // Regexes can be exploited by a bad actor to cause lag. Consider another solution
		_targetIndex = _targetIndex select 0 select 0 select 0; // ??
		_targetIndex = parseNumber _targetIndex;

		RC_Artillery_Markers pushBackUnique [_targetIndex, _marker];
		RC_Artillery_Markers sort true;
		publicVariable "RC_Artillery_Markers";
	};

	if (_isGPSMarker) exitWith {
		_gpsTarget = createVehicleLocal ["RC_GPSDatalinkTarget", (markerPos _x), [], 0, "CAN_COLLIDE"];

		_side = side player;
		[{
			params ["_args", "_thisHandler"];
			_args params ["_gpsTarget", "_side"]

			if (!alive _gpsTarget) exitWith { [_thisHandler] call CBA_fnc_removePerFrameHandler };

			_side reportRemoteTarget [_gpsTarget, 5];
		}, 1, [_gpsTarget, _side]] call CBA_fnc_addPerFrameHandler;

		activeGPSMarkers pushBackUnique [_marker, _gpsTarget];
		publicVariable "activeGPSMarkers";
	};

}];

addMissionEventHandler ["MarkerDeleted", {
	params ["_marker", "_local", "_deleter"];

	private _markerIndex = activeGPSMarkers find _marker;
	if (_markerIndex > -1) exitWith {
		deleteVehicle ((activeGPSMarkers select _markerIndex) select 2);
		activeGPSMarkers deleteAt _markerIndex;
		publicVariable "activeGPSMarkers";
	};

	_markerIndex = RC_Artillery_Markers find _marker;
	if (_markerIndex > -1) exitWith {
		_markerIndex deleteAt _markerIndex;
		publicVariable "RC_Artillery_Markers";
	};
}];

addMissionEventHandler ["MarkerUpdated", {
	params ["_marker", "_local"];

	private _markerIndex = activeGPSMarkers find _marker;
	if (_markerIndex isNotEqualTo -1) exitWith { };

	(activeGPSMarkers select _markerIndex) setPosATL (markerPos _marker);
	publicVariable "activeGPSMarkers";
}];