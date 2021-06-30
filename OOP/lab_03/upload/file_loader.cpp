#include "file_loader.hpp"

FileLoader::~FileLoader()
{
    close();
}

void FileLoader::open(char* source_name)
{
    if (file.is_open())
    {
        close();
    }

    file.open(source_name);
    time_t t_time = time(NULL);
    if (!file.is_open())
    {
       throw ErrorFileOpen(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }
}

void FileLoader::close()
{
    if (file.is_open())
    {
        file.close();
    }
}

int FileLoader::readCountInfo()
{
    time_t t_time = time(NULL);
    if (!file.is_open())
    {
       throw ErrorFileOpen(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }
    int count = 0;
    file >> count;
    return count;
}

Point FileLoader::readPoint()
{
    double x = 0, y = 0, z = 0;
    file >> x >> y >> z;
    return {x, y, z};
}

Edge FileLoader::readEdgeInfo()
{
    int begin = 0, end = 0;
    file >> begin >> end;
    return {begin, end};
}
