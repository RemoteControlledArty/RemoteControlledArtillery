dlc = "RHS_AFRF";
rhs_decalParameters[]={
	"['Number',cRHSAIRPchelaNumberPlaces,'AviaRed']"
};
rhs_hasNoRadar=1;

category = "Autonomous";
wreck = "";
scope = 0;
faction="rhs_faction_vvs";
side = 0;
crew = "O_UAV_AI";
typicalCargo[] = {"O_UAV_AI"};
accuracy = 1;

class Library
{
	libTextDesc = "The Pchela-1T is an unmanned aerial vehicle (UAV) developed in Russia. Its primary uses are surveillance and observation or target designation.";
};
displayName = "Pchela-1T";
model = "\rhsafrf\addons\rhs_a2port_air\PCHELA1T\Pchela1T.p3d";
//picture = "\ca\air2\data\UI\picture_Pchela1T_CA.paa";
icon = "\rhsafrf\addons\rhs_a2port_air\data\map_ico\icon_Pchela1T_CA.paa";
mapSize = 5;
armor = 75;
damageResistance = 0.03176;
class Hitpoints
{
	class HitHull 			{armor = -50;	explosionShielding = 0.80; passThrough = 1.0; minimalHit = -0.4;	radius = 0.15; material = -1; name = "trup";		visual = "zbytek";	depends = "0";  	};
	class HitEngine 		{armor = -40;	explosionShielding = 1.0; passThrough = 0.20; minimalHit = -0.05;	radius = 0.07; material = -1; name = "motor";		visual = "zbytek";	depends = "0"; 		};
	class HitLCRudder 		{armor = -30;	explosionShielding = 0.60; passThrough = 0.10; minimalHit = 0.10;	radius = 0.12; material = -1; name = "hit_rudder";		armorComponent = "hit_rudder";visual = "-";		depends = "0";							};
	class HitLAileron 		{armor = -30;	explosionShielding = 0.50; passThrough = 0.10; minimalHit = 0.10;	radius = 0.13; material = -1; name = "hit_wing_l";		armorComponent = "hit_wing_l";visual = "-";		depends = "0";  					};
	class HitRAileron 		{armor = -30;	explosionShielding = 0.50; passThrough = 0.10; minimalHit = 0.10;	radius = 0.13; material = -1; name = "hit_wing_r";		armorComponent = "hit_wing_r";visual = "-";		depends = "0"; 					};
};

uavCameraDriverPos = "gunnerview";
uavCameraDriverDir = "gunnerview_dir";
uavCameraGunnerPos = "gunnerview";
uavCameraGunnerDir = "gunnerview_dir";

memoryPointLDust = "DustLeft";
memoryPointRDust = "DustRight";
memoryPointDriverOptics = "gunnerview";

driveOnComponent[] = {"gear_1","gear_2"};

weapons[] = {};
magazines[] = {};

class Damage
{
	tex[] = {};
	mat[] =
	{
		"rhsafrf\addons\rhs_a2port_air\PCHELA1T\data\pchela1t.rvmat",
		"rhsafrf\addons\rhs_a2port_air\PCHELA1T\data\pchela1t_damage.rvmat",
		"rhsafrf\addons\rhs_a2port_air\PCHELA1T\data\pchela1t_destruct.rvmat"
	};
};
class textureSources
{
	class standard
	{
		displayName="Grey";
		author="$STR_RHS_AUTHOR_FULL";
		textures[]=
		{
			"\rhsafrf\addons\rhs_a2port_air\PCHELA1T\data\pchela1tblu_co.paa"
		};
		factions[]=// This source should be available only for these factions
		{
			rhs_faction_vvs_c, rhs_faction_vvs
		};
	};
	class Camo: standard
	{
		displayName="Camo";
		author="$STR_RHS_AUTHOR_FULL";
		textures[]=
		{
			"\rhsafrf\addons\rhs_a2port_air\PCHELA1T\data\pchela1t_co.paa"
		};
	};
};
textureList[]=
{
};
class Attributes {
	class ObjectTexture {
		control = "ObjectTexture";
		data = "ObjectTexture";
		displayName = "Skin";
		tooltip = "Texture and material set applied on the object.";
	};
	class rhs_decalNumber_type {
		displayName = "Define font type of side number";
		tooltip = "Define kind of font that will be drawn on vehicle";
		property = "rhs_decalNumber_type";
		control = "Combo";
		expression = "_this setVariable ['%s', _value];[_this,[['Number', cRHSAIRPchelaNumberPlaces, _value]]] call rhs_fnc_decalsInit";
		defaultValue = 0;
		typeName = "STRING";
		class values {

			class AviaRed {
				name = "Aviation Red";
				value = "AviaRed";
			};
			class AviaBlue {
				name = "Aviation Blue";
				value = "AviaBlue";
				defaultValue = "AviaBlue";
			};
			class AviaWhiteOut {
				name = "Aviation White Out";
				value = "AviaWhiteOut";
			};
			class AviaYellow {
				name = "Aviation Yellow";
				value = "AviaYellow";
			};
			class AviaCDF {
				name = "Aviation CDF";
				value = "AviaCDF";
			};
			class Default {
				name = "Default";
				value = "Default";
			};
			class DefaultRed {
				name = "Default (Red)";
				value = "DefaultRed";
			};
			class BoldRed {
				name = "Bold Red";
				value = "BoldRed";
			};
			class CDF {
				name = "CDF";
				value = "CDF";
			};
			class Handpaint {
				name = "Handpaint";
				value = "Handpaint";
			};
			class HandpaintBlack {
				name = "Handpaint Black";
				value = "HandpaintBlack";
			};
			class Iraqi {
				name = "Iraqi";
				value = "Iraqi";
			};
		};
	};
	class rhs_decalNumber {
		displayName = "Set side number";
		tooltip = "Set side number. 2 numbers are required. Type 0 to hide numbers completly";
		property = "rhs_decalNumber";
		control = "Edit";
		validate = "Number";
		typeName = "Number";
		defaultValue = "-1";
		expression = "if( _value >= 0)then{if( _value == 0)then{{[_this setobjectTexture [_x,'a3\data_f\clear_empty.paa']]}foreach cRHSAIRPchelaNumberPlaces}else{[_this, [['Number', cRHSAIRPchelaNumberPlaces, _this getVariable ['rhs_decalNumber_type','AviaYellow'], _value] ] ] call rhs_fnc_decalsInit}};";
	};
};
transportSoldier = 0;
maxSpeed = 225;
fuelCapacity = 1500;
//aileronSensitivity = 0.6;
//landingAoa = "rad 5";
//envelope[] = {0,0,0.3,1,2.5,3.3,3.5,3.2,2.5,2,1.5,1};
thrustCoef[] = {1.48,1.45,1.4,1.35,1.3,1.24,0.9,0.5,0.3,0.1,0,0,0,0,0,0};
envelope[] = {0,0.07,0.26,0.59,1.04,1.63,1.98,2.7,3.2,4.05,4.68,5.49,6.19,7.04,7.53,7.9,7.4,7.2,6.5,6.2,6};
angleOfIndicence = -0.25*3.1415/180;		/// angle of incidence - difference between forward and airfold chord line - def. val is 3*PI/180 (meaning three degrees), be carefull with this value, will affect how much the nose of aircraft drops down during a level flight

landingSpeed = 73;
flaps = 0;
airBrake = 0;
cabinOpening = 0;
gearRetracting = 0;
stallSpeed = 200;
threat[] = {0.3,0.3,0.1};
audible = 8;

hiddenSelections[] = {"Camo","n1","n2","n3"};
hiddenSelectionsTextures[] = {"\rhsafrf\addons\rhs_a2port_air\PCHELA1T\data\pchela1t_co.paa"};

class EventHandlers : EventHandlers
{
	class RHS_EventHandlers
	{
		init = "_this call rhs_fnc_air_init";
		postInit = "_this call rhs_fnc_reapplyTextures";
		//hitpart = "_this call rhs_fnc_hitPart";
	};
};