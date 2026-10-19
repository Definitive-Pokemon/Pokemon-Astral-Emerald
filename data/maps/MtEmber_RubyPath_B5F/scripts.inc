MtEmber_RubyPath_B5F_MapScripts::
	.byte 0

MtEmber_RubyPath_B5F_EventScript_BrailleMessage::
	lockall
	setvar VAR_0x8005, 130
	waitbuttonpress
	releaseall
	end

MtEmber_RubyPath_B5F_EventScript_Ruby::
	lock
	faceplayer
	@setflag FLAG_GOT_RUBY
	removeobject LOCALID_RUBY
	@giveitem_msg MtEmber_RubyPath_B5F_Text_FoundARuby, ITEM_RUBY, 1, MUS_RG_OBTAIN_KEY_ITEM
	giveitem ITEM_RUBY
	release
	end

MtEmber_RubyPath_B5F_Text_FoundARuby::
    .string "{PLAYER} found a RUBY!$"
