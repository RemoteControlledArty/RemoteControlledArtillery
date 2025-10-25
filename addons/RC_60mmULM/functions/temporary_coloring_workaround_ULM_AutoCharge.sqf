switch (true) do {
	// If Elevation is close/correct change the Elevation text color
	case((_realElevation < (_mediumAngleSol + 0.5)) and (_realElevation > (_mediumAngleSol - 0.5))): {_ctrlElevation ctrlSetTextColor [0,1,0,1];};
	case((_realElevation < (_mediumAngleSol + 0.75)) and (_realElevation > (_mediumAngleSol - 0.75))): {_ctrlElevation ctrlSetTextColor [0.725,1,0.5,1];};
	case((_realElevation < (_mediumAngleSol + 1)) and (_realElevation > (_mediumAngleSol - 1))): {_ctrlElevation ctrlSetTextColor [0.8,1,0.5,1];};
	case((_realElevation < (_mediumAngleSol + 2)) and (_realElevation > (_mediumAngleSol - 2))): {_ctrlElevation ctrlSetTextColor [0.85,1,0.5,1];};
	case((_realElevation < (_mediumAngleSol + 3)) and (_realElevation > (_mediumAngleSol - 3))): {_ctrlElevation ctrlSetTextColor [0.9,1,0.5,1];};
	case((_realElevation < (_mediumAngleSol + 4)) and (_realElevation > (_mediumAngleSol - 4))): {_ctrlElevation ctrlSetTextColor [0.95,1,0.5,1];};
	case((_realElevation < (_mediumAngleSol + 5)) and (_realElevation > (_mediumAngleSol - 5))): {_ctrlElevation ctrlSetTextColor [1,1,0.5,1];};
	case((_realElevation < (_mediumAngleSol + 6)) and (_realElevation > (_mediumAngleSol - 6))): {_ctrlElevation ctrlSetTextColor [1,0.95,0.5,1];};
	case((_realElevation < (_mediumAngleSol + 8)) and (_realElevation > (_mediumAngleSol - 8))): {_ctrlElevation ctrlSetTextColor [1,0.9,0.5,1];};
	case((_realElevation < (_mediumAngleSol + 9)) and (_realElevation > (_mediumAngleSol - 9))): {_ctrlElevation ctrlSetTextColor [1,0.85,0.5,1];};
	case((_realElevation < (_mediumAngleSol + 10)) and (_realElevation > (_mediumAngleSol - 10))): {_ctrlElevation ctrlSetTextColor [1,0.8,0.5,1];};

	// If neither then set it to White again
	default {
		_ctrlElevation ctrlSetTextColor [1,1,1,1];
	};
};

switch (true) do {
	// If Azimuth is close/correct change the Azimuth text color
	case((_realAzimuth < (_targetAzimuth + 0.5)) and (_realAzimuth > (_targetAzimuth - 0.5))): {_ctrlAzimuth ctrlSetTextColor [0,1,0,1];};
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