#ifndef FILE_ABSTRACT_H
#define FILE_ABSTRACT_H
#include <iostream>
#include <filesystem>
#include <taglib/taglib.h>
#include <taglib/fileref.h>
using namespace std;
using namespace TagLib;
class FileAbstract : public FileRef
{
private:
    string path;

protected:
    FileRef getFileRef();
    Tag *getTag();
    AudioProperties *getAudioProperties();

public:
    FileAbstract();
    FileAbstract(const string &p);
    virtual ~FileAbstract() = default;

    void setPath(const string &p);
    string getPath();
    string getName();

    string getTitle();
    void setTitle(const string &title);
    string getArtist();
    void setArtist(const string &artist);
    string getAlbum();
    void setAlbum(const string &album);
    string getYear();
    void setYear(const string &year);
    unsigned int getDuration();
    unsigned int getSize();
    unsigned int getBitRate();
    unsigned int getSampleRate();
};

#endif // ! FILE_ABSTRACT_H