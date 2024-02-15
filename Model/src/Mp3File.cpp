#include "Mp3File.h"

Mp3File::Mp3File(/* args */)
{
}
Mp3File::Mp3File(const string &path) : FileAbstract(path) {}
Mp3File::~Mp3File() {
    cout << "mp3 file deconstructor" << endl;
}

string Mp3File::getArtist()
{
    FileRef ref = getFileRef();
    Tag *tag = ref.tag();
    return tag->artist().toCString(true);
}