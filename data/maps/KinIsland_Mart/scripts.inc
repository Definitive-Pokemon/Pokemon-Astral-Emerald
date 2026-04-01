KinIsland_Mart_MapScripts::
	.byte 0

KinIsland_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart KinIsland_Mart_Items
	msgbox gText_PleaseComeAgain
	release
	end

	.align 2
KinIsland_Mart_Items::
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_REVIVE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_NONE
	release
	end

KinIsland_Mart_EventScript_Picnicker::
	msgbox KinIsland_Mart_Text_TrueThatCeldadonDeptStoreBigger, MSGBOX_NPC
	end

KinIsland_Mart_EventScript_BugCatcher::
	msgbox KinIsland_Mart_Text_PeopleHealWithBerriesFromForest, MSGBOX_NPC
	end

KinIsland_Mart_EventScript_Youngster::
	msgbox KinIsland_Mart_Text_BikersWereAboutToTrashMart, MSGBOX_NPC
	end
KinIsland_Mart_Text_TrueThatCeldadonDeptStoreBigger::
    .string "Is it true?\p"
    .string "CELADON DEPT. STORE is several\n"
    .string "times bigger than this shop?$"

KinIsland_Mart_Text_PeopleHealWithBerriesFromForest::
    .string "I sometimes buy medicine here.\p"
    .string "But a lot of people heal POKéMON\n"
    .string "with BERRIES from BERRY FOREST.\p"
    .string "After all, BERRIES are free and\n"
    .string "they never run out.$"

KinIsland_Mart_Text_BikersWereAboutToTrashMart::
    .string "Those BIKERS were about to trash\n"
    .string "this POKéMON MART.\p"
    .string "Am I glad they decided to leave!$"

