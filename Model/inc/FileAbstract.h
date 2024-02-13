#ifndef FILE_ABSTRACT_H
#define FILE_ABSTRACT_H
#include <iostream>
#include <taglib/taglib.h>
#include <taglib/fileref.h>
using namespace std;
using namespace TagLib;
class FileAbstract : public FileRef
{
private:
    string path;
    FileRef ref;

public:
    FileAbstract();
    FileAbstract(const string &p);
    virtual ~FileAbstract() = default;

    void setPath(const string &p);
    string getPath();

    FileRef getFileRef();
    Tag *getTag();
};

#endif // ! FILE_ABSTRACT_H