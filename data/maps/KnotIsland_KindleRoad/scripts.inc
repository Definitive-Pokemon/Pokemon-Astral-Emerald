KnotIsland_KindleRoad_MapScripts::
	.byte 0

KnotIsland_KindleRoad_EventScript_Maria::
	trainerbattle_single TRAINER_SWIMMER_FEMALE_MARIA, KnotIsland_KindleRoad_Text_MariaIntro, KnotIsland_KindleRoad_Text_MariaDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, KnotIsland_KindleRoad_EventScript_MariaRematch
	msgbox KnotIsland_KindleRoad_Text_MariaPostBattle, MSGBOX_AUTOCLOSE
	end

KnotIsland_KindleRoad_EventScript_MariaRematch::
	trainerbattle_rematch TRAINER_CLIFFORD, KnotIsland_KindleRoad_Text_MariaRematchIntro, KnotIsland_KindleRoad_Text_MariaDefeat
	msgbox KnotIsland_KindleRoad_Text_MariaPostBattle, MSGBOX_AUTOCLOSE
	end

KnotIsland_KindleRoad_EventScript_Abigail::
	trainerbattle_single TRAINER_SWIMMER_FEMALE_ABIGAIL, KnotIsland_KindleRoad_Text_AbigailIntro, KnotIsland_KindleRoad_Text_AbigailDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, KnotIsland_KindleRoad_EventScript_AbigailRematch
	msgbox KnotIsland_KindleRoad_Text_AbigailPostBattle, MSGBOX_AUTOCLOSE
	end

KnotIsland_KindleRoad_EventScript_AbigailRematch::
	trainerbattle_rematch TRAINER_CLIFFORD, KnotIsland_KindleRoad_Text_AbigailRematchIntro, KnotIsland_KindleRoad_Text_AbigailDefeat
	msgbox KnotIsland_KindleRoad_Text_AbigailPostBattle, MSGBOX_AUTOCLOSE
	end

KnotIsland_KindleRoad_EventScript_Finn::
	trainerbattle_single TRAINER_SWIMMER_MALE_FINN, KnotIsland_KindleRoad_Text_FinnIntro, KnotIsland_KindleRoad_Text_FinnDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, KnotIsland_KindleRoad_EventScript_FinnRematch
	msgbox KnotIsland_KindleRoad_Text_FinnPostBattle, MSGBOX_AUTOCLOSE
	end

KnotIsland_KindleRoad_EventScript_FinnRematch::
	trainerbattle_rematch TRAINER_CLIFFORD, KnotIsland_KindleRoad_Text_FinnRematchIntro, KnotIsland_KindleRoad_Text_FinnDefeat
	msgbox KnotIsland_KindleRoad_Text_FinnPostBattle, MSGBOX_AUTOCLOSE
	end

KnotIsland_KindleRoad_EventScript_Garrett::
	trainerbattle_single TRAINER_SWIMMER_MALE_GARRETT, KnotIsland_KindleRoad_Text_GarrettIntro, KnotIsland_KindleRoad_Text_GarrettDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, KnotIsland_KindleRoad_EventScript_GarrettRematch
	msgbox KnotIsland_KindleRoad_Text_GarrettPostBattle, MSGBOX_AUTOCLOSE
	end

KnotIsland_KindleRoad_EventScript_GarrettRematch::
	trainerbattle_rematch TRAINER_CLIFFORD, KnotIsland_KindleRoad_Text_GarrettRematchIntro, KnotIsland_KindleRoad_Text_GarrettDefeat
	msgbox KnotIsland_KindleRoad_Text_GarrettPostBattle, MSGBOX_AUTOCLOSE
	end

KnotIsland_KindleRoad_EventScript_Tommy::
	trainerbattle_single TRAINER_FISHERMAN_TOMMY, KnotIsland_KindleRoad_Text_TommyIntro, KnotIsland_KindleRoad_Text_TommyDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, KnotIsland_KindleRoad_EventScript_TommyRematch
	msgbox KnotIsland_KindleRoad_Text_TommyPostBattle, MSGBOX_AUTOCLOSE
	end

KnotIsland_KindleRoad_EventScript_TommyRematch::
	trainerbattle_rematch TRAINER_CLIFFORD, KnotIsland_KindleRoad_Text_TommyRematchIntro, KnotIsland_KindleRoad_Text_TommyDefeat
	msgbox KnotIsland_KindleRoad_Text_TommyPostBattle, MSGBOX_AUTOCLOSE
	end

KnotIsland_KindleRoad_EventScript_Sharon::
	trainerbattle_single TRAINER_CRUSH_GIRL_SHARON, KnotIsland_KindleRoad_Text_SharonIntro, KnotIsland_KindleRoad_Text_SharonDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, KnotIsland_KindleRoad_EventScript_SharonRematch
	msgbox KnotIsland_KindleRoad_Text_SharonPostBattle, MSGBOX_AUTOCLOSE
	end

KnotIsland_KindleRoad_EventScript_SharonRematch::
	trainerbattle_rematch TRAINER_CLIFFORD, KnotIsland_KindleRoad_Text_SharonRematchIntro, KnotIsland_KindleRoad_Text_SharonDefeat
	msgbox KnotIsland_KindleRoad_Text_SharonPostBattle, MSGBOX_AUTOCLOSE
	end

KnotIsland_KindleRoad_EventScript_Tanya::
	trainerbattle_single TRAINER_CRUSH_GIRL_TANYA, KnotIsland_KindleRoad_Text_TanyaIntro, KnotIsland_KindleRoad_Text_TanyaDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, KnotIsland_KindleRoad_EventScript_TanyaRematch
	msgbox KnotIsland_KindleRoad_Text_TanyaPostBattle, MSGBOX_AUTOCLOSE
	end

KnotIsland_KindleRoad_EventScript_TanyaRematch::
	trainerbattle_rematch TRAINER_CLIFFORD, KnotIsland_KindleRoad_Text_TanyaRematchIntro, KnotIsland_KindleRoad_Text_TanyaDefeat
	msgbox KnotIsland_KindleRoad_Text_TanyaPostBattle, MSGBOX_AUTOCLOSE
	end

KnotIsland_KindleRoad_EventScript_Shea::
	trainerbattle_single TRAINER_BLACK_BELT_SHEA, KnotIsland_KindleRoad_Text_SheaIntro, KnotIsland_KindleRoad_Text_SheaDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, KnotIsland_KindleRoad_EventScript_SheaRematch
	msgbox KnotIsland_KindleRoad_Text_SheaPostBattle, MSGBOX_AUTOCLOSE
	end

KnotIsland_KindleRoad_EventScript_SheaRematch::
	trainerbattle_rematch TRAINER_CLIFFORD, KnotIsland_KindleRoad_Text_SheaRematchIntro, KnotIsland_KindleRoad_Text_SheaDefeat
	msgbox KnotIsland_KindleRoad_Text_SheaPostBattle, MSGBOX_AUTOCLOSE
	end

KnotIsland_KindleRoad_EventScript_Hugh::
	trainerbattle_single TRAINER_BLACK_BELT_HUGH, KnotIsland_KindleRoad_Text_HughIntro, KnotIsland_KindleRoad_Text_HughDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, KnotIsland_KindleRoad_EventScript_HughRematch
	msgbox KnotIsland_KindleRoad_Text_HughPostBattle, MSGBOX_AUTOCLOSE
	end

KnotIsland_KindleRoad_EventScript_HughRematch::
	trainerbattle_rematch TRAINER_CLIFFORD, KnotIsland_KindleRoad_Text_HughRematchIntro, KnotIsland_KindleRoad_Text_HughDefeat
	msgbox KnotIsland_KindleRoad_Text_HughPostBattle, MSGBOX_AUTOCLOSE
	end

KnotIsland_KindleRoad_EventScript_Bryce::
	trainerbattle_single TRAINER_CAMPER_BRYCE, KnotIsland_KindleRoad_Text_BryceIntro, KnotIsland_KindleRoad_Text_BryceDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, KnotIsland_KindleRoad_EventScript_BryceRematch
	msgbox KnotIsland_KindleRoad_Text_BrycePostBattle, MSGBOX_AUTOCLOSE
	end

KnotIsland_KindleRoad_EventScript_BryceRematch::
	trainerbattle_rematch TRAINER_CLIFFORD, KnotIsland_KindleRoad_Text_BryceRematchIntro, KnotIsland_KindleRoad_Text_BryceDefeat
	msgbox KnotIsland_KindleRoad_Text_BrycePostBattle, MSGBOX_AUTOCLOSE
	end

KnotIsland_KindleRoad_EventScript_Claire::
	trainerbattle_single TRAINER_PICNICKER_CLAIRE, KnotIsland_KindleRoad_Text_ClaireIntro, KnotIsland_KindleRoad_Text_ClaireDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, KnotIsland_KindleRoad_EventScript_ClaireRematch
	msgbox KnotIsland_KindleRoad_Text_ClairePostBattle, MSGBOX_AUTOCLOSE
	end

KnotIsland_KindleRoad_EventScript_ClaireRematch::
	trainerbattle_rematch TRAINER_CLIFFORD, KnotIsland_KindleRoad_Text_ClaireRematchIntro, KnotIsland_KindleRoad_Text_ClaireDefeat
	msgbox KnotIsland_KindleRoad_Text_ClairePostBattle, MSGBOX_AUTOCLOSE
	end

KnotIsland_KindleRoad_EventScript_Kia::
	trainerbattle_double TRAINER_CRUSH_KIN_MIK_KIA, KnotIsland_KindleRoad_Text_KiaIntro, KnotIsland_KindleRoad_Text_KiaDefeat, KnotIsland_KindleRoad_Text_KiaNotEnoughMons
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, KnotIsland_KindleRoad_EventScript_KiaRematch
	msgbox KnotIsland_KindleRoad_Text_KiaPostBattle, MSGBOX_AUTOCLOSE
	end

KnotIsland_KindleRoad_EventScript_KiaRematch::
trainerbattle_rematch TRAINER_CLIFFORD, KnotIsland_KindleRoad_Text_KiaRematchIntro, KnotIsland_KindleRoad_Text_KiaDefeat
	msgbox KnotIsland_KindleRoad_Text_KiaPostBattle, MSGBOX_AUTOCLOSE
	end

KnotIsland_KindleRoad_EventScript_Mik::
	trainerbattle_double TRAINER_CRUSH_KIN_MIK_KIA, KnotIsland_KindleRoad_Text_MikIntro, KnotIsland_KindleRoad_Text_MikDefeat, KnotIsland_KindleRoad_Text_MikNotEnoughMons
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, KnotIsland_KindleRoad_EventScript_MikRematch
	msgbox KnotIsland_KindleRoad_Text_MikPostBattle, MSGBOX_AUTOCLOSE
	end

KnotIsland_KindleRoad_EventScript_MikRematch::
	trainerbattle_rematch TRAINER_CLIFFORD, KnotIsland_KindleRoad_Text_MikRematchIntro, KnotIsland_KindleRoad_Text_MikDefeat
	msgbox KnotIsland_KindleRoad_Text_MikPostBattle, MSGBOX_AUTOCLOSE
	end

KnotIsland_KindleRoad_EventScript_RouteSign::
	msgbox KnotIsland_KindleRoad_Text_RouteSign, MSGBOX_SIGN
	end

KnotIsland_KindleRoad_EventScript_EmberSpaSign::
	msgbox KnotIsland_KindleRoad_Text_EmberSpaSign, MSGBOX_SIGN
	end

KnotIsland_KindleRoad_Text_MariaIntro::
    .string "The weather's gorgeous!\n"
    .string "Perfect for a battle!$"

KnotIsland_KindleRoad_Text_MariaDefeat::
    .string "Aiyeeeeh!$"

KnotIsland_KindleRoad_Text_MariaPostBattle::
    .string "Please don't splash my face!\n"
    .string "You'll ruin the makeup.$"

KnotIsland_KindleRoad_Text_AbigailIntro::
    .string "I'm beginning to get a sunburn…$"

KnotIsland_KindleRoad_Text_AbigailDefeat::
    .string "Oh, you're so awful.$"

KnotIsland_KindleRoad_Text_AbigailPostBattle::
    .string "I like that cap you have.\n"
    .string "Maybe I should wear one, too…$"

KnotIsland_KindleRoad_Text_FinnIntro::
    .string "Seen from here, MT. EMBER towers\n"
    .string "into the sky.$"

KnotIsland_KindleRoad_Text_FinnDefeat::
    .string "Well, aren't you tough?$"

KnotIsland_KindleRoad_Text_FinnPostBattle::
    .string "The sky is immense around these\n"
    .string "parts.$"

KnotIsland_KindleRoad_Text_GarrettIntro::
    .string "I took a break from swimming,\n"
    .string "only to have you challenge me?$"

KnotIsland_KindleRoad_Text_GarrettDefeat::
    .string "Hey, what the…\n"
    .string "You're good, you!$"

KnotIsland_KindleRoad_Text_GarrettPostBattle::
    .string "Instead of using SURF all the time,\n"
    .string "you should swim some.$"

KnotIsland_KindleRoad_Text_TommyIntro::
    .string "Wait! Wait a second!\n"
    .string "I think I've hooked a big one!$"

KnotIsland_KindleRoad_Text_TommyDefeat::
    .string "I've lost it all again…$"

KnotIsland_KindleRoad_Text_TommyPostBattle::
    .string "Not only did I lose, the big one\n"
    .string "got away from me, too!$"

KnotIsland_KindleRoad_Text_SharonIntro::
    .string "Could you help me out with my\n"
    .string "training?$"

KnotIsland_KindleRoad_Text_SharonDefeat::
    .string "You were a cut above me.$"

KnotIsland_KindleRoad_Text_SharonPostBattle::
    .string "It's clear that you're skilled.\n"
    .string "I like you!$"

KnotIsland_KindleRoad_Text_TanyaIntro::
    .string "There isn't a day in which we don't\n"
    .string "train!$"

KnotIsland_KindleRoad_Text_TanyaDefeat::
    .string "I'm such a fool!$"

KnotIsland_KindleRoad_Text_TanyaPostBattle::
    .string "I'll train even harder from now on!$"

KnotIsland_KindleRoad_Text_SheaIntro::
    .string "Every morning, before breakfast,\n"
    .string "I swim around this island.$"

KnotIsland_KindleRoad_Text_SheaDefeat::
    .string "Gasp…\n"
    .string "Gasp…$"

KnotIsland_KindleRoad_Text_SheaPostBattle::
    .string "I lost because I'm pooped from all\n"
    .string "the running I did…$"

KnotIsland_KindleRoad_Text_HughIntro::
    .string "Dress appropriately for battle!\n"
    .string "Lose that frivolous outfit!$"

KnotIsland_KindleRoad_Text_HughDefeat::
    .string "Why me?!$"

KnotIsland_KindleRoad_Text_HughPostBattle::
    .string "Even martial artists are becoming\n"
    .string "fashion conscious these days…$"

KnotIsland_KindleRoad_Text_BryceIntro::
    .string "You know, everything tastes great\n"
    .string "when you're out in the wild.$"

KnotIsland_KindleRoad_Text_BryceDefeat::
    .string "Awww, blown!$"

KnotIsland_KindleRoad_Text_BrycePostBattle::
    .string "The water in volcanic regions is\n"
    .string "delicious.$"

KnotIsland_KindleRoad_Text_ClaireIntro::
    .string "My lunch filled us up, so will you\n"
    .string "battle us for some exercise?$"

KnotIsland_KindleRoad_Text_ClaireDefeat::
    .string "That made me all sweaty.$"

KnotIsland_KindleRoad_Text_ClairePostBattle::
    .string "What should I do?\n"
    .string "I feel famished again.$"

KnotIsland_KindleRoad_Text_KiaIntro::
    .string "KIA: My big brother and I make\n"
    .string "an awesome combination!$"

KnotIsland_KindleRoad_Text_KiaDefeat::
    .string "KIA: Huh?!\n"
    .string "I can't believe it!$"

KnotIsland_KindleRoad_Text_KiaPostBattle::
    .string "KIA: How could there be anyone\n"
    .string "better than my big brother?$"

KnotIsland_KindleRoad_Text_KiaNotEnoughMons::
    .string "KIA: If you want to battle with\n"
    .string "us, you have to bring at least two\l"
    .string "POKéMON with you.$"

KnotIsland_KindleRoad_Text_MikIntro::
    .string "MIK: Together with KIA, I'm afraid\n"
    .string "of nothing!$"

KnotIsland_KindleRoad_Text_MikDefeat::
    .string "MIK: Whoa!\n"
    .string "That's too much!$"

KnotIsland_KindleRoad_Text_MikPostBattle::
    .string "MIK: How could my combination\n"
    .string "with KIA fail?$"

KnotIsland_KindleRoad_Text_MariaRematchIntro::
	.string "The weather's gorgeous!\n"
	.string "I'll try not to spoil it.$"

KnotIsland_KindleRoad_Text_AbigailRematchIntro::
	.string "My sunburn is starting to hurt…$"

KnotIsland_KindleRoad_Text_FinnRematchIntro::
	.string "The fire bird's mountain casts\n"
	.string "a huge shadow…$"

KnotIsland_KindleRoad_Text_GarrettRematchIntro::
	.string "I have this strong feeling that\n"
	.string "I can win this time!$"

KnotIsland_KindleRoad_Text_TommyRematchIntro::
	.string "Wait! Wait a second!\n"
	.string "I'm sure I've hooked a big one!$"

KnotIsland_KindleRoad_Text_SharonRematchIntro::
	.string "You'll help me out with my\n"
	.string "training again?$"

KnotIsland_KindleRoad_Text_TanyaRematchIntro::
	.string "We haven't missed a single day of\n"
	.string "training yet!$"

KnotIsland_KindleRoad_Text_SheaRematchIntro::
	.string "Every morning, before breakfast,\n"
	.string "I swim around this island…\l"
	.string "Three times!$"

KnotIsland_KindleRoad_Text_HughRematchIntro::
	.string "Dress appropriately for battle!\n"
	.string "Lose that frivolous outfit, I said!$"

KnotIsland_KindleRoad_Text_BryceRematchIntro::
	.string "You know, everything tastes great\n"
	.string "when you're out in the wild.$"

KnotIsland_KindleRoad_Text_ClaireRematchIntro::
	.string "I ate too much again, so will you\n"
	.string "battle us for some exercise?$"

KnotIsland_KindleRoad_Text_KiaRematchIntro::
	.string "KIA: My big brother and I make\n"
	.string "an awesome combination!\p"
	.string "We won't lose this time!$"

KnotIsland_KindleRoad_Text_MikRematchIntro::
	.string "MIK: Together with KIA, we're\n"
	.string "afraid of nothing!\p"
	.string "We'll prove it to you this time!$"

KnotIsland_KindleRoad_Text_MikNotEnoughMons::
    .string "MIK: Hey, do you want to battle\n"
    .string "with us two?\p"
    .string "Bring two or more POKéMON with\n"
    .string "you, then.$"

KnotIsland_KindleRoad_Text_RouteSign::
    .string "This is KINDLE ROAD.\p"
    .string "Go straight for MT. EMBER.$"

KnotIsland_KindleRoad_Text_EmberSpaSign::
    .string "Light the Fire in Your Heart!\n"
    .string "EMBER SPA$"


