.set LOCALID_SAMUEL, 1
.set LOCALID_AGATHA, 2

ChronoIsland_LostCave_Room9_MapScripts::
	.byte 0

ChronoIsland_LostCave_Entrance_EventScript_CelebiEvent5::
	lockall
	fadeoutbgm 1
	applymovement LOCALID_AGATHA, ChronoIsland_LostCave_Room9_Movement_Agatha1
	waitmovement 0
	textcolor 1
	msgbox ChronoIsland_LostCave_Room9_Text_Agatha1
	closemessage
	applymovement LOCALID_SAMUEL, ChronoIsland_LostCave_Room9_Movement_Oak1
	waitmovement 0
	textcolor 0
	msgbox ChronoIsland_LostCave_Room9_Text_Oak1
	closemessage
	applymovement LOCALID_AGATHA, ChronoIsland_LostCave_Room9_Movement_Agatha1
	waitmovement 0
	textcolor 1
	msgbox ChronoIsland_LostCave_Room9_Text_Agatha2
	closemessage
	applymovement LOCALID_SAMUEL, ChronoIsland_LostCave_Room9_Movement_Oak1
	waitmovement 0
	textcolor 0
	msgbox ChronoIsland_LostCave_Room9_Text_Oak2
	closemessage
	applymovement LOCALID_AGATHA, ChronoIsland_LostCave_Room9_Movement_Agatha1
	waitmovement 0
	textcolor 1
	msgbox ChronoIsland_LostCave_Room9_Text_Agatha3
	closemessage
	applymovement LOCALID_SAMUEL, ChronoIsland_LostCave_Room9_Movement_Oak1
	waitmovement 0
	textcolor 0
	msgbox ChronoIsland_LostCave_Room9_Text_Oak3
	closemessage
	applymovement LOCALID_SAMUEL, ChronoIsland_LostCave_Room9_Movement_Oak1
	waitmovement 0
	textcolor 0
	msgbox ChronoIsland_LostCave_Room9_Text_Oak4
	closemessage
	applymovement LOCALID_AGATHA, ChronoIsland_LostCave_Room9_Movement_Agatha1
	waitmovement 0
	textcolor 1
	msgbox ChronoIsland_LostCave_Room9_Text_Agatha4
	closemessage
	applymovement LOCALID_SAMUEL, ChronoIsland_LostCave_Room9_Movement_Oak1
	waitmovement 0
	textcolor 0
	msgbox ChronoIsland_LostCave_Room9_Text_Oak5
	closemessage
	applymovement LOCALID_AGATHA, ChronoIsland_LostCave_Room9_Movement_Agatha1
	applymovement LOCALID_SAMUEL, ChronoIsland_LostCave_Room9_Movement_Oak1
	waitmovement 0
	textcolor 2
	msgbox ChronoIsland_LostCave_Room9_Text_Both
	closemessage
	applymovement LOCALID_AGATHA, ChronoIsland_LostCave_Room9_Movement_Agatha2
	applymovement LOCALID_SAMUEL, ChronoIsland_LostCave_Room9_Movement_Oak2
	waitmovement 0
	applymovement LOCALID_AGATHA, ChronoIsland_LostCave_Room9_Movement_Agatha2
	applymovement LOCALID_SAMUEL, ChronoIsland_LostCave_Room9_Movement_Oak2
	waitmovement 0
	applymovement LOCALID_AGATHA, ChronoIsland_LostCave_Room9_Movement_Agatha3
	applymovement LOCALID_SAMUEL, ChronoIsland_LostCave_Room9_Movement_Oak2
	waitmovement 0
	applymovement LOCALID_SAMUEL, ChronoIsland_LostCave_Room9_Movement_Oak1
	waitmovement 0
	removeobject LOCALID_SAMUEL
	playse SE_EXIT
	applymovement LOCALID_AGATHA, ChronoIsland_LostCave_Room9_Movement_Agatha4
	waitmovement 0
	removeobject LOCALID_AGATHA
	playse SE_EXIT
	setflag FLAG_HIDE_DUO5
	clearflag FLAG_HIDE_DUO6
	clearflag FLAG_HIDE_STORY_CELEBI
	setvar VAR_CELEBI_EVENT, 6
	fadeinbgm 1
	releaseall
	end

ChronoIsland_LostCave_Room9_Text_Agatha1::
	.string "Sam… I'm scared…$"
	
ChronoIsland_LostCave_Room9_Text_Oak1::
	.string "I'll admit that I am starting to feel\n"
	.string "a little nervous as well…$"
	
ChronoIsland_LostCave_Room9_Text_Agatha2::
	.string "This POKéMON… is really powerful,\n"
	.string "right?$"

ChronoIsland_LostCave_Room9_Text_Oak2::
	.string "So I've heard…$"
	
ChronoIsland_LostCave_Room9_Text_Agatha3::
	.string "Are we gonna make it?$"

ChronoIsland_LostCave_Room9_Text_Oak3::
	.string "Of course we are, sweet.\p"
	.string "Remember, I'm the CHAMPION.$"
	
ChronoIsland_LostCave_Room9_Text_Oak4::
	.string "Are you ready, AGATHA?$"
	
ChronoIsland_LostCave_Room9_Text_Agatha4::
	.string "…\p"
	.string "Yes, I am.\p"
	.string "What about you, SAMUEL?$"
	
ChronoIsland_LostCave_Room9_Text_Oak5::
	.string "As ready as ever, love.\n"
	.string "No going back now.$"
	
ChronoIsland_LostCave_Room9_Text_Both::
	.string "Let's go!!$"
	
ChronoIsland_LostCave_Room9_Movement_Agatha1::
	walk_in_place_up
	step_end
	
ChronoIsland_LostCave_Room9_Movement_Oak1::
	walk_in_place_up
	step_end
	
ChronoIsland_LostCave_Room9_Movement_Agatha2::
	walk_up
	step_end
	
ChronoIsland_LostCave_Room9_Movement_Oak2::
	walk_up
	step_end
	
ChronoIsland_LostCave_Room9_Movement_Agatha3::
	walk_up
	walk_in_place_right
	step_end
	
ChronoIsland_LostCave_Room9_Movement_Agatha4::
	walk_right
	walk_in_place_up
	step_end