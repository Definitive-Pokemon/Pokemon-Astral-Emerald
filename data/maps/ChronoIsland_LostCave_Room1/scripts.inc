.set LOCALID_HIKER, 1
.set LOCALID_SAMUEL, 2
.set LOCALID_AGATHA, 3

ChronoIsland_LostCave_Room1_MapScripts::
	.byte 0

ChronoIsland_LostCave_Room1_EventScript_Lawson::
	trainerbattle_single TRAINER_RUIN_MANIAC_LAWSON, ChronoIsland_LostCave_Room1_Text_LawsonIntro, ChronoIsland_LostCave_Room1_Text_LawsonDefeat
	msgbox ChronoIsland_LostCave_Room1_Text_LawsonPostBattle, MSGBOX_AUTOCLOSE
	end

ChronoIsland_LostCave_Entrance_EventScript_CelebiEvent2::
	lockall
	applymovement LOCALID_SAMUEL, ChronoIsland_LostCave_Room1_Movement_Oak1
	waitmovement 0
	textcolor 0
	msgbox ChronoIsland_LostCave_Room1_Text_Oak1
	closemessage
	applymovement LOCALID_AGATHA, ChronoIsland_LostCave_Room1_Movement_Agatha1
	waitmovement 0
	textcolor 1
	msgbox ChronoIsland_LostCave_Room1_Text_Agatha1
	closemessage
	applymovement LOCALID_AGATHA, ChronoIsland_LostCave_Room1_Movement_Agatha2
	waitmovement 0
	applymovement LOCALID_SAMUEL, ChronoIsland_LostCave_Room1_Movement_Oak2
	waitmovement 0
	msgbox ChronoIsland_LostCave_Room1_Text_Agatha2
	closemessage
	applymovement LOCALID_SAMUEL, ChronoIsland_LostCave_Room1_Movement_Oak3
	waitmovement 0
	textcolor 0
	msgbox ChronoIsland_LostCave_Room1_Text_Oak2
	closemessage
	applymovement LOCALID_AGATHA, ChronoIsland_LostCave_Room1_Movement_Agatha3
	waitmovement 0
	textcolor 1
	msgbox ChronoIsland_LostCave_Room1_Text_Agatha3
	closemessage
	applymovement LOCALID_SAMUEL, ChronoIsland_LostCave_Room1_Movement_Oak4
	applymovement LOCALID_AGATHA, ChronoIsland_LostCave_Room1_Movement_Agatha4
	waitmovement 0
	removeobject LOCALID_SAMUEL
	playse SE_EXIT
	applymovement LOCALID_AGATHA, ChronoIsland_LostCave_Room1_Movement_Agatha5
	waitmovement 0
	removeobject LOCALID_AGATHA
	playse SE_EXIT
	setflag FLAG_HIDE_DUO2
	clearflag FLAG_HIDE_DUO3
	delay 20
	setvar VAR_CELEBI_EVENT2, 2
	setvar VAR_CELEBI_EVENT3, 1
	releaseall
	end
	
ChronoIsland_LostCave_Room1_Text_Oak1::
	.string "I think we should just take a pick…$"
	
ChronoIsland_LostCave_Room1_Text_Agatha1::
	.string "…always so impulsive.\n"
	.string "Let me take a good look first.$"
	
ChronoIsland_LostCave_Room1_Text_Agatha2::
	.string "Found it!\p"
	.string "Three rocks means going right,\n"
	.string "corresponding to the position\l"
	.string "of the number three on the clock!$"
	
ChronoIsland_LostCave_Room1_Text_Oak2::
	.string "You always amaze me with your\n"
	.string "spatial awareness…$"
	
ChronoIsland_LostCave_Room1_Text_Agatha3::
	.string "Stop it, you're making me blush!\p"
	.string "Let's get a move on!$"
	
ChronoIsland_LostCave_Room1_Movement_Oak1::
	walk_in_place_right
	step_end
	
ChronoIsland_LostCave_Room1_Movement_Agatha1::
	walk_in_place_left
	step_end
	
ChronoIsland_LostCave_Room1_Movement_Agatha2::
	face_up
	delay_16
	delay_16
	face_left
	delay_16
	delay_16
	face_down
	delay_16
	delay_16
	walk_down
	walk_down
	delay_16
	delay_16
	walk_in_place_right
	walk_in_place_right
	delay_16
	delay_16
	walk_left
	walk_left
	walk_left
	delay_16
	delay_16
	walk_in_place_down
	walk_in_place_down
	delay_16
	delay_16
	walk_up
	walk_up
	delay_16
	delay_16
	walk_in_place_up
	walk_in_place_up
	delay_16
	delay_16
	face_right
	delay_16
	walk_in_place_right
	step_end
	
ChronoIsland_LostCave_Room1_Movement_Oak2::
	walk_in_place_left
	step_end
	
ChronoIsland_LostCave_Room1_Movement_Oak3::
	walk_in_place_left
	step_end
	
ChronoIsland_LostCave_Room1_Movement_Agatha3::
	walk_in_place_right
	step_end
	
ChronoIsland_LostCave_Room1_Movement_Oak4::
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_right
	step_end
	
ChronoIsland_LostCave_Room1_Movement_Agatha4::
	walk_right
	walk_right
	walk_right
	walk_right
	step_end
	
ChronoIsland_LostCave_Room1_Movement_Agatha5::
	walk_right
	walk_in_place_right
	step_end

ChronoIsland_LostCave_Room1_Text_LawsonIntro::
    .string "Aiyeeeeeh!\p"
    .string "I thought this was an ancient ruin.\n"
    .string "But it's teeming with ghosts!$"

ChronoIsland_LostCave_Room1_Text_LawsonDefeat::
    .string "Aiyeeeeeh!\n"
    .string "Mercy!$"

ChronoIsland_LostCave_Room1_Text_LawsonPostBattle::
    .string "I'm trying to get out of here, but\n"
    .string "I always end up at the same spot.\p"
    .string "Maybe the number of boulders is\n"
    .string "a hint…$"

