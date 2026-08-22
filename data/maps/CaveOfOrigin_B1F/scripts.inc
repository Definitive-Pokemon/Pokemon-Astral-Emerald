.set LOCALID_WALLACE, 1

CaveOfOrigin_B1F_MapScripts::
	.byte 0

CaveOfOrigin_B1F_EventScript_Wallace::
	lock
	faceplayer
	msgbox CaveOfOrigin_B1F_Text_WallaceStory, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_WALLACE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 60
	playse SE_PIN
	applymovement LOCALID_WALLACE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_WALLACE, Common_Movement_Delay48
	waitmovement 0
	delay 30
	applymovement LOCALID_WALLACE, Common_Movement_FacePlayer
	waitmovement 0
	msgbox CaveOfOrigin_B1F_Text_WellHeadToSkyPillar, MSGBOX_DEFAULT
	closemessage
	playse SE_EXIT
	fadescreenspeed FADE_TO_BLACK, 4
	setflag FLAG_WALLACE_GOES_TO_SKY_PILLAR
	setvar VAR_SOOTOPOLIS_CITY_STATE, 3
	removeobject LOCALID_WALLACE
	clearflag FLAG_HIDE_SKY_PILLAR_WALLACE
	fadescreen FADE_FROM_BLACK
	release
	end

CaveOfOrigin_B1F_Text_WallaceStory:
	.string "Ah, so you are {PLAYER}{KUN}?\p"
	.string "I've heard such marvelous tales of your\n"
	.string "exploits.\p"
	.string "My name is Wallace.\p"
	.string "I was once the Gym Leader of\n"
	.string "Sootopolis, but something came up.\p"
	.string "So now, I've entrusted my mentor Juan\n"
	.string "with the Gym's operation.\p"
	.string "And now, here we are…\n"
	.string "standing amidst a legend.\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Groudon and Kyogre… such power.\p"
	.string "But according to the ancient carvings\n"
	.string "here in the Cave of Origin, there is yet\l"
	.string "another being.\p"
	.string "A sacred Pokémon, known in legends\n"
	.string "as the Dragon Lord.\p"
	.string "It is said that in times of strife, this\n"
	.string "ethereal being descended from the\l"
	.string "heavens to quell the chaos below.\p"
	.string "I believe that seeking out this\n"
	.string "Dragon Lord may be our only hope.\p"
	.string "The Sky Pillar, a monument to its\n"
	.string "majesty, lies waiting on Route 131.\p"
	.string "I trust that we will find the answers we\n"
	.string "seek there.\p"
	.string "I've studied the carvings, and at long\n"
	.string "last…\p"
	.string "I believe I know how to unlock its\n"
	.string "secrets.$"

CaveOfOrigin_B1F_Text_WellHeadToSkyPillar:
	.string "Wallace: {PLAYER}{KUN}, will you\n"
	.string "accompany me?\p"
	.string "There's not a moment to lose!\p"
	.string "Let us make haste to the Sky Pillar.\n"
	.string "Time is of the essence!\p"
	.string "I will go ahead and prepare to open\n"
	.string "its entrance.\p"
	.string "Please meet me there as soon as you can.$"
