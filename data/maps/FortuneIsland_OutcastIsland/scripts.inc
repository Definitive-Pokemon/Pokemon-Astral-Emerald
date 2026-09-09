FortuneIsland_OutcastIsland_MapScripts::
	.byte 0

FortuneIsland_OutcastIsland_EventScript_Tylor::
	trainerbattle_single TRAINER_FISHERMAN_TYLOR, FortuneIsland_OutcastIsland_Text_TylorIntro, FortuneIsland_OutcastIsland_Text_TylorDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, FortuneIsland_OutcastIsland_EventScript_TylorRematch
	msgbox FortuneIsland_OutcastIsland_Text_TylorPostBattle, MSGBOX_AUTOCLOSE
	end

FortuneIsland_OutcastIsland_EventScript_TylorRematch::
	trainerbattle_rematch TRAINER_CLIFFORD, FortuneIsland_OutcastIsland_Text_TylorRematchIntro, FortuneIsland_OutcastIsland_Text_TylorDefeat
	msgbox FortuneIsland_OutcastIsland_Text_TylorPostBattle, MSGBOX_AUTOCLOSE
	end

FortuneIsland_OutcastIsland_EventScript_Mymo::
	trainerbattle_single TRAINER_SWIMMER_MALE_MYMO, FortuneIsland_OutcastIsland_Text_MymoIntro, FortuneIsland_OutcastIsland_Text_MymoDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, FortuneIsland_OutcastIsland_EventScript_MymoRematch
	msgbox FortuneIsland_OutcastIsland_Text_MymoPostBattle, MSGBOX_AUTOCLOSE
	end

FortuneIsland_OutcastIsland_EventScript_MymoRematch::
	trainerbattle_rematch TRAINER_CLIFFORD, FortuneIsland_OutcastIsland_Text_MymoRematchIntro, FortuneIsland_OutcastIsland_Text_MymoDefeat
	msgbox FortuneIsland_OutcastIsland_Text_MymoPostBattle, MSGBOX_AUTOCLOSE
	end

FortuneIsland_OutcastIsland_EventScript_Nicole::
	trainerbattle_single TRAINER_SWIMMER_FEMALE_NICOLE, FortuneIsland_OutcastIsland_Text_NicoleIntro, FortuneIsland_OutcastIsland_Text_NicoleDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, FortuneIsland_OutcastIsland_EventScript_NicoleRematch
	msgbox FortuneIsland_OutcastIsland_Text_NicolePostBattle, MSGBOX_AUTOCLOSE
	end

FortuneIsland_OutcastIsland_EventScript_NicoleRematch::
	trainerbattle_rematch TRAINER_CLIFFORD, FortuneIsland_OutcastIsland_Text_NicoleRematchIntro, FortuneIsland_OutcastIsland_Text_NicoleDefeat
	msgbox FortuneIsland_OutcastIsland_Text_NicolePostBattle, MSGBOX_AUTOCLOSE
	end

FortuneIsland_OutcastIsland_EventScript_Ava::
	trainerbattle_double TRAINER_SIS_AND_BRO_AVA_GEB, FortuneIsland_OutcastIsland_Text_AvaIntro, FortuneIsland_OutcastIsland_Text_AvaDefeat, FortuneIsland_OutcastIsland_Text_AvaNotEnoughMons
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, FortuneIsland_OutcastIsland_EventScript_AvaRematch
	msgbox FortuneIsland_OutcastIsland_Text_AvaPostBattle, MSGBOX_AUTOCLOSE
	end

FortuneIsland_OutcastIsland_EventScript_AvaRematch::
	trainerbattle_rematch TRAINER_CLIFFORD, FortuneIsland_OutcastIsland_Text_AvaRematchIntro, FortuneIsland_OutcastIsland_Text_AvaDefeat
	msgbox FortuneIsland_OutcastIsland_Text_AvaPostBattle, MSGBOX_AUTOCLOSE
	end

FortuneIsland_OutcastIsland_EventScript_Geb::
	trainerbattle_double TRAINER_SIS_AND_BRO_AVA_GEB, FortuneIsland_OutcastIsland_Text_GebIntro, FortuneIsland_OutcastIsland_Text_GebDefeat, FortuneIsland_OutcastIsland_Text_GebNotEnoughMons
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, FortuneIsland_OutcastIsland_EventScript_GebRematch
	msgbox FortuneIsland_OutcastIsland_Text_GebPostBattle, MSGBOX_AUTOCLOSE
	end

FortuneIsland_OutcastIsland_EventScript_GebRematch::
	trainerbattle_rematch TRAINER_CLIFFORD, FortuneIsland_OutcastIsland_Text_GebRematchIntro, FortuneIsland_OutcastIsland_Text_GebDefeat
	msgbox FortuneIsland_OutcastIsland_Text_GebPostBattle, MSGBOX_AUTOCLOSE
	end

FortuneIsland_OutcastIsland_Text_TylorRematchIntro::
	.string "I'm still having no luck at all.\n"
	.string "A battle'd be a change of pace!$"

FortuneIsland_OutcastIsland_Text_MymoRematchIntro::
	.string "Gasp… Gasp…\p"
	.string "I swam here from SIX ISLAND's port\n"
	.string "in one go again.$"

FortuneIsland_OutcastIsland_Text_NicoleRematchIntro::
	.string "You always come along while I'm\n"
	.string "swimming.$"

FortuneIsland_OutcastIsland_Text_AvaRematchIntro::
	.string "AVA: Let's have another\n"
	.string "two-on-two marine battle today!$"

FortuneIsland_OutcastIsland_Text_GebRematchIntro::
	.string "GEB: My big sister and I are way\n"
	.string "tougher than before!$"

FortuneIsland_OutcastIsland_EventScript_Rocket::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_46, FortuneIsland_OutcastIsland_Text_RocketIntro, FortuneIsland_OutcastIsland_Text_RocketDefeat
	msgbox FortuneIsland_OutcastIsland_Text_RocketPostBattle, MSGBOX_AUTOCLOSE
	end

FortuneIsland_OutcastIsland_Text_RocketIntro::
    .string "There're no rare POKéMON around\n"
    .string "these parts! Not a one!\p"
    .string "That burns me up, man.\n"
    .string "I'll take it out on you!$"

FortuneIsland_OutcastIsland_Text_RocketDefeat::
    .string "…Huh?$"

FortuneIsland_OutcastIsland_Text_RocketPostBattle::
    .string "So listen, you haven't seen any\n"
    .string "rare POKéMON, have you?$"

FortuneIsland_OutcastIsland_Text_TylorIntro::
    .string "I'm having no luck at all.\n"
    .string "A battle'd be a change of pace!$"

FortuneIsland_OutcastIsland_Text_TylorDefeat::
    .string "Nope, no luck at all…$"

FortuneIsland_OutcastIsland_Text_TylorPostBattle::
    .string "I can't very well go home without\n"
    .string "catching something, though.$"

FortuneIsland_OutcastIsland_Text_MymoIntro::
    .string "Gasp… Gasp…\p"
    .string "I swam here from SIX ISLE PORT\n"
    .string "in one go.$"

FortuneIsland_OutcastIsland_Text_MymoDefeat::
    .string "Gasp…\n"
    .string "Gasp…$"

FortuneIsland_OutcastIsland_Text_MymoPostBattle::
    .string "I'm only at the halfway point…\n"
    .string "I'm beat…$"

FortuneIsland_OutcastIsland_Text_NicoleIntro::
    .string "It's not so easy sending POKéMON\n"
    .string "out while swimming, you know?$"

FortuneIsland_OutcastIsland_Text_NicoleDefeat::
    .string "I didn't lose to you at swimming.\n"
    .string "This doesn't bother me.$"

FortuneIsland_OutcastIsland_Text_NicolePostBattle::
    .string "Are you headed for the island up\n"
    .string "past here?\p"
    .string "I didn't see anything interesting\n"
    .string "there.$"

FortuneIsland_OutcastIsland_Text_AvaIntro::
    .string "AVA: Let's have a two-on-two\n"
    .string "marine battle!$"

FortuneIsland_OutcastIsland_Text_AvaDefeat::
    .string "AVA: Oh, you're amazing!\n"
    .string "Even better, you're on your own!$"

FortuneIsland_OutcastIsland_Text_AvaPostBattle::
    .string "AVA: You know, I do prefer the\n"
    .string "sea over any pool.$"

FortuneIsland_OutcastIsland_Text_AvaNotEnoughMons::
    .string "AVA: You're challenging us to\n"
    .string "a battle?\p"
    .string "You'll need at least two POKéMON\n"
    .string "if you want to do that.$"

FortuneIsland_OutcastIsland_Text_GebIntro::
    .string "GEB: Big Sister, help!\n"
    .string "Please battle with me!$"

FortuneIsland_OutcastIsland_Text_GebDefeat::
    .string "GEB: Wow, Big Sister, this person's\n"
    .string "really good!$"

FortuneIsland_OutcastIsland_Text_GebPostBattle::
    .string "GEB: I'm hanging onto my sister\n"
    .string "because I can't touch the bottom.$"

FortuneIsland_OutcastIsland_Text_GebNotEnoughMons::
    .string "GEB: Please battle against me and\n"
    .string "my sister!\p"
    .string "…Oh, you don't have two POKéMON?$"
