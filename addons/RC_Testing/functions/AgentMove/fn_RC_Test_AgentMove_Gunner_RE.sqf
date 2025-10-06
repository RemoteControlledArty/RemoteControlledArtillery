params ["_vic","_gun"];

[_vic, _gun] spawn {
	params ["_vic","_gun"];
	
	_gun moveOut _vic;
	sleep 0.25;
	_gun moveInDriver _vic;
	sleep 0.25;
	_gun moveOut _vic;
	sleep 0.25;
	_gun moveInGunner _vic;
};