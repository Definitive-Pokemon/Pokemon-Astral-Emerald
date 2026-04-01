.set LOCALID_RESORT_GORGEOUS_SELPHY, 8

ChronoIsland_ResortGorgeous_MapScripts::
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, ChronoIsland_ResortGorgeous_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, ChronoIsland_ResortGorgeous_OnFrame
	.byte 0

ChronoIsland_ResortGorgeous_OnWarp::
	map_script_2 VAR_MAP_SCENE_CHRONO_ISLAND_RESORT_GORGEOUS, 1, ChronoIsland_ResortGorgeous_EventScript_TurnPlayerNorth
	.2byte 0

ChronoIsland_ResortGorgeous_EventScript_TurnPlayerNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

ChronoIsland_ResortGorgeous_OnFrame::
	map_script_2 VAR_MAP_SCENE_CHRONO_ISLAND_RESORT_GORGEOUS, 1, ChronoIsland_ResortGorgeous_EventScript_SelphyReturnHomeScene
	.2byte 0

ChronoIsland_ResortGorgeous_EventScript_SelphyReturnHomeScene::
	lockall

	msgbox ChronoIsland_ResortGorgeous_Text_SelphyThanksYouMayGoNow
	closemessage
	applymovement LOCALID_RESORT_GORGEOUS_SELPHY, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	opendoor 39, 8
	waitdooranim
	applymovement LOCALID_RESORT_GORGEOUS_SELPHY, ChronoIsland_ResortGorgeous_Movement_SelphyEnterHome
	waitmovement 0
	closedoor 39, 8
	waitdooranim
	removeobject LOCALID_RESORT_GORGEOUS_SELPHY
	clearflag FLAG_HIDE_RESORT_GORGEOUS_INSIDE_SELPHY
	setvar VAR_MAP_SCENE_CHRONO_ISLAND_RESORT_GORGEOUS, 2
	releaseall
	end

ChronoIsland_ResortGorgeous_Movement_SelphyEnterHome::
	walk_up
	set_invisible
	step_end

ChronoIsland_ResortGorgeous_EventScript_Daisy::
	trainerbattle_single TRAINER_PAINTER_DAISY, ChronoIsland_ResortGorgeous_Text_DaisyIntro, ChronoIsland_ResortGorgeous_Text_DaisyDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, ChronoIsland_ResortGorgeous_EventScript_DaisyRematch
	msgbox ChronoIsland_ResortGorgeous_Text_DaisyPostBattle, MSGBOX_AUTOCLOSE
	end

ChronoIsland_ResortGorgeous_EventScript_DaisyRematch::
	trainerbattle_rematch TRAINER_CLIFFORD, ChronoIsland_ResortGorgeous_Text_DaisyRematchIntro, ChronoIsland_ResortGorgeous_Text_DaisyDefeat
	msgbox ChronoIsland_ResortGorgeous_Text_DaisyPostBattle, MSGBOX_AUTOCLOSE
	end

ChronoIsland_ResortGorgeous_EventScript_Celina::
	trainerbattle_single TRAINER_PAINTER_CELINA, ChronoIsland_ResortGorgeous_Text_CelinaIntro, ChronoIsland_ResortGorgeous_Text_CelinaDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, ChronoIsland_ResortGorgeous_EventScript_CelinaRematch
	msgbox ChronoIsland_ResortGorgeous_Text_CelinaPostBattle, MSGBOX_AUTOCLOSE
	end

ChronoIsland_ResortGorgeous_EventScript_CelinaRematch::
	trainerbattle_rematch TRAINER_CLIFFORD, ChronoIsland_ResortGorgeous_Text_CelinaRematchIntro, ChronoIsland_ResortGorgeous_Text_CelinaDefeat
	msgbox ChronoIsland_ResortGorgeous_Text_CelinaPostBattle, MSGBOX_AUTOCLOSE
	end

ChronoIsland_ResortGorgeous_EventScript_Rayna::
	trainerbattle_single TRAINER_PAINTER_RAYNA, ChronoIsland_ResortGorgeous_Text_RaynaIntro, ChronoIsland_ResortGorgeous_Text_RaynaDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, ChronoIsland_ResortGorgeous_EventScript_RaynaRematch
	msgbox ChronoIsland_ResortGorgeous_Text_RaynaPostBattle, MSGBOX_AUTOCLOSE
	end

ChronoIsland_ResortGorgeous_EventScript_RaynaRematch::
	trainerbattle_rematch TRAINER_CLIFFORD, ChronoIsland_ResortGorgeous_Text_RaynaRematchIntro, ChronoIsland_ResortGorgeous_Text_RaynaDefeat
	msgbox ChronoIsland_ResortGorgeous_Text_RaynaPostBattle, MSGBOX_AUTOCLOSE
	end

ChronoIsland_ResortGorgeous_EventScript_Jacki::
	trainerbattle_single TRAINER_LADY_JACKI, ChronoIsland_ResortGorgeous_Text_JackiIntro, ChronoIsland_ResortGorgeous_Text_JackiDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, ChronoIsland_ResortGorgeous_EventScript_JackiRematch
	msgbox ChronoIsland_ResortGorgeous_Text_JackiPostBattle, MSGBOX_AUTOCLOSE
	end

ChronoIsland_ResortGorgeous_EventScript_JackiRematch::
	trainerbattle_rematch TRAINER_CLIFFORD, ChronoIsland_ResortGorgeous_Text_JackiRematchIntro, ChronoIsland_ResortGorgeous_Text_JackiDefeat
	msgbox ChronoIsland_ResortGorgeous_Text_JackiPostBattle, MSGBOX_AUTOCLOSE
	end

ChronoIsland_ResortGorgeous_EventScript_Gillian::
	trainerbattle_single TRAINER_LADY_GILLIAN, ChronoIsland_ResortGorgeous_Text_GillianIntro, ChronoIsland_ResortGorgeous_Text_GillianDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, ChronoIsland_ResortGorgeous_EventScript_GillianRematch
	msgbox ChronoIsland_ResortGorgeous_Text_GillianPostBattle, MSGBOX_AUTOCLOSE
	end

ChronoIsland_ResortGorgeous_EventScript_GillianRematch::
	trainerbattle_rematch TRAINER_CLIFFORD, ChronoIsland_ResortGorgeous_Text_GillianRematchIntro, ChronoIsland_ResortGorgeous_Text_GillianDefeat
	msgbox ChronoIsland_ResortGorgeous_Text_GillianPostBattle, MSGBOX_AUTOCLOSE
	end

ChronoIsland_ResortGorgeous_EventScript_Destin::
	trainerbattle_single TRAINER_YOUNGSTER_DESTIN, ChronoIsland_ResortGorgeous_Text_DestinIntro, ChronoIsland_ResortGorgeous_Text_DestinDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, ChronoIsland_ResortGorgeous_EventScript_DestinRematch
	msgbox ChronoIsland_ResortGorgeous_Text_DestinPostBattle, MSGBOX_AUTOCLOSE
	end

ChronoIsland_ResortGorgeous_EventScript_DestinRematch::
	trainerbattle_rematch TRAINER_CLIFFORD, ChronoIsland_ResortGorgeous_Text_DestinRematchIntro, ChronoIsland_ResortGorgeous_Text_DestinDefeat
	msgbox ChronoIsland_ResortGorgeous_Text_DestinPostBattle, MSGBOX_AUTOCLOSE
	end

ChronoIsland_ResortGorgeous_EventScript_Toby::
	trainerbattle_single TRAINER_SWIMMER_MALE_TOBY, ChronoIsland_ResortGorgeous_Text_TobyIntro, ChronoIsland_ResortGorgeous_Text_TobyDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, ChronoIsland_ResortGorgeous_EventScript_TobyRematch
	msgbox ChronoIsland_ResortGorgeous_Text_TobyPostBattle, MSGBOX_AUTOCLOSE
	end

ChronoIsland_ResortGorgeous_EventScript_TobyRematch::
	trainerbattle_rematch TRAINER_CLIFFORD, ChronoIsland_ResortGorgeous_Text_TobyRematchIntro, ChronoIsland_ResortGorgeous_Text_TobyDefeat
	msgbox ChronoIsland_ResortGorgeous_Text_TobyPostBattle, MSGBOX_AUTOCLOSE
	end

ChronoIsland_ResortGorgeous_EventScript_SelphysHouseSign::
	msgbox ChronoIsland_ResortGorgeous_Text_SelphysHouse, MSGBOX_SIGN
	end

ChronoIsland_ResortGorgeous_Text_DaisyIntro::
    .string "With these hands, I will create\n"
    .string "my victory!$"

ChronoIsland_ResortGorgeous_Text_DaisyDefeat::
    .string "The shame of this…\n"
    .string "I'm red-faced…$"

ChronoIsland_ResortGorgeous_Text_DaisyPostBattle::
    .string "Uh-oh, my paint tubes have\n"
    .string "scattered everywhere!$"

ChronoIsland_ResortGorgeous_Text_CelinaIntro::
    .string "Excuse me!\n"
    .string "I'm trying to paint.\l"
    .string "Please keep out of my sight!$"

ChronoIsland_ResortGorgeous_Text_CelinaDefeat::
    .string "This loss…\n"
    .string "I feel like I'm whiting out…$"

ChronoIsland_ResortGorgeous_Text_CelinaPostBattle::
    .string "GILLIAN?\n"
    .string "Please tilt your head slightly…\l"
    .string "There! That's the look I want!$"

ChronoIsland_ResortGorgeous_Text_RaynaIntro::
    .string "Hmm…\n"
    .string "The angle, it is not quite there…$"

ChronoIsland_ResortGorgeous_Text_RaynaDefeat::
    .string "Oh…\n"
    .string "My feelings, they are blue…$"

ChronoIsland_ResortGorgeous_Text_RaynaPostBattle::
    .string "The sky and the sea…\n"
    .string "They are so fickle.\p"
    .string "Their changing expressions make\n"
    .string "them difficult to capture.$"

ChronoIsland_ResortGorgeous_Text_JackiIntro::
    .string "I am visiting my friend's retreat,\n"
    .string "if you must know.$"

ChronoIsland_ResortGorgeous_Text_JackiDefeat::
    .string "Oh, my, so strong.$"

ChronoIsland_ResortGorgeous_Text_JackiPostBattle::
    .string "I find it pleasurable to leisurely\n"
    .string "battle in the gentle sea breeze.$"

ChronoIsland_ResortGorgeous_Text_GillianIntro::
    .string "I'm thinking of having a pool\n"
    .string "made specially for POKéMON.$"

ChronoIsland_ResortGorgeous_Text_GillianDefeat::
    .string "Oh, my goodness gracious!$"

ChronoIsland_ResortGorgeous_Text_GillianPostBattle::
    .string "A pool would be nice, but I must\n"
    .string "say, a sun-room may be sublime.$"

ChronoIsland_ResortGorgeous_Text_DestinIntro::
    .string "I'm a good runner.\n"
    .string "I'm really fast!$"

ChronoIsland_ResortGorgeous_Text_DestinDefeat::
    .string "Oops!\n"
    .string "I rushed things!$"

ChronoIsland_ResortGorgeous_Text_DestinPostBattle::
    .string "When I run with the wind, it feels\n"
    .string "like I could fly!$"

ChronoIsland_ResortGorgeous_Text_TobyIntro::
    .string "I say, this marine life here at\n"
    .string "this resort agrees with me.$"

ChronoIsland_ResortGorgeous_Text_TobyDefeat::
    .string "That's a shocker!\n"
    .string "You must be joking.$"

ChronoIsland_ResortGorgeous_Text_TobyPostBattle::
    .string "Getting so serious over this…\n"
    .string "How nonsensical.$"

ChronoIsland_ResortGorgeous_Text_DaisyRematchIntro::
	.string "With these hands, I will create\n"
	.string "my victory today.$"

ChronoIsland_ResortGorgeous_Text_CelinaRematchIntro::
	.string "Must I repeat myself?\n"
	.string "I'm trying to paint.\l"
	.string "Please keep out of my sight!$"

ChronoIsland_ResortGorgeous_Text_RaynaRematchIntro::
	.string "I haven't made any progress…\n"
	.string "I still can't get the right angle…$"

ChronoIsland_ResortGorgeous_Text_JackiRematchIntro::
	.string "Oh, you will give me another\n"
	.string "opportunity to match wits with you?$"

ChronoIsland_ResortGorgeous_Text_GillianRematchIntro::
	.string "They're almost finished making the\n"
	.string "pool for my POKéMON.\p"
	.string "You must drop in for a visit.$"

ChronoIsland_ResortGorgeous_Text_DestinRematchIntro::
	.string "I'm a good runner.\n"
	.string "I've gotten even faster!$"

ChronoIsland_ResortGorgeous_Text_TobyRematchIntro::
	.string "I say, friend!\n"
	.string "Let us enjoy our time together!$"

ChronoIsland_ResortGorgeous_Text_SelphyThanksYouMayGoNow::
    .string "SELPHY: Thank you.\p"
    .string "You may go now.$"

ChronoIsland_ResortGorgeous_Text_SelphysHouse::
    .string "SELPHY'S HOUSE$"

