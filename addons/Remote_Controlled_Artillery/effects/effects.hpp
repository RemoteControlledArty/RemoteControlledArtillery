//cratereffects
class RC_CircleDust_Base
{
	simulation="particles";
	enabled="distToWater interpolate [0.05,0.06,-1,1]";
	position[]={0,0,0};
	intensity=1;
	interval=1;
	lifeTime=0.2;
};

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
	class RC_CircleDust: RC_CircleDust_Base
	{
		type="RC_82mmCircleDust";
	};
};

class RC_82mmGuidedDust
{
	class RC_CircleDust: RC_CircleDust_Base
	{
		type="RC_82mmGuidedCircleDust";
	};
};

class RC_105mmAirburstDust
{
	class RC_CircleDust: RC_CircleDust_Base
	{
		type="RC_105mmCircleDust";
	};
};

class RC_105mmGuidedDust
{
	class RC_CircleDust: RC_CircleDust_Base
	{
		type="RC_105mmGuidedCircleDust";
	};
};

class RC_120mmAirburstDust
{
	class RC_CircleDust: RC_CircleDust_Base
	{
		type="RC_120mmCircleDust";
	};
};
class RC_120mmGuidedDust
{
	class RC_CircleDust: RC_CircleDust_Base
	{
		type="RC_120mmGuidedDust";
	};
};

class RC_155mmAirburstDust
{
	class RC_CircleDust: RC_CircleDust_Base
	{
		type="RC_155mmCircleDust";
	};
};
class RC_155mmGuidedDust
{
	class RC_CircleDust: RC_CircleDust_Base
	{
		type="RC_155mmGuidedCircleDust";
	};
};

class RC_230mmAirburstDust
{
	class RC_CircleDust: RC_CircleDust_Base
	{
		type="RC_105mmCircleDust";
	};
};
class RC_230mmGuidedDust
{
	class RC_CircleDust: RC_CircleDust_Base
	{
		type="RC_230mmGuidedCircleDust";
	};
};

class RC_604mmAirburstDust
{
	class RC_CircleDust: RC_CircleDust_Base
	{
		type="RC_604mmCircleDust";
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

	//no effect?
	class SparksBig1
	{
		simulation="particles";
		type="ObjectDestructionSparks";
		position[]={0,0,0};
		intensity=0;
		interval=1;
		lifeTime=0;
	};
	class FireSparksBig1
	{
		simulation="particles";
		type="FireSparks";
		position[]={0,0,0};
		intensity=1;
		interval=1;
		lifeTime=2.8;
	};

	/*
	class MortarSmoke1
	{
		simulation="particles";
		type="CloudBigDark";
		position[]={0,0,0};
		intensity=1;
		interval=1;
		lifeTime=1;
	};
	*/
	/*
	class Explosion1
	{
		simulation="particles";
		type="ExplosionParticles";
		position[]={0,0,0};
		intensity=3;
		interval=1;
		lifeTime=0.25;
	};
	*/
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

/*
class HeavyBombExplosion;
class RC_HeavyBombExplosion: HeavyBombExplosion
{
	class ExpSparksBig
	{
		simulation="particles";
		type="ExpSparks";
		position[]={0,0,0};
		intensity=1;
		interval=1;
		lifeTime=0.5;
	};
	class ShardsBig
	{
		simulation="particles";
		type="ObjectDestructionShards";
		position="";
		intensity=1;
		interval=1;
		lifeTime=1;
	};
	class ShardsBig1
	{
		simulation="particles";
		type="ObjectDestructionShards1";
		position="";
		intensity=1;
		interval=1;
		lifeTime=1;
	};
	class ShardsBig2
	{
		simulation="particles";
		type="ObjectDestructionShards2";
		position="";
		intensity=1;
		interval=1;
		lifeTime=1;
	};
	class ShardsBig3
	{
		simulation="particles";
		type="ObjectDestructionShards3";
		position="";
		intensity=1;
		interval=1;
		lifeTime=1;
	};
	class ShardsBigBurn
	{
		simulation="particles";
		type="ObjectDestructionShardsBurning";
		position="";
		intensity=1;
		interval=1;
		lifeTime=1;
	};
	class ShardsBigBurn1
	{
		simulation="particles";
		type="ObjectDestructionShardsBurning1";
		position="";
		intensity=1;
		interval=1;
		lifeTime=1;
	};
	class ShardsBigBurn2
	{
		simulation="particles";
		type="ObjectDestructionShardsBurning2";
		position="";
		intensity=1;
		interval=1;
		lifeTime=1;
	};
	class ShardsBigBurn3
	{
		simulation="particles";
		type="ObjectDestructionShardsBurning3";
		position="";
		intensity=1;
		interval=1;
		lifeTime=1;
	};
	class LightExpBig
	{
		simulation="light";
		type="ExploLight";
		position[]={0,1.5,0};
		intensity=0.001;
		interval=1;
		lifeTime=0.5;
	};
	class Explosion1Big
	{
		simulation="particles";
		type="VehExplosionParticles";
		position[]={0,0,0};
		intensity=1;
		interval=1;
		lifeTime=0.2;
	};
	class BombExp1
	{
		simulation="particles";
		type="HeavyBombExp1";
		position[]={0,0,0};
		intensity=1;
		interval=1;
		lifeTime=0.2;
	};
	class Smoke1Big
	{
		simulation="particles";
		type="VehExpSmoke";
		position[]={0,0,0};
		intensity=1;
		interval=1;
		lifeTime=1;
	};
	class SmallSmoke1Big
	{
		simulation="particles";
		type="VehExpSmoke2";
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
*/