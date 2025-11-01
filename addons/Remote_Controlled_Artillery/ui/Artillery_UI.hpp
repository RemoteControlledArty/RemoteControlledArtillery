#include "..\script_component.hpp"
/* #Huxaga
$[
	1.063,
	["ArtilleryThing",[["(safeZoneX + (safeZoneW - ((safeZoneW / safeZoneH) min 1.2)) / 2)","(safeZoneY + (safeZoneH - (((safeZoneW / safeZoneH) min 1.2) / 1.2)) / 2)","((safeZoneW / safeZoneH) min 1.2)","(((safeZoneW / safeZoneH) min 1.2) / 1.2)"],"(((safeZoneW / safeZoneH) min 1.2) / 40)","((((safeZoneW / safeZoneH) min 1.2) / 1.2) / 25)","GUI_GRID"],2,0,0],
	[1001,"",[1,"CH: 0",["0.871267 * safezoneW + safezoneX","0.0599647 * safezoneH + safezoneY","0.0247512 * safezoneW","0.0330027 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","0.8"],[]],
	[1002,"",[1,"AZ: 0000",["0.902206 * safezoneW + safezoneX","0.0599647 * safezoneH + safezoneY","0.0371267 * safezoneW","0.0330027 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","0.8"],[]],
	[1003,"",[1,"EL: 0000",["0.951709 * safezoneW + safezoneX","0.0599647 * safezoneH + safezoneY","0.0309389 * safezoneW","0.0330027 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","0.8"],[]],
	[1004,"",[1,"DIST: 0000",["0.871219 * safezoneW + safezoneX","0.0819664 * safezoneH + safezoneY","0.0371219 * safezoneW","0.0330027 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","0.8"],[]],
	[1005,"",[1,"T: 0",["0.871219 * safezoneW + safezoneX","0.103968 * safezoneH + safezoneY","0.0247479 * safezoneW","0.0330027 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","0.8"],[]],
	[1006,"",[1,"T AZ: 0000",["0.902154 * safezoneW + safezoneX","0.0819664 * safezoneH + safezoneY","0.0371267 * safezoneW","0.0330027 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","0.8"],[]],
	[1007,"",[1,"DIF: 0000",["0.95165 * safezoneW + safezoneX","0.0819664 * safezoneH + safezoneY","0.0309389 * safezoneW","0.0330027 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","0.8"],[]]
]
*/

/*
	Author: Fluffy
*/

class RC_Artillery_Base
{
	idd = -1;
	movingEnable = 0;
	duration = 9999;
	fadeIn = "false";
	fadeOut = "false";
	
	//sizeEx = 0.8 * safezoneH

	////////////////////////////////////////////////////////
	// GUI EDITOR OUTPUT START (by Fluffy, v1.063, #Huxaga)
	////////////////////////////////////////////////////////

	class RscText_1001: RscText
	{
		idc = IDC_CHARGE;
		text = "CH: 0"; //--- ToDo: Localize;
		x = "0.871267 * safezoneW + safezoneX";
		y = "0.1199294 * safezoneH + safezoneY";
		w = "0.0801219 * safezoneW";
		h = "0.0330027 * safezoneH";
		sizeEx = "0.55 * (0.0330027 * safezoneH)";
	};
	class RscText_1002: RscText_1001
	{
		idc = IDC_AZIMUTH;
		text = "AZ: 0000"; //--- ToDo: Localize;
		x = "0.915206 * safezoneW + safezoneX";
		y = "0.1199294 * safezoneH + safezoneY";
	};
	class RscText_1003: RscText_1001
	{
		idc = IDC_ELEVATION;
		text = "EL: 0000"; //--- ToDo: Localize;
		x = "0.951709 * safezoneW + safezoneX";
		y = "0.1199294 * safezoneH + safezoneY";
	};
	class RscText_1004: RscText_1001
	{
		idc = IDC_DISTANCE;
		text = "DIST: 0000"; //--- ToDo: Localize;
		x = "0.871219 * safezoneW + safezoneX";
		y = "0.1419311 * safezoneH + safezoneY";
	};
	class RscText_1005: RscText_1001
	{
		idc = IDC_TARGET;
		text = "T: 0"; //--- ToDo: Localize;
		x = "0.871219 * safezoneW + safezoneX";
		y = "0.1639327 * safezoneH + safezoneY";
	};
	class RscText_1006: RscText_1001
	{
		idc = IDC_TARGET_AZIMUTH;
		text = "T AZ: 0000"; //--- ToDo: Localize;
		x = "0.915154 * safezoneW + safezoneX";
		y = "0.1419311 * safezoneH + safezoneY";
	};
	class RscText_1007: RscText_1001
	{
		idc = IDC_DIFFERENCE;
		text = "DIF: 0000"; //--- ToDo: Localize;
		x = "0.95165 * safezoneW + safezoneX";
		y = "0.1419311 * safezoneH + safezoneY";
	};
	class RscText_1008: RscText_1001
	{
		idc = IDC_HIGHSOL;
		text = "high EL: 0000"; //--- ToDo: Localize;

		x = "0.95165 * safezoneW + safezoneX";
		y = "0.1639327 * safezoneH + safezoneY";
	};
	class RscText_1010: RscText_1001
	{
		idc = IDC_HIGHETA;
		text = "ETA: 000"; //--- ToDo: Localize;
		x = "0.915154 * safezoneW + safezoneX";
		y = "0.1639327 * safezoneH + safezoneY";
	};
	class RscText_1012: RscText_1001
	{
		idc = IDC_MESSAGE;
		text = "READY"; //--- ToDo: Localize;
		x = "0.871267 * safezoneW + safezoneX";
		y = "0.1009294 * safezoneH + safezoneY";
		w = "0.1801219 * safezoneW";
	};
	class RscText_1015: RscText_1001 
	{
		idc = 1015;
		text = "SELECT TARGET ON DATALINK"; //--- ToDo: Localize;
		colorText[] = {1,0,0,1};
		x = "0.885267 * safezoneW + safezoneX";
		y = "0.1819294 * safezoneH + safezoneY";
		h = "0.0850027 * safezoneH";
		w = "0.3001219 * safezoneW";
	};
	class RscText_1016: RscText_1001 
	{
		idc = 1016;
		text = "TO ACTIVATE GUIDAINCE"; //--- ToDo: Localize;
		colorText[] = {1,0,0,1};
		x = "0.891267 * safezoneW + safezoneX";
		y = "0.1979294 * safezoneH + safezoneY";
		h = "0.0850027 * safezoneH";
		w = "0.3001219 * safezoneW";
	};

	//Keybinds Display, by Ascent
	class RscText_1017: RscText_1001 
	{
		idc = IDC_KEY_SELECT;
		text = "select DL target:"; //--- ToDo: Localize;
		colorText[] = {0.4,0.4,0.4,0.4};
		x = "0.891267 * safezoneW + safezoneX";
		y = "0.2179294 * safezoneH + safezoneY";
		h = "0.0850027 * safezoneH";
		w = "0.3001219 * safezoneW";
	};
	class RscText_1018: RscText_1001 
	{
		idc = IDC_KEY_UNSELECT;
		text = "unselect DL target:"; //--- ToDo: Localize;
		colorText[] = {0.4,0.4,0.4,0.4};
		x = "0.891267 * safezoneW + safezoneX";
		y = "0.2339294 * safezoneH + safezoneY";
		h = "0.0850027 * safezoneH";
		w = "0.3001219 * safezoneW";
	};
	class RscText_1019: RscText_1001 
	{
		idc = IDC_KEY_MARKERSF;
		text = "cycle markers ->:"; //--- ToDo: Localize;
		colorText[] = {0.4,0.4,0.4,0.4};
		x = "0.891267 * safezoneW + safezoneX";
		y = "0.2499294 * safezoneH + safezoneY";
		h = "0.0850027 * safezoneH";
		w = "0.3001219 * safezoneW";
	};
	class RscText_1020: RscText_1001 
	{
		idc = IDC_KEY_MARKERSB;
		text = "cycle markers <-:"; //--- ToDo: Localize;
		colorText[] = {0.4,0.4,0.4,0.4};
		x = "0.891267 * safezoneW + safezoneX";
		y = "0.2659294  * safezoneH + safezoneY";
		h = "0.0850027 * safezoneH";
		w = "0.3001219 * safezoneW";
	};
	class RscText_1021: RscText_1001 
	{
		idc = IDC_KEY_CHARGES;
		text = "cycle charges:"; //--- ToDo: Localize;
		colorText[] = {0.4,0.4,0.4,0.4};
		x = "0.891267 * safezoneW + safezoneX";
		y = "0.2819294 * safezoneH + safezoneY";
		h = "0.0850027 * safezoneH";
		w = "0.3001219 * safezoneW";
	};
	class RscText_1022: RscText_1001 
	{
		idc = IDC_KEY_ELUP;
		text = "elevation up:"; //--- ToDo: Localize;
		colorText[] = {0.4,0.4,0.4,0.4};
		x = "0.891267 * safezoneW + safezoneX";
		y = "0.2979294 * safezoneH + safezoneY";
		h = "0.0850027 * safezoneH";
		w = "0.3001219 * safezoneW";
	};
	class RscText_1023: RscText_1001 
	{
		idc = IDC_KEY_ELDOWN;
		text = "elevation down:"; //--- ToDo: Localize;
		colorText[] = {0.4,0.4,0.4,0.4};
		x = "0.891267 * safezoneW + safezoneX";
		y = "0.3139294 * safezoneH + safezoneY";
		h = "0.0850027 * safezoneH";
		w = "0.3001219 * safezoneW";
	};
	class RscText_1024: RscText_1001 
	{
		idc = IDC_KEY_ELSLOW;
		text = "slow elevation:"; //--- ToDo: Localize;
		colorText[] = {0.4,0.4,0.4,0.4};
		x = "0.891267 * safezoneW + safezoneX";
		y = "0.3299294 * safezoneH + safezoneY";
		h = "0.0850027 * safezoneH";
		w = "0.3001219 * safezoneW";
	};
	class RscText_1025: RscText_1001 
	{
		idc = IDC_KEY_AZSLOW;
		text = "slow azimuth: zoom in"; //--- ToDo: Localize;
		colorText[] = {0.4,0.4,0.4,0.4};
		x = "0.891267 * safezoneW + safezoneX";
		y = "0.3459294 * safezoneH + safezoneY";
		h = "0.0850027 * safezoneH";
		w = "0.3001219 * safezoneW";
	};

	//warning for ace scopes bug preventing gun elevation, by Ascent
	class RscText_1026: RscText_1001 
	{
		idc = 1026;
		text = "Warning: Ace adjustable scopes prevent"; //--- ToDo: Localize;
		colorText[] = {0.5,0,0,0.5};
		x = "0.871267 * safezoneW + safezoneX";
		y = "0.3659294 * safezoneH + safezoneY";
		h = "0.0850027 * safezoneH";
		w = "0.3001219 * safezoneW";
	};
	class RscText_1027: RscText_1001 
	{
		idc = 1027;
		text = "gun elevation if the keybinds overlap!"; //--- ToDo: Localize;
		colorText[] = {0.5,0,0,0.5};
		x = "0.876267 * safezoneW + safezoneX";
		y = "0.3819294 * safezoneH + safezoneY";
		h = "0.0850027 * safezoneH";
		w = "0.3001219 * safezoneW";
	};
	class RscText_1028: RscText_1001 
	{
		idc = 1028;
		text = "Disable this warning in addon settings."; //--- ToDo: Localize;
		colorText[] = {0.5,0,0,0.5};
		x = "0.876267 * safezoneW + safezoneX";
		y = "0.3979294 * safezoneH + safezoneY";
		h = "0.0850027 * safezoneH";
		w = "0.3001219 * safezoneW";
	};
	////////////////////////////////////////////////////////
	// GUI EDITOR OUTPUT END
	////////////////////////////////////////////////////////
};
class RC_Artillery: RC_Artillery_Base
{
	onLoad = "uiNameSpace setVariable ['RC_Artillery', _this select 0]";

	controls[]=
	{
		RscText_1001,
		RscText_1002,
		RscText_1003,
		RscText_1004,
		RscText_1005,
		RscText_1006,
		RscText_1007,
		RscText_1008,
		RscText_1009,
		RscText_1010,
		RscText_1011,
		RscText_1012,
		RscText_1013,
		RscText_1014,
		RscText_1015,
		RscText_1016,
		RscText_1017,
		RscText_1018,
		RscText_1019,
		RscText_1020,
		RscText_1021,
		RscText_1022,
		RscText_1023,
		RscText_1024,
		RscText_1025,
		RscText_1026,
		RscText_1027,
		RscText_1028
	};

	class RscText_1008: RscText_1001
	{
		idc = IDC_HIGHSOL;
		text = "high EL: 0000"; //--- ToDo: Localize;

		x = "0.95165 * safezoneW + safezoneX";
		y = "0.1639327 * safezoneH + safezoneY";
	};
	class RscText_1009: RscText_1001
	{
		idc = IDC_LOWSOL;
		text = "low EL: 0000"; //--- ToDo: Localize;

		x = "0.95165 * safezoneW + safezoneX";
		y = "0.1859345 * safezoneH + safezoneY";
	};
	class RscText_1010: RscText_1001
	{
		idc = IDC_HIGHETA;
		text = "ETA: 000"; //--- ToDo: Localize;
		x = "0.915154 * safezoneW + safezoneX";
		y = "0.1639327 * safezoneH + safezoneY";
	};
	class RscText_1011: RscText_1001
	{
		idc = IDC_LOWETA;
		text = "ETA: 000"; //--- ToDo: Localize;
		x = "0.915154 * safezoneW + safezoneX";
		y = "0.1859345 * safezoneH + safezoneY";
	};
	class RscText_1013: RscText_1001 
	{
		idc = 1013;
		text = "RAISE CAMERA INTO SKY"; //--- ToDo: Localize;
		colorText[] = {1,0,0,1};
		x = "0.891267 * safezoneW + safezoneX";
		y = "0.1819294 * safezoneH + safezoneY";
		h = "0.0850027 * safezoneH";
		w = "0.3001219 * safezoneW";
	};
	class RscText_1014: RscText_1001 
	{
		idc = 1014;
		text = "FOR SUBMUNITIONS TO WORK"; //--- ToDo: Localize;
		colorText[] = {1,0,0,1};
		x = "0.885267 * safezoneW + safezoneX";
		y = "0.1979294 * safezoneH + safezoneY";
		h = "0.0850027 * safezoneH";
		w = "0.3001219 * safezoneW";
	};
};
class RC_ULM_Rsc: RC_Artillery_Base
{
	onLoad = "uiNameSpace setVariable ['RC_ULM_Rsc', _this select 0]";

	controls[]=
	{
		RscText_1002,
		RscText_1003,
		RscText_1004,
		RscText_1006,
		RscText_1007,
		RscText_1008,
		RscText_1010,
		RscText_1012,
		RscText_1015,
		RscText_1016,
		RscText_1017,
		RscText_1018,
		RscText_1019,
		RscText_1020,
		RscText_1021,
		RscText_1022,
		RscText_1023,
		RscText_1024,
		RscText_1025,
		RscText_1026,
		RscText_1027,
		RscText_1028,
		RscText_1029,
		RscText_1030,
		RscText_1031,
		RscText_1032,
		RscText_1033
	};

	class RscText_1008: RscText_1001
	{
		idc = IDC_HIGHSOL;
		text = "high EL: 0000"; //--- ToDo: Localize;

		x = "0.95165 * safezoneW + safezoneX";
		y = "0.1639327 * safezoneH + safezoneY";
	};
	class RscText_1010: RscText_1001
	{
		idc = IDC_HIGHETA;
		text = "ETA: 000"; //--- ToDo: Localize;
		x = "0.915154 * safezoneW + safezoneX";
		y = "0.1639327 * safezoneH + safezoneY";
	};
	class RscText_1029: RscText_1001
	{
		idc = IDC_MEDSOL;
		text = "medium EL: 0000"; //--- ToDo: Localize;
		x = "0.95165 * safezoneW + safezoneX";
		y = "0.1859345 * safezoneH + safezoneY";
		/*
		x = "0.95165 * safezoneW + safezoneX";
		y = "0.1639327 * safezoneH + safezoneY";
		*/
	};
	class RscText_1030: RscText_1001
	{
		idc = IDC_MEDETA;
		text = "ETA: 000"; //--- ToDo: Localize;
		x = "0.915154 * safezoneW + safezoneX";
		y = "0.1859345 * safezoneH + safezoneY";
		/*
		x = "0.915154 * safezoneW + safezoneX";
		y = "0.1639327 * safezoneH + safezoneY";
		*/
	};
	class RscText_1031: RscText_1005
	{
		idc = IDC_HIGHMV;
		text = "MV: 000"; //--- ToDo: Localize;
	};
	class RscText_1032: RscText_1005
	{
		idc = IDC_MEDMV;
		text = "MV: 000"; //--- ToDo: Localize;
		y = "0.1859345 * safezoneH + safezoneY";
	};
	class RscText_1033: RscText_1005
	{
		idc = IDC_NEWTARGET;
		y = "0.1199294 * safezoneH + safezoneY";
	};
};
class RC_ULM_old_Rsc: RC_Artillery_Base
{
	onLoad = "uiNameSpace setVariable ['RC_ULM_old_Rsc', _this select 0]";

	controls[]=
	{
		RscText_1001,
		RscText_1002,
		RscText_1003,
		RscText_1004,
		RscText_1005,
		RscText_1006,
		RscText_1007,
		RscText_1008,
		RscText_1010,
		RscText_1012,
		RscText_1015,
		RscText_1016,
		RscText_1017,
		RscText_1018,
		RscText_1019,
		RscText_1020,
		RscText_1021,
		RscText_1022,
		RscText_1023,
		RscText_1024,
		RscText_1025,
		RscText_1026,
		RscText_1027,
		RscText_1028
	};

	class RscText_1008: RscText_1001
	{
		idc = IDC_HIGHSOL;
		text = "high EL: 0000"; //--- ToDo: Localize;

		x = "0.95165 * safezoneW + safezoneX";
		y = "0.1639327 * safezoneH + safezoneY";
	};
	class RscText_1010: RscText_1001
	{
		idc = IDC_HIGHETA;
		text = "ETA: 000"; //--- ToDo: Localize;
		x = "0.915154 * safezoneW + safezoneX";
		y = "0.1639327 * safezoneH + safezoneY";
	};
};