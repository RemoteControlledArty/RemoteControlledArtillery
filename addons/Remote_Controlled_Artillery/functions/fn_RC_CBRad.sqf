/*
 * Author: Eric & Ascent
 * Checks spawned vehicles if they have the value "artilleryscanner=1;", to apply eventhandler that if friendly counter battery radar is active:
 * -for players marks opposing indirect fire sources on the map
 * -for AI returns fire on opposing indirect fire sources
 * Needs to be preinit to work on 3den spawned vehicles.
*/

RC_CBRad_Player_Array_B = [];
RC_CBRad_Player_Array_O = [];
RC_CBRad_Player_Array_I = [];
publicVariable "RC_CBRad_Player_Array_B";
publicVariable "RC_CBRad_Player_Array_O";
publicVariable "RC_CBRad_Player_Array_I";

RC_CBRad_AI_Array_B = [];
RC_CBRad_AI_Array_O = [];
RC_CBRad_AI_Array_I = [];
publicVariable "RC_CBRad_AI_Array_B";
publicVariable "RC_CBRad_AI_Array_O";
publicVariable "RC_CBRad_AI_Array_I";

RC_ArtilleryArray_B = [];
RC_ArtilleryArray_O = [];
RC_ArtilleryArray_I = [];
publicVariable "RC_ArtilleryArray_B";
publicVariable "RC_ArtilleryArray_O";
publicVariable "RC_ArtilleryArray_I";

RC_isInRangeArray_B = [];
RC_isInRangeArray_O = [];
RC_isInRangeArray_I = [];
publicVariable "RC_isInRangeArray_B";
publicVariable "RC_isInRangeArray_O";
publicVariable "RC_isInRangeArray_I";

RC_fireMissionArray_B = [];
RC_fireMissionArray_O = [];
RC_fireMissionArray_I = [];
publicVariable "RC_fireMissionArray_B";
publicVariable "RC_fireMissionArray_O";
publicVariable "RC_fireMissionArray_I";


/* testing scripts section
[(str RC_ArtilleryArray_O)] remoteExec ["hintSilent", west];
[(str RC_CBRad_AI_Array_O)] remoteExec ["hintSilent", west];
[(str RC_isInRangeArray_O)] remoteExec ["hintSilent", west];
[(str RC_fireMissionArray_O)] remoteExec ["hintSilent", west];


_this doArtilleryFire [(getpos target), (currentMagazine _this), 1];
[(getpos target), (currentMagazine _this), 1] remoteExec ["doArtilleryFire", _this];

_entitySide_O = (side _this == east);
if (_entitySide_O) then { 
RC_ArtilleryArray_O pushback _entity; 
publicVariable 'RC_ArtilleryArray_O';
*/
/*
if (_opposedTo_B and _CBRad_AI_Alive_B) then {
    _unitPos = getPos _unit;
    [_unitPos] spawn
    {
        params ["_unitPos"];
        sleep (RC_Test+RC_Test2);
        {
            RC_isInRangeArray_B deleteAt (RC_isInRangeArray_B find _x);

            _isInRange = _unitPos inRangeOfArtillery [[_x], (currentMagazine _x)];
            _isAlive = alive _x;
            _isAlive = isNil _x;
            if (_isInRange && _isAlive) then {
                RC_isInRangeArray_B pushback _x;
                publicVariable 'RC_isInRangeArray_B';
            };
            sleep 0.1;
        } forEach RC_ArtilleryArray_B;

        if ((count RC_isInRangeArray_B) > 0) then
        {
            _firstInRange_B = (RC_isInRangeArray_B select 0);
            _firstInRange_B doArtilleryFire [_unitPos, (currentMagazine _firstInRange_B), 1];

            RC_fireMissionArray_B pushback _firstInRange_B;
            publicVariable 'RC_fireMissionArray_B';
            sleep 10;

            _fireMissionNotCompleted = (({_x == _firstInRange_B} count RC_fireMissionArray_B) > 0);
            if (_fireMissionNotCompleted) then
            {
                if ((count RC_isInRangeArray_B) > 1) then
                {
                    _secondInRange_B = (RC_isInRangeArray_B select 1);
                    _secondInRange_B doArtilleryFire [_unitPos, (currentMagazine _secondInRange_B), 1];

                    RC_fireMissionArray_B pushback _secondInRange_B;
                    publicVariable 'RC_fireMissionArray_B';
                    sleep 10;

                    _fireMissionNotCompleted = (({_x == _secondInRange_B} count RC_fireMissionArray_B) > 0);
                    if (_fireMissionNotCompleted) then
                    {
                        if ((count RC_isInRangeArray_B) > 2) then
                        {
                            _thirdInRange_B = (RC_isInRangeArray_B select 2);
                            _thirdInRange_B doArtilleryFire [_unitPos, (currentMagazine _thirdInRange_B), 1];

                            RC_fireMissionArray_B pushback _thirdInRange_B;
                            publicVariable 'RC_fireMissionArray_B';
                            sleep 10;

                            _fireMissionNotCompleted = (({_x == _thirdInRange_B} count RC_fireMissionArray_B) > 0);
                            if (_fireMissionNotCompleted) then
                            {
                                if ((count RC_isInRangeArray_B) > 3) then
                                {
                                    _fourthInRange_B = (RC_isInRangeArray_B select 3);
                                    _fourthInRange_B doArtilleryFire [_unitPos, (currentMagazine _fourthInRange_B), 1];
                                };
                            };
                        };
                    };
                };
            };
        };
    };
};
*/


if (!isServer) exitwith {};

addMissionEventHandler ["EntityCreated", {
	params ["_entity"];
	_isArtillery = getNumber (configFile >> "CfgVehicles" >> (typeOf _entity) >> "artilleryScanner") == 1;

	if (_isArtillery) then {

        _entitySide_B = (side _entity == west);
        _entitySide_O = (side _entity == east);
        _entitySide_I = (side _entity == resistance);

        switch (true) do {
            case(_entitySide_B): {
                RC_ArtilleryArray_B pushback _entity;
                publicVariable 'RC_ArtilleryArray_B';

                //for testing
                [str RC_ArtilleryArray_B] remoteExec ["hint", west];
            };
            case(_entitySide_O): {
                RC_ArtilleryArray_O pushback _entity;
                publicVariable 'RC_ArtilleryArray_O';

                //for testing
                [str RC_ArtilleryArray_O] remoteExec ["hint", west];
            };
            case(_entitySide_I): {
                RC_ArtilleryArray_I pushback _entity;
                publicVariable 'RC_ArtilleryArray_I';

                //for testing
                [str RC_ArtilleryArray_I] remoteExec ["hint", west];
            };
        };

        _this setVariable ["ArtySourceMarkersTime", 0, true];

		_entity addEventHandler ["Fired", {
            //params ["_unit", "_magazine"];  //didnt work
    		params ["_unit", "_weapon", "_muzzle", "_mode", "_ammo", "_magazine"];
            //params ["_unit", "_weapon", "_muzzle", "_mode", "_ammo", "_magazine", "_projectile", "_gunner"];

            _isPrimaryAmmo = _magazine == (currentMagazine _unit);  //currentMagazine usually gives mainturret mag, so usually shouldnt trigger for commander turret?
            if (_isPrimaryAmmo) then {
                
                _unitSide_B = (side _unit == west);
                _unitSide_O = (side _unit == east);
                _unitSide_I = (side _unit == resistance);

                switch (true) do {
                    case(_unitSide_B): {
                        RC_fireMissionArray_B deleteAt (RC_fireMissionArray_B find _unit);
                        publicVariable "RC_fireMissionArray_B";

                        //for testing
                        [str _unitSide_B] remoteExec ["hint", west];
                    };
                    case(_unitSide_O): {
                        RC_fireMissionArray_O deleteAt (RC_fireMissionArray_O find _unit);
                        publicVariable "RC_fireMissionArray_O";

                        //for testing
                        [str _unitSide_O] remoteExec ["hint", west];
                    };
                    case(_unitSide_I): {
                        RC_fireMissionArray_I deleteAt (RC_fireMissionArray_I find _unit);
                        publicVariable "RC_fireMissionArray_I";

                        //for testing
                        [str _unitSide_I] remoteExec ["hint", west];
                    };
                };

                /*
                RC_fireMissionArray_B deleteAt (RC_fireMissionArray_B find _unit);
                RC_fireMissionArray_O deleteAt (RC_fireMissionArray_O find _unit);
                RC_fireMissionArray_I deleteAt (RC_fireMissionArray_I find _unit);
                publicVariable "RC_fireMissionArray_B";
                publicVariable "RC_fireMissionArray_O";
                publicVariable "RC_fireMissionArray_I";
                */

                _CBRad_Player_Alive_B = ({alive _x} count RC_CBRad_Player_Array_B) > 0;
                _CBRad_Player_Alive_O = ({alive _x} count RC_CBRad_Player_Array_O) > 0;
                _CBRad_Player_Alive_I = ({alive _x} count RC_CBRad_Player_Array_I) > 0;

                _CBRad_AI_Alive_B = ({alive _x} count RC_CBRad_AI_Array_B) > 0;
                _CBRad_AI_Alive_O = ({alive _x} count RC_CBRad_AI_Array_O) > 0;
                _CBRad_AI_Alive_I = ({alive _x} count RC_CBRad_AI_Array_I) > 0;

                _opposedTo_B = [side _unit, west] call BIS_fnc_sideIsEnemy;
                _opposedTo_O = [side _unit, east] call BIS_fnc_sideIsEnemy;
                _opposedTo_I = [side _unit, resistance] call BIS_fnc_sideIsEnemy;
                
                //Blufor Player
                if (_opposedTo_B and _CBRad_Player_Alive_B) then {
                    //for testing
                    ["blufor rad(P) detected shot"] remoteExec ["hint", west];

                    private _timeInterval = 10;
                    private _lastMarkerTime = _unit getVariable "ArtySourceMarkersTime";
                    private _timeSinceLastMarker = time - _lastMarkerTime;

                    if (_timeSinceLastMarker > _timeInterval) then {
                        [_unit] spawn
                        {
                            params ["_unit"];
                            _unit setVariable ["ArtySourceMarkersTime", time, true];
                            private _artySourcePos = getPosASL _unit;

                            _markerName = ("_USER_DEFINED ArtySourceMarker" + str _artySourcePos);
                            _markerArray = [_markerName, _artySourcePos, 1];

                            sleep (RC_Test);
                            private _artySourceMarker = createMarker [_markerName, _artySourcePos, 1];
                            [_artySourceMarker, "o_art"] remoteExec ["setMarkerType", west];
                            [_artySourceMarker, 0.7] remoteExec ["setMarkerAlpha", west];
                            [_markerName] remoteExec ["deleteMarker", east];
                            [_markerName] remoteExec ["deleteMarker", resistance];

                            _artySourcePosX = round (_artySourcePos select 0);
                            _artySourcePosY = round (_artySourcePos select 1);
                            _artySourcePosZ = round (_artySourcePos select 2);

                            _message = "incoming! source: x" + str _artySourcePosX + " y" + str _artySourcePosY + " z" + str _artySourcePosZ;
                            [_message] remoteExec ["hint", west];
                            sleep 3;
                            [""] remoteExec ["hintSilent", west];
                        };
                    };
                };

                //Blufor AI
                if (_opposedTo_B and _CBRad_AI_Alive_B) then {
                    //for testing
                    ["blufor rad(AI) detected shot"] remoteExec ["hint", west];

                    RC_ArtilleryArray_B = RC_ArtilleryArray_B - [objNull];
                    publicVariable 'RC_ArtilleryArray_B';
                    RC_isInRangeArray_B = RC_isInRangeArray_B - [objNull];
                    publicVariable 'RC_isInRangeArray_B';

                    _unitPos = getPos _unit;
                    [_unitPos] spawn
                    {
                        params ["_unitPos"];
                        sleep (RC_Test+RC_Test2);
                        //RC_isInRangeArray_B = [];
                        {
                            RC_isInRangeArray_B deleteAt (RC_isInRangeArray_B find _x);
                            //private _currentMag = (currentMagazine _x);
                            _isNull = isNull _x;
                            if !(_isNull) then
                            {
                                _isInRange = _unitPos inRangeOfArtillery [[_x], (currentMagazine _x)];
                                _isAlive = alive _x;
                                if (_isInRange && _isAlive) then {
                                    RC_isInRangeArray_B pushback _x;
                                    publicVariable 'RC_isInRangeArray_B';
                                };
                            };
                            sleep 0.1;
                        } forEach RC_ArtilleryArray_B;

                        if ((count RC_isInRangeArray_B) > 0) then
                        {
                            _firstInRange_B = (RC_isInRangeArray_B select 0);
                            _firstInRange_B doArtilleryFire [_unitPos, (currentMagazine _firstInRange_B), 1];

                            RC_fireMissionArray_B pushback _firstInRange_B;
                            publicVariable 'RC_fireMissionArray_B';
                            sleep 10;

                            _fireMissionNotCompleted = (({_x == _firstInRange_B} count RC_fireMissionArray_B) > 0);
                            if (_fireMissionNotCompleted) then
                            {
                                if ((count RC_isInRangeArray_B) > 1) then
                                {
                                    //for testing
                                    ["first B firemission failed"] remoteExec ["hint", west];

                                    _secondInRange_B = (RC_isInRangeArray_B select 1);
                                    _secondInRange_B doArtilleryFire [_unitPos, (currentMagazine _secondInRange_B), 1];

                                    RC_fireMissionArray_B pushback _secondInRange_B;
                                    publicVariable 'RC_fireMissionArray_B';
                                    sleep 10;

                                    _fireMissionNotCompleted = (({_x == _secondInRange_B} count RC_fireMissionArray_B) > 0);
                                    if (_fireMissionNotCompleted) then
                                    {
                                        if ((count RC_isInRangeArray_B) > 2) then
                                        {
                                            //for testing
                                            ["second B firemission failed"] remoteExec ["hint", west];

                                            _thirdInRange_B = (RC_isInRangeArray_B select 2);
                                            _thirdInRange_B doArtilleryFire [_unitPos, (currentMagazine _thirdInRange_B), 1];

                                            RC_fireMissionArray_B pushback _thirdInRange_B;
                                            publicVariable 'RC_fireMissionArray_B';
                                            sleep 10;

                                            _fireMissionNotCompleted = (({_x == _thirdInRange_B} count RC_fireMissionArray_B) > 0);
                                            if (_fireMissionNotCompleted) then
                                            {
                                                if ((count RC_isInRangeArray_B) > 3) then
                                                {
                                                    //for testing
                                                    ["third B firemission failed"] remoteExec ["hint", west];

                                                    _fourthInRange_B = (RC_isInRangeArray_B select 3);
                                                    _fourthInRange_B doArtilleryFire [_unitPos, (currentMagazine _fourthInRange_B), 1];
                                                };
                                            };
                                        };
                                    };
                                };
                            };
                        };
                    };
                };

                //Opfor Player
                if (_opposedTo_O and _CBRad_Player_Alive_O) then {
                    //for testing
                    ["opfor rad(P) detected shot"] remoteExec ["hint", west];

                    private _timeInterval = 10; 
                    private _lastMarkerTime = _unit getVariable "ArtySourceMarkersTime";
                    private _timeSinceLastMarker = time - _lastMarkerTime;

                    if (_timeSinceLastMarker > _timeInterval) then {
                        [_unit] spawn
                        {
                            params ["_unit"];
                            _unit setVariable ["ArtySourceMarkersTime", time, true];
                            private _artySourcePos = getPosASL _unit;
                            
                            _markerName = ("_USER_DEFINED ArtySourceMarker" + str _artySourcePos);
                            _markerArray = [_markerName, _artySourcePos, 1];
                            
                            sleep (RC_Test);
                            private _artySourceMarker = createMarker [_markerName, _artySourcePos, 1];
                            [_artySourceMarker, "o_art"] remoteExec ["setMarkerType", east];
                            [_artySourceMarker, 0.7] remoteExec ["setMarkerAlpha", east];
                            [_markerName] remoteExec ["deleteMarker", west];
                            [_markerName] remoteExec ["deleteMarker", resistance];

                            _artySourcePosX = round (_artySourcePos select 0);
                            _artySourcePosY = round (_artySourcePos select 1);
                            _artySourcePosZ = round (_artySourcePos select 2);

                            _message = "incoming! source: x" + str _artySourcePosX + " y" + str _artySourcePosY + " z" + str _artySourcePosZ;
                            [_message] remoteExec ["hint", east];
                            sleep 3;
                            [""] remoteExec ["hintSilent", east];
                        };
                    };
                };

                //Opfor AI
                if (_opposedTo_O and _CBRad_AI_Alive_O) then {
                    //for testing
                    ["opfor rad(AI) detected shot"] remoteExec ["hint", west];
                    
                    RC_ArtilleryArray_O = RC_ArtilleryArray_O - [objNull];
                    publicVariable 'RC_ArtilleryArray_O';
                    RC_isInRangeArray_O = RC_isInRangeArray_O - [objNull];
                    publicVariable 'RC_isInRangeArray_O';

                    //RC_ArtilleryArray_O deleteAt (RC_ArtilleryArray_O find [objNull]);     //prevents objNull in array
                    //RC_isInRangeArray_O deleteAt (RC_isInRangeArray_O find [objNull]);     //prevents objNull in array
                    //RC_ArtilleryArray_O = RC_ArtilleryArray_O arrayIntersect RC_ArtilleryArray_O;
                    //RC_isInRangeArray_O = RC_isInRangeArray_O arrayIntersect RC_isInRangeArray_O;

                    //You can remove duplicates (get unique items) with this command:
                    //private _myArray = [1, 2, 2, 3, 4];
                    //private _result = _myArray arrayIntersect _myArray; // _result is [1, 2, 3, 4]

                    /*
                    if (ObjNull in RC_isInRangeArray_O) then {
                        {RC_isInRangeArray_O = RC_isInRangeArray_O - [objNull]} forEach RC_isInRangeArray_O;
                    };
                    */

                    _unitPos = getPos _unit;
                    [_unitPos] spawn
                    {
                        params ["_unitPos"];
                        sleep (RC_Test+RC_Test2);
                        //RC_isInRangeArray_O = [];
                        {
                            RC_isInRangeArray_O deleteAt (RC_isInRangeArray_O find _x);     //prevents doubles in array
                            //private _currentMag = (currentMagazine _x);
                            _isNull = isNull _x;
                            if !(_isNull) then
                            {
                                _isInRange = _unitPos inRangeOfArtillery [[_x], (currentMagazine _x)];
                                _isAlive = alive _x;
                                if (_isInRange && _isAlive) then {
                                    RC_isInRangeArray_O pushback _x;
                                    publicVariable 'RC_isInRangeArray_O';
                                };
                            };
                            sleep 0.1;
                        } forEach RC_ArtilleryArray_O;

                        if ((count RC_isInRangeArray_O) > 0) then
                        {
                            _firstInRange_O = (RC_isInRangeArray_O select 0);
                            _firstInRange_O doArtilleryFire [_unitPos, (currentMagazine _firstInRange_O), 1];

                            RC_fireMissionArray_O pushback _firstInRange_O;
                            publicVariable 'RC_fireMissionArray_O';
                            sleep 10;

                            _fireMissionNotCompleted = (({_x == _firstInRange_O} count RC_fireMissionArray_O) > 0);
                            if (_fireMissionNotCompleted) then
                            {
                                if ((count RC_isInRangeArray_O) > 1) then
                                {
                                    //for testing
                                    ["first O firemission failed"] remoteExec ["hint", west];

                                    _secondInRange_O = (RC_isInRangeArray_O select 1);
                                    _secondInRange_O doArtilleryFire [_unitPos, (currentMagazine _secondInRange_O), 1];

                                    RC_fireMissionArray_O pushback _secondInRange_O;
                                    publicVariable 'RC_fireMissionArray_O';
                                    sleep 10;

                                    _fireMissionNotCompleted = (({_x == _secondInRange_O} count RC_fireMissionArray_O) > 0);
                                    if (_fireMissionNotCompleted) then
                                    {
                                        if ((count RC_isInRangeArray_O) > 2) then
                                        {
                                            //for testing
                                            ["second firemission failed"] remoteExec ["hint", west];

                                            _thirdInRange_O = (RC_isInRangeArray_O select 2);
                                            _thirdInRange_O doArtilleryFire [_unitPos, (currentMagazine _thirdInRange_O), 1];

                                            RC_fireMissionArray_O pushback _thirdInRange_O;
                                            publicVariable 'RC_fireMissionArray_O';
                                            sleep 10;

                                            _fireMissionNotCompleted = (({_x == _thirdInRange_O} count RC_fireMissionArray_O) > 0);
                                            if (_fireMissionNotCompleted) then
                                            {
                                                if ((count RC_isInRangeArray_O) > 3) then
                                                {
                                                    //for testing
                                                    ["third firemission failed"] remoteExec ["hint", west];

                                                    _fourthInRange_O = (RC_isInRangeArray_O select 3);
                                                    _fourthInRange_O doArtilleryFire [_unitPos, (currentMagazine _fourthInRange_O), 1];
                                                };
                                            };
                                        };
                                    };
                                };
                            };
                        };
                    };
                };

                //Independent Player
                if (_opposedTo_I and _CBRad_Player_Alive_I) then {
                    //for testing
                    ["ind rad(P) detected shot"] remoteExec ["hint", west];

                    private _timeInterval = 10; 
                    private _lastMarkerTime = _unit getVariable "ArtySourceMarkersTime";
                    private _timeSinceLastMarker = time - _lastMarkerTime;

                    if (_timeSinceLastMarker > _timeInterval) then {
                        [_unit] spawn
                        {
                            params ["_unit"];
                            _unit setVariable ["ArtySourceMarkersTime", time, true];
                            private _artySourcePos = getPosASL _unit;
                            
                            _markerName = ("_USER_DEFINED ArtySourceMarker" + str _artySourcePos);
                            _markerArray = [_markerName, _artySourcePos, 1];
                            
                            sleep (RC_Test);
                            private _artySourceMarker = createMarker [_markerName, _artySourcePos, 1];
                            [_artySourceMarker, "o_art"] remoteExec ["setMarkerType", resistance];
                            [_artySourceMarker, 0.7] remoteExec ["setMarkerAlpha", resistance];
                            [_markerName] remoteExec ["deleteMarker", west];
                            [_markerName] remoteExec ["deleteMarker", east];

                            _artySourcePosX = round (_artySourcePos select 0);
                            _artySourcePosY = round (_artySourcePos select 1);
                            _artySourcePosZ = round (_artySourcePos select 2);

                            _message = "incoming! source: x" + str _artySourcePosX + " y" + str _artySourcePosY + " z" + str _artySourcePosZ;
                            [_message] remoteExec ["hint", resistance];
                            sleep 3;
                            [""] remoteExec ["hintSilent", resistance];
                        };
                    };
                };

                //Independent AI
                if (_opposedTo_I and _CBRad_AI_Alive_I) then {
                    //for testing
                    ["ind rad(AI) detected shot"] remoteExec ["hint", west];

                    RC_ArtilleryArray_I = RC_ArtilleryArray_I - [objNull];
                    publicVariable 'RC_ArtilleryArray_I';
                    RC_isInRangeArray_I = RC_isInRangeArray_I - [objNull];
                    publicVariable 'RC_isInRangeArray_I';

                    _unitPos = getPos _unit;
                    [_unitPos] spawn
                    {
                        params ["_unitPos"];
                        sleep (RC_Test+RC_Test2);
                        //RC_isInRangeArray_I = [];
                        {
                            RC_isInRangeArray_I deleteAt (RC_isInRangeArray_I find _x);     //prevents doubles in array
                            //private _currentMag = (currentMagazine _x);
                            _isNull = isNull _x;
                            if !(_isNull) then
                            {
                                _isInRange = _unitPos inRangeOfArtillery [[_x], (currentMagazine _x)];
                                _isAlive = alive _x;
                                if (_isInRange && _isAlive) then {
                                    RC_isInRangeArray_I pushback _x;
                                    publicVariable 'RC_isInRangeArray_I';
                                };
                            };
                            sleep 0.1;
                        } forEach RC_ArtilleryArray_I;

                        if ((count RC_isInRangeArray_I) > 0) then
                        {
                            _firstInRange_I = (RC_isInRangeArray_I select 0);
                            _firstInRange_I doArtilleryFire [_unitPos, (currentMagazine _firstInRange_I), 1];

                            RC_fireMissionArray_I pushback _firstInRange_I;
                            publicVariable 'RC_fireMissionArray_I';
                            sleep 10;

                            _fireMissionNotCompleted = (({_x == _firstInRange_I} count RC_fireMissionArray_I) > 0);
                            if (_fireMissionNotCompleted) then
                            {
                                if ((count RC_isInRangeArray_I) > 1) then
                                {
                                    //for testing
                                    ["first I firemission failed"] remoteExec ["hint", west];

                                    _secondInRange_I = (RC_isInRangeArray_I select 1);
                                    _secondInRange_I doArtilleryFire [_unitPos, (currentMagazine _secondInRange_I), 1];

                                    RC_fireMissionArray_I pushback _secondInRange_I;
                                    publicVariable 'RC_fireMissionArray_I';
                                    sleep 10;

                                    _fireMissionNotCompleted = (({_x == _secondInRange_I} count RC_fireMissionArray_I) > 0);
                                    if (_fireMissionNotCompleted) then
                                    {
                                        if ((count RC_isInRangeArray_I) > 2) then
                                        {
                                            //for testing
                                            ["second I firemission failed"] remoteExec ["hint", west];

                                            _thirdInRange_I = (RC_isInRangeArray_I select 2);
                                            _thirdInRange_I doArtilleryFire [_unitPos, (currentMagazine _thirdInRange_I), 1];

                                            RC_fireMissionArray_I pushback _thirdInRange_I;
                                            publicVariable 'RC_fireMissionArray_I';
                                            sleep 10;

                                            _fireMissionNotCompleted = (({_x == _thirdInRange_I} count RC_fireMissionArray_I) > 0);
                                            if (_fireMissionNotCompleted) then
                                            {
                                                if ((count RC_isInRangeArray_I) > 3) then
                                                {
                                                    //for testing
                                                    ["third I firemission failed"] remoteExec ["hint", west];

                                                    _fourthInRange_I = (RC_isInRangeArray_I select 3);
                                                    _fourthInRange_I doArtilleryFire [_unitPos, (currentMagazine _fourthInRange_I), 1];
                                                };
                                            };
                                        };
                                    };
                                };
                            };
                        };
                    };
                };
            };
		}];
	};
}];