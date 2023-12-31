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

#include "../../include/util/serialization.hpp"
#include "../../include/util/util.hpp"

const char* serialization::serialize(util::Packet* packet) {
	return (const char*) packet;
};

util::Packet* serialization::deserialize(const char* packet) {
	return (util::Packet*) packet;
};