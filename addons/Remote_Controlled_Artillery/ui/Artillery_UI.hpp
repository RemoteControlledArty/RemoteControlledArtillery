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

class RC_Artillery {
	idd = -1;
	onLoad = "uiNameSpace setVariable ['RC_Artillery', _this select 0]";
	movingEnable = 0;
	duration = 9999;
	fadeIn = "false";
	fadeOut = "false";
	
	//sizeEx = 0.8 * safezoneH
	
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
		RscText_1024
	};
	////////////////////////////////////////////////////////
	// GUI EDITOR OUTPUT START (by Fluffy, v1.063, #Huxaga)
	////////////////////////////////////////////////////////

	class RscText_1001: RscText
	{
		idc = 1001;
		text = "CH: 0"; //--- ToDo: Localize;
		x = "0.871267 * safezoneW + safezoneX";
		y = "0.1199294 * safezoneH + safezoneY";
		w = "0.0801219 * safezoneW";
		h = "0.0330027 * safezoneH";
		sizeEx = "0.55 * (0.0330027 * safezoneH)";
	};
	class RscText_1002: RscText_1001
	{
		idc = 1002;
		text = "AZ: 0000"; //--- ToDo: Localize;
		x = "0.915206 * safezoneW + safezoneX";
		y = "0.1199294 * safezoneH + safezoneY";
	};
	class RscText_1003: RscText_1001
	{
		idc = 1003;
		text = "EL: 0000"; //--- ToDo: Localize;
		x = "0.951709 * safezoneW + safezoneX";
		y = "0.1199294 * safezoneH + safezoneY";
	};
	class RscText_1004: RscText_1001
	{
		idc = 1004;
		text = "DIST: 0000"; //--- ToDo: Localize;
		x = "0.871219 * safezoneW + safezoneX";
		y = "0.1419311 * safezoneH + safezoneY";
	};
	class RscText_1005: RscText_1001
	{
		idc = 1005;
		text = "T: 0"; //--- ToDo: Localize;
		x = "0.871219 * safezoneW + safezoneX";
		y = "0.1639327 * safezoneH + safezoneY";
	};
	class RscText_1006: RscText_1001
	{
		idc = 1006;
		text = "T AZ: 0000"; //--- ToDo: Localize;
		x = "0.915154 * safezoneW + safezoneX";
		y = "0.1419311 * safezoneH + safezoneY";
	};
	class RscText_1007: RscText_1001
	{
		idc = 1007;
		text = "DIF: 0000"; //--- ToDo: Localize;
		x = "0.95165 * safezoneW + safezoneX";
		y = "0.1419311 * safezoneH + safezoneY";
	};
	class RscText_1008: RscText_1001
	{
		idc = 1008;
		text = "H SOL: 0000"; //--- ToDo: Localize;
		x = "0.95165 * safezoneW + safezoneX";
		y = "0.1639327 * safezoneH + safezoneY";
	};
	class RscText_1009: RscText_1001
	{
		idc = 1009;
		text = "L SOL: 0000"; //--- ToDo: Localize;
		x = "0.95165 * safezoneW + safezoneX";
		y = "0.1859345 * safezoneH + safezoneY";
	};
	class RscText_1010: RscText_1001
	{
		idc = 1010;
		text = "ETA: 000"; //--- ToDo: Localize;
		x = "0.915154 * safezoneW + safezoneX";
		y = "0.1639327 * safezoneH + safezoneY";
	};
	class RscText_1011: RscText_1001
	{
		idc = 1011;
		text = "ETA: 000"; //--- ToDo: Localize;
		x = "0.915154 * safezoneW + safezoneX";
		y = "0.1859345 * safezoneH + safezoneY";
	};
	class RscText_1012: RscText_1001
	{
		idc = 1012;
		text = "READY"; //--- ToDo: Localize;
		x = "0.871267 * safezoneW + safezoneX";
		y = "0.1009294 * safezoneH + safezoneY";
		w = "0.1801219 * safezoneW";
	};
	class RscText_1013: RscText_1001 
	{
		idc = 1013;
		text = "RAISE CAMERA INTO SKY"; //--- ToDo: Localize;
		colorText[] = {1,0,0,1};
		x = "0.891267 * safezoneW + safezoneX";
		y = "0.1779294 * safezoneH + safezoneY";
		h = "0.0850027 * safezoneH";
		w = "0.3001219 * safezoneW";
	};
	class RscText_1014: RscText_1001 
	{
		idc = 1014;
		text = "FOR SUBMUNITIONS TO WORK"; //--- ToDo: Localize;
		colorText[] = {1,0,0,1};
		x = "0.885267 * safezoneW + safezoneX";
		y = "0.1939294 * safezoneH + safezoneY";
		h = "0.0850027 * safezoneH";
		w = "0.3001219 * safezoneW";
	};
	class RscText_1015: RscText_1001 
	{
		idc = 1015;
		text = "LOCK TARGET ON DATALINK"; //--- ToDo: Localize;
		colorText[] = {1,0,0,1};
		x = "0.885267 * safezoneW + safezoneX";
		y = "0.1779294 * safezoneH + safezoneY";
		h = "0.0850027 * safezoneH";
		w = "0.3001219 * safezoneW";
	};
	class RscText_1016: RscText_1001 
	{
		idc = 1016;
		text = "TO ACTIVATE GUIDAINCE"; //--- ToDo: Localize;
		colorText[] = {1,0,0,1};
		x = "0.891267 * safezoneW + safezoneX";
		y = "0.1939294 * safezoneH + safezoneY";
		h = "0.0850027 * safezoneH";
		w = "0.3001219 * safezoneW";
	};

	//Keybinds Display, by Ascent
	class RscText_1017: RscText_1001 
	{
		idc = 1017;
		text = "cycle markers ->:"; //--- ToDo: Localize;
		colorText[] = {0.4,0.4,0.4,0.4};
		x = "0.891267 * safezoneW + safezoneX";	//"0.885267 * safezoneW + safezoneX";
		y = "0.2099294 * safezoneH + safezoneY";
		h = "0.0850027 * safezoneH";
		w = "0.3001219 * safezoneW";
		sizeEx = "0.45 * (0.0330027 * safezoneH)";
	};
	class RscText_1018: RscText_1001 
	{
		idc = 1018;
		text = "cycle markers <-:"; //--- ToDo: Localize;
		colorText[] = {0.4,0.4,0.4,0.4};
		x = "0.891267 * safezoneW + safezoneX";	//"0.885267 * safezoneW + safezoneX";
		y = "0.2205961 * safezoneH + safezoneY";
		h = "0.0850027 * safezoneH";
		w = "0.3001219 * safezoneW";
		sizeEx = "0.45 * (0.0330027 * safezoneH)";
	};
	class RscText_1019: RscText_1001 
	{
		idc = 1019;
		text = "select target:"; //--- ToDo: Localize;
		colorText[] = {0.4,0.4,0.4,0.4};
		x = "0.891267 * safezoneW + safezoneX";	//"0.885267 * safezoneW + safezoneX";
		y = "0.2339294 * safezoneH + safezoneY";
		h = "0.0850027 * safezoneH";
		w = "0.3001219 * safezoneW";
		sizeEx = "0.45 * (0.0330027 * safezoneH)";
	};
	class RscText_1020: RscText_1001 
	{
		idc = 1020;
		text = "unselect target:"; //--- ToDo: Localize;
		colorText[] = {0.4,0.4,0.4,0.4};
		x = "0.891267 * safezoneW + safezoneX";	//"0.885267 * safezoneW + safezoneX";
		y = "0.2472627  * safezoneH + safezoneY";
		h = "0.0850027 * safezoneH";
		w = "0.3001219 * safezoneW";
		sizeEx = "0.45 * (0.0330027 * safezoneH)";
	};
	class RscText_1021: RscText_1001 
	{
		idc = 1021;
		text = "cycle charges:"; //--- ToDo: Localize;
		colorText[] = {0.4,0.4,0.4,0.4};
		x = "0.891267 * safezoneW + safezoneX";	//"0.885267 * safezoneW + safezoneX";
		y = "0.2605961 * safezoneH + safezoneY";
		h = "0.0850027 * safezoneH";
		w = "0.3001219 * safezoneW";
		sizeEx = "0.45 * (0.0330027 * safezoneH)";
	};
	class RscText_1022: RscText_1001 
	{
		idc = 1022;
		text = "elevation up:"; //--- ToDo: Localize;
		colorText[] = {0.4,0.4,0.4,0.4};
		x = "0.891267 * safezoneW + safezoneX";	//"0.885267 * safezoneW + safezoneX";
		y = "0.2739294 * safezoneH + safezoneY";
		h = "0.0850027 * safezoneH";
		w = "0.3001219 * safezoneW";
		sizeEx = "0.45 * (0.0330027 * safezoneH)";
	};
	class RscText_1023: RscText_1001 
	{
		idc = 1023;
		text = "elevation down:"; //--- ToDo: Localize;
		colorText[] = {0.4,0.4,0.4,0.4};
		x = "0.891267 * safezoneW + safezoneX";	//"0.885267 * safezoneW + safezoneX";
		y = "0.2872627 * safezoneH + safezoneY";
		h = "0.0850027 * safezoneH";
		w = "0.3001219 * safezoneW";
		sizeEx = "0.45 * (0.0330027 * safezoneH)";
	};
	class RscText_1024: RscText_1001 
	{
		idc = 1024;
		text = "slow elevation:"; //--- ToDo: Localize;
		colorText[] = {0.4,0.4,0.4,0.4};
		x = "0.891267 * safezoneW + safezoneX";	//"0.885267 * safezoneW + safezoneX";
		y = "0.3005961 * safezoneH + safezoneY";
		h = "0.0850027 * safezoneH";
		w = "0.3001219 * safezoneW";
		sizeEx = "0.45 * (0.0330027 * safezoneH)";
	};
	////////////////////////////////////////////////////////
	// GUI EDITOR OUTPUT END
	////////////////////////////////////////////////////////
};
