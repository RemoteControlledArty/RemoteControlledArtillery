//OM AH-6M
class O_Heli_Transport_04_black_F;
class RC_OM_Heli_SkyCrane_Core: O_Heli_Transport_04_black_F
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_fetch.hpp"
};
class RC_OM_Heli_SkyCrane_Base: RC_OM_Heli_SkyCrane_Core
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_main.hpp"

	//class CargoTurret;

	class Turrets: Turrets
	{
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_turrets.hpp"
	};
};
class RC_OM_Heli_SkyCrane_blk_UV: RC_OM_Heli_SkyCrane_Base
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_EH.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_UA.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_UV.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_logi_small.hpp"

	displayName="OM AH-6M";
};
class RC_OM_Heli_SkyCrane_blk: RC_OM_Heli_SkyCrane_blk_UV
{
	scope=2;
	scopeCurator=2;
	forceInGarage=1;

	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideB.hpp"
};
class RC_OM_Heli_SkyCrane_blk_O: RC_OM_Heli_SkyCrane_blk
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideO.hpp"
};
class RC_OM_Heli_SkyCrane_blk_I: RC_OM_Heli_SkyCrane_blk
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideI.hpp"
};


//OM MH-6M