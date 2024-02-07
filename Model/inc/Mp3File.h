#ifndef MP3_FILE_H
#define MP3_FILE_H
#include <iostream>
#include "FileAbstract.h"
using namespace std;

class Mp3File : public FileAbstract
{
private:
    /* data */
    string album;
public:
    Mp3File(/* args */);
    Mp3File(const string& album);
    ~Mp3File();

    void setAlbum(const string& album);
    string getAlbum();
};

#endif // ! MP3_FILE_H