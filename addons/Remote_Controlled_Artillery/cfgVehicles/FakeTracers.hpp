class ThingEffect;
class RCfakeTracerW : ThingEffect
{
	scope = 2;
	simulation = "thingEffect";
	destrType = "DestructNo";
	armor = 0;
	cost = 0;
	timeToLive=4;

	displayName = "Tracer While";
	model="\A3\Weapons_f\Data\bullettracer\tracer_white";
};
class RCfakeTracerR : RCfakeTracerW
{
	displayName = "Tracer Red";
	model = "\A3\Weapons_f\Data\bullettracer\tracer_red";
};
class RCfakeTracerG : RCfakeTracerW
{
	displayName = "Tracer Green";
	model = "\A3\Weapons_f\Data\bullettracer\tracer_green";
};
class RCfakeTracerY : RCfakeTracerW
{
	displayName = "Tracer Yellow";
	model = "\A3\Weapons_f\Data\bullettracer\tracer_yellow";
};