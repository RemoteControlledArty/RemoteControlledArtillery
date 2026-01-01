/*
 * Author: Eric & Ascent
 * Creates Arrays for Counter Battery use.
*/

if (!isServer) exitwith {};

RC_CBRad_DetectionTime_P 	= 15;
RC_CBRad_IgnoreTime_P 		= 15;	//doesnt seem to work with 15s, and unclear whats a desirable value
/*
publicVariable "RC_CBRad_DetectionTime_P";
publicVariable "RC_CBRad_IgnoreTime_P";
*/

RC_CBRad_DetectionTime_AI 	= 1;	//15
RC_CBRad_PrepTime_AI 		= 1;	//10
RC_CBRad_ReassignTime_AI 	= 15;
RC_CBRad_IgnoreTime_AI 		= 1;	//15
RC_CBRad_AccuracyRadius_AI 	= 15;
RC_CBRad_ReturnAmount_AI 	= 3;	//1
/*
publicVariable "RC_CBRad_DetectionTime_AI";
publicVariable "RC_CBRad_PrepTime_AI";
publicVariable "RC_CBRad_ReassignTime_AI";
publicVariable "RC_CBRad_IgnoreTime_AI";
publicVariable "RC_CBRad_AccuracyRadius_AI";
*/

RC_CBRad_AI_Array = [];
/*
RC_CBRad_AI_Array_B = [];
RC_CBRad_AI_Array_O = [];
RC_CBRad_AI_Array_I = [];
publicVariable "RC_CBRad_AI_Array_B";
publicVariable "RC_CBRad_AI_Array_O";
publicVariable "RC_CBRad_AI_Array_I";
*/

RC_CBRad_Player_Array = [];
/*
RC_CBRad_Player_Array_B = [];
RC_CBRad_Player_Array_O = [];
RC_CBRad_Player_Array_I = [];
publicVariable "RC_CBRad_Player_Array_B";
publicVariable "RC_CBRad_Player_Array_O";
publicVariable "RC_CBRad_Player_Array_I";
*/

RC_ArtilleryArray = [];
RC_ArtilleryArray_B = [];
RC_ArtilleryArray_O = [];
RC_ArtilleryArray_I = [];
/*
publicVariable "RC_ArtilleryArray_B";
publicVariable "RC_ArtilleryArray_O";
publicVariable "RC_ArtilleryArray_I";
*/

RC_fireMissionArray_B = [];
RC_fireMissionArray_O = [];
RC_fireMissionArray_I = [];
/*
publicVariable "RC_fireMissionArray_B";
publicVariable "RC_fireMissionArray_O";
publicVariable "RC_fireMissionArray_I";
*/