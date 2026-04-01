QuestIsland_SevaultCanyon_Entrance_MapScripts::
	.byte 0

QuestIsland_SevaultCanyon_Entrance_EventScript_RouteSign::
	msgbox QuestIsland_SevaultCanyon_Entrance_Text_RouteSign, MSGBOX_SIGN
	end

QuestIsland_SevaultCanyon_Entrance_EventScript_Miah::
	trainerbattle_single TRAINER_AROMA_LADY_MIAH, QuestIsland_SevaultCanyon_Entrance_Text_MiahIntro, QuestIsland_SevaultCanyon_Entrance_Text_MiahDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, QuestIsland_SevaultCanyon_Entrance_EventScript_MiahRematch
	msgbox QuestIsland_SevaultCanyon_Entrance_Text_MiahPostBattle, MSGBOX_AUTOCLOSE
	end

QuestIsland_SevaultCanyon_Entrance_EventScript_MiahRematch::
	trainerbattle_rematch TRAINER_CLIFFORD, QuestIsland_SevaultCanyon_Entrance_Text_MiahRematchIntro, QuestIsland_SevaultCanyon_Entrance_Text_MiahDefeat
	msgbox QuestIsland_SevaultCanyon_Entrance_Text_MiahPostBattle, MSGBOX_AUTOCLOSE
	end

QuestIsland_SevaultCanyon_Entrance_EventScript_Eve::
	trainerbattle_double TRAINER_YOUNG_COUPLE_EVE_JON, QuestIsland_SevaultCanyon_Entrance_Text_EveIntro, QuestIsland_SevaultCanyon_Entrance_Text_EveDefeat, QuestIsland_SevaultCanyon_Entrance_Text_EveNotEnoughMons
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, QuestIsland_SevaultCanyon_Entrance_EventScript_EveRematch
	msgbox QuestIsland_SevaultCanyon_Entrance_Text_EvePostBattle, MSGBOX_AUTOCLOSE
	end

QuestIsland_SevaultCanyon_Entrance_EventScript_EveRematch::
	trainerbattle_rematch TRAINER_CLIFFORD, QuestIsland_SevaultCanyon_Entrance_Text_EveRematchIntro, QuestIsland_SevaultCanyon_Entrance_Text_EveDefeat
	msgbox QuestIsland_SevaultCanyon_Entrance_Text_EvePostBattle, MSGBOX_AUTOCLOSE
	end

QuestIsland_SevaultCanyon_Entrance_EventScript_Jon::
	trainerbattle_double TRAINER_YOUNG_COUPLE_EVE_JON, QuestIsland_SevaultCanyon_Entrance_Text_JonIntro, QuestIsland_SevaultCanyon_Entrance_Text_JonDefeat, QuestIsland_SevaultCanyon_Entrance_Text_JonNotEnoughMons
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, QuestIsland_SevaultCanyon_Entrance_EventScript_JonRematch
	msgbox QuestIsland_SevaultCanyon_Entrance_Text_JonPostBattle, MSGBOX_AUTOCLOSE
	end

QuestIsland_SevaultCanyon_Entrance_EventScript_JonRematch::
	trainerbattle_rematch TRAINER_CLIFFORD, QuestIsland_SevaultCanyon_Entrance_Text_JonRematchIntro, QuestIsland_SevaultCanyon_Entrance_Text_JonDefeat
	msgbox QuestIsland_SevaultCanyon_Entrance_Text_JonPostBattle, MSGBOX_AUTOCLOSE
	end

QuestIsland_SevaultCanyon_Entrance_EventScript_Mason::
	trainerbattle_single TRAINER_JUGGLER_MASON, QuestIsland_SevaultCanyon_Entrance_Text_MasonIntro, QuestIsland_SevaultCanyon_Entrance_Text_MasonDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, QuestIsland_SevaultCanyon_Entrance_EventScript_MasonRematch
	msgbox QuestIsland_SevaultCanyon_Entrance_Text_MasonPostBattle, MSGBOX_AUTOCLOSE
	end

QuestIsland_SevaultCanyon_Entrance_EventScript_MasonRematch::
	trainerbattle_rematch TRAINER_CLIFFORD, QuestIsland_SevaultCanyon_Entrance_Text_MasonRematchIntro, QuestIsland_SevaultCanyon_Entrance_Text_MasonDefeat
	msgbox QuestIsland_SevaultCanyon_Entrance_Text_MasonPostBattle, MSGBOX_AUTOCLOSE
	end

QuestIsland_SevaultCanyon_Entrance_EventScript_Nicolas::
	trainerbattle_single TRAINER_PKMN_RANGER_NICOLAS, QuestIsland_SevaultCanyon_Entrance_Text_NicolasIntro, QuestIsland_SevaultCanyon_Entrance_Text_NicolasDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, QuestIsland_SevaultCanyon_Entrance_EventScript_NicolasRematch
	msgbox QuestIsland_SevaultCanyon_Entrance_Text_NicolasPostBattle, MSGBOX_AUTOCLOSE
	end

QuestIsland_SevaultCanyon_Entrance_EventScript_NicolasRematch::
	trainerbattle_rematch TRAINER_CLIFFORD, QuestIsland_SevaultCanyon_Entrance_Text_NicolasRematchIntro, QuestIsland_SevaultCanyon_Entrance_Text_NicolasDefeat
	msgbox QuestIsland_SevaultCanyon_Entrance_Text_NicolasPostBattle, MSGBOX_AUTOCLOSE
	end

QuestIsland_SevaultCanyon_Entrance_EventScript_Madeline::
	trainerbattle_single TRAINER_PKMN_RANGER_MADELINE, QuestIsland_SevaultCanyon_Entrance_Text_MadelineIntro, QuestIsland_SevaultCanyon_Entrance_Text_MadelineDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, QuestIsland_SevaultCanyon_Entrance_EventScript_MadelineRematch
	msgbox QuestIsland_SevaultCanyon_Entrance_Text_MadelinePostBattle, MSGBOX_AUTOCLOSE
	end

QuestIsland_SevaultCanyon_Entrance_EventScript_MadelineRematch::
	trainerbattle_rematch TRAINER_CLIFFORD, QuestIsland_SevaultCanyon_Entrance_Text_MadelineRematchIntro, QuestIsland_SevaultCanyon_Entrance_Text_MadelineDefeat
	msgbox QuestIsland_SevaultCanyon_Entrance_Text_MadelinePostBattle, MSGBOX_AUTOCLOSE
	end

    QuestIsland_SevaultCanyon_Entrance_Text_MiahRematchIntro::
	.string "Kyahaha!\p"
	.string "Coming back won't change a thing.\n"
	.string "I'll flick you away effortlessly!$"

QuestIsland_SevaultCanyon_Entrance_Text_MasonRematchIntro::
	.string "Howdy! You're a member of my\n"
	.string "fan club, isn't that right?$"

QuestIsland_SevaultCanyon_Entrance_Text_NicolasRematchIntro::
	.string "This island is too spread out…\n"
	.string "Patrolling the place is a drag…$"

QuestIsland_SevaultCanyon_Entrance_Text_MadelineRematchIntro::
	.string "I don't forgive people who abuse\n"
	.string "POKéMON!$"

QuestIsland_SevaultCanyon_Entrance_Text_EveRematchIntro::
	.string "EVE: I'll team up with JON and\n"
	.string "battle together again.$"

QuestIsland_SevaultCanyon_Entrance_Text_JonRematchIntro::
	.string "JON: When I'm with EVE, it feels\n"
	.string "like we could never lose, not ever.$"


QuestIsland_SevaultCanyon_Entrance_Text_MiahIntro::
    .string "Kyahaha!\n"
    .string "I'll flick you away effortlessly!$"

QuestIsland_SevaultCanyon_Entrance_Text_MiahDefeat::
    .string "Tch!\n"
    .string "Too strong for me!$"

QuestIsland_SevaultCanyon_Entrance_Text_MiahPostBattle::
    .string "What's that?\n"
    .string "I don't act the way I look?\p"
    .string "Heh, that's a part of my strategy!$"

QuestIsland_SevaultCanyon_Entrance_Text_MasonIntro::
    .string "Howdy!\n"
    .string "Are you a member of my fan club?$"

QuestIsland_SevaultCanyon_Entrance_Text_MasonDefeat::
    .string "Oh, so you're not a fan…\p"
    .string "Well, I can change that.\n"
    .string "Let me sing for you!$"

QuestIsland_SevaultCanyon_Entrance_Text_MasonPostBattle::
    .string "Lalalah…\n"
    .string "My POKéMON, I send them out,\l"
    .string "all the girls scream and shout!$"

QuestIsland_SevaultCanyon_Entrance_Text_NicolasIntro::
    .string "This island is too spread out…\n"
    .string "It's not easy patrolling the place.$"

QuestIsland_SevaultCanyon_Entrance_Text_NicolasDefeat::
    .string "Uh-huh…$"

QuestIsland_SevaultCanyon_Entrance_Text_NicolasPostBattle::
    .string "TRAINERS like you from cities,\n"
    .string "they sure are tough.\p"
    .string "You'll be headed for the TOWER,\n"
    .string "won't you?$"

QuestIsland_SevaultCanyon_Entrance_Text_MadelineIntro::
    .string "I punish people who abuse\n"
    .string "POKéMON!$"

QuestIsland_SevaultCanyon_Entrance_Text_MadelineDefeat::
    .string "You don't seem to be a problem\n"
    .string "TRAINER.$"

QuestIsland_SevaultCanyon_Entrance_Text_MadelinePostBattle::
    .string "If you treat your POKéMON with\n"
    .string "kindness, they'll understand.$"

QuestIsland_SevaultCanyon_Entrance_Text_EveIntro::
    .string "EVE: I'll team up with JON and\n"
    .string "battle together.$"

QuestIsland_SevaultCanyon_Entrance_Text_EveDefeat::
    .string "EVE: Me and JON, we lost.\n"
    .string "Ehehe.$"

QuestIsland_SevaultCanyon_Entrance_Text_EvePostBattle::
    .string "EVE: I'm going to work harder with\n"
    .string "JON.$"

QuestIsland_SevaultCanyon_Entrance_Text_EveNotEnoughMons::
    .string "EVE: I want to team up with JON\n"
    .string "when I battle you.\p"
    .string "Come back with two POKéMON, okay?$"

QuestIsland_SevaultCanyon_Entrance_Text_JonIntro::
    .string "JON: When I'm with EVE, it feels\n"
    .string "like we could never lose.$"

QuestIsland_SevaultCanyon_Entrance_Text_JonDefeat::
    .string "JON: When I'm with EVE,\n"
    .string "it doesn't feel like I've lost!$"

QuestIsland_SevaultCanyon_Entrance_Text_JonPostBattle::
    .string "JON: When I'm with EVE, I feel\n"
    .string "giddy whether I win or lose.\p"
    .string "It's magical!$"

QuestIsland_SevaultCanyon_Entrance_Text_JonNotEnoughMons::
    .string "JON: If it's with EVE, I'll be\n"
    .string "happy to battle with you.\p"
    .string "So, I'd like to make it a\n"
    .string "two-on-two battle, if I may.$"

QuestIsland_SevaultCanyon_Entrance_Text_RouteSign::
    .string "SEVAULT CANYON ENTRANCE\p"
    .string "TRAINERS are asked to refrain from\n"
    .string "damaging plants in the CANYON.$"

