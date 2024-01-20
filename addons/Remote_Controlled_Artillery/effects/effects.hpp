//cratereffects
class RC_ArtyShellCrater
{
	class MissileCircleDust
	{
		simulation="particles";
		type="RC_CircleDustBig";
		enabled="distToWater interpolate [0.0,0.01,-1,1]";
		position[]={0,0,0};
		intensity=1;
		interval=1;
		lifeTime=0.25;
	};
};

class RC_82mmAirburstDust
{
	class MissileCircleDust
	{
		simulation="particles";
		type="RC_82mmCircleDust";
		enabled="distToWater interpolate [0.05,0.06,-1,1]";
		position[]={0,0,0};
		intensity=1;
		interval=1;
		lifeTime=0.2;	//0.2
	};
	class CircleDust
	{
		simulation="particles";
		type="RC_82mmCircleDust";
		enabled="distToWater interpolate [0.05,0.06,-1,1]";
		position[]={0,0,0};
		intensity=1;
		interval=1;
		lifeTime=0.2;	//0.2
	};
};

class RC_105mmAirburstDust
{
	class MissileCircleDust
	{
		simulation="particles";
		type="RC_82mmCircleDust";
		enabled="distToWater interpolate [0.05,0.06,-1,1]";
		position[]={0,0,0};
		intensity=1;
		interval=1;
		lifeTime=0.2;	//0.2
	};
	class CircleDust
	{
		simulation="particles";
		type="RC_105mmCircleDust";
		enabled="distToWater interpolate [0.05,0.06,-1,1]";
		position[]={0,0,0};
		intensity=1;
		interval=1;
		lifeTime=0.2;	//0.2
	};
};

class RC_120mmAirburstDust
{
	class MissileCircleDust
	{
		simulation="particles";
		type="RC_120mmCircleDust";
		enabled="distToWater interpolate [0.05,0.06,-1,1]";
		position[]={0,0,0};
		intensity=1;
		interval=1;
		lifeTime=0.2;	//0.2
	};
	class CircleDust
	{
		simulation="particles";
		type="RC_120mmCircleDust";
		enabled="distToWater interpolate [0.05,0.06,-1,1]";
		position[]={0,0,0};
		intensity=1;
		interval=1;
		lifeTime=0.2;	//0.2
	};
};

class RC_155mmAirburstDust
{
	class MissileCircleDust
	{
		simulation="particles";
		type="RC_155mmCircleDust";
		enabled="distToWater interpolate [0.05,0.06,-1,1]";
		position[]={0,0,0};
		intensity=1;
		interval=1;
		lifeTime=0.2;	//0.2
	};
	class CircleDust
	{
		simulation="particles";
		type="RC_155mmCircleDust";
		enabled="distToWater interpolate [0.05,0.06,-1,1]";
		position[]={0,0,0};
		intensity=1;
		interval=1;
		lifeTime=0.2;	//0.2
	};
};

class RC_230mmAirburstDust
{
	class MissileCircleDust
	{
		simulation="particles";
		type="RC_230mmCircleDust";
		enabled="distToWater interpolate [0.05,0.06,-1,1]";
		position[]={0,0,0};
		intensity=1;
		interval=1;
		lifeTime=0.2;	//0.2
	};
	class CircleDust
	{
		simulation="particles";
		type="RC_230mmCircleDust";
		enabled="distToWater interpolate [0.05,0.06,-1,1]";
		position[]={0,0,0};
		intensity=1;
		interval=1;
		lifeTime=0.2;	//0.2
	};
};

class RC_604mmAirburstDust
{
	class MissileCircleDust
	{
		simulation="particles";
		type="RC_604mmCircleDust";
		enabled="distToWater interpolate [0.05,0.06,-1,1]";
		position[]={0,0,0};
		intensity=1;
		interval=1;
		lifeTime=0.2;	//0.2
	};
	class CircleDust
	{
		simulation="particles";
		type="RC_604mmCircleDust";
		enabled="distToWater interpolate [0.05,0.06,-1,1]";
		position[]={0,0,0};
		intensity=1;
		interval=1;
		lifeTime=0.2;	//0.2
	};
};

//explosioneffects
class RC_MortarExplosion
{
	class Light1
	{
		simulation="light";
		type="GrenadeExploLight";
		position[]={0,0,0};
		intensity=0.0099999998;
		interval=1;
		lifeTime=1;
	};
	class MortarExp1
	{
		simulation="particles";
		type="RC_MortarExp";
		position[]={0,0,0};
		intensity=1;
		interval=1;
		lifeTime=0.5;
	};
	class MortarSmoke1
	{
		simulation="particles";
		type="CloudBigDark";
		position[]={0,0,0};
		intensity=1;
		interval=1;
		lifeTime=1;
	};
};