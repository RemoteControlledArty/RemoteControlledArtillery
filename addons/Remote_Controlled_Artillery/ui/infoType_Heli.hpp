class RscOptics_AV_pilot;
class RC_RscOptics_AV_Heli_Core: RscOptics_AV_pilot
{
    class DriverOpticsGroup;
};
class RC_RscOptics_AV_Heli: RC_RscOptics_AV_Heli_Core
{
    class DriverOpticsGroup: DriverOpticsGroup
    {
        class controls
        {
            class TextMag
            {
                access = 0;
                colorBackground[] = {0,0,0,0};
                colorShadow[] = {0,0,0,0.5};
                colorText[] = {1,1,1,1};    
                deletable = 0;
                fade = 0;
                fixedWidth = 0;
                font = "EtelkaMonospacePro";
                h = "1 * 		(0.025 * SafezoneH)";
                idc = 1011;
                linespacing = 1;
                shadow = 0;
                sizeEx = "0.02*SafezoneH";
                style = 0;
                text = "CAM MAG:";
                tooltipColorBox[] = {1,1,1,1};
                tooltipColorShade[] = {0,0,0,0.65};
                tooltipColorText[] = {1,1,1,1};
                type = 0;
                w = "5 * 		(0.01875 * SafezoneH)";
                x = "5.8 * 		(0.01875 * SafezoneH)";
                y = "7 * 		(0.025 * SafezoneH)";
            };
            class OpticsZoom
            {
                access = 0;
                colorBackground[] = {0,0,0,0};
                colorShadow[] = {0,0,0,0.5};
                colorText[] = {1,1,1,1};
                deletable = 0;  
                fade = 0;
                fixedWidth = 0;
                font = "EtelkaMonospacePro";
                h = "1 * 		(0.025 * SafezoneH)";
                idc = 192;
                linespacing = 1;
                shadow = 0;
                sizeEx = "0.02*SafezoneH";
                style = 0;
                text = "28x";
                tooltipColorBox[] = {1,1,1,1};
                tooltipColorShade[] = {0,0,0,0.65};
                tooltipColorText[] = {1,1,1,1};
                type = 0;
                w = "6 * 		(0.01875 * SafezoneH)";
                x = "10.3 * 		(0.01875 * SafezoneH)";
                y = "7 * 		(0.025 * SafezoneH)";
            };
            class AnalogueHorizon
            {
                access = 0;
                bottomValue = -90;
                colorBackground[] = {0,0,0,0};
                colorText[] = {1,1,1,1};
                deletable = 0;
                fade = 0;
                fixedWidth = 0;
                font = "TahomaB";
                h = "30 * 		(0.025 * SafezoneH)";
                idc = 383;
                lineSpacing = 0;
                shadow = 0;
                sizeEx = 0;
                style = 48;
                text = "\A3\Ui_f\data\IGUI\Cfg\HelicopterHUD\horizon_ladder_ca.paa";
                tooltipColorBox[] = {1,1,1,1};
                tooltipColorShade[] = {0,0,0,0.65};
                tooltipColorText[] = {1,1,1,1}; 
                topValue = 90;
                type = 0;
                visibleRange = -1;
                w = "20 * 		(0.01875 * SafezoneH)";
                x = "16.75 * 		(0.01875 * SafezoneH)";
                y = "5 * 		(0.025 * SafezoneH)";
            };
        };
    };
};