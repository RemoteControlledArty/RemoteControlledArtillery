defaultUserMFDvalues[]={0.15000001,1,0.15000001,0.69999999};
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
		helmetPosition[]={-0.045000002,0.045000002,0.1};
		helmetRight[]={0.090000004,0,0};
		helmetDown[]={0,-0.090000004,0};
		font="RobotoCondensedLight";
		class Bones
		{
			class PlaneOrientation
			{
				type="fixed";
				pos[]={0.5,0.5};
			};
			class WeaponAim
			{
				type="vector";
				source="weapon";
				pos0[]={0.5,0.5};
				pos10[]={0.69700003,0.69499999};
			};
			class Velocity
			{
				type="vector";
				source="velocityToView";
				pos0[]={0.5,0.5};
				pos10[]={0.69700003,0.69499999};
			};
			class ForwardVec
			{
				type="vector";
				source="forward";
				pos0[]={0,0};
				pos10[]={0.197,0.19499999};
			};
			class HorizonBank2
			{
				type="rotational";
				source="HorizonBank";
				center[]={0.5,0.5};
				min=-6.2831898;
				max=6.2831898;
				minAngle=-360;
				maxAngle=360;
				aspectRatio=0.98984802;
			};
			class HorizonDive
			{
				source="horizonDive";
				type="linear";
				min=-1;
				max=1;
				minPos[]={0.5,1.75};
				maxPos[]={0.5,-0.75};
			};
			class SliderAltitudeSource
			{
				type="linear";
				source="altitudeAGL";
				min=0;
				max=50;
				sourceOffset=-2;
				minPos[]=
				{
					0.84500003,
					"0.2 + 0 * 0.065"
				};
				maxPos[]=
				{
					0.84500003,
					"0.2 + 5 * 0.065"
				};
			};
			class SliderSpeedSource
			{
				type="linear";
				source="speed";
				min=0;
				max=138.88901;
				minPos[]={0.255,0.2};
				maxPos[]={0.255,0.52499998};
			};
			class SliderVSpeedSource
			{
				type="linear";
				source="vspeed";
				min=-30;
				max=30;
				minPos[]=
				{
					0.89499998,
					"0.6 + 0 * 0.04"
				};
				maxPos[]=
				{
					0.89499998,
					"0.6 + 6 * 0.04"
				};
			};
			class ImpactPoint
			{
				type="vector";
				source="ImpactPointToView";
				pos0[]={0.5,0.5};
				pos10[]={0.69700003,0.69499999};
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
				pos10[]={0.69700003,0.69499999};
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
				aspectRatio=0.98984802;
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
			clipTL[]={0,0};
			clipBR[]={1,1};
			class PlaneHeading
			{
				width=4;
				class Vector
				{
					type="line";
					width=2;
					points[]=
					{
						
						{
							"PlaneOrientation",
							{0,0},
							1
						},
						
						{
							"Velocity",
							{0,0},
							1
						},
						{}
					};
				};
			};
			class Horizont
			{
				clipTL[]={0.25,0.25};
				clipBR[]={0.75,0.75};
				width=4;
				class Dimmed
				{
					width=4;
					class Level00
					{
						type="line";
						width=4;
						points[]=
						{
							
							{
								"HorizonDive",
								{-0.17,0},
								1
							},
							
							{
								"HorizonDive",
								{-0.079999998,0},
								1
							},
							{},
							
							{
								"HorizonDive",
								{-0.0049999999,0},
								1
							},
							
							{
								"HorizonDive",
								{0.0049999999,0},
								1
							},
							{},
							
							{
								"HorizonDive",
								{0.079999998,0},
								1
							},
							
							{
								"HorizonDive",
								{0.17,0},
								1
							}
						};
					};
					class Level2M10: Level00
					{
						type="line";
						points[]=
						{
							
							{
								"HorizonDive",
								
								{
									-0.17,
									"-0.195 / 10 * 10 * 3/3"
								},
								1
							},
							
							{
								"HorizonDive",
								
								{
									-0.079999998,
									"-0.195 / 10 * 10 * 3/3"
								},
								1
							},
							{},
							
							{
								"HorizonDive",
								
								{
									0.079999998,
									"-0.195 / 10 * 10 * 3/3"
								},
								1
							},
							
							{
								"HorizonDive",
								
								{
									0.17,
									"-0.195 / 10 * 10 * 3/3"
								},
								1
							}
						};
					};
					class VALM2_1_10
					{
						type="text";
						source="static";
						text=10;
						align="center";
						scale=1;
						sourceScale=1;
						pos[]=
						{
							"HorizonDive",
							
							{
								0.090000004,
								"0.013-0.015 * 3/3 - 0.195 / 10 * 10 * 3/3"
							},
							1
						};
						right[]=
						{
							"HorizonDive",
							
							{
								"0.09 + 0.05 * 3/3",
								"0.013-0.015 * 3/3 - 0.195 / 10 * 10 * 3/3"
							},
							1
						};
						down[]=
						{
							"HorizonDive",
							
							{
								0.090000004,
								"0.013+0.015 * 3/3 - 0.195 / 10 * 10 * 3/3"
							},
							1
						};
					};
					class VALM2_2_10: VALM2_1_10
					{
						pos[]=
						{
							"HorizonDive",
							
							{
								-0.090000004,
								"0.013-0.015 * 3/3 - 0.195 / 10 * 10 * 3/3"
							},
							1
						};
						right[]=
						{
							"HorizonDive",
							
							{
								"-0.09 + 0.05 * 3/3",
								"0.013-0.015 * 3/3 - 0.195 / 10 * 10 * 3/3"
							},
							1
						};
						down[]=
						{
							"HorizonDive",
							
							{
								-0.090000004,
								"0.013+0.015 * 3/3 - 0.195 / 10 * 10 * 3/3"
							},
							1
						};
					};
					class Level2P10: Level00
					{
						type="line";
						points[]=
						{
							
							{
								"HorizonDive",
								
								{
									-0.17,
									"+0.195 / 10 * 10 * 3/3"
								},
								1
							},
							
							{
								"HorizonDive",
								
								{
									-0.079999998,
									"+0.195 / 10 * 10 * 3/3"
								},
								1
							},
							{},
							
							{
								"HorizonDive",
								
								{
									0.079999998,
									"+0.195 / 10 * 10 * 3/3"
								},
								1
							},
							
							{
								"HorizonDive",
								
								{
									0.17,
									"+0.195 / 10 * 10 * 3/3"
								},
								1
							}
						};
					};
					class VALP2_1_10
					{
						type="text";
						source="static";
						text=-10;
						align="center";
						scale=1;
						sourceScale=1;
						pos[]=
						{
							"HorizonDive",
							
							{
								0.090000004,
								"0.013-0.015 * 3/3 + 0.195 / 10 * 10 * 3/3"
							},
							1
						};
						right[]=
						{
							"HorizonDive",
							
							{
								"0.09 + 0.05 * 3/3",
								"0.013-0.015 * 3/3 + 0.195 / 10 * 10 * 3/3"
							},
							1
						};
						down[]=
						{
							"HorizonDive",
							
							{
								0.090000004,
								"0.013+0.015 * 3/3 + 0.195 / 10 * 10 * 3/3"
							},
							1
						};
					};
					class VALP2_2_10: VALP2_1_10
					{
						pos[]=
						{
							"HorizonDive",
							
							{
								-0.090000004,
								"0.013-0.015 * 3/3 + 0.195 / 10 * 10 * 3/3"
							},
							1
						};
						right[]=
						{
							"HorizonDive",
							
							{
								"-0.09 + 0.05 * 3/3",
								"0.013-0.015 * 3/3 + 0.195 / 10 * 10 * 3/3"
							},
							1
						};
						down[]=
						{
							"HorizonDive",
							
							{
								-0.090000004,
								"0.013+0.015 * 3/3 + 0.195 / 10 * 10 * 3/3"
							},
							1
						};
					};
					class Level2M20: Level00
					{
						type="line";
						points[]=
						{
							
							{
								"HorizonDive",
								
								{
									-0.17,
									"-0.195 / 10 * 20 * 3/3"
								},
								1
							},
							
							{
								"HorizonDive",
								
								{
									-0.079999998,
									"-0.195 / 10 * 20 * 3/3"
								},
								1
							},
							{},
							
							{
								"HorizonDive",
								
								{
									0.079999998,
									"-0.195 / 10 * 20 * 3/3"
								},
								1
							},
							
							{
								"HorizonDive",
								
								{
									0.17,
									"-0.195 / 10 * 20 * 3/3"
								},
								1
							}
						};
					};
					class VALM2_1_20
					{
						type="text";
						source="static";
						text=20;
						align="center";
						scale=1;
						sourceScale=1;
						pos[]=
						{
							"HorizonDive",
							
							{
								0.090000004,
								"0.013-0.015 * 3/3 - 0.195 / 10 * 20 * 3/3"
							},
							1
						};
						right[]=
						{
							"HorizonDive",
							
							{
								"0.09 + 0.05 * 3/3",
								"0.013-0.015 * 3/3 - 0.195 / 10 * 20 * 3/3"
							},
							1
						};
						down[]=
						{
							"HorizonDive",
							
							{
								0.090000004,
								"0.013+0.015 * 3/3 - 0.195 / 10 * 20 * 3/3"
							},
							1
						};
					};
					class VALM2_2_20: VALM2_1_20
					{
						pos[]=
						{
							"HorizonDive",
							
							{
								-0.090000004,
								"0.013-0.015 * 3/3 - 0.195 / 10 * 20 * 3/3"
							},
							1
						};
						right[]=
						{
							"HorizonDive",
							
							{
								"-0.09 + 0.05 * 3/3",
								"0.013-0.015 * 3/3 - 0.195 / 10 * 20 * 3/3"
							},
							1
						};
						down[]=
						{
							"HorizonDive",
							
							{
								-0.090000004,
								"0.013+0.015 * 3/3 - 0.195 / 10 * 20 * 3/3"
							},
							1
						};
					};
					class Level2P20: Level00
					{
						type="line";
						points[]=
						{
							
							{
								"HorizonDive",
								
								{
									-0.17,
									"+0.195 / 10 * 20 * 3/3"
								},
								1
							},
							
							{
								"HorizonDive",
								
								{
									-0.079999998,
									"+0.195 / 10 * 20 * 3/3"
								},
								1
							},
							{},
							
							{
								"HorizonDive",
								
								{
									0.079999998,
									"+0.195 / 10 * 20 * 3/3"
								},
								1
							},
							
							{
								"HorizonDive",
								
								{
									0.17,
									"+0.195 / 10 * 20 * 3/3"
								},
								1
							}
						};
					};
					class VALP2_1_20
					{
						type="text";
						source="static";
						text=-20;
						align="center";
						scale=1;
						sourceScale=1;
						pos[]=
						{
							"HorizonDive",
							
							{
								0.090000004,
								"0.013-0.015 * 3/3 + 0.195 / 10 * 20 * 3/3"
							},
							1
						};
						right[]=
						{
							"HorizonDive",
							
							{
								"0.09 + 0.05 * 3/3",
								"0.013-0.015 * 3/3 + 0.195 / 10 * 20 * 3/3"
							},
							1
						};
						down[]=
						{
							"HorizonDive",
							
							{
								0.090000004,
								"0.013+0.015 * 3/3 + 0.195 / 10 * 20 * 3/3"
							},
							1
						};
					};
					class VALP2_2_20: VALP2_1_20
					{
						pos[]=
						{
							"HorizonDive",
							
							{
								-0.090000004,
								"0.013-0.015 * 3/3 + 0.195 / 10 * 20 * 3/3"
							},
							1
						};
						right[]=
						{
							"HorizonDive",
							
							{
								"-0.09 + 0.05 * 3/3",
								"0.013-0.015 * 3/3 + 0.195 / 10 * 20 * 3/3"
							},
							1
						};
						down[]=
						{
							"HorizonDive",
							
							{
								-0.090000004,
								"0.013+0.015 * 3/3 + 0.195 / 10 * 20 * 3/3"
							},
							1
						};
					};
					class Level2M30: Level00
					{
						type="line";
						points[]=
						{
							
							{
								"HorizonDive",
								
								{
									-0.17,
									"-0.195 / 10 * 30 * 3/3"
								},
								1
							},
							
							{
								"HorizonDive",
								
								{
									-0.079999998,
									"-0.195 / 10 * 30 * 3/3"
								},
								1
							},
							{},
							
							{
								"HorizonDive",
								
								{
									0.079999998,
									"-0.195 / 10 * 30 * 3/3"
								},
								1
							},
							
							{
								"HorizonDive",
								
								{
									0.17,
									"-0.195 / 10 * 30 * 3/3"
								},
								1
							}
						};
					};
					class VALM2_1_30
					{
						type="text";
						source="static";
						text=30;
						align="center";
						scale=1;
						sourceScale=1;
						pos[]=
						{
							"HorizonDive",
							
							{
								0.090000004,
								"0.013-0.015 * 3/3 - 0.195 / 10 * 30 * 3/3"
							},
							1
						};
						right[]=
						{
							"HorizonDive",
							
							{
								"0.09 + 0.05 * 3/3",
								"0.013-0.015 * 3/3 - 0.195 / 10 * 30 * 3/3"
							},
							1
						};
						down[]=
						{
							"HorizonDive",
							
							{
								0.090000004,
								"0.013+0.015 * 3/3 - 0.195 / 10 * 30 * 3/3"
							},
							1
						};
					};
					class VALM2_2_30: VALM2_1_30
					{
						pos[]=
						{
							"HorizonDive",
							
							{
								-0.090000004,
								"0.013-0.015 * 3/3 - 0.195 / 10 * 30 * 3/3"
							},
							1
						};
						right[]=
						{
							"HorizonDive",
							
							{
								"-0.09 + 0.05 * 3/3",
								"0.013-0.015 * 3/3 - 0.195 / 10 * 30 * 3/3"
							},
							1
						};
						down[]=
						{
							"HorizonDive",
							
							{
								-0.090000004,
								"0.013+0.015 * 3/3 - 0.195 / 10 * 30 * 3/3"
							},
							1
						};
					};
					class Level2P30: Level00
					{
						type="line";
						points[]=
						{
							
							{
								"HorizonDive",
								
								{
									-0.17,
									"+0.195 / 10 * 30 * 3/3"
								},
								1
							},
							
							{
								"HorizonDive",
								
								{
									-0.079999998,
									"+0.195 / 10 * 30 * 3/3"
								},
								1
							},
							{},
							
							{
								"HorizonDive",
								
								{
									0.079999998,
									"+0.195 / 10 * 30 * 3/3"
								},
								1
							},
							
							{
								"HorizonDive",
								
								{
									0.17,
									"+0.195 / 10 * 30 * 3/3"
								},
								1
							}
						};
					};
					class VALP2_1_30
					{
						type="text";
						source="static";
						text=-30;
						align="center";
						scale=1;
						sourceScale=1;
						pos[]=
						{
							"HorizonDive",
							
							{
								0.090000004,
								"0.013-0.015 * 3/3 + 0.195 / 10 * 30 * 3/3"
							},
							1
						};
						right[]=
						{
							"HorizonDive",
							
							{
								"0.09 + 0.05 * 3/3",
								"0.013-0.015 * 3/3 + 0.195 / 10 * 30 * 3/3"
							},
							1
						};
						down[]=
						{
							"HorizonDive",
							
							{
								0.090000004,
								"0.013+0.015 * 3/3 + 0.195 / 10 * 30 * 3/3"
							},
							1
						};
					};
					class VALP2_2_30: VALP2_1_30
					{
						pos[]=
						{
							"HorizonDive",
							
							{
								-0.090000004,
								"0.013-0.015 * 3/3 + 0.195 / 10 * 30 * 3/3"
							},
							1
						};
						right[]=
						{
							"HorizonDive",
							
							{
								"-0.09 + 0.05 * 3/3",
								"0.013-0.015 * 3/3 + 0.195 / 10 * 30 * 3/3"
							},
							1
						};
						down[]=
						{
							"HorizonDive",
							
							{
								-0.090000004,
								"0.013+0.015 * 3/3 + 0.195 / 10 * 30 * 3/3"
							},
							1
						};
					};
					class Level2M40: Level00
					{
						type="line";
						points[]=
						{
							
							{
								"HorizonDive",
								
								{
									-0.17,
									"-0.195 / 10 * 40 * 3/3"
								},
								1
							},
							
							{
								"HorizonDive",
								
								{
									-0.079999998,
									"-0.195 / 10 * 40 * 3/3"
								},
								1
							},
							{},
							
							{
								"HorizonDive",
								
								{
									0.079999998,
									"-0.195 / 10 * 40 * 3/3"
								},
								1
							},
							
							{
								"HorizonDive",
								
								{
									0.17,
									"-0.195 / 10 * 40 * 3/3"
								},
								1
							}
						};
					};
					class VALM2_1_40
					{
						type="text";
						source="static";
						text=40;
						align="center";
						scale=1;
						sourceScale=1;
						pos[]=
						{
							"HorizonDive",
							
							{
								0.090000004,
								"0.013-0.015 * 3/3 - 0.195 / 10 * 40 * 3/3"
							},
							1
						};
						right[]=
						{
							"HorizonDive",
							
							{
								"0.09 + 0.05 * 3/3",
								"0.013-0.015 * 3/3 - 0.195 / 10 * 40 * 3/3"
							},
							1
						};
						down[]=
						{
							"HorizonDive",
							
							{
								0.090000004,
								"0.013+0.015 * 3/3 - 0.195 / 10 * 40 * 3/3"
							},
							1
						};
					};
					class VALM2_2_40: VALM2_1_40
					{
						pos[]=
						{
							"HorizonDive",
							
							{
								-0.090000004,
								"0.013-0.015 * 3/3 - 0.195 / 10 * 40 * 3/3"
							},
							1
						};
						right[]=
						{
							"HorizonDive",
							
							{
								"-0.09 + 0.05 * 3/3",
								"0.013-0.015 * 3/3 - 0.195 / 10 * 40 * 3/3"
							},
							1
						};
						down[]=
						{
							"HorizonDive",
							
							{
								-0.090000004,
								"0.013+0.015 * 3/3 - 0.195 / 10 * 40 * 3/3"
							},
							1
						};
					};
					class Level2P40: Level00
					{
						type="line";
						points[]=
						{
							
							{
								"HorizonDive",
								
								{
									-0.17,
									"+0.195 / 10 * 40 * 3/3"
								},
								1
							},
							
							{
								"HorizonDive",
								
								{
									-0.079999998,
									"+0.195 / 10 * 40 * 3/3"
								},
								1
							},
							{},
							
							{
								"HorizonDive",
								
								{
									0.079999998,
									"+0.195 / 10 * 40 * 3/3"
								},
								1
							},
							
							{
								"HorizonDive",
								
								{
									0.17,
									"+0.195 / 10 * 40 * 3/3"
								},
								1
							}
						};
					};
					class VALP2_1_40
					{
						type="text";
						source="static";
						text=-40;
						align="center";
						scale=1;
						sourceScale=1;
						pos[]=
						{
							"HorizonDive",
							
							{
								0.090000004,
								"0.013-0.015 * 3/3 + 0.195 / 10 * 40 * 3/3"
							},
							1
						};
						right[]=
						{
							"HorizonDive",
							
							{
								"0.09 + 0.05 * 3/3",
								"0.013-0.015 * 3/3 + 0.195 / 10 * 40 * 3/3"
							},
							1
						};
						down[]=
						{
							"HorizonDive",
							
							{
								0.090000004,
								"0.013+0.015 * 3/3 + 0.195 / 10 * 40 * 3/3"
							},
							1
						};
					};
					class VALP2_2_40: VALP2_1_40
					{
						pos[]=
						{
							"HorizonDive",
							
							{
								-0.090000004,
								"0.013-0.015 * 3/3 + 0.195 / 10 * 40 * 3/3"
							},
							1
						};
						right[]=
						{
							"HorizonDive",
							
							{
								"-0.09 + 0.05 * 3/3",
								"0.013-0.015 * 3/3 + 0.195 / 10 * 40 * 3/3"
							},
							1
						};
						down[]=
						{
							"HorizonDive",
							
							{
								-0.090000004,
								"0.013+0.015 * 3/3 + 0.195 / 10 * 40 * 3/3"
							},
							1
						};
					};
					class Level2M50: Level00
					{
						type="line";
						points[]=
						{
							
							{
								"HorizonDive",
								
								{
									-0.17,
									"-0.195 / 10 * 50 * 3/3"
								},
								1
							},
							
							{
								"HorizonDive",
								
								{
									-0.079999998,
									"-0.195 / 10 * 50 * 3/3"
								},
								1
							},
							{},
							
							{
								"HorizonDive",
								
								{
									0.079999998,
									"-0.195 / 10 * 50 * 3/3"
								},
								1
							},
							
							{
								"HorizonDive",
								
								{
									0.17,
									"-0.195 / 10 * 50 * 3/3"
								},
								1
							}
						};
					};
					class VALM2_1_50
					{
						type="text";
						source="static";
						text=50;
						align="center";
						scale=1;
						sourceScale=1;
						pos[]=
						{
							"HorizonDive",
							
							{
								0.090000004,
								"0.013-0.015 * 3/3 - 0.195 / 10 * 50 * 3/3"
							},
							1
						};
						right[]=
						{
							"HorizonDive",
							
							{
								"0.09 + 0.05 * 3/3",
								"0.013-0.015 * 3/3 - 0.195 / 10 * 50 * 3/3"
							},
							1
						};
						down[]=
						{
							"HorizonDive",
							
							{
								0.090000004,
								"0.013+0.015 * 3/3 - 0.195 / 10 * 50 * 3/3"
							},
							1
						};
					};
					class VALM2_2_50: VALM2_1_50
					{
						pos[]=
						{
							"HorizonDive",
							
							{
								-0.090000004,
								"0.013-0.015 * 3/3 - 0.195 / 10 * 50 * 3/3"
							},
							1
						};
						right[]=
						{
							"HorizonDive",
							
							{
								"-0.09 + 0.05 * 3/3",
								"0.013-0.015 * 3/3 - 0.195 / 10 * 50 * 3/3"
							},
							1
						};
						down[]=
						{
							"HorizonDive",
							
							{
								-0.090000004,
								"0.013+0.015 * 3/3 - 0.195 / 10 * 50 * 3/3"
							},
							1
						};
					};
					class Level2P50: Level00
					{
						type="line";
						points[]=
						{
							
							{
								"HorizonDive",
								
								{
									-0.17,
									"+0.195 / 10 * 50 * 3/3"
								},
								1
							},
							
							{
								"HorizonDive",
								
								{
									-0.079999998,
									"+0.195 / 10 * 50 * 3/3"
								},
								1
							},
							{},
							
							{
								"HorizonDive",
								
								{
									0.079999998,
									"+0.195 / 10 * 50 * 3/3"
								},
								1
							},
							
							{
								"HorizonDive",
								
								{
									0.17,
									"+0.195 / 10 * 50 * 3/3"
								},
								1
							}
						};
					};
					class VALP2_1_50
					{
						type="text";
						source="static";
						text=-50;
						align="center";
						scale=1;
						sourceScale=1;
						pos[]=
						{
							"HorizonDive",
							
							{
								0.090000004,
								"0.013-0.015 * 3/3 + 0.195 / 10 * 50 * 3/3"
							},
							1
						};
						right[]=
						{
							"HorizonDive",
							
							{
								"0.09 + 0.05 * 3/3",
								"0.013-0.015 * 3/3 + 0.195 / 10 * 50 * 3/3"
							},
							1
						};
						down[]=
						{
							"HorizonDive",
							
							{
								0.090000004,
								"0.013+0.015 * 3/3 + 0.195 / 10 * 50 * 3/3"
							},
							1
						};
					};
					class VALP2_2_50: VALP2_1_50
					{
						pos[]=
						{
							"HorizonDive",
							
							{
								-0.090000004,
								"0.013-0.015 * 3/3 + 0.195 / 10 * 50 * 3/3"
							},
							1
						};
						right[]=
						{
							"HorizonDive",
							
							{
								"-0.09 + 0.05 * 3/3",
								"0.013-0.015 * 3/3 + 0.195 / 10 * 50 * 3/3"
							},
							1
						};
						down[]=
						{
							"HorizonDive",
							
							{
								-0.090000004,
								"0.013+0.015 * 3/3 + 0.195 / 10 * 50 * 3/3"
							},
							1
						};
					};
				};
			};
			class MGun
			{
				condition="-2+(mgun+rocket)*ImpactDistance";
				width=4;
				class Circle
				{
					type="line";
					width=4;
					points[]=
					{
						
						{
							"ImpactPoint",
							{0,-0.0277157},
							1
						},
						
						{
							"ImpactPoint",
							{0,-0.034644701},
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
				class Cross
				{
					type="line";
					width=3;
					points[]=
					{
						
						{
							"ImpactPoint",
							{0,-0.029695399},
							1
						},
						
						{
							"ImpactPoint",
							{0,-0.039593901},
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
				class Circle2
				{
					type="line";
					width=3;
					points[]={};
				};
				class Circle_Min_Range
				{
					type="line";
					width=3;
					points[]=
					{
						
						{
							"ImpactPoint",
							{0,-0.029695399},
							1
						},
						
						{
							"ImpactPoint",
							{0.0052080001,-0.029244101},
							1
						},
						
						{
							"ImpactPoint",
							{0.01026,-0.027904799},
							1
						},
						
						{
							"ImpactPoint",
							{0.015,-0.0257162},
							1
						},
						
						{
							"ImpactPoint",
							{0.019284001,-0.022746701},
							1
						},
						
						{
							"ImpactPoint",
							{0.022980001,-0.019088199},
							1
						},
						
						{
							"ImpactPoint",
							{0.025979999,-0.0148477},
							1
						},
						
						{
							"ImpactPoint",
							{0.028191,-0.0101558},
							1
						},
						
						{
							"ImpactPoint",
							{0.029544,-0.0051551298},
							1
						},
						
						{
							"ImpactPoint",
							{0.029999999,0},
							1
						},
						
						{
							"ImpactPoint",
							{0.029544,0.0051551298},
							1
						},
						
						{
							"ImpactPoint",
							{0.028191,0.0101558},
							1
						},
						
						{
							"ImpactPoint",
							{0.025979999,0.0148477},
							1
						},
						
						{
							"ImpactPoint",
							{0.022980001,0.019088199},
							1
						},
						
						{
							"ImpactPoint",
							{0.019284001,0.022746701},
							1
						},
						
						{
							"ImpactPoint",
							{0.015,0.0257162},
							1
						},
						
						{
							"ImpactPoint",
							{0.01026,0.027904799},
							1
						},
						
						{
							"ImpactPoint",
							{0.0052080001,0.029244101},
							1
						},
						
						{
							"ImpactPoint",
							{0,0.029695399},
							1
						},
						
						{
							"ImpactPoint",
							{-0.0052080001,0.029244101},
							1
						},
						
						{
							"ImpactPoint",
							{-0.01026,0.027904799},
							1
						},
						
						{
							"ImpactPoint",
							{-0.015,0.0257162},
							1
						},
						
						{
							"ImpactPoint",
							{-0.019284001,0.022746701},
							1
						},
						
						{
							"ImpactPoint",
							{-0.022980001,0.019088199},
							1
						},
						
						{
							"ImpactPoint",
							{-0.025979999,0.0148477},
							1
						},
						
						{
							"ImpactPoint",
							{-0.028191,0.0101558},
							1
						},
						
						{
							"ImpactPoint",
							{-0.029544,0.0051551298},
							1
						},
						
						{
							"ImpactPoint",
							{-0.029999999,0},
							1
						},
						
						{
							"ImpactPoint",
							{-0.029544,-0.0051551298},
							1
						},
						
						{
							"ImpactPoint",
							{-0.028191,-0.0101558},
							1
						},
						
						{
							"ImpactPoint",
							{-0.025979999,-0.0148477},
							1
						},
						
						{
							"ImpactPoint",
							{-0.022980001,-0.019088199},
							1
						},
						
						{
							"ImpactPoint",
							{-0.019284001,-0.022746701},
							1
						},
						
						{
							"ImpactPoint",
							{-0.015,-0.0257162},
							1
						},
						
						{
							"ImpactPoint",
							{-0.01026,-0.027904799},
							1
						},
						
						{
							"ImpactPoint",
							{-0.0052080001,-0.029244101},
							1
						},
						
						{
							"ImpactPoint",
							{0,-0.029695399},
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
			class Missile
			{
				condition="missile";
				width=0.050000001;
				class Circle
				{
					type="line";
					width=4;
					points[]=
					{
						
						{
							"ForwardVec",
							1,
							"WeaponAim",
							{0,-0.069289297},
							1
						},
						
						{
							"ForwardVec",
							1,
							"WeaponAim",
							{0.012152,-0.068236098},
							1
						},
						
						{
							"ForwardVec",
							1,
							"WeaponAim",
							{0.023940001,-0.065111198},
							1
						},
						
						{
							"ForwardVec",
							1,
							"WeaponAim",
							{0.035,-0.060004599},
							1
						},
						
						{
							"ForwardVec",
							1,
							"WeaponAim",
							{0.044996001,-0.0530756},
							1
						},
						
						{
							"ForwardVec",
							1,
							"WeaponAim",
							{0.053619999,-0.044539198},
							1
						},
						
						{
							"ForwardVec",
							1,
							"WeaponAim",
							{0.060619999,-0.034644701},
							1
						},
						
						{
							"ForwardVec",
							1,
							"WeaponAim",
							{0.065779001,-0.023697},
							1
						},
						
						{
							"ForwardVec",
							1,
							"WeaponAim",
							{0.068935998,-0.0120286},
							1
						},
						
						{
							"ForwardVec",
							1,
							"WeaponAim",
							{0.07,0},
							1
						},
						
						{
							"ForwardVec",
							1,
							"WeaponAim",
							{0.068935998,0.0120286},
							1
						},
						
						{
							"ForwardVec",
							1,
							"WeaponAim",
							{0.065779001,0.023697},
							1
						},
						
						{
							"ForwardVec",
							1,
							"WeaponAim",
							{0.060619999,0.034644701},
							1
						},
						
						{
							"ForwardVec",
							1,
							"WeaponAim",
							{0.053619999,0.044539198},
							1
						},
						
						{
							"ForwardVec",
							1,
							"WeaponAim",
							{0.044996001,0.0530756},
							1
						},
						
						{
							"ForwardVec",
							1,
							"WeaponAim",
							{0.035,0.060004599},
							1
						},
						
						{
							"ForwardVec",
							1,
							"WeaponAim",
							{0.023940001,0.065111198},
							1
						},
						
						{
							"ForwardVec",
							1,
							"WeaponAim",
							{0.012152,0.068236098},
							1
						},
						
						{
							"ForwardVec",
							1,
							"WeaponAim",
							{0,0.069289297},
							1
						},
						
						{
							"ForwardVec",
							1,
							"WeaponAim",
							{-0.012152,0.068236098},
							1
						},
						
						{
							"ForwardVec",
							1,
							"WeaponAim",
							{-0.023940001,0.065111198},
							1
						},
						
						{
							"ForwardVec",
							1,
							"WeaponAim",
							{-0.035,0.060004599},
							1
						},
						
						{
							"ForwardVec",
							1,
							"WeaponAim",
							{-0.044996001,0.0530756},
							1
						},
						
						{
							"ForwardVec",
							1,
							"WeaponAim",
							{-0.053619999,0.044539198},
							1
						},
						
						{
							"ForwardVec",
							1,
							"WeaponAim",
							{-0.060619999,0.034644701},
							1
						},
						
						{
							"ForwardVec",
							1,
							"WeaponAim",
							{-0.065779001,0.023697},
							1
						},
						
						{
							"ForwardVec",
							1,
							"WeaponAim",
							{-0.068935998,0.0120286},
							1
						},
						
						{
							"ForwardVec",
							1,
							"WeaponAim",
							{-0.07,0},
							1
						},
						
						{
							"ForwardVec",
							1,
							"WeaponAim",
							{-0.068935998,-0.0120286},
							1
						},
						
						{
							"ForwardVec",
							1,
							"WeaponAim",
							{-0.065779001,-0.023697},
							1
						},
						
						{
							"ForwardVec",
							1,
							"WeaponAim",
							{-0.060619999,-0.034644701},
							1
						},
						
						{
							"ForwardVec",
							1,
							"WeaponAim",
							{-0.053619999,-0.044539198},
							1
						},
						
						{
							"ForwardVec",
							1,
							"WeaponAim",
							{-0.044996001,-0.0530756},
							1
						},
						
						{
							"ForwardVec",
							1,
							"WeaponAim",
							{-0.035,-0.060004599},
							1
						},
						
						{
							"ForwardVec",
							1,
							"WeaponAim",
							{-0.023940001,-0.065111198},
							1
						},
						
						{
							"ForwardVec",
							1,
							"WeaponAim",
							{-0.012152,-0.068236098},
							1
						},
						
						{
							"ForwardVec",
							1,
							"WeaponAim",
							{0,-0.069289297},
							1
						}
					};
				};
			};
			class TargetDiamond
			{
				condition="1-missilelocked";
				blinkingPattern[]={0.30000001,0.30000001};
				blinkingStartsOn=1;
				class shape
				{
					type="line";
					width=2;
					points[]=
					{
						
						{
							"Target",
							1,
							"Limit0109",
							1,
							{0.027740801,0.0054619699},
							1
						},
						
						{
							"Target",
							1,
							"Limit0109",
							1,
							{0.027740801,-0.0054619699},
							1
						},
						{},
						
						{
							"Target",
							1,
							"Limit0109",
							1,
							{0.023517501,-0.0155544},
							1
						},
						
						{
							"Target",
							1,
							"Limit0109",
							1,
							{0.0157139,-0.023278801},
							1
						},
						{},
						
						{
							"Target",
							1,
							"Limit0109",
							1,
							{0.0055179899,-0.0274592},
							1
						},
						
						{
							"Target",
							1,
							"Limit0109",
							1,
							{-0.0055179899,-0.0274592},
							1
						},
						{},
						
						{
							"Target",
							1,
							"Limit0109",
							1,
							{-0.0157139,-0.023278801},
							1
						},
						
						{
							"Target",
							1,
							"Limit0109",
							1,
							{-0.023517501,-0.0155544},
							1
						},
						{},
						
						{
							"Target",
							1,
							"Limit0109",
							1,
							{-0.027740801,-0.0054619601},
							1
						},
						
						{
							"Target",
							1,
							"Limit0109",
							1,
							{-0.027740801,0.0054619801},
							1
						},
						{},
						
						{
							"Target",
							1,
							"Limit0109",
							1,
							{-0.023517501,0.0155544},
							1
						},
						
						{
							"Target",
							1,
							"Limit0109",
							1,
							{-0.0157139,0.023278801},
							1
						},
						{},
						
						{
							"Target",
							1,
							"Limit0109",
							1,
							{-0.0055179801,0.0274592},
							1
						},
						
						{
							"Target",
							1,
							"Limit0109",
							1,
							{0.0055179899,0.0274592},
							1
						},
						{},
						
						{
							"Target",
							1,
							"Limit0109",
							1,
							{0.0157139,0.023278801},
							1
						},
						
						{
							"Target",
							1,
							"Limit0109",
							1,
							{0.023517501,0.0155544},
							1
						},
						{},
						
						{
							"Target",
							1,
							"Limit0109",
							1,
							{0.027740801,0.0054619499},
							1
						},
						
						{
							"Target",
							1,
							"Limit0109",
							1,
							{0.027740801,-0.0054619699},
							1
						},
						{},
						
						{
							"Target",
							1,
							"Limit0109",
							1,
							{0.023517501,-0.0155544},
							1
						},
						
						{
							"Target",
							1,
							"Limit0109",
							1,
							{0.0157139,-0.023278801},
							1
						},
						{},
						
						{
							"Target",
							1,
							"Limit0109",
							1,
							{0.0055179801,-0.0274592},
							1
						},
						
						{
							"Target",
							1,
							"Limit0109",
							1,
							{-0.0055180001,-0.0274592},
							1
						},
						{},
						
						{
							"Target",
							1,
							"Limit0109",
							1,
							{-0.0157139,-0.023278801},
							1
						},
						
						{
							"Target",
							1,
							"Limit0109",
							1,
							{-0.023517501,-0.0155544},
							1
						},
						{},
						{},
						
						{
							"Target",
							1,
							
							{
								"Limit0109",
								-0.02,
								-2.3607599e-010
							},
							1
						},
						
						{
							"Target",
							1,
							
							{
								"Limit0109",
								-0.015,
								-1.7705699e-010
							},
							1
						},
						{},
						
						{
							"Target",
							1,
							
							{
								"Limit0109",
								-1.74846e-009,
								0.019796999
							},
							1
						},
						
						{
							"Target",
							1,
							
							{
								"Limit0109",
								-1.31134e-009,
								0.0148477
							},
							1
						},
						{},
						
						{
							"Target",
							1,
							
							{
								"Limit0109",
								0.02,
								8.6535201e-010
							},
							1
						},
						
						{
							"Target",
							1,
							
							{
								"Limit0109",
								0.015,
								6.4901401e-010
							},
							1
						},
						{},
						
						{
							"Target",
							1,
							
							{
								"Limit0109",
								0,
								-0.019796999
							},
							1
						},
						
						{
							"Target",
							1,
							
							{
								"Limit0109",
								0,
								-0.0148477
							},
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
					width=3;
					points[]=
					{
						
						{
							"Target",
							1,
							"Limit0109",
							{0,-0.019796999},
							1
						},
						
						{
							"Target",
							1,
							"Limit0109",
							{0.0034719999,-0.019495999},
							1
						},
						
						{
							"Target",
							1,
							"Limit0109",
							{0.0068399999,-0.0186032},
							1
						},
						
						{
							"Target",
							1,
							"Limit0109",
							{0.0099999998,-0.017144199},
							1
						},
						
						{
							"Target",
							1,
							"Limit0109",
							{0.012856,-0.0151645},
							1
						},
						
						{
							"Target",
							1,
							"Limit0109",
							{0.01532,-0.0127255},
							1
						},
						
						{
							"Target",
							1,
							"Limit0109",
							{0.01732,-0.00989848},
							1
						},
						
						{
							"Target",
							1,
							"Limit0109",
							{0.018794,-0.0067705601},
							1
						},
						
						{
							"Target",
							1,
							"Limit0109",
							{0.019695999,-0.00343675},
							1
						},
						
						{
							"Target",
							1,
							"Limit0109",
							{0.02,0},
							1
						},
						
						{
							"Target",
							1,
							"Limit0109",
							{0.019695999,0.00343675},
							1
						},
						
						{
							"Target",
							1,
							"Limit0109",
							{0.018794,0.0067705601},
							1
						},
						
						{
							"Target",
							1,
							"Limit0109",
							{0.01732,0.00989848},
							1
						},
						
						{
							"Target",
							1,
							"Limit0109",
							{0.01532,0.0127255},
							1
						},
						
						{
							"Target",
							1,
							"Limit0109",
							{0.012856,0.0151645},
							1
						},
						
						{
							"Target",
							1,
							"Limit0109",
							{0.0099999998,0.017144199},
							1
						},
						
						{
							"Target",
							1,
							"Limit0109",
							{0.0068399999,0.0186032},
							1
						},
						
						{
							"Target",
							1,
							"Limit0109",
							{0.0034719999,0.019495999},
							1
						},
						
						{
							"Target",
							1,
							"Limit0109",
							{0,0.019796999},
							1
						},
						
						{
							"Target",
							1,
							"Limit0109",
							{-0.0034719999,0.019495999},
							1
						},
						
						{
							"Target",
							1,
							"Limit0109",
							{-0.0068399999,0.0186032},
							1
						},
						
						{
							"Target",
							1,
							"Limit0109",
							{-0.0099999998,0.017144199},
							1
						},
						
						{
							"Target",
							1,
							"Limit0109",
							{-0.012856,0.0151645},
							1
						},
						
						{
							"Target",
							1,
							"Limit0109",
							{-0.01532,0.0127255},
							1
						},
						
						{
							"Target",
							1,
							"Limit0109",
							{-0.01732,0.00989848},
							1
						},
						
						{
							"Target",
							1,
							"Limit0109",
							{-0.018794,0.0067705601},
							1
						},
						
						{
							"Target",
							1,
							"Limit0109",
							{-0.019695999,0.00343675},
							1
						},
						
						{
							"Target",
							1,
							"Limit0109",
							{-0.02,0},
							1
						},
						
						{
							"Target",
							1,
							"Limit0109",
							{-0.019695999,-0.00343675},
							1
						},
						
						{
							"Target",
							1,
							"Limit0109",
							{-0.018794,-0.0067705601},
							1
						},
						
						{
							"Target",
							1,
							"Limit0109",
							{-0.01732,-0.00989848},
							1
						},
						
						{
							"Target",
							1,
							"Limit0109",
							{-0.01532,-0.0127255},
							1
						},
						
						{
							"Target",
							1,
							"Limit0109",
							{-0.012856,-0.0151645},
							1
						},
						
						{
							"Target",
							1,
							"Limit0109",
							{-0.0099999998,-0.017144199},
							1
						},
						
						{
							"Target",
							1,
							"Limit0109",
							{-0.0068399999,-0.0186032},
							1
						},
						
						{
							"Target",
							1,
							"Limit0109",
							{-0.0034719999,-0.019495999},
							1
						},
						
						{
							"Target",
							1,
							"Limit0109",
							{0,-0.019796999},
							1
						},
						{},
						
						{
							"Target",
							1,
							
							{
								"Limit0109",
								-0.02,
								-2.3607599e-010
							},
							1
						},
						
						{
							"Target",
							1,
							
							{
								"Limit0109",
								-0.015,
								-1.7705699e-010
							},
							1
						},
						{},
						
						{
							"Target",
							1,
							
							{
								"Limit0109",
								-1.74846e-009,
								0.019796999
							},
							1
						},
						
						{
							"Target",
							1,
							
							{
								"Limit0109",
								-1.31134e-009,
								0.0148477
							},
							1
						},
						{},
						
						{
							"Target",
							1,
							
							{
								"Limit0109",
								0.02,
								8.6535201e-010
							},
							1
						},
						
						{
							"Target",
							1,
							
							{
								"Limit0109",
								0.015,
								6.4901401e-010
							},
							1
						},
						{},
						
						{
							"Target",
							1,
							
							{
								"Limit0109",
								0,
								-0.019796999
							},
							1
						},
						
						{
							"Target",
							1,
							
							{
								"Limit0109",
								0,
								-0.0148477
							},
							1
						}
					};
				};
			};
			class IncomingMissile
			{
				condition="incomingmissile";
				blinkingPattern[]={0.30000001,0.30000001};
				blinkingStartsOn=0;
				class Text
				{
					type="text";
					source="static";
					text="!INCOMING MISSILE!";
					align="center";
					scale=1;
					pos[]=
					{
						{0.48500001,0.217766},
						1
					};
					right[]=
					{
						{0.54500002,0.217766},
						1
					};
					down[]=
					{
						{0.48500001,0.267259},
						1
					};
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
						{0.18000001,0.53500003},
						1
					};
					right[]=
					{
						{0.23,0.53500003},
						1
					};
					down[]=
					{
						{0.18000001,0.56999999},
						1
					};
				};
				class CollectiveText
				{
					type="text";
					source="static";
					text="%";
					align="right";
					scale=1;
					pos[]=
					{
						{0.18000001,0.53500003},
						1
					};
					right[]=
					{
						{0.23,0.53500003},
						1
					};
					down[]=
					{
						{0.18000001,0.56999999},
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
				align="right";
				scale=1;
				pos[]=
				{
					{0.16,0.07},
					1
				};
				right[]=
				{
					{0.23999999,0.07},
					1
				};
				down[]=
				{
					{0.16,0.12},
					1
				};
			};
			class VspeedNumber
			{
				type="text";
				source="vspeed";
				sourceScale=1;
				sourceLength=2;
				align="left";
				scale=1;
				pos[]=
				{
					{0.92000002,0.52999997},
					1
				};
				right[]=
				{
					{0.99000001,0.52999997},
					1
				};
				down[]=
				{
					{0.92000002,0.59500003},
					1
				};
			};
			class AltNumber
			{
				type="text";
				source="altitudeAGL";
				sourceScale=1;
				sourceOffset=-2;
				sourceLength=3;
				align="left";
				scale=1;
				pos[]=
				{
					{0.83999997,0.07},
					1
				};
				right[]=
				{
					{0.92000002,0.07},
					1
				};
				down[]=
				{
					{0.83999997,0.12},
					1
				};
			};
			class VspeedNumberStaticP30
			{
				type="text";
				source="static";
				text="+30";
				scale=1;
				sourceScale=1;
				align="right";
				pos[]=
				{
					{0.93000001,0.583},
					1
				};
				right[]=
				{
					{0.97000003,0.583},
					1
				};
				down[]=
				{
					{0.93000001,0.61299998},
					1
				};
			};
			class VspeedNumberStatic0
			{
				type="text";
				source="static";
				text=" 0";
				scale=1;
				sourceScale=1;
				align="right";
				pos[]=
				{
					{0.93000001,0.70300001},
					1
				};
				right[]=
				{
					{0.97000003,0.70300001},
					1
				};
				down[]=
				{
					{0.93000001,0.73299998},
					1
				};
			};
			class VspeedNumberStaticM30
			{
				type="text";
				source="static";
				text="-30";
				scale=1;
				sourceScale=1;
				align="right";
				pos[]=
				{
					{0.93000001,0.82300001},
					1
				};
				right[]=
				{
					{0.97000003,0.82300001},
					1
				};
				down[]=
				{
					{0.93000001,0.85299999},
					1
				};
			};
			class AltGroup
			{
				condition="53 -altitudeAGL";
				class Static
				{
					type="line";
					width=4;
					points[]=
					{
						
						{
							"SliderAltitudeSource",
							{-0.015,0.0099999998},
							1
						},
						
						{
							"SliderAltitudeSource",
							{0,0},
							1
						},
						
						{
							"SliderAltitudeSource",
							{-0.015,-0.0099999998},
							1
						},
						
						{
							"SliderAltitudeSource",
							{-0.015,0.0099999998},
							1
						},
						{},
						
						{
							
							{
								0.85000002,
								"0.2 + 0 * 0.065"
							},
							1
						},
						
						{
							
							{
								0.85000002,
								"0.2 + 5 * 0.065"
							},
							1
						},
						{},
						
						{
							
							{
								0.85000002,
								"0.2 + 0 * 0.065"
							},
							1
						},
						
						{
							
							{
								0.87,
								"0.2 + 0 * 0.065"
							},
							1
						},
						{},
						
						{
							
							{
								0.86000001,
								"0.2 + 1 * 0.065"
							},
							1
						},
						
						{
							
							{
								0.87,
								"0.2 + 1 * 0.065"
							},
							1
						},
						{},
						
						{
							
							{
								0.86000001,
								"0.2 + 2 * 0.065"
							},
							1
						},
						
						{
							
							{
								0.87,
								"0.2 + 2 * 0.065"
							},
							1
						},
						{},
						
						{
							
							{
								0.86000001,
								"0.2 + 3 * 0.065"
							},
							1
						},
						
						{
							
							{
								0.87,
								"0.2 + 3 * 0.065"
							},
							1
						},
						{},
						
						{
							
							{
								0.86000001,
								"0.2 + 4 * 0.065"
							},
							1
						},
						
						{
							
							{
								0.87,
								"0.2 + 4 * 0.065"
							},
							1
						},
						{},
						
						{
							
							{
								0.85000002,
								"0.2 + 5 * 0.065"
							},
							1
						},
						
						{
							
							{
								0.87,
								"0.2 + 5 * 0.065"
							},
							1
						},
						{}
					};
				};
				class AltStatic50
				{
					type="text";
					source="static";
					text="50";
					scale=1;
					sourceScale=1;
					align="right";
					pos[]=
					{
						{0.88,0.183},
						1
					};
					right[]=
					{
						{0.92000002,0.183},
						1
					};
					down[]=
					{
						{0.88,0.213},
						1
					};
				};
				class AltStatic0
				{
					type="text";
					source="static";
					text="0";
					scale=1;
					sourceScale=1;
					align="right";
					pos[]=
					{
						{0.88,0.50800002},
						1
					};
					right[]=
					{
						{0.92000002,0.50800002},
						1
					};
					down[]=
					{
						{0.88,0.53799999},
						1
					};
				};
			};
			class SpeedGroup
			{
				condition="speed-2.78";
				class Static
				{
					type="line";
					width=4;
					points[]=
					{
						
						{
							"SliderSpeedSource",
							{0.015,0.0099999998},
							1
						},
						
						{
							"SliderSpeedSource",
							{0,0},
							1
						},
						
						{
							"SliderSpeedSource",
							{0.015,-0.0099999998},
							1
						},
						
						{
							"SliderSpeedSource",
							{0.015,0.0099999998},
							1
						},
						{},
						
						{
							{0.25,0.2},
							1
						},
						
						{
							{0.25,0.52499998},
							1
						},
						{},
						
						{
							{0.25,0.2},
							1
						},
						
						{
							{0.23,0.2},
							1
						},
						{},
						
						{
							{0.23999999,0.26499999},
							1
						},
						
						{
							{0.23,0.26499999},
							1
						},
						{},
						
						{
							{0.23999999,0.33000001},
							1
						},
						
						{
							{0.23,0.33000001},
							1
						},
						{},
						
						{
							{0.23999999,0.39500001},
							1
						},
						
						{
							{0.23,0.39500001},
							1
						},
						{},
						
						{
							{0.23999999,0.46000001},
							1
						},
						
						{
							{0.23,0.46000001},
							1
						},
						{},
						
						{
							{0.25,0.52499998},
							1
						},
						
						{
							{0.23,0.52499998},
							1
						},
						{}
					};
				};
				class SpeedStatic500
				{
					type="text";
					source="static";
					text="500";
					scale=1;
					sourceScale=1;
					align="left";
					pos[]=
					{
						{0.22,0.183},
						1
					};
					right[]=
					{
						{0.25999999,0.183},
						1
					};
					down[]=
					{
						{0.22,0.213},
						1
					};
				};
				class SpeedStatic0
				{
					type="text";
					source="static";
					text="0";
					scale=1;
					sourceScale=1;
					align="left";
					pos[]=
					{
						{0.22,0.50800002},
						1
					};
					right[]=
					{
						{0.25999999,0.50800002},
						1
					};
					down[]=
					{
						{0.22,0.53799999},
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
					{0.5,0},
					1
				};
				right[]=
				{
					{0.57999998,0},
					1
				};
				down[]=
				{
					{0.5,0.050000001},
					1
				};
			};
			class HeadingHeadNumber
			{
				type="text";
				source="cameraDir";
				sourceScale=1;
				align="center";
				scale=1;
				pos[]=
				{
					{0.5,0.057999998},
					1
				};
				right[]=
				{
					{0.57999998,0.057999998},
					1
				};
				down[]=
				{
					{0.5,0.108},
					1
				};
			};
			class HeadingGroupLeft
			{
				clipTL[]={0,0};
				clipBR[]={0.44999999,1};
				class HeadingScale
				{
					type="scale";
					horizontal=1;
					source="heading";
					sourceScale=0.1;
					width=4;
					NeverEatSeaWeed=1;
					top=0.30000001;
					center=0.5;
					bottom=0.69999999;
					lineXleft=0.11;
					lineYright=0.1;
					lineXleftMajor=0.11;
					lineYrightMajor=0.090000004;
					majorLineEach=2;
					numberEach=2;
					step=0.5;
					stepSize=0.055555601;
					align="center";
					scale=1;
					pos[]=
					{
						0.30000001,
						"0.00 + 0.05"
					};
					right[]=
					{
						0.36000001,
						"0.00 + 0.05"
					};
					down[]=
					{
						0.30000001,
						"0.04 + 0.05"
					};
				};
			};
			class HeadingGroupRight: HeadingGroupLeft
			{
				clipTL[]={0.55000001,0};
				clipBR[]={1,1};
				class HeadingScale: HeadingScale
				{
				};
			};
			class Static
			{
				type="line";
				width=4;
				points[]=
				{
					
					{
						{0.46200001,0.064999998},
						1
					},
					
					{
						{0.53799999,0.064999998},
						1
					},
					
					{
						{0.55800003,0.085000001},
						1
					},
					
					{
						{0.53799999,0.105},
						1
					},
					
					{
						{0.46200001,0.105},
						1
					},
					
					{
						{0.442,0.085000001},
						1
					},
					
					{
						{0.46200001,0.064999998},
						1
					},
					{},
					
					{
						{0.44499999,0.0049999999},
						1
					},
					
					{
						{0.55500001,0.0049999999},
						1
					},
					
					{
						{0.55500001,0.045000002},
						1
					},
					
					{
						{0.44499999,0.045000002},
						1
					},
					
					{
						{0.44499999,0.0049999999},
						1
					},
					{},
					
					{
						"HorizonBank2",
						{0,-0.0019797001},
						1
					},
					
					{
						"HorizonBank2",
						{0.001,-0.00171442},
						1
					},
					
					{
						"HorizonBank2",
						{0.001732,-0.00098984805},
						1
					},
					
					{
						"HorizonBank2",
						{0.0020000001,0},
						1
					},
					
					{
						"HorizonBank2",
						{0.001732,0.00098984805},
						1
					},
					
					{
						"HorizonBank2",
						{0.001,0.00171442},
						1
					},
					
					{
						"HorizonBank2",
						{0,0.0019797001},
						1
					},
					
					{
						"HorizonBank2",
						{-0.001,0.00171442},
						1
					},
					
					{
						"HorizonBank2",
						{-0.001732,0.00098984805},
						1
					},
					
					{
						"HorizonBank2",
						{-0.0020000001,0},
						1
					},
					
					{
						"HorizonBank2",
						{-0.001732,-0.00098984805},
						1
					},
					
					{
						"HorizonBank2",
						{-0.001,-0.00171442},
						1
					},
					
					{
						"HorizonBank2",
						{0,-0.0019797001},
						1
					},
					{},
					
					{
						"HorizonBank2",
						{0,-0.029695399},
						1
					},
					
					{
						"HorizonBank2",
						{0.015,-0.0257162},
						1
					},
					
					{
						"HorizonBank2",
						{0.025979999,-0.0148477},
						1
					},
					
					{
						"HorizonBank2",
						{0.029999999,0},
						1
					},
					{},
					
					{
						"HorizonBank2",
						{-0.029999999,0},
						1
					},
					
					{
						"HorizonBank2",
						{-0.025979999,-0.0148477},
						1
					},
					
					{
						"HorizonBank2",
						{-0.015,-0.0257162},
						1
					},
					
					{
						"HorizonBank2",
						{0,-0.029695399},
						1
					},
					{},
					
					{
						"HorizonBank2",
						{0.029999999,1.29803e-009},
						1
					},
					
					{
						"HorizonBank2",
						{0.050000001,2.1633799e-009},
						1
					},
					{},
					
					{
						"HorizonBank2",
						{-0.029999999,-3.5411399e-010},
						1
					},
					
					{
						"HorizonBank2",
						{-0.050000001,-5.9019101e-010},
						1
					},
					{},
					
					{
						"WeaponAim",
						{-0.050000001,2.1633799e-009},
						1
					},
					
					{
						"WeaponAim",
						{-0.059999999,2.59606e-009},
						1
					},
					{},
					
					{
						"WeaponAim",
						{0.050000001,-5.9019101e-010},
						1
					},
					
					{
						"WeaponAim",
						{0.059999999,-7.0822898e-010},
						1
					},
					{},
					
					{
						"WeaponAim",
						{-0.025,0.0428617},
						1
					},
					
					{
						"WeaponAim",
						{-0.029999999,0.051433999},
						1
					},
					{},
					
					{
						"WeaponAim",
						{0.025,0.0428617},
						1
					},
					
					{
						"WeaponAim",
						{0.029999999,0.051433999},
						1
					},
					{},
					
					{
						"WeaponAim",
						{-0.043301299,0.0247462},
						1
					},
					
					{
						"WeaponAim",
						{-0.0519615,0.029695399},
						1
					},
					{},
					
					{
						"WeaponAim",
						{0.043301299,0.0247462},
						1
					},
					
					{
						"WeaponAim",
						{0.0519615,0.029695399},
						1
					},
					{},
					
					{
						"SliderVSpeedSource",
						{-0.015,0.0099999998},
						1
					},
					
					{
						"SliderVSpeedSource",
						{0,0},
						1
					},
					
					{
						"SliderVSpeedSource",
						{-0.015,-0.0099999998},
						1
					},
					
					{
						"SliderVSpeedSource",
						{-0.015,0.0099999998},
						1
					},
					{},
					
					{
						
						{
							0.89999998,
							"0.6 - 0.3 * 0.04"
						},
						1
					},
					
					{
						
						{
							0.89999998,
							"0.6 + 6.3 * 0.04"
						},
						1
					},
					{},
					
					{
						
						{
							0.89999998,
							"0.6 + 0 * 0.04"
						},
						1
					},
					
					{
						
						{
							0.92000002,
							"0.6 + 0 * 0.04"
						},
						1
					},
					{},
					
					{
						
						{
							0.91000003,
							"0.6 + 1 * 0.04"
						},
						1
					},
					
					{
						
						{
							0.92000002,
							"0.6 + 1 * 0.04"
						},
						1
					},
					{},
					
					{
						
						{
							0.91000003,
							"0.6 + 2 * 0.04"
						},
						1
					},
					
					{
						
						{
							0.92000002,
							"0.6 + 2 * 0.04"
						},
						1
					},
					{},
					
					{
						
						{
							0.89999998,
							"0.6 + 3 * 0.04"
						},
						1
					},
					
					{
						
						{
							0.92000002,
							"0.6 + 3 * 0.04"
						},
						1
					},
					{},
					
					{
						
						{
							0.91000003,
							"0.6 + 4 * 0.04"
						},
						1
					},
					
					{
						
						{
							0.92000002,
							"0.6 + 4 * 0.04"
						},
						1
					},
					{},
					
					{
						
						{
							0.91000003,
							"0.6 + 5 * 0.04"
						},
						1
					},
					
					{
						
						{
							0.92000002,
							"0.6 + 5 * 0.04"
						},
						1
					},
					{},
					
					{
						
						{
							0.89999998,
							"0.6 + 6 * 0.04"
						},
						1
					},
					
					{
						
						{
							0.92000002,
							"0.6 + 6 * 0.04"
						},
						1
					},
					{},
					
					{
						{0.31,0.112},
						1
					},
					
					{
						{0.69,0.112},
						1
					},
					{}
				};
			};
			class Weapons
			{
				type="text";
				source="weapon";
				sourceScale=1;
				align="right";
				scale=0.5;
				pos[]=
				{
					{0.1,0.93000001},
					1
				};
				right[]=
				{
					
					{
						"0.16 - 0.02",
						0.93000001
					},
					1
				};
				down[]=
				{
					{0.1,0.97000003},
					1
				};
			};
			class Ammo
			{
				type="text";
				source="ammo";
				sourceScale=1;
				align="right";
				scale=0.5;
				pos[]=
				{
					{0.1,0.88},
					1
				};
				right[]=
				{
					
					{
						"0.16 - 0.02",
						0.88
					},
					1
				};
				down[]=
				{
					{0.1,0.92000002},
					1
				};
			};
			class cmWeapons
			{
				type="text";
				source="cmweapon";
				sourceScale=1;
				align="left";
				scale=0.5;
				pos[]=
				{
					{0.89999998,0.93000001},
					1
				};
				right[]=
				{
					{0.94,0.93000001},
					1
				};
				down[]=
				{
					{0.89999998,0.97000003},
					1
				};
			};
			class cmAmmo
			{
				type="text";
				source="cmammo";
				sourceScale=1;
				align="left";
				scale=0.5;
				pos[]=
				{
					{0.89999998,0.88},
					1
				};
				right[]=
				{
					{0.94,0.88},
					1
				};
				down[]=
				{
					{0.89999998,0.92000002},
					1
				};
			};
		};
	};
};