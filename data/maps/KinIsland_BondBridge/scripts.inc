KinIsland_BondBridge_MapScripts::
	.byte 0

KinIsland_BondBridge_EventScript_Nikki::
	trainerbattle_single TRAINER_AROMA_LADY_NIKKI, KinIsland_BondBridge_Text_NikkiIntro, KinIsland_BondBridge_Text_NikkiDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, KinIsland_BondBridge_EventScript_NikkiRematch
	msgbox KinIsland_BondBridge_Text_NikkiPostBattle, MSGBOX_AUTOCLOSE
	end

KinIsland_BondBridge_EventScript_NikkiRematch::
	trainerbattle_rematch TRAINER_CLIFFORD, KinIsland_BondBridge_Text_NikkiRematchIntro, KinIsland_BondBridge_Text_NikkiDefeat
	msgbox KinIsland_BondBridge_Text_NikkiPostBattle, MSGBOX_AUTOCLOSE
	end

KinIsland_BondBridge_EventScript_Violet::
	trainerbattle_single TRAINER_AROMA_LADY_VIOLET, KinIsland_BondBridge_Text_VioletIntro, KinIsland_BondBridge_Text_VioletDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, KinIsland_BondBridge_EventScript_VioletRematch
	msgbox KinIsland_BondBridge_Text_VioletPostBattle, MSGBOX_AUTOCLOSE
	end

KinIsland_BondBridge_EventScript_VioletRematch::
	trainerbattle_rematch TRAINER_CLIFFORD, KinIsland_BondBridge_Text_VioletRematchIntro, KinIsland_BondBridge_Text_VioletDefeat
	msgbox KinIsland_BondBridge_Text_VioletPostBattle, MSGBOX_AUTOCLOSE
	end

KinIsland_BondBridge_EventScript_Amira::
	trainerbattle_single TRAINER_TUBER_AMIRA, KinIsland_BondBridge_Text_AmiraIntro, KinIsland_BondBridge_Text_AmiraDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, KinIsland_BondBridge_EventScript_AmiraRematch
	msgbox KinIsland_BondBridge_Text_AmiraPostBattle, MSGBOX_AUTOCLOSE
	end

KinIsland_BondBridge_EventScript_AmiraRematch::
	trainerbattle_rematch TRAINER_CLIFFORD, KinIsland_BondBridge_Text_AmiraRematchIntro, KinIsland_BondBridge_Text_AmiraDefeat
	msgbox KinIsland_BondBridge_Text_AmiraPostBattle, MSGBOX_AUTOCLOSE
	end

KinIsland_BondBridge_EventScript_Alexis::
	trainerbattle_single TRAINER_TUBER_ALEXIS, KinIsland_BondBridge_Text_AlexisIntro, KinIsland_BondBridge_Text_AlexisDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, KinIsland_BondBridge_EventScript_AlexisRematch
	msgbox KinIsland_BondBridge_Text_AlexisPostBattle, MSGBOX_AUTOCLOSE
	end

KinIsland_BondBridge_EventScript_AlexisRematch::
	trainerbattle_rematch TRAINER_CLIFFORD, KinIsland_BondBridge_Text_AlexisRematchIntro, KinIsland_BondBridge_Text_AlexisDefeat
	msgbox KinIsland_BondBridge_Text_AlexisPostBattle, MSGBOX_AUTOCLOSE
	end

KinIsland_BondBridge_EventScript_Tisha::
	trainerbattle_single TRAINER_SWIMMER_FEMALE_TISHA, KinIsland_BondBridge_Text_TishaIntro, KinIsland_BondBridge_Text_TishaDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, KinIsland_BondBridge_EventScript_TishaRematch
	msgbox KinIsland_BondBridge_Text_TishaPostBattle, MSGBOX_AUTOCLOSE
	end

KinIsland_BondBridge_EventScript_TishaRematch::
	trainerbattle_rematch TRAINER_CLIFFORD, KinIsland_BondBridge_Text_TishaRematchIntro, KinIsland_BondBridge_Text_TishaDefeat
	msgbox KinIsland_BondBridge_Text_TishaPostBattle, MSGBOX_AUTOCLOSE
	end

KinIsland_BondBridge_EventScript_Joy::
	trainerbattle_double TRAINER_TWINS_JOY_MEG, KinIsland_BondBridge_Text_JoyIntro, KinIsland_BondBridge_Text_JoyDefeat, KinIsland_BondBridge_Text_JoyNotEnoughMons
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, KinIsland_BondBridge_EventScript_JoyRematch
	msgbox KinIsland_BondBridge_Text_JoyPostBattle, MSGBOX_AUTOCLOSE
	end

KinIsland_BondBridge_EventScript_JoyRematch::
	trainerbattle_rematch TRAINER_CLIFFORD, KinIsland_BondBridge_Text_JoyRematchIntro, KinIsland_BondBridge_Text_JoyDefeat
	msgbox KinIsland_BondBridge_Text_JoyPostBattle, MSGBOX_AUTOCLOSE
	end

KinIsland_BondBridge_EventScript_Meg::
	trainerbattle_double TRAINER_TWINS_JOY_MEG, KinIsland_BondBridge_Text_MegIntro, KinIsland_BondBridge_Text_MegDefeat, KinIsland_BondBridge_Text_MegNotEnoughMons
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, KinIsland_BondBridge_EventScript_MegRematch
	msgbox KinIsland_BondBridge_Text_MegPostBattle, MSGBOX_AUTOCLOSE
	end

KinIsland_BondBridge_EventScript_MegRematch::
	trainerbattle_rematch TRAINER_CLIFFORD, KinIsland_BondBridge_Text_MegRematchIntro, KinIsland_BondBridge_Text_MegDefeat
	msgbox KinIsland_BondBridge_Text_MegPostBattle, MSGBOX_AUTOCLOSE
	end

KinIsland_BondBridge_EventScript_BerryForestSign::
	msgbox KinIsland_BondBridge_Text_BerryForestAhead, MSGBOX_SIGN
	end

KinIsland_BondBridge_EventScript_BondBridgeSign::
	msgbox KinIsland_BondBridge_Text_BondBridgeSign, MSGBOX_SIGN
	end

KinIsland_BondBridge_Text_NikkiIntro::
    .string "The salty tang of the sea…\n"
    .string "It tickles my heart.$"

KinIsland_BondBridge_Text_NikkiDefeat::
    .string "…Sniff, sniff…\n"
    .string "Something smells unpleasant…$"

KinIsland_BondBridge_Text_NikkiPostBattle::
    .string "Perhaps that reek is your sweaty\n"
    .string "POKéMON's body odor…$"

KinIsland_BondBridge_Text_VioletIntro::
    .string "Where are you off to in such\n"
    .string "a hurry?$"

KinIsland_BondBridge_Text_VioletDefeat::
    .string "You're raising some wonderful\n"
    .string "POKéMON.$"

KinIsland_BondBridge_Text_VioletPostBattle::
    .string "If you keep going this way, you'll\n"
    .string "eventually reach BERRY FOREST.$"

KinIsland_BondBridge_Text_AmiraIntro::
    .string "My mommy said that I can't swim\n"
    .string "without my float ring.$"

KinIsland_BondBridge_Text_AmiraDefeat::
    .string "Waaah!\n"
    .string "Waaah!$"

KinIsland_BondBridge_Text_AmiraPostBattle::
    .string "This year, I'm going to finally\n"
    .string "learn how to swim!$"

KinIsland_BondBridge_Text_AlexisIntro::
    .string "Yay, yay!\n"
    .string "POKéMON!$"

KinIsland_BondBridge_Text_AlexisDefeat::
    .string "What happens now?$"

KinIsland_BondBridge_Text_AlexisPostBattle::
    .string "Did I just win?\n"
    .string "Or did I lose?$"

KinIsland_BondBridge_Text_TishaIntro::
    .string "Oh, no, don't come here!\n"
    .string "Please, stay away from me!$"

KinIsland_BondBridge_Text_TishaDefeat::
    .string "Okay, you've won!\n"
    .string "Now will you please go away?$"

KinIsland_BondBridge_Text_TishaPostBattle::
    .string "A POKéMON bit through my \n"
    .string "swimsuit.\p"
    .string "I can't get out of the water!$"

KinIsland_BondBridge_Text_JoyIntro::
    .string "JOY: We'll teach you what our\n"
    .string "favorite POKéMON is!$"

KinIsland_BondBridge_Text_JoyDefeat::
    .string "JOY: Ohh…\n"
    .string "MEG!$"

KinIsland_BondBridge_Text_JoyPostBattle::
    .string "JOY: Wasn't that fun?\n"
    .string "I hope we can battle again!$"

KinIsland_BondBridge_Text_JoyNotEnoughMons::
    .string "JOY: I really want to battle with\n"
    .string "MEG.\p"
    .string "One POKéMON isn't enough.$"

KinIsland_BondBridge_Text_MegIntro::
    .string "MEG: We'll show you our favorite\n"
    .string "POKéMON.$"

KinIsland_BondBridge_Text_MegDefeat::
    .string "MEG: Ohh…\n"
    .string "JOY!$"

KinIsland_BondBridge_Text_MegPostBattle::
    .string "MEG: JOY, wasn't that fun?$"

KinIsland_BondBridge_Text_MegNotEnoughMons::
    .string "MEG: I want to battle together\n"
    .string "with JOY.\p"
    .string "One POKéMON isn't enough.$"

KinIsland_BondBridge_Text_NikkiRematchIntro::
	.string "Are we to battle again?$"

KinIsland_BondBridge_Text_VioletRematchIntro::
	.string "From where have you come, and\n"
	.string "where are you bound?$"

KinIsland_BondBridge_Text_AmiraRematchIntro::
	.string "I want to swim without my float\n"
	.string "ring soon.$"

KinIsland_BondBridge_Text_AlexisRematchIntro::
	.string "Yay, yay!\n"
	.string "POKéMON!$"

KinIsland_BondBridge_Text_TishaRematchIntro::
	.string "Oh, no, didn't I tell you already?\n"
	.string "Please, stay away from me!$"

KinIsland_BondBridge_Text_JoyRematchIntro::
	.string "JOY: We've gotten stronger!\n"
	.string "Lots and lots!$"

KinIsland_BondBridge_Text_MegRematchIntro::
	.string "MEG: You can't beat us today!$"

KinIsland_BondBridge_Text_BerryForestAhead::
    .string "BERRY FOREST AHEAD$"

KinIsland_BondBridge_Text_BondBridgeSign::
    .string "BOND BRIDGE\n"
    .string "Please be quiet when crossing.\p"
    .string "BERRY FOREST AHEAD$"

