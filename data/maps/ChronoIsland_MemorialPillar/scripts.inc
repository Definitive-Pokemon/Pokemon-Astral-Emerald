.set LOCALID_MEMORIAL_MAN, 1

ChronoIsland_MemorialPillar_MapScripts::
	.byte 0

ChronoIsland_MemorialPillar_EventScript_MemorialMan::
	lock
	goto_if_set FLAG_GOT_TM42_AT_MEMORIAL_PILLAR, ChronoIsland_MemorialPillar_EventScript_AlreadyGotTM42
	goto_if_set FLAG_NO_ROOM_FOR_TM42_AT_MEMORIAL_PILLAR, ChronoIsland_MemorialPillar_EventScript_ReturnedForTM42
	msgbox ChronoIsland_MemorialPillar_Text_ScrubScrub
	closemessage
	applymovement LOCALID_MEMORIAL_MAN, Common_Movement_FacePlayer
	waitmovement 0
	delay 45
	msgbox ChronoIsland_MemorialPillar_Text_YourMonsLookHealthy
	applymovement LOCALID_MEMORIAL_MAN, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox ChronoIsland_MemorialPillar_Text_ThisIsWhereIBuriedMyOnix
	release
	end

ChronoIsland_MemorialPillar_EventScript_AlreadyGotTM42::
	msgbox ChronoIsland_MemorialPillar_Text_ScrubScrubTectonix
	release
	end

ChronoIsland_MemorialPillar_EventScript_ReturnedForTM42::
	msgbox ChronoIsland_MemorialPillar_Text_StillHaveThingAsMyThanks
	giveitem ITEM_TM42
	goto_if_eq VAR_RESULT, FALSE, ChronoIsland_MemorialPillar_EventScript_NoRoomForTM42
	call ChronoIsland_MemorialPillar_EventScript_ReceivedTM42
	release
	end

ChronoIsland_MemorialPillar_EventScript_Memorial::
	lockall
	goto_if_set FLAG_GOT_TM42_AT_MEMORIAL_PILLAR, ChronoIsland_MemorialPillar_EventScript_MemorialLemonadeAlreadyPlaced
	goto_if_set FLAG_NO_ROOM_FOR_TM42_AT_MEMORIAL_PILLAR, ChronoIsland_MemorialPillar_EventScript_MemorialLemonadeAlreadyPlaced
	msgbox ChronoIsland_MemorialPillar_Text_HereLiesTectonixLemonadeOffering
	checkitem ITEM_LEMONADE
	goto_if_eq VAR_RESULT, TRUE, ChronoIsland_MemorialPillar_EventScript_AskPlaceLemonade
	releaseall
	end

ChronoIsland_MemorialPillar_EventScript_AskPlaceLemonade::
	msgbox ChronoIsland_MemorialPillar_Text_LeaveAnotherLemonadeOffering, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, ChronoIsland_MemorialPillar_EventScript_PlaceLemonade
	releaseall
	end

ChronoIsland_MemorialPillar_EventScript_PlaceLemonade::
	removeitem ITEM_LEMONADE
	msgbox ChronoIsland_MemorialPillar_Text_PlacedCanOfLemonade
	closemessage
	applymovement LOCALID_MEMORIAL_MAN, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 45
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	textcolor NPC_TEXT_COLOR_MALE
	msgbox ChronoIsland_MemorialPillar_Text_ThankYouPleaseTakeThis
	giveitem ITEM_TM42
	goto_if_eq VAR_RESULT, FALSE, ChronoIsland_MemorialPillar_EventScript_NoRoomForTM42
	call ChronoIsland_MemorialPillar_EventScript_ReceivedTM42
	releaseall
	end

ChronoIsland_MemorialPillar_EventScript_ReceivedTM42::
	msgbox ChronoIsland_MemorialPillar_Text_BeGoodToYourMonsToo
	applymovement LOCALID_MEMORIAL_MAN, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	setflag FLAG_GOT_TM42_AT_MEMORIAL_PILLAR
	return

ChronoIsland_MemorialPillar_EventScript_NoRoomForTM42::
	setflag FLAG_NO_ROOM_FOR_TM42_AT_MEMORIAL_PILLAR
	msgbox ChronoIsland_MemorialPillar_Text_DontHaveRoomForIt
	releaseall
	end

ChronoIsland_MemorialPillar_EventScript_MemorialLemonadeAlreadyPlaced::
	msgbox ChronoIsland_MemorialPillar_Text_HereLiesTectonix
	releaseall
	end
ChronoIsland_MemorialPillar_Text_MiloIntro::
    .string "I'm the eldest of the BIRD\n"
    .string "BROTHERS.\p"
    .string "The best thing about birds…\n"
    .string "It has to be the beak.$"

ChronoIsland_MemorialPillar_Text_MiloDefeat::
    .string "Oh, so sharp!$"

ChronoIsland_MemorialPillar_Text_MiloPostBattle::
    .string "You can fly to FOUR ISLAND from\n"
    .string "here.$"

ChronoIsland_MemorialPillar_Text_ChazIntro::
    .string "I'm the middle kid of the BIRD\n"
    .string "BROTHERS.\p"
    .string "The best thing about birds…\n"
    .string "It has to be the wings.$"

ChronoIsland_MemorialPillar_Text_ChazDefeat::
    .string "Flap, flap!$"

ChronoIsland_MemorialPillar_Text_ChazPostBattle::
    .string "There was a really somber guy\n"
    .string "over that way.$"

ChronoIsland_MemorialPillar_Text_HaroldIntro::
    .string "I'm the youngest of the BIRD\n"
    .string "BROTHERS.\p"
    .string "The best thing about birds…\n"
    .string "It has to be the down.$"

ChronoIsland_MemorialPillar_Text_HaroldDefeat::
    .string "Down is so comfy…\n"
    .string "It makes me drowsy…$"

ChronoIsland_MemorialPillar_Text_HaroldPostBattle::
    .string "It fills me with happiness when\n"
    .string "bird POKéMON beg playfully…$"

ChronoIsland_MemorialPillar_Text_ScrubScrub::
    .string "Scrub, scrub…$"

ChronoIsland_MemorialPillar_Text_YourMonsLookHealthy::
    .string "Hello…\n"
    .string "Your POKéMON look healthy…$"

ChronoIsland_MemorialPillar_Text_ThisIsWhereIBuriedMyOnix::
    .string "This is where I buried my ONIX…\n"
    .string "It was named TECTONIX…$"

ChronoIsland_MemorialPillar_Text_HereLiesTectonixLemonadeOffering::
    .string "“Here lies TECTONIX Eis engraved\n"
    .string "on a boulder.\p"
    .string "There is a LEMONADE placed as an\n"
    .string "offering in front of the grave.$"

ChronoIsland_MemorialPillar_Text_LeaveAnotherLemonadeOffering::
    .string "Would you like to leave another\n"
    .string "LEMONADE as an offering?$"

ChronoIsland_MemorialPillar_Text_PlacedCanOfLemonade::
    .string "{PLAYER} placed a can of LEMONADE\n"
    .string "in front of the grave.$"

ChronoIsland_MemorialPillar_Text_ThankYouPleaseTakeThis::
    .string "Th-thank you…\p"
    .string "That was my TECTONIX's favorite\n"
    .string "drink…\p"
    .string "I don't even know you, but your\n"
    .string "act of kindness…\p"
    .string "It's uplifted me a little.\p"
    .string "Can you please take this as my\n"
    .string "thanks?$"

ChronoIsland_MemorialPillar_Text_BeGoodToYourMonsToo::
    .string "Please be good to your POKéMON,\n"
    .string "too.$"

ChronoIsland_MemorialPillar_Text_DontHaveRoomForIt::
    .string "If you don't have room for it,\n"
    .string "I'll hold it for you till next time.$"

ChronoIsland_MemorialPillar_Text_StillHaveThingAsMyThanks::
    .string "Oh, it's you from that time…\p"
    .string "I still have that thing I wanted\n"
    .string "you to have as my thanks.$"

ChronoIsland_MemorialPillar_Text_ScrubScrubTectonix::
    .string "Scrub, scrub…\p"
    .string "… … …\n"
    .string "TECTONIX…$"

ChronoIsland_MemorialPillar_Text_HereLiesTectonix::
    .string "Boulders and rocks are neatly piled\n"
    .string "up as a cairn.\p"
    .string "“Here lies TECTONIX Eis engraved\n"
    .string "on a boulder.$"

