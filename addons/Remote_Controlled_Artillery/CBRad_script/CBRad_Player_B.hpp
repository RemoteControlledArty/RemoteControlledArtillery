init="if (!isserver) exitwith {};  RC_CBRad_Player_Array_B pushback (_this select 0);  publicVariable 'RC_CBRad_Player_Array_B';";
killed="if (!isserver) exitwith {};  RC_CBRad_Player_Array_B deleteAt (RC_CBRad_Player_Array_B find (_this select 0));  publicVariable 'RC_CBRad_Player_Array_B';";