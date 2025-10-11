class RHS_RscWeaponSosnaU_FCS;
class RC_RHS_RscWeaponSosnaU_FCS: RHS_RscWeaponSosnaU_FCS
{
	scriptName="RscUnitInfo";
	scriptPath="IGUI";
	updateHeightByCrew=0;
	updateWidthByCrew=0;
	updateWidthByWeapon=0;
	idd=300;
	movingEnable=0;

	//RscOptics_MBT_02_gunner
	controls[]={"CA_Zeroing","CA_IGUI_elements_group"};
	//onLoad="[""onLoad"",_this,""RscUnitInfo"",'IGUI'] call (uinamespace getvariable 'BIS_fnc_initDisplay')";
	onUnload="[""onUnload"",_this,""RscUnitInfo"",'IGUI'] call (uinamespace getvariable 'BIS_fnc_initDisplay')";

	///RHS RHS_RscWeaponSosnaU_FCS
	//controls[]={"CA_OpticsZoom","CA_IGUI_elements_group"};
	onLoad="['onLoad',_this,'RscUnitInfo','IGUI'] call (uinamespace getvariable 'BIS_fnc_initDisplay'); _this call RHS_fnc_sight_sosnaU";
	//onUnload="[""onUnload"",_this,""RscUnitInfo"",'IGUI'] call (uinamespace getvariable 'BIS_fnc_initDisplay')";
};
class RHS_RscWeaponSosnaU_commander_FCS;
class RC_RHS_RscWeaponSosnaU_commander_FCS: RHS_RscWeaponSosnaU_commander_FCS
{
	scriptName="RscUnitInfo";
	scriptPath="IGUI";
	updateHeightByCrew=0;
	updateWidthByCrew=0;
	updateWidthByWeapon=0;
	idd=300;
	movingEnable=0;

	//RscOptics_MBT_02_gunner
	controls[]={"CA_Zeroing","CA_IGUI_elements_group"};
	//onLoad="[""onLoad"",_this,""RscUnitInfo"",'IGUI'] call (uinamespace getvariable 'BIS_fnc_initDisplay')";
	onUnload="[""onUnload"",_this,""RscUnitInfo"",'IGUI'] call (uinamespace getvariable 'BIS_fnc_initDisplay')";

	///RHS RHS_RscWeaponSosnaU_FCS
	//controls[]={"CA_OpticsZoom","CA_IGUI_elements_group"};
	onLoad="['onLoad',_this,'RscUnitInfo','IGUI'] call (uinamespace getvariable 'BIS_fnc_initDisplay'); (_this + [true]) call RHS_fnc_sight_sosnaU";
	//onUnload="[""onUnload"",_this,""RscUnitInfo"",'IGUI'] call (uinamespace getvariable 'BIS_fnc_initDisplay')";
};