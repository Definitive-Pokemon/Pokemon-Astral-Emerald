FortuneIsland_DottedHole_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FortuneIsland_DottedHole_1F_OnTransition
	.byte 0

FortuneIsland_DottedHole_1F_OnTransition::
	@setworldmapflag FLAG_WORLD_MAP_FORTUNE_ISLAND_DOTTED_HOLE_1F
	end

FortuneIsland_DottedHole_B1F_EventScript_BrailleUp::
	lockall
	@braillemessage Braille_Text_Up
	waitbuttonpress
	releaseall
	end

FortuneIsland_DottedHole_B4F_EventScript_BrailleDown::
	lockall
	@braillemessage Braille_Text_Down
	waitbuttonpress
	releaseall
	end

FortuneIsland_DottedHole_B3F_EventScript_BrailleRight::
	lockall
	@braillemessage Braille_Text_Right
	waitbuttonpress
	releaseall
	end

FortuneIsland_DottedHole_B2F_EventScript_BrailleLeft::
	lockall
	@braillemessage Braille_Text_Left
	waitbuttonpress
	releaseall
	end
