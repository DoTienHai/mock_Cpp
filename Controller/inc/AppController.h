#ifndef APP_CONTROLLER_H
#define APP_CONTROLLER_H
#include <iostream>
#include "LocalMediaList.h"
#include "Playlist.h"
#include "MainMenuView.h"
#include "LocalMediaFilesView.h"
#include "PlaylistView.h"
using namespace std;

class AppController
{
private:
    /* Models */
    LocalMediaList localFileList;      // store file in local
    vector<Playlist *> playlistVector; // store user playlists

    /* Views */
    MainMenuView mainMenuView;               // view for main menu
    LocalMediaFilesView localMediaFilesView; // views for functions of local files
    PlaylistView playlistView;               // views for functions of playlists

public:
    AppController(/* args */);
    ~AppController();

    void run(); // app run
private:
    /* get input option when has a menu */
    int optionInput();
    /*******************************************************************************/
    /* functions implement for main menu option*/
    void playWithLocalMediaFiles();
    void playWithYourPlayLists();

    /*******************************************************************************/
    /* functions implement for playWithLocalMediaFiles option */
    void listAllLocalMediaFiles();
    void modifyFile();

    /* functions implement for modifyFile option */
    void showMetadata();
    void updateMetadata();
    void addToPlaylist();

    /*******************************************************************************/
    /* functions implement for playWithYourPlayLists option */
    void createPlaylist();
    void DeletePlaylist();
    void modifyPlaylist();

    /* functions implement for modifyPlaylist option */
    void showPlaylist();
    void addFile();
    void deleteFile();
};

#endif // ! APP_CONTROLLER_H