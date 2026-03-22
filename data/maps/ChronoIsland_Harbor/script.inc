ChronoIsland_Harbor_MapScripts::
	.byte 0

ChronoIsland_Harbor_EventScript_Sailor::
	lock
	faceplayer
	message Text_WhereDoYouWantToSail
	waitmessage
	setvar VAR_0x8004, SEAGALLOP_CHRONO_ISLAND
	goto EventScript_ChooseDestFromIsland
	end
