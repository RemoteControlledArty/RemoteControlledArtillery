class RscInGameUI
{
	class RscUnitInfo;
	
	class RscWeaponRangeArtillery {
        onLoad = "uiNamespace setVariable ['RCA_ArtyUI',_this select 0]";
    };

    class RscWeaponRangeArtilleryAuto {
        onLoad = "uiNamespace setVariable ['RCA_ArtyUI',_this select 0]";
    };

    class RC_RscWeaponRangeArtilleryAuto: RscWeaponRangeArtilleryAuto {};

    #include "\Remote_Controlled_Artillery\ui\infoType_Heli.hpp"
};