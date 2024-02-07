#ifndef LOCAL_MEDIA_FILE_H
#define LOCAL_MEDIA_FILE_H
#include <iostream>
#include <vector>
#include "FileAbstract.h"
using namespace std;

class LocalMediaList
{
private:
    /* data */
    vector<FileAbstract*> localFileList;
public:
    LocalMediaList(/* args */);
    ~LocalMediaList();

    vector<FileAbstract*> getList();
};




#endif // ! LOCAL_MEDIA_FILE_H