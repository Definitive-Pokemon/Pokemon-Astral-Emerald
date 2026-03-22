BoonIsland_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, BoonIsland_OnTransition
	.byte 0

BoonIsland_OnTransition::
	setflag FLAG_VISITED_BOON_ISLAND
	call BoonIsland_EventScript_SetShopState
	end

BoonIsland_EventScript_SetShopState::
	goto_if_set FLAG_SYS_CAN_LINK_WITH_RS, BoonIsland_EventScript_SetShopStateAfterHoennLink
	goto_if_set FLAG_SYS_GAME_CLEAR, BoonIsland_EventScript_SetShopStateAfterChampion
	goto_if_set FLAG_RESCUED_LOSTELLE, BoonIsland_EventScript_SetShopStateAfterLostelleRescue
	goto BoonIsland_EventScript_SetShopStateDefault
	end

BoonIsland_EventScript_SetShopStateAfterHoennLink::
	goto_if_unset FLAG_BOON_ISLAND_SHOP_INTRODUCED, BoonIsland_EventScript_SetShopInitial
	goto_if_unset FLAG_BOON_ISLAND_SHOP_EXPANDED_1, BoonIsland_EventScript_SetShopExpanded1
	goto_if_unset FLAG_BOON_ISLAND_SHOP_EXPANDED_2, BoonIsland_EventScript_SetShopExpanded2
	goto BoonIsland_EventScript_SetShopExpanded3
	end

BoonIsland_EventScript_SetShopStateAfterChampion::
	goto_if_unset FLAG_BOON_ISLAND_SHOP_INTRODUCED, BoonIsland_EventScript_SetShopInitial
	goto_if_unset FLAG_RESCUED_LOSTELLE, BoonIsland_EventScript_SetShopInitial
	goto_if_unset FLAG_BOON_ISLAND_SHOP_EXPANDED_1, BoonIsland_EventScript_SetShopExpanded1
	goto BoonIsland_EventScript_SetShopExpanded2
	end

BoonIsland_EventScript_SetShopStateAfterLostelleRescue::
	goto_if_unset FLAG_BOON_ISLAND_SHOP_INTRODUCED, BoonIsland_EventScript_SetShopInitial
	goto BoonIsland_EventScript_SetShopExpanded1
	end

BoonIsland_EventScript_SetShopStateDefault::
	goto BoonIsland_EventScript_SetShopInitial
	end

BoonIsland_EventScript_SetShopInitial::
	setvar VAR_MAP_SCENE_BOON_ISLAND, 1
	return

BoonIsland_EventScript_SetShopExpanded1::
	setvar VAR_MAP_SCENE_BOON_ISLAND, 2
	clearflag FLAG_HIDE_BOON_ISLAND_WOMAN
	return

BoonIsland_EventScript_SetShopExpanded2::
	setvar VAR_MAP_SCENE_BOON_ISLAND, 3
	clearflag FLAG_HIDE_BOON_ISLAND_BEAUTY
	return

BoonIsland_EventScript_SetShopExpanded3::
	setvar VAR_MAP_SCENE_BOON_ISLAND, 4
	clearflag FLAG_HIDE_BOON_ISLAND_SUPER_NERD
	return

BoonIsland_EventScript_Clerk::

	lock
	faceplayer
	goto_if_eq VAR_MAP_SCENE_BOON_ISLAND, 4, BoonIsland_EventScript_ClerkShopExpanded3
	goto_if_eq VAR_MAP_SCENE_BOON_ISLAND, 3, BoonIsland_EventScript_ClerkShopExpanded2
	goto_if_eq VAR_MAP_SCENE_BOON_ISLAND, 2, BoonIsland_EventScript_ClerkShopExpanded1
	goto BoonIsland_EventScript_ClerkShopInitial
	end

BoonIsland_EventScript_ClerkShopExpanded3::
	goto_if_set FLAG_BOON_ISLAND_SHOP_EXPANDED_3, BoonIsland_EventScript_ClerkShopSkipIntro
	setflag FLAG_BOON_ISLAND_SHOP_EXPANDED_3
	message BoonIsland_Text_BringingItemsFromDistantLands
	waitmessage
	goto BoonIsland_EventScript_ShopExpanded3
	end

BoonIsland_EventScript_ClerkShopExpanded2::
	goto_if_set FLAG_BOON_ISLAND_SHOP_EXPANDED_2, BoonIsland_EventScript_ClerkShopSkipIntro
	setflag FLAG_BOON_ISLAND_SHOP_EXPANDED_2
	message BoonIsland_Text_HopeYouGiveItYourBest
	waitmessage
	goto BoonIsland_EventScript_ShopExpanded2
	end

BoonIsland_EventScript_ClerkShopExpanded1::
	goto_if_set FLAG_BOON_ISLAND_SHOP_EXPANDED_1, BoonIsland_EventScript_ClerkShopSkipIntro
	setflag FLAG_BOON_ISLAND_SHOP_EXPANDED_1
	message BoonIsland_Text_AddedMerchandiseForLostelle
	waitmessage
	goto BoonIsland_EventScript_ShopExpanded1
	end

BoonIsland_EventScript_ClerkShopInitial::
	goto_if_set FLAG_BOON_ISLAND_SHOP_INTRODUCED, BoonIsland_EventScript_ClerkShopSkipIntro
	setflag FLAG_BOON_ISLAND_SHOP_INTRODUCED
	message BoonIsland_Text_WelcomeToShopMerchandiseLimited
	waitmessage
	goto BoonIsland_EventScript_ShopInitial
	end

BoonIsland_EventScript_ClerkShopSkipIntro::
	message Text_MayIHelpYou
	waitmessage
	goto_if_eq VAR_MAP_SCENE_BOON_ISLAND, 4, BoonIsland_EventScript_ShopExpanded3
	goto_if_eq VAR_MAP_SCENE_BOON_ISLAND, 3, BoonIsland_EventScript_ShopExpanded2
	goto_if_eq VAR_MAP_SCENE_BOON_ISLAND, 2, BoonIsland_EventScript_ShopExpanded1
	goto BoonIsland_EventScript_ShopInitial
	end

BoonIsland_EventScript_ShopInitial::
	pokemart BoonIsland_Items_ShopInitial
	msgbox Text_PleaseComeAgain
	release
	end

	.align 2
BoonIsland_Items_ShopInitial::
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_FRESH_WATER
	.2byte ITEM_NONE
	release
	end

BoonIsland_EventScript_ShopExpanded1::
	pokemart BoonIsland_Items_ShopExpanded1
	msgbox Text_PleaseComeAgain
	release
	end

	.align 2
BoonIsland_Items_ShopExpanded1::
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_SODA_POP
	.2byte ITEM_FRESH_WATER
	.2byte ITEM_NONE
	release
	end

BoonIsland_EventScript_ShopExpanded2::
	pokemart BoonIsland_Items_ShopExpanded2
	msgbox Text_PleaseComeAgain
	release
	end

	.align 2
BoonIsland_Items_ShopExpanded2::
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_LEMONADE
	.2byte ITEM_SODA_POP
	.2byte ITEM_FRESH_WATER
	.2byte ITEM_MOOMOO_MILK
	.2byte ITEM_NONE
	release
	end

BoonIsland_EventScript_ShopExpanded3::
	pokemart BoonIsland_Items_ShopExpanded3
	msgbox Text_PleaseComeAgain
	release
	end

	.align 2
BoonIsland_Items_ShopExpanded3::
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_REPEAT_BALL
	.2byte ITEM_TIMER_BALL
	.2byte ITEM_LEMONADE
	.2byte ITEM_SODA_POP
	.2byte ITEM_FRESH_WATER
	.2byte ITEM_MOOMOO_MILK
	.2byte ITEM_LAVA_COOKIE
	.2byte ITEM_NONE
	release
	end

BoonIsland_EventScript_Sailor::
	msgbox BoonIsland_Text_FellowMovedFromCeladonCity, MSGBOX_NPC
	end

BoonIsland_EventScript_Woman::
	msgbox BoonIsland_Text_ShopkeepersBrotherWorksGameCorner, MSGBOX_NPC
	end

BoonIsland_EventScript_Beauty::
	lock
	faceplayer
	famechecker FAMECHECKER_BRUNO, 4
	msgbox BoonIsland_Text_BrunoCameToIslandWhileBack
	release
	end

BoonIsland_EventScript_SuperNerd::
	msgbox BoonIsland_Text_BuyRareItemsHere, MSGBOX_NPC
	end

BoonIsland_EventScript_Boy::
	msgbox BoonIsland_Text_OldWomanLivesOutOnCape, MSGBOX_NPC
	end

BoonIsland_EventScript_LittleBoy::
	msgbox BoonIsland_Text_HaveYouTriedJumpingGame, MSGBOX_NPC
	end

BoonIsland_EventScript_IslandSign::
	msgbox BoonIsland_Text_IslandSign, MSGBOX_SIGN
	end

BoonIsland_EventScript_JoyfulGameCornerSign::
	msgbox BoonIsland_Text_JoyfulGameCornerSign, MSGBOX_SIGN
	end

BoonIsland_EventScript_FastCurrentSign::
	msgbox BoonIsland_Text_DangerFastCurrent, MSGBOX_SIGN
	end
BoonIsland_Text_IslandSign::
    .string "TWO ISLAND\n"
    .string "Boon Island for Two$"

BoonIsland_Text_JoyfulGameCornerSign::
    .string "Skip & Chomp!\n"
    .string "Joyful GAME CORNER$"

BoonIsland_Text_DangerFastCurrent::
    .string "DANGER! FAST CURRENT!\n"
    .string "Fishing and surfing prohibited!$"

BoonIsland_Text_WelcomeToShopMerchandiseLimited::
    .string "Oh!\n"
    .string "Hello, welcome to my shop!\p"
    .string "We've only opened up recently.\p"
    .string "Our merchandise is limited, but I\n"
    .string "hope we can serve your needs.$"

BoonIsland_Text_AddedMerchandiseForLostelle::
    .string "I can't tell you how grateful I am\n"
    .string "for your rescue of LOSTELLE.\p"
    .string "Thanks to your feat, the people of\n"
    .string "THREE ISLAND have changed their\l"
    .string "attitudes about KANTO people.\p"
    .string "And, I'm from KANTO, you see.\p"
    .string "The people of THREE ISLAND\n"
    .string "helped me add to my merchandise.$"

BoonIsland_Text_HopeYouGiveItYourBest::
    .string "Hi! I'm giving it my best here.\n"
    .string "I hope you do too, {PLAYER}.$"

BoonIsland_Text_BringingItemsFromDistantLands::
    .string "Oh, hello, {PLAYER}!\n"
    .string "Welcome!\p"
    .string "I've started bringing in items from\n"
    .string "distant lands.\p"
    .string "I've got some rare items in, too.\n"
    .string "Please have a look!$"

BoonIsland_Text_FellowMovedFromCeladonCity::
    .string "That fellow there, he moved here\n"
    .string "from CELADON CITY.\p"
    .string "He started up a shop with his\n"
    .string "younger brother.\p"
    .string "You have to wonder if he knew what\n"
    .string "he was getting into.$"

BoonIsland_Text_ShopkeepersBrotherWorksGameCorner::
    .string "The shopkeeper's brother took\n"
    .string "a job at the GAME CORNER.\p"
    .string "He's trying to pull together money\n"
    .string "so they can buy more merchandise.$"

BoonIsland_Text_BrunoCameToIslandWhileBack::
    .string "Listen, listen.\n"
    .string "Did you know?\p"
    .string "A famous TRAINER came to the\n"
    .string "ISLAND a little while back.\p"
    .string "He's one of the ELITE FOUR.\n"
    .string "His name is BRUNO.\p"
    .string "He went away disappointed when he\n"
    .string "found out that they were all sold\l"
    .string "out of Rage Candybars.$"

BoonIsland_Text_BuyRareItemsHere::
    .string "The discerning TRAINER knows to\n"
    .string "buy rare items here!$"

BoonIsland_Text_OldWomanLivesOutOnCape::
    .string "There's an old woman who lives in\n"
    .string "a cottage out on the cape.\p"
    .string "She gives the eye to POKéMON.\n"
    .string "It's a bit unnerving.$"

BoonIsland_Text_HaveYouTriedJumpingGame::
    .string "Boing! Boing!\n"
    .string "Have you tried the jumping game?\p"
    .string "The POKéMON you can enter…\n"
    .string "Boing!\p"
    .string "Some go boing!\p"
    .string "And some go boooooooing!\p"
    .string "Did you know that?\n"
    .string "Boing!$"

