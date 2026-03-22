QuestIsland_Mart_MapScripts::
	.byte 0

QuestIsland_Mart_EventScript_Clerk::
	lock
	faceplayer
	message Text_MayIHelpYou
	waitmessage
	pokemart QuestIsland_Mart_Items
	msgbox Text_PleaseComeAgain
	release
	end

	.align 2
QuestIsland_Mart_Items::
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_MAX_POTION
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_REVIVE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_NONE
	release
	end

QuestIsland_Mart_EventScript_Lass::
	msgbox QuestIsland_Mart_Text_MonHavePersonalitiesOfTheirOwn, MSGBOX_NPC
	end

QuestIsland_Mart_EventScript_Hiker::
	msgbox QuestIsland_Mart_Text_PreparationsCompleteForRuins, MSGBOX_NPC
	end

QuestIsland_Mart_EventScript_Fisher::
	msgbox QuestIsland_Mart_Text_NeedToFishOnQuestIsland, MSGBOX_NPC
	end
QuestIsland_Mart_Text_MonHavePersonalitiesOfTheirOwn::
    .string "POKéMON have personalities of their\n"
    .string "own, just like people.\p"
    .string "My PIKACHU has a HASTY nature,\n"
    .string "so it grew to be a speedy POKéMON.$"

QuestIsland_Mart_Text_PreparationsCompleteForRuins::
    .string "Okay, preparations are complete\n"
    .string "for me to explore the RUINS.$"

QuestIsland_Mart_Text_NeedToFishOnQuestIsland::
    .string "I need to fish on SEVEN ISLAND.\p"
    .string "That will complete my fishing tour\n"
    .string "of the SEVII ISLANDS.\p"
    .string "I'd better stock up on some\n"
    .string "POKé BALLS first, though.$"

