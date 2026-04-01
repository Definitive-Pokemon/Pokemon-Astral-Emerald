BoonIsland_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, BoonIsland_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

BoonIsland_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_BOON_ISLAND
	end

BoonIsland_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	call Common_EventScript_PkmnCenterNurse
	release
	end

BoonIsland_PokemonCenter_1F_EventScript_GBAKid::
	msgbox BoonIsland_PokemonCenter_1F_Text_HaveYouVisitedGameCorner, MSGBOX_NPC
	end

BoonIsland_PokemonCenter_1F_EventScript_BugCatcher::
	msgbox BoonIsland_PokemonCenter_1F_Text_OldLadyLivesOutOnCape, MSGBOX_NPC
	end
BoonIsland_PokemonCenter_1F_Text_HaveYouVisitedGameCorner::
    .string "Have you visited the GAME CORNER\n"
    .string "already?\p"
    .string "It's no good to go alone.\n"
    .string "You have to take a friend along.$"

BoonIsland_PokemonCenter_1F_Text_OldLadyLivesOutOnCape::
    .string "Not many people live on\n"
    .string "TWO ISLAND.\p"
    .string "There is this old lady who lives\n"
    .string "out on the cape.\p"
    .string "She's been there since I don't know\n"
    .string "when.$"

