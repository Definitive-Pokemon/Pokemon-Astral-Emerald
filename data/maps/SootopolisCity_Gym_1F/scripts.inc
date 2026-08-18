SootopolisCity_Gym_1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SootopolisCity_Gym_1F_OnFrame
	map_script MAP_SCRIPT_ON_RESUME, SootopolisCity_Gym_1F_OnResume
	map_script MAP_SCRIPT_ON_LOAD, SootopolisCity_Gym_1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, SootopolisCity_Gym_1F_OnTransition
	.byte 0

SootopolisCity_Gym_1F_OnTransition:
	setvar VAR_ICE_STEP_COUNT, 1
	end

SootopolisCity_Gym_1F_OnResume:
	setstepcallback STEP_CB_SOOTOPOLIS_ICE
	end

SootopolisCity_Gym_1F_OnLoad:
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special SetSootopolisGymCrackedIceMetatiles
	end

SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles::
	goto_if_lt VAR_ICE_STEP_COUNT, 8, SootopolisCity_Gym_1F_EventScript_StopCheckingStairs  @ All stairs ice
	goto_if_lt VAR_ICE_STEP_COUNT, 28, SootopolisCity_Gym_1F_EventScript_OpenFirstStairs
	goto_if_lt VAR_ICE_STEP_COUNT, 67, SootopolisCity_Gym_1F_EventScript_OpenFirstAndSecondStairs
	setmetatile 8, 4, METATILE_SootopolisGym_Stairs, FALSE
	setmetatile 8, 5, METATILE_SootopolisGym_Stairs, FALSE
SootopolisCity_Gym_1F_EventScript_OpenFirstAndSecondStairs::
	setmetatile 8, 10, METATILE_SootopolisGym_Stairs, FALSE
	setmetatile 8, 11, METATILE_SootopolisGym_Stairs, FALSE
SootopolisCity_Gym_1F_EventScript_OpenFirstStairs::
	setmetatile 8, 15, METATILE_SootopolisGym_Stairs, FALSE
	setmetatile 8, 16, METATILE_SootopolisGym_Stairs, FALSE
SootopolisCity_Gym_1F_EventScript_StopCheckingStairs::
	return

SootopolisCity_Gym_1F_OnFrame:
	map_script_2 VAR_ICE_STEP_COUNT, 8, SootopolisCity_Gym_1F_EventScript_UnlockFirstStairs
	map_script_2 VAR_ICE_STEP_COUNT, 28, SootopolisCity_Gym_1F_EventScript_UnlockSecondStairs
	map_script_2 VAR_ICE_STEP_COUNT, 67, SootopolisCity_Gym_1F_EventScript_UnlockThirdStairs
	map_script_2 VAR_ICE_STEP_COUNT, 0, SootopolisCity_Gym_1F_EventScript_FallThroughIce
	.2byte 0

SootopolisCity_Gym_1F_EventScript_UnlockFirstStairs::
	addvar VAR_ICE_STEP_COUNT, 1
	delay 40
	playse SE_ICE_STAIRS
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special DrawWholeMapView
	end

SootopolisCity_Gym_1F_EventScript_UnlockSecondStairs::
	addvar VAR_ICE_STEP_COUNT, 1
	delay 40
	playse SE_ICE_STAIRS
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special DrawWholeMapView
	end

SootopolisCity_Gym_1F_EventScript_UnlockThirdStairs::
	addvar VAR_ICE_STEP_COUNT, 1
	delay 40
	playse SE_ICE_STAIRS
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special DrawWholeMapView
	end

SootopolisCity_Gym_1F_EventScript_FallThroughIce::
	lockall
	delay 20
	applymovement OBJ_EVENT_ID_PLAYER, SootopolisCity_Gym_1F_Movement_FallThroughIce
	waitmovement 0
	playse SE_FALL
	delay 60
	warphole MAP_SOOTOPOLIS_CITY_GYM_B1F
	waitstate
	end

SootopolisCity_Gym_1F_Movement_FallThroughIce:
	set_invisible
	step_end

SootopolisCity_Gym_1F_CheckBadgeAndSetWeather::
	goto_if_unset FLAG_BADGE08_GET, SootopolisCity_Gym_1F_SetWeatherHardMode
	goto_if_set FLAG_BADGE08_GET, SootopolisCity_Gym_1F_EventScript_Wallace2
	end

SootopolisCity_Gym_1F_SetWeatherHardMode::
	setweather WEATHER_RAIN
	doweather
	goto SootopolisCity_Gym_1F_EventScript_Wallace2

SootopolisCity_Gym_1F_EventScript_Wallace::
	goto_if_set FLAG_DIFFICULTY_HARD, SootopolisCity_Gym_1F_CheckBadgeAndSetWeather
	goto_if_unset FLAG_DIFFICULTY_HARD, SootopolisCity_Gym_1F_EventScript_Wallace2
	end

SootopolisCity_Gym_1F_EventScript_Wallace2::
	trainerbattle_single TRAINER_WALLACE_1, SootopolisCity_Gym_1F_Text_WallaceIntro, SootopolisCity_Gym_1F_Text_WallaceDefeat, SootopolisCity_Gym_1F_EventScript_WallaceDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, SootopolisCity_Gym_1F_EventScript_WallaceRematch
	goto_if_unset FLAG_RECEIVED_TM_WATER_PULSE, SootopolisCity_Gym_1F_EventScript_GiveWaterPulse2
	goto_if_unset FLAG_BADGE06_GET, SootopolisCity_Gym_1F_EventScript_GoGetFortreeBadge
	msgbox SootopolisCity_Gym_1F_Text_WallacePostBattle, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_WallaceDefeated::
	setweather WEATHER_NONE
	doweather
	message SootopolisCity_Gym_1F_Text_ReceivedRainBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox SootopolisCity_Gym_1F_Text_ExplainRainBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_SOOTOPOLIS_GYM
	setflag FLAG_BADGE08_GET
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_RESIDENTS
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_STEVEN
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_WALLACE
	setvar VAR_SOOTOPOLIS_CITY_STATE, 6
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_MAN_1
	setvar VAR_0x8008, 8
	call Common_EventScript_SetGymTrainers
	call SootopolisCity_Gym_1F_EventScript_GiveWaterPulse
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox SootopolisCity_Gym_1F_Text_RegisteredWallace, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_WALLACE_MATCH_CALL
	release
	end

SootopolisCity_Gym_1F_EventScript_GiveWaterPulse::
	giveitem ITEM_TM_WATER_PULSE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox SootopolisCity_Gym_1F_Text_ExplainWaterPulse, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_WATER_PULSE
	return

SootopolisCity_Gym_1F_EventScript_GiveWaterPulse2::
	giveitem ITEM_TM_WATER_PULSE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox SootopolisCity_Gym_1F_Text_ExplainWaterPulse, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_WATER_PULSE
	release
	end

SootopolisCity_Gym_1F_EventScript_GoGetFortreeBadge::
	msgbox SootopolisCity_Gym_1F_Text_GoGetFortreeBadge, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_WallaceRematch::
	setweather WEATHER_RAIN
	doweather
	trainerbattle_rematch_double TRAINER_WALLACE_1, SootopolisCity_Gym_1F_Text_WallacePreRematch, SootopolisCity_Gym_1F_Text_WallaceRematchDefeat, SootopolisCity_Gym_1F_Text_WallaceRematchNeedTwoMons
	setweather WEATHER_NONE
	doweather
	msgbox SootopolisCity_Gym_1F_Text_WallacePostRematch, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_1F_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_SOOTOPOLIS_GYM, SootopolisCity_Gym_1F_EventScript_GymGuidePostVictory
	msgbox SootopolisCity_Gym_1F_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_GymGuidePostVictory::
	msgbox SootopolisCity_Gym_1F_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE08_GET, SootopolisCity_Gym_1F_EventScript_GymStatueCertified
	goto SootopolisCity_Gym_1F_EventScript_GymStatue
	end

SootopolisCity_Gym_1F_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE08_GET, SootopolisCity_Gym_1F_EventScript_GymStatueCertified
	goto SootopolisCity_Gym_1F_EventScript_GymStatue
	end

SootopolisCity_Gym_1F_EventScript_GymStatueCertified::
	msgbox SootopolisCity_Gym_1F_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_Gym_1F_EventScript_GymStatue::
	msgbox SootopolisCity_Gym_1F_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_Gym_1F_Text_GymGuideAdvice:
	.string "Yo! Champ-in-making!\n"
	.string "I can't believe how far you've come!\p"
	.string "Are you ready to finish this out?\p"
	.string "Sootopolis's Gym Leader Wallace is\n"
	.string "a master of Water-type Pokémon\l"
	.string "and all things beautiful.\p"
	.string "You've battled Water-types before,\n"
	.string "but Wallace is on another level.\p"
	.string "Watching Wallace fight, there's a grace\n"
	.string "that few other trainers possess.\p"
	.string "Many believe him to be as strong\n"
	.string "as those in the Elite Four.\p"
	.string "Some even say…\n"
	.string "Ah, it doesn't matter.\p"
	.string "{PLAYER}!\n"
	.string "I know you can do this!$"

SootopolisCity_Gym_1F_Text_GymGuidePostVictory:
	.string "Yow! You've beaten Wallace, who\n"
	.string "is supposedly the best in Hoenn!\p"
	.string "{PLAYER}! It's been an honor!\p"
	.string "It's time for you to take on the\n"
	.string "Pokémon League challenge!\p"
	.string "I can't come with you, but just\n"
	.string "know I'll be rooting for you!$"

SootopolisCity_Gym_1F_Text_WallaceIntro:
	.string "Allow me to formally introduce\n"
	.string "myself.\p"
	.string "I am Wallace.\n"
	.string "The Gym Leader of Sootopolis.\p"
	.string "There's something about you…\n"
	.string "A difference in your demeanor.\p"
	.string "I think I sense that in you.\p"
	.string "What happened on top of the Sky\n"
	.string "Pillar, and what you did, I will likely\l"
	.string "learn through our upcoming battle.\p"
	.string "Now, show me. Show me the power you\n"
	.string "wield with your Pokémon.\p"
	.string "And I, in turn, shall present you with\n"
	.string "a performance of illusions in water\l"
	.string "by me and my Pokémon!$"

@ NOTE: This defeat text actually causes a buffer overflow. It's about 50 bytes too long for
@ the gDisplayedStringBattle buffer that it's put into, and it stomps all over the gBattleTextBuffs
@ after, as well as the otherwise unused array after that. One wonders if that's the reason for
@ the existence of that unused array of ints.
SootopolisCity_Gym_1F_Text_WallaceDefeat:
	.string "Bravo.\p"
	.string "I realize now your authenticity and\n"
	.string "magnificence as a Pokémon Trainer.\p"
	.string "I find much joy in having met you and\n"
	.string "your Pokémon.\p"
	.string "You have proven yourself worthy of\n"
	.string "the Rain Badge. Accept it.$"

SootopolisCity_Gym_1F_Text_ReceivedRainBadge:
	.string "{PLAYER} received the Rain Badge\n"
	.string "from Wallace.$"

SootopolisCity_Gym_1F_Text_ExplainRainBadgeTakeThis:
	.string "Having the Rain Badge shall assure you\n"
	.string "the full obedience of all your Pokémon\l"
	.string "to your every command.\p"
	.string "The Rain Badge also allows the use\n"
	.string "of the HM move Waterfall to scale\l"
	.string "walls of cascading water.\p"
	.string "And, so that you never forget the\n"
	.string "battle we shared, take this…$"

SootopolisCity_Gym_1F_Text_ExplainWaterPulse:
	.string "The Technical Machine I handed you\n"
	.string "contains Water Pulse.\p"
	.string "In use, it will occasionally confuse\n"
	.string "the target with ultrasonic waves.\p"
	.string "… … … … … …$"

SootopolisCity_Gym_1F_Text_RegisteredWallace:
	.string "Registered Gym Leader Wallace\n"
	.string "in the Pokénav.$"

SootopolisCity_Gym_1F_Text_WallacePostBattle:
	.string "The Trainers who have gathered all\n"
	.string "the Gym Badges of Hoenn should make\l"
	.string "way to the ultimate destination.\p"
	.string "The Pokémon League.\p"
	.string "Travel to the easternmost reaches\n"
	.string "of Hoenn, to the island Ever Grande.\p"
	.string "There, you shall find the Pokémon\n"
	.string "League.$"

SootopolisCity_Gym_1F_Text_GoGetFortreeBadge:
	.string "There remains but one Badge to\n"
	.string "obtain in Hoenn.\p"
	.string "If you wish to challenge the Pokémon\n"
	.string "League, you must obtain the last\l"
	.string "Badge from the Gym in Fortree.$"

SootopolisCity_Gym_1F_Text_GymStatue:
	.string "Sootopolis City Pokémon Gym$"

SootopolisCity_Gym_1F_Text_GymStatueCertified:
	.string "Sootopolis City Pokémon Gym\p"
	.string "Wallace's Certified Trainers:\n"
	.string "{PLAYER}$"

SootopolisCity_Gym_1F_Text_WallacePreRematch://EDIT
	.string "Wallace: Ah, this Gym had returned to its\n"
	.string "usual state of serenity…\p"
	.string "But our young typhoon has returned\n"
	.string "to put us to the test again!\p"
	.string "Well, my friend, most certainly!\p"
	.string "I shall be delighted to dance with you\n"
	.string "as often as you wish!$"

SootopolisCity_Gym_1F_Text_WallaceRematchDefeat://EDIT
	.string "Ahahaha, you are the winner!\n"
	.string "You have defeated me again!$"

SootopolisCity_Gym_1F_Text_WallacePostRematch://EDIT
	.string "Wallace: If I told you to become my\n"
	.string "apprentice, you will refuse, I am sure.\p"
	.string "I would like to make a gift of my coat\n"
	.string "to you.\p"
	.string "But again, you will refuse.\n"
	.string "I imagine that to be so.\p"
	.string "And that, my friend, is a certain sign\n"
	.string "of nobility!$"

SootopolisCity_Gym_1F_Text_WallaceRematchNeedTwoMons://EDIT
	.string "Wallace: Ah, this Gym had returned to its\n"
	.string "usual state of serenity…\p"
	.string "But our young typhoon has returned\n"
	.string "to put us to the test again!\p"
	.string "Well, my friend, most certainly!\n"
	.string "I shall be delighted to dance with you…\p"
	.string "Ah, no, no, no.\n"
	.string "You have with you but one Pokémon.\p"
	.string "I wish that you would return with\n"
	.string "two, perhaps more, Pokémon, please.$"

