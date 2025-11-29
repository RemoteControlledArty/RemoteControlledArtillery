class Man;
class CAManBase : Man {
	class ACE_SelfActions {
		class RequestFPV {
			displayName = "Request FPV";
			condition = "[_player] call RC_fnc_RC_FPV_Request_Condition";
			statement = "[_player] call RC_fnc_RC_FPV_Request_Search";
		};
	};
};