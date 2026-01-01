//removes objNull from array
RC_ArtilleryArray_B = RC_ArtilleryArray_B - [objNull];
RC_isInRangeArray_B = RC_isInRangeArray_B - [objNull];
publicVariable "RC_ArtilleryArray_B";
publicVariable "RC_isInRangeArray_B";

//shot source position
private _vehiclePos = getPos _vehicle;
private _angle = random 360;
private _distance = RC_CBRad_AccuracyRadius_AI * (sqrt random 1);   //first value is radius
private _targetPos = _vehiclePos getPos [_distance, _angle];

[_targetPos] spawn
{
    params ["_targetPos"];
    //CBRad detection time
    sleep RC_CBRad_DetectionTime_AI;


    //checks if opposing artillery is in range
    //RC_isInRangeArray_B = []; //good or bad idea to empty the array?
    {
        RC_isInRangeArray_B deleteAt (RC_isInRangeArray_B find _x); //prevents doubles in array
        private _isNull = isNull _x;
        if !(_isNull) then
        {
            private _isInRange = _targetPos inRangeOfArtillery [[_x], (currentMagazine _x)];
            private _isAlive = alive _x;
            if (_isInRange && _isAlive) then {
                RC_isInRangeArray_B pushback _x;
            };
        };
        sleep 0.1;
    } forEach RC_ArtilleryArray_B;
    //publicVariable "RC_isInRangeArray_B";


    //true if atleast 1 opposing artillery is in range
    if ((count RC_isInRangeArray_B) > 0) then
    {
        //simulating AI preperation time before shot (AI only)
        sleep (RC_CBRad_PrepTime_AI);

        //selects first opposing artillery in range to return fire
        private _isInRange_B = (RC_isInRangeArray_B select 0);
        //changes locality of asset to server, as somehow only there doArtilleryFire works
        private _isInRange_B_Owner = owner _isInRange_B;
        [_isInRange_B, [_targetPos, (currentMagazine _isInRange_B), 1]] remoteExec ["doArtilleryFire", _isInRange_B_Owner];
        
        //if it doesnt shoot in time, firemission will be passed to next in isInRangeArray
        RC_fireMissionArray_B pushback _isInRange_B;
        sleep RC_CBRad_ReassignTime_AI;
        private _fireMissionNotCompleted = (({_x == _isInRange_B} count RC_fireMissionArray_B) > 0);

        if (_fireMissionNotCompleted) then
        {
            if ((count RC_isInRangeArray_B) > 1) then
            {
                //selects second opposing artillery in range to return fire
                _isInRange_B = (RC_isInRangeArray_B select 1);
                //changes locality of asset to server, as somehow only there doArtilleryFire works
                _isInRange_B_Owner = owner _isInRange_B;
                [_isInRange_B, [_targetPos, (currentMagazine _isInRange_B), 1]] remoteExec ["doArtilleryFire", _isInRange_B_Owner];
                
                //if it doesnt shoot in time, firemission will be passed to next in isInRangeArray
                RC_fireMissionArray_B pushback _isInRange_B;
                sleep RC_CBRad_ReassignTime_AI;
                _fireMissionNotCompleted = (({_x == _isInRange_B} count RC_fireMissionArray_B) > 0);

                if (_fireMissionNotCompleted) then
                {
                    if ((count RC_isInRangeArray_B) > 2) then
                    {
                        //selects second opposing artillery in range to return fire
                        _isInRange_B = (RC_isInRangeArray_B select 2);
                        //changes locality of asset to server, as somehow only there doArtilleryFire works
                        _isInRange_B_Owner = owner _isInRange_B;
                        [_isInRange_B, [_targetPos, (currentMagazine _isInRange_B), 1]] remoteExec ["doArtilleryFire", _isInRange_B_Owner];
                        
                        //if it doesnt shoot in time, firemission will be passed to next in isInRangeArray
                        RC_fireMissionArray_B pushback _isInRange_B;
                        sleep RC_CBRad_ReassignTime_AI;
                        _fireMissionNotCompleted = (({_x == _isInRange_B} count RC_fireMissionArray_B) > 0);

                        if (_fireMissionNotCompleted) then
                        {
                            if ((count RC_isInRangeArray_B) > 3) then
                            {
                                //selects third opposing artillery in range to return fire
                                _isInRange_B = (RC_isInRangeArray_B select 3);
                                //changes locality of asset to server, as somehow only there doArtilleryFire works
                                _isInRange_B_Owner = owner _isInRange_B;
                                [_isInRange_B, [_targetPos, (currentMagazine _isInRange_B), 1]] remoteExec ["doArtilleryFire", _isInRange_B_Owner];
                            };
                        };
                    };
                };
            };
        };
    };
};