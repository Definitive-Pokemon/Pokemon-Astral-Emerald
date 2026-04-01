FortuneIsland_PatternBush_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FortuneIsland_PatternBush_OnTransition
	.byte 0

FortuneIsland_PatternBush_OnTransition::
	@setworldmapflag FLAG_WORLD_MAP_FORTUNE_ISLAND_PATTERN_BUSH
	getplayerxy VAR_TEMP_1, VAR_TEMP_2
	call_if_ge VAR_TEMP_1, 50, FortuneIsland_PatternBush_EventScript_SetEscapeRightExit
	call_if_le VAR_TEMP_1, 49, FortuneIsland_PatternBush_EventScript_SetEscapeLeftExit
	end

FortuneIsland_PatternBush_EventScript_SetEscapeRightExit::
	setescapewarp MAP_FORTUNE_ISLAND_GREEN_PATH, 255, 64, 10
	return

FortuneIsland_PatternBush_EventScript_SetEscapeLeftExit::
	setescapewarp MAP_FORTUNE_ISLAND_GREEN_PATH, 255, 45, 10
	return

FortuneIsland_PatternBush_EventScript_Bethany::
	trainerbattle_single TRAINER_PKMN_BREEDER_BETHANY, FortuneIsland_PatternBush_Text_BethanyIntro, FortuneIsland_PatternBush_Text_BethanyDefeat
	msgbox FortuneIsland_PatternBush_Text_BethanyPostBattle, MSGBOX_AUTOCLOSE
	end

FortuneIsland_PatternBush_EventScript_Allison::
	trainerbattle_single TRAINER_PKMN_BREEDER_ALLISON, FortuneIsland_PatternBush_Text_AllisonIntro, FortuneIsland_PatternBush_Text_AllisonDefeat
	msgbox FortuneIsland_PatternBush_Text_AllisonPostBattle, MSGBOX_AUTOCLOSE
	end

FortuneIsland_PatternBush_EventScript_Garret::
	trainerbattle_single TRAINER_BUG_CATCHER_GARRET, FortuneIsland_PatternBush_Text_GarretIntro, FortuneIsland_PatternBush_Text_GarretDefeat
	msgbox FortuneIsland_PatternBush_Text_GarretPostBattle, MSGBOX_AUTOCLOSE
	end

FortuneIsland_PatternBush_EventScript_Jonah::
	trainerbattle_single TRAINER_BUG_CATCHER_JONAH, FortuneIsland_PatternBush_Text_JonahIntro, FortuneIsland_PatternBush_Text_JonahDefeat
	msgbox FortuneIsland_PatternBush_Text_JonahPostBattle, MSGBOX_AUTOCLOSE
	end

FortuneIsland_PatternBush_EventScript_Vance::
	trainerbattle_single TRAINER_BUG_CATCHER_VANCE, FortuneIsland_PatternBush_Text_VanceIntro, FortuneIsland_PatternBush_Text_VanceDefeat
	msgbox FortuneIsland_PatternBush_Text_VancePostBattle, MSGBOX_AUTOCLOSE
	end

FortuneIsland_PatternBush_EventScript_Nash::
	trainerbattle_single TRAINER_YOUNGSTER_NASH, FortuneIsland_PatternBush_Text_NashIntro, FortuneIsland_PatternBush_Text_NashDefeat
	msgbox FortuneIsland_PatternBush_Text_NashPostBattle, MSGBOX_AUTOCLOSE
	end

FortuneIsland_PatternBush_EventScript_Cordell::
	trainerbattle_single TRAINER_YOUNGSTER_CORDELL, FortuneIsland_PatternBush_Text_CordellIntro, FortuneIsland_PatternBush_Text_CordellDefeat
	msgbox FortuneIsland_PatternBush_Text_CordellPostBattle, MSGBOX_AUTOCLOSE
	end

FortuneIsland_PatternBush_EventScript_Dalia::
	trainerbattle_single TRAINER_LASS_DALIA, FortuneIsland_PatternBush_Text_DaliaIntro, FortuneIsland_PatternBush_Text_DaliaDefeat
	msgbox FortuneIsland_PatternBush_Text_DaliaPostBattle, MSGBOX_AUTOCLOSE
	end

FortuneIsland_PatternBush_EventScript_Joana::
	trainerbattle_single TRAINER_LASS_JOANA, FortuneIsland_PatternBush_Text_JoanaIntro, FortuneIsland_PatternBush_Text_JoanaDefeat
	msgbox FortuneIsland_PatternBush_Text_JoanaPostBattle, MSGBOX_AUTOCLOSE
	end

FortuneIsland_PatternBush_EventScript_Riley::
	trainerbattle_single TRAINER_CAMPER_RILEY, FortuneIsland_PatternBush_Text_RileyIntro, FortuneIsland_PatternBush_Text_RileyDefeat
	msgbox FortuneIsland_PatternBush_Text_RileyPostBattle, MSGBOX_AUTOCLOSE
	end

FortuneIsland_PatternBush_EventScript_Marcy::
	trainerbattle_single TRAINER_PICNICKER_MARCY, FortuneIsland_PatternBush_Text_MarcyIntro, FortuneIsland_PatternBush_Text_MarcyDefeat
	msgbox FortuneIsland_PatternBush_Text_MarcyPostBattle, MSGBOX_AUTOCLOSE
	end

FortuneIsland_PatternBush_EventScript_Layton::
	trainerbattle_single TRAINER_RUIN_MANIAC_LAYTON, FortuneIsland_PatternBush_Text_LaytonIntro, FortuneIsland_PatternBush_Text_LaytonDefeat
	msgbox FortuneIsland_PatternBush_Text_LaytonPostBattle, MSGBOX_AUTOCLOSE
	end
FortuneIsland_PatternBush_Text_BethanyIntro::
    .string "I'm curious, how do you raise your\n"
    .string "POKéMON?$"

FortuneIsland_PatternBush_Text_BethanyDefeat::
    .string "You raise your POKéMON with a\n"
    .string "whole lot of love!$"

FortuneIsland_PatternBush_Text_BethanyPostBattle::
    .string "In the same way your mother raised\n"
    .string "you full of love, you should raise\l"
    .string "your POKéMON.$"

FortuneIsland_PatternBush_Text_AllisonIntro::
    .string "I'm working to preserve the natural\n"
    .string "ecology of POKéMON here.$"

FortuneIsland_PatternBush_Text_AllisonDefeat::
    .string "Oh, for someone so young, you are\n"
    .string "tremendous!$"

FortuneIsland_PatternBush_Text_AllisonPostBattle::
    .string "I'm not saying that you shouldn't\n"
    .string "catch POKéMON.\p"
    .string "I just want people to raise their\n"
    .string "POKéMON responsibly.$"

FortuneIsland_PatternBush_Text_GarretIntro::
    .string "I caught a BUG POKéMON that lives\n"
    .string "only around here!$"

FortuneIsland_PatternBush_Text_GarretDefeat::
    .string "Heheh…\n"
    .string "Isn't my POKéMON awesome?$"

FortuneIsland_PatternBush_Text_GarretPostBattle::
    .string "There's a girl near the BUSH who\n"
    .string "measures HERACROSS for TRAINERS.$"

FortuneIsland_PatternBush_Text_JonahIntro::
    .string "You know, it just doesn't feel right\n"
    .string "if I don't use BUG POKéMON.$"

FortuneIsland_PatternBush_Text_JonahDefeat::
    .string "It's okay, losing is a fun part of\n"
    .string "POKéMON's appeal, too.$"

FortuneIsland_PatternBush_Text_JonahPostBattle::
    .string "By the way, “appeal” is a weird\n"
    .string "word, if you think about it.\p"
    .string "Like, is it like an orange peel?\n"
    .string "Or like a ringing bell?$"

FortuneIsland_PatternBush_Text_VanceIntro::
    .string "Yeah, yeah, yeah!\n"
    .string "Look at all the BUG POKéMON!$"

FortuneIsland_PatternBush_Text_VanceDefeat::
    .string "I got beat while I was still busy\n"
    .string "celebrating!$"

FortuneIsland_PatternBush_Text_VancePostBattle::
    .string "I'm going to bring my little brother\n"
    .string "here next time.$"

FortuneIsland_PatternBush_Text_NashIntro::
    .string "Look, look! There are funny\n"
    .string "patterns on the ground.$"

FortuneIsland_PatternBush_Text_NashDefeat::
    .string "Super awesome!$"

FortuneIsland_PatternBush_Text_NashPostBattle::
    .string "The funny patterns on the ground…\p"
    .string "They look like the patterns on my\n"
    .string "grandpa's clothes.$"

FortuneIsland_PatternBush_Text_CordellIntro::
    .string "I bet you think I'm just some guy,\n"
    .string "don't you, eh?$"

FortuneIsland_PatternBush_Text_CordellDefeat::
    .string "I bet you think I'm weak,\n"
    .string "don't you, eh?$"

FortuneIsland_PatternBush_Text_CordellPostBattle::
    .string "Ayup, you townies come around all\n"
    .string "so dandy with a hat that flashy…\p"
    .string "How about giving me that?$"

FortuneIsland_PatternBush_Text_DaliaIntro::
    .string "Take a deep breath.\n"
    .string "Isn't the air delicious?$"

FortuneIsland_PatternBush_Text_DaliaDefeat::
    .string "If you'd like, I can teach you how\n"
    .string "to breathe properly.$"

FortuneIsland_PatternBush_Text_DaliaPostBattle::
    .string "First, exhale.\n"
    .string "Blow everything out.\p"
    .string "When you can't exhale anymore,\n"
    .string "inhale the clean air!\p"
    .string "Isn't it refreshing?$"

FortuneIsland_PatternBush_Text_JoanaIntro::
    .string "I love BUG POKéMON.\n"
    .string "That's why I'm here all the time.\p"
    .string "Am I the only girl like that?$"

FortuneIsland_PatternBush_Text_JoanaDefeat::
    .string "I lost, but I'm still laughing.\n"
    .string "Am I the only girl like that?$"

FortuneIsland_PatternBush_Text_JoanaPostBattle::
    .string "I'm going to keep on collecting\n"
    .string "BUG POKéMON.\p"
    .string "Am I the only girl like that?$"

FortuneIsland_PatternBush_Text_RileyIntro::
    .string "This is a good spot.\n"
    .string "I'll pitch my tent here.$"

FortuneIsland_PatternBush_Text_RileyDefeat::
    .string "Wimped out…$"

FortuneIsland_PatternBush_Text_RileyPostBattle::
    .string "I'm going to observe the night sky\n"
    .string "here.$"

FortuneIsland_PatternBush_Text_MarcyIntro::
    .string "Oh, yuck!\n"
    .string "I think a bug stung me!$"

FortuneIsland_PatternBush_Text_MarcyDefeat::
    .string "It wasn't a bug.\n"
    .string "I cut my shin on some grass.$"

FortuneIsland_PatternBush_Text_MarcyPostBattle::
    .string "A little cut like that…\n"
    .string "A little spit's enough to cure it!$"

FortuneIsland_PatternBush_Text_LaytonIntro::
    .string "Have you noticed something odd\n"
    .string "about these parts?$"

FortuneIsland_PatternBush_Text_LaytonDefeat::
    .string "Have you taken a good look around\n"
    .string "your feet?$"

FortuneIsland_PatternBush_Text_LaytonPostBattle::
    .string "There are places here in PATTERN\n"
    .string "BUSH where grass won't grow.\p"
    .string "What could be the cause of such\n"
    .string "a phenomenon?$"

