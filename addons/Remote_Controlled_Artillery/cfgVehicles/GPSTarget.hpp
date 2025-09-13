// targets for reporting created markers into datalink for locking on with guided
class All;
class RC_GPSDatalinkTarget: All
{
	author="Ascent";
	displayName="GPS Marker";
	_generalMacro="RC_GPSDatalinkTarget";
	scope=2;	//0?
	scopeCurator=2;	//0?
	scopeArsenal=0;
	//faction="RemoteControlled_B";
	//editorSubcategory="RC_Spotting_subcat";
	//alwaysTarget=0;
	//edited lasertarget values
	model="\A3\Weapons_f\laserTgt.p3d";
	//model="laserTgt.p3d";
	//model="";
	reversed=0;
	hasDriver=0;
	icon="iconLaserTarget";
	accuracy=9.9999997e-005;
	picture="pictureLaserTarget";
	weapons[]={"FakeWeapon"};
	magazines[]={"FakeWeapon"};
	type=1;
	threat[]={0,0,0};	//threat[]={1,1,1};
	maxSpeed=0;
	simulation="artillerymarker";	//forgot why, but its one of the few/only things that worked
	laserTarget=0;
	nvTarget=0;
	irTarget=1;
	artilleryTarget=0;	//1 would make it unlockable on datalink panel by all rounds
	destrType="DestructNo";
	side=3;
	cost=2500000;	//makes it easier to select in datalink
	armor=500;
};
class RC_ArtySourceTarget: RC_GPSDatalinkTarget
{
	displayName="GPS Artillery Source";
	_generalMacro="RC_ArtySourceTarget";
};
class RC_CRAM_Target_Base: All
{
	author="Ascent";
	displayName="RAM Projectile";
	scope=0;
	scopeCurator=0;
	scopeArsenal=0;

	alwaysTarget=1;
	threat[]={0,1,1};
	cost=10000000;
	armor=1;
	side=5;
	destrType="DestructDefault";	//destrType="DestructNo";
	irTarget=1;
	visualTarget=1;	//0
	maxSpeed=1750;	//0

	model="\A3\Weapons_f\laserTgt.p3d";
	//model="\A3\Weapons_F_EPC\Ammo\Bomb_03_F.p3d";

	reversed=0;
	hasDriver=0;
	icon="iconLaserTarget";
	accuracy=1000;		//9.9999997e-005
	picture="pictureLaserTarget";
	weapons[]={"FakeWeapon"};
	magazines[]={"FakeWeapon"};
	type=1;
	simulation="artillerymarker";	//forgot why, but its one of the few/only things that worked
	laserTarget=0;
	nvTarget=0;
	artilleryTarget=0;	//1 would make it unlockable on datalink panel by all rounds
};
class RC_CRAM_Target_B: RC_CRAM_Target_Base
{
	scope=1;
	scopeCurator=1;
	side=1;
};
class RC_CRAM_Target_O: RC_CRAM_Target_B
{
	side=0;
};
class RC_CRAM_Target_I: RC_CRAM_Target_B
{
	side=2;
};