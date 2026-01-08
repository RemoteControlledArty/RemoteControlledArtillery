class UniformItem;
class U_C_WorkerCoveralls;
class RC_CoverallsBlk: U_C_WorkerCoveralls
{
	author="Ascent";
	scope=2;
	//scopeArsenal=2;
	//modelSides[]={0,1,2,3};
	displayName="Pilot Suit Black";
	picture="\A3\characters_f\data\ui\icon_U_C_WorkerCoveralls_ca.paa";
	model="\A3\Characters_F\Common\Suitpacks\suitpack_civilian_F.p3d";
	hiddenSelections[]={"Camo","insignia"};	//"camo"
	hiddenSelectionsTextures[]={"\A3\Characters_F\Common\Data\coveralls_black_co.paa"};
	class ItemInfo: UniformItem
	{
		uniformModel="-";
		uniformClass="C_man_w_worker_F";
		containerClass="Supply30";
		mass=30;
	};
};
class RC_CoverallsBlk: RC_CoverallsBlk
{
	displayName="Crew Suit Black";
};