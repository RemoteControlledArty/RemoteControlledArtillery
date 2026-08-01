params ["_targetName", "_magName", "_distance", "_charge", "_MIL", "_aligned", "_ETA"];

//ETA and "splash in 3sec" notification for crew / UV controller
[_targetName, _magName, _distance, _charge, _MIL, _aligned, _ETA] spawn {
	params ["_targetName", "_magName", "_distance", "_charge", "_MIL", "_aligned", "_ETA"];

	if (_ETA > 0) then {

		systemChat format ["%1,  %2,  %3m,  Ch%4,  %5 MIL,  %6,  %7sec", _targetName, _magName, round _distance, _charge, round _MIL, _aligned, round _ETA];


		if (_ETA > 3) then {
			sleep (_ETA - 3);
			systemChat "splash in 3sec";
			sleep 3;
		} else {
			sleep _ETA;
		};

		systemChat "splash";
	} else {
		systemChat format ["%1,  %2,  ?m,  Ch%3,  %4 MIL,  %5,  ?sec", _targetName, _magName, _charge, round _MIL, _aligned];
	};
};