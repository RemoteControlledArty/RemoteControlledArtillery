class UniformItem;
class U_C_WorkerCoveralls;
class RC_CoverallsBlk: U_C_WorkerCoveralls
{
	scope=2;
	displayName="Coveralls Black";
	picture="\A3\characters_f\data\ui\icon_U_C_WorkerCoveralls_ca.paa";
	model="\A3\Characters_F\Common\Suitpacks\suitpack_civilian_F.p3d";
	hiddenSelections[]={"Camo","insignia"};
	hiddenSelectionsTextures[]={"\A3\Characters_F\Common\Data\coveralls_black_co.paa"};
	class ItemInfo: UniformItem
	{
		uniformModel="-";
		uniformClass="RC_CoverallsBlk_Man";
		containerClass="Supply50";
		mass=30;
	};
};