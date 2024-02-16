#include "AppView.h"

AppView::AppView(/* args */) {}

AppView::~AppView() {}

void AppView::showMenu()
{
    cout << "\n----------------------------------------------------------------" << endl;
    cout << "MAIN MENU:" << endl;
    cout << PLAY_WITH_LOCAL_MEDIA_FILES << ". Play with local media files." << endl;
    cout << PLAY_WITH_YOUR_PLAYLISTS << ". Play with your playlists." << endl;
    cout << EXIT << ". Exit." << endl;
    cout << "----------------------------------------------------------------" << endl;
}
void AppView::backMessage()
{
    cout << "Exit." << endl;
}
void AppView::invalidInputMessage()
{
    cout << "Invalid option!" << endl;
}
int AppView::intInput()
{
    int input;
    cin >> input;
    cin.ignore();
    return input;
}
string AppView::stringInput()
{
    string input;
    getline(cin, input);
    return input;
}