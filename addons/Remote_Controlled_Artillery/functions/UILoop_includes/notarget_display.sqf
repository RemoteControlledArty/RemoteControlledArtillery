// If we don't have any Valid Targets
_ctrlAzimuth ctrlSetTextColor [1, 1, 1, 1];
_ctrlElevation ctrlSetTextColor [1, 1, 1, 1];

_ctrlDistance ctrlSetText "DIST: 0000";
_ctrlTarget ctrlSetText "T: 0";
_ctrlTargetAzimuth ctrlSetText "T AZ: 0000";
_ctrlDifference ctrlSetText "DIF: 0000" ;
_ctrlHighSol ctrlSetText "high EL: 0000";
_ctrlLowSol ctrlSetText "low EL: 0000";
_ctrlHighETA ctrlSetText "ETA: 000";
_ctrlLowETA ctrlSetText "ETA: 000";

// If we have no Targets
_ctrlMessage ctrlSetTextColor [1, 0, 0, 1];
_ctrlMessage ctrlSetPositionX (0.868267 * safezoneW + safezoneX);
_ctrlMessage ctrlSetText format ["ADD MAP MARKER: %1%2", RC_Marker_Prefix, "1-99 / gps"];