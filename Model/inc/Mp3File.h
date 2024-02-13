#ifndef MP3_FILE_H
#define MP3_FILE_H
#include <iostream>
#include "FileAbstract.h"
using namespace std;

class Mp3File : public FileAbstract
{
private:
    /* data */
public:
    Mp3File(/* args */);
    Mp3File(const string& path);
    ~Mp3File();

    string getArtist();
};

#endif // ! MP3_FILE_H