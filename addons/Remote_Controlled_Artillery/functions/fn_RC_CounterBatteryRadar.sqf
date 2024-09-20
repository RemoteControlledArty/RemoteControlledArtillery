/*
 * Author: Eric & Ascent
 * Checks spawned vehicles if they have the value "artilleryscanner=1;", to apply eventhandler that scans for enemy counter battery radar to mark it on map after firing.
 * Needs to be preinit to work on 3den spawned vehicles.
*/

RC_CounterBatteryRadarArray_B = [];
RC_CounterBatteryRadarArray_O = [];
RC_CounterBatteryRadarArray_I = [];
publicVariable "RC_CounterBatteryRadarArray_B";
publicVariable "RC_CounterBatteryRadarArray_O";
publicVariable "RC_CounterBatteryRadarArray_I";

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
                //hint format ["B %1", RC_ArtilleryArray_B];
            };
            case(_entitySide_O): {
                RC_ArtilleryArray_O pushback _entity;
                publicVariable 'RC_ArtilleryArray_O';
                //hint format ["O %1", RC_ArtilleryArray_O];
            };
            case(_entitySide_I): {
                RC_ArtilleryArray_I pushback _entity;
                publicVariable 'RC_ArtilleryArray_I';
                //hint format ["I %1", RC_ArtilleryArray_I];
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
                    };
                    case(_unitSide_O): {
                        RC_fireMissionArray_O deleteAt (RC_fireMissionArray_O find _unit);
                        publicVariable "RC_fireMissionArray_O";
                    };
                    case(_unitSide_I): {
                        RC_fireMissionArray_I deleteAt (RC_fireMissionArray_I find _unit);
                        publicVariable "RC_fireMissionArray_I";
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

                _CBRalive_B = ({alive _x} count RC_CounterBatteryRadarArray_B) > 0;
                _CBRalive_O = ({alive _x} count RC_CounterBatteryRadarArray_O) > 0;
                _CBRalive_I = ({alive _x} count RC_CounterBatteryRadarArray_I) > 0;

                _opposedTo_B = [side _unit, west] call BIS_fnc_sideIsEnemy;
                _opposedTo_O = [side _unit, east] call BIS_fnc_sideIsEnemy;
                _opposedTo_I = [side _unit, resistance] call BIS_fnc_sideIsEnemy;

                //can two can activate? (needed)
                switch (true) do {
                    //Blufor
                    case(_opposedTo_B and _CBRalive_B): {
                        private _timeInterval = 10;
                        private _lastMarkerTime = _unit getVariable "ArtySourceMarkersTime";
                        private _timeSinceLastMarker = time - _lastMarkerTime;

                        if (_timeSinceLastMarker > _timeInterval) then {
                            _unit setVariable ["ArtySourceMarkersTime", time, true];
                            private _artySourcePos = getPosASL _unit;

                            _markerName = ("_USER_DEFINED ArtySourceMarker" + str _artySourcePos);
                            _markerArray = [_markerName, _artySourcePos, 1];

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
                        };

                        _unitPos = getPos _unit;
                        [_unitPos] spawn
                        {
                            params ["_unitPos"];
                            sleep (RC_Test+RC_Test2);
                            //RC_isInRangeArray_B = [];
                            {
                                RC_isInRangeArray_B deleteAt (RC_isInRangeArray_B find _x);     //prevents doubles in array
                                //You can remove duplicates (get unique items) with this command:
                                //private _myArray = [1, 2, 2, 3, 4];
                                //private _result = _myArray arrayIntersect _myArray; // _result is [1, 2, 3, 4]

                                //private _currentMag = (currentMagazine _x);
                                _isInRange = _unitPos inRangeOfArtillery [[_x], (currentMagazine _x)];
                                _isAlive = alive _x;
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
                                            };
                                        };
                                    };
                                };
                            };
                        };
                    };

                    //Opfor
                    case(_opposedTo_O and _CBRalive_O): {
                        private _timeInterval = 10; 
                        private _lastMarkerTime = _unit getVariable "ArtySourceMarkersTime";
                        private _timeSinceLastMarker = time - _lastMarkerTime;

                        if (_timeSinceLastMarker > _timeInterval) then {
                            _unit setVariable ["ArtySourceMarkersTime", time, true];
                            private _artySourcePos = getPosASL _unit;
                            
                            _markerName = ("_USER_DEFINED ArtySourceMarker" + str _artySourcePos);
                            _markerArray = [_markerName, _artySourcePos, 1];
                            
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
                        };

                        _unitPos = getPos _unit;
                        [_unitPos] spawn
                        {
                            params ["_unitPos"];
                            sleep (RC_Test+RC_Test2);
                            //RC_isInRangeArray_O = [];
                            {
                                RC_isInRangeArray_O deleteAt (RC_isInRangeArray_O find _x);     //prevents doubles in array

                                //private _currentMag = (currentMagazine _x);
                                _isInRange = _unitPos inRangeOfArtillery [[_x], (currentMagazine _x)];
                                _isAlive = alive _x;
                                if (_isInRange && _isAlive) then {
                                    RC_isInRangeArray_O pushback _x;
                                    publicVariable 'RC_isInRangeArray_O';
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
                                                _thirdInRange_O = (RC_isInRangeArray_O select 2);
                                                _thirdInRange_O doArtilleryFire [_unitPos, (currentMagazine _thirdInRange_O), 1];
                                            };
                                        };
                                    };
                                };
                            };
                            /*
                            if ((count RC_isInRangeArray_O) > 0) then
                            {
                                (RC_isInRangeArray_O select 0) doArtilleryFire [_unitPos, (currentMagazine (RC_isInRangeArray_O select 0)), 1];
                            };
                            if ((count RC_isInRangeArray_O) > 1) then
                            {
                                (RC_isInRangeArray_O select 1) doArtilleryFire [_unitPos, (currentMagazine (RC_isInRangeArray_O select 1)), 1];
                            };
                            */
                        };
                    };

                    //Independent
                    case(_opposedTo_I and _CBRalive_I): {
                        private _timeInterval = 10; 
                        private _lastMarkerTime = _unit getVariable "ArtySourceMarkersTime";
                        private _timeSinceLastMarker = time - _lastMarkerTime;

                        if (_timeSinceLastMarker > _timeInterval) then {
                            _unit setVariable ["ArtySourceMarkersTime", time, true];
                            private _artySourcePos = getPosASL _unit;
                            
                            _markerName = ("_USER_DEFINED ArtySourceMarker" + str _artySourcePos);
                            _markerArray = [_markerName, _artySourcePos, 1];
 
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
                        };

                        _unitPos = getPos _unit;
                        [_unitPos] spawn
                        {
                            params ["_unitPos"];
                            sleep (RC_Test+RC_Test2);
                            //RC_isInRangeArray_I = [];
                            {
                                RC_isInRangeArray_I deleteAt (RC_isInRangeArray_I find _x);     //prevents doubles in array
                                //private _currentMag = (currentMagazine _x);
                                _isInRange = _unitPos inRangeOfArtillery [[_x], (currentMagazine _x)];
                                _isAlive = alive _x;
                                if (_isInRange && _isAlive) then {
                                    RC_isInRangeArray_I pushback _x;
                                    publicVariable 'RC_isInRangeArray_I';
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
                                        _secondInRange_I = (RC_isInRangeArray_I select 1);
                                        _secondInRange_I doArtilleryFire [_unitPos, (currentMagazine _secondInRange_I), 1];
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


//needs some work creates red areas, optimally instead if the position didnt change a NATO symbol enemy artillery map marker should be made
//and a warning message "incoming grit ?, source grit ?"
/*
_this setVariable ["ArtyMarkersTime",0, true]; 

_this addEventHandler ["Fired", { 
    params ["_unit", "_weapon", "_muzzle", "_mode", "_ammo", "_magazine", "_projectile", "_gunner"];


private _timeInterval = 10; 
private _lastMarkerTime = _unit getVariable "ArtyMarkersTime";
private _timeSinceLastMarker = time - _lastMarkerTime;


if (_timeSinceLastMarker > _timeInterval) then {
    _unit setVariable ["ArtyMarkersTime",time, true]; 
    private _artyLocation = getPos _unit; 
    private _radius = 100; 

    private _angle = random 360;     
    private _randomSquareRoot = sqrt random 1;    
    private _distance = _radius * _randomSquareRoot;  
    private _markerPosition = _artyLocation getPos [_distance, _angle];

    private _aproxArtyMarker = createMarker ["_USER_DEFINED AproxArtyMarker" + str _markerPosition, _markerPosition];

    _aproxArtyMarker setMarkerShape "ELLIPSE"; 
    _aproxArtyMarker setMarkerSize [_radius, _radius];
    _aproxArtyMarker setMarkerColor "colorRed";
    _aproxArtyMarker setMarkerBrush "SolidBorder";
    _aproxArtyMarker setMarkerAlpha 0.1; 
    };

}];
*/
