.set LOCALID_FLOE_ISLAND_DAYCARE_MAN, 1
.set LOCALID_FLOE_ISLAND_RIVAL, 10

FloeIsland_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FloeIsland_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FloeIsland_OnFrame
	.byte 0

FloeIsland_OnTransition::
	setflag FLAG_VISITED_FLOE_ISLAND
	call_if_eq VAR_MAP_SCENE_FLOE_ISLAND, 0, FloeIsland_EventScript_ShowRival
	call FloeIsland_EventScript_TrySetDayCareManPos
	end

FloeIsland_EventScript_ShowRival::
	clearflag FLAG_HIDE_FLOE_ISLAND_RIVAL
	return

FloeIsland_EventScript_TrySetDayCareManPos::
	goto_if_unset FLAG_PENDING_DAYCARE_EGG, FloeIsland_EventScript_EndSetDayCareManPos
	setobjectxyperm LOCALID_FLOE_ISLAND_DAYCARE_MAN, 16, 14
FloeIsland_EventScript_EndSetDayCareManPos::
	return

FloeIsland_OnFrame::
	map_script_2 VAR_MAP_SCENE_FLOE_ISLAND, 0, FloeIsland_EventScript_RivalScene
	.2byte 0

FloeIsland_EventScript_RivalScene::
	lockall
	textcolor NPC_TEXT_COLOR_MALE
	applymovement LOCALID_FLOE_ISLAND_RIVAL, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	playbgm MUS_RG_ENCOUNTER_RIVAL, 0
	applymovement LOCALID_FLOE_ISLAND_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_FLOE_ISLAND_RIVAL, Common_Movement_Delay48
	waitmovement 0
	delay 25
	applymovement LOCALID_FLOE_ISLAND_RIVAL, FloeIsland_Movement_RivalApproach
	waitmovement 0
	msgbox FloeIsland_Text_RivalAlreadyGotEggBeSmellingYa
	closemessage
	applymovement LOCALID_PLAYER, FloeIsland_Movement_PlayerWatchRivalExit
	applymovement LOCALID_FLOE_ISLAND_RIVAL, FloeIsland_Movement_RivalExit
	waitmovement 0
	fadedefaultbgm
	playse SE_EXIT
	delay 35
	removeobject LOCALID_FLOE_ISLAND_RIVAL
	setvar VAR_MAP_SCENE_FLOE_ISLAND, 1
	releaseall
	end

FloeIsland_Movement_RivalApproach::
	walk_right
	walk_right
	walk_down
	walk_down
	step_end

FloeIsland_Movement_RivalExit::
	delay_16
	delay_4
	walk_down
	step_end

FloeIsland_Movement_PlayerWatchRivalExit::
	walk_left
	walk_in_place_faster_right
	step_end

FloeIsland_EventScript_DaycareMan::
	lock
	faceplayer
	special GetDaycareMonNicknames
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_EGG_WAITING, FloeIsland_EventScript_DaycareEggWaiting
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, FloeIsland_EventScript_CheckOnOneMon
	goto_if_eq VAR_RESULT, DAYCARE_TWO_MONS, FloeIsland_EventScript_CheckOnTwoMons
	msgbox DayCare_Text_ImDaycareManSpeakToMyWife
	release
	end

FloeIsland_EventScript_DaycareEggWaiting::
	msgbox DayCare_Text_DoYouWantEgg, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, FloeIsland_EventScript_DaycareAcceptEgg
	msgbox DayCare_Text_IWillKeepDoYouWantIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, FloeIsland_EventScript_DaycareAcceptEgg
	msgbox DayCare_Text_IllKeepIt
	clearflag FLAG_PENDING_DAYCARE_EGG
	special RejectEggFromDayCare
	release
	end

FloeIsland_EventScript_DaycareAcceptEgg::
	specialvar VAR_RESULT, CalculatePlayerPartyCount
	goto_if_ne VAR_RESULT, PARTY_SIZE, FloeIsland_EventScript_DaycareReceivedEgg
	msgbox DayCare_Text_YouHaveNoRoomForIt
	release
	end

FloeIsland_EventScript_DaycareReceivedEgg::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	message DayCare_Text_ReceivedEgg
	call EventScript_RestorePrevTextColor
	playfanfare MUS_RG_LEVEL_UP
	waitfanfare
	waitbuttonpress
	msgbox DayCare_Text_TakeGoodCareOfIt
	special GiveEggFromDaycare
	clearflag FLAG_PENDING_DAYCARE_EGG
	release
	end

FloeIsland_EventScript_CheckOnOneMon::
	special GetDaycareMonNicknames
	msgbox DayCare_Text_YourMonIsDoingFine
	release
	end

FloeIsland_EventScript_CheckOnTwoMons::
	special GetDaycareMonNicknames
	msgbox DayCare_Text_YourMonsAreDoingFine
	special SetDaycareCompatibilityString
	special ShowFieldMessageStringVar4
	waitmessage
	waitbuttonpress
	release
	end

FloeIsland_EventScript_OldWoman::
	lock
	faceplayer
	goto_if_set FLAG_SYS_CAN_LINK_WITH_RS, FloeIsland_EventScript_OldWomanLoreleiLeft
	msgbox FloeIsland_Text_LoreleiHasReturned
	release
	end

FloeIsland_EventScript_OldWomanLoreleiLeft::
	famechecker FAMECHECKER_LORELEI, 5
	msgbox FloeIsland_Text_LoreleiMetLaprasAsChild
	release
	end

FloeIsland_EventScript_LittleGirl::
	lock
	faceplayer
	famechecker FAMECHECKER_LORELEI, 4
	msgbox FloeIsland_Text_LoreleiHasLotsOfStuffedDolls
	release
	end

FloeIsland_EventScript_FatMan::
	msgbox FloeIsland_Text_MadeSlushieUsingIcefallCaveIce, MSGBOX_NPC
	end

FloeIsland_EventScript_IslandSign::
	msgbox FloeIsland_Text_IslandSign, MSGBOX_SIGN
	end

FloeIsland_EventScript_LoreleisHouseSign::
	msgbox FloeIsland_Text_LoreleisHouse, MSGBOX_SIGN
	end
FloeIsland_Text_IslandSign::
    .string "FOUR ISLAND\n"
    .string "The Warm, Blue, Floe Island$"

FloeIsland_Text_LoreleiHasReturned::
    .string "LORELEI has returned.\p"
    .string "Did she find the city life too\n"
    .string "stressful, I wonder?$"

FloeIsland_Text_LoreleiMetLaprasAsChild::
    .string "LORELEI has gone back.\p"
    .string "The LAPRAS she has, I imagine it\n"
    .string "to be the one she met as a child.\p"
    .string "I believe it was in ICEFALL CAVE\n"
    .string "that she caught it.\p"
    .string "Perhaps that POKéMON has been with\n"
    .string "her ever since.$"

FloeIsland_Text_RivalAlreadyGotEggBeSmellingYa::
    .string "{RIVAL}: Hey!\n"
    .string "{PLAYER}!\p"
    .string "What are you doing here in the\n"
    .string "SEVII ISLANDS?\p"
    .string "You should quit copying me,\n"
    .string "you know?\p"
    .string "Anyways, I already got my POKéMON\n"
    .string "EGG, so I'm done with this island.\p"
    .string "Heh, I bet you don't even know\n"
    .string "about POKéMON EGGS.\p"
    .string "You'll never fill your NATIONAL\n"
    .string "POKéDEX that way.\p"
    .string "By the way, I saw someone we both\n"
    .string "know on this island.\p"
    .string "Why don't you go look around if\n"
    .string "it makes you curious?\p"
    .string "Me, I don't have the time to\n"
    .string "waste.\p"
    .string "Be smelling ya!$"

FloeIsland_Text_LoreleiHasLotsOfStuffedDolls::
    .string "Oh, you found me!\n"
    .string "Please don't tell LORELEI.\p"
    .string "Did you know that LORELEI has lots\n"
    .string "and lots of stuffed dolls?\p"
    .string "Every time she comes back to\n"
    .string "FOUR ISLAND, her collection grows!$"

FloeIsland_Text_MadeSlushieUsingIcefallCaveIce::
    .string "Ooh, chilly!\p"
    .string "I made a slushie using ice I\n"
    .string "shaved inside ICEFALL CAVE.\p"
    .string "It's chilly and tasty!$"

FloeIsland_Text_LoreleisHouse::
    .string "LORELEI'S HOUSE$"

