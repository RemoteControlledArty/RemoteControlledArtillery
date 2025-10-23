class EventHandlers: EventHandlers
{
	class RC_Detection
	{
		#include "\Remote_Controlled_Artillery\includes_script\AT_SourceIndicator.hpp"
		#include "\Remote_Controlled_Artillery\includes_script\cUAS_Beep_400m.hpp"
	};
	class RC_AT_Warning
	{
		#include "\Remote_Controlled_Artillery\includes_script\AT_Warning.hpp"
	};
	class RC_Heli
	{
		//#include "\Remote_Controlled_Artillery\includes_script\initHeli.hpp"
		#include "\Remote_Controlled_Artillery\includes_script\killedHeli.hpp"
	};
};