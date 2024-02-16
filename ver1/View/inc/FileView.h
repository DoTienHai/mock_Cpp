#ifndef FILE_VIEW_H
#define FILE_VIEW_H
#include <iostream>
#include "FileAbstract.h"
#include "Mp3File.h"
#include "Mp4File.h"
using namespace std;

enum PROPERTY_UPDATE
{
    TITLE = 1,
    ALBUM = 2,
    ARTIST = 3,
    YEAR = 4,
    PROPERTY_UPDATE_BACK = 0,
};


class FileView
{
private:
    /* data */
public:
    FileView(/* args */);
    virtual ~FileView() = default;

    void showFile(FileAbstract *file);
    void updateMetadataFileMenu(FileAbstract *file);
};

#endif // ! FILE_VIEW_H