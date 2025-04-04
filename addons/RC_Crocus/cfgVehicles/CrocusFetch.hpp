class RscText;
class ctrlControlsGroupNoScrollBars;
class ctrlControlsGroup;
class ctrlStaticBackground;
class ctrlStaticPicture;
class ctrlStructuredText;
class RscTitles
{
	class ArmaFPV_Dialog
	{
		idd=-1;
		duration=9.9999997e+037;
		movingEnable="false";
		enableSimulation="true";
		class controls
		{
			class LeftLine: RscText
			{
				idc=-1;
				x="safeZoneXAbs";
				y="safeZoneY";
				w="(safeZoneW * 0.15)";
				h="(safeZoneH)";
				colorBackground[]={0,0,0,1};
			};
			class RightLine: LeftLine
			{
				x="safeZoneXAbs + safeZoneWAbs - (safeZoneW * 0.15)";
			};
			class CommunicationGroup: ctrlControlsGroupNoScrollBars
			{
				idc=-1;
				x="(safeZoneXAbs + (safeZoneW * 0.15)) + (safeZoneWAbs - 2*(safeZoneW * 0.15)) - ( 6 * ( pixelGridNoUIScale * pixelW * 2 )) - ( 2 * ( pixelGridNoUIScale * pixelW * 2 ))";
				y="(safeZoneY) + ( 6 * ( pixelGridNoUIScale * pixelH * 2 ))";
				w="( 6 * ( pixelGridNoUIScale * pixelW * 2 ))";
				h="( 2 * ( pixelGridNoUIScale * pixelH * 2 ))";
				class controls
				{
					class CommunicationPicture: ctrlStaticPicture
					{
						idc=-1;
						text="\ArmaFPV\pictures\100.paa";
						onLoad="uiNameSpace setVariable [""ArmaFPV_SignalPicture"", _this # 0];";
						x=0;
						y="0.0 + ( 2 * ( pixelGridNoUIScale * pixelH * 2 )) / 2 - ( 1 * ( pixelGridNoUIScale * pixelH * 2 )) / 2";
						w="( 3 * ( pixelGridNoUIScale * pixelW * 2 )) / 2";
						h="( 1 * ( pixelGridNoUIScale * pixelH * 2 ))";
					};
					class CommunicationText: ctrlStructuredText
					{
						idc=-1;
						onLoad="uiNameSpace setVariable [""ArmaFPV_SignalText"", _this # 0];";
						class Attributes
						{
							font="VCROSDMono";
							align="center";
							shadow=1;
						};
						shadow=0;
						size="( 1.8 * ( pixelGridNoUIScale * pixelH * 2 ))";
						text="27";
						x=0;
						y=0;
						w="( 6 * ( pixelGridNoUIScale * pixelW * 2 ))";
						h="( 2 * ( pixelGridNoUIScale * pixelH * 2 ))";
					};
				};
			};
			class BatteryGroup: ctrlControlsGroupNoScrollBars
			{
				idc=-1;
				x="(safeZoneXAbs + (safeZoneW * 0.15)) + ( 2 * ( pixelGridNoUIScale * pixelW * 2 ))";
				y="(safeZoneY) + (safeZoneH) - ( 2 * ( pixelGridNoUIScale * pixelH * 2 )) - ( 8 * ( pixelGridNoUIScale * pixelH * 2 ))";
				w="( 8 * ( pixelGridNoUIScale * pixelW * 2 ))";
				h="( 2 * ( pixelGridNoUIScale * pixelH * 2 ))";
				class controls
				{
					class BatteryPicture: ctrlStaticPicture
					{
						idc=-1;
						onLoad="uiNameSpace setVariable [""ArmaFPV_BatteryPicture"", _this # 0];";
						text="\ArmaFPV\pictures\A100.paa";
						x=0;
						y=0;
						w="( 1 * ( pixelGridNoUIScale * pixelW * 2 ))";
						h="( 1.8 * ( pixelGridNoUIScale * pixelH * 2 ))";
					};
					class BatteryText: ctrlStructuredText
					{
						idc=-1;
						onLoad="uiNameSpace setVariable [""ArmaFPV_BatteryText"", _this # 0];";
						class Attributes
						{
							font="VCROSDMono";
							align="center";
							shadow=1;
						};
						shadow=0;
						size="( 1.3 * ( pixelGridNoUIScale * pixelH * 2 ))";
						text="3.79 v";
						x=0;
						y="( 0.3 * ( pixelGridNoUIScale * pixelH * 2 ))";
						w="( 8 * ( pixelGridNoUIScale * pixelW * 2 ))";
						h="( 2 * ( pixelGridNoUIScale * pixelH * 2 ))";
					};
				};
			};
			class OnTime_Group: ctrlControlsGroupNoScrollBars
			{
				idc=-1;
				x="(safeZoneXAbs + (safeZoneW * 0.15)) + (safeZoneWAbs - 2*(safeZoneW * 0.15)) - ( 6 * ( pixelGridNoUIScale * pixelW * 2 )) - ( 2 * ( pixelGridNoUIScale * pixelW * 2 ))";
				y="(safeZoneY) + (safeZoneH) - ( 2 * ( pixelGridNoUIScale * pixelH * 2 )) - ( 8 * ( pixelGridNoUIScale * pixelH * 2 ))";
				w="( 10 * ( pixelGridNoUIScale * pixelW * 2 ))";
				h="( 2.5 * ( pixelGridNoUIScale * pixelH * 2 ))";
				class controls
				{
					class OnTime_Picture: ctrlStaticPicture
					{
						idc=-1;
						text="\ArmaFPV\pictures\mn.paa";
						x=0;
						y=0;
						w="( 6 * ( pixelGridNoUIScale * pixelW * 2 )) / 2";
						h="( 2 * ( pixelGridNoUIScale * pixelH * 2 ))";
					};
					class OnTime_Text: ctrlStructuredText
					{
						idc=-1;
						onLoad="uiNameSpace setVariable [""ArmaFPV_OnTimeText"", _this # 0];";
						class Attributes
						{
							font="VCROSDMono";
							align="right";
							shadow=1;
						};
						shadow=0;
						size="( 1.4 * ( pixelGridNoUIScale * pixelH * 2 ))";
						text="03:38";
						x=0;
						y="( 0.3 * ( pixelGridNoUIScale * pixelH * 2 ))";
						w="( 6.5 * ( pixelGridNoUIScale * pixelW * 2 ))";
						h="( 2 * ( pixelGridNoUIScale * pixelH * 2 ))";
					};
				};
			};
			class Center_target: ctrlStaticPicture
			{
				idc=-1;
				text="\ArmaFPV\pictures\PRICEL.paa";
				x="0.5 - ( 2 * ( pixelGridNoUIScale * pixelW * 2 )) / 2";
				y="0.5 - ( 2 * ( pixelGridNoUIScale * pixelH * 2 )) / 2 + ( 1.25 * ( pixelGridNoUIScale * pixelH * 2 ))";
				w="( 2 * ( pixelGridNoUIScale * pixelW * 2 ))";
				h="( 2 * ( pixelGridNoUIScale * pixelH * 2 ))";
			};
			class V_Line_Left: ctrlStaticPicture
			{
				idc=-1;
				text="\ArmaFPV\pictures\horiz.paa";
				x="0.5 + ( 10 * ( pixelGridNoUIScale * pixelW * 2 ))";
				y="0.5 - ( 12 * ( pixelGridNoUIScale * pixelH * 2 )) / 2";
				w="( 1 * ( pixelGridNoUIScale * pixelW * 2 ))";
				h="( 12 * ( pixelGridNoUIScale * pixelH * 2 ))";
			};
			class V_Line_Right: V_Line_Left
			{
				x="0.5 - ( 10 * ( pixelGridNoUIScale * pixelW * 2 ))";
			};
			class MainText: ctrlStructuredText
			{
				idc=-1;
				class Attributes
				{
					font="VCROSDMono";
					align="center";
					shadow=1;
				};
				shadow=0;
				size="( 1.4 * ( pixelGridNoUIScale * pixelH * 2 ))";
				onLoad="uiNameSpace setVariable [""ArmaFPV_MainText"", _this # 0];";
				text="";
				x="(safeZoneXAbs + (safeZoneW * 0.15)) + (safeZoneWAbs - 2*(safeZoneW * 0.15)) / 2 - ( 20 * ( pixelGridNoUIScale * pixelW * 2 )) / 2";
				y="0.5 - ( 12 * ( pixelGridNoUIScale * pixelH * 2 )) / 2 - ( 1.6 * ( pixelGridNoUIScale * pixelH * 2 ))";
				w="( 20 * ( pixelGridNoUIScale * pixelW * 2 ))";
				h="( 1.6 * ( pixelGridNoUIScale * pixelH * 2 ))";
			};
		};
	};
};
class CfgAmmo
{
	class M_Vorona_HEAT;
	class FPV_RPG42_AT: M_Vorona_HEAT
	{
		explosive=0.80000001;
		hit=150;
		htMax=1800;
		htMin=60;
		indirectHit=42;		//MP 42, AT 25, AP 60
		indirectHitRange=7;		//MP 5, AT 3.5, AP 6
		submunitionInitSpeed=1000;
		warheadName="TandemHEAT";
		submunitionAmmo="FPV_RPG42_AT_Penetrator";
		submunitionDirectionType="SubmunitionModelDirection";
		submunitionParentSpeedCoef=0;
		submunitionInitialOffset[]={0,0,-0.1};
		triggerOnImpact=1;
		deleteParentWhenTriggered=0;
	};
	class FPV_RPG42_AT_AB: FPV_RPG42_AT
	{
		laserLock=1;
		irLock=1;
		airLock=1;
		nvLock=1;
		//triggerOnImpact=0;
		thrustTime=0;
		thrust=0;
		fuseDistance=0;

		//explosionTime=0.0001;
		//timeToLive=0.0001;
		timeToLive=3;

		model="\A3\weapons_f\launchers\RPG32\tbg32v_rocket.p3d";
		effectsMissileInit="";
		explosionEffects="";
		muzzleEffect="";
		explosionSoundEffect="";
		CraterEffects="";

		soundHit1[]=
		{
			"A3\Sounds_F\arsenal\sfx\bullet_hits\plastic_01",
			1,
			1,
			1
		};
		soundHit2[]=
		{
			"A3\Sounds_F\arsenal\sfx\bullet_hits\plastic_01",
			2.5118864,
			1,
			1
		};
		soundHit3[]=
		{
			"A3\Sounds_F\arsenal\sfx\bullet_hits\plastic_01",
			2.5118864,
			1,
			1
		};
	};
	class ammo_Penetrator_Vorona;
	class FPV_RPG42_AT_Penetrator: ammo_Penetrator_Vorona
	{
		hit=480;
		indirectHit=0;
		indirectHitRange=0;
		warheadName="TandemHEAT";
	};
};
class CfgMagazines
{
	class RC_target_confirmer_mag;
	class RC_target_confirmer_AB_mag: RC_target_confirmer_mag
	{
		scope=2;
		ammo="FPV_RPG42_AT_AB";
		count=1;
		initSpeed=0;

		//displayName="MP warhead";
		//displayNameShort="MP warhead";
	};
};
class CfgWeapons
{
	class RC_target_confirmer;
	class RC_target_confirmer_AB: RC_target_confirmer
	{
		scope=2;
		displayName="airburst";
		displayNameShort="airburst";
		magazines[]=
		{
			"RC_target_confirmer_AB_mag"
		};
		canLock=2;

		class Single
		{
			displayName="airburst";
			reloadTime=1;
			burst=1;
			sounds[]=
			{
				"StandardSound"
			};
			class StandardSound
			{
				begin1[]=
				{
					"A3\Sounds_F_Orange\Vehicles\Air\UAV_06\UAV_6_DemineDrone_Bomb_Release_01",
					3.9810717,
					1,
					20
				};
				soundBegin[]=
				{
					"begin1",
					1
				};
			};
			showToPlayer=1;

			textureType="semi";
			recoil="recoil_single_primary_3outof10";
			recoilProne="recoil_single_primary_prone_3outof10";
			aiDispersionCoefY=1.7;
			aiDispersionCoefX=1.4;
			soundBurst=0;
			requiredOpticType=-1;
			aiRateOfFire=2;
			aiRateOfFireDispersion=1;
			aiRateOfFireDistance=500;
		};
	};
};
class CfgFontFamilies
{
	class VCROSDMono
	{
		fonts[]=
		{
			"\ArmaFPV\font\VCROSDMono6",
			"\ArmaFPV\font\VCROSDMono7",
			"\ArmaFPV\font\VCROSDMono8",
			"\ArmaFPV\font\VCROSDMono9",
			"\ArmaFPV\font\VCROSDMono10",
			"\ArmaFPV\font\VCROSDMono11",
			"\ArmaFPV\font\VCROSDMono12",
			"\ArmaFPV\font\VCROSDMono13",
			"\ArmaFPV\font\VCROSDMono14",
			"\ArmaFPV\font\VCROSDMono15",
			"\ArmaFPV\font\VCROSDMono16",
			"\ArmaFPV\font\VCROSDMono17",
			"\ArmaFPV\font\VCROSDMono18",
			"\ArmaFPV\font\VCROSDMono19",
			"\ArmaFPV\font\VCROSDMono20",
			"\ArmaFPV\font\VCROSDMono21",
			"\ArmaFPV\font\VCROSDMono22",
			"\ArmaFPV\font\VCROSDMono23",
			"\ArmaFPV\font\VCROSDMono24",
			"\ArmaFPV\font\VCROSDMono25",
			"\ArmaFPV\font\VCROSDMono26",
			"\ArmaFPV\font\VCROSDMono27",
			"\ArmaFPV\font\VCROSDMono28",
			"\ArmaFPV\font\VCROSDMono29",
			"\ArmaFPV\font\VCROSDMono30",
			"\ArmaFPV\font\VCROSDMono31",
			"\ArmaFPV\font\VCROSDMono34",
			"\ArmaFPV\font\VCROSDMono35",
			"\ArmaFPV\font\VCROSDMono37",
			"\ArmaFPV\font\VCROSDMono46"
		};
	};
};
class CfgFunctions
{
	class DB
	{
		class FPV
		{
			file="\ArmaFPV\functions";
			class fpv_createDialog
			{
			};
			class fpv_getSignal
			{
			};
			class fpv_handleBattery
			{
			};
			class fpv_handleConnect
			{
				postInit=1;
			};
			class fpv_handleSignal
			{
			};
			class fpv_handleSettings
			{
			};
			class fpv_handleTime
			{
			};
			class fpv_onDestroy
			{
			};
			class fpv_onSignalLost
			{
			};
			class fpv_destroyUI
			{
			};
			class fpv_droneInit
			{
			};
		};
	};
};
class SensorTemplatePassiveRadar;
class SensorTemplateAntiRadiation;
class SensorTemplateActiveRadar;
class SensorTemplateIR;
class SensorTemplateVisual;
class SensorTemplateMan;
class SensorTemplateLaser;
class SensorTemplateNV;
class SensorTemplateDataLink;
class DefaultVehicleSystemsDisplayManagerLeft
{
	class components;
};
class DefaultVehicleSystemsDisplayManagerRight
{
	class components;
};