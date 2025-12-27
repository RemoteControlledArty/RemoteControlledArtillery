defaultUserMFDvalues[]={0.25,1,0.25,1};
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
		color[]={0.15000001,1,0.15000001,1};
		helmetMountedDisplay=1;
		helmetPosition[]={-0.037500001,0.037500001,0.1};
		helmetRight[]={0.075000003,0,0};
		helmetDown[]={0,-0.075000003,0};
		font="LucidaConsoleB";
		turret[]={-2};
		class Bones
		{
			class HUDCenter
			{
				type="fixed";
				pos[]={0.5,0.5};
			};
			class HorizonBankSource
			{
				type="rotational";
				source="HorizonBank";
				center[]={0.5,0.5};
				min=-6.2831001;
				max=6.2831001;
				minAngle=-360;
				maxAngle=360;
			};
			class HorizonDiveSource
			{
				source="horizonDive";
				type="linear";
				min=-1;
				max=1;
				minPos[]={0.5,2.5};
				maxPos[]={0.5,-1.5};
			};
			class VelocityVector
			{
				type="vector";
				source="velocityToView";
				pos0[]={0.5,0.5};
				pos10[]={0.73400003,0.73000002};
			};
			class ForwardVector
			{
				type="vector";
				source="forward";
				pos0[]={0,0};
				pos10[]={0.234,0.23};
			};
			class GunnerAim
			{
				type="vector";
				source="turret";
				pos0[]={0,-0.60000002};
				pos10[]={0.0068000001,-0.012};
				projection=0;
			};
			class WeaponAim
			{
				type="vector";
				source="weaponToView";
				pos0[]={0.5,0.5};
				pos10[]={0.73400003,0.73000002};
			};
			class SliderDiveSource
			{
				type="linear";
				source="horizonDive";
				min="RAD(-10)";
				max="RAD(10)";
				minPos[]={0.105,0.38};
				maxPos[]={0.105,0.54000002};
			};
			class SliderDiveSource30: SliderDiveSource
			{
				min="RAD(10)";
				max="RAD(30)";
				minPos[]={0,-0.039999999};
				maxPos[]=
				{
					0,
					"0)"
				};
			};
			class SliderDiveSource90: SliderDiveSource30
			{
				min="RAD(30)";
				max="RAD(90)";
				minPos[]={0,-0.039999999};
			};
			class SliderDiveSource30m: SliderDiveSource
			{
				min="RAD(-30)";
				max="RAD(-10)";
				minPos[]={0,0};
				maxPos[]={0,0.039999999};
			};
			class SliderDiveSource90m: SliderDiveSource30m
			{
				min="RAD(-90)";
				max="RAD(-30)";
				maxPos[]={0,0.039999999};
			};
			class SliderAltitudeSource
			{
				type="linear";
				source="altitudeAGL";
				sourceOffset=-3;
				min=0;
				max=1000;
				minPos[]={0.88499999,0.2};
				maxPos[]={0.88499999,0.375};
			};
			class GForceSource
			{
				type="linear";
				source="gmeter";
				sourceScale=0.15000001;
				min=-1;
				max=3;
				minPos[]={0.105,0.69999999};
				maxPos[]={0.105,0.86000001};
			};
			class SliderVSpeedSource
			{
				type="linear";
				source="vspeed";
				min=-15;
				max=15;
				minPos[]={0.79500002,0.60000002};
				maxPos[]={0.79500002,0.83999997};
			};
			class ImpactPoint
			{
				type="vector";
				source="ImpactPointToView";
				pos0[]={0.5,0.5};
				pos10[]={0.73400003,0.73000002};
			};
			class ImpactPointRockets
			{
				type="vector";
				source="ImpactPointToView";
				pos0[]={0.5,0.52499998};
				pos10[]={0.73400003,0.755};
			};
			class WPPoint
			{
				type="vector";
				source="WPPointToView";
				pos0[]={0.5,0.5};
				pos10[]={0.73400003,0.73000002};
			};
			class rtdRPM1
			{
				type="linear";
				source="rtdrpm1";
				min=0.1;
				max=1;
				minPos[]={0,-0.75999999};
				maxPos[]={0,0};
			};
			class rtdRPM2: rtdRPM1
			{
				source="rtdrpm2";
			};
			class Limit0109
			{
				type="limit";
				limits[]={0.1,0.1,0.89999998,0.89999998};
			};
			class Target
			{
				source="targettoview";
				type="vector";
				pos0[]={0.5,0.5};
				pos10[]={0.73400003,0.73000002};
			};
			class MissileFlightTimeRot1
			{
				type="rotational";
				source="MissileFlightTime";
				sourceScale=0.46000001;
				center[]={0,0};
				min=0;
				max=0.5;
				minAngle=0;
				maxAngle=18;
				aspectRatio=0.98290598;
			};
			class MissileFlightTimeRot2: MissileFlightTimeRot1
			{
				maxAngle=36;
				max=1;
			};
			class MissileFlightTimeRot3: MissileFlightTimeRot1
			{
				maxAngle=54;
				max=1.5;
			};
			class MissileFlightTimeRot4: MissileFlightTimeRot1
			{
				maxAngle=72;
				max=2;
			};
			class MissileFlightTimeRot5: MissileFlightTimeRot1
			{
				maxAngle=90;
				max=2.5;
			};
			class MissileFlightTimeRot6: MissileFlightTimeRot1
			{
				maxAngle=108;
				max=3;
			};
			class MissileFlightTimeRot7: MissileFlightTimeRot1
			{
				maxAngle=126;
				max=3.5;
			};
			class MissileFlightTimeRot8: MissileFlightTimeRot1
			{
				maxAngle=144;
				max=4;
			};
			class MissileFlightTimeRot9: MissileFlightTimeRot1
			{
				maxAngle=162;
				max=4.5;
			};
			class MissileFlightTimeRot10: MissileFlightTimeRot1
			{
				maxAngle=180;
				max=5;
			};
			class MissileFlightTimeRot11: MissileFlightTimeRot1
			{
				maxAngle=198;
				max=5.5;
			};
			class MissileFlightTimeRot12: MissileFlightTimeRot1
			{
				maxAngle=216;
				max=6;
			};
			class MissileFlightTimeRot13: MissileFlightTimeRot1
			{
				maxAngle=234;
				max=6.5;
			};
			class MissileFlightTimeRot14: MissileFlightTimeRot1
			{
				maxAngle=252;
				max=7;
			};
			class MissileFlightTimeRot15: MissileFlightTimeRot1
			{
				maxAngle=270;
				max=7.5;
			};
			class MissileFlightTimeRot16: MissileFlightTimeRot1
			{
				maxAngle=288;
				max=8;
			};
			class MissileFlightTimeRot17: MissileFlightTimeRot1
			{
				maxAngle=306;
				max=8.5;
			};
			class MissileFlightTimeRot18: MissileFlightTimeRot1
			{
				maxAngle=324;
				max=9;
			};
			class MissileFlightTimeRot19: MissileFlightTimeRot1
			{
				maxAngle=342;
				max=9.5;
			};
			class MissileFlightTimeRot20: MissileFlightTimeRot1
			{
				maxAngle=360;
				max=10;
			};
			class HorizonBankRotFull
			{
				type="rotational";
				source="horizonBank";
				center[]={0,0};
				min=-3.1415999;
				max=3.1415999;
				minAngle=-180;
				maxAngle=180;
				aspectRatio=1;
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
			condition="(1 - (cameraHeadingDiffY<=-19) + (abs(cameraHeadingDiffX)>=24))*on";
			class VelocityLine
			{
				type="line";
				width=2;
				points[]=
				{
					
					{
						"HUDCenter",
						1
					},
					
					{
						"VelocityVector",
						1
					},
					{},
					
					{
						"VelocityVector",
						{0,-0.0049145301},
						1
					},
					
					{
						"VelocityVector",
						{0.0024999999,-0.0042559798},
						1
					},
					
					{
						"VelocityVector",
						{0.0043299999,-0.0024572599},
						1
					},
					
					{
						"VelocityVector",
						{0.0049999999,0},
						1
					},
					
					{
						"VelocityVector",
						{0.0043299999,0.0024572599},
						1
					},
					
					{
						"VelocityVector",
						{0.0024999999,0.0042559798},
						1
					},
					
					{
						"VelocityVector",
						{0,0.0049145301},
						1
					},
					
					{
						"VelocityVector",
						{-0.0024999999,0.0042559798},
						1
					},
					
					{
						"VelocityVector",
						{-0.0043299999,0.0024572599},
						1
					},
					
					{
						"VelocityVector",
						{-0.0049999999,0},
						1
					},
					
					{
						"VelocityVector",
						{-0.0043299999,-0.0024572599},
						1
					},
					
					{
						"VelocityVector",
						{-0.0024999999,-0.0042559798},
						1
					},
					
					{
						"VelocityVector",
						{0,-0.0049145301},
						1
					},
					{}
				};
			};
			class Static
			{
				type="line";
				width=3;
				points[]=
				{
					
					{
						"SliderDiveSource90",
						1,
						"SliderDiveSource30",
						1,
						"SliderDiveSource",
						1,
						"SliderDiveSource30m",
						1,
						"SliderDiveSource90m",
						1,
						{0.015,0.0099999998},
						1
					},
					
					{
						"SliderDiveSource90",
						1,
						"SliderDiveSource30",
						1,
						"SliderDiveSource",
						1,
						"SliderDiveSource30m",
						1,
						"SliderDiveSource90m",
						1,
						{0,0},
						1
					},
					
					{
						"SliderDiveSource90",
						1,
						"SliderDiveSource30",
						1,
						"SliderDiveSource",
						1,
						"SliderDiveSource30m",
						1,
						"SliderDiveSource90m",
						1,
						{0.015,-0.0099999998},
						1
					},
					
					{
						"SliderDiveSource90",
						1,
						"SliderDiveSource30",
						1,
						"SliderDiveSource",
						1,
						"SliderDiveSource30m",
						1,
						"SliderDiveSource90m",
						1,
						{0.015,0.0099999998},
						1
					},
					{},
					
					{
						"SliderDiveSource90",
						1,
						"SliderDiveSource30",
						1,
						"SliderDiveSource",
						1,
						"SliderDiveSource30m",
						1,
						"SliderDiveSource90m",
						1,
						{0.029999999,0.015},
						1
					},
					
					{
						"SliderDiveSource90",
						1,
						"SliderDiveSource30",
						1,
						"SliderDiveSource",
						1,
						"SliderDiveSource30m",
						1,
						"SliderDiveSource90m",
						1,
						{0.088,0.015},
						1
					},
					
					{
						"SliderDiveSource90",
						1,
						"SliderDiveSource30",
						1,
						"SliderDiveSource",
						1,
						"SliderDiveSource30m",
						1,
						"SliderDiveSource90m",
						1,
						{0.088,-0.015},
						1
					},
					
					{
						"SliderDiveSource90",
						1,
						"SliderDiveSource30",
						1,
						"SliderDiveSource",
						1,
						"SliderDiveSource30m",
						1,
						"SliderDiveSource90m",
						1,
						{0.029999999,-0.015},
						1
					},
					
					{
						"SliderDiveSource90",
						1,
						"SliderDiveSource30",
						1,
						"SliderDiveSource",
						1,
						"SliderDiveSource30m",
						1,
						"SliderDiveSource90m",
						1,
						{0.029999999,0.015},
						1
					},
					{},
					
					{
						{0.1,0.30000001},
						1
					},
					
					{
						{0.1,0.62},
						1
					},
					{},
					
					{
						{0.1,0.30000001},
						1
					},
					
					{
						{0.079999998,0.30000001},
						1
					},
					{},
					
					{
						{0.1,0.34},
						1
					},
					
					{
						{0.079999998,0.34},
						1
					},
					{},
					
					{
						{0.1,0.38},
						1
					},
					
					{
						{0.079999998,0.38},
						1
					},
					{},
					
					{
						{0.1,0.46000001},
						1
					},
					
					{
						{0.079999998,0.46000001},
						1
					},
					{},
					
					{
						{0.1,0.54000002},
						1
					},
					
					{
						{0.079999998,0.54000002},
						1
					},
					{},
					
					{
						{0.1,0.57999998},
						1
					},
					
					{
						{0.079999998,0.57999998},
						1
					},
					{},
					
					{
						{0.1,0.62},
						1
					},
					
					{
						{0.079999998,0.62},
						1
					},
					{},
					
					{
						"GForceSource",
						{0.015,0.0099999998},
						1
					},
					
					{
						"GForceSource",
						{0,0},
						1
					},
					
					{
						"GForceSource",
						{0.015,-0.0099999998},
						1
					},
					
					{
						"GForceSource",
						{0.015,0.0099999998},
						1
					},
					{},
					
					{
						{0.1,0.68800002},
						1
					},
					
					{
						{0.1,0.81999999},
						1
					},
					{},
					
					{
						{0.1,0.69999999},
						1
					},
					
					{
						{0.079999998,0.69999999},
						1
					},
					{},
					
					{
						{0.1,0.74000001},
						1
					},
					
					{
						{0.079999998,0.74000001},
						1
					},
					{},
					
					{
						{0.1,0.77999997},
						1
					},
					
					{
						{0.079999998,0.77999997},
						1
					},
					{},
					
					{
						{0.1,0.81999999},
						1
					},
					
					{
						{0.079999998,0.81999999},
						1
					},
					{},
					
					{
						{0.40000001,0.86000001},
						1
					},
					
					{
						{0.40000001,0.94},
						1
					},
					
					{
						{0.60000002,0.94},
						1
					},
					
					{
						{0.60000002,0.86000001},
						1
					},
					
					{
						{0.40000001,0.86000001},
						1
					},
					{},
					
					{
						{0.40000001,0.89499998},
						1
					},
					
					{
						{0.40799999,0.89499998},
						1
					},
					{},
					
					{
						{0.60000002,0.89499998},
						1
					},
					
					{
						{0.59200001,0.89499998},
						1
					},
					{},
					
					{
						{0.5,0.86000001},
						1
					},
					
					{
						{0.5,0.86799997},
						1
					},
					{},
					
					{
						{0.5,0.94},
						1
					},
					
					{
						{0.5,0.93199998},
						1
					},
					{},
					
					{
						{0.46000001,0.07},
						1
					},
					
					{
						{0.54000002,0.07},
						1
					},
					
					{
						{0.54000002,0.035},
						1
					},
					
					{
						{0.46000001,0.035},
						1
					},
					
					{
						{0.46000001,0.07},
						1
					},
					{},
					
					{
						{0.15000001,0.115},
						1
					},
					
					{
						{0.85000002,0.115},
						1
					},
					{},
					
					{
						{0,0.95999998},
						1
					},
					
					{
						{1.1,0.95999998},
						1
					},
					{},
					
					{
						{0.47999999,0.5},
						1
					},
					
					{
						{0.49000001,0.5},
						1
					},
					{},
					
					{
						{0.50999999,0.5},
						1
					},
					
					{
						{0.51999998,0.5},
						1
					},
					{},
					
					{
						{0.5,0.49000001},
						1
					},
					
					{
						{0.5,0.47999999},
						1
					},
					{},
					
					{
						{0.5,0.50999999},
						1
					},
					
					{
						{0.5,0.51999998},
						1
					},
					{},
					
					{
						"WeaponAim",
						1,
						{-0.02,0},
						1
					},
					
					{
						"WeaponAim",
						1,
						{-0.0099999998,0},
						1
					},
					{},
					
					{
						"WeaponAim",
						1,
						{0.0099999998,0},
						1
					},
					
					{
						"WeaponAim",
						1,
						{0.02,0},
						1
					},
					{},
					
					{
						"WeaponAim",
						1,
						{0,-0.0099999998},
						1
					},
					
					{
						"WeaponAim",
						1,
						{0,-0.02},
						1
					},
					{},
					
					{
						"WeaponAim",
						1,
						{0,0.0099999998},
						1
					},
					
					{
						"WeaponAim",
						1,
						{0,0.02},
						1
					},
					{},
					
					{
						"HUDCenter",
						{-0.16500001,7.0890902e-009},
						1
					},
					
					{
						"HUDCenter",
						{-0.22,9.45212e-009},
						1
					},
					{},
					
					{
						"HUDCenter",
						{0.16500001,-1.9339701e-009},
						1
					},
					
					{
						"HUDCenter",
						{0.22,-2.57863e-009},
						1
					},
					{},
					
					{
						"HUDCenter",
						{-0.082500003,0.140452},
						1
					},
					
					{
						"HUDCenter",
						{-0.096249998,0.16385999},
						1
					},
					{},
					
					{
						"HUDCenter",
						{0.082500003,0.140452},
						1
					},
					
					{
						"HUDCenter",
						{0.096249998,0.16385999},
						1
					},
					{},
					
					{
						"HUDCenter",
						{-0.142894,0.081089698},
						1
					},
					
					{
						"HUDCenter",
						{-0.16671,0.094604701},
						1
					},
					{},
					
					{
						"HUDCenter",
						{0.142894,0.081089698},
						1
					},
					
					{
						"HUDCenter",
						{0.16671,0.094604701},
						1
					},
					{},
					
					{
						"HUDCenter",
						{-0.116673,0.114678},
						1
					},
					
					{
						"HUDCenter",
						{-0.155564,0.152904},
						1
					},
					{},
					
					{
						"HUDCenter",
						{0.116673,0.114678},
						1
					},
					
					{
						"HUDCenter",
						{0.155563,0.152904},
						1
					},
					{},
					{}
				};
			};
			class Gunner
			{
				type="line";
				width=4;
				points[]=
				{
					
					{
						"GunnerAim",
						{0.48500001,0.89200002},
						1
					},
					
					{
						"GunnerAim",
						{0.48500001,0.90799999},
						1
					},
					
					{
						"GunnerAim",
						{0.51499999,0.90799999},
						1
					},
					
					{
						"GunnerAim",
						{0.51499999,0.89200002},
						1
					},
					
					{
						"GunnerAim",
						{0.48500001,0.89200002},
						1
					}
				};
			};
			class DiveNumber
			{
				type="text";
				source="horizondive";
				sourceScale=57.29578;
				sourceOffset=0;
				align="left";
				scale=1;
				pos[]=
				{
					"SliderDiveSource90",
					1,
					"SliderDiveSource30",
					1,
					"SliderDiveSource",
					1,
					"SliderDiveSource30m",
					1,
					"SliderDiveSource90m",
					1,
					
					{
						0.085000001,
						"0.00-0.011"
					},
					1
				};
				right[]=
				{
					"SliderDiveSource90",
					1,
					"SliderDiveSource30",
					1,
					"SliderDiveSource",
					1,
					"SliderDiveSource30m",
					1,
					"SliderDiveSource90m",
					1,
					
					{
						0.12,
						"0.00-0.011"
					},
					1
				};
				down[]=
				{
					"SliderDiveSource90",
					1,
					"SliderDiveSource30",
					1,
					"SliderDiveSource",
					1,
					"SliderDiveSource30m",
					1,
					"SliderDiveSource90m",
					1,
					
					{
						0.085000001,
						"0.03-0.011"
					},
					1
				};
			};
			class VSpeedGroup
			{
				condition="on";
				class VSpeedNumber
				{
					type="text";
					source="vspeed";
					sourceScale=1;
					align="center";
					scale=1;
					pos[]=
					{
						
						{
							"0.82+0.07",
							0.72799999
						},
						1
					};
					right[]=
					{
						
						{
							"0.87+0.07",
							0.72799999
						},
						1
					};
					down[]=
					{
						
						{
							"0.82+0.07",
							0.76300001
						},
						1
					};
				};
				class Static
				{
					type="line";
					width=3;
					points[]=
					{
						
						{
							{0.85900003,0.75999999},
							1
						},
						
						{
							{0.91900003,0.75999999},
							1
						},
						
						{
							{0.91900003,0.72500002},
							1
						},
						
						{
							{0.85900003,0.72500002},
							1
						},
						
						{
							{0.85900003,0.75999999},
							1
						},
						{}
					};
				};
			};
			class VSpeedGroupUp
			{
				condition="vspeed";
				class Static
				{
					type="line";
					width=3;
					points[]=
					{
						
						{
							{0.86900002,0.71499997},
							1
						},
						
						{
							{0.90899998,0.71499997},
							1
						},
						
						{
							{0.889,0.69499999},
							1
						},
						
						{
							{0.86900002,0.71499997},
							1
						},
						{}
					};
				};
			};
			class VSpeedGroupDown
			{
				condition="-vspeed";
				class Static
				{
					type="line";
					width=3;
					points[]=
					{
						
						{
							{0.86900002,0.76999998},
							1
						},
						
						{
							{0.90899998,0.76999998},
							1
						},
						
						{
							{0.889,0.79000002},
							1
						},
						
						{
							{0.86900002,0.76999998},
							1
						},
						{}
					};
				};
			};
			class AltGroup
			{
				condition="1000 - altitudeAGL";
				class Static
				{
					type="line";
					width=3;
					points[]=
					{
						
						{
							"SliderAltitudeSource",
							{0.024,0.0099999998},
							1
						},
						
						{
							"SliderAltitudeSource",
							{0.0089999996,0},
							1
						},
						
						{
							"SliderAltitudeSource",
							{0.024,-0.0099999998},
							1
						},
						
						{
							"SliderAltitudeSource",
							{0.024,0.0099999998},
							1
						},
						{},
						
						{
							"SliderAltitudeSource",
							{0.035,0.015},
							1
						},
						
						{
							"SliderAltitudeSource",
							{0.093000002,0.015},
							1
						},
						
						{
							"SliderAltitudeSource",
							{0.093000002,-0.015},
							1
						},
						
						{
							"SliderAltitudeSource",
							{0.035,-0.015},
							1
						},
						
						{
							"SliderAltitudeSource",
							{0.035,0.015},
							1
						},
						{},
						
						{
							{0.889,0.2},
							1
						},
						
						{
							{0.889,0.375},
							1
						},
						{},
						
						{
							{0.87900001,0.2},
							1
						},
						
						{
							{0.89899999,0.2},
							1
						},
						{},
						
						{
							{0.87900001,0.375},
							1
						},
						
						{
							{0.89899999,0.375},
							1
						},
						{}
					};
				};
				class AltNumber
				{
					type="text";
					source="altitudeAGL";
					sourceScale=1;
					sourceOffset=-3;
					align="left";
					scale=1;
					pos[]=
					{
						"SliderAltitudeSource",
						
						{
							0.085000001,
							"0.00-0.011"
						},
						1
					};
					right[]=
					{
						"SliderAltitudeSource",
						
						{
							0.11,
							"0.00-0.011"
						},
						1
					};
					down[]=
					{
						"SliderAltitudeSource",
						
						{
							0.085000001,
							"0.03-0.011"
						},
						1
					};
				};
				class AltStatic50
				{
					type="text";
					source="static";
					text="1000";
					scale=1;
					sourceScale=1;
					align="center";
					pos[]=
					{
						{0.88499999,0.171},
						1
					};
					right[]=
					{
						{0.92500001,0.171},
						1
					};
					down[]=
					{
						{0.88499999,0.20100001},
						1
					};
				};
			};
			class SpeedNumber
			{
				type="text";
				source="speed";
				sourceScale=3.5999999;
				sourceLength=3;
				align="left";
				scale=1;
				pos[]=
				{
					{0.13,0.22},
					1
				};
				down[]=
				{
					{0.13,0.25999999},
					1
				};
				right[]=
				{
					{0.2,0.22},
					1
				};
			};
			class Angle_90
			{
				type="text";
				source="static";
				text="90";
				scale=1;
				sourceScale=1;
				align="left";
				pos[]=
				{
					{0.07,0.285},
					1
				};
				right[]=
				{
					{0.11,0.285},
					1
				};
				down[]=
				{
					{0.07,0.315},
					1
				};
			};
			class Angle_30
			{
				type="text";
				source="static";
				text="30";
				scale=1;
				sourceScale=1;
				align="left";
				pos[]=
				{
					{0.07,0.32499999},
					1
				};
				right[]=
				{
					{0.11,0.32499999},
					1
				};
				down[]=
				{
					{0.07,0.35499999},
					1
				};
			};
			class Angle_10
			{
				type="text";
				source="static";
				text="10";
				scale=1;
				sourceScale=1;
				align="left";
				pos[]=
				{
					{0.07,0.36500001},
					1
				};
				right[]=
				{
					{0.11,0.36500001},
					1
				};
				down[]=
				{
					{0.07,0.39500001},
					1
				};
			};
			class Angle_0
			{
				type="text";
				source="static";
				text="0";
				scale=1;
				sourceScale=1;
				align="left";
				pos[]=
				{
					{0.07,0.44499999},
					1
				};
				right[]=
				{
					{0.11,0.44499999},
					1
				};
				down[]=
				{
					{0.07,0.47499999},
					1
				};
			};
			class Angle_10m
			{
				type="text";
				source="static";
				text="-10";
				scale=1;
				sourceScale=1;
				align="left";
				pos[]=
				{
					{0.07,0.52499998},
					1
				};
				right[]=
				{
					{0.11,0.52499998},
					1
				};
				down[]=
				{
					{0.07,0.55500001},
					1
				};
			};
			class Angle_30m
			{
				type="text";
				source="static";
				text="-30";
				scale=1;
				sourceScale=1;
				align="left";
				pos[]=
				{
					{0.07,0.565},
					1
				};
				right[]=
				{
					{0.11,0.565},
					1
				};
				down[]=
				{
					{0.07,0.59500003},
					1
				};
			};
			class Angle_90m
			{
				type="text";
				source="static";
				text="-90";
				scale=1;
				sourceScale=1;
				align="left";
				pos[]=
				{
					{0.07,0.60500002},
					1
				};
				right[]=
				{
					{0.11,0.60500002},
					1
				};
				down[]=
				{
					{0.07,0.63499999},
					1
				};
			};
			class GMeterStatic3
			{
				type="text";
				source="static";
				text="3";
				scale=1;
				sourceScale=1;
				align="left";
				pos[]=
				{
					{0.07,0.68300003},
					1
				};
				right[]=
				{
					{0.11,0.68300003},
					1
				};
				down[]=
				{
					{0.07,0.713},
					1
				};
			};
			class GMeterStatic2
			{
				type="text";
				source="static";
				text="2";
				scale=1;
				sourceScale=1;
				align="left";
				pos[]=
				{
					{0.07,0.72299999},
					1
				};
				right[]=
				{
					{0.11,0.72299999},
					1
				};
				down[]=
				{
					{0.07,0.75300002},
					1
				};
			};
			class GMeterStatic1
			{
				type="text";
				source="static";
				text="1";
				scale=1;
				sourceScale=1;
				align="left";
				pos[]=
				{
					{0.07,0.76300001},
					1
				};
				right[]=
				{
					{0.11,0.76300001},
					1
				};
				down[]=
				{
					{0.07,0.79299998},
					1
				};
			};
			class GMeterStatic0
			{
				type="text";
				source="static";
				text="0";
				scale=1;
				sourceScale=1;
				align="left";
				pos[]=
				{
					{0.07,0.80299997},
					1
				};
				right[]=
				{
					{0.11,0.80299997},
					1
				};
				down[]=
				{
					{0.07,0.833},
					1
				};
			};
			class RtdOnlyGroup
			{
				condition="simulRTD";
				class CollectiveNumber
				{
					type="text";
					source="rtdCollective";
					sourceScale=100;
					align="left";
					scale=1;
					pos[]=
					{
						{0.889,0.46000001},
						1
					};
					right[]=
					{
						{0.93900001,0.46000001},
						1
					};
					down[]=
					{
						{0.889,0.495},
						1
					};
				};
				class CollectiveText
				{
					type="text";
					source="static";
					text="%";
					scale=1;
					sourceScale=1;
					align="right";
					pos[]=
					{
						{0.89899999,0.46000001},
						1
					};
					right[]=
					{
						{0.949,0.46000001},
						1
					};
					down[]=
					{
						{0.89899999,0.495},
						1
					};
				};
				class EngineRPM
				{
					type="line";
					width=3;
					points[]=
					{
						
						{
							{0.88999999,0.5},
							1
						},
						
						{
							{0.88999999,0.66000003},
							1
						},
						{},
						
						{
							{0.92000002,0.5},
							1
						},
						
						{
							{0.86000001,0.5},
							1
						},
						{},
						
						{
							{0.92000002,0.66000003},
							1
						},
						
						{
							{0.86000001,0.66000003},
							1
						},
						{},
						
						{
							{0.91000003,0.54000002},
							1
						},
						
						{
							{0.87,0.54000002},
							1
						},
						{},
						
						{
							{0.91000003,0.57999998},
							1
						},
						
						{
							{0.87,0.57999998},
							1
						},
						{},
						
						{
							{0.91000003,0.62},
							1
						},
						
						{
							{0.87,0.62},
							1
						},
						{}
					};
				};
				class EngineRPMLines
				{
					type="line";
					width=5;
					points[]=
					{
						
						{
							
							{
								"0.90+0.01",
								0.66000003
							},
							1
						},
						
						{
							"rtdrpm1",
							
							{
								"0.90+0.01",
								0.66000003
							},
							1
						},
						{},
						
						{
							
							{
								"0.86+0.01",
								0.66000003
							},
							1
						},
						
						{
							"rtdrpm2",
							
							{
								"0.86+0.01",
								0.66000003
							},
							1
						},
						{},
						{}
					};
				};
				class RPM60Text
				{
					type="text";
					source="static";
					text="60";
					scale=1;
					sourceScale=1;
					align="right";
					pos[]=
					{
						{0.92500001,0.64499998},
						1
					};
					right[]=
					{
						{0.95499998,0.64499998},
						1
					};
					down[]=
					{
						{0.92500001,0.67000002},
						1
					};
				};
				class RPM80Text
				{
					type="text";
					source="static";
					text="80";
					scale=1;
					sourceScale=1;
					align="right";
					pos[]=
					{
						{0.92500001,0.60500002},
						1
					};
					right[]=
					{
						{0.95499998,0.60500002},
						1
					};
					down[]=
					{
						{0.92500001,0.63},
						1
					};
				};
				class RPM100Text
				{
					type="text";
					source="static";
					text="100";
					scale=1;
					sourceScale=1;
					align="right";
					pos[]=
					{
						{0.92500001,0.565},
						1
					};
					right[]=
					{
						{0.95499998,0.565},
						1
					};
					down[]=
					{
						{0.92500001,0.58999997},
						1
					};
				};
				class RPM120Text
				{
					type="text";
					source="static";
					text="120";
					scale=1;
					sourceScale=1;
					align="right";
					pos[]=
					{
						{0.92500001,0.52499998},
						1
					};
					right[]=
					{
						{0.95499998,0.52499998},
						1
					};
					down[]=
					{
						{0.92500001,0.55000001},
						1
					};
				};
			};
			class HeadingNumber
			{
				type="text";
				source="heading";
				sourceScale=1;
				align="center";
				scale=1;
				pos[]=
				{
					
					{
						"0.80-0.302",
						"0.082-0.043"
					},
					1
				};
				right[]=
				{
					
					{
						"0.84-0.302",
						"0.082-0.043"
					},
					1
				};
				down[]=
				{
					
					{
						"0.80-0.302",
						"0.117-0.043"
					},
					1
				};
			};
			class HeadingRotationArrow
			{
				condition="5-abs(cameraDir-heading)*( (abs(heading-cameraDir))<=355)";
				class HeadingArrow
				{
					type="line";
					width=3;
					points[]=
					{
						
						{
							{0.51999998,0.079999998},
							1
						},
						
						{
							{0.5,0.11},
							1
						},
						
						{
							{0.47999999,0.079999998},
							1
						},
						
						{
							{0.51999998,0.079999998},
							1
						},
						{}
					};
				};
			};
			class HeadingRotation
			{
				condition="abs(cameraDir-heading)*( (abs(heading-cameraDir))<=355)-5";
				class HeadingHeadNumber
				{
					type="text";
					source="cameraDir";
					sourceScale=1;
					align="center";
					scale=1;
					pos[]=
					{
						
						{
							"0.80-0.302",
							"0.082+0.001"
						},
						1
					};
					right[]=
					{
						
						{
							"0.83-0.302",
							"0.082+0.001"
						},
						1
					};
					down[]=
					{
						
						{
							"0.80-0.302",
							"0.113+0.001"
						},
						1
					};
				};
				class HeadingArrow
				{
					type="line";
					width=3;
					points[]=
					{
						
						{
							{0.47799999,0.075000003},
							1
						},
						
						{
							{0.52200001,0.075000003},
							1
						},
						
						{
							{0.55199999,0.094999999},
							1
						},
						
						{
							{0.52200001,0.115},
							1
						},
						
						{
							{0.47799999,0.115},
							1
						},
						
						{
							{0.44800001,0.094999999},
							1
						},
						
						{
							{0.47799999,0.075000003},
							1
						},
						{}
					};
				};
			};
			class HeadingScale
			{
				type="scale";
				horizontal=1;
				source="heading";
				sourceScale=0.1;
				sourceoffset=0;
				width=3;
				NeverEatSeaWeed=1;
				top=0.15000001;
				center=0.5;
				bottom=0.85000002;
				lineXleft=0.114;
				lineYright=0.12;
				lineXleftMajor=0.114;
				lineYrightMajor=0.13;
				majorLineEach=2;
				numberEach=6;
				step=0.5;
				stepSize=0.034482799;
				align="center";
				scale=1;
				pos[]={0.15000001,0.13};
				right[]={0.20999999,0.13};
				down[]={0.15000001,0.17};
			};
			class HorizonBanking
			{
				type="line";
				width=3;
				clipTL[]={0,0.1};
				clipBR[]={1,0.89999998};
				points[]=
				{
					
					{
						"HorizonBankSource",
						{0.16,0},
						1
					},
					
					{
						"HorizonBankSource",
						{0.1,0},
						1
					},
					
					{
						"HorizonBankSource",
						{0.085000001,-0.015},
						1
					},
					
					{
						"HorizonBankSource",
						{0.07,0},
						1
					},
					
					{
						"HorizonBankSource",
						{0.050000001,0},
						1
					},
					{},
					
					{
						"HorizonBankSource",
						{-0.16,0},
						1
					},
					
					{
						"HorizonBankSource",
						{-0.1,0},
						1
					},
					
					{
						"HorizonBankSource",
						{-0.085000001,-0.015},
						1
					},
					
					{
						"HorizonBankSource",
						{-0.07,0},
						1
					},
					
					{
						"HorizonBankSource",
						{-0.050000001,0},
						1
					},
					{}
				};
			};
			class CoordXNumber
			{
				type="text";
				source="coordinateX";
				sourceScale=0.0099999998;
				sourceLength=3;
				sourceOffset=-0.5;
				align="right";
				scale=1;
				pos[]=
				{
					{0.80900002,0.96100003},
					1
				};
				right[]=
				{
					{0.85900003,0.96100003},
					1
				};
				down[]=
				{
					{0.80900002,0.99599999},
					1
				};
			};
			class CoordYNumber: CoordXNumber
			{
				source="coordinateY";
				pos[]=
				{
					{0.89899999,0.96100003},
					1
				};
				right[]=
				{
					{0.949,0.96100003},
					1
				};
				down[]=
				{
					{0.89899999,0.99599999},
					1
				};
			};
			class Time: CoordXNumber
			{
				source="time";
				text="%X";
				align="left";
				pos[]=
				{
					{0.60500002,0.96100003},
					1
				};
				right[]=
				{
					{0.65499997,0.96100003},
					1
				};
				down[]=
				{
					{0.60500002,0.99599999},
					1
				};
			};
			class CurrentWeapon
			{
				type="text";
				source="weapon";
				sourceScale=1;
				align="left";
				scale=1;
				pos[]=
				{
					{0.97899997,0.889},
					1
				};
				right[]=
				{
					{1.029,0.889},
					1
				};
				down[]=
				{
					{0.97899997,0.92400002},
					1
				};
			};
			class CurrentAmmo: CurrentWeapon
			{
				source="ammo";
				align="left";
				pos[]=
				{
					{0.97899997,0.921},
					1
				};
				right[]=
				{
					{1.029,0.921},
					1
				};
				down[]=
				{
					{0.97899997,0.95599997},
					1
				};
			};
			class CoordXText
			{
				type="text";
				source="static";
				text="GRID:";
				scale=1;
				sourceScale=1;
				align="right";
				pos[]=
				{
					{0.65499997,0.96100003},
					1
				};
				right[]=
				{
					{0.70499998,0.96100003},
					1
				};
				down[]=
				{
					{0.65499997,0.99599999},
					1
				};
			};
			class CoordYText
			{
				type="text";
				source="static";
				text="";
				scale=1;
				sourceScale=1;
				align="right";
				pos[]=
				{
					{0.875,0.96100003},
					1
				};
				right[]=
				{
					{0.92500001,0.96100003},
					1
				};
				down[]=
				{
					{0.875,0.99599999},
					1
				};
			};
			class LightsGroup
			{
				condition="lights";
				class LightsText
				{
					type="text";
					source="static";
					text="LIGHT";
					align="left";
					scale=1;
					pos[]=
					{
						{0.149,0.96100003},
						1
					};
					right[]=
					{
						{0.199,0.96100003},
						1
					};
					down[]=
					{
						{0.149,0.99599999},
						1
					};
				};
			};
			class CollisionLights
			{
				condition="collisionlights";
				class CollisionLightsText
				{
					type="text";
					source="static";
					text="COLL";
					align="left";
					scale=1;
					pos[]=
					{
						{0.30899999,0.96100003},
						1
					};
					right[]=
					{
						{0.359,0.96100003},
						1
					};
					down[]=
					{
						{0.30899999,0.99599999},
						1
					};
				};
			};
			class WeaponsLocking
			{
				condition="missilelocking";
				blinkingPattern[]={0.2,0.2};
				blinkingStartsOn=1;
				class Text
				{
					type="text";
					source="static";
					text="LOCKING";
					align="center";
					scale=1;
					pos[]=
					{
						{0.215,0.87970102},
						1
					};
					right[]=
					{
						{0.27500001,0.87970102},
						1
					};
					down[]=
					{
						{0.215,0.928846},
						1
					};
				};
			};
			class TargetInfo
			{
				condition="missilelocked";
				class TargetLockedText
				{
					type="text";
					source="static";
					text="TARGET ACQUIRED";
					scale=1;
					sourceScale=1;
					align="center";
					pos[]=
					{
						{0.19499999,0.85900003},
						1
					};
					right[]=
					{
						{0.235,0.85900003},
						1
					};
					down[]=
					{
						{0.19499999,0.88999999},
						1
					};
				};
				class TimeOfFlightText
				{
					type="text";
					source="static";
					text="TOF:";
					scale=1;
					sourceScale=1;
					align="left";
					pos[]=
					{
						
						{
							"0.127+0.13",
							0.889
						},
						1
					};
					right[]=
					{
						{0.30199999,0.889},
						1
					};
					down[]=
					{
						
						{
							"0.127+0.13",
							0.92400002
						},
						1
					};
				};
				class DistanceText
				{
					type="text";
					source="static";
					text="DISTANCE:";
					scale=1;
					sourceScale=1;
					align="left";
					pos[]=
					{
						
						{
							"0.125+0.13",
							0.921
						},
						1
					};
					right[]=
					{
						{0.30000001,0.921},
						1
					};
					down[]=
					{
						
						{
							"0.125+0.13",
							0.95599997
						},
						1
					};
				};
				class TOF_source: CurrentWeapon
				{
					source="missileflighttime";
					align="right";
					pos[]=
					{
						{0.26899999,0.889},
						1
					};
					right[]=
					{
						{0.31900001,0.889},
						1
					};
					down[]=
					{
						{0.26899999,0.92400002},
						1
					};
				};
				class TargetDistance: CurrentWeapon
				{
					source="targetDist";
					sourceLength=0;
					sourcePrecision=1;
					sourceScale=0.001;
					align="right";
					pos[]=
					{
						{0.26899999,0.921},
						1
					};
					right[]=
					{
						{0.31900001,0.921},
						1
					};
					down[]=
					{
						{0.26899999,0.95599997},
						1
					};
				};
			};
			class IncomingMissile
			{
				condition="incomingmissile";
				blinkingPattern[]={0.30000001,0.30000001};
				blinkingStartsOn=1;
				class Text
				{
					type="text";
					source="static";
					text="!INCOMING MISSILE!";
					align="center";
					scale=1;
					pos[]=
					{
						{0.48500001,0.21623901},
						1
					};
					right[]=
					{
						{0.54500002,0.21623901},
						1
					};
					down[]=
					{
						{0.48500001,0.265385},
						1
					};
				};
			};
			class MGun
			{
				condition="-2+mgun*ImpactDistance";
				class Cross
				{
					type="line";
					width=3;
					points[]=
					{
						
						{
							"ImpactPoint",
							{0,-0.0294872},
							1
						},
						
						{
							"ImpactPoint",
							{0,-0.0393162},
							1
						},
						{},
						
						{
							"ImpactPoint",
							{0.02,-0.024},
							1
						},
						
						{
							"ImpactPoint",
							{0.025,-0.030999999},
							1
						},
						{},
						
						{
							"ImpactPoint",
							{0,-0.0020000001},
							1
						},
						
						{
							"ImpactPoint",
							{0,0.0020000001},
							1
						},
						{},
						
						{
							"ImpactPoint",
							{-0.0020000001,0},
							1
						},
						
						{
							"ImpactPoint",
							{0.0020000001,0},
							1
						},
						{}
					};
				};
				class Circle
				{
					type="line";
					width=3;
					points[]=
					{
						
						{
							"ImpactPoint",
							{0,-0.0275214},
							1
						},
						
						{
							"ImpactPoint",
							{0,-0.0344017},
							1
						},
						
						{
							"MissileFlightTimeRot1",
							{0,0.035},
							1,
							"ImpactPoint",
							1
						},
						
						{
							"MissileFlightTimeRot2",
							{0,0.035},
							1,
							"ImpactPoint",
							1
						},
						
						{
							"MissileFlightTimeRot3",
							{0,0.035},
							1,
							"ImpactPoint",
							1
						},
						
						{
							"MissileFlightTimeRot4",
							{0,0.035},
							1,
							"ImpactPoint",
							1
						},
						
						{
							"MissileFlightTimeRot5",
							{0,0.035},
							1,
							"ImpactPoint",
							1
						},
						
						{
							"MissileFlightTimeRot6",
							{0,0.035},
							1,
							"ImpactPoint",
							1
						},
						
						{
							"MissileFlightTimeRot7",
							{0,0.035},
							1,
							"ImpactPoint",
							1
						},
						
						{
							"MissileFlightTimeRot8",
							{0,0.035},
							1,
							"ImpactPoint",
							1
						},
						
						{
							"MissileFlightTimeRot9",
							{0,0.035},
							1,
							"ImpactPoint",
							1
						},
						
						{
							"MissileFlightTimeRot10",
							{0,0.035},
							1,
							"ImpactPoint",
							1
						},
						
						{
							"MissileFlightTimeRot11",
							{0,0.035},
							1,
							"ImpactPoint",
							1
						},
						
						{
							"MissileFlightTimeRot12",
							{0,0.035},
							1,
							"ImpactPoint",
							1
						},
						
						{
							"MissileFlightTimeRot13",
							{0,0.035},
							1,
							"ImpactPoint",
							1
						},
						
						{
							"MissileFlightTimeRot14",
							{0,0.035},
							1,
							"ImpactPoint",
							1
						},
						
						{
							"MissileFlightTimeRot15",
							{0,0.035},
							1,
							"ImpactPoint",
							1
						},
						
						{
							"MissileFlightTimeRot16",
							{0,0.035},
							1,
							"ImpactPoint",
							1
						},
						
						{
							"MissileFlightTimeRot17",
							{0,0.035},
							1,
							"ImpactPoint",
							1
						},
						
						{
							"MissileFlightTimeRot18",
							{0,0.035},
							1,
							"ImpactPoint",
							1
						},
						
						{
							"MissileFlightTimeRot19",
							{0,0.035},
							1,
							"ImpactPoint",
							1
						},
						
						{
							"MissileFlightTimeRot20",
							{0,0.035},
							1,
							"ImpactPoint",
							1
						},
						
						{
							"MissileFlightTimeRot20",
							{0,0.028000001},
							1,
							"ImpactPoint",
							1
						}
					};
				};
				class Circle_Min_Range
				{
					type="line";
					width=3;
					points[]=
					{
						
						{
							"ImpactPoint",
							{0,-0.0294872},
							1
						},
						
						{
							"ImpactPoint",
							{0.0052080001,-0.029038999},
							1
						},
						
						{
							"ImpactPoint",
							{0.01026,-0.0277091},
							1
						},
						
						{
							"ImpactPoint",
							{0.015,-0.0255359},
							1
						},
						
						{
							"ImpactPoint",
							{0.019284001,-0.022587201},
							1
						},
						
						{
							"ImpactPoint",
							{0.022980001,-0.0189544},
							1
						},
						
						{
							"ImpactPoint",
							{0.025979999,-0.0147436},
							1
						},
						
						{
							"ImpactPoint",
							{0.028191,-0.0100846},
							1
						},
						
						{
							"ImpactPoint",
							{0.029544,-0.0051189698},
							1
						},
						
						{
							"ImpactPoint",
							{0.029999999,0},
							1
						},
						
						{
							"ImpactPoint",
							{0.029544,0.0051189698},
							1
						},
						
						{
							"ImpactPoint",
							{0.028191,0.0100846},
							1
						},
						
						{
							"ImpactPoint",
							{0.025979999,0.0147436},
							1
						},
						
						{
							"ImpactPoint",
							{0.022980001,0.0189544},
							1
						},
						
						{
							"ImpactPoint",
							{0.019284001,0.022587201},
							1
						},
						
						{
							"ImpactPoint",
							{0.015,0.0255359},
							1
						},
						
						{
							"ImpactPoint",
							{0.01026,0.0277091},
							1
						},
						
						{
							"ImpactPoint",
							{0.0052080001,0.029038999},
							1
						},
						
						{
							"ImpactPoint",
							{0,0.0294872},
							1
						},
						
						{
							"ImpactPoint",
							{-0.0052080001,0.029038999},
							1
						},
						
						{
							"ImpactPoint",
							{-0.01026,0.0277091},
							1
						},
						
						{
							"ImpactPoint",
							{-0.015,0.0255359},
							1
						},
						
						{
							"ImpactPoint",
							{-0.019284001,0.022587201},
							1
						},
						
						{
							"ImpactPoint",
							{-0.022980001,0.0189544},
							1
						},
						
						{
							"ImpactPoint",
							{-0.025979999,0.0147436},
							1
						},
						
						{
							"ImpactPoint",
							{-0.028191,0.0100846},
							1
						},
						
						{
							"ImpactPoint",
							{-0.029544,0.0051189698},
							1
						},
						
						{
							"ImpactPoint",
							{-0.029999999,0},
							1
						},
						
						{
							"ImpactPoint",
							{-0.029544,-0.0051189698},
							1
						},
						
						{
							"ImpactPoint",
							{-0.028191,-0.0100846},
							1
						},
						
						{
							"ImpactPoint",
							{-0.025979999,-0.0147436},
							1
						},
						
						{
							"ImpactPoint",
							{-0.022980001,-0.0189544},
							1
						},
						
						{
							"ImpactPoint",
							{-0.019284001,-0.022587201},
							1
						},
						
						{
							"ImpactPoint",
							{-0.015,-0.0255359},
							1
						},
						
						{
							"ImpactPoint",
							{-0.01026,-0.0277091},
							1
						},
						
						{
							"ImpactPoint",
							{-0.0052080001,-0.029038999},
							1
						},
						
						{
							"ImpactPoint",
							{0,-0.0294872},
							1
						}
					};
				};
				class Distance
				{
					type="text";
					source="ImpactDistance";
					sourceScale=0.001;
					sourcePrecision=1;
					max=15;
					align="center";
					scale=1;
					pos[]=
					{
						"ImpactPoint",
						{-0.0020000001,-0.079999998},
						1
					};
					right[]=
					{
						"ImpactPoint",
						{0.045000002,-0.079999998},
						1
					};
					down[]=
					{
						"ImpactPoint",
						{-0.0020000001,-0.039999999},
						1
					};
				};
			};
			class Rockets
			{
				condition="-2+rocket*ImpactDistance";
				class Cross
				{
					type="line";
					width=3;
					points[]=
					{
						
						{
							"ImpactPoint",
							{0,-0.0294872},
							1
						},
						
						{
							"ImpactPoint",
							{0,-0.0393162},
							1
						},
						{},
						
						{
							"ImpactPoint",
							{0.02,-0.024},
							1
						},
						
						{
							"ImpactPoint",
							{0.025,-0.030999999},
							1
						},
						{},
						
						{
							"ImpactPoint",
							{0,-0.0020000001},
							1
						},
						
						{
							"ImpactPoint",
							{0,0.0020000001},
							1
						},
						{},
						
						{
							"ImpactPoint",
							{-0.0020000001,0},
							1
						},
						
						{
							"ImpactPoint",
							{0.0020000001,0},
							1
						},
						{}
					};
				};
				class Circle
				{
					type="line";
					width=3;
					points[]=
					{
						
						{
							"ImpactPoint",
							{0,-0.0275214},
							1
						},
						
						{
							"ImpactPoint",
							{0,-0.0344017},
							1
						},
						
						{
							"MissileFlightTimeRot1",
							{0,0.035},
							1,
							"ImpactPoint",
							1
						},
						
						{
							"MissileFlightTimeRot2",
							{0,0.035},
							1,
							"ImpactPoint",
							1
						},
						
						{
							"MissileFlightTimeRot3",
							{0,0.035},
							1,
							"ImpactPoint",
							1
						},
						
						{
							"MissileFlightTimeRot4",
							{0,0.035},
							1,
							"ImpactPoint",
							1
						},
						
						{
							"MissileFlightTimeRot5",
							{0,0.035},
							1,
							"ImpactPoint",
							1
						},
						
						{
							"MissileFlightTimeRot6",
							{0,0.035},
							1,
							"ImpactPoint",
							1
						},
						
						{
							"MissileFlightTimeRot7",
							{0,0.035},
							1,
							"ImpactPoint",
							1
						},
						
						{
							"MissileFlightTimeRot8",
							{0,0.035},
							1,
							"ImpactPoint",
							1
						},
						
						{
							"MissileFlightTimeRot9",
							{0,0.035},
							1,
							"ImpactPoint",
							1
						},
						
						{
							"MissileFlightTimeRot10",
							{0,0.035},
							1,
							"ImpactPoint",
							1
						},
						
						{
							"MissileFlightTimeRot11",
							{0,0.035},
							1,
							"ImpactPoint",
							1
						},
						
						{
							"MissileFlightTimeRot12",
							{0,0.035},
							1,
							"ImpactPoint",
							1
						},
						
						{
							"MissileFlightTimeRot13",
							{0,0.035},
							1,
							"ImpactPoint",
							1
						},
						
						{
							"MissileFlightTimeRot14",
							{0,0.035},
							1,
							"ImpactPoint",
							1
						},
						
						{
							"MissileFlightTimeRot15",
							{0,0.035},
							1,
							"ImpactPoint",
							1
						},
						
						{
							"MissileFlightTimeRot16",
							{0,0.035},
							1,
							"ImpactPoint",
							1
						},
						
						{
							"MissileFlightTimeRot17",
							{0,0.035},
							1,
							"ImpactPoint",
							1
						},
						
						{
							"MissileFlightTimeRot18",
							{0,0.035},
							1,
							"ImpactPoint",
							1
						},
						
						{
							"MissileFlightTimeRot19",
							{0,0.035},
							1,
							"ImpactPoint",
							1
						},
						
						{
							"MissileFlightTimeRot20",
							{0,0.035},
							1,
							"ImpactPoint",
							1
						},
						
						{
							"MissileFlightTimeRot20",
							{0,0.028000001},
							1,
							"ImpactPoint",
							1
						}
					};
				};
				class Circle_Min_Range
				{
					type="line";
					width=3;
					points[]=
					{
						
						{
							"ImpactPoint",
							{0,-0.0294872},
							1
						},
						
						{
							"ImpactPoint",
							{0.0052080001,-0.029038999},
							1
						},
						
						{
							"ImpactPoint",
							{0.01026,-0.0277091},
							1
						},
						
						{
							"ImpactPoint",
							{0.015,-0.0255359},
							1
						},
						
						{
							"ImpactPoint",
							{0.019284001,-0.022587201},
							1
						},
						
						{
							"ImpactPoint",
							{0.022980001,-0.0189544},
							1
						},
						
						{
							"ImpactPoint",
							{0.025979999,-0.0147436},
							1
						},
						
						{
							"ImpactPoint",
							{0.028191,-0.0100846},
							1
						},
						
						{
							"ImpactPoint",
							{0.029544,-0.0051189698},
							1
						},
						
						{
							"ImpactPoint",
							{0.029999999,0},
							1
						},
						
						{
							"ImpactPoint",
							{0.029544,0.0051189698},
							1
						},
						
						{
							"ImpactPoint",
							{0.028191,0.0100846},
							1
						},
						
						{
							"ImpactPoint",
							{0.025979999,0.0147436},
							1
						},
						
						{
							"ImpactPoint",
							{0.022980001,0.0189544},
							1
						},
						
						{
							"ImpactPoint",
							{0.019284001,0.022587201},
							1
						},
						
						{
							"ImpactPoint",
							{0.015,0.0255359},
							1
						},
						
						{
							"ImpactPoint",
							{0.01026,0.0277091},
							1
						},
						
						{
							"ImpactPoint",
							{0.0052080001,0.029038999},
							1
						},
						
						{
							"ImpactPoint",
							{0,0.0294872},
							1
						},
						
						{
							"ImpactPoint",
							{-0.0052080001,0.029038999},
							1
						},
						
						{
							"ImpactPoint",
							{-0.01026,0.0277091},
							1
						},
						
						{
							"ImpactPoint",
							{-0.015,0.0255359},
							1
						},
						
						{
							"ImpactPoint",
							{-0.019284001,0.022587201},
							1
						},
						
						{
							"ImpactPoint",
							{-0.022980001,0.0189544},
							1
						},
						
						{
							"ImpactPoint",
							{-0.025979999,0.0147436},
							1
						},
						
						{
							"ImpactPoint",
							{-0.028191,0.0100846},
							1
						},
						
						{
							"ImpactPoint",
							{-0.029544,0.0051189698},
							1
						},
						
						{
							"ImpactPoint",
							{-0.029999999,0},
							1
						},
						
						{
							"ImpactPoint",
							{-0.029544,-0.0051189698},
							1
						},
						
						{
							"ImpactPoint",
							{-0.028191,-0.0100846},
							1
						},
						
						{
							"ImpactPoint",
							{-0.025979999,-0.0147436},
							1
						},
						
						{
							"ImpactPoint",
							{-0.022980001,-0.0189544},
							1
						},
						
						{
							"ImpactPoint",
							{-0.019284001,-0.022587201},
							1
						},
						
						{
							"ImpactPoint",
							{-0.015,-0.0255359},
							1
						},
						
						{
							"ImpactPoint",
							{-0.01026,-0.0277091},
							1
						},
						
						{
							"ImpactPoint",
							{-0.0052080001,-0.029038999},
							1
						},
						
						{
							"ImpactPoint",
							{0,-0.0294872},
							1
						}
					};
				};
				class Distance
				{
					type="text";
					source="ImpactDistance";
					sourceScale=0.001;
					sourcePrecision=1;
					max=15;
					align="center";
					scale=1;
					pos[]=
					{
						"ImpactPoint",
						{-0.0020000001,-0.079999998},
						1
					};
					right[]=
					{
						"ImpactPoint",
						{0.045000002,-0.079999998},
						1
					};
					down[]=
					{
						"ImpactPoint",
						{-0.0020000001,-0.039999999},
						1
					};
				};
			};
			class BombCrosshairGroup
			{
				type="group";
				condition="bomb";
				class BombCrosshair
				{
					type="line";
					width=4;
					points[]=
					{
						
						{
							"ImpactPoint",
							{0,-0.0982906},
							1
						},
						
						{
							"ImpactPoint",
							{0.01736,-0.096796602},
							1
						},
						
						{
							"ImpactPoint",
							{0.034200002,-0.0923637},
							1
						},
						
						{
							"ImpactPoint",
							{0.050000001,-0.085119702},
							1
						},
						
						{
							"ImpactPoint",
							{0.064280003,-0.075290598},
							1
						},
						
						{
							"ImpactPoint",
							{0.0766,-0.063181199},
							1
						},
						
						{
							"ImpactPoint",
							{0.086599998,-0.0491453},
							1
						},
						
						{
							"ImpactPoint",
							{0.093970001,-0.033615399},
							1
						},
						
						{
							"ImpactPoint",
							{0.098480001,-0.0170632},
							1
						},
						
						{
							"ImpactPoint",
							{0.1,0},
							1
						},
						
						{
							"ImpactPoint",
							{0.098480001,0.0170632},
							1
						},
						
						{
							"ImpactPoint",
							{0.093970001,0.033615399},
							1
						},
						
						{
							"ImpactPoint",
							{0.086599998,0.0491453},
							1
						},
						
						{
							"ImpactPoint",
							{0.0766,0.063181199},
							1
						},
						
						{
							"ImpactPoint",
							{0.064280003,0.075290598},
							1
						},
						
						{
							"ImpactPoint",
							{0.050000001,0.085119702},
							1
						},
						
						{
							"ImpactPoint",
							{0.034200002,0.0923637},
							1
						},
						
						{
							"ImpactPoint",
							{0.01736,0.096796602},
							1
						},
						
						{
							"ImpactPoint",
							{0,0.0982906},
							1
						},
						
						{
							"ImpactPoint",
							{-0.01736,0.096796602},
							1
						},
						
						{
							"ImpactPoint",
							{-0.034200002,0.0923637},
							1
						},
						
						{
							"ImpactPoint",
							{-0.050000001,0.085119702},
							1
						},
						
						{
							"ImpactPoint",
							{-0.064280003,0.075290598},
							1
						},
						
						{
							"ImpactPoint",
							{-0.0766,0.063181199},
							1
						},
						
						{
							"ImpactPoint",
							{-0.086599998,0.0491453},
							1
						},
						
						{
							"ImpactPoint",
							{-0.093970001,0.033615399},
							1
						},
						
						{
							"ImpactPoint",
							{-0.098480001,0.0170632},
							1
						},
						
						{
							"ImpactPoint",
							{-0.1,0},
							1
						},
						
						{
							"ImpactPoint",
							{-0.098480001,-0.0170632},
							1
						},
						
						{
							"ImpactPoint",
							{-0.093970001,-0.033615399},
							1
						},
						
						{
							"ImpactPoint",
							{-0.086599998,-0.0491453},
							1
						},
						
						{
							"ImpactPoint",
							{-0.0766,-0.063181199},
							1
						},
						
						{
							"ImpactPoint",
							{-0.064280003,-0.075290598},
							1
						},
						
						{
							"ImpactPoint",
							{-0.050000001,-0.085119702},
							1
						},
						
						{
							"ImpactPoint",
							{-0.034200002,-0.0923637},
							1
						},
						
						{
							"ImpactPoint",
							{-0.01736,-0.096796602},
							1
						},
						
						{
							"ImpactPoint",
							{0,-0.0982906},
							1
						},
						{},
						
						{
							"ImpactPoint",
							1,
							"Limit0109",
							1,
							{0,-0.0196581},
							1
						},
						
						{
							"ImpactPoint",
							1,
							"Limit0109",
							1,
							{0.014,-0.0137607},
							1
						},
						
						{
							"ImpactPoint",
							1,
							"Limit0109",
							1,
							
							{
								"+ 0.02",
								0
							},
							1
						},
						
						{
							"ImpactPoint",
							1,
							"Limit0109",
							1,
							{0.014,0.0137607},
							1
						},
						
						{
							"ImpactPoint",
							1,
							"Limit0109",
							1,
							{0,0.0196581},
							1
						},
						
						{
							"ImpactPoint",
							1,
							"Limit0109",
							1,
							{-0.014,0.0137607},
							1
						},
						
						{
							"ImpactPoint",
							1,
							"Limit0109",
							1,
							
							{
								"- 0.02",
								0
							},
							1
						},
						
						{
							"ImpactPoint",
							1,
							"Limit0109",
							1,
							{-0.014,-0.0137607},
							1
						},
						
						{
							"ImpactPoint",
							1,
							"Limit0109",
							1,
							{0,-0.0196581},
							1
						},
						{},
						
						{
							"VelocityVector",
							0.001,
							"ImpactPoint",
							1,
							"Limit0109",
							1,
							{0,0},
							1
						},
						
						{
							"VelocityVector",
							1,
							"Limit0109",
							1,
							{0,0},
							1
						}
					};
				};
				class Distance
				{
					type="text";
					source="ImpactDistance";
					sourceScale=0.001;
					sourcePrecision=1;
					max=15;
					align="center";
					scale=1;
					pos[]=
					{
						"ImpactPoint",
						{-0.0020000001,0.11},
						1
					};
					right[]=
					{
						"ImpactPoint",
						{0.045000002,0.11},
						1
					};
					down[]=
					{
						"ImpactPoint",
						{-0.0020000001,0.15000001},
						1
					};
				};
			};
			class WP
			{
				condition="wpvalid";
				class WPdist
				{
					type="text";
					source="wpdist";
					sourceScale=0.001;
					sourcePrecision=1;
					align="left";
					scale=1;
					pos[]=
					{
						{0.935,0.79713702},
						1
					};
					right[]=
					{
						{0.97500002,0.79713702},
						1
					};
					down[]=
					{
						{0.935,0.83448702},
						1
					};
				};
				class WPstatic
				{
					type="text";
					source="static";
					text=">";
					align="center";
					scale=2;
					pos[]=
					{
						{0.94999999,0.79713702},
						1
					};
					right[]=
					{
						{0.97000003,0.79713702},
						1
					};
					down[]=
					{
						{0.94999999,0.83448702},
						1
					};
				};
				class WPIndex
				{
					type="text";
					source="wpIndex";
					sourceScale=1;
					align="right";
					scale=1;
					pos[]=
					{
						{0.95999998,0.79713702},
						1
					};
					right[]=
					{
						{1,0.79713702},
						1
					};
					down[]=
					{
						{0.95999998,0.83448702},
						1
					};
				};
				class WP
				{
					width=1;
					type="line";
					points[]=
					{
						
						{
							"wppoint",
							1,
							
							{
								"HorizonBankRotFull",
								0.015,
								-0.035
							},
							1
						},
						
						{
							"wppoint",
							1,
							
							{
								"HorizonBankRotFull",
								0,
								0
							},
							1
						},
						
						{
							"wppoint",
							1,
							
							{
								"HorizonBankRotFull",
								-0.015,
								-0.035
							},
							1
						}
					};
				};
			};
			class RadarBoxes
			{
				type="radartoview";
				pos0[]={0.5,0.5};
				pos10[]={0.73400003,0.73000002};
				width=2;
				points[]=
				{
					
					{
						{-0.0020000001,-0.0019658101},
						1
					},
					
					{
						{0.0020000001,-0.0019658101},
						1
					},
					
					{
						{0.0020000001,0.0019658101},
						1
					},
					
					{
						{-0.0020000001,0.0019658101},
						1
					},
					
					{
						{-0.0020000001,-0.0019658101},
						1
					}
				};
			};
			class TargetDiamond
			{
				class shape
				{
					type="line";
					width=4;
					points[]=
					{
						
						{
							"Target",
							1,
							"Limit0109",
							1,
							{0.02,0.0196581},
							1
						},
						
						{
							"Target",
							1,
							"Limit0109",
							1,
							{-0.02,0.0196581},
							1
						},
						
						{
							"Target",
							1,
							"Limit0109",
							1,
							{-0.02,-0.0196581},
							1
						},
						
						{
							"Target",
							1,
							"Limit0109",
							1,
							{0.02,-0.0196581},
							1
						},
						
						{
							"Target",
							1,
							"Limit0109",
							1,
							{0.02,0.0196581},
							1
						}
					};
				};
			};
			class TargetLocked
			{
				condition="missilelocked";
				class shape
				{
					type="line";
					width=4;
					points[]=
					{
						
						{
							"Target",
							1,
							"Limit0109",
							1,
							{0,-0.0294872},
							1
						},
						
						{
							"Target",
							1,
							"Limit0109",
							1,
							{0.029999999,0},
							1
						},
						
						{
							"Target",
							1,
							"Limit0109",
							1,
							{0,0.0294872},
							1
						},
						
						{
							"Target",
							1,
							"Limit0109",
							1,
							{-0.029999999,0},
							1
						},
						
						{
							"Target",
							1,
							"Limit0109",
							1,
							{0,-0.0294872},
							1
						}
					};
				};
			};
		};
	};
	class HMD_CMPilot: AirplaneHUD
	{
		turret[]={-1};
		class Draw
		{
			alpha="user3";
			color[]=
			{
				"user0",
				"user1",
				"user2"
			};
			condition="(1 - (cameraHeadingDiffY<=-19) + (abs(cameraHeadingDiffX)>=24))*on";
			class CMName
			{
				type="text";
				source="cmweapon";
				sourceScale=1;
				align="left";
				scale=1;
				pos[]=
				{
					{0.86900002,0.84899998},
					1
				};
				right[]=
				{
					{0.91900003,0.84899998},
					1
				};
				down[]=
				{
					{0.86900002,0.884},
					1
				};
			};
			class CMCount
			{
				type="text";
				source="cmammo";
				sourceScale=1;
				align="left";
				scale=1;
				pos[]=
				{
					{0.97899997,0.84899998},
					1
				};
				right[]=
				{
					{1.029,0.84899998},
					1
				};
				down[]=
				{
					{0.97899997,0.884},
					1
				};
			};
		};
	};
};
numberPhysicalWheels=3;
class TextureSources
{
	class Black
	{
		displayName="$STR_A3_TEXTURESOURCES_BLACK0";
		author="$STR_A3_Bohemia_Interactive";
		textures[]=
		{
			"A3\Air_F_Beta\Heli_Attack_02\Data\Heli_Attack_02_body1_black_CO.paa",
			"A3\Air_F_Beta\Heli_Attack_02\Data\Heli_Attack_02_body2_black_CO.paa"
		};
		factions[]=
		{
			"OPF_F"
		};
	};
	class Opfor
	{
		displayName="$STR_A3_TEXTURESOURCES_OPFOR0";
		author="$STR_A3_Bohemia_Interactive";
		textures[]=
		{
			"A3\Air_F_Beta\Heli_Attack_02\Data\Heli_Attack_02_body1_CO.paa",
			"A3\Air_F_Beta\Heli_Attack_02\Data\Heli_Attack_02_body2_CO.paa"
		};
		factions[]=
		{
			"OPF_F"
		};
	};
};
};
class Heli_Attack_02_dynamicLoadout_base_F: Heli_Attack_02_base_F
{
author="$STR_A3_Bohemia_Interactive";
_generalMacro="Heli_Attack_02_dynamicLoadout_base_F";
class Turrets: Turrets
{
	class MainTurret: MainTurret
	{
		weapons[]=
		{
			"gatling_30mm",
			"Laserdesignator_mounted"
		};
		magazines[]=
		{
			"250Rnd_30mm_HE_shells_Tracer_Green",
			"250Rnd_30mm_APDS_shells_Tracer_Green",
			"Laserbatteries"
		};
	};
};
class Components: Components
{
	class TransportPylonsComponent
	{
		uiPicture="\A3\Air_F_Beta\Heli_Attack_02\Data\UI\Heli_Attack_02_3DEN_CA.paa";
		class Pylons
		{
			class PylonLeft1
			{
				attachment="PylonRack_4Rnd_LG_scalpel";
				priority=5;
				hardpoints[]=
				{
					"O_MISSILE_PYLON",
					"O_BOMB_PYLON_HELI",
					"UNI_SCALPEL",
					"20MM_TWIN_CANNON"
				};
				turret[]={0};
				UIposition[]={0.059999999,0.40000001};
			};
			class PylonLeft2: PylonLeft1
			{
				attachment="PylonRack_19Rnd_Rocket_Skyfire";
				priority=4;
				hardpoints[]=
				{
					"O_MISSILE_PYLON",
					"O_BOMB_PYLON_HELI",
					"UNI_SCALPEL",
					"20MM_TWIN_CANNON"
				};
				UIposition[]={0.079999998,0.34999999};
			};
			class PylonRight2: PylonLeft2
			{
				mirroredMissilePos=2;
				UIposition[]={0.56999999,0.34999999};
			};
			class PylonRight1: PylonLeft1
			{
				mirroredMissilePos=1;
				UIposition[]={0.58999997,0.40000001};
			};
		};
		class Presets
		{
			class Empty
			{
				displayName="$STR_empty";
				attachment[]={};
			};
			class Default
			{
				displayName="$STR_vehicle_default";
				attachment[]=
				{
					"PylonRack_4Rnd_LG_scalpel",
					"PylonRack_19Rnd_Rocket_Skyfire",
					"PylonRack_19Rnd_Rocket_Skyfire",
					"PylonRack_4Rnd_LG_scalpel"
				};
			};
			class AT
			{
				displayName="$STR_A3_cfgmagazines_titan_at_dns";
				attachment[]=
				{
					"PylonRack_4Rnd_LG_scalpel",
					"PylonRack_4Rnd_LG_scalpel",
					"PylonRack_4Rnd_LG_scalpel",
					"PylonRack_4Rnd_LG_scalpel"
				};
			};
			class HAT
			{
				displayName="$STR_A3_Heavy_AT_preset_displayName";
				attachment[]=
				{
					"PylonRack_4Rnd_LG_scalpel",
					"PylonRack_1Rnd_Missile_AGM_01_F",
					"PylonRack_1Rnd_Missile_AGM_01_F",
					"PylonRack_4Rnd_LG_scalpel"
				};
			};
			class CAS
			{
				displayName="$STR_A3_CAS_PRESET_DISPLAYNAME";
				attachment[]=
				{
					"PylonRack_19Rnd_Rocket_Skyfire",
					"PylonMissile_1Rnd_Bomb_03_F",
					"PylonMissile_1Rnd_Bomb_03_F",
					"PylonRack_19Rnd_Rocket_Skyfire"
				};
			};
		};
	};
};