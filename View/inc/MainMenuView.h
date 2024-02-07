#ifndef MAIN_MENU_VIEW_H
#define MAIN_MENU_VIEW_H
#include <iostream>
using namespace std;

enum MAIN_MENU_OPTION {
    PLAY_WITH_LOCAL_MEDIA_FILES = 1,
    PLAY_WITH_YOUR_PLAYLISTS = 2,
    EXIT = 0,
};

class MainMenuView
{
private:
    /* data */
public:
    MainMenuView(/* args */);
    ~MainMenuView();

    void showMenu();
};






#endif /* MAIN_MENU_VIEW_H */
