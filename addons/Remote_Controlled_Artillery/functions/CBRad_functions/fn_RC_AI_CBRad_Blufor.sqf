params ["_vehicle", "_artilleryArray_B"];


//shot source position
private _vehiclePos = getPos _vehicle;
private _angle = random 360;
private _distance = RC_CBRad_AccuracyRadius_AI * (sqrt random 1);   //first value is radius
private _targetPos = _vehiclePos getPos [_distance, _angle];


[_targetPos, _artilleryArray_B] spawn
{
    params ["_targetPos", "_artilleryArray_B"];
    //CBRad detection time
    sleep RC_CBRad_DetectionTime_AI;


    //checks if opposing artillery is in range
    private _isInRangeArray_B = [];
    {
        if !(isNull _x) then
        {
            private _isInRange = _targetPos inRangeOfArtillery [[_x], (currentMagazine _x)];
            private _isAlive = alive _x;
            if (_isInRange && _isAlive) then {
                _isInRangeArray_B pushback _x;
            };
        };
        sleep 0.1;
    } forEach _artilleryArray_B;


    //creating subarray with distance to target
    private _sortedIsInRangeArray_B = _isInRangeArray_B select {!isNull _x} apply {
        [_x distance2D player, _x]
    };
    //sorts array based on distance to target
    _sortedIsInRangeArray_B sort true;
    //re-selecting only objects
    _sortedIsInRangeArray_B = _sortedIsInRangeArray_B apply {_x#1};


    /*
    private _sortedArray = _array select {!isNull _x} apply { [_x distance2D player, _x] };
    _sortedArray sort true;
    //re-selecting only objects
    _sortedArray = _sortedArray apply {_x#1};

    //CHECK IF CBRAD ALIVE AFTER TIMER
    //servertest
    RC_ArtilleryArray_O = RC_ArtilleryArray_O select {!isNull _x} apply { [_x distance2D player, _x] };
    RC_ArtilleryArray_O sort true;
    RC_ArtilleryArray_O = RC_ArtilleryArray_O apply { _x#1 };
    private _message = str RC_ArtilleryArray_O;
    [_message] remoteExec ["hintSilent", west];
    */


    //true if atleast 1 opposing artillery is in range
    if ((count _sortedIsInRangeArray_B) > 0) then
    {
        //simulating AI preperation time before shot (AI only)
        sleep (RC_CBRad_PrepTime_AI);

        //selects first opposing artillery in range to return fire
        private _isInRange_B = (_sortedIsInRangeArray_B select 0);
        //changes locality of asset to server, as somehow only there doArtilleryFire works
        private _isInRange_B_Owner = owner _isInRange_B;
        [_isInRange_B, [_targetPos, (currentMagazine _isInRange_B), RC_CBRad_ReturnAmount_AI]] remoteExec ["doArtilleryFire", _isInRange_B_Owner];
        
        //if it doesnt shoot in time, firemission will be passed to next in isInRangeArray
        RC_fireMissionArray_B pushback _isInRange_B;
        sleep RC_CBRad_ReassignTime_AI;
        private _fireMissionNotCompleted = (({_x == _isInRange_B} count RC_fireMissionArray_B) > 0);


        if (_fireMissionNotCompleted) then
        {
            if ((count _sortedIsInRangeArray_B) > 1) then
            {
                //selects second opposing artillery in range to return fire
                _isInRange_B = (_sortedIsInRangeArray_B select 1);
                //changes locality of asset to server, as somehow only there doArtilleryFire works
                _isInRange_B_Owner = owner _isInRange_B;
                [_isInRange_B, [_targetPos, (currentMagazine _isInRange_B), RC_CBRad_ReturnAmount_AI]] remoteExec ["doArtilleryFire", _isInRange_B_Owner];
                
                //if it doesnt shoot in time, firemission will be passed to next in isInRangeArray
                RC_fireMissionArray_B pushback _isInRange_B;
                sleep RC_CBRad_ReassignTime_AI;
                _fireMissionNotCompleted = (({_x == _isInRange_B} count RC_fireMissionArray_B) > 0);


                if (_fireMissionNotCompleted) then
                {
                    if ((count _sortedIsInRangeArray_B) > 2) then
                    {
                        //selects second opposing artillery in range to return fire
                        _isInRange_B = (_sortedIsInRangeArray_B select 2);
                        //changes locality of asset to server, as somehow only there doArtilleryFire works
                        _isInRange_B_Owner = owner _isInRange_B;
                        [_isInRange_B, [_targetPos, (currentMagazine _isInRange_B), RC_CBRad_ReturnAmount_AI]] remoteExec ["doArtilleryFire", _isInRange_B_Owner];
                        
                        //if it doesnt shoot in time, firemission will be passed to next in isInRangeArray
                        RC_fireMissionArray_B pushback _isInRange_B;
                        sleep RC_CBRad_ReassignTime_AI;
                        _fireMissionNotCompleted = (({_x == _isInRange_B} count RC_fireMissionArray_B) > 0);


                        if (_fireMissionNotCompleted) then
                        {
                            if ((count _sortedIsInRangeArray_B) > 3) then
                            {
                                //selects third opposing artillery in range to return fire
                                _isInRange_B = (_sortedIsInRangeArray_B select 3);
                                //changes locality of asset to server, as somehow only there doArtilleryFire works
                                _isInRange_B_Owner = owner _isInRange_B;
                                [_isInRange_B, [_targetPos, (currentMagazine _isInRange_B), RC_CBRad_ReturnAmount_AI]] remoteExec ["doArtilleryFire", _isInRange_B_Owner];
                            };
                        };
                    };
                };
            };
        };
    };
};