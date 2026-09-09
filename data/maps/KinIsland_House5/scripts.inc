KinIsland_House5_MapScripts::
	.byte 0

KinIsland_House5_EventScript_LittleGirl::
	lock
	faceplayer
	goto_if_set FLAG_RESCUED_LOSTELLE, KinIsland_House5_EventScript_LittleGirlLostelleFound
	msgbox KinIsland_House5_Text_ImNotLostelle
	release
	end

KinIsland_House5_EventScript_LittleGirlLostelleFound::
	msgbox KinIsland_House5_Text_IllGoPlayWithLostelle
	release
	end
KinIsland_House5_Text_ImNotLostelle::
    .string "Me?\n"
    .string "I'm not LOSTELLE.\p"
    .string "She's probably gone to the\n"
    .string "BERRY FOREST, I think.\p"
    .string "She picks BERRIES there for making\n"
    .string "lunch.$"

KinIsland_House5_Text_IllGoPlayWithLostelle::
    .string "I think I'll go play with LOSTELLE\n"
    .string "today.$"

