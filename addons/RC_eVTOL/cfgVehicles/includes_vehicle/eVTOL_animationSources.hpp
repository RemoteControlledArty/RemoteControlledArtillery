class AnimationSources: AnimationSources
{
	class Hide_BenchesBack: Hide_BenchesBack
	{
		initPhase=0;
        //forceAnimatePhase=0;  //1
		//lockCargo[] = {2,4,6,7};
	};
    class Hide_BenchesFront: Hide_BenchesFront
	{
		initPhase=0;
        //forceAnimatePhase=0;  //1
		//lockCargo[] = {2,4,6,7};
	};
};

animationList[]={"Hide_Door_L",1,"Hide_Door_R",1,"Hide_BenchesFront",0,"Hide_BenchesBack",0,"ExtendBoomStick",0};