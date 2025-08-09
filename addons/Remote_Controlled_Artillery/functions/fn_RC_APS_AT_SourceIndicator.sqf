/*
	Author: Ascent

	Description:
	Warning sound fired at by any AT (except player fired unguided), if line of sight marks source of fire briefly in datalink.
*/

params ['_target','_ammo','_vehicle','_instigator','_missile'];

if ((_target distance _vehicle) > 4000) exitwith {};

private _crew = (crew _target) select {isPlayer _x};
[['\A3\Sounds_F\vehicles\air\noises\alarm_locked_by_missile_1.wss', 0.3]] remoteExec ['playSoundUI', _crew];

private _controllers = (UAVControl _target);
private _controller1 = _controllers select 0;
if (_controller1 isNotEqualTo objNull) then {
	[['\A3\Sounds_F\vehicles\air\noises\alarm_locked_by_missile_1.wss', 0.3]] remoteExec ['playSoundUI', _controller1];

	if (count _controllers > 2) then {
		private _controller2 = _controllers select 3;
		[['\A3\Sounds_F\vehicles\air\noises\alarm_locked_by_missile_1.wss', 0.3]] remoteExec ['playSoundUI', _controller2];
	};
};

if (!RC_AT_SourceIndicationStatic && !RC_AT_SourceIndicationInf && !RC_AT_SourceIndicationVic) exitwith {};
if (([_vehicle, 'GEOM', _target] checkVisibility [eyePos _vehicle, eyePos _target]) == 0) exitwith {};

private _side = side _target;
if (_vehicle isKindOf 'StaticWeapon' && RC_AT_SourceIndicationStatic) then {
	[_side,[_vehicle, 300]] remoteExec ['reportRemoteTarget', _side];
	[_vehicle, [_side, true]] remoteExec ['confirmSensorTarget', _side];
} else {
	if (_vehicle isKindOf 'Man'	&& RC_AT_SourceIndicationInf) then {
		[_side,[_vehicle, 10]] remoteExec ['reportRemoteTarget', _side];
		[_vehicle, [_side, true]] remoteExec ['confirmSensorTarget', _side];
	} else {
		if (RC_AT_SourceIndicationVic) then {
			[_side,[_vehicle, 20]] remoteExec ['reportRemoteTarget', _side];
			[_vehicle, [_side, true]] remoteExec ['confirmSensorTarget', _side];
		};
	};
};

/*
private _prevCargesAPS = (_uav getVariable ["RC_cargesAPS", 0, true]);
private _curCargesAPS = _prevCargesAPS - 1;
[_uav, ["RC_cargesAPS", _curCargesAPS], true] remoteExec ["setVariable", 0, true];
*/


//turns turret to AT source
//_target lockCameraTo [_vehicle, [0], true];	//gunner
_target lockCameraTo [_vehicle, [0,0], true];	//commander


private _chargesAPS = _target getVariable ["RC_chargesAPS", -1];	//-1 = default return value
if (_chargesAPS == -1) then {_chargesAPS = 3;};

systemchat str _chargesAPS;

if (_chargesAPS > 0) then {
	systemchat "passed";

	private _nextChargesAPS = _chargesAPS - 1;
	_nextChargesAPSstr = str _nextChargesAPS;
	if (local target) then {
		_target setVariable ["RC_chargesAPS", _nextChargesAPS, true];	//true is public without RE
	};

	_missile addEventHandler ["SubmunitionCreated", {
		params ["_projectile", "_submunitionProjectile"];
		/*
		private _submunDir = getDir _submunitionProjectile;
		systemchat "_submunDir" + str _submunDir;
		_submunitionProjectile setDir -_submunDir;

		private _submunDir2 = getDir _submunitionProjectile;
		systemchat "_submunDir" + str _submunDir2;

		triggerAmmo _submunitionProjectile;
		*/
		deleteVehicle _submunitionProjectile;
	}];
	
	[_target, _missile, _nextChargesAPSstr] spawn
	{
		systemchat "spawned";
		params ["_target","_missile", "_nextChargesAPSstr"];
		//systemchat "waiting for APS";

		while {(alive _target) and (alive _missile)} do
		{
			//systemchat "while APS";

			//sleep 0.01;
			if ((_missile distance _target) <= 30) exitwith {
				triggerAmmo _missile;
				systemchat "activated APS, " + _nextChargesAPSstr + " charges remaining";
			};
		};
	};
};