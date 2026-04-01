QuestIsland_TrainerTower_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, QuestIsland_TrainerTower_OnTransition
	.byte 0

QuestIsland_TrainerTower_OnTransition::
	setvar VAR_AE_MAP_SCENE_TRAINER_TOWER, 0
	end

QuestIsland_TrainerTower_EventScript_Dario::
	trainerbattle_single TRAINER_PSYCHIC_DARIO, QuestIsland_TrainerTower_Text_DarioIntro, QuestIsland_TrainerTower_Text_DarioDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, QuestIsland_TrainerTower_EventScript_DarioRematch
	msgbox QuestIsland_TrainerTower_Text_DarioPostBattle, MSGBOX_AUTOCLOSE
	end

QuestIsland_TrainerTower_EventScript_DarioRematch::
	trainerbattle_rematch TRAINER_CLIFFORD, QuestIsland_TrainerTower_Text_DarioRematchIntro, QuestIsland_TrainerTower_Text_DarioDefeat
	msgbox QuestIsland_TrainerTower_Text_DarioPostBattle, MSGBOX_AUTOCLOSE
	end

QuestIsland_TrainerTower_EventScript_Rodette::
	trainerbattle_single TRAINER_PSYCHIC_RODETTE, QuestIsland_TrainerTower_Text_RodetteIntro, QuestIsland_TrainerTower_Text_RodetteDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, QuestIsland_TrainerTower_EventScript_RodetteRematch
	msgbox QuestIsland_TrainerTower_Text_RodettePostBattle, MSGBOX_AUTOCLOSE
	end

QuestIsland_TrainerTower_EventScript_RodetteRematch::
	trainerbattle_rematch TRAINER_CLIFFORD, QuestIsland_TrainerTower_Text_RodetteRematchIntro, QuestIsland_TrainerTower_Text_RodetteDefeat
	msgbox QuestIsland_TrainerTower_Text_RodettePostBattle, MSGBOX_AUTOCLOSE
	end

QuestIsland_TrainerTower_Text_DarioRematchIntro::
	.string "I sensed your approach.$"

QuestIsland_TrainerTower_Text_RodetteRematchIntro::
	.string "Somewhere on this island, peculiar\n"
	.string "POKéMON are sleeping.$"

QuestIsland_TrainerTower_EventScript_TrainerTowerSign::
	msgbox QuestIsland_TrainerTower_Text_TrainerTowerSign, MSGBOX_SIGN
	end

QuestIsland_TrainerTower_EventScript_TrainerTowerAheadSign::
	msgbox QuestIsland_TrainerTower_Text_TrainerTowerAhead, MSGBOX_SIGN
	end

QuestIsland_TrainerTower_Text_DarioIntro::
    .string "I sensed your approach.$"

QuestIsland_TrainerTower_Text_DarioDefeat::
    .string "Give up…$"

QuestIsland_TrainerTower_Text_DarioPostBattle::
    .string "In your future, I sense that you\n"
    .string "will meet many others.\p"
    .string "I think you will be linked to each\n"
    .string "other by a strange power.$"

QuestIsland_TrainerTower_Text_RodetteIntro::
    .string "Somewhere on this island, peculiar\n"
    .string "POKéMON are sleeping.$"

QuestIsland_TrainerTower_Text_RodetteDefeat::
    .string "What an amazing TRAINER!$"

QuestIsland_TrainerTower_Text_RodettePostBattle::
    .string "Somewhere on this island, peculiar\n"
    .string "POKéMON are sleeping.\p"
    .string "Could it be that they're waiting\n"
    .string "for you?$"

QuestIsland_TrainerTower_Text_TrainerTowerSign::
    .string "TRAINER TOWER ENTRANCE\n"
    .string "Rise to the Challenge, TRAINERS!$"

QuestIsland_TrainerTower_Text_TrainerTowerAhead::
    .string "TRAINER TOWER AHEAD$"
