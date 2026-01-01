class RscOptics_AV_pilot;
class RC_RscOptics_AV_Heli_Core: RscOptics_AV_pilot
{
    class DriverOpticsGroup;
    class controls;
};
class RC_RscOptics_AV_Heli: RC_RscOptics_AV_Heli_Core
{
    class DriverOpticsGroup: DriverOpticsGroup
    {
        class controls: controls
        {
            class HorizonCenter: RscPicture {};
        };
    };
};