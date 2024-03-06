/*
	Author: Fluffy, Ascent, Eric
*/

if (!isServer) exitWith { };

addMissionEventHandler ["MarkerCreated", {
	params ["_marker", "_channelNumber", "_owner", "_local"];

	/* Check if Marker starts with RC_Marker_Prefix or RC_GPS_Prefix */
	private _markerText = markerText _marker;
	private _isArtyMarker = (_markerText select [0, count RC_Marker_Prefix]) isEqualTo RC_Marker_Prefix;
	private _isGPSMarker = (_markerText select [0, count RC_GPS_Prefix]) isEqualTo RC_GPS_Prefix;
	if (!_isArtyMarker && { !_isGPSMarker }) exitWith { };

	if (_isArtyMarker) exitWith {
		_targetIndex = _markerText regexFind ["[0-9]{1,2}", 0];
		_targetIndex = (flatten _targetIndex) select 0;
		_targetIndex = parseNumber _targetIndex;

		RC_Artillery_Markers pushBackUnique [_targetIndex, _marker];
		RC_Artillery_Markers sort true;
		publicVariable "RC_Artillery_Markers";
	};

	if (_isGPSMarker) exitWith {
		_gpsTarget = createVehicleLocal ["RC_GPSDatalinkTarget", (markerPos _marker), [], 0, "CAN_COLLIDE"];
		_gpsTarget setPosATL (markerPos _marker);

		_side = side player;
		[{
			params ["_args", "_thisHandler"];
			_args params ["_gpsTarget", "_side"];

			if (isNull _gpsTarget || { !alive _gpsTarget }) exitWith { [_thisHandler] call CBA_fnc_removePerFrameHandler };

			_side reportRemoteTarget [_gpsTarget, 5];
		}, 1, [_gpsTarget, _side]] call CBA_fnc_addPerFrameHandler;

		activeGPSMarkers pushBackUnique [_marker, _gpsTarget];
		publicVariable "activeGPSMarkers";
	};
}];

addMissionEventHandler ["MarkerDeleted", {
	params ["_marker", "_local", "_deleter"];

	private _markerIndex = activeGPSMarkers findIf { (_x select 0) isEqualTo _marker };
	if (_markerIndex > -1) exitWith {
		(activeGPSMarkers select _markerIndex) params ["", "_gpsTarget"];
		deleteVehicle _gpsTarget;
		
		activeGPSMarkers deleteAt _markerIndex;
		publicVariable "activeGPSMarkers";
	};

	_markerIndex = RC_Artillery_Markers findIf { (_x select 1) isEqualTo _marker };
	if (_markerIndex > -1) exitWith {
		RC_Artillery_Markers deleteAt _markerIndex;
		publicVariable "RC_Artillery_Markers";
	};
}];

addMissionEventHandler ["MarkerUpdated", {
	params ["_marker", "_local"];

	private _markerIndex = activeGPSMarkers findIf { (_x select 0) isEqualTo _marker };
	if (_markerIndex isEqualTo -1) exitWith { };

	(activeGPSMarkers select _markerIndex) params ["", "_gpsTarget"];
	deleteVehicle _gpsTarget;

	// Moving the position of existing target does not work ???
	// Workaround is to re-create the gps target
	_gpsTarget = createVehicleLocal ["RC_GPSDatalinkTarget", (markerPos _marker), [], 0, "CAN_COLLIDE"];
	_gpsTarget setPosATL (markerPos _marker);

	(activeGPSMarkers select _markerIndex) set [1, _gpsTarget];

	systemChat format ["Updated position to %1 from %2", str markerPos _marker, str _marker];
}];