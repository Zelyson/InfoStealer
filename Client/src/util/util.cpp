/* 
* InfoStealer - Extracts information and interesting files from a target system.
* Copyright (C) 2023 Sebastian Hasch - <https://github.com/Zelyson/InfoStealer>
* 
* This program is free software licensed under the GNU General Public License version 3:
* you can redistribute it and/or modify it under the terms of the 
* GNU General Public License version 3 as published by the Free Software Foundation.
* 
* You should have received a copy of the GNU General Public License
* along with this program. If not, see <https://www.gnu.org/licenses/gpl-3.0>.
*/


#include <cstring>
#include <fstream>
#include <sstream>   
#include <string> 
#include <vector> 


#include "../../include/util/util.hpp"

bool util::filecmp(util::File& file1, util::File& file2) {
    if (file1.size != file2.size)
        return false;
    int a = memcmp(file1.buffer, file2.buffer, file1.size);
    return a;
}

util::File util::getFile(std::wstring& path) {
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

util::Packet util::getPacket(const char* path) {
    util::Packet packet{};
    packet.file = util::getFile(path);

    std::string strData(path);
    const char separator = '\\';
    std::stringstream streamData(strData);
    std::string val;
    while (std::getline(streamData, val, separator)) {
    }
    packet.name = val;

    return packet;
}
