/*
 * Author: Eric & Ascent
 * Creates Arrays for Counter Battery use.
*/

if (!isServer) exitwith {};

RC_CBRad_DetectionTime_P 	= 15;
RC_CBRad_IgnoreTime_P 		= 7.5;	//doesnt seem to work, and unclear whats a desirable value

RC_CBRad_DetectionTime_AI 	= 15;
RC_CBRad_PrepTime_AI 		= 10;
RC_CBRad_ReassignTime_AI 	= 15;
RC_CBRad_IgnoreTime_AI 		= 7.5;	//doesnt seem to work, and unclear whats a desirable value
RC_CBRad_AccuracyRadius_AI 	= 15;
RC_CBRad_ReturnAmount_AI 	= 3;

RC_CBRad_AI_Array = [];
RC_CBRad_Player_Array = [];

RC_ArtilleryArray = [];
RC_ArtilleryArray_B = [];
RC_ArtilleryArray_O = [];
RC_ArtilleryArray_I = [];

RC_fireMissionArray_B = [];
RC_fireMissionArray_O = [];
RC_fireMissionArray_I = [];