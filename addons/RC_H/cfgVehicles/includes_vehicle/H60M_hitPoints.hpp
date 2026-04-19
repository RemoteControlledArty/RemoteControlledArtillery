//damage
armor=100; 						//V 35, H 600, RC 70
armorStructural=25;				//V 20, H 4
damageResistance=0.01039; 		//V 0.01039, H 0.01039
epeImpulseDamageCoef=0;			//V 20, H 0, RC 0
explosionShielding=4;			//V 4, H 4
fuelExplosionPower=1;			//V 1, H 1
minTotalDamageThreshold=0.005;	//V 0.005, H 0.05, RC 0.005
secondaryExplosion=-1;			//V -1, H -1
crewCrashProtection=0.01;		//V 0.2, H 0.25
crewVulnerable=1;				//V 1, H 1
hullDamageCauseExplosion=0;		//V 0, H 0
//hullExplosionDelay[]={,};		//undefined because bool is 0, also hull armor is very high

/*
replaceDamaged = "";
replaceDamagedHitpoints[] = {};
replaceDamagedLimit = 0.9;		//V 0.9, H 0.9
*/

/*
"armorStructural" value acts as a divisor to global damage.

In theory, a hitpoint location receives damage.
This damage is applied to global damage as well,
but reduced via passthrough value on the hitlocation and the global armorStructural value.

However, test results indicate that this is not true in every case,
not matching any formula that has been floating around on various other damage related pages.
*/


class HitPoints: HitPoints
{
	class HitHull
	{
		armor=-40000;			//V -120, H ?, RC -400000
		depends="HitEngine";	//V "HitEngine"
		radius=0.02;			//V 0.02
		minimalHit=-0.15;		//V -0.15
		explosionShielding=1;	//V 1, RC 1
		passThrough=1;			//V 1, H ?, RC 1/0.5/0
		material=51;

		simulation="RHS_Hull_Helicopter";
		armorComponent="hull_hit";
		name="hull_hit";
		convexComponent="hull_hit";
		visual="zbytek";

		class DestructionEffects
		{
			ammoExplosionEffect="";
			effectRadius=1;	
			ignoreFuel=1;

			class RHS_Hull_Fire
			{
				intensity=0.5;
				interval=1;
				lifeTime=60;
				position="hull_fire_1";
				simulation="particles";
				type="MediumDestructionFire";
			};
			class RHS_Hull_Fire_2: RHS_Hull_Fire
			{
				position="hull_fire_2";
			};
			class RHS_Hull_Fire_3: RHS_Hull_Fire
			{
				position="hull_fire_3";
			};
			class RHS_Hull_Smoke: RHS_Hull_Fire
			{
				type="SmallWreckSmoke";
			};
			class RHS_Hull_Smoke_small1: RHS_Hull_Fire_2
			{
				type="WeaponWreckSmoke";
			};
			class RHS_Hull_Smoke_small2: RHS_Hull_Smoke_small1
			{
				position="hull_fire_3";
			};
			class RHS_Hull_Sounds: RHS_Hull_Fire
			{
				simulation="sound";
				type="Fire";
			};
			class RHS_Hull_Sparks: RHS_Hull_Fire
			{
				type="AirFireSparks";
			};
		};
	};
	class HitFuel
	{
		armor=-150;				//V -130, H ?, RC -150
		radius=0.125;			//V 0.125
		minimalHit=-0.04;		//V -0.04
		explosionShielding=1;	//V 0.5, RC 1
		passThrough=0;			//V 1
		material=51;

		armorComponent = "fuel_hit";
		name="fuel_hit";
		convexComponent="fuel_hit";
		visual="-";
	};
	class HitAvionics
	{
		armor=-80;					//V 2 = -80, H ?, RC -80
		radius=0.05;				//V 0.05
		minimalHit=0.1;				//V 0.1, RC 0.1
		explosionShielding=1;		//V 0.5, RC 1
		passThrough=0;				//V 1, H ?
		material=51;

		name="avionics_hit";
		convexComponent="avionics_hit";
		visual="-";
	};
	class HitHRotor
	{
		armor=-400;					//V 3 = -105, H 10.35, 10.35 = -414, RC = -400
		radius=0.2;					//V 0.2, H 0.47, RC 0.2
		//minimalHit=0.1;			//V NA, H 0.1, RC 0.1
		explosionShielding=1.75;	//V 0.5, H 3000, RC 1.75
		passThrough=0;				//V 0.1, H 0, RC 0
		material=51;				//V 51, H 51

		name="main_rotor_hit";
		convexComponent="main_rotor_hit";
		visual="main rotor static";
	};
	class HitVRotor
	{
		armor=-200;					//V 1 = -35, H 0.054, 0.81 = -32.4, RC -200
		radius=0.05;				//V 0.05, H 0.24
		//minimalHit=0.1;			//V NA, H 0.1, RC 0.1
		explosionShielding=1;		//V 0.8, H 0.27, RC 1
		passThrough=0;				//V 0.3, H 0, RC 0
		material=51;				//V 51, H 51

		name="tail_rotor_hit";
		convexComponent="tail_rotor_hit";
		visual="tail rotor static";
	};
	class HitEngine
	{
		armor=-40000;			//V 999 = -39960, H 66.6, 999 = -39960, RC -40000
		depends="0.5 * (HitEngine1 + HitEngine2)";
		radius=0.05;			//V 0.05, H 0.05
		explosionShielding=1;	//V 1, H 1
		minimalHit=1;			//V 1, H 1
		passThrough=0;			//V 1, H 0, RC 0
		material=51;			//V 51, H 51

		name="engine_hit";
		convexComponent="engine_hit";
		visual="camo2";
	};
	class HitEngine1
	{
		armor=-43.2;				//V 0.7 = -28, H 0.072, 1.08 = -43.2, RC -35.6
		radius=0.35;				//V 0.35, H 0.59, RC 0.35
		explosionShielding=1.73;	//V 3, H 0.46, RC 1.73
		minimalHit=0.1;				//V 0.1, H 0.1
		passThrough=0;				//V 1, H 0, RC 0
		material=51;				//V 51, H 51

		name="engine_1_hit";
		convexComponent="engine_1_hit";
		visual="motor";
	};
	class HitEngine2: HitEngine1
	{
		name="engine_2_hit";
		convexComponent="engine_2_hit";
	};
	class HitEngine3: HitEngine
	{
		armor=-10;				//V 0.25 = -10, RC -10
		explosionShielding=1;	//V 1, H ?
		passThrough=0;			//V 1
		material=51;

		name="engine_3_hit";
		convexComponent="engine_3_hit";
		visual="motor";
	};
	class HitMissiles
	{
		armor=-28;					//V 0.1 = -3.5, H 0.036, 0.54 = -21.6, RC -28
		//radius=0.25;				//V NA, H 0.3, RC 0.25
		minimalHit=0.05;			//V 0.05, H 0.1, RC 0.075
		explosionShielding=0.65;	//V 1, H 0.3, RC 0.65
		passThrough=0;				//V 0.5, H 0, RC 0
		material=51;				//V 51, H 51

		name="ammo_hit";
		convexComponent="ammo_hit";
		visual="munice";
	};
	class HitGear		//landing gear or rotor gearbox?
	{
		armor=-60;		//V 0.9 = -31.5, RC -60
		passThrough=0;	//V 0
		material=-1;

		name="gear";
	};
	class HitWinch
	{
		armor=-120;		//V -40
		radius=0.1;
		passThrough=0;	//V 0
		material=51;

		name="slingLoad0";
		visual="";

		class DestructionEffects
		{
			ammoExplosionEffect = "";

			class Explo
			{
				intensity=1;
				interval=1;
				lifeTime=0.06;
				position="slingLoad0";
				simulation="particles";
				type="WinchDestructionExplo";
			};
			class Sparks: Explo
			{
				lifeTime=0.1;
				type="WinchDestructionSparks";
			};
		};
	};


	class HitPylon1
	{
		armor=-30;

		explosionShielding=0.1;
		radius=0.7;
		minimalHit=-0.1;
		passThrough=0;

		name="hit_pylon_1";
		visual="-";

		class DestructionEffects
		{
			ammoExplosionEffect="";
			effectRadius=1;
			ignoreFuel=1;

			class RHS_Pylon_Flash
			{
				intensity=0.5;
				interval=1;
				lifeTime=0.006;
				position="fx_pylon_1";
				simulation="particles";
				type="RHS_ERA_Flash";
			};
			class RHS_Pylon_Shard: RHS_Pylon_Flash
			{
				intensity=1;
				lifeTime=0.03;
				type="RHS_ERA_Shard";
			};
			class RHS_Pylon_Smoke: RHS_Pylon_Flash
			{
				intensity=0.1;
				lifeTime=0.04;
				type="RHS_ERA_Smoke";
			};
			class RHS_Pylon_Sound: RHS_Pylon_Flash
			{
				intensity=1;
				lifeTime=1;
				simulation="sound";
				type="RHS_ERA_Explosion_Sound";
			};
		};
	};
	class HitPylon2: HitPylon1
	{
		name="hit_pylon_2";

		class DestructionEffects: DestructionEffects
		{
			class RHS_Pylon_Flash: RHS_Pylon_Flash
			{
				position="fx_pylon_2";
			};
			class RHS_Pylon_Shard: RHS_Pylon_Shard
			{
				position="fx_pylon_2";
			};
			class RHS_Pylon_Smoke: RHS_Pylon_Smoke
			{
				position="fx_pylon_2";
			};
			class RHS_Pylon_Sound: RHS_Pylon_Sound
			{
				position="fx_pylon_2";
			};
		};
	};
	class HitPylon3: HitPylon1
	{
		name="hit_pylon_3";

		class DestructionEffects: DestructionEffects
		{
			class RHS_Pylon_Flash: RHS_Pylon_Flash
			{
				position="fx_pylon_3";
			};
			class RHS_Pylon_Shard: RHS_Pylon_Shard
			{
				position="fx_pylon_3";
			};
			class RHS_Pylon_Smoke: RHS_Pylon_Smoke
			{
				position="fx_pylon_3";
			};
			class RHS_Pylon_Sound: RHS_Pylon_Sound
			{
				position="fx_pylon_3";
			};
		};
	};
	class HitPylon4: HitPylon1
	{
		name="hit_pylon_4";

		class DestructionEffects: DestructionEffects
		{
			class RHS_Pylon_Flash: RHS_Pylon_Flash
			{
				position="fx_pylon_4";
			};
			class RHS_Pylon_Shard: RHS_Pylon_Shard
			{
				position="fx_pylon_4";
			};
			class RHS_Pylon_Smoke: RHS_Pylon_Smoke
			{
				position="fx_pylon_4";
			};
			class RHS_Pylon_Sound: RHS_Pylon_Sound
			{
				position="fx_pylon_4";
			};
		};
	};


	class HitHydraulics
	{
		armor=-42;		//V 0.8 = -28, RC -42
		passThrough=0;	//V 0.8
		material=-1;

		name="hydraulics";
	};
	class HitHStabilizerL1
	{
		armor=-42;		//V 0.8 = -28, RC -42
		passThrough=0;	//V 1
		material=-1;

		name="HStabilizerL1";
	};
	class HitHStabilizerR1: HitHStabilizerL1
	{
		passThrough=0;	//V 0

		name="HStabilizerR1";
	};
	class HitTail
	{
		armor=-42;		//V 0.8 = -28, RC -42
		passThrough=0;	//V 1
		material=-1;

		name="tail boom";
	};
	class HitTransmission
	{
		armor=-42;		//V 0.8 = -28, RC -42
		passThrough=0;	//V 0.8
		material=-1;

		name="transmission";
	};
	class HitVStabilizer1
	{
		armor=-42;		//V 0.8 = -28, RC -42
		passThrough=0;	//V 1
		material=-1;

		name="VStabilizer1";
	};
	class HitPitotTube
	{
		armor=-30;		//V 0.5 = -17.5, RC -30
		passThrough=0;	//V 0.2
		material=-1;

		name="pitot tube";
	};
	class HitStaticPort
	{
		armor=-5.25;		//V 0.1 = -3.5, RC -5.25
		passThrough=0;	//V 1
		material=-1;

		name="static port";
	};
	class HitStarter1
	{
		armor=-5.25;		//V 0.1 = -3.5, RC -5.25
		passThrough=0;	//V 0
		material=-1;

		name="starter1";
	};
	class HitStarter2: HitStarter1
	{
		name="starter2";
	};
	class HitStarter3: HitStarter1
	{
		name="starter3";
	};
	class HitLight
	{
		armor=-3.5;		//V 0.1 = -3.5
		passThrough=0;
		material=-1;

		name="light";
	};


	class HitLGlass
	{
		armor=-5.25;				//V 0.1 = -3.5, H ?, RC -5.25
		explosionShielding=1;	//V 1, H ?
		passThrough=0;			//V 0, H ?
		material=51;

		name="sklo predni L";
		convexComponent="sklo predni L";
		visual="sklo predni L";
	};
	class HitRGlass: HitLGlass
	{
		name="sklo predni P";
		convexComponent="sklo predni P";
		visual="sklo predni P";
	};


	class HitGlass1
	{
		armor=-70;				//V 2 = -70
		radius=0.15;			//V 0.15
		explosionShielding=2;	//V 2
		passThrough=0;
		material=-1;

		name="glass1";
		convexComponent="glass1";
		visual="glass1";
	};
	class HitGlass2: HitGlass1
	{
		name="glass2";
		convexComponent="glass2";
		visual="glass2";
	};
	class HitGlass3: HitGlass1
	{
		radius=0.35;

		name="glass3";
		convexComponent="glass3";
		visual="glass3";
	};
	class HitGlass4: HitGlass3
	{
		name="glass4";
		convexComponent="glass4";
		visual="glass4";
	};
	class HitGlass5
	{
		armor=-70;				//V 2 = -70
		//radius=0.15;			//V NA
		//explosionShielding=2;	//V NA
		passThrough=0;
		material=-1;

		name="glass5";
		convexComponent="glass5";
		visual="glass5";
	};
	class HitGlass6: HitGlass5
	{
		name="glass6";
		convexComponent="glass6";
		visual="glass6";
	};
};