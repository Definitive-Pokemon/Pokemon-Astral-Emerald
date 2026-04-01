ChronoIsland_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ChronoIsland_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

ChronoIsland_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_CHRONO_ISLAND
	end

ChronoIsland_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	call Common_EventScript_PkmnCenterNurse
	release
	end

ChronoIsland_PokemonCenter_1F_EventScript_Chef::
	msgbox ChronoIsland_PokemonCenter_1F_Text_OnMyWayToPrepareMeal, MSGBOX_NPC
	end

ChronoIsland_PokemonCenter_1F_EventScript_CooltrainerF::
	msgbox ChronoIsland_PokemonCenter_1F_Text_YoureOnQuestToCatchEveryMon, MSGBOX_NPC
	end
ChronoIsland_PokemonCenter_1F_Text_OnMyWayToPrepareMeal::
    .string "I'm on my way to prepare a meal\n"
    .string "for a certain high-society person.$"

ChronoIsland_PokemonCenter_1F_Text_YoureOnQuestToCatchEveryMon::
    .string "You're on a quest to catch every\n"
    .string "single kind of POKéMON?\p"
    .string "…How incredible. Please tell me if\n"
    .string "you catch a strong one!$"

