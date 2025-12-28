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
class Limit0109
{
	type="limit";
	limits[]={0.1,0.1,0.89999998,0.89999998};
};