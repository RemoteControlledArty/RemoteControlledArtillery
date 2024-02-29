[
    "RC_ace_hotkey_warning",
    "CHECKBOX",
    ["ace hotkey warning", "Remember! If ace scope adjustments hotkey overlaps, it prevents artillery gun elevation, when using a zeroable scope."],
    ["Remote Controlled Artillery"],
    true,
    false,
    {},
    false
] call CBA_fnc_addSetting;

[
    "RC_Allow_Vanilla_Arty_Computer",
    "CHECKBOX",
    ["allow vanilla arty computer", "When this is ticked the vanilla Artillery Computer can be used, without ACE it cannot be disabled for Mortars. Vanilla computer has high trajectory only, so worse TOF."],
    ["Remote Controlled Artillery"],
    false,
    true,
    {},
    true
] call CBA_fnc_addSetting;

[
    "RC_Solution_Calculator_On",
    "CHECKBOX",
    ["allow EL solution calculator", "When this is ticked Elevation Solutions will be calculated and displayed."],
    ["Remote Controlled Artillery"],
    true,
    true,
    {},
    true
] call CBA_fnc_addSetting;

[
    "RC_Arty_EL_Diff",
    "CHECKBOX",
    ["elevation difference reference", "When ticked the Elevation Difference shown is the Target Compared to the Artillery Piece, if unticked the other way."],
    ["Remote Controlled Artillery"],
    true,
    true,
    {},
    true
] call CBA_fnc_addSetting;

[
    "RC_Update_Number",
    "SLIDER",
    ["artillery target update delay", "This number is how long it takes between Updating the possible Artillery Targets in Seconds."],
    ["Remote Controlled Artillery"],
    [1, 5, 1, 0, false],
    true
] call CBA_fnc_addSetting;

[
    "Remote Controlled Artillery",
    "RC_Scroll_Targets_Forwards",
    "scroll forward through possible targets",
    {true call RC_fnc_scrollSolutions},
    "",
	[6, [false, false, false]]
] call CBA_fnc_addKeybind;

[
    "Remote Controlled Artillery",
    "RC_Scroll_Targets_Backwards",
    "scroll backwards through possible targets",
    {false call RC_fnc_scrollSolutions},
    "",
	[4, [false, false, false]]
] call CBA_fnc_addKeybind;

[
    "RC_Marker_Prefix",
    "EDITBOX",
    ["artillery marker prefix", "This is the Prefix (Case Insensitive) that the Target Markers need to have to be considered a valid Target."],
    "Remote Controlled Artillery",
    "Arty"
] call CBA_fnc_addSetting;

[
    "RC_GPS_Prefix",
    "EDITBOX",
    ["GPS marker prefix", "This is the Prefix (Case Insensitive) that the Target Markers need to have to be considered a valid Target."],
    "Remote Controlled Artillery",
    "GPS"
] call CBA_fnc_addSetting;

//doesnt work with current UI setup
/*
[
    "RC_Show_Keybinds",
    "CHECKBOX",
    ["Show Keybinds Display", "shows the faint Display of Keybinds for Artillery Functions"],
    ["Remote Controlled Artillery"],
    true,
    false,
    {},
    true
] call CBA_fnc_addSetting;
*/

