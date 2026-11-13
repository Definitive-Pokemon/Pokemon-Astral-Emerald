.set LOCALID_SAMUEL, 1
.set LOCALID_AGATHA, 2

ChronoIsland_LostCave_Room7_MapScripts::
	.byte 0

ChronoIsland_LostCave_Entrance_EventScript_CelebiEvent4::
	lockall
	applymovement LOCALID_AGATHA, ChronoIsland_LostCave_Room7_Movement_Agatha1
	waitmovement 0
	textcolor 1
	msgbox ChronoIsland_LostCave_Room7_Text_Agatha1
	closemessage
	applymovement LOCALID_SAMUEL, ChronoIsland_LostCave_Room7_Movement_Oak1
	waitmovement 0
	textcolor 0
	msgbox ChronoIsland_LostCave_Room7_Text_Oak1
	closemessage
	applymovement LOCALID_AGATHA, ChronoIsland_LostCave_Room7_Movement_Agatha1
	waitmovement 0
	textcolor 1
	msgbox ChronoIsland_LostCave_Room7_Text_Agatha2
	closemessage
	applymovement LOCALID_SAMUEL, ChronoIsland_LostCave_Room7_Movement_Oak1
	waitmovement 0
	textcolor 0
	msgbox ChronoIsland_LostCave_Room7_Text_Oak2
	closemessage
	applymovement LOCALID_AGATHA, ChronoIsland_LostCave_Room7_Movement_Agatha1
	waitmovement 0
	textcolor 1
	msgbox ChronoIsland_LostCave_Room7_Text_Agatha3
	closemessage
	applymovement LOCALID_SAMUEL, ChronoIsland_LostCave_Room7_Movement_Oak1
	waitmovement 0
	textcolor 0
	msgbox ChronoIsland_LostCave_Room7_Text_Oak3
	closemessage
	applymovement LOCALID_AGATHA, ChronoIsland_LostCave_Room7_Movement_Agatha1
	waitmovement 0
	textcolor 1
	msgbox ChronoIsland_LostCave_Room7_Text_Agatha4
	closemessage
	applymovement LOCALID_SAMUEL, ChronoIsland_LostCave_Room7_Movement_Oak2
	applymovement LOCALID_AGATHA, ChronoIsland_LostCave_Room7_Movement_Agatha2
	waitmovement 0
	applymovement LOCALID_SAMUEL, ChronoIsland_LostCave_Room7_Movement_Oak2
	applymovement LOCALID_AGATHA, ChronoIsland_LostCave_Room7_Movement_Agatha2
	waitmovement 0
	applymovement LOCALID_SAMUEL, ChronoIsland_LostCave_Room7_Movement_Oak2
	applymovement LOCALID_AGATHA, ChronoIsland_LostCave_Room7_Movement_Agatha3
	waitmovement 0
	applymovement LOCALID_SAMUEL, ChronoIsland_LostCave_Room7_Movement_Oak3
	waitmovement 0
	removeobject LOCALID_SAMUEL
	playse SE_EXIT
	applymovement LOCALID_AGATHA, ChronoIsland_LostCave_Room7_Movement_Agatha4
	waitmovement 0
	removeobject LOCALID_AGATHA
	playse SE_EXIT
	setflag FLAG_HIDE_DUO4
	clearflag FLAG_HIDE_DUO5
	setvar VAR_CELEBI_EVENT, 5
	releaseall
	end

ChronoIsland_LostCave_Room7_Text_Agatha1::
	.string "I can't see a thing!\n"
	.string "This mist is crazy!$"
	
ChronoIsland_LostCave_Room7_Text_Oak1::
	.string "Just follow the sound of my voice.\p"
	.string "You're all safe and sound with me.$"
	
ChronoIsland_LostCave_Room7_Text_Agatha2::
	.string "Safe and sound, with you?\p"
	.string "You can't even find your own\n"
	.string "RUNNING SHOES whenever you\l"
	.string "head out.$"
	
ChronoIsland_LostCave_Room7_Text_Oak2::
	.string "Should I just leave you behind,\n"
	.string "then?$"
	
ChronoIsland_LostCave_Room7_Text_Agatha3::
	.string "Stop joking around and help me!$"
	
ChronoIsland_LostCave_Room7_Text_Oak3::
	.string "Here, I'll hold your hand.$"
	
ChronoIsland_LostCave_Room7_Text_Agatha4::
	.string "Giggle…$"
	
ChronoIsland_LostCave_Room7_Movement_Agatha1::
	walk_in_place_left
	step_end
	
ChronoIsland_LostCave_Room7_Movement_Oak1::
	walk_in_place_right
	step_end
	
ChronoIsland_LostCave_Room7_Movement_Oak2::
	walk_down
	step_end
	
ChronoIsland_LostCave_Room7_Movement_Agatha2::
	walk_down
	step_end
	
ChronoIsland_LostCave_Room7_Movement_Agatha3::
	walk_down
	walk_in_place_left
	step_end
	
	
ChronoIsland_LostCave_Room7_Movement_Oak3::
	walk_in_place_down
	step_end
	
ChronoIsland_LostCave_Room7_Movement_Agatha4::
	walk_left
	walk_in_place_down
	step_end