#ifndef PLAYLIST_VIEW_H
#define PLAYLIST_VIEW_H
#include <iostream>
#include "FileView.h"
#include "Playlist.h"
using namespace std;

enum PLAY_WITH_YOUR_PLAYLISTS_OPTION
{
    DISPLAY_ALL_PLAYLIST = 1,
    CREATE_PLAYLIST = 2,
    DELETE_PLAYLIST = 3,
    MODIFY_PLAYLIST = 4,
    PLAYLIST_BACK = 0,

};

enum MODIFY_PLAYLIST_OPTION
{
    SHOW_PLAYLIST = 1,
    ADD_FILE = 2,
    DELETE_FILE = 3,
    MODIFY_PLAYLIST_BACK = 0,
};

class PlaylistView : public FileView
{
private:
    /* data */
public:
    PlaylistView(/* args */);
    ~PlaylistView();

    void showMenu();
    void showModifyMenu();

    void showAllPlaylist(vector<Playlist*> playlistVector);
    void showPlaylist(Playlist* playlist);
};

#endif // ! PLAYLIST_VIEW_H