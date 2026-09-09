MtEmber_RubyPath_B5F_MapScripts::
	.byte 0

MtEmber_RubyPath_B5F_EventScript_BrailleMessage::
	lockall
	setvar VAR_0x8005, 130
	waitbuttonpress
	releaseall
	end
