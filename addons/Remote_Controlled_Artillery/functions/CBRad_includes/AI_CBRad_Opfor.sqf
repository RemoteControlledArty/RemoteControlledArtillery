//removes objNull from array
RC_ArtilleryArray_O = RC_ArtilleryArray_O - [objNull];
RC_isInRangeArray_O = RC_isInRangeArray_O - [objNull];
publicVariable "RC_ArtilleryArray_O";
publicVariable "RC_isInRangeArray_O";

//shot source position
_vehiclePos = getPos _vehicle;
private _angle = random 360;
private _distance = 15 * (sqrt random 1);   //first value is radius
private _targetPos = _vehiclePos getPos [_distance, _angle];

[_targetPos] spawn
{
    params ["_targetPos"];
    //CBRad detection time (same for players & AI)
    sleep RC_DetectionTime_F1;

    //checks if opposing artillery is in range
    //RC_isInRangeArray_O = []; //good or bad idea to empty the array?
    {
        RC_isInRangeArray_O deleteAt (RC_isInRangeArray_O find _x); //prevents doubles in array
        _isNull = isNull _x;
        if !(_isNull) then
        {
            _isInRange = _targetPos inRangeOfArtillery [[_x], (currentMagazine _x)];
            _isAlive = alive _x;
            if (_isInRange && _isAlive) then {
                RC_isInRangeArray_O pushback _x;
            };
        };
        sleep 0.1;
    } forEach RC_ArtilleryArray_O;
    //publicVariable "RC_isInRangeArray_O";

    //true if atleast 1 opposing artillery is in range
    if ((count RC_isInRangeArray_O) > 0) then
    {
        //simulating AI preperation time before shot (AI only)
        sleep (RC_PrepTime_F1);

        //selects first opposing artillery in range to return fire
        _isInRange_O = (RC_isInRangeArray_O select 0);
        //changes locality of asset to server, as somehow only there doArtilleryFire works
        _isInRange_O_Owner = owner _isInRange_O;
        [_isInRange_O, [_targetPos, (currentMagazine _isInRange_O), 1]] remoteExec ["doArtilleryFire", _isInRange_O_Owner];
        
        //if it doesnt shoot in time, firemission will be passed to next in isInRangeArray
        RC_fireMissionArray_O pushback _isInRange_O;
        sleep RC_ReassignTime_F1;
        _fireMissionNotCompleted = (({_x == _isInRange_O} count RC_fireMissionArray_O) > 0);

        if (_fireMissionNotCompleted) then
        {
            if ((count RC_isInRangeArray_O) > 1) then
            {
                //selects second opposing artillery in range to return fire
                _isInRange_O = (RC_isInRangeArray_O select 1);
                //changes locality of asset to server, as somehow only there doArtilleryFire works
                _isInRange_O_Owner = owner _isInRange_O;
                [_isInRange_O, [_targetPos, (currentMagazine _isInRange_O), 1]] remoteExec ["doArtilleryFire", _isInRange_O_Owner];
                
                //if it doesnt shoot in time, firemission will be passed to next in isInRangeArray
                RC_fireMissionArray_O pushback _isInRange_O;
                sleep RC_ReassignTime_F1;
                _fireMissionNotCompleted = (({_x == _isInRange_O} count RC_fireMissionArray_O) > 0);

                if (_fireMissionNotCompleted) then
                {
                    if ((count RC_isInRangeArray_O) > 2) then
                    {
                        //selects second opposing artillery in range to return fire
                        _isInRange_O = (RC_isInRangeArray_O select 2);
                        //changes locality of asset to server, as somehow only there doArtilleryFire works
                        _isInRange_O_Owner = owner _isInRange_O;
                        [_isInRange_O, [_targetPos, (currentMagazine _isInRange_O), 1]] remoteExec ["doArtilleryFire", _isInRange_O_Owner];
                        
                        //if it doesnt shoot in time, firemission will be passed to next in isInRangeArray
                        RC_fireMissionArray_O pushback _isInRange_O;
                        sleep RC_ReassignTime_F1;
                        _fireMissionNotCompleted = (({_x == _isInRange_O} count RC_fireMissionArray_O) > 0);

                        if (_fireMissionNotCompleted) then
                        {
                            if ((count RC_isInRangeArray_O) > 3) then
                            {
                                //selects third opposing artillery in range to return fire
                                _isInRange_O = (RC_isInRangeArray_O select 3);
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