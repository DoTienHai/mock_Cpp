#include "LocalMediaList.h"

LocalMediaList::LocalMediaList(/* args */)
{
}

LocalMediaList::~LocalMediaList()
{
    for (FileAbstract *it : localFileList)
    {
        delete (it);
    }
    localFileList.clear();
}

vector<FileAbstract*> LocalMediaList::getList(){
    return localFileList;
}