[
    "RC_Arty_Computer_On",
    "CHECKBOX",
    ["Allow Artillery Computer", "When this is Ticked the Artillery Computer can be Used"],
    ["Remote Controlled Artillery"],
    true,
    true,
    {},
    true
] call CBA_fnc_addSetting;

[
    "RC_Arty_EL_Diff",
    "CHECKBOX",
    ["Elevation Difference Reference", "When Ticked the Elevation Difference shown is the Target Compared to the Artillery Piece."],
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
    [4, 15, 10, 0, false],
    true
] call CBA_fnc_addSetting;

[
    "Remote Controlled Artillery",
    "RC_Target_Scroll_Forward",
    "Scroll Forward through Possible Targets",
    {true call RC_fnc_scrollSolutions},
    "",
	[5, [false, false, false]]
] call CBA_fnc_addKeybind;

[
    "Remote Controlled Artillery",
    "RC_Target_Scroll_Backward",
    "Scroll Backwards through Possible Targets",
    {false call RC_fnc_scrollSolutions},
    "",
	[3, [false, false, false]]
] call CBA_fnc_addKeybind;

[
    "RC_Marker_Prefix",
    "EDITBOX",
    ["Artillery Marker Prefix", "This is the Prefix (Case Insensitive) that the Target Markers need to have to be considered a valid Target."],
    "Remote Controlled Artillery",
    "Arty"
] call CBA_fnc_addSetting;
