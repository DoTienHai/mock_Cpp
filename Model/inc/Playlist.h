#ifndef PLAYLIST_H
#define PLAYLIST_H
#include <iostream>
#include <vector>
#include "FileAbstract.h"
using namespace std;


class Playlist {
private:
    string name;
    vector<FileAbstract> files;
public:
    Playlist(const string& n) : name(n) {}
    ~Playlist() = default;

    void addFile(const FileAbstract& file);

    // void viewPlaylist();

    string getName();

    vector<FileAbstract> getFiles();
};


#endif // ! PLAYLIST_H