#include "AppController.h"

AppController::AppController(/* args */) {}

AppController::~AppController()
{
    for (Playlist *it : this->playlistVector)
    {
        delete it;
    }
    playlistVector.clear();
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
    localMediaFilesView.displayAllFiles(localFileList);
    cout << "Select a number of file to modify: " << endl;
    int numberInput;
    cin >> numberInput;
    cin.ignore();
    FileAbstract *fileChosen = nullptr;
    if (numberInput > 0 && numberInput <= (int)(localFileList.getList().size() - 1))
    {
        fileChosen = localFileList.getList().at(numberInput - 1);
    }
    else
    {
        cout << "invalid input!" << endl;
        return;
    }

    int option;
    do
    {
        localMediaFilesView.showModifyFileMenu();
        option = optionInput();
        switch (option)
        {
        case SHOW_METADATA:
        {
            showMetadata(fileChosen);
            break;
        }
        case UPDATE_METADATA:
        {
            updateMetadata(fileChosen);
            break;
        }
        case ADD_TO_PLAYLIST:
        {
            addToPlaylist(fileChosen);

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
    } while (option != MODIFY_FILE_BACK);
}

void AppController::showMetadata(FileAbstract *file)
{
    this->localMediaFilesView.showFile(file);
}
void AppController::updateMetadata(FileAbstract *file)
{
    cout << "update meta data" << endl;
}
void AppController::addToPlaylist(FileAbstract *file)
{
    cout << "add to playlist." << endl;
    if (playlistVector.size() == 0)
    {
        cout << "You don't have a playlist. Need to create one." << endl;
        createPlaylist();
        playlistVector.at(0)->addFile(file);
    }
    else
    {
        cout << "Do you want to add this file to a new playlist?(Y/N)";
        string createOption;
        cin >> createOption;
        if (createOption == "Y" || createOption == "y")
        {
            createPlaylist();
            (*(playlistVector.end() - 1))->addFile(file);
        }
        else
        {

            this->playlistView.showAllPlaylist(this->playlistVector);
            cout << "Enter a number before the Playlist you want to modify:" << endl;
            int numberInput;
            cin >> numberInput;
            if (numberInput > 0 && numberInput <= (int)playlistVector.size())
            {
                playlistVector.at(numberInput - 1)->addFile(file);
            }
            else
            {
                cout << "invalid input!" << endl;
                return;
            }
        }
    }
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
        case DISPLAY_ALL_PLAYLIST:
        {
            displayAllPlayList();
            break;
        }
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

void AppController::displayAllPlayList()
{
    this->playlistView.showAllPlaylist(this->playlistVector);
}

void AppController::createPlaylist()
{
    cout << "Enter name of your playlist: " << endl;
    string name;
    cin >> name;
    this->playlistVector.push_back(new Playlist(name));
    this->playlistView.showAllPlaylist(this->playlistVector);
}
void AppController::DeletePlaylist()
{
    if (this->playlistVector.size())
    {

        this->playlistView.showAllPlaylist(this->playlistVector);
        cout << "Enter a number before the Playlist you want to delete:" << endl;
        int numberInput;
        cin >> numberInput;
        if (numberInput > 0 && numberInput <= (int)playlistVector.size())
        {
            vector<Playlist *>::iterator temp = playlistVector.begin() + numberInput - 1;
            (*temp)->clear();
            delete (*temp);
            playlistVector.erase(temp);
        }
        else
        {
            cout << "invalid input!" << endl;
            return;
        }
    }
    else
    {
        cout << "There is no playlist to delete." << endl;
    }
}
void AppController::modifyPlaylist()
{
    this->playlistView.showAllPlaylist(this->playlistVector);
    cout << "Enter a number before the Playlist you want to modify:" << endl;
    int numberInput;
    cin >> numberInput;
    Playlist *playlistModify = nullptr;
    if (numberInput > 0 && numberInput <= (int)playlistVector.size())
    {
        playlistModify = playlistVector.at(numberInput - 1);
    }
    else
    {
        cout << "invalid input!" << endl;
        return;
    }

    int option;
    do
    {
        playlistView.showModifyMenu();
        option = optionInput();
        switch (option)
        {
        case SHOW_PLAYLIST:
        {
            showPlaylist(playlistModify);
            break;
        }
        case ADD_FILE:
        {
            addFile(playlistModify);
            break;
        }
        case DELETE_FILE:
        {
            deleteFile(playlistModify);
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

void AppController::showPlaylist(Playlist *playlist)
{
    this->playlistView.showPlaylist(playlist);
}
void AppController::addFile(Playlist *playlist)
{
    if (localFileList.getList().size() != 0)
    {
        localMediaFilesView.displayAllFiles(localFileList);
        cout << "Select a number of file to add to playlist " << playlist->getName() << endl;
        int numberInput;
        cin >> numberInput;
        cin.ignore();
        if (numberInput > 0 && numberInput <= (int)(localFileList.getList().size() - 1))
        {
            playlist->addFile(localFileList.getList().at(numberInput - 1));
        }
        else
        {
            cout << "invalid input!" << endl;
            return;
        }
    }
    else
    {
        cout << "there is no file in local to add!" << endl;
    }
}
void AppController::deleteFile(Playlist *playlist)
{
    this->playlistView.showPlaylist(playlist);
    cout << "Enter a number before the file you want to delete:" << endl;
    int numberInput;
    cin >> numberInput;
    if (numberInput > 0 && numberInput <= (int)playlist->getPlaylist().size())
    {
        FileAbstract *file = playlist->getPlaylist().at(numberInput - 1);
        playlist->deleteFile(file);
    }
    else
    {
        cout << "invalid input!" << endl;
        return;
    }
}