/*
    RC UI OnUnload
*/

diag_log "[RC][UI] onUnload fired";
systemChat "[RC] UI unloaded";

uiNamespace setVariable ["RC_UI_Active", false];
uiNamespace setVariable ["RC_ui", nil];
uiNamespace setVariable ["RC_Artillery", nil];


/*
uiNamespace setVariable ["RC_UI_Active", false];
uiNamespace setVariable ["RC_ui", nil];
uiNamespace setVariable ["RC_state", nil];
uiNamespace setVariable ["RC_vehicle", nil];
*/