FortuneIsland_WaterPath_MapScripts::
	.byte 0

FortuneIsland_WaterPath_EventScript_Rose::
	trainerbattle_single TRAINER_AROMA_LADY_ROSE, FortuneIsland_WaterPath_Text_RoseIntro, FortuneIsland_WaterPath_Text_RoseDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, FortuneIsland_WaterPath_EventScript_RoseRematch
	msgbox FortuneIsland_WaterPath_Text_RosePostBattle, MSGBOX_AUTOCLOSE
	end

FortuneIsland_WaterPath_EventScript_RoseRematch::
	trainerbattle_rematch TRAINER_CLIFFORD, FortuneIsland_WaterPath_Text_RoseRematchIntro, FortuneIsland_WaterPath_Text_RoseDefeat
	msgbox FortuneIsland_WaterPath_Text_RosePostBattle, MSGBOX_AUTOCLOSE
	end

FortuneIsland_WaterPath_EventScript_Edward::
	trainerbattle_single TRAINER_JUGGLER_EDWARD, FortuneIsland_WaterPath_Text_EdwardIntro, FortuneIsland_WaterPath_Text_EdwardDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, FortuneIsland_WaterPath_EventScript_EdwardRematch
	msgbox FortuneIsland_WaterPath_Text_EdwardPostBattle, MSGBOX_AUTOCLOSE
	end

FortuneIsland_WaterPath_EventScript_EdwardRematch::
	trainerbattle_rematch TRAINER_CLIFFORD, FortuneIsland_WaterPath_Text_EdwardRematchIntro, FortuneIsland_WaterPath_Text_EdwardDefeat
	msgbox FortuneIsland_WaterPath_Text_EdwardPostBattle, MSGBOX_AUTOCLOSE
	end

FortuneIsland_WaterPath_EventScript_Samir::
	trainerbattle_single TRAINER_SWIMMER_MALE_SAMIR, FortuneIsland_WaterPath_Text_SamirIntro, FortuneIsland_WaterPath_Text_SamirDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, FortuneIsland_WaterPath_EventScript_SamirRematch
	msgbox FortuneIsland_WaterPath_Text_SamirPostBattle, MSGBOX_AUTOCLOSE
	end

FortuneIsland_WaterPath_EventScript_SamirRematch::
	trainerbattle_rematch TRAINER_CLIFFORD, FortuneIsland_WaterPath_Text_SamirRematchIntro, FortuneIsland_WaterPath_Text_SamirDefeat
	msgbox FortuneIsland_WaterPath_Text_SamirPostBattle, MSGBOX_AUTOCLOSE
	end

FortuneIsland_WaterPath_EventScript_Denise::
	trainerbattle_single TRAINER_SWIMMER_FEMALE_DENISE, FortuneIsland_WaterPath_Text_DeniseIntro, FortuneIsland_WaterPath_Text_DeniseDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, FortuneIsland_WaterPath_EventScript_DeniseRematch
	msgbox FortuneIsland_WaterPath_Text_DenisePostBattle, MSGBOX_AUTOCLOSE
	end

FortuneIsland_WaterPath_EventScript_DeniseRematch::
	trainerbattle_rematch TRAINER_CLIFFORD, FortuneIsland_WaterPath_Text_DeniseRematchIntro, FortuneIsland_WaterPath_Text_DeniseDefeat
	msgbox FortuneIsland_WaterPath_Text_DenisePostBattle, MSGBOX_AUTOCLOSE
	end

FortuneIsland_WaterPath_EventScript_Miu::
	trainerbattle_double TRAINER_TWINS_MIU_MIA, FortuneIsland_WaterPath_Text_MiuIntro, FortuneIsland_WaterPath_Text_MiuDefeat, FortuneIsland_WaterPath_Text_MiuNotEnoughMons
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, FortuneIsland_WaterPath_EventScript_MiuRematch
	msgbox FortuneIsland_WaterPath_Text_MiuPostBattle, MSGBOX_AUTOCLOSE
	end

FortuneIsland_WaterPath_EventScript_MiuRematch::
	trainerbattle_rematch TRAINER_CLIFFORD, FortuneIsland_WaterPath_Text_MiuRematchIntro, FortuneIsland_WaterPath_Text_MiuDefeat
	msgbox FortuneIsland_WaterPath_Text_MiuPostBattle, MSGBOX_AUTOCLOSE
	end

FortuneIsland_WaterPath_EventScript_Mia::
	trainerbattle_double TRAINER_TWINS_MIU_MIA, FortuneIsland_WaterPath_Text_MiaIntro, FortuneIsland_WaterPath_Text_MiaDefeat, FortuneIsland_WaterPath_Text_MiaNotEnoughMons
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, FortuneIsland_WaterPath_EventScript_MiaRematch
	msgbox FortuneIsland_WaterPath_Text_MiaPostBattle, MSGBOX_AUTOCLOSE
	end

FortuneIsland_WaterPath_EventScript_MiaRematch::
	trainerbattle_rematch TRAINER_CLIFFORD, FortuneIsland_WaterPath_Text_MiaRematchIntro, FortuneIsland_WaterPath_Text_MiaDefeat
	msgbox FortuneIsland_WaterPath_Text_MiaPostBattle, MSGBOX_AUTOCLOSE
	end

FortuneIsland_WaterPath_EventScript_Earl::
	trainerbattle_single TRAINER_HIKER_EARL, FortuneIsland_WaterPath_Text_EarlIntro, FortuneIsland_WaterPath_Text_EarlDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, FortuneIsland_WaterPath_EventScript_EarlRematch
	msgbox FortuneIsland_WaterPath_Text_EarlPostBattle, MSGBOX_AUTOCLOSE
	end

FortuneIsland_WaterPath_EventScript_EarlRematch::
	trainerbattle_rematch TRAINER_CLIFFORD, FortuneIsland_WaterPath_Text_EarlRematchIntro, FortuneIsland_WaterPath_Text_EarlDefeat
	msgbox FortuneIsland_WaterPath_Text_EarlPostBattle, MSGBOX_AUTOCLOSE
	end


    FortuneIsland_WaterPath_Text_RoseRematchIntro::
	.string "Oh, hello.\n"
	.string "A pleasant breeze is blowing again.$"

FortuneIsland_WaterPath_Text_EdwardRematchIntro::
	.string "Hehehe, I'm practicing in secret\n"
	.string "again.$"

FortuneIsland_WaterPath_Text_SamirRematchIntro::
	.string "What, you're sick of seeing\n"
	.string "SWIMMERS like me?\p"
	.string "Aww, don't be hatin'!\n"
	.string "Battle with me again.$"

FortuneIsland_WaterPath_Text_DeniseRematchIntro::
	.string "Sigh…\n"
	.string "My boyfriend's busy again…$"

FortuneIsland_WaterPath_Text_EarlRematchIntro::
	.string "Come on, tell me, where are the\n"
	.string "mountains around these parts?$"

FortuneIsland_WaterPath_Text_MiuRematchIntro::
	.string "MIU: Hello, POKéMON!\n"
	.string "It's time to play again!$"

FortuneIsland_WaterPath_Text_MiaRematchIntro::
	.string "MIA: Hello, POKéMON!\n"
	.string "It's time to battle again!$"

FortuneIsland_WaterPath_EventScript_HornWantedSign::
	msgbox FortuneIsland_WaterPath_Text_WantedUltimateHorn, MSGBOX_SIGN
	end

FortuneIsland_WaterPath_EventScript_RouteSign::
	msgbox FortuneIsland_WaterPath_Text_RouteSign, MSGBOX_SIGN
	end
FortuneIsland_WaterPath_Text_RoseIntro::
    .string "I let a pleasant breeze lead me\n"
    .string "all the way here.$"

FortuneIsland_WaterPath_Text_RoseDefeat::
    .string "Giggle… You're so cute when you're\n"
    .string "determined.$"

FortuneIsland_WaterPath_Text_RosePostBattle::
    .string "I want to go to the woods over\n"
    .string "there, but…\p"
    .string "There are lots of BUG POKéMON.\n"
    .string "They scare me a little.$"

FortuneIsland_WaterPath_Text_EdwardIntro::
    .string "I'm practicing in secret so no one\n"
    .string "can see me.$"

FortuneIsland_WaterPath_Text_EdwardDefeat::
    .string "Nobody saw me losing, right?$"

FortuneIsland_WaterPath_Text_EdwardPostBattle::
    .string "As a performer, I don't want people\n"
    .string "to know about the effort I put in.$"

FortuneIsland_WaterPath_Text_SamirIntro::
    .string "What, you're suggesting that you're\n"
    .string "sick of seeing SWIMMERS like me?\p"
    .string "Aww, don't be hatin'!$"

FortuneIsland_WaterPath_Text_SamirDefeat::
    .string "Oh, no, no, no.$"

FortuneIsland_WaterPath_Text_SamirPostBattle::
    .string "I couldn't lift the stigma of being\n"
    .string "a SWIMMER…$"

FortuneIsland_WaterPath_Text_DeniseIntro::
    .string "My boyfriend's always busy, so I\n"
    .string "come swimming by myself.$"

FortuneIsland_WaterPath_Text_DeniseDefeat::
    .string "Awww, I knew this would happen!$"

FortuneIsland_WaterPath_Text_DenisePostBattle::
    .string "When I can't be with my boyfriend,\n"
    .string "I spend time with the POKéMON he\l"
    .string "gave me.$"

FortuneIsland_WaterPath_Text_EarlIntro::
    .string "Tell me, where are the mountains\n"
    .string "around these parts?$"

FortuneIsland_WaterPath_Text_EarlDefeat::
    .string "I lost my way while I was busy\n"
    .string "battling!$"

FortuneIsland_WaterPath_Text_EarlPostBattle::
    .string "Aren't there any mountains around\n"
    .string "these parts?$"

FortuneIsland_WaterPath_Text_MiuIntro::
    .string "MIU: Hello, POKéMON!\n"
    .string "It's time to play!$"

FortuneIsland_WaterPath_Text_MiuDefeat::
    .string "MIU: Oh, no!\n"
    .string "Mommy!$"

FortuneIsland_WaterPath_Text_MiuPostBattle::
    .string "MIU: It makes me all sad inside\n"
    .string "when we lose…$"

FortuneIsland_WaterPath_Text_MiuNotEnoughMons::
    .string "MIU: MIA and I are TWINS.\n"
    .string "We want to battle together.$"

FortuneIsland_WaterPath_Text_MiaIntro::
    .string "MIA: Hello, POKéMON!\n"
    .string "It's time to battle!$"

FortuneIsland_WaterPath_Text_MiaDefeat::
    .string "MIA: You're mean!\n"
    .string "You're bad for winning!$"

FortuneIsland_WaterPath_Text_MiaPostBattle::
    .string "MIA: Ohh…\n"
    .string "I'm sorry, my POKéMON…$"

FortuneIsland_WaterPath_Text_MiaNotEnoughMons::
    .string "MIA: Oh, you only have one\n"
    .string "POKéMON?\p"
    .string "Don't you feel lonesome?$"

FortuneIsland_WaterPath_Text_WantedUltimateHorn::
    .string "Wanted!\n"
    .string "The Ultimate Horn!$"

FortuneIsland_WaterPath_Text_RouteSign::
    .string "WATER PATH\n"
    .string "Leads to RUIN VALLEY$"

