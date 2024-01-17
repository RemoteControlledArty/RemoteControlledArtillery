/*
class CircleDustBig
{
	interval=0.0020000001;
	circleRadius=4;
	circleVelocity[]={1,0,1};
	particleShape="\A3\data_f\ParticleEffects\Universal\Universal";
	particleFSNtieth=16;
	particleFSIndex=12;
	particleFSFrameCount=13;
	particleFSLoop=0;
	animationName="";
	particleType="Billboard";
	timerPeriod=1;
	lifeTime=6;
	moveVelocity[]={0,1,0};
	rotationVelocity=0;
	weight=0.052999999;
	volume=0.039999999;
	rubbing=0.02;
	size[]=
	{
		"0.0125 * intensity + 4.5",
		"0.0125 * intensity + 9"
	};
	color[]=
	{
		{0.60000002,0.5,0.40000001,0.079999998},
		{0.60000002,0.5,0.40000001,0.059999999},
		{0.60000002,0.5,0.40000001,0.039999999},
		{0.60000002,0.5,0.40000001,0.02},
		{0.60000002,0.5,0.40000001,0.0099999998},
		{0.60000002,0.5,0.40000001,0.001}
	};
	animationSpeed[]={1000};
	randomDirectionPeriod=0.1;
	randomDirectionIntensity=0.050000001;
	onTimerScript="";
	beforeDestroyScript="";
	lifeTimeVar=1;
	positionVar[]={10,1,10};
	MoveVelocityVar[]={2,0.5,2};
	rotationVelocityVar=20;
	sizeVar=0.30000001;
	colorVar[]={0,0,0,0};
	randomDirectionPeriodVar=0;
	randomDirectionIntensityVar=0;
};
*/

class CircleDustBig;
class RC_CircleDustBig: CircleDustBig
{
	circleRadius=10;	//4
	circleVelocity[]={1,0,1};
	particleShape="\A3\data_f\ParticleEffects\Universal\Universal";
	particleType="Billboard";
	timerPeriod=1;
	lifeTime=15;	//6
	weight=0.052999999;
	volume=0.039999999;
	lifeTimeVar=1;
	positionVar[]={10,1,10};
	rotationVelocityVar=20;
	sizeVar=0.30000001;
};

/*
class CircleDustMed: Default
{
	interval=0.001;
	circleRadius=1.3;
	circleVelocity[]={0.80000001,0,0.80000001};
	particleShape="\A3\data_f\ParticleEffects\Universal\Universal";
	particleFSNtieth=16;
	particleFSIndex=12;
	particleFSFrameCount=13;
	particleFSLoop=0;
	animationName="";
	particleType="Billboard";
	timerPeriod=1;
	lifeTime=3.5;
	moveVelocity[]={0,1,0};
	rotationVelocity=0;
	weight=0.052999999;
	volume=0.039999999;
	rubbing=0.050000001;
	size[]={6,11};
	color[]=
	{
		{0.40000001,0.30000001,0.2,0.1},
		{0.40000001,0.30000001,0.2,0.07},
		{0.40000001,0.30000001,0.2,0.039999999},
		{0.40000001,0.30000001,0.2,0.02},
		{0.40000001,0.30000001,0.2,0.0099999998},
		{0.40000001,0.30000001,0.2,0.001}
	};
	animationSpeed[]={1000};
	randomDirectionPeriod=0.1;
	randomDirectionIntensity=0.050000001;
	onTimerScript="";
	beforeDestroyScript="";
	lifeTimeVar=0.5;
	positionVar[]={10,1,10};
	MoveVelocityVar[]={0.5,0.5,0.5};
	rotationVelocityVar=20;
	sizeVar=0.2;
	colorVar[]={0,0,0,0};
	randomDirectionPeriodVar=0;
	randomDirectionIntensityVar=0;
};
*/

class CircleDustMed;
class RC_82mmCircleDust: CircleDustMed
{
	circleRadius=12.7;
	//circleRadius[]={12.7,8.5,4.2};	//doesnt work
	lifeTime=20;	//3.5
};

class RC_105mmCircleDust: CircleDustMed
{
	circleRadius=15.3;
	lifeTime=20;	//3.5
};

class RC_120mmCircleDust: CircleDustMed
{
	circleRadius=17;
	lifeTime=20;	//3.5
};

class RC_155mmCircleDust: CircleDustMed
{
	circleRadius=21.2;
	//size[]={6,11};	//size[]={6,11};
	lifeTime=20;	//3.5
};

class RC_230mmCircleDust: CircleDustMed
{
	circleRadius=42.4;
	size[]={12,22};	//size[]={6,11};
	lifeTime=30;	//3.5
};