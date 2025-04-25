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

/*
[
    "RC_Allow_Vanilla_Arty_Computer",
    "CHECKBOX",
    ["allow lame vanilla arty computer", "When this is ticked the vanilla Artillery Computer can be used, without ACE it cannot be disabled for Mortars. Vanilla computer has high trajectory only, so worse TOF and accuracy."],
    ["Remote Controlled Artillery"],
    false,
    true,
    {},
    true
] call CBA_fnc_addSetting;
*/

[
    "RC_allowPortableMortarComputer",
    "CHECKBOX",
    ["allow lame vanilla arty computer for portable mortars", "When this is ticked the vanilla Artillery Computer can be used for portable mortars, without ACE it cannot be disabled for Mortars. Vanilla computer has high trajectory only, so worse TOF and accuracy."],
    ["Remote Controlled Artillery"],
    false,
    true,
    {},
    true
] call CBA_fnc_addSetting;

[
    "RC_allowVehicleMortarComputer",
    "CHECKBOX",
    ["allow lame vanilla arty computer for vehicle mortars", "When this is ticked the vanilla Artillery Computer can be used for vehicle mortars, without ACE it cannot be disabled for Mortars. Vanilla computer has high trajectory only, so worse TOF and accuracy."],
    ["Remote Controlled Artillery"],
    false,
    true,
    {},
    true
] call CBA_fnc_addSetting;

[
    "RC_allowHowitzerComputer",
    "CHECKBOX",
    ["allow lame vanilla arty computer for howitzers", "When this is ticked the vanilla Artillery Computer can be used for howitzers, without ACE it cannot be disabled for Mortars. Vanilla computer has high trajectory only, so worse TOF and accuracy."],
    ["Remote Controlled Artillery"],
    false,
    true,
    {},
    true
] call CBA_fnc_addSetting;

[
    "RC_allowMLRSComputer",
    "CHECKBOX",
    ["allow lame vanilla arty computer for MLRS/MRL", "When this is ticked the vanilla Artillery Computer can be used for MLRS/MRL, without ACE it cannot be disabled for Mortars. Vanilla computer has high trajectory only, so worse TOF and accuracy."],
    ["Remote Controlled Artillery"],
    false,
    true,
    {},
    true
] call CBA_fnc_addSetting;

/*
//ace tables show false data currently, so for now this setting is removed and on by default
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
*/

[
    "RC_Arty_EL_Diff",
    "CHECKBOX",
    ["elevation difference reference", "When ticked the Elevation Difference shown is the Target compared to the Artillery Piece, if unticked the other way."],
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

[
    "RC_AT_SourceIndication",
    "CHECKBOX",
    ["allow AT fire source indicator", "Only for this mods vehicles that have missile/rocket detection systems, marks source of enemy AT fire in datalink for short period."],
    ["Remote Controlled Artillery"],
    true,
    true,
    {},
    true
] call CBA_fnc_addSetting;

/*
[
    "RC_DetectionTime_F1",
    "SLIDER",
    ["CBRad detection time", "CBRad detection time"],
    ["Remote Controlled Artillery"],
    [15, 30, 15, 0, false],
    true
] call CBA_fnc_addSetting;

[
    "RC_PrepTime_F1",
    "SLIDER",
    ["CB AI preperation time", "CB AI preperation time"],
    ["Remote Controlled Artillery"],
    [10, 30, 10, 0, false],
    true
] call CBA_fnc_addSetting;

[
    "RC_ReassignTime_F1",
    "SLIDER",
    ["CB reassign time", "reassign time setting"],
    ["Remote Controlled Artillery"],
    [15, 30, 15, 0, false],
    true
] call CBA_fnc_addSetting;

//testing
[
    "RC_DetectionTime_Test1",
    "SLIDER",
    ["TEST CBRad detection time", "TEST CBRad detection time"],
    ["Remote Controlled Artillery"],
    [5, 30, 15, 0, false],
    true
] call CBA_fnc_addSetting;

[
    "RC_PrepTime_Test1",
    "SLIDER",
    ["TEST CB AI preperation time", "TEST CB AI preperation time"],
    ["Remote Controlled Artillery"],
    [5, 30, 10, 0, false],
    true
] call CBA_fnc_addSetting;

[
    "RC_ReassignTime_Test1",
    "SLIDER",
    ["TEST CB reassign time", "TEST reassign time setting"],
    ["Remote Controlled Artillery"],
    [5, 30, 15, 0, false],
    true
] call CBA_fnc_addSetting;
*/

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