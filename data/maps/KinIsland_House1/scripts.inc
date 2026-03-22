KinIsland_House1_MapScripts::
	.byte 0

KinIsland_House1_EventScript_Lostelle::
	lock
	faceplayer
	@special BufferBigGuyOrBigGirlString
	msgbox KinIsland_House1_Text_YoureAlwaysSoCool
	release
	end

KinIsland_House1_EventScript_DisplayCase::
	msgbox KinIsland_House1_Text_RareRocksGemsDisplayed, MSGBOX_SIGN
	end
KinIsland_House1_Text_YoureAlwaysSoCool::
    .string "LOSTELLE: Hi, {PLAYER}!\n"
    .string "You're always so cool!\p"
    .string "I'll make lunch for you, too, one\n"
    .string "day, {PLAYER}.$"

KinIsland_House1_Text_RareRocksGemsDisplayed::
    .string "Rare rocks and gems are displayed.$"

