//throwable
class GrenadeLauncher;
class Throw: GrenadeLauncher {

	class ThrowMuzzle: GrenadeLauncher {};
	class Interceptor_MP2_ThrowMuzzle: 			ThrowMuzzle {magazines[] = {"Interceptor_MP2_Throw"};			};

	muzzles[]+=
	{
		"Interceptor_MP2_ThrowMuzzle"
	};
};