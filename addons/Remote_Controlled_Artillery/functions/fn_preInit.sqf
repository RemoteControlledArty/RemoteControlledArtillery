/*
 * Author: Eric & Ascent
 * Declare Global variables
*/

RC_ETA_weapon = "";
RC_ETA_targetName = "";
RC_ETA_aligned = "";
RC_ETA_realElevation = 0;
RC_ETA_realAzimuth = 0;
RC_ETA_distance = 0;
RC_ETA_charge = 0;
RC_ETA_travelTimeLow = 0;
RC_ETA_lowAngleSol = 0;
RC_ETA_travelTimeHigh = 0;
RC_ETA_highAngleSol = 0;

activeGPSMarkers = [];
RC_Artillery_Markers = [];
RC_Current_Target = [];
RC_UV_favs = [];
RC_FPV_Deployers = [];

RC_Current_Index = 0;
RC_RscOn = false;		//in Rsc
RC_InUI = false;

RC_SpawCount = 3;	//original value, unclear if written correctly
RC_SpawnCount = 3;	//backup until useplace of value found