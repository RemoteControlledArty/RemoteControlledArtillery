[] spawn {
	private _weakSignalDuration = 0;
	private _specialEffectTime = 0;

	while { missionNamespace getVariable ["ArmaFPV_isControl", false] } do {
		// UI
		private _player = missionNamespace getVariable ["bis_fnc_moduleRemoteControl_unit", player];
		private _uav = getConnectedUAV _player;
		
		private _signal = [_player, _uav] call DB_fnc_fpv_getSignal;
		private _altitude = getPos _uav select 2;
		private _controlPicture = uiNameSpace getVariable ["ArmaFPV_SignalPicture", controlNull];
		private _controlText = uiNameSpace getVariable ["ArmaFPV_SignalText", controlNull];
		private _picture = "";

		if (_signal < 0.05) then {
			_weakSignalDuration = _weakSignalDuration + 0.2;
			if (_weakSignalDuration >= 5) then {
				[_player, _uav] call RC_fnc_fpv_onSignalLost_MP;
				_weakSignalDuration = 0;
			};
		} else {
			_weakSignalDuration = 0;
		};

		if (_signal < 0.3 && _altitude < 20) then {
			_randomChance = random 1;
			
			if (_randomChance > 0.9 && _specialEffectTime <= 0) then {
				PP_colorC = ppEffectCreate ["ColorCorrections",1500];
				PP_colorC ppEffectEnable true;
				PP_colorC ppEffectAdjust [1.08,0.67,0.06,[0,0,0.45,0.06],[1,1,0.93,1.61],[0.33,0.33,0.15,0.2],[0,0,0,0,0,0,5]];
				PP_colorC ppEffectCommit 0;
				PP_dynamic = ppEffectCreate ["DynamicBlur",500];
				PP_dynamic ppEffectEnable true;
				PP_dynamic ppEffectAdjust [0.4];
				PP_dynamic ppEffectCommit 0;
				PP_film = ppEffectCreate ["FilmGrain",2000];
				PP_film ppEffectEnable true;
				PP_film ppEffectAdjust [1,0.47,4.26,0.5,0.5,true];
				PP_film ppEffectCommit 0;

				_specialEffectTime = 2;
			};
		};

		if (_specialEffectTime > 0) then {
			_specialEffectTime = _specialEffectTime - 0.2;
			
			if (_specialEffectTime <= 0) then {
				ppEffectDestroy PP_colorC;
				ppEffectDestroy PP_dynamic;
				ppEffectDestroy PP_film;
			};
		};

		switch (true) do {
			case (_signal > 0.75): { _picture = "\ArmaFPV\pictures\100.paa"; };
			case (_signal > 0.5): { _picture = "\ArmaFPV\pictures\75.paa" };
			case (_signal > 0.25): { _picture = "\ArmaFPV\pictures\50.paa" };
			case (_signal > 0): { _picture = "\ArmaFPV\pictures\25.paa" };
			case (_signal <= 0): { _picture = "\ArmaFPV\pictures\0.paa" };
			default { _picture = "\ArmaFPV\pictures\100.paa" };
		};

		_controlPicture ctrlSetText _picture;
		_controlText ctrlSetText str(round(_signal * 100));

		// EFFECTS
		private _ppEffect = missionNameSpace getVariable ["DB_fpv_ppEffect", []];
		private _adjust = linearConversion [1, 0, _signal, 0.1, 1.0];
		
		if (_ppEffect isNotEqualTo []) then {
			{
				ppEffectDestroy _x;
			} forEach _ppEffect;
		};

		private _PP_colorC = ppEffectCreate ["ColorCorrections", 1500];
		_PP_colorC ppEffectEnable true;
		_PP_colorC ppEffectAdjust [[1.08, 1.2, _adjust] call BIS_fnc_lerp, [0.67, 1, _adjust] call BIS_fnc_lerp, 0.06, [0,0,0.45,0.06], [1,1,0.93,1.61], [0.33, 0.33, 0.15, 0.2], [0, 0, 0, 0, 0, 0, 5]];
		_PP_colorC ppEffectCommit 0;

		private _PP_dynamic = ppEffectCreate ["DynamicBlur", 500];
		_PP_dynamic ppEffectEnable true;
		_PP_dynamic ppEffectAdjust [[0.2, 0.7, _adjust] call BIS_fnc_lerp];
		_PP_dynamic ppEffectCommit 0;

		private _PP_film = ppEffectCreate ["FilmGrain", 2000];
		_PP_film ppEffectEnable true;
		_PP_film ppEffectAdjust [[0.04, 1, _adjust] call BIS_fnc_lerp, 1, [4.09, 4.5, _adjust] call BIS_fnc_lerp, 0.5, 0.5, true];
		_PP_film ppEffectCommit 0;


		missionNameSpace setVariable ["DB_fpv_ppEffect", [_PP_colorC, _PP_dynamic, _PP_film]];

		sleep 0.2;
	};
};