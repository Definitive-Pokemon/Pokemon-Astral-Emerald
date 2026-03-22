QuestIsland_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, QuestIsland_OnTransition
	.byte 0

QuestIsland_OnTransition::
	setflag FLAG_VISITED_QUEST_ISLAND
	end

QuestIsland_EventScript_IslandSign::
	msgbox QuestIsland_Text_IslandSign, MSGBOX_SIGN
	end

QuestIsland_EventScript_OldWoman::
	msgbox QuestIsland_Text_IslandsMadeInSevenDays, MSGBOX_NPC
	end

QuestIsland_EventScript_Scientist::
	msgbox QuestIsland_Text_IslandVirtuallyUntouched, MSGBOX_NPC
	end
    
Text_SwordsDanceTeach::
    .string "Not many people come out here.\p"
    .string "If I train here, I'm convinced that\n"
    .string "I'll get stronger and stronger.\p"
    .string "Yep, stronger and stronger…\p"
    .string "How would you like to learn a move\n"
    .string "like that? It's SWORDS DANCE.$"

Text_SwordsDanceDeclined::
    .string "Well, that's fine, too.$"

Text_SwordsDanceWhichMon::
    .string "All right, pick which POKéMON\n"
    .string "I should teach it to.$"

Text_SwordsDanceTaught::
    .string "If only we could keep getting\n"
    .string "stronger and stronger, eh?$"

QuestIsland_Text_IslandSign::
    .string "SEVEN ISLAND\n"
    .string "Quest Island of Infinity$"

QuestIsland_Text_IslandsMadeInSevenDays::
    .string "These islands are called the SEVII\n"
    .string "ISLANDS because there are seven.\p"
    .string "…Or at least that's what the young\n"
    .string "people believe.\p"
    .string "The truth is, these islands are so\n"
    .string "named because they are said to\l"
    .string "have been made in seven days.$"

QuestIsland_Text_IslandVirtuallyUntouched::
    .string "This island has been left virtually\n"
    .string "untouched in its natural state.\p"
    .string "It could be a little difficult to\n"
    .string "hike around because of that.$"

