#ifndef LOCAL_MEDIA_FILE_H
#define LOCAL_MEDIA_FILE_H
#include <iostream>
#include <vector>
#include <unistd.h>
#include <filesystem>
#include <cstring>
#include "FileAbstract.h"
#include "Mp3File.h"
#include "Mp4File.h"
using namespace std;

class LocalMediaList
{
private:
    /* data */
    string path;
    vector<FileAbstract *> localFileList;
public:
    LocalMediaList(/* args */);
    ~LocalMediaList();

    vector<FileAbstract *> getList();
};

#endif // ! LOCAL_MEDIA_FILE_H