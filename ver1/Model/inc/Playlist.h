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

    FileAbstract* getFileAt(int const & index);
    void addFile(FileAbstract *file);
    void deleteFile(FileAbstract *file);

    string getName();

    vector<FileAbstract *> getPlaylist();
    void clear();

};

#endif // ! PLAYLIST_H