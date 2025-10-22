//add 2x FPV deployable per mousewheel
//NEEDS script to reset camera when pilot left / when remote control is taken
//make RC-OM Y-32
//vehicle player setPilotCameraDirection [0,1,0] // re-centers the camera
//correct uavCameraDriverPos

isUav=1;
vehicleClass="Autonomous";
uavCameraDriverPos="pip_pilot_pos";
uavCameraDriverDir="pip_pilot_dir";
uavCameraGunnerPos="PiP1_pos";
uavCameraGunnerDir="PiP1_dir";

memoryPointTaskMarker="TaskMarker_1_pos";
memoryPointDriverOptics="Copilot_view_dir";
//memoryPointDriverOptics="pip_pilot_pos";
//memoryPointDriverOptics="Slingload_cam";

driverOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_02_n_F.p3d";
unitInfoType="RscOptics_AV_pilot";
unitInfoTypeRTD="RscOptics_AV_pilot";

driverForceOptics=1;
driverCompartments="Compartment1";