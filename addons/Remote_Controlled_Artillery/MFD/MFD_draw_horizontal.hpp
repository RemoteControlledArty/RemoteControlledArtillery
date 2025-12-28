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