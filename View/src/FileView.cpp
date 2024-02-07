#include "FileView.h"

FileView::FileView(/* args */)
{
}

FileView::~FileView()
{
}

void FileView::showFile(FileAbstract *file)
{
    Mp3File *mp3File = dynamic_cast<Mp3File *>(file);
    Mp4File *mp4File = dynamic_cast<Mp4File *>(file);

    if (mp3File)
    {
        cout << "This a mp3 File." << endl;
    }
    if (mp4File)
    {

        cout << "This a mp4 File." << endl;
    }
}