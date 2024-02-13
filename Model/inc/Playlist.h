#ifndef PLAYLIST_H
#define PLAYLIST_H
#include <iostream>
#include <vector>
#include "FileAbstract.h"
using namespace std;

class Playlist
{
private:
    string name;
    vector<FileAbstract *> playlist;

public:
    Playlist();
    Playlist(const string &n);
    ~Playlist();

    void addFile(FileAbstract *file);
    void deleteFile(FileAbstract *file);

    string getName();

    vector<FileAbstract *> getPlaylist();
};

#endif // ! PLAYLIST_H