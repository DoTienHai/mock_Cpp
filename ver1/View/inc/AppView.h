#ifndef MAIN_MENU_VIEW_H
#define MAIN_MENU_VIEW_H
#include <iostream>
using namespace std;

enum MAIN_MENU_OPTION
{
    PLAY_WITH_LOCAL_MEDIA_FILES = 1,
    PLAY_WITH_YOUR_PLAYLISTS = 2,
    EXIT = 0,
};

class AppView
{
private:
    /* data */
public:
    AppView(/* args */);
    ~AppView();

    void showMenu();
    void backMessage();
    void invalidInputMessage();

    /* get input option when has a menu */
    int intInput(const string & msg);
    string stringInput(const string & msg);
};

#endif /* MAIN_MENU_VIEW_H */
