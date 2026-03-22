FourIsland_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FourIsland_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

FourIsland_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_FOUR_ISLAND
	end

FourIsland_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse
	release
	end

FourIsland_PokemonCenter_1F_EventScript_Man::
	msgbox FourIsland_PokemonCenter_1F_Text_RareIceMonsInCave, MSGBOX_NPC
	end

FourIsland_PokemonCenter_1F_EventScript_Woman::
	msgbox FourIsland_PokemonCenter_1F_Text_DayCarePeopleFoundEggBefore, MSGBOX_NPC
	end

FourIsland_PokemonCenter_1F_EventScript_Gentleman::
	msgbox FourIsland_PokemonCenter_1F_Text_NewPokemonJournalHasntArrived, MSGBOX_NPC
	end
@ The 5 texts below are supposed to be in FourIsland_House1
Text_BodySlamTeach::
    .string "Ready?\n"
    .string "Boing!\p"
    .string "We're having a BODY SLAM match\n"
    .string "to see who wimps out first.\p"
    .string "If you were to join us, you'd be\n"
    .string "squashed like a bug, though窶ｦ\p"
    .string "How about I teach BODY SLAM to\n"
    .string "a POKﾃｩMON of yours instead?$"

Text_BodySlamDeclined::
    .string "Come again!\n"
    .string "Boing!$"

Text_BodySlamWhichMon::
    .string "Which POKﾃｩMON wants to learn how\n"
    .string "to BODY SLAM?$"

Text_BodySlamTaught::
    .string "Boioing!$"

FourIsland_House1_Text_FatMan::
    .string "縺昴ｌ縲縺ｼ繧医・繧難ｼ―n"
    .string "縺翫∪縺医縺翫ｂ縺・↑縺ゅ・・・"

FourIsland_PokemonCenter_1F_Text_RareIceMonsInCave::
    .string "There's a rare kind of ICE POKﾃｩMON\n"
    .string "that lives in the cave.\p"
    .string "We get a lot of visitors hoping to\n"
    .string "see that POKﾃｩMON.$"

FourIsland_PokemonCenter_1F_Text_DayCarePeopleFoundEggBefore::
    .string "Oh? A POKﾃｩMON EGG?\n"
    .string "窶ｦI have no idea.\p"
    .string "窶ｦOh, wait. The DAY-CARE people\n"
    .string "in town were saying something.\p"
    .string "They said that they'd found EGGS\n"
    .string "before on their property.$"

FourIsland_PokemonCenter_1F_Text_NewPokemonJournalHasntArrived::
    .string "What's this?\p"
    .string "The new POKﾃｩMON JOURNAL hasn't\n"
    .string "arrived on this island?$"

