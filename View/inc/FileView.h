#ifndef FILE_VIEW_H
#define FILE_VIEW_H
#include <iostream>
#include "FileAbstract.h"
#include "Mp3File.h"
#include "Mp4File.h"
using namespace std;

class FileView
{
private:
    /* data */
public:
    FileView(/* args */);
    virtual ~FileView();

    void showFile(FileAbstract *file);
};

#endif // ! FILE_VIEW_H