defaultUserMFDvalues[]={0.25,1,0.25,1};

class MFD
{
	class MFD_Pilot_10
	{
		topLeft="MFD_10_TL";
		topRight="MFD_10_TR";
		bottomLeft="MFD_10_BL";
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
	class MFD_Pilot_8
	{
		topLeft="MFD_8_TL";
		topRight="MFD_8_TR";
		bottomLeft="MFD_8_BL";
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
		turret[]={-2};
		class Bones
		{
		};
		class Draw
		{
			alpha=1;
			color[]={0,0.12,0};
			condition="on";
			class Time
			{
				type="text";
				source="time";
				text="%X";
				sourceScale=1;
				align="right";
				scale=1;
				pos[]=
				{
					{0.029999999,0.11},
					1
				};
				right[]=
				{
					{0.13,0.11},
					1
				};
				down[]=
				{
					{0.029999999,0.2},
					1
				};
			};
			class Fuel
			{
				type="text";
				source="fuel";
				text="%X";
				sourceScale=2517;
				sourceLength=4;
				align="right";
				scale=1;
				pos[]=
				{
					{0.029999999,0.31},
					1
				};
				right[]=
				{
					{0.13,0.31},
					1
				};
				down[]=
				{
					{0.029999999,0.40000001},
					1
				};
			};
			class LBSText
			{
				type="text";
				source="static";
				text="LBS";
				scale=1;
				sourceScale=1;
				align="right";
				pos[]=
				{
					{0.30000001,0.31},
					1
				};
				right[]=
				{
					{0.40000001,0.31},
					1
				};
				down[]=
				{
					{0.30000001,0.40000001},
					1
				};
			};
			class GridX
			{
				type="text";
				source="coordinateX";
				sourceScale=0.0099999998;
				sourceOffset=-0.5;
				sourceLength=3;
				align="right";
				scale=1;
				pos[]=
				{
					{0.029999999,0.61000001},
					1
				};
				right[]=
				{
					{0.13,0.61000001},
					1
				};
				down[]=
				{
					{0.029999999,0.69999999},
					1
				};
			};
			class GridY: GridX
			{
				source="coordinateY";
				pos[]=
				{
					{0.23999999,0.61000001},
					1
				};
				right[]=
				{
					{0.34,0.61000001},
					1
				};
				down[]=
				{
					{0.23999999,0.69999999},
					1
				};
			};
			class GridText
			{
				type="text";
				source="static";
				text="GRID:";
				scale=1;
				sourceScale=1;
				align="right";
				pos[]=
				{
					{0.029999999,0.50999999},
					1
				};
				right[]=
				{
					{0.13,0.50999999},
					1
				};
				down[]=
				{
					{0.029999999,0.60000002},
					1
				};
			};
		};
	};
	class MFD_Pilot_9
	{
		topLeft="MFD_9_TL";
		topRight="MFD_9_TR";
		bottomLeft="MFD_9_BL";
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
		turret[]={-2};
		class Bones
		{
		};
		class Draw
		{
			alpha=1;
			color[]={0,0.12,0};
			condition="on";
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
						{0.22,0.2},
						1
					};
					right[]=
					{
						{0.28,0.2},
						1
					};
					down[]=
					{
						{0.22,0.23999999},
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
						{0.22,0.2},
						1
					};
					right[]=
					{
						{0.28,0.2},
						1
					};
					down[]=
					{
						{0.22,0.23999999},
						1
					};
				};
			};
			class SpeedNumber
			{
				type="text";
				source="speed";
				sourceScale=3.5999999;
				align="left";
				scale=1;
				pos[]=
				{
					{0.28,0.45199999},
					1
				};
				right[]=
				{
					{0.31999999,0.45199999},
					1
				};
				down[]=
				{
					{0.28,0.49200001},
					1
				};
			};
			class AltNumber
			{
				type="text";
				source="altitudeAGL";
				sourceScale=1;
				sourceOffset=-2;
				align="left";
				scale=1;
				pos[]=
				{
					{0.75,0.45199999},
					1
				};
				right[]=
				{
					{0.79000002,0.45199999},
					1
				};
				down[]=
				{
					{0.75,0.49200001},
					1
				};
			};
			class CruiseMode
			{
				condition="1+((altitudeASL-27) min 1) - autohover";
				class AltNumberASL
				{
					type="text";
					source="altitudeASL";
					sourceScale=1;
					align="left";
					scale=1;
					pos[]=
					{
						{0.81,0.16},
						1
					};
					right[]=
					{
						{0.85000002,0.16},
						1
					};
					down[]=
					{
						{0.81,0.2},
						1
					};
				};
			};
		};
	};
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
		helmetPosition[]={-0.037500001,0.037500001,0.1};
		helmetRight[]={0.075000003,0,0};
		helmetDown[]={0,-0.075000003,0};
		font="LucidaConsoleB";
		turret[]={0};
		class Bones
		{
			class HUDCenter
			{
				type="fixed";
				pos[]={0.5,0.5};
			};
			class WeaponAim
			{
				type="vector";
				source="weapon";
				pos0[]={0.5,0.5};
				pos10[]={0.73400003,0.73000002};
			};
			class WeaponAimRelative: WeaponAim
			{
				source="weapontoview";
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
			class HorizonVector
			{
				type="horizontoview";
				pos0[]={0.5,0.5};
				pos10[]={0.83092302,0.825266};
				angle=0;
			};
			class GunnerAim
			{
				type="vector";
				source="turret";
				pos0[]={0,-2};
				pos10[]={0.0068000001,-0.0099999998};
				projection=0;
			};
			class VerticalSpeedBone
			{
				type="linear";
				source="vspeed";
				sourceScale=1;
				min=-10;
				max=10;
				minPos[]={0,-0.31999999};
				maxPos[]={0,0.31999999};
			};
			class HorizonBankRot
			{
				type="linear";
				source="horizonBank";
				min=-0.52359998;
				max=0.52359998;
				minPos[]={0.41,0.83999997};
				maxPos[]={0.58999997,0.83999997};
				aspectRatio=1;
			};
			class ImpactPoint
			{
				type="vector";
				source="ImpactPointToView";
				pos0[]={0.5,0.5};
				pos10[]={0.73400003,0.73000002};
			};
			class Target
			{
				source="targettoview";
				type="vector";
				pos0[]={0.5,0.5};
				pos10[]={0.73400003,0.73000002};
			};
			class Limit0109
			{
				type="limit";
				limits[]={0.1,0.1,0.89999998,0.89999998};
			};
			class LimitWaypoint
			{
				type="limit";
				limits[]={0.2,0.1,0.80000001,0.1};
			};
			class WPPoint
			{
				type="vector";
				source="WPPoint";
				pos0[]={0.5,0.5};
				pos10[]={0.73400003,0.73000002};
			};
			class WPPointToView: WPPoint
			{
				source="WPPointToView";
			};
			class RadarHeight
			{
				type="linear";
				source="altitudeAGL";
				sourceScale=1;
				sourceOffset=-2;
				min=0;
				max=100;
				minPos[]={0.903,0.18000001};
				maxPos[]={0.903,0.81999999};
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
			alpha=1;
			color[]={0.25,1,0.25};
			condition="on - (cameraHeadingDiffY<=-19) + (abs(cameraHeadingDiffX)>=24)";
			class Static
			{
				type="line";
				width=4;
				points[]=
				{
					
					{
						{0.5,0.11},
						1
					},
					
					{
						{0.5,0.14},
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
						{0.40000001,0.88499999},
						1
					},
					
					{
						{0.40799999,0.88499999},
						1
					},
					{},
					
					{
						{0.60000002,0.88499999},
						1
					},
					
					{
						{0.59200001,0.88499999},
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
						{0.51999998,0.86000001},
						1
					},
					
					{
						{0.51999998,0.81999999},
						1
					},
					{},
					
					{
						{0.47999999,0.86000001},
						1
					},
					
					{
						{0.47999999,0.81999999},
						1
					},
					{},
					
					{
						{0.55000001,0},
						1
					},
					
					{
						{0.55000001,0.039999999},
						1
					},
					
					{
						{0.44999999,0.039999999},
						1
					},
					
					{
						{0.44999999,0},
						1
					},
					
					{
						{0.55000001,0},
						1
					}
				};
			};
			class HeadingNumber
			{
				type="text";
				source="Heading";
				sourceScale=1;
				align="center";
				scale=1;
				pos[]=
				{
					{0.5,0.0060000001},
					1
				};
				right[]=
				{
					{0.55000001,0.0060000001},
					1
				};
				down[]=
				{
					{0.5,0.046},
					1
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
							"0.082-0.025"
						},
						1
					};
					right[]=
					{
						
						{
							"0.83-0.302",
							"0.082-0.025"
						},
						1
					};
					down[]=
					{
						
						{
							"0.80-0.302",
							"0.113-0.025"
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
							{0.47799999,0.045000002},
							1
						},
						
						{
							{0.52200001,0.045000002},
							1
						},
						
						{
							{0.55199999,0.07},
							1
						},
						
						{
							{0.52200001,0.094999999},
							1
						},
						
						{
							{0.47799999,0.094999999},
							1
						},
						
						{
							{0.44800001,0.07},
							1
						},
						
						{
							{0.47799999,0.045000002},
							1
						},
						{}
					};
				};
				class HeadingScaleRight
				{
					clipTL[]={0.55000001,0.050000001};
					clipBR[]={0.82999998,0.11};
					class lines
					{
						type="scale";
						horizontal=1;
						source="heading";
						sourceScale=1;
						width=4;
						top=0.5;
						center=0.5;
						bottom=0.85000002;
						lineXleft=0.11;
						lineYright=0.1;
						lineXleftMajor=0.11;
						lineYrightMajor=0.090000004;
						majorLineEach=2;
						numberEach=2;
						step=22.5;
						stepSize=0.075000003;
						align="center";
						scale=1;
						pos[]={0.49599999,0.050000001};
						right[]={0.53600001,0.050000001};
						down[]={0.49599999,0.090000004};
					};
				};
				class HeadingScaleMidle
				{
					type="scale";
					horizontal=1;
					source="heading";
					sourceScale=1;
					width=4;
					top=0.44999999;
					center=0.5;
					bottom=0.55000001;
					lineXleft=0.11;
					lineYright=0.1;
					lineXleftMajor=0.11;
					lineYrightMajor=0.1;
					majorLineEach=2;
					step=22.5;
					stepSize=0.075000003;
					align="center";
					scale=1;
					numberEach=0;
					pos[]={0.47,0.050000001};
					right[]={0.5,0.050000001};
					down[]={0.44999999,0.090000004};
				};
				class HeadingScaleLeft
				{
					clipTL[]={0.18000001,0.050000001};
					clipBR[]={0.44999999,0.11};
					class lines
					{
						type="scale";
						horizontal=1;
						source="heading";
						sourceScale=1;
						width=4;
						top=0.15000001;
						center=0.5;
						bottom=0.55000001;
						lineXleft=0.11;
						lineYright=0.1;
						lineXleftMajor=0.11;
						lineYrightMajor=0.090000004;
						majorLineEach=2;
						numberEach=2;
						step=22.5;
						stepSize=0.075000003;
						align="center";
						scale=1;
						pos[]={0.146,0.050000001};
						right[]={0.186,0.050000001};
						down[]={0.146,0.090000004};
					};
				};
			};
			class HeadingScaleFull
			{
				condition="5-abs(cameraDir-heading)*( (abs(heading-cameraDir))<=355)";
				class HeadingScale
				{
					clipTL[]={0.18000001,0};
					clipBR[]={0.82999998,1};
					class lines
					{
						type="scale";
						horizontal=1;
						source="heading";
						sourceScale=1;
						width=4;
						top=0.15000001;
						center=0.5;
						bottom=0.85000002;
						lineXleft=0.11;
						lineYright=0.1;
						lineXleftMajor=0.11;
						lineYrightMajor=0.090000004;
						majorLineEach=2;
						numberEach=2;
						step=22.5;
						stepSize=0.075000003;
						align="center";
						scale=1;
						pos[]={0.146,0.050000001};
						right[]={0.186,0.050000001};
						down[]={0.146,0.090000004};
					};
				};
			};
			class HorizonBankRot
			{
				type="polygon";
				width=4;
				points[]=
				{
					
					{
						
						{
							"HorizonBankRot",
							1,
							{0,0},
							1
						},
						
						{
							"HorizonBankRot",
							{0.0026047199,-0.0145196},
							1
						},
						
						{
							"HorizonBankRot",
							{0.0051302998,-0.0138544},
							1
						},
						
						{
							"HorizonBankRot",
							{0.0074999998,-0.0127683},
							1
						}
					},
					
					{
						
						{
							"HorizonBankRot",
							1,
							{0,0},
							1
						},
						
						{
							"HorizonBankRot",
							{0.0074999998,-0.0127683},
							1
						},
						
						{
							"HorizonBankRot",
							{0.0096418103,-0.0112942},
							1
						},
						
						{
							"HorizonBankRot",
							{0.0114907,-0.0094769998},
							1
						}
					},
					
					{
						
						{
							"HorizonBankRot",
							1,
							{0,0},
							1
						},
						
						{
							"HorizonBankRot",
							{0.0114907,-0.0094769998},
							1
						},
						
						{
							"HorizonBankRot",
							{0.0129904,-0.0073717898},
							1
						},
						
						{
							"HorizonBankRot",
							{0.0140954,-0.0050426},
							1
						}
					},
					
					{
						
						{
							"HorizonBankRot",
							1,
							{0,0},
							1
						},
						
						{
							"HorizonBankRot",
							{0.0140954,-0.0050426},
							1
						},
						
						{
							"HorizonBankRot",
							{0.0147721,-0.0025601999},
							1
						},
						
						{
							"HorizonBankRot",
							{0.015,6.4446298e-010},
							1
						}
					},
					
					{
						
						{
							"HorizonBankRot",
							1,
							{0,0},
							1
						},
						
						{
							"HorizonBankRot",
							{0.015,6.4446298e-010},
							1
						},
						
						{
							"HorizonBankRot",
							{0.0147721,0.0025601999},
							1
						},
						
						{
							"HorizonBankRot",
							{0.0140954,0.0050426},
							1
						}
					},
					
					{
						
						{
							"HorizonBankRot",
							1,
							{0,0},
							1
						},
						
						{
							"HorizonBankRot",
							{0.0140954,0.0050426},
							1
						},
						
						{
							"HorizonBankRot",
							{0.0129904,0.0073718},
							1
						},
						
						{
							"HorizonBankRot",
							{0.0114907,0.0094769998},
							1
						}
					},
					
					{
						
						{
							"HorizonBankRot",
							1,
							{0,0},
							1
						},
						
						{
							"HorizonBankRot",
							{0.0114907,0.0094769998},
							1
						},
						
						{
							"HorizonBankRot",
							{0.0096418103,0.0112942},
							1
						},
						
						{
							"HorizonBankRot",
							{0.0074999998,0.0127683},
							1
						}
					},
					
					{
						
						{
							"HorizonBankRot",
							1,
							{0,0},
							1
						},
						
						{
							"HorizonBankRot",
							{0.0074999998,0.0127683},
							1
						},
						
						{
							"HorizonBankRot",
							{0.0051302998,0.0138544},
							1
						},
						
						{
							"HorizonBankRot",
							{0.0026047199,0.0145196},
							1
						}
					},
					
					{
						
						{
							"HorizonBankRot",
							1,
							{0,0},
							1
						},
						
						{
							"HorizonBankRot",
							{0.0026047199,0.0145196},
							1
						},
						
						{
							"HorizonBankRot",
							{-1.31134e-009,0.0147436},
							1
						},
						
						{
							"HorizonBankRot",
							{-0.00260473,0.0145196},
							1
						}
					},
					
					{
						
						{
							"HorizonBankRot",
							1,
							{0,0},
							1
						},
						
						{
							"HorizonBankRot",
							{-0.00260473,0.0145196},
							1
						},
						
						{
							"HorizonBankRot",
							{-0.0051302998,0.0138544},
							1
						},
						
						{
							"HorizonBankRot",
							{-0.0074999998,0.0127683},
							1
						}
					},
					
					{
						
						{
							"HorizonBankRot",
							1,
							{0,0},
							1
						},
						
						{
							"HorizonBankRot",
							{-0.0074999998,0.0127683},
							1
						},
						
						{
							"HorizonBankRot",
							{-0.0096418103,0.0112942},
							1
						},
						
						{
							"HorizonBankRot",
							{-0.0114907,0.0094769998},
							1
						}
					},
					
					{
						
						{
							"HorizonBankRot",
							1,
							{0,0},
							1
						},
						
						{
							"HorizonBankRot",
							{-0.0114907,0.0094769998},
							1
						},
						
						{
							"HorizonBankRot",
							{-0.0129904,0.0073717898},
							1
						},
						
						{
							"HorizonBankRot",
							{-0.0140954,0.0050426},
							1
						}
					},
					
					{
						
						{
							"HorizonBankRot",
							1,
							{0,0},
							1
						},
						
						{
							"HorizonBankRot",
							{-0.0140954,0.0050426},
							1
						},
						
						{
							"HorizonBankRot",
							{-0.0147721,0.0025601999},
							1
						},
						
						{
							"HorizonBankRot",
							{-0.015,-1.75816e-010},
							1
						}
					},
					
					{
						
						{
							"HorizonBankRot",
							1,
							{0,0},
							1
						},
						
						{
							"HorizonBankRot",
							{-0.015,-1.75816e-010},
							1
						},
						
						{
							"HorizonBankRot",
							{-0.0147721,-0.0025601999},
							1
						},
						
						{
							"HorizonBankRot",
							{-0.0140954,-0.0050426},
							1
						}
					},
					
					{
						
						{
							"HorizonBankRot",
							1,
							{0,0},
							1
						},
						
						{
							"HorizonBankRot",
							{-0.0140954,-0.0050426},
							1
						},
						
						{
							"HorizonBankRot",
							{-0.0129904,-0.0073718},
							1
						},
						
						{
							"HorizonBankRot",
							{-0.0114907,-0.0094769998},
							1
						}
					},
					
					{
						
						{
							"HorizonBankRot",
							1,
							{0,0},
							1
						},
						
						{
							"HorizonBankRot",
							{-0.0114907,-0.0094769998},
							1
						},
						
						{
							"HorizonBankRot",
							{-0.0096418103,-0.0112942},
							1
						},
						
						{
							"HorizonBankRot",
							{-0.0074999998,-0.0127683},
							1
						}
					},
					
					{
						
						{
							"HorizonBankRot",
							1,
							{0,0},
							1
						},
						
						{
							"HorizonBankRot",
							{-0.0074999998,-0.0127683},
							1
						},
						
						{
							"HorizonBankRot",
							{-0.0051303101,-0.0138544},
							1
						},
						
						{
							"HorizonBankRot",
							{-0.0026047199,-0.0145196},
							1
						}
					},
					
					{
						
						{
							"HorizonBankRot",
							1,
							{0,0},
							1
						},
						
						{
							"HorizonBankRot",
							{-0.0026047199,-0.0145196},
							1
						},
						
						{
							"HorizonBankRot",
							{2.6226801e-009,-0.0147436},
							1
						},
						
						{
							"HorizonBankRot",
							{0.0026047199,-0.0145196},
							1
						}
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
						{0.22,0.2},
						1
					};
					right[]=
					{
						{0.28,0.2},
						1
					};
					down[]=
					{
						{0.22,0.23999999},
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
						{0.22,0.2},
						1
					};
					right[]=
					{
						{0.28,0.2},
						1
					};
					down[]=
					{
						{0.22,0.23999999},
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
					{0.16,0.47999999},
					1
				};
				right[]=
				{
					{0.22,0.47999999},
					1
				};
				down[]=
				{
					{0.16,0.51999998},
					1
				};
			};
			class AltNumber
			{
				type="text";
				source="altitudeAGL";
				sourceScale=1;
				sourceOffset=-2;
				align="left";
				scale=1;
				pos[]=
				{
					{0.81,0.47999999},
					1
				};
				right[]=
				{
					{0.87,0.47999999},
					1
				};
				down[]=
				{
					{0.81,0.51999998},
					1
				};
			};
			class HoverMode
			{
				condition="autohover";
				class HoverText
				{
					type="text";
					source="static";
					text="HOVER";
					scale=1;
					sourceScale=1;
					align="right";
					pos[]=
					{
						{0.0049999999,0.075000003},
						1
					};
					right[]=
					{
						{0.045000002,0.075000003},
						1
					};
					down[]=
					{
						{0.0049999999,0.11},
						1
					};
				};
			};
			class CruiseMode
			{
				condition="((altitudeASL-27) min 1) - autohover";
				class CruiseText
				{
					type="text";
					source="static";
					text="CRUISE";
					scale=1;
					sourceScale=1;
					align="right";
					pos[]=
					{
						{0.0049999999,0.075000003},
						1
					};
					right[]=
					{
						{0.045000002,0.075000003},
						1
					};
					down[]=
					{
						{0.0049999999,0.11},
						1
					};
				};
				class AltNumberASL
				{
					type="text";
					source="altitudeASL";
					sourceScale=1;
					align="left";
					scale=1;
					pos[]=
					{
						{0.81,0.16},
						1
					};
					right[]=
					{
						{0.87,0.16},
						1
					};
					down[]=
					{
						{0.81,0.2},
						1
					};
				};
			};
			class TransitionMode
			{
				condition="((27-altitudeASL) min 1) - autohover";
				class TransText
				{
					type="text";
					source="static";
					text="TRANS";
					scale=1;
					sourceScale=1;
					align="right";
					pos[]=
					{
						{0.0049999999,0.075000003},
						1
					};
					right[]=
					{
						{0.045000002,0.075000003},
						1
					};
					down[]=
					{
						{0.0049999999,0.11},
						1
					};
				};
			};
			class HoverModeHide
			{
				condition="1-autohover";
				class VelocityLine
				{
					type="line";
					width=4;
					points[]=
					{
						
						{
							"VelocityVector",
							{0,-0.0196581},
							1
						},
						
						{
							"VelocityVector",
							{0.0099999998,-0.017023901},
							1
						},
						
						{
							"VelocityVector",
							{0.01732,-0.0098290602},
							1
						},
						
						{
							"VelocityVector",
							{0.02,0},
							1
						},
						
						{
							"VelocityVector",
							{0.01732,0.0098290602},
							1
						},
						
						{
							"VelocityVector",
							{0.0099999998,0.017023901},
							1
						},
						
						{
							"VelocityVector",
							{0,0.0196581},
							1
						},
						
						{
							"VelocityVector",
							{-0.0099999998,0.017023901},
							1
						},
						
						{
							"VelocityVector",
							{-0.01732,0.0098290602},
							1
						},
						
						{
							"VelocityVector",
							{-0.02,0},
							1
						},
						
						{
							"VelocityVector",
							{-0.01732,-0.0098290602},
							1
						},
						
						{
							"VelocityVector",
							{-0.0099999998,-0.017023901},
							1
						},
						
						{
							"VelocityVector",
							{0,-0.0196581},
							1
						},
						{},
						
						{
							"VelocityVector",
							{0.039999999,0},
							1
						},
						
						{
							"VelocityVector",
							{0.02,0},
							1
						},
						{},
						
						{
							"VelocityVector",
							{-0.039999999,0},
							1
						},
						
						{
							"VelocityVector",
							{-0.02,0},
							1
						},
						{},
						
						{
							"VelocityVector",
							{0,-0.0393162},
							1
						},
						
						{
							"VelocityVector",
							{0,-0.0196581},
							1
						},
						{}
					};
				};
			};
			class GearGroup
			{
				type="group";
				condition="ils";
				class GearText
				{
					type="text";
					source="static";
					text="GEAR";
					align="right";
					scale=1;
					pos[]=
					{
						{0.015,0.33418801},
						1
					};
					right[]=
					{
						{0.055,0.33418801},
						1
					};
					down[]=
					{
						{0.015,0.363675},
						1
					};
				};
			};
			class LaserGroup
			{
				condition="laseron";
				class laserText
				{
					type="text";
					source="static";
					text="LASER";
					scale=1;
					sourceScale=1;
					align="right";
					pos[]=
					{
						{0.015,0.37},
						1
					};
					right[]=
					{
						{0.055,0.37},
						1
					};
					down[]=
					{
						{0.015,0.405},
						1
					};
				};
			};
			class RadarGroup
			{
				condition="activeSensorsOn";
				class radarText
				{
					type="text";
					source="static";
					text="RADAR";
					scale=1;
					sourceScale=1;
					align="right";
					pos[]=
					{
						{0.015,0.41},
						1
					};
					right[]=
					{
						{0.055,0.41},
						1
					};
					down[]=
					{
						{0.015,0.44499999},
						1
					};
				};
			};
			class VerticalSpeedScale
			{
				type="line";
				width=4;
				points[]=
				{
					
					{
						"WeaponAimRelative",
						1,
						{-0.029999999,0},
						1
					},
					
					{
						"WeaponAimRelative",
						1,
						{-0.02,0},
						1
					},
					{},
					
					{
						"WeaponAimRelative",
						1,
						{0.02,0},
						1
					},
					
					{
						"WeaponAimRelative",
						1,
						{0.029999999,0},
						1
					},
					{},
					
					{
						"WeaponAimRelative",
						1,
						{0,-0.02},
						1
					},
					
					{
						"WeaponAimRelative",
						1,
						{0,-0.029999999},
						1
					},
					{},
					
					{
						"WeaponAimRelative",
						1,
						{0,0.02},
						1
					},
					
					{
						"WeaponAimRelative",
						1,
						{0,0.029999999},
						1
					},
					{},
					
					{
						"HUDCenter",
						1,
						{-0.029999999,0},
						1
					},
					
					{
						"HUDCenter",
						1,
						{-0.0099999998,0},
						1
					},
					{},
					
					{
						"HUDCenter",
						1,
						{0.0099999998,0},
						1
					},
					
					{
						"HUDCenter",
						1,
						{0.029999999,0},
						1
					},
					{},
					
					{
						"HUDCenter",
						1,
						{0,-0.0099999998},
						1
					},
					
					{
						"HUDCenter",
						1,
						{0,-0.029999999},
						1
					},
					{},
					
					{
						"HUDCenter",
						1,
						{0,0.0099999998},
						1
					},
					
					{
						"HUDCenter",
						1,
						{0,0.029999999},
						1
					},
					{},
					
					{
						{0.91500002,0.18000001},
						1
					},
					
					{
						{0.935,0.18000001},
						1
					},
					{},
					
					{
						{0.87,0.18000001},
						1
					},
					
					{
						{0.88999999,0.18000001},
						1
					},
					{},
					
					{
						{0.91500002,0.34},
						1
					},
					
					{
						{0.935,0.34},
						1
					},
					{},
					
					{
						{0.87,0.34},
						1
					},
					
					{
						{0.88999999,0.34},
						1
					},
					{},
					
					{
						{0.875,0.37200001},
						1
					},
					
					{
						{0.88499999,0.37200001},
						1
					},
					{},
					
					{
						{0.875,0.40400001},
						1
					},
					
					{
						{0.88499999,0.40400001},
						1
					},
					{},
					
					{
						{0.875,0.43599999},
						1
					},
					
					{
						{0.88499999,0.43599999},
						1
					},
					{},
					
					{
						{0.875,0.46799999},
						1
					},
					
					{
						{0.88499999,0.46799999},
						1
					},
					{},
					
					{
						{0.87,0.5},
						1
					},
					
					{
						{0.88999999,0.5},
						1
					},
					{},
					
					{
						{0.91500002,0.5},
						1
					},
					
					{
						{0.935,0.5},
						1
					},
					{},
					
					{
						{0.91500002,0.66000003},
						1
					},
					
					{
						{0.935,0.66000003},
						1
					},
					{},
					
					{
						{0.87,0.66000003},
						1
					},
					
					{
						{0.88999999,0.66000003},
						1
					},
					{},
					
					{
						{0.875,0.62800002},
						1
					},
					
					{
						{0.88499999,0.62800002},
						1
					},
					{},
					
					{
						{0.875,0.59600002},
						1
					},
					
					{
						{0.88499999,0.59600002},
						1
					},
					{},
					
					{
						{0.875,0.56400001},
						1
					},
					
					{
						{0.88499999,0.56400001},
						1
					},
					{},
					
					{
						{0.875,0.53200001},
						1
					},
					
					{
						{0.88499999,0.53200001},
						1
					},
					{},
					
					{
						{0.92000002,0.69199997},
						1
					},
					
					{
						{0.93000001,0.69199997},
						1
					},
					{},
					
					{
						{0.92000002,0.72399998},
						1
					},
					
					{
						{0.93000001,0.72399998},
						1
					},
					{},
					
					{
						{0.92000002,0.75599998},
						1
					},
					
					{
						{0.93000001,0.75599998},
						1
					},
					{},
					
					{
						{0.92000002,0.78799999},
						1
					},
					
					{
						{0.93000001,0.78799999},
						1
					},
					{},
					
					{
						{0.91500002,0.81999999},
						1
					},
					
					{
						{0.935,0.81999999},
						1
					},
					{},
					
					{
						{0.87,0.81999999},
						1
					},
					
					{
						{0.88999999,0.81999999},
						1
					},
					{}
				};
			};
			class VerticalSpeedArrow
			{
				type="polygon";
				points[]=
				{
					
					{
						
						{
							"VerticalSpeedBone",
							{0.85000002,0.48800001},
							1
						},
						
						{
							"VerticalSpeedBone",
							{0.87,0.5},
							1
						},
						
						{
							"VerticalSpeedBone",
							{0.85000002,0.51200002},
							1
						}
					}
				};
			};
			class RadarAltitude
			{
				condition="101-altitudeAGL";
				class RadarHeight
				{
					type="line";
					width=15;
					points[]=
					{
						
						{
							{0.903,0.81999999},
							1
						},
						
						{
							"RadarHeight",
							{0,0},
							1
						},
						{}
					};
				};
			};
			class HorizonLine
			{
				condition="1-autohover";
				clipTL[]={0.2,0.145};
				clipBR[]={0.80000001,0.85500002};
				class HorizonLineDraw
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
			class WeaponsText
			{
				condition="1- mgun";
				class Weapons
				{
					type="text";
					source="weapon";
					sourceScale=1;
					align="left";
					scale=0.5;
					pos[]=
					{
						{0.38,0.86900002},
						1
					};
					right[]=
					{
						{0.41499999,0.86900002},
						1
					};
					down[]=
					{
						{0.38,0.90399998},
						1
					};
				};
			};
			class Ammo
			{
				type="text";
				source="ammo";
				sourceScale=1;
				align="left";
				scale=0.5;
				pos[]=
				{
					{0.38,0.90100002},
					1
				};
				right[]=
				{
					{0.41499999,0.90100002},
					1
				};
				down[]=
				{
					{0.38,0.93599999},
					1
				};
			};
			class MGun
			{
				condition="mgun";
				class Weapons
				{
					type="text";
					source="static";
					text="GUN";
					sourceScale=1;
					align="left";
					scale=0.5;
					pos[]=
					{
						{0.38,0.86900002},
						1
					};
					right[]=
					{
						{0.41499999,0.86900002},
						1
					};
					down[]=
					{
						{0.38,0.90399998},
						1
					};
				};
				class Circle
				{
					type="line";
					width=4;
					points[]=
					{
						
						{
							"ImpactPoint",
							{0.025,0},
							1
						},
						
						{
							"ImpactPoint",
							{0.0099999998,0},
							1
						},
						{},
						
						{
							"ImpactPoint",
							{0,0.0245726},
							1
						},
						
						{
							"ImpactPoint",
							{0,0.0098290602},
							1
						},
						{},
						
						{
							"ImpactPoint",
							{-0.025,0},
							1
						},
						
						{
							"ImpactPoint",
							{-0.0099999998,0},
							1
						},
						{},
						
						{
							"ImpactPoint",
							{0,-0.0245726},
							1
						},
						
						{
							"ImpactPoint",
							{0,-0.0098290602},
							1
						},
						{},
						
						{
							"ImpactPoint",
							{0,-0.0098290602},
							1
						},
						
						{
							"ImpactPoint",
							{0.0049999999,-0.0085119698},
							1
						},
						
						{
							"ImpactPoint",
							{0.0086599998,-0.0049145301},
							1
						},
						
						{
							"ImpactPoint",
							{0.0099999998,0},
							1
						},
						
						{
							"ImpactPoint",
							{0.0086599998,0.0049145301},
							1
						},
						
						{
							"ImpactPoint",
							{0.0049999999,0.0085119698},
							1
						},
						
						{
							"ImpactPoint",
							{0,0.0098290602},
							1
						},
						
						{
							"ImpactPoint",
							{-0.0049999999,0.0085119698},
							1
						},
						
						{
							"ImpactPoint",
							{-0.0086599998,0.0049145301},
							1
						},
						
						{
							"ImpactPoint",
							{-0.0099999998,0},
							1
						},
						
						{
							"ImpactPoint",
							{-0.0086599998,-0.0049145301},
							1
						},
						
						{
							"ImpactPoint",
							{-0.0049999999,-0.0085119698},
							1
						},
						
						{
							"ImpactPoint",
							{0,-0.0098290602},
							1
						}
					};
				};
			};
			class AAMissile
			{
				condition="AAmissile";
				class Circle
				{
					type="line";
					width=4;
					points[]=
					{
						
						{
							"ForwardVector",
							1,
							"HUDCenter",
							{0,-0.245726},
							1
						},
						
						{
							"ForwardVector",
							1,
							"HUDCenter",
							{0.043400001,-0.241991},
							1
						},
						
						{
							"ForwardVector",
							1,
							"HUDCenter",
							{0.085500002,-0.230909},
							1
						},
						
						{
							"ForwardVector",
							1,
							"HUDCenter",
							{0.125,-0.212799},
							1
						},
						
						{
							"ForwardVector",
							1,
							"HUDCenter",
							{0.16069999,-0.188226},
							1
						},
						
						{
							"ForwardVector",
							1,
							"HUDCenter",
							{0.19149999,-0.15795299},
							1
						},
						
						{
							"ForwardVector",
							1,
							"HUDCenter",
							{0.2165,-0.122863},
							1
						},
						
						{
							"ForwardVector",
							1,
							"HUDCenter",
							{0.234925,-0.084038503},
							1
						},
						
						{
							"ForwardVector",
							1,
							"HUDCenter",
							{0.2462,-0.042658102},
							1
						},
						
						{
							"ForwardVector",
							1,
							"HUDCenter",
							{0.25,0},
							1
						},
						
						{
							"ForwardVector",
							1,
							"HUDCenter",
							{0.2462,0.042658102},
							1
						},
						
						{
							"ForwardVector",
							1,
							"HUDCenter",
							{0.234925,0.084038503},
							1
						},
						
						{
							"ForwardVector",
							1,
							"HUDCenter",
							{0.2165,0.122863},
							1
						},
						
						{
							"ForwardVector",
							1,
							"HUDCenter",
							{0.19149999,0.15795299},
							1
						},
						
						{
							"ForwardVector",
							1,
							"HUDCenter",
							{0.16069999,0.188226},
							1
						},
						
						{
							"ForwardVector",
							1,
							"HUDCenter",
							{0.125,0.212799},
							1
						},
						
						{
							"ForwardVector",
							1,
							"HUDCenter",
							{0.085500002,0.230909},
							1
						},
						
						{
							"ForwardVector",
							1,
							"HUDCenter",
							{0.043400001,0.241991},
							1
						},
						
						{
							"ForwardVector",
							1,
							"HUDCenter",
							{0,0.245726},
							1
						},
						
						{
							"ForwardVector",
							1,
							"HUDCenter",
							{-0.043400001,0.241991},
							1
						},
						
						{
							"ForwardVector",
							1,
							"HUDCenter",
							{-0.085500002,0.230909},
							1
						},
						
						{
							"ForwardVector",
							1,
							"HUDCenter",
							{-0.125,0.212799},
							1
						},
						
						{
							"ForwardVector",
							1,
							"HUDCenter",
							{-0.16069999,0.188226},
							1
						},
						
						{
							"ForwardVector",
							1,
							"HUDCenter",
							{-0.19149999,0.15795299},
							1
						},
						
						{
							"ForwardVector",
							1,
							"HUDCenter",
							{-0.2165,0.122863},
							1
						},
						
						{
							"ForwardVector",
							1,
							"HUDCenter",
							{-0.234925,0.084038503},
							1
						},
						
						{
							"ForwardVector",
							1,
							"HUDCenter",
							{-0.2462,0.042658102},
							1
						},
						
						{
							"ForwardVector",
							1,
							"HUDCenter",
							{-0.25,0},
							1
						},
						
						{
							"ForwardVector",
							1,
							"HUDCenter",
							{-0.2462,-0.042658102},
							1
						},
						
						{
							"ForwardVector",
							1,
							"HUDCenter",
							{-0.234925,-0.084038503},
							1
						},
						
						{
							"ForwardVector",
							1,
							"HUDCenter",
							{-0.2165,-0.122863},
							1
						},
						
						{
							"ForwardVector",
							1,
							"HUDCenter",
							{-0.19149999,-0.15795299},
							1
						},
						
						{
							"ForwardVector",
							1,
							"HUDCenter",
							{-0.16069999,-0.188226},
							1
						},
						
						{
							"ForwardVector",
							1,
							"HUDCenter",
							{-0.125,-0.212799},
							1
						},
						
						{
							"ForwardVector",
							1,
							"HUDCenter",
							{-0.085500002,-0.230909},
							1
						},
						
						{
							"ForwardVector",
							1,
							"HUDCenter",
							{-0.043400001,-0.241991},
							1
						},
						
						{
							"ForwardVector",
							1,
							"HUDCenter",
							{0,-0.245726},
							1
						}
					};
				};
			};
			class ATMissile
			{
				condition="ATmissile";
				class Circle
				{
					type="line";
					width=4;
					points[]=
					{
						
						{
							"ForwardVector",
							1,
							"HUDCenter",
							{-0.15000001,-0.14743599},
							1
						},
						
						{
							"ForwardVector",
							1,
							"HUDCenter",
							{-0.15000001,-0.12777799},
							1
						},
						{},
						
						{
							"ForwardVector",
							1,
							"HUDCenter",
							{-0.15000001,0.14743599},
							1
						},
						
						{
							"ForwardVector",
							1,
							"HUDCenter",
							{-0.15000001,0.12777799},
							1
						},
						{},
						
						{
							"ForwardVector",
							1,
							"HUDCenter",
							{0.15000001,-0.14743599},
							1
						},
						
						{
							"ForwardVector",
							1,
							"HUDCenter",
							{0.15000001,-0.12777799},
							1
						},
						{},
						
						{
							"ForwardVector",
							1,
							"HUDCenter",
							{0.15000001,0.14743599},
							1
						},
						
						{
							"ForwardVector",
							1,
							"HUDCenter",
							{0.15000001,0.12777799},
							1
						},
						{},
						
						{
							"ForwardVector",
							1,
							"HUDCenter",
							{-0.15000001,-0.14743599},
							1
						},
						
						{
							"ForwardVector",
							1,
							"HUDCenter",
							{-0.13,-0.14743599},
							1
						},
						{},
						
						{
							"ForwardVector",
							1,
							"HUDCenter",
							{-0.15000001,0.14743599},
							1
						},
						
						{
							"ForwardVector",
							1,
							"HUDCenter",
							{-0.13,0.14743599},
							1
						},
						{},
						
						{
							"ForwardVector",
							1,
							"HUDCenter",
							{0.15000001,-0.14743599},
							1
						},
						
						{
							"ForwardVector",
							1,
							"HUDCenter",
							{0.13,-0.14743599},
							1
						},
						{},
						
						{
							"ForwardVector",
							1,
							"HUDCenter",
							{0.15000001,0.14743599},
							1
						},
						
						{
							"ForwardVector",
							1,
							"HUDCenter",
							{0.13,0.14743599},
							1
						}
					};
				};
			};
			class Rockets
			{
				condition="rocket";
				class RocketDummy
				{
					type="line";
					width=3;
					points[]=
					{
						
						{
							"ImpactPoint",
							{0.0099999998,-0.0294872},
							1
						},
						
						{
							"ImpactPoint",
							{-0.0099999998,-0.0294872},
							1
						},
						{},
						
						{
							"ImpactPoint",
							{0.0099999998,0.0294872},
							1
						},
						
						{
							"ImpactPoint",
							{-0.0099999998,0.0294872},
							1
						},
						{},
						
						{
							"ImpactPoint",
							{0,-0.0294872},
							1
						},
						
						{
							"ImpactPoint",
							{0,0.0294872},
							1
						},
						{}
					};
				};
			};
			class WP
			{
				condition="wpvalid - autohover";
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
						{0.235,0.77403802},
						1
					};
					right[]=
					{
						{0.27500001,0.77403802},
						1
					};
					down[]=
					{
						{0.235,0.80155998},
						1
					};
				};
				class WPIndex
				{
					type="text";
					source="wpIndex";
					sourceScale=1;
					sourceLength=2;
					align="right";
					scale=1;
					pos[]=
					{
						{0.096000001,0.77600402},
						1
					};
					right[]=
					{
						{0.126,0.77600402},
						1
					};
					down[]=
					{
						{0.096000001,0.79959399},
						1
					};
				};
				class WPstatic
				{
					type="text";
					source="static";
					text="W";
					scale=1;
					sourceScale=1;
					align="right";
					pos[]=
					{
						{0.075000003,0.77499998},
						1
					};
					right[]=
					{
						{0.105,0.77499998},
						1
					};
					down[]=
					{
						{0.075000003,0.80000001},
						1
					};
				};
				class WPAuto
				{
					type="text";
					source="static";
					text="A";
					scale=1;
					sourceScale=1;
					align="right";
					pos[]=
					{
						
						{
							"0.075 +0.035",
							0.80000001
						},
						1
					};
					right[]=
					{
						{0.14,0.80000001},
						1
					};
					down[]=
					{
						
						{
							"0.075 +0.035",
							0.82499999
						},
						1
					};
				};
				class WPKM
				{
					type="text";
					source="static";
					text="KM";
					scale=1;
					sourceScale=1;
					align="right";
					pos[]=
					{
						
						{
							"0.075 +0.16",
							0.77499998
						},
						1
					};
					right[]=
					{
						{0.26499999,0.77499998},
						1
					};
					down[]=
					{
						
						{
							"0.075 +0.16",
							0.80299997
						},
						1
					};
				};
				class WPTime
				{
					type="text";
					source="static";
					text="-:--";
					scale=1;
					sourceScale=1;
					align="right";
					pos[]=
					{
						
						{
							"0.075 +0.11",
							0.80000001
						},
						1
					};
					right[]=
					{
						{0.215,0.80000001},
						1
					};
					down[]=
					{
						
						{
							"0.075 +0.11",
							0.82499999
						},
						1
					};
				};
				class WP
				{
					width=2;
					type="line";
					points[]=
					{
						
						{
							"WPPoint",
							1,
							"LimitWaypoint",
							1,
							{-0.02,0.039999999},
							1
						},
						
						{
							"WPPoint",
							1,
							"LimitWaypoint",
							1,
							{0,0.02},
							1
						},
						
						{
							"WPPoint",
							1,
							"LimitWaypoint",
							1,
							{0.02,0.039999999},
							1
						},
						{}
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
						{0.493,0.76666701},
						1
					};
					right[]=
					{
						{0.55299997,0.76666701},
						1
					};
					down[]=
					{
						{0.493,0.81581199},
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
			class RadarTargets
			{
				class RadarBoxes
				{
					type="radartoview";
					pos0[]={0.5,0.5};
					pos10[]={0.73400003,0.73000002};
					width=4;
					points[]=
					{
						
						{
							{-0.0035000001,-0.0034401701},
							1
						},
						
						{
							{0.0035000001,-0.0034401701},
							1
						},
						
						{
							{0.0035000001,0.0034401701},
							1
						},
						
						{
							{-0.0035000001,0.0034401701},
							1
						},
						
						{
							{-0.0035000001,-0.0034401701},
							1
						}
					};
				};
			};
			class TargetDiamond
			{
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
							1,
							{0.0074999998,0},
							1
						},
						
						{
							"Target",
							1,
							"Limit0109",
							1,
							{0.0125,0},
							1
						},
						{},
						
						{
							"Target",
							1,
							"Limit0109",
							1,
							{0.0175,0},
							1
						},
						
						{
							"Target",
							1,
							"Limit0109",
							1,
							{0.022500001,0},
							1
						},
						{},
						
						{
							"Target",
							1,
							"Limit0109",
							1,
							{0.0275,0},
							1
						},
						
						{
							"Target",
							1,
							"Limit0109",
							1,
							{0.032499999,0},
							1
						},
						{},
						
						{
							"Target",
							1,
							"Limit0109",
							1,
							{0.037500001,0},
							1
						},
						
						{
							"Target",
							1,
							"Limit0109",
							1,
							{0.0425,0},
							1
						},
						{},
						
						{
							"Target",
							1,
							"Limit0109",
							1,
							{0.047499999,0},
							1
						},
						
						{
							"Target",
							1,
							"Limit0109",
							1,
							{0.052499998,0},
							1
						},
						{},
						
						{
							"Target",
							1,
							"Limit0109",
							1,
							{-0.0074999998,0},
							1
						},
						
						{
							"Target",
							1,
							"Limit0109",
							1,
							{-0.0125,0},
							1
						},
						{},
						
						{
							"Target",
							1,
							"Limit0109",
							1,
							{-0.0175,0},
							1
						},
						
						{
							"Target",
							1,
							"Limit0109",
							1,
							{-0.022500001,0},
							1
						},
						{},
						
						{
							"Target",
							1,
							"Limit0109",
							1,
							{-0.0275,0},
							1
						},
						
						{
							"Target",
							1,
							"Limit0109",
							1,
							{-0.032499999,0},
							1
						},
						{},
						
						{
							"Target",
							1,
							"Limit0109",
							1,
							{-0.037500001,0},
							1
						},
						
						{
							"Target",
							1,
							"Limit0109",
							1,
							{-0.0425,0},
							1
						},
						{},
						
						{
							"Target",
							1,
							"Limit0109",
							1,
							{-0.047499999,0},
							1
						},
						
						{
							"Target",
							1,
							"Limit0109",
							1,
							{-0.052499998,0},
							1
						},
						{},
						
						{
							"Target",
							1,
							"Limit0109",
							1,
							{0,0.0073717898},
							1
						},
						
						{
							"Target",
							1,
							"Limit0109",
							1,
							{0,0.0122863},
							1
						},
						{},
						
						{
							"Target",
							1,
							"Limit0109",
							1,
							{0,0.0172009},
							1
						},
						
						{
							"Target",
							1,
							"Limit0109",
							1,
							{0,0.0221154},
							1
						},
						{},
						
						{
							"Target",
							1,
							"Limit0109",
							1,
							{0,0.0270299},
							1
						},
						
						{
							"Target",
							1,
							"Limit0109",
							1,
							{0,0.031944402},
							1
						},
						{},
						
						{
							"Target",
							1,
							"Limit0109",
							1,
							{0,0.036858998},
							1
						},
						
						{
							"Target",
							1,
							"Limit0109",
							1,
							{0,0.041773502},
							1
						},
						{},
						
						{
							"Target",
							1,
							"Limit0109",
							1,
							{0,0.046688002},
							1
						},
						
						{
							"Target",
							1,
							"Limit0109",
							1,
							{0,0.051602598},
							1
						},
						{},
						
						{
							"Target",
							1,
							"Limit0109",
							1,
							{0,-0.0073717898},
							1
						},
						
						{
							"Target",
							1,
							"Limit0109",
							1,
							{0,-0.0122863},
							1
						},
						{},
						
						{
							"Target",
							1,
							"Limit0109",
							1,
							{0,-0.0172009},
							1
						},
						
						{
							"Target",
							1,
							"Limit0109",
							1,
							{0,-0.0221154},
							1
						},
						{},
						
						{
							"Target",
							1,
							"Limit0109",
							1,
							{0,-0.0270299},
							1
						},
						
						{
							"Target",
							1,
							"Limit0109",
							1,
							{0,-0.031944402},
							1
						},
						{},
						
						{
							"Target",
							1,
							"Limit0109",
							1,
							{0,-0.036858998},
							1
						},
						
						{
							"Target",
							1,
							"Limit0109",
							1,
							{0,-0.041773502},
							1
						},
						{},
						
						{
							"Target",
							1,
							"Limit0109",
							1,
							{0,-0.046688002},
							1
						},
						
						{
							"Target",
							1,
							"Limit0109",
							1,
							{0,-0.051602598},
							1
						},
						{}
					};
				};
			};
			class TargetLocked
			{
				condition="missilelocked";
				class TargetLockedText
				{
					type="text";
					source="static";
					text="VALID LOCK";
					scale=1;
					sourceScale=1;
					align="center";
					pos[]=
					{
						{0.493,0.77899998},
						1
					};
					right[]=
					{
						{0.53299999,0.77899998},
						1
					};
					down[]=
					{
						{0.493,0.81},
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
					align="right";
					pos[]=
					{
						
						{
							"0.127+0.49",
							0.86900002
						},
						1
					};
					right[]=
					{
						{0.65200001,0.86900002},
						1
					};
					down[]=
					{
						
						{
							"0.127+0.49",
							0.90399998
						},
						1
					};
				};
				class DistanceText
				{
					type="text";
					source="static";
					text="DIST:";
					scale=1;
					sourceScale=1;
					align="right";
					pos[]=
					{
						
						{
							"0.125+0.49",
							0.90100002
						},
						1
					};
					right[]=
					{
						{0.64999998,0.90100002},
						1
					};
					down[]=
					{
						
						{
							"0.125+0.49",
							0.93599999
						},
						1
					};
				};
				class TOF_source
				{
					type="text";
					scale=1;
					sourceScale=1;
					source="missileflighttime";
					align="right";
					pos[]=
					{
						{0.73900002,0.86900002},
						1
					};
					right[]=
					{
						{0.77399999,0.86900002},
						1
					};
					down[]=
					{
						{0.73900002,0.90399998},
						1
					};
				};
				class TargetDistance: TOF_source
				{
					source="targetDist";
					sourceLength=0;
					sourcePrecision=1;
					sourceScale=0.001;
					align="right";
					pos[]=
					{
						{0.73900002,0.90100002},
						1
					};
					right[]=
					{
						{0.77399999,0.90100002},
						1
					};
					down[]=
					{
						{0.73900002,0.93599999},
						1
					};
				};
			};
		};
	};
};



class MFD
		{
			class MFD_Pilot_1
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
									{0.50142902,0.49276599},
									1
								},
								
								{
									{0.505,0.49276599},
									1
								},
								
								{
									{0.505,0.49780199},
									1
								},
								
								{
									{0.50142902,0.49780199},
									1
								},
								
								{
									{0.50142902,0.49276599},
									1
								},
								{},
								
								{
									{0.50928599,0.49578801},
									1
								},
								
								{
									{0.587143,0.49578801},
									1
								},
								{},
								
								{
									{0.50285703,0.50283903},
									1
								},
								
								{
									{0.50285703,0.59752798},
									1
								},
								{},
								
								{
									{0.49857101,0.49578801},
									1
								},
								
								{
									{0.41999999,0.49578801},
									1
								},
								{},
								
								{
									{0.50285703,0.39404801},
									1
								},
								
								{
									{0.50285703,0.48672199},
									1
								},
								{},
								
								{
									{0.62,0.339652},
									1
								},
								
								{
									{0.65285701,0.339652},
									1
								},
								
								{
									{0.65285701,0.382967},
									1
								},
								{},
								
								{
									{0.65285701,0.615659},
									1
								},
								
								{
									{0.65285701,0.65998203},
									1
								},
								
								{
									{0.62071401,0.65998203},
									1
								},
								{},
								
								{
									{0.38428599,0.65998203},
									1
								},
								
								{
									{0.35142899,0.65998203},
									1
								},
								
								{
									{0.35142899,0.615659},
									1
								},
								{},
								
								{
									{0.38428599,0.339652},
									1
								},
								
								{
									{0.35142899,0.339652},
									1
								},
								
								{
									{0.35142899,0.382967},
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
								{0.33000001,0.81},
								1
							};
							right[]=
							{
								{0.37,0.81},
								1
							};
							down[]=
							{
								{0.33000001,0.84500003},
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
								{0.47999999,0.81},
								1
							};
							right[]=
							{
								{0.51999998,0.81},
								1
							};
							down[]=
							{
								{0.47999999,0.84500003},
								1
							};
						};
					};
				};
			};
			class MFD_Pilot_2
			{
				topLeft="MFD_2_TL";
				topRight="MFD_2_TR";
				bottomLeft="MFD_2_BL";
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
				turret[]={-2};
				class Bones
				{
				};
				class Draw
				{
					alpha=1;
					color[]={0,0.12,0};
					condition="on";
					class Time
					{
						type="text";
						source="time";
						text="%X";
						sourceScale=1;
						align="right";
						scale=1;
						pos[]=
						{
							{0.029999999,0.11},
							1
						};
						right[]=
						{
							{0.13,0.11},
							1
						};
						down[]=
						{
							{0.029999999,0.2},
							1
						};
					};
					class Fuel
					{
						type="text";
						source="fuel";
						text="%X";
						sourceScale=2517;
						sourceLength=4;
						align="right";
						scale=1;
						pos[]=
						{
							{0.029999999,0.31},
							1
						};
						right[]=
						{
							{0.13,0.31},
							1
						};
						down[]=
						{
							{0.029999999,0.40000001},
							1
						};
					};
					class LBSText
					{
						type="text";
						source="static";
						text="LBS";
						scale=1;
						sourceScale=1;
						align="right";
						pos[]=
						{
							{0.30000001,0.31},
							1
						};
						right[]=
						{
							{0.40000001,0.31},
							1
						};
						down[]=
						{
							{0.30000001,0.40000001},
							1
						};
					};
					class GridX
					{
						type="text";
						source="coordinateX";
						sourceScale=0.0099999998;
						sourceOffset=-0.5;
						sourceLength=3;
						align="right";
						scale=1;
						pos[]=
						{
							{0.029999999,0.61000001},
							1
						};
						right[]=
						{
							{0.13,0.61000001},
							1
						};
						down[]=
						{
							{0.029999999,0.69999999},
							1
						};
					};
					class GridY: GridX
					{
						source="coordinateY";
						pos[]=
						{
							{0.23999999,0.61000001},
							1
						};
						right[]=
						{
							{0.34,0.61000001},
							1
						};
						down[]=
						{
							{0.23999999,0.69999999},
							1
						};
					};
					class GridText
					{
						type="text";
						source="static";
						text="GRID:";
						scale=1;
						sourceScale=1;
						align="right";
						pos[]=
						{
							{0.029999999,0.50999999},
							1
						};
						right[]=
						{
							{0.13,0.50999999},
							1
						};
						down[]=
						{
							{0.029999999,0.60000002},
							1
						};
					};
				};
			};
			class MFD_Pilot_3
			{
				topLeft="MFD_3_TL";
				topRight="MFD_3_TR";
				bottomLeft="MFD_3_BL";
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
				turret[]={-2};
				class Bones
				{
				};
				class Draw
				{
					alpha=1;
					color[]={0,0.12,0};
					condition="on";
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
								{0.22,0.2},
								1
							};
							right[]=
							{
								{0.28,0.2},
								1
							};
							down[]=
							{
								{0.22,0.23999999},
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
								{0.22,0.2},
								1
							};
							right[]=
							{
								{0.28,0.2},
								1
							};
							down[]=
							{
								{0.22,0.23999999},
								1
							};
						};
					};
					class SpeedNumber
					{
						type="text";
						source="speed";
						sourceScale=3.5999999;
						align="left";
						scale=1;
						pos[]=
						{
							{0.28,0.45199999},
							1
						};
						right[]=
						{
							{0.31999999,0.45199999},
							1
						};
						down[]=
						{
							{0.28,0.49200001},
							1
						};
					};
					class AltNumber
					{
						type="text";
						source="altitudeAGL";
						sourceScale=1;
						sourceOffset=-2;
						align="left";
						scale=1;
						pos[]=
						{
							{0.75,0.45199999},
							1
						};
						right[]=
						{
							{0.79000002,0.45199999},
							1
						};
						down[]=
						{
							{0.75,0.49200001},
							1
						};
					};
					class CruiseMode
					{
						condition="1+((altitudeASL-27) min 1) - autohover";
						class AltNumberASL
						{
							type="text";
							source="altitudeASL";
							sourceScale=1;
							align="left";
							scale=1;
							pos[]=
							{
								{0.81,0.16},
								1
							};
							right[]=
							{
								{0.85000002,0.16},
								1
							};
							down[]=
							{
								{0.81,0.2},
								1
							};
						};
					};
				};
			};
			class MFD_Pilot_5: MFD_Pilot_1
			{
				topLeft="MFD_5_TL";
				topRight="MFD_5_TR";
				bottomLeft="MFD_5_BL";
				turret[]={0};
				class Draw
				{
					color[]={0,0.12,0};
					condition="on";
					class BlackBackgroundGroup
					{
						color[]={0,0,0};
						class BlackBackground
						{
							type="polygon";
							points[]=
							{
								
								{
									
									{
										{0,0.1},
										1
									},
									
									{
										{1,0.1},
										1
									},
									
									{
										{1,1},
										1
									},
									
									{
										{0,1},
										1
									}
								}
							};
						};
					};
					class ReticleGroup
					{
						color[]={0,0.12,0};
						class Reticle
						{
							type="line";
							width=4;
							points[]=
							{
								
								{
									{0.43000001,0.49059799},
									1
								},
								
								{
									{0.164,0.49059799},
									1
								},
								
								{
									{0.164,0.49059799},
									1
								},
								
								{
									{0.164,0.630171},
									1
								},
								
								{
									{0.164,0.630171},
									1
								},
								
								{
									{0.43799999,0.630171},
									1
								},
								
								{
									{0.43799999,0.630171},
									1
								},
								
								{
									{0.43799999,0.73239303},
									1
								},
								
								{
									{0.62199998,0.73239303},
									1
								},
								
								{
									{0.62199998,0.630171},
									1
								},
								
								{
									{0.62199998,0.630171},
									1
								},
								
								{
									{0.898,0.630171},
									1
								},
								
								{
									{0.898,0.630171},
									1
								},
								
								{
									{0.898,0.49059799},
									1
								},
								
								{
									{0.63,0.49059799},
									1
								},
								
								{
									{0.63,0.49059799},
									1
								},
								
								{
									{0.616,0.48273501},
									1
								},
								
								{
									{0.616,0.29794899},
									1
								},
								
								{
									{0.59200001,0.29794899},
									1
								},
								
								{
									{0.55800003,0.286154},
									1
								},
								
								{
									{0.55800003,0.27239299},
									1
								},
								
								{
									{0.5,0.27239299},
									1
								},
								
								{
									{0.5,0.286154},
									1
								},
								
								{
									{0.46799999,0.29794899},
									1
								},
								
								{
									{0.44600001,0.29794899},
									1
								},
								
								{
									{0.44600001,0.48273501},
									1
								},
								
								{
									{0.43000001,0.49059799},
									1
								},
								{},
								
								{
									{0.46000001,0.60000002},
									1
								},
								
								{
									{0.60000002,0.60000002},
									1
								},
								
								{
									{0.60000002,0.72000003},
									1
								},
								
								{
									{0.46000001,0.72000003},
									1
								},
								
								{
									{0.46000001,0.60000002},
									1
								},
								{},
								
								{
									{0.039999999,0.80000001},
									1
								},
								
								{
									{0.23999999,0.80000001},
									1
								},
								
								{
									{0.23999999,0.86000001},
									1
								},
								
								{
									{0.039999999,0.86000001},
									1
								},
								
								{
									{0.039999999,0.80000001},
									1
								},
								{},
								
								{
									{-0.059999999,0.82999998},
									1
								},
								
								{
									{0.039999999,0.82999998},
									1
								},
								{},
								
								{
									{0.039999999,0.93000001},
									1
								},
								
								{
									{0.23999999,0.93000001},
									1
								},
								
								{
									{0.23999999,0.99000001},
									1
								},
								
								{
									{0.039999999,0.99000001},
									1
								},
								
								{
									{0.039999999,0.93000001},
									1
								},
								{},
								
								{
									{-0.059999999,0.95999998},
									1
								},
								
								{
									{0.039999999,0.95999998},
									1
								},
								{},
								
								{
									{0.27000001,0.86000001},
									1
								},
								
								{
									{0.82999998,0.86000001},
									1
								},
								
								{
									{0.82999998,0.98000002},
									1
								},
								
								{
									{0.27000001,0.98000002},
									1
								},
								
								{
									{0.27000001,0.86000001},
									1
								},
								{},
								
								{
									{0.23,0.18000001},
									1
								},
								
								{
									{0.37,0.18000001},
									1
								},
								
								{
									{0.37,0.25999999},
									1
								},
								
								{
									{0.23,0.25999999},
									1
								},
								
								{
									{0.23,0.18000001},
									1
								},
								{},
								
								{
									{0.69999999,0.18000001},
									1
								},
								
								{
									{0.83999997,0.18000001},
									1
								},
								
								{
									{0.83999997,0.25999999},
									1
								},
								
								{
									{0.69999999,0.25999999},
									1
								},
								
								{
									{0.69999999,0.18000001},
									1
								},
								{},
								
								{
									{0.23999999,0.28999999},
									1
								},
								
								{
									{0.36000001,0.28999999},
									1
								},
								
								{
									{0.36000001,0.37},
									1
								},
								
								{
									{0.23999999,0.37},
									1
								},
								
								{
									{0.23999999,0.28999999},
									1
								},
								{},
								
								{
									{0.70999998,0.28999999},
									1
								},
								
								{
									{0.82999998,0.28999999},
									1
								},
								
								{
									{0.82999998,0.37},
									1
								},
								
								{
									{0.70999998,0.37},
									1
								},
								
								{
									{0.70999998,0.28999999},
									1
								},
								{}
							};
						};
						class SightSelect1
						{
							type="text";
							source="static";
							text="SIGHT";
							scale=1;
							sourceScale=1;
							align="right";
							pos[]=
							{
								
								{
									"0.53-0.29",
									0.18700001
								},
								1
							};
							right[]=
							{
								{0.28,0.18700001},
								1
							};
							down[]=
							{
								
								{
									"0.53-0.29",
									0.222
								},
								1
							};
						};
						class SightSelect2
						{
							type="text";
							source="static";
							text="FCR";
							scale=1;
							sourceScale=1;
							align="right";
							pos[]=
							{
								
								{
									"0.53-0.29",
									0.227
								},
								1
							};
							right[]=
							{
								{0.28,0.227},
								1
							};
							down[]=
							{
								
								{
									"0.53-0.29",
									0.26199999
								},
								1
							};
						};
						class AcqSelect1
						{
							type="text";
							source="static";
							text="ACQ";
							scale=1;
							sourceScale=1;
							align="left";
							pos[]=
							{
								
								{
									"0.53+0.29",
									0.18700001
								},
								1
							};
							right[]=
							{
								{0.86000001,0.18700001},
								1
							};
							down[]=
							{
								
								{
									"0.53+0.29",
									0.222
								},
								1
							};
						};
						class AcqSelect2
						{
							type="text";
							source="static";
							text="FCR";
							scale=1;
							sourceScale=1;
							align="left";
							pos[]=
							{
								
								{
									"0.53+0.29",
									0.227
								},
								1
							};
							right[]=
							{
								{0.86000001,0.227},
								1
							};
							down[]=
							{
								
								{
									"0.53+0.29",
									0.26199999
								},
								1
							};
						};
						class LSTSelect1
						{
							type="text";
							source="static";
							text="LST";
							scale=1;
							sourceScale=1;
							align="center";
							pos[]=
							{
								
								{
									"0.53-0.23",
									0.29699999
								},
								1
							};
							right[]=
							{
								{0.34,0.29699999},
								1
							};
							down[]=
							{
								
								{
									"0.53-0.23",
									0.33199999
								},
								1
							};
						};
						class LSTSelect2
						{
							type="text";
							source="static";
							text="A";
							scale=1;
							sourceScale=1;
							align="center";
							pos[]=
							{
								
								{
									"0.53-0.23",
									0.33700001
								},
								1
							};
							right[]=
							{
								{0.34,0.33700001},
								1
							};
							down[]=
							{
								
								{
									"0.53-0.23",
									0.37200001
								},
								1
							};
						};
						class LRFDSelect1
						{
							type="text";
							source="static";
							text="LRFD";
							scale=1;
							sourceScale=1;
							align="center";
							pos[]=
							{
								
								{
									"0.53+0.24",
									0.29699999
								},
								1
							};
							right[]=
							{
								{0.81,0.29699999},
								1
							};
							down[]=
							{
								
								{
									"0.53+0.24",
									0.33199999
								},
								1
							};
						};
						class LRFDSelect2
						{
							type="text";
							source="static";
							text="B";
							scale=1;
							sourceScale=1;
							align="center";
							pos[]=
							{
								
								{
									"0.53+0.24",
									0.33700001
								},
								1
							};
							right[]=
							{
								{0.81,0.33700001},
								1
							};
							down[]=
							{
								
								{
									"0.53+0.24",
									0.37200001
								},
								1
							};
						};
						class PilotText
						{
							type="text";
							source="static";
							text="PILOT";
							scale=1;
							sourceScale=1;
							align="right";
							pos[]=
							{
								
								{
									"0.53-0.48",
									0.815
								},
								1
							};
							right[]=
							{
								{0.090000004,0.815},
								1
							};
							down[]=
							{
								
								{
									"0.53-0.48",
									0.85000002
								},
								1
							};
						};
						class CopilotText
						{
							type="text";
							source="static";
							text="COPILOT";
							scale=1;
							sourceScale=1;
							align="right";
							pos[]=
							{
								
								{
									"0.53-0.48",
									0.94499999
								},
								1
							};
							right[]=
							{
								{0.090000004,0.94499999},
								1
							};
							down[]=
							{
								
								{
									"0.53-0.48",
									0.98000002
								},
								1
							};
						};
						class PylonText6
						{
							type="text";
							source="static";
							text="#6";
							scale=1;
							sourceScale=1;
							align="center";
							pos[]=
							{
								
								{
									"0.53-0.31 + 0.00",
									0.55000001
								},
								1
							};
							right[]=
							{
								{0.25999999,0.55000001},
								1
							};
							down[]=
							{
								
								{
									"0.53-0.31 + 0.00",
									0.58499998
								},
								1
							};
						};
						class PylonText5
						{
							type="text";
							source="static";
							text="#5";
							scale=1;
							sourceScale=1;
							align="center";
							pos[]=
							{
								
								{
									"0.53-0.31 + 0.09",
									0.55000001
								},
								1
							};
							right[]=
							{
								{0.34999999,0.55000001},
								1
							};
							down[]=
							{
								
								{
									"0.53-0.31 + 0.09",
									0.58499998
								},
								1
							};
						};
						class PylonText4
						{
							type="text";
							source="static";
							text="#4";
							scale=1;
							sourceScale=1;
							align="center";
							pos[]=
							{
								
								{
									"0.53-0.31 + 0.09*2",
									0.55000001
								},
								1
							};
							right[]=
							{
								{0.44,0.55000001},
								1
							};
							down[]=
							{
								
								{
									"0.53-0.31 + 0.09*2",
									0.58499998
								},
								1
							};
						};
						class PylonText3
						{
							type="text";
							source="static";
							text="#3";
							scale=1;
							sourceScale=1;
							align="center";
							pos[]=
							{
								
								{
									"0.53+0.31 - 0.09*2",
									0.55000001
								},
								1
							};
							right[]=
							{
								{0.69999999,0.55000001},
								1
							};
							down[]=
							{
								
								{
									"0.53+0.31 - 0.09*2",
									0.58499998
								},
								1
							};
						};
						class PylonText2
						{
							type="text";
							source="static";
							text="#2";
							scale=1;
							sourceScale=1;
							align="center";
							pos[]=
							{
								
								{
									"0.53+0.31 - 0.09",
									0.55000001
								},
								1
							};
							right[]=
							{
								{0.79000002,0.55000001},
								1
							};
							down[]=
							{
								
								{
									"0.53+0.31 - 0.09",
									0.58499998
								},
								1
							};
						};
						class PylonText1
						{
							type="text";
							source="static";
							text="#1";
							scale=1;
							sourceScale=1;
							align="center";
							pos[]=
							{
								
								{
									"0.53+0.31 - 0.00",
									0.55000001
								},
								1
							};
							right[]=
							{
								{0.88,0.55000001},
								1
							};
							down[]=
							{
								
								{
									"0.53+0.31 - 0.00",
									0.58499998
								},
								1
							};
						};
						class CurrentWeaponText
						{
							type="text";
							source="static";
							text="WEAPON";
							scale=1;
							sourceScale=1;
							align="center";
							pos[]=
							{
								{0.55000001,0.81999999},
								1
							};
							right[]=
							{
								{0.58999997,0.81999999},
								1
							};
							down[]=
							{
								{0.55000001,0.85500002},
								1
							};
						};
						class Weapons
						{
							type="text";
							source="weapon";
							sourceScale=1;
							align="center";
							scale=1;
							pos[]=
							{
								{0.55000001,0.87},
								1
							};
							right[]=
							{
								{0.58999997,0.87},
								1
							};
							down[]=
							{
								{0.55000001,0.90499997},
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
								{0.55000001,0.92000002},
								1
							};
							right[]=
							{
								{0.58999997,0.92000002},
								1
							};
							down[]=
							{
								{0.55000001,0.95499998},
								1
							};
						};
					};
					class MGun
					{
						class Default
						{
							condition="ammo0 > 0";
							color[]={0,0.12,0};
							class Shape
							{
								type="line";
								width=4;
								points[]=
								{
									
									{
										{0.55599999,0.38641},
										1
									},
									
									{
										{0.50199997,0.38641},
										1
									},
									
									{
										{0.458,0.38641},
										1
									},
									
									{
										{0.458,0.44931599},
										1
									},
									
									{
										{0.60000002,0.44931599},
										1
									},
									
									{
										{0.60000002,0.38641},
										1
									},
									
									{
										{0.55599999,0.38641},
										1
									},
									{},
									
									{
										{0.50199997,0.38641},
										1
									},
									
									{
										{0.50199997,0.32547},
										1
									},
									
									{
										{0.52200001,0.32547},
										1
									},
									
									{
										{0.52200001,0.284188},
										1
									},
									
									{
										{0.54000002,0.284188},
										1
									},
									
									{
										{0.54000002,0.327436},
										1
									},
									
									{
										{0.55599999,0.327436},
										1
									},
									
									{
										{0.55599999,0.38641},
										1
									},
									
									{
										{0.50199997,0.38641},
										1
									}
								};
							};
							class Ammo
							{
								type="text";
								source="ammo";
								sourceIndex=0;
								sourceScale=1;
								sourceLength=4;
								align="center";
								scale=1;
								pos[]=
								{
									{0.52999997,0.41},
									1
								};
								right[]=
								{
									{0.56999999,0.41},
									1
								};
								down[]=
								{
									{0.52999997,0.44499999},
									1
								};
							};
						};
						class Selected: Default
						{
							condition="(mgun +  (ammo0 min 1))/2";
							color[]={0.99000001,0.94,0.58999997};
							class Shape: Shape
							{
							};
							class Ammo: Ammo
							{
							};
						};
						class Empty: Default
						{
							condition="ammo0 <= 0";
							color[]={1,0,0,1};
							class Shape: Shape
							{
							};
							class Ammo: Ammo
							{
								source="static";
								text="EMPTY";
							};
						};
					};
					class Pylon1
					{
						type="pylonicon";
						pos[]=
						{
							{0.81999999,0.5},
							1
						};
						pylon=1;
						name="Heli_Attack_01";
					};
					class Pylon2: Pylon1
					{
						pos[]=
						{
							{0.73000002,0.5},
							1
						};
						pylon=2;
					};
					class Pylon3: Pylon1
					{
						pos[]=
						{
							{0.63999999,0.5},
							1
						};
						pylon=3;
					};
					class Pylon4: Pylon1
					{
						pos[]=
						{
							{0.36000001,0.5},
							1
						};
						pylon=4;
					};
					class Pylon5: Pylon1
					{
						pos[]=
						{
							{0.27000001,0.5},
							1
						};
						pylon=5;
					};
					class Pylon6: Pylon1
					{
						pos[]=
						{
							{0.18000001,0.5},
							1
						};
						pylon=6;
					};
					class ExternalPylon
					{
						color[]={0,0.12,0};
						class DrawLine
						{
							type="line";
							width=4;
							points[]=
							{
								
								{
									{0.16,0.77999997},
									1
								},
								
								{
									{0.88,0.77999997},
									1
								},
								
								{
									{0.88,0.68000001},
									1
								},
								
								{
									{0.64999998,0.68000001},
									1
								},
								{},
								
								{
									{0.41,0.68000001},
									1
								},
								
								{
									{0.16,0.68000001},
									1
								},
								
								{
									{0.16,0.77999997},
									1
								}
							};
						};
						class ExternalPylonsText
						{
							type="text";
							source="static";
							text="EXT PYLONS";
							scale=1;
							sourceScale=1;
							align="center";
							pos[]=
							{
								{0.51999998,0.75},
								1
							};
							right[]=
							{
								{0.55500001,0.75},
								1
							};
							down[]=
							{
								{0.51999998,0.77499998},
								1
							};
						};
						class Pylon7: Pylon1
						{
							pos[]=
							{
								{0.27000001,0.69999999},
								1
							};
							pylon=7;
						};
						class Pylon8: Pylon1
						{
							pos[]=
							{
								{0.73000002,0.69999999},
								1
							};
							pylon=8;
						};
					};
					class ArmBackground
					{
						color[]={0.19,0.039999999,0};
						class BlackBackground
						{
							type="polygon";
							points[]=
							{
								
								{
									
									{
										
										{
											"0.0+0.48",
											"0.0+0.14"
										},
										1
									},
									
									{
										
										{
											"0.1+0.48",
											"0.0+0.14"
										},
										1
									},
									
									{
										
										{
											"0.1+0.48",
											"0.1+0.14"
										},
										1
									},
									
									{
										
										{
											"0.0+0.48",
											"0.1+0.14"
										},
										1
									}
								}
							};
						};
					};
					class BlackText
					{
						color[]={0.15000001,0.0099999998,0};
						class CMText
						{
							type="text";
							source="static";
							text="ARM";
							scale=1;
							sourceScale=1;
							align="center";
							pos[]=
							{
								{0.52999997,0.17},
								1
							};
							right[]=
							{
								{0.56999999,0.17},
								1
							};
							down[]=
							{
								{0.52999997,0.205},
								1
							};
						};
					};
				};
			};
			class MFD_Pilot_5_CM: MFD_Pilot_5
			{
				topLeft="MFD_5_TL";
				topRight="MFD_5_TR";
				bottomLeft="MFD_5_BL";
				turret[]={-1};
				class Draw
				{
					color[]={0,0.12,0};
					condition="on";
					class CMText
					{
						type="text";
						source="static";
						text="CM";
						scale=1;
						sourceScale=1;
						align="center";
						pos[]=
						{
							{0.52999997,0.61000001},
							1
						};
						right[]=
						{
							{0.56999999,0.61000001},
							1
						};
						down[]=
						{
							{0.52999997,0.64499998},
							1
						};
					};
					class CMAmmo
					{
						type="text";
						source="cmammo";
						sourceScale=1;
						sourceLength=3;
						align="center";
						scale=1;
						pos[]=
						{
							{0.52999997,0.66000003},
							1
						};
						right[]=
						{
							{0.56999999,0.66000003},
							1
						};
						down[]=
						{
							{0.52999997,0.69499999},
							1
						};
					};
				};
			};
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
					class WeaponAim
					{
						type="vector";
						source="weapon";
						pos0[]={0.5,0.5};
						pos10[]={0.73400003,0.73000002};
					};
					class WeaponAimRelative: WeaponAim
					{
						source="weapontoview";
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
					class HorizonVector
					{
						type="horizontoview";
						pos0[]={0.5,0.5};
						pos10[]={0.83092302,0.825266};
						angle=0;
					};
					class GunnerAim
					{
						type="vector";
						source="turret";
						pos0[]={0,-2};
						pos10[]={0.0068000001,-0.0099999998};
						projection=0;
					};
					class VerticalSpeedBone
					{
						type="linear";
						source="vspeed";
						sourceScale=1;
						min=-10;
						max=10;
						minPos[]={0,-0.31999999};
						maxPos[]={0,0.31999999};
					};
					class HorizonBankRot
					{
						type="linear";
						source="horizonBank";
						min=-0.52359998;
						max=0.52359998;
						minPos[]={0.41,0.83999997};
						maxPos[]={0.58999997,0.83999997};
						aspectRatio=1;
					};
					class ImpactPoint
					{
						type="vector";
						source="ImpactPointToView";
						pos0[]={0.5,0.5};
						pos10[]={0.73400003,0.73000002};
					};
					class Target
					{
						source="targettoview";
						type="vector";
						pos0[]={0.5,0.5};
						pos10[]={0.73400003,0.73000002};
					};
					class Limit0109
					{
						type="limit";
						limits[]={0.1,0.1,0.89999998,0.89999998};
					};
					class LimitWaypoint
					{
						type="limit";
						limits[]={0.2,0.1,0.80000001,0.1};
					};
					class WPPoint
					{
						type="vector";
						source="WPPoint";
						pos0[]={0.5,0.5};
						pos10[]={0.73400003,0.73000002};
					};
					class WPPointToView: WPPoint
					{
						source="WPPointToView";
					};
					class RadarHeight
					{
						type="linear";
						source="altitudeAGL";
						sourceScale=1;
						sourceOffset=-2;
						min=0;
						max=100;
						minPos[]={0.903,0.18000001};
						maxPos[]={0.903,0.81999999};
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
					class Static
					{
						type="line";
						width=4;
						points[]=
						{
							
							{
								{0.5,0.11},
								1
							},
							
							{
								{0.5,0.14},
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
								{0.40000001,0.88499999},
								1
							},
							
							{
								{0.40799999,0.88499999},
								1
							},
							{},
							
							{
								{0.60000002,0.88499999},
								1
							},
							
							{
								{0.59200001,0.88499999},
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
								{0.51999998,0.86000001},
								1
							},
							
							{
								{0.51999998,0.81999999},
								1
							},
							{},
							
							{
								{0.47999999,0.86000001},
								1
							},
							
							{
								{0.47999999,0.81999999},
								1
							},
							{},
							
							{
								{0.55000001,0},
								1
							},
							
							{
								{0.55000001,0.039999999},
								1
							},
							
							{
								{0.44999999,0.039999999},
								1
							},
							
							{
								{0.44999999,0},
								1
							},
							
							{
								{0.55000001,0},
								1
							}
						};
					};
					class HeadingNumber
					{
						type="text";
						source="Heading";
						sourceScale=1;
						align="center";
						scale=1;
						pos[]=
						{
							{0.5,0.0060000001},
							1
						};
						right[]=
						{
							{0.55000001,0.0060000001},
							1
						};
						down[]=
						{
							{0.5,0.046},
							1
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
									"0.082-0.025"
								},
								1
							};
							right[]=
							{
								
								{
									"0.83-0.302",
									"0.082-0.025"
								},
								1
							};
							down[]=
							{
								
								{
									"0.80-0.302",
									"0.113-0.025"
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
									{0.47799999,0.045000002},
									1
								},
								
								{
									{0.52200001,0.045000002},
									1
								},
								
								{
									{0.55199999,0.07},
									1
								},
								
								{
									{0.52200001,0.094999999},
									1
								},
								
								{
									{0.47799999,0.094999999},
									1
								},
								
								{
									{0.44800001,0.07},
									1
								},
								
								{
									{0.47799999,0.045000002},
									1
								},
								{}
							};
						};
						class HeadingScaleRight
						{
							clipTL[]={0.55000001,0.050000001};
							clipBR[]={0.82999998,0.11};
							class lines
							{
								type="scale";
								horizontal=1;
								source="heading";
								sourceScale=1;
								width=4;
								top=0.5;
								center=0.5;
								bottom=0.85000002;
								lineXleft=0.11;
								lineYright=0.1;
								lineXleftMajor=0.11;
								lineYrightMajor=0.090000004;
								majorLineEach=2;
								numberEach=2;
								step=22.5;
								stepSize=0.075000003;
								align="center";
								scale=1;
								pos[]={0.49599999,0.050000001};
								right[]={0.53600001,0.050000001};
								down[]={0.49599999,0.090000004};
							};
						};
						class HeadingScaleMidle
						{
							type="scale";
							horizontal=1;
							source="heading";
							sourceScale=1;
							width=4;
							top=0.44999999;
							center=0.5;
							bottom=0.55000001;
							lineXleft=0.11;
							lineYright=0.1;
							lineXleftMajor=0.11;
							lineYrightMajor=0.1;
							majorLineEach=2;
							step=22.5;
							stepSize=0.075000003;
							align="center";
							scale=1;
							numberEach=0;
							pos[]={0.47,0.050000001};
							right[]={0.5,0.050000001};
							down[]={0.44999999,0.090000004};
						};
						class HeadingScaleLeft
						{
							clipTL[]={0.18000001,0.050000001};
							clipBR[]={0.44999999,0.11};
							class lines
							{
								type="scale";
								horizontal=1;
								source="heading";
								sourceScale=1;
								width=4;
								top=0.15000001;
								center=0.5;
								bottom=0.55000001;
								lineXleft=0.11;
								lineYright=0.1;
								lineXleftMajor=0.11;
								lineYrightMajor=0.090000004;
								majorLineEach=2;
								numberEach=2;
								step=22.5;
								stepSize=0.075000003;
								align="center";
								scale=1;
								pos[]={0.146,0.050000001};
								right[]={0.186,0.050000001};
								down[]={0.146,0.090000004};
							};
						};
					};
					class HeadingScaleFull
					{
						condition="4-abs(cameraDir-heading)*( (abs(heading-cameraDir))<=355)";
						class HeadingScale
						{
							clipTL[]={0.18000001,0};
							clipBR[]={0.82999998,1};
							class lines
							{
								type="scale";
								horizontal=1;
								source="heading";
								sourceScale=1;
								width=4;
								top=0.15000001;
								center=0.5;
								bottom=0.85000002;
								lineXleft=0.11;
								lineYright=0.1;
								lineXleftMajor=0.11;
								lineYrightMajor=0.090000004;
								majorLineEach=2;
								numberEach=2;
								step=22.5;
								stepSize=0.075000003;
								align="center";
								scale=1;
								pos[]={0.146,0.050000001};
								right[]={0.186,0.050000001};
								down[]={0.146,0.090000004};
							};
						};
					};
					class HorizonBankRot
					{
						type="polygon";
						width=4;
						points[]=
						{
							
							{
								
								{
									"HorizonBankRot",
									1,
									{0,0},
									1
								},
								
								{
									"HorizonBankRot",
									{0.0026047199,-0.0145196},
									1
								},
								
								{
									"HorizonBankRot",
									{0.0051302998,-0.0138544},
									1
								},
								
								{
									"HorizonBankRot",
									{0.0074999998,-0.0127683},
									1
								}
							},
							
							{
								
								{
									"HorizonBankRot",
									1,
									{0,0},
									1
								},
								
								{
									"HorizonBankRot",
									{0.0074999998,-0.0127683},
									1
								},
								
								{
									"HorizonBankRot",
									{0.0096418103,-0.0112942},
									1
								},
								
								{
									"HorizonBankRot",
									{0.0114907,-0.0094769998},
									1
								}
							},
							
							{
								
								{
									"HorizonBankRot",
									1,
									{0,0},
									1
								},
								
								{
									"HorizonBankRot",
									{0.0114907,-0.0094769998},
									1
								},
								
								{
									"HorizonBankRot",
									{0.0129904,-0.0073717898},
									1
								},
								
								{
									"HorizonBankRot",
									{0.0140954,-0.0050426},
									1
								}
							},
							
							{
								
								{
									"HorizonBankRot",
									1,
									{0,0},
									1
								},
								
								{
									"HorizonBankRot",
									{0.0140954,-0.0050426},
									1
								},
								
								{
									"HorizonBankRot",
									{0.0147721,-0.0025601999},
									1
								},
								
								{
									"HorizonBankRot",
									{0.015,6.4446298e-010},
									1
								}
							},
							
							{
								
								{
									"HorizonBankRot",
									1,
									{0,0},
									1
								},
								
								{
									"HorizonBankRot",
									{0.015,6.4446298e-010},
									1
								},
								
								{
									"HorizonBankRot",
									{0.0147721,0.0025601999},
									1
								},
								
								{
									"HorizonBankRot",
									{0.0140954,0.0050426},
									1
								}
							},
							
							{
								
								{
									"HorizonBankRot",
									1,
									{0,0},
									1
								},
								
								{
									"HorizonBankRot",
									{0.0140954,0.0050426},
									1
								},
								
								{
									"HorizonBankRot",
									{0.0129904,0.0073718},
									1
								},
								
								{
									"HorizonBankRot",
									{0.0114907,0.0094769998},
									1
								}
							},
							
							{
								
								{
									"HorizonBankRot",
									1,
									{0,0},
									1
								},
								
								{
									"HorizonBankRot",
									{0.0114907,0.0094769998},
									1
								},
								
								{
									"HorizonBankRot",
									{0.0096418103,0.0112942},
									1
								},
								
								{
									"HorizonBankRot",
									{0.0074999998,0.0127683},
									1
								}
							},
							
							{
								
								{
									"HorizonBankRot",
									1,
									{0,0},
									1
								},
								
								{
									"HorizonBankRot",
									{0.0074999998,0.0127683},
									1
								},
								
								{
									"HorizonBankRot",
									{0.0051302998,0.0138544},
									1
								},
								
								{
									"HorizonBankRot",
									{0.0026047199,0.0145196},
									1
								}
							},
							
							{
								
								{
									"HorizonBankRot",
									1,
									{0,0},
									1
								},
								
								{
									"HorizonBankRot",
									{0.0026047199,0.0145196},
									1
								},
								
								{
									"HorizonBankRot",
									{-1.31134e-009,0.0147436},
									1
								},
								
								{
									"HorizonBankRot",
									{-0.00260473,0.0145196},
									1
								}
							},
							
							{
								
								{
									"HorizonBankRot",
									1,
									{0,0},
									1
								},
								
								{
									"HorizonBankRot",
									{-0.00260473,0.0145196},
									1
								},
								
								{
									"HorizonBankRot",
									{-0.0051302998,0.0138544},
									1
								},
								
								{
									"HorizonBankRot",
									{-0.0074999998,0.0127683},
									1
								}
							},
							
							{
								
								{
									"HorizonBankRot",
									1,
									{0,0},
									1
								},
								
								{
									"HorizonBankRot",
									{-0.0074999998,0.0127683},
									1
								},
								
								{
									"HorizonBankRot",
									{-0.0096418103,0.0112942},
									1
								},
								
								{
									"HorizonBankRot",
									{-0.0114907,0.0094769998},
									1
								}
							},
							
							{
								
								{
									"HorizonBankRot",
									1,
									{0,0},
									1
								},
								
								{
									"HorizonBankRot",
									{-0.0114907,0.0094769998},
									1
								},
								
								{
									"HorizonBankRot",
									{-0.0129904,0.0073717898},
									1
								},
								
								{
									"HorizonBankRot",
									{-0.0140954,0.0050426},
									1
								}
							},
							
							{
								
								{
									"HorizonBankRot",
									1,
									{0,0},
									1
								},
								
								{
									"HorizonBankRot",
									{-0.0140954,0.0050426},
									1
								},
								
								{
									"HorizonBankRot",
									{-0.0147721,0.0025601999},
									1
								},
								
								{
									"HorizonBankRot",
									{-0.015,-1.75816e-010},
									1
								}
							},
							
							{
								
								{
									"HorizonBankRot",
									1,
									{0,0},
									1
								},
								
								{
									"HorizonBankRot",
									{-0.015,-1.75816e-010},
									1
								},
								
								{
									"HorizonBankRot",
									{-0.0147721,-0.0025601999},
									1
								},
								
								{
									"HorizonBankRot",
									{-0.0140954,-0.0050426},
									1
								}
							},
							
							{
								
								{
									"HorizonBankRot",
									1,
									{0,0},
									1
								},
								
								{
									"HorizonBankRot",
									{-0.0140954,-0.0050426},
									1
								},
								
								{
									"HorizonBankRot",
									{-0.0129904,-0.0073718},
									1
								},
								
								{
									"HorizonBankRot",
									{-0.0114907,-0.0094769998},
									1
								}
							},
							
							{
								
								{
									"HorizonBankRot",
									1,
									{0,0},
									1
								},
								
								{
									"HorizonBankRot",
									{-0.0114907,-0.0094769998},
									1
								},
								
								{
									"HorizonBankRot",
									{-0.0096418103,-0.0112942},
									1
								},
								
								{
									"HorizonBankRot",
									{-0.0074999998,-0.0127683},
									1
								}
							},
							
							{
								
								{
									"HorizonBankRot",
									1,
									{0,0},
									1
								},
								
								{
									"HorizonBankRot",
									{-0.0074999998,-0.0127683},
									1
								},
								
								{
									"HorizonBankRot",
									{-0.0051303101,-0.0138544},
									1
								},
								
								{
									"HorizonBankRot",
									{-0.0026047199,-0.0145196},
									1
								}
							},
							
							{
								
								{
									"HorizonBankRot",
									1,
									{0,0},
									1
								},
								
								{
									"HorizonBankRot",
									{-0.0026047199,-0.0145196},
									1
								},
								
								{
									"HorizonBankRot",
									{2.6226801e-009,-0.0147436},
									1
								},
								
								{
									"HorizonBankRot",
									{0.0026047199,-0.0145196},
									1
								}
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
								{0.22,0.2},
								1
							};
							right[]=
							{
								{0.28,0.2},
								1
							};
							down[]=
							{
								{0.22,0.23999999},
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
								{0.22,0.2},
								1
							};
							right[]=
							{
								{0.28,0.2},
								1
							};
							down[]=
							{
								{0.22,0.23999999},
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
							{0.16,0.47999999},
							1
						};
						right[]=
						{
							{0.22,0.47999999},
							1
						};
						down[]=
						{
							{0.16,0.51999998},
							1
						};
					};
					class AltNumber
					{
						type="text";
						source="altitudeAGL";
						sourceScale=1;
						sourceOffset=-2;
						align="left";
						scale=1;
						pos[]=
						{
							{0.81,0.47999999},
							1
						};
						right[]=
						{
							{0.87,0.47999999},
							1
						};
						down[]=
						{
							{0.81,0.51999998},
							1
						};
					};
					class HoverMode
					{
						condition="autohover";
						class HoverText
						{
							type="text";
							source="static";
							text="HOVER";
							scale=1;
							sourceScale=1;
							align="right";
							pos[]=
							{
								{0.0049999999,0.075000003},
								1
							};
							right[]=
							{
								{0.045000002,0.075000003},
								1
							};
							down[]=
							{
								{0.0049999999,0.11},
								1
							};
						};
					};
					class CruiseMode
					{
						condition="((altitudeASL-27) min 1) - autohover";
						class CruiseText
						{
							type="text";
							source="static";
							text="CRUISE";
							scale=1;
							sourceScale=1;
							align="right";
							pos[]=
							{
								{0.0049999999,0.075000003},
								1
							};
							right[]=
							{
								{0.045000002,0.075000003},
								1
							};
							down[]=
							{
								{0.0049999999,0.11},
								1
							};
						};
						class AltNumberASL
						{
							type="text";
							source="altitudeASL";
							sourceScale=1;
							align="left";
							scale=1;
							pos[]=
							{
								{0.81,0.16},
								1
							};
							right[]=
							{
								{0.87,0.16},
								1
							};
							down[]=
							{
								{0.81,0.2},
								1
							};
						};
					};
					class TransitionMode
					{
						condition="((27-altitudeASL) min 1) - autohover";
						class TransText
						{
							type="text";
							source="static";
							text="TRANS";
							scale=1;
							sourceScale=1;
							align="right";
							pos[]=
							{
								{0.0049999999,0.075000003},
								1
							};
							right[]=
							{
								{0.045000002,0.075000003},
								1
							};
							down[]=
							{
								{0.0049999999,0.11},
								1
							};
						};
					};
					class HoverModeHide
					{
						condition="1-autohover";
						class VelocityLine
						{
							type="line";
							width=4;
							points[]=
							{
								
								{
									"VelocityVector",
									{0,-0.0196581},
									1
								},
								
								{
									"VelocityVector",
									{0.0099999998,-0.017023901},
									1
								},
								
								{
									"VelocityVector",
									{0.01732,-0.0098290602},
									1
								},
								
								{
									"VelocityVector",
									{0.02,0},
									1
								},
								
								{
									"VelocityVector",
									{0.01732,0.0098290602},
									1
								},
								
								{
									"VelocityVector",
									{0.0099999998,0.017023901},
									1
								},
								
								{
									"VelocityVector",
									{0,0.0196581},
									1
								},
								
								{
									"VelocityVector",
									{-0.0099999998,0.017023901},
									1
								},
								
								{
									"VelocityVector",
									{-0.01732,0.0098290602},
									1
								},
								
								{
									"VelocityVector",
									{-0.02,0},
									1
								},
								
								{
									"VelocityVector",
									{-0.01732,-0.0098290602},
									1
								},
								
								{
									"VelocityVector",
									{-0.0099999998,-0.017023901},
									1
								},
								
								{
									"VelocityVector",
									{0,-0.0196581},
									1
								},
								{},
								
								{
									"VelocityVector",
									{0.039999999,0},
									1
								},
								
								{
									"VelocityVector",
									{0.02,0},
									1
								},
								{},
								
								{
									"VelocityVector",
									{-0.039999999,0},
									1
								},
								
								{
									"VelocityVector",
									{-0.02,0},
									1
								},
								{},
								
								{
									"VelocityVector",
									{0,-0.0393162},
									1
								},
								
								{
									"VelocityVector",
									{0,-0.0196581},
									1
								},
								{}
							};
						};
					};
					class GearGroup
					{
						type="group";
						condition="ils";
						class GearText
						{
							type="text";
							source="static";
							text="GEAR";
							align="right";
							scale=1;
							pos[]=
							{
								{0.015,0.33418801},
								1
							};
							right[]=
							{
								{0.055,0.33418801},
								1
							};
							down[]=
							{
								{0.015,0.363675},
								1
							};
						};
					};
					class LaserGroup
					{
						condition="laseron";
						class laserText
						{
							type="text";
							source="static";
							text="LASER";
							scale=1;
							sourceScale=1;
							align="right";
							pos[]=
							{
								{0.015,0.37},
								1
							};
							right[]=
							{
								{0.055,0.37},
								1
							};
							down[]=
							{
								{0.015,0.405},
								1
							};
						};
					};
					class RadarGroup
					{
						condition="activeSensorsOn";
						class radarText
						{
							type="text";
							source="static";
							text="RADAR";
							scale=1;
							sourceScale=1;
							align="right";
							pos[]=
							{
								{0.015,0.41},
								1
							};
							right[]=
							{
								{0.055,0.41},
								1
							};
							down[]=
							{
								{0.015,0.44499999},
								1
							};
						};
					};
					class VerticalSpeedScale
					{
						type="line";
						width=4;
						points[]=
						{
							
							{
								"WeaponAimRelative",
								1,
								{-0.029999999,0},
								1
							},
							
							{
								"WeaponAimRelative",
								1,
								{-0.02,0},
								1
							},
							{},
							
							{
								"WeaponAimRelative",
								1,
								{0.02,0},
								1
							},
							
							{
								"WeaponAimRelative",
								1,
								{0.029999999,0},
								1
							},
							{},
							
							{
								"WeaponAimRelative",
								1,
								{0,-0.02},
								1
							},
							
							{
								"WeaponAimRelative",
								1,
								{0,-0.029999999},
								1
							},
							{},
							
							{
								"WeaponAimRelative",
								1,
								{0,0.02},
								1
							},
							
							{
								"WeaponAimRelative",
								1,
								{0,0.029999999},
								1
							},
							{},
							
							{
								"HUDCenter",
								1,
								{-0.029999999,0},
								1
							},
							
							{
								"HUDCenter",
								1,
								{-0.0099999998,0},
								1
							},
							{},
							
							{
								"HUDCenter",
								1,
								{0.0099999998,0},
								1
							},
							
							{
								"HUDCenter",
								1,
								{0.029999999,0},
								1
							},
							{},
							
							{
								"HUDCenter",
								1,
								{0,-0.0099999998},
								1
							},
							
							{
								"HUDCenter",
								1,
								{0,-0.029999999},
								1
							},
							{},
							
							{
								"HUDCenter",
								1,
								{0,0.0099999998},
								1
							},
							
							{
								"HUDCenter",
								1,
								{0,0.029999999},
								1
							},
							{},
							
							{
								{0.91500002,0.18000001},
								1
							},
							
							{
								{0.935,0.18000001},
								1
							},
							{},
							
							{
								{0.87,0.18000001},
								1
							},
							
							{
								{0.88999999,0.18000001},
								1
							},
							{},
							
							{
								{0.91500002,0.34},
								1
							},
							
							{
								{0.935,0.34},
								1
							},
							{},
							
							{
								{0.87,0.34},
								1
							},
							
							{
								{0.88999999,0.34},
								1
							},
							{},
							
							{
								{0.875,0.37200001},
								1
							},
							
							{
								{0.88499999,0.37200001},
								1
							},
							{},
							
							{
								{0.875,0.40400001},
								1
							},
							
							{
								{0.88499999,0.40400001},
								1
							},
							{},
							
							{
								{0.875,0.43599999},
								1
							},
							
							{
								{0.88499999,0.43599999},
								1
							},
							{},
							
							{
								{0.875,0.46799999},
								1
							},
							
							{
								{0.88499999,0.46799999},
								1
							},
							{},
							
							{
								{0.87,0.5},
								1
							},
							
							{
								{0.88999999,0.5},
								1
							},
							{},
							
							{
								{0.91500002,0.5},
								1
							},
							
							{
								{0.935,0.5},
								1
							},
							{},
							
							{
								{0.91500002,0.66000003},
								1
							},
							
							{
								{0.935,0.66000003},
								1
							},
							{},
							
							{
								{0.87,0.66000003},
								1
							},
							
							{
								{0.88999999,0.66000003},
								1
							},
							{},
							
							{
								{0.875,0.62800002},
								1
							},
							
							{
								{0.88499999,0.62800002},
								1
							},
							{},
							
							{
								{0.875,0.59600002},
								1
							},
							
							{
								{0.88499999,0.59600002},
								1
							},
							{},
							
							{
								{0.875,0.56400001},
								1
							},
							
							{
								{0.88499999,0.56400001},
								1
							},
							{},
							
							{
								{0.875,0.53200001},
								1
							},
							
							{
								{0.88499999,0.53200001},
								1
							},
							{},
							
							{
								{0.92000002,0.69199997},
								1
							},
							
							{
								{0.93000001,0.69199997},
								1
							},
							{},
							
							{
								{0.92000002,0.72399998},
								1
							},
							
							{
								{0.93000001,0.72399998},
								1
							},
							{},
							
							{
								{0.92000002,0.75599998},
								1
							},
							
							{
								{0.93000001,0.75599998},
								1
							},
							{},
							
							{
								{0.92000002,0.78799999},
								1
							},
							
							{
								{0.93000001,0.78799999},
								1
							},
							{},
							
							{
								{0.91500002,0.81999999},
								1
							},
							
							{
								{0.935,0.81999999},
								1
							},
							{},
							
							{
								{0.87,0.81999999},
								1
							},
							
							{
								{0.88999999,0.81999999},
								1
							},
							{}
						};
					};
					class VerticalSpeedArrow
					{
						type="polygon";
						points[]=
						{
							
							{
								
								{
									"VerticalSpeedBone",
									{0.85000002,0.48800001},
									1
								},
								
								{
									"VerticalSpeedBone",
									{0.87,0.5},
									1
								},
								
								{
									"VerticalSpeedBone",
									{0.85000002,0.51200002},
									1
								}
							}
						};
					};
					class RadarAltitude
					{
						condition="101-altitudeAGL";
						class RadarHeight
						{
							type="line";
							width=15;
							points[]=
							{
								
								{
									{0.903,0.81999999},
									1
								},
								
								{
									"RadarHeight",
									{0,0},
									1
								},
								{}
							};
						};
					};
					class HorizonLine
					{
						condition="1-autohover";
						clipTL[]={0.2,0.145};
						clipBR[]={0.80000001,0.85500002};
						class HorizonLineDraw
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
					class WeaponsText
					{
						condition="1- mgun";
						class Weapons
						{
							type="text";
							source="weapon";
							sourceScale=1;
							align="left";
							scale=0.5;
							pos[]=
							{
								{0.38,0.86900002},
								1
							};
							right[]=
							{
								{0.41499999,0.86900002},
								1
							};
							down[]=
							{
								{0.38,0.90399998},
								1
							};
						};
					};
					class Ammo
					{
						type="text";
						source="ammo";
						sourceScale=1;
						align="left";
						scale=0.5;
						pos[]=
						{
							{0.38,0.90100002},
							1
						};
						right[]=
						{
							{0.41499999,0.90100002},
							1
						};
						down[]=
						{
							{0.38,0.93599999},
							1
						};
					};
					class MGun
					{
						condition="mgun";
						class Weapons
						{
							type="text";
							source="static";
							text="GUN";
							sourceScale=1;
							align="left";
							scale=0.5;
							pos[]=
							{
								{0.38,0.86900002},
								1
							};
							right[]=
							{
								{0.41499999,0.86900002},
								1
							};
							down[]=
							{
								{0.38,0.90399998},
								1
							};
						};
						class Circle
						{
							type="line";
							width=4;
							points[]=
							{
								
								{
									"WeaponAimRelative",
									{0.025,0},
									1
								},
								
								{
									"WeaponAimRelative",
									{0.0099999998,0},
									1
								},
								{},
								
								{
									"WeaponAimRelative",
									{0,0.0245726},
									1
								},
								
								{
									"WeaponAimRelative",
									{0,0.0098290602},
									1
								},
								{},
								
								{
									"WeaponAimRelative",
									{-0.025,0},
									1
								},
								
								{
									"WeaponAimRelative",
									{-0.0099999998,0},
									1
								},
								{},
								
								{
									"WeaponAimRelative",
									{0,-0.0245726},
									1
								},
								
								{
									"WeaponAimRelative",
									{0,-0.0098290602},
									1
								},
								{},
								
								{
									"WeaponAimRelative",
									{0,-0.0098290602},
									1
								},
								
								{
									"WeaponAimRelative",
									{0.0049999999,-0.0085119698},
									1
								},
								
								{
									"WeaponAimRelative",
									{0.0086599998,-0.0049145301},
									1
								},
								
								{
									"WeaponAimRelative",
									{0.0099999998,0},
									1
								},
								
								{
									"WeaponAimRelative",
									{0.0086599998,0.0049145301},
									1
								},
								
								{
									"WeaponAimRelative",
									{0.0049999999,0.0085119698},
									1
								},
								
								{
									"WeaponAimRelative",
									{0,0.0098290602},
									1
								},
								
								{
									"WeaponAimRelative",
									{-0.0049999999,0.0085119698},
									1
								},
								
								{
									"WeaponAimRelative",
									{-0.0086599998,0.0049145301},
									1
								},
								
								{
									"WeaponAimRelative",
									{-0.0099999998,0},
									1
								},
								
								{
									"WeaponAimRelative",
									{-0.0086599998,-0.0049145301},
									1
								},
								
								{
									"WeaponAimRelative",
									{-0.0049999999,-0.0085119698},
									1
								},
								
								{
									"WeaponAimRelative",
									{0,-0.0098290602},
									1
								}
							};
						};
					};
					class AAMissile
					{
						condition="AAmissile";
						class Circle
						{
							type="line";
							width=4;
							points[]=
							{
								
								{
									"ForwardVector",
									1,
									"HUDCenter",
									{0,-0.245726},
									1
								},
								
								{
									"ForwardVector",
									1,
									"HUDCenter",
									{0.043400001,-0.241991},
									1
								},
								
								{
									"ForwardVector",
									1,
									"HUDCenter",
									{0.085500002,-0.230909},
									1
								},
								
								{
									"ForwardVector",
									1,
									"HUDCenter",
									{0.125,-0.212799},
									1
								},
								
								{
									"ForwardVector",
									1,
									"HUDCenter",
									{0.16069999,-0.188226},
									1
								},
								
								{
									"ForwardVector",
									1,
									"HUDCenter",
									{0.19149999,-0.15795299},
									1
								},
								
								{
									"ForwardVector",
									1,
									"HUDCenter",
									{0.2165,-0.122863},
									1
								},
								
								{
									"ForwardVector",
									1,
									"HUDCenter",
									{0.234925,-0.084038503},
									1
								},
								
								{
									"ForwardVector",
									1,
									"HUDCenter",
									{0.2462,-0.042658102},
									1
								},
								
								{
									"ForwardVector",
									1,
									"HUDCenter",
									{0.25,0},
									1
								},
								
								{
									"ForwardVector",
									1,
									"HUDCenter",
									{0.2462,0.042658102},
									1
								},
								
								{
									"ForwardVector",
									1,
									"HUDCenter",
									{0.234925,0.084038503},
									1
								},
								
								{
									"ForwardVector",
									1,
									"HUDCenter",
									{0.2165,0.122863},
									1
								},
								
								{
									"ForwardVector",
									1,
									"HUDCenter",
									{0.19149999,0.15795299},
									1
								},
								
								{
									"ForwardVector",
									1,
									"HUDCenter",
									{0.16069999,0.188226},
									1
								},
								
								{
									"ForwardVector",
									1,
									"HUDCenter",
									{0.125,0.212799},
									1
								},
								
								{
									"ForwardVector",
									1,
									"HUDCenter",
									{0.085500002,0.230909},
									1
								},
								
								{
									"ForwardVector",
									1,
									"HUDCenter",
									{0.043400001,0.241991},
									1
								},
								
								{
									"ForwardVector",
									1,
									"HUDCenter",
									{0,0.245726},
									1
								},
								
								{
									"ForwardVector",
									1,
									"HUDCenter",
									{-0.043400001,0.241991},
									1
								},
								
								{
									"ForwardVector",
									1,
									"HUDCenter",
									{-0.085500002,0.230909},
									1
								},
								
								{
									"ForwardVector",
									1,
									"HUDCenter",
									{-0.125,0.212799},
									1
								},
								
								{
									"ForwardVector",
									1,
									"HUDCenter",
									{-0.16069999,0.188226},
									1
								},
								
								{
									"ForwardVector",
									1,
									"HUDCenter",
									{-0.19149999,0.15795299},
									1
								},
								
								{
									"ForwardVector",
									1,
									"HUDCenter",
									{-0.2165,0.122863},
									1
								},
								
								{
									"ForwardVector",
									1,
									"HUDCenter",
									{-0.234925,0.084038503},
									1
								},
								
								{
									"ForwardVector",
									1,
									"HUDCenter",
									{-0.2462,0.042658102},
									1
								},
								
								{
									"ForwardVector",
									1,
									"HUDCenter",
									{-0.25,0},
									1
								},
								
								{
									"ForwardVector",
									1,
									"HUDCenter",
									{-0.2462,-0.042658102},
									1
								},
								
								{
									"ForwardVector",
									1,
									"HUDCenter",
									{-0.234925,-0.084038503},
									1
								},
								
								{
									"ForwardVector",
									1,
									"HUDCenter",
									{-0.2165,-0.122863},
									1
								},
								
								{
									"ForwardVector",
									1,
									"HUDCenter",
									{-0.19149999,-0.15795299},
									1
								},
								
								{
									"ForwardVector",
									1,
									"HUDCenter",
									{-0.16069999,-0.188226},
									1
								},
								
								{
									"ForwardVector",
									1,
									"HUDCenter",
									{-0.125,-0.212799},
									1
								},
								
								{
									"ForwardVector",
									1,
									"HUDCenter",
									{-0.085500002,-0.230909},
									1
								},
								
								{
									"ForwardVector",
									1,
									"HUDCenter",
									{-0.043400001,-0.241991},
									1
								},
								
								{
									"ForwardVector",
									1,
									"HUDCenter",
									{0,-0.245726},
									1
								}
							};
						};
					};
					class ATMissile
					{
						condition="ATmissile";
						class Circle
						{
							type="line";
							width=4;
							points[]=
							{
								
								{
									"ForwardVector",
									1,
									"HUDCenter",
									{-0.15000001,-0.14743599},
									1
								},
								
								{
									"ForwardVector",
									1,
									"HUDCenter",
									{-0.15000001,-0.12777799},
									1
								},
								{},
								
								{
									"ForwardVector",
									1,
									"HUDCenter",
									{-0.15000001,0.14743599},
									1
								},
								
								{
									"ForwardVector",
									1,
									"HUDCenter",
									{-0.15000001,0.12777799},
									1
								},
								{},
								
								{
									"ForwardVector",
									1,
									"HUDCenter",
									{0.15000001,-0.14743599},
									1
								},
								
								{
									"ForwardVector",
									1,
									"HUDCenter",
									{0.15000001,-0.12777799},
									1
								},
								{},
								
								{
									"ForwardVector",
									1,
									"HUDCenter",
									{0.15000001,0.14743599},
									1
								},
								
								{
									"ForwardVector",
									1,
									"HUDCenter",
									{0.15000001,0.12777799},
									1
								},
								{},
								
								{
									"ForwardVector",
									1,
									"HUDCenter",
									{-0.15000001,-0.14743599},
									1
								},
								
								{
									"ForwardVector",
									1,
									"HUDCenter",
									{-0.13,-0.14743599},
									1
								},
								{},
								
								{
									"ForwardVector",
									1,
									"HUDCenter",
									{-0.15000001,0.14743599},
									1
								},
								
								{
									"ForwardVector",
									1,
									"HUDCenter",
									{-0.13,0.14743599},
									1
								},
								{},
								
								{
									"ForwardVector",
									1,
									"HUDCenter",
									{0.15000001,-0.14743599},
									1
								},
								
								{
									"ForwardVector",
									1,
									"HUDCenter",
									{0.13,-0.14743599},
									1
								},
								{},
								
								{
									"ForwardVector",
									1,
									"HUDCenter",
									{0.15000001,0.14743599},
									1
								},
								
								{
									"ForwardVector",
									1,
									"HUDCenter",
									{0.13,0.14743599},
									1
								}
							};
						};
					};
					class Rockets
					{
						condition="rocket";
						class RocketDummy
						{
							type="line";
							width=3;
							points[]=
							{
								
								{
									"ImpactPoint",
									{0.0099999998,-0.0294872},
									1
								},
								
								{
									"ImpactPoint",
									{-0.0099999998,-0.0294872},
									1
								},
								{},
								
								{
									"ImpactPoint",
									{0.0099999998,0.0294872},
									1
								},
								
								{
									"ImpactPoint",
									{-0.0099999998,0.0294872},
									1
								},
								{},
								
								{
									"ImpactPoint",
									{0,-0.0294872},
									1
								},
								
								{
									"ImpactPoint",
									{0,0.0294872},
									1
								},
								{}
							};
						};
					};
					class WP
					{
						condition="wpvalid - autohover";
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
								{0.235,0.77403802},
								1
							};
							right[]=
							{
								{0.27500001,0.77403802},
								1
							};
							down[]=
							{
								{0.235,0.80155998},
								1
							};
						};
						class WPIndex
						{
							type="text";
							source="wpIndex";
							sourceScale=1;
							sourceLength=2;
							align="right";
							scale=1;
							pos[]=
							{
								{0.096000001,0.77600402},
								1
							};
							right[]=
							{
								{0.126,0.77600402},
								1
							};
							down[]=
							{
								{0.096000001,0.79959399},
								1
							};
						};
						class WPstatic
						{
							type="text";
							source="static";
							text="W";
							scale=1;
							sourceScale=1;
							align="right";
							pos[]=
							{
								{0.075000003,0.77499998},
								1
							};
							right[]=
							{
								{0.105,0.77499998},
								1
							};
							down[]=
							{
								{0.075000003,0.80000001},
								1
							};
						};
						class WPAuto
						{
							type="text";
							source="static";
							text="A";
							scale=1;
							sourceScale=1;
							align="right";
							pos[]=
							{
								
								{
									"0.075 +0.035",
									0.80000001
								},
								1
							};
							right[]=
							{
								{0.14,0.80000001},
								1
							};
							down[]=
							{
								
								{
									"0.075 +0.035",
									0.82499999
								},
								1
							};
						};
						class WPKM
						{
							type="text";
							source="static";
							text="KM";
							scale=1;
							sourceScale=1;
							align="right";
							pos[]=
							{
								
								{
									"0.075 +0.16",
									0.77499998
								},
								1
							};
							right[]=
							{
								{0.26499999,0.77499998},
								1
							};
							down[]=
							{
								
								{
									"0.075 +0.16",
									0.80299997
								},
								1
							};
						};
						class WPTime
						{
							type="text";
							source="static";
							text="-:--";
							scale=1;
							sourceScale=1;
							align="right";
							pos[]=
							{
								
								{
									"0.075 +0.11",
									0.80000001
								},
								1
							};
							right[]=
							{
								{0.215,0.80000001},
								1
							};
							down[]=
							{
								
								{
									"0.075 +0.11",
									0.82499999
								},
								1
							};
						};
						class WP
						{
							width=2;
							type="line";
							points[]=
							{
								
								{
									"WPPoint",
									1,
									"LimitWaypoint",
									1,
									{-0.02,0.039999999},
									1
								},
								
								{
									"WPPoint",
									1,
									"LimitWaypoint",
									1,
									{0,0.02},
									1
								},
								
								{
									"WPPoint",
									1,
									"LimitWaypoint",
									1,
									{0.02,0.039999999},
									1
								},
								{}
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
								{0.493,0.76666701},
								1
							};
							right[]=
							{
								{0.55299997,0.76666701},
								1
							};
							down[]=
							{
								{0.493,0.81581199},
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
					class RadarTargets
					{
						class RadarBoxes
						{
							type="radartoview";
							pos0[]={0.5,0.5};
							pos10[]={0.73400003,0.73000002};
							width=4;
							points[]=
							{
								
								{
									{-0.0035000001,-0.0034401701},
									1
								},
								
								{
									{0.0035000001,-0.0034401701},
									1
								},
								
								{
									{0.0035000001,0.0034401701},
									1
								},
								
								{
									{-0.0035000001,0.0034401701},
									1
								},
								
								{
									{-0.0035000001,-0.0034401701},
									1
								}
							};
						};
					};
					class TargetDiamond
					{
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
									1,
									{0.0074999998,0},
									1
								},
								
								{
									"Target",
									1,
									"Limit0109",
									1,
									{0.0125,0},
									1
								},
								{},
								
								{
									"Target",
									1,
									"Limit0109",
									1,
									{0.0175,0},
									1
								},
								
								{
									"Target",
									1,
									"Limit0109",
									1,
									{0.022500001,0},
									1
								},
								{},
								
								{
									"Target",
									1,
									"Limit0109",
									1,
									{0.0275,0},
									1
								},
								
								{
									"Target",
									1,
									"Limit0109",
									1,
									{0.032499999,0},
									1
								},
								{},
								
								{
									"Target",
									1,
									"Limit0109",
									1,
									{0.037500001,0},
									1
								},
								
								{
									"Target",
									1,
									"Limit0109",
									1,
									{0.0425,0},
									1
								},
								{},
								
								{
									"Target",
									1,
									"Limit0109",
									1,
									{0.047499999,0},
									1
								},
								
								{
									"Target",
									1,
									"Limit0109",
									1,
									{0.052499998,0},
									1
								},
								{},
								
								{
									"Target",
									1,
									"Limit0109",
									1,
									{-0.0074999998,0},
									1
								},
								
								{
									"Target",
									1,
									"Limit0109",
									1,
									{-0.0125,0},
									1
								},
								{},
								
								{
									"Target",
									1,
									"Limit0109",
									1,
									{-0.0175,0},
									1
								},
								
								{
									"Target",
									1,
									"Limit0109",
									1,
									{-0.022500001,0},
									1
								},
								{},
								
								{
									"Target",
									1,
									"Limit0109",
									1,
									{-0.0275,0},
									1
								},
								
								{
									"Target",
									1,
									"Limit0109",
									1,
									{-0.032499999,0},
									1
								},
								{},
								
								{
									"Target",
									1,
									"Limit0109",
									1,
									{-0.037500001,0},
									1
								},
								
								{
									"Target",
									1,
									"Limit0109",
									1,
									{-0.0425,0},
									1
								},
								{},
								
								{
									"Target",
									1,
									"Limit0109",
									1,
									{-0.047499999,0},
									1
								},
								
								{
									"Target",
									1,
									"Limit0109",
									1,
									{-0.052499998,0},
									1
								},
								{},
								
								{
									"Target",
									1,
									"Limit0109",
									1,
									{0,0.0073717898},
									1
								},
								
								{
									"Target",
									1,
									"Limit0109",
									1,
									{0,0.0122863},
									1
								},
								{},
								
								{
									"Target",
									1,
									"Limit0109",
									1,
									{0,0.0172009},
									1
								},
								
								{
									"Target",
									1,
									"Limit0109",
									1,
									{0,0.0221154},
									1
								},
								{},
								
								{
									"Target",
									1,
									"Limit0109",
									1,
									{0,0.0270299},
									1
								},
								
								{
									"Target",
									1,
									"Limit0109",
									1,
									{0,0.031944402},
									1
								},
								{},
								
								{
									"Target",
									1,
									"Limit0109",
									1,
									{0,0.036858998},
									1
								},
								
								{
									"Target",
									1,
									"Limit0109",
									1,
									{0,0.041773502},
									1
								},
								{},
								
								{
									"Target",
									1,
									"Limit0109",
									1,
									{0,0.046688002},
									1
								},
								
								{
									"Target",
									1,
									"Limit0109",
									1,
									{0,0.051602598},
									1
								},
								{},
								
								{
									"Target",
									1,
									"Limit0109",
									1,
									{0,-0.0073717898},
									1
								},
								
								{
									"Target",
									1,
									"Limit0109",
									1,
									{0,-0.0122863},
									1
								},
								{},
								
								{
									"Target",
									1,
									"Limit0109",
									1,
									{0,-0.0172009},
									1
								},
								
								{
									"Target",
									1,
									"Limit0109",
									1,
									{0,-0.0221154},
									1
								},
								{},
								
								{
									"Target",
									1,
									"Limit0109",
									1,
									{0,-0.0270299},
									1
								},
								
								{
									"Target",
									1,
									"Limit0109",
									1,
									{0,-0.031944402},
									1
								},
								{},
								
								{
									"Target",
									1,
									"Limit0109",
									1,
									{0,-0.036858998},
									1
								},
								
								{
									"Target",
									1,
									"Limit0109",
									1,
									{0,-0.041773502},
									1
								},
								{},
								
								{
									"Target",
									1,
									"Limit0109",
									1,
									{0,-0.046688002},
									1
								},
								
								{
									"Target",
									1,
									"Limit0109",
									1,
									{0,-0.051602598},
									1
								},
								{}
							};
						};
					};
					class TargetLocked
					{
						condition="missilelocked";
						class TargetLockedText
						{
							type="text";
							source="static";
							text="VALID LOCK";
							scale=1;
							sourceScale=1;
							align="center";
							pos[]=
							{
								{0.493,0.77899998},
								1
							};
							right[]=
							{
								{0.53299999,0.77899998},
								1
							};
							down[]=
							{
								{0.493,0.81},
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
							align="right";
							pos[]=
							{
								
								{
									"0.127+0.49",
									0.86900002
								},
								1
							};
							right[]=
							{
								{0.65200001,0.86900002},
								1
							};
							down[]=
							{
								
								{
									"0.127+0.49",
									0.90399998
								},
								1
							};
						};
						class DistanceText
						{
							type="text";
							source="static";
							text="DIST:";
							scale=1;
							sourceScale=1;
							align="right";
							pos[]=
							{
								
								{
									"0.125+0.49",
									0.90100002
								},
								1
							};
							right[]=
							{
								{0.64999998,0.90100002},
								1
							};
							down[]=
							{
								
								{
									"0.125+0.49",
									0.93599999
								},
								1
							};
						};
						class TOF_source
						{
							type="text";
							scale=1;
							sourceScale=1;
							source="missileflighttime";
							align="right";
							pos[]=
							{
								{0.73900002,0.86900002},
								1
							};
							right[]=
							{
								{0.77399999,0.86900002},
								1
							};
							down[]=
							{
								{0.73900002,0.90399998},
								1
							};
						};
						class TargetDistance: TOF_source
						{
							source="targetDist";
							sourceLength=0;
							sourcePrecision=1;
							sourceScale=0.001;
							align="right";
							pos[]=
							{
								{0.73900002,0.90100002},
								1
							};
							right[]=
							{
								{0.77399999,0.90100002},
								1
							};
							down[]=
							{
								{0.73900002,0.93599999},
								1
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
					class cmWeapons
					{
						type="text";
						source="cmweapon";
						sourceScale=1;
						align="right";
						scale=0.5;
						pos[]=
						{
							{0.001,0.86900002},
							1
						};
						right[]=
						{
							{0.035999998,0.86900002},
							1
						};
						down[]=
						{
							{0.001,0.90399998},
							1
						};
					};
					class cmAmmo
					{
						type="text";
						source="cmammo";
						sourceScale=1;
						align="right";
						scale=0.5;
						pos[]=
						{
							{0.001,0.90100002},
							1
						};
						right[]=
						{
							{0.035999998,0.90100002},
							1
						};
						down[]=
						{
							{0.001,0.93599999},
							1
						};
					};
				};
			};
			class MFD_Left_Flight
			{
				topLeft="MFD_3_TL";
				topRight="MFD_3_TR";
				bottomLeft="MFD_3_BL";
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
				turret[]={-2};
				class material
				{
					ambient[]={5,5,5,1};
					diffuse[]={5,5,5,1};
					emissive[]={400,200,200,1};
				};
				class Bones
				{
					class HUDCenter
					{
						type="fixed";
						pos[]={0.5,0.5};
					};
					class VelocityVector
					{
						type="vector";
						source="velocity";
						pos0[]={0.5,0.5};
						pos10[]={0.93400002,0.93000001};
					};
					class ForwardVector
					{
						type="vector";
						source="forward";
						pos0[]={0,0};
						pos10[]={0.43399999,0.43000001};
					};
					class HorizonVector
					{
						type="horizon";
						pos0[]={0.5,0.5};
						pos10[]={1.11376,1.10811};
						angle=0;
					};
					class GunnerAim
					{
						type="vector";
						source="turret";
						pos0[]={0,-2};
						pos10[]={0.0068000001,-0.0099999998};
						projection=0;
					};
					class VerticalSpeedBone
					{
						type="linear";
						source="vspeed";
						sourceScale=1;
						min=-10;
						max=10;
						minPos[]={0,-0.25999999};
						maxPos[]={0,0.25999999};
					};
					class TurnRate
					{
						type="linear";
						source="user";
						sourceIndex=11;
						min=-4.8000002;
						max=4.8000002;
						minPos[]={0.36000001,0.87};
						maxPos[]={0.63999999,0.87};
						aspectRatio=1;
					};
					class FCR_Bearing
					{
						type="linear";
						source="user";
						sourceIndex=17;
						min=-180;
						max=180;
						minPos[]={0.34999999,0.16500001};
						maxPos[]={0.66000003,0.16500001};
					};
					class HorizonBankRot
					{
						type="linear";
						source="gmeterXgrav";
						min=-1;
						max=1;
						minPos[]={0.41,0.94};
						maxPos[]={0.58999997,0.94};
						aspectRatio=1;
					};
					class HorizonBankRot_Up
					{
						type="rotational";
						source="horizonBank";
						center[]={0.5,0.5};
						min="-rad(90)";
						max="rad(90)";
						minAngle="180.25-89";
						maxAngle="180.75+89";
						aspectRatio=1;
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
					class LimitWaypoint
					{
						type="limit";
						limits[]={0.23,0.14,0.76999998,0.14};
					};
					class WPPoint
					{
						type="vector";
						source="WPPoint";
						pos0[]={0.5,0.5};
						pos10[]={0.60000002,0.93000001};
					};
					class Level0
					{
						pos0[]={0.5,0.5};
						pos10[]={0.60416001,0.60320002};
						type="horizon";
						angle=0;
					};
					class LevelP05: Level0
					{
						angle=5;
					};
					class LevelM05: Level0
					{
						angle=-5;
					};
					class LevelP10: Level0
					{
						angle=10;
					};
					class LevelM10: Level0
					{
						angle=-10;
					};
					class LevelP15: Level0
					{
						angle=15;
					};
					class LevelM15: Level0
					{
						angle=-15;
					};
					class LevelP20: Level0
					{
						angle=20;
					};
					class LevelM20: Level0
					{
						angle=-20;
					};
					class LevelP25: Level0
					{
						angle=25;
					};
					class LevelM25: Level0
					{
						angle=-25;
					};
					class LevelP30: Level0
					{
						angle=30;
					};
					class LevelM30: Level0
					{
						angle=-30;
					};
					class LevelP35: Level0
					{
						angle=35;
					};
					class LevelM35: Level0
					{
						angle=-35;
					};
					class LevelP40: Level0
					{
						angle=40;
					};
					class LevelM40: Level0
					{
						angle=-40;
					};
					class LevelP45: Level0
					{
						angle=45;
					};
					class LevelM45: Level0
					{
						angle=-45;
					};
					class LevelP50: Level0
					{
						angle=50;
					};
					class LevelM50: Level0
					{
						angle=-50;
					};
					class LevelP60: Level0
					{
						angle=60;
					};
					class LevelM60: Level0
					{
						angle=-60;
					};
					class LevelP70: Level0
					{
						angle=70;
					};
					class LevelM70: Level0
					{
						angle=-70;
					};
					class LevelP80: Level0
					{
						angle=80;
					};
					class LevelM80: Level0
					{
						angle=-80;
					};
					class LevelP90: Level0
					{
						angle=90;
					};
					class LevelM90: Level0
					{
						angle=-90;
					};
					class RadarHeight
					{
						type="linear";
						source="altitudeAGL";
						sourceScale=1;
						sourceOffset=-2;
						min=0;
						max=61;
						minPos[]={0.97299999,0.25};
						maxPos[]={0.97299999,0.77999997};
					};
				};
				class Draw
				{
					alpha=1;
					color[]={0,0.12,0};
					condition="on";
					class Static
					{
						type="line";
						width=4;
						points[]=
						{
							
							{
								"VelocityVector",
								{0,-0.0198157},
								1
							},
							
							{
								"VelocityVector",
								{0.0099999998,-0.017160401},
								1
							},
							
							{
								"VelocityVector",
								{0.01732,-0.0099078296},
								1
							},
							
							{
								"VelocityVector",
								{0.02,0},
								1
							},
							
							{
								"VelocityVector",
								{0.01732,0.0099078296},
								1
							},
							
							{
								"VelocityVector",
								{0.0099999998,0.017160401},
								1
							},
							
							{
								"VelocityVector",
								{0,0.0198157},
								1
							},
							
							{
								"VelocityVector",
								{-0.0099999998,0.017160401},
								1
							},
							
							{
								"VelocityVector",
								{-0.01732,0.0099078296},
								1
							},
							
							{
								"VelocityVector",
								{-0.02,0},
								1
							},
							
							{
								"VelocityVector",
								{-0.01732,-0.0099078296},
								1
							},
							
							{
								"VelocityVector",
								{-0.0099999998,-0.017160401},
								1
							},
							
							{
								"VelocityVector",
								{0,-0.0198157},
								1
							},
							{},
							
							{
								"VelocityVector",
								{0.039999999,0},
								1
							},
							
							{
								"VelocityVector",
								{0.02,0},
								1
							},
							{},
							
							{
								"VelocityVector",
								{-0.039999999,0},
								1
							},
							
							{
								"VelocityVector",
								{-0.02,0},
								1
							},
							{},
							
							{
								"VelocityVector",
								{0,-0.0396313},
								1
							},
							
							{
								"VelocityVector",
								{0,-0.0198157},
								1
							},
							{},
							
							{
								{0.38118199,0.224373},
								1
							},
							
							{
								{0.37768799,0.21509001},
								1
							},
							{},
							
							{
								{0.40702799,0.22628599},
								1
							},
							
							{
								{0.40139401,0.20727301},
								1
							},
							{},
							
							{
								{0.427728,0.210832},
								1
							},
							
							{
								{0.42560199,0.201151},
								1
							},
							{},
							
							{
								{0.45303601,0.216369},
								1
							},
							
							{
								{0.45019001,0.19675501},
								1
							},
							{},
							
							{
								{0.47574499,0.20399199},
								1
							},
							
							{
								{0.47503099,0.19410899},
								1
							},
							{},
							
							{
								{0.52425498,0.20399199},
								1
							},
							
							{
								{0.52496898,0.19410899},
								1
							},
							{},
							
							{
								{0.54696399,0.216369},
								1
							},
							
							{
								{0.54980999,0.19675501},
								1
							},
							{},
							
							{
								{0.572272,0.210832},
								1
							},
							
							{
								{0.57439798,0.201151},
								1
							},
							{},
							
							{
								{0.59297198,0.22628599},
								1
							},
							
							{
								{0.59860599,0.20727301},
								1
							},
							{},
							
							{
								{0.61881799,0.224373},
								1
							},
							
							{
								{0.62231201,0.21509001},
								1
							},
							{},
							
							{
								{0.38,0.95999998},
								1
							},
							
							{
								{0.62,0.95999998},
								1
							},
							{},
							
							{
								{0.51999998,0.95999998},
								1
							},
							
							{
								{0.51999998,0.92000002},
								1
							},
							{},
							
							{
								{0.47999999,0.95999998},
								1
							},
							
							{
								{0.47999999,0.92000002},
								1
							},
							{},
							
							{
								{0.36000001,0.89999998},
								1
							},
							
							{
								{0.36000001,0.86500001},
								1
							},
							{},
							
							{
								{0.40000001,0.89999998},
								1
							},
							
							{
								{0.40000001,0.86500001},
								1
							},
							{},
							
							{
								{0.44,0.89999998},
								1
							},
							
							{
								{0.44,0.86500001},
								1
							},
							{},
							
							{
								{0.47999999,0.89999998},
								1
							},
							
							{
								{0.47999999,0.86500001},
								1
							},
							{},
							
							{
								{0.51999998,0.89999998},
								1
							},
							
							{
								{0.51999998,0.86500001},
								1
							},
							{},
							
							{
								{0.56,0.89999998},
								1
							},
							
							{
								{0.56,0.86500001},
								1
							},
							{},
							
							{
								{0.60000002,0.89999998},
								1
							},
							
							{
								{0.60000002,0.86500001},
								1
							},
							{},
							
							{
								{0.63999999,0.89999998},
								1
							},
							
							{
								{0.63999999,0.86500001},
								1
							},
							{},
							
							{
								{0.98500001,0.25999999},
								1
							},
							
							{
								{1.005,0.25999999},
								1
							},
							{},
							
							{
								{0.94,0.25999999},
								1
							},
							
							{
								{0.95999998,0.25999999},
								1
							},
							{},
							
							{
								{0.98500001,0.38999999},
								1
							},
							
							{
								{1.005,0.38999999},
								1
							},
							{},
							
							{
								{0.94,0.38999999},
								1
							},
							
							{
								{0.95999998,0.38999999},
								1
							},
							{},
							
							{
								{0.94499999,0.41600001},
								1
							},
							
							{
								{0.95499998,0.41600001},
								1
							},
							{},
							
							{
								{0.94499999,0.442},
								1
							},
							
							{
								{0.95499998,0.442},
								1
							},
							{},
							
							{
								{0.94499999,0.46799999},
								1
							},
							
							{
								{0.95499998,0.46799999},
								1
							},
							{},
							
							{
								{0.94499999,0.49399999},
								1
							},
							
							{
								{0.95499998,0.49399999},
								1
							},
							{},
							
							{
								{0.94,0.51999998},
								1
							},
							
							{
								{0.95999998,0.51999998},
								1
							},
							{},
							
							{
								{0.98500001,0.51999998},
								1
							},
							
							{
								{1.005,0.51999998},
								1
							},
							{},
							
							{
								{0.98500001,0.64999998},
								1
							},
							
							{
								{1.005,0.64999998},
								1
							},
							{},
							
							{
								{0.94,0.64999998},
								1
							},
							
							{
								{0.95999998,0.64999998},
								1
							},
							{},
							
							{
								{0.94499999,0.62400001},
								1
							},
							
							{
								{0.95499998,0.62400001},
								1
							},
							{},
							
							{
								{0.94499999,0.59799999},
								1
							},
							
							{
								{0.95499998,0.59799999},
								1
							},
							{},
							
							{
								{0.94499999,0.57200003},
								1
							},
							
							{
								{0.95499998,0.57200003},
								1
							},
							{},
							
							{
								{0.94499999,0.546},
								1
							},
							
							{
								{0.95499998,0.546},
								1
							},
							{},
							
							{
								{0.99000001,0.676},
								1
							},
							
							{
								{1,0.676},
								1
							},
							{},
							
							{
								{0.99000001,0.70200002},
								1
							},
							
							{
								{1,0.70200002},
								1
							},
							{},
							
							{
								{0.99000001,0.72799999},
								1
							},
							
							{
								{1,0.72799999},
								1
							},
							{},
							
							{
								{0.99000001,0.75400001},
								1
							},
							
							{
								{1,0.75400001},
								1
							},
							{},
							
							{
								{0.98500001,0.77999997},
								1
							},
							
							{
								{1.005,0.77999997},
								1
							},
							{},
							
							{
								{0.94,0.77999997},
								1
							},
							
							{
								{0.95999998,0.77999997},
								1
							},
							{},
							
							{
								{0.125,0.93000001},
								1
							},
							
							{
								{0.215,0.93000001},
								1
							},
							
							{
								{0.215,0.98000002},
								1
							},
							
							{
								{0.125,0.98000002},
								1
							},
							
							{
								{0.125,0.93000001},
								1
							},
							{},
							
							{
								{0.80000001,0.014},
								1
							},
							
							{
								{0.87,0.014},
								1
							},
							{},
							
							{
								{0.50999999,0.014},
								1
							},
							
							{
								{0.61000001,0.014},
								1
							},
							{},
							
							{
								{0.38,0.014},
								1
							},
							
							{
								{0.46000001,0.014},
								1
							},
							{},
							
							{
								{0.13500001,0.014},
								1
							},
							
							{
								{0.2,0.014},
								1
							},
							{}
						};
					};
					class StaticBold
					{
						type="line";
						width=6;
						points[]=
						{
							
							{
								{0.36291301,0.242588},
								1
							},
							
							{
								{0.35460499,0.224563},
								1
							},
							{},
							
							{
								{0.5,0.21304099},
								1
							},
							
							{
								{0.5,0.16053},
								1
							},
							{},
							
							{
								{0.63708699,0.242588},
								1
							},
							
							{
								{0.64539498,0.224563},
								1
							},
							{},
							
							{
								"HUDCenter",
								{-0.108,0},
								1
							},
							
							{
								"HUDCenter",
								{-0.027000001,0},
								1
							},
							
							{
								"HUDCenter",
								{-0.0135,0.0285},
								1
							},
							
							{
								"HUDCenter",
								{0,0},
								1
							},
							
							{
								"HUDCenter",
								{0.0135,0.0285},
								1
							},
							
							{
								"HUDCenter",
								{0.027000001,0},
								1
							},
							
							{
								"HUDCenter",
								{0.108,0},
								1
							},
							{}
						};
					};
					class DrawBankLeft
					{
						condition="(horizonBank<=-0.4)";
						color[]={1,1,1};
						class Static
						{
							type="line";
							width=4;
							points[]=
							{
								
								{
									{0.177542,0.47049999},
									1
								},
								
								{
									{0.15799899,0.466288},
									1
								},
								{},
								
								{
									{0.181437,0.422277},
									1
								},
								
								{
									{0.172068,0.41881499},
									1
								},
								{},
								
								{
									{0.201589,0.378557},
									1
								},
								
								{
									{0.192812,0.37380901},
									1
								},
								{},
								
								{
									{0.23582099,0.34406099},
									1
								},
								
								{
									{0.21981101,0.33218601},
									1
								},
								{},
								
								{
									{0.25958401,0.30180001},
									1
								},
								
								{
									{0.25251299,0.29479399},
									1
								},
								{},
								
								{
									{0.30223799,0.278256},
									1
								},
								
								{
									{0.29025301,0.262393},
									1
								},
								{},
								
								{
									{0.337055,0.244339},
									1
								},
								
								{
									{0.33226299,0.235644},
									1
								},
								{}
							};
						};
					};
					class DrawBankRight
					{
						condition="(horizonBank>=0.4)";
						color[]={1,1,1};
						class Static
						{
							type="line";
							width=4;
							points[]=
							{
								
								{
									{0.66294497,0.244339},
									1
								},
								
								{
									{0.66773701,0.235644},
									1
								},
								{},
								
								{
									{0.69776201,0.278256},
									1
								},
								
								{
									{0.70974702,0.262393},
									1
								},
								{},
								
								{
									{0.74041599,0.30180001},
									1
								},
								
								{
									{0.74748701,0.29479399},
									1
								},
								{},
								
								{
									{0.76417899,0.34406099},
									1
								},
								
								{
									{0.78018898,0.33218601},
									1
								},
								{},
								
								{
									{0.79841101,0.378557},
									1
								},
								
								{
									{0.80718797,0.37380901},
									1
								},
								{},
								
								{
									{0.81856298,0.422277},
									1
								},
								
								{
									{0.827932,0.41881499},
									1
								},
								{},
								
								{
									{0.82245803,0.47049999},
									1
								},
								
								{
									{0.84200102,0.466288},
									1
								},
								{}
							};
						};
					};
					class RadarAltitude
					{
						condition="62-altitudeAGL";
						class RadarHeight
						{
							type="line";
							width=15;
							points[]=
							{
								
								{
									{0.97299999,0.77999997},
									1
								},
								
								{
									"RadarHeight",
									{0,0},
									1
								},
								{}
							};
						};
					};
					class HeadingHeadNumber
					{
						type="text";
						source="heading";
						sourceScale=1;
						align="center";
						scale=1;
						pos[]=
						{
							
							{
								0.5,
								"0.042+0.05"
							},
							1
						};
						right[]=
						{
							
							{
								0.54000002,
								"0.042+0.05"
							},
							1
						};
						down[]=
						{
							{0.5,0.132},
							1
						};
					};
					class HeadingScaleRight
					{
						clipTL[]={0.55000001,0};
						clipBR[]={0.76999998,0.5};
						class lines
						{
							type="scale";
							horizontal=1;
							source="heading";
							sourceScale=0.1;
							width=4;
							NeverEatSeaWeed=1;
							top=0.5;
							center=0.5;
							bottom=0.81999999;
							lineXleft=0.16;
							lineYright=0.15000001;
							lineXleftMajor=0.16;
							lineYrightMajor=0.14;
							majorLineEach=3;
							numberEach=3;
							step=1;
							stepSize=0.0263889;
							align="center";
							scale=1;
							pos[]=
							{
								0.495,
								"0.05+0.05"
							};
							right[]=
							{
								0.51999998,
								"0.05+0.05"
							};
							down[]=
							{
								0.495,
								"0.08+0.05"
							};
						};
					};
					class HeadingScaleMidle
					{
						type="scale";
						horizontal=1;
						source="heading";
						sourceScale=0.1;
						width=4;
						NeverEatSeaWeed=1;
						top=0.44999999;
						center=0.5;
						bottom=0.55000001;
						lineXleft=0.16;
						lineYright=0.15000001;
						lineXleftMajor=0.16;
						lineYrightMajor=0.15000001;
						majorLineEach=2;
						step=1;
						stepSize=0.0263889;
						align="center";
						scale=1;
						numberEach=0;
						pos[]=
						{
							0.47,
							"0.05+0.05"
						};
						right[]=
						{
							0.5,
							"0.05+0.05"
						};
						down[]=
						{
							0.44999999,
							"0.09+0.05"
						};
					};
					class HeadingScaleLeft
					{
						clipTL[]={0.23,0};
						clipBR[]={0.44999999,0.5};
						class lines
						{
							type="scale";
							horizontal=1;
							source="heading";
							sourceScale=0.1;
							width=4;
							NeverEatSeaWeed=1;
							top=0.17;
							center=0.5;
							bottom=0.55000001;
							lineXleft=0.16;
							lineYright=0.15000001;
							lineXleftMajor=0.16;
							lineYrightMajor=0.14;
							majorLineEach=3;
							numberEach=3;
							step=1;
							stepSize=0.0263889;
							align="center";
							scale=1;
							pos[]=
							{
								0.16599999,
								"0.05+0.05"
							};
							right[]=
							{
								0.191,
								"0.05+0.05"
							};
							down[]=
							{
								0.16599999,
								"0.08+0.05"
							};
						};
					};
					class HorizonBankRot
					{
						type="polygon";
						width=4;
						points[]=
						{
							
							{
								
								{
									"HorizonBankRot",
									1,
									{0,0},
									1
								},
								
								{
									"HorizonBankRot",
									{0.0026047199,-0.014636},
									1
								},
								
								{
									"HorizonBankRot",
									{0.0051302998,-0.0139655},
									1
								},
								
								{
									"HorizonBankRot",
									{0.0074999998,-0.0128707},
									1
								}
							},
							
							{
								
								{
									"HorizonBankRot",
									1,
									{0,0},
									1
								},
								
								{
									"HorizonBankRot",
									{0.0074999998,-0.0128707},
									1
								},
								
								{
									"HorizonBankRot",
									{0.0096418103,-0.0113848},
									1
								},
								
								{
									"HorizonBankRot",
									{0.0114907,-0.00955295},
									1
								}
							},
							
							{
								
								{
									"HorizonBankRot",
									1,
									{0,0},
									1
								},
								
								{
									"HorizonBankRot",
									{0.0114907,-0.00955295},
									1
								},
								
								{
									"HorizonBankRot",
									{0.0129904,-0.0074308799},
									1
								},
								
								{
									"HorizonBankRot",
									{0.0140954,-0.0050830198},
									1
								}
							},
							
							{
								
								{
									"HorizonBankRot",
									1,
									{0,0},
									1
								},
								
								{
									"HorizonBankRot",
									{0.0140954,-0.0050830198},
									1
								},
								
								{
									"HorizonBankRot",
									{0.0147721,-0.00258072},
									1
								},
								
								{
									"HorizonBankRot",
									{0.015,6.4962802e-010},
									1
								}
							},
							
							{
								
								{
									"HorizonBankRot",
									1,
									{0,0},
									1
								},
								
								{
									"HorizonBankRot",
									{0.015,6.4962802e-010},
									1
								},
								
								{
									"HorizonBankRot",
									{0.0147721,0.00258072},
									1
								},
								
								{
									"HorizonBankRot",
									{0.0140954,0.0050830198},
									1
								}
							},
							
							{
								
								{
									"HorizonBankRot",
									1,
									{0,0},
									1
								},
								
								{
									"HorizonBankRot",
									{0.0140954,0.0050830198},
									1
								},
								
								{
									"HorizonBankRot",
									{0.0129904,0.0074308799},
									1
								},
								
								{
									"HorizonBankRot",
									{0.0114907,0.00955295},
									1
								}
							},
							
							{
								
								{
									"HorizonBankRot",
									1,
									{0,0},
									1
								},
								
								{
									"HorizonBankRot",
									{0.0114907,0.00955295},
									1
								},
								
								{
									"HorizonBankRot",
									{0.0096418103,0.0113848},
									1
								},
								
								{
									"HorizonBankRot",
									{0.0074999998,0.0128707},
									1
								}
							},
							
							{
								
								{
									"HorizonBankRot",
									1,
									{0,0},
									1
								},
								
								{
									"HorizonBankRot",
									{0.0074999998,0.0128707},
									1
								},
								
								{
									"HorizonBankRot",
									{0.0051302998,0.0139655},
									1
								},
								
								{
									"HorizonBankRot",
									{0.0026047199,0.014636},
									1
								}
							},
							
							{
								
								{
									"HorizonBankRot",
									1,
									{0,0},
									1
								},
								
								{
									"HorizonBankRot",
									{0.0026047199,0.014636},
									1
								},
								
								{
									"HorizonBankRot",
									{-1.31134e-009,0.0148618},
									1
								},
								
								{
									"HorizonBankRot",
									{-0.00260473,0.014636},
									1
								}
							},
							
							{
								
								{
									"HorizonBankRot",
									1,
									{0,0},
									1
								},
								
								{
									"HorizonBankRot",
									{-0.00260473,0.014636},
									1
								},
								
								{
									"HorizonBankRot",
									{-0.0051302998,0.0139655},
									1
								},
								
								{
									"HorizonBankRot",
									{-0.0074999998,0.0128707},
									1
								}
							},
							
							{
								
								{
									"HorizonBankRot",
									1,
									{0,0},
									1
								},
								
								{
									"HorizonBankRot",
									{-0.0074999998,0.0128707},
									1
								},
								
								{
									"HorizonBankRot",
									{-0.0096418103,0.0113848},
									1
								},
								
								{
									"HorizonBankRot",
									{-0.0114907,0.00955295},
									1
								}
							},
							
							{
								
								{
									"HorizonBankRot",
									1,
									{0,0},
									1
								},
								
								{
									"HorizonBankRot",
									{-0.0114907,0.00955295},
									1
								},
								
								{
									"HorizonBankRot",
									{-0.0129904,0.0074308701},
									1
								},
								
								{
									"HorizonBankRot",
									{-0.0140954,0.0050830198},
									1
								}
							},
							
							{
								
								{
									"HorizonBankRot",
									1,
									{0,0},
									1
								},
								
								{
									"HorizonBankRot",
									{-0.0140954,0.0050830198},
									1
								},
								
								{
									"HorizonBankRot",
									{-0.0147721,0.00258072},
									1
								},
								
								{
									"HorizonBankRot",
									{-0.015,-1.77225e-010},
									1
								}
							},
							
							{
								
								{
									"HorizonBankRot",
									1,
									{0,0},
									1
								},
								
								{
									"HorizonBankRot",
									{-0.015,-1.77225e-010},
									1
								},
								
								{
									"HorizonBankRot",
									{-0.0147721,-0.00258072},
									1
								},
								
								{
									"HorizonBankRot",
									{-0.0140954,-0.0050830198},
									1
								}
							},
							
							{
								
								{
									"HorizonBankRot",
									1,
									{0,0},
									1
								},
								
								{
									"HorizonBankRot",
									{-0.0140954,-0.0050830198},
									1
								},
								
								{
									"HorizonBankRot",
									{-0.0129904,-0.0074308799},
									1
								},
								
								{
									"HorizonBankRot",
									{-0.0114907,-0.00955295},
									1
								}
							},
							
							{
								
								{
									"HorizonBankRot",
									1,
									{0,0},
									1
								},
								
								{
									"HorizonBankRot",
									{-0.0114907,-0.00955295},
									1
								},
								
								{
									"HorizonBankRot",
									{-0.0096418103,-0.0113848},
									1
								},
								
								{
									"HorizonBankRot",
									{-0.0074999998,-0.0128707},
									1
								}
							},
							
							{
								
								{
									"HorizonBankRot",
									1,
									{0,0},
									1
								},
								
								{
									"HorizonBankRot",
									{-0.0074999998,-0.0128707},
									1
								},
								
								{
									"HorizonBankRot",
									{-0.0051303101,-0.0139655},
									1
								},
								
								{
									"HorizonBankRot",
									{-0.0026047199,-0.014636},
									1
								}
							},
							
							{
								
								{
									"HorizonBankRot",
									1,
									{0,0},
									1
								},
								
								{
									"HorizonBankRot",
									{-0.0026047199,-0.014636},
									1
								},
								
								{
									"HorizonBankRot",
									{2.6226801e-009,-0.0148618},
									1
								},
								
								{
									"HorizonBankRot",
									{0.0026047199,-0.014636},
									1
								}
							},
							
							{
								
								{
									"FCR_Bearing",
									{-0.018999999,0},
									1
								},
								
								{
									"FCR_Bearing",
									{-0.0080000004,0},
									1
								},
								
								{
									"FCR_Bearing",
									{-0.0080000004,0.011},
									1
								},
								
								{
									"FCR_Bearing",
									{-0.018999999,0.011},
									1
								}
							},
							
							{
								
								{
									"FCR_Bearing",
									{-0.003,0},
									1
								},
								
								{
									"FCR_Bearing",
									{0.0080000004,0},
									1
								},
								
								{
									"FCR_Bearing",
									{0.0080000004,0.011},
									1
								},
								
								{
									"FCR_Bearing",
									{-0.003,0.011},
									1
								}
							},
							
							{
								
								{
									"FCR_Bearing",
									{0.0080000004,0},
									1
								},
								
								{
									"FCR_Bearing",
									{0.014,0.0055},
									1
								},
								
								{
									"FCR_Bearing",
									{0.0080000004,0.011},
									1
								}
							},
							
							{
								
								{
									"FCR_Bearing",
									{-0.018999999,0},
									1
								},
								
								{
									"FCR_Bearing",
									{-0.025,0.0055},
									1
								},
								
								{
									"FCR_Bearing",
									{-0.018999999,0.011},
									1
								}
							},
							
							{
								
								{
									"TurnRate",
									{-0.013,0},
									1
								},
								
								{
									"TurnRate",
									{0.017000001,0},
									1
								},
								
								{
									"TurnRate",
									{0.017000001,0.029999999},
									1
								},
								
								{
									"TurnRate",
									{-0.013,0.029999999},
									1
								}
							},
							
							{
								
								{
									{0.40000001,0.86500001},
									1
								},
								
								{
									{0.41999999,0.84500003},
									1
								},
								
								{
									{0.44,0.86500001},
									1
								}
							},
							
							{
								
								{
									{0.47999999,0.86500001},
									1
								},
								
								{
									{0.5,0.84500003},
									1
								},
								
								{
									{0.51999998,0.86500001},
									1
								}
							},
							
							{
								
								{
									{0.56,0.86500001},
									1
								},
								
								{
									{0.57999998,0.84500003},
									1
								},
								
								{
									{0.60000002,0.86500001},
									1
								}
							},
							
							{
								
								{
									"HorizonBankRot_Up",
									{0,-0.28732699},
									1
								},
								
								{
									"HorizonBankRot_Up",
									{0.0099999998,-0.26751199},
									1
								},
								
								{
									"HorizonBankRot_Up",
									{-0.0099999998,-0.26751199},
									1
								}
							},
							
							{
								
								{
									{0.87,0.0068000001},
									1
								},
								
								{
									{0.88999999,0.014},
									1
								},
								
								{
									{0.87,0.021199999},
									1
								}
							},
							
							{
								
								{
									{0.58999997,0.0068000001},
									1
								},
								
								{
									{0.61000001,0.014},
									1
								},
								
								{
									{0.58999997,0.021199999},
									1
								}
							},
							
							{
								
								{
									{0.46000001,0.0068000001},
									1
								},
								
								{
									{0.47999999,0.014},
									1
								},
								
								{
									{0.46000001,0.021199999},
									1
								}
							},
							
							{
								
								{
									{0.19,0.0068000001},
									1
								},
								
								{
									{0.20999999,0.014},
									1
								},
								
								{
									{0.19,0.021199999},
									1
								}
							},
							
							{
								
								{
									"VerticalSpeedBone",
									{0.92000002,0.50800002},
									1
								},
								
								{
									"VerticalSpeedBone",
									{0.94,0.51999998},
									1
								},
								
								{
									"VerticalSpeedBone",
									{0.92000002,0.53200001},
									1
								}
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
								{0.11,0.13},
								1
							};
							right[]=
							{
								{0.15000001,0.13},
								1
							};
							down[]=
							{
								{0.11,0.17},
								1
							};
						};
						class CollectiveNumber
						{
							type="text";
							source="rtdRotorTorque";
							sourceScale=200;
							align="left";
							scale=1;
							pos[]=
							{
								{0.11,0.13},
								1
							};
							right[]=
							{
								{0.15000001,0.13},
								1
							};
							down[]=
							{
								{0.11,0.17},
								1
							};
						};
					};
					class Speed_Normal
					{
						condition="speed<=108";
						class SpeedNumber
						{
							type="text";
							source="speed";
							sourceScale=1.9438444;
							align="right";
							scale=1;
							pos[]=
							{
								{0.07,0.47999999},
								1
							};
							right[]=
							{
								{0.11,0.47999999},
								1
							};
							down[]=
							{
								{0.07,0.51999998},
								1
							};
						};
					};
					class Speed_VNE: Speed_Normal
					{
						condition="speed>=108";
						color[]={1,0,0};
						class SpeedNumber: SpeedNumber
						{
						};
					};
					class AltNumber
					{
						type="text";
						source="altitudeAGL";
						sourceScale=3.2808399;
						sourceOffset=-6.88976;
						align="left";
						scale=1;
						pos[]=
						{
							{0.91000003,0.505},
							1
						};
						right[]=
						{
							{0.94,0.505},
							1
						};
						down[]=
						{
							{0.91000003,0.53500003},
							1
						};
					};
					class AslNumber
					{
						type="text";
						source="altitudeASL";
						sourceScale=3.2808399;
						sourceOffset=-6.5616798;
						align="left";
						scale=1;
						pos[]=
						{
							{0.92000002,0.115},
							1
						};
						right[]=
						{
							{0.95999998,0.115},
							1
						};
						down[]=
						{
							{0.92000002,0.155},
							1
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
								
								{
									"0.26+-0.03",
									"0.735+0.05"
								},
								1
							};
							right[]=
							{
								
								{
									0.26499999,
									"0.735+0.05"
								},
								1
							};
							down[]=
							{
								
								{
									"0.26+-0.03",
									0.81999999
								},
								1
							};
						};
						class WPIndex
						{
							type="text";
							source="wpIndex";
							sourceScale=1;
							sourceLength=2;
							align="right";
							scale=1;
							pos[]=
							{
								
								{
									"0.09+-0.03",
									"0.735+0.05"
								},
								1
							};
							right[]=
							{
								
								{
									0.094999999,
									"0.735+0.05"
								},
								1
							};
							down[]=
							{
								
								{
									"0.09+-0.03",
									0.81999999
								},
								1
							};
						};
						class WPGroundSpeed
						{
							type="text";
							source="speed";
							sourceScale=1.9438444;
							align="right";
							scale=1;
							pos[]=
							{
								
								{
									"0.055+-0.03",
									"0.735+0.055+0.05"
								},
								1
							};
							right[]=
							{
								
								{
									0.059999999,
									"0.735+0.055+0.05"
								},
								1
							};
							down[]=
							{
								
								{
									"0.055+-0.03",
									0.875
								},
								1
							};
						};
						class WPstatic
						{
							type="text";
							source="static";
							text="W";
							scale=1;
							sourceScale=1;
							align="right";
							pos[]=
							{
								
								{
									"-0.03 + 0.055",
									0.78500003
								},
								1
							};
							right[]=
							{
								{0.059999999,0.78500003},
								1
							};
							down[]=
							{
								
								{
									"-0.03 + 0.055",
									0.81999999
								},
								1
							};
						};
						class WPAuto
						{
							type="text";
							source="static";
							text="";
							scale=1;
							sourceScale=1;
							align="right";
							pos[]=
							{
								
								{
									"-0.03 + 0.055 +0.035",
									0.83999997
								},
								1
							};
							right[]=
							{
								{0.094999999,0.83999997},
								1
							};
							down[]=
							{
								
								{
									"-0.03 + 0.055 +0.035",
									0.875
								},
								1
							};
						};
						class WPKM
						{
							type="text";
							source="static";
							text="KM";
							scale=1;
							sourceScale=1;
							align="right";
							pos[]=
							{
								
								{
									"-0.03 + 0.055 +0.21",
									0.78500003
								},
								1
							};
							right[]=
							{
								{0.27000001,0.78500003},
								1
							};
							down[]=
							{
								
								{
									"-0.03 + 0.055 +0.21",
									0.81999999
								},
								1
							};
						};
						class WPTime_NoEst
						{
							condition="(speed<=5)+(wpdist<=1)";
							class WPTime
							{
								type="text";
								source="static";
								text="-:--";
								scale=1;
								sourceScale=1;
								align="right";
								pos[]=
								{
									
									{
										"-0.03 + 0.055 +0.15",
										0.83999997
									},
									1
								};
								right[]=
								{
									{0.20999999,0.83999997},
									1
								};
								down[]=
								{
									
									{
										"-0.03 + 0.055 +0.15",
										0.875
									},
									1
								};
							};
						};
						class WPTime_Est
						{
							condition="(speed>=5)*(wpdist>=1)";
							class WPTime
							{
								type="text";
								source="userText";
								sourceIndex=1;
								scale=1;
								sourceScale=1;
								align="right";
								pos[]=
								{
									{0.175,0.83999997},
									1
								};
								right[]=
								{
									{0.20999999,0.83999997},
									1
								};
								down[]=
								{
									{0.175,0.875},
									1
								};
							};
						};
						class Static
						{
							type="line";
							width=4;
							points[]=
							{
								
								{
									"WPPoint",
									1,
									"LimitWaypoint",
									1,
									{-0.0099999998,0.039999999},
									1
								},
								
								{
									"WPPoint",
									1,
									"LimitWaypoint",
									1,
									{0,0.02},
									1
								},
								
								{
									"WPPoint",
									1,
									"LimitWaypoint",
									1,
									{0.0099999998,0.039999999},
									1
								},
								{},
								
								{
									{0.0174,0.77399999},
									1
								},
								
								{
									{0.01195,0.78100002},
									1
								},
								
								{
									{0.0065000099,0.78799999},
									1
								},
								
								{
									{0.0065000099,0.87199998},
									1
								},
								
								{
									{0.01195,0.87900001},
									1
								},
								
								{
									{0.0174,0.88599998},
									1
								},
								
								{
									{0.3008,0.88599998},
									1
								},
								
								{
									{0.30625001,0.87900001},
									1
								},
								
								{
									{0.31169999,0.87199998},
									1
								},
								
								{
									{0.31169999,0.78799999},
									1
								},
								
								{
									{0.30625001,0.78100002},
									1
								},
								
								{
									{0.3008,0.77399999},
									1
								},
								
								{
									{0.0174,0.77399999},
									1
								},
								{}
							};
						};
					};
					class Cyan
					{
						color[]={0.0099999998,0.36000001,0.82999998};
						alpha=0.5;
						class HorizontalLine
						{
							clipTL[]={0.2,0.25};
							clipBR[]={0.80000001,0.75};
							class LevelP05
							{
								type="line";
								width=3;
								points[]=
								{
									
									{
										"LevelP05",
										{-0.0049999999,0},
										1
									},
									
									{
										"LevelP05",
										{0.025,0},
										1
									}
								};
							};
							class LevelP15
							{
								type="line";
								width=3;
								points[]=
								{
									
									{
										"LevelP15",
										{-0.0049999999,0},
										1
									},
									
									{
										"LevelP15",
										{0.025,0},
										1
									}
								};
							};
							class LevelP25
							{
								type="line";
								width=3;
								points[]=
								{
									
									{
										"LevelP25",
										{-0.0049999999,0},
										1
									},
									
									{
										"LevelP25",
										{0.025,0},
										1
									}
								};
							};
							class LevelP35
							{
								type="line";
								width=3;
								points[]=
								{
									
									{
										"LevelP35",
										{-0.0049999999,0},
										1
									},
									
									{
										"LevelP35",
										{0.025,0},
										1
									}
								};
							};
							class LevelP45
							{
								type="line";
								width=3;
								points[]=
								{
									
									{
										"LevelP45",
										{-0.0049999999,0},
										1
									},
									
									{
										"LevelP45",
										{0.025,0},
										1
									}
								};
							};
							class LevelP10
							{
								type="line";
								width=3;
								points[]=
								{
									
									{
										"LevelP10",
										{-0.16599999,0.02},
										1
									},
									
									{
										"LevelP10",
										{-0.16599999,0},
										1
									},
									
									{
										"LevelP10",
										{-0.039999999,0},
										1
									},
									{},
									
									{
										"LevelP10",
										{0.054000001,0},
										1
									},
									
									{
										"LevelP10",
										{0.19400001,0},
										1
									},
									
									{
										"LevelP10",
										{0.19400001,0.02},
										1
									}
								};
							};
							class VALP_1_10
							{
								type="text";
								source="static";
								text="10";
								align="left";
								scale=1;
								sourceScale=1;
								pos[]=
								{
									"LevelP10",
									{-0.19,-0.017000001},
									1
								};
								right[]=
								{
									"LevelP10",
									{-0.15000001,-0.017000001},
									1
								};
								down[]=
								{
									"LevelP10",
									{-0.19,0.030999999},
									1
								};
							};
							class VALP_1_10_R
							{
								type="text";
								source="static";
								text="10";
								align="right";
								scale=1;
								sourceScale=1;
								pos[]=
								{
									"LevelP10",
									{0.20999999,-0.017000001},
									1
								};
								right[]=
								{
									"LevelP10",
									{0.25,-0.017000001},
									1
								};
								down[]=
								{
									"LevelP10",
									{0.20999999,0.030999999},
									1
								};
							};
							class LevelP20
							{
								type="line";
								width=3;
								points[]=
								{
									
									{
										"LevelP20",
										{-0.16599999,0.02},
										1
									},
									
									{
										"LevelP20",
										{-0.16599999,0},
										1
									},
									
									{
										"LevelP20",
										{-0.039999999,0},
										1
									},
									{},
									
									{
										"LevelP20",
										{0.054000001,0},
										1
									},
									
									{
										"LevelP20",
										{0.19400001,0},
										1
									},
									
									{
										"LevelP20",
										{0.19400001,0.02},
										1
									}
								};
							};
							class VALP_1_20
							{
								type="text";
								source="static";
								text="20";
								align="left";
								scale=1;
								sourceScale=1;
								pos[]=
								{
									"LevelP20",
									{-0.19,-0.017000001},
									1
								};
								right[]=
								{
									"LevelP20",
									{-0.15000001,-0.017000001},
									1
								};
								down[]=
								{
									"LevelP20",
									{-0.19,0.030999999},
									1
								};
							};
							class VALP_1_20_R
							{
								type="text";
								source="static";
								text="20";
								align="right";
								scale=1;
								sourceScale=1;
								pos[]=
								{
									"LevelP20",
									{0.20999999,-0.017000001},
									1
								};
								right[]=
								{
									"LevelP20",
									{0.25,-0.017000001},
									1
								};
								down[]=
								{
									"LevelP20",
									{0.20999999,0.030999999},
									1
								};
							};
							class LevelP30
							{
								type="line";
								width=3;
								points[]=
								{
									
									{
										"LevelP30",
										{-0.16599999,0.02},
										1
									},
									
									{
										"LevelP30",
										{-0.16599999,0},
										1
									},
									
									{
										"LevelP30",
										{-0.039999999,0},
										1
									},
									{},
									
									{
										"LevelP30",
										{0.054000001,0},
										1
									},
									
									{
										"LevelP30",
										{0.19400001,0},
										1
									},
									
									{
										"LevelP30",
										{0.19400001,0.02},
										1
									}
								};
							};
							class VALP_1_30
							{
								type="text";
								source="static";
								text="30";
								align="left";
								scale=1;
								sourceScale=1;
								pos[]=
								{
									"LevelP30",
									{-0.19,-0.017000001},
									1
								};
								right[]=
								{
									"LevelP30",
									{-0.15000001,-0.017000001},
									1
								};
								down[]=
								{
									"LevelP30",
									{-0.19,0.030999999},
									1
								};
							};
							class VALP_1_30_R
							{
								type="text";
								source="static";
								text="30";
								align="right";
								scale=1;
								sourceScale=1;
								pos[]=
								{
									"LevelP30",
									{0.20999999,-0.017000001},
									1
								};
								right[]=
								{
									"LevelP30",
									{0.25,-0.017000001},
									1
								};
								down[]=
								{
									"LevelP30",
									{0.20999999,0.030999999},
									1
								};
							};
							class LevelP40
							{
								type="line";
								width=3;
								points[]=
								{
									
									{
										"LevelP40",
										{-0.16599999,0.02},
										1
									},
									
									{
										"LevelP40",
										{-0.16599999,0},
										1
									},
									
									{
										"LevelP40",
										{-0.039999999,0},
										1
									},
									{},
									
									{
										"LevelP40",
										{0.054000001,0},
										1
									},
									
									{
										"LevelP40",
										{0.19400001,0},
										1
									},
									
									{
										"LevelP40",
										{0.19400001,0.02},
										1
									}
								};
							};
							class VALP_1_40
							{
								type="text";
								source="static";
								text="40";
								align="left";
								scale=1;
								sourceScale=1;
								pos[]=
								{
									"LevelP40",
									{-0.19,-0.017000001},
									1
								};
								right[]=
								{
									"LevelP40",
									{-0.15000001,-0.017000001},
									1
								};
								down[]=
								{
									"LevelP40",
									{-0.19,0.030999999},
									1
								};
							};
							class VALP_1_40_R
							{
								type="text";
								source="static";
								text="40";
								align="right";
								scale=1;
								sourceScale=1;
								pos[]=
								{
									"LevelP40",
									{0.20999999,-0.017000001},
									1
								};
								right[]=
								{
									"LevelP40",
									{0.25,-0.017000001},
									1
								};
								down[]=
								{
									"LevelP40",
									{0.20999999,0.030999999},
									1
								};
							};
							class LevelP50
							{
								type="line";
								width=3;
								points[]=
								{
									
									{
										"LevelP50",
										{-0.16599999,0.02},
										1
									},
									
									{
										"LevelP50",
										{-0.16599999,0},
										1
									},
									
									{
										"LevelP50",
										{-0.039999999,0},
										1
									},
									{},
									
									{
										"LevelP50",
										{0.054000001,0},
										1
									},
									
									{
										"LevelP50",
										{0.19400001,0},
										1
									},
									
									{
										"LevelP50",
										{0.19400001,0.02},
										1
									}
								};
							};
							class VALP_1_50
							{
								type="text";
								source="static";
								text="50";
								align="left";
								scale=1;
								sourceScale=1;
								pos[]=
								{
									"LevelP50",
									{-0.19,-0.017000001},
									1
								};
								right[]=
								{
									"LevelP50",
									{-0.15000001,-0.017000001},
									1
								};
								down[]=
								{
									"LevelP50",
									{-0.19,0.030999999},
									1
								};
							};
							class VALP_1_50_R
							{
								type="text";
								source="static";
								text="50";
								align="right";
								scale=1;
								sourceScale=1;
								pos[]=
								{
									"LevelP50",
									{0.20999999,-0.017000001},
									1
								};
								right[]=
								{
									"LevelP50",
									{0.25,-0.017000001},
									1
								};
								down[]=
								{
									"LevelP50",
									{0.20999999,0.030999999},
									1
								};
							};
							class LevelP60
							{
								type="line";
								width=3;
								points[]=
								{
									
									{
										"LevelP60",
										{-0.16599999,0.02},
										1
									},
									
									{
										"LevelP60",
										{-0.16599999,0},
										1
									},
									
									{
										"LevelP60",
										{-0.039999999,0},
										1
									},
									{},
									
									{
										"LevelP60",
										{0.054000001,0},
										1
									},
									
									{
										"LevelP60",
										{0.19400001,0},
										1
									},
									
									{
										"LevelP60",
										{0.19400001,0.02},
										1
									}
								};
							};
							class VALP_1_60
							{
								type="text";
								source="static";
								text="60";
								align="left";
								scale=1;
								sourceScale=1;
								pos[]=
								{
									"LevelP60",
									{-0.19,-0.017000001},
									1
								};
								right[]=
								{
									"LevelP60",
									{-0.15000001,-0.017000001},
									1
								};
								down[]=
								{
									"LevelP60",
									{-0.19,0.030999999},
									1
								};
							};
							class VALP_1_60_R
							{
								type="text";
								source="static";
								text="60";
								align="right";
								scale=1;
								sourceScale=1;
								pos[]=
								{
									"LevelP60",
									{0.20999999,-0.017000001},
									1
								};
								right[]=
								{
									"LevelP60",
									{0.25,-0.017000001},
									1
								};
								down[]=
								{
									"LevelP60",
									{0.20999999,0.030999999},
									1
								};
							};
							class LevelP70
							{
								type="line";
								width=3;
								points[]=
								{
									
									{
										"LevelP70",
										{-0.16599999,0.02},
										1
									},
									
									{
										"LevelP70",
										{-0.16599999,0},
										1
									},
									
									{
										"LevelP70",
										{-0.039999999,0},
										1
									},
									{},
									
									{
										"LevelP70",
										{0.054000001,0},
										1
									},
									
									{
										"LevelP70",
										{0.19400001,0},
										1
									},
									
									{
										"LevelP70",
										{0.19400001,0.02},
										1
									}
								};
							};
							class VALP_1_70
							{
								type="text";
								source="static";
								text="70";
								align="left";
								scale=1;
								sourceScale=1;
								pos[]=
								{
									"LevelP70",
									{-0.19,-0.017000001},
									1
								};
								right[]=
								{
									"LevelP70",
									{-0.15000001,-0.017000001},
									1
								};
								down[]=
								{
									"LevelP70",
									{-0.19,0.030999999},
									1
								};
							};
							class VALP_1_70_R
							{
								type="text";
								source="static";
								text="70";
								align="right";
								scale=1;
								sourceScale=1;
								pos[]=
								{
									"LevelP70",
									{0.20999999,-0.017000001},
									1
								};
								right[]=
								{
									"LevelP70",
									{0.25,-0.017000001},
									1
								};
								down[]=
								{
									"LevelP70",
									{0.20999999,0.030999999},
									1
								};
							};
							class LevelP80
							{
								type="line";
								width=3;
								points[]=
								{
									
									{
										"LevelP80",
										{-0.16599999,0.02},
										1
									},
									
									{
										"LevelP80",
										{-0.16599999,0},
										1
									},
									
									{
										"LevelP80",
										{-0.039999999,0},
										1
									},
									{},
									
									{
										"LevelP80",
										{0.054000001,0},
										1
									},
									
									{
										"LevelP80",
										{0.19400001,0},
										1
									},
									
									{
										"LevelP80",
										{0.19400001,0.02},
										1
									}
								};
							};
							class VALP_1_80
							{
								type="text";
								source="static";
								text="80";
								align="left";
								scale=1;
								sourceScale=1;
								pos[]=
								{
									"LevelP80",
									{-0.19,-0.017000001},
									1
								};
								right[]=
								{
									"LevelP80",
									{-0.15000001,-0.017000001},
									1
								};
								down[]=
								{
									"LevelP80",
									{-0.19,0.030999999},
									1
								};
							};
							class VALP_1_80_R
							{
								type="text";
								source="static";
								text="80";
								align="right";
								scale=1;
								sourceScale=1;
								pos[]=
								{
									"LevelP80",
									{0.20999999,-0.017000001},
									1
								};
								right[]=
								{
									"LevelP80",
									{0.25,-0.017000001},
									1
								};
								down[]=
								{
									"LevelP80",
									{0.20999999,0.030999999},
									1
								};
							};
						};
					};
					class Brown
					{
						color[]={0.94,0.18000001,0};
						alpha=0.5;
						class HorizontalLine
						{
							clipTL[]={0.2,0.25};
							clipBR[]={0.80000001,0.75};
							class Level0
							{
								type="line";
								source="Level0";
								width=3;
								points[]=
								{
									
									{
										"Level0",
										{-0.54000002,0},
										1
									},
									
									{
										"Level0",
										{-0.067500003,0},
										1
									},
									{},
									
									{
										"Level0",
										{0.067500003,0},
										1
									},
									
									{
										"Level0",
										{0.54000002,0},
										1
									}
								};
							};
							class LevelM05
							{
								type="line";
								width=3;
								points[]=
								{
									
									{
										"LevelM05",
										{-0.0049999999,0},
										1
									},
									
									{
										"LevelM05",
										{0.025,0},
										1
									}
								};
							};
							class LevelM15
							{
								type="line";
								width=3;
								points[]=
								{
									
									{
										"LevelM15",
										{-0.0049999999,0},
										1
									},
									
									{
										"LevelM15",
										{0.025,0},
										1
									}
								};
							};
							class LevelM25
							{
								type="line";
								width=3;
								points[]=
								{
									
									{
										"LevelM25",
										{-0.0049999999,0},
										1
									},
									
									{
										"LevelM25",
										{0.025,0},
										1
									}
								};
							};
							class LevelM35
							{
								type="line";
								width=3;
								points[]=
								{
									
									{
										"LevelM35",
										{-0.0049999999,0},
										1
									},
									
									{
										"LevelM35",
										{0.025,0},
										1
									}
								};
							};
							class LevelM45
							{
								type="line";
								width=3;
								points[]=
								{
									
									{
										"LevelM45",
										{-0.0049999999,0},
										1
									},
									
									{
										"LevelM45",
										{0.025,0},
										1
									}
								};
							};
							class LevelM10
							{
								type="line";
								width=3;
								points[]=
								{
									
									{
										"LevelM10",
										{-0.16599999,-0.02},
										1
									},
									
									{
										"LevelM10",
										{-0.16599999,0},
										1
									},
									
									{
										"LevelM10",
										{-0.138,0},
										1
									},
									{},
									
									{
										"LevelM10",
										{-0.124,0},
										1
									},
									
									{
										"LevelM10",
										{-0.096000001,0},
										1
									},
									{},
									
									{
										"LevelM10",
										{-0.082000002,0},
										1
									},
									
									{
										"LevelM10",
										{-0.054000001,0},
										1
									},
									{},
									{},
									
									{
										"LevelM10",
										{0.16599999,-0.02},
										1
									},
									
									{
										"LevelM10",
										{0.16599999,0},
										1
									},
									
									{
										"LevelM10",
										{0.138,0},
										1
									},
									{},
									
									{
										"LevelM10",
										{0.124,0},
										1
									},
									
									{
										"LevelM10",
										{0.096000001,0},
										1
									},
									{},
									
									{
										"LevelM10",
										{0.082000002,0},
										1
									},
									
									{
										"LevelM10",
										{0.054000001,0},
										1
									},
									{}
								};
							};
							class VALM_1_10
							{
								type="text";
								source="static";
								text=10;
								align="left";
								scale=1;
								sourceScale=1;
								sourceLength=2;
								pos[]=
								{
									"LevelM10",
									{-0.18000001,-0.032000002},
									1
								};
								right[]=
								{
									"LevelM10",
									{-0.14,-0.032000002},
									1
								};
								down[]=
								{
									"LevelM10",
									{-0.18000001,0.016000001},
									1
								};
							};
							class VALM_1_10_R
							{
								type="text";
								source="static";
								text=10;
								align="right";
								scale=1;
								sourceScale=1;
								sourceLength=2;
								pos[]=
								{
									"LevelM10",
									{0.18000001,-0.032000002},
									1
								};
								right[]=
								{
									"LevelM10",
									{0.22,-0.032000002},
									1
								};
								down[]=
								{
									"LevelM10",
									{0.18000001,0.016000001},
									1
								};
							};
							class LevelM20
							{
								type="line";
								width=3;
								points[]=
								{
									
									{
										"LevelM20",
										{-0.16599999,-0.02},
										1
									},
									
									{
										"LevelM20",
										{-0.16599999,0},
										1
									},
									
									{
										"LevelM20",
										{-0.138,0},
										1
									},
									{},
									
									{
										"LevelM20",
										{-0.124,0},
										1
									},
									
									{
										"LevelM20",
										{-0.096000001,0},
										1
									},
									{},
									
									{
										"LevelM20",
										{-0.082000002,0},
										1
									},
									
									{
										"LevelM20",
										{-0.054000001,0},
										1
									},
									{},
									{},
									
									{
										"LevelM20",
										{0.16599999,-0.02},
										1
									},
									
									{
										"LevelM20",
										{0.16599999,0},
										1
									},
									
									{
										"LevelM20",
										{0.138,0},
										1
									},
									{},
									
									{
										"LevelM20",
										{0.124,0},
										1
									},
									
									{
										"LevelM20",
										{0.096000001,0},
										1
									},
									{},
									
									{
										"LevelM20",
										{0.082000002,0},
										1
									},
									
									{
										"LevelM20",
										{0.054000001,0},
										1
									},
									{}
								};
							};
							class VALM_1_20
							{
								type="text";
								source="static";
								text=20;
								align="left";
								scale=1;
								sourceScale=1;
								sourceLength=2;
								pos[]=
								{
									"LevelM20",
									{-0.18000001,-0.032000002},
									1
								};
								right[]=
								{
									"LevelM20",
									{-0.14,-0.032000002},
									1
								};
								down[]=
								{
									"LevelM20",
									{-0.18000001,0.016000001},
									1
								};
							};
							class VALM_1_20_R
							{
								type="text";
								source="static";
								text=20;
								align="right";
								scale=1;
								sourceScale=1;
								sourceLength=2;
								pos[]=
								{
									"LevelM20",
									{0.18000001,-0.032000002},
									1
								};
								right[]=
								{
									"LevelM20",
									{0.22,-0.032000002},
									1
								};
								down[]=
								{
									"LevelM20",
									{0.18000001,0.016000001},
									1
								};
							};
							class LevelM30
							{
								type="line";
								width=3;
								points[]=
								{
									
									{
										"LevelM30",
										{-0.16599999,-0.02},
										1
									},
									
									{
										"LevelM30",
										{-0.16599999,0},
										1
									},
									
									{
										"LevelM30",
										{-0.138,0},
										1
									},
									{},
									
									{
										"LevelM30",
										{-0.124,0},
										1
									},
									
									{
										"LevelM30",
										{-0.096000001,0},
										1
									},
									{},
									
									{
										"LevelM30",
										{-0.082000002,0},
										1
									},
									
									{
										"LevelM30",
										{-0.054000001,0},
										1
									},
									{},
									{},
									
									{
										"LevelM30",
										{0.16599999,-0.02},
										1
									},
									
									{
										"LevelM30",
										{0.16599999,0},
										1
									},
									
									{
										"LevelM30",
										{0.138,0},
										1
									},
									{},
									
									{
										"LevelM30",
										{0.124,0},
										1
									},
									
									{
										"LevelM30",
										{0.096000001,0},
										1
									},
									{},
									
									{
										"LevelM30",
										{0.082000002,0},
										1
									},
									
									{
										"LevelM30",
										{0.054000001,0},
										1
									},
									{}
								};
							};
							class VALM_1_30
							{
								type="text";
								source="static";
								text=30;
								align="left";
								scale=1;
								sourceScale=1;
								sourceLength=2;
								pos[]=
								{
									"LevelM30",
									{-0.18000001,-0.032000002},
									1
								};
								right[]=
								{
									"LevelM30",
									{-0.14,-0.032000002},
									1
								};
								down[]=
								{
									"LevelM30",
									{-0.18000001,0.016000001},
									1
								};
							};
							class VALM_1_30_R
							{
								type="text";
								source="static";
								text=30;
								align="right";
								scale=1;
								sourceScale=1;
								sourceLength=2;
								pos[]=
								{
									"LevelM30",
									{0.18000001,-0.032000002},
									1
								};
								right[]=
								{
									"LevelM30",
									{0.22,-0.032000002},
									1
								};
								down[]=
								{
									"LevelM30",
									{0.18000001,0.016000001},
									1
								};
							};
							class LevelM40
							{
								type="line";
								width=3;
								points[]=
								{
									
									{
										"LevelM40",
										{-0.16599999,-0.02},
										1
									},
									
									{
										"LevelM40",
										{-0.16599999,0},
										1
									},
									
									{
										"LevelM40",
										{-0.138,0},
										1
									},
									{},
									
									{
										"LevelM40",
										{-0.124,0},
										1
									},
									
									{
										"LevelM40",
										{-0.096000001,0},
										1
									},
									{},
									
									{
										"LevelM40",
										{-0.082000002,0},
										1
									},
									
									{
										"LevelM40",
										{-0.054000001,0},
										1
									},
									{},
									{},
									
									{
										"LevelM40",
										{0.16599999,-0.02},
										1
									},
									
									{
										"LevelM40",
										{0.16599999,0},
										1
									},
									
									{
										"LevelM40",
										{0.138,0},
										1
									},
									{},
									
									{
										"LevelM40",
										{0.124,0},
										1
									},
									
									{
										"LevelM40",
										{0.096000001,0},
										1
									},
									{},
									
									{
										"LevelM40",
										{0.082000002,0},
										1
									},
									
									{
										"LevelM40",
										{0.054000001,0},
										1
									},
									{}
								};
							};
							class VALM_1_40
							{
								type="text";
								source="static";
								text=40;
								align="left";
								scale=1;
								sourceScale=1;
								sourceLength=2;
								pos[]=
								{
									"LevelM40",
									{-0.18000001,-0.032000002},
									1
								};
								right[]=
								{
									"LevelM40",
									{-0.14,-0.032000002},
									1
								};
								down[]=
								{
									"LevelM40",
									{-0.18000001,0.016000001},
									1
								};
							};
							class VALM_1_40_R
							{
								type="text";
								source="static";
								text=40;
								align="right";
								scale=1;
								sourceScale=1;
								sourceLength=2;
								pos[]=
								{
									"LevelM40",
									{0.18000001,-0.032000002},
									1
								};
								right[]=
								{
									"LevelM40",
									{0.22,-0.032000002},
									1
								};
								down[]=
								{
									"LevelM40",
									{0.18000001,0.016000001},
									1
								};
							};
							class LevelM50
							{
								type="line";
								width=3;
								points[]=
								{
									
									{
										"LevelM50",
										{-0.16599999,-0.02},
										1
									},
									
									{
										"LevelM50",
										{-0.16599999,0},
										1
									},
									
									{
										"LevelM50",
										{-0.138,0},
										1
									},
									{},
									
									{
										"LevelM50",
										{-0.124,0},
										1
									},
									
									{
										"LevelM50",
										{-0.096000001,0},
										1
									},
									{},
									
									{
										"LevelM50",
										{-0.082000002,0},
										1
									},
									
									{
										"LevelM50",
										{-0.054000001,0},
										1
									},
									{},
									{},
									
									{
										"LevelM50",
										{0.16599999,-0.02},
										1
									},
									
									{
										"LevelM50",
										{0.16599999,0},
										1
									},
									
									{
										"LevelM50",
										{0.138,0},
										1
									},
									{},
									
									{
										"LevelM50",
										{0.124,0},
										1
									},
									
									{
										"LevelM50",
										{0.096000001,0},
										1
									},
									{},
									
									{
										"LevelM50",
										{0.082000002,0},
										1
									},
									
									{
										"LevelM50",
										{0.054000001,0},
										1
									},
									{}
								};
							};
							class VALM_1_50
							{
								type="text";
								source="static";
								text=50;
								align="left";
								scale=1;
								sourceScale=1;
								sourceLength=2;
								pos[]=
								{
									"LevelM50",
									{-0.18000001,-0.032000002},
									1
								};
								right[]=
								{
									"LevelM50",
									{-0.14,-0.032000002},
									1
								};
								down[]=
								{
									"LevelM50",
									{-0.18000001,0.016000001},
									1
								};
							};
							class VALM_1_50_R
							{
								type="text";
								source="static";
								text=50;
								align="right";
								scale=1;
								sourceScale=1;
								sourceLength=2;
								pos[]=
								{
									"LevelM50",
									{0.18000001,-0.032000002},
									1
								};
								right[]=
								{
									"LevelM50",
									{0.22,-0.032000002},
									1
								};
								down[]=
								{
									"LevelM50",
									{0.18000001,0.016000001},
									1
								};
							};
							class LevelM60
							{
								type="line";
								width=3;
								points[]=
								{
									
									{
										"LevelM60",
										{-0.16599999,-0.02},
										1
									},
									
									{
										"LevelM60",
										{-0.16599999,0},
										1
									},
									
									{
										"LevelM60",
										{-0.138,0},
										1
									},
									{},
									
									{
										"LevelM60",
										{-0.124,0},
										1
									},
									
									{
										"LevelM60",
										{-0.096000001,0},
										1
									},
									{},
									
									{
										"LevelM60",
										{-0.082000002,0},
										1
									},
									
									{
										"LevelM60",
										{-0.054000001,0},
										1
									},
									{},
									{},
									
									{
										"LevelM60",
										{0.16599999,-0.02},
										1
									},
									
									{
										"LevelM60",
										{0.16599999,0},
										1
									},
									
									{
										"LevelM60",
										{0.138,0},
										1
									},
									{},
									
									{
										"LevelM60",
										{0.124,0},
										1
									},
									
									{
										"LevelM60",
										{0.096000001,0},
										1
									},
									{},
									
									{
										"LevelM60",
										{0.082000002,0},
										1
									},
									
									{
										"LevelM60",
										{0.054000001,0},
										1
									},
									{}
								};
							};
							class VALM_1_60
							{
								type="text";
								source="static";
								text=60;
								align="left";
								scale=1;
								sourceScale=1;
								sourceLength=2;
								pos[]=
								{
									"LevelM60",
									{-0.18000001,-0.032000002},
									1
								};
								right[]=
								{
									"LevelM60",
									{-0.14,-0.032000002},
									1
								};
								down[]=
								{
									"LevelM60",
									{-0.18000001,0.016000001},
									1
								};
							};
							class VALM_1_60_R
							{
								type="text";
								source="static";
								text=60;
								align="right";
								scale=1;
								sourceScale=1;
								sourceLength=2;
								pos[]=
								{
									"LevelM60",
									{0.18000001,-0.032000002},
									1
								};
								right[]=
								{
									"LevelM60",
									{0.22,-0.032000002},
									1
								};
								down[]=
								{
									"LevelM60",
									{0.18000001,0.016000001},
									1
								};
							};
							class LevelM70
							{
								type="line";
								width=3;
								points[]=
								{
									
									{
										"LevelM70",
										{-0.16599999,-0.02},
										1
									},
									
									{
										"LevelM70",
										{-0.16599999,0},
										1
									},
									
									{
										"LevelM70",
										{-0.138,0},
										1
									},
									{},
									
									{
										"LevelM70",
										{-0.124,0},
										1
									},
									
									{
										"LevelM70",
										{-0.096000001,0},
										1
									},
									{},
									
									{
										"LevelM70",
										{-0.082000002,0},
										1
									},
									
									{
										"LevelM70",
										{-0.054000001,0},
										1
									},
									{},
									{},
									
									{
										"LevelM70",
										{0.16599999,-0.02},
										1
									},
									
									{
										"LevelM70",
										{0.16599999,0},
										1
									},
									
									{
										"LevelM70",
										{0.138,0},
										1
									},
									{},
									
									{
										"LevelM70",
										{0.124,0},
										1
									},
									
									{
										"LevelM70",
										{0.096000001,0},
										1
									},
									{},
									
									{
										"LevelM70",
										{0.082000002,0},
										1
									},
									
									{
										"LevelM70",
										{0.054000001,0},
										1
									},
									{}
								};
							};
							class VALM_1_70
							{
								type="text";
								source="static";
								text=70;
								align="left";
								scale=1;
								sourceScale=1;
								sourceLength=2;
								pos[]=
								{
									"LevelM70",
									{-0.18000001,-0.032000002},
									1
								};
								right[]=
								{
									"LevelM70",
									{-0.14,-0.032000002},
									1
								};
								down[]=
								{
									"LevelM70",
									{-0.18000001,0.016000001},
									1
								};
							};
							class VALM_1_70_R
							{
								type="text";
								source="static";
								text=70;
								align="right";
								scale=1;
								sourceScale=1;
								sourceLength=2;
								pos[]=
								{
									"LevelM70",
									{0.18000001,-0.032000002},
									1
								};
								right[]=
								{
									"LevelM70",
									{0.22,-0.032000002},
									1
								};
								down[]=
								{
									"LevelM70",
									{0.18000001,0.016000001},
									1
								};
							};
							class LevelM80
							{
								type="line";
								width=3;
								points[]=
								{
									
									{
										"LevelM80",
										{-0.16599999,-0.02},
										1
									},
									
									{
										"LevelM80",
										{-0.16599999,0},
										1
									},
									
									{
										"LevelM80",
										{-0.138,0},
										1
									},
									{},
									
									{
										"LevelM80",
										{-0.124,0},
										1
									},
									
									{
										"LevelM80",
										{-0.096000001,0},
										1
									},
									{},
									
									{
										"LevelM80",
										{-0.082000002,0},
										1
									},
									
									{
										"LevelM80",
										{-0.054000001,0},
										1
									},
									{},
									{},
									
									{
										"LevelM80",
										{0.16599999,-0.02},
										1
									},
									
									{
										"LevelM80",
										{0.16599999,0},
										1
									},
									
									{
										"LevelM80",
										{0.138,0},
										1
									},
									{},
									
									{
										"LevelM80",
										{0.124,0},
										1
									},
									
									{
										"LevelM80",
										{0.096000001,0},
										1
									},
									{},
									
									{
										"LevelM80",
										{0.082000002,0},
										1
									},
									
									{
										"LevelM80",
										{0.054000001,0},
										1
									},
									{}
								};
							};
							class VALM_1_80
							{
								type="text";
								source="static";
								text=80;
								align="left";
								scale=1;
								sourceScale=1;
								sourceLength=2;
								pos[]=
								{
									"LevelM80",
									{-0.18000001,-0.032000002},
									1
								};
								right[]=
								{
									"LevelM80",
									{-0.14,-0.032000002},
									1
								};
								down[]=
								{
									"LevelM80",
									{-0.18000001,0.016000001},
									1
								};
							};
							class VALM_1_80_R
							{
								type="text";
								source="static";
								text=80;
								align="right";
								scale=1;
								sourceScale=1;
								sourceLength=2;
								pos[]=
								{
									"LevelM80",
									{0.18000001,-0.032000002},
									1
								};
								right[]=
								{
									"LevelM80",
									{0.22,-0.032000002},
									1
								};
								down[]=
								{
									"LevelM80",
									{0.18000001,0.016000001},
									1
								};
							};
						};
					};
					class Red
					{
						color[]={1,0,0};
						alpha=0.30000001;
						class LO_Alt
						{
							condition="altitudeAGL <= 10";
							class Lo_ALT
							{
								type="text";
								source="static";
								text="LO";
								scale=1;
								sourceScale=1;
								align="left";
								pos[]=
								{
									{0.91000003,0.56999999},
									1
								};
								right[]=
								{
									{0.94999999,0.56999999},
									1
								};
								down[]=
								{
									{0.91000003,0.61000001},
									1
								};
							};
						};
					};
					class Engine
					{
						type="text";
						source="static";
						text="ENG";
						scale=1;
						sourceScale=1;
						align="left";
						pos[]=
						{
							{0.20999999,0.029999999},
							1
						};
						right[]=
						{
							{0.23999999,0.029999999},
							1
						};
						down[]=
						{
							{0.20999999,0.059999999},
							1
						};
					};
					class Fuel
					{
						type="text";
						source="static";
						text="FUEL";
						scale=1;
						sourceScale=1;
						align="left";
						pos[]=
						{
							{0.47999999,0.029999999},
							1
						};
						right[]=
						{
							{0.50999999,0.029999999},
							1
						};
						down[]=
						{
							{0.47999999,0.059999999},
							1
						};
					};
					class Performance
					{
						type="text";
						source="static";
						text="PERF";
						scale=1;
						sourceScale=1;
						align="left";
						pos[]=
						{
							{0.61000001,0.029999999},
							1
						};
						right[]=
						{
							{0.63999999,0.029999999},
							1
						};
						down[]=
						{
							{0.61000001,0.059999999},
							1
						};
					};
					class Utilities
					{
						type="text";
						source="static";
						text="UTIL";
						scale=1;
						sourceScale=1;
						align="left";
						pos[]=
						{
							{0.88999999,0.029999999},
							1
						};
						right[]=
						{
							{0.92000002,0.029999999},
							1
						};
						down[]=
						{
							{0.88999999,0.059999999},
							1
						};
					};
					class Flight
					{
						type="text";
						source="static";
						text="FLT";
						scale=1;
						sourceScale=1;
						align="left";
						pos[]=
						{
							{0.20999999,0.94},
							1
						};
						right[]=
						{
							{0.23999999,0.94},
							1
						};
						down[]=
						{
							{0.20999999,0.97000003},
							1
						};
					};
					class Set
					{
						type="text";
						source="static";
						text="SET";
						scale=1;
						sourceScale=1;
						align="left";
						pos[]=
						{
							{0.88999999,0.94},
							1
						};
						right[]=
						{
							{0.92000002,0.94},
							1
						};
						down[]=
						{
							{0.88999999,0.97000003},
							1
						};
					};
					class Waterline
					{
						type="text";
						source="static";
						text="-W-";
						scale=1;
						sourceScale=1;
						align="left";
						pos[]=
						{
							{0.079999998,0.69},
							1
						};
						right[]=
						{
							{0.11,0.69},
							1
						};
						down[]=
						{
							{0.079999998,0.72000003},
							1
						};
					};
				};
			};
			class MFD_Left_Engine
			{
				topLeft="MFD_6_TL";
				topRight="MFD_6_TR";
				bottomLeft="MFD_6_BL";
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
				turret[]={-2};
				class material
				{
					ambient[]={5,5,5,1};
					diffuse[]={5,5,5,1};
					emissive[]={400,200,200,1};
				};
				class Bones
				{
					class HUDCenter
					{
						type="fixed";
						pos[]={0.5,0.5};
					};
					class Torque
					{
						type="linear";
						source="rpm";
						sourceScale=10;
						min=35;
						max=160;
						minPos[]={0,0};
						maxPos[]={0,0.36500001};
					};
					class TurbineSpeed
					{
						type="linear";
						source="rpm";
						sourceScale=1;
						min=0;
						max=13;
						minPos[]={0,0};
						maxPos[]={0,0.38499999};
					};
					class RotorSpeed
					{
						type="linear";
						source="rpm";
						sourceScale=1;
						min=0;
						max=9.3999996;
						minPos[]={0,0.059999999};
						maxPos[]={0,0.25999999};
					};
					class RotorSpeed2: RotorSpeed
					{
						min=9.3999996;
						max=10;
						minPos[]={0,-0.059999999};
						maxPos[]={0,0};
					};
					class TGT_Temp
					{
						type="linear";
						source="rpm";
						sourceScale=65;
						min=0;
						max=810;
						minPos[]={0,0};
						maxPos[]={0,0.25999999};
					};
					class RTD_Torque_1
					{
						type="linear";
						source="rtdRpm1";
						sourceIndex=10;
						sourceScale=216;
						refreshRate=0.1;
						min=0;
						max=130;
						minPos[]={0,0};
						maxPos[]={0,0.27500001};
					};
					class RTD_Torque_2: RTD_Torque_1
					{
						source="rtdRpm2";
						sourceIndex=11;
					};
					class RTD_Torque_Level_1_1: RTD_Torque_1
					{
						max=30;
						maxPos[]={0,0.064999998};
					};
					class RTD_Torque_Level_1_2: RTD_Torque_2
					{
						max=30;
						maxPos[]={0,0.064999998};
					};
					class RTD_Torque_Level_1_Yellow_1: RTD_Torque_1
					{
						min=30;
						max=130;
						maxPos[]={0,0.27500001};
					};
					class RTD_Torque_Level_1_Yellow_2: RTD_Torque_2
					{
						min=30;
						max=130;
						maxPos[]={0,0.27500001};
					};
					class RTD_Torque_Level_2_1: RTD_Torque_1
					{
						max=70;
						maxPos[]={0,0.175};
					};
					class RTD_Torque_Level_2_2: RTD_Torque_2
					{
						max=70;
						maxPos[]={0,0.175};
					};
					class RTD_Torque_Level_2_Yellow_1: RTD_Torque_1
					{
						min=70;
						max=130;
						maxPos[]={0,0.175};
					};
					class RTD_Torque_Level_2_Yellow_2: RTD_Torque_2
					{
						min=70;
						max=130;
						maxPos[]={0,0.175};
					};
					class RTD_Torque_Level_3_1: RTD_Torque_1
					{
						max=100;
						maxPos[]={0,0.235};
					};
					class RTD_Torque_Level_3_2: RTD_Torque_2
					{
						max=100;
						maxPos[]={0,0.235};
					};
					class RTD_Torque_Level_3_Yellow_1: RTD_Torque_1
					{
						min=101;
						max=115;
						maxPos[]={0,0.059999999};
					};
					class RTD_Torque_Level_3_Yellow_2: RTD_Torque_2
					{
						min=101;
						max=115;
						maxPos[]={0,0.059999999};
					};
					class RTD_Torque_Level_3_Red_1: RTD_Torque_1
					{
						min=115;
						max=130;
						maxPos[]={0,0.055};
					};
					class RTD_Torque_Level_3_Red_2: RTD_Torque_2
					{
						min=115;
						max=130;
						maxPos[]={0,0.055};
					};
					class RTD_TurbineSpeed_1
					{
						type="linear";
						source="user";
						sourceIndex=13;
						sourceScale=1;
						min=0;
						max=105;
						minPos[]={0,0};
						maxPos[]={0,0.31999999};
					};
					class RTD_TurbineSpeed_2: RTD_TurbineSpeed_1
					{
						sourceIndex=14;
					};
					class RTD_TurbineSpeed_Yellow_1: RTD_TurbineSpeed_1
					{
						min=105;
						max=120;
						minPos[]={0,0};
						maxPos[]={0,0.075000003};
					};
					class RTD_TurbineSpeed_Yellow_2: RTD_TurbineSpeed_2
					{
						min=105;
						max=120;
						minPos[]={0,0};
						maxPos[]={0,0.075000003};
					};
					class RTD_RotorSpeed
					{
						type="linear";
						source="user";
						sourceIndex=12;
						min=0;
						max=94;
						minPos[]={0,0.059999999};
						maxPos[]={0,0.25999999};
					};
					class RTD_RotorSpeed2: RTD_RotorSpeed
					{
						min=94;
						max=100;
						minPos[]={0,-0.059999999};
						maxPos[]={0,0};
					};
				};
				class Draw
				{
					alpha=1;
					color[]={0,0.12,0};
					condition="on";
					class Static
					{
						type="line";
						width=4;
						points[]=
						{
							
							{
								{0.105,0.93000001},
								1
							},
							
							{
								{0.19499999,0.93000001},
								1
							},
							
							{
								{0.19499999,0.98000002},
								1
							},
							
							{
								{0.105,0.98000002},
								1
							},
							
							{
								{0.105,0.93000001},
								1
							},
							{},
							
							{
								{0.80000001,0.014},
								1
							},
							
							{
								{0.87,0.014},
								1
							},
							{},
							
							{
								{0.50999999,0.014},
								1
							},
							
							{
								{0.61000001,0.014},
								1
							},
							{},
							
							{
								{0.38,0.014},
								1
							},
							
							{
								{0.46000001,0.014},
								1
							},
							{},
							
							{
								{0.26499999,0.014},
								1
							},
							
							{
								{0.33000001,0.014},
								1
							},
							{}
						};
					};
					class Polygons
					{
						type="polygon";
						width=4;
						points[]=
						{
							
							{
								
								{
									{0.87,0.0068000001},
									1
								},
								
								{
									{0.88999999,0.014},
									1
								},
								
								{
									{0.87,0.021199999},
									1
								}
							},
							
							{
								
								{
									{0.58999997,0.0068000001},
									1
								},
								
								{
									{0.61000001,0.014},
									1
								},
								
								{
									{0.58999997,0.021199999},
									1
								}
							},
							
							{
								
								{
									{0.46000001,0.0068000001},
									1
								},
								
								{
									{0.47999999,0.014},
									1
								},
								
								{
									{0.46000001,0.021199999},
									1
								}
							},
							
							{
								
								{
									{0.31999999,0.0068000001},
									1
								},
								
								{
									{0.34,0.014},
									1
								},
								
								{
									{0.31999999,0.021199999},
									1
								}
							}
						};
					};
					class GroundMode
					{
						condition="(altitudeAGL<=6)";
						class Static
						{
							type="line";
							width=4;
							points[]=
							{
								
								{
									{0.1462,0.64200002},
									1
								},
								
								{
									{0.1416,0.65549999},
									1
								},
								
								{
									{0.13699999,0.66900003},
									1
								},
								
								{
									{0.13699999,0.83099997},
									1
								},
								
								{
									{0.1416,0.84450001},
									1
								},
								
								{
									{0.1462,0.85799998},
									1
								},
								
								{
									{0.3854,0.85799998},
									1
								},
								
								{
									{0.38999999,0.84450001},
									1
								},
								
								{
									{0.3946,0.83099997},
									1
								},
								
								{
									{0.3946,0.66900003},
									1
								},
								
								{
									{0.38999999,0.65549999},
									1
								},
								
								{
									{0.3854,0.64200002},
									1
								},
								
								{
									{0.1462,0.64200002},
									1
								},
								{},
								
								{
									{0.43619999,0.64200002},
									1
								},
								
								{
									{0.4316,0.65549999},
									1
								},
								
								{
									{0.42699999,0.66900003},
									1
								},
								
								{
									{0.42699999,0.83099997},
									1
								},
								
								{
									{0.4316,0.84450001},
									1
								},
								
								{
									{0.43619999,0.85799998},
									1
								},
								
								{
									{0.67540002,0.85799998},
									1
								},
								
								{
									{0.68000001,0.84450001},
									1
								},
								
								{
									{0.6846,0.83099997},
									1
								},
								
								{
									{0.6846,0.66900003},
									1
								},
								
								{
									{0.68000001,0.65549999},
									1
								},
								
								{
									{0.67540002,0.64200002},
									1
								},
								
								{
									{0.43619999,0.64200002},
									1
								},
								{}
							};
						};
						class Engine
						{
							type="text";
							source="static";
							text="ENGINE";
							scale=1;
							sourceScale=1;
							align="center";
							pos[]=
							{
								
								{
									"0.3	-0.08",
									0.64999998
								},
								1
							};
							right[]=
							{
								{0.245,0.64999998},
								1
							};
							down[]=
							{
								
								{
									"0.3	-0.08",
									0.67500001
								},
								1
							};
						};
						class EngineOilPsi
						{
							type="text";
							source="static";
							text="OIL PSI";
							scale=1;
							sourceScale=1;
							align="center";
							pos[]=
							{
								
								{
									"0.33-0.08",
									0.69
								},
								1
							};
							right[]=
							{
								{0.27500001,0.69},
								1
							};
							down[]=
							{
								
								{
									"0.33-0.08",
									0.71499997
								},
								1
							};
						};
						class EngineOilPsi1
						{
							type="text";
							source="static";
							text="1";
							scale=1;
							sourceScale=1;
							align="center";
							pos[]=
							{
								
								{
									"0.3	-0.08",
									0.81999999
								},
								1
							};
							right[]=
							{
								{0.245,0.81999999},
								1
							};
							down[]=
							{
								
								{
									"0.3	-0.08",
									0.84500003
								},
								1
							};
						};
						class EngineOilPsi2
						{
							type="text";
							source="static";
							text="2";
							scale=1;
							sourceScale=1;
							align="center";
							pos[]=
							{
								
								{
									"0.4	-0.08",
									0.81999999
								},
								1
							};
							right[]=
							{
								{0.345,0.81999999},
								1
							};
							down[]=
							{
								
								{
									"0.4	-0.08",
									0.84500003
								},
								1
							};
						};
						class HydPressure
						{
							type="text";
							source="static";
							text="HYD PSI";
							scale=1;
							sourceScale=1;
							align="center";
							pos[]=
							{
								
								{
									"0.57	-0.06",
									0.64999998
								},
								1
							};
							right[]=
							{
								{0.53500003,0.64999998},
								1
							};
							down[]=
							{
								
								{
									"0.57	-0.06",
									0.67500001
								},
								1
							};
						};
						class HydPressurePrimary
						{
							type="text";
							source="static";
							text="PRI";
							scale=1;
							sourceScale=1;
							align="right";
							pos[]=
							{
								
								{
									"0.52	-0.06",
									0.70499998
								},
								1
							};
							right[]=
							{
								{0.48500001,0.70499998},
								1
							};
							down[]=
							{
								
								{
									"0.52	-0.06",
									0.73000002
								},
								1
							};
						};
						class HydPressureUtility
						{
							type="text";
							source="static";
							text="UTIL";
							scale=1;
							sourceScale=1;
							align="right";
							pos[]=
							{
								
								{
									"0.52	-0.06",
									0.75999999
								},
								1
							};
							right[]=
							{
								{0.48500001,0.75999999},
								1
							};
							down[]=
							{
								
								{
									"0.52	-0.06",
									0.78500003
								},
								1
							};
						};
						class HydPressureAccumulator
						{
							type="text";
							source="static";
							text="ACC";
							scale=1;
							sourceScale=1;
							align="right";
							pos[]=
							{
								
								{
									"0.52	-0.06",
									0.815
								},
								1
							};
							right[]=
							{
								{0.48500001,0.815},
								1
							};
							down[]=
							{
								
								{
									"0.52	-0.06",
									0.83999997
								},
								1
							};
						};
						class HydPressureUtilityVal
						{
							type="text";
							source="static";
							text="3000";
							scale=1;
							sourceScale=1;
							align="right";
							pos[]=
							{
								
								{
									"0.62	-0.06",
									0.75999999
								},
								1
							};
							right[]=
							{
								{0.58499998,0.75999999},
								1
							};
							down[]=
							{
								
								{
									"0.62	-0.06",
									0.78500003
								},
								1
							};
						};
						class HydPressureAccumulatorVal
						{
							type="text";
							source="static";
							text="3000";
							scale=1;
							sourceScale=1;
							align="right";
							pos[]=
							{
								
								{
									"0.62	-0.06",
									0.815
								},
								1
							};
							right[]=
							{
								{0.58499998,0.815},
								1
							};
							down[]=
							{
								
								{
									"0.62	-0.06",
									0.83999997
								},
								1
							};
						};
						class Green
						{
							condition="rpm>=2.5";
							class EngineOilPsiValue1
							{
								type="text";
								source="rpm";
								sourceScale=8.8000002;
								sourceLength=1;
								refreshRate=0.13;
								align="center";
								scale=1;
								pos[]=
								{
									
									{
										"0.3	-0.08",
										0.77499998
									},
									1
								};
								right[]=
								{
									{0.245,0.77499998},
									1
								};
								down[]=
								{
									
									{
										"0.3	-0.08",
										0.80000001
									},
									1
								};
							};
							class EngineOilPsiValue2: EngineOilPsiValue1
							{
								pos[]=
								{
									
									{
										"0.4	-0.08",
										0.77499998
									},
									1
								};
								right[]=
								{
									{0.345,0.77499998},
									1
								};
								down[]=
								{
									
									{
										"0.4	-0.08",
										0.80000001
									},
									1
								};
								sourceScale=9;
								refreshRate=0.1;
							};
						};
						class Red: Green
						{
							condition="rpm<=2.5";
							color[]={1,0,0};
							alpha=0.30000001;
							class EngineOilPsiValue1: EngineOilPsiValue1
							{
							};
							class EngineOilPsiValue2: EngineOilPsiValue2
							{
							};
						};
						class Hydraulics_OK
						{
							condition="user15>=1300";
							class HydPressurePrimaryVal
							{
								type="text";
								source="user";
								sourceIndex=15;
								scale=1;
								sourceScale=1;
								align="right";
								pos[]=
								{
									{0.56,0.70499998},
									1
								};
								right[]=
								{
									{0.58499998,0.70499998},
									1
								};
								down[]=
								{
									{0.56,0.73000002},
									1
								};
							};
						};
						class Hydraulics_Low
						{
							condition="user15<=1300";
							color[]={1,0,0};
							class HydPressurePrimaryVal
							{
								type="text";
								source="user";
								sourceIndex=15;
								scale=1;
								sourceScale=1;
								align="right";
								pos[]=
								{
									{0.56,0.70499998},
									1
								};
								right[]=
								{
									{0.58499998,0.70499998},
									1
								};
								down[]=
								{
									{0.56,0.73000002},
									1
								};
							};
						};
					};
					class AirMode
					{
						condition="(altitudeAGL>=6)";
						class Static
						{
							type="line";
							width=4;
							points[]=
							{
								
								{
									{0.039000198,0.60399997},
									1
								},
								
								{
									{0.0220001,0.62099999},
									1
								},
								
								{
									{0.0050001098,0.63800001},
									1
								},
								
								{
									{0.0050001098,0.84200001},
									1
								},
								
								{
									{0.0220001,0.85900003},
									1
								},
								
								{
									{0.039000198,0.87599999},
									1
								},
								
								{
									{0.92299998,0.87599999},
									1
								},
								
								{
									{0.94,0.85900003},
									1
								},
								
								{
									{0.95700002,0.84200001},
									1
								},
								
								{
									{0.95700002,0.63800001},
									1
								},
								
								{
									{0.94,0.62099999},
									1
								},
								
								{
									{0.92299998,0.60399997},
									1
								},
								
								{
									{0.039000198,0.60399997},
									1
								},
								{},
								
								{
									{0.73619998,0.122},
									1
								},
								
								{
									{0.73159999,0.1355},
									1
								},
								
								{
									{0.727,0.149},
									1
								},
								
								{
									{0.727,0.31099999},
									1
								},
								
								{
									{0.73159999,0.32449999},
									1
								},
								
								{
									{0.73619998,0.338},
									1
								},
								
								{
									{0.97539997,0.338},
									1
								},
								
								{
									{0.98000002,0.32449999},
									1
								},
								
								{
									{0.98460001,0.31099999},
									1
								},
								
								{
									{0.98460001,0.149},
									1
								},
								
								{
									{0.98000002,0.1355},
									1
								},
								
								{
									{0.97539997,0.122},
									1
								},
								
								{
									{0.73619998,0.122},
									1
								},
								{},
								
								{
									{0.505,0.62},
									1
								},
								
								{
									{0.505,0.86000001},
									1
								},
								{},
								
								{
									{0.495,0.62},
									1
								},
								
								{
									{0.495,0.86000001},
									1
								},
								{}
							};
						};
						class HydPressure
						{
							type="text";
							source="static";
							text="HYD PSI";
							scale=1;
							sourceScale=1;
							align="center";
							pos[]=
							{
								
								{
									"0.57	-0.06+0.3",
									0.13
								},
								1
							};
							right[]=
							{
								{0.83499998,0.13},
								1
							};
							down[]=
							{
								
								{
									"0.57	-0.06+0.3",
									0.155
								},
								1
							};
						};
						class HydPressurePrimary
						{
							type="text";
							source="static";
							text="PRI";
							scale=1;
							sourceScale=1;
							align="right";
							pos[]=
							{
								
								{
									"0.52	-0.06+0.3",
									0.185
								},
								1
							};
							right[]=
							{
								{0.78500003,0.185},
								1
							};
							down[]=
							{
								
								{
									"0.52	-0.06+0.3",
									0.20999999
								},
								1
							};
						};
						class HydPressureUtility
						{
							type="text";
							source="static";
							text="UTIL";
							scale=1;
							sourceScale=1;
							align="right";
							pos[]=
							{
								
								{
									"0.52	-0.06+0.3",
									0.23999999
								},
								1
							};
							right[]=
							{
								{0.78500003,0.23999999},
								1
							};
							down[]=
							{
								
								{
									"0.52	-0.06+0.3",
									0.26499999
								},
								1
							};
						};
						class HydPressureAccumulator
						{
							type="text";
							source="static";
							text="ACC";
							scale=1;
							sourceScale=1;
							align="right";
							pos[]=
							{
								
								{
									"0.52	-0.06+0.3",
									0.29499999
								},
								1
							};
							right[]=
							{
								{0.78500003,0.29499999},
								1
							};
							down[]=
							{
								
								{
									"0.52	-0.06+0.3",
									0.31999999
								},
								1
							};
						};
						class HydPressureUtilityVal
						{
							type="text";
							source="static";
							text="3000";
							scale=1;
							sourceScale=1;
							align="right";
							pos[]=
							{
								
								{
									"0.62	-0.06+0.3",
									0.23999999
								},
								1
							};
							right[]=
							{
								{0.88499999,0.23999999},
								1
							};
							down[]=
							{
								
								{
									"0.62	-0.06+0.3",
									0.26499999
								},
								1
							};
						};
						class HydPressureAccumulatorVal
						{
							type="text";
							source="static";
							text="3000";
							scale=1;
							sourceScale=1;
							align="right";
							pos[]=
							{
								
								{
									"0.62	-0.06+0.3",
									0.29499999
								},
								1
							};
							right[]=
							{
								{0.88499999,0.29499999},
								1
							};
							down[]=
							{
								
								{
									"0.62	-0.06+0.3",
									0.31999999
								},
								1
							};
						};
						class Hydraulics_OK
						{
							condition="user15>=1300";
							class HydPressurePrimaryVal
							{
								type="text";
								source="user";
								sourceIndex=15;
								scale=1;
								sourceScale=1;
								align="right";
								pos[]=
								{
									{0.86000001,0.185},
									1
								};
								right[]=
								{
									{0.88499999,0.185},
									1
								};
								down[]=
								{
									{0.86000001,0.20999999},
									1
								};
							};
						};
						class Hydraulics_Low
						{
							condition="user15<=1300";
							color[]={1,0,0};
							class HydPressurePrimaryVal
							{
								type="text";
								source="user";
								sourceIndex=15;
								scale=1;
								sourceScale=1;
								align="right";
								pos[]=
								{
									{0.86000001,0.185},
									1
								};
								right[]=
								{
									{0.88499999,0.185},
									1
								};
								down[]=
								{
									{0.86000001,0.20999999},
									1
								};
							};
						};
					};
					class Flight
					{
						type="text";
						source="static";
						text="FLT";
						scale=1;
						sourceScale=1;
						align="left";
						pos[]=
						{
							{0.34,0.029999999},
							1
						};
						right[]=
						{
							{0.37,0.029999999},
							1
						};
						down[]=
						{
							{0.34,0.059999999},
							1
						};
					};
					class Fuel
					{
						type="text";
						source="static";
						text="FUEL";
						scale=1;
						sourceScale=1;
						align="left";
						pos[]=
						{
							{0.47999999,0.029999999},
							1
						};
						right[]=
						{
							{0.50999999,0.029999999},
							1
						};
						down[]=
						{
							{0.47999999,0.059999999},
							1
						};
					};
					class Performance
					{
						type="text";
						source="static";
						text="PERF";
						scale=1;
						sourceScale=1;
						align="left";
						pos[]=
						{
							{0.61000001,0.029999999},
							1
						};
						right[]=
						{
							{0.63999999,0.029999999},
							1
						};
						down[]=
						{
							{0.61000001,0.059999999},
							1
						};
					};
					class Utilities
					{
						type="text";
						source="static";
						text="UTIL";
						scale=1;
						sourceScale=1;
						align="left";
						pos[]=
						{
							{0.88999999,0.029999999},
							1
						};
						right[]=
						{
							{0.92000002,0.029999999},
							1
						};
						down[]=
						{
							{0.88999999,0.059999999},
							1
						};
					};
					class Torque
					{
						type="text";
						source="static";
						text="TORQUE %";
						scale=1;
						sourceScale=1;
						align="right";
						pos[]=
						{
							{0.015,0.11},
							1
						};
						right[]=
						{
							{0.039999999,0.11},
							1
						};
						down[]=
						{
							{0.015,0.13500001},
							1
						};
					};
					class TGT
					{
						type="text";
						source="static";
						text="TGT   C";
						scale=1;
						sourceScale=1;
						align="right";
						pos[]=
						{
							
							{
								"0.23+0.03",
								0.11
							},
							1
						};
						right[]=
						{
							{0.285,0.11},
							1
						};
						down[]=
						{
							
							{
								"0.23+0.03",
								0.13500001
							},
							1
						};
					};
					class TGT_o
					{
						type="text";
						source="static";
						text="o";
						scale=1;
						sourceScale=1;
						align="right";
						pos[]=
						{
							
							{
								"0.305+0.03",
								0.105
							},
							1
						};
						right[]=
						{
							{0.352,0.105},
							1
						};
						down[]=
						{
							
							{
								"0.305+0.03",
								0.122
							},
							1
						};
					};
					class EngPowerTurbineSpeed_1
					{
						type="text";
						source="static";
						text="N   %";
						scale=1;
						sourceScale=1;
						align="right";
						pos[]=
						{
							{0.43000001,0.11},
							1
						};
						right[]=
						{
							{0.45500001,0.11},
							1
						};
						down[]=
						{
							{0.43000001,0.13500001},
							1
						};
					};
					class EngPowerTurbineSpeed_1P
					{
						type="text";
						source="static";
						text="P";
						scale=1;
						sourceScale=1;
						align="right";
						pos[]=
						{
							
							{
								"0.43+0.025",
								0.115
							},
							1
						};
						right[]=
						{
							{0.47999999,0.115},
							1
						};
						down[]=
						{
							
							{
								"0.43+0.025",
								0.14
							},
							1
						};
					};
					class RotorSpeed
					{
						type="text";
						source="static";
						text="N   %";
						scale=1;
						sourceScale=1;
						align="right";
						pos[]=
						{
							{0.53500003,0.11},
							1
						};
						right[]=
						{
							{0.56,0.11},
							1
						};
						down[]=
						{
							{0.53500003,0.13500001},
							1
						};
					};
					class RotorSpeedR
					{
						type="text";
						source="static";
						text="R";
						scale=1;
						sourceScale=1;
						align="right";
						pos[]=
						{
							
							{
								"0.535+0.025",
								0.115
							},
							1
						};
						right[]=
						{
							{0.58499998,0.115},
							1
						};
						down[]=
						{
							
							{
								"0.535+0.025",
								0.14
							},
							1
						};
					};
					class EngPowerTurbineSpeed_2
					{
						type="text";
						source="static";
						text="N   %";
						scale=1;
						sourceScale=1;
						align="right";
						pos[]=
						{
							{0.63999999,0.11},
							1
						};
						right[]=
						{
							{0.66500002,0.11},
							1
						};
						down[]=
						{
							{0.63999999,0.13500001},
							1
						};
					};
					class EngPowerTurbineSpeed_2P
					{
						type="text";
						source="static";
						text="P";
						scale=1;
						sourceScale=1;
						align="right";
						pos[]=
						{
							
							{
								"0.64+0.025",
								0.115
							},
							1
						};
						right[]=
						{
							{0.69,0.115},
							1
						};
						down[]=
						{
							
							{
								"0.64+0.025",
								0.14
							},
							1
						};
					};
					class EngPowerTurbineSpeed_Percent_2
					{
						type="text";
						source="static";
						text="N   %";
						scale=1;
						sourceScale=1;
						align="right";
						pos[]=
						{
							{0.82999998,0.36000001},
							1
						};
						right[]=
						{
							{0.85500002,0.36000001},
							1
						};
						down[]=
						{
							{0.82999998,0.38499999},
							1
						};
					};
					class EngPowerTurbineSpeed_Percent_2P
					{
						type="text";
						source="static";
						text="P";
						scale=1;
						sourceScale=1;
						align="right";
						pos[]=
						{
							
							{
								"0.83+0.025",
								0.36500001
							},
							1
						};
						right[]=
						{
							{0.88,0.36500001},
							1
						};
						down[]=
						{
							
							{
								"0.83+0.025",
								0.38999999
							},
							1
						};
					};
					class EngGasGeneratorSpeed_Percent_2
					{
						type="text";
						source="static";
						text="N   %";
						scale=1;
						sourceScale=1;
						align="right";
						pos[]=
						{
							{0.82999998,0.46000001},
							1
						};
						right[]=
						{
							{0.85500002,0.46000001},
							1
						};
						down[]=
						{
							{0.82999998,0.48500001},
							1
						};
					};
					class EngGasGeneratorSpeed_Percent_2P
					{
						type="text";
						source="static";
						text="G";
						scale=1;
						sourceScale=1;
						align="right";
						pos[]=
						{
							
							{
								"0.83+0.025",
								0.465
							},
							1
						};
						right[]=
						{
							{0.88,0.465},
							1
						};
						down[]=
						{
							
							{
								"0.83+0.025",
								0.49000001
							},
							1
						};
					};
					class StarterGroup
					{
						condition="(rpm<=4.6)* (6-altitudeAGL)";
						class White
						{
							color[]={1,1,1};
							class StarterOn
							{
								type="text";
								source="static";
								text="ON";
								scale=1;
								sourceScale=1;
								align="center";
								pos[]=
								{
									
									{
										"0.14+0.79",
										0.60000002
									},
									1
								};
								right[]=
								{
									{0.95499998,0.60000002},
									1
								};
								down[]=
								{
									
									{
										"0.14+0.79",
										0.625
									},
									1
								};
							};
						};
						class Starter
						{
							type="text";
							source="static";
							text="START";
							scale=1;
							sourceScale=1;
							align="center";
							pos[]=
							{
								{0.86000001,0.64999998},
								1
							};
							right[]=
							{
								{0.88499999,0.64999998},
								1
							};
							down[]=
							{
								{0.86000001,0.67500001},
								1
							};
						};
						class Static
						{
							type="line";
							width=4;
							points[]=
							{
								
								{
									{0.73619998,0.44999999},
									1
								},
								
								{
									{0.73159999,0.465},
									1
								},
								
								{
									{0.727,0.47999999},
									1
								},
								
								{
									{0.727,0.66000003},
									1
								},
								
								{
									{0.73159999,0.67500001},
									1
								},
								
								{
									{0.73619998,0.69},
									1
								},
								
								{
									{0.97539997,0.69},
									1
								},
								
								{
									{0.98000002,0.67500001},
									1
								},
								
								{
									{0.98460001,0.66000003},
									1
								},
								
								{
									{0.98460001,0.47999999},
									1
								},
								
								{
									{0.98000002,0.465},
									1
								},
								
								{
									{0.97539997,0.44999999},
									1
								},
								
								{
									{0.73619998,0.44999999},
									1
								},
								{}
							};
						};
					};
					class StandardFlightModel
					{
						condition="simulArma";
						class TorqueLevel_0
						{
							condition="rpm<=3.5";
							class TorqueEng1
							{
								type="text";
								source="static";
								text="0";
								scale=1;
								sourceScale=1;
								align="center";
								pos[]=
								{
									{0.039999999,0.465},
									1
								};
								right[]=
								{
									{0.064999998,0.465},
									1
								};
								down[]=
								{
									{0.039999999,0.49000001},
									1
								};
							};
							class TorqueEng2
							{
								type="text";
								source="static";
								text="0";
								scale=1;
								sourceScale=1;
								align="center";
								pos[]=
								{
									{0.14,0.465},
									1
								};
								right[]=
								{
									{0.16500001,0.465},
									1
								};
								down[]=
								{
									{0.14,0.49000001},
									1
								};
							};
							class Red
							{
								color[]={1,0,0};
								alpha=1;
								class DrawLines
								{
									type="line";
									width=6;
									points[]=
									{
										
										{
											{0.0049999999,0.43000001},
											1
										},
										
										{
											{0.185,0.43000001},
											1
										},
										{}
									};
								};
								class DrawPolygons
								{
									type="polygon";
									points[]=
									{
										
										{
											
											{
												{0.085000001,0.43000001},
												1
											},
											
											{
												{0.094999999,0.44},
												1
											},
											
											{
												{0.105,0.43000001},
												1
											},
											
											{
												{0.094999999,0.41999999},
												1
											}
										}
									};
								};
							};
						};
						class TorqueLevel_1: TorqueLevel_0
						{
							condition="(rpm<=5)*(rpm>=3.5)";
							class Torque_Eng1
							{
								type="text";
								source="rpm";
								sourceScale=12.1;
								sourceOffset=-35;
								sourceLength=1;
								refreshRate=0.13;
								align="center";
								scale=1;
								pos[]=
								{
									{0.039999999,0.465},
									1
								};
								right[]=
								{
									{0.064999998,0.465},
									1
								};
								down[]=
								{
									{0.039999999,0.49000001},
									1
								};
							};
							class Torque_Eng2: Torque_Eng1
							{
								pos[]=
								{
									{0.14,0.465},
									1
								};
								right[]=
								{
									{0.16500001,0.465},
									1
								};
								down[]=
								{
									{0.14,0.49000001},
									1
								};
								source="rpm";
								sourceScale=12.4;
								refreshRate=0.1;
							};
							class Red: Red
							{
								class DrawLines: DrawLines
								{
								};
								class DrawPolygons: DrawPolygons
								{
								};
							};
						};
						class TorqueLevel_2: TorqueLevel_1
						{
							condition="(rpm>=5)*(rpm<=9)";
							class Torque_Eng1: Torque_Eng1
							{
								pos[]=
								{
									{0.039999999,0.315},
									1
								};
								right[]=
								{
									{0.064999998,0.315},
									1
								};
								down[]=
								{
									{0.039999999,0.34},
									1
								};
							};
							class Torque_Eng2: Torque_Eng2
							{
								pos[]=
								{
									{0.14,0.315},
									1
								};
								right[]=
								{
									{0.16500001,0.315},
									1
								};
								down[]=
								{
									{0.14,0.34},
									1
								};
							};
							class Red: Red
							{
								class DrawLines: DrawLines
								{
									points[]=
									{
										
										{
											{0.0049999999,0.28},
											1
										},
										
										{
											{0.185,0.28},
											1
										},
										{}
									};
								};
								class DrawPolygons: DrawPolygons
								{
									points[]=
									{
										
										{
											
											{
												{0.085000001,0.28},
												1
											},
											
											{
												{0.094999999,0.28999999},
												1
											},
											
											{
												{0.105,0.28},
												1
											},
											
											{
												{0.094999999,0.27000001},
												1
											}
										}
									};
								};
							};
						};
						class TorqueLevel_3: TorqueLevel_1
						{
							condition="rpm>=9";
							class Torque_Eng1: Torque_Eng1
							{
								pos[]=
								{
									{0.039999999,0.25},
									1
								};
								right[]=
								{
									{0.064999998,0.25},
									1
								};
								down[]=
								{
									{0.039999999,0.27500001},
									1
								};
							};
							class Torque_Eng2: Torque_Eng2
							{
								pos[]=
								{
									{0.14,0.25},
									1
								};
								right[]=
								{
									{0.16500001,0.25},
									1
								};
								down[]=
								{
									{0.14,0.27500001},
									1
								};
							};
							class Red: Red
							{
								class DrawLines: DrawLines
								{
									points[]=
									{
										
										{
											{0.0049999999,0.2},
											1
										},
										
										{
											{0.185,0.2},
											1
										},
										{}
									};
								};
								class DrawPolygons: DrawPolygons
								{
									points[]=
									{
										
										{
											
											{
												{0.085000001,0.2},
												1
											},
											
											{
												{0.094999999,0.20999999},
												1
											},
											
											{
												{0.105,0.2},
												1
											},
											
											{
												{0.094999999,0.19},
												1
											}
										}
									};
								};
							};
						};
						class RPM_Eng1
						{
							type="text";
							source="rpm";
							sourceScale=10.1;
							sourceLength=1;
							refreshRate=0.13;
							align="center";
							scale=1;
							pos[]=
							{
								
								{
									"0.04+0.76",
									0.405
								},
								1
							};
							right[]=
							{
								{0.82499999,0.405},
								1
							};
							down[]=
							{
								
								{
									"0.04+0.76",
									0.43000001
								},
								1
							};
						};
						class RPM_Eng2: RPM_Eng1
						{
							pos[]=
							{
								
								{
									"0.14+0.78",
									0.405
								},
								1
							};
							right[]=
							{
								{0.94499999,0.405},
								1
							};
							down[]=
							{
								
								{
									"0.14+0.78",
									0.43000001
								},
								1
							};
							source="rpm";
							sourceScale=10.4;
							refreshRate=0.1;
						};
						class TGT_Eng1
						{
							type="text";
							source="rpm";
							sourceScale=71.900002;
							refreshRate=0.13;
							align="center";
							scale=1;
							pos[]=
							{
								
								{
									"0.04+0.23",
									0.255
								},
								1
							};
							right[]=
							{
								{0.29499999,0.255},
								1
							};
							down[]=
							{
								
								{
									"0.04+0.23",
									0.28
								},
								1
							};
						};
						class TGT_Eng2: TGT_Eng1
						{
							pos[]=
							{
								
								{
									"0.14+0.23",
									0.255
								},
								1
							};
							right[]=
							{
								{0.39500001,0.255},
								1
							};
							down[]=
							{
								
								{
									"0.14+0.23",
									0.28
								},
								1
							};
							sourceScale=71.800003;
							refreshRate=0.1;
						};
						class GasGen_Ok
						{
							condition="rpm>=6.3";
							class GasGen_Eng1
							{
								type="text";
								source="rpm";
								sourceScale=9.8999996;
								sourceLength=1;
								sourcePrecision=1;
								refreshRate=0.13;
								align="center";
								scale=1;
								pos[]=
								{
									
									{
										"0.04+0.76",
										0.505
									},
									1
								};
								right[]=
								{
									{0.82499999,0.505},
									1
								};
								down[]=
								{
									
									{
										"0.04+0.76",
										0.52999997
									},
									1
								};
							};
							class GasGen_Eng2: GasGen_Eng1
							{
								pos[]=
								{
									
									{
										"0.14+0.78",
										0.505
									},
									1
								};
								right[]=
								{
									{0.94499999,0.505},
									1
								};
								down[]=
								{
									
									{
										"0.14+0.78",
										0.52999997
									},
									1
								};
								sourceScale=9.8000002;
								refreshRate=0.1;
							};
						};
						class Red
						{
							color[]={1,0,0};
							alpha=0.1;
							class GasGen_Low
							{
								condition="rpm<=6.3";
								class GasGen_Eng1
								{
									type="text";
									source="rpm";
									sourceScale=9.8999996;
									sourceLength=1;
									sourcePrecision=1;
									refreshRate=0.13;
									align="center";
									scale=1;
									pos[]=
									{
										
										{
											"0.04+0.76",
											0.505
										},
										1
									};
									right[]=
									{
										{0.82499999,0.505},
										1
									};
									down[]=
									{
										
										{
											"0.04+0.76",
											0.52999997
										},
										1
									};
								};
								class GasGen_Eng2: GasGen_Eng1
								{
									pos[]=
									{
										
										{
											"0.14+0.78",
											0.505
										},
										1
									};
									right[]=
									{
										{0.94499999,0.505},
										1
									};
									down[]=
									{
										
										{
											"0.14+0.78",
											0.52999997
										},
										1
									};
									sourceScale=9.8000002;
									refreshRate=0.1;
								};
							};
						};
						class DrawTGT_Green
						{
							alpha=0.60000002;
							class DrawPolygon
							{
								type="polygon";
								points[]=
								{
									
									{
										
										{
											{0.029999999,0.55000001},
											1
										},
										
										{
											{0.050000001,0.55000001},
											1
										},
										
										{
											"Torque",
											1,
											{0.050000001,0.185},
											1
										},
										
										{
											"Torque",
											1,
											{0.029999999,0.185},
											1
										}
									},
									
									{
										
										{
											{0.13,0.55000001},
											1
										},
										
										{
											{0.15000001,0.55000001},
											1
										},
										
										{
											"Torque",
											1,
											{0.15000001,0.185},
											1
										},
										
										{
											"Torque",
											1,
											{0.13,0.185},
											1
										}
									},
									
									{
										
										{
											{0.25999999,0.55000001},
											1
										},
										
										{
											{0.28,0.55000001},
											1
										},
										
										{
											"TGT_Temp",
											1,
											{0.28,0.28999999},
											1
										},
										
										{
											"TGT_Temp",
											1,
											{0.25999999,0.28999999},
											1
										}
									},
									
									{
										
										{
											{0.36000001,0.55000001},
											1
										},
										
										{
											{0.38,0.55000001},
											1
										},
										
										{
											"TGT_Temp",
											1,
											{0.38,0.28999999},
											1
										},
										
										{
											"TGT_Temp",
											1,
											{0.36000001,0.28999999},
											1
										}
									},
									
									{
										
										{
											{0.44999999,0.55000001},
											1
										},
										
										{
											{0.47,0.55000001},
											1
										},
										
										{
											"TurbineSpeed",
											1,
											{0.47,0.16500001},
											1
										},
										
										{
											"TurbineSpeed",
											1,
											{0.44999999,0.16500001},
											1
										}
									},
									
									{
										
										{
											{0.66000003,0.55000001},
											1
										},
										
										{
											{0.68000001,0.55000001},
											1
										},
										
										{
											"TurbineSpeed",
											1,
											{0.68000001,0.175},
											1
										},
										
										{
											"TurbineSpeed",
											1,
											{0.66000003,0.175},
											1
										}
									}
								};
							};
						};
						class DrawRotor_Green
						{
							condition="rpm>=9.4";
							alpha=0.60000002;
							class DrawPolygon
							{
								type="polygon";
								points[]=
								{
									
									{
										
										{
											{0.52499998,0.55000001},
											1
										},
										
										{
											{0.61500001,0.55000001},
											1
										},
										
										{
											"RotorSpeed2",
											1,
											"RotorSpeed",
											1,
											{0.61500001,0.28999999},
											1
										},
										
										{
											"RotorSpeed2",
											1,
											"RotorSpeed",
											1,
											{0.52499998,0.28999999},
											1
										}
									}
								};
							};
							class RotorSpeed
							{
								type="text";
								source="rpm";
								sourceScale=9.8999996;
								sourceLength=1;
								sourcePrecision=0;
								refreshRate=0.13;
								align="center";
								scale=1;
								pos[]=
								{
									{0.56999999,0.255},
									1
								};
								right[]=
								{
									{0.59500003,0.255},
									1
								};
								down[]=
								{
									{0.56999999,0.28},
									1
								};
							};
						};
						class DrawRotor_Red: DrawRotor_Green
						{
							condition="rpm<=9.4";
							color[]={1,0,0};
							alpha=0.30000001;
							class DrawPolygon
							{
								type="polygon";
								points[]=
								{
									
									{
										
										{
											{0.52499998,0.55000001},
											1
										},
										
										{
											{0.61500001,0.55000001},
											1
										},
										
										{
											"RotorSpeed2",
											1,
											"RotorSpeed",
											1,
											{0.61500001,0.28999999},
											1
										},
										
										{
											"RotorSpeed2",
											1,
											"RotorSpeed",
											1,
											{0.52499998,0.28999999},
											1
										}
									}
								};
							};
							class RotorSpeed: RotorSpeed
							{
							};
						};
						class DrawTGT_Yellow
						{
							color[]={1,0.30000001,0};
							class DrawPolygon
							{
								type="polygon";
								points[]={};
							};
						};
					};
					class AdvancedFlightModel: StandardFlightModel
					{
						condition="simulRTD";
						class TorqueLevel_1
						{
							condition="(user12<=50)";
							class Red
							{
								color[]={1,0,0};
								class DrawLines
								{
									type="line";
									width=4;
									points[]=
									{
										
										{
											{0.0049999999,0.43000001},
											1
										},
										
										{
											{0.185,0.43000001},
											1
										},
										{}
									};
								};
								class DrawPolygons
								{
									type="polygon";
									points[]=
									{
										
										{
											
											{
												{0.085000001,0.43000001},
												1
											},
											
											{
												{0.094999999,0.44},
												1
											},
											
											{
												{0.105,0.43000001},
												1
											},
											
											{
												{0.094999999,0.41999999},
												1
											}
										}
									};
								};
							};
							class Nominal_L
							{
								condition="(rtdRpm1*216)<=30";
								class Torque_Eng1
								{
									type="text";
									source="rtdRpm1";
									sourceScale=216;
									sourceIndex=10;
									sourceLength=1;
									refreshRate=0.13;
									align="center";
									scale=1;
									pos[]=
									{
										{0.039999999,0.44499999},
										1
									};
									right[]=
									{
										{0.064999998,0.44499999},
										1
									};
									down[]=
									{
										{0.039999999,0.47},
										1
									};
								};
								class DrawPolygons
								{
									type="polygon";
									points[]=
									{
										
										{
											
											{
												{0.029999999,0.55000001},
												1
											},
											
											{
												{0.050000001,0.55000001},
												1
											},
											
											{
												"RTD_Torque_Level_1_1",
												1,
												{0.050000001,0.48500001},
												1
											},
											
											{
												"RTD_Torque_Level_1_1",
												1,
												{0.029999999,0.48500001},
												1
											}
										}
									};
								};
							};
							class Nominal_R: Nominal_L
							{
								condition="(rtdRpm2*216)<=30";
								class Torque_Eng2: Torque_Eng1
								{
									pos[]=
									{
										{0.14,0.44499999},
										1
									};
									right[]=
									{
										{0.16500001,0.44499999},
										1
									};
									down[]=
									{
										{0.14,0.47},
										1
									};
									source="rtdRpm2";
									sourceScale=216;
									sourceIndex=11;
									refreshRate=0.1;
								};
								class DrawPolygons: DrawPolygons
								{
									points[]=
									{
										
										{
											
											{
												{0.13,0.55000001},
												1
											},
											
											{
												{0.15000001,0.55000001},
												1
											},
											
											{
												"RTD_Torque_Level_1_2",
												1,
												{0.15000001,0.48500001},
												1
											},
											
											{
												"RTD_Torque_Level_1_2",
												1,
												{0.13,0.48500001},
												1
											}
										}
									};
								};
							};
							class Overtorque_L: Nominal_L
							{
								condition="(rtdRpm1*216)>=30";
								color[]={1,0,0};
								class Torque_Eng1: Torque_Eng1
								{
								};
								class DrawPolygons: DrawPolygons
								{
									points[]=
									{
										
										{
											
											{
												{0.029999999,0.55000001},
												1
											},
											
											{
												{0.050000001,0.55000001},
												1
											},
											
											{
												"RTD_Torque_Level_1_1",
												1,
												{0.050000001,0.48500001},
												1
											},
											
											{
												"RTD_Torque_Level_1_1",
												1,
												{0.029999999,0.48500001},
												1
											}
										},
										
										{
											
											{
												{0.02,0.43000001},
												1
											},
											
											{
												{0.059999999,0.43000001},
												1
											},
											
											{
												"RTD_Torque_Level_1_Yellow_1",
												1,
												{0.059999999,0.155},
												1
											},
											
											{
												"RTD_Torque_Level_1_Yellow_1",
												1,
												{0.02,0.155},
												1
											}
										}
									};
								};
							};
							class Overtorque_R: Nominal_R
							{
								condition="(rtdRpm2*216)>=30";
								color[]={1,0,0};
								class Torque_Eng2: Torque_Eng2
								{
								};
								class DrawPolygons: DrawPolygons
								{
									points[]=
									{
										
										{
											
											{
												{0.13,0.55000001},
												1
											},
											
											{
												{0.15000001,0.55000001},
												1
											},
											
											{
												"RTD_Torque_Level_1_2",
												1,
												{0.15000001,0.48500001},
												1
											},
											
											{
												"RTD_Torque_Level_1_2",
												1,
												{0.13,0.48500001},
												1
											}
										},
										
										{
											
											{
												{0.12,0.43000001},
												1
											},
											
											{
												{0.16,0.43000001},
												1
											},
											
											{
												"RTD_Torque_Level_1_Yellow_2",
												1,
												{0.16,0.155},
												1
											},
											
											{
												"RTD_Torque_Level_1_Yellow_2",
												1,
												{0.12,0.155},
												1
											}
										}
									};
								};
							};
						};
						class RPM_Eng1: RPM_Eng1
						{
							source="user";
							sourceIndex=13;
							sourceScale=1;
						};
						class RPM_Eng2: RPM_Eng2
						{
							source="user";
							sourceIndex=14;
							sourceScale=1;
						};
						class TGT_Eng1: TGT_Eng1
						{
						};
						class TGT_Eng2: TGT_Eng2
						{
						};
						class GasGen_Ok: GasGen_Ok
						{
							condition="rpm>=6.3";
							class GasGen_Eng1: GasGen_Eng1
							{
								type="text";
								source="rpm";
								sourceScale=9.8999996;
								sourceLength=1;
								sourcePrecision=1;
								refreshRate=0.13;
							};
							class GasGen_Eng2: GasGen_Eng1
							{
								pos[]=
								{
									
									{
										"0.14+0.78",
										0.505
									},
									1
								};
								right[]=
								{
									{0.94499999,0.505},
									1
								};
								down[]=
								{
									
									{
										"0.14+0.78",
										0.52999997
									},
									1
								};
								sourceScale=9.8000002;
								refreshRate=0.1;
							};
						};
						class Red: Red
						{
							class GasGen_Low: GasGen_Low
							{
								condition="rpm<=6.3";
								class GasGen_Eng1: GasGen_Eng1
								{
									source="rpm";
									sourceScale=9.8999996;
									sourceLength=1;
									sourcePrecision=1;
									refreshRate=0.13;
								};
								class GasGen_Eng2: GasGen_Eng1
								{
									pos[]=
									{
										
										{
											"0.14+0.78",
											0.505
										},
										1
									};
									right[]=
									{
										{0.94499999,0.505},
										1
									};
									down[]=
									{
										
										{
											"0.14+0.78",
											0.52999997
										},
										1
									};
									sourceScale=9.8000002;
									refreshRate=0.1;
								};
							};
						};
						class DrawTGT_Green
						{
							alpha=0.60000002;
							class DrawPolygon
							{
								type="polygon";
								points[]=
								{
									
									{
										
										{
											{0.25999999,0.55000001},
											1
										},
										
										{
											{0.28,0.55000001},
											1
										},
										
										{
											"TGT_Temp",
											1,
											{0.28,0.28999999},
											1
										},
										
										{
											"TGT_Temp",
											1,
											{0.25999999,0.28999999},
											1
										}
									},
									
									{
										
										{
											{0.36000001,0.55000001},
											1
										},
										
										{
											{0.38,0.55000001},
											1
										},
										
										{
											"TGT_Temp",
											1,
											{0.38,0.28999999},
											1
										},
										
										{
											"TGT_Temp",
											1,
											{0.36000001,0.28999999},
											1
										}
									}
								};
							};
						};
						class DrawEngineP_1_Green
						{
							condition="user13<=105";
							class DrawPolygon
							{
								type="polygon";
								points[]=
								{
									
									{
										
										{
											{0.44999999,0.55000001},
											1
										},
										
										{
											{0.47,0.55000001},
											1
										},
										
										{
											"RTD_TurbineSpeed_1",
											1,
											{0.47,0.23},
											1
										},
										
										{
											"RTD_TurbineSpeed_1",
											1,
											{0.44999999,0.23},
											1
										}
									}
								};
							};
						};
						class DrawEngineP_2_Green
						{
							condition="user14<=105";
							class DrawPolygon
							{
								type="polygon";
								points[]=
								{
									
									{
										
										{
											{0.66000003,0.55000001},
											1
										},
										
										{
											{0.68000001,0.55000001},
											1
										},
										
										{
											"RTD_TurbineSpeed_2",
											1,
											{0.68000001,0.23},
											1
										},
										
										{
											"RTD_TurbineSpeed_2",
											1,
											{0.66000003,0.23},
											1
										}
									}
								};
							};
						};
						class DrawEngineP_1_Yellow: DrawEngineP_1_Green
						{
							condition="user13>=105";
							color[]={1,0.30000001,0};
							class DrawPolygon: DrawPolygon
							{
								points[]=
								{
									
									{
										
										{
											{0.44999999,0.55000001},
											1
										},
										
										{
											{0.47,0.55000001},
											1
										},
										
										{
											"RTD_TurbineSpeed_1",
											1,
											{0.47,0.23},
											1
										},
										
										{
											"RTD_TurbineSpeed_1",
											1,
											{0.44999999,0.23},
											1
										}
									},
									
									{
										
										{
											{0.44,0.23},
											1
										},
										
										{
											{0.47999999,0.23},
											1
										},
										
										{
											"RTD_TurbineSpeed_Yellow_1",
											1,
											{0.47999999,0.155},
											1
										},
										
										{
											"RTD_TurbineSpeed_Yellow_1",
											1,
											{0.44,0.155},
											1
										}
									}
								};
							};
						};
						class DrawEngineP_2_Yellow: DrawEngineP_2_Green
						{
							condition="user14>=105";
							color[]={1,0.30000001,0};
							class DrawPolygon: DrawPolygon
							{
								points[]=
								{
									
									{
										
										{
											{0.66000003,0.55000001},
											1
										},
										
										{
											{0.68000001,0.55000001},
											1
										},
										
										{
											"RTD_TurbineSpeed_2",
											1,
											{0.68000001,0.23},
											1
										},
										
										{
											"RTD_TurbineSpeed_2",
											1,
											{0.66000003,0.23},
											1
										}
									},
									
									{
										
										{
											{0.64999998,0.23},
											1
										},
										
										{
											{0.69,0.23},
											1
										},
										
										{
											"RTD_TurbineSpeed_Yellow_2",
											1,
											{0.69,0.155},
											1
										},
										
										{
											"RTD_TurbineSpeed_Yellow_2",
											1,
											{0.64999998,0.155},
											1
										}
									}
								};
							};
						};
						class DrawRotor_Green
						{
							condition="user12>=94";
							alpha=0.60000002;
							class DrawPolygon
							{
								type="polygon";
								points[]=
								{
									
									{
										
										{
											{0.52499998,0.55000001},
											1
										},
										
										{
											{0.61500001,0.55000001},
											1
										},
										
										{
											"RTD_RotorSpeed2",
											1,
											"RTD_RotorSpeed",
											1,
											{0.61500001,0.28999999},
											1
										},
										
										{
											"RTD_RotorSpeed2",
											1,
											"RTD_RotorSpeed",
											1,
											{0.52499998,0.28999999},
											1
										}
									}
								};
							};
							class RotorSpeed
							{
								type="text";
								source="user";
								sourceIndex=12;
								sourceScale=1;
								sourceLength=1;
								sourcePrecision=0;
								refreshRate=0.13;
								align="center";
								scale=1;
								pos[]=
								{
									{0.56999999,0.255},
									1
								};
								right[]=
								{
									{0.59500003,0.255},
									1
								};
								down[]=
								{
									{0.56999999,0.28},
									1
								};
							};
						};
						class DrawRotor_Red: DrawRotor_Green
						{
							condition="user12<=94";
							color[]={1,0,0};
							alpha=0.30000001;
							class DrawPolygon
							{
								type="polygon";
								points[]=
								{
									
									{
										
										{
											{0.52499998,0.55000001},
											1
										},
										
										{
											{0.61500001,0.55000001},
											1
										},
										
										{
											"RTD_RotorSpeed2",
											1,
											"RTD_RotorSpeed",
											1,
											{0.61500001,0.28999999},
											1
										},
										
										{
											"RTD_RotorSpeed2",
											1,
											"RTD_RotorSpeed",
											1,
											{0.52499998,0.28999999},
											1
										}
									}
								};
							};
							class RotorSpeed: RotorSpeed
							{
							};
						};
					};
					class DrawBlackBackground
					{
						color[]={0,0,0};
						alpha=1;
						class DrawPolygon
						{
							type="polygon";
							points[]=
							{
								
								{
									
									{
										{0.52499998,0.51999998},
										1
									},
									
									{
										{0.52499998,0.55000001},
										1
									},
									
									{
										{0.56999999,0.55000001},
										1
									}
								},
								
								{
									
									{
										{0.61500001,0.51999998},
										1
									},
									
									{
										{0.61500001,0.55000001},
										1
									},
									
									{
										{0.56999999,0.55000001},
										1
									}
								},
								
								{
									
									{
										{0.52499998,0.28999999},
										1
									},
									
									{
										{0.55000001,0.28999999},
										1
									},
									
									{
										{0.55000001,0.34999999},
										1
									},
									
									{
										{0.52499998,0.33000001},
										1
									}
								},
								
								{
									
									{
										{0.61500001,0.28999999},
										1
									},
									
									{
										{0.58999997,0.28999999},
										1
									},
									
									{
										{0.58999997,0.34999999},
										1
									},
									
									{
										{0.61500001,0.33000001},
										1
									}
								},
								
								{
									
									{
										{0.44999999,0.22},
										1
									},
									
									{
										{0.44999999,0.23},
										1
									},
									
									{
										{0.44,0.23},
										1
									}
								},
								
								{
									
									{
										{0.47,0.22},
										1
									},
									
									{
										{0.47,0.23},
										1
									},
									
									{
										{0.47999999,0.23},
										1
									}
								},
								
								{
									
									{
										{0.46000001,0.155},
										1
									},
									
									{
										{0.44,0.155},
										1
									},
									
									{
										{0.44,0.17},
										1
									}
								},
								
								{
									
									{
										{0.46000001,0.155},
										1
									},
									
									{
										{0.47999999,0.155},
										1
									},
									
									{
										{0.47999999,0.17},
										1
									}
								},
								
								{
									
									{
										{0.66000003,0.22},
										1
									},
									
									{
										{0.66000003,0.23},
										1
									},
									
									{
										{0.64999998,0.23},
										1
									}
								},
								
								{
									
									{
										{0.68000001,0.22},
										1
									},
									
									{
										{0.68000001,0.23},
										1
									},
									
									{
										{0.69,0.23},
										1
									}
								},
								
								{
									
									{
										{0.67000002,0.155},
										1
									},
									
									{
										{0.64999998,0.155},
										1
									},
									
									{
										{0.64999998,0.17},
										1
									}
								},
								
								{
									
									{
										{0.67000002,0.155},
										1
									},
									
									{
										{0.69,0.155},
										1
									},
									
									{
										{0.69,0.17},
										1
									}
								}
							};
						};
					};
					class Yellow
					{
						color[]={1,0.30000001,0};
						alpha=1;
						class DrawLines
						{
							type="line";
							width=6;
							points[]=
							{
								
								{
									{0.23,0.175},
									1
								},
								
								{
									{0.31,0.175},
									1
								},
								{},
								
								{
									{0.23,0.19},
									1
								},
								
								{
									{0.31,0.19},
									1
								},
								{},
								
								{
									{0.23,0.205},
									1
								},
								
								{
									{0.31,0.205},
									1
								},
								{},
								
								{
									{0.33000001,0.175},
									1
								},
								
								{
									{0.41,0.175},
									1
								},
								{},
								
								{
									{0.33000001,0.19},
									1
								},
								
								{
									{0.41,0.19},
									1
								},
								{},
								
								{
									{0.33000001,0.205},
									1
								},
								
								{
									{0.41,0.205},
									1
								},
								{}
							};
						};
					};
					class Red
					{
						color[]={1,0,0};
						alpha=1;
						class DrawLines
						{
							type="line";
							width=6;
							points[]=
							{
								
								{
									{0.23,0.16},
									1
								},
								
								{
									{0.41,0.16},
									1
								},
								{},
								
								{
									{0.52499998,0.22},
									1
								},
								
								{
									{0.56999999,0.19},
									1
								},
								
								{
									{0.61500001,0.22},
									1
								}
							};
						};
						class DrawPolygons
						{
							type="polygon";
							points[]=
							{
								
								{
									
									{
										{0.31,0.16},
										1
									},
									
									{
										{0.31999999,0.17},
										1
									},
									
									{
										{0.33000001,0.16},
										1
									},
									
									{
										{0.31999999,0.15000001},
										1
									}
								},
								
								{
									
									{
										{0.50999999,0.19},
										1
									},
									
									{
										{0.51999998,0.2},
										1
									},
									
									{
										{0.52999997,0.19},
										1
									},
									
									{
										{0.51999998,0.18000001},
										1
									}
								},
								
								{
									
									{
										{0.61000001,0.19},
										1
									},
									
									{
										{0.62,0.2},
										1
									},
									
									{
										{0.63,0.19},
										1
									},
									
									{
										{0.62,0.18000001},
										1
									}
								}
							};
						};
					};
					class TorqueEng1
					{
						type="text";
						source="static";
						text="1";
						scale=1;
						sourceScale=1;
						align="center";
						pos[]=
						{
							{0.039999999,0.56},
							1
						};
						right[]=
						{
							{0.064999998,0.56},
							1
						};
						down[]=
						{
							{0.039999999,0.58499998},
							1
						};
					};
					class TorqueEng2
					{
						type="text";
						source="static";
						text="2";
						scale=1;
						sourceScale=1;
						align="center";
						pos[]=
						{
							{0.14,0.56},
							1
						};
						right[]=
						{
							{0.16500001,0.56},
							1
						};
						down[]=
						{
							{0.14,0.58499998},
							1
						};
					};
					class TGTEng1
					{
						type="text";
						source="static";
						text="1";
						scale=1;
						sourceScale=1;
						align="center";
						pos[]=
						{
							
							{
								"0.04+0.23",
								0.56
							},
							1
						};
						right[]=
						{
							{0.29499999,0.56},
							1
						};
						down[]=
						{
							
							{
								"0.04+0.23",
								0.58499998
							},
							1
						};
					};
					class TGTEng2
					{
						type="text";
						source="static";
						text="2";
						scale=1;
						sourceScale=1;
						align="center";
						pos[]=
						{
							
							{
								"0.14+0.23",
								0.56
							},
							1
						};
						right[]=
						{
							{0.39500001,0.56},
							1
						};
						down[]=
						{
							
							{
								"0.14+0.23",
								0.58499998
							},
							1
						};
					};
					class TurbineSpeed1
					{
						type="text";
						source="static";
						text="1";
						scale=1;
						sourceScale=1;
						align="center";
						pos[]=
						{
							
							{
								"0.04+0.42",
								0.56
							},
							1
						};
						right[]=
						{
							{0.48500001,0.56},
							1
						};
						down[]=
						{
							
							{
								"0.04+0.42",
								0.58499998
							},
							1
						};
					};
					class TurbineSpeed2
					{
						type="text";
						source="static";
						text="2";
						scale=1;
						sourceScale=1;
						align="center";
						pos[]=
						{
							
							{
								"0.14+0.53",
								0.56
							},
							1
						};
						right[]=
						{
							{0.69499999,0.56},
							1
						};
						down[]=
						{
							
							{
								"0.14+0.53",
								0.58499998
							},
							1
						};
					};
					class TurbineSpeed1_Percent
					{
						type="text";
						source="static";
						text="1";
						scale=1;
						sourceScale=1;
						align="center";
						pos[]=
						{
							
							{
								"0.04+0.76",
								0.56
							},
							1
						};
						right[]=
						{
							{0.82499999,0.56},
							1
						};
						down[]=
						{
							
							{
								"0.04+0.76",
								0.58499998
							},
							1
						};
					};
					class TurbineSpeed2_Percent
					{
						type="text";
						source="static";
						text="2";
						scale=1;
						sourceScale=1;
						align="center";
						pos[]=
						{
							
							{
								"0.14+0.78",
								0.56
							},
							1
						};
						right[]=
						{
							{0.94499999,0.56},
							1
						};
						down[]=
						{
							
							{
								"0.14+0.78",
								0.58499998
							},
							1
						};
					};
					class Engine
					{
						type="text";
						source="static";
						text="ENG";
						scale=1;
						sourceScale=1;
						align="left";
						pos[]=
						{
							{0.19,0.94},
							1
						};
						right[]=
						{
							{0.22,0.94},
							1
						};
						down[]=
						{
							{0.19,0.97000003},
							1
						};
					};
					class System
					{
						type="text";
						source="static";
						text="SYS";
						scale=1;
						sourceScale=1;
						align="left";
						pos[]=
						{
							{0.33000001,0.94},
							1
						};
						right[]=
						{
							{0.36000001,0.94},
							1
						};
						down[]=
						{
							{0.33000001,0.97000003},
							1
						};
					};
					class ETF
					{
						type="text";
						source="static";
						text="ETF";
						scale=1;
						sourceScale=1;
						align="left";
						pos[]=
						{
							{0.47,0.94},
							1
						};
						right[]=
						{
							{0.5,0.94},
							1
						};
						down[]=
						{
							{0.47,0.97000003},
							1
						};
					};
					class WCA
					{
						type="text";
						source="static";
						text="WCA";
						scale=1;
						sourceScale=1;
						align="left";
						pos[]=
						{
							{0.88999999,0.94},
							1
						};
						right[]=
						{
							{0.92000002,0.94},
							1
						};
						down[]=
						{
							{0.88999999,0.97000003},
							1
						};
					};
				};
			};
			class MFD_Left_Radar
			{
				topLeft="MFD_4_TL";
				topRight="MFD_4_TR";
				bottomLeft="MFD_4_BL";
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
				turret[]={-2};
				class material
				{
					ambient[]={5,5,5,1};
					diffuse[]={5,5,5,1};
					emissive[]={400,200,200,1};
				};
				class Bones
				{
					class Sensor_Offset
					{
						type="fixed";
						pos[]={0,0.25};
					};
					class Static_Offset
					{
						type="fixed";
						pos[]={0.5,0.85000002};
					};
					class Static_Offset2: Static_Offset
					{
						pos[]={0.5,0.75};
					};
					class Static_Offset_AA: Static_Offset
					{
						pos[]={0.5,0.495};
					};
					class Sensor_Offset_AA: Static_Offset
					{
						pos[]={0,-0.0049999999};
					};
					class LimitWaypoint
					{
						type="limit";
						limits[]={0.22,0.059999999,0.77999997,0.059999999};
					};
					class FCR_Bearing
					{
						type="linear";
						source="user";
						sourceIndex=17;
						min=-180;
						max=180;
						minPos[]={0.34999999,0.085000001};
						maxPos[]={0.66000003,0.085000001};
					};
					class FCR_ScanLine_Bottom
					{
						type="rotational";
						source="ClockSecondSmooth";
						sourceModulo=0.0666667;
						sourceScale=1;
						min=0;
						max=0.033333302;
						pos0[]={0,0};
						pos10[]={0,0};
						center[]={0,0};
						minAngle=90;
						maxAngle=270;
						aspectRatio=1;
					};
					class FCR_ScanLine_Top: FCR_ScanLine_Bottom
					{
						min=0.033333302;
						max=0.0666667;
						minAngle=270;
						maxAngle=90;
					};
					class FCR_ScanLine_AA: FCR_ScanLine_Bottom
					{
						min=0;
						max=1;
						minAngle=180;
						maxAngle=540;
					};
					class WPPoint
					{
						type="vector";
						source="WPPoint";
						pos0[]={0.5,0.5};
						pos10[]={0.93400002,0.93000001};
					};
					class GunnerAim
					{
						type="vector";
						source="turret";
						pos0[]={0,-2};
						pos10[]={0.0068000001,-0.0099999998};
						projection=0;
					};
				};
				class Draw
				{
					alpha=1;
					color[]={0,0.12,0};
					condition="on";
					class Static
					{
						type="line";
						width=5;
						points[]=
						{
							
							{
								{0.5,0.090000004},
								1
							},
							
							{
								{0.5,0.12},
								1
							},
							{},
							
							{
								{0.0099999998,0.82999998},
								1
							},
							
							{
								{0.035,0.82999998},
								1
							},
							{},
							
							{
								{0.0099999998,0.84500003},
								1
							},
							
							{
								{0.02,0.84500003},
								1
							},
							{},
							
							{
								{0.0099999998,0.86000001},
								1
							},
							
							{
								{0.02,0.86000001},
								1
							},
							{},
							
							{
								{0.0099999998,0.875},
								1
							},
							
							{
								{0.02,0.875},
								1
							},
							{},
							
							{
								{0.0099999998,0.88999999},
								1
							},
							
							{
								{0.02,0.88999999},
								1
							},
							{},
							
							{
								{0.0099999998,0.90499997},
								1
							},
							
							{
								{0.035,0.90499997},
								1
							},
							{},
							
							{
								{0.0099999998,0.92000002},
								1
							},
							
							{
								{0.02,0.92000002},
								1
							},
							{},
							
							{
								{0.0099999998,0.935},
								1
							},
							
							{
								{0.02,0.935},
								1
							},
							{},
							
							{
								{0.0099999998,0.94999999},
								1
							},
							
							{
								{0.035,0.94999999},
								1
							},
							{},
							
							{
								{0.079999998,0.91000003},
								1
							},
							
							{
								{0.075000003,0.91500002},
								1
							},
							
							{
								{0.07,0.92000002},
								1
							},
							
							{
								{0.07,0.98000002},
								1
							},
							
							{
								{0.075000003,0.98500001},
								1
							},
							
							{
								{0.079999998,0.99000001},
								1
							},
							
							{
								{0.34,0.99000001},
								1
							},
							
							{
								{0.345,0.98500001},
								1
							},
							
							{
								{0.34999999,0.98000002},
								1
							},
							
							{
								{0.34999999,0.92000002},
								1
							},
							
							{
								{0.345,0.91500002},
								1
							},
							
							{
								{0.34,0.91000003},
								1
							},
							
							{
								{0.079999998,0.91000003},
								1
							},
							{},
							
							{
								{0.66000003,0.91000003},
								1
							},
							
							{
								{0.65499997,0.91500002},
								1
							},
							
							{
								{0.64999998,0.92000002},
								1
							},
							
							{
								{0.64999998,0.98000002},
								1
							},
							
							{
								{0.65499997,0.98500001},
								1
							},
							
							{
								{0.66000003,0.99000001},
								1
							},
							
							{
								{0.92000002,0.99000001},
								1
							},
							
							{
								{0.92500001,0.98500001},
								1
							},
							
							{
								{0.93000001,0.98000002},
								1
							},
							
							{
								{0.93000001,0.92000002},
								1
							},
							
							{
								{0.92500001,0.91500002},
								1
							},
							
							{
								{0.92000002,0.91000003},
								1
							},
							
							{
								{0.66000003,0.91000003},
								1
							},
							{},
							{},
							
							{
								{0.80000001,0.014},
								1
							},
							
							{
								{0.87,0.014},
								1
							},
							{},
							
							{
								{0.94523901,0.33577099},
								1
							},
							
							{
								{0.96414399,0.33577099},
								1
							},
							
							{
								{0.96414399,0.341741},
								1
							},
							
							{
								{0.99449199,0.32582101},
								1
							},
							
							{
								{0.96414399,0.309403},
								1
							},
							
							{
								{0.96414399,0.315871},
								1
							},
							
							{
								{0.94523901,0.315871},
								1
							},
							
							{
								{0.94523901,0.33577099},
								1
							},
							{},
							
							{
								{0.059666701,0.33577099},
								1
							},
							
							{
								{0.040761199,0.33577099},
								1
							},
							
							{
								{0.040761199,0.341741},
								1
							},
							
							{
								{0.0109104,0.32582101},
								1
							},
							
							{
								{0.040761199,0.309403},
								1
							},
							
							{
								{0.040761199,0.315871},
								1
							},
							
							{
								{0.059666701,0.315871},
								1
							},
							
							{
								{0.059666701,0.33577099},
								1
							},
							{}
						};
					};
					class ClassArrows
					{
						type="polygon";
						points[]=
						{
							
							{
								
								{
									{0.87,0.0068000001},
									1
								},
								
								{
									{0.88999999,0.014},
									1
								},
								
								{
									{0.87,0.021199999},
									1
								}
							},
							
							{
								
								{
									{0.059999999,0.89420003},
									1
								},
								
								{
									{0.039999999,0.90499997},
									1
								},
								
								{
									{0.059999999,0.91579998},
									1
								}
							},
							
							{
								
								{
									"FCR_Bearing",
									{-0.018999999,0},
									1
								},
								
								{
									"FCR_Bearing",
									{-0.0080000004,0},
									1
								},
								
								{
									"FCR_Bearing",
									{-0.0080000004,0.011},
									1
								},
								
								{
									"FCR_Bearing",
									{-0.018999999,0.011},
									1
								}
							},
							
							{
								
								{
									"FCR_Bearing",
									{-0.003,0},
									1
								},
								
								{
									"FCR_Bearing",
									{0.0080000004,0},
									1
								},
								
								{
									"FCR_Bearing",
									{0.0080000004,0.011},
									1
								},
								
								{
									"FCR_Bearing",
									{-0.003,0.011},
									1
								}
							},
							
							{
								
								{
									"FCR_Bearing",
									{0.0080000004,0},
									1
								},
								
								{
									"FCR_Bearing",
									{0.014,0.0055},
									1
								},
								
								{
									"FCR_Bearing",
									{0.0080000004,0.011},
									1
								}
							},
							
							{
								
								{
									"FCR_Bearing",
									{-0.018999999,0},
									1
								},
								
								{
									"FCR_Bearing",
									{-0.025,0.0055},
									1
								},
								
								{
									"FCR_Bearing",
									{-0.018999999,0.011},
									1
								}
							}
						};
					};
					class HeadingHeadNumber
					{
						type="text";
						source="heading";
						sourceScale=1;
						align="center";
						scale=1;
						pos[]=
						{
							
							{
								0.5,
								"0.042-0.03"
							},
							1
						};
						right[]=
						{
							
							{
								0.54000002,
								"0.042-0.03"
							},
							1
						};
						down[]=
						{
							{0.5,0.052000001},
							1
						};
					};
					class HeadingScaleRight
					{
						clipTL[]={0.55000001,0};
						clipBR[]={0.76999998,0.11};
						class lines
						{
							type="scale";
							horizontal=1;
							source="heading";
							sourceScale=0.1;
							width=4;
							NeverEatSeaWeed=1;
							top=0.5;
							center=0.5;
							bottom=0.81999999;
							lineXleft=0.079999998;
							lineYright=0.07;
							lineXleftMajor=0.079999998;
							lineYrightMajor=0.059999999;
							majorLineEach=3;
							numberEach=3;
							step=1;
							stepSize=0.0263889;
							align="center";
							scale=1;
							pos[]=
							{
								0.495,
								"0.05-0.03"
							};
							right[]=
							{
								0.51999998,
								"0.05-0.03"
							};
							down[]=
							{
								0.495,
								"0.08-0.03"
							};
						};
					};
					class HeadingScaleMidle
					{
						type="scale";
						horizontal=1;
						source="heading";
						sourceScale=0.1;
						width=4;
						NeverEatSeaWeed=1;
						top=0.44999999;
						center=0.5;
						bottom=0.55000001;
						lineXleft=0.079999998;
						lineYright=0.07;
						lineXleftMajor=0.079999998;
						lineYrightMajor=0.07;
						majorLineEach=2;
						step=1;
						stepSize=0.0263889;
						align="center";
						scale=1;
						numberEach=0;
						pos[]=
						{
							0.47,
							"0.05-0.03"
						};
						right[]=
						{
							0.5,
							"0.05-0.03"
						};
						down[]=
						{
							0.44999999,
							"0.09-0.03"
						};
					};
					class HeadingScaleLeft
					{
						clipTL[]={0.23,0};
						clipBR[]={0.44999999,0.11};
						class lines
						{
							type="scale";
							horizontal=1;
							source="heading";
							sourceScale=0.1;
							width=4;
							NeverEatSeaWeed=1;
							top=0.17;
							center=0.5;
							bottom=0.55000001;
							lineXleft=0.079999998;
							lineYright=0.07;
							lineXleftMajor=0.079999998;
							lineYrightMajor=0.059999999;
							majorLineEach=3;
							numberEach=3;
							step=1;
							stepSize=0.0263889;
							align="center";
							scale=1;
							pos[]=
							{
								0.16599999,
								"0.05-0.03"
							};
							right[]=
							{
								0.191,
								"0.05-0.03"
							};
							down[]=
							{
								0.16599999,
								"0.08-0.03"
							};
						};
					};
					class WP
					{
						condition="wpvalid";
						class Static
						{
							type="line";
							width=4;
							points[]=
							{
								
								{
									"WPPoint",
									1,
									"LimitWaypoint",
									1,
									{-0.0099999998,0.039999999},
									1
								},
								
								{
									"WPPoint",
									1,
									"LimitWaypoint",
									1,
									{0,0.02},
									1
								},
								
								{
									"WPPoint",
									1,
									"LimitWaypoint",
									1,
									{0.0099999998,0.039999999},
									1
								},
								{}
							};
						};
					};
					class TgtStoreSelection1
					{
						type="text";
						source="static";
						text="T";
						scale=1;
						sourceScale=1;
						align="right";
						pos[]=
						{
							{0.0049999999,0.44999999},
							1
						};
						right[]=
						{
							{0.035,0.44999999},
							1
						};
						down[]=
						{
							{0.0049999999,0.47999999},
							1
						};
					};
					class TgtStoreSelection2
					{
						type="text";
						source="static";
						text="G";
						scale=1;
						sourceScale=1;
						align="right";
						pos[]=
						{
							{0.0049999999,0.49000001},
							1
						};
						right[]=
						{
							{0.035,0.49000001},
							1
						};
						down[]=
						{
							{0.0049999999,0.51999998},
							1
						};
					};
					class TgtStoreSelection3
					{
						type="text";
						source="static";
						text="T";
						scale=1;
						sourceScale=1;
						align="right";
						pos[]=
						{
							{0.0049999999,0.52999997},
							1
						};
						right[]=
						{
							{0.035,0.52999997},
							1
						};
						down[]=
						{
							{0.0049999999,0.56},
							1
						};
					};
					class NextToShoot1
					{
						type="text";
						source="static";
						text="N";
						scale=1;
						sourceScale=1;
						align="right";
						pos[]=
						{
							{0.0049999999,0.14},
							1
						};
						right[]=
						{
							{0.035,0.14},
							1
						};
						down[]=
						{
							{0.0049999999,0.17},
							1
						};
					};
					class NextToShoot2
					{
						type="text";
						source="static";
						text="T";
						scale=1;
						sourceScale=1;
						align="right";
						pos[]=
						{
							{0.0049999999,0.18000001},
							1
						};
						right[]=
						{
							{0.035,0.18000001},
							1
						};
						down[]=
						{
							{0.0049999999,0.20999999},
							1
						};
					};
					class NextToShoot3
					{
						type="text";
						source="static";
						text="S";
						scale=1;
						sourceScale=1;
						align="right";
						pos[]=
						{
							{0.0049999999,0.22},
							1
						};
						right[]=
						{
							{0.035,0.22},
							1
						};
						down[]=
						{
							{0.0049999999,0.25},
							1
						};
					};
					class RF_Sel1
					{
						type="text";
						source="static";
						text="RF";
						scale=1;
						sourceScale=1;
						align="left";
						pos[]=
						{
							{0.995,0.46000001},
							1
						};
						right[]=
						{
							{1.025,0.46000001},
							1
						};
						down[]=
						{
							{0.995,0.49000001},
							1
						};
					};
					class RF_Sel2
					{
						type="text";
						source="static";
						text="HO";
						scale=1;
						sourceScale=1;
						align="left";
						pos[]=
						{
							{0.995,0.5},
							1
						};
						right[]=
						{
							{1.025,0.5},
							1
						};
						down[]=
						{
							{0.995,0.52999997},
							1
						};
					};
					class AcquisitionBtn1
					{
						type="text";
						source="static";
						text="ACQ";
						scale=1;
						sourceScale=1;
						align="left";
						pos[]=
						{
							{0.995,0.77999997},
							1
						};
						right[]=
						{
							{1.025,0.77999997},
							1
						};
						down[]=
						{
							{0.995,0.81},
							1
						};
					};
					class AcquisitionBtn2
					{
						type="text";
						source="static";
						text="T32";
						scale=1;
						sourceScale=1;
						align="left";
						pos[]=
						{
							{0.995,0.83999997},
							1
						};
						right[]=
						{
							{1.025,0.83999997},
							1
						};
						down[]=
						{
							{0.995,0.87},
							1
						};
					};
					class CScope
					{
						type="text";
						source="static";
						text="C SCP";
						scale=1;
						sourceScale=1;
						align="left";
						pos[]=
						{
							{0.23,0.029999999},
							1
						};
						right[]=
						{
							{0.25999999,0.029999999},
							1
						};
						down[]=
						{
							{0.23,0.059999999},
							1
						};
					};
					class Utilities
					{
						type="text";
						source="static";
						text="UTIL";
						scale=1;
						sourceScale=1;
						align="left";
						pos[]=
						{
							{0.88999999,0.029999999},
							1
						};
						right[]=
						{
							{0.92000002,0.029999999},
							1
						};
						down[]=
						{
							{0.88999999,0.059999999},
							1
						};
					};
					class TotalTargetCount
					{
						type="text";
						source="static";
						text="XXXX";
						scale=1;
						sourceScale=1;
						align="left";
						pos[]=
						{
							{0.97000003,0.079999998},
							1
						};
						right[]=
						{
							{1,0.079999998},
							1
						};
						down[]=
						{
							{0.97000003,0.11},
							1
						};
					};
					class RadarGround
					{
						condition="1";
						class Static
						{
							type="line";
							width=4;
							points[]=
							{
								
								{
									{0.40000001,0.91000003},
									1
								},
								
								{
									{0.40000001,0.99000001},
									1
								},
								
								{
									{0.60000002,0.99000001},
									1
								},
								
								{
									{0.60000002,0.91000003},
									1
								},
								
								{
									{0.40000001,0.91000003},
									1
								},
								{},
								
								{
									{0.40000001,0.935},
									1
								},
								
								{
									{0.40799999,0.935},
									1
								},
								{},
								
								{
									{0.60000002,0.935},
									1
								},
								
								{
									{0.59200001,0.935},
									1
								},
								{},
								
								{
									{0.5,0.91000003},
									1
								},
								
								{
									{0.5,0.91799998},
									1
								},
								{},
								
								{
									{0.5,0.99000001},
									1
								},
								
								{
									{0.5,0.98199999},
									1
								},
								{},
								
								{
									{0.050999999,0.81},
									1
								},
								
								{
									{0.161,0.81},
									1
								},
								
								{
									{0.161,0.86000001},
									1
								},
								
								{
									{0.050999999,0.86000001},
									1
								},
								
								{
									{0.050999999,0.81},
									1
								},
								{},
								
								{
									{0.91500002,0.82999998},
									1
								},
								
								{
									{1,0.82999998},
									1
								},
								
								{
									{1,0.88},
									1
								},
								
								{
									{0.91500002,0.88},
									1
								},
								
								{
									{0.91500002,0.82999998},
									1
								},
								{},
								
								{
									"GunnerAim",
									{0.48500001,0.94199997},
									1
								},
								
								{
									"GunnerAim",
									{0.48500001,0.958},
									1
								},
								
								{
									"GunnerAim",
									{0.51499999,0.958},
									1
								},
								
								{
									"GunnerAim",
									{0.51499999,0.94199997},
									1
								},
								
								{
									"GunnerAim",
									{0.48500001,0.94199997},
									1
								},
								{},
								
								{
									"Static_Offset2",
									{0.050000001,2.1654301e-009},
									1
								},
								
								{
									"Static_Offset2",
									{0.49000001,2.1221201e-008},
									1
								},
								
								{
									"Static_Offset2",
									{0.48813501,-0.0423127},
									1
								},
								
								{
									"Static_Offset2",
									{0.48255599,-0.084303401},
									1
								},
								
								{
									"Static_Offset2",
									{0.473304,-0.125652},
									1
								},
								
								{
									"Static_Offset2",
									{0.46044901,-0.166045},
									1
								},
								
								{
									"Static_Offset2",
									{0.44409099,-0.205174},
									1
								},
								
								{
									"Static_Offset2",
									{0.42435199,-0.242742},
									1
								},
								
								{
									"Static_Offset2",
									{0.40138501,-0.27846199},
									1
								},
								
								{
									"Static_Offset2",
									{0.37536201,-0.31206301},
									1
								},
								
								{
									"Static_Offset2",
									{0.34648201,-0.34328899},
									1
								},
								
								{
									"Static_Offset2",
									{0.31496599,-0.37190199},
									1
								},
								
								{
									"Static_Offset2",
									{0.28105301,-0.39768499},
									1
								},
								
								{
									"Static_Offset2",
									{0.245,-0.420441},
									1
								},
								
								{
									"Static_Offset2",
									{0.207083,-0.439998},
									1
								},
								
								{
									"Static_Offset2",
									{0.16759001,-0.45620599},
									1
								},
								
								{
									"Static_Offset2",
									{0.126821,-0.468941},
									1
								},
								
								{
									"Static_Offset2",
									{0.085087597,-0.47810799},
									1
								},
								
								{
									"Static_Offset2",
									{0.0427063,-0.48363701},
									1
								},
								
								{
									"Static_Offset2",
									{0,-0.485484},
									1
								},
								
								{
									"Static_Offset2",
									{-0.0427063,-0.48363701},
									1
								},
								
								{
									"Static_Offset2",
									{-0.085087597,-0.47810799},
									1
								},
								
								{
									"Static_Offset2",
									{-0.126821,-0.468941},
									1
								},
								
								{
									"Static_Offset2",
									{-0.16759001,-0.45620599},
									1
								},
								
								{
									"Static_Offset2",
									{-0.207083,-0.439998},
									1
								},
								
								{
									"Static_Offset2",
									{-0.245,-0.420441},
									1
								},
								
								{
									"Static_Offset2",
									{-0.28105301,-0.39768499},
									1
								},
								
								{
									"Static_Offset2",
									{-0.31496599,-0.37190199},
									1
								},
								
								{
									"Static_Offset2",
									{-0.34648201,-0.34328899},
									1
								},
								
								{
									"Static_Offset2",
									{-0.37536201,-0.31206301},
									1
								},
								
								{
									"Static_Offset2",
									{-0.40138501,-0.27846199},
									1
								},
								
								{
									"Static_Offset2",
									{-0.42435199,-0.242742},
									1
								},
								
								{
									"Static_Offset2",
									{-0.44409099,-0.205174},
									1
								},
								
								{
									"Static_Offset2",
									{-0.46044901,-0.166045},
									1
								},
								
								{
									"Static_Offset2",
									{-0.473304,-0.125652},
									1
								},
								
								{
									"Static_Offset2",
									{-0.48255599,-0.084303401},
									1
								},
								
								{
									"Static_Offset2",
									{-0.48813501,-0.0423127},
									1
								},
								
								{
									"Static_Offset2",
									{-0.49000001,2.1221201e-008},
									1
								},
								
								{
									"Static_Offset2",
									{-0.050000001,2.1654301e-009},
									1
								},
								
								{
									"Static_Offset2",
									{-0.47999999,2.07881e-008},
									1
								},
								{},
								
								{
									"Static_Offset2",
									{0,-0.485484},
									1
								},
								
								{
									"Static_Offset2",
									{0,-0.46566799},
									1
								},
								{},
								
								{
									"Static_Offset2",
									{0.126821,-0.468941},
									1
								},
								
								{
									"Static_Offset2",
									{0.121645,-0.449801},
									1
								},
								{},
								
								{
									"Static_Offset2",
									{0.245,-0.420441},
									1
								},
								
								{
									"Static_Offset2",
									{0.235,-0.40327999},
									1
								},
								{},
								
								{
									"Static_Offset2",
									{0.34648201,-0.34328899},
									1
								},
								
								{
									"Static_Offset2",
									{0.33234,-0.32927701},
									1
								},
								{},
								
								{
									"Static_Offset2",
									{0.42435199,-0.242742},
									1
								},
								
								{
									"Static_Offset2",
									{0.40703201,-0.232834},
									1
								},
								{},
								
								{
									"Static_Offset2",
									{0.473304,-0.125652},
									1
								},
								
								{
									"Static_Offset2",
									{0.45398501,-0.120524},
									1
								},
								{},
								
								{
									"Static_Offset2",
									{-0.126821,-0.468941},
									1
								},
								
								{
									"Static_Offset2",
									{-0.121645,-0.449801},
									1
								},
								{},
								
								{
									"Static_Offset2",
									{-0.245,-0.420441},
									1
								},
								
								{
									"Static_Offset2",
									{-0.235,-0.40327999},
									1
								},
								{},
								
								{
									"Static_Offset2",
									{-0.34648201,-0.34328899},
									1
								},
								
								{
									"Static_Offset2",
									{-0.33234,-0.32927701},
									1
								},
								{},
								
								{
									"Static_Offset2",
									{-0.42435199,-0.242742},
									1
								},
								
								{
									"Static_Offset2",
									{-0.40703201,-0.232834},
									1
								},
								{},
								
								{
									"Static_Offset2",
									{-0.473304,-0.125652},
									1
								},
								
								{
									"Static_Offset2",
									{-0.45398501,-0.120524},
									1
								},
								{}
							};
						};
						class StaticLight
						{
							type="line";
							width=2;
							points[]=
							{
								
								{
									"Static_Offset2",
									{0.294,1.27327e-008},
									1
								},
								
								{
									"Static_Offset2",
									{0.29288101,-0.0253876},
									1
								},
								
								{
									"Static_Offset2",
									{0.289534,-0.050581999},
									1
								},
								
								{
									"Static_Offset2",
									{0.28398201,-0.075391501},
									1
								},
								
								{
									"Static_Offset2",
									{0.27627,-0.0996271},
									1
								},
								
								{
									"Static_Offset2",
									{0.26645499,-0.123105},
									1
								},
								
								{
									"Static_Offset2",
									{0.254612,-0.14564499},
									1
								},
								
								{
									"Static_Offset2",
									{0.240831,-0.167077},
									1
								},
								
								{
									"Static_Offset2",
									{0.225217,-0.18723799},
									1
								},
								
								{
									"Static_Offset2",
									{0.20788901,-0.205973},
									1
								},
								
								{
									"Static_Offset2",
									{0.18898,-0.223141},
									1
								},
								
								{
									"Static_Offset2",
									{0.168632,-0.238611},
									1
								},
								
								{
									"Static_Offset2",
									{0.147,-0.25226501},
									1
								},
								
								{
									"Static_Offset2",
									{0.12425,-0.26399899},
									1
								},
								
								{
									"Static_Offset2",
									{0.100554,-0.27372301},
									1
								},
								
								{
									"Static_Offset2",
									{0.076092802,-0.28136501},
									1
								},
								
								{
									"Static_Offset2",
									{0.0510526,-0.286865},
									1
								},
								
								{
									"Static_Offset2",
									{0.0256238,-0.29018199},
									1
								},
								
								{
									"Static_Offset2",
									{0,-0.29128999},
									1
								},
								
								{
									"Static_Offset2",
									{-0.0256238,-0.29018199},
									1
								},
								
								{
									"Static_Offset2",
									{-0.0510526,-0.286865},
									1
								},
								
								{
									"Static_Offset2",
									{-0.076092802,-0.28136501},
									1
								},
								
								{
									"Static_Offset2",
									{-0.100554,-0.27372301},
									1
								},
								
								{
									"Static_Offset2",
									{-0.12425,-0.26399899},
									1
								},
								
								{
									"Static_Offset2",
									{-0.147,-0.25226501},
									1
								},
								
								{
									"Static_Offset2",
									{-0.168632,-0.238611},
									1
								},
								
								{
									"Static_Offset2",
									{-0.18898,-0.223141},
									1
								},
								
								{
									"Static_Offset2",
									{-0.20788901,-0.205973},
									1
								},
								
								{
									"Static_Offset2",
									{-0.225217,-0.18723799},
									1
								},
								
								{
									"Static_Offset2",
									{-0.240831,-0.167077},
									1
								},
								
								{
									"Static_Offset2",
									{-0.254612,-0.14564499},
									1
								},
								
								{
									"Static_Offset2",
									{-0.26645499,-0.123105},
									1
								},
								
								{
									"Static_Offset2",
									{-0.27627,-0.0996271},
									1
								},
								
								{
									"Static_Offset2",
									{-0.28398201,-0.075391501},
									1
								},
								
								{
									"Static_Offset2",
									{-0.289534,-0.050581999},
									1
								},
								
								{
									"Static_Offset2",
									{-0.29288101,-0.0253876},
									1
								},
								
								{
									"Static_Offset2",
									{-0.294,1.27327e-008},
									1
								},
								
								{
									"Static_Offset2",
									{-0.029999999,1.29926e-009},
									1
								},
								
								{
									"Static_Offset2",
									{-0.28799999,1.24729e-008},
									1
								},
								{},
								
								{
									"Static_Offset2",
									{0,-0.29525301},
									1
								},
								
								{
									"Static_Offset2",
									{0,-0.283364},
									1
								},
								{},
								
								{
									"Static_Offset2",
									{0.147,6.3663501e-009},
									1
								},
								
								{
									"Static_Offset2",
									{0.146441,-0.0126938},
									1
								},
								
								{
									"Static_Offset2",
									{0.144767,-0.025291},
									1
								},
								
								{
									"Static_Offset2",
									{0.141991,-0.037695698},
									1
								},
								
								{
									"Static_Offset2",
									{0.138135,-0.049813598},
									1
								},
								
								{
									"Static_Offset2",
									{0.13322701,-0.061552301},
									1
								},
								
								{
									"Static_Offset2",
									{0.127306,-0.072822601},
									1
								},
								
								{
									"Static_Offset2",
									{0.120415,-0.083538704},
									1
								},
								
								{
									"Static_Offset2",
									{0.112609,-0.0936189},
									1
								},
								
								{
									"Static_Offset2",
									{0.103945,-0.102987},
									1
								},
								
								{
									"Static_Offset2",
									{0.094489798,-0.111571},
									1
								},
								
								{
									"Static_Offset2",
									{0.084315799,-0.119306},
									1
								},
								
								{
									"Static_Offset2",
									{0.0735,-0.126132},
									1
								},
								
								{
									"Static_Offset2",
									{0.062124901,-0.131999},
									1
								},
								
								{
									"Static_Offset2",
									{0.050276998,-0.13686199},
									1
								},
								
								{
									"Static_Offset2",
									{0.038046401,-0.140682},
									1
								},
								
								{
									"Static_Offset2",
									{0.0255263,-0.14343201},
									1
								},
								
								{
									"Static_Offset2",
									{0.0128119,-0.145091},
									1
								},
								
								{
									"Static_Offset2",
									{0,-0.14564499},
									1
								},
								
								{
									"Static_Offset2",
									{-0.0128119,-0.145091},
									1
								},
								
								{
									"Static_Offset2",
									{-0.0255263,-0.14343201},
									1
								},
								
								{
									"Static_Offset2",
									{-0.038046401,-0.140682},
									1
								},
								
								{
									"Static_Offset2",
									{-0.050276998,-0.13686199},
									1
								},
								
								{
									"Static_Offset2",
									{-0.062124901,-0.131999},
									1
								},
								
								{
									"Static_Offset2",
									{-0.0735,-0.126132},
									1
								},
								
								{
									"Static_Offset2",
									{-0.084315799,-0.119306},
									1
								},
								
								{
									"Static_Offset2",
									{-0.094489798,-0.111571},
									1
								},
								
								{
									"Static_Offset2",
									{-0.103945,-0.102987},
									1
								},
								
								{
									"Static_Offset2",
									{-0.112609,-0.0936189},
									1
								},
								
								{
									"Static_Offset2",
									{-0.120415,-0.083538704},
									1
								},
								
								{
									"Static_Offset2",
									{-0.127306,-0.072822601},
									1
								},
								
								{
									"Static_Offset2",
									{-0.13322701,-0.061552301},
									1
								},
								
								{
									"Static_Offset2",
									{-0.138135,-0.049813598},
									1
								},
								
								{
									"Static_Offset2",
									{-0.141991,-0.037695698},
									1
								},
								
								{
									"Static_Offset2",
									{-0.144767,-0.025291},
									1
								},
								
								{
									"Static_Offset2",
									{-0.146441,-0.0126938},
									1
								},
								
								{
									"Static_Offset2",
									{-0.147,6.3663501e-009},
									1
								},
								
								{
									"Static_Offset2",
									{-0.015,6.4962802e-010},
									1
								},
								
								{
									"Static_Offset2",
									{-0.14399999,6.23643e-009},
									1
								},
								{},
								
								{
									"Static_Offset2",
									{0,-0.15258101},
									1
								},
								
								{
									"Static_Offset2",
									{0,-0.14663599},
									1
								},
								{}
							};
						};
						class TransponderID
						{
							type="text";
							source="static";
							text="ELEV";
							scale=1;
							sourceScale=1;
							align="right";
							pos[]=
							{
								
								{
									"0.005+0.05",
									0.75999999
								},
								1
							};
							right[]=
							{
								{0.085000001,0.75999999},
								1
							};
							down[]=
							{
								
								{
									"0.005+0.05",
									0.79000002
								},
								1
							};
						};
						class ElevMode
						{
							type="text";
							source="static";
							text="AUTO";
							scale=1;
							sourceScale=1;
							align="right";
							pos[]=
							{
								
								{
									"0.005+0.05",
									0.81999999
								},
								1
							};
							right[]=
							{
								{0.085000001,0.81999999},
								1
							};
							down[]=
							{
								
								{
									"0.005+0.05",
									0.85000002
								},
								1
							};
						};
						class ZoomBtn1
						{
							type="text";
							source="static";
							text="Z";
							scale=1;
							sourceScale=1;
							align="right";
							pos[]=
							{
								{0.96499997,0.14},
								1
							};
							right[]=
							{
								{0.995,0.14},
								1
							};
							down[]=
							{
								{0.96499997,0.17},
								1
							};
						};
						class ZoomBtn2
						{
							type="text";
							source="static";
							text="O";
							scale=1;
							sourceScale=1;
							align="right";
							pos[]=
							{
								{0.96499997,0.18000001},
								1
							};
							right[]=
							{
								{0.995,0.18000001},
								1
							};
							down[]=
							{
								{0.96499997,0.20999999},
								1
							};
						};
						class ZoomBtn3
						{
							type="text";
							source="static";
							text="O";
							scale=1;
							sourceScale=1;
							align="right";
							pos[]=
							{
								{0.96499997,0.22},
								1
							};
							right[]=
							{
								{0.995,0.22},
								1
							};
							down[]=
							{
								{0.96499997,0.25},
								1
							};
						};
						class ZoomBtn4
						{
							type="text";
							source="static";
							text="M";
							scale=1;
							sourceScale=1;
							align="right";
							pos[]=
							{
								{0.96499997,0.25999999},
								1
							};
							right[]=
							{
								{0.995,0.25999999},
								1
							};
							down[]=
							{
								{0.96499997,0.28999999},
								1
							};
						};
						class SensorGroup
						{
							class Sensor
							{
								type="sensor";
								pos[]=
								{
									"Sensor_Offset",
									
									{
										"0+-0.18",
										"0+-0.18"
									},
									1
								};
								down[]=
								{
									"Sensor_Offset",
									
									{
										"1--0.18",
										"1--0.18"
									},
									1
								};
								showTargetTypes="2+4+8+16+32+64+128+256+512+1024";
								width=4;
								sensorLineType=0;
								sensorLineWidth=3;
								targetLineWidth=-0.00192;
								targetLineLength=0.02;
								range="SidePanelRadarRange";
								class MissileThreat
								{
									color[]={1,0,0};
									class TargetLines
									{
										type="line";
										width=2;
										points[]=
										{
											
											{
												{0,-0.0198157},
												1
											},
											
											{
												{0.0034719999,-0.019514499},
												1
											},
											
											{
												{0.0068399999,-0.0186208},
												1
											},
											
											{
												{0.0099999998,-0.017160401},
												1
											},
											
											{
												{0.012856,-0.0151788},
												1
											},
											
											{
												{0.01532,-0.0127375},
												1
											},
											
											{
												{0.01732,-0.0099078296},
												1
											},
											
											{
												{0.018794,-0.0067769601},
												1
											},
											
											{
												{0.019695999,-0.0034399999},
												1
											},
											
											{
												{0.02,0},
												1
											},
											
											{
												{0.019695999,0.0034399999},
												1
											},
											
											{
												{0.018794,0.0067769601},
												1
											},
											
											{
												{0.01732,0.0099078296},
												1
											},
											
											{
												{0.01532,0.0127375},
												1
											},
											
											{
												{0.012856,0.0151788},
												1
											},
											
											{
												{0.0099999998,0.017160401},
												1
											},
											
											{
												{0.0068399999,0.0186208},
												1
											},
											
											{
												{0.0034719999,0.019514499},
												1
											},
											
											{
												{0,0.0198157},
												1
											},
											
											{
												{-0.0034719999,0.019514499},
												1
											},
											
											{
												{-0.0068399999,0.0186208},
												1
											},
											
											{
												{-0.0099999998,0.017160401},
												1
											},
											
											{
												{-0.012856,0.0151788},
												1
											},
											
											{
												{-0.01532,0.0127375},
												1
											},
											
											{
												{-0.01732,0.0099078296},
												1
											},
											
											{
												{-0.018794,0.0067769601},
												1
											},
											
											{
												{-0.019695999,0.0034399999},
												1
											},
											
											{
												{-0.02,0},
												1
											},
											
											{
												{-0.019695999,-0.0034399999},
												1
											},
											
											{
												{-0.018794,-0.0067769601},
												1
											},
											
											{
												{-0.01732,-0.0099078296},
												1
											},
											
											{
												{-0.01532,-0.0127375},
												1
											},
											
											{
												{-0.012856,-0.0151788},
												1
											},
											
											{
												{-0.0099999998,-0.017160401},
												1
											},
											
											{
												{-0.0068399999,-0.0186208},
												1
											},
											
											{
												{-0.0034719999,-0.019514499},
												1
											},
											
											{
												{0,-0.0198157},
												1
											}
										};
									};
									class TextM
									{
										type="text";
										source="static";
										text="M";
										align="center";
										scale=1;
										pos[]=
										{
											{0,-0.0099999998},
											1
										};
										right[]=
										{
											{0.02,-0.0099999998},
											1
										};
										down[]=
										{
											{0,0.0099999998},
											1
										};
									};
								};
								class lockingThreat
								{
									color[]={1,0.30000001,0};
									class TargetLines
									{
										type="line";
										points[]=
										{
											
											{
												{0.02,0},
												1
											},
											
											{
												{0,0.0198157},
												1
											},
											
											{
												{-0.02,0},
												1
											},
											
											{
												{0,-0.0198157},
												1
											},
											
											{
												{0.02,0},
												1
											}
										};
									};
								};
								class markingThreat: lockingThreat
								{
									class TargetLines: TargetLines
									{
									};
								};
								class rwr
								{
									class TargetLines
									{
										type="line";
										width=2;
										points[]=
										{
											
											{
												{0.02,0},
												1
											},
											
											{
												{0,0.0198157},
												1
											},
											
											{
												{-0.02,0},
												1
											},
											
											{
												{0,-0.0198157},
												1
											},
											
											{
												{0.02,0},
												1
											}
										};
									};
								};
								class rwrFriendly: rwr
								{
									color[]={0,1,0};
									class TargetLines: TargetLines
									{
									};
								};
								class rwrEnemy: rwr
								{
									color[]={1,0,0};
									class TargetLines: TargetLines
									{
									};
								};
								class rwrGroup: rwr
								{
									color[]={1,0,0};
									class TargetLines: TargetLines
									{
									};
								};
								class rwrDestroyed
								{
								};
								class markedTarget
								{
									color[]={1,0.30000001,0};
									class TargetLines
									{
										type="line";
										width=3;
										points[]=
										{
											
											{
												{-0.017000001,-0.0168433},
												1
											},
											
											{
												{-0.0099999998,-0.0168433},
												1
											},
											{},
											
											{
												{0.017000001,-0.0168433},
												1
											},
											
											{
												{0.0099999998,-0.0168433},
												1
											},
											{},
											
											{
												{-0.017000001,-0.0168433},
												1
											},
											
											{
												{-0.017000001,-0.0099078296},
												1
											},
											{},
											
											{
												{0.017000001,-0.0168433},
												1
											},
											
											{
												{0.017000001,-0.0099078296},
												1
											},
											{},
											
											{
												{-0.017000001,0.0168433},
												1
											},
											
											{
												{-0.0099999998,0.0168433},
												1
											},
											{},
											
											{
												{0.017000001,0.0168433},
												1
											},
											
											{
												{0.0099999998,0.0168433},
												1
											},
											{},
											
											{
												{-0.017000001,0.0168433},
												1
											},
											
											{
												{-0.017000001,0.0099078296},
												1
											},
											{},
											
											{
												{0.017000001,0.0168433},
												1
											},
											
											{
												{0.017000001,0.0099078296},
												1
											},
											{}
										};
									};
								};
								class assignedTarget: markedTarget
								{
									color[]={1,0,0};
									class TargetLines: TargetLines
									{
									};
								};
								class target
								{
									color[]={1,0.30000001,0};
									class TargetLines
									{
										type="polygon";
										points[]=
										{
											
											{
												
												{
													{-0.0099999998,-0.0099999998},
													1
												},
												
												{
													{0,-0.0099999998},
													1
												},
												
												{
													{0,0},
													1
												},
												
												{
													{-0.0099999998,0},
													1
												}
											}
										};
									};
								};
								class targetFriendly: target
								{
									color[]={0,1,0};
									class TargetLines: TargetLines
									{
									};
								};
								class targetEnemy: target
								{
									color[]={1,0,0};
									class TargetLines: TargetLines
									{
									};
								};
								class targetGroup: target
								{
									color[]={1,0,0};
									class TargetLines: TargetLines
									{
									};
								};
								class targetDestroyed
								{
								};
								class targetGround: target
								{
									class TargetLines: TargetLines
									{
										type="polygon";
										points[]=
										{
											
											{
												
												{
													{-0.0099999998,-0.0099999998},
													1
												},
												
												{
													{0.015,-0.0099999998},
													1
												},
												
												{
													{0.015,0},
													1
												},
												
												{
													{-0.0099999998,0},
													1
												}
											},
											
											{
												
												{
													{-0.0070000002,-0.017999999},
													1
												},
												
												{
													{-0.0020000001,-0.017999999},
													1
												},
												
												{
													{-0.0020000001,0.0070000002},
													1
												},
												
												{
													{-0.0070000002,0.0070000002},
													1
												}
											},
											
											{
												
												{
													{0.0070000002,-0.017999999},
													1
												},
												
												{
													{0.012,-0.017999999},
													1
												},
												
												{
													{0.012,0.0070000002},
													1
												},
												
												{
													{0.0070000002,0.0070000002},
													1
												}
											}
										};
									};
								};
								class targetGroundFriendly: targetGround
								{
									color[]={0,1,0};
									class TargetLines: TargetLines
									{
									};
								};
								class targetGroundEnemy: targetGround
								{
									color[]={1,0,0};
									class TargetLines: TargetLines
									{
									};
								};
								class targetGroundGroup: targetGround
								{
									color[]={1,0,0};
									class TargetLines: TargetLines
									{
									};
								};
								class targetGroundDestroyed
								{
								};
								class targetGroundRemote: target
								{
									class TargetLines: TargetLines
									{
									};
								};
								class targetGroundRemoteFriendly: targetGroundRemote
								{
									color[]={0,1,0};
									class TargetLines: TargetLines
									{
									};
								};
								class targetGroundRemoteEnemy: targetGroundRemote
								{
									color[]={1,0,0};
									class TargetLines: TargetLines
									{
									};
								};
								class targetGroundRemoteGroup: targetGroundRemote
								{
									color[]={1,0,0};
									class TargetLines: TargetLines
									{
									};
								};
								class targetGroundRemoteDestroyed
								{
								};
								class targetLaser: target
								{
									class TargetLines: TargetLines
									{
										type="line";
										width=4;
										points[]=
										{
											
											{
												{0,-0.0198157},
												1
											},
											
											{
												{-1.74846e-009,0.0198157},
												1
											},
											{},
											
											{
												{0.02,8.6617002e-010},
												1
											},
											
											{
												{-0.02,-2.3629901e-010},
												1
											},
											{},
											
											{
												{0.0106066,-0.0105088},
												1
											},
											
											{
												{-0.0106066,0.0105088},
												1
											},
											{},
											
											{
												{0.0106066,0.0105088},
												1
											},
											
											{
												{-0.0106066,-0.0105088},
												1
											},
											{}
										};
									};
								};
								class targetLaserFriendly: targetLaser
								{
									color[]={0,1,0};
									class TargetLines: TargetLines
									{
									};
								};
								class targetLaserEnemy: targetLaser
								{
									color[]={1,0,0};
									class TargetLines: TargetLines
									{
									};
								};
								class targetLaserGroup: targetLaser
								{
									color[]={1,0,0};
									class TargetLines: TargetLines
									{
									};
								};
								class targetNVG: targetLaser
								{
									class TargetLines: TargetLines
									{
									};
								};
								class targetNVGFriendly: targetNVG
								{
									color[]={0,1,0};
									class TargetLines: TargetLines
									{
									};
								};
								class targetNVGEnemy: targetNVG
								{
									color[]={1,0,0};
									class TargetLines: TargetLines
									{
									};
								};
								class targetNVGGroup: targetNVG
								{
									color[]={1,0,0};
									class TargetLines: TargetLines
									{
									};
								};
								class targetMan: target
								{
									class TargetLines: TargetLines
									{
									};
								};
								class targetManFriendly: targetMan
								{
									color[]={0,1,0};
									class TargetLines: TargetLines
									{
									};
								};
								class targetManEnemy: targetMan
								{
									color[]={1,0,0};
									class TargetLines: TargetLines
									{
									};
								};
								class targetManGroup: targetMan
								{
									color[]={1,0,0};
									class TargetLines: TargetLines
									{
									};
								};
								class targetManRemote: target
								{
									class TargetLines: TargetLines
									{
									};
								};
								class targetManRemoteFriendly: targetManRemote
								{
									color[]={0,1,0};
									class TargetLines: TargetLines
									{
									};
								};
								class targetManRemoteEnemy: targetManRemote
								{
									color[]={1,0,0};
									class TargetLines: TargetLines
									{
									};
								};
								class targetManRemoteGroup: targetManRemote
								{
									color[]={1,0,0};
									class TargetLines: TargetLines
									{
									};
								};
								class targetAir
								{
									color[]={1,1,1};
									class TargetLines
									{
										type="polygon";
										points[]=
										{
											
											{
												
												{
													{0,0},
													1
												},
												
												{
													{0.0099999998,0.015},
													1
												},
												
												{
													{-0.0099999998,0.015},
													1
												}
											},
											
											{
												
												{
													{0,0},
													1
												},
												
												{
													{0.0099999998,-0.015},
													1
												},
												
												{
													{-0.0099999998,-0.015},
													1
												}
											}
										};
									};
								};
								class targetAirFriendly: targetAir
								{
									color[]={0,1,0};
									class TargetLines: TargetLines
									{
									};
								};
								class targetAirEnemy: targetAir
								{
									color[]={1,0,0};
									class TargetLines: TargetLines
									{
									};
								};
								class targetAirGroup: targetAir
								{
									color[]={1,0,0};
									class TargetLines: TargetLines
									{
									};
								};
								class targetAirDestroyed
								{
								};
								class targetAirRemote: targetAir
								{
									color[]={1,1,1};
									class TargetLines: TargetLines
									{
									};
								};
								class targetAirRemoteFriendly: targetAirRemote
								{
									color[]={0,1,0};
									class TargetLines: TargetLines
									{
									};
								};
								class targetAirRemoteEnemy: targetAirRemote
								{
									color[]={1,0,0};
									class TargetLines: TargetLines
									{
									};
								};
								class targetAirRemoteGroup: targetAirRemote
								{
									color[]={1,0,0};
									class TargetLines: TargetLines
									{
									};
								};
								class targetAirRemoteDestroyed
								{
								};
							};
						};
					};
					class RadarGroup
					{
						condition="activeSensorsOn";
						class RadarGround
						{
							condition="1";
							class TransText
							{
								type="text";
								source="static";
								text="FCR/G";
								scale=1;
								sourceScale=1;
								align="right";
								pos[]=
								{
									
									{
										"0.1-0.02",
										0.92000002
									},
									1
								};
								right[]=
								{
									{0.107,0.92000002},
									1
								};
								down[]=
								{
									
									{
										"0.1-0.02",
										0.94700003
									},
									1
								};
							};
							class DrawLines
							{
								type="line";
								width=4;
								points[]=
								{
									
									{
										"Static_Offset2",
										1,
										
										{
											"FCR_ScanLine_Bottom",
											0,
											-0.0198157
										},
										1
									},
									
									{
										"Static_Offset2",
										1,
										
										{
											"FCR_ScanLine_Bottom",
											0,
											-0.29128999
										},
										1
									},
									{},
									
									{
										"Static_Offset2",
										1,
										
										{
											"FCR_ScanLine_Top",
											0,
											-0.29128999
										},
										1
									},
									
									{
										"Static_Offset2",
										1,
										
										{
											"FCR_ScanLine_Top",
											0,
											-0.485484
										},
										1
									},
									{}
								};
							};
						};
						class AutoRange
						{
							condition="targetDist>=1";
							class RangeText
							{
								type="text";
								source="static";
								text="R";
								scale=1;
								sourceScale=1;
								align="right";
								pos[]=
								{
									
									{
										"0.26-0.05",
										0.92000002
									},
									1
								};
								right[]=
								{
									{0.237,0.92000002},
									1
								};
								down[]=
								{
									
									{
										"0.26-0.05",
										0.94700003
									},
									1
								};
							};
							class RangeSource
							{
								type="text";
								source="targetDist";
								sourceScale=0.001;
								sourceLength=2;
								sourcePrecision=1;
								refreshRate=0.1;
								align="right";
								scale=1;
								pos[]=
								{
									
									{
										"0.29-0.05",
										"0.86+0.06"
									},
									1
								};
								right[]=
								{
									
									{
										0.26699999,
										"0.86+0.06"
									},
									1
								};
								down[]=
								{
									
									{
										"0.29-0.05",
										0.94700003
									},
									1
								};
							};
						};
						class LaserRange
						{
							condition="targetDist<=0.99";
							class RangeText
							{
								type="text";
								source="static";
								text="*";
								scale=1;
								sourceScale=1;
								align="right";
								pos[]=
								{
									
									{
										"0.26-0.05",
										0.92000002
									},
									1
								};
								right[]=
								{
									{0.237,0.92000002},
									1
								};
								down[]=
								{
									
									{
										"0.26-0.05",
										0.94700003
									},
									1
								};
							};
							class SpeedSource
							{
								type="text";
								source="laserDist";
								sourceScale=1;
								sourceLength=4;
								refreshRate=0.1;
								align="right";
								scale=1;
								pos[]=
								{
									
									{
										"0.29-0.05",
										"0.86+0.06"
									},
									1
								};
								right[]=
								{
									
									{
										0.26699999,
										"0.86+0.06"
									},
									1
								};
								down[]=
								{
									
									{
										"0.29-0.05",
										0.94700003
									},
									1
								};
							};
						};
					};
					class TADSGroup
					{
						condition="1-activeSensorsOn";
						class TransText
						{
							type="text";
							source="static";
							text="TADS";
							scale=1;
							sourceScale=1;
							align="right";
							pos[]=
							{
								
								{
									"0.1-0.02",
									0.92000002
								},
								1
							};
							right[]=
							{
								{0.107,0.92000002},
								1
							};
							down[]=
							{
								
								{
									"0.1-0.02",
									0.94700003
								},
								1
							};
						};
						class AutoRange
						{
							condition="targetDist>=1";
							class RangeText
							{
								type="text";
								source="static";
								text="A";
								scale=1;
								sourceScale=1;
								align="right";
								pos[]=
								{
									
									{
										"0.26-0.05",
										0.92000002
									},
									1
								};
								right[]=
								{
									{0.237,0.92000002},
									1
								};
								down[]=
								{
									
									{
										"0.26-0.05",
										0.94700003
									},
									1
								};
							};
							class RangeSource
							{
								type="text";
								source="targetDist";
								sourceScale=0.001;
								sourceLength=2;
								sourcePrecision=1;
								refreshRate=0.1;
								align="right";
								scale=1;
								pos[]=
								{
									
									{
										"0.29-0.05",
										"0.86+0.06"
									},
									1
								};
								right[]=
								{
									
									{
										0.26699999,
										"0.86+0.06"
									},
									1
								};
								down[]=
								{
									
									{
										"0.29-0.05",
										0.94700003
									},
									1
								};
							};
						};
						class LaserRange
						{
							condition="targetDist<=0.99";
							class RangeText
							{
								type="text";
								source="static";
								text="*";
								scale=1;
								sourceScale=1;
								align="right";
								pos[]=
								{
									
									{
										"0.26-0.05",
										0.92000002
									},
									1
								};
								right[]=
								{
									{0.237,0.92000002},
									1
								};
								down[]=
								{
									
									{
										"0.26-0.05",
										0.94700003
									},
									1
								};
							};
							class SpeedSource
							{
								type="text";
								source="laserDist";
								sourceScale=1;
								sourceLength=4;
								refreshRate=0.1;
								align="right";
								scale=1;
								pos[]=
								{
									
									{
										"0.29-0.05",
										"0.86+0.06"
									},
									1
								};
								right[]=
								{
									
									{
										0.26699999,
										"0.86+0.06"
									},
									1
								};
								down[]=
								{
									
									{
										"0.29-0.05",
										0.94700003
									},
									1
								};
							};
						};
					};
					class MGun
					{
						condition="mgun";
						class RangeText
						{
							type="text";
							source="static";
							text="P GUN";
							scale=1;
							sourceScale=1;
							align="right";
							pos[]=
							{
								
								{
									"0.61+0.05",
									0.92000002
								},
								1
							};
							right[]=
							{
								{0.68699998,0.92000002},
								1
							};
							down[]=
							{
								
								{
									"0.61+0.05",
									0.94700003
								},
								1
							};
						};
						class Weapons
						{
							type="text";
							source="weapon";
							text="GUN";
							sourceScale=1;
							align="right";
							scale=0.5;
							pos[]=
							{
								
								{
									"0.61+0.05",
									"0.90+0.055"
								},
								1
							};
							right[]=
							{
								
								{
									0.68699998,
									"0.90+0.055"
								},
								1
							};
							down[]=
							{
								
								{
									"0.61+0.05",
									0.98199999
								},
								1
							};
						};
						class Ammo
						{
							type="text";
							source="ammo";
							sourceScale=1;
							align="left";
							scale=0.5;
							pos[]=
							{
								
								{
									"0.85+0.05",
									"0.86+0.06"
								},
								1
							};
							right[]=
							{
								
								{
									0.92699999,
									"0.86+0.06"
								},
								1
							};
							down[]=
							{
								
								{
									"0.85+0.05",
									0.94700003
								},
								1
							};
						};
					};
					class AAMissile
					{
						condition="bomb";
						class ModeText
						{
							type="text";
							source="static";
							text="P ATA";
							scale=1;
							sourceScale=1;
							align="right";
							pos[]=
							{
								
								{
									"0.61+0.05",
									0.92000002
								},
								1
							};
							right[]=
							{
								{0.68699998,0.92000002},
								1
							};
							down[]=
							{
								
								{
									"0.61+0.05",
									0.94700003
								},
								1
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
								
								{
									"0.61+0.05",
									"0.90+0.055"
								},
								1
							};
							right[]=
							{
								
								{
									0.68699998,
									"0.90+0.055"
								},
								1
							};
							down[]=
							{
								
								{
									"0.61+0.05",
									0.98199999
								},
								1
							};
						};
					};
					class ATMissile
					{
						condition="ATmissile + AAmissile";
						class ModeText
						{
							type="text";
							source="static";
							text="P MSL";
							scale=1;
							sourceScale=1;
							align="right";
							pos[]=
							{
								
								{
									"0.61+0.05",
									0.92000002
								},
								1
							};
							right[]=
							{
								{0.68699998,0.92000002},
								1
							};
							down[]=
							{
								
								{
									"0.61+0.05",
									0.94700003
								},
								1
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
								
								{
									"0.61+0.05",
									"0.90+0.055"
								},
								1
							};
							right[]=
							{
								
								{
									0.68699998,
									"0.90+0.055"
								},
								1
							};
							down[]=
							{
								
								{
									"0.61+0.05",
									0.98199999
								},
								1
							};
						};
					};
					class Rockets
					{
						condition="rocket";
						class ModeText
						{
							type="text";
							source="static";
							text="P RKT";
							scale=1;
							sourceScale=1;
							align="right";
							pos[]=
							{
								
								{
									"0.61+0.05",
									0.92000002
								},
								1
							};
							right[]=
							{
								{0.68699998,0.92000002},
								1
							};
							down[]=
							{
								
								{
									"0.61+0.05",
									0.94700003
								},
								1
							};
						};
						class AmmoName
						{
							type="text";
							source="ammoFormat";
							sourceScale=1;
							align="right";
							scale=0.5;
							pos[]=
							{
								
								{
									"0.61+0.05",
									"0.90+0.055"
								},
								1
							};
							right[]=
							{
								
								{
									0.68699998,
									"0.90+0.055"
								},
								1
							};
							down[]=
							{
								
								{
									"0.61+0.05",
									0.98199999
								},
								1
							};
						};
					};
				};
			};
		};
		radarTargetSize=0.89999998;
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				class MFD
				{
					class MFD_Pilot_10
					{
						topLeft="MFD_10_TL";
						topRight="MFD_10_TR";
						bottomLeft="MFD_10_BL";
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
					class MFD_Pilot_8
					{
						topLeft="MFD_8_TL";
						topRight="MFD_8_TR";
						bottomLeft="MFD_8_BL";
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
						turret[]={-2};
						class Bones
						{
						};
						class Draw
						{
							alpha=1;
							color[]={0,0.12,0};
							condition="on";
							class Time
							{
								type="text";
								source="time";
								text="%X";
								sourceScale=1;
								align="right";
								scale=1;
								pos[]=
								{
									{0.029999999,0.11},
									1
								};
								right[]=
								{
									{0.13,0.11},
									1
								};
								down[]=
								{
									{0.029999999,0.2},
									1
								};
							};
							class Fuel
							{
								type="text";
								source="fuel";
								text="%X";
								sourceScale=2517;
								sourceLength=4;
								align="right";
								scale=1;
								pos[]=
								{
									{0.029999999,0.31},
									1
								};
								right[]=
								{
									{0.13,0.31},
									1
								};
								down[]=
								{
									{0.029999999,0.40000001},
									1
								};
							};
							class LBSText
							{
								type="text";
								source="static";
								text="LBS";
								scale=1;
								sourceScale=1;
								align="right";
								pos[]=
								{
									{0.30000001,0.31},
									1
								};
								right[]=
								{
									{0.40000001,0.31},
									1
								};
								down[]=
								{
									{0.30000001,0.40000001},
									1
								};
							};
							class GridX
							{
								type="text";
								source="coordinateX";
								sourceScale=0.0099999998;
								sourceOffset=-0.5;
								sourceLength=3;
								align="right";
								scale=1;
								pos[]=
								{
									{0.029999999,0.61000001},
									1
								};
								right[]=
								{
									{0.13,0.61000001},
									1
								};
								down[]=
								{
									{0.029999999,0.69999999},
									1
								};
							};
							class GridY: GridX
							{
								source="coordinateY";
								pos[]=
								{
									{0.23999999,0.61000001},
									1
								};
								right[]=
								{
									{0.34,0.61000001},
									1
								};
								down[]=
								{
									{0.23999999,0.69999999},
									1
								};
							};
							class GridText
							{
								type="text";
								source="static";
								text="GRID:";
								scale=1;
								sourceScale=1;
								align="right";
								pos[]=
								{
									{0.029999999,0.50999999},
									1
								};
								right[]=
								{
									{0.13,0.50999999},
									1
								};
								down[]=
								{
									{0.029999999,0.60000002},
									1
								};
							};
						};
					};
					class MFD_Pilot_9
					{
						topLeft="MFD_9_TL";
						topRight="MFD_9_TR";
						bottomLeft="MFD_9_BL";
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
						turret[]={-2};
						class Bones
						{
						};
						class Draw
						{
							alpha=1;
							color[]={0,0.12,0};
							condition="on";
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
										{0.22,0.2},
										1
									};
									right[]=
									{
										{0.28,0.2},
										1
									};
									down[]=
									{
										{0.22,0.23999999},
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
										{0.22,0.2},
										1
									};
									right[]=
									{
										{0.28,0.2},
										1
									};
									down[]=
									{
										{0.22,0.23999999},
										1
									};
								};
							};
							class SpeedNumber
							{
								type="text";
								source="speed";
								sourceScale=3.5999999;
								align="left";
								scale=1;
								pos[]=
								{
									{0.28,0.45199999},
									1
								};
								right[]=
								{
									{0.31999999,0.45199999},
									1
								};
								down[]=
								{
									{0.28,0.49200001},
									1
								};
							};
							class AltNumber
							{
								type="text";
								source="altitudeAGL";
								sourceScale=1;
								sourceOffset=-2;
								align="left";
								scale=1;
								pos[]=
								{
									{0.75,0.45199999},
									1
								};
								right[]=
								{
									{0.79000002,0.45199999},
									1
								};
								down[]=
								{
									{0.75,0.49200001},
									1
								};
							};
							class CruiseMode
							{
								condition="1+((altitudeASL-27) min 1) - autohover";
								class AltNumberASL
								{
									type="text";
									source="altitudeASL";
									sourceScale=1;
									align="left";
									scale=1;
									pos[]=
									{
										{0.81,0.16},
										1
									};
									right[]=
									{
										{0.85000002,0.16},
										1
									};
									down[]=
									{
										{0.81,0.2},
										1
									};
								};
							};
						};
					};
					class MFD_Pilot_11: MFD_Pilot_10
					{
						topLeft="MFD_11_TL";
						topRight="MFD_11_TR";
						bottomLeft="MFD_11_BL";
						turret[]={0};
						class Draw
						{
							color[]={0,0.12,0};
							condition="on";
							class BlackBackgroundGroup
							{
								color[]={0,0,0};
								class BlackBackground
								{
									type="polygon";
									points[]=
									{
										
										{
											
											{
												{0,0.1},
												1
											},
											
											{
												{1,0.1},
												1
											},
											
											{
												{1,1},
												1
											},
											
											{
												{0,1},
												1
											}
										}
									};
								};
							};
							class ReticleGroup
							{
								color[]={0,0.12,0};
								class Reticle
								{
									type="line";
									width=4;
									points[]=
									{
										
										{
											{0.43000001,0.49059799},
											1
										},
										
										{
											{0.164,0.49059799},
											1
										},
										
										{
											{0.164,0.49059799},
											1
										},
										
										{
											{0.164,0.630171},
											1
										},
										
										{
											{0.164,0.630171},
											1
										},
										
										{
											{0.43799999,0.630171},
											1
										},
										
										{
											{0.43799999,0.630171},
											1
										},
										
										{
											{0.43799999,0.73239303},
											1
										},
										
										{
											{0.62199998,0.73239303},
											1
										},
										
										{
											{0.62199998,0.630171},
											1
										},
										
										{
											{0.62199998,0.630171},
											1
										},
										
										{
											{0.898,0.630171},
											1
										},
										
										{
											{0.898,0.630171},
											1
										},
										
										{
											{0.898,0.49059799},
											1
										},
										
										{
											{0.63,0.49059799},
											1
										},
										
										{
											{0.63,0.49059799},
											1
										},
										
										{
											{0.616,0.48273501},
											1
										},
										
										{
											{0.616,0.29794899},
											1
										},
										
										{
											{0.59200001,0.29794899},
											1
										},
										
										{
											{0.55800003,0.286154},
											1
										},
										
										{
											{0.55800003,0.27239299},
											1
										},
										
										{
											{0.5,0.27239299},
											1
										},
										
										{
											{0.5,0.286154},
											1
										},
										
										{
											{0.46799999,0.29794899},
											1
										},
										
										{
											{0.44600001,0.29794899},
											1
										},
										
										{
											{0.44600001,0.48273501},
											1
										},
										
										{
											{0.43000001,0.49059799},
											1
										},
										{},
										
										{
											{0.46000001,0.60000002},
											1
										},
										
										{
											{0.60000002,0.60000002},
											1
										},
										
										{
											{0.60000002,0.72000003},
											1
										},
										
										{
											{0.46000001,0.72000003},
											1
										},
										
										{
											{0.46000001,0.60000002},
											1
										},
										{},
										
										{
											{0.039999999,0.80000001},
											1
										},
										
										{
											{0.23999999,0.80000001},
											1
										},
										
										{
											{0.23999999,0.86000001},
											1
										},
										
										{
											{0.039999999,0.86000001},
											1
										},
										
										{
											{0.039999999,0.80000001},
											1
										},
										{},
										
										{
											{-0.059999999,0.82999998},
											1
										},
										
										{
											{0.039999999,0.82999998},
											1
										},
										{},
										
										{
											{0.039999999,0.93000001},
											1
										},
										
										{
											{0.23999999,0.93000001},
											1
										},
										
										{
											{0.23999999,0.99000001},
											1
										},
										
										{
											{0.039999999,0.99000001},
											1
										},
										
										{
											{0.039999999,0.93000001},
											1
										},
										{},
										
										{
											{-0.059999999,0.95999998},
											1
										},
										
										{
											{0.039999999,0.95999998},
											1
										},
										{},
										
										{
											{0.27000001,0.86000001},
											1
										},
										
										{
											{0.82999998,0.86000001},
											1
										},
										
										{
											{0.82999998,0.98000002},
											1
										},
										
										{
											{0.27000001,0.98000002},
											1
										},
										
										{
											{0.27000001,0.86000001},
											1
										},
										{},
										
										{
											{0.23,0.18000001},
											1
										},
										
										{
											{0.37,0.18000001},
											1
										},
										
										{
											{0.37,0.25999999},
											1
										},
										
										{
											{0.23,0.25999999},
											1
										},
										
										{
											{0.23,0.18000001},
											1
										},
										{},
										
										{
											{0.69999999,0.18000001},
											1
										},
										
										{
											{0.83999997,0.18000001},
											1
										},
										
										{
											{0.83999997,0.25999999},
											1
										},
										
										{
											{0.69999999,0.25999999},
											1
										},
										
										{
											{0.69999999,0.18000001},
											1
										},
										{},
										
										{
											{0.23999999,0.28999999},
											1
										},
										
										{
											{0.36000001,0.28999999},
											1
										},
										
										{
											{0.36000001,0.37},
											1
										},
										
										{
											{0.23999999,0.37},
											1
										},
										
										{
											{0.23999999,0.28999999},
											1
										},
										{},
										
										{
											{0.70999998,0.28999999},
											1
										},
										
										{
											{0.82999998,0.28999999},
											1
										},
										
										{
											{0.82999998,0.37},
											1
										},
										
										{
											{0.70999998,0.37},
											1
										},
										
										{
											{0.70999998,0.28999999},
											1
										}
									};
								};
								class SightSelect1
								{
									type="text";
									source="static";
									text="SIGHT";
									scale=1;
									sourceScale=1;
									align="right";
									pos[]=
									{
										
										{
											"0.53-0.29",
											0.18700001
										},
										1
									};
									right[]=
									{
										{0.28,0.18700001},
										1
									};
									down[]=
									{
										
										{
											"0.53-0.29",
											0.222
										},
										1
									};
								};
								class SightSelect2
								{
									type="text";
									source="static";
									text="FCR";
									scale=1;
									sourceScale=1;
									align="right";
									pos[]=
									{
										
										{
											"0.53-0.29",
											0.227
										},
										1
									};
									right[]=
									{
										{0.28,0.227},
										1
									};
									down[]=
									{
										
										{
											"0.53-0.29",
											0.26199999
										},
										1
									};
								};
								class AcqSelect1
								{
									type="text";
									source="static";
									text="ACQ";
									scale=1;
									sourceScale=1;
									align="left";
									pos[]=
									{
										
										{
											"0.53+0.29",
											0.18700001
										},
										1
									};
									right[]=
									{
										{0.86000001,0.18700001},
										1
									};
									down[]=
									{
										
										{
											"0.53+0.29",
											0.222
										},
										1
									};
								};
								class AcqSelect2
								{
									type="text";
									source="static";
									text="FCR";
									scale=1;
									sourceScale=1;
									align="left";
									pos[]=
									{
										
										{
											"0.53+0.29",
											0.227
										},
										1
									};
									right[]=
									{
										{0.86000001,0.227},
										1
									};
									down[]=
									{
										
										{
											"0.53+0.29",
											0.26199999
										},
										1
									};
								};
								class LSTSelect1
								{
									type="text";
									source="static";
									text="LST";
									scale=1;
									sourceScale=1;
									align="center";
									pos[]=
									{
										
										{
											"0.53-0.23",
											0.29699999
										},
										1
									};
									right[]=
									{
										{0.34,0.29699999},
										1
									};
									down[]=
									{
										
										{
											"0.53-0.23",
											0.33199999
										},
										1
									};
								};
								class LSTSelect2
								{
									type="text";
									source="static";
									text="A";
									scale=1;
									sourceScale=1;
									align="center";
									pos[]=
									{
										
										{
											"0.53-0.23",
											0.33700001
										},
										1
									};
									right[]=
									{
										{0.34,0.33700001},
										1
									};
									down[]=
									{
										
										{
											"0.53-0.23",
											0.37200001
										},
										1
									};
								};
								class LRFDSelect1
								{
									type="text";
									source="static";
									text="LRFD";
									scale=1;
									sourceScale=1;
									align="center";
									pos[]=
									{
										
										{
											"0.53+0.24",
											0.29699999
										},
										1
									};
									right[]=
									{
										{0.81,0.29699999},
										1
									};
									down[]=
									{
										
										{
											"0.53+0.24",
											0.33199999
										},
										1
									};
								};
								class LRFDSelect2
								{
									type="text";
									source="static";
									text="B";
									scale=1;
									sourceScale=1;
									align="center";
									pos[]=
									{
										
										{
											"0.53+0.24",
											0.33700001
										},
										1
									};
									right[]=
									{
										{0.81,0.33700001},
										1
									};
									down[]=
									{
										
										{
											"0.53+0.24",
											0.37200001
										},
										1
									};
								};
								class PilotText
								{
									type="text";
									source="static";
									text="PILOT";
									scale=1;
									sourceScale=1;
									align="right";
									pos[]=
									{
										
										{
											"0.53-0.48",
											0.815
										},
										1
									};
									right[]=
									{
										{0.090000004,0.815},
										1
									};
									down[]=
									{
										
										{
											"0.53-0.48",
											0.85000002
										},
										1
									};
								};
								class CopilotText
								{
									type="text";
									source="static";
									text="COPILOT";
									scale=1;
									sourceScale=1;
									align="right";
									pos[]=
									{
										
										{
											"0.53-0.48",
											0.94499999
										},
										1
									};
									right[]=
									{
										{0.090000004,0.94499999},
										1
									};
									down[]=
									{
										
										{
											"0.53-0.48",
											0.98000002
										},
										1
									};
								};
								class PylonText6
								{
									type="text";
									source="static";
									text="#6";
									scale=1;
									sourceScale=1;
									align="center";
									pos[]=
									{
										
										{
											"0.53-0.31 + 0.00",
											0.55000001
										},
										1
									};
									right[]=
									{
										{0.25999999,0.55000001},
										1
									};
									down[]=
									{
										
										{
											"0.53-0.31 + 0.00",
											0.58499998
										},
										1
									};
								};
								class PylonText5
								{
									type="text";
									source="static";
									text="#5";
									scale=1;
									sourceScale=1;
									align="center";
									pos[]=
									{
										
										{
											"0.53-0.31 + 0.09",
											0.55000001
										},
										1
									};
									right[]=
									{
										{0.34999999,0.55000001},
										1
									};
									down[]=
									{
										
										{
											"0.53-0.31 + 0.09",
											0.58499998
										},
										1
									};
								};
								class PylonText4
								{
									type="text";
									source="static";
									text="#4";
									scale=1;
									sourceScale=1;
									align="center";
									pos[]=
									{
										
										{
											"0.53-0.31 + 0.09*2",
											0.55000001
										},
										1
									};
									right[]=
									{
										{0.44,0.55000001},
										1
									};
									down[]=
									{
										
										{
											"0.53-0.31 + 0.09*2",
											0.58499998
										},
										1
									};
								};
								class PylonText3
								{
									type="text";
									source="static";
									text="#3";
									scale=1;
									sourceScale=1;
									align="center";
									pos[]=
									{
										
										{
											"0.53+0.31 - 0.09*2",
											0.55000001
										},
										1
									};
									right[]=
									{
										{0.69999999,0.55000001},
										1
									};
									down[]=
									{
										
										{
											"0.53+0.31 - 0.09*2",
											0.58499998
										},
										1
									};
								};
								class PylonText2
								{
									type="text";
									source="static";
									text="#2";
									scale=1;
									sourceScale=1;
									align="center";
									pos[]=
									{
										
										{
											"0.53+0.31 - 0.09",
											0.55000001
										},
										1
									};
									right[]=
									{
										{0.79000002,0.55000001},
										1
									};
									down[]=
									{
										
										{
											"0.53+0.31 - 0.09",
											0.58499998
										},
										1
									};
								};
								class PylonText1
								{
									type="text";
									source="static";
									text="#1";
									scale=1;
									sourceScale=1;
									align="center";
									pos[]=
									{
										
										{
											"0.53+0.31 - 0.00",
											0.55000001
										},
										1
									};
									right[]=
									{
										{0.88,0.55000001},
										1
									};
									down[]=
									{
										
										{
											"0.53+0.31 - 0.00",
											0.58499998
										},
										1
									};
								};
								class CurrentWeaponText
								{
									type="text";
									source="static";
									text="CURRENT WEAPON";
									scale=1;
									sourceScale=1;
									align="center";
									pos[]=
									{
										{0.55000001,0.81999999},
										1
									};
									right[]=
									{
										{0.58999997,0.81999999},
										1
									};
									down[]=
									{
										{0.55000001,0.85500002},
										1
									};
								};
								class Weapons
								{
									type="text";
									source="weapon";
									sourceScale=1;
									align="center";
									scale=1;
									pos[]=
									{
										{0.55000001,0.87},
										1
									};
									right[]=
									{
										{0.58999997,0.87},
										1
									};
									down[]=
									{
										{0.55000001,0.90499997},
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
										{0.55000001,0.92000002},
										1
									};
									right[]=
									{
										{0.58999997,0.92000002},
										1
									};
									down[]=
									{
										{0.55000001,0.95499998},
										1
									};
								};
							};
							class MGun
							{
								class Default
								{
									condition="ammo0 > 0";
									color[]={0,0.12,0};
									class Shape
									{
										type="line";
										width=4;
										points[]=
										{
											
											{
												{0.55599999,0.38641},
												1
											},
											
											{
												{0.50199997,0.38641},
												1
											},
											
											{
												{0.458,0.38641},
												1
											},
											
											{
												{0.458,0.44931599},
												1
											},
											
											{
												{0.60000002,0.44931599},
												1
											},
											
											{
												{0.60000002,0.38641},
												1
											},
											
											{
												{0.55599999,0.38641},
												1
											},
											{},
											
											{
												{0.50199997,0.38641},
												1
											},
											
											{
												{0.50199997,0.32547},
												1
											},
											
											{
												{0.52200001,0.32547},
												1
											},
											
											{
												{0.52200001,0.284188},
												1
											},
											
											{
												{0.54000002,0.284188},
												1
											},
											
											{
												{0.54000002,0.327436},
												1
											},
											
											{
												{0.55599999,0.327436},
												1
											},
											
											{
												{0.55599999,0.38641},
												1
											},
											
											{
												{0.50199997,0.38641},
												1
											}
										};
									};
									class Ammo
									{
										type="text";
										source="ammo";
										sourceIndex=0;
										sourceScale=1;
										sourceLength=4;
										align="center";
										scale=1;
										pos[]=
										{
											{0.52999997,0.41},
											1
										};
										right[]=
										{
											{0.56999999,0.41},
											1
										};
										down[]=
										{
											{0.52999997,0.44499999},
											1
										};
									};
								};
								class Selected: Default
								{
									condition="(mgun +  (ammo0 min 1))/2";
									color[]={0.99000001,0.94,0.58999997};
									class Shape: Shape
									{
									};
									class Ammo: Ammo
									{
									};
								};
								class Empty: Default
								{
									condition="ammo0 <= 0";
									color[]={1,0,0,1};
									class Shape: Shape
									{
									};
									class Ammo: Ammo
									{
										source="static";
										text="EMPTY";
									};
								};
							};
							class Pylon1
							{
								type="pylonicon";
								pos[]=
								{
									{0.81999999,0.5},
									1
								};
								pylon=1;
								name="Heli_Attack_01";
							};
							class Pylon2: Pylon1
							{
								pos[]=
								{
									{0.73000002,0.5},
									1
								};
								pylon=2;
							};
							class Pylon3: Pylon1
							{
								pos[]=
								{
									{0.63999999,0.5},
									1
								};
								pylon=3;
							};
							class Pylon4: Pylon1
							{
								pos[]=
								{
									{0.36000001,0.5},
									1
								};
								pylon=4;
							};
							class Pylon5: Pylon1
							{
								pos[]=
								{
									{0.27000001,0.5},
									1
								};
								pylon=5;
							};
							class Pylon6: Pylon1
							{
								pos[]=
								{
									{0.18000001,0.5},
									1
								};
								pylon=6;
							};
							class ArmBackground
							{
								color[]={0.19,0.039999999,0};
								class BlackBackground
								{
									type="polygon";
									points[]=
									{
										
										{
											
											{
												
												{
													"0.0+0.48",
													"0.0+0.14"
												},
												1
											},
											
											{
												
												{
													"0.1+0.48",
													"0.0+0.14"
												},
												1
											},
											
											{
												
												{
													"0.1+0.48",
													"0.1+0.14"
												},
												1
											},
											
											{
												
												{
													"0.0+0.48",
													"0.1+0.14"
												},
												1
											}
										}
									};
								};
							};
							class BlackText
							{
								color[]={0.15000001,0.0099999998,0};
								class CMText
								{
									type="text";
									source="static";
									text="ARM";
									scale=1;
									sourceScale=1;
									align="center";
									pos[]=
									{
										{0.52999997,0.17},
										1
									};
									right[]=
									{
										{0.56999999,0.17},
										1
									};
									down[]=
									{
										{0.52999997,0.205},
										1
									};
								};
							};
						};
					};
					class MFD_Pilot_11_CM: MFD_Pilot_11
					{
						turret[]={-1};
						class Draw
						{
							color[]={0,0.12,0};
							condition="on";
							class CMText
							{
								type="text";
								source="static";
								text="CM";
								scale=1;
								sourceScale=1;
								align="center";
								pos[]=
								{
									{0.52999997,0.61000001},
									1
								};
								right[]=
								{
									{0.56999999,0.61000001},
									1
								};
								down[]=
								{
									{0.52999997,0.64499998},
									1
								};
							};
							class CMAmmo
							{
								type="text";
								source="cmammo";
								sourceScale=1;
								sourceLength=3;
								align="center";
								scale=1;
								pos[]=
								{
									{0.52999997,0.66000003},
									1
								};
								right[]=
								{
									{0.56999999,0.66000003},
									1
								};
								down[]=
								{
									{0.52999997,0.69499999},
									1
								};
							};
						};
					};
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
						helmetPosition[]={-0.037500001,0.037500001,0.1};
						helmetRight[]={0.075000003,0,0};
						helmetDown[]={0,-0.075000003,0};
						font="LucidaConsoleB";
						turret[]={0};
						class Bones
						{
							class HUDCenter
							{
								type="fixed";
								pos[]={0.5,0.5};
							};
							class WeaponAim
							{
								type="vector";
								source="weapon";
								pos0[]={0.5,0.5};
								pos10[]={0.73400003,0.73000002};
							};
							class WeaponAimRelative: WeaponAim
							{
								source="weapontoview";
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
							class HorizonVector
							{
								type="horizontoview";
								pos0[]={0.5,0.5};
								pos10[]={0.83092302,0.825266};
								angle=0;
							};
							class GunnerAim
							{
								type="vector";
								source="turret";
								pos0[]={0,-2};
								pos10[]={0.0068000001,-0.0099999998};
								projection=0;
							};
							class VerticalSpeedBone
							{
								type="linear";
								source="vspeed";
								sourceScale=1;
								min=-10;
								max=10;
								minPos[]={0,-0.31999999};
								maxPos[]={0,0.31999999};
							};
							class HorizonBankRot
							{
								type="linear";
								source="horizonBank";
								min=-0.52359998;
								max=0.52359998;
								minPos[]={0.41,0.83999997};
								maxPos[]={0.58999997,0.83999997};
								aspectRatio=1;
							};
							class ImpactPoint
							{
								type="vector";
								source="ImpactPointToView";
								pos0[]={0.5,0.5};
								pos10[]={0.73400003,0.73000002};
							};
							class Target
							{
								source="targettoview";
								type="vector";
								pos0[]={0.5,0.5};
								pos10[]={0.73400003,0.73000002};
							};
							class Limit0109
							{
								type="limit";
								limits[]={0.1,0.1,0.89999998,0.89999998};
							};
							class LimitWaypoint
							{
								type="limit";
								limits[]={0.2,0.1,0.80000001,0.1};
							};
							class WPPoint
							{
								type="vector";
								source="WPPoint";
								pos0[]={0.5,0.5};
								pos10[]={0.73400003,0.73000002};
							};
							class WPPointToView: WPPoint
							{
								source="WPPointToView";
							};
							class RadarHeight
							{
								type="linear";
								source="altitudeAGL";
								sourceScale=1;
								sourceOffset=-2;
								min=0;
								max=100;
								minPos[]={0.903,0.18000001};
								maxPos[]={0.903,0.81999999};
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
							alpha=1;
							color[]={0.25,1,0.25};
							condition="on - (cameraHeadingDiffY<=-19) + (abs(cameraHeadingDiffX)>=24)";
							class Static
							{
								type="line";
								width=4;
								points[]=
								{
									
									{
										{0.5,0.11},
										1
									},
									
									{
										{0.5,0.14},
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
										{0.40000001,0.88499999},
										1
									},
									
									{
										{0.40799999,0.88499999},
										1
									},
									{},
									
									{
										{0.60000002,0.88499999},
										1
									},
									
									{
										{0.59200001,0.88499999},
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
										{0.51999998,0.86000001},
										1
									},
									
									{
										{0.51999998,0.81999999},
										1
									},
									{},
									
									{
										{0.47999999,0.86000001},
										1
									},
									
									{
										{0.47999999,0.81999999},
										1
									},
									{},
									
									{
										{0.55000001,0},
										1
									},
									
									{
										{0.55000001,0.039999999},
										1
									},
									
									{
										{0.44999999,0.039999999},
										1
									},
									
									{
										{0.44999999,0},
										1
									},
									
									{
										{0.55000001,0},
										1
									}
								};
							};
							class HeadingNumber
							{
								type="text";
								source="Heading";
								sourceScale=1;
								align="center";
								scale=1;
								pos[]=
								{
									{0.5,0.0060000001},
									1
								};
								right[]=
								{
									{0.55000001,0.0060000001},
									1
								};
								down[]=
								{
									{0.5,0.046},
									1
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
											"0.082-0.025"
										},
										1
									};
									right[]=
									{
										
										{
											"0.83-0.302",
											"0.082-0.025"
										},
										1
									};
									down[]=
									{
										
										{
											"0.80-0.302",
											"0.113-0.025"
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
											{0.47799999,0.045000002},
											1
										},
										
										{
											{0.52200001,0.045000002},
											1
										},
										
										{
											{0.55199999,0.07},
											1
										},
										
										{
											{0.52200001,0.094999999},
											1
										},
										
										{
											{0.47799999,0.094999999},
											1
										},
										
										{
											{0.44800001,0.07},
											1
										},
										
										{
											{0.47799999,0.045000002},
											1
										},
										{}
									};
								};
								class HeadingScaleRight
								{
									clipTL[]={0.55000001,0.050000001};
									clipBR[]={0.82999998,0.11};
									class lines
									{
										type="scale";
										horizontal=1;
										source="heading";
										sourceScale=1;
										width=4;
										top=0.5;
										center=0.5;
										bottom=0.85000002;
										lineXleft=0.11;
										lineYright=0.1;
										lineXleftMajor=0.11;
										lineYrightMajor=0.090000004;
										majorLineEach=2;
										numberEach=2;
										step=22.5;
										stepSize=0.075000003;
										align="center";
										scale=1;
										pos[]={0.49599999,0.050000001};
										right[]={0.53600001,0.050000001};
										down[]={0.49599999,0.090000004};
									};
								};
								class HeadingScaleMidle
								{
									type="scale";
									horizontal=1;
									source="heading";
									sourceScale=1;
									width=4;
									top=0.44999999;
									center=0.5;
									bottom=0.55000001;
									lineXleft=0.11;
									lineYright=0.1;
									lineXleftMajor=0.11;
									lineYrightMajor=0.1;
									majorLineEach=2;
									step=22.5;
									stepSize=0.075000003;
									align="center";
									scale=1;
									numberEach=0;
									pos[]={0.47,0.050000001};
									right[]={0.5,0.050000001};
									down[]={0.44999999,0.090000004};
								};
								class HeadingScaleLeft
								{
									clipTL[]={0.18000001,0.050000001};
									clipBR[]={0.44999999,0.11};
									class lines
									{
										type="scale";
										horizontal=1;
										source="heading";
										sourceScale=1;
										width=4;
										top=0.15000001;
										center=0.5;
										bottom=0.55000001;
										lineXleft=0.11;
										lineYright=0.1;
										lineXleftMajor=0.11;
										lineYrightMajor=0.090000004;
										majorLineEach=2;
										numberEach=2;
										step=22.5;
										stepSize=0.075000003;
										align="center";
										scale=1;
										pos[]={0.146,0.050000001};
										right[]={0.186,0.050000001};
										down[]={0.146,0.090000004};
									};
								};
							};
							class HeadingScaleFull
							{
								condition="5-abs(cameraDir-heading)*( (abs(heading-cameraDir))<=355)";
								class HeadingScale
								{
									clipTL[]={0.18000001,0};
									clipBR[]={0.82999998,1};
									class lines
									{
										type="scale";
										horizontal=1;
										source="heading";
										sourceScale=1;
										width=4;
										top=0.15000001;
										center=0.5;
										bottom=0.85000002;
										lineXleft=0.11;
										lineYright=0.1;
										lineXleftMajor=0.11;
										lineYrightMajor=0.090000004;
										majorLineEach=2;
										numberEach=2;
										step=22.5;
										stepSize=0.075000003;
										align="center";
										scale=1;
										pos[]={0.146,0.050000001};
										right[]={0.186,0.050000001};
										down[]={0.146,0.090000004};
									};
								};
							};
							class HorizonBankRot
							{
								type="polygon";
								width=4;
								points[]=
								{
									
									{
										
										{
											"HorizonBankRot",
											1,
											{0,0},
											1
										},
										
										{
											"HorizonBankRot",
											{0.0026047199,-0.0145196},
											1
										},
										
										{
											"HorizonBankRot",
											{0.0051302998,-0.0138544},
											1
										},
										
										{
											"HorizonBankRot",
											{0.0074999998,-0.0127683},
											1
										}
									},
									
									{
										
										{
											"HorizonBankRot",
											1,
											{0,0},
											1
										},
										
										{
											"HorizonBankRot",
											{0.0074999998,-0.0127683},
											1
										},
										
										{
											"HorizonBankRot",
											{0.0096418103,-0.0112942},
											1
										},
										
										{
											"HorizonBankRot",
											{0.0114907,-0.0094769998},
											1
										}
									},
									
									{
										
										{
											"HorizonBankRot",
											1,
											{0,0},
											1
										},
										
										{
											"HorizonBankRot",
											{0.0114907,-0.0094769998},
											1
										},
										
										{
											"HorizonBankRot",
											{0.0129904,-0.0073717898},
											1
										},
										
										{
											"HorizonBankRot",
											{0.0140954,-0.0050426},
											1
										}
									},
									
									{
										
										{
											"HorizonBankRot",
											1,
											{0,0},
											1
										},
										
										{
											"HorizonBankRot",
											{0.0140954,-0.0050426},
											1
										},
										
										{
											"HorizonBankRot",
											{0.0147721,-0.0025601999},
											1
										},
										
										{
											"HorizonBankRot",
											{0.015,6.4446298e-010},
											1
										}
									},
									
									{
										
										{
											"HorizonBankRot",
											1,
											{0,0},
											1
										},
										
										{
											"HorizonBankRot",
											{0.015,6.4446298e-010},
											1
										},
										
										{
											"HorizonBankRot",
											{0.0147721,0.0025601999},
											1
										},
										
										{
											"HorizonBankRot",
											{0.0140954,0.0050426},
											1
										}
									},
									
									{
										
										{
											"HorizonBankRot",
											1,
											{0,0},
											1
										},
										
										{
											"HorizonBankRot",
											{0.0140954,0.0050426},
											1
										},
										
										{
											"HorizonBankRot",
											{0.0129904,0.0073718},
											1
										},
										
										{
											"HorizonBankRot",
											{0.0114907,0.0094769998},
											1
										}
									},
									
									{
										
										{
											"HorizonBankRot",
											1,
											{0,0},
											1
										},
										
										{
											"HorizonBankRot",
											{0.0114907,0.0094769998},
											1
										},
										
										{
											"HorizonBankRot",
											{0.0096418103,0.0112942},
											1
										},
										
										{
											"HorizonBankRot",
											{0.0074999998,0.0127683},
											1
										}
									},
									
									{
										
										{
											"HorizonBankRot",
											1,
											{0,0},
											1
										},
										
										{
											"HorizonBankRot",
											{0.0074999998,0.0127683},
											1
										},
										
										{
											"HorizonBankRot",
											{0.0051302998,0.0138544},
											1
										},
										
										{
											"HorizonBankRot",
											{0.0026047199,0.0145196},
											1
										}
									},
									
									{
										
										{
											"HorizonBankRot",
											1,
											{0,0},
											1
										},
										
										{
											"HorizonBankRot",
											{0.0026047199,0.0145196},
											1
										},
										
										{
											"HorizonBankRot",
											{-1.31134e-009,0.0147436},
											1
										},
										
										{
											"HorizonBankRot",
											{-0.00260473,0.0145196},
											1
										}
									},
									
									{
										
										{
											"HorizonBankRot",
											1,
											{0,0},
											1
										},
										
										{
											"HorizonBankRot",
											{-0.00260473,0.0145196},
											1
										},
										
										{
											"HorizonBankRot",
											{-0.0051302998,0.0138544},
											1
										},
										
										{
											"HorizonBankRot",
											{-0.0074999998,0.0127683},
											1
										}
									},
									
									{
										
										{
											"HorizonBankRot",
											1,
											{0,0},
											1
										},
										
										{
											"HorizonBankRot",
											{-0.0074999998,0.0127683},
											1
										},
										
										{
											"HorizonBankRot",
											{-0.0096418103,0.0112942},
											1
										},
										
										{
											"HorizonBankRot",
											{-0.0114907,0.0094769998},
											1
										}
									},
									
									{
										
										{
											"HorizonBankRot",
											1,
											{0,0},
											1
										},
										
										{
											"HorizonBankRot",
											{-0.0114907,0.0094769998},
											1
										},
										
										{
											"HorizonBankRot",
											{-0.0129904,0.0073717898},
											1
										},
										
										{
											"HorizonBankRot",
											{-0.0140954,0.0050426},
											1
										}
									},
									
									{
										
										{
											"HorizonBankRot",
											1,
											{0,0},
											1
										},
										
										{
											"HorizonBankRot",
											{-0.0140954,0.0050426},
											1
										},
										
										{
											"HorizonBankRot",
											{-0.0147721,0.0025601999},
											1
										},
										
										{
											"HorizonBankRot",
											{-0.015,-1.75816e-010},
											1
										}
									},
									
									{
										
										{
											"HorizonBankRot",
											1,
											{0,0},
											1
										},
										
										{
											"HorizonBankRot",
											{-0.015,-1.75816e-010},
											1
										},
										
										{
											"HorizonBankRot",
											{-0.0147721,-0.0025601999},
											1
										},
										
										{
											"HorizonBankRot",
											{-0.0140954,-0.0050426},
											1
										}
									},
									
									{
										
										{
											"HorizonBankRot",
											1,
											{0,0},
											1
										},
										
										{
											"HorizonBankRot",
											{-0.0140954,-0.0050426},
											1
										},
										
										{
											"HorizonBankRot",
											{-0.0129904,-0.0073718},
											1
										},
										
										{
											"HorizonBankRot",
											{-0.0114907,-0.0094769998},
											1
										}
									},
									
									{
										
										{
											"HorizonBankRot",
											1,
											{0,0},
											1
										},
										
										{
											"HorizonBankRot",
											{-0.0114907,-0.0094769998},
											1
										},
										
										{
											"HorizonBankRot",
											{-0.0096418103,-0.0112942},
											1
										},
										
										{
											"HorizonBankRot",
											{-0.0074999998,-0.0127683},
											1
										}
									},
									
									{
										
										{
											"HorizonBankRot",
											1,
											{0,0},
											1
										},
										
										{
											"HorizonBankRot",
											{-0.0074999998,-0.0127683},
											1
										},
										
										{
											"HorizonBankRot",
											{-0.0051303101,-0.0138544},
											1
										},
										
										{
											"HorizonBankRot",
											{-0.0026047199,-0.0145196},
											1
										}
									},
									
									{
										
										{
											"HorizonBankRot",
											1,
											{0,0},
											1
										},
										
										{
											"HorizonBankRot",
											{-0.0026047199,-0.0145196},
											1
										},
										
										{
											"HorizonBankRot",
											{2.6226801e-009,-0.0147436},
											1
										},
										
										{
											"HorizonBankRot",
											{0.0026047199,-0.0145196},
											1
										}
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
										{0.22,0.2},
										1
									};
									right[]=
									{
										{0.28,0.2},
										1
									};
									down[]=
									{
										{0.22,0.23999999},
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
										{0.22,0.2},
										1
									};
									right[]=
									{
										{0.28,0.2},
										1
									};
									down[]=
									{
										{0.22,0.23999999},
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
									{0.16,0.47999999},
									1
								};
								right[]=
								{
									{0.22,0.47999999},
									1
								};
								down[]=
								{
									{0.16,0.51999998},
									1
								};
							};
							class AltNumber
							{
								type="text";
								source="altitudeAGL";
								sourceScale=1;
								sourceOffset=-2;
								align="left";
								scale=1;
								pos[]=
								{
									{0.81,0.47999999},
									1
								};
								right[]=
								{
									{0.87,0.47999999},
									1
								};
								down[]=
								{
									{0.81,0.51999998},
									1
								};
							};
							class HoverMode
							{
								condition="autohover";
								class HoverText
								{
									type="text";
									source="static";
									text="HOVER";
									scale=1;
									sourceScale=1;
									align="right";
									pos[]=
									{
										{0.0049999999,0.075000003},
										1
									};
									right[]=
									{
										{0.045000002,0.075000003},
										1
									};
									down[]=
									{
										{0.0049999999,0.11},
										1
									};
								};
							};
							class CruiseMode
							{
								condition="((altitudeASL-27) min 1) - autohover";
								class CruiseText
								{
									type="text";
									source="static";
									text="CRUISE";
									scale=1;
									sourceScale=1;
									align="right";
									pos[]=
									{
										{0.0049999999,0.075000003},
										1
									};
									right[]=
									{
										{0.045000002,0.075000003},
										1
									};
									down[]=
									{
										{0.0049999999,0.11},
										1
									};
								};
								class AltNumberASL
								{
									type="text";
									source="altitudeASL";
									sourceScale=1;
									align="left";
									scale=1;
									pos[]=
									{
										{0.81,0.16},
										1
									};
									right[]=
									{
										{0.87,0.16},
										1
									};
									down[]=
									{
										{0.81,0.2},
										1
									};
								};
							};
							class TransitionMode
							{
								condition="((27-altitudeASL) min 1) - autohover";
								class TransText
								{
									type="text";
									source="static";
									text="TRANS";
									scale=1;
									sourceScale=1;
									align="right";
									pos[]=
									{
										{0.0049999999,0.075000003},
										1
									};
									right[]=
									{
										{0.045000002,0.075000003},
										1
									};
									down[]=
									{
										{0.0049999999,0.11},
										1
									};
								};
							};
							class HoverModeHide
							{
								condition="1-autohover";
								class VelocityLine
								{
									type="line";
									width=4;
									points[]=
									{
										
										{
											"VelocityVector",
											{0,-0.0196581},
											1
										},
										
										{
											"VelocityVector",
											{0.0099999998,-0.017023901},
											1
										},
										
										{
											"VelocityVector",
											{0.01732,-0.0098290602},
											1
										},
										
										{
											"VelocityVector",
											{0.02,0},
											1
										},
										
										{
											"VelocityVector",
											{0.01732,0.0098290602},
											1
										},
										
										{
											"VelocityVector",
											{0.0099999998,0.017023901},
											1
										},
										
										{
											"VelocityVector",
											{0,0.0196581},
											1
										},
										
										{
											"VelocityVector",
											{-0.0099999998,0.017023901},
											1
										},
										
										{
											"VelocityVector",
											{-0.01732,0.0098290602},
											1
										},
										
										{
											"VelocityVector",
											{-0.02,0},
											1
										},
										
										{
											"VelocityVector",
											{-0.01732,-0.0098290602},
											1
										},
										
										{
											"VelocityVector",
											{-0.0099999998,-0.017023901},
											1
										},
										
										{
											"VelocityVector",
											{0,-0.0196581},
											1
										},
										{},
										
										{
											"VelocityVector",
											{0.039999999,0},
											1
										},
										
										{
											"VelocityVector",
											{0.02,0},
											1
										},
										{},
										
										{
											"VelocityVector",
											{-0.039999999,0},
											1
										},
										
										{
											"VelocityVector",
											{-0.02,0},
											1
										},
										{},
										
										{
											"VelocityVector",
											{0,-0.0393162},
											1
										},
										
										{
											"VelocityVector",
											{0,-0.0196581},
											1
										},
										{}
									};
								};
							};
							class GearGroup
							{
								type="group";
								condition="ils";
								class GearText
								{
									type="text";
									source="static";
									text="GEAR";
									align="right";
									scale=1;
									pos[]=
									{
										{0.015,0.33418801},
										1
									};
									right[]=
									{
										{0.055,0.33418801},
										1
									};
									down[]=
									{
										{0.015,0.363675},
										1
									};
								};
							};
							class LaserGroup
							{
								condition="laseron";
								class laserText
								{
									type="text";
									source="static";
									text="LASER";
									scale=1;
									sourceScale=1;
									align="right";
									pos[]=
									{
										{0.015,0.37},
										1
									};
									right[]=
									{
										{0.055,0.37},
										1
									};
									down[]=
									{
										{0.015,0.405},
										1
									};
								};
							};
							class RadarGroup
							{
								condition="activeSensorsOn";
								class radarText
								{
									type="text";
									source="static";
									text="RADAR";
									scale=1;
									sourceScale=1;
									align="right";
									pos[]=
									{
										{0.015,0.41},
										1
									};
									right[]=
									{
										{0.055,0.41},
										1
									};
									down[]=
									{
										{0.015,0.44499999},
										1
									};
								};
							};
							class VerticalSpeedScale
							{
								type="line";
								width=4;
								points[]=
								{
									
									{
										"WeaponAimRelative",
										1,
										{-0.029999999,0},
										1
									},
									
									{
										"WeaponAimRelative",
										1,
										{-0.02,0},
										1
									},
									{},
									
									{
										"WeaponAimRelative",
										1,
										{0.02,0},
										1
									},
									
									{
										"WeaponAimRelative",
										1,
										{0.029999999,0},
										1
									},
									{},
									
									{
										"WeaponAimRelative",
										1,
										{0,-0.02},
										1
									},
									
									{
										"WeaponAimRelative",
										1,
										{0,-0.029999999},
										1
									},
									{},
									
									{
										"WeaponAimRelative",
										1,
										{0,0.02},
										1
									},
									
									{
										"WeaponAimRelative",
										1,
										{0,0.029999999},
										1
									},
									{},
									
									{
										"HUDCenter",
										1,
										{-0.029999999,0},
										1
									},
									
									{
										"HUDCenter",
										1,
										{-0.0099999998,0},
										1
									},
									{},
									
									{
										"HUDCenter",
										1,
										{0.0099999998,0},
										1
									},
									
									{
										"HUDCenter",
										1,
										{0.029999999,0},
										1
									},
									{},
									
									{
										"HUDCenter",
										1,
										{0,-0.0099999998},
										1
									},
									
									{
										"HUDCenter",
										1,
										{0,-0.029999999},
										1
									},
									{},
									
									{
										"HUDCenter",
										1,
										{0,0.0099999998},
										1
									},
									
									{
										"HUDCenter",
										1,
										{0,0.029999999},
										1
									},
									{},
									
									{
										{0.91500002,0.18000001},
										1
									},
									
									{
										{0.935,0.18000001},
										1
									},
									{},
									
									{
										{0.87,0.18000001},
										1
									},
									
									{
										{0.88999999,0.18000001},
										1
									},
									{},
									
									{
										{0.91500002,0.34},
										1
									},
									
									{
										{0.935,0.34},
										1
									},
									{},
									
									{
										{0.87,0.34},
										1
									},
									
									{
										{0.88999999,0.34},
										1
									},
									{},
									
									{
										{0.875,0.37200001},
										1
									},
									
									{
										{0.88499999,0.37200001},
										1
									},
									{},
									
									{
										{0.875,0.40400001},
										1
									},
									
									{
										{0.88499999,0.40400001},
										1
									},
									{},
									
									{
										{0.875,0.43599999},
										1
									},
									
									{
										{0.88499999,0.43599999},
										1
									},
									{},
									
									{
										{0.875,0.46799999},
										1
									},
									
									{
										{0.88499999,0.46799999},
										1
									},
									{},
									
									{
										{0.87,0.5},
										1
									},
									
									{
										{0.88999999,0.5},
										1
									},
									{},
									
									{
										{0.91500002,0.5},
										1
									},
									
									{
										{0.935,0.5},
										1
									},
									{},
									
									{
										{0.91500002,0.66000003},
										1
									},
									
									{
										{0.935,0.66000003},
										1
									},
									{},
									
									{
										{0.87,0.66000003},
										1
									},
									
									{
										{0.88999999,0.66000003},
										1
									},
									{},
									
									{
										{0.875,0.62800002},
										1
									},
									
									{
										{0.88499999,0.62800002},
										1
									},
									{},
									
									{
										{0.875,0.59600002},
										1
									},
									
									{
										{0.88499999,0.59600002},
										1
									},
									{},
									
									{
										{0.875,0.56400001},
										1
									},
									
									{
										{0.88499999,0.56400001},
										1
									},
									{},
									
									{
										{0.875,0.53200001},
										1
									},
									
									{
										{0.88499999,0.53200001},
										1
									},
									{},
									
									{
										{0.92000002,0.69199997},
										1
									},
									
									{
										{0.93000001,0.69199997},
										1
									},
									{},
									
									{
										{0.92000002,0.72399998},
										1
									},
									
									{
										{0.93000001,0.72399998},
										1
									},
									{},
									
									{
										{0.92000002,0.75599998},
										1
									},
									
									{
										{0.93000001,0.75599998},
										1
									},
									{},
									
									{
										{0.92000002,0.78799999},
										1
									},
									
									{
										{0.93000001,0.78799999},
										1
									},
									{},
									
									{
										{0.91500002,0.81999999},
										1
									},
									
									{
										{0.935,0.81999999},
										1
									},
									{},
									
									{
										{0.87,0.81999999},
										1
									},
									
									{
										{0.88999999,0.81999999},
										1
									},
									{}
								};
							};
							class VerticalSpeedArrow
							{
								type="polygon";
								points[]=
								{
									
									{
										
										{
											"VerticalSpeedBone",
											{0.85000002,0.48800001},
											1
										},
										
										{
											"VerticalSpeedBone",
											{0.87,0.5},
											1
										},
										
										{
											"VerticalSpeedBone",
											{0.85000002,0.51200002},
											1
										}
									}
								};
							};
							class RadarAltitude
							{
								condition="101-altitudeAGL";
								class RadarHeight
								{
									type="line";
									width=15;
									points[]=
									{
										
										{
											{0.903,0.81999999},
											1
										},
										
										{
											"RadarHeight",
											{0,0},
											1
										},
										{}
									};
								};
							};
							class HorizonLine
							{
								condition="1-autohover";
								clipTL[]={0.2,0.145};
								clipBR[]={0.80000001,0.85500002};
								class HorizonLineDraw
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
							class WeaponsText
							{
								condition="1- mgun";
								class Weapons
								{
									type="text";
									source="weapon";
									sourceScale=1;
									align="left";
									scale=0.5;
									pos[]=
									{
										{0.38,0.86900002},
										1
									};
									right[]=
									{
										{0.41499999,0.86900002},
										1
									};
									down[]=
									{
										{0.38,0.90399998},
										1
									};
								};
							};
							class Ammo
							{
								type="text";
								source="ammo";
								sourceScale=1;
								align="left";
								scale=0.5;
								pos[]=
								{
									{0.38,0.90100002},
									1
								};
								right[]=
								{
									{0.41499999,0.90100002},
									1
								};
								down[]=
								{
									{0.38,0.93599999},
									1
								};
							};
							class MGun
							{
								condition="mgun";
								class Weapons
								{
									type="text";
									source="static";
									text="GUN";
									sourceScale=1;
									align="left";
									scale=0.5;
									pos[]=
									{
										{0.38,0.86900002},
										1
									};
									right[]=
									{
										{0.41499999,0.86900002},
										1
									};
									down[]=
									{
										{0.38,0.90399998},
										1
									};
								};
								class Circle
								{
									type="line";
									width=4;
									points[]=
									{
										
										{
											"ImpactPoint",
											{0.025,0},
											1
										},
										
										{
											"ImpactPoint",
											{0.0099999998,0},
											1
										},
										{},
										
										{
											"ImpactPoint",
											{0,0.0245726},
											1
										},
										
										{
											"ImpactPoint",
											{0,0.0098290602},
											1
										},
										{},
										
										{
											"ImpactPoint",
											{-0.025,0},
											1
										},
										
										{
											"ImpactPoint",
											{-0.0099999998,0},
											1
										},
										{},
										
										{
											"ImpactPoint",
											{0,-0.0245726},
											1
										},
										
										{
											"ImpactPoint",
											{0,-0.0098290602},
											1
										},
										{},
										
										{
											"ImpactPoint",
											{0,-0.0098290602},
											1
										},
										
										{
											"ImpactPoint",
											{0.0049999999,-0.0085119698},
											1
										},
										
										{
											"ImpactPoint",
											{0.0086599998,-0.0049145301},
											1
										},
										
										{
											"ImpactPoint",
											{0.0099999998,0},
											1
										},
										
										{
											"ImpactPoint",
											{0.0086599998,0.0049145301},
											1
										},
										
										{
											"ImpactPoint",
											{0.0049999999,0.0085119698},
											1
										},
										
										{
											"ImpactPoint",
											{0,0.0098290602},
											1
										},
										
										{
											"ImpactPoint",
											{-0.0049999999,0.0085119698},
											1
										},
										
										{
											"ImpactPoint",
											{-0.0086599998,0.0049145301},
											1
										},
										
										{
											"ImpactPoint",
											{-0.0099999998,0},
											1
										},
										
										{
											"ImpactPoint",
											{-0.0086599998,-0.0049145301},
											1
										},
										
										{
											"ImpactPoint",
											{-0.0049999999,-0.0085119698},
											1
										},
										
										{
											"ImpactPoint",
											{0,-0.0098290602},
											1
										}
									};
								};
							};
							class AAMissile
							{
								condition="AAmissile";
								class Circle
								{
									type="line";
									width=4;
									points[]=
									{
										
										{
											"ForwardVector",
											1,
											"HUDCenter",
											{0,-0.245726},
											1
										},
										
										{
											"ForwardVector",
											1,
											"HUDCenter",
											{0.043400001,-0.241991},
											1
										},
										
										{
											"ForwardVector",
											1,
											"HUDCenter",
											{0.085500002,-0.230909},
											1
										},
										
										{
											"ForwardVector",
											1,
											"HUDCenter",
											{0.125,-0.212799},
											1
										},
										
										{
											"ForwardVector",
											1,
											"HUDCenter",
											{0.16069999,-0.188226},
											1
										},
										
										{
											"ForwardVector",
											1,
											"HUDCenter",
											{0.19149999,-0.15795299},
											1
										},
										
										{
											"ForwardVector",
											1,
											"HUDCenter",
											{0.2165,-0.122863},
											1
										},
										
										{
											"ForwardVector",
											1,
											"HUDCenter",
											{0.234925,-0.084038503},
											1
										},
										
										{
											"ForwardVector",
											1,
											"HUDCenter",
											{0.2462,-0.042658102},
											1
										},
										
										{
											"ForwardVector",
											1,
											"HUDCenter",
											{0.25,0},
											1
										},
										
										{
											"ForwardVector",
											1,
											"HUDCenter",
											{0.2462,0.042658102},
											1
										},
										
										{
											"ForwardVector",
											1,
											"HUDCenter",
											{0.234925,0.084038503},
											1
										},
										
										{
											"ForwardVector",
											1,
											"HUDCenter",
											{0.2165,0.122863},
											1
										},
										
										{
											"ForwardVector",
											1,
											"HUDCenter",
											{0.19149999,0.15795299},
											1
										},
										
										{
											"ForwardVector",
											1,
											"HUDCenter",
											{0.16069999,0.188226},
											1
										},
										
										{
											"ForwardVector",
											1,
											"HUDCenter",
											{0.125,0.212799},
											1
										},
										
										{
											"ForwardVector",
											1,
											"HUDCenter",
											{0.085500002,0.230909},
											1
										},
										
										{
											"ForwardVector",
											1,
											"HUDCenter",
											{0.043400001,0.241991},
											1
										},
										
										{
											"ForwardVector",
											1,
											"HUDCenter",
											{0,0.245726},
											1
										},
										
										{
											"ForwardVector",
											1,
											"HUDCenter",
											{-0.043400001,0.241991},
											1
										},
										
										{
											"ForwardVector",
											1,
											"HUDCenter",
											{-0.085500002,0.230909},
											1
										},
										
										{
											"ForwardVector",
											1,
											"HUDCenter",
											{-0.125,0.212799},
											1
										},
										
										{
											"ForwardVector",
											1,
											"HUDCenter",
											{-0.16069999,0.188226},
											1
										},
										
										{
											"ForwardVector",
											1,
											"HUDCenter",
											{-0.19149999,0.15795299},
											1
										},
										
										{
											"ForwardVector",
											1,
											"HUDCenter",
											{-0.2165,0.122863},
											1
										},
										
										{
											"ForwardVector",
											1,
											"HUDCenter",
											{-0.234925,0.084038503},
											1
										},
										
										{
											"ForwardVector",
											1,
											"HUDCenter",
											{-0.2462,0.042658102},
											1
										},
										
										{
											"ForwardVector",
											1,
											"HUDCenter",
											{-0.25,0},
											1
										},
										
										{
											"ForwardVector",
											1,
											"HUDCenter",
											{-0.2462,-0.042658102},
											1
										},
										
										{
											"ForwardVector",
											1,
											"HUDCenter",
											{-0.234925,-0.084038503},
											1
										},
										
										{
											"ForwardVector",
											1,
											"HUDCenter",
											{-0.2165,-0.122863},
											1
										},
										
										{
											"ForwardVector",
											1,
											"HUDCenter",
											{-0.19149999,-0.15795299},
											1
										},
										
										{
											"ForwardVector",
											1,
											"HUDCenter",
											{-0.16069999,-0.188226},
											1
										},
										
										{
											"ForwardVector",
											1,
											"HUDCenter",
											{-0.125,-0.212799},
											1
										},
										
										{
											"ForwardVector",
											1,
											"HUDCenter",
											{-0.085500002,-0.230909},
											1
										},
										
										{
											"ForwardVector",
											1,
											"HUDCenter",
											{-0.043400001,-0.241991},
											1
										},
										
										{
											"ForwardVector",
											1,
											"HUDCenter",
											{0,-0.245726},
											1
										}
									};
								};
							};
							class ATMissile
							{
								condition="ATmissile";
								class Circle
								{
									type="line";
									width=4;
									points[]=
									{
										
										{
											"ForwardVector",
											1,
											"HUDCenter",
											{-0.15000001,-0.14743599},
											1
										},
										
										{
											"ForwardVector",
											1,
											"HUDCenter",
											{-0.15000001,-0.12777799},
											1
										},
										{},
										
										{
											"ForwardVector",
											1,
											"HUDCenter",
											{-0.15000001,0.14743599},
											1
										},
										
										{
											"ForwardVector",
											1,
											"HUDCenter",
											{-0.15000001,0.12777799},
											1
										},
										{},
										
										{
											"ForwardVector",
											1,
											"HUDCenter",
											{0.15000001,-0.14743599},
											1
										},
										
										{
											"ForwardVector",
											1,
											"HUDCenter",
											{0.15000001,-0.12777799},
											1
										},
										{},
										
										{
											"ForwardVector",
											1,
											"HUDCenter",
											{0.15000001,0.14743599},
											1
										},
										
										{
											"ForwardVector",
											1,
											"HUDCenter",
											{0.15000001,0.12777799},
											1
										},
										{},
										
										{
											"ForwardVector",
											1,
											"HUDCenter",
											{-0.15000001,-0.14743599},
											1
										},
										
										{
											"ForwardVector",
											1,
											"HUDCenter",
											{-0.13,-0.14743599},
											1
										},
										{},
										
										{
											"ForwardVector",
											1,
											"HUDCenter",
											{-0.15000001,0.14743599},
											1
										},
										
										{
											"ForwardVector",
											1,
											"HUDCenter",
											{-0.13,0.14743599},
											1
										},
										{},
										
										{
											"ForwardVector",
											1,
											"HUDCenter",
											{0.15000001,-0.14743599},
											1
										},
										
										{
											"ForwardVector",
											1,
											"HUDCenter",
											{0.13,-0.14743599},
											1
										},
										{},
										
										{
											"ForwardVector",
											1,
											"HUDCenter",
											{0.15000001,0.14743599},
											1
										},
										
										{
											"ForwardVector",
											1,
											"HUDCenter",
											{0.13,0.14743599},
											1
										}
									};
								};
							};
							class Rockets
							{
								condition="rocket";
								class RocketDummy
								{
									type="line";
									width=3;
									points[]=
									{
										
										{
											"ImpactPoint",
											{0.0099999998,-0.0294872},
											1
										},
										
										{
											"ImpactPoint",
											{-0.0099999998,-0.0294872},
											1
										},
										{},
										
										{
											"ImpactPoint",
											{0.0099999998,0.0294872},
											1
										},
										
										{
											"ImpactPoint",
											{-0.0099999998,0.0294872},
											1
										},
										{},
										
										{
											"ImpactPoint",
											{0,-0.0294872},
											1
										},
										
										{
											"ImpactPoint",
											{0,0.0294872},
											1
										},
										{}
									};
								};
							};
							class WP
							{
								condition="wpvalid - autohover";
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
										{0.235,0.77403802},
										1
									};
									right[]=
									{
										{0.27500001,0.77403802},
										1
									};
									down[]=
									{
										{0.235,0.80155998},
										1
									};
								};
								class WPIndex
								{
									type="text";
									source="wpIndex";
									sourceScale=1;
									sourceLength=2;
									align="right";
									scale=1;
									pos[]=
									{
										{0.096000001,0.77600402},
										1
									};
									right[]=
									{
										{0.126,0.77600402},
										1
									};
									down[]=
									{
										{0.096000001,0.79959399},
										1
									};
								};
								class WPstatic
								{
									type="text";
									source="static";
									text="W";
									scale=1;
									sourceScale=1;
									align="right";
									pos[]=
									{
										{0.075000003,0.77499998},
										1
									};
									right[]=
									{
										{0.105,0.77499998},
										1
									};
									down[]=
									{
										{0.075000003,0.80000001},
										1
									};
								};
								class WPAuto
								{
									type="text";
									source="static";
									text="A";
									scale=1;
									sourceScale=1;
									align="right";
									pos[]=
									{
										
										{
											"0.075 +0.035",
											0.80000001
										},
										1
									};
									right[]=
									{
										{0.14,0.80000001},
										1
									};
									down[]=
									{
										
										{
											"0.075 +0.035",
											0.82499999
										},
										1
									};
								};
								class WPKM
								{
									type="text";
									source="static";
									text="KM";
									scale=1;
									sourceScale=1;
									align="right";
									pos[]=
									{
										
										{
											"0.075 +0.16",
											0.77499998
										},
										1
									};
									right[]=
									{
										{0.26499999,0.77499998},
										1
									};
									down[]=
									{
										
										{
											"0.075 +0.16",
											0.80299997
										},
										1
									};
								};
								class WPTime
								{
									type="text";
									source="static";
									text="-:--";
									scale=1;
									sourceScale=1;
									align="right";
									pos[]=
									{
										
										{
											"0.075 +0.11",
											0.80000001
										},
										1
									};
									right[]=
									{
										{0.215,0.80000001},
										1
									};
									down[]=
									{
										
										{
											"0.075 +0.11",
											0.82499999
										},
										1
									};
								};
								class WP
								{
									width=2;
									type="line";
									points[]=
									{
										
										{
											"WPPoint",
											1,
											"LimitWaypoint",
											1,
											{-0.02,0.039999999},
											1
										},
										
										{
											"WPPoint",
											1,
											"LimitWaypoint",
											1,
											{0,0.02},
											1
										},
										
										{
											"WPPoint",
											1,
											"LimitWaypoint",
											1,
											{0.02,0.039999999},
											1
										},
										{}
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
										{0.493,0.76666701},
										1
									};
									right[]=
									{
										{0.55299997,0.76666701},
										1
									};
									down[]=
									{
										{0.493,0.81581199},
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
							class RadarTargets
							{
								class RadarBoxes
								{
									type="radartoview";
									pos0[]={0.5,0.5};
									pos10[]={0.73400003,0.73000002};
									width=4;
									points[]=
									{
										
										{
											{-0.0035000001,-0.0034401701},
											1
										},
										
										{
											{0.0035000001,-0.0034401701},
											1
										},
										
										{
											{0.0035000001,0.0034401701},
											1
										},
										
										{
											{-0.0035000001,0.0034401701},
											1
										},
										
										{
											{-0.0035000001,-0.0034401701},
											1
										}
									};
								};
							};
							class TargetDiamond
							{
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
											1,
											{0.0074999998,0},
											1
										},
										
										{
											"Target",
											1,
											"Limit0109",
											1,
											{0.0125,0},
											1
										},
										{},
										
										{
											"Target",
											1,
											"Limit0109",
											1,
											{0.0175,0},
											1
										},
										
										{
											"Target",
											1,
											"Limit0109",
											1,
											{0.022500001,0},
											1
										},
										{},
										
										{
											"Target",
											1,
											"Limit0109",
											1,
											{0.0275,0},
											1
										},
										
										{
											"Target",
											1,
											"Limit0109",
											1,
											{0.032499999,0},
											1
										},
										{},
										
										{
											"Target",
											1,
											"Limit0109",
											1,
											{0.037500001,0},
											1
										},
										
										{
											"Target",
											1,
											"Limit0109",
											1,
											{0.0425,0},
											1
										},
										{},
										
										{
											"Target",
											1,
											"Limit0109",
											1,
											{0.047499999,0},
											1
										},
										
										{
											"Target",
											1,
											"Limit0109",
											1,
											{0.052499998,0},
											1
										},
										{},
										
										{
											"Target",
											1,
											"Limit0109",
											1,
											{-0.0074999998,0},
											1
										},
										
										{
											"Target",
											1,
											"Limit0109",
											1,
											{-0.0125,0},
											1
										},
										{},
										
										{
											"Target",
											1,
											"Limit0109",
											1,
											{-0.0175,0},
											1
										},
										
										{
											"Target",
											1,
											"Limit0109",
											1,
											{-0.022500001,0},
											1
										},
										{},
										
										{
											"Target",
											1,
											"Limit0109",
											1,
											{-0.0275,0},
											1
										},
										
										{
											"Target",
											1,
											"Limit0109",
											1,
											{-0.032499999,0},
											1
										},
										{},
										
										{
											"Target",
											1,
											"Limit0109",
											1,
											{-0.037500001,0},
											1
										},
										
										{
											"Target",
											1,
											"Limit0109",
											1,
											{-0.0425,0},
											1
										},
										{},
										
										{
											"Target",
											1,
											"Limit0109",
											1,
											{-0.047499999,0},
											1
										},
										
										{
											"Target",
											1,
											"Limit0109",
											1,
											{-0.052499998,0},
											1
										},
										{},
										
										{
											"Target",
											1,
											"Limit0109",
											1,
											{0,0.0073717898},
											1
										},
										
										{
											"Target",
											1,
											"Limit0109",
											1,
											{0,0.0122863},
											1
										},
										{},
										
										{
											"Target",
											1,
											"Limit0109",
											1,
											{0,0.0172009},
											1
										},
										
										{
											"Target",
											1,
											"Limit0109",
											1,
											{0,0.0221154},
											1
										},
										{},
										
										{
											"Target",
											1,
											"Limit0109",
											1,
											{0,0.0270299},
											1
										},
										
										{
											"Target",
											1,
											"Limit0109",
											1,
											{0,0.031944402},
											1
										},
										{},
										
										{
											"Target",
											1,
											"Limit0109",
											1,
											{0,0.036858998},
											1
										},
										
										{
											"Target",
											1,
											"Limit0109",
											1,
											{0,0.041773502},
											1
										},
										{},
										
										{
											"Target",
											1,
											"Limit0109",
											1,
											{0,0.046688002},
											1
										},
										
										{
											"Target",
											1,
											"Limit0109",
											1,
											{0,0.051602598},
											1
										},
										{},
										
										{
											"Target",
											1,
											"Limit0109",
											1,
											{0,-0.0073717898},
											1
										},
										
										{
											"Target",
											1,
											"Limit0109",
											1,
											{0,-0.0122863},
											1
										},
										{},
										
										{
											"Target",
											1,
											"Limit0109",
											1,
											{0,-0.0172009},
											1
										},
										
										{
											"Target",
											1,
											"Limit0109",
											1,
											{0,-0.0221154},
											1
										},
										{},
										
										{
											"Target",
											1,
											"Limit0109",
											1,
											{0,-0.0270299},
											1
										},
										
										{
											"Target",
											1,
											"Limit0109",
											1,
											{0,-0.031944402},
											1
										},
										{},
										
										{
											"Target",
											1,
											"Limit0109",
											1,
											{0,-0.036858998},
											1
										},
										
										{
											"Target",
											1,
											"Limit0109",
											1,
											{0,-0.041773502},
											1
										},
										{},
										
										{
											"Target",
											1,
											"Limit0109",
											1,
											{0,-0.046688002},
											1
										},
										
										{
											"Target",
											1,
											"Limit0109",
											1,
											{0,-0.051602598},
											1
										},
										{}
									};
								};
							};
							class TargetLocked
							{
								condition="missilelocked";
								class TargetLockedText
								{
									type="text";
									source="static";
									text="VALID LOCK";
									scale=1;
									sourceScale=1;
									align="center";
									pos[]=
									{
										{0.493,0.77899998},
										1
									};
									right[]=
									{
										{0.53299999,0.77899998},
										1
									};
									down[]=
									{
										{0.493,0.81},
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
									align="right";
									pos[]=
									{
										
										{
											"0.127+0.49",
											0.86900002
										},
										1
									};
									right[]=
									{
										{0.65200001,0.86900002},
										1
									};
									down[]=
									{
										
										{
											"0.127+0.49",
											0.90399998
										},
										1
									};
								};
								class DistanceText
								{
									type="text";
									source="static";
									text="DIST:";
									scale=1;
									sourceScale=1;
									align="right";
									pos[]=
									{
										
										{
											"0.125+0.49",
											0.90100002
										},
										1
									};
									right[]=
									{
										{0.64999998,0.90100002},
										1
									};
									down[]=
									{
										
										{
											"0.125+0.49",
											0.93599999
										},
										1
									};
								};
								class TOF_source
								{
									type="text";
									scale=1;
									sourceScale=1;
									source="missileflighttime";
									align="right";
									pos[]=
									{
										{0.73900002,0.86900002},
										1
									};
									right[]=
									{
										{0.77399999,0.86900002},
										1
									};
									down[]=
									{
										{0.73900002,0.90399998},
										1
									};
								};
								class TargetDistance: TOF_source
								{
									source="targetDist";
									sourceLength=0;
									sourcePrecision=1;
									sourceScale=0.001;
									align="right";
									pos[]=
									{
										{0.73900002,0.90100002},
										1
									};
									right[]=
									{
										{0.77399999,0.90100002},
										1
									};
									down[]=
									{
										{0.73900002,0.93599999},
										1
									};
								};
							};
						};
					};
				};
			};
		};