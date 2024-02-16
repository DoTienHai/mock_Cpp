#include "FileAbstract.h"

FileAbstract::FileAbstract() {}

FileAbstract::FileAbstract(const string &p) : path(p) {}

void FileAbstract::setPath(const string &p)
{
    this->path = p;
}

string FileAbstract::getPath()
{
    return path;
}
string FileAbstract::getName()
{
    std::filesystem::path pathObj(path);
    return pathObj.filename().string();
}

FileRef FileAbstract::getFileRef()
{
    return FileRef((path).c_str());
}
Tag *FileAbstract::getTag()
{
    return getFileRef().tag();
}
AudioProperties *FileAbstract::getAudioProperties()
{
    return getFileRef().audioProperties();
}

string FileAbstract::getTitle()
{
    string ret = getTag()->title().toCString(true);
    return ret == "" ? "Unknown" : ret;
}

void FileAbstract::setTitle(const string &title) {}
string FileAbstract::getArtist()
{
    string ret = getTag()->artist().toCString(true);
    return ret == "" ? "Unknown" : ret;
}
void FileAbstract::setArtist(const string &artist) {}
string FileAbstract::getAlbum()
{
    string ret = getTag()->album().toCString(true);
    return ret == "" ? "Unknown" : ret;
}
void FileAbstract::setAlbum(const string &album) {}
string FileAbstract::getYear()
{
    string ret = to_string(getTag()->year());
    return ret == "" ? "Unknown" : ret;
}
void FileAbstract::setYear(const string &year) {}
unsigned int FileAbstract::getDuration()
{
    TagLib::AudioProperties *audioProperties = getFileRef().audioProperties();
    return audioProperties->lengthInSeconds();
}
unsigned int FileAbstract::getSize()
{
    return filesystem::file_size(path);
}
unsigned int FileAbstract::getBitRate()
{
    return getAudioProperties()->lengthInSeconds();
}
unsigned int FileAbstract::getSampleRate()
{
    return getAudioProperties()->sampleRate();
}
