.set LOCALID_JOYFUL_GAME_CORNER_DADDY, 1
.set LOCALID_JOYFUL_GAME_CORNER_BIKER, 2
.set LOCALID_JOYFUL_GAME_CORNER_LOSTELLE, 3

BoonIsland_JoyfulGameCorner_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, BoonIsland_JoyfulGameCorner_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BoonIsland_JoyfulGameCorner_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BoonIsland_JoyfulGameCorner_OnFrame
	map_script MAP_SCRIPT_ON_LOAD, CableClub_OnLoad
	.byte 0

BoonIsland_JoyfulGameCorner_OnTransition::
	call_if_set FLAG_AE_GOT_MOON_STONE_FROM_JOYFUL_GAME_CORNER, BoonIsland_JoyfulGameCorner_EventScript_SetLostelleReturnedPos
	end

BoonIsland_JoyfulGameCorner_EventScript_SetLostelleReturnedPos::
	setobjectxyperm LOCALID_JOYFUL_GAME_CORNER_DADDY, 6, 2
	setobjectmovementtype LOCALID_JOYFUL_GAME_CORNER_DADDY, MOVEMENT_TYPE_FACE_DOWN
	setobjectmovementtype LOCALID_JOYFUL_GAME_CORNER_LOSTELLE, MOVEMENT_TYPE_LOOK_AROUND
	setvar VAR_MAP_SCENE_BOON_ISLAND_JOYFUL_GAME_CORNER, 4
	return

BoonIsland_JoyfulGameCorner_OnWarp::
	map_script_2 VAR_MAP_SCENE_BOON_ISLAND_JOYFUL_GAME_CORNER, 2, BoonIsland_JoyfulGameCorner_EventScript_TurnPlayerNorth
	@map_script_2 VAR_CABLE_CLUB_STATE, USING_MINIGAME, EventScript_CheckTurnAttendant
	.2byte 0

BoonIsland_JoyfulGameCorner_EventScript_TurnPlayerNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BoonIsland_JoyfulGameCorner_OnFrame::
	map_script_2 VAR_MAP_SCENE_BOON_ISLAND_JOYFUL_GAME_CORNER, 0, BoonIsland_JoyfulGameCorner_EventScript_HelpFindLostelleScene
	map_script_2 VAR_MAP_SCENE_BOON_ISLAND_JOYFUL_GAME_CORNER, 2, BoonIsland_JoyfulGameCorner_EventScript_FoundLostelleScene
	map_script_2 VAR_CABLE_CLUB_STATE, USING_MINIGAME, CableClub_EventScript_ExitMinigameRoom
	.2byte 0

BoonIsland_JoyfulGameCorner_EventScript_FoundLostelleScene::
	lockall

	msgbox BoonIsland_JoyfulGameCorner_Text_YouRescuedLostelle

	@special BufferBigGuyOrBigGirlString
	msgbox BoonIsland_JoyfulGameCorner_Text_LostelleItsOkayDaddy
	closemessage
	applymovement LOCALID_JOYFUL_GAME_CORNER_LOSTELLE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	setvar VAR_MAP_SCENE_BOON_ISLAND_JOYFUL_GAME_CORNER, 3
	releaseall
	end

BoonIsland_JoyfulGameCorner_EventScript_HelpFindLostelleScene::
	lockall

	applymovement LOCALID_JOYFUL_GAME_CORNER_DADDY, BoonIsland_JoyfulGameCorner_Movement_DaddyPacing
	waitmovement 0
	msgbox BoonIsland_JoyfulGameCorner_Text_WhereHasLostelleGottenTo
	closemessage
	applymovement LOCALID_JOYFUL_GAME_CORNER_DADDY, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_JOYFUL_GAME_CORNER_DADDY, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_JOYFUL_GAME_CORNER_DADDY, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_JOYFUL_GAME_CORNER_DADDY, BoonIsland_JoyfulGameCorner_Movement_DaddyApproachPlayer
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox BoonIsland_JoyfulGameCorner_Text_PleaseHelpFindLostelle
	closemessage
	playse SE_DOOR
	waitse
	applymovement LOCALID_PLAYER, BoonIsland_JoyfulGameCorner_Movement_PlayerFaceDaddy
	waitmovement 0
	playbgm MUS_RG_ENCOUNTER_BOY, 0
	addobject LOCALID_JOYFUL_GAME_CORNER_BIKER
	applymovement LOCALID_JOYFUL_GAME_CORNER_BIKER, BoonIsland_JoyfulGameCorner_Movement_BikerLookAround
	waitmovement 0
	msgbox BoonIsland_JoyfulGameCorner_Text_IsThisOnlyKinIsland
	applymovement LOCALID_JOYFUL_GAME_CORNER_BIKER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox BoonIsland_JoyfulGameCorner_Text_ThisIsBoonIslandMoveIt
	msgbox BoonIsland_JoyfulGameCorner_Text_TheseIslandsAreConfusing
	closemessage
	applymovement LOCALID_JOYFUL_GAME_CORNER_BIKER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_JOYFUL_GAME_CORNER_BIKER
	fadedefaultbgm
	delay 60
	msgbox BoonIsland_JoyfulGameCorner_Text_PunkScuffedUpMyFloor
	clearflag FLAG_HIDE_KIN_ISLAND_LONE_BIKER
	setvar VAR_MAP_SCENE_KIN_ISLAND, 2
	setvar VAR_MAP_SCENE_BOON_ISLAND_JOYFUL_GAME_CORNER, 1
	releaseall
	end

BoonIsland_JoyfulGameCorner_Movement_DaddyPacing::
	walk_left
	walk_right
	walk_right
	delay_8
	walk_in_place_faster_up
	delay_16
	step_end

BoonIsland_JoyfulGameCorner_Movement_DaddyApproachPlayer::
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

BoonIsland_JoyfulGameCorner_Movement_PlayerFaceDaddy::
	walk_left
	walk_in_place_faster_right
	step_end

BoonIsland_JoyfulGameCorner_Movement_BikerLookAround::
	walk_in_place_faster_left
	delay_8
	walk_in_place_faster_right
	delay_8
	walk_in_place_faster_up
	step_end

BoonIsland_JoyfulGameCorner_EventScript_InfoMan::
	lock
	faceplayer
	goto_if_set FLAG_AE_RESCUED_LOSTELLE, BoonIsland_JoyfulGameCorner_EventScript_GetGamesGoingSoon
	msgbox BoonIsland_JoyfulGameCorner_Text_NotRunningAnyGamesToday
	release
	end

BoonIsland_JoyfulGameCorner_EventScript_GetGamesGoingSoon::
	msgbox BoonIsland_JoyfulGameCorner_Text_GetGamesGoingSoon
	release
	end

@ Only referred to as Lostelles Daddy in text
BoonIsland_JoyfulGameCorner_EventScript_LostellesDaddy::
	lock
	faceplayer
	goto_if_set FLAG_AE_GOT_MOON_STONE_FROM_JOYFUL_GAME_CORNER, BoonIsland_JoyfulGameCorner_EventScript_GetGameCornerRunning
	goto_if_eq VAR_MAP_SCENE_BOON_ISLAND_JOYFUL_GAME_CORNER, 3, BoonIsland_JoyfulGameCorner_EventScript_GiveDaddyMeteorite
	msgbox BoonIsland_JoyfulGameCorner_Text_PleaseGoToKinIsland
	release
	end

BoonIsland_JoyfulGameCorner_EventScript_GiveDaddyMeteorite::
	goto_if_set FLAG_NO_ROOM_FOR_JOYFUL_GAME_CORNER_MOON_STONE, BoonIsland_JoyfulGameCorner_EventScript_ReceiveMoonStone
	msgbox BoonIsland_JoyfulGameCorner_Text_ThisIsForMe
	setvar VAR_MAP_SCENE_KNOT_ISLAND_POKEMON_CENTER_1F, 2
	playfanfare MUS_OBTAIN_TMHM
	message BoonIsland_JoyfulGameCorner_Text_HandedMeteoriteToLostellesDaddy
	waitmessage
	waitfanfare
	removeitem ITEM_METEORITE
	msgbox BoonIsland_JoyfulGameCorner_Text_OhThisIsFromBill
	goto BoonIsland_JoyfulGameCorner_EventScript_ReceiveMoonStone
	end

BoonIsland_JoyfulGameCorner_EventScript_ReceiveMoonStone::
	checkitemspace ITEM_MOON_STONE
	goto_if_eq VAR_RESULT, FALSE, BoonIsland_JoyfulGameCorner_EventScript_NoRoomForMoonStone
	@additem ITEM_MOON_STONE
	setflag FLAG_AE_GOT_MOON_STONE_FROM_JOYFUL_GAME_CORNER
	giveitem ITEM_MOON_STONE
	@msgreceiveditem BoonIsland_JoyfulGameCorner_Text_ReceivedMoonStoneFromLostellesDaddy, ITEM_MOON_STONE
	release
	end

BoonIsland_JoyfulGameCorner_EventScript_GetGameCornerRunning::
	msgbox BoonIsland_JoyfulGameCorner_Text_IllGetGameCornerRunning
	release
	end

BoonIsland_JoyfulGameCorner_EventScript_NoRoomForMoonStone::
	setflag FLAG_NO_ROOM_FOR_JOYFUL_GAME_CORNER_MOON_STONE
	msgbox BoonIsland_JoyfulGameCorner_Text_NotGoingToFitInBag
	release
	end

BoonIsland_JoyfulGameCorner_EventScript_Lostelle::
	lock
	faceplayer
	msgbox BoonIsland_JoyfulGameCorner_Text_PleaseShowMeYouBeingCool
	release
	end
BoonIsland_JoyfulGameCorner_Text_WhereHasLostelleGottenTo::
    .string "Now, where's LOSTELLE gotten to\n"
    .string "today?\p"
    .string "She always brings me lunch every\n"
    .string "day right about now…$"

BoonIsland_JoyfulGameCorner_Text_PleaseHelpFindLostelle::
    .string "Hm? You, there!\n"
    .string "Are you a friend of LOSTELLE's?\p"
    .string "Have you seen LOSTELLE around?\n"
    .string "I don't know where she might be.\l"
    .string "She should've been here long ago.\p"
    .string "LOSTELLE's a cutie - she got my\n"
    .string "looks - so what if someone…\p"
    .string "What if something's happened to\n"
    .string "my LOSTELLE?!\p"
    .string "Please, help me find her!\n"
    .string "Please go search THREE ISLAND!$"

BoonIsland_JoyfulGameCorner_Text_IsThisOnlyKinIsland::
    .string "Hah? What is this GAME CORNER?\n"
    .string "How much sadder can this get?\p"
    .string "Those clowns…\p"
    .string "They said they'd be waiting on the\n"
    .string "island, so where are they?\p"
    .string "Hey, you! Is this the only THREE\n"
    .string "ISLAND around here?$"

BoonIsland_JoyfulGameCorner_Text_ThisIsBoonIslandMoveIt::
    .string "Try waking up before you crawl out\n"
    .string "of bed, you punk.\p"
    .string "This is TWO ISLAND!\p"
    .string "Move it! Get your filthy motorbike\n"
    .string "out of my place!$"

BoonIsland_JoyfulGameCorner_Text_TheseIslandsAreConfusing::
    .string "Huh…\n"
    .string "Oh, oh, gotcha.\p"
    .string "Tch…\n"
    .string "These islands are confusing…$"

BoonIsland_JoyfulGameCorner_Text_PunkScuffedUpMyFloor::
    .string "Would you look at that?\n"
    .string "That punk scuffed up my floor.$"

BoonIsland_JoyfulGameCorner_Text_PleaseGoToKinIsland::
    .string "Hey, but listen! I'm begging you,\n"
    .string "you have to go to THREE ISLAND.\p"
    .string "If anything were to happen to my\n"
    .string "LOSTELLE…\p"
    .string "My place is the house with the red\n"
    .string "roof on THREE ISLAND.\p"
    .string "She may just show up late here,\n"
    .string "so I can't run off anywhere.\p"
    .string "That's why I have to get you to do\n"
    .string "me this big favor.$"

BoonIsland_JoyfulGameCorner_Text_NotRunningAnyGamesToday::
    .string "I'm sorry.\n"
    .string "We're not running any games today.$"

BoonIsland_JoyfulGameCorner_Text_GetGamesGoingSoon::
    .string "We'll get the games going soon\n"
    .string "for you!$"

BoonIsland_JoyfulGameCorner_Text_YouRescuedLostelle::
    .string "So you rescued LOSTELLE?\n"
    .string "How can I thank you?\p"
    .string "LOSTELLE, darling, forgive me!\p"
    .string "Daddy didn't know you were scared\n"
    .string "and in trouble!$"

BoonIsland_JoyfulGameCorner_Text_LostelleItsOkayDaddy::
    .string "LOSTELLE: It's okay, Daddy.\n"
    .string "I got to be friends with {PLAYER}!$"

BoonIsland_JoyfulGameCorner_Text_ThisIsForMe::
    .string "Oh, what's that?\n"
    .string "You're saying that this is for me?\p"
    .string "How did you know that I love rare\n"
    .string "rocks and gems?\p"
    .string "You sure know how to make a guy\n"
    .string "happy.$"

BoonIsland_JoyfulGameCorner_Text_HandedMeteoriteToLostellesDaddy::
    .string "{PLAYER} handed the METEORITE\n"
    .string "to LOSTELLE's daddy.$"

BoonIsland_JoyfulGameCorner_Text_OhThisIsFromBill::
    .string "Oh, I see, this is from BILL!\n"
    .string "You have to thank him for me!\p"
    .string "You know, you've been fantastic.\n"
    .string "I want you to have this.$"

BoonIsland_JoyfulGameCorner_Text_ReceivedMoonStoneFromLostellesDaddy::
    .string "{PLAYER} received a MOON STONE\n"
    .string "from LOSTELLE's daddy.$"

BoonIsland_JoyfulGameCorner_Text_NotGoingToFitInBag::
    .string "Your BAG's not going to fit another\n"
    .string "thing…$"

BoonIsland_JoyfulGameCorner_Text_IllGetGameCornerRunning::
    .string "All right, I'll get the GAME CORNER\n"
    .string "running right away.\p"
    .string "You have to come visit with a\n"
    .string "friend.$"

BoonIsland_JoyfulGameCorner_Text_PleaseShowMeYouBeingCool::
    .string "Listen, listen!\p"
    .string "Please show me you being cool\n"
    .string "again!$"

