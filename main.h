#ifndef D7C31025_8304_468E_9946_7B906190DACD
#define D7C31025_8304_468E_9946_7B906190DACD

#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>
#include <algorithm>

#include "MediaBrowser.h"
#include "MediaFile.h"
#include "Playlist.h"
#include "MediaInterface.h"

enum {
    ADD_TO_PLAYLIST_CMD             = 1,
    DELETE_FROM_PLAYLIST_CMD        = 2,
    DELETE_PLAYLIST_CMD             = 3
};

enum {
    DISPLAY_ALL_MEDIA_FILES         = 1,
    CREATE_PLAYLIST                 = 2,
    UPDATE_PLAYLIST                 = 3,
    VIEW_PLAYLIST                   = 4,
    EXIT_APPLICATION                = 5
};

#endif /* D7C31025_8304_468E_9946_7B906190DACD */
