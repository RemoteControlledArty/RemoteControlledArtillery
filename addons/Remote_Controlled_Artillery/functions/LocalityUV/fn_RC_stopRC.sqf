player remoteControl objNull;
player switchCamera "INTERNAL";

//close terminal if it opens
0 spawn {
    sleep 0.2;	//wait if terminal opens

    private _uavDisplay = findDisplay 160;
    if (!isNull _uavDisplay) then {
        _uavDisplay closeDisplay 1;
    };
};