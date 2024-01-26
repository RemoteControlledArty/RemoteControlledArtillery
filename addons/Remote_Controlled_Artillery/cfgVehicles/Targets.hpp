// targets for reporting created markers into datalink for selecting
/*
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
*/

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

class O_TargetSoldier;
class RC_InvisibleDatalinkTarget_O: O_TargetSoldier
{
	author="Ascent";
	displayName="GPS Marker";

	scope=2;
	scopeCurator=2;
	scopeArsenal=0;

	irTarget=1;
	//laserTarget=1;
	//nvTarget=1;	//makes marker stand out but requires NV lock ammo which could strike friendlies with strobes
	crewVulnerable=0;
	type=1;

	//destrType="DestructNo";
	threat[]={0.0,0.0,0.0};
	class HitPoints
	{
	};
};
class B_TargetSoldier;
class RC_InvisibleDatalinkTarget_B: B_TargetSoldier
{
	author="Ascent";
	displayName="GPS Marker";

	scope=2;
	scopeCurator=2;
	scopeArsenal=0;

	irTarget=1;
	//laserTarget=1;

	crewVulnerable=0;
	type=1;

	//destrType="DestructNo";
	threat[]={0.0,0.0,0.0};
	class HitPoints
	{
	};
};
class I_TargetSoldier;
class RC_InvisibleDatalinkTarget_I: I_TargetSoldier
{
	author="Ascent";
	displayName="GPS Marker";

	scope=2;
	scopeCurator=2;
	scopeArsenal=0;

	irTarget=1;
	//laserTarget=1;

	crewVulnerable=0;
	type=1;

	//destrType="DestructNo";
	threat[]={0.0,0.0,0.0};
	class HitPoints
	{
	};
};

class RC_ReportingInvisibleDatalinkTarget_O_Base: RC_InvisibleDatalinkTarget_O
{
	class EventHandlers;
};
class RC_ReportingInvisibleDatalinkTarget_O: RC_ReportingInvisibleDatalinkTarget_O_Base
{
	class EventHandlers: EventHandlers
	{
		init="(_this select 0) spawn {while {true} do {side player reportRemoteTarget [(_this select 0), 5]; sleep 1;};};";
	};
};
//if !hasInterface exitWith {};

/*
_marker = _this setVehicleVarName "gps";
hintSilent format ["varname: %1", vehicleVarName _marker];
*/

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