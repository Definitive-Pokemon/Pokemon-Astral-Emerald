#ifndef GUARD_REGIONS_H
#define GUARD_REGIONS_H

#include "global.h"
#include "strings.h"
#include "constants/regions.h"
#include "constants/region_map_sections.h"

static inline enum Region GetCurrentRegion(void)
{
    return gMapHeader.region;
}

static inline const u8 *GetCurrentRegionName(void)
{
    switch (GetCurrentRegion())
    {
    case REGION_HOENN:
        return gText_Hoenn;
    case REGION_SEVII:
        return gText_Sevii;
    case REGION_NONE:
    case REGIONS_COUNT:
        return gText_RegionDefault;
    }
    return gText_Hoenn;
}

#endif // GUARD_REGIONS_H