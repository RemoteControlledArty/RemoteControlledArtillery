fired="params ['_u','_w','_mu','_mo','_a','_ma','_p','_g']; \
if ((_ammo find 'HEAB' == -1) and (_ammo find 'MPAB' == -1)) exitWith {}; \
private _mR = 4000; \
private _sG = side _g; \
private _t = allUnits select { \
	alive _x && \
	(_x distance _g) <= _mR && \
	(side _x) != _sG && \
	(side _x) != civilian \
}; \
private _tDL = ((listRemoteTargets _sG) apply {_x select 0}) select { \
	((_x isKindOf 'LaserTarget') or (_x isKindOf 'RC_GPSDatalinkTarget')) && \
	(_x distance _g) <= _mR \
}; \
{ _t pushBackUnique _x } forEach _tDL; \
if (_t isEqualTo []) exitWith {}; \
private _r = 7; \
[_p, _r, _t] spawn { \
	params ['_p','_r','_t']; \
	waitUntil { sleep 0.015; !isNull _p && alive _p }; \
	private _done = false; \
	while { alive _p } do { \
		sleep 0.005; \
		{ \
			if ((_p distance _x) <= _r) then { \
				triggerAmmo _p; \
				_done = true; \
			}; \
		} forEach _t; \
	}; \
};";