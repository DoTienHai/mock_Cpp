#ifndef FILE_ABSTRACT_H
#define FILE_ABSTRACT_H
#include <iostream>
using namespace std;

class FileAbstract
{
private:
    string name;
    string path;

public:
    FileAbstract();
    FileAbstract(const string &n, const string &p);
    virtual ~FileAbstract() = default;

    void setName(const string &n);
    void setPath(const string &p);
    string getName();
    string getPath();
};

#endif // ! FILE_ABSTRACT_H