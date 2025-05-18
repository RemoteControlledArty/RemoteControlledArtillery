//disconnects uav after player death, to make it available again and not blocked

addMissionEventHandler
["entityRespawned",
{
  params ["_entity", "_corpse","_uav"];
  _uav = getConnectedUAV _corpse;
  _corpse connectTerminalToUAV objNull;
  _entity connectTerminalToUAV _uav;
}
];