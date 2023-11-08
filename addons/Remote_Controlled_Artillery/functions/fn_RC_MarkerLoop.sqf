/*
	Author: Fluffy
*/


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
			{
				private _result = (markerText _x) regexMatch (format [".*%1[0-9]{1,2}.*/i", RC_Marker_Prefix]);
				if _result then {
					_result = (markerText _x) regexFind ["[0-9]{1,2}", 0];
					_result = _result select 0 select 0 select 0;
					_result = parseNumber _result;
					_markers pushBackUnique [_result, _x];
				};
			} forEach allMapMarkers;

			_markers sort true;
			RC_Artillery_Markers = _markers;
		};
	};
};
