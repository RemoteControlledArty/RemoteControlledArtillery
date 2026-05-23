/*
 * Author: Ascent
 * Public: No.
*/


if (!hasInterface) exitWith {};


RC_M30_On = false;
RC_M30_Arr = [];


player addEventHandler ["OpticsSwitch", {
	params ["_unit", "_isADS"];

	if (_isADS) then {
		0 spawn {
			sleep 0.3;
			if (((currentWeapon player) isEqualTo "RC_M30") && (cameraView == "GUNNER") && (!isRemoteControlling player) && (vehicle player isEqualTo player)) then {
				RC_M30_On = true;
				
				//to prevent bug
				sleep 0.5;
				if (cameraView != "GUNNER") then {
					RC_M30_On = false;
				};
			} else {
				RC_M30_On = false;
			};
		};
	} else {
		RC_M30_On = false;
	};
}];


//to prevent bug
player addEventHandler ["SlotItemChanged", {

	if ((currentWeapon player) isNotEqualTo "RC_M30") then {
		RC_M30_On = false;
	};
}];


[] spawn
{
	while {true} do {

		if (RC_M30_On) then {
			private _arr = listRemoteTargets side player;

			RC_M30_Arr = [];

			{
				private _t = _x select 0;

				if ((!isNull _t) && (alive _t)) then {

					if (_t isKindOf "LaserTarget") then {

						private _d = round (_t distance player);
						
						if (_d < 1000) then {

							//private _o = (1 - (_d / 1000))^2;
							//_o = _o max 0.15 min 0.4;
							//private _c = [1, 0, 0, _o];
							private _c = [1, 0, 0, 0.75];
							private _n = "Lase " + str _d + "m";

							RC_M30_Arr pushBack [_c, _t, _n];
						};
					};


					if (_t isKindOf "RC_GPSDatalinkTarget") then {

						private _d = round (_t distance player);
						
						if (_d < 1000) then {

							//private _o = (1 - (_d / 1000))^2;
							//_o = _o max 0.15 min 0.4;
							//private _c = [1, 0, 0, _o];
							private _c = [1, 0, 0, 0.75];
							private _n = "GPS " + str _d + "m";

							RC_M30_Arr pushBack [_c, _t, _n];
						};
					};
				};

			} forEach _arr;

			sleep 0.5;
		};

		sleep 0.5;
	};
};


addMissionEventHandler ["Draw3D", {
	if (RC_M30_On) then {
		{	
			drawIcon3D ["\A3\ui_f\data\map\markers\handdrawn\dot_CA.paa", _x select 0, ASLToAGL (eyePos (_x select 1)), 0.25, 0.25, 45, _x select 2, 1, 0.03, "PuristaMedium"];
		} forEach RC_M30_Arr;
	};
}];