/*
	Author: Ascent
*/

[] spawn
{
	while {true} do
	{
		_uv = (getConnectedUAV player);

		// restart if no UV is connected
		if (_uv isEqualTo objNull) then {continue;};

		sleep 1;
	};
};