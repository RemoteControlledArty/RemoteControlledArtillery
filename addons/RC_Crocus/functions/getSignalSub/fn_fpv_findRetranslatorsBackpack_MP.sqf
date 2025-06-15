params ["_position", "_radius", "_side"];

private _retranslators = [];
private _backpackArray = ["RC_SignalBoosterLRR_blk", "RC_SignalBoosterLRR_mtp", "RC_SignalBoosterLRR_tropic", "RC_SignalBoosterLRR_wdl", "RC_SignalBoosterLRR_a", "RC_SignalBoosterLRR_g", "RC_SignalBoosterLRR_ilbe_A", "RC_SignalBoosterLRR_ilbe_G", "RC_SignalBoosterLRR_ilbe_MC"];
private _backpack = backpack _player;

if ({ _x in _backpack } count _backpackArray > 0) then {
	_retranslators = [_player];
};

_retranslators