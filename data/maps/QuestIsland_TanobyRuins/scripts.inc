QuestIsland_TanobyRuins_MapScripts::
	.byte 0

QuestIsland_TanobyRuins_EventScript_Brandon::
	trainerbattle_single TRAINER_RUIN_MANIAC_BRANDON, QuestIsland_TanobyRuins_Text_BrandonIntro, QuestIsland_TanobyRuins_Text_BrandonDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, QuestIsland_TanobyRuins_EventScript_BrandonRematch
	msgbox QuestIsland_TanobyRuins_Text_BrandonPostBattle, MSGBOX_AUTOCLOSE
	end

QuestIsland_TanobyRuins_EventScript_BrandonRematch::
	trainerbattle_rematch TRAINER_CLIFFORD, QuestIsland_TanobyRuins_Text_BrandonRematchIntro, QuestIsland_TanobyRuins_Text_BrandonDefeat
	msgbox QuestIsland_TanobyRuins_Text_BrandonPostBattle, MSGBOX_AUTOCLOSE
	end

QuestIsland_TanobyRuins_EventScript_Benjamin::
	trainerbattle_single TRAINER_RUIN_MANIAC_BENJAMIN, QuestIsland_TanobyRuins_Text_BenjaminIntro, QuestIsland_TanobyRuins_Text_BenjaminDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, QuestIsland_TanobyRuins_EventScript_BenjaminRematch
	msgbox QuestIsland_TanobyRuins_Text_BenjaminPostBattle, MSGBOX_AUTOCLOSE
	end

QuestIsland_TanobyRuins_EventScript_BenjaminRematch::
	trainerbattle_rematch TRAINER_CLIFFORD, QuestIsland_TanobyRuins_Text_BenjaminRematchIntro, QuestIsland_TanobyRuins_Text_BenjaminDefeat
	msgbox QuestIsland_TanobyRuins_Text_BenjaminPostBattle, MSGBOX_AUTOCLOSE
	end

QuestIsland_TanobyRuins_EventScript_Edna::
	trainerbattle_single TRAINER_PAINTER_EDNA, QuestIsland_TanobyRuins_Text_EdnaIntro, QuestIsland_TanobyRuins_Text_EdnaDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, QuestIsland_TanobyRuins_EventScript_EdnaRematch
	msgbox QuestIsland_TanobyRuins_Text_EdnaPostBattle, MSGBOX_AUTOCLOSE
	end

QuestIsland_TanobyRuins_EventScript_EdnaRematch::
	trainerbattle_rematch TRAINER_CLIFFORD, QuestIsland_TanobyRuins_Text_EdnaRematchIntro, QuestIsland_TanobyRuins_Text_EdnaDefeat
	msgbox QuestIsland_TanobyRuins_Text_EdnaPostBattle, MSGBOX_AUTOCLOSE
	end

QuestIsland_TanobyRuins_EventScript_Clifford::
	trainerbattle_single TRAINER_GENTLEMAN_CLIFFORD, QuestIsland_TanobyRuins_Text_CliffordIntro, QuestIsland_TanobyRuins_Text_CliffordDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, QuestIsland_TanobyRuins_EventScript_CliffordRematch
	msgbox QuestIsland_TanobyRuins_Text_CliffordPostBattle, MSGBOX_AUTOCLOSE
	end

QuestIsland_TanobyRuins_EventScript_CliffordRematch::
	trainerbattle_rematch TRAINER_CLIFFORD, QuestIsland_TanobyRuins_Text_CliffordRematchIntro, QuestIsland_TanobyRuins_Text_CliffordDefeat
	msgbox QuestIsland_TanobyRuins_Text_CliffordPostBattle, MSGBOX_AUTOCLOSE
	end

    QuestIsland_TanobyRuins_Text_BrandonRematchIntro::
	.string "Have you discovered anything about\n"
	.string "this stone chamber?$"

QuestIsland_TanobyRuins_Text_BenjaminRematchIntro::
	.string "A mystic POKéMON is said to sleep\n"
	.string "inside here.$"

QuestIsland_TanobyRuins_Text_EdnaRematchIntro::
	.string "My teacher is showing me how to\n"
	.string "paint some more.$"

QuestIsland_TanobyRuins_Text_CliffordRematchIntro::
	.string "Today, in addition to our lesson,\n"
	.string "we came to see the chamber again.$"

QuestIsland_TanobyRuins_Text_BrandonIntro::
    .string "Do you know anything about this\n"
    .string "stone chamber?$"

QuestIsland_TanobyRuins_Text_BrandonDefeat::
    .string "That was uncalled for.\n"
    .string "You didn't have to be so rough.$"

QuestIsland_TanobyRuins_Text_BrandonPostBattle::
    .string "The TANOBY RUINS date back at\n"
    .string "least 1,500 years.\p"
    .string "But it's a baffling mystery as to\n"
    .string "why it was built in the first place.$"

QuestIsland_TanobyRuins_Text_BenjaminIntro::
    .string "A mystic POKéMON is said to sleep\n"
    .string "inside here.$"

QuestIsland_TanobyRuins_Text_BenjaminDefeat::
    .string "I'm not much good in battle.$"

QuestIsland_TanobyRuins_Text_BenjaminPostBattle::
    .string "I hear there are other ruins like\n"
    .string "the one here.\p"
    .string "Might they be the resting places\n"
    .string "of other mystic POKéMON?$"

QuestIsland_TanobyRuins_Text_EdnaIntro::
    .string "CLIFFORD is teaching me how to\n"
    .string "paint.$"

QuestIsland_TanobyRuins_Text_EdnaDefeat::
    .string "We might get in trouble for being\n"
    .string "noisy here.$"

QuestIsland_TanobyRuins_Text_EdnaPostBattle::
    .string "I said that I wanted to paint an\n"
    .string "old building.\p"
    .string "So CLIFFORD brought me here.$"

QuestIsland_TanobyRuins_Text_CliffordIntro::
    .string "Today, in addition to our lesson,\n"
    .string "we came to see the chamber.$"

QuestIsland_TanobyRuins_Text_CliffordDefeat::
    .string "My, how extraordinary.$"

QuestIsland_TanobyRuins_Text_CliffordPostBattle::
    .string "Ah, so you are studying POKéMON\n"
    .string "on your own…\p"
    .string "Yes, you certainly are quite the\n"
    .string "extraordinary person, indeed.$"
