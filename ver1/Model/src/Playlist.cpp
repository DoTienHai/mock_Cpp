#include "Playlist.h"

Playlist::Playlist() {}
Playlist::Playlist(const string &n) : name(n) {}
Playlist::~Playlist()
{
    cout << playlist.size() << endl;
    cout << "deconstructor playlist" << endl;
}
FileAbstract *Playlist::getFileAt(int const &index)
{
    return playlist.at(index);
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

void Playlist::clear()
{
    playlist.clear();
}