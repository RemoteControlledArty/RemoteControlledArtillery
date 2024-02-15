/*
	Author: Fluffy
*/

activeGPSMarkers = [];
RC_Artillery_Markers = [];
RC_Current_Target = [];
RC_Current_Index = 0;
RC_InUI = false;

if !hasInterface exitWith {};

RC_Marker_Loop = [] spawn {

	while {true} do {
		sleep RC_Update_Number;
		
		if (RC_InUI) then {
			_markers = [];
			_side = side player;
			{
				private _result = (markerText _x) regexMatch (format [".*%1[0-9]{1,2}.*/i", RC_Marker_Prefix]);
				if _result then {
					_result = (markerText _x) regexFind ["[0-9]{1,2}", 0];
					_result = _result select 0 select 0 select 0;
					_result = parseNumber _result;
					_markers pushBackUnique [_result, _x];
				};

				// Find a Marker with the GPS Prefix
				private _gpsResult = (markerText _x) regexMatch (format [".*%1[0-9]{1,2}.*/i", RC_GPS_Prefix]);
				if _gpsResult then {
					_currentMarker = _x;
					if (activeGPSMarkers findIf {_x isEqualTo _currentMarker} == -1) then {
						
						// Create Target
						//gpsTarget = createVehicle ["RC_GPSDatalinkTarget", (markerPos _x), [], 0, "CAN_COLLIDE"];
						gpsTarget = createVehicleLocal ["RC_GPSDatalinkTarget", (markerPos _x), [], 0, "CAN_COLLIDE"];

						// Spawn a little script to handle the GPS target					
						[_x, _side] spawn {

							params ["_watchedMarker", "_side"];

							_moveHandler = addMissionEventHandler ["MarkerUpdated", {
								params ["_marker", "_local"];
								_watchedMarker = _thisArgs select 0;

								if (_marker isEqualTo _watchedMarker) then {
									_pos = AGLToASL (markerPos _watchedMarker);
									gpsTarget setPosASL [_pos select 0, _pos select 1, 1];
								}						
							}, [_watchedMarker]];

							_deleteHandler = addMissionEventHandler ["MarkerDeleted", {
								params ["_marker", "_local", "_deleter"];
								_watchedMarker = _thisArgs select 0;
								_moveHandler = _thisArgs select 1;	//2 before

								if (_marker isEqualTo _watchedMarker) then {
									deleteVehicle gpsTarget;
									removeMissionEventHandler ["MarkerUpdated", _moveHandler];
									removeMissionEventHandler ["MarkerDeleted", _thisEventHandler];
								}
							}, [_watchedMarker, _moveHandler]];

							// While the GPS target is alive we Report to Datalink
							while {alive gpsTarget} do {
								_side reportRemoteTarget [gpsTarget, 5];
								sleep 1;
							};
						};

						activeGPSMarkers pushBack _x;
					};
				};
			} forEach allMapMarkers;

			_markers sort true;
			RC_Artillery_Markers = _markers;
		};
	};
};
