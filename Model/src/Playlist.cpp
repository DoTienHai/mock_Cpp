#include "Playlist.h"

Playlist::Playlist() {}
Playlist::Playlist(const string &n) : name(n) {}
Playlist::~Playlist()
{
    for (FileAbstract *it : this->playlist)
    {
        delete it;
    }
    this->playlist.clear();
}

void Playlist::addFile(FileAbstract *file)
{
    playlist.push_back(file);
}
void Playlist::deleteFile(FileAbstract *file)
{
    for (vector<FileAbstract *>::iterator it = playlist.begin(); it != playlist.end(); it++)
    {
        if ((*it) == file)
        {
            playlist.erase(it);
            return;
        }
    }
}
string Playlist::getName()
{
    return name;
}

vector<FileAbstract *> Playlist::getPlaylist()
{
    return playlist;
}