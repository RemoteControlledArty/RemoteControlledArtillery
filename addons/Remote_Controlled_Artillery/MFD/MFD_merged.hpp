//defaultUserMFDvalues[]={0.25,1,0.25,1};							//AH99
defaultUserMFDvalues[]={0.15000001,1,0.15000001,0.69999999};		//KA60
//defaultUserMFDvalues[]={0.25,1,0.25,1};							//Mi48
//defaultUserMFDvalues[]={0,1,0.30000001,1};						//Hellcat


class MFD
{
	class AirplaneHUD
	{
		//base
		#include "\Remote_Controlled_Artillery\MFD\MFD_HUD_base.hpp"

		class Bones
		{
			//additions
			//#include "\Remote_Controlled_Artillery\MFD\MFD_bones_static.hpp"
			#include "\Remote_Controlled_Artillery\MFD\MFD_bones_vector.hpp"
			#include "\Remote_Controlled_Artillery\MFD\MFD_bones_vertical.hpp"
			#include "\Remote_Controlled_Artillery\MFD\MFD_bones_horizontal.hpp"
			#include "\Remote_Controlled_Artillery\MFD\MFD_bones_impact.hpp"
		};

		class Draw
		{
			//base
			#include "\Remote_Controlled_Artillery\MFD\MFD_draw_base.hpp"

			//additions
			//#include "\Remote_Controlled_Artillery\MFD\MFD_draw_static.hpp"
			#include "\Remote_Controlled_Artillery\MFD\MFD_draw_vector.hpp"
			#include "\Remote_Controlled_Artillery\MFD\MFD_draw_vertical.hpp"
			#include "\Remote_Controlled_Artillery\MFD\MFD_draw_horizontal.hpp"
			#include "\Remote_Controlled_Artillery\MFD\MFD_draw_impact.hpp"
		};
	};
};