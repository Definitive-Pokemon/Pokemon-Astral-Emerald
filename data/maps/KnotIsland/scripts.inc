.equ LOCALID_BILL, 1

KnotIsland_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, KnotIsland_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, KnotIsland_OnFrameTable
	.byte 0

KnotIsland_OnTransition::
	setflag FLAG_VISITED_KNOT_ISLAND
	end
	
KnotIsland_OnFrameTable::
	map_script_2 VAR_KNOT_ISLAND_STATE, 0, KnotIsland_EventScript_EnterKnotIsland_FirstTime
	.2byte 0

KnotIsland_EventScript_EnterKnotIsland_FirstTime::
	lockall
	textcolor NPC_TEXT_COLOR_MALE
	applymovement LOCALID_PLAYER, KnotIsland_Movement_PlayerExitHarbor
	waitmovement 0
	msgbox KnotIsland_Text_BillLetsGoSeeCelio
	closemessage
	applymovement LOCALID_KNOT_ISLAND_BILL, KnotIsland_Movement_BillWalkToPokeCenter
	applymovement LOCALID_PLAYER, KnotIsland_Movement_PlayerWalkToPokeCenter
	waitmovement 0
	opendoor 14, 5
	waitdooranim
	applymovement LOCALID_KNOT_ISLAND_BILL, KnotIsland_Movement_BillEnterPokeCenter
	applymovement LOCALID_PLAYER, KnotIsland_Movement_PlayerEnterPokeCenter
	waitmovement 0
	closedoor 14, 5
	waitdooranim
	removeobject LOCALID_KNOT_ISLAND_BILL
	@setvar VAR_MAP_SCENE_KNOT_ISLAND_HARBOR, 3
	warp MAP_KNOT_ISLAND_POKEMON_CENTER_1F, 9, 9
	waitstate
	releaseall
	end

KnotIsland_Movement_PlayerExitHarbor::
	walk_up
	step_end

		.macro walk_to_pokecenter
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	.endm

KnotIsland_Movement_PlayerWalkToPokeCenter::
	walk_up
	walk_to_pokecenter
	step_end

KnotIsland_Movement_PlayerEnterPokeCenter::
	walk_up
	walk_up
	set_invisible
	step_end


KnotIsland_Movement_BillWalkToPokeCenter::
	walk_to_pokecenter
	walk_up
	step_end

KnotIsland_Movement_BillEnterPokeCenter::
	walk_up
	set_invisible
	step_end

KnotIsland_EventScript_OldMan::
	lock
	faceplayer
	@
	@ Alt text here for SEVII_DETOUR and RS_LINK!
	msgbox KnotIsland_Text_LuckyToHaveCelioHere
	release
	end

KnotIsland_EventScript_BaldingMan::
	msgbox KnotIsland_Text_IsntWarmClimateHereGreat, MSGBOX_NPC
	end

KnotIsland_EventScript_IslandSign::
	msgbox KnotIsland_Text_IslandSign, MSGBOX_SIGN
	end

KnotIsland_EventScript_PokemonNetCenterSign::
	msgbox KnotIsland_Text_PokemonNetCenterSign, MSGBOX_SIGN
	end
	
KnotIsland_Text_BillLetsGoSeeCelio::
    .string "BILL: Here we are!\n"
    .string "This is ONE ISLAND.\p"
    .string "There are several islands around\n"
    .string "here, and this is one of them.\p"
    .string "My friend CELIO sent the boat to\n"
    .string "fetch me here.\p"
    .string "He's in charge of the island's PC\n"
    .string "network by his lonesome.\p"
    .string "…Why am I telling you this now?\n"
    .string "Let's just go see CELIO!$"

KnotIsland_Text_LuckyToHaveCelioHere::
    .string "Here we are on an island smack in\n"
    .string "the middle of nowhere.\p"
    .string "We're lucky to have an upstanding\n"
    .string "young man like Celio here.\p"
    .string "My granddaughter was in a tizzy\n"
    .string "over Celio's friend.\p"
    .string "Something about a famous\n"
    .string "Pokémaniac?\p"
    .string "I'm not sure what that means, but\n"
    .string "Celio is quite the man!$"


KnotIsland_Text_IslandSign::
    .string "One Island\n"
    .string "Friends Gather at Knot Island$"

KnotIsland_Text_PokemonNetCenterSign::
    .string "Expanding the Pokémon World!\n"
    .string "Pokémon Net Center$"


KnotIsland_Text_IsntWarmClimateHereGreat::
    .string "Hi, sight-seeing, are you?\n"
    .string "Isn't the warm climate here great?$"

	
