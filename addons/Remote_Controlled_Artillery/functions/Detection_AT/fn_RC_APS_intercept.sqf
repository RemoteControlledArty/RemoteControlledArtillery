params ["_projPos", "_projVel", "_projDir", "_vic", "_vicCenter", "_chargesAPS"];

//systemchat "APS";	//debug

//countermeasure launch sound
playSound3D ["a3\sounds_f_mod\arsenal\weapons\smg\adr_97\adr_97_closeshot_01.wss", _vic, false, _vicCenter, 5, 0.8, 600];

private _dist = _projPos distance (getPosASL _vic);
private _timeOffset = ((_dist/2) min 15) / (vectorMagnitude _projVel);
private _interceptPosASL = [
	(_projPos #0) + (_projVel #0) * _timeOffset,
	(_projPos #1) + (_projVel #1) * _timeOffset,
	(_projPos #2) + (_projVel #2) * _timeOffset
];

_expl = "RC_APS_Expl_Scripted" createVehicle (ASLToATL _interceptPosASL);
private _explDir = -_projDir;
[_expl, _explDir] remoteExec ["setDir", 0];
_expl setDamage 1;

//_vic removeMagazineTurret ["RC_1Rnd_APS_M", [-1]];
private _vicOwner = owner _vic;
private _removeMagArr = ["RC_1Rnd_APS_M", [-1]];
[_vic, _removeMagArr] remoteExec ["removeMagazineTurret", _vicOwner];

private _nextChargesAPS = 0 max (_chargesAPS - 1);
private _string = "activated APS, " + str _nextChargesAPS + " remaining";
private _crew = (crew _vic) select {isPlayer _x};
[_string] remoteExec ["systemChat", _crew];