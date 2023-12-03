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

#include "../include/initialize.hpp"
#include "../include/comms/comms.hpp"
#include "../include/util/srvutil.hpp"



int initialize::init(const char* argv[]) {
	comms* com = new comms();
	com->start();

	return 0;
}

