#include "main.h"
#include "MediaBrowser.h"
#include <filesystem>
#include <fstream>

using namespace std;
namespace fs = filesystem;

MediaBrowser::MediaBrowser() {
    loadMediaFiles(fs::current_path().string());
}

MediaBrowser::~MediaBrowser() {
    for(auto& playlist : playlists) {
        delete playlist;
    }
}

void MediaBrowser::mainProgram() {
    int currentPage = 1;
    const int pageSize = 10;

    while (true) {
        int choice = interface.mainMenuInterface();
        int update_cmd;

        switch (choice) {
            case DISPLAY_ALL_MEDIA_FILES:
                interface.displayMediaFiles(this, currentPage, pageSize);
                break;

            case CREATE_PLAYLIST:
                createPlaylist();
                break;

            case UPDATE_PLAYLIST:
                update_cmd = interface.updatePlaylistInterface();
                updatePlaylist(update_cmd);
                break;

            case VIEW_PLAYLIST:
                interface.displayPlaylists(this);
                break;

            case EXIT_APPLICATION:
                cout << "Exiting the application. Goodbye!" << endl;
                return;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}

void MediaBrowser::loadMediaFiles(const string& directory) {
    for (const auto& entry : fs::recursive_directory_iterator(directory)) {
        if (entry.is_regular_file()) {
            string fileExtension = entry.path().extension().string();
            transform(fileExtension.begin(), fileExtension.end(), fileExtension.begin(), ::tolower);

            if (fileExtension == ".mp3" || fileExtension == ".mp4") {
                MediaFile mediaFile(entry.path().filename().string(), entry.path().string());
                mediaFiles.push_back(mediaFile);
            }
        }
    }
}

void MediaBrowser::createPlaylist() {
    string new_name;
    cout << "Enter name of new playlist: ";
    getline(cin, new_name);
    playlists.push_back(new Playlist(new_name));
    cout << "New playlist - " << new_name << " - Created" << endl;
}

void MediaBrowser::updatePlaylist(int update_cmd) {
    string playlist_name;
    switch(update_cmd) {
    case ADD_TO_PLAYLIST_CMD:
        cout << "Enter playlist name that you want to add media file: ";
        getline(cin, playlist_name);
        for(auto& playlist : playlists) {
            if(playlist->getName() == playlist_name) {
                addToPlaylist(playlist);
                return;
            }
        }
        cout << "Playlist name not found!" << endl;
        break;
    case DELETE_FROM_PLAYLIST_CMD:
        cout << "Enter playlist name that you want to delete media file: ";
        getline(cin, playlist_name);
        for(auto& playlist : playlists) {
            if(playlist->getName() == playlist_name) {
                deleteFromPlaylist(playlist);
                return;
            }
        }
        cout << "Playlist name not found!" << endl;
        break;
    case DELETE_PLAYLIST_CMD:
        cout << "Enter playlist name that you want to delete: ";
        getline(cin, playlist_name);
        for(auto& playlist : playlists) {
            if(playlist->getName() == playlist_name) {
                deletePlaylist(playlist_name);
                return;
            }
        }
        cout << "Playlist name not found!" << endl;
        break;
    }
}

void MediaBrowser::addToPlaylist(Playlist* playlist) {
    cout << "Enter name of media file that you want to add to this playlist: ";
    string file_name;
    getline(cin, file_name);
    for(auto& file : mediaFiles) {
        if(file.getName() == file_name) {
            playlist->addFile(file);
            interface.viewPlaylist(playlist);
            cout << "File added successfully!" << endl;
            return;
        }
    }
    cout << "File add failed. Media file name not found!" << endl;
}

void MediaBrowser::deleteFromPlaylist(Playlist* playlist) {
    cout << "Enter name of media file that you want to delete from this playlist: ";
    string file_name;
    getline(cin, file_name);
    vector<MediaFile> files = playlist->getFiles();
    auto it = find_if(files.begin(), files.end(), 
        [file_name](auto& file) {
            return file.getName() == file_name;
        });
    if(it != files.end()) {
        files.erase(it);
        cout << "Media file with name '" << file_name << "' has been deleted from playlist " << playlist->getName() << endl;
    }
    else {
        cout << "File deletion failed. Media file name not found!" << endl;
    }
}

void MediaBrowser::deletePlaylist(string playlist_name) {
    auto it = find_if(playlists.begin(), playlists.end(), 
        [playlist_name](auto& playlist) {
            return playlist->getName() == playlist_name;
        });
    if(it != playlists.end()) {
        delete *it;
        playlists.erase(it);
        cout << "Playlist " << playlist_name << " has been deleted." << endl;
    }
}

vector<MediaFile> MediaBrowser::getMediaFiles() {
    return mediaFiles;
}

vector<Playlist*> MediaBrowser::getPlaylists() {
    return playlists;
}