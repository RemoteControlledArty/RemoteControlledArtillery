params ["_uav", "_position", "_magazine"];

private _time = time + 600;     //10min flight time
private _camera   = localNameSpace getVariable ["RC_Interceptor_camera", objNull];
private _PP_colorC = localNameSpace getVariable ["RC_Interceptor_PP_colorC",  -1];
private _PP_dynamic = localNameSpace getVariable ["RC_Interceptor_PP_dynamic",  -1];
private _PP_film = localNameSpace getVariable ["RC_Interceptor_PP_film",  -1];
private _idEachFrame = localNameSpace getVariable ["RC_Interceptor_idEachFrame", -1];
private _idEventHead = localNameSpace getVariable ["RC_Interceptor_EventHead", -1];
private _idMouse     = localNameSpace getVariable ["RC_Interceptor_idMouse", -1];
private _idNvg       = localNameSpace getVariable ["RC_Interceptor_idNvg", -1]; 
private _idSlowDown  = localNameSpace getVariable ["RC_Interceptor_idSlowDown", -1]; 
private _idUpSpeed   = localNameSpace getVariable ["RC_Interceptor_idUpSpeed", -1]; 
private _controls    = localNameSpace getVariable ["RC_Interceptor_controls", []];
private _ammo = getText (configFile >> "CfgMagazines" >> _magazine >> "ammo");

waitUntil {
    !(canMove _uav) ||
    ((_uav distance _position) > 10000) ||
    (time > _time)
};

deleteVehicle ((attachedObjects _ammo)#0);  //removes target
_ammo = createVehicle [_ammo, (_uav modelToWorld [0, 0, 0]), [], 0, "CAN_COLLIDE"];
_ammo setVectorDirAndUp [vectorDir _camera, vectorUp _camera];

ppEffectDestroy _PP_colorC;
ppEffectDestroy _PP_dynamic;
ppEffectDestroy _PP_film;

removeMissionEventHandler ["EachFrame", _idEachFrame];
removeMissionEventHandler ["EachFrame", _idEventHead];

findDisplay 46 displayRemoveEventHandler ["KeyDown", _idNvg];

_controls apply { ctrlDelete _x };
    
deleteVehicle _uav;

camUseNVG false;
false setCamUseTI 1;

_camera cameraEffect ["terminate","back"];
camDestroy _camera;

cutText ["", "PLAIN"];
"SB_RscCompass" cutText ["", "PLAIN"];