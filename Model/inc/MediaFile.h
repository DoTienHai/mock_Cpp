#ifndef FA207558_4C00_4F98_A43A_F413D7F41F8D
#define FA207558_4C00_4F98_A43A_F413D7F41F8D

#include "main.h"
using namespace std;

class MediaFile {
private:
    string name;
    string path;
public:
    MediaFile(const string& n, const string& p) : name(n), path(p) {}
    ~MediaFile() = default;

    string getName();
    string getPath();
};

#endif /* FA207558_4C00_4F98_A43A_F413D7F41F8D */
