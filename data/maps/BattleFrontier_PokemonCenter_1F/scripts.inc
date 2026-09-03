.set LOCALID_NURSE, 1

BattleFrontier_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

BattleFrontier_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_BATTLE_FRONTIER_OUTSIDE_EAST
	end

BattleFrontier_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_PokemonCenter_1F_EventScript_SchoolKid::
	lock
	faceplayer
	goto_if_set FLAG_FRONTIER_SEEDOT_NPC_TRADE_COMPLETED, BattleFrontier_PokemonCenter_1F_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_SEEDOT
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox BattleFrontier_PokemonCenter_1F_Text_IllTradeIfYouWant, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_PokemonCenter_1F_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_PokemonCenter_1F_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, BattleFrontier_PokemonCenter_1F_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	msgbox BattleFrontier_PokemonCenter_1F_Text_PleaseBeGoodToMyPokemon, MSGBOX_DEFAULT
	setflag FLAG_FRONTIER_SEEDOT_NPC_TRADE_COMPLETED
	release
	end

BattleFrontier_PokemonCenter_1F_EventScript_DeclineTrade::
	msgbox BattleFrontier_PokemonCenter_1F_Text_YouDontWantToThatsOkay, MSGBOX_DEFAULT
	release
	end

BattleFrontier_PokemonCenter_1F_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox BattleFrontier_PokemonCenter_1F_Text_DoesntLookLikeMonToMe, MSGBOX_DEFAULT
	release
	end

BattleFrontier_PokemonCenter_1F_EventScript_TradeCompleted::
	msgbox BattleFrontier_PokemonCenter_1F_Text_AnyPokemonCanBeCute, MSGBOX_DEFAULT
	release
	end


BattleFrontier_PokemonCenter_1F_EventScript_DisableChallenges::
	lock
	msgbox BattleFrontier_PokemonCenter_1F_Text_DisableChallenges, MSGBOX_NPC
	dynmultichoice 0, 0, FALSE, 5, 0, DYN_MULTICHOICE_CB_NONE, EventScript_MultichoiceDisableChallenge_Text_Challenge_EvoLimit, EventScript_MultichoiceDisableChallenge_Text_Challenge_Mirror, EventScript_MultichoiceDisableChallenge_Text_Challenge_MirrorThief, EventScript_MultichoiceDisableChallenge_Text_Challenge_Expensive, EventScript_MultichoiceDisableChallenge_Text_Challenge_OneType, EventScript_MultichoiceDisableChallenge_Text_Challenge_PartyLimit, EventScript_MultichoiceDisableChallenge_Text_Challenge_NoItemPlayer, EventScript_MultichoiceDisableChallenge_Text_Challenge_NoItemTrainer, EventScript_MultichoiceDisableChallenge_Text_Challenge_PokecenterChal
	switch VAR_RESULT
	case 0, BattleFrontier_PokemonCenter_1F_EventScript_DisableChallenges_EvoLimit_Ask
	case 1, BattleFrontier_PokemonCenter_1F_EventScript_DisableChallenges_Mirror_Ask
	case 2, BattleFrontier_PokemonCenter_1F_EventScript_DisableChallenges_MirrorThief_Ask
	case 3, BattleFrontier_PokemonCenter_1F_EventScript_DisableChallenges_Expensive_Ask
	case 4, BattleFrontier_PokemonCenter_1F_EventScript_DisableChallenges_OneType_Ask
	case 5, BattleFrontier_PokemonCenter_1F_EventScript_DisableChallenges_PartyLimit_Ask
	case 6, BattleFrontier_PokemonCenter_1F_EventScript_DisableChallenges_NoItemPlayer_Ask
	case 7, BattleFrontier_PokemonCenter_1F_EventScript_DisableChallenges_NoItemTrainer_Ask
	case 8, BattleFrontier_PokemonCenter_1F_EventScript_DisableChallenges_PokecenterChal_Ask
	closemessage
	release
	end

BattleFrontier_PokemonCenter_1F_Text_DisableChallenges:
	.string "Congratulations for beating the game!\p"
	.string "You can now disable some challenges,\n"
	.string "if you feel like it.\p"
	.string "Keep in mind that you won't be able to\n"
	.string "enable them again.\p"
	.string "Also, if any of the challenges are not\n"
	.string "enabled, nothing will happen if you try\l"
	.string "to disable them.$"

BattleFrontier_PokemonCenter_1F_Text_Done:
	.string "Done!$"

@evo limit
BattleFrontier_PokemonCenter_1F_EventScript_DisableChallenges_EvoLimit_Ask:
	msgbox EventScript_MultichoiceDisableChallenge_Text_Challenge_EvoLimit_Disable, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, BattleFrontier_PokemonCenter_1F_EventScript_DisableChallenges_EvoLimit
	case NO, Debug_Script_1_Closemessage
	case MULTI_B_PRESSED, Debug_Script_1_Closemessage
	end

BattleFrontier_PokemonCenter_1F_EventScript_DisableChallenges_EvoLimit:
	callnative DisableChallengesAfterBeatingGameEvoLimit
	msgbox BattleFrontier_PokemonCenter_1F_Text_Done, MSGBOX_NPC
	closemessage
	release
	end

EventScript_MultichoiceDisableChallenge_Text_Challenge_EvoLimit:
	.string "Evolution Limit$"

EventScript_MultichoiceDisableChallenge_Text_Challenge_EvoLimit_Disable:
	.string "Disable Evolution Limit?$"

@mirror
BattleFrontier_PokemonCenter_1F_EventScript_DisableChallenges_Mirror_Ask:
	msgbox EventScript_MultichoiceDisableChallenge_Text_Challenge_Mirror_Disable, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, BattleFrontier_PokemonCenter_1F_EventScript_DisableChallenges_Mirror
	case NO, Debug_Script_1_Closemessage
	case MULTI_B_PRESSED, Debug_Script_1_Closemessage
	end

BattleFrontier_PokemonCenter_1F_EventScript_DisableChallenges_Mirror:
	callnative DisableChallengesAfterBeatingGameMirror
	msgbox BattleFrontier_PokemonCenter_1F_Text_Done, MSGBOX_NPC
	closemessage
	release
	end

EventScript_MultichoiceDisableChallenge_Text_Challenge_Mirror:
	.string "Mirror$"

EventScript_MultichoiceDisableChallenge_Text_Challenge_Mirror_Disable:
	.string "Disable Mirror challenge?$"

@mirror thief
BattleFrontier_PokemonCenter_1F_EventScript_DisableChallenges_MirrorThief_Ask:
	msgbox EventScript_MultichoiceDisableChallenge_Text_Challenge_MirrorThief_Disable, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, BattleFrontier_PokemonCenter_1F_EventScript_DisableChallenges_MirrorThief
	case NO, Debug_Script_1_Closemessage
	case MULTI_B_PRESSED, Debug_Script_1_Closemessage
	end

BattleFrontier_PokemonCenter_1F_EventScript_DisableChallenges_MirrorThief:
	callnative DisableChallengesAfterBeatingGameMirrorThief
	msgbox BattleFrontier_PokemonCenter_1F_Text_Done, MSGBOX_NPC
	closemessage
	release
	end

EventScript_MultichoiceDisableChallenge_Text_Challenge_MirrorThief:
	.string "Mirror Thief$"

EventScript_MultichoiceDisableChallenge_Text_Challenge_MirrorThief_Disable:
	.string "Disable Mirror Thief challenge?$"

@Expensive Challenge
BattleFrontier_PokemonCenter_1F_EventScript_DisableChallenges_Expensive_Ask:
	msgbox EventScript_MultichoiceDisableChallenge_Text_Challenge_Expensive_Disable, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, BattleFrontier_PokemonCenter_1F_EventScript_DisableChallenges_Expensive
	case NO, Debug_Script_1_Closemessage
	case MULTI_B_PRESSED, Debug_Script_1_Closemessage
	end

BattleFrontier_PokemonCenter_1F_EventScript_DisableChallenges_Expensive:
	callnative DisableChallengesAfterBeatingGameExpensiveChallenge
	msgbox BattleFrontier_PokemonCenter_1F_Text_Done, MSGBOX_NPC
	closemessage
	release
	end

EventScript_MultichoiceDisableChallenge_Text_Challenge_Expensive:
	.string "Ultra Expensive!$"

EventScript_MultichoiceDisableChallenge_Text_Challenge_Expensive_Disable:
	.string "Disable Ultra Expensive?$"

@one type
BattleFrontier_PokemonCenter_1F_EventScript_DisableChallenges_OneType_Ask:
	msgbox EventScript_MultichoiceDisableChallenge_Text_Challenge_OneType_Disable, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, BattleFrontier_PokemonCenter_1F_EventScript_DisableChallenges_OneType
	case NO, Debug_Script_1_Closemessage
	case MULTI_B_PRESSED, Debug_Script_1_Closemessage
	end

BattleFrontier_PokemonCenter_1F_EventScript_DisableChallenges_OneType:
	callnative DisableChallengesAfterBeatingGameOneType
	msgbox BattleFrontier_PokemonCenter_1F_Text_Done, MSGBOX_NPC
	closemessage
	release
	end

EventScript_MultichoiceDisableChallenge_Text_Challenge_OneType:
	.string "One Type Challenge$"

EventScript_MultichoiceDisableChallenge_Text_Challenge_OneType_Disable:
	.string "Disable One Type Challenge?$"

@party limit
BattleFrontier_PokemonCenter_1F_EventScript_DisableChallenges_PartyLimit_Ask:
	msgbox EventScript_MultichoiceDisableChallenge_Text_Challenge_PartyLimit_Disable, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, BattleFrontier_PokemonCenter_1F_EventScript_DisableChallenges_PartyLimit
	case NO, Debug_Script_1_Closemessage
	case MULTI_B_PRESSED, Debug_Script_1_Closemessage
	end

BattleFrontier_PokemonCenter_1F_EventScript_DisableChallenges_PartyLimit:
	callnative DisableChallengesAfterBeatingGamePartyLimit
	msgbox BattleFrontier_PokemonCenter_1F_Text_Done, MSGBOX_NPC
	closemessage
	release
	end

EventScript_MultichoiceDisableChallenge_Text_Challenge_PartyLimit:
	.string "Party Limit$"

EventScript_MultichoiceDisableChallenge_Text_Challenge_PartyLimit_Disable:
	.string "Disable Party Limit?$"

@no item player
BattleFrontier_PokemonCenter_1F_EventScript_DisableChallenges_NoItemPlayer_Ask:
	msgbox EventScript_MultichoiceDisableChallenge_Text_Challenge_NoItemPlayer_Disable, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, BattleFrontier_PokemonCenter_1F_EventScript_DisableChallenges_NoItemPlayer
	case NO, Debug_Script_1_Closemessage
	case MULTI_B_PRESSED, Debug_Script_1_Closemessage
	end

BattleFrontier_PokemonCenter_1F_EventScript_DisableChallenges_NoItemPlayer:
	callnative DisableChallengesAfterBeatingGameNoItemPlayer
	msgbox BattleFrontier_PokemonCenter_1F_Text_Done, MSGBOX_NPC
	closemessage
	release
	end

EventScript_MultichoiceDisableChallenge_Text_Challenge_NoItemPlayer:
	.string "No Item (Player)$"

EventScript_MultichoiceDisableChallenge_Text_Challenge_NoItemPlayer_Disable:
	.string "Disable No Item (Player)?$"

@no item TRAINER
BattleFrontier_PokemonCenter_1F_EventScript_DisableChallenges_NoItemTrainer_Ask:
	msgbox EventScript_MultichoiceDisableChallenge_Text_Challenge_NoItemTrainer_Disable, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, BattleFrontier_PokemonCenter_1F_EventScript_DisableChallenges_NoItemTrainer
	case NO, Debug_Script_1_Closemessage
	case MULTI_B_PRESSED, Debug_Script_1_Closemessage
	end

BattleFrontier_PokemonCenter_1F_EventScript_DisableChallenges_NoItemTrainer:
	callnative DisableChallengesAfterBeatingGameNoItemTrainer
	msgbox BattleFrontier_PokemonCenter_1F_Text_Done, MSGBOX_NPC
	closemessage
	release
	end

EventScript_MultichoiceDisableChallenge_Text_Challenge_NoItemTrainer:
	.string "No Item (Trainers)$"

EventScript_MultichoiceDisableChallenge_Text_Challenge_NoItemTrainer_Disable:
	.string "Disable No Item (Trainers)?$"

@pkcenter challenge
BattleFrontier_PokemonCenter_1F_EventScript_DisableChallenges_PokecenterChal_Ask:
	msgbox EventScript_MultichoiceDisableChallenge_Text_Challenge_PokecenterChal_Disable, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, BattleFrontier_PokemonCenter_1F_EventScript_DisableChallenges_PokecenterChal
	case NO, Debug_Script_1_Closemessage
	case MULTI_B_PRESSED, Debug_Script_1_Closemessage
	end

BattleFrontier_PokemonCenter_1F_EventScript_DisableChallenges_PokecenterChal:
	callnative DisableChallengesAfterBeatingGamePkmCenterChallenge
	msgbox BattleFrontier_PokemonCenter_1F_Text_Done, MSGBOX_NPC
	closemessage
	release
	end

EventScript_MultichoiceDisableChallenge_Text_Challenge_PokecenterChal:
	.string "Pokécenter Challenge$"

EventScript_MultichoiceDisableChallenge_Text_Challenge_PokecenterChal_Disable:
	.string "Disable Pokécenter Challenge?$"

BattleFrontier_PokemonCenter_1F_EventScript_Man::
	msgbox BattleFrontier_PokemonCenter_1F_Text_NextStopBattleArena, MSGBOX_NPC
	end

BattleFrontier_PokemonCenter_1F_EventScript_Picnicker::
	msgbox BattleFrontier_PokemonCenter_1F_Text_GoingThroughEveryChallenge, MSGBOX_NPC
	end

BattleFrontier_PokemonCenter_1F_EventScript_Skitty::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SKITTY, CRY_MODE_NORMAL
	msgbox BattleFrontier_PokemonCenter_1F_Text_Skitty, MSGBOX_DEFAULT
	waitmoncry
	release
	end
	
BattleFrontier_PokemonCenter_1F_Text_IllTradeIfYouWant:
	.string "There was someone here using a {STR_VAR_1},\n"
	.string "a Pokémon I've never seen before.\p"
	.string "I couldn't help but notice it was\n"
	.string "both rare and quite impressive.\p"
	.string "If you find one, I'm willing to\n"
	.string "trade you my {STR_VAR_2}.\p"
	.string "It may not be as rare, but I know\n"
	.string "my Pokémon is cute. Maybe you’ll\l"
	.string "find it worth the trade.$"

BattleFrontier_PokemonCenter_1F_Text_PleaseBeGoodToMyPokemon:
	.string "Eheheh…\n"
	.string "Please be good to my Pokémon.$"

BattleFrontier_PokemonCenter_1F_Text_DoesntLookLikeMonToMe:
	.string "Huh? That doesn't look anything like\n"
	.string "a {STR_VAR_1} to me.$"

BattleFrontier_PokemonCenter_1F_Text_YouDontWantToThatsOkay:
	.string "Oh, if you don't want to, that's okay.\n"
	.string "But my Pokémon is cute, you know…$"

BattleFrontier_PokemonCenter_1F_Text_AnyPokemonCanBeCute:
	.string "Any Pokémon can be cute if you raise\n"
	.string "it with care and kindness.$"

BattleFrontier_PokemonCenter_1F_Text_NextStopBattleArena:
	.string "Okay! Next stop, the Battle Arena!\n"
	.string "I'd better get the right Pokémon from\l"
	.string "the PC Storage System.$"

BattleFrontier_PokemonCenter_1F_Text_GoingThroughEveryChallenge:
	.string "Giggle… I'm going to go through every\n"
	.string "challenge with just this baby!$"

BattleFrontier_PokemonCenter_1F_Text_Skitty:
	.string "Skitty: Mya myaaah!$"
