ChronoIsland_LostCave_Room1_MapScripts::
	.byte 0

ChronoIsland_LostCave_Room1_EventScript_Lawson::
	trainerbattle_single TRAINER_RUIN_MANIAC_LAWSON, ChronoIsland_LostCave_Room1_Text_LawsonIntro, ChronoIsland_LostCave_Room1_Text_LawsonDefeat
	msgbox ChronoIsland_LostCave_Room1_Text_LawsonPostBattle, MSGBOX_AUTOCLOSE
	end
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

