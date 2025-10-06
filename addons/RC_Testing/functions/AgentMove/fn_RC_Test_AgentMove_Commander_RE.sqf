params ["_vic","_com"];

[_vic, _com] spawn {
	params ["_vic","_com"];
	
	_com moveOut _vic;
	sleep 0.25;
	_com moveInDriver _vic;
	sleep 0.25;
	_com moveOut _vic;
	sleep 0.25;
	_com moveInCommander _vic;
};