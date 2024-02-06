#ifndef C44BD54D_8A21_4D96_99D1_7ACC89A697A2
#define C44BD54D_8A21_4D96_99D1_7ACC89A697A2

#include "main.h"
#include "MediaFile.h"

class Playlist {
private:
    string name;
    vector<MediaFile> files;
public:
    Playlist(const string& n) : name(n) {}
    ~Playlist() = default;

    void addFile(const MediaFile& file);

    // void viewPlaylist();

    string getName();

    vector<MediaFile> getFiles();
};

#endif /* C44BD54D_8A21_4D96_99D1_7ACC89A697A2 */
