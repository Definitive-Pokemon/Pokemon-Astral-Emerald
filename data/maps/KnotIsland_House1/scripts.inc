KnotIsland_House1_MapScripts::
	.byte 0


KnotIsland_House1_EventScript_OldMan::
	lock
	faceplayer
	msgbox KnotIsland_House1_EventScript_OldMan_Text_0
	release
	return


KnotIsland_House1_EventScript_OldWoman::
	lock
	faceplayer
	msgbox KnotIsland_House1_EventScript_OldWoman_Text_0
	release
	return


KnotIsland_House1_EventScript_OldMan_Text_0:
	.string "On sunny days, I step out and gaze upon\n"
	.string "the volcano. That's my daily routine.$"

KnotIsland_House1_EventScript_OldWoman_Text_0:
	.string "Let me think… When was the last time MT.\n"
	.string "EMBER erupted?$"
