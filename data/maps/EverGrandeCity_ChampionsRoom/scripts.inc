EverGrandeCity_ChampionsRoom_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_ChampionsRoom_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_ChampionsRoom_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_ChampionsRoom_OnFrame
	.byte 0

EverGrandeCity_ChampionsRoom_OnTransition:
	call Common_EventScript_SetupRivalGfxId
	end

EverGrandeCity_ChampionsRoom_OnWarp:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_ChampionsRoom_EventScript_PlayerTurnNorth
	.2byte 0

EverGrandeCity_ChampionsRoom_EventScript_PlayerTurnNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

EverGrandeCity_ChampionsRoom_OnFrame:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_ChampionsRoom_EventScript_EnterRoom
	.2byte 0

EverGrandeCity_ChampionsRoom_EventScript_EnterRoom::
	lockall
	applymovement LOCALID_PLAYER, Common_Movement_WalkUp4
	waitmovement 0
	delay 40
	applymovement LOCALID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerApproachWallace
	waitmovement 0
	setvar VAR_TEMP_1, 1
	goto_if_unset FLAG_IS_CHAMPION, EverGrandeCity_ChampionsRoom_EventScript_Steven
	goto EverGrandeCity_ChampionsRoom_EventScript_Wallace
	releaseall
	end

EverGrandeCity_ChampionsRoom_Movement_PlayerApproachWallace:
	walk_up
	walk_up
	step_end

EverGrandeCity_ChampionsRoom_EventScript_Steven::
	playbgm MUS_ENCOUNTER_CHAMPION, FALSE
	msgbox EverGrandeCity_ChampionsRoom_Text_StevenIntroSpeech, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_STEVEN_1, EverGrandeCity_ChampionsRoom_Text_StevenDefeat
	goto EverGrandeCity_ChampionsRoom_EventScript_StevenDefeated
	end

EverGrandeCity_ChampionsRoom_EventScript_StevenDefeated::
	playse SE_DOOR
	setmetatile 6, 1, METATILE_EliteFour_OpenDoorChampion_Frame, FALSE
	setmetatile 6, 2, METATILE_EliteFour_OpenDoorChampion_Opening, FALSE
	special DrawWholeMapView
	msgbox EverGrandeCity_ChampionsRoom_Text_StevenPostBattleSpeech, MSGBOX_DEFAULT
	closemessage
	playse SE_DOOR
	checkplayergender
	call_if_eq VAR_RESULT, MALE, EverGrandeCity_ChampionsRoom_EventScript_PlayMayMusic
	call_if_eq VAR_RESULT, FEMALE, EverGrandeCity_ChampionsRoom_EventScript_PlayBrendanMusic
	addobject LOCALID_CHAMPIONS_ROOM_RIVAL
	call EverGrandeCity_ChampionsRoom_EventScript_RivalApproachPlayer
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, EverGrandeCity_ChampionsRoom_EventScript_MayAdvice
	goto_if_eq VAR_RESULT, FEMALE, EverGrandeCity_ChampionsRoom_EventScript_BrendanAdvice
	end

EverGrandeCity_ChampionsRoom_EventScript_PlayMayMusic::
	playbgm MUS_ENCOUNTER_MAY, FALSE
	return

EverGrandeCity_ChampionsRoom_EventScript_PlayBrendanMusic::
	playbgm MUS_ENCOUNTER_BRENDAN, FALSE
	return

EverGrandeCity_ChampionsRoom_EventScript_MayAdvice::
	msgbox EverGrandeCity_ChampionsRoom_Text_MayAdvice, MSGBOX_DEFAULT
	delay 40
	playse SE_PIN
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, Common_Movement_Delay48
	waitmovement 0
	call EverGrandeCity_ChampionsRoom_EventScript_RivalLookBackAndForth
	msgbox EverGrandeCity_ChampionsRoom_Text_MayItsAlreadyOver, MSGBOX_DEFAULT
	goto EverGrandeCity_ChampionsRoom_EventScript_BirchArrivesExitForHoF
	end

EverGrandeCity_ChampionsRoom_EventScript_BrendanAdvice::
	msgbox EverGrandeCity_ChampionsRoom_Text_BrendanAdvice, MSGBOX_DEFAULT
	delay 40
	playse SE_PIN
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, Common_Movement_Delay48
	waitmovement 0
	call EverGrandeCity_ChampionsRoom_EventScript_RivalLookBackAndForth
	msgbox EverGrandeCity_ChampionsRoom_Text_BrendanYouveWon, MSGBOX_DEFAULT
	goto EverGrandeCity_ChampionsRoom_EventScript_BirchArrivesExitForHoF
	end

EverGrandeCity_ChampionsRoom_EventScript_BirchArrivesExitForHoF::
	closemessage
	addobject LOCALID_CHAMPIONS_ROOM_BIRCH
	applymovement LOCALID_CHAMPIONS_ROOM_BIRCH, EverGrandeCity_ChampionsRoom_Movement_BirchArrives
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox EverGrandeCity_ChampionsRoom_Text_BirchArriveRatePokedex, MSGBOX_DEFAULT
	call ProfBirch_EventScript_RatePokedex
	msgbox EverGrandeCity_ChampionsRoom_Text_BirchCongratulations, MSGBOX_DEFAULT
	goto_if_unset FLAG_IS_CHAMPION, EverGrandeCity_ChampionsRoom_EventScript_StevenGoToHOF
	goto EverGrandeCity_ChampionsRoom_EventScript_WallaceGoToHOF
	
EverGrandeCity_ChampionsRoom_EventScript_StevenGoToHOF::
	applymovement LOCALID_CHAMPIONS_ROOM_STEVEN, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 20
	applymovement LOCALID_CHAMPIONS_ROOM_STEVEN, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox EverGrandeCity_ChampionsRoom_Text_StevenComeWithMe, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement LOCALID_CHAMPIONS_ROOM_STEVEN, EverGrandeCity_ChampionsRoom_Movement_WallaceExitStart
	applymovement LOCALID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerExitStart
	applymovement LOCALID_CHAMPIONS_ROOM_BIRCH, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, EverGrandeCity_ChampionsRoom_Movement_RivalFollows
	waitmovement 0
	delay 20
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox EverGrandeCity_ChampionsRoom_Text_StevenWaitOutside, MSGBOX_DEFAULT
	checkplayergender
	call_if_eq VAR_RESULT, MALE, EverGrandeCity_ChampionsRoom_EventScript_MayCongratulations
	call_if_eq VAR_RESULT, FEMALE, EverGrandeCity_ChampionsRoom_EventScript_BrendanCongratulations
	closemessage
	applymovement LOCALID_CHAMPIONS_ROOM_STEVEN, EverGrandeCity_ChampionsRoom_Movement_WallaceExit
	applymovement LOCALID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerExit
	waitmovement 0
	setflag FLAG_HIDE_PETALBURG_GYM_GREETER
	warp MAP_EVER_GRANDE_CITY_HALL_OF_FAME, 7, 16
	waitstate
	releaseall
	end

EverGrandeCity_ChampionsRoom_EventScript_MayCongratulations::
	msgbox EverGrandeCity_ChampionsRoom_Text_MayCongratulations, MSGBOX_DEFAULT
	return

EverGrandeCity_ChampionsRoom_EventScript_BrendanCongratulations::
	msgbox EverGrandeCity_ChampionsRoom_Text_BrendanCongratulations, MSGBOX_DEFAULT
	return

EverGrandeCity_ChampionsRoom_EventScript_RivalApproachPlayer::
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, EverGrandeCity_ChampionsRoom_Movement_RivalApproachPlayer
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

EverGrandeCity_ChampionsRoom_EventScript_RivalLookBackAndForth::
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, EverGrandeCity_ChampionsRoom_Movement_RivalLookBackAndForth
	waitmovement 0
	return

EverGrandeCity_ChampionsRoom_EventScript_Wallace::
	playbgm MUS_ENCOUNTER_CHAMPION, FALSE
	msgbox EverGrandeCity_ChampionsRoom_Text_IntroSpeech, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WALLACE_2, EverGrandeCity_ChampionsRoom_Text_Defeat
	goto EverGrandeCity_ChampionsRoom_EventScript_WallaceDefeated
	end

EverGrandeCity_ChampionsRoom_EventScript_WallaceDefeated::
	playse SE_DOOR
	setmetatile 6, 1, METATILE_EliteFour_OpenDoorChampion_Frame, FALSE
	setmetatile 6, 2, METATILE_EliteFour_OpenDoorChampion_Opening, FALSE
	special DrawWholeMapView
	msgbox EverGrandeCity_ChampionsRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	closemessage
	playse SE_DOOR
	checkplayergender
	call_if_eq VAR_RESULT, MALE, EverGrandeCity_ChampionsRoom_EventScript_PlayMayMusic
	call_if_eq VAR_RESULT, FEMALE, EverGrandeCity_ChampionsRoom_EventScript_PlayBrendanMusic
	addobject LOCALID_CHAMPIONS_ROOM_RIVAL
	call EverGrandeCity_ChampionsRoom_EventScript_RivalApproachPlayer
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, EverGrandeCity_ChampionsRoom_EventScript_RematchMayAdvice
	goto_if_eq VAR_RESULT, FEMALE, EverGrandeCity_ChampionsRoom_EventScript_RematchBrendanAdvice
	end

EverGrandeCity_ChampionsRoom_EventScript_RematchMayAdvice::
	msgbox EverGrandeCity_ChampionsRoom_Text_RematchMayAdvice, MSGBOX_DEFAULT
	goto EverGrandeCity_ChampionsRoom_EventScript_RematchBirchArrivesExitForHoF
	end

EverGrandeCity_ChampionsRoom_EventScript_RematchBrendanAdvice::
	msgbox EverGrandeCity_ChampionsRoom_Text_RematchBrendanAdvice, MSGBOX_DEFAULT
	goto EverGrandeCity_ChampionsRoom_EventScript_RematchBirchArrivesExitForHoF
	end

EverGrandeCity_ChampionsRoom_EventScript_RematchBirchArrivesExitForHoF::
	closemessage
	addobject LOCALID_CHAMPIONS_ROOM_BIRCH
	applymovement LOCALID_CHAMPIONS_ROOM_BIRCH, EverGrandeCity_ChampionsRoom_Movement_BirchArrives
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox EverGrandeCity_ChampionsRoom_Text_RematchBirchArriveRatePokedex, MSGBOX_DEFAULT
	call ProfBirch_EventScript_RatePokedex
	msgbox EverGrandeCity_ChampionsRoom_Text_RematchBirchCongratulations, MSGBOX_DEFAULT
	closemessage
	goto_if_unset FLAG_IS_CHAMPION, EverGrandeCity_ChampionsRoom_EventScript_StevenGoToHOF
	goto EverGrandeCity_ChampionsRoom_EventScript_WallaceGoToHOF

EverGrandeCity_ChampionsRoom_EventScript_WallaceGoToHOF::
	applymovement LOCALID_CHAMPIONS_ROOM_WALLACE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 20
	applymovement LOCALID_CHAMPIONS_ROOM_WALLACE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox EverGrandeCity_ChampionsRoom_Text_RematchWallaceComeWithMe, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement LOCALID_CHAMPIONS_ROOM_WALLACE, EverGrandeCity_ChampionsRoom_Movement_WallaceExitStart
	applymovement LOCALID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerExitStart
	applymovement LOCALID_CHAMPIONS_ROOM_BIRCH, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, EverGrandeCity_ChampionsRoom_Movement_RivalFollows
	waitmovement 0
	delay 20
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox EverGrandeCity_ChampionsRoom_Text_WallaceWaitOutside, MSGBOX_DEFAULT
	checkplayergender
	call_if_eq VAR_RESULT, MALE, EverGrandeCity_ChampionsRoom_EventScript_RematchMayCongratulations
	call_if_eq VAR_RESULT, FEMALE, EverGrandeCity_ChampionsRoom_EventScript_RematchBrendanCongratulations
	closemessage
	applymovement LOCALID_CHAMPIONS_ROOM_WALLACE, EverGrandeCity_ChampionsRoom_Movement_WallaceExit
	applymovement LOCALID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerExit
	waitmovement 0
	setflag FLAG_HIDE_PETALBURG_GYM_GREETER
	warp MAP_EVER_GRANDE_CITY_HALL_OF_FAME, 7, 16
	waitstate
	releaseall
	end

EverGrandeCity_ChampionsRoom_EventScript_RematchMayCongratulations:
	msgbox EverGrandeCity_ChampionsRoom_Text_RematchMayCongratulations, MSGBOX_DEFAULT
	return

EverGrandeCity_ChampionsRoom_EventScript_RematchBrendanCongratulations:
	msgbox EverGrandeCity_ChampionsRoom_Text_RematchBrendanCongratulations, MSGBOX_DEFAULT
	return

EverGrandeCity_ChampionsRoom_Movement_PlayerExitStart:
	walk_up
	walk_up
	step_end

EverGrandeCity_ChampionsRoom_Movement_PlayerExit:
	walk_up
	delay_16
	walk_up
	delay_8
	set_invisible
	step_end

EverGrandeCity_ChampionsRoom_Movement_RivalApproachPlayer:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_up
	walk_in_place_faster_right
	step_end

EverGrandeCity_ChampionsRoom_Movement_RivalLookBackAndForth:
	walk_in_place_faster_up
	delay_16
	walk_in_place_faster_right
	delay_16
	walk_in_place_faster_up
	delay_8
	walk_in_place_faster_right
	delay_16
	step_end

EverGrandeCity_ChampionsRoom_Movement_RivalFollows:
	walk_right
	walk_up
	step_end

EverGrandeCity_ChampionsRoom_Movement_WallaceExitStart:
	walk_up
	walk_up
	walk_in_place_faster_down
	step_end

EverGrandeCity_ChampionsRoom_Movement_WallaceExit:
	walk_up
	delay_8
	set_invisible
	step_end

EverGrandeCity_ChampionsRoom_Movement_BirchArrives:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_in_place_faster_left
	step_end

EverGrandeCity_ChampionsRoom_Text_StevenIntroSpeech:
	.string "STEVEN: Welcome, {PLAYER}{KUN}.\p"
	.string "I was looking forward to seeing you\n"
	.string "here one day.\p"
	.string "That incident in SOOTOPOLIS CITY…\n"
	.string "That was superb work, putting an end\l"
	.string "to that crisis all by yourself.\p"
	.string "What else did you achieve during your\n"
	.string "journey with POKéMON?\p"
	.string "What did you feel, meeting so many\n"
	.string "other TRAINERS like you?\p"
	.string "What has awoken in you?\n"
	.string "I want you to hit me with it all!\p"
	.string "Now, bring it!$"

EverGrandeCity_ChampionsRoom_Text_StevenDefeat:
	.string "I, the CHAMPION, fall in defeat…\p"
	.string "Kudos to you, {PLAYER}{KUN}!\p"
	.string "You are a truly noble POKéMON\n"
	.string "TRAINER!$"

EverGrandeCity_ChampionsRoom_Text_StevenPostBattleSpeech:
	.string "STEVEN: Congratulations!\p"
	.string "The feelings you have for your\n"
	.string "POKéMON…\p"
	.string "And the POKéMON that responded to\n"
	.string "those feelings with all their might…\p"
	.string "They came together as one, and created\n"
	.string "an even greater power.\p"
	.string "And thus, you were able to grasp\n"
	.string "victory today!\p"
	.string "You are rightfully the HOENN region's\n"
	.string "new…$"

EverGrandeCity_ChampionsRoom_Text_MayAdvice:
	.string "MAY: {PLAYER}{KUN}!\p"
	.string "Here's some advice before you challenge\n"
	.string "the CHAMPION…$"

EverGrandeCity_ChampionsRoom_Text_MayItsAlreadyOver:
	.string "MAY: Huh?\n"
	.string "What, what, what?\p"
	.string "{PLAYER}{KUN}…\n"
	.string "Could it be that…\l"
	.string "It's already over?$"

EverGrandeCity_ChampionsRoom_Text_BrendanAdvice:
	.string "BRENDAN: {PLAYER}!\p"
	.string "How would you like some advice before\n"
	.string "you challenge the CHAMPION?…$"

EverGrandeCity_ChampionsRoom_Text_BrendanYouveWon:
	.string "BRENDAN: {PLAYER}…\p"
	.string "Are you trying to tell me…\n"
	.string "You've beaten the CHAMPION?$"

EverGrandeCity_ChampionsRoom_Text_BirchArriveRatePokedex:
	.string "PROF. BIRCH: See?\n"
	.string "What did I tell you, {RIVAL}?\p"
	.string "Didn't I tell you that you don't need\n"
	.string "to worry about {PLAYER}{KUN}?\p"
	.string "… … … … … … … …\n"
	.string "{PLAYER}{KUN}, you've finally done it.\p"
	.string "When I heard that you defeated your\n"
	.string "own father at the PETALBURG GYM,\l"
	.string "I thought perhaps you had a chance…\p"
	.string "But to think you've actually become\n"
	.string "the CHAMPION!\p"
	.string "Ah, yes!\p"
	.string "What became of your POKéDEX?\n"
	.string "Here, let me see.$"

EverGrandeCity_ChampionsRoom_Text_BirchCongratulations:
	.string "PROF. BIRCH: Anyways,\n"
	.string "congratulations!\p"
	.string "Now, go proudly into the final room!$"

EverGrandeCity_ChampionsRoom_Text_StevenComeWithMe:
	.string "STEVEN: {PLAYER}{KUN}…\p"
	.string "No, let me rephrase that properly.\p"
	.string "The new CHAMPION!\p"
	.string "Come with me.$"

EverGrandeCity_ChampionsRoom_Text_WallaceWaitOutside:
	.string "WALLACE: I'm sorry, but…\p"
	.string "From here on, only those TRAINERS who\n"
	.string "have become CHAMPIONS may enter.\p"
	.string "You'll have to wait outside with\n"
	.string "PROF. BIRCH.$"

EverGrandeCity_ChampionsRoom_Text_StevenWaitOutside:
	.string "STEVEN: I'm sorry, but…\p"
	.string "From here on, only those TRAINERS who\n"
	.string "have become CHAMPIONS may enter.\p"
	.string "You'll have to wait outside with the\n"
	.string "PROFESSOR.$"

EverGrandeCity_ChampionsRoom_Text_MayCongratulations:
	.string "MAY: Groan…\p"
	.string "… … … … … … … …\n"
	.string "… … … … … … … …\p"
	.string "I'm just joking! That's okay!\n"
	.string "That's the rule!\p"
	.string "{PLAYER}{KUN}!\n"
	.string "Honestly, congratulations!$"

EverGrandeCity_ChampionsRoom_Text_BrendanCongratulations:
	.string "BRENDAN: Whaaaat?! … … … … …\n"
	.string "… … … … … … … …\p"
	.string "It can't be helped if that's the rule.\p"
	.string "{PLAYER}, way to go!\n"
	.string "Congratulations!$"
	.string "PROFESSOR.$"

EverGrandeCity_ChampionsRoom_Text_IntroSpeech:
	.string "WALLACE: Welcome, {PLAYER}{KUN}.\p"
	.string "It's been quite some time\n"
	.string "since we last met…\p"
	.string "Let me reintroduce myself.\p"
	.string "I am WALLACE, former CHAMPION\n"
	.string "of the HOENN region.\p"
	.string "I've heard about your struggles\n"
	.string "on the SEVII ISLANDS.\p"
	.string "You overcame many difficult situations\n"
	.string "by working as one with your POKéMON.\p"
	.string "We TRAINERS raise POKéMON by giving\n"
	.string "them items and by teaching them new\l"
	.string "techniques for battle.\p"
	.string "But we ourselves also learn many\n"
	.string "things from POKéMON.\p"
	.string "And this is where your achievements\n"
	.string "are put to the test against what\l"
	.string "others like you have achieved.\p"
	.string "Now!\p"
	.string "Who can most elegantly dance with\n"
	.string "their POKéMON in HOENN?\p"
	.string "Show me right here and now!$"

EverGrandeCity_ChampionsRoom_Text_Defeat:
	.string "I, former CHAMPION, fall in defeat…\n"
	.string "That was wonderful work.\l"
	.string "You were elegant, infuriatingly so.\l"
	.string "And yet it was utterly glorious!\p"
	.string "Congratulations, {PLAYER}{KUN}!$"

EverGrandeCity_ChampionsRoom_Text_PostBattleSpeech:
	.string "WALLACE: The POKéMON you sent into\n"
	.string "battle…\p"
	.string "At times they danced like a spring\n"
	.string "breeze, and at times they struck\l"
	.string "like lightning.\p"
	.string "It was with light, yet surefooted,\n"
	.string "elegance that you led your POKéMON.\p"
	.string "Even I felt bedazzled by your\n"
	.string "masterful performance!\p"
	.string "You remain HOENN's CHAMPION,\n"
	.string "{PLAYER}{KUN}.$"

EverGrandeCity_ChampionsRoom_Text_RematchMayAdvice:
	.string "MAY: {PLAYER}{KUN}!\p"
	.string "You've beaten WALLACE again!\n"
	.string "That's amazing!$"

EverGrandeCity_ChampionsRoom_Text_RematchBrendanAdvice:
	.string "BRENDAN: {PLAYER}{KUN}!\p"
	.string "Wow! You beat WALLACE again!\n"
	.string "That's amazing!$"

EverGrandeCity_ChampionsRoom_Text_RematchBirchArriveRatePokedex:
	.string "PROF. BIRCH: {PLAYER}{KUN},\n"
	.string "I expected nothing else.\p"
	.string "Now, can I see your POKéDEX?\p"
	.string "You must have seen many new POKéMON\n"
	.string "unknown to the HOENN region!$"

EverGrandeCity_ChampionsRoom_Text_RematchBirchCongratulations:
	.string "PROF. BIRCH: Anyways,\n"
	.string "I knew you could handle yourself\n"
	.string "in another fight against WALLACE,\l"
	.string "even if he isn't holding back.\p"
	.string "You see, WALLACE and STEVEN have\n"
	.string "both been CHAMPION of HOENN.\p"
	.string "Evenly matched, the two kept taking\n"
	.string "the title from each other.\p"
	.string "I knew that if you could beat one,\n"
	.string "you could take on the other.\p"
	.string "Anyways,\n"
	.string "congratulations!\p"
	.string "Now, go proudly into the final room!$"

EverGrandeCity_ChampionsRoom_Text_RematchWallaceComeWithMe:
	.string "WALLACE: {PLAYER}{KUN}…\p"
	.string "You've firmly entrenched yourself\n"
	.string "into the history of HOENN.\p"
	.string "Come with me.\p"
	.string "It is time to record this splendid\n"
	.string "achievement at the HALL OF FAME.$"

EverGrandeCity_ChampionsRoom_Text_RematchMayCongratulations:
	.string "MAY: Groan…\n"
	.string "Not again…\p"
	.string "… … … … … … … …\p"
	.string "Only joking!\n"
	.string "You know that I don't mind.\p"
	.string "{PLAYER}{KUN}!\n"
	.string "Honestly, congratulations!$"

EverGrandeCity_ChampionsRoom_Text_RematchBrendanCongratulations:
	.string "BRENDAN: Pfffft!\n"
	.string "Stupid…\p"
	.string "Oh well, rules are rules.\p"
	.string "{PLAYER}, way to go!\n"
	.string "Congratulations!$"

EverGrandeCity_ChampionsRoom_Text_RematchWallaceChampion::
	.string "WALLACE: Ah, {RIVAL},\n"
	.string "You see, I was CHAMPION long ago,\l"
	.string "trading the title back and forth\l"
	.string "with STEVEN in a friendly rivalry.\p"
	.string "We each held the title many times,\n"
	.string "constantly pushing each other to\l"
	.string "improve.\p"
	.string "But today… today belongs to\n"
	.string "{PLAYER}{KUN}.\p"
	.string "Come, CHAMPION. Let us mark this moment\n"
	.string "in the HALL OF FAME!$"
