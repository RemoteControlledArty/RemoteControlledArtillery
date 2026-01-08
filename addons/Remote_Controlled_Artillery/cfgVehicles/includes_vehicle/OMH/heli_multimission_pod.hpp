//this fire rewrites the ReammoBox_F based ammo pod to be LandVehicle based, to show up in the helicopter section like the other pods
/*
class LandVehicle;
class StaticWeapon: LandVehicle {class EventHandlers;};
class Pod_Heli_Transport_04_crewed_base_F: StaticWeapon {};

class ReammoBox_F;
class Slingload_base_F: ReammoBox_F {class EventHandlers;};
class Pod_Heli_Transport_04_base_F: Slingload_base_F {};
*/


/*
//ReammoBox_F
editorCategory="EdCat_Supplies";	//c only
reversed=1;	//c
destrType="DestructBuilding";	//c
explosionEffect="";	//c
class DestructionEffects {};	//c
class AnimationSources;	//c
//class HitPoints;	//c
*/


//LandVehicle
/*
getInAction="GetInLow";		//v
getOutAction="GetOutLow";		//v
cargoGetInAction[]={"GetInLow"};	//v
cargoGetOutAction[]={"GetOutLow"};	//v
*/
memoryPointsGetInCargo="Cargo_pos";		//v
memoryPointsGetInCargoDir="Cargo_dir";	//v

crew="O_helipilot_F";	//v
typicalCargo[]={"O_Soldier_lite_F"};		//v

editorForceEmpty=1;	//v only
supplyRadius=-1;	//v
ejectDeadCargo=0;	//v
ejectDeadDriver=0;	//v
cargoCompartments[]={"Compartment2"};		//v
cargoDoors[]={};	//v
cargoAction[]={};	//v
memoryPointTaskMarker="TaskMarker_1_pos";	//v
class CargoTurret;	//v
class Turrets {};	//v
class HitPoints;	//v


//mixed
getInAction="";
getOutAction="";
cargoGetInAction[]={};
cargoGetOutAction[]={};

mapSize=6.77;	//v	&blkAmmo
//mapSize=6.7600002;	//c

//_generalMacro="Pod_Heli_Transport_04_crewed_base_F";	//v
//_generalMacro="Pod_Heli_Transport_04_base_F";	//c

//side=0;	//v
//side=3;	//c


//pod variant values
accuracy=1000;		//0.5 v base only 	//1000 v and c variants
transportSoldier=1;	//0 to 8	//1 required to show up in editor
model="\A3\Air_F_Heli\Heli_Transport_04\Pod_Heli_Transport_04_ammo_F.p3d";
explosionEffect="FuelExplosion";
secondaryExplosion=-1;
fuelExplosionPower=1;
//attendant=1;	//medical?
icon="iconObject_1x2";	//ammo iconObject_1x2 //some others iconObject_2x3

editorPreview="\A3\EditorPreviews_F\Data\CfgVehicles\Land_Pod_Heli_Transport_04_ammo_F.jpg";
picture="\A3\Air_F_Heli\Heli_Transport_04\Data\UI\Pod_Heli_Transport_04_covered_CA.paa";	//??? available for v not c

features="Randomization: No						<br />Camo selections: 2 exterior						<br />Script door sources: None						<br />Script animations: None						<br />Executed scripts: None						<br />Available scripts: camo variant \a3\Air_F_Heli\Heli_Transport_04\Scripts\Pods_Heli_Transport_04_pods_camo.sqf, black variant \a3\Air_F_Heli\Heli_Transport_04\Scripts\Pods_Heli_Transport_04_pods_black.sqf						<br />Firing from vehicles: No						<br />Slingload: No						<br />Cargo proxy indexes: None";

//required to show up black and not cause script errors
hiddenSelections[]=
{
	"Camo_1",
	"Camo_2"
};

textureList[]=
{
	"Black",
	1
};
hiddenSelectionsTextures[]=
{
	"A3\Air_F_Heli\Heli_Transport_04\Data\Heli_Transport_04_Pod_Ext01_Black_CO.paa",
	"A3\Air_F_Heli\Heli_Transport_04\Data\Heli_Transport_04_Pod_Ext02_Black_CO.paa"
};
class SimpleObject
{
	eden=1;	//0hex, 1blk
	animate[]={};
	hide[]={};
	verticalOffset=1.204;	//v 1.325, c 1.204
	verticalOffsetWorld=0;
	init="''";
};


class DestructionEffects
{
	class FireBig1
	{
		simulation="particles";
		type="ObjectDestructionFire1";
		position="";
		intensity=0.15000001;
		interval=1;
		lifeTime=3;
	};
	class FireBig2
	{
		simulation="particles";
		type="ObjectDestructionFire2";
		position="";
		intensity=0.15000001;
		interval=1;
		lifeTime=3;
	};
	class FireSparksBig1
	{
		simulation="particles";
		type="FireSparks";
		position="";
		intensity=1;
		interval=1;
		lifeTime=2.8;
	};
	class LightBig1
	{
		simulation="light";
		type="ObjectDestructionLight";
		position="";
		intensity=0.001;
		interval=1;
		lifeTime=3;
	};
	class Refract1
	{
		simulation="particles";
		type="ObjectDestructionRefract";
		position="";
		intensity=0.15000001;
		interval=1;
		lifeTime=3;
	};
	class SmokeBig1
	{
		simulation="particles";
		type="ObjectDestructionSmoke";
		position="";
		intensity=1;
		interval=1;
		lifeTime=3.5;
	};
	class SmokeBig1_2
	{
		simulation="particles";
		type="ObjectDestructionSmoke1_2";
		position="";
		intensity=1;
		interval=1;
		lifeTime=3.5;
	};
	class Sound
	{
		simulation="sound";
		type="Fire";
		position="";
		intensity=1;
		interval=1;
		lifeTime=1;
	};
	class SparksBig1
	{
		simulation="particles";
		type="ObjectDestructionSparks";
		position="";
		intensity=0;
		interval=1;
		lifeTime=3;
	};
};
class Damage
{
	tex[]={};
	mat[]=
	{
		"A3\Air_F_Heli\Heli_Transport_04\Data\Heli_Transport_04_Pod_Ext01.rvmat",
		"A3\Air_F_Heli\Heli_Transport_04\Data\Heli_Transport_04_Pod_Ext01_damage.rvmat",
		"A3\Air_F_Heli\Heli_Transport_04\Data\Heli_Transport_04_Pod_Ext01_destruct.rvmat",
		"A3\Air_F_Heli\Heli_Transport_04\Data\Heli_Transport_04_Pod_Ext02.rvmat",
		"A3\Air_F_Heli\Heli_Transport_04\Data\Heli_Transport_04_Pod_Ext02_damage.rvmat",
		"A3\Air_F_Heli\Heli_Transport_04\Data\Heli_Transport_04_Pod_Ext02_destruct.rvmat"
	};
};