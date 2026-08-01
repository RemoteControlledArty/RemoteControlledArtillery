RC_UV_favs = RC_UV_favs select {!isNull _x && alive _x};

private _favNameList = [];
{
	private _favName = getText (configFile >> "CfgVehicles" >> typeOf _x >> "displayName");
	_favNameList = _favNameList + [_favName];

} forEach RC_UV_favs;

hint format [
	"current favorited UV's:\n%1",
	_favNameList joinString "\n"
];

0 spawn
{
	sleep 2.5;
	hint "";
};