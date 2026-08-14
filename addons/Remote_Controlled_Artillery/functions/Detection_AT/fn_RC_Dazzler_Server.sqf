/*
	Author: Ascent

	Description:
	Dazzler
*/

params ["_vic", "_proj"];

//systemchat "Dazzler server"; 	//debug

//needs to be run where projectile is local, owner can only be found on server
private _ownerID = owner _proj;
[_vic, _proj] remoteExec ["RC_fnc_RC_Dazzler_Local", _ownerID];