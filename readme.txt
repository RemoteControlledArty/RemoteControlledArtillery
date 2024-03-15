Have fun with the mod and make sure to send me footage of your unit using it! :D

REUPLOADING IS NOT ALLOWED, ask me to make changes or additions. Took us a lot of effort to make this mod (thousands lines of code and >5months of work), so please respect that work.
What is allowed is inheriting and then editing, so that it requires my mod, but tweaks it or introduces additions.
Its done in the config as follows.

base_asset;		//loads my mod vehicle or item
new_asset: base_asset	//inherits everything from my mods vehicle or item, to your new one
{
	changes		//make all the changes you have in mind
};

You can also use similar structure as my mod to make other assets remote controllable, like of your favorite mods, as its a lot of work for me.
Make sure to send me the link so i can also have fun with it. ;D


NEW ARTILLERY FEATURES:
-cycle through "target reference markers" named "arty1" until "arty99" on the map, it will calculate and display target distance, azimuth, and elevation difference
-Fire Control System with low&high trajectory firing solution calculator
*low trajectory sicnificantly shortens time of flight, and increases accuracy!
-datalink panel and integration, with live updating low/high firing solutions for selected target (the real MAGIC, was a TON of work)

-Airburst ammunition, highly effective against trenches etc, for Mortars/Howitzers/MLRS
-MP Guided ammunition, that now works even in manual fire on laser/vehicle/gps targets, *including an optional 2m delayed fuze variant

-lockable gps target by placing a map marker "gps" (only one possible at a time until next updates)
-datalink laser designators, to share laser spot location (for firing solution) with indirect fire assets without them needing line of sight
-finer artillery charges to optimize angle more, like firing over hills with low trajectory

-new RC Mortar Carrier
-improvements to Cluster ammunition


New quality of live features:
-improved vehicle FOV for situational awareness and usability
-automatic vehicle engine turnoff when stopping to improve communication and awareness
-map being available in more vehicles

Other new assets:
-lowtech&hightech UAV:
-AR-1 has short range, to make it easier for Zeus to build missions, and no thermals (wouldnt work with range limitation script)
-AR-3 has long range, has image recognition & displays targets
-short ranged Grenade Dropping UAV's for all factions (will be improved in next updates)

-remote controllable Infantery Carriers (ICV), to fix most units extrem mobility issues, of having to leave vehicles behind for assault, taking ages to recover, or if not left behind getting destroyed
-automated driver for IFV/FSV/MBT, to remove the job noone wants to do, and decrease dependancy of buggy human ai drivers, also allows to be in the same ace group, improving coordination
-datalink integration and datalink guided NLOS ATGM's for IFV/FSV/MBT

-optional RC Medical Truck's that act as respawn, like for when you dont have air reinsert


Bonus Content:
-new improved hand held Laser Designators, with wider field of view, and white hot Ti instead of eye hurting green hot (non Ti versions also included)
-script that finally FIXES the common problem of noone being able to connect to a UAV/UGV a player accessed before his death (this fix is a way bigger deal than you might realize)


Current Quirks:
-locality issues (ofc being worked on), assets work imperfect when given to by zeus in multiplayer instead of placed oneself, artillery luckly is only very lightly effected,
	the ICF/IFV/FSV/MBT more strongly, the fix is to connect to the driver and waiting until it reacts to WASD, then go to gunner again
-the datalink target the "gps" marker creates is active for about 3minutes before it is gone for unknown reasons
-replacing or renaming "arty" markers bugs their distance, press 5 to cycle markers to fix distance, full solution is being worked on
-if placed in editor before a MP mission, artillery can be incorrectly loaded with datalink off, check this as zeus and reenable it in that case, assets placed by zeus dont have that issue

Quirks using Vanilla Artillery Computer:
-change ammo types per mousewheel menu, not in the artillery computer
-generating the ace rangetable requires having been close to it once
-disabling artillery computer in options after having already used it, requires mission restart (not a big deal, decide beforehand)

Recent bug fixes:
- distance is now correctly calculated
- tons of other stuff


Thanks to:
Fluffy who put an enormous amount of work into this with me.
Aaren for providing the explosion effect.
And my great friend Eric to often help me with scripting problems.


How to add/remove artillery ammunition in editor:
//in editor doubleclick asset, or leftclick then attributes, paste this in, with ? replaced by your prefered number of rounds

//82mm RC Mortar (max 40 shells):
this removeMagazineTurret["RC_10Rnd_82mm_Mo_shells", [0]];
this removeMagazineTurret["RC_5Rnd_82mm_Mo_HEAB", [0]];
this removeMagazineTurret["RC_5Rnd_82mm_Mo_MultiGuided", [0]];
this removeMagazineTurret["RC_15Rnd_82mm_Mo_Smoke_white", [0]];;
this removeMagazineTurret["RC_6Rnd_82mm_Mo_Flare_white", [0]];

//for 82mm RC VehicleMortar additionally:
this removeMagazineTurret["RC_15Rnd_82mm_Mo_shells", [0]];
this removeMagazineTurret["RC_20Rnd_82mm_Mo_Smoke_white", [0]];;
this removeMagazineTurret["RC_9Rnd_82mm_Mo_AT_mine", [0]];
this removeMagazineTurret["RC_9Rnd_82mm_Mo_mine", [0]];

this addMagazineTurret["RC_?Rnd_82mm_Mo_shells", [0]];
this addMagazineTurret["RC_?Rnd_82mm_Mo_HEAB", [0]];
this addMagazineTurret["RC_?Rnd_82mm_Mo_Smoke_white", [0]];
this addMagazineTurret["RC_?Rnd_82mm_Mo_MultiGuided", [0]];
this addMagazineTurret["RC_?Rnd_82mm_Mo_AT_mine", [0]];
this addMagazineTurret["RC_?Rnd_82mm_Mo_mine", [0]];
this addMagazineTurret["RC_?Rnd_82mm_Mo_Flare_white", [0]];

extra:
this addMagazineTurret["RC_?Rnd_82mm_Mo_LaserGuided", [0]];
this addMagazineTurret["RC_?Rnd_82mm_Mo_LG_DelayedFuse", [0]];


//120mm RC Static Howitzer (max 40 shells):
this removeMagazineTurret["RC_15Rnd_120mm_Mo_shells", [0]];
this removeMagazineTurret["RC_5Rnd_120mm_Mo_HEAB", [0]];
this removeMagazineTurret["RC_5Rnd_120mm_Mo_MultiGuided", [0]];
this removeMagazineTurret["RC_2Rnd_120mm_Mo_Cluster", [0]];
this removeMagazineTurret["RC_20Rnd_120mm_Mo_Smoke", [0]];
this removeMagazineTurret["RC_9Rnd_120mm_Mo_AT_mine", [0]];
this removeMagazineTurret["RC_9Rnd_120mm_Mo_mine", [0]];
this removeMagazineTurret["RC_6Rnd_120mm_Mo_Illum", [0]];

this addMagazineTurret["RC_?Rnd_120mm_Mo_HEAB", [0]];
this addMagazineTurret["RC_?Rnd_120mm_Mo_Smoke", [0]];
this addMagazineTurret["RC_?Rnd_120mm_Mo_MultiGuided", [0]];
this addMagazineTurret["RC_?Rnd_120mm_Mo_Cluster", [0]];
this addMagazineTurret["RC_?Rnd_120mm_Mo_AT_Mine", [0]];
this addMagazineTurret["RC_?Rnd_120mm_Mo_Mine", [0]];
this addMagazineTurret["RC_?Rnd_120mm_Mo_Illum", [0]];

extra:
this addMagazineTurret["RC_?Rnd_155mm_Mo_LaserGuided", [0]];
this addMagazineTurret["RC_?Rnd_120mm_Mo_LG_DelayedFuse", [0]];

//155mm RC Howitzer (max 40 shells):
this removeMagazineTurret["RC_15Rnd_155mm_Mo_shells", [0]];
this removeMagazineTurret["RC_5Rnd_155mm_Mo_HEAB", [0]];
this removeMagazineTurret["RC_5Rnd_155mm_Mo_MultiGuided", [0]];
this removeMagazineTurret["RC_2Rnd_155mm_Mo_Cluster", [0]];
this removeMagazineTurret["RC_20Rnd_155mm_Mo_Smoke_white", [0]];
this removeMagazineTurret["RC_9Rnd_155mm_Mo_AT_mine", [0]];
this removeMagazineTurret["RC_9Rnd_155mm_Mo_mine", [0]];
this removeMagazineTurret["RC_6Rnd_155mm_Mo_Illum", [0]];

this addMagazineTurret["RC_?Rnd_155mm_Mo_HEAB", [0]];
this addMagazineTurret["RC_?Rnd_155mm_Mo_Smoke_white", [0]];
this addMagazineTurret["RC_?Rnd_155mm_Mo_MultiGuided", [0]];
this addMagazineTurret["RC_?Rnd_155mm_Mo_Cluster", [0]];
this addMagazineTurret["RC_?Rnd_155mm_Mo_AT_mine", [0]];
this addMagazineTurret["RC_?Rnd_155mm_Mo_mine", [0]];
this addMagazineTurret["RC_?Rnd_155mm_Mo_Illum", [0]];

extra:
this addMagazineTurret["RC_?Rnd_155mm_Mo_LaserGuided", [0]];
this addMagazineTurret["RC_?Rnd_155mm_Mo_LG_DelayedFuse", [0]];


//230mm MLRS/MRL (max 12 rockets):
this removeMagazineTurret["RC_6Rnd_230mm_rockets_HEAB", [0]];
this removeMagazineTurret["RC_4Rnd_230mm_rockets_MultiGuided", [0]];
this removeMagazineTurret["RC_2Rnd_230mm_rockets_cluster", [0]];

this addMagazineTurret["RC_?Rnd_230mm_rockets_HEAB", [0]];
this addMagazineTurret["RC_?Rnd_230mm_rockets_MultiGuided", [0]];
this addMagazineTurret["RC_?Rnd_230mm_rockets_cluster", [0]];

extra (ATACMS max 2 rockets):
this addMagazineTurret["RC_?Rnd_230mm_rockets_LaserGuided", [0]];
this addMagazineTurret["RC_?Rnd_230mm_rockets_LG_DelayedFuse", [0]];
this addMagazineTurret["RC_?Rnd_604mm_rockets_ATACMS_HEAB", [0]];
this addMagazineTurret["RC_?Rnd_604mm_rockets_ATACMS_DPICM", [0]];
this addMagazineTurret["RC_?Rnd_230mm_rockets", [0]];