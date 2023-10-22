Have fun with the mod and make sure to send me footage of your unit using it! :D

Took me a lot of effort to make this mod (6000 lines of code and LOTS of testing), so please respect that work.

REUPLOADING IS NOT ALLOWED, ask me to make changes or additions.
What is allowed is inheriting and then editing, so that it requires my mod, but tweaks it or introduces additions.
Its done in the config as follows.

base_asset;		//loads my mod vehicle or item
new_asset: base_asset	//inherits everything from my mods vehicle or item, to your new one
{
	changes		//make all the changes you have in mind
};

You can also use similar structure as my mod to make other assets remote controllable, like of your favorite mods, as its a lot of work for me.
Make sure to send me the link so i can also have fun with it. ;D


NEW FEATURES:
-Cycle through targets marked as "arty1", "arty2", "arty3" until 99 on the map, it will calculate elevation difference, range, and required azimuth, required gun elevation can be looked up on ace artillery tables.
-Howitzer gunner can now drive, to dodge counter artillery :D
-made more mod friendly

Coming quality of life features:
-accurate gun elevation formulas for high and low trajectory (check the steampage/ mod readme for it soon again)
-youtube video explaining how to use the new displays
-map being available in more vehicles
-turn off motor when vehicle holds

Bug fixes:
-fixed Nyx and AA crew being actual UAV_crew instead of humans
-fixed major bug that required respawn, by removed "go to driver/commander seat" options from all vehicles

Current Quirks:
- change ammo types per mousewheel menu, not in the artillery computer
- generating the ace rangetable requires having been close to it once
- disabling artillery computer in options after having already used it, requires mission restart (not a big deal, decide beforehand)


How to add/remove artillery ammunition, rightclick unit, open unit attributes, copy&paste in those bits, X stands for the amount you want:
Mortar:
this removeMagazineTurret["RC_12Rnd_82mm_Mo_shells", [0]] 
this removeMagazineTurret["RC_12Rnd_82mm_Mo_Flare_white", [0]] 
this removeMagazineTurret[ "RC_12Rnd_82mm_Mo_Smoke_white", [0]] 
this removeMagazineTurret[ "RC_4Rnd_82mm_Mo_guided", [0]] 
this removeMagazineTurret["RC_4Rnd_82mm_Mo_LG", [0]] 

this addMagazineTurret["RC_XRnd_82mm_Mo_shells", [0]] 
this addMagazineTurret["RC_XRnd_82mm_Mo_Flare_white", [0]] 
this addMagazineTurret["RC_XRnd_82mm_Mo_Smoke_white", [0]] 
this addMagazineTurret["RC_XRnd_82mm_Mo_guided", [0]] 
this addMagazineTurret["RC_XRnd_82mm_Mo_LG", [0]]

Howitzer:
this removeMagazineTurret["RC_12Rnd_155mm_Mo_shells", [0]]
this removeMagazineTurret["RC_4Rnd_155mm_Mo_guided", [0]]
this removeMagazineTurret[ "RC_8Rnd_155mm_Mo_mine", [0]]
this removeMagazineTurret[ "RC_2Rnd_155mm_Mo_Cluster", [0]]
this removeMagazineTurret["RC_12Rnd_155mm_Mo_smoke", [0]]
this removeMagazineTurret["RC_12Rnd_155mm_Mo_smoke", [0]]

this addMagazineTurret["RC_XRnd_155mm_Mo_shells", [0]]
this addMagazineTurret["RC_XRnd_155mm_Mo_guided", [0]]
this addMagazineTurret["RC_XRnd_155mm_Mo_mine", [0]]
this addMagazineTurret["RC_XRnd_155mm_Mo_Cluster", [0]]
this addMagazineTurret["RC_XRnd_155mm_Mo_smoke", [0]]
this addMagazineTurret["RC_XRnd_155mm_Mo_AT_mine", [0]]

MLRS:
this removeMagazineTurret["RC_6Rnd_230mm_rockets", [0]]
this removeMagazineTurret["RC_6Rnd_230mm_rockets_cluster", [0]]

this addMagazineTurret["RC_XRnd_230mm_rockets", [0]]
this addMagazineTurret["RC_XRnd_230mm_rockets_cluster", [0]]