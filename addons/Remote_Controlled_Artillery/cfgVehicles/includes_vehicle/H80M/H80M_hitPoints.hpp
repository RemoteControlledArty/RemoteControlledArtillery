/*
armor=35;
armorStructural=20;
epeImpulseDamageCoef=20;
damageResistance=0.01039;
class HitPoints: HitPoints
{
	class HitFuel: HitFuel
	{
		armor=-130;
		armorComponent="fuel_hit";
		name="fuel_hit";
		visual="-";
		radius=0.125;
		minimalhit=-0.039999999;
		explosionShielding=0.5;
		passThrough=0;
	};
	class HitHull: HitHull
	{
		depends="HitEngine";
		simulation="RHS_Hull_Helicopter";
		armor=-120;
		minimalHit=-0.15000001;
		radius=0.02;
		name="hull_hit";
		armorComponent="hull_hit";
		visual="zbytek";
		passThrough=1;
		class DestructionEffects: RHS_Effects_Helicopter_Hull_Destruction
		{
		};
	};
	class HitEngine: HitEngine
	{
		armorComponent="engine_hit";
		name="engine_hit";
		armor=-120;
		visual="-";
		radius=0.15000001;
		explosionShielding=0.85000002;
		minimalhit=-0.050000001;
		passThrough=0.30000001;
	};
	class HitAvionics: HitAvionics
	{
		name="avionics_hit";
		armor=2;
		visual="-";
		radius=0.050000001;
		explosionShielding=0.5;
	};
	class HitVRotor: HitVRotor
	{
		visual="tail rotor static";
		armor=1;
		radius=0.050000001;
		explosionShielding=0.80000001;
	};
	class HitHRotor: HitHRotor
	{
		visual="main rotor static";
		armor=3;
		radius=0.2;
		explosionShielding=0.5;
	};
	class HitGlass1: HitGlass1
	{
		armor=2;				//2
		radius=0.15000001;
		explosionShielding=2;	//2
	};
	class HitGlass2: HitGlass2
	{
		armor=2;				//2
		radius=0.15000001;
		explosionShielding=2;	//2
	};
	class HitGlass3: HitGlass3
	{
		armor=2;				//2
		radius=0.15000001;
		explosionShielding=2;	//2
	};
	class HitGlass4: HitGlass4
	{
		armor=2;				//2
		radius=0.15000001;
		explosionShielding=2;	//2
	};
};
*/