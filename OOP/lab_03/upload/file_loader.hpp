#ifndef FILE_LOADER_HPP
#define FILE_LOADER_HPP

#include <fstream>
#include <iostream>
#include "upload/base_loader.h"
#include "exceptions/exceptions.h"
#include <ctime>

class FileLoader: public BaseLoader
{
public:
    FileLoader() = default;
    ~FileLoader() override;

    void open(char* source_name) override;
    void close() override;

    int readCountInfo() override;
    Edge readEdgeInfo() override;
    Point readPoint() override;

private:
    std::ifstream file;
};

#endif // FILE_LOADER_HPP
