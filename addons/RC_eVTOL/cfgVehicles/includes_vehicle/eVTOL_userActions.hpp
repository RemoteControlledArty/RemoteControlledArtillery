class UserActions: UserActions
{
	class RC_Detach
	{
		displayName="Detach";
		position="pos driver";
		radius=1.5;
		showwindow=0;
		onlyforplayer=1;
		shortcut="";

		condition="(this isEqualTo (vehicle player)) && (!isRemoteControlling player) && ((attachedTo this) isNotEqualTo objNull)";
		statement="[this] spawn fnc_RC_eVTOL_detach";
	};


	class RC_Attach
	{
		displayName="Attach";
		position="pos driver";
		radius=1.5;
		showwindow=0;
		onlyforplayer=1;
		shortcut="";

		//condition="(this isEqualTo (vehicle player)) && (!isRemoteControlling player) && ((attachedTo this) isEqualTo objNull)";
		condition="((this animationSourcePhase 'FoldArms') == 1) && ((this distance cursorObject) < 5) && (this isEqualTo (vehicle player)) && (!isRemoteControlling player)";
		statement="[this, cursorObject] spawn fnc_RC_eVTOL_attach";
	};


	class FoldArms
	{
		displayName="Fold Arms";
		position="pos driver";
		radius=1.5;
		showwindow=0;
		onlyforplayer=1;
		shortcut="";

		condition="((this animationSourcePhase 'FoldArms') == 0) && ((!(isEngineOn this)) && (!isRemoteControlling player))";
		statement="[this, 1, player] call GYGJetson_fnc_setFold;";
	};


	class UnfoldArms
	{
		displayName="removed";
		position="pos driver";
		radius=0;
		showwindow=0;
		onlyforplayer=1;
		shortcut="";

		condition="false";
		statement="";
	};
};