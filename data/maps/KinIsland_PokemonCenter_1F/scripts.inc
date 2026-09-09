KinIsland_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, KinIsland_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

KinIsland_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_KIN_ISLAND
	end

KinIsland_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	call Common_EventScript_PkmnCenterNurse
	release
	end

KinIsland_PokemonCenter_1F_EventScript_Sailor::
	msgbox KinIsland_PokemonCenter_1F_Text_ImpossibleToSurfBetweenIslands, MSGBOX_NPC
	end

KinIsland_PokemonCenter_1F_EventScript_Lass::
	msgbox KinIsland_PokemonCenter_1F_Text_AlwaysBerriesInBerryForest, MSGBOX_NPC
	end

KinIsland_PokemonCenter_1F_EventScript_Rocker::
	msgbox KinIsland_PokemonCenter_1F_Text_PCNetworkCanLinkWithKanto, MSGBOX_NPC
	end
KinIsland_PokemonCenter_1F_Text_PCNetworkCanLinkWithKanto::
    .string "Hey, did you hear the news?\p"
    .string "The PC network here can now link\n"
    .string "with PCs in KANTO.\p"
    .string "I don't know how that came about,\n"
    .string "but it's fantastic!$"

KinIsland_PokemonCenter_1F_Text_ImpossibleToSurfBetweenIslands::
    .string "It's impossible to SURF between the\n"
    .string "islands around these parts.\p"
    .string "The tides are too fast and\n"
    .string "treacherous.$"

KinIsland_PokemonCenter_1F_Text_AlwaysBerriesInBerryForest::
    .string "Let's crush BERRIES!\n"
    .string "…That'd be wasting BERRIES?\p"
    .string "You can always find some BERRIES\n"
    .string "on the ground in BERRY FOREST.$"

