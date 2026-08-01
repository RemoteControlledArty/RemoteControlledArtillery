params ["_veh", "_artyArr", "_side"];


//shot source position
private _vehPos = getPos _veh;
private _angle = random 360;
private _distance = RC_CBRad_AccuracyRadius_AI * (sqrt random 1);   //first value is radius
private _targetPos = _vehPos getPos [_distance, _angle];


[_targetPos, _artyArr, _side] spawn
{
    params ["_targetPos", "_artyArr", "_side"];
    //CBRad detection time
    sleep RC_CBRad_DetectionTime_AI;


    //checks if opposing artillery is in range
    private _inRangeArr = [];
    {
        if !(isNull _x) then
        {
            private _inRange = _targetPos inRangeOfArtillery [[_x], (currentMagazine _x)];
            private _isAlive = alive _x;
            if (_inRange && _isAlive) then {
                _inRangeArr pushback _x;
            };
        };
        sleep 0.1;
    } forEach _artyArr;


    //creating subArr with distance to target
    private _sortedInRangeArr = _inRangeArr select {!isNull _x} apply {
        [_x distance2D _targetPos, _x]
    };
    //sorts array based on distance to target
    _sortedInRangeArr sort true;
    //re-selecting only objects
    _sortedInRangeArr = _sortedInRangeArr apply {_x#1};


    //true if atleast 1 opposing artillery is in range
    if ((count _sortedInRangeArr) > 0) then
    {
        //simulating AI preperation time before shot (AI only)
        sleep (RC_CBRad_PrepTime_AI);

        //selects first opposing artillery in range to return fire
        private _responder = _sortedInRangeArr #0;
        //changes locality of asset to server, as somehow only there doArtilleryFire works
        private _responderOwner = owner _responder;
        [_responder, [_targetPos, (currentMagazine _responder), RC_CBRad_ReturnAmount_AI]] remoteExec ["doArtilleryFire", _responderOwner];
        
        //if it doesnt shoot in time, firemission will be passed to next in isInRangeArr
        private _fireMissionNotCompleted = false;
        switch (true) do {
            case(_side == west): {
                
                RC_fireMissionArray_B pushback _responder;
                sleep RC_CBRad_ReassignTime_AI;
                _fireMissionNotCompleted = (({_x == _responder} count RC_fireMissionArray_B) > 0);
            };
            case(_side == east): {
                
                RC_fireMissionArray_B pushback _responder;
                sleep RC_CBRad_ReassignTime_AI;
                _fireMissionNotCompleted = (({_x == _responder} count RC_fireMissionArray_B) > 0);
            };
            case(_side == resistance): {
                
                RC_fireMissionArray_B pushback _responder;
                sleep RC_CBRad_ReassignTime_AI;
                _fireMissionNotCompleted = (({_x == _responder} count RC_fireMissionArray_B) > 0);
            };
        };


        if (_fireMissionNotCompleted) then
        {
            if ((count _sortedInRangeArr) > 1) then
            {
                //selects second opposing artillery in range to return fire
                _responder = _sortedInRangeArr #1;
                //changes locality of asset to server, as somehow only there doArtilleryFire works
                _responderOwner = owner _responder;
                [_responder, [_targetPos, (currentMagazine _responder), RC_CBRad_ReturnAmount_AI]] remoteExec ["doArtilleryFire", _responderOwner];
                
                //if it doesnt shoot in time, firemission will be passed to next in isInRangeArr
                switch (true) do {
                    case(_side == west): {
                        
                        RC_fireMissionArray_B pushback _responder;
                        sleep RC_CBRad_ReassignTime_AI;
                        _fireMissionNotCompleted = (({_x == _responder} count RC_fireMissionArray_B) > 0);
                    };
                    case(_side == east): {
                        
                        RC_fireMissionArray_B pushback _responder;
                        sleep RC_CBRad_ReassignTime_AI;
                        _fireMissionNotCompleted = (({_x == _responder} count RC_fireMissionArray_B) > 0);
                    };
                    case(_side == resistance): {
                        
                        RC_fireMissionArray_B pushback _responder;
                        sleep RC_CBRad_ReassignTime_AI;
                        _fireMissionNotCompleted = (({_x == _responder} count RC_fireMissionArray_B) > 0);
                    };
                };


                if (_fireMissionNotCompleted) then
                {
                    if ((count _sortedInRangeArr) > 2) then
                    {
                        //selects second opposing artillery in range to return fire
                        _responder = _sortedInRangeArr #2;
                        //changes locality of asset to server, as somehow only there doArtilleryFire works
                        _responderOwner = owner _responder;
                        [_responder, [_targetPos, (currentMagazine _responder), RC_CBRad_ReturnAmount_AI]] remoteExec ["doArtilleryFire", _responderOwner];
                        
                        //if it doesnt shoot in time, firemission will be passed to next in isInRangeArr
                        switch (true) do {
                            case(_side == west): {
                                
                                RC_fireMissionArray_B pushback _responder;
                                sleep RC_CBRad_ReassignTime_AI;
                                _fireMissionNotCompleted = (({_x == _responder} count RC_fireMissionArray_B) > 0);
                            };
                            case(_side == east): {
                                
                                RC_fireMissionArray_B pushback _responder;
                                sleep RC_CBRad_ReassignTime_AI;
                                _fireMissionNotCompleted = (({_x == _responder} count RC_fireMissionArray_B) > 0);
                            };
                            case(_side == resistance): {
                                
                                RC_fireMissionArray_B pushback _responder;
                                sleep RC_CBRad_ReassignTime_AI;
                                _fireMissionNotCompleted = (({_x == _responder} count RC_fireMissionArray_B) > 0);
                            };
                        };


                        if (_fireMissionNotCompleted) then
                        {
                            if ((count _sortedInRangeArr) > 3) then
                            {
                                //selects third opposing artillery in range to return fire
                                _responder = _sortedInRangeArr #3;
                                //changes locality of asset to server, as somehow only there doArtilleryFire works
                                _responderOwner = owner _responder;
                                [_responder, [_targetPos, (currentMagazine _responder), RC_CBRad_ReturnAmount_AI]] remoteExec ["doArtilleryFire", _responderOwner];
                            };
                        };
                    };
                };
            };
        };
    };
};