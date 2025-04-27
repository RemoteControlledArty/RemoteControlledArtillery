class RC_AC_FSV_A: RC_AA_A
{
	/*
	class EventHandlers: EventHandlers
	{
	};
	*/

	displayName="RC Annihilator FSV/C-UAS";
	editorSubcategory="RC_FSV_subcat";

	class AnimationSources: AnimationSources
	{
		class Missiles_revolving
		{
			source="revolving";
			weapon="RC_AA_Missile_Launcher";
		};
		class Missiles_reloadMagazine: Missiles_revolving
		{
			source="reloadMagazine";
		};
		class muzzle_rot
		{
			source="ammorandom";
			weapon="RC_autocannon_35mm";
		};
		class cannon_35mm_revolving
		{
			source="revolving";
			weapon="RC_autocannon_35mm";
		};
	};

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_cfg\panels_FSV_gunner_missile.hpp"
			dontCreateAI=1;

			weapons[]=
			{
				"RC_autocannon_35mm",
				"RC_AA_Missile_Launcher",
				"SmokeLauncher"
			};
			#include "\Remote_Controlled_Artillery\includes_vicmags\mags_AC_FSV_35mm_red.hpp"

			class Turrets: Turrets
			{
				class CommanderOptics: CommanderOptics
				{
					#include "\Remote_Controlled_Artillery\includes_cfg\panels_FSV_commander.hpp"
					dontCreateAI=1;
				};
			};
		};
	};

	class Components: Components
	{
		class SensorsManagerComponent
		{
			class Components
			{
				class ActiveRadarSensorComponent: SensorTemplateActiveRadar
				{
					class AirTarget
					{
						minRange=4000;
						maxRange=4000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=4000;
						maxRange=4000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					typeRecognitionDistance=4000;
					angleRangeHorizontal=360;
					angleRangeVertical=360;
					aimDown=0;
					maxTrackableSpeed=694.44397;
				};
				class DataLinkSensorComponent: SensorTemplateDataLink
				{
					typeRecognitionDistance=67000;

					class AirTarget
					{
						minRange=67000;
						maxRange=67000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=67000;
						maxRange=67000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
				};
				class IRSensorComponent: SensorTemplateIR
				{
					typeRecognitionDistance=4000;

					class AirTarget
					{
						minRange=4000;
						maxRange=4000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=4000;
						maxRange=4000;
						objectDistanceLimitCoef=1;
						viewDistanceLimitCoef=1;
					};
					maxTrackableSpeed=600;
					angleRangeHorizontal=1;
					angleRangeVertical=1;
					animDirection="mainGun";
				};
				class VisualSensorComponent: SensorTemplateVisual
				{
					typeRecognitionDistance=600;

					class AirTarget
					{
						minRange=600;
						maxRange=600;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=0;
						maxRange=0;
						objectDistanceLimitCoef=1;
						viewDistanceLimitCoef=1;
					};
					maxTrackableSpeed=600;
					nightRangeCoef=0.80000001;
					angleRangeHorizontal=360;
					angleRangeVertical=360;
					animDirection="mainGun";
				};
				class ManSensorComponent: SensorTemplateMan
				{
					typeRecognitionDistance=500;
					class AirTarget
					{
						minRange=500;
						maxRange=500;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=500;
						maxRange=500;
						objectDistanceLimitCoef=1;
						viewDistanceLimitCoef=1;
					};
					maxTrackableSpeed=15;
					angleRangeHorizontal=22.5;
					angleRangeVertical=22.5;
					animDirection="mainGun";
					aimDown=0;
				};
				class PassiveRadarSensorComponent: SensorTemplatePassiveRadar
				{
					typeRecognitionDistance=1;
					class AirTarget
					{
						minRange=4000;
						maxRange=4000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=4000;
						maxRange=4000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					//allowsMarking=1;	//targeting would be great, problem is just it tells name which seems a bit op?
				};
			};
		};
	};

	#include "\Remote_Controlled_Artillery\loadouts\FSVitemsB.hpp"
};
class RC_AC_FSV_WD: RC_AC_FSV_A
{
	DLC="Expansion";
	editorPreview="\A3\EditorPreviews_F_Exp\Data\CfgVehicles\B_T_APC_Tracked_01_AA_F.jpg";
	hiddenSelectionsTextures[]=
	{
		"A3\Armor_F_exp\APC_Tracked_01\Data\apc_tracked_01_aa_body_olive_co.paa",
		"A3\Armor_F_exp\APC_Tracked_01\Data\mbt_01_body_olive_co.paa",
		"A3\Armor_F_exp\APC_Tracked_01\Data\apc_tracked_01_aa_tower_olive_co.paa",
		//"a3\Armor_F\Data\camonet_NATO_Green_CO.paa"
		"a3\armor_f\data\camonet_green_co.paa"
	};
};
/*
class RC_AA_A_O: RC_AA_A
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_vicmags\mags_AA_35mm_green.hpp"
		};
	};
};
class RC_AA_WD_O: RC_AA_WD
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_vicmags\mags_AA_35mm_green.hpp"
		};
	};
};
class RC_AA_A_I: RC_AA_A
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_vicmags\mags_AA_35mm_yellow.hpp"
		};
	};
};
class RC_AA_WD_I: RC_AA_WD
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_vicmags\mags_AA_35mm_yellow.hpp"
		};
	};
};
*/