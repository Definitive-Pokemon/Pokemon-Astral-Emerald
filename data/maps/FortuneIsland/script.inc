FortuneIsland_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FortuneIsland_OnTransition
	.byte 0

FortuneIsland_OnTransition::
	setflag FLAG_VISITED_FORTUNE_ISLAND
	end

FortuneIsland_EventScript_Hiker::
	msgbox FortuneIsland_Text_ThatWayToWaterPathRuinValley, MSGBOX_NPC
	end

FortuneIsland_EventScript_Boy::
	msgbox FortuneIsland_Text_SkyAtNightIsFantastic, MSGBOX_NPC
	end

FortuneIsland_EventScript_IslandSign::
	msgbox FortuneIsland_Text_IslandSign, MSGBOX_SIGN
	end
FortuneIsland_Text_IslandSign::
    .string "SIX ISLAND\n"
    .string "Fortune Island of Aged Wisdom$"

FortuneIsland_Text_ThatWayToWaterPathRuinValley::
    .string "Keep going this way and you'll get\n"
    .string "to the WATER PATH.\p"
    .string "Stay on that and you'll get to\n"
    .string "the RUIN VALLEY.$"

FortuneIsland_Text_SkyAtNightIsFantastic::
    .string "When you're this far away from the\n"
    .string "city, the sky at night is fantastic.$"

