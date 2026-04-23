class vve_autocannon_35mm;
class RC_Single_autocannon_35mm_AA_base: vve_autocannon_35mm
{
	class AutoFast;
	class AutoSlow;

	class close;
	class short;
	class medium;
	class far;
};
class RC_Single_autocannon_35mm_AA: RC_Single_autocannon_35mm_AA_base
{
	author="Ascent";
	displayName="35mm SHORAD";

	magazineReloadTime=20;
	canLock=2;
	ballisticsComputer="2 + 4";	//why 2?

	magazines[]=
	{
		"RC_600Rnd_35mm_HEAB_AA_T_R",
		"RC_600Rnd_35mm_HEAB_AA_T_G",
		"RC_600Rnd_35mm_HEAB_AA_T_Y",
		"RC_600Rnd_35mm_MPAB_AA_T_R",
		"RC_600Rnd_35mm_MPAB_AA_T_G",
		"RC_600Rnd_35mm_MPAB_AA_T_Y"
	};

	modes[]=
	{
		"AutoSlow",
		"AutoFast",
		//"Direct",

		"close",
		"short",
		"medium",
		"far"
	};
	
	class AutoSlow: AutoSlow
	{
		magazineReloadTime=20;
		canLock=2;
		ballisticsComputer="2 + 4";

		displayName="35mm SHORAD";
		reloadTime=0.2;
		dispersion=0.002;	//0.002
	};
	class AutoFast: AutoFast
	{
		magazineReloadTime=20;
		canLock=2;
		ballisticsComputer="2 + 4";

		displayName="35mm SHORAD";
		reloadTime=0.05;
		dispersion=0.002;	//0.002
	};
	/*
	class Direct: AutoFast
	{
		magazineReloadTime=20;
		canLock=2;
		#include "\Remote_Controlled_Artillery\includes_cfg\BallisticsCalculatorCannon.hpp"
		maxZeroing=4000;

		displayName="35mm Direct";
		reloadTime=0.06;
		dispersion=0.0008;
	};
	*/

	class close: close
	{
		magazineReloadTime=20;
		reloadTime=0.2;
	};
	class short: short
	{
		magazineReloadTime=20;
		reloadTime=0.2;
	};
	class medium: medium
	{
		magazineReloadTime=20;
		reloadTime=0.2;
	};
	class far: far
	{
		magazineReloadTime=20;
		reloadTime=0.2;
	};
};