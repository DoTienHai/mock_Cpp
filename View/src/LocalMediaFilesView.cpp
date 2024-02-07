#include "LocalMediaFilesView.h"

LocalMediaFilesView::LocalMediaFilesView(/* args */) {}

LocalMediaFilesView::~LocalMediaFilesView() {}



void LocalMediaFilesView::showMenu()
{
    cout << "----------------------------------------------------------------" <<endl;
    cout << "PLAY WITH LOCAL MEDIA FILES MENU: " << endl;
    cout << LIST_ALL_LOCAL_MEDIA_FILES << ". List all local media files." << endl;
    cout << MODIFY_FILE << ". Modify file." << endl;
    cout << LOCAL_MEDIA_FILES_BACK << ". Back." << endl;
}

void LocalMediaFilesView::showModifyFileMenu(){
    cout << "----------------------------------------------------------------" <<endl;
    cout << "MODIFY FILE OPTION: " << endl;
    cout << SHOW_METADATA << ". Show metadata." << endl;
    cout << UPDATE_METADATA << ". Update metadata." << endl;
    cout << ADD_TO_PLAYLIST << ". Add to playlist." << endl;
    cout << MODIFY_FILE_BACK << ". Back." << endl;
}

void LocalMediaFilesView::displayAllFiles(LocalMediaList &list)
{
    cout << "All media files:" << endl;

}