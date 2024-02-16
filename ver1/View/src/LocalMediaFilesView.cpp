#include "LocalMediaFilesView.h"

LocalMediaFilesView::LocalMediaFilesView(/* args */) {}

LocalMediaFilesView::~LocalMediaFilesView() {}

void LocalMediaFilesView::showMenu()
{
    cout << "\n----------------------------------------------------------------" << endl;
    cout << "PLAY WITH LOCAL MEDIA FILES MENU: " << endl;
    cout << LIST_ALL_LOCAL_MEDIA_FILES << ". List all local media files." << endl;
    cout << MODIFY_FILE << ". Modify file." << endl;
    cout << LOCAL_MEDIA_FILES_BACK << ". Back." << endl;
    cout << "----------------------------------------------------------------" << endl;
}

void LocalMediaFilesView::showModifyFileMenu()
{
    cout << "\n----------------------------------------------------------------" << endl;
    cout << "MODIFY FILE OPTION: " << endl;
    cout << SHOW_METADATA << ". Show metadata." << endl;
    cout << UPDATE_METADATA << ". Update metadata." << endl;
    cout << ADD_TO_PLAYLIST << ". Add to playlist." << endl;
    cout << MODIFY_FILE_BACK << ". Back." << endl;
    cout << "----------------------------------------------------------------" << endl;

}

void LocalMediaFilesView::displayAllFiles(LocalMediaList &list)
{
    if (list.getList().size())
    {
        cout << "All media files:" << endl;
        int count = 1;
        for (FileAbstract *it : list.getList())
        {
            cout << count << ". " << it->getPath() << endl;
            count++;
        }
    }
    else
    {
        cout << "There is no media file in this path." << endl;
    }
}