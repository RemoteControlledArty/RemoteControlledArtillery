/*
	Author: Ascent

	Description:
	Temporary fix for anti drone sensors being destroyed by the arma update due to before unused cfgVehicles value "visualTargetSize = factor;" now having an effect.
	Problem is 400m C-UAS visual sensor * 0.05 FPV drone visual target size = 20m... 400m would take 8000m sensor which would be OP against helixopters and planes...
	So this script checks for spawned vehicles with too small visualTargetSize and sets it to 1 until alternative fix is found.
*/


addMissionEventHandler ["EntityCreated", {
	params ["_entity"];
	
	//if (!local _entity) exitwith {};

	private _type = typeOf _entity;
	private _visSize = getNumber (configFile >> "CfgVehicles" >> _type >> "visualTargetSize");

	if (_visSize < 1) then {

		private _irSize = getNumber (configFile >> "CfgVehicles" >> _type >> "irTargetSize");
		private _radSize = getNumber (configFile >> "CfgVehicles" >> _type >> "radarTargetSize");

		//global argument, local effect
		_entity setTargetSize [1, _irSize, _radSize];

		//if used with "if (!local _entity) exitwith {};" at the start:
		//[_entity, [1, _irSize, _radSize]] remoteExec ["setTargetSize", 0, true];
	};
}];