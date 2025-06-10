class RscText;
class ctrlControlsGroupNoScrollBars;
class ctrlControlsGroup;
class ctrlStaticBackground;
class ctrlStaticPicture;
class ctrlStructuredText;

#define GRID_W( num ) ( num * ( pixelGridNoUIScale * pixelW * 2 ))
#define GRID_H( num ) ( num * ( pixelGridNoUIScale * pixelH * 2 ))

#define LINE_WIDTH (safeZoneW * 0.15)
#define LINE_HEIGHT (safeZoneH)

#define WX_POS (safeZoneXAbs + LINE_WIDTH)
#define WY_POS (safeZoneY)
#define W_WIDTH (safeZoneWAbs - 2*LINE_WIDTH)
#define W_HEIGHT (safeZoneH)


class RscUnitInfo;
class RscControlsGroup;
class VScrollbar;
class HScrollbar;
class TextGrid;
class RscPicture;
class RscLadderPicture;
//class RscIGUIText;

class RscInGameUI
{
    class RscOptics_AV_pilot_RC_Crocus: RscUnitInfo
	{
		idd=300;
		controls[]=
		{
			"WeaponInfoControlsGroupRight",
			"CA_BackgroundVehicle",
			"CA_BackgroundVehicleTitle",
			"CA_BackgroundVehicleTitleDark",
			"CA_BackgroundFuel",
			"CA_Vehicle",
			"CA_VehicleRole",
			"CA_HitZones",
			"CA_VehicleTogglesBackground",
			"CA_VehicleToggles",
			"CA_SpeedBackground",
			"CA_SpeedUnits",
			"CA_Speed",
			"CA_ValueFuel",
			"CA_AltBackground",
			"CA_AltUnits",
			"CA_Alt",
			"DriverOpticsGroup"
		};
		class DriverOpticsGroup: RscControlsGroup
		{
			idc=392;
			class VScrollbar: VScrollbar
			{
				width=0;
			};
			class HScrollbar: HScrollbar
			{
				height=0;
			};
			x="0 * 		(0.01875 * SafezoneH) + 		(SafezoneX + ((SafezoneW - SafezoneH) / 2))";
			y="0 * 		(0.025 * SafezoneH) + 		(SafezoneY)";
			w="53.5 * 		(0.01875 * SafezoneH)";
			h="40 * 		(0.025 * SafezoneH)";
			class controls
			{
				class TextGrid: RscText
				{
					style=0;
					sizeEx="0.02*SafezoneH";
					shadow=0;
					font="EtelkaMonospacePro";
					idc=1005;
					text="GRID:";
					x="5.8 * 		(0.01875 * SafezoneH)";
					y="31.8 * 		(0.025 * SafezoneH)";
					w="5 * 		(0.01875 * SafezoneH)";
					h="1 * 		(0.025 * SafezoneH)";
				};
				class ValueGrid: TextGrid
				{
					idc=189;
					text="382546";
					x="10.3 * 		(0.01875 * SafezoneH)";
					y="31.8 * 		(0.025 * SafezoneH)";
					w="6 * 		(0.01875 * SafezoneH)";
					h="1 * 		(0.025 * SafezoneH)";
				};
				class TextTime: TextGrid
				{
					idc=1010;
					text="TIME [UTC]:";
					x="5.8 * 		(0.01875 * SafezoneH)";
					y="32.6 * 		(0.025 * SafezoneH)";
					w="5 * 		(0.01875 * SafezoneH)";
					h="1 * 		(0.025 * SafezoneH)";
				};
				class ValueTime: TextGrid
				{
					idc=101;
					text="20:28:35";
					x="10 * 		(0.01875 * SafezoneH)";
					y="32.6 * 		(0.025 * SafezoneH)";
					w="6 * 		(0.01875 * SafezoneH)";
					h="1 * 		(0.025 * SafezoneH)";
				};
                /*
                class Target: RscIGUIText
                {
                    IDC=107;
                    text="tgttype";
                    x="10 * 		(0.01875 * SafezoneH)";
					y="32.6 * 		(0.025 * SafezoneH)";
                    //x=0;
                    //y="1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
                    w="(profilenamespace getvariable [""IGUI_GRID_CUSTOMINFORIGHT_W"",		(10 * (((safezoneW / safezoneH) min 1.2) / 40))])";
                    h="1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
                };
                */
                /*
				class BorderLineSpdTop: RscPicture
				{
					idc=1203;
					text="\A3\Ui_f\data\IGUI\Cfg\HelicopterHUD\border_line_ca.paa";
					x="3.343 * 		(0.01875 * SafezoneH)";
					y="12.4 * 		(0.025 * SafezoneH)";
					w="3 * 		(0.01875 * SafezoneH)";
					h="1 * 		(0.025 * SafezoneH)";
				};
				class BorderLineSpdBottom: RscPicture
				{
					idc=1207;
					text="\A3\Ui_f\data\IGUI\Cfg\HelicopterHUD\border_line_ca.paa";
					x="3.343 * 		(0.01875 * SafezoneH)";
					y="26.5 * 		(0.025 * SafezoneH)";
					w="3 * 		(0.01875 * SafezoneH)";
					h="1 * 		(0.025 * SafezoneH)";
				};
				class BorderLineAltTop: RscPicture
				{
					idc=1205;
					text="\A3\Ui_f\data\IGUI\Cfg\HelicopterHUD\border_line_ca.paa";
					x="47.16 * 		(0.01875 * SafezoneH)";
					y="12.4 * 		(0.025 * SafezoneH)";
					w="3 * 		(0.01875 * SafezoneH)";
					h="1 * 		(0.025 * SafezoneH)";
				};
				class BorderLineAltBottom: RscPicture
				{
					idc=1206;
					text="\A3\Ui_f\data\IGUI\Cfg\HelicopterHUD\border_line_ca.paa";
					x="47.16 * 		(0.01875 * SafezoneH)";
					y="26.5 * 		(0.025 * SafezoneH)";
					w="3 * 		(0.01875 * SafezoneH)";
					h="1 * 		(0.025 * SafezoneH)";
				};
                */
				class TextSpd: TextGrid
				{
					idc=1004;
                    sizeEx="0.03*SafezoneH";
					text="SPD";
                    x="6.4 * 		(0.01875 * SafezoneH)";
					y="19.5 * 		(0.025 * SafezoneH)";
					w="6 * 		(0.01875 * SafezoneH)";
					h="1.2 * 		(0.025 * SafezoneH)";
				};
                /*
				class SpeedValueBorder: RscPicture
				{
					idc=1200;
					text="\A3\Ui_f\data\IGUI\Cfg\HelicopterHUD\altimeter_value_ca.paa";
					x="6.3 * 		(0.01875 * SafezoneH)";
					y="19 * 		(0.025 * SafezoneH)";
					w="5 * 		(0.01875 * SafezoneH)";
					h="2 * 		(0.025 * SafezoneH)";
				};
                */
				class CA_Speed: TextGrid
				{
					idc=190;
					sizeEx="0.03*SafezoneH";
					text="120";
					x="8.5 * 		(0.01875 * SafezoneH)";
					y="19.5 * 		(0.025 * SafezoneH)";
					w="6 * 		(0.01875 * SafezoneH)";
					h="1.2 * 		(0.025 * SafezoneH)";
				};
				class TextAlt: TextGrid
				{
					idc=1006;
                    sizeEx="0.03*SafezoneH";
					text="ALT";
                    x="45.2 * 		(0.01875 * SafezoneH)";
					y="19.5 * 		(0.025 * SafezoneH)";
					w="3.2 * 		(0.01875 * SafezoneH)";
					h="1.2 * 		(0.025 * SafezoneH)";
				};
                /*
				class AltValueBorder: RscPicture
				{
					idc=1201;
					text="\A3\Ui_f\data\IGUI\Cfg\HelicopterHUD\airspeed_value_ca.paa";
					x="42.25 * 		(0.01875 * SafezoneH)";
					y="19 * 		(0.025 * SafezoneH)";
					w="5 * 		(0.01875 * SafezoneH)";
					h="2 * 		(0.025 * SafezoneH)";
				};
                */
				class CA_Alt: TextGrid
				{
					idc=191;
					sizeEx="0.03*SafezoneH";
					style=1;
					text="3825";
					x="42 * 		(0.01875 * SafezoneH)";
					y="19.5 * 		(0.025 * SafezoneH)";
					w="3.2 * 		(0.01875 * SafezoneH)";
					h="1.2 * 		(0.025 * SafezoneH)";
				};
				class AnalogueHorizon: RscLadderPicture
				{
					idc=383;
					topValue=90;
					bottomValue=-90;
					visibleRange=-1;
					text="\A3\Ui_f\data\IGUI\Cfg\HelicopterHUD\horizon_ladder_ca.paa";
					x="16.75 * 		(0.01875 * SafezoneH)";
					y="5 * 		(0.025 * SafezoneH)";
					w="20 * 		(0.01875 * SafezoneH)";
					h="30 * 		(0.025 * SafezoneH)";
				};
			};
		};
	};
};

class RscTitles
{
    class ArmaFPV_DialogNew
    {
        idd = -1;
        duration = 1e+038;
        movingEnable = false;
        enableSimulation = true;

        class controls
        {
            class LeftLine : RscText
            {
                idc = -1;

                x = safeZoneXAbs;
                y = safeZoneY;
                w = LINE_WIDTH;
                h = LINE_HEIGHT;

                colorBackground[] = {0, 0, 0, 1};
            };

            class RightLine : LeftLine
            {
                x = safeZoneXAbs + safeZoneWAbs - LINE_WIDTH;
            };

            class CommunicationGroup : ctrlControlsGroupNoScrollBars
            {
                idc = -1;

                x = WX_POS + W_WIDTH - GRID_W(6) - GRID_W(2); 
                y = WY_POS + GRID_H(6);
                w = GRID_W(6);
                h = GRID_H(2);

                class controls
                {
                    class CommunicationPicture : ctrlStaticPicture
                    {
                        idc = -1;

                        text = "\ArmaFPV\pictures\100.paa";
                        onLoad = "uiNameSpace setVariable [""ArmaFPV_SignalPicture"", _this # 0];";

                        x = 0.0;
                        y = 0.0 + GRID_H(2) / 2 - GRID_H(1) / 2;
                        w = GRID_W(3) / 2;
                        h = GRID_H(1);
                    };

                    class CommunicationText : ctrlStructuredText
                    {
                        idc = -1;

                        onLoad = "uiNameSpace setVariable [""ArmaFPV_SignalText"", _this # 0];";

                        class Attributes
                        {
                            font = "VCROSDMono";
                            align = "center";
                            shadow = 1;
                        };

                        shadow = 0;
                        size = GRID_H(1.8);

                        text = "27";

                        x = 0.0;
                        y = 0.0;
                        w = GRID_W(6);
                        h = GRID_H(2);
                    };
                };
            };

            class BatteryGroup : ctrlControlsGroupNoScrollBars
            {
                idc = -1;

                x = WX_POS + GRID_W(2); 
                y = WY_POS + W_HEIGHT - GRID_H(2) - GRID_H(8);
                w = GRID_W(8);
                h = GRID_H(2);

                class controls
                {
                    class BatteryPicture : ctrlStaticPicture
                    {
                        idc = -1;

                        onLoad = "uiNameSpace setVariable [""ArmaFPV_BatteryPicture"", _this # 0];";

                        text = "\ArmaFPV\pictures\A100.paa";

                        x = 0.0;
                        y = 0.0;
                        w = GRID_W(1);
                        h = GRID_H(1.8);
                    };

                    class BatteryText : ctrlStructuredText
                    {
                        idc = -1;

                        onLoad = "uiNameSpace setVariable [""ArmaFPV_BatteryText"", _this # 0];";

                        class Attributes
                        {
                            font = "VCROSDMono";
                            align = "center";
                            shadow = 1;
                        };

                        shadow = 0;
                        size = GRID_H(1.3);

                        text = "3.79 v";

                        x = 0.0;
                        y = GRID_H(0.3);
                        w = GRID_W(8);
                        h = GRID_H(2);
                    };
                };
            };

            class OnTime_Group : ctrlControlsGroupNoScrollBars
            {
                idc = -1;

                x = WX_POS + W_WIDTH - GRID_W(6) - GRID_W(2); 
                y = WY_POS + W_HEIGHT - GRID_H(2) - GRID_H(8);
                w = GRID_W(10);
                h = GRID_H(2.5);

                class controls
                {
                    class OnTime_Picture : ctrlStaticPicture
                    {
                        idc = -1;

                        text = "\ArmaFPV\pictures\mn.paa";

                        x = 0.0;
                        y = 0.0;
                        w = GRID_W(6) / 2;
                        h = GRID_H(2);
                    };

                    class OnTime_Text : ctrlStructuredText
                    {
                        idc = -1;

                        onLoad = "uiNameSpace setVariable [""ArmaFPV_OnTimeText"", _this # 0];";

                        class Attributes
                        {
                            font = "VCROSDMono";
                            align = "right";
                            shadow = 1;
                        };

                        shadow = 0;
                        size = GRID_H(1.4);

                        text = "03:38";

                        x = 0.0;
                        y = GRID_H(0.3);
                        w = GRID_W(6.5);
                        h = GRID_H(2);
                    };
                };
            };

            class Center_target : ctrlStaticPicture
            {
                idc = -1;

                text = "\ArmaFPV\pictures\PRICEL.paa";

                x = 0.5 - GRID_W(2) / 2;
                y = 0.5 - GRID_H(2) / 2;
                w = GRID_W(2);
                h = GRID_H(2);
            };

            class V_Line_Left : ctrlStaticPicture
            {
                idc = -1;

                text = "\ArmaFPV\pictures\horiz.paa";

                x = 0.5 + GRID_W(10);
                y = 0.5 - GRID_H(12) / 2;
                w = GRID_W(1);
                h = GRID_H(12);
            };

            class V_Line_Right : V_Line_Left
            {
                x = 0.5 - GRID_W(10);
            };

            class MainText : ctrlStructuredText
            {
                idc = -1;

                class Attributes
                {
                    font = "VCROSDMono";
                    align = "center";
                    shadow = 1;
                };

                shadow = 0;
                size = GRID_H(1.4);

                onLoad = "uiNameSpace setVariable [""ArmaFPV_MainText"", _this # 0];";

                text = "";

                x = WX_POS + W_WIDTH / 2 - GRID_W(20) / 2;
                y = 0.5 - GRID_H(12) / 2 - GRID_H(1.6);
                w = GRID_W(20);
                h = GRID_H(1.6);
            };
        };
    };
};