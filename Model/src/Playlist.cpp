#include "Playlist.h"

void Playlist::addFile(const FileAbstract& file) {
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

vector<FileAbstract> Playlist::getFiles() {
    return files;
}