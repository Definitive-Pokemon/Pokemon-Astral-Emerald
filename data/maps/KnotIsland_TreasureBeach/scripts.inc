KnotIsland_TreasureBeach_MapScripts::
.byte 0

KnotIsland_TreasureBeach_EventScript_Boy::
	msgbox KnotIsland_TreasureBeach_Text_GoodThingsWashUpOnBeach, MSGBOX_NPC
	end
	
KnotIsland_TreasureBeach_EventScript_Amara::
	trainerbattle_single TRAINER_SWIMMER_FEMALE_AMARA, KnotIsland_TreasureBeach_Text_AmaraIntro, KnotIsland_TreasureBeach_Text_AmaraDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, KnotIsland_TreasureBeach_EventScript_AmaraRematch
	msgbox KnotIsland_TreasureBeach_Text_AmaraPostBattle, MSGBOX_AUTOCLOSE
	end

KnotIsland_TreasureBeach_EventScript_AmaraRematch::
	trainerbattle_rematch TRAINER_CLIFFORD, KnotIsland_TreasureBeach_Text_AmaraRematchIntro, KnotIsland_TreasureBeach_Text_AmaraDefeat
	msgbox KnotIsland_TreasureBeach_Text_AmaraPostBattle, MSGBOX_AUTOCLOSE
	end


KnotIsland_TreasureBeach_Text_AmaraIntro::
    .string "Lying back, rocked by the waves…\n"
    .string "It's exquisite.$"

KnotIsland_TreasureBeach_Text_AmaraDefeat::
    .string "I lost…\n"
    .string "It feels awful.$"

KnotIsland_TreasureBeach_Text_AmaraPostBattle::
    .string "The sea is pleasantly warm in these\n"
    .string "parts.$"

KnotIsland_TreasureBeach_Text_AmaraRematchIntro::
	.string "Lying back, rocked by the waves…\n"
	.string "I don't notice time slipping by…$"

KnotIsland_TreasureBeach_Text_GoodThingsWashUpOnBeach::
    .string "Good things get washed up by the\n"
    .string "ocean current onto this beach.\p"
    .string "That's why I often come here for\n"
    .string "some beachcombing.$"
