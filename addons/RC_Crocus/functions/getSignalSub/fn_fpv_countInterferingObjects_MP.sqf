params ["_from", "_to"];
private _intersectedSurfaces = lineIntersectsSurfaces [
	eyepos _from,
	getPosWorld _to,
	_from,
	_to,
	true,
	10,
	"FIRE",
	"NONE"
];
private _filteredObstacles = _intersectedSurfaces select { 
	private _intersectedObject = _x select 2;
	private _isParent = (_intersectedObject isEqualTo objectParent _from) || (_intersectedObject isEqualTo objectParent _to);
	!_isParent && !(_intersectedObject isKindOf "Man")
};
count _filteredObstacles