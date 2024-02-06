#ifndef FA110AE1_2A82_4F4F_B944_5BC914282698
#define FA110AE1_2A82_4F4F_B944_5BC914282698

#include "main.h"
#include "Playlist.h"
#include "MediaBrowser.h"

class MediaBrowser;

class MediaInterface {
private:

public:
    MediaInterface() = default;
    ~MediaInterface() = default;

    int mainMenuInterface();
    int updatePlaylistInterface();
    void viewPlaylist(Playlist* playlist);
    void displayMediaFiles(MediaBrowser* browser, int page, int pageSize);
    void displayPlaylists(MediaBrowser* browser);
};

#endif /* FA110AE1_2A82_4F4F_B944_5BC914282698 */
