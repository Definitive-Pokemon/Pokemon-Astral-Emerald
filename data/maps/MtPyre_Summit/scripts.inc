.set LOCALID_ARCHIE, 2
.set LOCALID_OLD_LADY, 3
.set LOCALID_AQUA_GRUNT_1, 4
.set LOCALID_AQUA_GRUNT_2, 5
.set LOCALID_MAXIE, 6
.set LOCALID_MATT, 7
.set LOCALID_POOCHYENA_1, 8
.set LOCALID_AQUA_GRUNT_3, 9
.set LOCALID_POOCHYENA_2, 10
.set LOCALID_MAGMA_GRUNT_1, 11
.set LOCALID_MAGMA_GRUNT_2, 12
.set LOCALID_POOCHYENA_3, 13
.set LOCALID_POOCHYENA_4, 14
.set LOCALID_POOCHYENA_5, 15
.set LOCALID_MAGMA_GRUNT_3, 16
.set LOCALID_POOCHYENA_6, 17
.set LOCALID_MAGMA_GRUNT_4, 18

MtPyre_Summit_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, EncounterTable
	map_script MAP_SCRIPT_ON_TRANSITION, MtPyre_Summit_OnTransition
	.byte 0

MtPyre_Summit_OnTransition:
	callnative ChangeEncounterTable
	call_if_eq VAR_MT_PYRE_STATE, 2, MtPyre_Summit_EventScript_SetArchieMaxiePositions
	call_if_unset FLAG_RECEIVED_RED_OR_BLUE_ORB, MtPyre_Summit_EventScript_UnhideGrunts
	end

MtPyre_Summit_EventScript_SetArchieMaxiePositions::
	setobjectxyperm LOCALID_MAXIE, 23, 6
	setobjectxyperm LOCALID_ARCHIE, 22, 6
	applymovement LOCALID_ARCHIE, Common_Movement_FaceUp
	applymovement LOCALID_MAXIE, Common_Movement_FaceUp
	waitmovement 0
	end

MtPyre_Summit_EventScript_UnhideGrunts::
	clearflag FLAG_HIDE_MT_PYRE_SUMMIT_MAXIE
	clearflag FLAG_HIDE_MT_PYRE_SUMMIT_TEAM_MAGMA
	clearflag FLAG_HIDE_MT_PYRE_SUMMIT_ARCHIE
	clearflag FLAG_HIDE_MT_PYRE_SUMMIT_TEAM_AQUA
	clearflag FLAG_HIDE_MT_PYRE_SUMMIT_MATT
	end

MtPyre_Summit_EventScript_TeamAquaTrigger0::
	lockall
	setvar VAR_0x8008, 0
	goto MtPyre_Summit_EventScript_TeamAquaExits
	end

MtPyre_Summit_EventScript_TeamAquaTrigger1::
	lockall
	setvar VAR_0x8008, 1
	goto MtPyre_Summit_EventScript_TeamAquaExits
	end

MtPyre_Summit_EventScript_TeamAquaTrigger2::
	lockall
	setvar VAR_0x8008, 2
	goto MtPyre_Summit_EventScript_TeamAquaExits
	end

MtPyre_Summit_EventScript_TeamAquaExits::
	special HasEnoughMonsForDoubleBattle
	goto_if_ne VAR_RESULT, PLAYER_HAS_TWO_USABLE_MONS, MtPyre_Summit_EventScript_ArchieSaysGoAway
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	msgbox MtPyre_Summit_Text_MaxieDangerousFolly, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieWalksRight
	waitmovement 0
	msgbox MtPyre_Summit_Text_ArchieDroughtsWillEnd, MSGBOX_DEFAULT
	msgbox MtPyre_Summit_Text_MaxieConsequences, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieWalksRight
	waitmovement 0
	msgbox MtPyre_Summit_Text_ArchieSelfRighteousness, MSGBOX_DEFAULT
	msgbox MtPyre_Summit_Text_MaxieLeaves, MSGBOX_DEFAULT
	closemessage
	setvar VAR_LAST_TALKED, LOCALID_MAXIE
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_MAXIE
	removeobject LOCALID_MAGMA_GRUNT_1
	removeobject LOCALID_MAGMA_GRUNT_2
	removeobject LOCALID_MAGMA_GRUNT_3
	removeobject LOCALID_MAGMA_GRUNT_4
	removeobject LOCALID_POOCHYENA_1
	removeobject LOCALID_POOCHYENA_2
	removeobject LOCALID_POOCHYENA_3
	removeobject LOCALID_POOCHYENA_4
	removeobject LOCALID_POOCHYENA_5
	removeobject LOCALID_POOCHYENA_6
	fadedefaultbgm
	fadescreen FADE_FROM_BLACK
	delay 20
	msgbox MtPyre_Summit_Text_ArchieKyogreWillAwaken, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ARCHIE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 50
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_ArchieFacePlayer0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_ArchieFacePlayer1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_ArchieFacePlayer2
	msgbox MtPyre_Summit_Text_ArchieBumpsIntoPlayer, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MATT, MtPyre_Summit_Movement_MattWalksToPlayer
	waitmovement 0
	setvar VAR_0x8004, SPECIAL_BATTLE_ARCHIE_AND_MATT
	setvar VAR_0x8005, 0
	special DoSpecialTrainerBattle
	waitstate
	switch VAR_RESULT
	case 1, MtPyre_Summit_EventScript_TeamAquaExits2
	fadescreen FADE_TO_BLACK
	special SetCB2WhiteOut
	waitstate
	releaseall
	end

MtPyre_Summit_EventScript_ArchieTrainer::
	trainerbattle TRAINER_BATTLE_SET_TRAINER_A, TRAINER_ARCHIE_MT_PYRE, 0, MossdeepCity_Gym_Text_ArchieDefeat, MossdeepCity_Gym_Text_ArchieDefeat
	end

MtPyre_Summit_EventScript_MattTrainer::
	trainerbattle TRAINER_BATTLE_SET_TRAINER_B, TRAINER_MATT_MT_PYRE, 0, MossdeepCity_Gym_Text_MattDefeat, MossdeepCity_Gym_Text_MattDefeat
	end

MtPyre_Summit_EventScript_TeamAquaExits2::
	msgbox MtPyre_Summit_Text_ArchieWeGotTheOrbLetsGo, MSGBOX_DEFAULT
	closemessage
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_ARCHIE
	removeobject LOCALID_AQUA_GRUNT_1
	removeobject LOCALID_AQUA_GRUNT_2
	removeobject LOCALID_AQUA_GRUNT_3
	removeobject LOCALID_MATT
	setflag FLAG_HIDE_MT_PYRE_SUMMIT_ARCHIE
	setflag FLAG_HIDE_MT_PYRE_SUMMIT_TEAM_AQUA
	setflag FLAG_HIDE_MT_PYRE_SUMMIT_MATT
	setflag FLAG_HIDE_MT_PYRE_SUMMIT_MAXIE
	setflag FLAG_HIDE_MT_PYRE_SUMMIT_TEAM_MAGMA
	fadedefaultbgm
	fadescreenswapbuffers FADE_FROM_BLACK
	delay 20
	setvar VAR_MT_PYRE_STATE, 1
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_OldLadyApproachPlayer0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_OldLadyApproachPlayer1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_OldLadyApproachPlayer2
	msgbox MtPyre_Summit_Text_BothOrbsTakenMagmaLeftThis, MSGBOX_DEFAULT
	giveitem ITEM_MAGMA_EMBLEM
	setflag FLAG_RECEIVED_RED_OR_BLUE_ORB
	setflag FLAG_HIDE_JAGGED_PASS_MAGMA_GUARD
	releaseall
	end

MtPyre_Summit_EventScript_ArchieSaysGoAway::
	msgbox MtPyre_Summit_Text_ArchieSaysGoAway, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerWalksAway
	waitmovement 0
	releaseall
	end

MtPyre_Summit_Movement_ArchieWalksRight:
	walk_right
	step_end

MtPyre_Summit_Movement_PlayerWalksAway:
	walk_down
	step_end

MtPyre_Summit_EventScript_ArchieFacePlayer0::
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieFacePlayer0
	applymovement LOCALID_MATT, MtPyre_Summit_Movement_MattFacePlayer0
	waitmovement 0
	return

@ Archie is already facing player
MtPyre_Summit_EventScript_ArchieFacePlayer1::
	return

MtPyre_Summit_EventScript_ArchieFacePlayer2::
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieFacePlayer2
	applymovement LOCALID_MATT, MtPyre_Summit_Movement_MattFacePlayer2
	waitmovement 0
	return

MtPyre_Summit_EventScript_OldLadyApproachPlayer0::
	applymovement LOCALID_OLD_LADY, MtPyre_Summit_Movement_OldLadyApproachPlayer0
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

MtPyre_Summit_EventScript_OldLadyApproachPlayer1::
	applymovement LOCALID_OLD_LADY, MtPyre_Summit_Movement_OldLadyApproachPlayer1
	waitmovement 0
	return

MtPyre_Summit_EventScript_OldLadyApproachPlayer2::
	applymovement LOCALID_OLD_LADY, MtPyre_Summit_Movement_OldLadyApproachPlayer2
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

MtPyre_Summit_Movement_OldLadyApproachPlayer0:
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

MtPyre_Summit_Movement_OldLadyApproachPlayer1:
	walk_down
	step_end

MtPyre_Summit_Movement_OldLadyApproachPlayer2:
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

MtPyre_Summit_Movement_ArchieFacePlayer0:
	walk_left
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_ArchieFacePlayer2:
	walk_right
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_MattFacePlayer0:
	walk_left
	step_end

MtPyre_Summit_Movement_MattFacePlayer2:
	walk_right
	step_end

MtPyre_Summit_Movement_MattWalksToPlayer:
	walk_up
	walk_up
	walk_up
	step_end

MtPyre_Summit_EventScript_OldMan::
	lock
	faceplayer
	goto_if_set FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE, MtPyre_Summit_EventScript_OldManAfterRayquaza
	msgbox MtPyre_Summit_Text_WillYouHearOutMyTale, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, MtPyre_Summit_EventScript_OldManTale
	call_if_eq VAR_RESULT, NO, MtPyre_Summit_EventScript_DeclineOldManTale
	release
	end

MtPyre_Summit_EventScript_OldManAfterRayquaza::
	msgbox MtPyre_Summit_Text_HearTheNewLegendOfHoenn, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, MtPyre_Summit_EventScript_OldManNewTale
	call_if_eq VAR_RESULT, NO, MtPyre_Summit_EventScript_DeclineOldManTale
	release
	end

MtPyre_Summit_EventScript_OldManTale::
	msgbox MtPyre_Summit_Text_GroudonKyogreTale, MSGBOX_DEFAULT
	return

MtPyre_Summit_EventScript_DeclineOldManTale::
	msgbox MtPyre_Summit_Text_WellThatTooIsFine, MSGBOX_DEFAULT
	return

MtPyre_Summit_EventScript_OldManNewTale::
	msgbox MtPyre_Summit_Text_HoennTrioTale, MSGBOX_DEFAULT
	return

MtPyre_Summit_EventScript_OldLady::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_RED_OR_BLUE_ORB, MtPyre_Summit_EventScript_OldLadyAfterOrbsReturned
	call_if_ge VAR_MT_PYRE_STATE, 3, MtPyre_Summit_EventScript_OldLadyOrbsReturned
	goto_if_set FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, MtPyre_Summit_EventScript_OldLadyLegendariesAwake
	msgbox MtPyre_Summit_Text_OrbsHaveBeenTaken, MSGBOX_DEFAULT
	release
	end

MtPyre_Summit_EventScript_OldLadyOrbsReturned::
	msgbox MtPyre_Summit_Text_ThoseTwoMenReturnedOrbs, MSGBOX_DEFAULT
	setflag FLAG_RETURNED_RED_OR_BLUE_ORB
	release
	end

MtPyre_Summit_EventScript_OldLadyLegendariesAwake::
	msgbox MtPyre_Summit_Text_GroudonKyogreAwakened, MSGBOX_DEFAULT
	release
	end

MtPyre_Summit_EventScript_OldLadyAfterOrbsReturned::
	msgbox MtPyre_Summit_Text_SuperAncientPokemonTaughtUs, MSGBOX_DEFAULT
	release
	end

MtPyre_Summit_EventScript_ArchieMaxieTrigger0::
	lockall
	setvar VAR_0x8008, 0
	goto MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs
	end

MtPyre_Summit_EventScript_ArchieMaxieTrigger1::
	lockall
	setvar VAR_0x8008, 1
	goto MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs
	end

MtPyre_Summit_EventScript_ArchieMaxieTrigger2::
	lockall
	setvar VAR_0x8008, 2
	goto MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs
	end

MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 60
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_ArchieMaxieBeginExit0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_ArchieMaxieBeginExit1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_ArchieMaxieBeginExit2
	playse SE_PIN
	applymovement LOCALID_MAXIE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MAXIE, Common_Movement_Delay48
	waitmovement 0
	delay 30
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_MaxieApproachPlayer0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_MaxieApproachPlayer1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_MaxieApproachPlayer2
	msgbox MtPyre_Summit_Text_MaxieSilence, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_MaxieApproachArchie0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_MaxieApproachArchie1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_MaxieApproachArchie2
	delay 30
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	removeobject LOCALID_ARCHIE
	removeobject LOCALID_MAXIE
	setvar VAR_MT_PYRE_STATE, 3
	releaseall
	end

MtPyre_Summit_EventScript_ArchieMaxieBeginExit0::
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit0
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	return

MtPyre_Summit_EventScript_ArchieMaxieBeginExit1::
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit1
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	return

MtPyre_Summit_EventScript_ArchieMaxieBeginExit2::
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit2
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachPlayer0::
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerFaceMaxie0
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieWatchMaxie
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieApproachPlayer0
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachPlayer1::
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerFaceMaxie
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieWatchMaxie
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieApproachPlayer1
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachPlayer2::
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerFaceMaxie
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieWatchMaxie
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieApproachPlayer2
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachArchie0::
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerWatchMaxie
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieApproachArchie0
	waitmovement 0
	applymovement LOCALID_ARCHIE, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachArchie1::
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerWatchMaxie
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieApproachArchie1
	waitmovement 0
	applymovement LOCALID_ARCHIE, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachArchie2::
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerWatchMaxie
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieApproachArchie2
	waitmovement 0
	applymovement LOCALID_ARCHIE, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

MtPyre_Summit_Movement_PlayerFaceMaxie0:
	delay_16
	delay_16
	walk_in_place_faster_right
	step_end

MtPyre_Summit_Movement_PlayerFaceMaxie:
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

MtPyre_Summit_Movement_ArchieExit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtPyre_Summit_Movement_MaxieExit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit0:
	delay_16
	delay_8
	walk_left
	walk_in_place_faster_right
	delay_16
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit1:
	delay_16
	delay_8
	walk_right
	walk_in_place_faster_left
	delay_16
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit2:
	delay_16
	delay_8
	walk_in_place_faster_left
	delay_16
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_MaxieApproachPlayer0:
	walk_up
	walk_up
	walk_up
	walk_left
	step_end

MtPyre_Summit_Movement_MaxieApproachPlayer1:
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_right
	step_end

MtPyre_Summit_Movement_MaxieApproachPlayer2:
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_right
	step_end

MtPyre_Summit_Movement_ArchieWatchMaxie:
	delay_16
	walk_in_place_faster_up
	step_end

MtPyre_Summit_Movement_PlayerWatchMaxie:
	delay_16
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_MaxieApproachArchie0:
	walk_down
	walk_right
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

MtPyre_Summit_Movement_MaxieApproachArchie1:
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

MtPyre_Summit_Movement_MaxieApproachArchie2:
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

MtPyre_Summit_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_1, MtPyre_Summit_Text_Grunt1Intro, MtPyre_Summit_Text_Grunt1Defeat
	msgbox MtPyre_Summit_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_2, MtPyre_Summit_Text_Grunt2Intro, MtPyre_Summit_Text_Grunt2Defeat
	msgbox MtPyre_Summit_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_3, MtPyre_Summit_Text_Grunt3Intro, MtPyre_Summit_Text_Grunt3Defeat
	msgbox MtPyre_Summit_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_4, MtPyre_Summit_Text_Grunt4Intro, MtPyre_Summit_Text_Grunt4Defeat
	msgbox MtPyre_Summit_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_EventScript_BusyAquaGrunt::
	msgbox MtPyre_Summit_Text_Grunt3Defeat, MSGBOX_SIGN
	end

MtPyre_Summit_EventScript_BusyMagmaGrunt1::
	msgbox MtPyre_Summit_Text_BusyMagmaGrunt1, MSGBOX_SIGN
	end

MtPyre_Summit_EventScript_BusyMagmaGrunt2::
	msgbox MtPyre_Summit_Text_BusyMagmaGrunt2, MSGBOX_SIGN
	end

MtPyre_Summit_EventScript_BusyMagmaGrunt3::
	msgbox MtPyre_Summit_Text_BusyMagmaGrunt3, MSGBOX_SIGN
	end

MtPyre_Summit_EventScript_BusyAquaGrunt1::
	msgbox MtPyre_Summit_Text_BusyAquaGrunt1, MSGBOX_SIGN
	end

MtPyre_Summit_EventScript_BusyAquaGrunt2::
	msgbox MtPyre_Summit_Text_BusyAquaGrunt2, MSGBOX_SIGN
	end

MtPyre_Summit_Text_BusyMagmaGrunt1:
	.string "We're in the middle of a crucial mission!\p"
	.string "Can't you see Team Aqua is trying to\n"
	.string "stop us?$"

MtPyre_Summit_Text_BusyMagmaGrunt2: 
	.string "The Red Orb will be ours!\n"
	.string "No time to waste on you!$"

MtPyre_Summit_Text_BusyMagmaGrunt3: 
	.string "Out of our way! The expansion of land\n"
	.string "depends on this moment!$"

MtPyre_Summit_Text_BusyAquaGrunt1: 
	.string "Step aside! We have to get the Blue Orb\n"
	.string "before Team Magma does!$"

MtPyre_Summit_Text_BusyAquaGrunt2:
	.string "Can't talk now! The fate of the world is\n"
	.string "at stake!$"

MtPyre_Summit_Text_Grunt1Intro:
	.string "Team Aqua?! They're trying to get\n"
	.string "ahead of us!\p"
	.string "I won’t let them take the Orb!$"

MtPyre_Summit_Text_Grunt1Defeat:
	.string "Ugh… I thought you were just another\n"
	.string "Team Aqua goon…$"

MtPyre_Summit_Text_Grunt1PostBattle:
	.string "Yeah, you’re tough…\n"
	.string "But Team Magma won’t give up!$"

MtPyre_Summit_Text_Grunt2Intro:
	.string "You’re caught in the middle now!\n"
	.string "We’ll take that Orb before Magma does!$"

MtPyre_Summit_Text_Grunt2Defeat:
	.string "I should’ve let Team Magma wear you\n"
	.string "down first…$"

MtPyre_Summit_Text_Grunt2PostBattle:
	.string "You don't know anything!\n"
	.string "So why are you messing with us?$"

MtPyre_Summit_Text_Grunt3Intro:
	.string "You…\n"
	.string "We saw you at Mt. Chimney.\p"
	.string "You don't belong to either Team,\n"
	.string "so why would you be here?$"

MtPyre_Summit_Text_Grunt3Defeat:
	.string "If you're going to mess with anyone,\n"
	.string "let it be Team Magma…$"

MtPyre_Summit_Text_Grunt3PostBattle:
	.string "Heh, it doesn't matter!\n"
	.string "We bought ourselves some time!\p"
	.string "The Boss should have snatched what\n"
	.string "he was after!$"

MtPyre_Summit_Text_Grunt4Intro:
	.string "Oh, I know!\n"
	.string "You tried to join Team Magma,\l"
	.string "but they wouldn't have you!\p"
	.string "Well, don't think that we'll let you\n"
	.string "join our Team Aqua!$"

MtPyre_Summit_Text_Grunt4Defeat:
	.string "If you want to join Team Aqua that\n"
	.string "badly, we can consider it…$"

MtPyre_Summit_Text_Grunt4PostBattle:
	.string "We have a great combination going\n"
	.string "with us members and our leader.$"

MtPyre_Summit_Text_ArchieSaysGoAway:
	.string "Archie: Hmph, you again?\p"
	.string "You think you can stand in my way\n"
	.string "with just one Pokémon?\p"
	.string "This isn't some child's game, kid.\n"
	.string "Go home before you get hurt.$"

MtPyre_Summit_Text_MaxieDangerousFolly:
	.string "Maxie: Hmph! Still clinging to your\n"
	.string "naive ideals, Archie?\p"
	.string "Your pursuit of Kyogre will only bring\n"
	.string "devastation.\p"
	.string "With the Red Orb in my possession,\n"
	.string "Groudon will awaken and bring true\l"
	.string "balance.\p"
	.string "Think of the farmland we could\n"
	.string "reclaim.\p"
	.string "Farmland that could feed millions!\p"
	.string "Your shortsightedness blinds you,\n"
	.string "Archie.$"

MtPyre_Summit_Text_ArchieDroughtsWillEnd:
	.string "Archie: You're the one who's blind,\n"
	.string "Maxie! Kyogre is the key to healing\l"
	.string "this world!\p"
	.string "The Blue Orb will awaken it, and the\n"
	.string "droughts will end!\p"
	.string "Water will revive barren lands, quenching\n"
	.string "the thirst of countless lives!$"

MtPyre_Summit_Text_MaxieConsequences:
	.string "Maxie: You fail to comprehend the\n"
	.string "consequences of your actions.\p"
	.string "Awakening Kyogre will bring ruin.\p"
	.string "Only Groudon can reclaim the land and\n"
	.string "secure prosperity.\p"
	.string "You would drown the world in chaos!$"

MtPyre_Summit_Text_ArchieSelfRighteousness:
	.string "Archie: Enough of your self\n"
	.string "righteousness!\p"
	.string "The world needs water to survive!\p"
	.string "With Kyogre's help, deserts will bloom\n"
	.string "and famine will end!\p"
	.string "You can't see that because you're\n"
	.string "blinded by your obsession with land!$"

MtPyre_Summit_Text_MaxieLeaves:
	.string "Maxie: I've indulged your ignorance\n"
	.string "long enough. There's no reasoning with\l"
	.string "someone so deluded.\p"
	.string "I have work to do… real work.\n"
	.string "Farewell, Archie.$"

MtPyre_Summit_Text_ArchieKyogreWillAwaken:
	.string "Archie: Maxie! Curse him!\n"
	.string "He refuses to see reason.\p"
	.string "No matter. With the Blue Orb, Kyogre\n"
	.string "will awaken, and I'll prove him wrong!\p"
	.string "Time is of the essence… I must act\n"
	.string "quickly.$"

MtPyre_Summit_Text_ArchieBumpsIntoPlayer:
	.string "Archie: You?!\n"
	.string "I can't afford any delays now!\p"
	.string "Every second counts in awakening\n"
	.string "Kyogre.\p"
	.string "If you're here to interfere, we'll have\n"
	.string "to deal with you swiftly!\p"
	.string "Prepare yourself!$"

MossdeepCity_Gym_Text_ArchieDefeat:
	.string "Archie: Tch… Don’t think this changes\n"
	.string "anything! We’ll still awaken Kyogre!$"

MossdeepCity_Gym_Text_MattDefeat:
	.string "Matt: So you think you've won? This\n"
	.string "changes nothing! Kyogre will be ours!$"

MtPyre_Summit_Text_ArchieWeGotTheOrbLetsGo:
	.string "Archie: Team Magma's Maxie got ahead\n"
	.string "of us, but we also got what we wanted.\p"
	.string "The Red Orb preserved at Mt. Pyre…\n"
	.string "I, Archie, now have it in my possession!\p"
	.string "Fufufu… Now we can bring our ultimate\n"
	.string "objective to fruition!\p"
	.string "Okay, Team!\n"
	.string "We're pulling out!$"

MtPyre_Summit_Text_BothOrbsTakenMagmaLeftThis:
	.string "Oh, no…\n"
	.string "This cannot happen…\p"
	.string "Not only the Red Orb, but even\n"
	.string "the Blue Orb has been taken…\p"
	.string "Those Orbs hold the key to\n"
	.string "keeping Kyogre and Groudon at peace.\p"
	.string "What are those men trying to do with\n"
	.string "the two Orbs?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Oh, yes. Was it Team Magma who left\n"
	.string "first?\p"
	.string "Well, in their haste, they left this\n"
	.string "behind.\p"
	.string "I couldn't imagine what exactly it\n"
	.string "could be.\p"
	.string "I would like you to have it.\n"
	.string "Perhaps it will be useful in some way.$"

MtPyre_Summit_Text_OrbsHaveBeenTaken:
	.string "The Blue Orb and Red Orb taken by\n"
	.string "those people…\p"
	.string "They must not be misused…\n"
	.string "I fear something terrible will happen…$"

MtPyre_Summit_Text_GroudonKyogreAwakened:
	.string "Oh, my goodness…\p"
	.string "You say that both Groudon and Kyogre\n"
	.string "have been awakened?\p"
	.string "It is said that the Blue Orb and\n"
	.string "the Red Orb quelled the rage of\l"
	.string "the two Pokémon…\p"
	.string "It is also said that the true owner\n"
	.string "of the Orbs still exists.\p"
	.string "However, no one knows who, or what\n"
	.string "exactly, the Orbs belong to.\p"
	.string "It could be a human, or perhaps\n"
	.string "a Pokémon, but no one knows.$"

MtPyre_Summit_Text_ThoseTwoMenReturnedOrbs:
	.string "The two men who took the Orbs came\n"
	.string "back to return them on their own.\p"
	.string "Those men…\n"
	.string "Perhaps they are not so evil after all…$"

MtPyre_Summit_Text_SuperAncientPokemonTaughtUs:
	.string "The embodiments of the land, sea,\n"
	.string "and the sky…\p"
	.string "That is said to be the identities of\n"
	.string "the super-ancient Pokémon…\p"
	.string "In the same way that we humans and\n"
	.string "Pokémon have life, our world, too,\l"
	.string "is alive…\p"
	.string "The super-ancient Pokémon have\n"
	.string "taught us that…$"

MtPyre_Summit_Text_WillYouHearOutMyTale:
	.string "Mt. Pyre is where we calm the spirits\n"
	.string "of Pokémon that have passed on…\p"
	.string "This is a high place where one can\n"
	.string "see all of Hoenn…\p"
	.string "The disembodied spirits of Pokémon\n"
	.string "must find solace here…\p"
	.string "Is it coincidence that you are here…\p"
	.string "Will you hear out my tale? A tale long\n"
	.string "told in the Hoenn region?$"

MtPyre_Summit_Text_GroudonKyogreTale:
	.string "It happened long, long ago…\p"
	.string "The world was wracked by a ferocious\n"
	.string "clash between the Pokémon of the land\l"
	.string "and the Pokémon of the sea…\p"
	.string "The Pokémon of the land raised\n"
	.string "mountains and created continents…\p"
	.string "The Pokémon of the sea raised huge\n"
	.string "waves and carved out oceans…\p"
	.string "Their fierce duel raged without end.\p"
	.string "The world was engulfed in massive\n"
	.string "infernos and vicious storms.\p"
	.string "The Blue Orb and the Red Orb brought\n"
	.string "an end to the calamity.\p"
	.string "Light poured from the two Orbs and\n"
	.string "becalmed the enraged adversaries.\p"
	.string "The pair, made docile, dove deep into\n"
	.string "the sea where eventually they\l"
	.string "disappeared…$"

MtPyre_Summit_Text_WellThatTooIsFine:
	.string "I see…\n"
	.string "Well, that, too, is fine…$"

MtPyre_Summit_Text_MaxieSilence:
	.string "Maxie: {PLAYER}…\p"
	.string "… … … … … …\n"
	.string "… … … … … …$"

MtPyre_Summit_Text_HearTheNewLegendOfHoenn:
	.string "It is my role to pass on the legends\n"
	.string "of Hoenn to future generations.\p"
	.string "And the crisis that just ended in\n"
	.string "Sootopolis rewrote a legend…\p"
	.string "Have you the time to hear the new\n"
	.string "legend of Hoenn?$"

MtPyre_Summit_Text_HoennTrioTale:
	.string "It happened long, long ago…\p"
	.string "The world was wracked by a ferocious\n"
	.string "clash between the Pokémon of the land\l"
	.string "and the Pokémon of the sea…\p"
	.string "The Pokémon of the land raised\n"
	.string "mountains and created continents…\p"
	.string "The Pokémon of the sea raised huge\n"
	.string "waves and carved out oceans…\p"
	.string "Their fierce duel raged without end.\p"
	.string "The world was engulfed in massive\n"
	.string "fires and vicious storms.\p"
	.string "It was then that the Pokémon of\n"
	.string "the sky descended from a storm.\p"
	.string "The Pokémon, shining a vivid green,\n"
	.string "becalmed the two enraged Pokémon.\p"
	.string "Then, its duty done, the green Pokémon\n"
	.string "flew off into the wild blue yonder…$"
