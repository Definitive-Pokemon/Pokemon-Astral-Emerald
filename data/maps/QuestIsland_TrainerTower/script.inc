SevenIsland_TrainerTower_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SevenIsland_TrainerTower_OnTransition
	.byte 0

SevenIsland_TrainerTower_OnTransition::
	setvar VAR_MAP_SCENE_TRAINER_TOWER, 0
	end

SevenIsland_TrainerTower_EventScript_TrainerTowerSign::
	msgbox SevenIsland_TrainerTower_Text_TrainerTowerSign, MSGBOX_SIGN
	end

SevenIsland_TrainerTower_EventScript_TrainerTowerAheadSign::
	msgbox SevenIsland_TrainerTower_Text_TrainerTowerAhead, MSGBOX_SIGN
	end
SevenIsland_TrainerTower_Text_DarioIntro::
    .string "I sensed your approach.$"

SevenIsland_TrainerTower_Text_DarioDefeat::
    .string "Give up窶ｦ$"

SevenIsland_TrainerTower_Text_DarioPostBattle::
    .string "In your future, I sense that you\n"
    .string "will meet many others.\p"
    .string "I think you will be linked to each\n"
    .string "other by a strange power.$"

SevenIsland_TrainerTower_Text_RodetteIntro::
    .string "Somewhere on this island, peculiar\n"
    .string "POKﾃｩMON are sleeping.$"

SevenIsland_TrainerTower_Text_RodetteDefeat::
    .string "What an amazing TRAINER!$"

SevenIsland_TrainerTower_Text_RodettePostBattle::
    .string "Somewhere on this island, peculiar\n"
    .string "POKﾃｩMON are sleeping.\p"
    .string "Could it be that they're waiting\n"
    .string "for you?$"

SevenIsland_TrainerTower_Text_TrainerTowerSign::
    .string "TRAINER TOWER ENTRANCE\n"
    .string "Rise to the Challenge, TRAINERS!$"

SevenIsland_TrainerTower_Text_TrainerTowerAhead::
    .string "TRAINER TOWER AHEAD$"

@ Unused text perhaps indicating Trainer Tower was planned to be unlocked by something
SevenIsland_TrainerTower_Text_LooksLikeTrainerTowerIsClosed::
    .string "繝医Ξ繝ｼ繝翫・繧ｿ繝ｯ繝ｼ縺ｫ縺ｯ\n"
    .string "縺・∪縺ｯ縲縺ｯ縺・ｌ縺ｪ縺・縺ｿ縺溘＞窶･$"

SevenIsland_TrainerTower_Text_TrainerTowerIsOpenLetsGoIn::
    .string "繝医Ξ繝ｼ繝翫・繧ｿ繝ｯ繝ｼ縺後縺ゅ＞縺ｦ繧具ｼ―n"
    .string "縺輔▲縺昴￥縲縺ｯ縺・▲縺ｦ縺ｿ繧医≧・・"

