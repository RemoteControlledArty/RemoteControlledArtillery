//alerts pilots of respawned players to ensure short reinsert times

addMissionEventHandler ["entityRespawned", {
  params ["_entity", "_corpse"];

  if (!RC_respawnAlertToPilots) exitWith {};

  private _isPilot = ((side player) isEqualTo (side _entity)) && ((vehicle player) isKindOf "Air");  //allPlayers select {((side _x) isEqualTo _side) && ((vehicle _x) isKindOf "Air")};

  if (!_isPilot) exitWith {};

  private _grid = mapGridPosition _entity;
  private _gridX = _grid select [0, 3];
  private _gridY = _grid select [3, 3];
  private _message = "Reinsert at: " + _gridX + "-" + _gridY;

  systemChat _message;
  playSoundUI ["a3\dubbing_f\modules\supports\transport_request.ogg", 0.75, 1];
}];