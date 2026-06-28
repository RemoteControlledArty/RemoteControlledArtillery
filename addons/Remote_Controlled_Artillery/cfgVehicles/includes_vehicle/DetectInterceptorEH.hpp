class RC_DetectInterceptors
{
	init="if (!isserver) exitwith {};  RC_DetectInterceptor_Array pushback (_this select 0);  publicVariable 'RC_DetectInterceptor_Array';";
	killed="if (!isserver) exitwith {};  RC_DetectInterceptor_Array deleteAt (RC_DetectInterceptor_Array find (_this select 0));  publicVariable 'RC_DetectInterceptor_Array';";
};