#ifndef GUARD_DATA_H
#define GUARD_DATA_H

#include "constants/moves.h"

#define N_FOLLOWER_HAPPY_MESSAGES 31
#define N_FOLLOWER_NEUTRAL_MESSAGES 14
#define N_FOLLOWER_SAD_MESSAGES 3
#define N_FOLLOWER_UPSET_MESSAGES 3
#define N_FOLLOWER_ANGRY_MESSAGES 5
#define N_FOLLOWER_PENSIVE_MESSAGES 20
#define N_FOLLOWER_LOVE_MESSAGES 10
#define N_FOLLOWER_SURPRISE_MESSAGES 20
#define N_FOLLOWER_CURIOUS_MESSAGES 7
#define N_FOLLOWER_MUSIC_MESSAGES 14
#define N_FOLLOWER_POISONED_MESSAGES 1

#define MAX_TRAINER_ITEMS 4

#define TRAINER_PIC_WIDTH 64
#define TRAINER_PIC_HEIGHT 64
#define TRAINER_PIC_SIZE (TRAINER_PIC_WIDTH * TRAINER_PIC_HEIGHT / 2)

// Red and Leaf's back pics have 5 frames, but this is presumably irrelevant in the places this is used.
#define MAX_TRAINER_PIC_FRAMES 4

enum {
    BATTLER_AFFINE_NORMAL,
    BATTLER_AFFINE_EMERGE,
    BATTLER_AFFINE_RETURN,
};

struct MonCoords
{
    // This would use a bitfield, but some function
    // uses it as a u8 and casting won't match.
    u8 size; // u8 width:4, height:4;
    u8 y_offset;
};

#define MON_COORDS_SIZE(width, height)(DIV_ROUND_UP(width, 8) << 4 | DIV_ROUND_UP(height, 8))
#define GET_MON_COORDS_WIDTH(size)((size >> 4) * 8)
#define GET_MON_COORDS_HEIGHT(size)((size & 0xF) * 8)

struct TrainerMonNoItemDefaultMoves
{
    u16 iv;
    u8 lvl;
    u16 species;
};

struct TrainerMonItemDefaultMoves
{
    u16 iv;
    u8 lvl;
    u16 species;
    u16 heldItem;
};

struct TrainerMonNoItemCustomMoves
{
    u16 iv;
    u8 lvl;
    u16 species;
    u16 moves[MAX_MON_MOVES];
};

struct TrainerMonItemCustomMoves
{
    u16 iv;
    u8 lvl;
    u16 species;
    u16 heldItem;
    u16 moves[MAX_MON_MOVES];
};

struct TrainerMonItemCustomMovesEVs
{
    u16 iv;
    u8 lvl;
    u16 species;
    u16 heldItem;
    u16 moves[MAX_MON_MOVES];
    u8 evs[NUM_STATS];
};

// NOTE: this one requires every individual IV to be set!
struct TrainerMonItemCustomMovesEVsSpecificAbility
{
    u8 ivs[NUM_STATS];
    u8 lvl;
    u16 species;
    u16 heldItem;
    u16 moves[MAX_MON_MOVES];
    u8 evs[NUM_STATS];
    u16 ability:2;
    u16 unused:14; // just for clarity
};

union TrainerMonPtr
{
    const struct TrainerMonNoItemDefaultMoves *NoItemDefaultMoves;
    const struct TrainerMonNoItemCustomMoves *NoItemCustomMoves;
    const struct TrainerMonItemDefaultMoves *ItemDefaultMoves;
    const struct TrainerMonItemCustomMoves *ItemCustomMoves;
    const struct TrainerMonItemCustomMovesEVs *ItemCustomMovesEVs;
    const struct TrainerMonItemCustomMovesEVsSpecificAbility *AllCustom;
};

struct TrainerParty
{
    u8 flags;
    u8 size;
    union TrainerMonPtr monPointers;
};

struct Trainer
{
    u8 trainerClass;
    u8 encounterMusic_gender; // last bit is gender
    u8 trainerPic;
    u8 trainerName[TRAINER_NAME_LENGTH + 1];
    u16 items[MAX_TRAINER_ITEMS];
    bool8 doubleBattle;
    u32 aiFlags;
    struct TrainerParty party;
    struct TrainerParty classicParty;
};

#define NO_ITEM_DEFAULT_MOVES(identifier) { monPointers = { .NoItemDefaultMoves = identifier },\
.flags = 0,\
.size = ARRAY_COUNT(identifier)}

#define NO_ITEM_CUSTOM_MOVES(identifier) { monPointers = { .NoItemCustomMoves = identifier },\
.flags = F_TRAINER_PARTY_CUSTOM_MOVESET,\
.size = ARRAY_COUNT(identifier)}

#define ITEM_DEFAULT_MOVES(identifier) { monPointers = { .ItemDefaultMoves = identifier },\
.flags = F_TRAINER_PARTY_HELD_ITEM,\
.size = ARRAY_COUNT(identifier)}

#define ITEM_CUSTOM_MOVES(identifier) { monPointers = { .ItemCustomMoves = identifier },\
.flags = F_TRAINER_PARTY_CUSTOM_MOVESET | F_TRAINER_PARTY_HELD_ITEM,\
.size = ARRAY_COUNT(identifier)}

#define ITEM_CUSTOM_MOVES_EVS(identifier) { monPointers = { .ItemCustomMovesEVs = identifier },\
.flags = F_TRAINER_PARTY_CUSTOM_MOVESET | F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_EV_SET,\
.size = ARRAY_COUNT(identifier)}

#define ALL_CUSTOM(identifier) { monPointers = { .AllCustom = identifier },\
.flags = F_TRAINER_PARTY_CUSTOM_MOVESET | F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_EV_SET | F_TRAINER_PARTY_SET_ABILITY,\
.size = ARRAY_COUNT(identifier)}

#define LINK_TRAINER_MONS(trainerId, modernType, classicType) \
.party = modernType(sParty_##trainerId),\
.classicParty = classicType(sClassicParty_##trainerId)

#define TRAINER_ENCOUNTER_MUSIC(trainer)((gTrainers[trainer].encounterMusic_gender & 0x7F))

struct FollowerMsgInfo {
    const u8 *text;
    const u8 *script;
};

struct FollowerMessagePool
{
    const struct FollowerMsgInfo * messages;
    const u8 * script;
    u16 length;
};


extern const u16 gMinigameDigits_Pal[];
extern const u32 gMinigameDigits_Gfx[];

extern const struct SpriteFrameImage gBattlerPicTable_PlayerLeft[];
extern const struct SpriteFrameImage gBattlerPicTable_OpponentLeft[];
extern const struct SpriteFrameImage gBattlerPicTable_PlayerRight[];
extern const struct SpriteFrameImage gBattlerPicTable_OpponentRight[];
extern const struct SpriteFrameImage gTrainerBackPicTable_Brendan[];
extern const struct SpriteFrameImage gTrainerBackPicTable_May[];
extern const struct SpriteFrameImage gTrainerBackPicTable_Red[];
extern const struct SpriteFrameImage gTrainerBackPicTable_Leaf[];
extern const struct SpriteFrameImage gTrainerBackPicTable_RubySapphireBrendan[];
extern const struct SpriteFrameImage gTrainerBackPicTable_RubySapphireMay[];
extern const struct SpriteFrameImage gTrainerBackPicTable_Wally[];
extern const struct SpriteFrameImage gTrainerBackPicTable_Steven[];

extern const union AffineAnimCmd *const gAffineAnims_BattleSpritePlayerSide[];
extern const union AffineAnimCmd *const gAffineAnims_BattleSpriteOpponentSide[];
extern const union AffineAnimCmd *const gAffineAnims_BattleSpriteContest[];

extern const union AnimCmd *const gAnims_MonPic[];
extern const struct MonCoords gMonFrontPicCoords[];
extern const struct CompressedSpriteSheet gMonStillFrontPicTable[];
extern const struct MonCoords gMonBackPicCoords[];
extern const struct CompressedSpriteSheet gMonBackPicTable[];
extern const struct CompressedSpritePalette gMonPaletteTable[];
extern const struct CompressedSpritePalette gMonShinyPaletteTable[];
extern const struct CompressedSpritePalette gMonShinyPaletteTable_Modern[];
extern const union AnimCmd *const *const gTrainerFrontAnimsPtrTable[];
extern const struct MonCoords gTrainerFrontPicCoords[];
extern const struct CompressedSpriteSheet gTrainerFrontPicTable[];
extern const struct CompressedSpritePalette gTrainerFrontPicPaletteTable[];
extern const union AnimCmd *const *const gTrainerBackAnimsPtrTable[];
extern const struct MonCoords gTrainerBackPicCoords[];
extern const struct CompressedSpriteSheet gTrainerBackPicTable[]; // functionally unused
extern const struct CompressedSpritePalette gTrainerBackPicPaletteTable[];

extern const u8 gEnemyMonElevation[NUM_SPECIES];

extern const union AnimCmd *const *const gMonFrontAnimsPtrTable[];
extern const struct CompressedSpriteSheet gMonFrontPicTable[];

extern const struct Trainer gTrainers[];
extern const u8 gTrainerClassNames[][13];
extern const u8 gSpeciesNames[][POKEMON_NAME_LENGTH + 1];
extern const u8 gMoveNames[MOVES_COUNT][MOVE_NAME_LENGTH + 1];

// Follower text messages
extern const struct FollowerMsgInfo gFollowerHappyMessages[];
extern const struct FollowerMsgInfo gFollowerNeutralMessages[];
extern const struct FollowerMsgInfo gFollowerSadMessages[];
extern const struct FollowerMsgInfo gFollowerUpsetMessages[];
extern const struct FollowerMsgInfo gFollowerAngryMessages[];
extern const struct FollowerMsgInfo gFollowerPensiveMessages[];
extern const struct FollowerMsgInfo gFollowerLoveMessages[];
extern const struct FollowerMsgInfo gFollowerSurpriseMessages[];
extern const struct FollowerMsgInfo gFollowerCuriousMessages[];
extern const struct FollowerMsgInfo gFollowerMusicMessages[];
extern const struct FollowerMsgInfo gFollowerPoisonedMessages[];

#endif // GUARD_DATA_H
