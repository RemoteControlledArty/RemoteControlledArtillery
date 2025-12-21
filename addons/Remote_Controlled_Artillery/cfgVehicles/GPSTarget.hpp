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
	model="\A3\Weapons_f\laserTgt.p3d";
	//model="\A3\Weapons_F\empty.p3d";
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
	cost=10000000;	//makes it easier to select in datalink
	armor=500;
};
class RC_ArtySourceTarget: RC_GPSDatalinkTarget
{
	displayName="GPS Artillery Source";
	_generalMacro="RC_ArtySourceTarget";
};


class Helicopter;
class RC_Projectile_Target_Core: Helicopter
{
	class HitPoints;
	class HitHull;
	class HitHRotor;
	class EventHandlers;
};
class RC_Projectile_Target_Base: RC_Projectile_Target_Core
{
	class EventHandlers: EventHandlers
	{
		class RC_Artillery
		{
			killed="if (!isserver) exitwith {}; triggerAmmo attachedTo (_this select 0);";
		};
	};

	author="Ascent";
	scope=0;
	displayName="Projectile";

	cost=999999999;
	threat[]={1, 1, 1};
	armor=0.5;
	precision=15;

	irTarget=1;
	visualTarget=1;

	radarTargetSize=1;
	visualTargetSize=1;
	irTargetSize=1;

	camouflage=0.5;
	audible=0.2;	//0.1
	accuracy=1;	//AR2 0.5, FW 1

	maxSpeed=1750;
	isUav=1;
	vehicleClass="Autonomous";
	reportOwnPosition=1;	//for testing

	//model="\A3\Weapons_F\empty.p3d";	//doesnt work, not engagable / destructable
	model="\A3\Weapons_f\ammo\cartridge_small";

	mapSize=1;
	icon="iconManVirtual";
	picture="";

	epeImpulseDamageCoef=5;	//?
	fuelExplosionPower=0;

	lockDetectionSystem=0;
	incomingMissileDetectionSystem=0;
	weapons[]={};
	magazines[]={};

	features="Randomization: No						<br />Camo selections: 1 - the whole body						<br />Script door sources: None						<br />Script animations: None						<br />Executed scripts: None						<br />Firing from vehicles: No						<br />Slingload: No						<br />Cargo proxy indexes: None";

	damageEffect="UAVDestructionEffects";
	destrType="DestructDefault";
	driverCompartments="Compartment3";
	cargoCompartments[]=
	{
		"Compartment2"
	};
	class HitPoints: HitPoints
	{
		class HitHull: HitHull
		{
			armor=0.1;
		};
	};
	class TransportItems
	{
	};
};
class RC_Projectile_Target_B: RC_Projectile_Target_Base
{
	scope=1;

	side=1;
	crew="B_UAV_AI";
	typicalCargo[]={"B_UAV_AI"};
};
class RC_Projectile_Target_O: RC_Projectile_Target_B
{
	side=0;
	crew="O_UAV_AI";
	typicalCargo[]={"O_UAV_AI"};
};
class RC_Projectile_Target_I: RC_Projectile_Target_B
{
	side=2;
	crew="I_UAV_AI";
	typicalCargo[]={"I_UAV_AI"};
};