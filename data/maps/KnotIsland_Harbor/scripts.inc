KnotIsland_Harbor_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, KnotIsland_Harbor_OnFrameTable
	.byte 0
	
KnotIsland_Harbor_OnFrameTable::
	map_script_2 VAR_MAP_SCENE_KNOT_ISLAND_HARBOR, 0, KnotIsland_Harbor_EventScript_EnterKnotIsland_HarborFirstTime
	.2byte 0
	
KnotIsland_Harbor_EventScript_EnterKnotIsland_HarborFirstTime::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, KnotIsland_Harbor_Movement_PlayerExitHarbor
	waitmovement 0
	warp MAP_KNOT_ISLAND, 12, 18
	waitstate
	releaseall
	end
	
KnotIsland_Harbor_Movement_PlayerExitHarbor:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

KnotIsland_Harbor_EventScript_Sailor::
	lock
	faceplayer
	msgbox Island_Harbors_Text_Oi_Chap, MSGBOX_DEFAULT
	setvar VAR_0x8004, 1
	@special ScriptMenu_CreateSeviiFerryMultichoice
	end

	
Island_Harbors_Text_Oi_Chap::
    .string "IM ERROR$"
