FortuneIsland_GreenPath_MapScripts::
	.byte 0

FortuneIsland_GreenPath_EventScript_Jaclyn::
	trainerbattle_single TRAINER_PSYCHIC_JACLYN, FortuneIsland_GreenPath_Text_JaclynIntro, FortuneIsland_GreenPath_Text_JaclynDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, FortuneIsland_GreenPath_EventScript_JaclynRematch
	msgbox FortuneIsland_GreenPath_Text_JaclynPostBattle, MSGBOX_AUTOCLOSE
	end

FortuneIsland_GreenPath_EventScript_JaclynRematch::
	trainerbattle_rematch TRAINER_CLIFFORD, FortuneIsland_GreenPath_Text_JaclynRematchIntro, FortuneIsland_GreenPath_Text_JaclynDefeat
	msgbox FortuneIsland_GreenPath_Text_JaclynPostBattle, MSGBOX_AUTOCLOSE
	end

FortuneIsland_GreenPath_Text_JaclynRematchIntro::
	.string "…Huh?\p"
	.string "I envision my house, but TELEPORT\n"
	.string "always brings me here!$"


FortuneIsland_GreenPath_EventScript_RightRouteSign::
	msgbox FortuneIsland_GreenPath_Text_LeftRouteSign, MSGBOX_SIGN
	end

FortuneIsland_GreenPath_EventScript_LeftRouteSign::
	msgbox FortuneIsland_GreenPath_Text_RightRouteSign, MSGBOX_SIGN
	end
FortuneIsland_GreenPath_Text_JaclynIntro::
    .string "…Huh?\p"
    .string "I was envisioning my house, but\n"
    .string "this is where I TELEPORT?$"

FortuneIsland_GreenPath_Text_JaclynDefeat::
    .string "Big boo-boo!$"

FortuneIsland_GreenPath_Text_JaclynPostBattle::
    .string "I am so scatterbrained!\p"
    .string "I need to focus so I can TELEPORT\n"
    .string "properly to my house!$"

FortuneIsland_GreenPath_Text_LeftRouteSign::
    .string "GREEN PATH\n"
    .string "PATTERN BUSH AHEAD$"

FortuneIsland_GreenPath_Text_RightRouteSign::
    .string "GREEN PATH\n"
    .string "Think Green, Keep Nature Clean!$"

