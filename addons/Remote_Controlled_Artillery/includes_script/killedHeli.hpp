//MPKilled
Killed=
"params ['_unit']; \
if ( (!local _unit) && (_unit isNotEqualTo (getConnectedUAV player)) ) exitwith {}; \
[_unit] call RC_fnc_RC_OMH_Side;";