//cratereffects
class RC_ArtyShellCrater
{
	class ShellStones
	{
		simulation="particles";
		type="DirtBig";
		position[]={0,0,0};
		intensity=1;
		interval=1;
		lifeTime=0.5;
	};
	class MissileCircleDust
	{
		simulation="particles";
		type="CircleDustBig";
		enabled="distToWater interpolate [0.0,0.01,-1,1]";
		position[]={0,0,0};
		intensity=1;
		interval=1;
		lifeTime=0.25;
	};
	class CircleDust
	{
		simulation="particles";
		type="RC_82mmCircleDust";
		enabled="distToWater interpolate [0.05,0.06,-1,1]";
		position[]={0,0,0};
		intensity=1;
		interval=1;
		lifeTime=0.2;
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
		lifeTime=0.2;
	};
	class CircleDust
	{
		simulation="particles";
		type="RC_82mmCircleDust";
		enabled="distToWater interpolate [0.05,0.06,-1,1]";
		position[]={0,0,0};
		intensity=1;
		interval=1;
		lifeTime=0.2;
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
		lifeTime=0.2;
	};
	class CircleDust
	{
		simulation="particles";
		type="RC_105mmCircleDust";
		enabled="distToWater interpolate [0.05,0.06,-1,1]";
		position[]={0,0,0};
		intensity=1;
		interval=1;
		lifeTime=0.2;
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
		lifeTime=0.2;
	};
	class CircleDust
	{
		simulation="particles";
		type="RC_120mmCircleDust";
		enabled="distToWater interpolate [0.05,0.06,-1,1]";
		position[]={0,0,0};
		intensity=1;
		interval=1;
		lifeTime=0.2;
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
		lifeTime=0.2;
	};
	class CircleDust
	{
		simulation="particles";
		type="RC_155mmCircleDust";
		enabled="distToWater interpolate [0.05,0.06,-1,1]";
		position[]={0,0,0};
		intensity=1;
		interval=1;
		lifeTime=0.2;
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
		lifeTime=0.2;
	};
	class CircleDust
	{
		simulation="particles";
		type="RC_230mmCircleDust";
		enabled="distToWater interpolate [0.05,0.06,-1,1]";
		position[]={0,0,0};
		intensity=1;
		interval=1;
		lifeTime=0.2;
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
		lifeTime=0.2;
	};
	class CircleDust
	{
		simulation="particles";
		type="RC_604mmCircleDust";
		enabled="distToWater interpolate [0.05,0.06,-1,1]";
		position[]={0,0,0};
		intensity=1;
		interval=1;
		lifeTime=0.2;
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
		type="MortarExp";
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
	class Shockwave
	{
		simulation="particles";
		type="ShellShockwave";
		position[]={0,0,0};
		intensity=1;
		interval= 1;
		lifeTime=1;
	};
};

class RC_GuidedExplosion
{
	class LightExp
	{
		simulation="light";
		type="ExploLight";
		position[]={0,1.5,0};
		intensity=0.001;
		interval=1;
		lifeTime=0.25;
	};
	class Explosion1
	{
		simulation="particles";
		type="ExplosionParticles";
		position[]={0,0,0};
		intensity=3;
		interval=1;
		lifeTime=0.25;
	};
	class SmallSmoke1
	{
		simulation="particles";
		type="CloudMedDark";
		position[]={0,0,0};
		intensity=1;
		interval=1;
		lifeTime=1;
	};
	class Shockwave
	{
		simulation="particles";
		type="ShellShockwave";
		position[]={0,0,0};
		intensity=1;
		interval= 1;
		lifeTime=1;
	};
};

class HeavyBombExplosion;
class RC_HeavyBombExplosion: HeavyBombExplosion
{
	class Shockwave
	{
		simulation="particles";
		type="ShellShockwave";
		position[]={0,0,0};
		intensity=1;
		interval= 1;
		lifeTime=1;
	};
};