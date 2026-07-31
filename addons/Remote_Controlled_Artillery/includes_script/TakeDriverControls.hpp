class TakeDriveControlsCommander
{
	displayName="Take Drive Controls";
	position="pos commander";
	radius=15;
	showwindow=0;
	onlyforplayer=1;
	shortcut="";

	condition="(player isEqualTo (commander this)) && (!local (driver this));";
	statement="[this, RC_fnc_RC_TakeControlCommanderServer] remoteExec ['call', 2]";
};
class TransferDriveControlsCommander: TakeDriveControlsCommander
{
	displayName="Transfer Drive Controls";

	condition="(player isEqualTo (commander this)) && (local (driver this)) && (isPlayer (gunner this));";
	statement="[this, RC_fnc_RC_TransferControlCommanderServer] remoteExec ['call', 2]";
};


class TakeDriveControlsGunner
{
	displayName="Take Drive Controls";
	position="pos gunner";
	radius=15;
	showwindow=0;
	onlyforplayer=1;
	shortcut="";

	condition="(player isEqualTo (gunner this)) && (!local (driver this));";
	statement="[this, RC_fnc_RC_TakeControlGunnerServer] remoteExec ['call', 2]";
};
class TransferDriveControlsGunner: TakeDriveControlsGunner
{
	displayName="Transfer Drive Controls";

	condition="(player isEqualTo (gunner this)) && (local (driver this)) && (isPlayer (commander this));";
	statement="[this, RC_fnc_RC_TransferControlGunnerServer] remoteExec ['call', 2]";
};