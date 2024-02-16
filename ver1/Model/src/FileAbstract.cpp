#include "FileAbstract.h"

FileAbstract::FileAbstract() {}

FileAbstract::FileAbstract(const string &p) : path(p), ref(path.c_str())
{
}

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
    return ref;
}
Tag *FileAbstract::getTag()
{
    return ref.tag();
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

void FileAbstract::setTitle(const string &title)
{
    getTag()->setTitle(title);
    ref.save();
}
string FileAbstract::getArtist()
{
    string ret = getTag()->artist().toCString(true);
    return ret == "" ? "Unknown" : ret;
}
void FileAbstract::setArtist(const string &artist)
{
    getTag()->setArtist(artist);
    ref.save();
}
string FileAbstract::getAlbum()
{
    string ret = getTag()->album().toCString(true);
    return ret == "" ? "Unknown" : ret;
}
void FileAbstract::setAlbum(const string &album)
{
    getTag()->setAlbum(album);
    ref.save();
}
string FileAbstract::getYear()
{
    int ret = getTag()->year();
    return ret == 0 ? "Unknown" : to_string(ret);
}
void FileAbstract::setYear(const string &year)
{
    getTag()->setYear(stoi(year));
    ref.save();
}
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
