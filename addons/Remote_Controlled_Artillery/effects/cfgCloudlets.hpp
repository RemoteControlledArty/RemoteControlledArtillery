class Default;
class RC_MortarExp: Default
{
	interval=0.02;
	circleRadius=0;
	circleVelocity[]={0,0,0};
	particleShape="\A3\data_f\ParticleEffects\Universal\Universal";
	particleFSNtieth=16;
	particleFSIndex=0;
	particleFSFrameCount=32;
	particleFSLoop=0;
	angleVar=1;
	animationName="";
	particleType="Billboard";
	timerPeriod=1;
	lifeTime=2;
	moveVelocity[]={0,1,0};
	rotationVelocity=0;
	weight=10;
	volume=7.9000001;
	rubbing=0.1;
	size[]=
	{
		"0.05 * intensity + 3",
		"0.05 * intensity + 2"
	};
	color[]=
	{
		{1,1,1,-20},
		{1,1,1,-15}
	};
	animationSpeed[]={1};
	randomDirectionPeriod=0.2;
	randomDirectionIntensity=0.2;
	onTimerScript="";
	beforeDestroyScript="";
	lifeTimeVar=0;
	positionVar[]={2.5,0.1,2.5};
	MoveVelocityVar[]={0.2,0.5,0.2};
	rotationVelocityVar=90;
	sizeVar=0.5;
	colorVar[]={0,0,0,0};
	randomDirectionPeriodVar=0;
	randomDirectionIntensityVar=0;
};

class RC_CloudMedDark: Default
{
	interval="0.02 * interval + 0.01";
	circleRadius=0;
	circleVelocity[]={0,0,0};
	particleShape="\A3\data_f\ParticleEffects\Universal\Universal";
	particleFSNtieth=16;
	particleFSIndex=7;
	particleFSFrameCount=48;
	particleFSLoop=1;
	angleVar=1;
	animationName="";
	particleType="Billboard";
	timerPeriod=1;
	lifeTime=8;
	moveVelocity[]={0,3,0};
	rotationVelocity=0;
	weight=0.052000001;
	volume=0.039999999;
	rubbing=0.0099999998;
	size[]=
	{
		"0.0125 * intensity + 6",
		"0.0125 * intensity + 9",
		"0.0125 * intensity + 13",
		"0.015 * intensity + 18"
	};
	color[]=
	{
		{0.2,0.2,0.2,0.60000002},
		{0.40000001,0.40000001,0.40000001,0.40000001},
		{0.60000002,0.60000002,0.60000002,0.2},
		{0.69999999,0.69999999,0.69999999,0.079999998},
		{1,1,1,0.0099999998}
	};
	animationSpeed[]={1.5,0.5,0.30000001,0.25,0.25};
	randomDirectionPeriod=0.2;
	randomDirectionIntensity=0.2;
	onTimerScript="";
	beforeDestroyScript="";
	lifeTimeVar=2;
	positionVar[]={2.5,3,2.5};
	MoveVelocityVar[]={1.5,3,1.5};
	rotationVelocityVar=20;
	sizeVar=0;
	colorVar[]={0,0,0,0};
	randomDirectionPeriodVar=0;
	randomDirectionIntensityVar=0;
};

class RC_CloudBigDark: Default
{
	interval=0.0020000001;
	circleRadius=0;
	circleVelocity[]={0,0,0};
	particleShape="\A3\data_f\ParticleEffects\Universal\Universal";
	particleFSNtieth=16;
	particleFSIndex=7;
	particleFSFrameCount=48;
	particleFSLoop=1;
	angleVar=1;
	animationName="";
	particleType="Billboard";
	timerPeriod=1;
	lifeTime=8;
	moveVelocity[]={0,4,0};
	rotationVelocity=0;
	weight=1.275;
	volume=1;
	rubbing=0.25;
	size[]={4,7,10,12};
	color[]=
	{
		{0.44999999,0.44999999,0.44999999,0.69999999},
		{0.5,0.5,0.5,0.5},
		{0.60000002,0.60000002,0.60000002,0.25},
		{0.64999998,0.64999998,0.64999998,0.0099999998}
	};
	animationSpeed[]={0.5,0.30000001,0.25,0.2,0.18000001};
	randomDirectionPeriod=0.2;
	randomDirectionIntensity=0.050000001;
	onTimerScript="";
	beforeDestroyScript="";
	lifeTimeVar=3;
	positionVar[]={2,12,2};
	MoveVelocityVar[]={1.5,5,1.5};
	rotationVelocityVar=10;
	sizeVar=0.5;
	colorVar[]={0,0,0,0};
	randomDirectionPeriodVar=0;
	randomDirectionIntensityVar=0;
};

class ShellSparks1: Default
{
	particleShape="\A3\data_f\ParticleEffects\Universal\Smoke";
	particleFSFrameCount=1;
	particleFSLoop=0;
	particleFSNtieth=1;
	particleFSIndex=0;
	particleType="Billboard";
	animationSpeed[]={-2};
	size[]={0.05};
	sizeVar=0.5;
	interval=0.01;
	rubbing=0.15;
	angleVar=360;
	positionVar[]={5,5,5};
	bounceOnSurface=0.01;
	bounceOnSurfaceVar=0.3;
	moveVelocity[]={0,0,0};
	MoveVelocityVar[]={15,10,15};
	weight=2.5;
	volume=0.5;
	emissiveColor[]={{10000,6000,1600,0.5}};
	colorVar[]={0.05,0.05,0.05,0};
	color[]={{0.8,0.6,0.16,-1},{0.8,0.6,0.16,0}};
	rotationVelocity = 1;
	randomDirectionPeriod=0.2;
	randomDirectionIntensity=0.2;
	lifeTime=8;
	lifeTimeVar=2;
};
class ShellSparks2: ShellSparks1
{
	moveVelocity[]={0,10,0};
	MoveVelocityVar[]={75,100,75};
	interval=0.002;
	lifeTime=0.2;
	lifeTimeVar=1;
	randomDirectionPeriodVar=0;
	randomDirectionIntensityVar=0;
	size[]={0.15};
};

class RC_CircleDustMed: Default
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
class RC_82mmCircleDust: RC_CircleDustMed
{
	circleRadius=12.7;
	lifeTime=20;
};
class RC_82mmGuidedCircleDust: RC_CircleDustMed
{
	circleRadius=9;
	lifeTime=20;
};

class RC_105mmCircleDust: RC_CircleDustMed
{
	circleRadius=15.3;
	size[]={6.9,12.7};
	lifeTime=20;
};
class RC_105mmGuidedCircleDust: RC_CircleDustMed
{
	circleRadius=10.9;
	lifeTime=20;
};

class RC_120mmCircleDust: RC_CircleDustMed
{
	circleRadius=17;
	size[]={8.1,14.9};
	lifeTime=20;
};
class RC_120mmGuidedCircleDust: RC_CircleDustMed
{
	circleRadius=12.4;
	lifeTime=20;
};

class RC_155mmCircleDust: RC_CircleDustMed
{
	circleRadius=21.2;
	size[]={9,16.5};
	lifeTime=20;
};
class RC_155mmGuidedCircleDust: RC_CircleDustMed
{
	circleRadius=15;
	lifeTime=20;
};

class RC_230mmCircleDust: RC_CircleDustMed
{
	circleRadius=31.8;
	size[]={12,22};
	lifeTime=30;
};
class RC_230mmGuidedCircleDust: RC_CircleDustMed
{
	circleRadius=15;
	lifeTime=20;
};

class RC_604mmCircleDust: RC_CircleDustMed
{
	circleRadius=174.3;
	size[]={24,44};
	lifeTime=40;
};

class ShellShockwave: Default
{
	beforeDestroyScript="";
	circleRadius=0;
	circleVelocity[]={0,0,0};
	randomDirectionIntensity=0.2;
	randomDirectionIntensityVar=0;
	randomDirectionPeriod=0.2;
	randomDirectionPeriodVar=0;
	colorVar[]={0,0,0,0};
	color[]={{1,1,1,0.04},{0.5,0.5,0.5,0.1},{0.3,0.3,0.3,0.04},{0.2,0.2,0.2,0}};
	MoveVelocityVar[]={0.2,0.5,0.2};
	moveVelocity[]={0,0,0};
	interval=30;
	onTimerScript="";
	volume=7.9000001;
	weight=10;
	rotationVelocity=0;
	rotationVelocityVar=90;
	particleShape="\A3\data_f\ParticleEffects\Universal\Smoke";
	particleType="Billboard";
	particleFSLoop=0;
	particleFSNtieth=1;
	particleFSFrameCount=1;
	particleFSIndex=0;
	angleVar=1;
	lifeTime=0.5;
	lifeTimeVar=0;
	positionVar[]={0.4,0.1,0.4};
	animationName="";
	animationSpeed[]={1};
	sizeVar=0.5;
	Size[]={1,8,20,35,50,70,100,120};
	timerPeriod=1;
	rubbing=0.1;
};