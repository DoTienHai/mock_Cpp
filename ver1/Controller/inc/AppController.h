#ifndef APP_CONTROLLER_H
#define APP_CONTROLLER_H
#include <iostream>
#include "LocalMediaList.h"
#include "Playlist.h"
#include "AppView.h"
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
    AppView appView;               // view for main menu
    LocalMediaFilesView localMediaFilesView; // views for functions of local files
    PlaylistView playlistView;               // views for functions of playlists

public:
    AppController(/* args */);
    ~AppController();

    void run(); // app run
private:

    /*******************************************************************************/
    /* functions implement for main menu option*/
    void playWithLocalMediaFiles();
    void playWithYourPlayLists();

    /*******************************************************************************/
    /* functions implement for playWithLocalMediaFiles option */
    void listAllLocalMediaFiles();
    void modifyFile();

    /* functions implement for modifyFile option */
    void showMetadata(FileAbstract * file);
    void updateMetadata(FileAbstract * file);
    void addToPlaylist(FileAbstract * file);

    /*******************************************************************************/
    /* functions implement for playWithYourPlayLists option */
    void displayAllPlayList();
    void createPlaylist();
    void DeletePlaylist();
    void modifyPlaylist();

    /* functions implement for modifyPlaylist option */
    void showPlaylist(Playlist* playlist);
    void addFile(Playlist* playlist);
    void deleteFile(Playlist* playlist);
};

#endif // ! APP_CONTROLLER_H