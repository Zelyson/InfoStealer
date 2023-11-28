#ifndef FILE_H
#define FILE_H


class util
{
public:
struct File
{
    char* buffer;
    size_t size;
};
    static bool filecmp(util::File file1, util::File file2);
    static File getFile(std::wstring path);
    static File getFile(const char* path);
private:

};
#endif