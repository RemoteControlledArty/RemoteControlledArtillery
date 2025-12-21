RC_INTERCEPTOR_SIGNAL=1;    //pre/re-define

private _effect_1 = missionNameSpace getVariable ["RC_fpv_ppEffect", []];
private _adjust = linearConversion [1, 0, RC_INTERCEPTOR_SIGNAL, 0.1, 1.0];

if (_effect_1 isNotEqualTo []) then {
	{
		ppEffectDestroy _x;
	} forEach _ppEffect;
};

private _PP_colorC = ppEffectCreate ["ColorCorrections", 1500];
_PP_colorC ppEffectEnable true;
_PP_colorC ppEffectAdjust [[1.08, 1.2, _adjust] call BIS_fnc_lerp, [0.67, 1, _adjust] call BIS_fnc_lerp, 0.06, [0,0,0.45,0.06], [1,1,0.93,1.61], [0.33, 0.33, 0.15, 0.2], [0, 0, 0, 0, 0, 0, 5]];
_PP_colorC ppEffectCommit 0;

private _PP_dynamic = ppEffectCreate ["DynamicBlur", 500];
_PP_dynamic ppEffectEnable true;
_PP_dynamic ppEffectAdjust [[0.2, 0.7, _adjust] call BIS_fnc_lerp];
_PP_dynamic ppEffectCommit 0;

private _PP_film = ppEffectCreate ["FilmGrain", 2000];
_PP_film ppEffectEnable true;
_PP_film ppEffectAdjust [[0.04, 1, _adjust] call BIS_fnc_lerp, 1, [4.09, 4.5, _adjust] call BIS_fnc_lerp, 0.5, 0.5, true];
_PP_film ppEffectCommit 0;


private _display = findDisplay 46 createDisplay "RscDisplayEmpty";

_display displayAddEventHandler ["Unload", {
    localNameSpace setVariable ["RC_Interceptor_display", displayNull];
}];

private _mapHover = _display ctrlCreate ["ctrlMapEmpty", -1];
_mapHover ctrlSetPosition [
    safeZoneXAbs,
    safeZoneY,
    safeZoneWAbs,
    0.5
];
_mapHover ctrlSetFade 1;
_mapHover ctrlCommit 0.0;
_mapHover ctrlMapCursor ["", "RC_Blank"];

private _controlDate = _display ctrlCreate ["RscStructuredText", -1];
_controlDate ctrlSetFontHeight 0.06;
_controlDate ctrlSetPosition [
    safeZoneX,
    safeZoneY,
    safeZoneW,
    0.5
];
_controlDate ctrlCommit 0.0;

private _controlCoord = _display ctrlCreate ["RscStructuredText", -1];
_controlCoord ctrlSetFontHeight 0.075;
_controlCoord ctrlSetPosition [
    safeZoneX,
    safeZoneY,
    safeZoneW,
    0.5
];
_controlCoord ctrlCommit 0.0;

private _controlSpeed = _display ctrlCreate ["RscStructuredText", -1];
_controlSpeed ctrlSetFontHeight 0.075;
_controlSpeed ctrlSetPosition [
    safeZoneX,
    safeZoneY + safeZoneH - 0.5,
    safeZoneW,
    0.5
];
_controlSpeed ctrlCommit 0.0;

localNameSpace setVariable ["RC_Interceptor_PP_colorC",  _PP_colorC];
localNameSpace setVariable ["RC_Interceptor_PP_dynamic",  _PP_dynamic];
localNameSpace setVariable ["RC_Interceptor_PP_film",  _PP_film];

localNameSpace setVariable ["RC_Interceptor_controls", [_controlCoord, _controlDate, _controlSpeed]];
localNameSpace setVariable ["RC_Interceptor_display", _display];