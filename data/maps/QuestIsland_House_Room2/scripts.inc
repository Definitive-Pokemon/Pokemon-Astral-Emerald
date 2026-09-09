QuestIsland_House_Room2_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, QuestIsland_House_Room2_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, QuestIsland_House_Room2_OnFrame
	.byte 0

QuestIsland_House_Room2_OnTransition::
	special SetEReaderTrainerGfxId
	end

QuestIsland_House_Room2_OnFrame::
	map_script_2 VAR_TEMP_1, 0, QuestIsland_House_Room2_EventScript_BattleVisitingTrainer
	.2byte 0

QuestIsland_House_Room2_EventScript_BattleVisitingTrainer::
	lockall
	applymovement LOCALID_PLAYER, QuestIsland_House_Room2_Movement_PlayerEnterRoom
	waitmovement 0
	special BufferEReaderTrainerGreeting
	msgbox gStringVar4
	closemessage
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 0
	special StartSpecialBattle
	waitstate
	call_if_eq VAR_RESULT, 3, QuestIsland_House_Room2_EventScript_BattleTie
	call_if_eq VAR_RESULT, 1, QuestIsland_House_Room2_EventScript_BattleWon
	call_if_eq VAR_RESULT, 2, QuestIsland_House_Room2_EventScript_BattleLost
	closemessage
	special HealPlayerParty
	applymovement LOCALID_PLAYER, QuestIsland_House_Room2_Movement_PlayerExitRoom
	waitmovement 0
	special LoadPlayerParty
	setvar VAR_TEMP_1, 1
	warp MAP_QUEST_ISLAND_HOUSE_ROOM1, 4, 1
	waitstate
	releaseall
	end

QuestIsland_House_Room2_EventScript_BattleTie::
	setvar VAR_MAP_SCENE_QUEST_ISLAND_HOUSE_ROOM1, 3
	msgbox QuestIsland_House_Room2_Text_MatchEndedUpDraw
	return

QuestIsland_House_Room2_EventScript_BattleWon::
	setvar VAR_MAP_SCENE_QUEST_ISLAND_HOUSE_ROOM1, 1
	special ShowFieldMessageStringVar4
	waitmessage
	waitbuttonpress
	return

QuestIsland_House_Room2_EventScript_BattleLost::
	setvar VAR_MAP_SCENE_QUEST_ISLAND_HOUSE_ROOM1, 2
	special ShowFieldMessageStringVar4
	waitmessage
	waitbuttonpress
	return

QuestIsland_House_Room2_Movement_PlayerEnterRoom::
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	step_end

QuestIsland_House_Room2_Movement_PlayerExitRoom::
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	delay_8
	step_end
