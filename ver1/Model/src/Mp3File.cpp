#include "Mp3File.h"

Mp3File::Mp3File(/* args */)
{
}
Mp3File::Mp3File(const string &path) : FileAbstract(path) {}
Mp3File::~Mp3File()
{
    cout << "mp3 file deconstructor" << endl;
}
unsigned int Mp3File::getChannels()
{
    return getAudioProperties()->channels();
}
