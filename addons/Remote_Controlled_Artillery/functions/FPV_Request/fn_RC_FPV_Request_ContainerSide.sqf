//required to define side of storage container, so neutral throwable FPV can be requested from container last opened from specific side

player addEventHandler ["InventoryClosed", {
	params ["_unit", "_container"];

	_container setVariable ["RC_FPV_ContainerSide", side player, true];
}];