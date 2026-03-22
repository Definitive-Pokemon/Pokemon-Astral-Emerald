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
	textcolor NPC_TEXT_COLOR_FEMALE
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

ChronoIsland_ResortGorgeous_Text_SelphyThanksYouMayGoNow::
    .string "SELPHY: Thank you.\p"
    .string "You may go now.$"

ChronoIsland_ResortGorgeous_Text_SelphysHouse::
    .string "SELPHY'S HOUSE$"

