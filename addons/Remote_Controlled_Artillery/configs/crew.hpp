// Blufor
class B_crew_F;
class RC_B_crew_F: B_crew_F
{
	weapons[]=
	{
	};
	respawnWeapons[]=
	{
	};
	magazines[]=
	{
	};
	respawnMagazines[]=
	{
	};

	armor=100;
	armorStructural=100;

	class HitPoints
	{
		class HitFace
		{
			armor=100;
			material=-1;
			name="face_hub";
			passThrough=0;
			radius=0.079999998;
			explosionShielding=0.1;
			minimalHit=0.0099999998;
		};
		class HitNeck: HitFace
		{
			armor=100;
			material=-1;
			name="neck";
			passThrough=0;
			radius=0.1;
			explosionShielding=0.5;
			minimalHit=0.0099999998;
		};
		class HitHead: HitNeck
		{
			armor=100;
			material=-1;
			name="head";
			passThrough=0;
			radius=0.2;
			explosionShielding=0.5;
			minimalHit=0.0099999998;
			depends="HitFace max HitNeck";
		};
		class HitPelvis: HitHead
		{
			armor=100;
			material=-1;
			name="pelvis";
			passThrough=0;
			radius=0.23999999;
			explosionShielding=1;
			visual="injury_body";
			minimalHit=0.0099999998;
			depends="0";
		};
		class HitAbdomen: HitPelvis
		{
			armor=100;
			material=-1;
			name="spine1";
			passThrough=0;
			radius=0.16;
			explosionShielding=1;
			visual="injury_body";
			minimalHit=0.0099999998;
		};
		class HitDiaphragm: HitAbdomen
		{
			armor=100;
			material=-1;
			name="spine2";
			passThrough=0;
			radius=0.18000001;
			explosionShielding=6;
			visual="injury_body";
			minimalHit=0.0099999998;
		};
		class HitChest: HitDiaphragm
		{
			armor=100;
			material=-1;
			name="spine3";
			passThrough=0;
			radius=0.18000001;
			explosionShielding=6;
			visual="injury_body";
			minimalHit=0.0099999998;
		};
		class HitBody: HitChest
		{
			armor=100;
			material=-1;
			name="body";
			passThrough=0;
			radius=0;
			explosionShielding=6;
			visual="injury_body";
			minimalHit=0.0099999998;
			depends="HitPelvis max HitAbdomen max HitDiaphragm max HitChest";
		};
		class HitArms: HitBody
		{
			armor=100;
			material=-1;
			name="arms";
			passThrough=0;
			radius=0.1;
			explosionShielding=1;
			visual="injury_hands";
			minimalHit=0.0099999998;
			depends="0";
		};
		class HitHands: HitArms
		{
			armor=100;
			material=-1;
			name="hands";
			passThrough=0;
			radius=0.1;
			explosionShielding=1;
			visual="injury_hands";
			minimalHit=0.0099999998;
			depends="HitArms";
		};
		class HitLegs: HitHands
		{
			armor=100;
			material=-1;
			name="legs";
			passThrough=0;
			radius=0.14;
			explosionShielding=1;
			visual="injury_legs";
			minimalHit=0.0099999998;
			depends="0";
		};
		class Incapacitated: HitLegs
		{
			armor=100;
			material=-1;
			name="body";
			passThrough=0;
			radius=0;
			explosionShielding=1;
			visual="";
			minimalHit=0;
			depends="(((Total - 0.25) max 0) + ((HitHead - 0.25) max 0) + ((HitBody - 0.25) max 0)) * 2";
		};
	};
};

// Independent / Indi
class I_crew_F;
class RC_I_crew_F: I_crew_F
{
	armor=100;
	armorStructural=100;

	weapons[]=
	{
	};
	respawnWeapons[]=
	{
	};
	magazines[]=
	{
	};
	respawnMagazines[]=
	{
	};

	class HitPoints
	{
		class HitFace
		{
			armor=100;
			material=-1;
			name="face_hub";
			passThrough=0;
			radius=0.079999998;
			explosionShielding=0.1;
			minimalHit=0.0099999998;
		};
		class HitNeck: HitFace
		{
			armor=100;
			material=-1;
			name="neck";
			passThrough=0;
			radius=0.1;
			explosionShielding=0.5;
			minimalHit=0.0099999998;
		};
		class HitHead: HitNeck
		{
			armor=100;
			material=-1;
			name="head";
			passThrough=0;
			radius=0.2;
			explosionShielding=0.5;
			minimalHit=0.0099999998;
			depends="HitFace max HitNeck";
		};
		class HitPelvis: HitHead
		{
			armor=100;
			material=-1;
			name="pelvis";
			passThrough=0;
			radius=0.23999999;
			explosionShielding=1;
			visual="injury_body";
			minimalHit=0.0099999998;
			depends="0";
		};
		class HitAbdomen: HitPelvis
		{
			armor=100;
			material=-1;
			name="spine1";
			passThrough=0;
			radius=0.16;
			explosionShielding=1;
			visual="injury_body";
			minimalHit=0.0099999998;
		};
		class HitDiaphragm: HitAbdomen
		{
			armor=100;
			material=-1;
			name="spine2";
			passThrough=0;
			radius=0.18000001;
			explosionShielding=6;
			visual="injury_body";
			minimalHit=0.0099999998;
		};
		class HitChest: HitDiaphragm
		{
			armor=100;
			material=-1;
			name="spine3";
			passThrough=0;
			radius=0.18000001;
			explosionShielding=6;
			visual="injury_body";
			minimalHit=0.0099999998;
		};
		class HitBody: HitChest
		{
			armor=100;
			material=-1;
			name="body";
			passThrough=0;
			radius=0;
			explosionShielding=6;
			visual="injury_body";
			minimalHit=0.0099999998;
			depends="HitPelvis max HitAbdomen max HitDiaphragm max HitChest";
		};
		class HitArms: HitBody
		{
			armor=100;
			material=-1;
			name="arms";
			passThrough=0;
			radius=0.1;
			explosionShielding=1;
			visual="injury_hands";
			minimalHit=0.0099999998;
			depends="0";
		};
		class HitHands: HitArms
		{
			armor=100;
			material=-1;
			name="hands";
			passThrough=0;
			radius=0.1;
			explosionShielding=1;
			visual="injury_hands";
			minimalHit=0.0099999998;
			depends="HitArms";
		};
		class HitLegs: HitHands
		{
			armor=100;
			material=-1;
			name="legs";
			passThrough=0;
			radius=0.14;
			explosionShielding=1;
			visual="injury_legs";
			minimalHit=0.0099999998;
			depends="0";
		};
		class Incapacitated: HitLegs
		{
			armor=100;
			material=-1;
			name="body";
			passThrough=0;
			radius=0;
			explosionShielding=1;
			visual="";
			minimalHit=0;
			depends="(((Total - 0.25) max 0) + ((HitHead - 0.25) max 0) + ((HitBody - 0.25) max 0)) * 2";
		};
	};
};

// Opfor
class O_crew_F;
class RC_O_crew_F: O_crew_F
{
	weapons[]=
	{
	};
	respawnWeapons[]=
	{
	};
	magazines[]=
	{
	};
	respawnMagazines[]=
	{
	};

	armor=100;
	armorStructural=100;

	class HitPoints
	{
		class HitFace
		{
			armor=100;
			material=-1;
			name="face_hub";
			passThrough=0;
			radius=0.079999998;
			explosionShielding=0.1;
			minimalHit=0.0099999998;
		};
		class HitNeck: HitFace
		{
			armor=100;
			material=-1;
			name="neck";
			passThrough=0;
			radius=0.1;
			explosionShielding=0.5;
			minimalHit=0.0099999998;
		};
		class HitHead: HitNeck
		{
			armor=100;
			material=-1;
			name="head";
			passThrough=0;
			radius=0.2;
			explosionShielding=0.5;
			minimalHit=0.0099999998;
			depends="HitFace max HitNeck";
		};
		class HitPelvis: HitHead
		{
			armor=100;
			material=-1;
			name="pelvis";
			passThrough=0;
			radius=0.23999999;
			explosionShielding=1;
			visual="injury_body";
			minimalHit=0.0099999998;
			depends="0";
		};
		class HitAbdomen: HitPelvis
		{
			armor=100;
			material=-1;
			name="spine1";
			passThrough=0;
			radius=0.16;
			explosionShielding=1;
			visual="injury_body";
			minimalHit=0.0099999998;
		};
		class HitDiaphragm: HitAbdomen
		{
			armor=100;
			material=-1;
			name="spine2";
			passThrough=0;
			radius=0.18000001;
			explosionShielding=6;
			visual="injury_body";
			minimalHit=0.0099999998;
		};
		class HitChest: HitDiaphragm
		{
			armor=100;
			material=-1;
			name="spine3";
			passThrough=0;
			radius=0.18000001;
			explosionShielding=6;
			visual="injury_body";
			minimalHit=0.0099999998;
		};
		class HitBody: HitChest
		{
			armor=100;
			material=-1;
			name="body";
			passThrough=0;
			radius=0;
			explosionShielding=6;
			visual="injury_body";
			minimalHit=0.0099999998;
			depends="HitPelvis max HitAbdomen max HitDiaphragm max HitChest";
		};
		class HitArms: HitBody
		{
			armor=100;
			material=-1;
			name="arms";
			passThrough=0;
			radius=0.1;
			explosionShielding=1;
			visual="injury_hands";
			minimalHit=0.0099999998;
			depends="0";
		};
		class HitHands: HitArms
		{
			armor=100;
			material=-1;
			name="hands";
			passThrough=0;
			radius=0.1;
			explosionShielding=1;
			visual="injury_hands";
			minimalHit=0.0099999998;
			depends="HitArms";
		};
		class HitLegs: HitHands
		{
			armor=100;
			material=-1;
			name="legs";
			passThrough=0;
			radius=0.14;
			explosionShielding=1;
			visual="injury_legs";
			minimalHit=0.0099999998;
			depends="0";
		};
		class Incapacitated: HitLegs
		{
			armor=100;
			material=-1;
			name="body";
			passThrough=0;
			radius=0;
			explosionShielding=1;
			visual="";
			minimalHit=0;
			depends="(((Total - 0.25) max 0) + ((HitHead - 0.25) max 0) + ((HitBody - 0.25) max 0)) * 2";
		};
	};
};