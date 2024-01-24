/*
	Author: Fluffy
*/


count (allUnits apply {typeof _x == "RC_InvisibleDatalinkTarget_B"})

RC_Artillery_Markers = [];
RC_Current_Target = [];
RC_Current_Index = 0;
RC_InUI = false;
RC_GPS_ClassNames = ["RC_InvisibleDatalinkTarget_B", "RC_InvisibleDatalinkTarget_O", "RC_InvisibleDatalinkTarget_I"];

if !hasInterface exitWith {};

RC_Marker_Loop = [] spawn {

	while {true} do {
		sleep RC_Update_Number;
		
		if (RC_InUI) then {
			_markers = [];
			_activeGPSMarkers = [];
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
					if (_activeGPSMarkers findIf {_x isEqualTo _currentMarker} == -1) then {

						// Find out which side the GPS Target should belong to
						_gpsTargetClass = switch (_side) do {
							case west: {RC_GPS_ClassNames select 0};
							case east: {RC_GPS_ClassNames select 1};
							case independent: {RC_GPS_ClassNames select 2};
							default {systemChat "Player Side undetermined"};
						};
						
						// Create Target
						_gpsTarget = _gpsTargetClass createVehicleLocal (markerPos _x);

						// Spawn a little script to handle the GPS target					
						[_x ,_gpsTarget, _side] spawn {

							params ["_watchedMarker", "_gpsTarget", "_side"];

							_moveHandler = addMissionEventHandler ["MarkerUpdated", {
								params ["_marker", "_local"];
								_watchedMarker = _thisArgs select 0;
								_gpsTarget = _thisArgs select 1;

								if (_marker isEqualTo _watchedMarker) then {
									_pos = AGLToASL (markerPos _watchedMarker);
									_gpsTarget setPosASL [_pos select 0, _pos select 1, 1];
								}						
							}, [_watchedMarker, _gpsTarget]];

							_deleteHandler = addMissionEventHandler ["MarkerDeleted", {
								params ["_marker", "_local", "_deleter"];
								_watchedMarker = _thisArgs select 0;
								_gpsTarget = _thisArgs select 1;
								_moveHandler = _thisArgs select 2;

								if (_marker isEqualTo _watchedMarker) then {
									deleteVehicle _gpsTarget;
									removeMissionEventHandler ["MarkerUpdated", _moveHandler];
									removeMissionEventHandler [_thisEventHandler, _moveHandler];
								}
							}, [_watchedMarker, _gpsTarget, _moveHandler]];

							// While the GPS target is alive we Report to Datalink
							while {alive _gpsTarget} do {
								_side reportRemoteTarget [_gpsTarget, 5];
								sleep 1;
							};
						};

					_activeGPSMarkers pushBack _x;
					};
				};
				
			} forEach allMapMarkers;

			_markers sort true;
			RC_Artillery_Markers = _markers;
		};
	};
};