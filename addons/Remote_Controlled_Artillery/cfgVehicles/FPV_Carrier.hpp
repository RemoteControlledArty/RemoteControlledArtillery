class RC_FPV_Carrier_Base: RC_Mortar_UGV_Base
{
	class EventHandlers: EventHandlers
	{
		class RC_Detection
		{
			#include "\Remote_Controlled_Artillery\includes_script\AT_SourceIndicator.hpp"
			#include "\Remote_Controlled_Artillery\includes_script\cUAS_Beep_400m.hpp"
		};
		class RC_LightsOff
		{
			#include "\Remote_Controlled_Artillery\includes_script\initLightsOff.hpp"
		};
	};

	editorSubcategory="RC_UAV_Designator_subcat";

	class Components: Components
	{
		class SensorsManagerComponent
		{
			class Components
			{
				class DataLinkSensorComponent: SensorTemplateDataLink
				{
					typeRecognitionDistance=8000;

					class AirTarget
					{
						minRange=8000;
						maxRange=8000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=8000;
						maxRange=8000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
				};
				#include "\Remote_Controlled_Artillery\includes_cfg\UAS_Sensor.hpp"
			};
		};
	};
};

class RC_FPV_Carrier_A: RC_FPV_Carrier_Base
{
	/*
	weapons[]=
	{
		"RC_FPV_Deployer",
		"SmokeLauncher"
	};
	magazines[]=
	{
		"RC_8xFPV_Deployer_Mag",
		"SmokeLauncherMag"
	};
	*/

	displayName="RC FPV Carrier";
	//scope=2;	//until weapon in rc crocus config is put to main
	//scopeCurator=2;
	
	faction="RemoteControlled_B";
	crew="B_UAV_AI";
	side=1;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsB.hpp"
};
class RC_FPV_Carrier_A_O: RC_FPV_Carrier_A
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsO.hpp"
};
class RC_FPV_Carrier_A_I: RC_FPV_Carrier_A
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsI.hpp"
};



class RC_FPV_Carrier_WD: RC_FPV_Carrier_A
{
	editorPreview="\A3\EditorPreviews_F_Exp\Data\CfgVehicles\B_T_UGV_01_olive_F.jpg";
	textureList[]=
	{
		"Olive",
		1
	};
	hiddenSelectionsTextures[]=
	{
		"\A3\Soft_F_Exp\UGV_01\Data\UGV_01_ext_olive_CO.paa",
		"\A3\Soft_F_Exp\UGV_01\Data\UGV_01_int_olive_CO.paa",
		"\A3\Data_F_Exp\Vehicles\Turret_olive_CO.paa"
	};
};
class RC_FPV_Carrier_WD_O: RC_FPV_Carrier_WD
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsO.hpp"
};
class RC_FPV_Carrier_WD_I: RC_FPV_Carrier_WD
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsI.hpp"
};