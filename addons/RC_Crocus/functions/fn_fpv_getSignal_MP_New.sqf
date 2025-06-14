params ["_player", "_uav"];

private _fnc_evaluateTerrainImpact = {  
    params ["_startPoint", "_endPoint"];
    private _terrainInterceptionValue = 0;
    private _initialPos = eyePos _startPoint;
    private _finalPos = getPosWorld _endPoint;
    private _isIntersecting = terrainIntersectASL [_initialPos, _finalPos];
    _terrainInterceptionValue = if (_isIntersecting) then { 1 } else { 0.1 };
    _terrainInterceptionValue
};

private _fnc_countInterferingObjects = { 
    params ["_from", "_to"];
    private _intersectedSurfaces = lineIntersectsSurfaces [
        eyepos _from,
        getPosWorld _to,
        _from,
        _to,
        true,
        10,
        "FIRE",
        "NONE"
    ];
    private _filteredObstacles = _intersectedSurfaces select { 
        private _intersectedObject = _x select 2;
        private _isParent = (_intersectedObject isEqualTo objectParent _from) || (_intersectedObject isEqualTo objectParent _to);
        !_isParent && !(_intersectedObject isKindOf "Man")
    };
    count _filteredObstacles
};


//make transition smoother, like booster to FPV, maybe also add: intesect from operator to booster to uav
private _fnc_findRetranslatorsNearPlayer = {
    params ["_position", "_radius", "_side"];

    /*
    //supposedly good for multiple vics
    retr1 = switch (_side) do {
        case west:      {_position nearObjects ["RC_Crocus_Mothership", 3000]};
        case east:      {_position nearObjects ["RC_Crocus_Mothership_O", 3000]};
        case resistance:{_position nearObjects ["RC_Crocus_Mothership_I", 3000]};
        default         {[]};
    };
    */

    _retr1 = [];
    _retr2 = [];
    if (_side isEqualTo west) then {
        _retr1 = _position nearEntities ["RC_Crocus_Mothership", 3000];
        _retr2 = _position nearEntities ["RC_Crocus_Carrier", 3000];
    };
    if (_side isEqualTo east) then {
        _retr1 = _position nearEntities ["RC_Crocus_Mothership_O", 3000];
        _retr2 = _position nearEntities ["RC_Crocus_Carrier_O", 3000];
    };
    if (_side isEqualTo resistance) then {
        _retr1 = _position nearEntities ["RC_Crocus_Mothership_I", 3000];
        _retr2 = _position nearEntities ["RC_Crocus_Carrier_I", 3000];
    };

    private _retr3 = _position nearObjects ["FPV_Retranslator", 3000];

    private _retr4 = [];
    private _backpackArray = ["RC_SignalBoosterLRR_blk", "RC_SignalBoosterLRR_mtp", "RC_SignalBoosterLRR_tropic", "RC_SignalBoosterLRR_wdl", "RC_SignalBoosterLRR_ilbe_A", "RC_SignalBoosterLRR_ilbe_G", "RC_SignalBoosterLRR_ilbe_MC"];
    private _backpack = backpack _player;
    if ({ _x in _backpack } count _backpackArray > 0) then {
       _retr4 = [_player];
    };

    private _retranslators = _retr1 + _retr2 + _retr3 + _retr4;
    _retranslators
};

private _fnc_findRetranslatorsNearUAV = {
    params ["_position", "_radius", "_side"];

    _retr1 = [];
    _retr2 = [];
    if (_side isEqualTo west) then {
        _retr1 = _position nearEntities ["RC_Crocus_Mothership", 3000];
        _retr2 = _position nearEntities ["RC_Crocus_Carrier", 3000];
    };
    if (_side isEqualTo east) then {
        _retr1 = _position nearEntities ["RC_Crocus_Mothership_O", 3000];
        _retr2 = _position nearEntities ["RC_Crocus_Carrier_O", 3000];
    };
    if (_side isEqualTo resistance) then {
        _retr1 = _position nearEntities ["RC_Crocus_Mothership_I", 3000];
        _retr2 = _position nearEntities ["RC_Crocus_Carrier_I", 3000];
    };

    private _retr3 = _position nearObjects ["FPV_Retranslator", 3000];

    private _retranslators = _retr1 + _retr2 + _retr3;
    _retranslators
};

private _fnc_findJammers = {
    params ["_position", "_radius"];
    private _jammers = _position nearEntities [["Sania", "Sania_with_tripod"], _radius];
    _jammers = _jammers select { _x getVariable ["DB_jammer_isActive", false] };
    _jammers
};

private _fnc_distanceImpact = {
    params ["_distance", "_maxDistance"];
    private _distanceFactor = 1 - (_distance / _maxDistance);
    _distanceFactor
};

//distance between player & booster / booster & uav should also play a difference, also prefering booster with higher Z coordinate
//*edit: booster would have larger receiver than FPV, so operator to booster distance would have less impact, but likely some
private _side = side _player;
private _retranslatorsNearUAV = [_uav, 3000, _side] call _fnc_findRetranslatorsNearUAV;
private _retranslatorsNearPlayer = [_player, 3000, _side] call _fnc_findRetranslatorsNearPlayer;

//add backpacks, also add Jammer, maybe add one with useraction that has to be actively used, "jam FPV's" within xmeters that jams all UV's for given time, which for type air results in ground crash
private _jammersNearUAV = [_uav, 1000] call _fnc_findJammers;

//private _maxDistance = if (count _retranslatorsNearUAV > 0 || count _retranslatorsNearPlayer > 0) then { FPV_MaxFlightDistance + 2500 } else { FPV_MaxFlightDistance };
private _maxDistance = if (count _retranslatorsNearUAV > 0 || count _retranslatorsNearPlayer > 0) then { 3000 } else { 3000 };



//_maxDistance changed to 3000!!! DOES NOT WORK FOR BACKPACK



private _distance = _player distance _uav;
private _distanceImpact = [_distance, _maxDistance] call _fnc_distanceImpact;

private _terrainInterception = [_player, _uav] call _fnc_evaluateTerrainImpact;
private _objectCount = [_player, _uav] call _fnc_countInterferingObjects;

private _signalStrength = 1 - (_objectCount * 0.05);
_signalStrength = _signalStrength * (1 - (_terrainInterception * (_distance / _maxDistance))) * _distanceImpact;

private _receiver = _uav;
if (count _retranslatorsNearPlayer > 0) then {
    private _firstRetranslatorsNearPlayer = _retranslatorsNearPlayer select 0;
    if ((_firstRetranslatorsNearPlayer isKindOf 'RC_FPV_Mothership_Base') || (_firstRetranslatorsNearPlayer isKindOf 'RC_FPV_Carrier_Base') || (_firstRetranslatorsNearPlayer isKindOf 'FPV_Retranslator')) then {
        if (alive _firstRetranslatorsNearPlayer) then {
            _receiver = _firstRetranslatorsNearPlayer;
            systemchat "receiver near player";
        };
    };
};
if (count _retranslatorsNearUAV > 0) then {
    private _firstRetranslatorsNearUAV = _retranslatorsNearUAV select 0;
    if ((_firstRetranslatorsNearUAV isKindOf 'RC_FPV_Mothership_Base') || (_firstRetranslatorsNearUAV isKindOf 'RC_FPV_Carrier_Base') || (_firstRetranslatorsNearUAV isKindOf 'FPV_Retranslator')) then {
        if ((alive _firstRetranslatorsNearUAV) || (_firstRetranslatorsNearUAV isKindOf 'FPV_Retranslator')) then {
            _receiver = _firstRetranslatorsNearUAV;
            systemchat "receiver near UAV";
        };
    };
};


//_maxDistance changed to 3000!!! DOES NOT WORK FOR BACKPACK

//maybe this x1.8 is the PROBLEM???
/*
//found further down
if ((_retranslatorsNearUAV isNotEqualTo []) || (_retranslatorsNearPlayer isNotEqualTo [])) then {
    _signalStrength = _signalStrength * 1.8;
};
*/


if (_receiver isNotEqualTo _uav) then {
    _distance2 = _player distance _receiver;
    _distanceImpact2 = [_distance2, _maxDistance] call _fnc_distanceImpact;

    private _distanceReceiver = _receiver distance _uav;
    private _distanceImpactReceiver = [_distanceReceiver, _maxDistance] call _fnc_distanceImpact;

    private _terrainInterception2 = [_player, _receiver] call _fnc_evaluateTerrainImpact;
    private _objectCount2 = [_player, _receiver] call _fnc_countInterferingObjects;

    private _terrainInterceptionReceiver = [_receiver, _uav] call _fnc_evaluateTerrainImpact;
    private _objectCountReceiver = [_receiver, _uav] call _fnc_countInterferingObjects;

    private _signalStrength2 = 1 - ((_objectCount2)  * 0.05);
    _signalStrength2 = _signalStrength2 * (1 - (_terrainInterception2 * (_distance / _maxDistance))) * _distanceImpact2;

    private _signalStrengthReceiver = 1 - (_objectCountReceiver  * 0.05);
    _signalStrengthReceiver = _signalStrengthReceiver * (1 - (_terrainInterceptionReceiver * (_distance / _maxDistance))) * _distanceImpactReceiver;

    private _signalStrengthFinal = _signalStrength;
    //connection quality based on the worse connection of playerToReceiver and receiverToUav
    if (_signalStrength2 > _signalStrengthReceiver) then {
        _signalStrengthFinal = _signalStrengthReceiver;
    } else {
        _signalStrengthFinal = _signalStrength2;
    };


    //_maxDistance changed to 3000!!! DOES NOT WORK FOR BACKPACK


    /*
    private _signalStrengthReceiver = 1 - (((_objectCount2 + _objectCountReceiver) / 2)  * 0.05);
    private _signalStrengthReceiver = _signalStrengthReceiver * (1 - (((_terrainInterception2 + _terrainInterceptionReceiver) / 2) * (_distance / _maxDistance))) * ((_distanceImpact2 + _distanceImpactReceiver)/2);
    */

    hint format ["obj %1\n ter %2\n dis %3\n sig %4\n rec %5\n obj2 %6\n objR %7\n ter2 %8\n terR %9\n dist2 %10\n distR %11\n sig2 %12\n sigR %13\n sigF %14", _objectCount, _terrainInterception, _distanceImpact, _signalStrength, _receiver, _objectCount2, _objectCountReceiver, _terrainInterception2, _terrainInterceptionReceiver, _distanceImpact2, _distanceImpactReceiver, _signalStrength2, _signalStrengthReceiver, _signalStrengthFinal];

    if (_signalStrengthFinal > _signalStrength) then {
        _signalStrength = _signalStrengthFinal;
    };
} else {
    hint format ["obj %1\n ter %2\n dis %3\n sig %4\n rec %5", _objectCount, _terrainInterception, _distanceImpact, _signalStrength, _receiver];
};


//maybe this x1.8 is the PROBLEM???
if ((_retranslatorsNearUAV isNotEqualTo []) || (_retranslatorsNearPlayer isNotEqualTo [])) then {
    _signalStrength = _signalStrength * 1.8;
};


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

/*
//would suddenly cut off despite signal booster
if (_distance > _maxDistance) then {
    _signalStrength = 0;
};
*/

_signalStrength = _signalStrength max 0 min 1;
_signalStrength;
