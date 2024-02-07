#include "FileAbstract.h"

FileAbstract::FileAbstract() {}

FileAbstract::FileAbstract(const string &n, const string &p) : name(n), path(p) {}

void FileAbstract::setName(const string &n)
{
    this->name = n;
}
void FileAbstract::setPath(const string &p)
{
    this->path = p;
}

string FileAbstract::getName()
{
    return name;
}

string FileAbstract::getPath()
{
    return path;
}