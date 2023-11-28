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
