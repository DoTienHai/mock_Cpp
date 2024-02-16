#include "FileView.h"

FileView::FileView(/* args */) {}

void FileView::showFile(FileAbstract *file)
{
    Mp3File *mp3File = dynamic_cast<Mp3File *>(file);
    Mp4File *mp4File = dynamic_cast<Mp4File *>(file);
    cout << file->getName() << ":" << endl;
    cout << "\t"
         << "Title: " << file->getTitle() << endl;
    cout << "\t"
         << "Artist: " << file->getArtist() << endl;
    cout << "\t"
         << "Album: " << file->getAlbum() << endl;
    cout << "\t"
         << "Year: " << file->getYear() << endl;
    cout << "\t"
         << "Duration: " << file->getDuration() << endl;
    cout << "\t"
         << "Size: " << file->getSize() / 1024 << "Mb" << endl;
    cout << "\t"
         << "Bit rate: " << file->getBitRate() << endl;
    cout << "\t"
         << "Sample rate: " << file->getSampleRate() << endl;

    if (mp3File)
    {
        cout << "\t"
             << "Channels: " << mp3File->getChannels() << endl;
    }
    if (mp4File)
    {
    }
}

void FileView::updateMetadataFileMenu(FileAbstract *file)
{
    showFile(file);
    cout << "\n----------------------------------------------------------------" << endl;
    cout << "UPDATE METADATA FILE MENU: " << endl;
    cout << TITLE << ". Update title." << endl;
    cout << ALBUM << ". Update album." << endl;
    cout << ARTIST << ". Update artist." << endl;
    cout << YEAR << ". Update year." << endl;
    cout << PROPERTY_UPDATE_BACK << ". Back." << endl;
    cout << "----------------------------------------------------------------" << endl;
}