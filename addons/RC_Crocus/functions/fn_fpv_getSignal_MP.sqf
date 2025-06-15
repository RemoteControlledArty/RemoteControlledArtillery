params ["_player", "_uav"];


private _side = side _player;
private _maxDistance = 4000;
private _maxDistanceReceiver = 8000;
private _radius = _maxDistanceReceiver / 2;


private _retranslatorsUAV = [_uav, _radius, _side] call RC_fnc_fpv_findRetranslatorsUAV_MP;
private _retranslatorsUGV = [_uav, _radius, _side] call RC_fnc_fpv_findRetranslatorsUGV_MP;
private _retranslatorsAntenna = [_uav, _radius, _side] call RC_fnc_fpv_findRetranslatorsAntenna_MP;
private _retranslatorsBackpack = [_player, _radius, _side] call RC_fnc_fpv_findRetranslatorsBackpack_MP;
private _retranslatorsUGVandAntenna = _retranslatorsUGV + _retranslatorsAntenna;
//private _retranslatorsReceiver = _retranslatorsUAV + _retranslatorsUGV + _retranslatorsAntenna;
private _retranslatorsAll = _retranslatorsUAV + _retranslatorsUGV + _retranslatorsAntenna + _retranslatorsBackpack;


//also add Jammers, maybe add one with useraction that has to be actively used, "jam FPV's" within xmeters that jams all UV's for given time, which for type air results in ground crash
private _jammersNearUAV = [_uav, 1000] call RC_fnc_fpv_findJammers_MP;


private _distance = _player distance _uav;

private _objectCount = [_player, _uav] call RC_fnc_fpv_countInterferingObjects_MP;
private _terrainInterception = [_player, _uav] call RC_fnc_fpv_evaluateTerrainImpact_MP;

private _signalStrengthObj = 1 - (_objectCount * 0.05);
private _signalStrengthObjTer = _signalStrengthObj * (1 - (_terrainInterception * (_distance / _maxDistance)));
_signalStrength = _signalStrengthObjTer * (1 - (_distance / _maxDistance));

if ((count _retranslatorsBackpack) > 0) then {
    private _signalStrengthObjTerBackpack = _signalStrengthObj * (1 - (_terrainInterception * (_distance / _maxDistanceReceiver)));
    _signalStrength = _signalStrengthObjTerBackpack * (1 - (_distance / _maxDistanceReceiver));
};


private _receiver = _uav;
if (count _retranslatorsUGVandAntenna > 0) then {

    private _closest = _retranslatorsUGVandAntenna select 0;
    private _distance1 = _player distance2D _closest;
    private _distance2 = _closest distance2D _uav;
    private _closestDist = _distance1 + _distance2;

    {
        private _distance1 = _player distance2D _x;
        private _distance2 = _x distance2D _uav;
        if ((_distance1 + _distance2) > _closestDist) then {
            _closestDist = (_distance1 + _distance2);
            _closest = _x;
        };
    } forEach _retranslatorsUGVandAntenna;

    _receiver = _closest;
};
if (count _retranslatorsUAV > 0) then {

    private _highest = _retranslatorsUAV select 0;
    private _highestASL = getPosASL _highest select 2;

    {
        private _ASL = getPosASL _x select 2;
        if (_ASL > _highestASL) then {
            _highestASL = _ASL;
            _highest = _x;
        };
    } forEach _retranslatorsUAV;

    _receiver = _highest;
};


if (_receiver isNotEqualTo _uav) then {
    private _objectCountPtR = [_player, _receiver] call RC_fnc_fpv_countInterferingObjects_MP;
    private _objectCountRtU = [_receiver, _uav] call RC_fnc_fpv_countInterferingObjects_MP;

    private _terrainInterceptionPtR = [_player, _receiver] call RC_fnc_fpv_evaluateTerrainImpact_MP;
    private _terrainInterceptionRtU = [_receiver, _uav] call RC_fnc_fpv_evaluateTerrainImpact_MP;

    private _signalStrengthReceiverObj = 1 - (((_objectCountPtR + _objectCountRtU) / 2) * 0.05);
    private _signalStrengthReceiverObjTer = _signalStrengthReceiverObj * (1 - (((_terrainInterceptionPtR + _terrainInterceptionRtU) / 2) * (_distance / _maxDistanceReceiver)));
    _signalStrengthReceiver = _signalStrengthReceiverObjTer * (1 - (_distance / _maxDistanceReceiver));

    //hint format ["obj %1 | %2+%3\n ter %4 | %5+%6\n dis %7\n sig %8 | %9", _objectCount, _objectCountPtR, _objectCountRtU, _terrainInterception, _terrainInterceptionPtR, _terrainInterceptionRtU, round _distance, round (_signalStrength*100), round (_signalStrengthReceiver*100)];

    if (_signalStrengthReceiver > _signalStrength) then
    {
        _signalStrength = _signalStrengthReceiver;
    };
    //(1 - (((0 + 0) / 2) * 0.05)) * (1 - (((1 + 1) / 2) * (3000 / 4000))) * (1 - (3000 / 4000));

};
/*
} else {
    hint format ["obj %1\n ter %2\n dis %3\n sig %4", _objectCount, _terrainInterception, _distance, _signalStrength];
};
*/


if (isNil "DB_timeInJammerZone") then {
    DB_timeInJammerZone = 0;
};


if (_jammersNearUAV isNotEqualTo []) then {
    DB_timeInJammerZone = DB_timeInJammerZone + diag_deltaTime;

    private _jammerImpact = 1 - (DB_timeInJammerZone * 1.75);
    _signalStrength = _signalStrength * _jammerImpact max 0;
} else {
    DB_timeInJammerZone = 0;
};


private _maxDistance0 = if (count _retranslatorsAll > 0) then {8000} else {4000};
if (_distance > _maxDistance0) then {
    _signalStrength = 0;
};


_signalStrength = _signalStrength max 0 min 1;
_signalStrength;
