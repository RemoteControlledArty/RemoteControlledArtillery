[
    "RC_Arty_Computer_On",
    "CHECKBOX",
    ["Allow Artillery Computer", "When this is ticked the Artillery Computer can be Used"],
    ["Remote Controlled Artillery"],
    true,
    true,
    {},
    true
] call CBA_fnc_addSetting;

[
    "RC_Solution_Calculator_On",
    "CHECKBOX",
    ["Allow EL Solution Calculator", "When this is ticked Elevation Solutions will be calculated and displayed."],
    ["Remote Controlled Artillery"],
    true,
    true,
    {},
    true
] call CBA_fnc_addSetting;

[
    "RC_Arty_EL_Diff",
    "CHECKBOX",
    ["Elevation Difference Reference", "When ticked the Elevation Difference shown is the Target Compared to the Artillery Piece."],
    ["Remote Controlled Artillery"],
    true,
    true,
    {},
    true
] call CBA_fnc_addSetting;

[
    "RC_Update_Number",
    "SLIDER",
    ["Artillery Target Update Delay", "This number is how long it takes between Updating the possible Artillery Targets in Seconds."],
    ["Remote Controlled Artillery"],
    [2, 10, 2, 0, false],
    true
] call CBA_fnc_addSetting;

[
    "Remote Controlled Artillery",
    "RC_Scroll_Targets_Forwards",
    "Scroll Forward through Possible Targets",
    {true call RC_fnc_scrollSolutions},
    "",
	[6, [false, false, false]]
] call CBA_fnc_addKeybind;

[
    "Remote Controlled Artillery",
    "RC_Scroll_Targets_Backwards",
    "Scroll Backwards through Possible Targets",
    {false call RC_fnc_scrollSolutions},
    "",
	[4, [false, false, false]]
] call CBA_fnc_addKeybind;

[
    "RC_Marker_Prefix",
    "EDITBOX",
    ["Artillery Marker Prefix", "This is the Prefix (Case Insensitive) that the Target Markers need to have to be considered a valid Target."],
    "Remote Controlled Artillery",
    "Arty"
] call CBA_fnc_addSetting;
