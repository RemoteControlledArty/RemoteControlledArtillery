class B_Crocus_AT;
class RC_Crocus_MP_Base: B_Crocus_AT
{
	class Turrets;
	class MainTurret;
	class ViewOptics;
	class Components;
	scope=0;
	scopeCurator=0;
	RC_Local=1; //1 = requires transfer of locality/ownership for full functionality
};
class RC_Crocus_MP: RC_Crocus_MP_Base
{
	author="Ascent";
	displayName="Crocus MP";
	faction="RemoteControlled_B";
	scope=0;
	scopeCurator=0;
	side=1;
	forceInGarage=1;
	
	//enginePower=1000;	//800
	//peakTorque=4000;	//3400
	//fuelCapacity=8.5;
	
	maxSpeed=180;	//140
	liftForceCoef=2;	//1
	cyclicAsideForceCoef=2;	//2
	cyclicForwardForceCoef=1.2;	//2
	mainRotorSpeed=-7;	//-7
	backRotorSpeed=7;	//7

	camouflage=0.5;	//0.5
	audible=0.5;	//0.1
	backRotorForceCoef=5;	//5
	radarTargetSize=0.05;	//0.1
	visualTargetSize=0.05;	//0.1


	class assembleInfo
	{
		assembleTo="";
		dissasembleTo[]=
		{
			"O_Crocus_AP_Bag"
		};
		displayName="";
	};

	typicalCargo[]=
	{
		"B_UAV_AI"
	};
};