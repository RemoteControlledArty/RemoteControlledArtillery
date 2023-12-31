// targets for reporting created markers into datalink for selecting
class ArtilleryTarget;
class RC_ArtilleryTarget: ArtilleryTarget
{
	isimulation="laserTarget"; 		//test

	scope=2;
	scopeCurator=2;
	irTarget=1;
	faction="RemoteControlled_B";
	editorSubcategory="RC_Targets_subcat";
};

class ArtilleryTargetW;
class RC_ArtilleryTargetW: ArtilleryTargetW
{
	isimulation="laserTarget"; 		//test

	scope=2;
	scopeCurator=2;
	irTarget=1;
	faction="RemoteControlled_B";
	editorSubcategory="RC_Targets_subcat";
};

class ArtilleryTargetE;
class RC_ArtilleryTargetE: ArtilleryTargetE
{
	isimulation="laserTarget"; 		//test
	
	scope=2;
	scopeCurator=2;
	irTarget=1;
	faction="RemoteControlled_B";
	editorSubcategory="RC_Targets_subcat";
};

class All;
class RC_LockableMarkerTarget: All
{
	reversed=0;
	hasDriver=0;
	icon="iconLaserTarget";
	displayName="Marker";
	nameSound="";
	accuracy=9.9999997e-005;
	model="laserTgt.p3d";
	picture="pictureLaserTarget";
	weapons[]=
	{
		"FakeWeapon"
	};
	magazines[]=
	{
		"FakeWeapon"
	};
	type=1;
	threat[]={0.1,0.1,0.1};
	maxSpeed=0;
	simulation="laserTarget";
	laserTarget=1;
	irTarget=1;
	artilleryTarget=1;
	destrType="DestructNo";
	side=3;
	cost=9.9999999e+014;
	armor=500;
};

/*
class LaserTarget: All
{
	reversed=0;
	hasDriver=0;
	icon="iconLaserTarget";
	displayName="$STR_DN_LASER_TARGET";
	nameSound="obj_LaserTarget";
	accuracy=9.9999997e-005;
	model="laserTgt.p3d";
	picture="pictureLaserTarget";
	weapons[]=
	{
		"FakeWeapon"
	};
	magazines[]=
	{
		"FakeWeapon"
	};
	type=1;
	threat[]={0.5,0.5,0.1};
	maxSpeed=0;
	simulation="nvmarker";
	laserTarget=1;
	irTarget=0;
	artilleryTarget=0;
	destrType="DestructNo";
	side=3;
	cost=9.9999999e+014;
	armor=500;
};
class NVTarget: All
{
	reversed=0;
	hasDriver=0;
	icon="iconLaserTarget";
	displayName="$STR_DN_LASER_TARGET";
	nameSound="obj_LaserTarget";
	accuracy=9.9999997e-005;
	model="laserTgt.p3d";
	picture="pictureLaserTarget";
	weapons[]=
	{
		"FakeWeapon"
	};
	magazines[]=
	{
		"FakeWeapon"
	};
	type=1;
	threat[]={0.2,0.5,0.1};
	maxSpeed=0;
	simulation="nvmarker";
	laserTarget=0;
	irTarget=0;
	nvTarget=1;
	destrType="DestructEngine";
	side=3;
	cost=9.9999999e+014;
	armor=500;
};
class ArtilleryTarget: All
{
	reversed=0;
	hasDriver=0;
	icon="iconLaserTarget";
	displayName="ArtilleryTarget";
	nameSound="";
	accuracy=9.9999997e-005;
	model="";
	picture="pictureLaserTarget";
	weapons[]=
	{
		"FakeWeapon"
	};
	magazines[]=
	{
		"FakeWeapon"
	};
	type=1;
	threat[]={0.5,0.5,0.1};
	maxSpeed=0;
	simulation="artillerymarker";
	laserTarget=0;
	irTarget=0;
	nvTarget=0;
	artilleryTarget=1;
	destrType="DestructNo";
	side=3;
	cost=9.9999999e+014;
	armor=500;
	scope=1;
};
class ArtilleryTargetW: ArtilleryTarget
{
	side=1;
	scope=1;
};
class ArtilleryTargetE: ArtilleryTarget
{
	side=0;
	scope=1;
};
*/