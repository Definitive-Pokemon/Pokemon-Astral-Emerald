.set LOCALID_BERRY_FOREST_LOSTELLE, 1

KinIsland_BerryForest_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, KinIsland_BerryForest_OnTransition
	.byte 0

KinIsland_BerryForest_OnTransition::
	@setworldmapflag FLAG_WORLD_MAP_KIN_ISLAND_BERRY_FOREST
	setescapewarp MAP_KIN_ISLAND_BOND_BRIDGE, 12, 6
	end

KinIsland_BerryForest_EventScript_Lostelle::
	lock
	faceplayer
	msgbox KinIsland_BerryForest_Text_HelpScaryPokemon
	playse SE_PIN
	applymovement LOCALID_BERRY_FOREST_LOSTELLE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_BERRY_FOREST_LOSTELLE, KinIsland_BerryForest_Movement_LostelleLookAround
	waitmovement 0
	msgbox KinIsland_BerryForest_Text_HereItComesAgain
	waitse
	playmoncry SPECIES_HYPNO, CRY_MODE_ENCOUNTER
	waitmoncry
	setwildbattle SPECIES_HYPNO, 30
	dowildbattle
	applymovement LOCALID_BERRY_FOREST_LOSTELLE, Common_Movement_FacePlayer
	waitmovement 0
	msgbox KinIsland_BerryForest_Text_ThankYouHaveThis
	giveitem ITEM_IAPAPA_BERRY
	call_if_eq VAR_RESULT, FALSE, KinIsland_BerryForest_EventScript_NoRoomForBerry
	@special BufferBigGuyOrBigGirlString
	msgbox KinIsland_BerryForest_Text_LetsGoHome
	closemessage
	setflag FLAG_AE_RESCUED_LOSTELLE
	setflag FLAG_AE_HIDE_LOSTELLE_IN_BERRY_FOREST
	setvar VAR_MAP_SCENE_BOON_ISLAND_JOYFUL_GAME_CORNER, 2
	clearflag FLAG_HIDE_BOON_ISLAND_GAME_CORNER_LOSTELLE
	warp MAP_BOON_ISLAND_JOYFUL_GAME_CORNER, 6, 6
	waitstate
	release
	end

KinIsland_BerryForest_EventScript_NoRoomForBerry::
	msgbox KinIsland_BerryForest_Text_BerryPouchIsFull
	return

KinIsland_BerryForest_Movement_LostelleLookAround::
	walk_in_place_faster_left
	delay_16
	walk_in_place_faster_right
	delay_8
	walk_in_place_faster_left
	step_end

KinIsland_BerryForest_EventScript_WelcomeSign::
	msgbox KinIsland_BerryForest_Text_WelcomeToBerryForest, MSGBOX_SIGN
	end

KinIsland_BerryForest_EventScript_BewareSign::
	msgbox KinIsland_BerryForest_Text_BewareWildBerryLovingMons, MSGBOX_SIGN
	end
KinIsland_BerryForest_Text_HelpScaryPokemon::
    .string "LOSTELLE: Whimper… Sniff…\n"
    .string "Oh! Please, help!\p"
    .string "A scary POKéMON appeared there\n"
    .string "a little while ago.\p"
    .string "It kept scaring.\n"
    .string "It made LOSTELLE scared.\p"
    .string "I'm too scared to move!\n"
    .string "But I want to go home…$"

KinIsland_BerryForest_Text_HereItComesAgain::
    .string "Oh! Here it comes again!\n"
    .string "No! Go away! It's scaring me!\p"
    .string "Waaaaaaah!\n"
    .string "I want my daddy!$"

KinIsland_BerryForest_Text_ThankYouHaveThis::
    .string "Ohh! That was so scary!\n"
    .string "Thank you!\p"
    .string "LOSTELLE came to pick some\n"
    .string "BERRIES.\p"
    .string "You can have this!$"

KinIsland_BerryForest_Text_LetsGoHome::
    .string "What's your name?\p"
    .string "LOSTELLE's scared, so can I go\n"
    .string "with you to my daddy's house?\p"
    .string "Okay!\n"
    .string "Let's go home!$"

KinIsland_BerryForest_Text_BerryPouchIsFull::
    .string "Your BERRY POUCH is full.\n"
    .string "I guess you don't want this.$"

KinIsland_BerryForest_Text_WelcomeToBerryForest::
    .string "Welcome to the BERRY FOREST\p"
    .string "Be friendly and share BERRIES with\n"
    .string "others and POKéMON.$"

KinIsland_BerryForest_Text_BewareWildBerryLovingMons::
    .string "Beware of wild, BERRY-loving\n"
    .string "POKéMON!$"

