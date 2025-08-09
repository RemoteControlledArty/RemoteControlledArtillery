/*
	Author: Ascent

	Description:
	APS
*/

params ["_unit", "_weapon", "_muzzle", "_mode", "_ammo", "_magazine", "_projectile", "_gunner"];

if (!isServer) exitwith {};

//maybe use single array but add radar side check, as that could prevent post spawn side change issues
//checks for opposing APS vehicles
private _APS_AliveAmount_B = ({alive _x} count RC_APS_Array_B);
private _APS_AliveAmount_O = ({alive _x} count RC_APS_Array_O);
private _APS_AliveAmount_I = ({alive _x} count RC_APS_Array_I);

private _APS_AliveAmount = _APS_AliveAmount_B + _APS_AliveAmount_O + _APS_AliveAmount_I;
if (!(_APS_AliveAmount > 0)) exitwith {};


//cleans up APS arrays
RC_APS_Array_B = RC_APS_Array_B - [objNull];
RC_APS_Array_O = RC_APS_Array_O - [objNull];
RC_APS_Array_I = RC_APS_Array_I - [objNull];

//checks side of the unit which fired
private _unitSide_B = (side _unit == west);
private _unitSide_O = (side _unit == east);
private _unitSide_I = (side _unit == resistance);

//checks opposing sides
private _opposedTo_B = [side _unit, west] call BIS_fnc_sideIsEnemy;
private _opposedTo_O = [side _unit, east] call BIS_fnc_sideIsEnemy;
private _opposedTo_I = [side _unit, resistance] call BIS_fnc_sideIsEnemy;


if (_opposedTo_B and (_APS_AliveAmount_B > 0)) then {
	[_vehicle] call RC_fnc_RC_AI_CBRad_Blufor;
};
if (_opposedTo_O and (_APS_AliveAmount_O > 0)) then {
	[_vehicle] call RC_fnc_RC_AI_CBRad_Opfor;
};
if (_opposedTo_I and (_APS_AliveAmount_I > 0)) then {
	[_vehicle] call RC_fnc_RC_AI_CBRad_Indfor;
};


/*
private _lastTime = _vehicle getVariable "ArtySourceTime";
private _timeSinceLast = time - _lastTime;

if (_timeSinceLast > RC_IgnoreTime_F1) then {
	_vehicle setVariable ["ArtySourceTime", time, true];
};
*/


//if (RC_M_APS_Vic);

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