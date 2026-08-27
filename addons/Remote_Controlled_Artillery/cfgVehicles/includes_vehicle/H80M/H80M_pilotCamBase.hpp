memoryPointTaskMarker="TaskMarker_1_pos";
memoryPointDriverOptics="light_l";

/*
light_l, Eye, Eye2, pos gunner, pos gunner dir, slingCamera, pos pilot, pos pilot dir, pos gunner2, pos gunner2 dir

light_l = front bottom, best
pos pilot dir = left bottom of hull, decent
pos pilot = similar as pos pilot dir, but futher from hull, so worse
Eye, pos gunner, pos gunner dir, slingLoad0 = not good
*/

unitInfoType="RC_RscOptics_AV_Heli";	//RC_RscOptics_AV_Heli
unitInfoTypeRTD="RC_RscOptics_AV_Heli";	//RC_RscOptics_AV_Heli
driverWeaponsInfoType="RscOptics_CAS_01_TGP";

driverOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_02_n_F.p3d";

weapons[]+={"Laserdesignator_pilotCamera"};
magazines[]+={"Laserbatteries"};
/*
weapons[]={"Laserdesignator_pilotCamera"};
magazines[]={"Laserbatteries"};
*/

//2.0
/*
memoryPointGunnerOptics="commanderview";
memoryPointDriverOptics="commanderview";
gunBeg="commanderview";
gunEnd="laserstart";
memoryPointGun="commanderview";
body="obsTurret";
gun="obsGun";
animationSourceBody="obsTurret";
animationSourceGun="obsGun";
turretInfoType="Rsc_Turret_UnitInfo";
*/