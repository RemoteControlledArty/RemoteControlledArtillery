class RscInGameUI
{
	class RscUnitInfo;
	
	class RscWeaponRangeArtillery
    {
        onLoad = "uiNamespace setVariable ['RCA_ArtyUI',_this select 0]";
    };
    class RscWeaponRangeArtilleryAuto
    {
        onLoad = "uiNamespace setVariable ['RCA_ArtyUI',_this select 0]";
    };

    class RC_RscArty: RscWeaponRangeArtillery
    {
        //onLoad = "RC_RscOn = true; uiNamespace setVariable ['ACE_dlgArtillery', _this select 0]; ['ace_infoDisplayChanged', [_this select 0, 'Artillery']] call CBA_fnc_localEvent;";
        onLoad="RC_RscOn = true;  uiNamespace setVariable ['RCA_ArtyUI',_this select 0]";
        onUnload="RC_RscOn = false;";
    };
    class RC_RscArtyAuto: RscWeaponRangeArtilleryAuto
    {
        //onLoad = "RC_RscOn = true; uiNamespace setVariable ['ACE_dlgArtillery', _this select 0]; ['ace_infoDisplayChanged', [_this select 0, 'Artillery']] call CBA_fnc_localEvent;";
        onLoad="RC_RscOn = true;  uiNamespace setVariable ['RCA_ArtyUI',_this select 0]";
        onUnload="RC_RscOn = false;";
    };

    #include "\Remote_Controlled_Artillery\ui\infoType_Heli.hpp"
};