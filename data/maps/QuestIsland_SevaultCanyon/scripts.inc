QuestIsland_SevaultCanyon_MapScripts::
	.byte 0

QuestIsland_SevaultCanyon_EventScript_Cyndy::
	trainerbattle_single TRAINER_CRUSH_GIRL_CYNDY, QuestIsland_SevaultCanyon_Text_CyndyIntro, QuestIsland_SevaultCanyon_Text_CyndyDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, QuestIsland_SevaultCanyon_EventScript_CyndyRematch
	msgbox QuestIsland_SevaultCanyon_Text_CyndyPostBattle, MSGBOX_AUTOCLOSE
	end

QuestIsland_SevaultCanyon_EventScript_CyndyRematch::
	trainerbattle_rematch TRAINER_CLIFFORD, QuestIsland_SevaultCanyon_Text_CyndyRematchIntro, QuestIsland_SevaultCanyon_Text_CyndyDefeat
	msgbox QuestIsland_SevaultCanyon_Text_CyndyPostBattle, MSGBOX_AUTOCLOSE
	end

QuestIsland_SevaultCanyon_EventScript_Evan::
	trainerbattle_single TRAINER_TAMER_EVAN, QuestIsland_SevaultCanyon_Text_EvanIntro, QuestIsland_SevaultCanyon_Text_EvanDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, QuestIsland_SevaultCanyon_EventScript_EvanRematch
	msgbox QuestIsland_SevaultCanyon_Text_EvanPostBattle, MSGBOX_AUTOCLOSE
	end

QuestIsland_SevaultCanyon_EventScript_EvanRematch::
	trainerbattle_rematch TRAINER_CLIFFORD, QuestIsland_SevaultCanyon_Text_EvanRematchIntro, QuestIsland_SevaultCanyon_Text_EvanDefeat
	msgbox QuestIsland_SevaultCanyon_Text_EvanPostBattle, MSGBOX_AUTOCLOSE
	end

QuestIsland_SevaultCanyon_EventScript_Jackson::
	trainerbattle_single TRAINER_PKMN_RANGER_JACKSON, QuestIsland_SevaultCanyon_Text_JacksonIntro, QuestIsland_SevaultCanyon_Text_JacksonDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, QuestIsland_SevaultCanyon_EventScript_JacksonRematch
	msgbox QuestIsland_SevaultCanyon_Text_JacksonPostBattle, MSGBOX_AUTOCLOSE
	end

QuestIsland_SevaultCanyon_EventScript_JacksonRematch::
	trainerbattle_rematch TRAINER_CLIFFORD, QuestIsland_SevaultCanyon_Text_JacksonRematchIntro, QuestIsland_SevaultCanyon_Text_JacksonDefeat
	msgbox QuestIsland_SevaultCanyon_Text_JacksonPostBattle, MSGBOX_AUTOCLOSE
	end

QuestIsland_SevaultCanyon_EventScript_Katelyn::
	trainerbattle_single TRAINER_PKMN_RANGER_KATELYN, QuestIsland_SevaultCanyon_Text_KatelynIntro, QuestIsland_SevaultCanyon_Text_KatelynDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, QuestIsland_SevaultCanyon_EventScript_KatelynRematch
	msgbox QuestIsland_SevaultCanyon_Text_KatelynPostBattle, MSGBOX_AUTOCLOSE
	end

QuestIsland_SevaultCanyon_EventScript_KatelynRematch::
	trainerbattle_rematch TRAINER_CLIFFORD, QuestIsland_SevaultCanyon_Text_KatelynRematchIntro, QuestIsland_SevaultCanyon_Text_KatelynDefeat
	msgbox QuestIsland_SevaultCanyon_Text_KatelynPostBattle, MSGBOX_AUTOCLOSE
	end

QuestIsland_SevaultCanyon_EventScript_Leroy::
	trainerbattle_single TRAINER_COOLTRAINER_LEROY, QuestIsland_SevaultCanyon_Text_LeroyIntro, QuestIsland_SevaultCanyon_Text_LeroyDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, QuestIsland_SevaultCanyon_EventScript_LeroyRematch
	msgbox QuestIsland_SevaultCanyon_Text_LeroyPostBattle, MSGBOX_AUTOCLOSE
	end

QuestIsland_SevaultCanyon_EventScript_LeroyRematch::
	trainerbattle_rematch TRAINER_CLIFFORD, QuestIsland_SevaultCanyon_Text_LeroyRematchIntro, QuestIsland_SevaultCanyon_Text_LeroyDefeat
	msgbox QuestIsland_SevaultCanyon_Text_LeroyPostBattle, MSGBOX_AUTOCLOSE
	end

QuestIsland_SevaultCanyon_EventScript_Michelle::
	trainerbattle_single TRAINER_COOLTRAINER_MICHELLE, QuestIsland_SevaultCanyon_Text_MichelleIntro, QuestIsland_SevaultCanyon_Text_MichelleDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, QuestIsland_SevaultCanyon_EventScript_MichelleRematch
	msgbox QuestIsland_SevaultCanyon_Text_MichellePostBattle, MSGBOX_AUTOCLOSE
	end

QuestIsland_SevaultCanyon_EventScript_MichelleRematch::
	trainerbattle_rematch TRAINER_CLIFFORD, QuestIsland_SevaultCanyon_Text_MichelleRematchIntro, QuestIsland_SevaultCanyon_Text_MichelleDefeat
	msgbox QuestIsland_SevaultCanyon_Text_MichellePostBattle, MSGBOX_AUTOCLOSE
	end

QuestIsland_SevaultCanyon_EventScript_Lex::
	trainerbattle_double TRAINER_COOL_COUPLE_LEX_NYA, QuestIsland_SevaultCanyon_Text_LexIntro, QuestIsland_SevaultCanyon_Text_LexDefeat, QuestIsland_SevaultCanyon_Text_LexNotEnoughMons
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, QuestIsland_SevaultCanyon_EventScript_LexRematch
	msgbox QuestIsland_SevaultCanyon_Text_LexPostBattle, MSGBOX_AUTOCLOSE
	end

QuestIsland_SevaultCanyon_EventScript_LexRematch::
	trainerbattle_rematch TRAINER_CLIFFORD, QuestIsland_SevaultCanyon_Text_LexRematchIntro, QuestIsland_SevaultCanyon_Text_LexDefeat
	msgbox QuestIsland_SevaultCanyon_Text_LexPostBattle, MSGBOX_AUTOCLOSE
	end

QuestIsland_SevaultCanyon_EventScript_Nya::
	trainerbattle_double TRAINER_COOL_COUPLE_LEX_NYA, QuestIsland_SevaultCanyon_Text_NyaIntro, QuestIsland_SevaultCanyon_Text_NyaDefeat, QuestIsland_SevaultCanyon_Text_NyaNotEnoughMons
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, QuestIsland_SevaultCanyon_EventScript_NyaRematch
	msgbox QuestIsland_SevaultCanyon_Text_NyaPostBattle, MSGBOX_AUTOCLOSE
	end

QuestIsland_SevaultCanyon_EventScript_NyaRematch::
	trainerbattle_rematch TRAINER_CLIFFORD, QuestIsland_SevaultCanyon_Text_NyaRematchIntro, QuestIsland_SevaultCanyon_Text_NyaDefeat
	msgbox QuestIsland_SevaultCanyon_Text_NyaPostBattle, MSGBOX_AUTOCLOSE
	end

    QuestIsland_SevaultCanyon_Text_CyndyRematchIntro::
	.string "Let's have another battle.\n"
	.string "My conditioning's in top form!$"

QuestIsland_SevaultCanyon_Text_EvanRematchIntro::
	.string "It doesn't matter if you happen to\n"
	.string "have the strongest POKéMON…\p"
	.string "It doesn't mean a thing if you don't\n"
	.string "know how to use them properly!$"

QuestIsland_SevaultCanyon_Text_JacksonRematchIntro::
	.string "I work to protect the environment.\n"
	.string "In turn, nature protects me!$"

QuestIsland_SevaultCanyon_Text_KatelynRematchIntro::
	.string "Every time we meet, you have those\n"
	.string "snazzy shoes on.$"

QuestIsland_SevaultCanyon_Text_LeroyRematchIntro::
	.string "You must have gotten tougher.\n"
	.string "Let me battle you, please!$"

QuestIsland_SevaultCanyon_Text_MichelleRematchIntro::
	.string "I was given the best possible\n"
	.string "education to become this strong.\p"
	.string "I won't lose this time.\n"
	.string "Absolutely not!$"

QuestIsland_SevaultCanyon_Text_LexRematchIntro::
	.string "LEX: My darling NYA, together\n"
	.string "we will win for certain!$"

QuestIsland_SevaultCanyon_Text_NyaRematchIntro::
	.string "NYA: I won't drag down my mentor\n"
	.string "LEX! We're going to win!$"

QuestIsland_SevaultCanyon_EventScript_RouteSign::
	msgbox QuestIsland_SevaultCanyon_Text_RouteSign, MSGBOX_SIGN
	end

QuestIsland_SevaultCanyon_Text_CyndyIntro::
    .string "My conditioning's in top form!$"

QuestIsland_SevaultCanyon_Text_CyndyDefeat::
    .string "Huh?\n"
    .string "Something's not right…$"

QuestIsland_SevaultCanyon_Text_CyndyPostBattle::
    .string "The way I am now, I may have to\n"
    .string "hold off on TRAINER TOWER…$"

QuestIsland_SevaultCanyon_Text_EvanIntro::
    .string "It doesn't matter if you happen to\n"
    .string "have the strongest POKéMON…\p"
    .string "It doesn't mean a thing if you don't\n"
    .string "know how to use them properly!$"

QuestIsland_SevaultCanyon_Text_EvanDefeat::
    .string "You're a master at this.$"

QuestIsland_SevaultCanyon_Text_EvanPostBattle::
    .string "You see them every so often,\n"
    .string "TRAINERS with awesome POKéMON\l"
    .string "who have no idea what to do.\p"
    .string "Before training POKéMON, TRAINERS\n"
    .string "themselves need to grow up.$"

QuestIsland_SevaultCanyon_Text_JacksonIntro::
    .string "I work to protect the environment.\n"
    .string "In turn, nature protects me!$"

QuestIsland_SevaultCanyon_Text_JacksonDefeat::
    .string "Whoa! You're tough!\n"
    .string "How about protecting me?$"

QuestIsland_SevaultCanyon_Text_JacksonPostBattle::
    .string "From far out among the stars, our\n"
    .string "planet is just a drop of water.\p"
    .string "But we want to protect that drop\n"
    .string "of water for everyone.$"

QuestIsland_SevaultCanyon_Text_KatelynIntro::
    .string "Those shoes you have are pretty\n"
    .string "snazzy.$"

QuestIsland_SevaultCanyon_Text_KatelynDefeat::
    .string "You're hot stuff in spite of your\n"
    .string "cute looks.$"

QuestIsland_SevaultCanyon_Text_KatelynPostBattle::
    .string "Your mom bought those snazzy\n"
    .string "RUNNING SHOES for you?\p"
    .string "She must adore you.$"

QuestIsland_SevaultCanyon_Text_LeroyIntro::
    .string "You look strong.\n"
    .string "Let me battle you, please!$"

QuestIsland_SevaultCanyon_Text_LeroyDefeat::
    .string "I knew it!\n"
    .string "You're as tough as I thought!$"

QuestIsland_SevaultCanyon_Text_LeroyPostBattle::
    .string "The way you battle has given me\n"
    .string "a lot of useful data.\p"
    .string "Thanks so much!$"

QuestIsland_SevaultCanyon_Text_MichelleIntro::
    .string "I was given the best possible\n"
    .string "education to become this strong.\p"
    .string "I don't want to lose to anyone!$"

QuestIsland_SevaultCanyon_Text_MichelleDefeat::
    .string "Thank you. I feel like I've been\n"
    .string "set free by losing to you.$"

QuestIsland_SevaultCanyon_Text_MichellePostBattle::
    .string "For some reason, I get furious\n"
    .string "over the slightest thing.\p"
    .string "I'll calm myself by breathing\n"
    .string "deeply.$"

QuestIsland_SevaultCanyon_Text_LexIntro::
    .string "LEX: My darling NYA, together\n"
    .string "we could win!$"

QuestIsland_SevaultCanyon_Text_LexDefeat::
    .string "LEX: I seem to have been too\n"
    .string "careless…$"

QuestIsland_SevaultCanyon_Text_LexPostBattle::
    .string "LEX: I think it was a good\n"
    .string "experience for NYA.\p"
    .string "You have my gratitude.$"

QuestIsland_SevaultCanyon_Text_LexNotEnoughMons::
    .string "LEX: May I ask you to battle the\n"
    .string "both of us at the same time?$"

QuestIsland_SevaultCanyon_Text_NyaIntro::
    .string "NYA: I'll do my best so I won't\n"
    .string "drag down my mentor, LEX!$"

QuestIsland_SevaultCanyon_Text_NyaDefeat::
    .string "NYA: Oh, no…\n"
    .string "I'm so sorry, I…$"

QuestIsland_SevaultCanyon_Text_NyaPostBattle::
    .string "NYA: I think I'm going to need\n"
    .string "much more seasoning and tutoring\l"
    .string "under LEX…\p"
    .string "…So, LEX, please, may I stay with\n"
    .string "you like this?$"

QuestIsland_SevaultCanyon_Text_NyaNotEnoughMons::
    .string "NYA: I'm sorry, but may we battle\n"
    .string "in two-on-two style?$"

QuestIsland_SevaultCanyon_Text_RouteSign::
    .string "SEVAULT CANYON\n"
    .string "TANOBY RUINS AHEAD$"

QuestIsland_SevaultCanyon_Text_BrunoTrainedWithBrawly::
    .string "Training by oneself is certainly\n"
    .string "not a bad thing.\p"
    .string "But it's also not bad to aim for\n"
    .string "the top with a partner.\p"
    .string "Even BRUNO…\n"
    .string "He trained with a fellow by the\l"
    .string "name of BRAWLY before.$"
