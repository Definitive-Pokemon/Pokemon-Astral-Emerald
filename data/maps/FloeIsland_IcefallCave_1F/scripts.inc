FloeIsland_IcefallCave_1F_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, FloeIsland_IcefallCave_1F_OnResume
	map_script MAP_SCRIPT_ON_LOAD, FloeIsland_IcefallCave_1F_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FloeIsland_IcefallCave_1F_OnFrame
	.byte 0

FloeIsland_IcefallCave_1F_OnResume::
	@setstepcallback STEP_CB_ICE
	end

FloeIsland_IcefallCave_1F_OnLoad::
	@special SetIcefallCaveCrackedIceMetatiles
	end

FloeIsland_IcefallCave_1F_OnFrame::
	map_script_2 VAR_TEMP_1, 1, FloeIsland_IcefallCave_1F_EventScript_FallDownHole
	.2byte 0

FloeIsland_IcefallCave_1F_EventScript_FallDownHole::
	lockall
	delay 20
	applymovement LOCALID_PLAYER, FloeIsland_IcefallCave_1F_Movement_SetInvisible
	waitmovement 0
	playse SE_FALL
	delay 60
	warphole MAP_FLOE_ISLAND_ICEFALL_CAVE_B1F
	waitstate
	releaseall
	end

FloeIsland_IcefallCave_1F_Movement_SetInvisible::
	set_invisible
	step_end
