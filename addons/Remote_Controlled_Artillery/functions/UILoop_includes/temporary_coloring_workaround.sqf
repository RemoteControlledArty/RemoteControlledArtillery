switch (true) do {
	// If Elevation is close/correct change the Elevation text color
	case((_realElevation < (_lowAngleSol + 0.25)) and (_realElevation > (_lowAngleSol - 0.25))): {_ctrlElevation ctrlSetTextColor [0,1,0,1];};
	case((_realElevation < (_highAngleSol + 0.25)) and (_realElevation > (_highAngleSol - 0.25))): {_ctrlElevation ctrlSetTextColor [0,1,0,1];};

	case((_realElevation < (_lowAngleSol + 0.5)) and (_realElevation > (_lowAngleSol - 0.5))): {_ctrlElevation ctrlSetTextColor [0.725,1,0.5,1];};
	case((_realElevation < (_highAngleSol + 0.5)) and (_realElevation > (_highAngleSol - 0.5))): {_ctrlElevation ctrlSetTextColor [0.725,1,0.5,1];};
	
	case((_realElevation < (_lowAngleSol + 1)) and (_realElevation > (_lowAngleSol - 1))): {_ctrlElevation ctrlSetTextColor [0.8,1,0.5,1];};
	case((_realElevation < (_highAngleSol + 1)) and (_realElevation > (_highAngleSol - 1))): {_ctrlElevation ctrlSetTextColor [0.8,1,0.5,1];};

	case((_realElevation < (_lowAngleSol + 2)) and (_realElevation > (_lowAngleSol - 2))): {_ctrlElevation ctrlSetTextColor [0.85,1,0.5,1];};
	case((_realElevation < (_highAngleSol + 2)) and (_realElevation > (_highAngleSol - 2))): {_ctrlElevation ctrlSetTextColor [0.85,1,0.5,1];};

	case((_realElevation < (_lowAngleSol + 3)) and (_realElevation > (_lowAngleSol - 3))): {_ctrlElevation ctrlSetTextColor [0.9,1,0.5,1];};
	case((_realElevation < (_highAngleSol + 3)) and (_realElevation > (_highAngleSol - 3))): {_ctrlElevation ctrlSetTextColor [0.9,1,0.5,1];};

	case((_realElevation < (_lowAngleSol + 4)) and (_realElevation > (_lowAngleSol - 4))): {_ctrlElevation ctrlSetTextColor [0.95,1,0.5,1];};
	case((_realElevation < (_highAngleSol + 4)) and (_realElevation > (_highAngleSol - 4))): {_ctrlElevation ctrlSetTextColor [0.95,1,0.5,1];};

	case((_realElevation < (_lowAngleSol + 5)) and (_realElevation > (_lowAngleSol - 5))): {_ctrlElevation ctrlSetTextColor [1,1,0.5,1];};
	case((_realElevation < (_highAngleSol + 5)) and (_realElevation > (_highAngleSol - 5))): {_ctrlElevation ctrlSetTextColor [1,1,0.5,1];};

	case((_realElevation < (_highAngleSol + 6)) and (_realElevation > (_highAngleSol - 6))): {_ctrlElevation ctrlSetTextColor [1,0.95,0.5,1];};
	case((_realElevation < (_lowAngleSol + 6)) and (_realElevation > (_lowAngleSol - 6))): {_ctrlElevation ctrlSetTextColor [1,0.95,0.5,1];};

	case((_realElevation < (_highAngleSol + 8)) and (_realElevation > (_highAngleSol - 8))): {_ctrlElevation ctrlSetTextColor [1,0.9,0.5,1];};
	case((_realElevation < (_lowAngleSol + 8)) and (_realElevation > (_lowAngleSol - 8))): {_ctrlElevation ctrlSetTextColor [1,0.9,0.5,1];};

	case((_realElevation < (_highAngleSol + 9)) and (_realElevation > (_highAngleSol - 9))): {_ctrlElevation ctrlSetTextColor [1,0.85,0.5,1];};
	case((_realElevation < (_lowAngleSol + 9)) and (_realElevation > (_lowAngleSol - 9))): {_ctrlElevation ctrlSetTextColor [1,0.85,0.5,1];};

	case((_realElevation < (_highAngleSol + 10)) and (_realElevation > (_highAngleSol - 10))): {_ctrlElevation ctrlSetTextColor [1,0.8,0.5,1];};
	case((_realElevation < (_lowAngleSol + 10)) and (_realElevation > (_lowAngleSol - 10))): {_ctrlElevation ctrlSetTextColor [1,0.8,0.5,1];};

	// If neither then set it to White again
	default {
		_ctrlElevation ctrlSetTextColor [1,1,1,1];
	};
};

switch (true) do {
	// If Azimuth is close/correct change the Azimuth text color
	case((_realAzimuth < (_targetAzimuth + 0.25)) and (_realAzimuth > (_targetAzimuth - 0.25))): {_ctrlAzimuth ctrlSetTextColor [0,1,0,1];};
	case((_realAzimuth < (_targetAzimuth + 1)) and (_realAzimuth > (_targetAzimuth - 1))): {_ctrlAzimuth ctrlSetTextColor [0.725,1,0.5,1];};
	case((_realAzimuth < (_targetAzimuth + 2)) and (_realAzimuth > (_targetAzimuth - 2))): {_ctrlAzimuth ctrlSetTextColor [0.8,1,0.5,1];};
	case((_realAzimuth < (_targetAzimuth + 3)) and (_realAzimuth > (_targetAzimuth - 3))): {_ctrlAzimuth ctrlSetTextColor [0.85,1,0.5,1];};
	case((_realAzimuth < (_targetAzimuth + 4)) and (_realAzimuth > (_targetAzimuth - 4))): {_ctrlAzimuth ctrlSetTextColor [0.9,1,0.5,1];};
	case((_realAzimuth < (_targetAzimuth + 5)) and (_realAzimuth > (_targetAzimuth - 5))): {_ctrlAzimuth ctrlSetTextColor [0.95,1,0.5,1];};
	case((_realAzimuth < (_targetAzimuth + 6)) and (_realAzimuth > (_targetAzimuth - 6))): {_ctrlAzimuth ctrlSetTextColor [1,1,0.5,1];};
	case((_realAzimuth < (_targetAzimuth + 9)) and (_realAzimuth > (_targetAzimuth - 9))): {_ctrlAzimuth ctrlSetTextColor [1,0.95,0.5,1];};
	case((_realAzimuth < (_targetAzimuth + 11)) and (_realAzimuth > (_targetAzimuth - 11))): {_ctrlAzimuth ctrlSetTextColor [1,0.9,0.5,1];};
	case((_realAzimuth < (_targetAzimuth + 15)) and (_realAzimuth > (_targetAzimuth - 15))): {_ctrlAzimuth ctrlSetTextColor [1,0.85,0.5,1];};
	case((_realAzimuth < (_targetAzimuth + 20)) and (_realAzimuth > (_targetAzimuth - 20))): {_ctrlAzimuth ctrlSetTextColor [1,0.8,0.5,1];};
	// If neither then set it to White again
	default {
		_ctrlAzimuth ctrlSetTextColor [1,1,1,1];
	};
};