class APC_Wheeled_01_mgs_up_QAV;
class RC_AMV_MGS_Core: APC_Wheeled_01_mgs_up_QAV
{
	class ViewCargo;
	scope=0;
	scopeCurator=0;
};
class RC_AMV_MGS_Base: RC_AMV_MGS_Core
{
	displayName="AMV MGS-T"
	scope=2;
	scopeCurator=2;

	/*
	model="\A3\Armor_F_Beta\APC_Wheeled_01\APC_Wheeled_01_cannon_F.p3d";
	hiddenSelectionsTextures[]=
	{
		"a3\armor_f_beta\APC_Wheeled_01\data\APC_Wheeled_01_base_co.paa",
		"a3\armor_f_beta\APC_Wheeled_01\data\APC_Wheeled_01_adds_co.paa",
		"a3\armor_f_beta\APC_Wheeled_01\data\APC_Wheeled_01_tows_co.paa",
		"a3\Armor_F\Data\camonet_NATO_Desert_CO.paa",
		"a3\Armor_F\Data\cage_sand_CO.paa"
	};
	*/

	hideWeaponsCargo=1;
	cargoIsCoDriver[]={0};
	transportSoldier=8;
	
	features="Randomization: No						<br />Camo selections: 3 - top of hull, bottom of hull, turret						<br />Script door sources: None						<br />Script animations: HideTurret						<br />Executed scripts: None 						<br />Firing from vehicles: No						<br />Slingload: No						<br />Cargo proxy indexes: 1 to 8";

	cargoGetInAction[]=
	{
		"GetInAMV_cargo"
	};
	cargoGetOutAction[]=
	{
		"GetOutLow"
	};
	cargoAction[]=
	{
		"passenger_apc_narrow_generic02_low",
		"passenger_apc_narrow_generic01_low",
		"passenger_apc_narrow_generic03",
		"passenger_apc_generic03_low",
		"passenger_apc_generic02",
		"passenger_generic02_foldhands",
		"passenger_apc_narrow_generic01_low",
		"passenger_apc_narrow_generic02_low"
	};
};