// if we don't have any valid targets
_ctrlAzimuth ctrlSetTextColor [1, 1, 1, 1];
_ctrlElevation ctrlSetTextColor [1, 1, 1, 1];

_ctrlDistance ctrlSetText "DIST: 0000";
_ctrlNewTarget ctrlSetText "T: 0";
_ctrlTargetAzimuth ctrlSetText "T AZ: 0000";
_ctrlDifference ctrlSetText "DIF: 0000";
_ctrlHighSol ctrlSetText "high EL: 0000";
_ctrlMediumSol ctrlSetText "med EL: 0000";
_ctrlHighETA ctrlSetText "ETA: 000";
_ctrlMediumETA ctrlSetText "ETA: 000";
_ctrlHighMV ctrlSetText "MV: 000";
_ctrlMediumMV ctrlSetText "MV: 000";

// if we have no targets
_ctrlMessage ctrlSetTextColor [1, 0, 0, 1];
_ctrlMessage ctrlSetPositionX (0.868267 * safezoneW + safezoneX);
_ctrlMessage ctrlSetText format ["ADD MAP MARKER: %1%2", RC_Marker_Prefix, "1-99 / gps"];