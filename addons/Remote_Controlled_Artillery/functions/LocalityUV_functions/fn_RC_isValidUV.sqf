// --- Helper: is _uav a valid, living UV? ---
params ["_uav"];
(!isNull _uav) && {alive _uav}