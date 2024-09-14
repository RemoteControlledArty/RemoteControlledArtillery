/*
 * Author: Eric & Ascent
 * Checks spawned vehicles if they have the value "artilleryscanner=1;", to apply eventhandler that scans for enemy counter battery radar to mark it on map after firing.
 * Needs to be preinit to work on 3den spawned vehicles.
*/


if (!isServer) exitwith {};

addMissionEventHandler ["EntityCreated", {
	params ["_entity"];
	_isArtillery = getNumber (configFile >> "CfgVehicles" >> (typeOf _entity) >> "artilleryScanner") == 1;

	if (_isArtillery) then {
		_entity addEventHandler ["Fired", { 
    		params ["_unit", "_weapon", "_muzzle", "_mode", "_ammo", "_magazine", "_projectile", "_gunner"];

			_unit setDamage 1;
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
