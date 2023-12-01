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

#pragma once

#include <iostream>

class util
{
public:
struct File
{
    char* buffer;
    size_t size;
};

struct Packet
{
    File file;
    std::string name;

};
    static bool filecmp(util::File& file1, util::File& file2);
    static File getFile(std::wstring& path);
    static File getFile(const char* path);
    static Packet getPacket(const char* path);

private:

};
