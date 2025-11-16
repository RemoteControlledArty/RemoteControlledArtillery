// shows if its not, almost, or fully aligned
switch (true) do {
	/*
	// warn if closer than guided triggerDistance (dangerous if near cover)
	case(
		(_lockedGuided) and (_distance < _triggerDistance)
	): {
		_ctrlMessage ctrlSetTextColor [1,0.5,0,1];
		_ctrlMessage ctrlSetPositionX (0.909967 * safezoneW + safezoneX);
		_ctrlMessage ctrlSetText "TOO CLOSE FOR GUIDED EXCEPT LOS";
	};
	*/

	// if guided allow larger margin for much faster alignment
	case(
		(_lockedGuided) and
		(_adjustedVelocityHigh > 0) and
		(_realElevation < (_highAngleSol + 6)) and
		(_realElevation > (_highAngleSol - 6)) and
		(_realAzimuth < (_targetAzimuth + 6)) and
		(_realAzimuth > (_targetAzimuth - 6))
	): {
		_ctrlMessage ctrlSetTextColor [0,1,0,1];
		_ctrlMessage ctrlSetPositionX (0.906267 * safezoneW + safezoneX);
		_ctrlMessage ctrlSetText "ALIGNED";
	};
	case(
		(_lockedGuided) and
		(_adjustedVelocityMedium > 0) and
		(_realElevation < (_mediumAngleSol + 6)) and
		(_realElevation > (_mediumAngleSol - 6)) and
		(_realAzimuth < (_targetAzimuth + 6)) and
		(_realAzimuth > (_targetAzimuth - 6))
	): {
		_ctrlMessage ctrlSetTextColor [0,1,0,1];
		_ctrlMessage ctrlSetPositionX (0.906267 * safezoneW + safezoneX);
		_ctrlMessage ctrlSetText "ALIGNED";
	};
	
	case(
		(_adjustedVelocityHigh > 0) and
		(_realElevation < (_highAngleSol + 0.5)) and
		(_realElevation > (_highAngleSol - 0.5)) and
		(_realAzimuth < (_targetAzimuth + 0.5)) and
		(_realAzimuth > (_targetAzimuth - 0.5))
	): {
		_ctrlMessage ctrlSetTextColor [0,1,0,1];
		_ctrlMessage ctrlSetPositionX (0.906267 * safezoneW + safezoneX);
		_ctrlMessage ctrlSetText "ALIGNED";
	};
	case(
		(_adjustedVelocityMedium > 0) and
		(_realElevation < (_mediumAngleSol + 0.5)) and
		(_realElevation > (_mediumAngleSol - 0.5)) and
		(_realAzimuth < (_targetAzimuth + 0.5)) and
		(_realAzimuth > (_targetAzimuth - 0.5))
	): {
		_ctrlMessage ctrlSetTextColor [0,1,0,1];
		_ctrlMessage ctrlSetPositionX (0.906267 * safezoneW + safezoneX);
		_ctrlMessage ctrlSetText "ALIGNED";
	};

	case(
		(! _lockedGuided) and
		(_adjustedVelocityHigh > 0) and
		(_realElevation < (_highAngleSol + 1)) and
		(_realElevation > (_highAngleSol - 1)) and
		(_realAzimuth < (_targetAzimuth + 1)) and
		(_realAzimuth > (_targetAzimuth - 1))
	): {
		_ctrlMessage ctrlSetTextColor [1,0.5,0,1];
		_ctrlMessage ctrlSetPositionX (0.909967 * safezoneW + safezoneX);
		_ctrlMessage ctrlSetText "NOT ALIGNED";
	};
	case(
		(! _lockedGuided) and
		(_adjustedVelocityMedium > 0) and
		(_realElevation < (_mediumAngleSol + 1)) and
		(_realElevation > (_mediumAngleSol - 1)) and
		(_realAzimuth < (_targetAzimuth + 1)) and
		(_realAzimuth > (_targetAzimuth - 1))
	): {
		_ctrlMessage ctrlSetTextColor [1,0.5,0,1];
		_ctrlMessage ctrlSetPositionX (0.909967 * safezoneW + safezoneX);
		_ctrlMessage ctrlSetText "NOT ALIGNED";
	};

	case(
		(_adjustedVelocityHigh == 0) and
		(! _usingMediumAngle)
	): {
		_ctrlMessage ctrlSetTextColor [1,0,0,1];
		_ctrlMessage ctrlSetPositionX (0.909967 * safezoneW + safezoneX);
		_ctrlMessage ctrlSetText "NOT IN RANGE";
	};
	case(
		(_adjustedVelocityMedium == 0) and
		(_usingMediumAngle)
	): {
		_ctrlMessage ctrlSetTextColor [1,0,0,1];
		_ctrlMessage ctrlSetPositionX (0.909967 * safezoneW + safezoneX);
		_ctrlMessage ctrlSetText "NOT IN RANGE";
	};

	default {
		_ctrlMessage ctrlSetTextColor [1,0,0,1];
		_ctrlMessage ctrlSetPositionX (0.909967 * safezoneW + safezoneX);
		_ctrlMessage ctrlSetText "NOT ALIGNED";
	};
};