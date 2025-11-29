params ["_player"];

private _playerEquipment = [goggles _player, headgear _player];
{if (_x in _playerEquipment) exitWith {true}} forEach ["RC_SO_Glasses", "RC_SO_Goggles_tan", "RC_SO_Goggles_grn", "RC_SO_Goggles_blk", "RC_SO_Goggles_NV_tan", "RC_SO_Goggles_NV_grn", "RC_SO_Goggles_NV_blk", "RC_SO_Goggles_TI_tan", "RC_SO_Goggles_TI_grn", "RC_SO_Goggles_TI_blk"];