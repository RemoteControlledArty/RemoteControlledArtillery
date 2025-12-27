defaultUserMFDvalues[]={0,1,0.30000001,1};

class MFD
{
	class AirplaneHUD
	{
		topLeft="HUD_top_left";
		topRight="HUD_top_right";
		bottomLeft="HUD_bottom_left";
		borderLeft=0;
		borderRight=0;
		borderTop=0;
		borderBottom=0;
		color[]={1,1,1,1};
		helmetMountedDisplay=1;
		helmetPosition[]={-0.025,0.025,0.1};
		helmetRight[]={0.050000001,0,0};
		helmetDown[]={0,-0.050000001,0};
		class Bones
		{
			class PlaneW
			{
				type="fixed";
				pos[]={0.5,0.57200003};
			};
			class WeaponAim
			{
				type="vector";
				source="weapon";
				pos0[]={0.5,0.5};
				pos10[]={0.847,0.84500003};
			};
			class ForwardVector
			{
				type="vector";
				source="forward";
				pos0[]={0,0};
				pos10[]={0.347,0.345};
			};
			class VelocityVector
			{
				type="vector";
				source="velocityToView";
				pos0[]={0.5,0.5};
				pos10[]={0.847,0.84500003};
			};
			class HorizonVector
			{
				type="horizon";
				pos0[]={0.5,0.57200003};
				pos10[]={0.99072701,1.0599};
				angle=0;
			};
			class VerticalSpeedBone
			{
				type="linear";
				source="vspeed";
				sourceScale=1;
				min=-15;
				max=15;
				minPos[]={0,-0.090000004};
				maxPos[]={0,0.090000004};
			};
		};
		class Draw
		{
			alpha="user3";
			color[]=
			{
				"user0",
				"user1",
				"user2"
			};
			condition="on";
			class Static
			{
				type="line";
				width=4;
				points[]=
				{
					
					{
						{0.5,0.115},
						1
					},
					
					{
						{0.5,0.13500001},
						1
					},
					{},
					
					{
						{0.81,0.5},
						1
					},
					
					{
						{0.82999998,0.5},
						1
					}
				};
			};
			class VelocityLine
			{
				type="line";
				width=4;
				points[]=
				{
					
					{
						"PlaneW",
						1
					},
					
					{
						"VelocityVector",
						1
					}
				};
			};
			class CollectiveGroup
			{
				condition="simulRTD";
				class CollectiveText
				{
					type="text";
					source="static";
					text="%";
					align="right";
					scale=1;
					pos[]=
					{
						{0.2,0.2},
						1
					};
					right[]=
					{
						{0.25999999,0.2},
						1
					};
					down[]=
					{
						{0.2,0.25},
						1
					};
				};
				class CollectiveNumber
				{
					type="text";
					source="rtdCollective";
					sourceScale=100;
					align="left";
					scale=1;
					pos[]=
					{
						{0.2,0.2},
						1
					};
					right[]=
					{
						{0.25999999,0.2},
						1
					};
					down[]=
					{
						{0.2,0.25},
						1
					};
				};
			};
			class SpeedNumber
			{
				type="text";
				source="speed";
				sourceScale=3.5999999;
				align="right";
				scale=1;
				pos[]=
				{
					{0.2,0.47499999},
					1
				};
				right[]=
				{
					{0.25999999,0.47499999},
					1
				};
				down[]=
				{
					{0.2,0.52499998},
					1
				};
			};
			class AltNumber
			{
				type="text";
				source="altitudeAGL";
				sourceScale=1;
				align="left";
				scale=1;
				pos[]=
				{
					{0.80000001,0.47499999},
					1
				};
				right[]=
				{
					{0.86000001,0.47499999},
					1
				};
				down[]=
				{
					{0.80000001,0.52499998},
					1
				};
			};
			class Weapons
			{
				type="text";
				source="weapon";
				sourceScale=1;
				align="right";
				scale=1;
				pos[]=
				{
					{0,0.89999998},
					1
				};
				right[]=
				{
					{0.059999999,0.89999998},
					1
				};
				down[]=
				{
					{0,0.94999999},
					1
				};
			};
			class Ammo
			{
				type="text";
				source="ammo";
				sourceScale=1;
				align="center";
				scale=1;
				pos[]=
				{
					{0.5,0.64999998},
					1
				};
				right[]=
				{
					{0.56,0.64999998},
					1
				};
				down[]=
				{
					{0.5,0.69999999},
					1
				};
			};
			class AltScale
			{
				type="scale";
				horizontal=0;
				source="altitudeAGL";
				sourceScale=1;
				min=0;
				width=4;
				top=0.69999999;
				center=0.5;
				bottom=0.25;
				lineXleft=0.83499998;
				lineYright=0.84500003;
				lineXleftMajor=0.83499998;
				lineYrightMajor=0.85500002;
				majorLineEach=5;
				numberEach=5;
				step=20;
				stepSize=0.029999999;
				align="right";
				scale=1;
				pos[]={0.87,0.67500001};
				right[]={0.93000001,0.67500001};
				down[]={0.87,0.72500002};
			};
			class VerticalSpeedScale
			{
				type="line";
				width=4;
				points[]=
				{
					
					{
						"VerticalSpeedBone",
						{0.86000001,0.83999997},
						1
					},
					
					{
						"VerticalSpeedBone",
						{0.87,0.85000002},
						1
					},
					
					{
						"VerticalSpeedBone",
						{0.86000001,0.86000001},
						1
					},
					{},
					
					{
						{0.88499999,0.75999999},
						1
					},
					
					{
						{0.89499998,0.75999999},
						1
					},
					{},
					
					{
						{0.88499999,0.79000002},
						1
					},
					
					{
						{0.89499998,0.79000002},
						1
					},
					{},
					
					{
						{0.88499999,0.81999999},
						1
					},
					
					{
						{0.89499998,0.81999999},
						1
					},
					{},
					
					{
						{0.88499999,0.85000002},
						1
					},
					
					{
						{0.90499997,0.85000002},
						1
					},
					{},
					
					{
						{0.88499999,0.88},
						1
					},
					
					{
						{0.89499998,0.88},
						1
					},
					{},
					
					{
						{0.88499999,0.91000003},
						1
					},
					
					{
						{0.89499998,0.91000003},
						1
					},
					{},
					
					{
						{0.88499999,0.94},
						1
					},
					
					{
						{0.89499998,0.94},
						1
					}
				};
			};
			class VspeedNumberStaticP15
			{
				type="text";
				source="static";
				text=15;
				scale=1;
				sourceScale=1;
				align="right";
				pos[]=
				{
					{0.91000003,0.73000002},
					1
				};
				right[]=
				{
					{0.97000003,0.73000002},
					1
				};
				down[]=
				{
					{0.91000003,0.77999997},
					1
				};
			};
			class VspeedNumberStaticM15
			{
				type="text";
				source="static";
				text=-15;
				scale=1;
				sourceScale=1;
				align="right";
				pos[]=
				{
					{0.91000003,0.91000003},
					1
				};
				right[]=
				{
					{0.97000003,0.91000003},
					1
				};
				down[]=
				{
					{0.91000003,0.95999998},
					1
				};
			};
			class HeadingScale
			{
				type="scale";
				horizontal=1;
				source="heading";
				sourceScale=1;
				width=4;
				top=0.30000001;
				center=0.5;
				bottom=0.69999999;
				lineXleft=0.11;
				lineYright=0.1;
				lineXleftMajor=0.11;
				lineYrightMajor=0.090000004;
				majorLineEach=3;
				numberEach=3;
				step=10;
				stepSize=0.039999999;
				align="center";
				scale=1;
				pos[]={0.30000001,0.039999999};
				right[]={0.36000001,0.039999999};
				down[]={0.30000001,0.090000004};
			};
			class HorizontalLine
			{
				clipTL[]={0.2,0.12};
				clipBR[]={0.80000001,0.95999998};
				class HorizontalLineDraw
				{
					type="line";
					width=4;
					points[]=
					{
						
						{
							"HorizonVector",
							{-0.22499999,0},
							1
						},
						
						{
							"HorizonVector",
							{-0.1875,0},
							1
						},
						{},
						
						{
							"HorizonVector",
							{-0.15000001,0},
							1
						},
						
						{
							"HorizonVector",
							{-0.1125,0},
							1
						},
						{},
						
						{
							"HorizonVector",
							{-0.075000003,0},
							1
						},
						
						{
							"HorizonVector",
							{-0.037500001,0},
							1
						},
						{},
						
						{
							"HorizonVector",
							{0.037500001,0},
							1
						},
						
						{
							"HorizonVector",
							{0.075000003,0},
							1
						},
						{},
						
						{
							"HorizonVector",
							{0.1125,0},
							1
						},
						
						{
							"HorizonVector",
							{0.15000001,0},
							1
						},
						{},
						
						{
							"HorizonVector",
							{0.1875,0},
							1
						},
						
						{
							"HorizonVector",
							{0.22499999,0},
							1
						}
					};
				};
			};
			class MGun
			{
				condition="on";
				class Circle
				{
					type="line";
					width=4;
					points[]=
					{
						
						{
							"ForwardVector",
							1,
							"WeaponAim",
							{0.050000001,0},
							1
						},
						
						{
							"ForwardVector",
							1,
							"WeaponAim",
							{0.025,0},
							1
						},
						{},
						
						{
							"ForwardVector",
							1,
							"WeaponAim",
							{0,0.049711801},
							1
						},
						
						{
							"ForwardVector",
							1,
							"WeaponAim",
							{0,0.024855901},
							1
						},
						{},
						
						{
							"ForwardVector",
							1,
							"WeaponAim",
							{-0.050000001,0},
							1
						},
						
						{
							"ForwardVector",
							1,
							"WeaponAim",
							{-0.025,0},
							1
						},
						{},
						
						{
							"ForwardVector",
							1,
							"WeaponAim",
							{0,-0.049711801},
							1
						},
						
						{
							"ForwardVector",
							1,
							"WeaponAim",
							{0,-0.024855901},
							1
						}
					};
				};
			};
			class Rockets
			{
				condition="missile";
				class Circle
				{
					type="line";
					width=4;
					points[]=
					{
						
						{
							"ForwardVector",
							1,
							"WeaponAim",
							{-0.25,-0.25},
							1
						},
						
						{
							"ForwardVector",
							1,
							"WeaponAim",
							{-0.25,-0.2},
							1
						},
						{},
						
						{
							"ForwardVector",
							1,
							"WeaponAim",
							{-0.25,0.25},
							1
						},
						
						{
							"ForwardVector",
							1,
							"WeaponAim",
							{-0.25,0.2},
							1
						},
						{},
						
						{
							"ForwardVector",
							1,
							"WeaponAim",
							{0.25,-0.25},
							1
						},
						
						{
							"ForwardVector",
							1,
							"WeaponAim",
							{0.25,-0.2},
							1
						},
						{},
						
						{
							"ForwardVector",
							1,
							"WeaponAim",
							{0.25,0.25},
							1
						},
						
						{
							"ForwardVector",
							1,
							"WeaponAim",
							{0.25,0.2},
							1
						},
						{},
						
						{
							"ForwardVector",
							1,
							"WeaponAim",
							{-0.25,-0.25},
							1
						},
						
						{
							"ForwardVector",
							1,
							"WeaponAim",
							{-0.2,-0.25},
							1
						},
						{},
						
						{
							"ForwardVector",
							1,
							"WeaponAim",
							{-0.25,0.25},
							1
						},
						
						{
							"ForwardVector",
							1,
							"WeaponAim",
							{-0.2,0.25},
							1
						},
						{},
						
						{
							"ForwardVector",
							1,
							"WeaponAim",
							{0.25,-0.25},
							1
						},
						
						{
							"ForwardVector",
							1,
							"WeaponAim",
							{0.2,-0.25},
							1
						},
						{},
						
						{
							"ForwardVector",
							1,
							"WeaponAim",
							{0.25,0.25},
							1
						},
						
						{
							"ForwardVector",
							1,
							"WeaponAim",
							{0.2,0.25},
							1
						},
						{},
						
						{
							"ForwardVector",
							1,
							"WeaponAim",
							{0.035,0.034798302},
							1
						},
						
						{
							"ForwardVector",
							1,
							"WeaponAim",
							{0.017999999,0.0178963},
							1
						},
						{},
						
						{
							"ForwardVector",
							1,
							"WeaponAim",
							{-0.035,0.034798302},
							1
						},
						
						{
							"ForwardVector",
							1,
							"WeaponAim",
							{-0.017999999,0.0178963},
							1
						},
						{},
						
						{
							"ForwardVector",
							1,
							"WeaponAim",
							{-0.035,-0.034798302},
							1
						},
						
						{
							"ForwardVector",
							1,
							"WeaponAim",
							{-0.017999999,-0.0178963},
							1
						},
						{},
						
						{
							"ForwardVector",
							1,
							"WeaponAim",
							{0.035,-0.034798302},
							1
						},
						
						{
							"ForwardVector",
							1,
							"WeaponAim",
							{0.017999999,-0.0178963},
							1
						}
					};
				};
			};
		};
	};
	class MFD_Pilot_10
	{
		topLeft="MFD_1_TL";
		topRight="MFD_1_TR";
		bottomLeft="MFD_1_BL";
		borderLeft=0;
		borderRight=0;
		borderTop=0;
		borderBottom=0;
		color[]={1,1,1,1};
		helmetMountedDisplay=0;
		helmetPosition[]={-0.037500001,0.037500001,0.1};
		helmetRight[]={0.075000003,0,0};
		helmetDown[]={0,-0.075000003,0};
		font="LucidaConsoleB";
		turret[]={0};
		class Bones
		{
		};
		class Draw
		{
			alpha=1;
			color[]={0.25,1,0.25};
			condition="on";
			class ReticleGroup
			{
				color[]={1,1,1};
				class Reticle
				{
					type="line";
					width=4;
					points[]=
					{
						
						{
							{0.491429,0.452766},
							1
						},
						
						{
							{0.495,0.452766},
							1
						},
						
						{
							{0.495,0.457802},
							1
						},
						
						{
							{0.491429,0.457802},
							1
						},
						
						{
							{0.491429,0.452766},
							1
						},
						{},
						
						{
							{0.499286,0.45578799},
							1
						},
						
						{
							{0.57714301,0.45578799},
							1
						},
						{},
						
						{
							{0.49285701,0.46283901},
							1
						},
						
						{
							{0.49285701,0.55752701},
							1
						},
						{},
						
						{
							{0.48857099,0.45578799},
							1
						},
						
						{
							{0.41,0.45578799},
							1
						},
						{},
						
						{
							{0.49285701,0.35404801},
							1
						},
						
						{
							{0.49285701,0.446722},
							1
						},
						{},
						
						{
							{0.61000001,0.29965201},
							1
						},
						
						{
							{0.64285702,0.29965201},
							1
						},
						
						{
							{0.64285702,0.342967},
							1
						},
						{},
						
						{
							{0.64285702,0.57565898},
							1
						},
						
						{
							{0.64285702,0.619982},
							1
						},
						
						{
							{0.61071402,0.619982},
							1
						},
						{},
						
						{
							{0.374286,0.619982},
							1
						},
						
						{
							{0.341429,0.619982},
							1
						},
						
						{
							{0.341429,0.57565898},
							1
						},
						{},
						
						{
							{0.374286,0.29965201},
							1
						},
						
						{
							{0.341429,0.29965201},
							1
						},
						
						{
							{0.341429,0.342967},
							1
						}
					};
				};
				class ModeText
				{
					type="text";
					source="static";
					text="Mode: TI WHOT";
					scale=1;
					sourceScale=1;
					align="right";
					pos[]=
					{
						{0.039999999,0.31999999},
						1
					};
					right[]=
					{
						{0.07,0.31999999},
						1
					};
					down[]=
					{
						{0.039999999,0.345},
						1
					};
				};
				class RangeText
				{
					type="text";
					source="static";
					text="Range:";
					scale=1;
					sourceScale=1;
					align="right";
					pos[]=
					{
						{0.36000001,0.81},
						1
					};
					right[]=
					{
						{0.40000001,0.81},
						1
					};
					down[]=
					{
						{0.36000001,0.84500003},
						1
					};
				};
				class Fuel
				{
					type="text";
					source="laserDist";
					sourceScale=1;
					sourceLength=4;
					align="right";
					scale=1;
					pos[]=
					{
						{0.50999999,0.81},
						1
					};
					right[]=
					{
						{0.55000001,0.81},
						1
					};
					down[]=
					{
						{0.50999999,0.84500003},
						1
					};
				};
			};
		};
	};
};