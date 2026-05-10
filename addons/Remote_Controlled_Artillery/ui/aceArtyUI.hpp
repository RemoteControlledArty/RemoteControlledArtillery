class RscInGameUI
{
	//class RscUnitInfo;

	class RscWeaponRangeArtillery;
    class RC_RscArty: RscWeaponRangeArtillery
    {
        //onLoad = "RC_RscOn = true; uiNamespace setVariable ['ACE_dlgArtillery', _this select 0]; ['ace_infoDisplayChanged', [_this select 0, 'Artillery']] call CBA_fnc_localEvent;";
        onLoad="RC_RscOn = true;";
        onUnload="RC_RscOn = false;";
    };

    class RscWeaponRangeArtilleryAuto;
    class RC_RscArtyAuto: RscWeaponRangeArtilleryAuto
    {
        //onLoad = "RC_RscOn = true; uiNamespace setVariable ['ACE_dlgArtillery', _this select 0]; ['ace_infoDisplayChanged', [_this select 0, 'Artillery']] call CBA_fnc_localEvent;";
        onLoad="RC_RscOn = true;";
        onUnload="RC_RscOn = false;";
    };

    #include "\Remote_Controlled_Artillery\ui\infoType_Heli.hpp"
};