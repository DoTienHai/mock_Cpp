#include "PlaylistView.h"

PlaylistView::PlaylistView(/* args */)
{
}

PlaylistView::~PlaylistView()
{
}

void PlaylistView::showMenu()
{
    cout << "----------------------------------------------------------------" <<endl;
    cout << "PLAY WITH YOUR PLAYLISTS OPTIONS:" << endl;
    cout << CREATE_PLAYLIST << ". Create playlist." << endl;
    cout << DELETE_PLAYLIST << ". Delete playlist." << endl;
    cout << MODIFY_PLAYLIST << ". Modify playlist." << endl;
    cout << PLAYLIST_BACK << ". Back to the menu." << endl;
}

void PlaylistView::showModifyMenu()
{
    cout << "----------------------------------------------------------------" <<endl;
    cout << "PLAY LIST MODIFY OPTION: " << endl;
    cout << SHOW_PLAYLIST << ". Show playlist." << endl;
    cout << ADD_FILE << ". Add file." << endl;
    cout << DELETE_FILE << ". Delete file." << endl;
    cout << MODIFY_PLAYLIST_BACK << ". Back to menu." << endl;
}