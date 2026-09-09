.equ PLAYER_X_POS, VAR_0x8004
.equ PLAYER_Y_POS, VAR_0x8005

.set LOCALID_WAREHOUSE_GRUNT2, 1
.set LOCALID_WAREHOUSE_GRUNT3, 2
.set LOCALID_WAREHOUSE_ADMIN1, 3
.set LOCALID_WAREHOUSE_ADMIN2, 4

ChronoIsland_Warehouse_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, ChronoIsland_Warehouse_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, ChronoIsland_Warehouse_OnTransition
	.byte 0

ChronoIsland_Warehouse_OnTransition::
	@setworldmapflag FLAG_WORLD_MAP_CHRONO_ISLAND_ROCKET_WAREHOUSE
	end

ChronoIsland_Warehouse_OnLoad::
	call_if_defeated TRAINER_TEAM_ROCKET_ADMIN, ChronoIsland_Warehouse_EventScript_SetArrowsForReEntry
	end

ChronoIsland_Warehouse_EventScript_SetArrowsForReEntry::
	@setmetatile 26, 20, METATILE_SilphCo_Arrow_Up, 0
	@setmetatile 27, 20, METATILE_SilphCo_Arrow_Up, 0
	return

ChronoIsland_Warehouse_EventScript_Cage::
	lockall
	goto_if_set FLAG_DEFEATED_ROCKETS_IN_WAREHOUSE, ChronoIsland_Warehouse_EventScript_CageUnlocked
	msgbox ChronoIsland_Warehouse_Text_ManyMonsLockedInPen
	releaseall
	end

ChronoIsland_Warehouse_EventScript_CageUnlocked::
	msgbox ChronoIsland_Warehouse_Text_PenUnlockedMonsFled
	releaseall
	end

ChronoIsland_Warehouse_EventScript_Computer::
	msgbox ChronoIsland_Warehouse_Text_ReportWithGraphsAndText, MSGBOX_SIGN
	end

ChronoIsland_Warehouse_EventScript_Admin2Trigger::
	lockall
	applymovement LOCALID_WAREHOUSE_ADMIN2, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	setvar VAR_MAP_SCENE_ROCKET_WAREHOUSE, 1
	releaseall
	end

ChronoIsland_Warehouse_EventScript_Gideon::
	trainerbattle_single TRAINER_SCIENTIST_GIDEON, ChronoIsland_Warehouse_Text_GideonIntro, ChronoIsland_Warehouse_Text_GideonDefeat, ChronoIsland_Warehouse_EventScript_DefeatedGideon
	@goto_if_set FLAG_SYS_CAN_LINK_WITH_RS, ChronoIsland_Warehouse_EventScript_MentionGiovannisKid
	msgbox ChronoIsland_Warehouse_Text_GetLostLeaveMeBe, MSGBOX_AUTOCLOSE
	end

ChronoIsland_Warehouse_EventScript_MentionGiovannisKid::
	msgbox ChronoIsland_Warehouse_Text_GiovannisKidHasRedHair, MSGBOX_AUTOCLOSE
	end

ChronoIsland_Warehouse_EventScript_DefeatedGideon::
	msgbox ChronoIsland_Warehouse_Text_GideonPostBattle
	setflag FLAG_RECOVERED_SAPPHIRE
	giveitem ITEM_SAPPHIRE
	release
	end

ChronoIsland_Warehouse_EventScript_Grunt2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_47, ChronoIsland_Warehouse_Text_Grunt2Intro, ChronoIsland_Warehouse_Text_Grunt2Defeat
	msgbox ChronoIsland_Warehouse_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

ChronoIsland_Warehouse_EventScript_Grunt3::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_48, ChronoIsland_Warehouse_Text_Grunt3Intro, ChronoIsland_Warehouse_Text_Grunt3Defeat
	msgbox ChronoIsland_Warehouse_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

ChronoIsland_Warehouse_EventScript_Admin2::
	trainerbattle_single TRAINER_TEAM_ROCKET_ADMIN_2, ChronoIsland_Warehouse_Text_Admin2Intro, ChronoIsland_Warehouse_Text_Admin2Defeat, ChronoIsland_Warehouse_EventScript_DefeatedAdmin2
	msgbox ChronoIsland_Warehouse_Text_Admin2PostBattle, MSGBOX_AUTOCLOSE
	end

ChronoIsland_Warehouse_EventScript_DefeatedAdmin2::
	getplayerxy PLAYER_X_POS, PLAYER_Y_POS
	call_if_le PLAYER_X_POS, 24, ChronoIsland_Warehouse_EventScript_PlayerFaceAdmin2
	msgbox ChronoIsland_Warehouse_Text_Admin2PostBattle
	closemessage
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_WAREHOUSE_GRUNT2
	removeobject LOCALID_WAREHOUSE_GRUNT3
	removeobject LOCALID_WAREHOUSE_ADMIN2
	removeobject LOCALID_WAREHOUSE_ADMIN1
	setflag FLAG_HIDE_CHRONO_ISLAND_ROCKETS
	fadescreen FADE_FROM_BLACK
	setvar VAR_MAP_SCENE_ROCKET_WAREHOUSE, 1
	setflag FLAG_DEFEATED_ROCKETS_IN_WAREHOUSE
	release
	end

ChronoIsland_Warehouse_EventScript_PlayerFaceAdmin2::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

ChronoIsland_Warehouse_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_42, ChronoIsland_Warehouse_Text_Grunt1Intro, ChronoIsland_Warehouse_Text_Grunt1Defeat
	msgbox ChronoIsland_Warehouse_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

ChronoIsland_Warehouse_EventScript_Admin1::
	trainerbattle_single TRAINER_TEAM_ROCKET_ADMIN, ChronoIsland_Warehouse_Text_Admin1Intro, ChronoIsland_Warehouse_Text_Admin1Defeat, ChronoIsland_Warehouse_EventScript_DefeatedAdmin1
	msgbox ChronoIsland_Warehouse_Text_MadeItSoYouCanComeBackThrough, MSGBOX_AUTOCLOSE
	end

ChronoIsland_Warehouse_EventScript_DefeatedAdmin1::
	getplayerxy PLAYER_X_POS, PLAYER_Y_POS
	specialvar VAR_RESULT, GetPlayerFacingDirection
	call_if_eq VAR_RESULT, DIR_NORTH, ChronoIsland_Warehouse_EventScript_PlayerFaceAdmin1
	msgbox ChronoIsland_Warehouse_Text_Admin1PostBattle
	closemessage
	call_if_le PLAYER_X_POS, 24, ChronoIsland_Warehouse_EventScript_AdminWalkToSwitchFar
	call_if_eq PLAYER_X_POS, 25, ChronoIsland_Warehouse_EventScript_AdminWalkToSwitch
	call_if_eq PLAYER_X_POS, 26, ChronoIsland_Warehouse_EventScript_AdminFaceSwitch
	call_if_eq PLAYER_X_POS, 27, ChronoIsland_Warehouse_EventScript_AdminFaceSwitch
	playse SE_PIN
	call ChronoIsland_Warehouse_EventScript_SetArrowsForReEntry
	special DrawWholeMapView
	waitse
	call_if_le PLAYER_X_POS, 24, ChronoIsland_Warehouse_EventScript_AdminFacePlayerLeft
	call_if_eq PLAYER_X_POS, 25, ChronoIsland_Warehouse_EventScript_AdminFacePlayerLeft
	call_if_eq PLAYER_X_POS, 26, ChronoIsland_Warehouse_EventScript_AdminFacePlayerLeft
	call_if_eq PLAYER_X_POS, 27, ChronoIsland_Warehouse_EventScript_AdminFacePlayerDown
	msgbox ChronoIsland_Warehouse_Text_MadeItSoYouCanComeBackThrough
	release
	end

ChronoIsland_Warehouse_EventScript_PlayerFaceAdmin1::
	goto_if_eq PLAYER_X_POS, 27, Common_EventScript_NopReturn
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

ChronoIsland_Warehouse_EventScript_AdminWalkToSwitchFar::
	applymovement LOCALID_WAREHOUSE_ADMIN1, ChronoIsland_Warehouse_Movement_AdminWalkToSwitchFar
	waitmovement 0
	return

ChronoIsland_Warehouse_EventScript_AdminWalkToSwitch::
	applymovement LOCALID_WAREHOUSE_ADMIN1, ChronoIsland_Warehouse_Movement_AdminWalkToSwitch
	waitmovement 0
	return

ChronoIsland_Warehouse_EventScript_AdminFaceSwitch::
	applymovement LOCALID_WAREHOUSE_ADMIN1, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

ChronoIsland_Warehouse_EventScript_AdminFacePlayerLeft::
	applymovement LOCALID_WAREHOUSE_ADMIN1, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

ChronoIsland_Warehouse_EventScript_AdminFacePlayerDown::
	applymovement LOCALID_WAREHOUSE_ADMIN1, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

ChronoIsland_Warehouse_Movement_AdminWalkToSwitchFar::
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

ChronoIsland_Warehouse_Movement_AdminWalkToSwitch::
	walk_right
	walk_in_place_faster_up
	step_end
ChronoIsland_Warehouse_Text_ManyMonsLockedInPen::
    .string "There are many POKéMON locked\n"
    .string "away in the pen…$"

ChronoIsland_Warehouse_Text_PenUnlockedMonsFled::
    .string "The pen door is unlocked.\n"
    .string "The POKéMON appear to have fled.$"

ChronoIsland_Warehouse_Text_Grunt2Intro::
    .string "Did you come here knowing it's\n"
    .string "TEAM ROCKET's WAREHOUSE?$"

ChronoIsland_Warehouse_Text_Grunt2Defeat::
    .string "What do you think you're doing?!$"

ChronoIsland_Warehouse_Text_Grunt2PostBattle::
    .string "TEAM ROCKET broke up?\n"
    .string "What planet are you from?$"

ChronoIsland_Warehouse_Text_Grunt1Intro::
    .string "Oh, now your POKéMON look strong.\n"
    .string "You're willing to sell them?\p"
    .string "Oh?\n"
    .string "You wanted to battle?$"

ChronoIsland_Warehouse_Text_Grunt1Defeat::
    .string "Oh, but…\n"
    .string "Too much!$"

ChronoIsland_Warehouse_Text_Grunt1PostBattle::
    .string "We can give you a great price.\n"
    .string "Sell us your POKéMON!$"

ChronoIsland_Warehouse_Text_Grunt3Intro::
    .string "I got word about you from the\n"
    .string "others.\p"
    .string "But there's no way a kid like you'd\n"
    .string "know our BOSS GIOVANNI!$"

ChronoIsland_Warehouse_Text_Grunt3Defeat::
    .string "Don't…you…dare…laugh…$"

ChronoIsland_Warehouse_Text_Grunt3PostBattle::
    .string "Don't mess in the doings of adults,\n"
    .string "you jumped-up pip-squeak!$"

ChronoIsland_Warehouse_Text_Admin1Intro::
    .string "I don't know or care if what I'm\n"
    .string "doing is right or wrong…\p"
    .string "I just put my faith in GIOVANNI\n"
    .string "and do as I am told.$"

ChronoIsland_Warehouse_Text_Admin1Defeat::
    .string "I…\n"
    .string "I'm shattered…$"

ChronoIsland_Warehouse_Text_Admin1PostBattle::
    .string "You're doing things according to\n"
    .string "your beliefs and morals.\p"
    .string "I understand now…$"

ChronoIsland_Warehouse_Text_MadeItSoYouCanComeBackThrough::
    .string "I've made it so you can come back\n"
    .string "in through there.\p"
    .string "Why don't you go get rested and\n"
    .string "refreshed for what lies ahead?\p"
    .string "The ADMIN after me outranks me\n"
    .string "thoroughly as a TRAINER.\p"
    .string "You'd better steel yourself for one\n"
    .string "harsh challenge.$"

ChronoIsland_Warehouse_Text_Admin2Intro::
    .string "That's quite enough of you \n"
    .string "playing the hero, kid.\p"
    .string "Spreading lies about how TEAM\n"
    .string "ROCKET has disbanded…\p"
    .string "It's such an obvious attempt to\n"
    .string "cause confusion in our ranks.\p"
    .string "Fortunately, we're not so ignorant\n"
    .string "to fall for the lies of a child!\p"
    .string "And now, I'll show you how scary\n"
    .string "an angry adult can be!$"

ChronoIsland_Warehouse_Text_Admin2Defeat::
    .string "Urgh…\n"
    .string "You were too strong…\p"
    .string "…\n"
    .string "Th-that's GIOVANNI's BADGE!\p"
    .string "So it's true?\n"
    .string "TEAM ROCKET really has disbanded?$"

ChronoIsland_Warehouse_Text_Admin2PostBattle::
    .string "We will abandon this WAREHOUSE…\p"
    .string "But don't think this is over.\n"
    .string "I won't let this be the end.\p"
    .string "I will find GIOVANNI.\n"
    .string "And I will resurrect TEAM ROCKET!\l"
    .string "I will…\p"
    .string "Until then, farewell!$"

ChronoIsland_Warehouse_Text_ReportWithGraphsAndText::
    .string "A report with graphs and text is on\n"
    .string "the PC monitor.\p"
    .string "“The Influence of Magnetic Waves\n"
    .string "on POKéMON Evolution”…\p"
    .string "… … … … … …\p"
    .string "It's too difficult to understand…$"

ChronoIsland_Warehouse_Text_GideonIntro::
    .string "I almost managed to sell the\n"
    .string "SAPPHIRE for huge money…\p"
    .string "Then, you just had to come along\n"
    .string "and blow the whole deal apart!\p"
    .string "Fufu… Fufufufu…\n"
    .string "There's no forgiveness for you!$"

ChronoIsland_Warehouse_Text_GideonDefeat::
    .string "Gah! Darn!\n"
    .string "Darn! Darn!$"

ChronoIsland_Warehouse_Text_GideonPostBattle::
    .string "If I can't sell it, it's worthless!\n"
    .string "Go ahead, take it!$"

ChronoIsland_Warehouse_Text_GetLostLeaveMeBe::
    .string "What do you want now?\n"
    .string "Go on, get lost, leave me be.$"

ChronoIsland_Warehouse_Text_GiovannisKidHasRedHair::
    .string "What, you again?\p"
    .string "You… You're not GIOVANNI's kid,\n"
    .string "are you?\p"
    .string "No, that can't be right!\n"
    .string "GIOVANNI's kid has red hair.\p"
    .string "You don't have any reasons for\n"
    .string "bugging me. Leave me alone!$"

