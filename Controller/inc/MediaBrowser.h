#ifndef A9DD36C6_47EA_428A_86E9_2F094BE62ACE
#define A9DD36C6_47EA_428A_86E9_2F094BE62ACE

#include "main.h"
#include "MediaFile.h"
#include "MediaInterface.h"
#include "Playlist.h"
using namespace std;

class MediaBrowser {
private:
    vector<MediaFile> mediaFiles;
    vector<Playlist*> playlists;
    MediaInterface interface;
public:
    MediaBrowser();
    ~MediaBrowser();

    void mainProgram();

    void loadMediaFiles(const string& directory);

    void createPlaylist();

    void updatePlaylist(int update_cmd);

    void addToPlaylist(Playlist* playlist);

    void deleteFromPlaylist(Playlist* playlist);

    void deletePlaylist(string playlist_name);

    vector<MediaFile> getMediaFiles();

    vector<Playlist*> getPlaylists();
};

#endif /* A9DD36C6_47EA_428A_86E9_2F094BE62ACE */
