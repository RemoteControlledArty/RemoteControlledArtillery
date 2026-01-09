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
            /*
            //RscOptics_crows
            //likely wont work as intended as driverCam isnt gunnerTurret
            class CA_TurretIndicator
            {
                access = 0;
                color[] = {1,1,1,1};  //{0.706,0.0745,0.0196,1};
                colorBackground[] = {0,0,0,0};
                colorText[] = {1,1,1,1};    //{1,1,1,1};
                deletable = 0;
                fade = 0;
                fixedWidth = 0;
                font = "TahomaB";
                h = "6 * (0.025 * SafezoneH)";
                IDC = 206;
                imageGun = "#(rgb,8,8,3)color(0,0,0,0)";
                imageHull = "A3\Ui_f\data\IGUI\RscIngameUI\RscOptics\turretIndicatorHull_RWS.paa";
                imageObsTurret = "#(rgb,8,8,3)color(0,0,0,0)";  
                imageTurret = "A3\Ui_f\data\IGUI\RscIngameUI\RscOptics\turretIndicatorTurret_RWS.paa";
                lineSpacing = 0;    
                shadow = 0;
                sizeEx = 0; 
                style = 0;
                text = "";
                textSize = "0.02*SafezoneH";
                tooltipColorBox[] = {1,1,1,1};
                tooltipColorShade[] = {0,0,0,0.65};
                tooltipColorText[] = {1,1,1,1};
                type = 105;
                w = "6 * (0.01875 * SafezoneH)";
                x = "2.25 * (0.01875 * SafezoneH)";
                y = "29.5 * (0.025 * SafezoneH)";
            };
            class CA_Heading
            {
                access = 0;
                color[] = {1,1,1,1};  //{0.706,0.0745,0.0196,1};
                colorBackground[] = {0,0,0,0};
                colorShadow[] = {0,0,0,0.5};
                colorText[] = {1,1,1,1};  //{0.706,0.0745,0.0196,1};
                deletable = 0;
                fade = 0;   
                fixedWidth = 0;
                font = "EtelkaMonospacePro";
                h = "1 * (0.025 * SafezoneH)";
                idc = 156;  
                linespacing = 1;
                shadow = 0;
                sizeEx = "0.038*SafezoneH"; 
                style = 2;
                text = "015";
                tooltipColorBox[] = {1,1,1,1};
                tooltipColorShade[] = {0,0,0,0.65};
                tooltipColorText[] = {1,1,1,1}; 
                type = 0;
                w = "3 * (0.01875 * SafezoneH)";
                x = "3.65 * (0.01875 * SafezoneH)"; 
                y = "35.9 * (0.025 * SafezoneH)";
            };
            */
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