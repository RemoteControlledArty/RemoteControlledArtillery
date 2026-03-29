//damage
armor=25; 						//V 40, H 600, RC 80 (600 doesnt get engaged, so 40 with armoredstructural 4x15=60 used instead)
armorStructural=25;				//V 4, H 4  <- there might be a solution here!, RC 4x15=60
damageResistance=0.00555; 		//V 0.00555, H 0.00555
epeImpulseDamageCoef=0;			//V 50, H 0, RC 0
explosionShielding=4;			//V 4, H 4
fuelExplosionPower=1;			//V 1, H 1
minTotalDamageThreshold=0.005;	//V 0.005, H 0.05, RC 0.005
secondaryExplosion=-1;			//V -1, H -1
crewCrashProtection=0.01;		//V 0.2, H 0.25
crewVulnerable=1;				//V 1, H 1
hullDamageCauseExplosion=0;		//V 0, H 0
//hullExplosionDelay[]={,};		//undefined because bool is 0, also hull armor is very high


class HitPoints: HitPoints
{
	class HitHull
	{
		armor=-40000;			//V 999 = -400000, H ?, RC -400000
		depends="Total";		//V "Total"
		radius=0.01;			//V 0.01
		minimalHit=0.05;		//V 0.05
		passThrough=1;			//V 1, H ?, RC 1/0.5/0
		material=51;

		name="hull_hit";
		convexComponent="hull_hit";
		visual="zbytek";
	};
	class HitFuel
	{
		armor=-150;				//V 1 = -40, H ?, RC -150
		radius=0.25;			//V 0.25
		minimalHit=0.05;		//V 0.05
		explosionShielding=1;	//V 1, RC 1
		passThrough=0;			//V 1
		material=51;

		name="fuel_hit";
		convexComponent="fuel_hit";
		visual="zbytek";
	};
	class HitAvionics
	{
		armor=-80;					//V 2 = -80, H ?, RC -80
		radius=0.4;					//V 0.4
		minimalHit=0.1;				//V 0.1, RC 0.1
		explosionShielding=1;		//V 1, RC 1
		passThrough=0;				//V 1, H ?
		material=51;

		name="avionics_hit";
		convexComponent="avionics_hit";
		visual="elektronika";
	};
	class HitHRotor
	{
		armor=-400;					//V 4.5 = -180, H 10.35, 10.35 = -414, RC = -400
		radius=0.4;					//V 0.4, H 0.47, RC 0.4
		minimalHit=0.1;				//V 0.09, H 0.1, RC 0.1
		explosionShielding=1.75;	//V 2.5, H 3000, RC 1.75
		passThrough=0;				//V 0.1, H 0, RC 0
		material=51;				//V 51, H 51

		name="main_rotor_hit";
		convexComponent="main_rotor_hit";
		visual="main rotor static";
	};
	class HitVRotor
	{
		armor=-200;					//V 3 = -120, H 0.054, 0.81 = -32.4, RC -200
		radius=0.06;				//V 0.06, H 0.24
		minimalHit=0.1;				//V 0.09, H 0.1, RC 0.1
		explosionShielding=1;		//V 6, H 0.27, RC 1
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
		visual="motor";
	};
	class HitEngine1
	{
		armor=-43.2;				//V 1 = -40, H 0.072, 1.08 = -43.2, RC -40
		radius=0.4;					//V 0.4, H 0.59, RC 0.4
		explosionShielding=1.73;	//V 3, H 0.46, RC 1.73
		minimalHit=0.2;				//V 0.2, H 0.1
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
	class HitEngine3
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
		armor=-40;					//V 1 = -40, H 0.036, 0.54 = -21.6, RC -40
		radius=0.15;				//V 0.15, H 0.3, RC 0.15
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
		armor=-60;		//V 0.9 = -36, RC -60
		passThrough=0;	//V 0
		material=-1;

		name="gear";
	};
	class HitWinch
	{
		armor=-120;		//V -4	0
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


	class HitHydraulics
	{
		armor=-48;		//V 0.8 = -32, RC -48
		passThrough=0;	//V 0.8
		material=-1;

		name="hydraulics";
	};
	class HitHStabilizerL1
	{
		armor=-48;		//V 0.8 = -32, RC -48
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
		armor=-48;		//V 0.8 = -32, RC -48
		passThrough=0;	//V 1
		material=-1;

		name="tail boom";
	};
	class HitTransmission
	{
		armor=-48;		//V 0.8 = -32, RC -48
		passThrough=0;	//V 0.8
		material=-1;

		name="transmission";
	};
	class HitVStabilizer1
	{
		armor=-48;		//V 0.8 = -32, RC -48
		passThrough=0;	//V 1
		material=-1;

		name="VStabilizer1";
	};
	class HitPitotTube
	{
		armor=-30;		//V 0.5 = -20, RC -30
		passThrough=0;	//V 0.2
		material=-1;

		name="pitot tube";
	};
	class HitStaticPort
	{
		armor=-6;		//V 0.1 = -4, RC -6
		passThrough=0;	//V 1
		material=-1;

		name="static port";
	};
	class HitStarter1
	{
		armor=-6;		//V 0.1 = -4, RC -6
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
		armor=-4;		//V 0.1 = -4
		passThrough=0;
		material=-1;

		name="light";
	};


	class HitLGlass
	{
		armor=-6;				//V 0.1 = -4, H ?, RC -6
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
		armor=-180;				//V 4.5 = -180, RC -180
		radius=0.37;			//V 0.37
		minimalHit=0.05;		//V 0.05
		explosionShielding=2;	//V 2
		passThrough=0;
		material=-1;

		name="glass1";
		visual="glass1";

		class DestructionEffects
		{
			ammoExplosionEffect="";

			class BrokenGlass1
			{
				intensity=0.15;
				interval=1;
				lifeTime=0.05;
				position="GlassEffects1";
				simulation="particles";

				type="BrokenGlass1NS";
			};
			class BrokenGlass1S: BrokenGlass1
			{
				type="BrokenGlass1SS";
			};
			class BrokenGlass2: BrokenGlass1
			{
				type="BrokenGlass2NS";
			};
			class BrokenGlass2S: BrokenGlass1
			{
				type="BrokenGlass2SS";
			};
			class BrokenGlass3: BrokenGlass1
			{
				type="BrokenGlass3NS";
			};
			class BrokenGlass3S: BrokenGlass1
			{
				type="BrokenGlass3SS";
			};
			class BrokenGlass4: BrokenGlass1
			{
				type="BrokenGlass4NS";
			};
			class BrokenGlass4S: BrokenGlass1
			{
				type="BrokenGlass4SS";
			};
			class BrokenGlass5: BrokenGlass1
			{
				type="BrokenGlass5NS";
			};
			class BrokenGlass5S: BrokenGlass1
			{
				type="BrokenGlass5SS";
			};
		};
	};
	class HitGlass2: HitGlass1
	{
		armor=-120;				//V 3 = -120, RC -120
		explosionShielding=1.5;	//V 1.5

		name="glass2";
		visual="glass2";

		class DestructionEffects: DestructionEffects
		{
			class BrokenGlass1: BrokenGlass1
			{
				position="GlassEffects2";
			};
			class BrokenGlass1S: BrokenGlass1S
			{
				position="GlassEffects2";
			};
			class BrokenGlass2: BrokenGlass2
			{
				position="GlassEffects2";
			};
			class BrokenGlass2S: BrokenGlass2S
			{
				position="GlassEffects2";
			};
			class BrokenGlass3: BrokenGlass3
			{
				position="GlassEffects2";
			};
			class BrokenGlass3S: BrokenGlass3S
			{
				position="GlassEffects2";
			};
			class BrokenGlass4: BrokenGlass4
			{
				position="GlassEffects2";
			};
			class BrokenGlass4S: BrokenGlass4S
			{
				position="GlassEffects2";
			};
			class BrokenGlass5: BrokenGlass5
			{
				position="GlassEffects2";
			};
			class BrokenGlass5S: BrokenGlass5S
			{
				position="GlassEffects2";
			};
		};
	};
	class HitGlass3: HitGlass2
	{
		radius=0.25;			//V 0.25

		name="glass3";
		visual="glass3";

		class DestructionEffects: DestructionEffects
		{
			class BrokenGlass1: BrokenGlass1
			{
				position="GlassEffects3";
			};
			class BrokenGlass1S: BrokenGlass1S
			{
				position="GlassEffects3";
			};
			class BrokenGlass2: BrokenGlass2
			{
				position="GlassEffects3";
			};
			class BrokenGlass2S: BrokenGlass2S
			{
				position="GlassEffects3";
			};
			class BrokenGlass3: BrokenGlass3
			{
				position="GlassEffects3";
			};
			class BrokenGlass3S: BrokenGlass3S
			{
				position="GlassEffects3";
			};
			class BrokenGlass4: BrokenGlass4
			{
				position="GlassEffects3";
			};
			class BrokenGlass4S: BrokenGlass4S
			{
				position="GlassEffects3";
			};
			class BrokenGlass5: BrokenGlass5
			{
				position="GlassEffects3";
			};
			class BrokenGlass5S: BrokenGlass5S
			{
				position="GlassEffects3";
			};
		};
	};
	class HitGlass4: HitGlass3
	{
		name="glass4";
		visual="glass4";
		
		class DestructionEffects: DestructionEffects
		{
			class BrokenGlass1: BrokenGlass1
			{
				position="GlassEffects4";
			};
			class BrokenGlass1S: BrokenGlass1S
			{
				position="GlassEffects4";
			};
			class BrokenGlass2: BrokenGlass2
			{
				position="GlassEffects4";
			};
			class BrokenGlass2S: BrokenGlass2S
			{
				position="GlassEffects4";
			};
			class BrokenGlass3: BrokenGlass3
			{
				position="GlassEffects4";
			};
			class BrokenGlass3S: BrokenGlass3S
			{
				position="GlassEffects4";
			};
			class BrokenGlass4: BrokenGlass4
			{
				position="GlassEffects4";
			};
			class BrokenGlass4S: BrokenGlass4S
			{
				position="GlassEffects4";
			};
			class BrokenGlass5: BrokenGlass5
			{
				position="GlassEffects4";
			};
			class BrokenGlass5S: BrokenGlass5S
			{
				position="GlassEffects4";
			};
		};
	};
	class HitGlass5: HitGlass1
	{
		radius=0.34;			//V 0.34

		name="glass5";
		visual="glass5";

		class DestructionEffects: DestructionEffects
		{
			class BrokenGlass1: BrokenGlass1
			{
				position="GlassEffects5";
			};
			class BrokenGlass1S: BrokenGlass1S
			{
				position="GlassEffects5";
			};
			class BrokenGlass2: BrokenGlass2
			{
				position="GlassEffects5";
			};
			class BrokenGlass2S: BrokenGlass2S
			{
				position="GlassEffects5";
			};
			class BrokenGlass3: BrokenGlass3
			{
				position="GlassEffects5";
			};
			class BrokenGlass3S: BrokenGlass3S
			{
				position="GlassEffects5";
			};
			class BrokenGlass4: BrokenGlass4
			{
				position="GlassEffects5";
			};
			class BrokenGlass4S: BrokenGlass4S
			{
				position="GlassEffects5";
			};
			class BrokenGlass5: BrokenGlass5
			{
				position="GlassEffects5";
			};
			class BrokenGlass5S: BrokenGlass5S
			{
				position="GlassEffects5";
			};
		};
	};
	class HitGlass6: HitGlass5
	{
		armor=-120;				//V 3 = -120, RC -120
		explosionShielding=1.5;	//V 1.5

		name="glass6";
		visual="glass6";

		class DestructionEffects: DestructionEffects
		{
			class BrokenGlass1: BrokenGlass1
			{
				position="GlassEffects6";
			};
			class BrokenGlass1S: BrokenGlass1S
			{
				position="GlassEffects6";
			};
			class BrokenGlass2: BrokenGlass2
			{
				position="GlassEffects6";
			};
			class BrokenGlass2S: BrokenGlass2S
			{
				position="GlassEffects6";
			};
			class BrokenGlass3: BrokenGlass3
			{
				position="GlassEffects6";
			};
			class BrokenGlass3S: BrokenGlass3S
			{
				position="GlassEffects6";
			};
			class BrokenGlass4: BrokenGlass4
			{
				position="GlassEffects6";
			};
			class BrokenGlass4S: BrokenGlass4S
			{
				position="GlassEffects6";
			};
			class BrokenGlass5: BrokenGlass5
			{
				position="GlassEffects6";
			};
			class BrokenGlass5S: BrokenGlass5S
			{
				position="GlassEffects6";
			};
		};
	};
	class HitGlass7: HitGlass6
	{
		radius=0.2;

		name="glass7";
		visual="glass7";

		class DestructionEffects: DestructionEffects
		{
			class BrokenGlass1: BrokenGlass1
			{
				position="GlassEffects7";
			};
			class BrokenGlass1S: BrokenGlass1S
			{
				position="GlassEffects7";
			};
			class BrokenGlass2: BrokenGlass2
			{
				position="GlassEffects7";
			};
			class BrokenGlass2S: BrokenGlass2S
			{
				position="GlassEffects7";
			};
			class BrokenGlass3: BrokenGlass3
			{
				position="GlassEffects7";
			};
			class BrokenGlass3S: BrokenGlass3S
			{
				position="GlassEffects7";
			};
			class BrokenGlass4: BrokenGlass4
			{
				position="GlassEffects7";
			};
			class BrokenGlass4S: BrokenGlass4S
			{
				position="GlassEffects7";
			};
			class BrokenGlass5: BrokenGlass5
			{
				position="GlassEffects7";
			};
			class BrokenGlass5S: BrokenGlass5S
			{
				position="GlassEffects7";
			};
		};
	};
	class HitGlass8: HitGlass7
	{
		name="glass8";
		visual="glass8";

		class DestructionEffects: DestructionEffects
		{
			class BrokenGlass1: BrokenGlass1
			{
				position="GlassEffects8";
			};
			class BrokenGlass1S: BrokenGlass1S
			{
				position="GlassEffects8";
			};
			class BrokenGlass2: BrokenGlass2
			{
				position="GlassEffects8";
			};
			class BrokenGlass2S: BrokenGlass2S
			{
				position="GlassEffects8";
			};
			class BrokenGlass3: BrokenGlass3
			{
				position="GlassEffects8";
			};
			class BrokenGlass3S: BrokenGlass3S
			{
				position="GlassEffects8";
			};
			class BrokenGlass4: BrokenGlass4
			{
				position="GlassEffects8";
			};
			class BrokenGlass4S: BrokenGlass4S
			{
				position="GlassEffects8";
			};
			class BrokenGlass5: BrokenGlass5
			{
				position="GlassEffects8";
			};
			class BrokenGlass5S: BrokenGlass5S
			{
				position="GlassEffects8";
			};
		};
	};
	class HitGlass9: HitGlass1
	{
		armor=-32;				//V 0.8 = -32, RC -32
		explosionShielding=1;	//V 1
		radius=0.24;

		name="glass9";
		visual="glass9";

		class DestructionEffects: DestructionEffects
		{
			class BrokenGlass1: BrokenGlass1
			{
				position="GlassEffects9";
			};
			class BrokenGlass1S: BrokenGlass1S
			{
				position="GlassEffects9";
			};
			class BrokenGlass2: BrokenGlass2
			{
				position="GlassEffects9";
			};
			class BrokenGlass2S: BrokenGlass2S
			{
				position="GlassEffects9";
			};
			class BrokenGlass3: BrokenGlass3
			{
				position="GlassEffects9";
			};
			class BrokenGlass3S: BrokenGlass3S
			{
				position="GlassEffects9";
			};
			class BrokenGlass4: BrokenGlass4
			{
				position="GlassEffects9";
			};
			class BrokenGlass4S: BrokenGlass4S
			{
				position="GlassEffects9";
			};
			class BrokenGlass5: BrokenGlass5
			{
				position="GlassEffects9";
			};
			class BrokenGlass5S: BrokenGlass5S
			{
				position="GlassEffects9";
			};
		};
	};
	class HitGlass10: HitGlass9
	{
		name="glass10";
		visual="glass10";

		class DestructionEffects: DestructionEffects
		{
			class BrokenGlass1: BrokenGlass1
			{
				position="GlassEffects10";
			};
			class BrokenGlass1S: BrokenGlass1S
			{
				position="GlassEffects10";
			};
			class BrokenGlass2: BrokenGlass2
			{
				position="GlassEffects10";
			};
			class BrokenGlass2S: BrokenGlass2S
			{
				position="GlassEffects10";
			};
			class BrokenGlass3: BrokenGlass3
			{
				position="GlassEffects10";
			};
			class BrokenGlass3S: BrokenGlass3S
			{
				position="GlassEffects10";
			};
			class BrokenGlass4: BrokenGlass4
			{
				position="GlassEffects10";
			};
			class BrokenGlass4S: BrokenGlass4S
			{
				position="GlassEffects10";
			};
			class BrokenGlass5: BrokenGlass5
			{
				position="GlassEffects10";
			};
			class BrokenGlass5S: BrokenGlass5S
			{
				position="GlassEffects10";
			};
		};
	};
	class HitGlass11: HitGlass9
	{
		name="glass11";
		visual="glass11";

		class DestructionEffects: DestructionEffects
		{
			class BrokenGlass1: BrokenGlass1
			{
				position="GlassEffects11";
			};
			class BrokenGlass1S: BrokenGlass1S
			{
				position="GlassEffects11";
			};
			class BrokenGlass2: BrokenGlass2
			{
				position="GlassEffects11";
			};
			class BrokenGlass2S: BrokenGlass2S
			{
				position="GlassEffects11";
			};
			class BrokenGlass3: BrokenGlass3
			{
				position="GlassEffects11";
			};
			class BrokenGlass3S: BrokenGlass3S
			{
				position="GlassEffects11";
			};
			class BrokenGlass4: BrokenGlass4
			{
				position="GlassEffects11";
			};
			class BrokenGlass4S: BrokenGlass4S
			{
				position="GlassEffects11";
			};
			class BrokenGlass5: BrokenGlass5
			{
				position="GlassEffects11";
			};
			class BrokenGlass5S: BrokenGlass5S
			{
				position="GlassEffects11";
			};
		};
	};
	class HitGlass12: HitGlass9
	{
		name="glass12";
		visual="glass12";

		class DestructionEffects: DestructionEffects
		{
			class BrokenGlass1: BrokenGlass1
			{
				position="GlassEffects12";
			};
			class BrokenGlass1S: BrokenGlass1S
			{
				position="GlassEffects12";
			};
			class BrokenGlass2: BrokenGlass2
			{
				position="GlassEffects12";
			};
			class BrokenGlass2S: BrokenGlass2S
			{
				position="GlassEffects12";
			};
			class BrokenGlass3: BrokenGlass3
			{
				position="GlassEffects12";
			};
			class BrokenGlass3S: BrokenGlass3S
			{
				position="GlassEffects12";
			};
			class BrokenGlass4: BrokenGlass4
			{
				position="GlassEffects12";
			};
			class BrokenGlass4S: BrokenGlass4S
			{
				position="GlassEffects12";
			};
			class BrokenGlass5: BrokenGlass5
			{
				position="GlassEffects12";
			};
			class BrokenGlass5S: BrokenGlass5S
			{
				position="GlassEffects12";
			};
		};
	};
	class HitGlass13: HitGlass9
	{
		name="glass13";
		visual="glass13";

		class DestructionEffects: DestructionEffects
		{
			class BrokenGlass1: BrokenGlass1
			{
				position="GlassEffects13";
			};
			class BrokenGlass1S: BrokenGlass1S
			{
				position="GlassEffects13";
			};
			class BrokenGlass2: BrokenGlass2
			{
				position="GlassEffects13";
			};
			class BrokenGlass2S: BrokenGlass2S
			{
				position="GlassEffects13";
			};
			class BrokenGlass3: BrokenGlass3
			{
				position="GlassEffects13";
			};
			class BrokenGlass3S: BrokenGlass3S
			{
				position="GlassEffects13";
			};
			class BrokenGlass4: BrokenGlass4
			{
				position="GlassEffects13";
			};
			class BrokenGlass4S: BrokenGlass4S
			{
				position="GlassEffects13";
			};
			class BrokenGlass5: BrokenGlass5
			{
				position="GlassEffects13";
			};
			class BrokenGlass5S: BrokenGlass5S
			{
				position="GlassEffects13";
			};
		};
	};
	class HitGlass14: HitGlass9
	{
		name="glass14";
		visual="glass14";

		class DestructionEffects: DestructionEffects
		{
			class BrokenGlass1: BrokenGlass1
			{
				position="GlassEffects14";
			};
			class BrokenGlass1S: BrokenGlass1S
			{
				position="GlassEffects14";
			};
			class BrokenGlass2: BrokenGlass2
			{
				position="GlassEffects14";
			};
			class BrokenGlass2S: BrokenGlass2S
			{
				position="GlassEffects14";
			};
			class BrokenGlass3: BrokenGlass3
			{
				position="GlassEffects14";
			};
			class BrokenGlass3S: BrokenGlass3S
			{
				position="GlassEffects14";
			};
			class BrokenGlass4: BrokenGlass4
			{
				position="GlassEffects14";
			};
			class BrokenGlass4S: BrokenGlass4S
			{
				position="GlassEffects14";
			};
			class BrokenGlass5: BrokenGlass5
			{
				position="GlassEffects14";
			};
			class BrokenGlass5S: BrokenGlass5S
			{
				position="GlassEffects14";
			};
		};
	};
};