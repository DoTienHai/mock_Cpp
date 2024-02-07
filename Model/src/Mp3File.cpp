#include "Mp3File.h"

Mp3File::Mp3File(/* args */)
{
}
Mp3File::Mp3File(const string& album):album(album){}
Mp3File::~Mp3File()
{
}

    void Mp3File::setAlbum(const string& album){
        this->album = album;
    }
    string Mp3File::getAlbum(){
        return album;
    }