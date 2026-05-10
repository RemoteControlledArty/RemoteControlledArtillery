/*
 * Author: Ascent
 * Store settings.
*/

0 spawn {
	sleep 1;

	if (isClass (configFile >> "CfgPatches" >> "ace_main")) then {
		RC_PrevAirRes = ace_artillerytables_advancedCorrections;	//stores setting
		RC_PrevAirResMortar = ace_mk6mortar_airResistanceEnabled;	//stores setting
	};
};
