MeteorFalls_B1F_2R_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MeteorFalls_B1F_2R_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, EncounterTable
	.byte 0

MeteorFalls_B1F_2R_OnTransition::
	callnative ChangeEncounterTable
	end
