#include "PlaylistView.h"

PlaylistView::PlaylistView(/* args */)
{
}

PlaylistView::~PlaylistView()
{
}

void PlaylistView::showMenu()
{
    cout << "\n----------------------------------------------------------------" << endl;
    cout << "PLAY WITH YOUR PLAYLISTS OPTIONS:" << endl;
    cout << DISPLAY_ALL_PLAYLIST << ". Display all playlist." << endl;
    cout << CREATE_PLAYLIST << ". Create playlist." << endl;
    cout << DELETE_PLAYLIST << ". Delete playlist." << endl;
    cout << MODIFY_PLAYLIST << ". Modify playlist." << endl;
    cout << PLAYLIST_BACK << ". Back to the menu." << endl;
    cout << "----------------------------------------------------------------" << endl;
}

void PlaylistView::showModifyMenu()
{
    cout << "\n----------------------------------------------------------------" << endl;
    cout << "PLAY LIST MODIFY OPTION: " << endl;
    cout << SHOW_PLAYLIST << ". Show playlist." << endl;
    cout << ADD_FILE << ". Add file." << endl;
    cout << DELETE_FILE << ". Delete file." << endl;
    cout << MODIFY_PLAYLIST_BACK << ". Back to menu." << endl;
    cout << "----------------------------------------------------------------" << endl;
}

void PlaylistView::showAllPlaylist(vector<Playlist *> playlistVector)
{
    if (playlistVector.size())
    {
        int count = 1;
        cout << "YOUR PLAYLISTs: " << endl;
        for (Playlist *it : playlistVector)
        {
            cout << count << ". " << it->getName() << endl;
            count++;
        }
    }
    else
    {
        cout << "There is no playlist." << endl;
    }
}

void PlaylistView::showPlaylist(Playlist *playlist)
{
    if (playlist->getPlaylist().size())
    {
        cout << "All media files in playlist " << playlist->getName() << endl;
        int count = 1;
        for (FileAbstract *it : playlist->getPlaylist())
        {
            cout << count << ". " << it->getPath() << endl;
            count++;
        }
    }
    else
    {
        cout << "There is no media file in playlist " << playlist->getName() << endl;
    }
}