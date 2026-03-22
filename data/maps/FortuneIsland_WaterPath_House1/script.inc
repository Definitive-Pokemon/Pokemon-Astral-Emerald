FortuneIsland_WaterPath_House1_MapScripts::
	.byte 0

FortuneIsland_WaterPath_House1_EventScript_Beauty::
	lock
	faceplayer

	setvar VAR_0x8004, SPECIES_HERACROSS
	specialvar VAR_RESULT, DoesPlayerPartyContainSpecies
	goto_if_eq VAR_RESULT, FALSE, FortuneIsland_WaterPath_House1_EventScript_NoHeracrossInParty
	@special GetHeracrossSizeRecordInfo
	msgbox FortuneIsland_WaterPath_House1_Text_MayIMeasureHeracross
	special ChoosePartyMon
	waitstate
	copyvar VAR_RESULT, VAR_0x8004
	goto_if_ge VAR_RESULT, PARTY_SIZE, FortuneIsland_WaterPath_House1_EventScript_DontShowMon
	@special CompareHeracrossSize
	goto_if_eq VAR_RESULT, 1, FortuneIsland_WaterPath_House1_EventScript_ShownNonHeracross
	goto_if_eq VAR_RESULT, 2, FortuneIsland_WaterPath_House1_EventScript_ShownSmallHeracross
	goto_if_eq VAR_RESULT, 3, FortuneIsland_WaterPath_House1_EventScript_ShownBigHeracross
	goto_if_eq VAR_RESULT, 4, FortuneIsland_WaterPath_House1_EventScript_ShownTiedHeracross
	release
	end

FortuneIsland_WaterPath_House1_EventScript_NoHeracrossInParty::
	msgbox FortuneIsland_WaterPath_House1_Text_LoveItNeedItHeracross
	release
	end

FortuneIsland_WaterPath_House1_EventScript_DontShowMon::
	release
	end

FortuneIsland_WaterPath_House1_EventScript_ShownNonHeracross::
	msgbox FortuneIsland_WaterPath_House1_Text_ThisWontDo
	release
	end

FortuneIsland_WaterPath_House1_EventScript_ShownSmallHeracross::
	goto_if_unset FLAG_GOT_NEST_BALL_FROM_WATER_PATH_HOUSE_1, FortuneIsland_WaterPath_House1_EventScript_ShownBigHeracross
	msgbox FortuneIsland_WaterPath_House1_Text_ItsXInchesYInchesWasBiggest
	release
	end

FortuneIsland_WaterPath_House1_EventScript_ShownTiedHeracross::
	goto_if_unset FLAG_GOT_NEST_BALL_FROM_WATER_PATH_HOUSE_1, FortuneIsland_WaterPath_House1_EventScript_ShownBigHeracross
	msgbox FortuneIsland_WaterPath_House1_Text_ItsXInchesSameAsBefore
	release
	end

FortuneIsland_WaterPath_House1_EventScript_ShownBigHeracross::
	setflag FLAG_GOT_NEST_BALL_FROM_WATER_PATH_HOUSE_1
	msgbox FortuneIsland_WaterPath_House1_Text_ItsXInchesDeserveReward
	giveitem ITEM_NEST_BALL
	goto_if_eq VAR_RESULT, FALSE, FortuneIsland_WaterPath_House1_EventScript_NoRoomForNestBall
	msgbox FortuneIsland_WaterPath_House1_Text_WantToSeeBiggerOne
	release
	end

FortuneIsland_WaterPath_House1_EventScript_NoRoomForNestBall::
	msgbox FortuneIsland_WaterPath_House1_Text_YourBagIsFull
	release
	end

FortuneIsland_WaterPath_House1_EventScript_SizeRecord::
	lockall
	goto_if_set FLAG_GOT_NEST_BALL_FROM_WATER_PATH_HOUSE_1, FortuneIsland_WaterPath_House1_EventScript_SizeRecordNonEmpty
	msgbox FortuneIsland_WaterPath_House1_Text_BlankChartOfSomeSort
	releaseall
	end

FortuneIsland_WaterPath_House1_EventScript_SizeRecordNonEmpty::
	@special GetHeracrossSizeRecordInfo
	msgbox FortuneIsland_WaterPath_House1_Text_BiggestHeracrossIsXInches
	releaseall
	end
FortuneIsland_WaterPath_House1_Text_LoveItNeedItHeracross::
    .string "Hera, hera, HERACROSS!\n"
    .string "Big and shiny, it's the bug boss!\l"
    .string "Love it, need it, HERACROSS!$"

FortuneIsland_WaterPath_House1_Text_MayIMeasureHeracross::
    .string "Eeeeek!\n"
    .string "That's a HERACROSS!\p"
    .string "Please, please, may I measure how\n"
    .string "big it is?$"

FortuneIsland_WaterPath_House1_Text_ItsXInchesDeserveReward::
    .string "Eeeek, it's {STR_VAR_2} inches!\n"
    .string "I've never seen anything like this!\l"
    .string "You deserve a reward!$"

FortuneIsland_WaterPath_House1_Text_WantToSeeBiggerOne::
    .string "I want to see a much, much bigger\n"
    .string "HERACROSS than that one.\p"
    .string "Oh, how I adore them, big\n"
    .string "HERACROSS!$"

FortuneIsland_WaterPath_House1_Text_ItsXInchesSameAsBefore::
    .string "Huh? This {STR_VAR_2}-inch measurement…\n"
    .string "Oh, boo! It's the same as before.$"

FortuneIsland_WaterPath_House1_Text_ItsXInchesYInchesWasBiggest::
    .string "Oh, it's just {STR_VAR_2} inches.\n"
    .string "The HERACROSS before was bigger.\p"
    .string "It was {STR_VAR_3} inches, the biggest\n"
    .string "HERACROSS you've brought me.$"

FortuneIsland_WaterPath_House1_Text_ThisWontDo::
    .string "Oh, no! This won't do!\p"
    .string "HERACROSS looks much more macho\n"
    .string "and cool, and has a lovely horn!$"

FortuneIsland_WaterPath_House1_Text_YourBagIsFull::
    .string "Your BAG is full.\n"
    .string "My reward won't fit.$"

FortuneIsland_WaterPath_House1_Text_BiggestHeracrossIsXInches::
    .string "The biggest HERACROSS that I have\n"
    .string "ever seen measured so far is:\p"
    .string "{STR_VAR_3} inches!$"

FortuneIsland_WaterPath_House1_Text_BlankChartOfSomeSort::
    .string "It's a blank chart of some sort.\p"
    .string "It has spaces for writing in\n"
    .string "records of some kind.$"

