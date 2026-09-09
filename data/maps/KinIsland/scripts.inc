.set LOCALID_KIN_ISLAND_ANTIBIKER1, 1
.set LOCALID_KIN_ISLAND_ANTIBIKER2, 2
.set LOCALID_PAXTON, 3
.set LOCALID_KIN_ISLAND_BIKER3, 4
.set LOCALID_KIN_ISLAND_BIKER1, 5
.set LOCALID_KIN_ISLAND_BIKER4, 6
.set LOCALID_KIN_ISLAND_BIKER2, 7
.set LOCALID_KIN_ISLAND_BIKER5, 8
.set LOCALID_KIN_ISLAND_BIKER6, 14

KinIsland_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, KinIsland_OnTransition
	.byte 0

KinIsland_OnTransition::
	setflag FLAG_VISITED_KIN_ISLAND
	call_if_set FLAG_RESCUED_LOSTELLE, KinIsland_EventScript_HideAntiBikers
	call_if_eq VAR_MAP_SCENE_KIN_ISLAND, 4, KinIsland_EventScript_SetAntiBikersMovementAfterBikers
	end

KinIsland_EventScript_HideAntiBikers::
	setflag FLAG_HIDE_KIN_ISLAND_ANTIBIKERS
	return

KinIsland_EventScript_SetAntiBikersMovementAfterBikers::
	setobjectmovementtype LOCALID_KIN_ISLAND_ANTIBIKER1, MOVEMENT_TYPE_LOOK_AROUND
	setobjectmovementtype LOCALID_KIN_ISLAND_ANTIBIKER2, MOVEMENT_TYPE_LOOK_AROUND
	return

KinIsland_EventScript_Biker::
	lock
	setvar VAR_TEMP_1, 2
	call KinIsland_EventScript_BikerArgumentScene
	release
	end

KinIsland_EventScript_AntiBiker1::
	lock
	goto_if_set FLAG_GOT_FULL_RESTORE_FROM_KIN_ISLAND_DEFENDER, KinIsland_EventScript_AntiBiker1GotFullRestore
	goto_if_eq VAR_MAP_SCENE_KIN_ISLAND, 4, KinIsland_EventScript_GiveFullRestore
	setvar VAR_TEMP_1, 0
	call KinIsland_EventScript_BikerArgumentScene
	release
	end

KinIsland_EventScript_AntiBiker1GotFullRestore::
	applymovement LOCALID_KIN_ISLAND_ANTIBIKER1, Common_Movement_FacePlayer
	waitmovement 0
	msgbox KinIsland_Text_YouveGotImpressiveMons
	release
	end

KinIsland_EventScript_GiveFullRestore::
	applymovement LOCALID_KIN_ISLAND_ANTIBIKER1, Common_Movement_FacePlayer
	waitmovement 0
	msgbox KinIsland_Text_ThankYouOhYourMonGotHurt
	checkitemspace ITEM_FULL_RESTORE
	goto_if_eq VAR_RESULT, FALSE, KinIsland_EventScript_NoRoomForFullRestore
	giveitem ITEM_FULL_RESTORE
	@msgreceiveditem KinIsland_Text_GivenFullRestore, ITEM_FULL_RESTORE
	@additem ITEM_FULL_RESTORE
	setflag FLAG_GOT_FULL_RESTORE_FROM_KIN_ISLAND_DEFENDER
	msgbox KinIsland_Text_YouveGotImpressiveMons
	release
	end

KinIsland_EventScript_NoRoomForFullRestore::
	msgbox KinIsland_Text_OhYourBagIsFull
	release
	end

KinIsland_EventScript_BikerArgumentScene::
	call_if_eq VAR_TEMP_1, 1, KinIsland_EventScript_PlayerFaceLeft
	call_if_eq VAR_TEMP_1, 2, KinIsland_EventScript_PlayerFaceLeft
	applymovement LOCALID_KIN_ISLAND_ANTIBIKER1, KinIsland_Movement_SpeakRight
	waitmovement 0
	msgbox KinIsland_Text_GoBackToKanto
	call_if_eq VAR_TEMP_1, 0, KinIsland_EventScript_PlayerFaceRight
	call_if_eq VAR_TEMP_1, 1, KinIsland_EventScript_PlayerFaceRight
	call_if_eq VAR_TEMP_1, 2, KinIsland_EventScript_PlayerFaceBiker
	applymovement LOCALID_KIN_ISLAND_BIKER1, KinIsland_Movement_SpeakLeft
	waitmovement 0
	msgbox KinIsland_Text_BossIsOnHisWay
	call_if_eq VAR_TEMP_1, 0, KinIsland_EventScript_PlayerFaceUp
	call_if_eq VAR_TEMP_1, 1, KinIsland_EventScript_PlayerFaceUp
	call_if_eq VAR_TEMP_1, 2, KinIsland_EventScript_PlayerFaceAntiBiker
	applymovement LOCALID_KIN_ISLAND_ANTIBIKER2, KinIsland_Movement_SpeakRight
	waitmovement 0
	msgbox KinIsland_Text_GetOffIslandNow
	call_if_eq VAR_TEMP_1, 0, KinIsland_EventScript_PlayerFaceRight
	call_if_eq VAR_TEMP_1, 1, KinIsland_EventScript_PlayerFaceRight
	call_if_eq VAR_TEMP_1, 2, KinIsland_EventScript_PlayerFaceBiker
	applymovement LOCALID_KIN_ISLAND_BIKER3, KinIsland_Movement_SpeakLeft
	waitmovement 0
	msgbox KinIsland_Text_WhosGonnaMakeMe
	return

KinIsland_EventScript_PlayerFaceUp::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

@ Unused
KinIsland_EventScript_PlayerFaceDown::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

KinIsland_EventScript_PlayerFaceLeft::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

KinIsland_EventScript_PlayerFaceRight::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

KinIsland_EventScript_PlayerFaceBiker::
	getplayerxy VAR_0x8004, VAR_0x8005
	goto_if_ge VAR_0x8004, 9, KinIsland_EventScript_PlayerFaceUp
	goto KinIsland_EventScript_PlayerFaceRight
	end

KinIsland_EventScript_PlayerFaceAntiBiker::
	getplayerxy VAR_0x8004, VAR_0x8005
	goto_if_ge VAR_0x8004, 9, KinIsland_EventScript_PlayerFaceLeft
	goto KinIsland_EventScript_PlayerFaceUp
	end

KinIsland_EventScript_AntiBiker2::
	lock
	goto_if_eq VAR_MAP_SCENE_KIN_ISLAND, 4, KinIsland_EventScript_AntiBiker2BikersGone
	setvar VAR_TEMP_1, 1
	call KinIsland_EventScript_BikerArgumentScene
	release
	end

KinIsland_EventScript_AntiBiker2BikersGone::
	applymovement LOCALID_KIN_ISLAND_ANTIBIKER2, Common_Movement_FacePlayer
	waitmovement 0
	msgbox KinIsland_Text_LostelleWentOffTowardsBondBridge
	release
	end

KinIsland_EventScript_BikerBossIntroTrigger::
	lockall

	applymovement LOCALID_KIN_ISLAND_ANTIBIKER1, KinIsland_Movement_SpeakRight
	waitmovement 0
	msgbox KinIsland_Text_AreYouBossGoBackToKanto
	applymovement LOCALID_PAXTON, KinIsland_Movement_SpeakLeft
	waitmovement 0
	msgbox KinIsland_Text_JustGotHerePal
	applymovement LOCALID_KIN_ISLAND_ANTIBIKER1, KinIsland_Movement_SpeakRight
	waitmovement 0
	msgbox KinIsland_Text_FollowersRaisingHavoc
	applymovement LOCALID_PAXTON, KinIsland_Movement_SpeakLeft
	waitmovement 0
	msgbox KinIsland_Text_OughtToBeThankingUs
	applymovement LOCALID_KIN_ISLAND_ANTIBIKER1, KinIsland_Movement_SpeakRight
	waitmovement 0
	msgbox KinIsland_Text_YouCowardsToughInPack
	setvar VAR_MAP_SCENE_KIN_ISLAND, 3
	releaseall
	end

KinIsland_Movement_SpeakLeft::
	walk_in_place_left
	step_end

KinIsland_Movement_SpeakRight::
	walk_in_place_right
	step_end

KinIsland_EventScript_BattleBikersTriggerLeft::
	lockall
	setvar VAR_TEMP_1, 0
	goto KinIsland_EventScript_BattleBikersScene
	end

KinIsland_EventScript_BattleBikersTriggerMidLeft::
	lockall
	setvar VAR_TEMP_1, 1
	goto KinIsland_EventScript_BattleBikersScene
	end

KinIsland_EventScript_BattleBikersTriggerMid::
	lockall
	setvar VAR_TEMP_1, 2
	goto KinIsland_EventScript_BattleBikersScene
	end

KinIsland_EventScript_BattleBikersTriggerMidRight::
	lockall
	setvar VAR_TEMP_1, 3
	goto KinIsland_EventScript_BattleBikersScene
	end

KinIsland_EventScript_BattleBikersTriggerRight::
	lockall
	setvar VAR_TEMP_1, 4
	goto KinIsland_EventScript_BattleBikersScene
	end

KinIsland_EventScript_BattleBikersScene::

	applymovement LOCALID_KIN_ISLAND_BIKER1, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_KIN_ISLAND_BIKER1, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_KIN_ISLAND_BIKER1, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_KIN_ISLAND_BIKER1, KinIsland_Movement_BikerApproach
	waitmovement 0
	playbgm MUS_RG_ENCOUNTER_BOY, 0
	msgbox KinIsland_Text_WannaMakeSomethingOfYourStaring, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, KinIsland_EventScript_LeaveBikersAlone
	msgbox KinIsland_Text_Biker1Intro
	setvar VAR_LAST_TALKED, LOCALID_KIN_ISLAND_BIKER1
	trainerbattle_no_intro TRAINER_BIKER_GOON, KinIsland_Text_Biker1Defeat
	applymovement LOCALID_KIN_ISLAND_BIKER1, KinIsland_Movement_BikerSpeak
	waitmovement 0
	msgbox KinIsland_Text_Biker1PostBattle
	closemessage
	applymovement LOCALID_KIN_ISLAND_BIKER2, KinIsland_Movement_BikerApproach
	waitmovement 0
	playbgm MUS_RG_ENCOUNTER_BOY, 0
	msgbox KinIsland_Text_Biker2Intro
	setvar VAR_LAST_TALKED, LOCALID_KIN_ISLAND_BIKER2
	trainerbattle_no_intro TRAINER_BIKER_GOON_2, KinIsland_Text_Biker2Defeat
	applymovement LOCALID_KIN_ISLAND_BIKER2, KinIsland_Movement_BikerSpeak
	waitmovement 0
	msgbox KinIsland_Text_Biker2PostBattle
	closemessage
	applymovement LOCALID_KIN_ISLAND_BIKER3, KinIsland_Movement_BikerApproach
	waitmovement 0
	playbgm MUS_RG_ENCOUNTER_BOY, 0
	msgbox KinIsland_Text_Biker3Intro
	setvar VAR_LAST_TALKED, LOCALID_KIN_ISLAND_BIKER3
	trainerbattle_no_intro TRAINER_BIKER_GOON_3, KinIsland_Text_Biker3Defeat
	applymovement LOCALID_KIN_ISLAND_BIKER3, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	applymovement LOCALID_KIN_ISLAND_BIKER4, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_KIN_ISLAND_BIKER5, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox KinIsland_Text_Biker3PostBattle
	closemessage
	delay 45
	call_if_eq VAR_TEMP_1, 0, KinIsland_EventScript_PaxtonApproachLeft
	call_if_eq VAR_TEMP_1, 1, KinIsland_EventScript_PaxtonApproachMidLeft
	call_if_eq VAR_TEMP_1, 2, KinIsland_EventScript_PaxtonApproachMid
	call_if_eq VAR_TEMP_1, 3, KinIsland_EventScript_PaxtonApproachMidRight
	call_if_eq VAR_TEMP_1, 4, KinIsland_EventScript_PaxtonApproachRight
	playbgm MUS_RG_ENCOUNTER_BOY, 0
	msgbox KinIsland_Text_PaxtonIntro
	setvar VAR_LAST_TALKED, LOCALID_PAXTON
	trainerbattle_no_intro TRAINER_PAXTON, KinIsland_Text_PaxtonDefeat
	msgbox KinIsland_Text_PaxtonPostBattle
	closemessage
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_PAXTON
	removeobject LOCALID_KIN_ISLAND_BIKER1
	removeobject LOCALID_KIN_ISLAND_BIKER2
	removeobject LOCALID_KIN_ISLAND_BIKER3
	removeobject LOCALID_KIN_ISLAND_BIKER4
	removeobject LOCALID_KIN_ISLAND_BIKER5
	removeobject LOCALID_KIN_ISLAND_BIKER6
	fadescreen FADE_FROM_BLACK
	setvar VAR_MAP_SCENE_KIN_ISLAND, 4
	releaseall
	end

KinIsland_EventScript_PaxtonApproachLeft::
	applymovement LOCALID_KIN_ISLAND_BIKER3, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_PAXTON, KinIsland_Movement_PaxtonApproachLeft
	waitmovement 0
	return

KinIsland_EventScript_PaxtonApproachMidLeft::
	applymovement LOCALID_KIN_ISLAND_BIKER3, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_PAXTON, KinIsland_Movement_PaxtonApproachMidLeft
	waitmovement 0
	return

KinIsland_EventScript_PaxtonApproachMid::
	applymovement LOCALID_KIN_ISLAND_BIKER3, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_PAXTON, KinIsland_Movement_PaxtonApproachMid
	applymovement LOCALID_PLAYER, KinIsland_Movement_PlayerFacePaxton
	waitmovement 0
	return

KinIsland_EventScript_PaxtonApproachMidRight::
	applymovement LOCALID_KIN_ISLAND_BIKER3, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_PLAYER, KinIsland_Movement_PlayerFacePaxton
	applymovement LOCALID_PAXTON, KinIsland_Movement_PaxtonApproachMidRight
	waitmovement 0
	return

KinIsland_EventScript_PaxtonApproachRight::
	applymovement LOCALID_KIN_ISLAND_BIKER3, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_PLAYER, KinIsland_Movement_PlayerFacePaxton
	applymovement LOCALID_PAXTON, KinIsland_Movement_PaxtonApproachRight
	waitmovement 0
	return

KinIsland_EventScript_LeaveBikersAlone::
	msgbox KinIsland_Text_ThatsSmart
	closemessage
	applymovement LOCALID_PLAYER, KinIsland_Movement_PlayerLeaveBikers
	waitmovement 0
	applymovement LOCALID_KIN_ISLAND_BIKER1, KinIsland_Movement_Biker1ReturnToPack
	waitmovement 0
	fadedefaultbgm
	releaseall
	end

KinIsland_Movement_PlayerLeaveBikers::
	walk_down
	step_end

KinIsland_Movement_BikerApproach::
	walk_down
	step_end

KinIsland_Movement_Biker1ReturnToPack::
	walk_up
	walk_in_place_faster_left
	step_end

KinIsland_Movement_BikerSpeak::
	walk_in_place_down
	step_end

KinIsland_Movement_PaxtonApproachLeft::
	walk_down
	walk_left
	walk_in_place_faster_down
	step_end

KinIsland_Movement_PaxtonApproachMidLeft::
	walk_down
	step_end

KinIsland_Movement_PaxtonApproachMid::
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

KinIsland_Movement_PlayerFacePaxton::
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

KinIsland_Movement_PaxtonApproachMidRight::
	walk_down
	walk_down
	walk_right
	walk_in_place_faster_right
	step_end

KinIsland_Movement_PaxtonApproachRight::
	walk_down
	walk_down
	walk_right
	walk_right
	walk_in_place_faster_right
	step_end

KinIsland_EventScript_Woman::
	msgbox KinIsland_Text_WouldntWantToSeeBikersHereAgain, MSGBOX_NPC
	end

KinIsland_EventScript_LittleBoy::
	msgbox KinIsland_Text_WhenDodouEvolvesGoingToPlayGame, MSGBOX_NPC
	end

KinIsland_EventScript_Doduo::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_DODUO, CRY_MODE_NORMAL
	msgbox KinIsland_Text_Doduo
	waitmoncry
	release
	end

KinIsland_EventScript_IslandSign::
	msgbox KinIsland_Text_IslandSign, MSGBOX_SIGN
	end

KinIsland_EventScript_Biker6::
	msgbox KinIsland_Text_IslandBelongsToUs, MSGBOX_NPC
	end
KinIsland_Text_IslandSign::
    .string "THREE ISLAND\n"
    .string "Kin Island of Family Bonding$"

KinIsland_Text_IslandBelongsToUs::
    .string "Hyahoo!\p"
    .string "From this day on, this island\n"
    .string "belongs to us!$"

KinIsland_Text_GoBackToKanto::
    .string "We don't need you people bringing\n"
    .string "your noise and trouble here!\p"
    .string "We're asking you to go back to\n"
    .string "KANTO!$"

KinIsland_Text_BossIsOnHisWay::
    .string "Hey, go cry somewhere else.\n"
    .string "Our boss is on his way.\p"
    .string "When he gets here, we'll give you\n"
    .string "a k-rad motorbike show you won't\l"
    .string "soon forget!$"

KinIsland_Text_GetOffIslandNow::
    .string "W-what!? Not on your life!\n"
    .string "Get off the island now!$"

KinIsland_Text_WhosGonnaMakeMe::
    .string "Who's gonna make me?$"

KinIsland_Text_AreYouBossGoBackToKanto::
    .string "Are you the boss?\n"
    .string "Go back to KANTO right now!$"

KinIsland_Text_JustGotHerePal::
    .string "Hah?\p"
    .string "I just got here, pal.\p"
    .string "What's with the hostile attitude?\n"
    .string "It's mighty cold of you!$"

KinIsland_Text_FollowersRaisingHavoc::
    .string "Your gang of followers have been\n"
    .string "raising havoc on their bikes.\p"
    .string "Do you have any idea how much\n"
    .string "trouble they've caused us on the\l"
    .string "island?$"

KinIsland_Text_OughtToBeThankingUs::
    .string "No, man, I don't get it at all.\p"
    .string "Look at this place.\n"
    .string "What do you do for entertainment?\p"
    .string "You ought to be thanking us for\n"
    .string "livening up this sleepy village.\p"
    .string "But hey, if you insist, you can try\n"
    .string "making us leave.$"

KinIsland_Text_YouCowardsToughInPack::
    .string "Grr… You cowards…\n"
    .string "So tough in a pack…$"

KinIsland_Text_WannaMakeSomethingOfYourStaring::
    .string "You, what are you staring at?\n"
    .string "Don't you know it's not polite?\p"
    .string "You wanna make something of it\n"
    .string "or what?$"

KinIsland_Text_ThatsSmart::
    .string "That's smart.\n"
    .string "Keep your nose out of this.$"

KinIsland_Text_Biker1Intro::
    .string "Heh, I like your guts.\n"
    .string "You'll be losing money to me, but…$"

KinIsland_Text_Biker1Defeat::
    .string "Wha…\n"
    .string "What is this kid?!$"

KinIsland_Text_Biker1PostBattle::
    .string "Aww, man…\n"
    .string "Don't you dare laugh!$"

KinIsland_Text_Biker2Intro::
    .string "Aren't you from KANTO?\n"
    .string "You should be on our side!$"

KinIsland_Text_Biker2Defeat::
    .string "Stop fooling around!$"

KinIsland_Text_Biker2PostBattle::
    .string "What's the matter with you,\n"
    .string "getting all hot like that?\p"
    .string "Totally uncool, man!$"

KinIsland_Text_Biker3Intro::
    .string "We invited the boss out here,\n"
    .string "but you had to mess it up!\p"
    .string "You embarrassed us, man!$"

KinIsland_Text_Biker3Defeat::
    .string "… … …   … … …$"

KinIsland_Text_Biker3PostBattle::
    .string "Boss, I'm telling you, you've gotta\n"
    .string "do something about this kid!$"

KinIsland_Text_PaxtonIntro::
    .string "I've been watching you, and I'd say\n"
    .string "you've done enough.\p"
    .string "What are you, their friend or\n"
    .string "something?\p"
    .string "Then I guess you'll be battling me\n"
    .string "in their place.$"

KinIsland_Text_PaxtonDefeat::
    .string "All right, enough!\n"
    .string "We'll leave like you wanted!\p"
    .string "We'll be happy to see the last of\n"
    .string "this boring island!$"

KinIsland_Text_PaxtonPostBattle::
    .string "Humph! Yeah, go right on hanging\n"
    .string "around with these hayseeds!$"

KinIsland_Text_ThankYouOhYourMonGotHurt::
    .string "Thank you! Those goons were\n"
    .string "nothing but bad trouble.\p"
    .string "Oh, look, your POKéMON got hurt\n"
    .string "on my account.$"

KinIsland_Text_GivenFullRestore::
    .string "{PLAYER} was given\n"
    .string "a FULL RESTORE.$"

KinIsland_Text_OhYourBagIsFull::
    .string "Oh?\n"
    .string "Your BAG is full.$"

KinIsland_Text_YouveGotImpressiveMons::
    .string "You've got seriously impressive\n"
    .string "POKéMON with you.$"

KinIsland_Text_LostelleWentOffTowardsBondBridge::
    .string "It'd be fantastic if someone as\n"
    .string "strong as you lived here.\p"
    .string "I hope you'll at least stay here\n"
    .string "a while.\p"
    .string "…I beg your pardon?\n"
    .string "You're looking for LOSTELLE?\p"
    .string "LOSTELLE went off towards BOND\n"
    .string "BRIDGE a while ago.$"

KinIsland_Text_WouldntWantToSeeBikersHereAgain::
    .string "THREE ISLAND is actually the most\n"
    .string "populous of the islands here.\p"
    .string "Still, it could be less sleepy.\p"
    .string "But I wouldn't want to see goons\n"
    .string "like those BIKERS here again.$"

KinIsland_Text_WhenDodouEvolvesGoingToPlayGame::
    .string "I'm going to train my DODUO in the\n"
    .string "BERRY FOREST.\p"
    .string "When it evolves, I'm going to play\n"
    .string "a game on TWO ISLAND.$"

KinIsland_Text_Doduo::
    .string "DODUO: Gigiih!$"

