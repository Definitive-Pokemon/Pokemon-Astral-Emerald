KinIsland_Port_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, KinIsland_Port_OnTransition
	.byte 0

KinIsland_Port_OnTransition::
	clearflag FLAG_SYS_PC_STORAGE_DISABLED
	setflag FLAG_SEVII_DETOUR_FINISHED
	end

KinIsland_Port_EventScript_Woman::
	lock
	faceplayer
	goto_if_ge VAR_MAP_SCENE_BOON_ISLAND_JOYFUL_GAME_CORNER, 2, KinIsland_Port_EventScript_WomanLostelleFound
	goto_if_ge VAR_MAP_SCENE_KIN_ISLAND, 4, KinIsland_Port_EventScript_WomanBikersGone
	msgbox KinIsland_Port_Text_IllCallThePolice
	release
	end

KinIsland_Port_EventScript_WomanLostelleFound::
	msgbox KinIsland_Port_Text_EverythingTurnedOutForBest
	release
	end

KinIsland_Port_EventScript_WomanBikersGone::
	msgbox KinIsland_Port_Text_ThankGoodnessBikersGone
	release
	end

KinIsland_Port_EventScript_Biker1::
	msgbox KinIsland_Port_Text_WereKantoRiderFederation, MSGBOX_NPC
	end

KinIsland_Port_EventScript_Biker2::
	lock
	msgbox KinIsland_Port_Text_ForkOverMoney
	release
	end
KinIsland_Port_Text_WereKantoRiderFederation::
    .string "We're the KANTO RIDER FEDERATION!\n"
    .string "Vroom! Vavavavooom! Vroom!\p"
    .string "My bike's wimpy, so I have to\n"
    .string "make exhaust noises myself!$"

KinIsland_Port_Text_ForkOverMoney::
    .string "Hey, hey, lady!\n"
    .string "Fork over some spending money!$"

KinIsland_Port_Text_IllCallThePolice::
    .string "Aiyeeh!\p"
    .string "Wh-who are you?!\n"
    .string "I… I'll call the police!$"

KinIsland_Port_Text_ThankGoodnessBikersGone::
    .string "Those BIKERS…\n"
    .string "Are they gone?\p"
    .string "Oh, thank goodness!\n"
    .string "They certainly had me terrified!$"

KinIsland_Port_Text_EverythingTurnedOutForBest::
    .string "Those BIKERS ran off, and\n"
    .string "LOSTELLE was found safe.\p"
    .string "Everything turned out for the best!$"

