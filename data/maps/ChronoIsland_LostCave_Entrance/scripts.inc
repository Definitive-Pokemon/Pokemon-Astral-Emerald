.set LOCALID_SAMUEL, 1
.set LOCALID_AGATHA, 2

ChronoIsland_LostCave_Entrance_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ChronoIsland_LostCave_Entrance_OnTransition
	.byte 0

ChronoIsland_LostCave_Entrance_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_CHRONO_ISLAND_LOST_CAVE_ENTRANCE
	end

ChronoIsland_LostCave_Entrance_EventScript_CelebiEvent1::
	lockall
	setweather WEATHER_FOG_HORIZONTAL
	doweather
	delay 120
	fadescreen FADE_TO_WHITE
	clearflag FLAG_HIDE_DUO1
	addobject LOCALID_SAMUEL
	addobject LOCALID_AGATHA
	fadescreen FADE_FROM_WHITE
	delay 20
	applymovement LOCALID_AGATHA, ChronoIsland_LostCave_Entrance_Movement_Agatha1
	waitmovement 0
	textcolor 1
	msgbox ChronoIsland_LostCave_Entrance_Text_Agatha1
	closemessage
	applymovement LOCALID_SAMUEL, ChronoIsland_LostCave_Entrance_Movement_Oak1
	waitmovement 0
	textcolor 0
	msgbox ChronoIsland_LostCave_Entrance_Text_Oak1
	closemessage
	applymovement LOCALID_AGATHA, ChronoIsland_LostCave_Entrance_Movement_Agatha2
	waitmovement 0
	textcolor 1
	msgbox ChronoIsland_LostCave_Entrance_Text_Agatha2
	closemessage
	applymovement LOCALID_SAMUEL, ChronoIsland_LostCave_Entrance_Movement_Oak2
	waitmovement 0
	textcolor 0
	msgbox ChronoIsland_LostCave_Entrance_Text_Oak2
	closemessage
	applymovement LOCALID_SAMUEL, ChronoIsland_LostCave_Entrance_Movement_Oak3
	waitmovement 0
	msgbox ChronoIsland_LostCave_Entrance_Text_Oak3
	closemessage
	applymovement LOCALID_SAMUEL, ChronoIsland_LostCave_Entrance_Movement_Oak4
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_SAMUEL
	applymovement LOCALID_AGATHA, ChronoIsland_LostCave_Entrance_Movement_Agatha3
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_AGATHA
	setflag FLAG_HIDE_DUO1
	clearflag FLAG_HIDE_DUO2
	setvar VAR_CELEBI_EVENT1, 2
	setvar VAR_CELEBI_EVENT2, 1
	
ChronoIsland_LostCave_Entrance_Text_Agatha1::
	.string "So, is this it, sweetheart?$"
	
ChronoIsland_LostCave_Entrance_Text_Oak1::
	.string "Yes AGATHA, this is it.$"
	
ChronoIsland_LostCave_Entrance_Text_Agatha2::
	.string "So you are about to become more\n"
	.string "powerful than ever before?$"
	
ChronoIsland_LostCave_Entrance_Text_Oak2::
	.string "Yes love, I guess that's correct.$"
	
ChronoIsland_LostCave_Entrance_Text_Oak3::
	.string "Well, time to get to business.$"
	
ChronoIsland_LostCave_Entrance_Movement_Agatha1::
	walk_in_place_right
	step_end
	
ChronoIsland_LostCave_Entrance_Movement_Oak1::
	walk_in_place_down
	step_end
	
ChronoIsland_LostCave_Entrance_Movement_Agatha2::
	walk_in_place_right
	step_end
	
ChronoIsland_LostCave_Entrance_Movement_Oak2::
	walk_in_place_down
	step_end
	
ChronoIsland_LostCave_Entrance_Movement_Oak3::
	walk_in_place_down
	step_end
	
ChronoIsland_LostCave_Entrance_Movement_Oak4::
	walk_down
	step_end
	
ChronoIsland_LostCave_Entrance_Movement_Agatha3::
	walk_right
	walk_down
	step_end