class CfgPatches
{
	class RC_GX_Dev
	{
		name="RC GX Dev";
		author="Ascent";

		units[]=
		{
			"RC_InterceptorMissile_Target_B",
			"RC_InterceptorMissile_Target_O",
			"RC_InterceptorMissile_Target_I"
		};

		requiredAddons[]=
		{
			"cba_main",
			"RC_Artillery",
			"gx_drones_uav_hunter"
		};

		skipWhenMissingDependencies=1;
	};
};


class CfgAmmo
{
	class RC_Interceptor_Direct_10m_Pre;
	class RC_Interceptor_Direct_10m: RC_Interceptor_Direct_10m_Pre
	{
		scope=1;
		model="\gx_drones\uav_hunter\Data\Models\GX_Hunter_SP.p3d";
	};
	class RC_Interceptor_Direct_5m_Pre;
	class RC_Interceptor_Direct_5m: RC_Interceptor_Direct_5m_Pre
	{
		scope=1;
		model="\gx_drones\uav_hunter\Data\Models\GX_Hunter_SP.p3d";
	};
	class RC_Interceptor_Direct_1m_Pre;
	class RC_Interceptor_Direct_1m: RC_Interceptor_Direct_1m_Pre
	{
		scope=1;
		model="\gx_drones\uav_hunter\Data\Models\GX_Hunter_SP.p3d";
	};


	class RC_Interceptor_Overfly_10m_Pre;
	class RC_Interceptor_Overfly_10m: RC_Interceptor_Overfly_10m_Pre
	{
		scope=1;
		model="\gx_drones\uav_hunter\Data\Models\GX_Hunter_SP.p3d";
	};
	class RC_Interceptor_Overfly_5m_Pre;
	class RC_Interceptor_Overfly_5m: RC_Interceptor_Overfly_5m_Pre
	{
		scope=1;
		model="\gx_drones\uav_hunter\Data\Models\GX_Hunter_SP.p3d";
	};


	class RC_Interceptor_TopDown_10m_Pre;
	class RC_Interceptor_TopDown_10m: RC_Interceptor_TopDown_10m_Pre
	{
		scope=1;
		model="\gx_drones\uav_hunter\Data\Models\GX_Hunter_SP.p3d";
	};
	class RC_Interceptor_TopDown_5m_Pre;
	class RC_Interceptor_TopDown_5m: RC_Interceptor_TopDown_5m_Pre
	{
		scope=1;
		model="\gx_drones\uav_hunter\Data\Models\GX_Hunter_SP.p3d";
	};
	class RC_Interceptor_TopDown_1m_Pre;
	class RC_Interceptor_TopDown_1m: RC_Interceptor_TopDown_1m_Pre
	{
		scope=1;
		model="\gx_drones\uav_hunter\Data\Models\GX_Hunter_SP.p3d";
	};


	class RC_Interceptor_Cruise_10m_Pre;
	class RC_Interceptor_Cruise_10m: RC_Interceptor_Cruise_10m_Pre
	{
		scope=1;
		model="\gx_drones\uav_hunter\Data\Models\GX_Hunter_SP.p3d";
	};
	class RC_Interceptor_Cruise_5m_Pre;
	class RC_Interceptor_Cruise_5m: RC_Interceptor_Cruise_5m_Pre
	{
		scope=1;
		model="\gx_drones\uav_hunter\Data\Models\GX_Hunter_SP.p3d";
	};
	class RC_Interceptor_Cruise_1m_Pre;
	class RC_Interceptor_Cruise_1m: RC_Interceptor_Cruise_1m_Pre
	{
		scope=1;
		model="\gx_drones\uav_hunter\Data\Models\GX_Hunter_SP.p3d";
	};
};


class CfgVehicles
{
	class RC_InterceptorMissile_Target_B_Pre;
	class RC_InterceptorMissile_Target_B: RC_InterceptorMissile_Target_B_Pre
	{
		model="\gx_drones\uav_hunter\Data\Models\GX_Hunter_SP.p3d";
		proxyShape="\gx_drones\uav_hunter\Data\Models\GX_Hunter_SP.p3d";
	};
	class RC_InterceptorMissile_Target_O_Pre;
	class RC_InterceptorMissile_Target_O: RC_InterceptorMissile_Target_O_Pre
	{
		model="\gx_drones\uav_hunter\Data\Models\GX_Hunter_SP.p3d";
		proxyShape="\gx_drones\uav_hunter\Data\Models\GX_Hunter_SP.p3d";
	};
	class RC_InterceptorMissile_Target_I_Pre;
	class RC_InterceptorMissile_Target_I: RC_InterceptorMissile_Target_I_Pre
	{
		model="\gx_drones\uav_hunter\Data\Models\GX_Hunter_SP.p3d";
		proxyShape="\gx_drones\uav_hunter\Data\Models\GX_Hunter_SP.p3d";
	};
};