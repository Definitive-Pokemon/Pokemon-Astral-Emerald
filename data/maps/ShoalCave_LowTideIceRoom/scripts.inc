
ShoalCave_LowTideIceRoom_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ShoalCave_LowTideIceRoom_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, EncounterTable
	.byte 0

ShoalCave_LowTideIceRoom_OnTransition::
	callnative ChangeEncounterTable
	end
