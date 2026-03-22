ChronoIsland_LostCave_Room4_MapScripts::
	.byte 0

ChronoIsland_LostCave_Room4_EventScript_Laura::
	trainerbattle_single TRAINER_PSYCHIC_LAURA, ChronoIsland_LostCave_Room4_Text_LauraIntro, ChronoIsland_LostCave_Room4_Text_LauraDefeat
	msgbox ChronoIsland_LostCave_Room4_Text_LauraPostBattle, MSGBOX_AUTOCLOSE
	end
ChronoIsland_LostCave_Room4_Text_LauraIntro::
    .string "I think there is a mysterious power\n"
    .string "at work in this cave.$"

ChronoIsland_LostCave_Room4_Text_LauraDefeat::
    .string "If you don't go into the right\n"
    .string "tunnel, you won't get ahead.$"

ChronoIsland_LostCave_Room4_Text_LauraPostBattle::
    .string "Earlier, a lady went into the caves\n"
    .string "ahead.$"

