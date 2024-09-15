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


if (!isServer) exitwith {};

hint format ["%1", "CBRad EH"];

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
                hint format ["B %1", RC_ArtilleryArray_B];
            };
            case(_entitySide_O): {
                RC_ArtilleryArray_O pushback _entity;
                publicVariable 'RC_ArtilleryArray_O';
                hint format ["O %1", RC_ArtilleryArray_O];
            };
            case(_entitySide_I): {
                RC_ArtilleryArray_I pushback _entity;
                publicVariable 'RC_ArtilleryArray_I';
                hint format ["I %1", RC_ArtilleryArray_I];
            };
        };

        //need another maybe custom addEH that can be triggered by below script, so counterbattery can fire?
        //_entity addEventHandler ["CBR_trigger", {

        _this setVariable ["ArtySourceMarkersTime",0, true]; 

        //how to make sure this is not triggered by secondary turret (MG/GMG)
		_entity addEventHandler ["Fired", {
    		params ["_unit"];
            //params ["_unit", "_weapon", "_muzzle", "_mode", "_ammo", "_magazine", "_projectile", "_gunner"];

            _CBRalive_B = ({alive _x} count RC_CounterBatteryRadarArray_B) > 0;
            _CBRalive_O = ({alive _x} count RC_CounterBatteryRadarArray_O) > 0;
            _CBRalive_I = ({alive _x} count RC_CounterBatteryRadarArray_I) > 0;

            //_CBRopposed_B = (side _unit != west);
            //_CBRopposed_O = (side _unit != east);
            //_CBRopposed_I = (side _unit != resistance);

            _unitSide_B = (side _unit == west);
            _unitSide_O = (side _unit == east);
            _unitSide_I = (side _unit == resistance);

            //check if two can activate? (needed)
            //how to include script, so it doesnt need to be rewritten
            //how to put marker only on one sides map? (side of the detecting radar)
            switch (true) do {
                case(_unitSide_B and _CBRalive_O): {
                    //_unit setDamage 1;
                    private _timeInterval = 10; 
                    private _lastMarkerTime = _unit getVariable "ArtySourceMarkersTime";
                    private _timeSinceLastMarker = time - _lastMarkerTime;

                    if (_timeSinceLastMarker > _timeInterval) then {
                        _unit setVariable ["ArtySourceMarkersTime", time, true];
                        private _artySourcePos = getPos _unit;
                        private _artySourceMarker = createMarker ["_USER_DEFINED ArtySourceMarker" + str _artySourcePos, _artySourcePos];
                        _artySourceMarker setMarkerType "o_art";
                        _artySourceMarker setMarkerAlpha 0.25;

                        _artySourcePosX = round (_artySourcePos select 0);
                        _artySourcePosY = round (_artySourcePos select 1);
                        //_artySourcePosZ = round (_artySourcePos select 2);

                        hint format ["incoming! source: %1", [_artySourcePosX, _artySourcePosY]];
                    };

                    _unitPos = getPos _unit;

                    [_unitPos] spawn
                    {
                        params ["_unitPos"];
                        //check which is actually in range first then select 0, so that not all fire and give away pos, but to make sure atleast one actually fires
                        _isInRange = _unitPos inRangeOfArtillery [[(RC_ArtilleryArray_O select 0)], ((getArtilleryAmmo [(RC_ArtilleryArray_O select 0)]) select 0)];
                        //throws string error, maybe if first in array is destroyed?
                        //{_x getArtilleryAmmo select 0} forEach RC_ArtilleryArray_O;
                        
                        if (_isInRange) then {
                            sleep 6;
                            (RC_ArtilleryArray_O select 0) doArtilleryFire [_unitPos, (getArtilleryAmmo [(RC_ArtilleryArray_O select 0)]) select 0, 1];
                        };
                    };
                };
                case(_unitSide_B and _CBRalive_I): {
                    //_unit setDamage 1;
                    private _timeInterval = 10; 
                    private _lastMarkerTime = _unit getVariable "ArtySourceMarkersTime";
                    private _timeSinceLastMarker = time - _lastMarkerTime;

                    if (_timeSinceLastMarker > _timeInterval) then {
                        _unit setVariable ["ArtySourceMarkersTime", time, true];
                        private _artySourcePos = getPos _unit;
                        private _artySourceMarker = createMarker ["_USER_DEFINED ArtySourceMarker" + str _artySourcePos, _artySourcePos];
                        _artySourceMarker setMarkerType "o_art";
                        _artySourceMarker setMarkerAlpha 0.25;

                        _artySourcePosX = round (_artySourcePos select 0);
                        _artySourcePosY = round (_artySourcePos select 1);

                        hint format ["incoming! source: %1", [_artySourcePosX, _artySourcePosY]];
                    };
                };

                case(_unitSide_O and _CBRalive_B): {
                    //_unit setDamage 1;
                    private _timeInterval = 10; 
                    private _lastMarkerTime = _unit getVariable "ArtySourceMarkersTime";
                    private _timeSinceLastMarker = time - _lastMarkerTime;

                    if (_timeSinceLastMarker > _timeInterval) then {
                        _unit setVariable ["ArtySourceMarkersTime", time, true];
                        private _artySourcePos = getPos _unit;
                        private _artySourceMarker = createMarker ["_USER_DEFINED ArtySourceMarker" + str _artySourcePos, _artySourcePos];
                        _artySourceMarker setMarkerType "o_art";
                        _artySourceMarker setMarkerAlpha 0.25;

                        _artySourcePosX = round (_artySourcePos select 0);
                        _artySourcePosY = round (_artySourcePos select 1);

                        hint format ["incoming! source: %1", [_artySourcePosX, _artySourcePosY]];
                    };

                    _unitPos = getPos _unit;

                    //counterfire test
                    _unitPos spawn
                    {
                        //check which is actually in range first then select 0, so that not all fire and give away pos, but to make sure atleast one actually fires
                        _isInRange = _this inRangeOfArtillery [[(RC_ArtilleryArray_B select 0)], ((getArtilleryAmmo [(RC_ArtilleryArray_B select 0)]) select 0)];
                        
                        if (_isInRange) then {
                            sleep 6;
                            (RC_ArtilleryArray_B select 0) doArtilleryFire [_this, (getArtilleryAmmo [(RC_ArtilleryArray_B select 0)]) select 0, 1];
                        };
                    };
                };
                case(_unitSide_O and _CBRalive_I): {
                    //_unit setDamage 1;
                    private _timeInterval = 10; 
                    private _lastMarkerTime = _unit getVariable "ArtySourceMarkersTime";
                    private _timeSinceLastMarker = time - _lastMarkerTime;

                    if (_timeSinceLastMarker > _timeInterval) then {
                        _unit setVariable ["ArtySourceMarkersTime", time, true];
                        private _artySourcePos = getPos _unit;
                        private _artySourceMarker = createMarker ["_USER_DEFINED ArtySourceMarker" + str _artySourcePos, _artySourcePos];
                        _artySourceMarker setMarkerType "o_art";
                        _artySourceMarker setMarkerAlpha 0.25;

                        _artySourcePosX = round (_artySourcePos select 0);
                        _artySourcePosY = round (_artySourcePos select 1);

                        hint format ["incoming! source: %1", [_artySourcePosX, _artySourcePosY]];
                    };
                };

                case(_unitSide_I and _CBRalive_B): {
                    //_unit setDamage 1;
                    private _timeInterval = 10; 
                    private _lastMarkerTime = _unit getVariable "ArtySourceMarkersTime";
                    private _timeSinceLastMarker = time - _lastMarkerTime;

                    if (_timeSinceLastMarker > _timeInterval) then {
                        _unit setVariable ["ArtySourceMarkersTime", time, true];
                        private _artySourcePos = getPos _unit;
                        private _artySourceMarker = createMarker ["_USER_DEFINED ArtySourceMarker" + str _artySourcePos, _artySourcePos];
                        _artySourceMarker setMarkerType "o_art";
                        _artySourceMarker setMarkerAlpha 0.25;

                        _artySourcePosX = round (_artySourcePos select 0);
                        _artySourcePosY = round (_artySourcePos select 1);

                        hint format ["incoming! source: %1", [_artySourcePosX, _artySourcePosY]];
                    };
                };
                case(_unitSide_I and _CBRalive_O): {
                    //_unit setDamage 1;
                    private _timeInterval = 10; 
                    private _lastMarkerTime = _unit getVariable "ArtySourceMarkersTime";
                    private _timeSinceLastMarker = time - _lastMarkerTime;

                    if (_timeSinceLastMarker > _timeInterval) then {
                        _unit setVariable ["ArtySourceMarkersTime", time, true];
                        private _artySourcePos = getPos _unit;
                        private _artySourceMarker = createMarker ["_USER_DEFINED ArtySourceMarker" + str _artySourcePos, _artySourcePos];
                        _artySourceMarker setMarkerType "o_art";
                        _artySourceMarker setMarkerAlpha 0.25;
                        
                        _artySourcePosX = round (_artySourcePos select 0);
                        _artySourcePosY = round (_artySourcePos select 1);

                        hint format ["incoming! source: %1", [_artySourcePosX, _artySourcePosY]];
                    };
                };
            };
		}];
	};
}];


/*
if (_timeSinceLastMarker > _timeInterval) then {
    _unit setVariable ["ArtyMarkersTime",time, true]; 
    private _markerPosition = getPos _unit; 
    //private _markerPosition = position _unit;
    private _aproxArtyMarker = createMarker ["_USER_DEFINED AproxArtyMarker" + str _markerPosition, _markerPosition];
    _aproxArtyMarker setMarkerShape "o_art"; 
    //_aproxArtyMarker setMarkerSize [_radius, _radius];
    //_aproxArtyMarker setMarkerColor "colorRed";
    //_aproxArtyMarker setMarkerBrush "SolidBorder";
    //_aproxArtyMarker setMarkerAlpha 0.1; 
};
*/


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
