private _player = missionNamespace getVariable ["bis_fnc_moduleRemoteControl_unit", player];
private _uav = getConnectedUAV _player;

// Если переменной нет, создаем ее с начальным временем
if (isNil {_uav getVariable ["RC_fpv_savedTime", nil]}) then {
    _uav setVariable ["RC_fpv_savedTime", 0];
};

// Получаем сохраненное значение
private _savedTime = _uav getVariable ["RC_fpv_savedTime", 0];
// Устанавливаем начальное время
private _startTime = time - _savedTime;

addMissionEventHandler ["EachFrame", {
	_thisArgs params ["_startTime", "_uav"];
	private _timeElapsed = time - _startTime;
	
	private _controlText = uiNameSpace getVariable ["RC_ArmaFPV_OnTimeText", controlNull];
	_controlText ctrlSetText ([_timeElapsed, "MM:SS"] call BIS_fnc_secondsToString);

	// Обновляем сохраненное время
	_uav setVariable ["RC_fpv_savedTime", _timeElapsed, true];

	if !(missionNamespace getVariable ["RC_ArmaFPV_isControl", false]) exitWith {
		removeMissionEventHandler ["EachFrame", _thisEventHandler];
	};
}, [_startTime, _uav]];
