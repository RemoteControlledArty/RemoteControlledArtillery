//throwable
class GrenadeLauncher;
class Throw: GrenadeLauncher {

	class ThrowMuzzle: GrenadeLauncher {};
	class Interceptor_MP_ThrowMuzzle: 			ThrowMuzzle {magazines[] = {"Interceptor_MP_Throw"};			};

	muzzles[]+=
	{
		"Interceptor_MP_ThrowMuzzle"
	};
};