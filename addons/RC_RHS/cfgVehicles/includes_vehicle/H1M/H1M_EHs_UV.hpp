class EventHandlers: EventHandlers
{
	class RC_Heli
	{
		#include "\Remote_Controlled_Artillery\includes_script\killedHeli.hpp"
	};
	class RC_Autonomous
	{
		init="(_this select 0) spawn {waitUntil {!isNull driver _this}; _this disableAI 'FIREWEAPON';};";
	};
};