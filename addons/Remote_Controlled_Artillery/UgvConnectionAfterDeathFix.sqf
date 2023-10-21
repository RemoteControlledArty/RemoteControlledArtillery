addMissionEventHandler
["entityRespawned",
{
  params ["_entity", "_corpse","_uav"];
  _uav = getConnectedUAV _corpse;
  _corpse connectTerminalToUAV objNull;
  _entity connectTerminalToUAV _uav;
}
];