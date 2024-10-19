/*
 * Author: Eric & Ascent
 * If artillery fired and opposing counter battery radar is active:
 * -for players marks opposing indirect fire sources on the map
 * -for AI returns fire on opposing indirect fire sources
*/

//if artillery fires checks if opposing CBRad is alive, for opposing AI assigns CB firemission, for opposing players creates map markers
addMissionEventHandler ["ArtilleryShellFired", {
    params ["_vehicle", "_weapon", "_ammo", "_gunner", "_instigator", "_artilleryTarget", "_targetPosition", "_shell"];
    //if (!local _vehicle) exitwith {};
    if (!isServer) exitwith {};
    
    //checks for opposing CBRad's
    _CBRad_Player_AliveAmount_B = ({alive _x} count RC_CBRad_Player_Array_B);
    _CBRad_Player_AliveAmount_O = ({alive _x} count RC_CBRad_Player_Array_O);
    _CBRad_AI_AliveAmount_B = ({alive _x} count RC_CBRad_AI_Array_B);
    _CBRad_AI_AliveAmount_O = ({alive _x} count RC_CBRad_AI_Array_O);

    _CBRad_AliveAmount = _CBRad_Player_AliveAmount_B + _CBRad_Player_AliveAmount_O+ _CBRad_AI_AliveAmount_B + _CBRad_AI_AliveAmount_O;
    if (!(_CBRad_AliveAmount>0)) exitwith {};
    
    //checks side of the vehicle
    _vehicleSide_B = (side _vehicle == west);
    _vehicleSide_O = (side _vehicle == east);

    //checks opposing sides
    _opposedTo_B = [side _vehicle, west] call BIS_fnc_sideIsEnemy;
    _opposedTo_O = [side _vehicle, east] call BIS_fnc_sideIsEnemy;


    //------------------------------------------------------------------


    //Blufor Player
    if (_opposedTo_B and (_CBRad_Player_AliveAmount_B>0)) then {
        //for testing
        //["blufor rad(P) detected shot"] remoteExec ["hint", west];

        //if (_timeSinceLastMarker > _timeInterval) then {
            [_vehicle] spawn {
                params ["_vehicle"];
                private _artySourcePos = getPosASL _vehicle;

                _roundedArtySourcePosX = round (_artySourcePos select 0);
                _roundedArtySourcePosY = round (_artySourcePos select 1);
                _markerName = ("_USER_DEFINED_" + str _roundedArtySourcePosX + str _roundedArtySourcePosY);
                deleteMarker _markerName;   //preventing doubles and outdated timestamp

                //_random = random [0, 10, 20];
                //_markerName = format ["%1%2", "_USER_DEFINED_", _random];

                sleep (RC_Timer1);

                private _artySourceMarker = createMarkerLocal [_markerName, _artySourcePos, 0];    //later sidechannel 1
                _artySourceMarker setMarkerTypeLocal "o_art";
                _artySourceMarker setMarkerAlphaLocal 1;
                _artySourceMarker setMarkerSizeLocal [0.6,0.6];
                
                _artySourceMarkerHour = date select 3;
                _artySourceMarkerMinute = date select 4;
                if (_artySourceMarkerMinute < 10) then {
                    _artySourceMarkerText = str _artySourceMarkerHour + ":0" + str _artySourceMarkerMinute;
                    _artySourceMarker setMarkerTextLocal format ["%1", _artySourceMarkerText];
                } else {
                    _artySourceMarkerText = str _artySourceMarkerHour + ":" + str _artySourceMarkerMinute;
                    _artySourceMarker setMarkerTextLocal format ["%1", _artySourceMarkerText];
                };

                _artySourceMarker setMarkerColor "ColorOrange";

                [_markerName] remoteExec ["deleteMarkerLocal", east];
                [_markerName] remoteExec ["deleteMarkerLocal", resistance];
            };
        //};
    };

    //Opfor Player
    if (_opposedTo_O and (_CBRad_Player_AliveAmount_O>0)) then {
        //for testing
        //["opfor rad(P) detected shot"] remoteExec ["hint", west];

        //if (_timeSinceLastMarker > _timeInterval) then {
            [_vehicle] spawn {
                params ["_vehicle"];
                private _artySourcePos = getPosASL _vehicle;
                
                _roundedArtySourcePosX = round (_artySourcePos select 0);
                _roundedArtySourcePosY = round (_artySourcePos select 1);
                _markerName = ("_USER_DEFINED_" + str _roundedArtySourcePosX + str _roundedArtySourcePosY);
                deleteMarker _markerName;   //preventing doubles and outdated timestamp

                //_random = random [0, 10, 20];
                //_markerName = format ["%1%2", "_USER_DEFINED_", _random];

                sleep (RC_Timer1);

                private _artySourceMarker = createMarkerLocal [_markerName, _artySourcePos, 0];    //later sidechannel 1
                _artySourceMarker setMarkerTypeLocal "o_art";
                _artySourceMarker setMarkerAlphaLocal 1;
                _artySourceMarker setMarkerSizeLocal [0.6,0.6];
                
                _artySourceMarkerHour = date select 3;
                _artySourceMarkerMinute = date select 4;
                if (_artySourceMarkerMinute < 10) then {
                    _artySourceMarkerText = str _artySourceMarkerHour + ":0" + str _artySourceMarkerMinute;
                    _artySourceMarker setMarkerTextLocal format ["%1", _artySourceMarkerText];
                } else {
                    _artySourceMarkerText = str _artySourceMarkerHour + ":" + str _artySourceMarkerMinute;
                    _artySourceMarker setMarkerTextLocal format ["%1", _artySourceMarkerText];
                };

                _artySourceMarker setMarkerColor "ColorOrange";

                [_markerName] remoteExec ["deleteMarkerLocal", west];
                [_markerName] remoteExec ["deleteMarkerLocal", resistance];
            };
        //};
    };
}];

/*
_this addEventHandler ["Fired", {
	params ["_unit", "_weapon", "_muzzle", "_mode", "_ammo", "_magazine", "_projectile", "_gunner"];

    private _artySourcePos = getPosASL _unit; 
    _roundedArtySourcePosX = round (_artySourcePos select 0); 
    _roundedArtySourcePosY = round (_artySourcePos select 1); 
    _markerName = ("_USER_DEFINED_" + str _roundedArtySourcePosX + str _roundedArtySourcePosY);
    deleteMarker _markerName;
    
    private _artySourceMarker = createMarkerLocal [_markerName, _artySourcePos, 0];
    _artySourceMarker setMarkerTypeLocal "o_art"; 
    _artySourceMarker setMarkerAlphaLocal 1;
    _artySourceMarker setMarkerSizeLocal [0.6,0.6];
    
    _artySourceMarkerHour = date select 3;
    _artySourceMarkerMinute = date select 4;
    if (_artySourceMarkerMinute < 10) then { 
        _artySourceMarkerText = str _artySourceMarkerHour + ":0" + str _artySourceMarkerMinute;
        _artySourceMarker setMarkerTextLocal format ["%1", _artySourceMarkerText];
    } else { 
        _artySourceMarkerText = str _artySourceMarkerHour + ":" + str _artySourceMarkerMinute;
        _artySourceMarker setMarkerTextLocal format ["%1", _artySourceMarkerText];
    };
    
    _artySourceMarker setMarkerColor "ColorOrange";

    [_markerName] remoteExec ["deleteMarkerLocal", east];
}];
*/

    /*
    [_vehicle, _targetPosition] spawn {
        params ["_vehicle", "_targetPosition"];
        _vehicle setVariable ["ArtySourceMarkersTime", time, true];
        private _artySourcePos = getPosASL _vehicle;

        //_markerName = ("_USER_DEFINED ArtySourceMarker" + str _artySourcePos);
        //_markerArray = [_markerName, _artySourcePos, 1];

        sleep (RC_Timer1);
        //_artySourceMarker = createMarkerLocal [_markerName, _artySourcePos, 1];
        _markerName = random [0, 10, 20];
	    _markerArray = format ["%1%2", "_USER_DEFINED_", _markerName];
        _artySourceMarker = createMarkerLocal [_markerArray, _artySourcePos, 1];
        _artySourceMarker setMarkerTypeLocal "o_art";
        _artySourceMarker setMarkerAlphaLocal 1;
        _artySourceMarker setMarkerSizeLocal [0.6,0.6];

        _artySourceMarkerHour = date select 3;
        _artySourceMarkerMinute = date select 4;
        if (_artySourceMarkerMinute < 10) then {
            _artySourceMarkerText = str _artySourceMarkerHour + ":0" + str _artySourceMarkerMinute;
            _artySourceMarker setMarkerTextLocal format ["%1", _artySourceMarkerText];
        } else {
            _artySourceMarkerText = str _artySourceMarkerHour + ":" + str _artySourceMarkerMinute;
            _artySourceMarker setMarkerTextLocal format ["%1", _artySourceMarkerText];
        };

        _artySourceMarker setMarkerColor "ColorOrange";

        [_markerName] remoteExec ["deleteMarkerLocal", west];
        [_markerName] remoteExec ["deleteMarkerLocal", resistance];

        _artySourceGrid = mapGridPosition _artySourcePos;
        _artySourceGridX = _artySourceGrid select [0, 3];
        _artySourceGridY = _artySourceGrid select [3, 3];
        _targetGrid = mapGridPosition _targetPosition;
        _targetGridX = _targetGrid select [0, 3];
        _targetGridY = _targetGrid select [3, 3];

        if ((_targetPosition select 0) == 0) then {
            _message = "INCOMING" + "\n" + "target: ???-???" + "\n" + "source: " + _artySourceGridX + "-" + _artySourceGridY;
            [["\A3\Sounds_F\vehicles\air\noises\alarm_locked_by_missile_4.wss", 0.15]] remoteExec ["playSoundUI", east];
            [_message] remoteExec ["hintSilent", east];
            sleep 5;
            [""] remoteExec ["hintSilent", east];
        } else {
            _message = "INCOMING" + "\n" + "target: " + _targetGridX + "-" + _targetGridY + "\n" + "source: " + _artySourceGridX + "-" + _artySourceGridY;
            [["\A3\Sounds_F\vehicles\air\noises\alarm_locked_by_missile_4.wss", 0.15]] remoteExec ["playSoundUI", east];
            [_message] remoteExec ["hintSilent", east];
            sleep 5;
            [""] remoteExec ["hintSilent", east];
        };
    };
    */


/*
_vehicle = vic;
_artySourcePos = getPosASL _vehicle;

_markerName = random [0, 10, 20];
_markerArray = format ["%1%2", "_USER_DEFINED_", _markerName];

_artySourceMarker = createMarkerLocal [_markerArray, _artySourcePos, 1];
_artySourceMarker setMarkerTypeLocal "o_art";
_artySourceMarker setMarkerAlphaLocal 1;
_artySourceMarker setMarkerSizeLocal [0.6,0.6];

_artySourceMarker setMarkerColor "ColorOrange";
*/


/*
_vehicle = vic;
_artySourcePos = getPosASL _vehicle;

_markerName = ("_USER_DEFINED ArtySourceMarker" + str _artySourcePos);
_markerArray = [_markerName, _artySourcePos, 1];

_artySourceMarker = createMarkerLocal [_markerName, _artySourcePos, 1];
_artySourceMarker setMarkerTypeLocal "o_art";
_artySourceMarker setMarkerAlphaLocal 1;
_artySourceMarker setMarkerSizeLocal [0.6,0.6];

[_artySourceMarker, "o_art"] remoteExec ["setMarkerTypeLocal", 0];
[_artySourceMarker, 1] remoteExec ["setMarkerAlphaLocal", 0];
[_artySourceMarker, [0.6,0.6]] remoteExec ["setMarkerSizeLocal", 0];
[_artySourceMarker, "ColorOrange"] remoteExec ["setMarkerColor", 0];
*/


/*
Putting that here for later, this works run local, not on server.
```sqf
_vehicle = _this;
_pos = getPosASL _vehicle;

_randomName = random [0, 10, 20];
_markerName = format ["%1%2", "_USER_DEFINED_", _randomName];
```

local to global
```sqf
_marker = createMarkerLocal [_markerName, _pos, 1];
_marker setMarkerTypeLocal "hd_destroy";
_marker setMarkerAlphaLocal 1;

_marker setMarkerColor "ColorBlue";  //non, 
```

global
```sqf
_marker = createMarker [_markerName, _pos, 1];
_marker setMarkerType "hd_destroy";
_marker setMarkerAlpha 1;

_marker setMarkerColor "ColorBlue";
```

RE
```sqf
_vehicle = _this;
_pos = getPosASL _vehicle;
_randomName = random [0, 10, 20];
_markerName = format ["%1%2", "_USER_DEFINED_", _randomName];
_marker = createMarker [_markerName, _pos, 1];
[_marker, "hd_destroy"] remoteExec ["setMarkerType", 4];
[_marker, 1] remoteExec ["setMarkerAlpha", 4];
[_marker, "ColorBlue"] remoteExec ["setMarkerColor", 4];
```
*/


/*
_vehicle = vic;
_artySourcePos = getPosASL _vehicle;

_markerName = ("_USER_DEFINED ArtySourceMarker" + str _artySourcePos);
_markerArray = [_markerName, _artySourcePos, 1];

_artySourceMarker = createMarker [_markerName, _artySourcePos, 1];
_artySourceMarker setMarkerType "o_art";
_artySourceMarker setMarkerAlpha 1;
_artySourceMarker setMarkerSize [0.6,0.6];
_artySourceMarker setMarkerColor "ColorOrange";
*/


//[_markerName] remoteExec ["deleteMarkerLocal", west];   //causes problems, not use for now
//[_markerName] remoteExec ["deleteMarkerLocal", resistance];   //causes problems, not use for now

/*
RC_ArtilleryArray_O deleteAt (RC_ArtilleryArray_O find [objNull]);     //prevents objNull in array
RC_isInRangeArray_O deleteAt (RC_isInRangeArray_O find [objNull]);     //prevents objNull in array
RC_ArtilleryArray_O = RC_ArtilleryArray_O arrayIntersect RC_ArtilleryArray_O;
RC_isInRangeArray_O = RC_isInRangeArray_O arrayIntersect RC_isInRangeArray_O;

You can remove duplicates (get unique items) with this command:
private _myArray = [1, 2, 2, 3, 4];
private _result = _myArray arrayIntersect _myArray; // _result is [1, 2, 3, 4]

if (ObjNull in RC_isInRangeArray_O) then {
    {RC_isInRangeArray_O = RC_isInRangeArray_O - [objNull]} forEach RC_isInRangeArray_O;
};
*/