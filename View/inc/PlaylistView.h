#ifndef PLAYLIST_VIEW_H
#define PLAYLIST_VIEW_H
#include <iostream>
#include "Playlist.h"
using namespace std;

enum PLAY_WITH_YOUR_PLAYLISTS_OPTION
{
    CREATE_PLAYLIST = 1,
    DELETE_PLAYLIST = 2,
    MODIFY_PLAYLIST = 3,
    PLAYLIST_BACK = 0,

};

enum MODIFY_PLAYLIST_OPTION
{
    SHOW_PLAYLIST = 1,
    ADD_FILE = 2,
    DELETE_FILE = 3,
    MODIFY_PLAYLIST_BACK = 0,
};

class PlaylistView
{
private:
    /* data */
public:
    PlaylistView(/* args */);
    ~PlaylistView();

    void showMenu();
    void showModifyMenu();
};

#endif // ! PLAYLIST_VIEW_H