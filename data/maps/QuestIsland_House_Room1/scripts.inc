.equ TRAINER_VISITING, VAR_TEMP_1

.set LOCALID_QUEST_ISLAND_HOUSE_OLD_WOMAN, 1

QuestIsland_House_Room1_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, QuestIsland_House_Room1_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, QuestIsland_House_Room1_OnFrame
	.byte 0

QuestIsland_House_Room1_OnTransition::
	@special ValidateEReaderTrainer
	call_if_eq VAR_RESULT, 0, QuestIsland_House_Room1_EventScript_SetTrainerVisitingLayout
	call_if_ne VAR_MAP_SCENE_QUEST_ISLAND_HOUSE_ROOM1, 0, QuestIsland_House_Room1_EventScript_MoveOldWomanToDoor
	end

QuestIsland_House_Room1_EventScript_SetTrainerVisitingLayout::
	setvar TRAINER_VISITING, TRUE
	setobjectxyperm LOCALID_QUEST_ISLAND_HOUSE_OLD_WOMAN, 4, 2
	setobjectmovementtype LOCALID_QUEST_ISLAND_HOUSE_OLD_WOMAN, MOVEMENT_TYPE_FACE_DOWN
	@setmaplayoutindex LAYOUT_QUEST_ISLAND_HOUSE_ROOM1_DOOR_OPEN
	return

QuestIsland_House_Room1_EventScript_MoveOldWomanToDoor::
	setobjectxyperm LOCALID_QUEST_ISLAND_HOUSE_OLD_WOMAN, 3, 2
	setobjectmovementtype LOCALID_QUEST_ISLAND_HOUSE_OLD_WOMAN, MOVEMENT_TYPE_FACE_RIGHT
	return

QuestIsland_House_Room1_OnFrame::
	map_script_2 VAR_MAP_SCENE_QUEST_ISLAND_HOUSE_ROOM1, 1, QuestIsland_House_Room1_EventScript_OldWomanCommentOnBattle
	map_script_2 VAR_MAP_SCENE_QUEST_ISLAND_HOUSE_ROOM1, 2, QuestIsland_House_Room1_EventScript_OldWomanCommentOnBattle
	map_script_2 VAR_MAP_SCENE_QUEST_ISLAND_HOUSE_ROOM1, 3, QuestIsland_House_Room1_EventScript_OldWomanCommentOnBattle
	.2byte 0

QuestIsland_House_Room1_EventScript_OldWomanCommentOnBattle::
	lockall

	applymovement LOCALID_PLAYER, QuestIsland_House_Room1_Movement_PlayerReEnterRoom
	waitmovement 0
	applymovement LOCALID_QUEST_ISLAND_HOUSE_OLD_WOMAN, QuestIsland_House_Room1_Movement_OldWomanWalkBehindPlayer
	waitmovement 0
	copyobjectxytoperm LOCALID_QUEST_ISLAND_HOUSE_OLD_WOMAN
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	call_if_eq VAR_MAP_SCENE_QUEST_ISLAND_HOUSE_ROOM1, 1, QuestIsland_House_Room1_EventScript_BattleWonComment
	call_if_eq VAR_MAP_SCENE_QUEST_ISLAND_HOUSE_ROOM1, 2, QuestIsland_House_Room1_EventScript_BattleLostComment
	call_if_eq VAR_MAP_SCENE_QUEST_ISLAND_HOUSE_ROOM1, 3, QuestIsland_House_Room1_EventScript_BattleTiedComment
	special LoadPlayerParty
	setvar VAR_MAP_SCENE_QUEST_ISLAND_HOUSE_ROOM1, 0
	releaseall
	end

QuestIsland_House_Room1_EventScript_BattleWonComment::
	msgbox QuestIsland_House_Room1_Text_AstoundingBattle
	return

QuestIsland_House_Room1_EventScript_BattleLostComment::
	msgbox QuestIsland_House_Room1_Text_FeelYourDisappointment
	return

QuestIsland_House_Room1_EventScript_BattleTiedComment::
	msgbox QuestIsland_House_Room1_Text_DrawWasIt
	return

QuestIsland_House_Room1_Movement_PlayerReEnterRoom::
	walk_down
	step_end

QuestIsland_House_Room1_Movement_OldWomanWalkBehindPlayer::
	walk_right
	walk_in_place_faster_down
	step_end

QuestIsland_House_Room1_EventScript_OldWoman::
	lock
	faceplayer
	@special ValidateEReaderTrainer
	call_if_eq VAR_RESULT, 1, QuestIsland_House_Room1_EventScript_InvalidVisitingTrainer
	goto_if_eq TRAINER_VISITING, TRUE, QuestIsland_House_Room1_EventScript_TrainerVisiting
	msgbox QuestIsland_House_Room1_Text_OnlyEnjoymentWatchingBattles
	release
	end

QuestIsland_House_Room1_EventScript_InvalidVisitingTrainer::
	msgbox QuestIsland_House_Room1_Text_OnlyEnjoymentWatchingBattles
	release
	end

QuestIsland_House_Room1_EventScript_TrainerVisiting::
	special SavePlayerParty
	special BufferEReaderTrainerName
	msgbox QuestIsland_House_Room1_Text_ChallengeVisitingTrainer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, QuestIsland_House_Room1_EventScript_DeclineBattle
	call QuestIsland_House_Room1_EventScript_ChooseParty
	goto_if_eq VAR_RESULT, 0, QuestIsland_House_Room1_EventScript_DeclineBattle
	msgbox QuestIsland_House_Room1_Text_SaveProgressBeforeBattle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, QuestIsland_House_Room1_EventScript_DeclineBattle
	special LoadPlayerParty
	@call EventScript_AskSaveGame
	goto_if_eq VAR_RESULT, 0, QuestIsland_House_Room1_EventScript_DeclineBattle
	special SavePlayerParty
	@special ReducePlayerPartyToThree
	msgbox QuestIsland_House_Room1_Text_DontHoldAnythingBack
	closemessage
	call_if_eq VAR_FACING, DIR_NORTH, QuestIsland_House_Room1_EventScript_EnterBattleRoomNorth
	call_if_eq VAR_FACING, DIR_EAST, QuestIsland_House_Room1_EventScript_EnterBattleRoomEast
	call_if_eq VAR_FACING, DIR_WEST, QuestIsland_House_Room1_EventScript_EnterBattleRoomWest
	warp MAP_QUEST_ISLAND_HOUSE_ROOM2, 3, 1
	waitstate
	release
	end

QuestIsland_House_Room1_EventScript_DeclineBattle::
	special LoadPlayerParty
	msgbox QuestIsland_House_Room1_Text_OhYouWontBattle
	release
	end

QuestIsland_House_Room1_EventScript_ChooseParty::
	msgbox QuestIsland_House_Room1_Text_LimitThreeMonsPerSide
	fadescreen FADE_TO_BLACK
	special ChooseHalfPartyForBattle
	waitstate
	return

QuestIsland_House_Room1_EventScript_EnterBattleRoomNorth::
	applymovement VAR_LAST_TALKED, QuestIsland_House_Room1_Movement_OldWomanMoveAsideLeft
	applymovement LOCALID_PLAYER, QuestIsland_House_Room1_Movement_PlayerEnterBattleRoomNorth
	waitmovement 0
	return

QuestIsland_House_Room1_EventScript_EnterBattleRoomEast::
	applymovement VAR_LAST_TALKED, QuestIsland_House_Room1_Movement_OldWomanMoveAsideRight
	applymovement LOCALID_PLAYER, QuestIsland_House_Room1_Movement_PlayerEnterBattleRoomEast
	waitmovement 0
	return

QuestIsland_House_Room1_EventScript_EnterBattleRoomWest::
	applymovement VAR_LAST_TALKED, QuestIsland_House_Room1_Movement_OldWomanMoveAsideLeft
	applymovement LOCALID_PLAYER, QuestIsland_House_Room1_Movement_PlayerEnterBattleRoomWest
	waitmovement 0
	return

QuestIsland_House_Room1_Movement_PlayerEnterBattleRoomNorth::
	delay_16
	walk_up
	walk_up
	step_end

QuestIsland_House_Room1_Movement_PlayerEnterBattleRoomEast::
	delay_16
	walk_right
	walk_up
	step_end

QuestIsland_House_Room1_Movement_PlayerEnterBattleRoomWest::
	delay_16
	walk_left
	walk_up
	step_end

QuestIsland_House_Room1_Movement_OldWomanMoveAsideLeft::
	walk_left
	walk_in_place_faster_right
	step_end

QuestIsland_House_Room1_Movement_OldWomanMoveAsideRight::
	walk_right
	walk_in_place_faster_left
	step_end

QuestIsland_House_Room1_EventScript_Box::
	msgbox QuestIsland_House_Room1_Text_SlightBreezeAroundBox, MSGBOX_SIGN
	end

QuestIsland_House_Room1_Text_OnlyEnjoymentWatchingBattles::
    .string "I may not look like much now,\n"
    .string "but when I was younger…\p"
    .string "I flew everywhere, challenging\n"
    .string "TRAINERS wherever I found them.\p"
    .string "Now, my only source of enjoyment\n"
    .string "is reminiscing about the past while\l"
    .string "watching battles.$"

QuestIsland_House_Room1_Text_SlightBreezeAroundBox::
    .string "There is a slight breeze blowing\n"
    .string "around the box.$"

QuestIsland_House_Room1_Text_ChallengeVisitingTrainer::
    .string "Ah!\n"
    .string "Welcome, my friend!\p"
    .string "Let me tell you something. There's\n"
    .string "a hidden room in the basement.\p"
    .string "A TRAINER named {STR_VAR_1} is\n"
    .string "waiting there now.\p"
    .string "Tell me, you did come to challenge\n"
    .string "{STR_VAR_1}, am I right?$"

QuestIsland_House_Room1_Text_OhYouWontBattle::
    .string "Oh…\n"
    .string "You won't battle…\p"
    .string "I see, I see.\n"
    .string "… …\p"
    .string "Well, perhaps if you change your\n"
    .string "mind, do come back.$"

QuestIsland_House_Room1_Text_LimitThreeMonsPerSide::
    .string "Ah!\n"
    .string "You will battle for me?\p"
    .string "It was worth my time moving the\n"
    .string "box aside, then.\p"
    .string "… …\n"
    .string "But there is one slight problem.\p"
    .string "This hidden room is not built very\n"
    .string "sturdy.\p"
    .string "Can I get you to limit it to\n"
    .string "battles of three POKéMON per side?$"

QuestIsland_House_Room1_Text_SaveProgressBeforeBattle::
    .string "Fine! Before your battle, would\n"
    .string "you like to save your game?$"

QuestIsland_House_Room1_Text_DontHoldAnythingBack::
    .string "All right.\n"
    .string "Don't hold anything back!$"

@ Unused
QuestIsland_House_Room1_Text_StrVar1_1::
    .string "{STR_VAR_1}$"

QuestIsland_House_Room2_Text_MatchEndedUpDraw::
    .string "The match ended up a draw.$"

QuestIsland_House_Room1_Text_DrawWasIt::
    .string "A draw, was it?\p"
    .string "However, let me say that it was\n"
    .string "a worthy spectacle.\p"
    .string "I'd say it was a wonderful battle\n"
    .string "with a real sense of depth!$"

@ Unused
QuestIsland_House_Room1_Text_StrVar1_2::
    .string "{STR_VAR_1}$"

QuestIsland_House_Room1_Text_AstoundingBattle::
    .string "Bravo!\p"
    .string "Bravo, indeed!\n"
    .string "What an astounding battle!\p"
    .string "It was so astounding, why, it keeps\n"
    .string "filling my eyes with tears!\p"
    .string "The thrust and parry of expertly\n"
    .string "used techniques!\p"
    .string "The clash of power upon power!\p"
    .string "Yes!\n"
    .string "It was sheer magnificence!$"

@ Unused
QuestIsland_House_Room1_Text_StrVar1_3::
    .string "{STR_VAR_1}$"

QuestIsland_House_Room1_Text_FeelYourDisappointment::
    .string "Too bad!\n"
    .string "I feel your disappointment.\p"
    .string "However, that disappointment is\n"
    .string "what will make you better.\p"
    .string "Use it, learn from it, and make it\n"
    .string "motivate you to seek greatness.\p"
    .string "Forget not this disappointment\n"
    .string "and redouble your training!$"

