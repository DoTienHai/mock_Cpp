#include "FileAbstract.h"

FileAbstract::FileAbstract() {}

FileAbstract::FileAbstract(const string &p) : path(p)
{
    ref = FileRef((path).c_str());
}

void FileAbstract::setPath(const string &p)
{
    this->path = p;
}

string FileAbstract::getPath()
{
    return path;
}

FileRef FileAbstract::getFileRef()
{
    return ref;
}
Tag *FileAbstract::getTag()
{
    return ref.tag();
}