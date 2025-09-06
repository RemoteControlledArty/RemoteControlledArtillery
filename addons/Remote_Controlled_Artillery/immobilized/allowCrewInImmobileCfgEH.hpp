class LandVehicle;
class Tank: LandVehicle {
	class EventHandlers {
		class RC_Immobilized {
			init="_this call RC_fnc_RC_allowCrewInImmobile;";
		};
	};
};
class Wheeled_APC_F: LandVehicle {
	class EventHandlers {
		class RC_Immobilized {
			init="_this call RC_fnc_RC_allowCrewInImmobile;";
		};
	};
};
class APC_Tracked_F: Tank {
	class EventHandlers {
		class RC_Immobilized {
			init="_this call RC_fnc_RC_allowCrewInImmobile;";
		};
	};
};