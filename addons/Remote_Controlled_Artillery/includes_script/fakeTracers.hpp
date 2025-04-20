fired="params ['_unit','_weapon','_muzzle','_mode','_ammo','_magazine','_projectile','_gunner'];	\
if (!local _gunner) exitWith {};	\
if ((_ammo find 'HEAB' == -1) && (_ammo find 'MPAB' == -1)) exitWith {};	\
private _matches = _ammo regexFind ['\\d{2,3}(?=mm)'];	\
private _caliberStr = '20';	\
if (count _matches > 0) then {	\
	_caliberStr = (_matches select 0) select 0;	\
};	\
private _caliber = parseNumber _caliberStr;	\
private _flareSize = (_caliber / 20) * 0.17;	\
private _lightColor = [1,1,1];	\
private _lightColorAmbient = [0.1,0.1,0.1];	\
switch true do {	\
	case (_ammo find 'T_R' > -1): { _lightColor = [1, 0.175, 0];};	\
	case (_ammo find 'T_G' > -1): { _lightColor = [0.225, 1, 0];};	\
	case (_ammo find 'T_Y' > -1): { _lightColor = [1, 1, 0.1];};	\
};	\
[_projectile, _lightColor, _flareSize] spawn {	\
	params ['_projectile','_lightColor','_flareSize'];	\
	waitUntil {!isNull _projectile && alive _projectile };	\
	private _light = '#lightpoint' createVehicle [0,0,0];	\
	_light setLightColor _lightColor;	\
	_light setLightBrightness 0.8;	\
	_light setLightAmbient [0,0,0];	\
	_light setLightIntensity 4000;	\
	_light setLightUseFlare true;	\
	_light setLightFlareSize 0.25;	\
	_light setLightFlareMaxDistance 5000;	\
	_light lightAttachObject [_projectile, [0,0,0]];	\
	waitUntil {! alive _projectile or isNull _projectile };	\
	deleteVehicle _light;	\
};";