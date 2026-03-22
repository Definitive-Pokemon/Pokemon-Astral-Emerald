.set LOCALID_TOWER_TRAINER_DOUBLES1, 2
.set LOCALID_TOWER_TRAINER_SINGLES, 3
.set LOCALID_TOWER_TRAINER_KNOCKOUT, 4
.set LOCALID_TOWER_TRAINER_DOUBLES2", 5

TrainerTower_3F_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, TrainerTower_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, TrainerTower_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, TrainerTower_OnFrame
	.byte 0

@ Below scripts are unused, the identical versions in the 1F script are used instead

TrainerTower_3F_EventScript_DoublesTrainer1::
	call TrainerTower_EventScript_SpeakToDoublesTrainer1
	end

TrainerTower_3F_EventScript_SinglesTrainer::
	call TrainerTower_EventScript_SpeakToSinglesTrainer
	end

TrainerTower_3F_EventScript_KnockoutTrainer::
	call TrainerTower_EventScript_SpeakToKnockoutTrainer
	end

TrainerTower_3F_EventScript_DoublesTrainer2::
	call TrainerTower_EventScript_SpeakToDoublesTrainer2
	end

TrainerTower_3F_EventScript_Owner::
	call TrainerTower_EventScript_SpeakToOwner
	end
