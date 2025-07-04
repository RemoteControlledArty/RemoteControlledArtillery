/*
	Author: Fluffy, Eric, Ascent
*/

if (!hasInterface) exitWith { };

addMissionEventHandler ["MarkerCreated", {
	params ["_marker", "_channelNumber", "_owner", "_local"];

	private _markerIndex = RC_Artillery_Markers findIf { (_x select 1) isEqualTo _marker };
	if (_markerIndex > -1) then {
		RC_Artillery_Markers deleteAt _markerIndex;	
	};

	/* Check if Marker starts with RC_Marker_Prefix or RC_GPS_Prefix */
	private _markerText = markerText _marker;
	private _isArtyMarker = (toLower (_markerText select [0, count RC_Marker_Prefix])) isEqualTo (toLower RC_Marker_Prefix);
	private _isGPSMarker = (toLower (_markerText select [0, count RC_GPS_Prefix])) isEqualTo (toLower RC_GPS_Prefix);
	if (!_isArtyMarker && { !_isGPSMarker }) exitWith { };

	if (_isArtyMarker) exitWith {
		_targetIndex = _markerText regexFind ["[0-9]{1,2}", 0];
		_targetIndex = (flatten _targetIndex) select 0;
		_targetIndex = parseNumber _targetIndex;

		RC_Artillery_Markers pushBackUnique [_targetIndex, _marker];
		RC_Artillery_Markers sort true;
	};

	if (_isGPSMarker) exitWith {
		_gpsTarget = createVehicleLocal ["RC_GPSDatalinkTarget", (markerPos _marker), [], 0, "CAN_COLLIDE"];
		_gpsTarget setPosATL (markerPos _marker);

		_side = side player;
		[{
			params ["_args", "_thisHandler"];
			_args params ["_marker", "_side"];

			private _markerIndex = activeGPSMarkers findIf { (_x select 0) isEqualTo _marker };
			if (_markerIndex isEqualTo -1) exitWith { [_thisHandler] call CBA_fnc_removePerFrameHandler };

			(activeGPSMarkers select _markerIndex) params ["", "_gpsTarget"];

			_side reportRemoteTarget [_gpsTarget, 2];
		}, 1, [_marker, _side]] call CBA_fnc_addPerFrameHandler;

		activeGPSMarkers pushBackUnique [_marker, _gpsTarget];
	};
}];

addMissionEventHandler ["MarkerDeleted", {
	params ["_marker", "_local", "_deleter"];

	private _markerIndex = activeGPSMarkers findIf { (_x select 0) isEqualTo _marker };
	if (_markerIndex > -1) exitWith {
		(activeGPSMarkers select _markerIndex) params ["", "_gpsTarget"];
		deleteVehicle _gpsTarget;

		activeGPSMarkers deleteAt _markerIndex;
	};

	_markerIndex = RC_Artillery_Markers findIf { (_x select 1) isEqualTo _marker };
	if (_markerIndex > -1) exitWith {
		RC_Artillery_Markers deleteAt _markerIndex;
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
}];