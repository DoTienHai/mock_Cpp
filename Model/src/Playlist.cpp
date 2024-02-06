#include "main.h"
#include "MediaFile.h"
#include "Playlist.h"

void Playlist::addFile(const MediaFile& file) {
    files.push_back(file);
}

// void Playlist::viewPlaylist() {
//     cout << "Playlist - " << name << endl;
//     for (auto& media_file : files) {
//         cout << media_file.getName() << " - " << media_file.getPath() << endl;
//     }
//     cout << endl;
// }

string Playlist::getName() {
    return name;
}

vector<MediaFile> Playlist::getFiles() {
    return files;
}