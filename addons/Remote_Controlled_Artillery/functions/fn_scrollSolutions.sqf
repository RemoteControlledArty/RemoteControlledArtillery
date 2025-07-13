/*
	Author: Fluffy
	
	All Artillery Markers
	RC_Artillery_Markers 
	Markers<MULTIARRAY> [Marker1<MULTIARRAY>, Marker2<MULTIARRAY>]
	
	Selected Artillery Target
	RC_Current_Target
	Marker<MULTIARRAY> [Number<INT>, MarkerName<STRING>]

	Index of Artillery Markers
	RC_Current_Index
	Index<INT>
*/

if ((!RC_InUI) && (!RC_ULM_InUI)) exitWith {};
if (RC_Artillery_Markers isEqualTo []) exitWith {};

params ["_direction"];

_markerCount = count RC_Artillery_Markers;

// Main Handler
if _direction then {
	// Forward
	// If we are at the Final Target
	if (RC_Current_Index >= (_markerCount - 1)) then {
		RC_Current_Index = 0;
	} else {
		// Increment
		RC_Current_Index = RC_Current_Index + 1;
	};
} else {
	// Backward
	if (RC_Current_Index <= 0) then {
		RC_Current_Index = (_markerCount - 1);
	} else {
		RC_Current_Index = RC_Current_Index - 1;
	};
};