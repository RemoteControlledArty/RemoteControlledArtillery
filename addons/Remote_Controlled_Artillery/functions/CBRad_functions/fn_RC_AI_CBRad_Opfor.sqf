params ["_vehicle", "_artilleryArray_O"];


//shot source position
private _vehiclePos = getPos _vehicle;
private _angle = random 360;
private _distance = RC_CBRad_AccuracyRadius_AI * (sqrt random 1);   //first value is radius
private _targetPos = _vehiclePos getPos [_distance, _angle];


[_targetPos, _artilleryArray_O] spawn
{
    params ["_targetPos", "_artilleryArray_O"];
    //CBRad detection time
    sleep RC_CBRad_DetectionTime_AI;


    //checks if opposing artillery is in range
    private _isInRangeArray_O = [];
    {
        if !(isNull _x) then
        {
            private _isInRange = _targetPos inRangeOfArtillery [[_x], (currentMagazine _x)];
            private _isAlive = alive _x;
            if (_isInRange && _isAlive) then {
                _isInRangeArray_O pushback _x;
            };
        };
        sleep 0.1;
    } forEach _artilleryArray_O;


    //creating subarray with distance to target
    private _sortedIsInRangeArray_O = _isInRangeArray_O select {!isNull _x} apply {
        [_x distance2D player, _x]
    };
    //sorts array based on distance to target
    _sortedIsInRangeArray_O sort true;
    //re-selecting only objects
    _sortedIsInRangeArray_O = _sortedIsInRangeArray_O apply {_x#1};


    //true if atleast 1 opposing artillery is in range
    if ((count _sortedIsInRangeArray_O) > 0) then
    {
        //simulating AI preperation time before shot (AI only)
        sleep (RC_CBRad_PrepTime_AI);

        //selects first opposing artillery in range to return fire
        private _isInRange_O = (_sortedIsInRangeArray_O select 0);
        //changes locality of asset to server, as somehow only there doArtilleryFire works
        private _isInRange_O_Owner = owner _isInRange_O;
        [_isInRange_O, [_targetPos, (currentMagazine _isInRange_O), 1]] remoteExec ["doArtilleryFire", _isInRange_O_Owner];
        
        //if it doesnt shoot in time, firemission will be passed to next in isInRangeArray
        RC_fireMissionArray_O pushback _isInRange_O;
        sleep RC_CBRad_ReassignTime_AI;
        private _fireMissionNotCompleted = (({_x == _isInRange_O} count RC_fireMissionArray_O) > 0);


        if (_fireMissionNotCompleted) then
        {
            if ((count _sortedIsInRangeArray_O) > 1) then
            {
                //selects second opposing artillery in range to return fire
                _isInRange_O = (_sortedIsInRangeArray_O select 1);
                //changes locality of asset to server, as somehow only there doArtilleryFire works
                _isInRange_O_Owner = owner _isInRange_O;
                [_isInRange_O, [_targetPos, (currentMagazine _isInRange_O), 1]] remoteExec ["doArtilleryFire", _isInRange_O_Owner];
                
                //if it doesnt shoot in time, firemission will be passed to next in isInRangeArray
                RC_fireMissionArray_O pushback _isInRange_O;
                sleep RC_CBRad_ReassignTime_AI;
                _fireMissionNotCompleted = (({_x == _isInRange_O} count RC_fireMissionArray_O) > 0);


                if (_fireMissionNotCompleted) then
                {
                    if ((count _sortedIsInRangeArray_O) > 2) then
                    {
                        //selects second opposing artillery in range to return fire
                        _isInRange_O = (_sortedIsInRangeArray_O select 2);
                        //changes locality of asset to server, as somehow only there doArtilleryFire works
                        _isInRange_O_Owner = owner _isInRange_O;
                        [_isInRange_O, [_targetPos, (currentMagazine _isInRange_O), 1]] remoteExec ["doArtilleryFire", _isInRange_O_Owner];
                        
                        //if it doesnt shoot in time, firemission will be passed to next in isInRangeArray
                        RC_fireMissionArray_O pushback _isInRange_O;
                        sleep RC_CBRad_ReassignTime_AI;
                        _fireMissionNotCompleted = (({_x == _isInRange_O} count RC_fireMissionArray_O) > 0);


                        if (_fireMissionNotCompleted) then
                        {
                            if ((count _sortedIsInRangeArray_O) > 3) then
                            {
                                //selects third opposing artillery in range to return fire
                                _isInRange_O = (_sortedIsInRangeArray_O select 3);
                                //changes locality of asset to server, as somehow only there doArtilleryFire works
                                _isInRange_O_Owner = owner _isInRange_O;
                                [_isInRange_O, [_targetPos, (currentMagazine _isInRange_O), 1]] remoteExec ["doArtilleryFire", _isInRange_O_Owner];
                            };
                        };
                    };
                };
            };
        };
    };
};