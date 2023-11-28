#include <fstream>
#include <cstring>

#include "../../include/util/util.hpp"

struct util::File file;

bool util::filecmp(util::File file1, util::File file2) {
    if (file1.size != file2.size)
        return false;
    int a = memcmp(file1.buffer, file2.buffer, file1.size);
    return a;
}

util::File util::getFile(std::wstring path) {
    util::File file{};
    std::ifstream fileStream(path, std::ios::binary);
    fileStream.seekg(0, std::ios::end);
    file.size = fileStream.tellg();
    fileStream.seekg(0, std::ios::beg);
    file.buffer = (char*)malloc(file.size);
    fileStream.read(file.buffer, file.size);
    fileStream.close();

    return file;
}

util::File util::getFile(const char* path) {
    util::File file{};
    std::ifstream fileStream(path, std::ios::binary);
    fileStream.seekg(0, std::ios::end);
    file.size = fileStream.tellg();
    fileStream.seekg(0, std::ios::beg);
    file.buffer = (char*)malloc(file.size);
    fileStream.read(file.buffer, file.size);
    fileStream.close();

    return file;
}