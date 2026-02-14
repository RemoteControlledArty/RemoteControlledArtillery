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


//class Air;
class Helicopter;
//class RC_Projectile_Target_Core: Air
class RC_Projectile_Target_Core: Helicopter
{
	/*
	simulation="helicopter";	//Air
	//simulation="airplanex";

	model="\A3\Weapons_F_beta\Launchers\titan\titan_missile_ap";
	proxyShape="\A3\Weapons_F_Sams\Ammo\Bomb_05_F_fly.p3d";

	fuelCapacity=0;
	gearsUpFrictionCoef=0;
	//airBrakeFrictionCoef=3;
	airFrictionCoefs2[]={0,0,0};
	airFrictionCoefs1[]={0,0,0};
	airFrictionCoefs0[]={0,0,0};
	enableSweep=1;
	liftForceCoef=0;
	cyclicAsideForceCoef=0;
	cyclicForwardForceCoef=0;
	backRotorForceCoef=0;
	bodyFrictionCoef=0;
	mainRotorSpeed=0;
	backRotorSpeed=0;
	*/

	class HitPoints;
	class HitHull;
	//class HitHRotor;
	class EventHandlers;
};
class RC_Projectile_Target_Base: RC_Projectile_Target_Core
{
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
	class EventHandlers: EventHandlers
	{
		class RC_Artillery
		{
			//MPKilled="if (!isServer) exitwith {};   params ['_unit'];   triggerAmmo attachedTo _unit;   deleteVehicle _unit;";
			killed="params ['_unit'];   triggerAmmo attachedTo _unit;   deleteVehicle _unit;";
		};
	};
	
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


class RC_Interceptor_Target_B: RC_Projectile_Target_Base
{
	scope=1;
	model="\A3\Weapons_F_beta\Launchers\titan\titan_missile_ap";
	proxyShape="\A3\Weapons_F_Sams\Ammo\Bomb_05_F_fly.p3d";

	side=1;
	crew="B_UAV_AI";
	typicalCargo[]={"B_UAV_AI"};
};
class RC_Interceptor_Target_O: RC_Interceptor_Target_B
{
	side=0;
	crew="O_UAV_AI";
	typicalCargo[]={"O_UAV_AI"};
};
class RC_Interceptor_Target_I: RC_Interceptor_Target_B
{
	side=2;
	crew="I_UAV_AI";
	typicalCargo[]={"I_UAV_AI"};
};


/*
class AllVehicles: All
{
	icon="iconVehicle";
	nameSound="unknown";
	class SquadTitles
	{
		name="clan_sign";
		color[]={0,0,0,0.75};
	};
	memoryPointDriverOptics[]=
	{
		"driverview",
		"pilot"
	};
	memoryPointsGetInDriver="pos driver";
	memoryPointsGetInDriverDir="pos driver dir";
	memoryPointsGetInCargo="pos cargo";
	memoryPointsGetInCargoDir="pos cargo dir";
	memoryPointsGetInCoDriver="pos codriver";
	memoryPointsGetInCoDriverDir="pos codriver dir";
	memoryPointsGetInDriverPrecise="pos driver";
	memoryPointsGetInCargoPrecise[]=
	{
		"pos cargo"
	};
	memoryPointsLeftWaterEffect="waterEffectL";
	memoryPointsRightWaterEffect="waterEffectR";
	memoryPointTaskMarker="";
	memoryPointTaskMarkerOffset[]={0,0,0};
	selectionClan="clan";
	selectionDashboard="podsvit pristroju";
	selectionShowDamage="poskozeni";
	selectionBackLights="zadni svetlo";
	class NewTurret
	{
		body="mainTurret";
		gun="mainGun";
		animationSourceBody="mainTurret";
		animationSourceGun="mainGun";
		animationSourceHatch="hatchGunner";
		animationSourceCamElev="camElev";
		proxyType="CPGunner";
		proxyIndex=1;
		gunnerName="$STR_POSITION_GUNNER";
		gunnerType="";
		primaryGunner=1;
		primaryObserver=0;
		weapons[]={};
		magazines[]={};
		soundServo[]=
		{
			"",
			0.0031622776,
			1
		};
		soundElevation[]=
		{
			"",
			0.0031622776,
			1
		};
		gunBeg="";
		gunEnd="";
		minElev=-4;
		maxElev=20;
		initElev=0;
		minTurn=-360;
		maxTurn=360;
		initTurn=0;
		minOutElev=-4;
		maxOutElev=20;
		initOutElev=0;
		minOutTurn=-60;
		maxOutTurn=60;
		initOutTurn=0;
		maxHorizontalRotSpeed=1.2;
		maxVerticalRotSpeed=1.2;
		minCamElev=-90;
		maxCamElev=90;
		initCamElev=0;
		stabilizedInAxes=3;
		primary=1;
		hasGunner=1;
		commanding=1;
		gunnerGetInAction="";
		gunnerGetOutAction="";
		gunnerAction="";
		gunnerInAction="";
		turretCanSee=0;
		showCrewAim=7;
		canUseScanners=1;
		class ViewGunner: ViewOptics
		{
			initAngleX=5;
			minAngleX=-75;
			maxAngleX=85;
			initAngleY=0;
			minAngleY=-150;
			maxAngleY=150;
			minFov=0.25;
			maxFov=1.25;
			initFov=0.75;
			minMoveX=0;
			maxMoveX=0;
			minMoveY=0;
			maxMoveY=0;
			minMoveZ=0;
			maxMoveZ=0;
			continuous=0;
		};
		class TurretSpec
		{
			showHeadPhones=0;
		};
		gunnerOpticsModel="";
		gunnerOpticsColor[]={0,0,0,1};
		memoryPointGunnerOptics="";
		gunnerForceOptics=1;
		gunnerOpticsShowCursor=0;
		turretInfoType="";
		gunnerOutOpticsModel="";
		gunnerOutOpticsColor[]={0,0,0,1};
		gunnerOpticsEffect[]={};
		gunnerOutOpticsEffect[]={};
		memoryPointGunnerOutOptics="";
		gunnerOutForceOptics=0;
		gunnerOutOpticsShowCursor=0;
		gunnerFireAlsoInInternalCamera=1;
		gunnerOutFireAlsoInInternalCamera=1;
		gunnerUsesPilotView=0;
		castGunnerShadow=0;
		viewGunnerShadow=1;
		viewGunnerShadowDiff=1;
		viewGunnerShadowAmb=1;
		ejectDeadGunner=0;
		hideWeaponsGunner=1;
		canHideGunner=-1;
		forceHideGunner=0;
		outGunnerMayFire=0;
		inGunnerMayFire=1;
		showHMD=0;
		viewGunnerInExternal=0;
		lockWhenDriverOut=0;
		lockWhenVehicleSpeed=-1;
		gunnerCompartments="Compartment1";
		LODTurnedIn=-1;
		LODTurnedOut=-1;
		startEngine=1;
		memoryPointsGetInGunner="";
		memoryPointsGetInGunnerDir="";
		memoryPointsGetInGunnerPrecise="";
		memoryPointGun="";
		selectionFireAnim="";
		missileBeg="spice rakety";
		missileEnd="konec rakety";
		armorLights=0.40000001;
		class Reflectors
		{
		};
		aggregateReflectors[]={};
		class GunFire: WeaponFireGun
		{
		};
		class GunClouds: WeaponCloudsGun
		{
		};
		class MGunClouds: WeaponCloudsMGun
		{
		};
		class HitPoints
		{
			class HitTurret
			{
				armor=0.80000001;
				material=51;
				name="turret";
				visual="turret";
				passThrough=1;
				explosionShielding=1;
			};
			class HitGun
			{
				armor=0.60000002;
				material=52;
				name="gun";
				visual="gun";
				passThrough=1;
				explosionShielding=1;
			};
		};
		class Turrets
		{
		};
		class ViewOptics
		{
			initAngleX=0;
			minAngleX=-30;
			maxAngleX=30;
			initAngleY=0;
			minAngleY=-100;
			maxAngleY=100;
			initFov=0.30000001;
			minFov=0.07;
			maxFov=0.34999999;
			minMoveX=0;
			maxMoveX=0;
			minMoveY=0;
			maxMoveY=0;
			minMoveZ=0;
			maxMoveZ=0;
			speedZoomMaxSpeed=1e+010;
			speedZoomMaxFOV=0;
		};
		forceNVG=0;
		isCopilot=0;
		canEject=1;
		gunnerLeftHandAnimName="";
		gunnerRightHandAnimName="";
		gunnerLeftLegAnimName="";
		gunnerRightLegAnimName="";
		gunnerDoor="";
		preciseGetInOut=0;
		turretFollowFreeLook=0;
		allowTabLock=1;
		showAllTargets=0;
		dontCreateAI=0;
		disableSoundAttenuation=0;
		slingLoadOperator=0;
		playerPosition=0;
		allowLauncherIn=0;
		allowLauncherOut=0;
		class TurnIn
		{
			turnOffset=0;
		};
		class TurnOut: TurnIn
		{
		};
	};
	class ViewPilot
	{
		initAngleX=5;
		minAngleX=-85;
		maxAngleX=85;
		initAngleY=0;
		minAngleY=-150;
		maxAngleY=150;
		minFov=0.25;
		maxFov=1.25;
		initFov=0.75;
		minMoveX=0;
		maxMoveX=0;
		minMoveY=0;
		maxMoveY=0;
		minMoveZ=0;
		maxMoveZ=0;
		speedZoomMaxSpeed=1e+010;
		speedZoomMaxFOV=0;
	};
	class ViewCargo
	{
		initAngleX=5;
		minAngleX=-75;
		maxAngleX=85;
		initAngleY=0;
		minAngleY=-150;
		maxAngleY=150;
		minFov=0.25;
		maxFov=1.25;
		initFov=0.75;
		minMoveX=0;
		maxMoveX=0;
		minMoveY=0;
		maxMoveY=0;
		minMoveZ=0;
		maxMoveZ=0;
		speedZoomMaxSpeed=1e+010;
		speedZoomMaxFOV=0;
	};
	class ViewOptics
	{
		initAngleX=0;
		minAngleX=-30;
		maxAngleX=30;
		initAngleY=0;
		minAngleY=-100;
		maxAngleY=100;
		initFov=0.69999999;
		minFov=0.41999999;
		maxFov=0.85000002;
		minMoveX=0;
		maxMoveX=0;
		minMoveY=0;
		maxMoveY=0;
		minMoveZ=0;
		maxMoveZ=0;
		speedZoomMaxSpeed=1e+010;
		speedZoomMaxFOV=0;
	};
	class PilotSpec
	{
		showHeadPhones=0;
	};
	class CargoSpec
	{
		class Cargo1
		{
			showHeadPhones=0;
		};
	};
	class MFD
	{
	};
	class Sounds
	{
		class Engine
		{
			sound="soundEngine";
			frequency="rpm";
			volume="rpm + speed";
		};
		class Movement
		{
			sound="soundEnviron";
			frequency="speed";
			volume="speed";
		};
	};
	class SoundEvents
	{
	};
	tracksSpeed=0;
	selectionLeftOffset="";
	selectionRightOffset="";
	class RenderTargets
	{
	};
	cargoProxyIndexes[]={};
	driverLeftHandAnimName="";
	driverRightHandAnimName="";
	driverLeftLegAnimName="";
	driverRightLegAnimName="";
	driverDoor="";
	cargoDoors[]={};
	hasTerminal=0;
	getInOutOnProxy=0;
	preciseGetInOut=0;
	cargoPreciseGetInOut[]={0};
	availableForSupportTypes[]={};
	waterPPInVehicle=1;
};
class Air: AllVehicles
{
	icon="iconAir";
	displayName="$STR_DN_HELICOPTER";
	nameSound="veh_aircraft";
	accuracy=0.0049999999;
	formationX=50;
	formationZ=100;
	precision=100;
	brakeDistance=200;
	formationTime=10;
	gearsUpFrictionCoef=0.5;
	airBrakeFrictionCoef=3;
	airFrictionCoefs2[]={0.001,0.00050000002,5.9999998e-005};
	airFrictionCoefs1[]={0.1,0.050000001,0.0060000001};
	airFrictionCoefs0[]={0,0,0};
	class Components
	{
		class TransportCountermeasuresComponent
		{
		};
	};
	altFullForce=2000;
	altNoForce=6000;
	armor=20;
	cost=10000000;
	fuelCapacity=1000;
	maxSpeed=400;
	attenuationEffectType="";
	insideSoundCoef=0.031622775;
	outsideSoundFilter=1;
	occludeSoundsWhenIn=0.31622776;
	obstructSoundsWhenIn=0.31622776;
	weapons[]=
	{
		"FakeWeapon"
	};
	magazines[]=
	{
		"FakeWeapon"
	};
	type=2;
	irScanRangeMin=2000;
	irScanRangeMax=10000;
	irScanToEyeFactor=2;
	nightVision=0;
	audible=10;
	unitInfoType="RscUnitInfoAir";
	threat[]={0.30000001,1,0.69999999};
	driverAction="";
	driverCompartments=0;
	cargoCompartments[]={0};
	gunnerCanSee="31+32";
	driverCanSee="31+32";
	typicalCargo[]=
	{
		"Soldier"
	};
	getInRadius=5;
	transportMaxMagazines=20;
	transportMaxWeapons=3;
	enableGPS=1;
	class MarkerLights
	{
		class RedStill
		{
			name="cerveny pozicni";
			color[]={0.30000001,0.029999999,0.029999999,1};
			ambient[]={0.029999999,0.003,0.003,1};
			brightness=0.0099999998;
			blinking=0;
		};
		class GreenStill
		{
			name="zeleny pozicni";
			color[]={0.029999999,0.30000001,0.029999999,1};
			ambient[]={0.003,0.029999999,0.003,1};
			brightness=0.0099999998;
			blinking=0;
		};
		class WhiteStill
		{
			name="bily pozicni";
			color[]={0.30000001,0.30000001,0.30000001,1};
			ambient[]={0.029999999,0.029999999,0.029999999,1};
			brightness=0.0099999998;
			blinking=0;
		};
		class WhiteBlinking
		{
			name="bily pozicni blik";
			color[]={1,1,1,1};
			ambient[]={0.1,0.1,0.1,1};
			brightness=0.0099999998;
			blinking=1;
		};
		class RedBlinking
		{
			name="cerveny pozicni blik";
			color[]={0.5,0.050000001,0.050000001,1};
			ambient[]={0.050000001,0.0049999999,0.0049999999,1};
			brightness=0.0099999998;
			blinking=1;
		};
	};
};
class Helicopter: Air
{
	vehicleClass="Air";
	icon="iconHelicopter";
	displayName="$STR_DN_HELICOPTER";
	nameSound="veh_helicopter";
	accuracy=0.079999998;
	simulation="helicopter";
	gearRetracting=0;
	dustEffect="HeliDust";
	waterEffect="HeliWater";
	washDownStrength=1;
	washDownDiameter=40;
	damageEffect="DamageSmokeHeli";
	gearUpTime=3.3299999;
	gearDownTime=2;
	gearMinAlt=0.5;
	class ViewPilot: ViewPilot
	{
		minFov=0.25;
		maxFov=1.25;
		initFov=0.75;
		initAngleX=10;
		minAngleX=-85;
		maxAngleX=85;
		initAngleY=0;
		minAngleY=-150;
		maxAngleY=150;
		minMoveX=-0.34999999;
		maxMoveX=0.34999999;
		minMoveY=-0.5;
		maxMoveY=0.2;
		minMoveZ=-0.30000001;
		maxMoveZ=0.5;
	};
	class CargoSpec
	{
		class Cargo1
		{
			showHeadPhones=1;
		};
		class Cargo2
		{
			showHeadPhones=0;
		};
	};
	mainRotorSpeed=1;
	backRotorSpeed=1.5;
	startDuration=20;
	mainBladeRadius=0;
	maxMainRotorDive=0;
	maxBackRotorDive=0;
	minMainRotorDive=0;
	minBackRotorDive=0;
	neutralBackRotorDive=0;
	neutralMainRotorDive=0;
	liftForceCoef=1;
	cyclicAsideForceCoef=1;
	cyclicForwardForceCoef=1;
	backRotorForceCoef=1;
	bodyFrictionCoef=1;
	selectionHRotorStill="velka vrtule staticka";
	selectionHRotorMove="velka vrtule blur";
	selectionVRotorStill="mala vrtule staticka";
	selectionVRotorMove="mala vrtule blur";
	memoryPointLMissile="L strela";
	memoryPointRMissile="P strela";
	memoryPointLRocket="L raketa";
	memoryPointRRocket="P raketa";
	memoryPointGun="";
	memoryPointPilot="pilot";
	_mainBladeCenter="rotor_center";
	selectionFireAnim="zasleh";
	class HitPoints
	{
		class HitHull
		{
			armor=0.5;
			material=50;
			name="trup";
			visual="trup";
			passThrough=1;
			explosionShielding=1;
		};
		class HitEngine
		{
			armor=0.60000002;
			material=60;
			name="motor";
			visual="motor";
			passThrough=1;
			explosionShielding=1;
		};
		class HitAvionics
		{
			armor=1.4;
			material=-1;
			name="elektronika";
			visual="elektronika";
			passThrough=1;
			explosionShielding=1;
		};
		class HitVRotor
		{
			armor=0.5;
			material=52;
			name="mala vrtule";
			visual="mala vrtule";
			passThrough=1;
			explosionShielding=1;
		};
		class HitHRotor
		{
			armor=0.69999999;
			material=51;
			name="velka vrtule";
			visual="velka vrtule";
			passThrough=1;
			explosionShielding=1;
		};
		class HitMissiles
		{
			armor=1.6;
			material=-1;
			name="munice";
			visual="";
			passThrough=1;
			explosionShielding=1;
		};
		class HitRGlass
		{
			armor=0.5;
			material=-1;
			name="sklo predni P";
			convexComponent="sklo predni P";
			visual="";
			passThrough=1;
			explosionShielding=1;
		};
		class HitLGlass
		{
			armor=0.5;
			material=-1;
			name="sklo predni L";
			convexComponent="sklo predni L";
			visual="";
			passThrough=1;
			explosionShielding=1;
		};
	};
	armorStructural=2;
	maxSpeed=300;
	enableSweep=1;
	envelope[]={0,0.2,0.89999998,2.0999999,2.5,3.3,3.5,3.5999999,3.7,3.8,3.8,3,0.89999998,0.69999999,0.5};
	unitInfoType="RscUnitInfoAir";
	minFireTime=20;
	steerAheadSimul=0.5;
	steerAheadPlan=0.69999999;
	class Turrets
	{
		class MainTurret: NewTurret
		{
			outGunnerMayFire=1;
			commanding=-1;
			startEngine=0;
			class TurretSpec: TurretSpec
			{
				showHeadPhones=1;
			};
		};
	};
	class ViewOptics: ViewOptics
	{
		initAngleX=0;
		minAngleX=-40;
		maxAngleX=17;
		initAngleY=0;
		minAngleY=-100;
		maxAngleY=100;
		initFov=0.5;
		minFov=0.30000001;
		maxFov=1.2;
	};
	class MFD
	{
		class HUD: AirplaneHUD
		{
		};
	};
	weapons[]=
	{
		"FakeWeapon"
	};
	magazines[]=
	{
		"FakeWeapon"
	};
	class Reflectors
	{
		class Reflector
		{
			color[]={0.80000001,0.80000001,1,1};
			ambient[]={0.07,0.07,0.07,1};
			position="L svetlo";
			direction="konec L svetla";
			hitpoint="L svetlo";
			selection="L svetlo";
			size=0.5;
			brightness=2;
		};
	};
	class Sounds: Sounds
	{
		class Engine: Engine
		{
			sound="soundEngine";
			frequency="(1-randomizer*0.05)*rotorSpeed*(1-rotorThrust*0.1)";
			volume="1";
		};
		class Movement: Movement
		{
			sound="soundEnviron";
			frequency="1";
			volume="speed * 0.03334";
		};
	};
	soundLandingGear[]=
	{
		"",
		1,
		1
	};
	class Exhausts
	{
	};
	minSmokeDamage=0.40000001;
	maxSmokeDamage=0.99000001;
	class RotorLibHelicopterProperties
	{
		RTDconfig="";
		hasAPU=0;
		maxTorque=10000;
		autoHoverCorrection[]={0,0,0};
		maxMainRotorStress=10000;
		maxTailRotorStress=10000;
		maxHorizontalStabilizerLeftStress=10000;
		maxHorizontalStabilizerRightStress=10000;
		maxVerticalStabilizerStress=10000;
		stressDamagePerSec=0.0099999998;
		retreatBladeStallWarningSpeed=69.400002;
		horizontalWingsAngleCollMin=0;
		horizontalWingsAngleCollMax=0;
		defaultCollective=0.69999999;
		vrsShakepowerCoef=1;
	};
	slingLoadMemoryPoint="slingLoad0";
	slingLoadMaxCargoMass=0;
	slingLoadMinCargoMass=0;
};
*/