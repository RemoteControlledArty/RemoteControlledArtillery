//advised trajectory for ammunition, 1=low, 2=high, 3=both
_advisedTrajectory = getNumber (configFile >> "CfgMagazines" >> (currentMagazine _uav) >> "RC_AdvisedTrajectory");
switch (_advisedTrajectory) do {
	case 1: {
		_ctrlLowSol ctrlSetTextColor [1.0, 1.0, 1.0, 1.0]; 
		_ctrlLowETA ctrlSetTextColor [1.0, 1.0, 1.0, 1.0]; 
		_ctrlHighSol ctrlSetTextColor [0.5, 0.5, 0.5, 0.5]; 
		_ctrlHighETA ctrlSetTextColor [0.5, 0.5, 0.5, 0.5];
	};

	case 2: {
		_ctrlHighSol ctrlSetTextColor [1.0, 1.0, 1.0, 1.0];
		_ctrlHighETA ctrlSetTextColor [1.0, 1.0, 1.0, 1.0];
		_ctrlLowSol ctrlSetTextColor [0.5, 0.5, 0.5, 0.5];
		_ctrlLowETA ctrlSetTextColor [0.5, 0.5, 0.5, 0.5];
	};

	case 3: {
		_ctrlLowSol ctrlSetTextColor [1.0, 1.0, 1.0, 1.0]; 
		_ctrlLowETA ctrlSetTextColor [1.0, 1.0, 1.0, 1.0]; 
		_ctrlHighSol ctrlSetTextColor [1.0, 1.0, 1.0, 1.0]; 
		_ctrlHighETA ctrlSetTextColor [1.0, 1.0, 1.0, 1.0];
	};
};