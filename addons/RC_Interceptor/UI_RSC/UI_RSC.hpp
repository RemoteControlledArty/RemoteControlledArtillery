class CfgWrapperUI
{
	class Cursors
	{
		class Arrow;
		class RC_Blank: Arrow
		{
			texture="\RC_Interceptor\pictures\blank_cursor_ca.paa";
		};
	};
};


class RscText;
class RscTitles
{
	class Default
	{
		idd=-1;
		fadein=0;
		fadeout=0;
		duration=0;
	};
	class SB_RscDisplayUAV
	{
		idd=9999;
		duration=1e+010;
		fadein=0;
		movingEnable=0;
		enableSimulation=0;
		enableDisplay=0;
		class controls
		{
			class GV1: RscText
			{
				x="safezoneX + safezoneW *0.1";
				y="safezoneY";
				w="0.001 * safezoneH";
				h="safezoneH";
				colorBackground[]={0,0,0,0.15000001};
			};
			class GV3: GV1
			{
				x="safezoneX + safezoneW *0.3";
			};
			class GV5: GV1
			{
				x="safezoneX + safezoneW *0.5";
			};
			class GV7: GV1
			{
				x="safezoneX + safezoneW *0.7";
			};
			class GV9: GV1
			{
				x="safezoneX + safezoneW *0.9";
			};
			class GH1: GV1
			{
				x="safezoneX";
				y="safezoneY + safezoneH *0.1";
				w="safezoneW";
				h="0.001 * safezoneH";
			};
			class GH3: GH1
			{
				y="safezoneY + safezoneH *0.3";
			};
			class GH5: GH1
			{
				y="safezoneY + safezoneH *0.5";
			};
			class GH7: GH1
			{
				y="safezoneY + safezoneH *0.7";
			};
			class GH9: GH1
			{
				y="safezoneY + safezoneH *0.9";
			};
			class cross1A: RscText
			{
				x="0.45 - 0.05 * 2 / 4";
				y=0.5;
				w="0.05 * 3 / 4";
				h=0.0020000001;
				text="";
				colorBackground[]={1,1,1,1};
			};
			class cross1B: cross1A
			{
				x="0.55 - 0.05 * 1 / 4";
				y=0.5;
				w="0.05 * 3 / 4";
				h=0.0020000001;
			};
			class cross2A: cross1A
			{
				x=0.5;
				y=0.40000001;
				w="0.002 *3 / 4";
				h=0.050000001;
			};
			class cross2B: cross1A
			{
				x=0.5;
				y=0.55000001;
				w="0.002 *3 / 4";
				h=0.050000001;
			};
		};
	};
};