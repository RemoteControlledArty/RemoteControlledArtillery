/*
	Author: Ascent

	Description:
	Dazzler
*/

params ["_vic"];

//systemchat "add dazzler server"; 	//debug

private _ownerID = owner _vic;
[_vic, ["RC_1Rnd_Dazzler_M", [-1], 1]] remoteExec ["addMagazineTurret", _ownerID];