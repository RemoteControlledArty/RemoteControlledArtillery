class HorizonBankSource
{
	type="rotational";
	source="HorizonBank";
	center[]={0.5,0.5};
	min=-6.2831001;
	max=6.2831001;
	minAngle=-360;
	maxAngle=360;
};
class HorizonDiveSource
{
	source="horizonDive";
	type="linear";
	min=-1;
	max=1;
	minPos[]={0.5,2.5};
	maxPos[]={0.5,-1.5};
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