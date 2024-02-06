#include "main.h"
#include "MediaInterface.h"
#include "Playlist.h"
#include "MediaBrowser.h"

int MediaInterface::mainMenuInterface() {
    cout << "1. View list of media files" << endl;
    cout << "2. Create new playlist" << endl;
    cout << "3. Update playlist" << endl;
    cout << "4. View playlists" << endl;
    cout << "5. Quit" << endl;

    int choice;
    cout << "Enter your command: ";
    cin >> choice;
    cin.ignore();
    return choice;
}

int MediaInterface::updatePlaylistInterface() {
    int update_cmd;
    cout << "1. Add file to playlist" << endl;
    cout << "2. Delete file from playlist" << endl;
    cout << "3. Delete playlist" << endl;
    cin >> update_cmd;
    cin.ignore();
    return update_cmd;
}

void MediaInterface::viewPlaylist(Playlist* playlist) {
    cout << "Playlist - " << playlist->getName() << endl;
    for (auto& media_file : playlist->getFiles()) {
        cout << media_file.getName() << " - " << media_file.getPath() << endl;
    }
    cout << endl;
}

void MediaInterface::displayMediaFiles(MediaBrowser* browser, int page, int pageSize) {
    int startIdx = (page - 1) * pageSize;
    int endIdx = min(startIdx + pageSize, static_cast<int>(browser->getMediaFiles().size()));

    for (int i = startIdx; i < endIdx; ++i) {
        cout << browser->getMediaFiles()[i].getName() << " - " << browser->getMediaFiles()[i].getPath() << endl;
    }

    if(endIdx < (int)browser->getMediaFiles().size()) {
        string cont;
        cout << "Show more? (Y/N): ";
        getline(cin, cont);
        if(cont == "Y" || cont == "y") {
            displayMediaFiles(browser, page + 1, pageSize);
        }
    }
}

void MediaInterface::displayPlaylists(MediaBrowser* browser) {
    for (auto& playlist : browser->getPlaylists()) {
        viewPlaylist(playlist);
    }
}