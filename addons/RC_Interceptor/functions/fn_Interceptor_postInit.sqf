RC_X = 0.5;
RC_Y = 0.5;
RC_SENSIVITY = 12;
//#define RC_SENSIVITY 12  //7

fnc_Interceptor_SetVel = {
    params ["_uav"];

    private _dt = diag_deltaTime;
    //private _frameAlpha = (_alpha * _dt) min 1;  // smoothing factor scaled by deltaTime

    _y = RC_X * RC_SENSIVITY;
    _p = RC_Y * RC_SENSIVITY;
    _r = 0;

    _dir = [
        sin _y * cos _p,
        cos _y * cos _p,
        sin _p
    ];
    
    _uav setVectorDirAndUp [
        _dir,
        [[0, -sin _p, cos _p], -_y] call BIS_fnc_rotateVector2D
    ];

    _speed = speed _uav;
    _maxSpeed = localNameSpace getVariable ["RC_Interceptor_maxSpeed", 1];
    _maxLiftSpeed = localNameSpace getVariable ["RC_Interceptor_maxLiftSpeed", 0];
    if (_speed > _maxSpeed) then {_speed = _maxSpeed;};

    _vel = _dir vectorMultiply (_speed / 3.6);
    _vel set [2, (_vel # 2) + (9.81 * _dt)];

    _uav setVelocity _vel;
};




/*
private _fnc_Interceptor_VelFunction = {
    params ["_from", "_to"];

    _y = RC_X * RC_SENSIVITY;
    _p = RC_Y * RC_SENSIVITY;
    _r = 0;

    _dir = [
        sin _y * cos _p,
        cos _y * cos _p,
        sin _p
    ];
    
    _uav setVectorDirAndUp [
        _dir,
        [[0, -sin _p, cos _p], -_y] call BIS_fnc_rotateVector2D
    ];
    */

    //physics
    /*
    _velDir = [
        sin _currentX * cos _currentY,
        cos _currentX * cos _currentY,
        sin _currentY
    ];
    */

    //visual
    //_visDir = vectorNormalized [sin _currentX, cos _currentX, 0]; // horizontal

    /*
    _speed = speed _uav;
    _maxSpeed = localNameSpace getVariable ["RC_Interceptor_maxSpeed", 1];
    _maxLiftSpeed = localNameSpace getVariable ["RC_Interceptor_maxLiftSpeed", 0];
    if (_speed > _maxSpeed) then {_speed = _maxSpeed;};

    //_vel = _velDir vectorMultiply (_speed / 3.6);
    _vel = _dir vectorMultiply (_speed / 3.6);
    //gravity cancel
    _vel set [2, (_vel # 2) + (9.81 * _dt)];
    //_vel set [2, (_vel # 2) + ((9.81 * _dt) * 10)];
    */
    

    /*
    // gravity compensation
    _vel set [2, (_vel # 2) + (9.81 * _dt)];
    // manual lift (independent of camera)
    //_vel set [2, (_vel # 2) + (_maxLiftSpeed / 3.6)];

    _vel set [2, (_vel # 2) + ((_maxLiftSpeed / 3.6) * _dt)];

    private _vLen = vectorMagnitude _vel;
    _speedCap = _maxSpeed max _maxLiftSpeed;
    if (_vLen > _speedCap) then {
        _vel = _vel vectorMultiply (_speedCap / _vLen);
    };
    //apply
    */
    
    /*
    // gravity compensation
    _vel set [2, (_vel # 2) + (9.81 * _dt)];

    // lift scaled by pitch (CRITICAL)
    private _pitchFactor = 1 - abs (_dir # 2);
    _vel set [2, (_vel # 2) + ((_maxLiftSpeed / 3.6) * _pitchFactor)];

    // total speed cap
    private _vLen = vectorMagnitude _vel;
    private _cap = _maxSpeed max _maxLiftSpeed;

    if (_vLen > _cap) then {
        _vel = _vel vectorMultiply (_cap / _vLen);
    };
    */

    /*
    _uav setVelocity _vel;

    //_previousX = _currentX;

    //hint format ["_dir: %1\n_up: %2", _dir, _up];
};
*/


/*
fnc_Interceptor_SetVel = {
    params ["_uav"];

    private _dt = diag_deltaTime;
    private _frameAlpha = (_alpha * _dt) min 1;  // smoothing factor scaled by deltaTime

    _y = RC_X * RC_SENSIVITY;
    _p = RC_Y * RC_SENSIVITY;
    _r = 0;

    _dir = [
        sin _y * cos _p,
        cos _y * cos _p,
        sin _p
    ];
    
    _uav setVectorDirAndUp [
        _dir,
        [[0, -sin _p, cos _p], -_y] call BIS_fnc_rotateVector2D
    ];

    _speed = speed _uav;
    _maxSpeed = localNameSpace getVariable ["RC_Interceptor_maxSpeed", 1];
    _maxLiftSpeed = localNameSpace getVariable ["RC_Interceptor_maxLiftSpeed", 0];
    if (_speed > _maxSpeed) then {_speed = _maxSpeed;};

    //_vel = _velDir vectorMultiply (_speed / 3.6);
    _vel = _dir vectorMultiply (_speed / 3.6);
    //gravity cancel
    _vel set [2, (_vel # 2) + (9.81 * _dt)];

    //_vel set [2, (_vel # 2) + (_maxLiftSpeed / 3.6)];
    _vel set [2, (_vel # 2) + ((_maxLiftSpeed / 3.6) * _dt)];

    private _vLen = vectorMagnitude _vel;
    _speedCap = _maxSpeed max _maxLiftSpeed;
    if (_vLen > _speedCap) then {
        _vel = _vel vectorMultiply (_speedCap / _vLen);
    };
    
    // gravity compensation
    _vel set [2, (_vel # 2) + (9.81 * _dt)];

    // lift scaled by pitch (CRITICAL)
    private _pitchFactor = 1 - abs (_dir # 2);
    _vel set [2, (_vel # 2) + ((_maxLiftSpeed / 3.6) * _pitchFactor)];

    // total speed cap
    private _vLen = vectorMagnitude _vel;
    private _cap = _maxSpeed max _maxLiftSpeed;

    if (_vLen > _cap) then {
        _vel = _vel vectorMultiply (_cap / _vLen);
    };

    _uav setVelocity _vel;
};

    _currentX = _currentX + (RC_X - _currentX) * _frameAlpha;
    _currentY = _currentY + (RC_Y - _currentY) * _frameAlpha;

    _y = RC_X * RC_SENSIVITY * (_dt / 0.0167);
    _p = RC_Y * RC_SENSIVITY * (_dt / 0.0167);
*/