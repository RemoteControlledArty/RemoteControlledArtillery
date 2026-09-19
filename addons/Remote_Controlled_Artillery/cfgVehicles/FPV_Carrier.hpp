class RC_FPV_Carrier_Core: RC_Mule_UGV_Core
{
	displayName="RC FPV Carrier";
	editorSubcategory="RC_UAV_Deployers_subcat";
	unitInfoType="RscOptics_AV_driver";

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
class RC_FPV_Carrier_Base: RC_FPV_Carrier_Core
{
	class EventHandlers: EventHandlers
	{
		#include "\Remote_Controlled_Artillery\includes_script\addToDeployerArray.hpp"

		#include "\Remote_Controlled_Artillery\includes_script\cUAS_Sensor_400m.hpp"
		#include "\Remote_Controlled_Artillery\includes_script\AT_Warning.hpp"
		#include "\Remote_Controlled_Artillery\includes_script\AT_Warning_Backup.hpp"

		#include "\Remote_Controlled_Artillery\includes_script\initLightsOff.hpp"
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

	//scope=2;	//until weapon in rc crocus config is put to main
	//scopeCurator=2;
	
	#include "\Remote_Controlled_Artillery\includes_cfg\sideB_UV.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsB.hpp"
};
class RC_FPV_Carrier_A_O: RC_FPV_Carrier_A
{
	#include "\Remote_Controlled_Artillery\includes_cfg\sideO_UV.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsO.hpp"
};
class RC_FPV_Carrier_A_I: RC_FPV_Carrier_A
{
	#include "\Remote_Controlled_Artillery\includes_cfg\sideI_UV.hpp"
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
	#include "\Remote_Controlled_Artillery\includes_cfg\sideO_UV.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsO.hpp"
};
class RC_FPV_Carrier_WD_I: RC_FPV_Carrier_WD
{
	#include "\Remote_Controlled_Artillery\includes_cfg\sideI_UV.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsI.hpp"
};