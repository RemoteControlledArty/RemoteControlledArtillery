//damage
armor=60; 						//V 30
armorStructural=8;				//V 4
damageResistance=0.01039; 		//V 0.01039, H 0.00555
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
		armor=-60;				//V 1 = -30, H ?, RC -400000
		depends="Total";		//V "Total"
		radius=0.12;			//V 0.12
		minimalHit=0.02;		//V 0.02
		explosionShielding=1;	//V 1, RC 1
		passThrough=1;			//V 1, H ?, RC 1/0.5/0
		material=-1;			//V -1, RC 51

		name="hull_hit";
		convexComponent="hull_hit";
		visual="";
	};
	class HitFuel
	{
		armor=-42;				//V 0.7 = -21, H ?, RC -150
		radius=0.11;			//V 0.11
		minimalHit=0.02;		//V 0.02
		explosionShielding=1;	//V 2, RC 1
		passThrough=0;			//V 1
		material=-1;			//-1, RC 51

		name="fuel_hit";
		convexComponent="fuel_hit";
		visual="";
	};
	class HitAvionics
	{
		armor=-30;					//V 0.5 = -15, H ?, RC -80
		radius=0.09;				//V 0.09
		minimalHit=0.02;			//V 0.02, RC 0.1
		explosionShielding=1;		//V 1, RC 1
		passThrough=0;				//V 0.3, H ?
		material=-1;				//-1, RC 51

		name="avionics_hit";
		convexComponent="avionics_hit";
		visual="";
	};
	class HitHRotor
	{
		armor=-42;					//V 0.7 = -21, H 10.35, 10.35 = -414, RC = -400
		radius=0.06;				//V 0.06, H 0.47, RC 0.4
		minimalHit=0.02;			//V 0.02, H 0.1, RC 0.1
		explosionShielding=1;		//V 1, H 3000, RC 1.75
		passThrough=0;				//V 0.15, H 0, RC 0
		material=-1;				//V 51, H 51

		name="main_rotor_hit";
		convexComponent="main_rotor_hit";
		visual="";
	};
	class HitEngine
	{
		armor=-42;				//V 0.7 = -21, H 66.6, 999 = -39960, RC -40000
		radius=0.09;			//V 0.09, H 0.05
		explosionShielding=1;	//V 1, H 1
		minimalHit=0.02;		//V 0.02, H 1
		passThrough=0;			//V 1, H 0, RC 0
		material=-1;			//V 51, H 51

		name="engine_hit";
		convexComponent="engine_hit";
		visual="";
	};
};