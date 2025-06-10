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

class RscTitles
{
    class ArmaFPV_Dialog
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

            /*
            class Center_target : ctrlStaticPicture
            {
                idc = -1;

                text = "\ArmaFPV\pictures\PRICEL.paa";

                x = 0.5 - GRID_W(2) / 2;
                y = 0.5 - GRID_H(2) / 2 + GRID_H(1.25);
                w = GRID_W(2);
                h = GRID_H(2);
            };
            */

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