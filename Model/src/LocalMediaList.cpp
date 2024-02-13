#include "LocalMediaList.h"

LocalMediaList::LocalMediaList(/* args */)
{
    char currentDir[100];

    if (getcwd(currentDir, sizeof(currentDir)) == nullptr)
    {
        std::cout << "Error getting current working directory." << std::endl;
        return;
    }

    path = currentDir;
    const std::filesystem::path directoryPath = path;
    for (const auto &entry : std::filesystem::recursive_directory_iterator(directoryPath))
    {
        if (entry.is_regular_file())
        {
            if (entry.path().extension() == ".mp3")
            {
                Mp3File a;
                localFileList.push_back(new Mp3File(entry.path()));
            }
            if (entry.path().extension() == ".mp4")
            {
                localFileList.push_back(new Mp4File(entry.path()));
            }
        }
    }
}

LocalMediaList::~LocalMediaList()
{
    for (FileAbstract *it : localFileList)
    {
        delete (it);
    }
    localFileList.clear();
}

vector<FileAbstract *> LocalMediaList::getList()
{
    return localFileList;
}