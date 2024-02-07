#include "MainMenuView.h"

MainMenuView::MainMenuView(/* args */) {}

MainMenuView::~MainMenuView() {}

void MainMenuView::showMenu()
{
    cout << "----------------------------------------------------------------" <<endl;
    cout << "MAIN MENU:" << endl;
    cout << PLAY_WITH_LOCAL_MEDIA_FILES << ". Play with local media files." << endl;
    cout << PLAY_WITH_YOUR_PLAYLISTS << ". Play with your playlists." << endl;
    cout << EXIT << ". Exit." << endl;
}