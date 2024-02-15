#include "Mp4File.h"

Mp4File::Mp4File(/* args */)
{
}
Mp4File::Mp4File(const string &path) : FileAbstract(path){};
Mp4File::~Mp4File(){
    cout << "mp4 file deconstructor" << endl;
}
