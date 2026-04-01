.set LOCALID_RUIN_VALLEY_SCIENTIST, 1

FortuneIsland_RuinValley_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, FortuneIsland_RuinValley_OnLoad
	.byte 0

FortuneIsland_RuinValley_OnLoad::
	call_if_set FLAG_AE_USED_CUT_ON_RUIN_VALLEY_BRAILLE, FortuneIsland_RuinValley_EventScript_OpenDottedHoleDoor
	end

FortuneIsland_RuinValley_EventScript_OpenDottedHoleDoor::
	@setmetatile 24, 24, METATILE_SeviiIslands67_DottedHoleDoor_Open, 0
	return

FortuneIsland_RuinValley_EventScript_Scientist::
	lock
	msgbox FortuneIsland_RuinValley_Text_CantFigureOutHowToGetInside
	applymovement LOCALID_RUIN_VALLEY_SCIENTIST, Common_Movement_FacePlayer
	waitmovement 0
	msgbox FortuneIsland_RuinValley_Text_IFoundThisPlace
	applymovement LOCALID_RUIN_VALLEY_SCIENTIST, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

FortuneIsland_RuinValley_EventScript_DottedHoleDoor::
	lockall
	goto_if_set FLAG_AE_USED_CUT_ON_RUIN_VALLEY_BRAILLE, FortuneIsland_RuinValley_EventScript_DottedHoleDoorOpen
	msgbox FortuneIsland_RuinValley_Text_CheckDoorMoreThoroughly, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, FortuneIsland_RuinValley_EventScript_IgnoreDottedHoleDoor
	msgbox FortuneIsland_RuinValley_Text_SeveralDotsOnTheDoor
	@braillemessage Braille_Text_Cut
	waitbuttonpress
	releaseall
	end

FortuneIsland_RuinValley_EventScript_DottedHoleDoorOpen::
	msgbox FortuneIsland_RuinValley_Text_DoorIsOpen
	releaseall
	end

FortuneIsland_RuinValley_EventScript_IgnoreDottedHoleDoor::
	msgbox FortuneIsland_RuinValley_Text_LeftDoorAlone
	releaseall
	end

FortuneIsland_RuinValley_EventScript_Stanly::
	trainerbattle_single TRAINER_RUIN_MANIAC_STANLY, FortuneIsland_RuinValley_Text_StanlyIntro, FortuneIsland_RuinValley_Text_StanlyDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, FortuneIsland_RuinValley_EventScript_StanlyRematch
	msgbox FortuneIsland_RuinValley_Text_StanlyPostBattle, MSGBOX_AUTOCLOSE
	end

FortuneIsland_RuinValley_EventScript_StanlyRematch::
	trainerbattle_rematch TRAINER_CLIFFORD, FortuneIsland_RuinValley_Text_StanlyRematchIntro, FortuneIsland_RuinValley_Text_StanlyDefeat
	msgbox FortuneIsland_RuinValley_Text_StanlyPostBattle, MSGBOX_AUTOCLOSE
	end

FortuneIsland_RuinValley_EventScript_Foster::
	trainerbattle_single TRAINER_RUIN_MANIAC_FOSTER, FortuneIsland_RuinValley_Text_FosterIntro, FortuneIsland_RuinValley_Text_FosterDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, FortuneIsland_RuinValley_EventScript_FosterRematch
	msgbox FortuneIsland_RuinValley_Text_FosterPostBattle, MSGBOX_AUTOCLOSE
	end

FortuneIsland_RuinValley_EventScript_FosterRematch::
	trainerbattle_rematch TRAINER_CLIFFORD, FortuneIsland_RuinValley_Text_FosterRematchIntro, FortuneIsland_RuinValley_Text_FosterDefeat
	msgbox FortuneIsland_RuinValley_Text_FosterPostBattle, MSGBOX_AUTOCLOSE
	end

FortuneIsland_RuinValley_EventScript_Larry::
	trainerbattle_single TRAINER_RUIN_MANIAC_LARRY, FortuneIsland_RuinValley_Text_LarryIntro, FortuneIsland_RuinValley_Text_LarryDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, FortuneIsland_RuinValley_EventScript_LarryRematch
	msgbox FortuneIsland_RuinValley_Text_LarryPostBattle, MSGBOX_AUTOCLOSE
	end

FortuneIsland_RuinValley_EventScript_LarryRematch::
	trainerbattle_rematch TRAINER_CLIFFORD, FortuneIsland_RuinValley_Text_LarryRematchIntro, FortuneIsland_RuinValley_Text_LarryDefeat
	msgbox FortuneIsland_RuinValley_Text_LarryPostBattle, MSGBOX_AUTOCLOSE
	end

FortuneIsland_RuinValley_EventScript_Daryl::
	trainerbattle_single TRAINER_HIKER_DARYL, FortuneIsland_RuinValley_Text_DarylIntro, FortuneIsland_RuinValley_Text_DarylDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, FortuneIsland_RuinValley_EventScript_DarylRematch
	msgbox FortuneIsland_RuinValley_Text_DarylPostBattle, MSGBOX_AUTOCLOSE
	end

FortuneIsland_RuinValley_EventScript_DarylRematch::
	trainerbattle_rematch TRAINER_CLIFFORD, FortuneIsland_RuinValley_Text_DarylRematchIntro, FortuneIsland_RuinValley_Text_DarylDefeat
	msgbox FortuneIsland_RuinValley_Text_DarylPostBattle, MSGBOX_AUTOCLOSE
	end

FortuneIsland_RuinValley_EventScript_Hector::
	trainerbattle_single TRAINER_POKEMANIAC_HECTOR, FortuneIsland_RuinValley_Text_HectorIntro, FortuneIsland_RuinValley_Text_HectorDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, FortuneIsland_RuinValley_EventScript_HectorRematch
	msgbox FortuneIsland_RuinValley_Text_HectorPostBattle, MSGBOX_AUTOCLOSE
	end

FortuneIsland_RuinValley_EventScript_HectorRematch::
	trainerbattle_rematch TRAINER_CLIFFORD, FortuneIsland_RuinValley_Text_HectorRematchIntro, FortuneIsland_RuinValley_Text_HectorDefeat
	msgbox FortuneIsland_RuinValley_Text_HectorPostBattle, MSGBOX_AUTOCLOSE
	end

FortuneIsland_RuinValley_Text_StanlyRematchIntro::
	.string "There appear to be many secrets\n"
	.string "still unsolved in this world.$"

FortuneIsland_RuinValley_Text_FosterRematchIntro::
	.string "Hi, didn't we meet before?\n"
	.string "What compelled you to come back?$"

FortuneIsland_RuinValley_Text_LarryRematchIntro::
	.string "It's been said that there are\n"
	.string "mysterious stones on this island.\p"
	.string "Have you discovered anything since\n"
	.string "we last met?$"

FortuneIsland_RuinValley_Text_DarylRematchIntro::
	.string "A rematch with you, so high up!$"

FortuneIsland_RuinValley_Text_HectorRematchIntro::
	.string "I'm pretty familiar with the land\n"
	.string "around these parts.$"

FortuneIsland_RuinValley_Text_CantFigureOutHowToGetInside::
    .string "I can't figure out how I'm supposed\n"
    .string "to get inside.$"

FortuneIsland_RuinValley_Text_IFoundThisPlace::
    .string "Let me tell you, I found this\n"
    .string "place.\p"
    .string "Don't look so envious, will you?$"

FortuneIsland_RuinValley_Text_CheckDoorMoreThoroughly::
    .string "The door doesn't budge at all.\n"
    .string "Check it more thoroughly?$"

FortuneIsland_RuinValley_Text_LeftDoorAlone::
    .string "{PLAYER} left the door alone.$"

FortuneIsland_RuinValley_Text_SeveralDotsOnTheDoor::
    .string "On closer inspection, there are\n"
    .string "several dots on the door…$"

FortuneIsland_RuinValley_Text_DoorIsOpen::
    .string "The door is open.$"

FortuneIsland_RuinValley_Text_StanlyIntro::
    .string "There appear to be many secrets\n"
    .string "still unsolved in this world.$"

FortuneIsland_RuinValley_Text_StanlyDefeat::
    .string "Hmm…$"

FortuneIsland_RuinValley_Text_StanlyPostBattle::
    .string "I suggest to you that you, too,\n"
    .string "give a thought to the secrets and\l"
    .string "mysteries of our world once a day.$"

FortuneIsland_RuinValley_Text_FosterIntro::
    .string "I'm curious, what compelled you to\n"
    .string "come here?$"

FortuneIsland_RuinValley_Text_FosterDefeat::
    .string "It's been so long since I battled,\n"
    .string "my instincts are off.$"

FortuneIsland_RuinValley_Text_FosterPostBattle::
    .string "There are several ruins on the\n"
    .string "SEVII ISLANDS.\p"
    .string "The majority of them date back\n"
    .string "a long way.$"

FortuneIsland_RuinValley_Text_LarryIntro::
    .string "It's been said that there are\n"
    .string "mysterious stones on this island.\p"
    .string "I suspect it has something to do\n"
    .string "with the ruins here.$"

FortuneIsland_RuinValley_Text_LarryDefeat::
    .string "Oh, interesting.$"

FortuneIsland_RuinValley_Text_LarryPostBattle::
    .string "Those ruins over there…\p"
    .string "I haven't had any luck in finding\n"
    .string "how I can get inside.$"

FortuneIsland_RuinValley_Text_DarylIntro::
    .string "A battle with you, so high up!$"

FortuneIsland_RuinValley_Text_DarylDefeat::
    .string "Oh, the heartbreak of losing so\n"
    .string "easily to you!$"

FortuneIsland_RuinValley_Text_DarylPostBattle::
    .string "Experience the joy of climbing!$"

FortuneIsland_RuinValley_Text_HectorIntro::
    .string "I'm pretty familiar with the land\n"
    .string "around these parts.$"

FortuneIsland_RuinValley_Text_HectorDefeat::
    .string "You don't need to be so pushy.\n"
    .string "I'll be happy to tell you.$"

FortuneIsland_RuinValley_Text_HectorPostBattle::
    .string "The door to the ruins…\n"
    .string "It has these strange patterns\l"
    .string "engraved on the outside.\p"
    .string "I don't know what they mean,\n"
    .string "though.$"
