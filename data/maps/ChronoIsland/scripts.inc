ChronoIsland_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ChronoIsland_OnTransition
	.byte 0

ChronoIsland_OnTransition::
	setflag FLAG_VISITED_CHRONO_ISLAND
	end

ChronoIsland_EventScript_IslandSign::
	msgbox ChronoIsland_Text_IslandSign, MSGBOX_SIGN
	end

ChronoIsland_EventScript_BugCatcher::
	msgbox ChronoIsland_Text_WeirdBuildingInMeadow, MSGBOX_NPC
	end

ChronoIsland_EventScript_Fisher::
	msgbox ChronoIsland_Text_BeenGettingBusierAroundHere, MSGBOX_NPC
	end
ChronoIsland_Text_IslandSign::
    .string "FIVE ISLAND\n"
    .string "Chrono Island: Where Time Goes$"

ChronoIsland_Text_WeirdBuildingInMeadow::
    .string "Oh, this stinks. I wanted to play in\n"
    .string "the MEADOW.\p"
    .string "But they put up a weird building\n"
    .string "on it, so I can't play there.$"

ChronoIsland_Text_BeenGettingBusierAroundHere::
    .string "It's been getting busier around\n"
    .string "these parts lately.\p"
    .string "I haven't been catching many good\n"
    .string "fish lately, either.$"

