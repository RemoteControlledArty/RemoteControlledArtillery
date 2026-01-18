/*
	Author: Ascent

	Description:
	Beep for newly detected UAV in Datalink.
	Only runs server side to save performance.
*/

if (!isServer) exitWith {};

[] spawn {

	//private _cycle = 0;
	//private _oldTargetsCount = 0;

	while {true} do {
		
		//4*0.75 sleeps = 3sec loop
		sleep 0.75;

		RC_CUAS_VehArray = RC_CUAS_VehArray select {!isNull _x && alive _x};

		if (count RC_CUAS_VehArray < 1) then {
			sleep 2.25;
			continue;
		};

		//seperates the alive vehicles by side, then counts each
		private _CUAS_VehArray_B = [];
		private _CUAS_VehArray_O = [];
		private _CUAS_VehArray_I = [];
		{
			private _side = side _x;
			
			switch (true) do {
				case(_side == west): {
					_CUAS_VehArray_B pushback _x;
				};
				case(_side == east): {
					_CUAS_VehArray_O pushback _x;
				};
				case(_side == resistance): {
					_CUAS_VehArray_I pushback _x;
				};
			};
		} forEach RC_CUAS_VehArray;


		sleep 0.75;

		if (count _CUAS_VehArray_B > 0) then {
			
			[_CUAS_VehArray_B, west] call RC_fnc_RC_cUAS_Beep_Call;
		};

		sleep 0.75;

		if (count _CUAS_VehArray_O > 0) then {
			
			[_CUAS_VehArray_O, east] call RC_fnc_RC_cUAS_Beep_Call;
		};

		sleep 0.75;

		if (count _CUAS_VehArray_I > 0) then {
			
			[_CUAS_VehArray_I, resistance] call RC_fnc_RC_cUAS_Beep_Call;
		};
	};
};