class UserActions: UserActions
{
	class Detach
	{
		displayName="Detach";
		position="pos driver";
		radius=1.5;
		showwindow=0;
		onlyforplayer=1;
		shortcut="";

		condition="(this isEqualTo (vehicle player)) && (!isRemoteControlling player) && ((attachedTo this) isNotEqualTo objNull)";
		statement="this disableCollisionWith (attachedTo this); detach this;";
		//statement="this disableCollisionWith (attachedTo this); detach this; this engineOn true;";
	};
};