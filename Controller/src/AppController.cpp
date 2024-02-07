#include "AppController.h"

AppController::AppController(/* args */)
{
}

AppController::~AppController()
{
}

void AppController::run()
{
    int option;
    do
    {
        mainMenuView.showMenu();
        option = optionInput();
        switch (option)
        {
        case PLAY_WITH_LOCAL_MEDIA_FILES:

        {
            playWithLocalMediaFiles();
            break;
        }
        case PLAY_WITH_YOUR_PLAYLISTS:
        {
            playWithYourPlayLists();
            break;
        }
        case EXIT:
        {
            cout << "Exit the program!" << endl;
            break;
        }
        default:
        {
            cout << "Invalid option. Please enter a valid option!" << endl;
            break;
        }
        }
    } while (option != EXIT);
}

int AppController::optionInput()
{
    int option;
    cin >> option;
    cin.ignore();
    return option;
}

void AppController::playWithLocalMediaFiles()
{

    int option;
    do
    {
        localMediaFilesView.showMenu();
        option = optionInput();
        switch (option)
        {
        case LIST_ALL_LOCAL_MEDIA_FILES:
        {
            listAllLocalMediaFiles();
            break;
        }
        case MODIFY_FILE:
        {
            modifyFile();
            break;
        }
        case LOCAL_MEDIA_FILES_BACK:
        {
            cout << "Exit to the Menu." << endl;
            break;
        }
        default:
        {
            cout << "Invalid option. Please enter a valid option!" << endl;
            break;
        }
        }
    } while (option != LOCAL_MEDIA_FILES_BACK);
}

void AppController::listAllLocalMediaFiles()
{
    localMediaFilesView.displayAllFiles(localFileList);
}
void AppController::modifyFile()
{
    int option;
    do
    {
        localMediaFilesView.showModifyFileMenu();
        option = optionInput();
        switch (option)
        {
        case SHOW_METADATA:
        {
            showMetadata();
            break;
        }
        case UPDATE_METADATA:
        {
            updateMetadata();
            break;
        }
        case ADD_TO_PLAYLIST:
        {
            addToPlaylist();
            break;
        }
        case MODIFY_FILE_BACK:
        {
            cout << "Exit to the Menu." << endl;
            break;
        }
        default:
        {
            cout << "Invalid option. Please enter a valid option!" << endl;
            break;
        }
        }
    } while (option != LOCAL_MEDIA_FILES_BACK);
}

void AppController::showMetadata()
{
    cout << "show meta data" << endl;
}
void AppController::updateMetadata()
{
    cout << "update meta data" << endl;
}
void AppController::addToPlaylist()
{
    cout << "add to playlist." << endl;
}

void AppController::playWithYourPlayLists()
{
    int option;
    do
    {
        playlistView.showMenu();
        option = optionInput();
        switch (option)
        {
        case CREATE_PLAYLIST:
        {
            createPlaylist();
            break;
        }
        case DELETE_PLAYLIST:
        {
            DeletePlaylist();
            break;
        }
        case MODIFY_PLAYLIST:
        {
            modifyPlaylist();
            break;
        }
        case PLAYLIST_BACK:
        {
            cout << "Exit to the Menu." << endl;
            break;
        }
        default:
        {
            cout << "Invalid option. Please enter a valid option!" << endl;
            break;
        }
        }
    } while (option != PLAYLIST_BACK);
}

void AppController::createPlaylist()
{
    cout << "create a playlist." << endl;
}
void AppController::DeletePlaylist()
{
    cout << "delete a playlist." << endl;
}
void AppController::modifyPlaylist()
{

    int option;
    do
    {
        playlistView.showModifyMenu();
        option = optionInput();
        switch (option)
        {
        case SHOW_PLAYLIST:
        {
            showPlaylist();
            break;
        }
        case ADD_FILE:
        {
            addFile();
            break;
        }
        case DELETE_FILE:
        {
            deleteFile();
            break;
        }
        case MODIFY_PLAYLIST_BACK:
        {
            cout << "Exit to the Menu." << endl;
            break;
        }
        default:
        {
            cout << "Invalid option. Please enter a valid option!" << endl;
            break;
        }
        }
    } while (option != MODIFY_PLAYLIST_BACK);
}

void AppController::showPlaylist()
{
    cout << "show playlist" << endl;
}
void AppController::addFile()
{
    cout << " add file to playlist" << endl;
}
void AppController::deleteFile()
{
    cout << "delete a file from playlist." << endl;
}