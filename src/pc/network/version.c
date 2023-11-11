#include <stdio.h>
#include "version.h"
#include "types.h"
#include "pc/pc_main.h"

static char sVersionString[MAX_VERSION_LENGTH] = { 0 };
static char sLocalVersionString[MAX_LOCAL_VERSION_LENGTH] = { 0 };

const char* get_version(void) {
    if (gCoopCompatibility) {
#if defined(VERSION_US)
        if (MINOR_VERSION_NUMBER > 0) {
            snprintf(sVersionString, MAX_VERSION_LENGTH, "%s%d.%d", VERSION_TEXT, VERSION_NUMBER, MINOR_VERSION_NUMBER);
        } else {
            snprintf(sVersionString, MAX_VERSION_LENGTH, "%s%d", VERSION_TEXT, VERSION_NUMBER);
        }
#else
        if (MINOR_VERSION_NUMBER > 0) {
            snprintf(sVersionString, MAX_VERSION_LENGTH, "%s%d.%d %s", VERSION_TEXT, VERSION_NUMBER, MINOR_VERSION_NUMBER, VERSION_REGION);
        } else {
            snprintf(sVersionString, MAX_VERSION_LENGTH, "%s%d %s", VERSION_TEXT, VERSION_NUMBER, VERSION_REGION);
        }
#endif
    } else {
#if defined(VERSION_US)
        snprintf(sVersionString, MAX_VERSION_LENGTH, "%s", SM64COOPDX_VERSION);
#else
        snprintf(sVersionString, MAX_VERSION_LENGTH, "%s %s", SM64COOPDX_VERSION, VERSION_REGION);
#endif
    }
    return sVersionString;
}

const char* get_version_local(void) {
    if (PATCH_VERSION_NUMBER <= 0) {
        return get_version();
    }

    if (gCoopCompatibility) {
#if defined(VERSION_US)
        snprintf(sLocalVersionString, MAX_LOCAL_VERSION_LENGTH, "%s%d.%d.%d", VERSION_TEXT, VERSION_NUMBER, MINOR_VERSION_NUMBER, PATCH_VERSION_NUMBER);
#else
        snprintf(sLocalVersionString, MAX_LOCAL_VERSION_LENGTH, "%s%d.%d.%d %s", VERSION_TEXT, VERSION_NUMBER, MINOR_VERSION_NUMBER, PATCH_VERSION_NUMBER, VERSION_REGION);
#endif
    } else {
#if defined(VERSION_US)
        snprintf(sLocalVersionString, MAX_LOCAL_VERSION_LENGTH, "%s", SM64COOPDX_VERSION);
#else
        snprintf(sLocalVersionString, MAX_LOCAL_VERSION_LENGTH, "%s %s", VERSION_TEXT, SM64COOPDX_VERSION, VERSION_REGION);
#endif
    }

    return sLocalVersionString;
}

const char* get_game_name(void) {
    if (gCoopCompatibility) {
#ifdef DEVELOPMENT
        return "sm64ex-coop-dev";
#elif !defined(VERSION_US)
        return "sm64ex-coop-intl";
#else
        return "sm64ex-coop";
#endif
    } else {
#ifdef DEVELOPMENT
        return "sm64coopdx-dev";
#elif !defined(VERSION_US)
        return "sm64coopdx-intl";
#else
        return "sm64coopdx";
#endif
    }
}
