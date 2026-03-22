BoonIsland_Harbor_MapScripts::
	.byte 0

BoonIsland_Harbor_EventScript_Sailor::
	lock
	faceplayer
	message Text_WhereDoYouWantToSail
	waitmessage
	setvar VAR_0x8004, SEAGALLOP_BOON_ISLAND
	goto EventScript_ChooseDestFromBoonIsland
	end
