.set DID_CHANSEY_DANCE, FLAG_TEMP_2
.set LOCALID_CHANSEY_DANCE_MAN, 1
QuestIsland_SevaultCanyon_House_MapScripts::
	.byte 0

QuestIsland_SevaultCanyon_House_EventScript_ChanseyDanceMan::
	lock
	goto_if_set DID_CHANSEY_DANCE, QuestIsland_SevaultCanyon_House_EventScript_AlreadyDanced
	playbgm MUS_SCHOOL, 0
	applymovement LOCALID_CHANSEY_DANCE_MAN, QuestIsland_SevaultCanyon_House_Movement_ChanseyDance
	waitmovement 0
	fadedefaultbgm
	delay 30
	applymovement LOCALID_CHANSEY_DANCE_MAN, Common_Movement_FacePlayer
	waitmovement 0
	msgbox QuestIsland_SevaultCanyon_House_Text_ChanseyDanceJoinIn

	msgbox QuestIsland_SevaultCanyon_House_Text_WouldYouLikeToDance, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, QuestIsland_SevaultCanyon_House_EventScript_DeclineDance
	msgbox QuestIsland_SevaultCanyon_House_Text_DancedChanseyDance
	closemessage
	call_if_ne VAR_FACING, DIR_SOUTH, QuestIsland_SevaultCanyon_House_EventScript_PlayerFaceDown
	delay 30
	playbgm MUS_SCHOOL, 0
	applymovement LOCALID_PLAYER, QuestIsland_SevaultCanyon_House_Movement_ChanseyDance
	waitmovement 0
	fadedefaultbgm
	delay 30
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox QuestIsland_SevaultCanyon_House_Text_YoureAllChipperNow
	setflag DID_CHANSEY_DANCE
	release
	end

QuestIsland_SevaultCanyon_House_EventScript_PlayerFaceDown::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

QuestIsland_SevaultCanyon_House_EventScript_AlreadyDanced::
	applymovement LOCALID_CHANSEY_DANCE_MAN, Common_Movement_FacePlayer
	waitmovement 0
	msgbox QuestIsland_SevaultCanyon_House_Text_ChanseyDanceJoinIn
	release
	end

QuestIsland_SevaultCanyon_House_EventScript_DeclineDance::

	msgbox QuestIsland_SevaultCanyon_House_Text_ComeOnDance
	release
	end

QuestIsland_SevaultCanyon_House_Movement_ChanseyDance::
	walk_in_place_down
	delay_16
	walk_in_place_down
	delay_16
	walk_in_place_down
	delay_16
	walk_in_place_down
	delay_16
	walk_in_place_faster_right
	delay_4
	walk_in_place_faster_up
	delay_4
	walk_in_place_faster_left
	delay_4
	walk_in_place_faster_down
	delay_4
	step_end

QuestIsland_SevaultCanyon_House_EventScript_Chansey::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_CHANSEY, CRY_MODE_NORMAL
	msgbox QuestIsland_SevaultCanyon_House_Text_Chansey
	waitmoncry
	release
	end
QuestIsland_SevaultCanyon_House_Text_ChanseyDanceJoinIn::
    .string "Dance, dance!\n"
    .string "CHANSEY Dance!\p"
    .string "You join in, too!\n"
    .string "Dance, dance!$"

QuestIsland_SevaultCanyon_House_Text_WouldYouLikeToDance::
    .string "Would you like to dance?$"

QuestIsland_SevaultCanyon_House_Text_ComeOnDance::
    .string "Come on, dance!$"

QuestIsland_SevaultCanyon_House_Text_DancedChanseyDance::
    .string "{PLAYER} danced the CHANSEY Dance!$"

QuestIsland_SevaultCanyon_House_Text_YoureAllChipperNow::
    .string "Ahahahaha!\p"
    .string "There, you're all chipper now!\n"
    .string "Lucky!$"

QuestIsland_SevaultCanyon_House_Text_Chansey::
    .string "CHANSEY: Chansi! Chansi!$"
