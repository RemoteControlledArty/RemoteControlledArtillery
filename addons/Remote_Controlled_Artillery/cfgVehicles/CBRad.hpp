// Counter Battery Radar - Player & AI Versions
class B_Radar_System_01_F;
class RC_CBRad1_base: B_Radar_System_01_F
{
	class Components;
	class Turrets;
	class MainTurret;
	class Hitpoints;
	class HitHull;
	class HitTurret;
	class EventHandlers;
	scope=0;
	scopeCurator=0;

	RC_CBR=1;	//1 = is Counter Battery Radar
};
class RC_CBRad1_Player_A: RC_CBRad1_base
{
	displayName="Counter-Battery Radar (Player)";
	faction="RemoteControlled_B";
	editorSubcategory="RC_Radar_subcat";
	author="Ascent";
	//scope=1;
	//scopeCurator=1;
	scope=2;
	scopeCurator=2;
	side=1;
	forceInGarage=1;

	threat[]={0.2,0.2,0.2};
	//radarTargetSize=1;
	lockDetectionSystem="2+4+8";
	incomingMissileDetectionSystem=16;

	class EventHandlers: EventHandlers
	{	
		class RC_Artillery
		{
			#include "\Remote_Controlled_Artillery\includes_script\CBRad_Player_B.hpp"
		};
	};

	class Components: Components
	{
		class SensorsManagerComponent
		{
			class Components
			{
			};
		};
	};

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			showAllTargets="2 + 4";

			class Components: Components
			{
				class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight
				{
					defaultDisplay="SensorDisplay";

					class Components
					{
						class SensorDisplay
						{
							componentType="SensorsDisplayComponent";
							range[]={50000,30000,15000,7500};
							resource="RscCustomInfoSensors";
						};
					};
				};
			};
		};
	};
};
class RC_CBRad1_Player_A_O: RC_CBRad1_Player_A
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;

	class EventHandlers: EventHandlers
	{	
		class RC_Artillery
		{
			#include "\Remote_Controlled_Artillery\includes_script\CBRad_Player_O.hpp"
		};
	};
};
class RC_CBRad1_Player_A_I: RC_CBRad1_Player_A
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;

	class EventHandlers: EventHandlers
	{	
		class RC_Artillery
		{
			#include "\Remote_Controlled_Artillery\includes_script\CBRad_Player_I.hpp"
		};
	};
};


class RC_CBRad1_Player_WD: RC_CBRad1_Player_A
{
	editorPreview="\A3\EditorPreviews_F_Enoch\Data\Cfgvehicles\I_E_Radar_System_01_F.jpg";
	hiddenSelectionsTextures[]=
	{
		"A3\Static_F_Sams\Radar_System_01\Data\Radar_system_01_mat_01_olive_CO.paa",
		"A3\Static_F_Sams\Radar_System_01\Data\Radar_system_01_mat_02_olive_CO.paa"
	};
};
class RC_CBRad1_Player_WD_O: RC_CBRad1_Player_WD
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;

	class EventHandlers: EventHandlers
	{	
		class RC_Artillery
		{
			#include "\Remote_Controlled_Artillery\includes_script\CBRad_Player_O.hpp"
		};
	};
};
class RC_CBRad1_Player_WD_I: RC_CBRad1_Player_WD
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;

	class EventHandlers: EventHandlers
	{	
		class RC_Artillery
		{
			#include "\Remote_Controlled_Artillery\includes_script\CBRad_Player_I.hpp"
		};
	};
};


class RC_CBRad1_AI_A: RC_CBRad1_Player_A
{
	class EventHandlers: EventHandlers
	{	
		class RC_Artillery
		{
			#include "\Remote_Controlled_Artillery\includes_script\CBRad_AI_B.hpp"
		};
	};

	displayName="Counter-Battery Radar (AI)";

	armor=40;	//80
	armorStructural=1;	//2
	//damageResistance=0.0040000002;

	class Hitpoints: HitPoints
	{
		class HitHull: HitHull
		{
			//armor=3;
			//radius=0.25;
			//minimalHit=0.050000001;
			explosionShielding=4;	//1.5
			passThrough=1;
		};
	};

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			class HitTurret: HitTurret
			{
				//armor=0.30000001;
				//radius=0.25;
				//passThrough=0;
				//minimalHit=0.1;
				explosionShielding=4;	//1.2
			};
		};
	};
};
class RC_CBRad1_AI_A_O: RC_CBRad1_AI_A
{
	class EventHandlers: EventHandlers
	{	
		class RC_Artillery
		{
			#include "\Remote_Controlled_Artillery\includes_script\CBRad_AI_O.hpp"
		};
	};
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
};
class RC_CBRad1_AI_A_I: RC_CBRad1_AI_A
{
	class EventHandlers: EventHandlers
	{	
		class RC_Artillery
		{
			#include "\Remote_Controlled_Artillery\includes_script\CBRad_AI_I.hpp"
		};
	};
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
};


class RC_CBRad1_AI_WD: RC_CBRad1_AI_A
{
	editorPreview="\A3\EditorPreviews_F_Enoch\Data\Cfgvehicles\I_E_Radar_System_01_F.jpg";
	hiddenSelectionsTextures[]=
	{
		"A3\Static_F_Sams\Radar_System_01\Data\Radar_system_01_mat_01_olive_CO.paa",
		"A3\Static_F_Sams\Radar_System_01\Data\Radar_system_01_mat_02_olive_CO.paa"
	};
};
class RC_CBRad1_AI_WD_O: RC_CBRad1_AI_WD
{
	class EventHandlers: EventHandlers
	{	
		class RC_Artillery
		{
			#include "\Remote_Controlled_Artillery\includes_script\CBRad_AI_O.hpp"
		};
	};
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
};
class RC_CBRad1_AI_WD_I: RC_CBRad1_AI_WD
{
	class EventHandlers: EventHandlers
	{	
		class RC_Artillery
		{
			#include "\Remote_Controlled_Artillery\includes_script\CBRad_AI_I.hpp"
		};
	};
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
};


//Hex Camo Counter Battery Radar
class O_Radar_System_02_F;
class RC_CBRad2_base: O_Radar_System_02_F
{
	class Components;
	class Turrets;
	class MainTurret;
	class Hitpoints;
	class HitHull;
	class HitTurret;
	class EventHandlers;
	scope=0;
	scopeCurator=0;

	RC_CBR=1;	//1 = is Counter Battery Radar
};
class RC_CBRad2_Player_A_O: RC_CBRad2_base
{
	displayName="Counter-Battery Radar (Player)";
	faction="RemoteControlled_O";
	editorSubcategory="RC_Radar_subcat";
	author="Ascent";
	//scope=1;
	//scopeCurator=1;
	scope=2;
	scopeCurator=2;
	side=0;
	forceInGarage=1;

	threat[]={0.2,0.2,0.2};
	//radarTargetSize=1;
	lockDetectionSystem="2+4+8";
	incomingMissileDetectionSystem=16;

	class EventHandlers: EventHandlers
	{	
		class RC_Artillery
		{
			#include "\Remote_Controlled_Artillery\includes_script\CBRad_Player_O.hpp"
		};
	};

	class Components: Components
	{
		class SensorsManagerComponent
		{
			class Components
			{
			};
		};
	};

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			showAllTargets="2 + 4";

			class Components: Components
			{
				class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight
				{
					defaultDisplay="SensorDisplay";

					class Components
					{
						class SensorDisplay
						{
							componentType="SensorsDisplayComponent";
							range[]={50000,30000,15000,7500};
							resource="RscCustomInfoSensors";
						};
					};
				};
			};
		};
	};
};
/*
class RC_CBRad2_Player_WD_O: RC_CBRad2_Player_A_O
{
	//editorPreview="\A3\EditorPreviews_F_Enoch\Data\Cfgvehicles\I_E_Radar_System_01_F.jpg";
	hiddenSelectionsTextures[]=
	{
		"A3\Static_F_Sams\Radar_System_02\Data\Radar_system_02_mat_01_ghex_CO.paa",
		"A3\Static_F_Sams\Radar_System_02\Data\Radar_system_02_mat_02_ghex_CO.paa"
	};
};
*/



class RC_CBRad2_AI_A_O: RC_CBRad2_Player_A_O
{
	class EventHandlers: EventHandlers
	{	
		class RC_Artillery
		{
			#include "\Remote_Controlled_Artillery\includes_script\CBRad_AI_O.hpp"
		};
	};

	displayName="Counter-Battery Radar (AI)";

	armor=40;	//80
	armorStructural=1;	//2
	//damageResistance=0.0040000002;

	class Hitpoints: HitPoints
	{
		class HitHull: HitHull
		{
			//armor=3;
			//radius=0.25;
			//minimalHit=0.050000001;
			explosionShielding=4;	//1.5
			passThrough=1;
		};
	};

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			class HitTurret: HitTurret
			{
				//armor=0.30000001;
				//radius=0.25;
				//passThrough=0;
				//minimalHit=0.1;
				explosionShielding=4;	//1.2
			};
		};
	};
};
/*
class RC_CBRad2_AI_WD_O: RC_CBRad2_AI_A_O
{
	//editorPreview="\A3\EditorPreviews_F_Enoch\Data\Cfgvehicles\I_E_Radar_System_01_F.jpg";
	hiddenSelectionsTextures[]=
	{
		"A3\Static_F_Sams\Radar_System_02\Data\Radar_system_02_mat_01_ghex_CO.paa",
		"A3\Static_F_Sams\Radar_System_02\Data\Radar_system_02_mat_02_ghex_CO.paa"
	};
};
*/