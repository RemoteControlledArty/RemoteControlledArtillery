class UserActions: UserActions
{
	class ControlsPilot
	{
		displayName="Take Pilot Controls";
		position="pos driver";
		radius=15;
		showwindow=0;
		onlyforplayer=1;
		shortcut="";

		condition="(player isEqualTo (driver this)) && (player isNotEqualTo (remoteControlled (gunner this)));";
		//statement="[this, RC_fnc_RC_TakeControlPilotGlobal] remoteExec ['call', 0]";
		statement="systemchat str time;  (driver this) action ['TakeVehicleControl', this];";
	};
	class ControlsCopilot
	{
		displayName="Take CoPilot Controls";
		position="pos gunner";
		radius=15;
		showwindow=0;
		onlyforplayer=1;
		shortcut="";

		condition="player isEqualTo (remoteControlled (gunner this));";
		//statement="[this, RC_fnc_RC_TakeControlCopilotGlobal] remoteExec ['call', 0]";
		statement="systemchat str time;  (gunner this) action ['TakeVehicleControl', this];";
	};
};